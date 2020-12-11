<?php

/**
 * @file
 * Code for enrd_sfr_pub_contact_ehd form customizations.
 */

/**
 * Customizations on the ENRD Sfr Contact EHD Form.
 *
 * @param mixed $form
 *   Drupal form array.
 * @param mixed $form_state
 *   Drupal form state array.
 */
function _enrd_sfr_pub_contact_ehd_customizations(&$form, &$form_state) {
  // After build alterations.
  $form['#after_build'][] = '_enrd_sfr_pub_contact_ehd_form_after_build';

  // Actually make fields required according to the respective fields.
  $form['#validate'][] = '_enrd_sfr_pub_contact_ehd_form_validate';

  // Prefill form fields for Authenticated.
  _enrd_sfr_pub_prefill_form_fields(array(
    'field_enrd_sfr_pub_contehd_name' => 'name',
    'field_enrd_sfr_pub_contehd_surn' => 'surname',
    'field_enrd_sfr_pub_contehd_email' => 'email',
  ), $form);

  // Hide "Type of publication(s)" field.
  if (isset($form['field_enrd_sfr_pub_contehd_type'])) {
    $form['field_enrd_sfr_pub_contehd_type']['#access'] = FALSE;
  }

  // ENRD Sfr Form Add conditions: EHD Contact form.
  // Conditions applied according to "Action".
  $reason_unsub = array(':input[name="field_enrd_sfr_pub_contehd_reas[und]"]' => array('value' => 'unsubscribe'));
  $reason_modify = array(':input[name="field_enrd_sfr_pub_contehd_reas[und]"]' => array('value' => 'modify subscription data'));

  // Field "Notes".
  $form['field_enrd_sfr_pub_contehd_not']['#states'] = array(
    'visible' => $reason_unsub,
  );
  // Field "Please specify how you would like to modify...".
  $form['field_enrd_sfr_pub_contehd_modif']['#states'] = array(
    'visible' => $reason_modify,
    'required' => $reason_modify,
  );

  $publications_page = apachesolr_search_page_load('evaluation_publications_elibrary');

  if ($publications_page) {
    // Add a page description.
    $element = array(
      '#type' => 'item',
      '#markup' => t('Fill in the form below to request to unsubscribe or modify your subscription to !url.', array(
        '!url' => l(
          t('Evaluation publications'),
          $publications_page['search_path'],
          array(
            'attributes' => array(
              'title' => t('Evaluation Helpdesk\'s Publications search page.'),
              'target' => '_blank',
            ),
          )
        ),
      )),
    );

    $form['enrd_sfr_contact_ehd_description'] = $element;

    if (isset($form['field_enrd_sfr_pub_contehd_reas'])) {
      // Set description weight.
      $form['enrd_sfr_contact_ehd_description']['#weight'] = $form['field_enrd_sfr_pub_contehd_reas']['#weight'] - 1;
    }
  }

  form_load_include($form_state, 'inc', 'enrd_mastermind', 'includes/enrd_mastermind.form.legal_notice_element');
  // EU Legal notice & Privacy Policy statements.
  $form['field_enrd_sfr_pub_eu_legal_notice'] = _enrd_mastermind_eu_legal_notice_checkbox();

  $contact_textarea_fields = array(
    'field_enrd_sfr_pub_contehd_not',
    'field_enrd_sfr_pub_contehd_modif',
  );
  // Show disclaimer "Legal notice" msg below textarea field.
  foreach ($contact_textarea_fields as $field) {
    if (isset($form[$field])) {
      $form['field_enrd_sfr_pub_eu_legal_notice']['#weight'] = $form[$field]['#weight'] + 1;
    }
  }

}

/**
 * After build callback for the ENRD Sfr Contact EHD Form.
 *
 * @param mixed $form
 *   Drupal form array.
 */
function _enrd_sfr_pub_contact_ehd_form_after_build($form) {
  // Override default ENRD Sfr form add page title.
  drupal_set_title(t('Unsubscribe / modify your subscription to Evaluation publications'));

  return $form;
}

/**
 * Validate function for ENRD Sfr Contact EHD Form fields.
 *
 * @param mixed $form
 *   Drupal form array.
 * @param mixed $form_state
 *   Drupal form state array.
 */
function _enrd_sfr_pub_contact_ehd_form_validate($form, &$form_state) {

  if (isset($form_state['values']['field_enrd_sfr_pub_contehd_reas'][LANGUAGE_NONE][0]['value'])) {
    $reason_value = $form_state['values']['field_enrd_sfr_pub_contehd_reas'][LANGUAGE_NONE][0]['value'];

    if ($reason_value == 'modify subscription data') {
      // Make "Please specify..." required if Action is "modify".
      if (empty($form_state['values']['field_enrd_sfr_pub_contehd_modif'][LANGUAGE_NONE][0]['value'])) {
        form_set_error('field_enrd_sfr_pub_contehd_modif', t('!name field is required.', array('!name' => $form['field_enrd_sfr_pub_contehd_modif'][LANGUAGE_NONE]['#title'])));
      }
    }
  }

}
