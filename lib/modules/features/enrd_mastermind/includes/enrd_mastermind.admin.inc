<?php

/**
 * @file
 * Custom configuration forms for ENRD settings.
 */

/**
 * Form to configure last udpate skipped paths.
 */
function enrd_mastermind_lastupdate_info_paths_form($form, &$form_state) {

  // Default form values.
  $default_skipped_paths = implode(PHP_EOL, module_invoke_all('last_update_ignore_list'));
  $custom_skipped_paths = variable_get('enrd_lastupdate_custom_skipped_paths', array());
  isset($custom_skipped_paths) ? $custom_skipped_paths = implode(PHP_EOL, $custom_skipped_paths) : NULL;

  $form['enrd_lastupdate'] = [
    '#type' => 'fieldset',
    '#title' => t('Configure Last update ignored paths'),
    '#description' => t('This form allows to add a list paths that should be ignored when displaying last update info in footer block. These paths will display the date of the most recent visit instead of the real entity info (published date, last access date, etc...)'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  ];

  $form['enrd_lastupdate']['enrd_lastupdate_default_skipped_paths'] = [
    '#type' => 'textarea',
    '#default_value' => $default_skipped_paths,
    '#title' => t('Default skipped paths'),
    '#description' => t('These paths are already excluded at system level and cannot be modified.'),
    '#disabled' => TRUE,
  ];

  $form['enrd_lastupdate']['enrd_lastupdate_custom_skipped_paths'] = [
    '#type' => 'textarea',
    '#default_value' => $custom_skipped_paths,
    '#title' => t('Custom paths to skip for last udpate footer info block'),
    '#description' => t('Add here a list of paths that should use default last update info. Enter one path per line.'),
  ];

  $form['submit'] = [
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  ];

  return $form;
}

/**
 * Custom form submit for enrd_mastermind_lastupdate_paths_form.
 *
 * @param mixed $form
 *   Drupal form array.
 * @param mixed $form_state
 *   Drupal form state array.
 */
function enrd_mastermind_lastupdate_info_paths_form_submit($form, &$form_state) {
  // Save form variable and return a status message.
  $enrd_lastupdate_custom_skipped_paths = preg_split('/\r\n|\n|\r/', trim($form_state['values']['enrd_lastupdate_custom_skipped_paths']), -1, PREG_SPLIT_NO_EMPTY);
  variable_set('enrd_lastupdate_custom_skipped_paths', $enrd_lastupdate_custom_skipped_paths);
  drupal_set_message(t('Configuration has been successfully updated.'));
}

/**
 * Form to configure a centralized privacy statement URL.
 */
function enrd_mastermind_privacy_statement_form($form, &$form_state) {

  $form['enrd_privacy_fieldset'] = [
    '#type' => 'fieldset',
    '#title' => t('ENRD Privacy Statement'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  ];

  $form['enrd_privacy_fieldset']['enrd_mastermind_privacy_statement'] = [
    '#type' => 'textfield',
    '#size' => 100,
    '#title' => t('Configure ENRD Privacy Statement URL'),
    '#description' => t('This field allows to set a custom privacy statement definition. It could be either an existing path (like "legal-notice/privacy-statement" or "node/123") or a filename (like "enrd-privacy-statement-policy.pdf"). If not set, the default EU commission privacy statement URL is used.'),
    '#default_value' => variable_get('enrd_mastermind_privacy_statement', ENRD_MASTERMIND_EU_LEGAL_NOTICE_URL),
    '#element_validate' => array('_enrd_mastermind_privacy_statement'),
  ];

  return system_settings_form($form);
}

/**
 * Validate function for EU Legal Notice field.
 *
 * @param array $element
 *   Drupal form element array.
 * @param array $form_state
 *   Drupal form_state array.
 */
function _enrd_mastermind_privacy_statement(array $element, array &$form_state) {

  // Check if a valid local filename is given.
  if (file_exists(file_default_scheme() . '://' . $element['#value'])) {
    $file_public_path = (variable_get('file_public_path', conf_path() . '/files'));
    // Save relative path of the given filename.
    $form_state['values']['enrd_mastermind_privacy_statement'] = $element['#value'] = $file_public_path . '/' . $element['#value'];
    drupal_set_message(t('Set a local file as privacy statement.'));
  }
  // Check if a valid local system url/alias is given.
  elseif (drupal_lookup_path('source', $element['#value']) || drupal_lookup_path('alias', $element['#value'])) {
    // Save the alias if it exists for a given system url.
    $form_state['values']['enrd_mastermind_privacy_statement'] = $element['#value'] = drupal_get_path_alias($element['#value']);
    drupal_set_message(t('Set a local path as privacy statement.'));
  }
  // For all other cases return a form error.
  else {
    form_error($element, t('You must enter a valid existing path or filename'));
  }
}
