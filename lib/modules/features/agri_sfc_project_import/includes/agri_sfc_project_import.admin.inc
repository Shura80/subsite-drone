<?php

/**
 * @file
 * agri_sfc_project_import.admin.inc
 */

/**
 * Implements hook_form().
 */
function agri_sfc_project_import_log_form($form, &$form_state) {

  if (isset($form_state['storage']) && $form_state['storage']['ask_confirm']) {
    $question = t("Are you sure you want to delete all messages in the log?");
    $path = "admin/reports/sfc-importer/log";
    $description = t("Warning: this action cannot be undone.");
    $yes = t("Yes, delete all");
    $no = t("Cancel");

    return confirm_form($form, $question, $path, $description, $yes, $no);
  }

  else {
    $form['log'] = array(
      '#title' => t('SFC Logs'),
      '#type' => 'fieldset',
    );

    $form['log']['reset'] = array(
      '#type' => 'submit',
      '#value' => t('Clear all messages'),
    );

    $form += _agri_sfc_project_import_get_log();

    $form['pager'] = array(
      '#markup' => theme('pager'),
    );
  }

  return $form;
}

/**
 * Implements hook_form_submit().
 */
function agri_sfc_project_import_log_form_submit($form, &$form_state) {

  if ($form_state['clicked_button']['#value'] == 'Clear all messages') {
    $form_state['rebuild'] = TRUE;
    $form_state['storage']['ask_confirm'] = TRUE;
  }
  elseif (isset($form_state['values']['confirm']) && $form_state['values']['confirm']) {
    db_delete('agri_sfc_project_import_log')->execute();
    $msg = t("All messages have been deleted.");
    drupal_set_message($msg);
  }
}

/**
 * Implements hook_form().
 */
function agri_sfc_project_config_form($form, &$form_state) {

  $funding_source_list = _agri_sfc_project_import_get_default_funding_list();
  $options = list_allowed_values(field_info_field('field_proj_funding_source_list'));
  $default_value = variable_get('agri_sfc_project_funding_source_map', array());

  $form['main_funding_source'] = array(
    '#title' => t('Main funding suorce'),
    '#type' => 'fieldset',
  );

  foreach ($funding_source_list as $funding_source_key => $funding_source_option) {
    $form['main_funding_source'][$funding_source_key] = array(
      '#type' => 'select',
      '#title' => $funding_source_option,
      '#options' => $options,
      '#empty_option' => t('- Select -'),
      '#required' => TRUE,
      '#default_value' => $default_value[$funding_source_key],
    );
  }

  $form['main_funding_source']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

/**
 * Implements hook_form_submit().
 */
function agri_sfc_project_config_form_submit($form, &$form_state) {
  $funding_source_list = _agri_sfc_project_import_get_default_funding_list();
  foreach ($funding_source_list as $funding_source_key => $funding_source_option) {
    $value[$funding_source_key] = $form_state['values'][$funding_source_key];
  }

  variable_set('agri_sfc_project_funding_source_map', $value);
  drupal_set_message(t('Configuration saved correctly.'));
}

/**
 * Retrieves error log from "agri_sfc_project_import_log" table.
 *
 * @return array
 *   Return the last 50 record.
 */
function _agri_sfc_project_import_get_log() {

  $header = array(
    array('data' => t('Date'), 'field' => 'timestamp', 'sort' => 'desc'),
    array('data' => t('User'), 'field' => 'user'),
    array('data' => t('Filename'), 'field' => 'file_name'),
    array('data' => t('Message'), 'field' => 'message'),
    array('data' => t('Details')),
  );

  $query = db_select('agri_sfc_project_import_log', 'log')
    ->extend('PagerDefault')
    ->extend('TableSort');

  $query = $query
    ->fields('log')
    ->limit(25)
    ->orderByHeader($header);
  $result = $query->execute();

  $rows = array();

  if (!empty($result)) {
    foreach ($result as $record) {
      $rows[] = array(
        'timestamp' => format_date($record->timestamp, 'long'),
        'user' => theme('username', array('account' => user_load_by_name($record->user))),
        'filename' => $record->file_name,
        'message' => $record->message,
        'link' => l(t('Details'), 'admin/reports/sfc-importer/log/' . $record->id),
      );
    }
  }

  $build['log_table'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
    '#empty' => t('No log messages available.'),
  );

  return $build;
}

/**
 * Page callback: Displays details about a specific database log message.
 *
 * @param int $id
 *   Unique ID of the database log message.
 *
 * @return array|string
 *   If the ID is located in the Database Logging table, a build array in the
 *   format expected by drupal_render(); otherwise, an empty string.
 *
 * @see agri_sfc_project_import_menu()
 */
function agri_sfc_project_import_log_details($id) {

  $result = db_select('agri_sfc_project_import_log', 'log')
    ->fields('log')
    ->condition('id', (int) $id)
    ->execute()
    ->fetchObject();

  if ($sfc_log = $result) {
    $rows = array(
      array(
        array('data' => t('Date'), 'header' => TRUE),
        format_date($sfc_log->timestamp, 'long'),
      ),
      array(
        array('data' => t('User'), 'header' => TRUE),
        theme('username', array('account' => user_load_by_name($sfc_log->user))),
      ),
      array(
        array('data' => t('Filename'), 'header' => TRUE),
        check_plain($sfc_log->file_name),
      ),
      array(
        array('data' => t('Message'), 'header' => TRUE),
        check_plain($sfc_log->message),
      ),
    );

    $build['log_table'] = array(
      '#theme' => 'table',
      '#rows' => $rows,
    );
    $build['details_table'] = array(
      '#theme' => 'table',
      '#rows' => unserialize($sfc_log->details),
    );

    return $build;
  }
  else {
    return '';
  }
}
