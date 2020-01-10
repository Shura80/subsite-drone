<?php

/**
 * @file
 * Code for enrd_sfr_pub_contact_cp form customizations.
 */

/**
 * Customizations on the ENRD Sfr Contact CP Form.
 *
 * @param mixed $form
 *   Drupal form array.
 * @param mixed $form_state
 *   Drupal form state array.
 */
function _enrd_sfr_pub_contact_cp_customizations(&$form, &$form_state) {
  // After build alterations.
  $form['#after_build'][] = '_enrd_sfr_pub_contact_cp_form_after_build';

  // Actually make fields required according to the respective fields.
  $form['#validate'][] = '_enrd_sfr_pub_contact_cp_form_validate';

  // Prefill form fields for Authenticated.
  _enrd_sfr_pub_prefill_form_fields(array(
    'field_enrd_sfr_pub_contcp_name' => 'name',
    'field_enrd_sfr_pub_contcp_surn' => 'surname',
    'field_enrd_sfr_pub_contcp_email' => 'email',
  ), $form);

  // ENRD Sfr Form Add conditions: CP Contact form.
  // Conditions applied according to "Reason".
  $reason_unsub = array(':input[name="field_enrd_sfr_pub_contcp_reas[und]"]' => array('value' => 'unsubscribe'));
  $reason_modify = array(':input[name="field_enrd_sfr_pub_contcp_reas[und]"]' => array('value' => 'modify subscription data'));

  // Field "Comments" states.
  $form['field_enrd_sfr_pub_contcp_comm']['#states']['visible'] = $reason_unsub;
  // Field "Please specify how you would like to modify (...)" states.
  $form['field_enrd_sfr_pub_contcp_modif']['#states']['visible'] = $reason_modify;
  $form['field_enrd_sfr_pub_contcp_modif']['#states']['required'] = $reason_modify;

  // Condition applied according to Electronic/Paper field.
  $paper_selected = array(':input[name="field_enrd_sfr_pub_contcp_papel[und][paper]"]' => array('checked' => TRUE));

  // Customizations on the "Address" field.
  // Show Addressfield if paper is selected.
  $form['field_enrd_sfr_pub_contcp_oldadd']['#states']['visible'] = $paper_selected;

  if (isset($form['field_enrd_sfr_pub_contcp_oldadd'][LANGUAGE_NONE][0])) {
    // "To what postal address..." Addressfield.
    $address = &$form['field_enrd_sfr_pub_contcp_oldadd'][LANGUAGE_NONE][0];

    // Override Address 1 & 2 titles.
    $address['street_block']['thoroughfare']['#title'] = t('Address Line 1');
    $address['street_block']['premise']['#title'] = t('Address Line 2');
    // Show Addressfield if paper is selected.
    $address['country']['#states']['required'] = $paper_selected;
    $address['street_block']['thoroughfare']['#states']['required'] = $paper_selected;
    $address['locality_block']['locality']['#states']['required'] = $paper_selected;
    // Force maxlength & size to Address 1 & 2.
    $address['street_block']['thoroughfare']['#maxlength'] = ENRD_SFR_PUB_EU_MAXLENGTH;
    $address['street_block']['premise']['#maxlength'] = ENRD_SFR_PUB_EU_MAXLENGTH;
    // Apply description to Address 1 & 2.
    $address['street_block']['thoroughfare']['#description'] = t('Maximum 35 characters.');
    $address['street_block']['premise']['#description'] = t('Maximum 35 characters.');
  }

  // Customization on "Type of publication(s)".
  // Remove "- None -" option from Chosen multi field.
  if (isset($form['field_enrd_sfr_pub_contcp_type'][LANGUAGE_NONE])) {
    unset($form['field_enrd_sfr_pub_contcp_type'][LANGUAGE_NONE]['#options']['_none']);
  }

  $publications_page = apachesolr_search_page_load('publications_elibrary');

  if ($publications_page) {
    // Add a page description.
    $element = array(
      '#type' => 'markup',
      '#markup' => t('Fill in the form below to request to unsubscribe or modify your subscription to !url.', array(
        '!url' => l(
          t('ENRD publications'),
          $publications_page['search_path'],
          array(
            'attributes' => array(
              'title' => t('ENRD Publications search page.'),
              'target' => '_blank',
            ),
          )
        ),
      )),
    );

    $form['enrd_sfr_contact_cp_description'] = $element;

    if (isset($form['field_enrd_sfr_pub_contcp_reas'])) {
      // Set description weight.
      $form['enrd_sfr_contact_cp_description']['#weight'] = $form['field_enrd_sfr_pub_contcp_reas']['#weight'] - 1;
    }
  }

  // Add EU Legal notice checkbox to the form.
  form_load_include($form_state, 'inc', 'enrd_mastermind', 'includes/enrd_mastermind.form.lagal_notice_element');
  $form['field_enrd_sfr_pub_eu_legal_notice'] = _enrd_mastermind_eu_legal_notice_checkbox();

  $contact_textarea_fields = array(
    'field_enrd_sfr_pub_contcp_comm',
    'field_enrd_sfr_pub_contcp_modif',
  );
  // Show disclaimer "Legal notice" msg below textarea fields.
  foreach ($contact_textarea_fields as $field) {
    if (isset($form[$field])) {
      $form['field_enrd_sfr_pub_eu_legal_notice']['#weight'] = $form[$field]['#weight'] + 1;
    }
  }

}

