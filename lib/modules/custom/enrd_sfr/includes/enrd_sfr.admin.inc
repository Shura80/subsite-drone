<?php

/**
 * @file
 * File enrd_sfr.admin.inc.
 */

/**
 * Generates the ENRD Sfr type editing form.
 *
 * @param array $form
 *   The complete parent form.
 * @param array $form_state
 *   The form state of the parent form.
 * @param object $enrd_sfr_type
 *   The ENRD Sfr Type object.
 * @param string $op
 *   The operation to perform.
 *
 * @var \Drupal\enrd_sfr\Entity\EnrdSfrType $enrd_sfr_type
 *   The ENRD Sfr Type object.
 *
 * @return array
 *   The complete parent form customized.
 */
function enrd_sfr_type_form(array $form, array &$form_state, $enrd_sfr_type, $op = 'edit') {
  if ($op == 'clone') {
    $enrd_sfr_type->label .= ' (cloned)';
    $enrd_sfr_type->name = '';
  }

  // Make the type object available to implementations of hook_form_alter.
  $form['#enrd_sfr_type'] = $enrd_sfr_type;

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $enrd_sfr_type->label,
    '#description' => t('The human-readable name of this ENRD Sfr type.'),
    '#required' => TRUE,
    '#size' => 30,
  );

  // Machine-readable type name.
  $form['name'] = array(
    '#type' => 'machine_name',
    '#default_value' => $enrd_sfr_type->name ? $enrd_sfr_type->name : '',
    '#maxlength' => 32,
    '#machine_name' => array(
      'exists' => 'invite_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this ENRD Sfr type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['description'] = array(
    '#type' => 'textarea',
    '#default_value' => $enrd_sfr_type->description ? $enrd_sfr_type->description : '',
    '#description' => t('Description about the ENRD Sfr type.'),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save ENRD Sfr type'),
    '#weight' => 40,
  );

  return $form;
}

/**
 * Submit handler for creating/editing enrd_sfr_type.
 *
 * @param array $form
 *   The complete parent form.
 * @param array $form_state
 *   The form state of the parent form.
 */
function enrd_sfr_type_form_submit(array &$form, array &$form_state) {
  $enrd_sfr_type = entity_ui_form_submit_build_entity($form, $form_state);
  // Save and go back.
  enrd_sfr_type_save($enrd_sfr_type);

  // Redirect user back to list of ENRD Sfr types.
  $form_state['redirect'] = 'admin/structure/enrd-sfr-types';
}

/**
 * Add new ENRD Sfr page callback.
 *
 * @param string $type
 *   The ENRD Sfr bundle machine name.
 *
 * @return array|mixed
 *   The rendered form.
 */
function enrd_sfr_add($type) {
  // Load ENRD Sfr entity of specific bundle.
  $enrd_sfr_type = enrd_sfr_get_types($type);

  // Create new instance of ENRD Sfr entity to be passed to the form.
  $enrd_sfr = entity_create(ENRD_SFR_ENTITY_NAME, array('type' => $type));
  drupal_set_title(t('Add @name request', array('@name' => entity_label('enrd_sfr_type', $enrd_sfr_type))), PASS_THROUGH);

  // Return the related renderable form.
  $output = drupal_get_form('enrd_sfr_form', $enrd_sfr);

  return $output;
}

/**
 * ENRD Sfr Form.
 *
 * @param array $form
 *   The complete parent form.
 * @param array $form_state
 *   The form state of the parent form.
 * @param object $enrd_sfr
 *   The ENRD Sfr object.
 *
 * @var Drupal\enrd_sfr\Entity\EnrdSfr $enrd_sfr
 *   ENRD Sfr object.
 *
 * @return array
 *   The completed form after customization.
 */
function enrd_sfr_form(array $form, array &$form_state, $enrd_sfr) {
  $form['#entity'] = $form_state['enrd_sfr'] = $enrd_sfr;

  field_attach_form(ENRD_SFR_ENTITY_NAME, $enrd_sfr, $form, $form_state);

  $submit = array();
  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions'] = array(
    '#weight' => 100,
  );

  $form['#validate'][] = 'enrd_sfr_form_validate';

  // Attach submit handler to the button.
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Send request'),
    '#submit' => $submit + array('enrd_sfr_form_submit'),
  );

  return $form;
}

/**
 * ENRD Sfr form validation handler.
 *
 * @param array $form
 *   The complete parent form.
 * @param array $form_state
 *   The form state of the parent form.
 */
function enrd_sfr_form_validate(array $form, array &$form_state) {
  $enrd_sfr = $form_state['enrd_sfr'];
  field_attach_form_validate(ENRD_SFR_ENTITY_NAME, $enrd_sfr, $form, $form_state);
}

/**
 * ENRD Sfr creation submit handler.
 *
 * @param array $form
 *   The complete parent form.
 * @param array $form_state
 *   The form state of the parent form.
 */
function enrd_sfr_form_submit(array $form, array &$form_state) {
  $enrd_sfr = $form_state['enrd_sfr'];

  // Copies submitted values to entity properties.
  entity_form_submit_build_entity(ENRD_SFR_ENTITY_NAME, $enrd_sfr, $form, $form_state);

  // Save the ENRD Sfr entity.
  enrd_sfr_save($enrd_sfr);
}
