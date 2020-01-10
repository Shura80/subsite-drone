<?php

/**
 * @file
 * Code to add custom form element "Legal notice".
 */

/**
 * Custom function to render Legal notice checkbox.
 *
 * @param array $options
 *   An array with the additional options for the element.
 *
 * @return array
 *   A Drupal renderable array element.
 */
function _enrd_mastermind_eu_legal_notice_checkbox($options = array()) {

  $element = array(
    '#type' => 'checkbox',
    '#title' => t('By checking this box, you acknowledge that you have read and understood the !url. !req', array(
      '!url' => l(
        t('European Commission\'s legal notice'),
        ENRD_MASTERMIND_EU_LEGAL_NOTICE_URL, array('attributes' => array('target' => '_blank'))),
      // Show required marker at the end of the line.
      '!req' => theme('form_required_marker'),
    )),
    '#attributes' => array('class' => array('form-legal-notice-disclaimer')),
    '#element_validate' => array('_enrd_mastermind_validate_eu_legal_notice'),
  );

  // Add more options or overwrite existing ones.
  if (!empty($options)) {
    $element = array_merge($element, $options);
  }

  return $element;
}

/**
 * Validate function for EU Legal Notice field.
 *
 * @param array $element
 *   Drupal form array element.
 * @param array $form_state
 *   Drupal form state array.
 */
function _enrd_mastermind_validate_eu_legal_notice(array $element, array &$form_state) {
  if (empty($element['#value'])) {
    form_error($element, t('You must agree with the EU Legal notice statement to proceed.'));
  }
}
