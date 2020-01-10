<?php

/**
 * @file
 * Define the hook_field for the field enrd_evf.
 */

/**
 * Implements hook_field_info().
 */
function enrd_evf_field_info() {
  return array(
    'email_verify_field' => array(
      'label' => t('Email with validation'),
      'description' => t('Email with token validation.'),
      'default_widget' => 'evf_textfield',
      'default_formatter' => 'evf_default',
      'instance_settings' => array(
        'template' => array(
          'from' => '',
          'subject' => '',
          'body' => '',
        ),
      ),
      'property_type' => 'text',
    ),
  );
}

/**
 * Implements field_settings_form().
 */
function enrd_evf_field_settings_form($field, $instance, $has_data) {
  $settings = $field['settings'];
  $form['expiration_time'] = array(
    '#type' => 'select',
    '#title' => t('Expiration time in days'),
    '#description' => t('Defines the number of the days after which to expire the token validity'),
    '#options' => drupal_map_assoc(array(1, 3, 7, 14, 30, 60, 365)),
    '#default_value' => isset($settings['expiration_time']) ? $settings['expiration_time'] : 30,
    '#disabled' => $has_data,
  );

  return $form;
}

/**
 * Implements hook_field_instance_settings_form().
 */
function enrd_evf_field_instance_settings_form($field, $instance) {

  $settings = $instance['settings'];

  $form = array(
    '#element_validate' => array('enrd_evf_field_settings_form_validate'),
  );

  $form['template'] = array(
    '#type' => 'fieldset',
    '#title' => t('Email template'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['template']['from'] = array(
    '#type' => 'textfield',
    '#title' => t('From'),
    '#default_value' => isset($settings['template']['from']) ? $settings['template']['from'] : '',
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => TRUE,
  );

  $form['template']['subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => isset($settings['template']['subject']) ? $settings['template']['subject'] : '',
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => TRUE,
  );

  $form['template']['body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#description' => t('Insert token'),
    '#default_value' => isset($settings['template']['body']) ? $settings['template']['body'] : '',
    '#required' => TRUE,
  );
  // Display the list of available placeholders if token module is installed.
  if (module_exists('token')) {
    $form['template']['token_help'] = array(
      '#theme' => 'token_tree',
      '#dialog' => TRUE,
      '#token_types' => array(
        'enrd_evf',
        $instance['entity_type'],
      ),
    );
  }

  return $form;
}

/**
 * Element_validate handler for enrd_evf_field_instance_settings_form().
 */
function enrd_evf_field_settings_form_validate($element, &$form_state, $complete_form) {
  $settings = $form_state['values']['instance']['settings'];
  if (!valid_email_address(trim($settings['template']['from']))) {
    $message = t('"%mail" is not a valid email address', array('%mail' => $settings['template']['from']));
    form_set_error('instance][settings][template][from', $message);
  }
}

/**
 * Implements hook_field_validate().
 */
function enrd_evf_field_validate($entity_type, $entity, $field, $instance, $langcode, $items, &$errors) {

  foreach ($items as $delta => $item) {
    if ($item['email'] != '' && !valid_email_address(trim($item['email']))) {
      $message = t('"%mail" is not a valid email address', array('%mail' => $item['email']));
      $errors[$field['field_name']][$langcode][$delta][] = array(
        'error' => 'email_invalid',
        'message' => $message,
      );
    }
  }
}

/**
 * Implements hook_content_is_empty().
 */
function enrd_evf_field_is_empty($item, $field) {
  return empty($item['email']);
}

/**
 * Implements hook_field_presave().
 */
function enrd_evf_field_presave($entity_type, $entity, $field, $instance, $langcode, &$items) {
  list(, , $bundle) = entity_extract_ids($entity_type, $entity);
  $field_name = $field['field_name'];

  // Prepares the attributes for each value of the field.
  foreach ($items as &$item) {
    _enrd_evf_process($item);

    if ($item['status'] === ENRD_EVF_STATUS_CONFIRM_BYPASS) {
      // Notify the other modules that the e-mail was confirmed.
      module_invoke_all('enrd_evf_post_status_confirm', $entity_type, $bundle, $entity, $field_name, FALSE);
    }
  }
}

/**
 * Implements hook_field_insert().
 */
function enrd_evf_field_insert($entity_type, $entity, $field, $instance, $langcode, &$items) {
  list($entity_id, , $bundle) = entity_extract_ids($entity_type, $entity);
  $settings = $field['settings'];
  $field_name = $field['field_name'];

  foreach ($items as $delta => $item) {
    if ($item['status'] === ENRD_EVF_STATUS_TO_CONFIRM) {
      // Data creation for token management.
      $token = _enrd_evf_management_token($entity_type, $bundle, $entity_id, $field_name, $delta, $settings);

      if (isset($token) && !empty($token)) {
        // Send a confirmation e-mail.
        _enrd_evf_send_confimation_email($item, $entity_type, $entity, $instance, $token);
        drupal_set_message(t('We have sent a confirmation email to the email address you have specified. Please open it and click on the link in order to finalize the request you have just submitted.'), 'modal');
      }
    }
  }
}

/**
 * Implements hook_field_delete().
 */
function enrd_evf_field_delete($entity_type, $entity, $field, $instance, $langcode, &$items) {
  list($id, , $bundle) = entity_extract_ids($entity_type, $entity);
  $field_name = $field['field_name'];

  foreach ($items as $delta => $item) {
    // Delete no longer necessary data from the management table.
    _enrd_evf_management_token_delete($entity_type, $bundle, $id, $field_name, $delta);
  }
}

/**
 * Implements hook_field_delete_field().
 */
function enrd_evf_field_delete_field($field) {
  if ($field['type'] != 'email_verify_field') {
    return;
  }

  // Delete no longer necessary data from the management table.
  db_delete(ENRD_EVF_MANAGEMENT_TABLE_NAME)
    ->condition('field_name', $field['field_name'])
    ->execute();
}
