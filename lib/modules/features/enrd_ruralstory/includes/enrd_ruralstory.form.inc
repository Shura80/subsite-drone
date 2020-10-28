<?php

/**
 * @file
 * Code for _enrd_ruralstory_form_customizations form customizations.
 */

/**
 * Customizations on the "ENRD Rural Story" Form.
 *
 * @param mixed $form
 *   Drupal form array.
 * @param mixed $form_state
 *   Drupal form state array.
 */
function _enrd_ruralstory_form_customizations(&$form, &$form_state) {
  // After build alterations.
  $form['#after_build'][] = '_enrd_ruralstory_form_after_build';

  form_load_include($form_state, 'inc', 'enrd_mastermind', 'includes/enrd_mastermind.form.legal_notice_element');
  // Add Authorization message checkbox.
  $form['legal_notice']['enrd_ruralstory_authorize_notice'] = _enrd_ruralstory_authorize_notice_checkbox();
  // EU Legal notice & Privacy Policy statements.
  $form['legal_notice']['enrd_ruralstory_eu_legal_notice'] = _enrd_mastermind_eu_legal_notice_checkbox();
  $form['legal_notice']['#weight'] = $form['actions']['#weight'] - 1;

  // Replace "Title" default value.
  if (isset($form['field_enrd_ruralstory_title'])) {
    $form['field_enrd_ruralstory_title'][LANGUAGE_NONE]['#options']['_none'] = t('- Select a title -');
  }

  // Show "Upload photos/files" field if user is Authenticated.
  if (isset($form['field_enrd_ruralstory_files'])) {
    $form['field_enrd_ruralstory_files']['#access'] = user_is_logged_in();
  }

  // Add validation to "Relevant Links" field.
  if (isset($form['field_enrd_ruralstory_links'])) {
    $form['field_enrd_ruralstory_links'][LANGUAGE_NONE]['add_more']['#submit'][] = '_ruralstory_links_field_add_more_validate';
  }

  // Override "Submit" message.
  $form['actions']['submit']['#value'] = t('Send your story');

  // Image captcha for Anonymous.
  if (user_is_anonymous()) {
    $form['actions'] = [
      'captcha' => [
        '#type' => 'captcha',
        '#captcha_type' => 'image_captcha/Image',
      ],
    ] + $form['actions'];
  }
}

/**
 * Custom submit to validate "Relevant Links" field.
 *
 * @param mixed $form
 *   Drupal form array.
 * @param mixed $form_state
 *   Drupal form state array.
 */
function _ruralstory_links_field_add_more_validate($form, &$form_state) {
  // Custom validation triggered when hitting "Add another item" button.
  // Allow maximum n. of links, regardless of whether JS is enabled or not.
  if ($form_state['field']['field_enrd_ruralstory_links'][LANGUAGE_NONE]['items_count'] >= 10) {
    form_set_error('field_enrd_ruralstory_links', t('@label field accepts maximum 10 links.', array('@label' => $form['field_enrd_ruralstory_links'][LANGUAGE_NONE]['#title'])));
  }
}

/**
 * After build callback for the "ENRD Rural Story" Form.
 *
 * @param mixed $form
 *   Drupal form array.
 * @param mixed $form_state
 *   Drupal form state array.
 */
function _enrd_ruralstory_form_after_build($form, &$form_state) {
  // Override default ENRD Sfr add page title.
  drupal_set_title(t('Share your Rural Story'));

  return $form;
}

/**
 * Custom function to generate the Authorize notice.
 *
 * @return array
 *   A Drupal renderable array element.
 */
function _enrd_ruralstory_authorize_notice_checkbox() {
  // Disclaimer msg above "Submit" button of the Rural Story Form.
  return array(
    '#type' => 'checkbox',
    '#title' => t(
      'I confirm that by submitting this information I authorise the ENRD CP to make it available online or in printed publications. !req',
      // Show required marker at the end of the line.
      array('!req' => theme('form_required_marker'))
    ),
    '#attributes' => array('class' => array('form-authorize-notice-disclaimer')),
    '#element_validate' => array('_enrd_ruralstory_authorize_notice'),
  );
}

/**
 * Validate function for Authorize CP notice field.
 *
 * @param array $element
 *   Drupal form array element.
 * @param array $form_state
 *   Drupal form state array.
 */
function _enrd_ruralstory_authorize_notice(array $element, array &$form_state) {
  if (empty($element['#value'])) {
    form_error($element, t('You must agree with the ENRD CP Authorization Statement to proceed.'));
  }
}
