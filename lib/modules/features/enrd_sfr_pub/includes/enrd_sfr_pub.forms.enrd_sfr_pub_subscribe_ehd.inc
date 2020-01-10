<?php

/**
 * @file
 * Code for enrd_sfr_pub_subscribe_ehd form customizations.
 */

/**
 * Customizations on the ENRD Sfr Subscription EHD Form.
 *
 * @param mixed $form
 *   Drupal form array.
 * @param mixed $form_state
 *   Drupal form state array.
 */
function _enrd_sfr_pub_subscribe_ehd_customizations(&$form, &$form_state) {
  // After build alterations.
  $form['#after_build'][] = '_enrd_sfr_pub_subscribe_ehd_form_after_build';

  // Remove AJAX behavior on change Addressfield "Country" event.
  if (isset($form['field_enrd_sfr_pub_subehd_countr'])) {
    unset($form['field_enrd_sfr_pub_subehd_countr'][LANGUAGE_NONE][0]['country']['#ajax']);

    // Add an empty value to use in the addressfield_default_values_alter hook.
    $form['field_enrd_sfr_pub_subehd_countr'][LANGUAGE_NONE][0]['country']['#options'] = array('' => t('- Select a country -')) + $form['field_enrd_sfr_pub_subehd_countr'][LANGUAGE_NONE][0]['country']['#options'];
  }

  // Hide "Type(s) of Publication" field.
  if (isset($form['field_enrd_sfr_pub_subehd_type'])) {
    $form['field_enrd_sfr_pub_subehd_type']['#access'] = FALSE;
  }

  // Prefill form fields for Authenticated.
  _enrd_sfr_pub_prefill_form_fields(array(
    'field_enrd_sfr_pub_subehd_name' => 'name',
    'field_enrd_sfr_pub_subehd_surnam' => 'surname',
    'field_enrd_sfr_pub_subehd_email' => 'email',
  ), $form);

  if (isset($form['field_enrd_sfr_pub_subehd_countr'])) {
    // Remove Addressfield fields other than "Country".
    unset($form['field_enrd_sfr_pub_subehd_countr'][LANGUAGE_NONE][0]['street_block']);
    unset($form['field_enrd_sfr_pub_subehd_countr'][LANGUAGE_NONE][0]['locality_block']);
  }

  $ehd_publications_page = apachesolr_search_page_load('evaluation_publications_elibrary');

  if ($ehd_publications_page) {
    // Add a page description.
    $element = array(
      '#type' => 'markup',
      '#markup' => t('Fill in the form below to request subscription to !url.', array(
        '!url' => l(
          t('Evaluation publications'),
          $ehd_publications_page['search_path'],
          array(
            'attributes' => array(
              'title' => t('Evaluation Publications search page.'),
              'target' => '_blank',
            ),
          )
        ),
      )),
    );

    $form['enrd_sfr_subscribe_ehd_description'] = $element;

    if (isset($form['field_enrd_sfr_pub_subehd_name'])) {
      // Set description weight.
      $form['enrd_sfr_subscribe_ehd_description']['#weight'] = $form['field_enrd_sfr_pub_subehd_name']['#weight'] - 1;
    }
  }

  // Create EU Legal notice checkbox.
  form_load_include($form_state, 'inc', 'enrd_mastermind', 'includes/enrd_mastermind.form.lagal_notice_element');
  $form['field_enrd_sfr_pub_eu_legal_notice'] = _enrd_mastermind_eu_legal_notice_checkbox();
  // Disclaimer "Legal notice" msg below "Type(s) of Publication" field.
  if (isset($form['field_enrd_sfr_pub_subehd_type'])) {
    $form['field_enrd_sfr_pub_eu_legal_notice']['#weight'] = $form['field_enrd_sfr_pub_subehd_type']['#weight'] + 1;
  }

  // Link message to Contact EHD Form.
  $form['enrd_sfr_pub_contact_ehd'] = _enrd_sfr_pub_redirect_contact_ehd_message();
  // Place the Unsub. disclaimer below "Submit" button.
  $form['enrd_sfr_pub_contact_ehd']['#weight'] = $form['actions']['#weight'] + 1;

}

/**
 * After build callback for the ENRD Sfr Subscribe EHD Form.
 *
 * @param mixed $form
 *   Drupal form array.
 */
function _enrd_sfr_pub_subscribe_ehd_form_after_build($form) {
  // Override default ENRD Sfr add page title.
  drupal_set_title(t('Subscribe to Evaluation publications'));

  return $form;
}

/**
 * Custom function to append Contact EHD form message.
 *
 * @return array
 *   HTML to render the form submit suffix.
 */
function _enrd_sfr_pub_redirect_contact_ehd_message() {
  // Disclaimer msg shown in the EHD Subscriptions Form.
  return array(
    '#type' => 'item',
    '#markup' => t('If you want to unsubscribe or modify your subscription data please !url.', array(
      '!url' => l(
        t('contact the Evaluation Helpdesk'),
        ENRD_SFR_PUB_ADD_REQUEST . _enrd_sfr_type_path_replace(ENRD_SFR_PUB_CONT_EHD_FORM),
        array('attributes' => array('target' => '_blank'))
      ),
    )),
  );
}
