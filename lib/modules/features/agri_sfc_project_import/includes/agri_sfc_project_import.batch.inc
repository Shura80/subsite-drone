<?php

/**
 * @file
 * Batch operations definition.
 */

/**
 * Callback for batch process.
 *
 * @param object $file
 *   The file object.
 * @param bool $skip_excel_validation
 *   The value determines skipping of required fields validation.
 * @param bool $simulate
 *   If true node will be not save.
 * @param array $context
 *   Array for managing data during execution.
 */
function _agri_sfc_project_import_batch_op_callback($file, $skip_excel_validation, $simulate, array &$context) {

  if (!isset($context['results']['dataset'])) {
    $context['results']['dataset'] = 0;
    $context['results']['success'] = 0;
    $context['results']['simulate'] = $simulate;
  }

  $context['results']['dataset']++;

  $path = $file->uri;
  $filename = $file->filename;
  $context['message'] = "Operation completed for file: " . $filename;

  try {
    // Include phpexcel module wrapper for PHPExcel library.
    module_load_include('inc', 'phpexcel');

    $result = phpexcel_import($path, FALSE, TRUE);
  }
  catch (Exception $e) {
    $result = FALSE;
  }

  // Excel file is not readable or not in the right format.
  if (!is_array($result) || count($result) <= 1 || !array_key_exists('PROJECT INFORMATION', $result)) {
    $context['results']['success'] = 0;
    _agri_sfc_project_import_add_error_log($filename, AGRI_SFC_PROJECT_IMPORT_INVALID_TEMPLATE);
    _agri_sfc_project_import_clear_temp();
    return;
  }

  $missing_labels = array();

  if (!$skip_excel_validation) {

    // Partners Sheet.
    $mandatory = $result['PARTNERS'];
    // Check for empty mandatory fields.
    // In Partners Sheet only a field must be filled for first parnter.
    // The other fields are filled from Project informations sheet.
    if ($mandatory[2][6] == AGRI_SFC_PROJECT_IMPORT_TEMPLATE_MANDATORY_FIELD && trim($mandatory[2][5]) == '') {
      $label = $mandatory[1][5];
      $missing_labels[] = array(
        'PARTNERS',
        t('Missing'),
        $label,
      );
    };

    $mandatory = array_intersect_key($result, drupal_map_assoc(array(
      'PROJECT INFORMATION',
      'KEYWORDS',
      'PA1',
      'PA2',
      'PA3',
      'PA4',
      'PA5',
      'PA6',
      'PA7',
      'PA8',
      'PA9',
      'PA10',
      'PA11',
      'PA12',
      'PA13',
      'PA14',
      'PA15',
      'PA16',
      'PA17',
      'PA18',
      'PA19',
      'PA20',
    )));

    // Check for empty mandatory fields.
    foreach ($mandatory as $sheet_name => $sheet) {
      foreach ($sheet as $row) {
        if ($row[2] == AGRI_SFC_PROJECT_IMPORT_TEMPLATE_MANDATORY_FIELD && trim($row[1] == '')) {
          $label = drupal_substr($row[0], 0, 50) . "...";
          $missing_labels[] = array(
            $sheet_name,
            t('Missing'),
            $label,
          );
        }
      }
    }

    if (count($missing_labels) > 0) {
      // Add a the header.
      array_unshift($missing_labels, array(
        array('data' => t('Sheet'), 'header' => TRUE),
        array('data' => t('Exception'), 'header' => TRUE),
        array('data' => t('Field'), 'header' => TRUE),
      ));
    }
  }

  // Fill Project structure.
  $project = _agri_sfc_project_import_map_fields($result);

  // Create managed File object.
  $managed_file = (object) array(
    'uid' => 1,
    'uri' => $path,
    'filemime' => file_get_mimetype($path),
    'status' => 1,
  );

  $directory = file_default_scheme() . '://' . AGRI_SFC_PROJECT_IMPORT_PUBLIC_FOLDER;
  $real_path = drupal_realpath($directory);
  // Check if directory exists.
  if (!is_dir($real_path)) {
    file_prepare_directory($real_path, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
  }

  $managed_file = file_copy($managed_file, $directory);
  $project['file'] = $managed_file;
  $project['original_filename'] = $file->filename;

  if (_agri_sfc_project_import_save_project($project, $simulate, $missing_labels)) {
    $context['results']['success'] = 1;
  }
  else {
    $context['results']['success'] = 0;
  }

  if (!$context['results']['success'] || $simulate) {
    file_delete($managed_file, TRUE);
  }
}

/**
 * Batch finished callback.
 *
 * @param bool $success
 *   TRUE of FALSE.
 * @param array $results
 *   Optional array.
 * @param array $operations
 *   Operations array.
 */
function _agri_sfc_project_import_batch_finished_callback($success, array $results, array $operations) {

  global $base_url;
  _agri_sfc_project_import_clear_temp();

  if ($results['simulate']) {
    drupal_set_message(t('Simulation completed.'));
  }
  else {
    if ($results['success'] == 1) {
      drupal_set_message(t('Data uploaded successfully'));
      drupal_goto($base_url . '/sfc-projects');
    }
    else {
      drupal_set_message(t('Error while importing data.'), 'error');
    }
  }
}
