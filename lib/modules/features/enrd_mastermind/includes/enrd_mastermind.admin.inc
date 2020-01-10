<?php

/**
 * @file
 * Custom configuration form for last udpate info skipped paths.
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
