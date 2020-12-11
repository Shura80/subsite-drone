<?php

/**
 * @file
 * Code to add custom form element "Legal notice".
 */

/**
 * Custom function to render Legal notice & Privacy Policy checkboxes.
 *
 * @param array $options
 *   An array with the additional options for the element.
 *
 * @return array
 *   A Drupal renderable array element.
 */
function _enrd_mastermind_eu_legal_notice_checkbox($options = array()) {

  $element = [
    '#type' => 'container',
    'eu_legal_notice' => [
      '#type' => 'checkbox',
      '#title' => t('By checking this box, you acknowledge that you have read and understood the !url. !req', [
        '!url' => l(
          t('ENRD Privacy Statement'),
          variable_get('enrd_mastermind_privacy_statement', ENRD_MASTERMIND_EU_LEGAL_NOTICE_URL),
          ['attributes' => ['target' => '_blank']]),
        // Show required marker at the end of the line.
        '!req' => theme('form_required_marker'),
      ]),
      '#attributes' => [
        'class' => ['form-legal-notice-disclaimer'],
      ],
      '#element_validate' => ['_enrd_mastermind_validate_eu_legal_notice'],
    ],
    'privacy_policy' => [
      '#type' => 'checkbox',
      '#title' => t('I agree that my data may be collected and used for the purposes mentioned in the privacy statement. !req', [
        '!req' => theme('form_required_marker'),
      ]) . _enrd_mastermind_privacy_policy_icon(),
      '#attributes' => [
        'class' => ['form-privacy-statement-disclaimer'],
      ],
      '#element_validate' => ['_enrd_mastermind_validate_privacy_statement'],
    ],
  ];

  // Add more options or overwrite existing ones.
  if (!empty($options)) {
    $element = array_merge($element, $options);
  }

  return $element;
}

/**
 * Custom function to create the "Privacy Policy" info icon.
 *
 * @return string
 *   The rendered HTML for the icon.
 */
function _enrd_mastermind_privacy_policy_icon() {
  $element = [
    '#type' => 'html_tag',
    '#title' => t('Privacy Policy mail disclaimer'),
    '#tag' => 'span',
    '#attributes' => [
      'class' => ['privacy-policy-icon', 'glyphicon', 'glyphicon-info-sign'],
      'title' => t('If you want your data to be removed from the ENRD contacts database and therefore, be excluded from future communication on our activities please send us an email at: !email.', ['!email' => ENRD_MASTERMIND_PRIVACY_POLICY_EMAIL]),
    ],
  ];

  return drupal_render($element);
}

/**
 * Validate function for EU Legal Notice checkbox.
 *
 * @param array $element
 *   Drupal form array element.
 * @param array $form_state
 *   Drupal form state array.
 */
function _enrd_mastermind_validate_eu_legal_notice(array $element, array &$form_state) {
  if (empty($element['#value'])) {
    form_error($element, t('You must agree with the ENRD Privacy Statement to proceed.'));
  }
}

/**
 * Validate function for the Privacy Statement checkbox.
 *
 * @param array $element
 *   Drupal form array element.
 * @param array $form_state
 *   Drupal form state array.
 */
function _enrd_mastermind_validate_privacy_statement(array $element, array &$form_state) {
  if (empty($element['#value'])) {
    form_error($element, t('You must agree with the Collection of Data Statement to proceed.'));
  }
}
