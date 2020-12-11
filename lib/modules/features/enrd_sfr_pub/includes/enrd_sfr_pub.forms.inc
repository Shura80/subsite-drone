<?php

/**
 * @file
 * Code for ENRD Sfr Form Add customizations.
 */

/**
 * Custom function to append ENRD Newsletter message.
 *
 * @return array
 *   HTML to render the form submit suffix.
 */
function _enrd_sfr_pub_redirect_enrd_newsletter_link() {
  // Disclaimer msg below "Submit" button of the Subscription Request Form.
  return array(
    '#type' => 'item',
    '#markup' => t('If you want to subscribe to the Newsletter, please go to the !url.', array(
      '!url' => l(
        t('ENRD Newsletter subscription page'),
      ENRD_SFR_PUB_NEWSLETTER_URL, array('attributes' => array('target' => '_blank'))),
    )),
  );
}

/**
 * Prefill name, surname and email in forms if current user is logged in.
 *
 * @param array $elements
 *   Drupal form elements array.
 * @param array $form
 *   Drupal form array.
 */
function _enrd_sfr_pub_prefill_form_fields(array $elements, array &$form) {
  if (user_is_logged_in()) {
    global $user;

    // Get mandatory user's First name and Last name.
    $authenticated_details = entity_metadata_wrapper('user', $user);
    $user_values = array(
      'name' => $authenticated_details->field_firstname->value(),
      'surname' => $authenticated_details->field_lastname->value(),
      'email' => $user->mail,
    );

    foreach ($elements as $field => $type) {
      if ($type == 'email') {
        $form[$field][LANGUAGE_NONE][0]['email']['#default_value'] = $user_values[$type];
      }
      else {
        $form[$field][LANGUAGE_NONE][0]['value']['#default_value'] = $user_values[$type];
      }
    }
  }
}
