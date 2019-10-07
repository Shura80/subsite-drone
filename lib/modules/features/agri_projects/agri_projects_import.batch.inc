<?php

/**
 * @file
 * Batch operations definition.
 */

define('PROJECT_TYPE', 'project');
define('NEEDS_FOR_RESEARCH_TYPE', 'needs_for_research_from_practice');
define('DEFAULT_USER_IMPORT', 'andresg');

/**
 * Callback for batch process.
 *
 * @param string $row
 *   The processing row.
 * @param string $type
 *   The processing row.
 * @param array $context
 *   Array for managing data during execution.
 */
function agri_projects_batch_op_callback($row, $type, array &$context) {

  if (!isset($context['results']['dataset'])) {
    $context['results']['dataset'] = 0;
    $context['results']['success'] = 0;
    $context['results']['fail'] = 0;
  }
  $context['results']['dataset']++;

  switch ($type) {
    case PROJECT_TYPE:
      _agri_projects_set_mapping_project($row, $context);
      return;

    case NEEDS_FOR_RESEARCH_TYPE:
      _agri_projects_set_mapping_needs_for_research($row, $context);
      return;
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
function agri_projects_batch_finished_callback($success, array $results, array $operations) {

  if ($success) {
    drush_log('Success: ' . $results['success'] . '/' . $results['dataset'], 'success');
    if ($results['fail'] != 0) {
      drush_log('Fail: ' . $results['fail'], 'error');
    }
    drush_print('Import completed.');
  }
  else {
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array(
      '%error_operation' => $error_operation[0],
      '@arguments' => print_r($error_operation[1], TRUE),
    ));
    drush_log($message, 'error');
  }

}

/**
 * Mapping field content type "project".
 *
 * @param string $row
 *   Csv row to process.
 * @param array $context
 *   Array for managing data during execution.
 */
function _agri_projects_set_mapping_project($row, array &$context) {

  $user_info = explode(';', $row[0]);
  foreach ($user_info as $key => $value) {
    $user_info[$key] = trim($value);
  }

  $user_info['uid'] = isset($user_info[2]) ? _agri_projects_get_user($user_info[2]) : _agri_projects_get_user();

  $all_fields = field_info_fields();

  try {
    $e = entity_create('node', array(
      'type' => PROJECT_TYPE,
    ));
    $e->uid = $user_info['uid'];
    $e->status = 1;
    $e->comment = 0;

    $entity = entity_metadata_wrapper('node', $e);
    $entity->title = $row[1];

    // Set the cck field.
    $entity->field_projects_name->set($user_info[0]);
    $entity->field_projects_surname->set($user_info[1]);
    $entity->field_core_email->set($user_info[2]);
    $entity->field_proj_title_eng->set($row[2]);
    $entity->field_proj_website->set(array(
      'url' => $row[3],
    ));

    $allowed_values = list_allowed_values($all_fields['field_projects_language']);
    foreach ($allowed_values as $key => $value) {
      if ($value == trim($row[4])) {
        $entity->field_projects_language->set($key);
      }
    }

    $entity->field_proj_problems->set($row[5]);
    $entity->field_proj_problems_eng->set($row[6]);
    $entity->field_proj_desc->set($row[7]);
    $entity->field_proj_desc_eng->set($row[8]);
    $entity->field_proj_results->set($row[9]);
    $entity->field_proj_results_eng->set($row[10]);

    $allowed_values = list_allowed_values($all_fields['field_proj_funding_source_list']);
    foreach ($allowed_values as $key => $value) {
      if ($value == trim($row[14])) {
        $entity->field_proj_funding_source_list->set($key);
      }
    }

    $entity->field_proj_rp_acronym->set($row[15]);
    $entity->field_proj_coordinator->set($row[16]);
    $entity->field_proj_contact_e_mail->set($row[17]);
    $entity->field_proj_rp_partners->set($row[18]);

    if (strtotime($row[20])) {
      $entity->field_proj_starting_date->set(strtotime($row[20]));
    }

    if ($row[21] != '') {
      $entity->field_proj_og_project_status->set($row[21]);
    }

    $entity->field_proj_og_budget->set($row[22]);
    $entity->field_proj_og_eu_contribution->set($row[23]);

    if ($row[25] != '') {
      $entity->field_proj_og_cross_border->set($row[25]);
    }

    $entity->field_proj_additional_info->set($row[26]);

    $keywords = explode(';', $row[12]);
    foreach ($keywords as $value) {
      $term = taxonomy_get_term_by_name($value);
      foreach ($term as $term_value) {
        $entity->field_core_keywords[] = $term_value->tid;
      }
    }

    $agricultural_sectors = explode(';', $row[13]);
    foreach ($agricultural_sectors as $value) {
      $term = taxonomy_get_term_by_name($value);
      foreach ($term as $term_value) {
        $entity->field_core_agricultural_sectors[] = $term_value->tid;
      }
    }

    $geographical_area = explode(';', $row[24]);
    foreach ($geographical_area as $value) {
      $term = taxonomy_get_term_by_name($value);
      foreach ($term as $term_value) {
        $entity->field_proj_geographical_area[] = $term_value->tid;
      }
    }

    // Save the node.
    $entity->save();
    $context['results']['success']++;
  }
  catch (Exception $e) {
    $context['results']['fail']++;
    drush_print($e->getMessage());
  }

}

/**
 * Mapping field content type "project".
 *
 * @param string $row
 *   Csv row to process.
 * @param array $context
 *   Array for managing data during execution.
 */
function _agri_projects_set_mapping_needs_for_research($row, array &$context) {

  $all_fields = field_info_fields();

  $user_info['uid'] = _agri_projects_get_user($row[8]);

  try {
    $e = entity_create('node', array(
      'type' => NEEDS_FOR_RESEARCH_TYPE,
    ));
    $e->uid = $user_info['uid'];
    $e->status = 1;
    $e->comment = 0;

    $entity = entity_metadata_wrapper('node', $e);
    $entity->title = $row[0];
    $entity->body->value->set($row[1]);

    // Set the cck field.
    $entity->field_core_description_eng->value->set($row[2]);
    $entity->field_projects_name->set($row[6]);
    $entity->field_projects_surname->set($row[7]);
    $entity->field_core_email->set($row[8]);

    $allowed_values = list_allowed_values($all_fields['field_projects_interested_in']);
    foreach ($allowed_values as $key => $value) {
      if ($value == trim($row[9])) {
        $entity->field_projects_interested_in->set($key);
      }
    }

    ($row[10] == 'Yes') ? $entity->field_projects_interested->set(TRUE) : $entity->field_projects_interested->set(FALSE);

    $allowed_values = list_allowed_values($all_fields['field_projects_language']);
    foreach ($allowed_values as $key => $value) {
      if ($value == trim($row[11])) {
        $entity->field_projects_language->set($key);
      }
    }

    $entity->field_core_additional_info->set($row[13]);

    // Set the cck taxonomy.
    $geographical_area = explode(';', $row[3]);
    foreach ($geographical_area as $value) {
      $term = taxonomy_get_term_by_name($value);
      foreach ($term as $term_value) {
        $entity->field_core_geographical_area[] = $term_value->tid;
      }
    }

    $keywords = explode(';', $row[5]);
    foreach ($keywords as $value) {
      $term = taxonomy_get_term_by_name($value);
      foreach ($term as $term_value) {
        $entity->field_core_keywords[] = $term_value->tid;
      }
    }

    // Save the node.
    $entity->save();
    $context['results']['success']++;
  }
  catch (Exception $e) {
    $context['results']['fail']++;
    drush_print($e->getMessage());
  }

}

/**
 * Get user info.
 *
 * @param string $email
 *   The user info string to get user detail from drupal.
 *
 * @return int
 *   The user id.
 */
function _agri_projects_get_user($email = NULL) {

  $query = db_select('users', 'u');

  if (!isset($email) || $email == '') {
    $query->condition('u.name', DEFAULT_USER_IMPORT);
  }
  else {
    $query->condition('u.init', $email, '=');
  }

  $query->fields('u', array('uid'));

  $result = $query->execute();
  foreach ($result as $record) {
    $author_uid = $record->uid;
  }

  return is_null($author_uid) ? 1 : $author_uid;

}