/**
 * After build callback for the ENRD Sfr Contact CP Form.
 *
 * @param mixed $form
 *   Drupal form array.
 * @param mixed $form_state
 *   Drupal form state array.
 */
function _enrd_sfr_pub_contact_cp_form_after_build($form, &$form_state) {
  // Override default ENRD Sfr form add page title.
  drupal_set_title(t('Unsubscribe / modify your subscription to publications'));

  // Create empty value select option.
  if (isset($form['field_enrd_sfr_pub_contcp_oldadd'][LANGUAGE_NONE][0])) {
    // "To what postal address..." Addressfield.
    $address_element = &$form['field_enrd_sfr_pub_contcp_oldadd'][LANGUAGE_NONE][0];

    $address_element['country']['#options'] = array('' => t('- Select a country -')) + $address_element['country']['#options'];
  }

  $paper_is_checked = isset($form_state['values']['field_enrd_sfr_pub_contcp_papel'][LANGUAGE_NONE]['paper']) &&
    !empty($form_state['values']['field_enrd_sfr_pub_contcp_papel'][LANGUAGE_NONE]['paper']);

  // If Paper is not checked, make fields unrequired.
  if (!$paper_is_checked) {
    // Note: the Addressfield field should be required.
    // If paper is not selected, "Country" should not be required.
    $address_element['country']['#required'] = FALSE;

    // If value is "Select a country", make fields required by default.
    $address_element['street_block']['thoroughfare']['#required'] = FALSE;
    $address_element['locality_block']['postal_code']['#required'] = FALSE;
    $address_element['locality_block']['dependent_locality']['#required'] = FALSE;
    $address_element['locality_block']['locality']['#required'] = FALSE;
    $address_element['locality_block']['administrative_area']['#required'] = FALSE;
  }

  return $form;

}

/**
 * Validate function for ENRD Sfr Contact CP Form fields.
 *
 * @param mixed $form
 *   Drupal form array.
 * @param mixed $form_state
 *   Drupal form state array.
 */
function _enrd_sfr_pub_contact_cp_form_validate($form, &$form_state) {

  if (isset($form_state['values']['field_enrd_sfr_pub_contcp_reas'][LANGUAGE_NONE][0]['value'])) {
    $reason_value = $form_state['values']['field_enrd_sfr_pub_contcp_reas'][LANGUAGE_NONE][0]['value'];

    if ($reason_value == 'modify subscription data') {
      // Make "Please specify how you would like to modify your subscription
      // information" required if Reason is "modify".
      if (empty($form_state['values']['field_enrd_sfr_pub_contcp_modif'][LANGUAGE_NONE][0]['value'])) {
        form_set_error('field_enrd_sfr_pub_contcp_modif', t('!name field is required.', array('!name' => $form['field_enrd_sfr_pub_contcp_modif'][LANGUAGE_NONE]['#title'])));
      }
    }
  }

}
