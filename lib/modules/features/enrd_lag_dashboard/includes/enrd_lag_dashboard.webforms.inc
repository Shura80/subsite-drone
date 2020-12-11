<?php

/**
 * @file
 * Code for ENRD LAG Database webform functionalities.
 */

/**
 * Retrieve lists of submissions for a given webform.
 */
function enrd_lag_dashboard_results_submissions($node) {
  global $user;

  module_load_include('inc', 'webform', 'includes/webform.submissions');
  $webform = entity_uuid_load('node', array(ENRD_LAG_DATABASE_LAG_CONTACT_UUID));
  $webform = reset($webform);

  $result = _enrd_lag_dashboard_get_submissions($node->nid, ENRD_LAG_DATABASE_LAG_CONTACT_UUID);

  $header = $result['header'];
  $submissions = $result['rows'];

  $count = webform_get_submission_count($webform->nid, NULL, NULL);
  $operation_column = end($header);
  $operation_total = $operation_column['colspan'];

  $rows = array();
  foreach ($submissions as $sid => $submission) {
    $row = array(
      $submission->is_draft ? t('@serial (draft)', array('@serial' => $submission->serial)) : $submission->serial,
      format_date($submission->submitted, 'short'),
    );

    // Custom LAG fields.
    $coop_offer = entity_load('node', array($submission->coop_offer));
    $row[] = l(reset($coop_offer)->title, drupal_get_path_alias("node/$submission->coop_offer"));
    $row[] = l($submission->your_email, "mailto:$submission->your_email");

    $row[] = l(t('View'), "node/$webform->nid/submission/$sid");
    $operation_count = 1;
    // No need to call this multiple times, just reference this in a variable.
    $destination = drupal_get_destination();
    if (webform_submission_access($webform, $submission, 'edit', $user)) {
      $row[] = l(t('Edit'), "node/$webform->nid/submission/$sid/edit", array('query' => $destination));
      $operation_count++;
    }
    if (webform_submission_access($webform, $submission, 'delete', $user)) {
      $row[] = l(t('Delete'), "node/$webform->nid/submission/$sid/delete", array('query' => $destination));
      $operation_count++;
    }
    if ($operation_count < $operation_total) {
      $row[count($row) - 1] = array(
        'data' => $row[count($row) - 1],
        'colspan' => $operation_total - $operation_count + 1,
      );
    }
    $rows[] = $row;
  }

  $element['#node'] = $node;
  $element['#submissions'] = $submissions;
  $element['#total_count'] = $count;
  $element['#attached']['library'][] = array('webform', 'admin');
  $element['table']['#theme'] = 'table';
  $element['table']['#header'] = $header;
  $element['table']['#rows'] = $rows;
  $element['table']['#empty'] = t('No items available');
  $element['table']['#operation_total'] = $operation_total;
  $element['pager']['#theme'] = 'pager';

  return drupal_render($element);

}

/**
 * Retrieve lists of submissions for a given webform.
 */
function enrd_lag_dashboard_results_submissions_top() {

  module_load_include('inc', 'webform', 'includes/webform.submissions');
  $webform = entity_uuid_load('node', array(ENRD_LAG_DATABASE_LAG_CONTACT_UUID));
  $webform = reset($webform);

  $result = _enrd_lag_dashboard_get_submissions_top(ENRD_LAG_DATABASE_LAG_CONTACT_UUID);
  $header = $result['header'];
  $submissions = $result['rows'];
  $count = webform_get_submission_count($webform->nid, NULL, NULL);
  $rows = array();

  foreach ($submissions as $submission) {
    $row = array();
    // Custom LAG fields.
    if ($lag = entity_load('node', array($submission->lag))) {
      $row[] = l(reset($lag)->title, drupal_get_path_alias("node/$submission->lag"));
      $row[] = $submission->count_submissions;
      $rows[] = $row;
    };
  }

  $element['#total_count'] = $count;
  $element['#attached']['library'][] = array('webform', 'admin');
  $element['table']['#theme'] = 'table';
  $element['table']['#header'] = $header;
  $element['table']['#rows'] = $rows;
  $element['table']['#empty'] = t('No items available');
  $element['pager']['#theme'] = 'pager';

  return drupal_render($element);

}

/**
 * Helper function to retrieve all Webform Submissions data.
 *
 * @param string $nid
 *   The node id of the node we're looking submissions for.
 * @param string $webform_uuid
 *   The UUID of default webform used for submissions.
 *
 * @return array
 *   An array of objects containing submissions data.
 */
function _enrd_lag_dashboard_get_submissions($nid, $webform_uuid) {

  $header = array(
    array('data' => t('#'), 'field' => 'sid'),
    array('data' => t('Submitted'), 'field' => 'submitted'),
    array('data' => t('Cooperation Offer'), 'field' => 'coop_offer'),
    array('data' => t('Email'), 'field' => 'your_email'),
    array(
      'data' => t('Operations'),
      'colspan' => module_exists('print') ? 5 : 3,
    ),
  );

  $query = db_select('webform_submissions', 'ws');
  $query->addTag('enrd_webform_submissions');

  $query->addField('wsd_1', 'data', 'coop_offer');
  $query->addField('wsd_2', 'data', 'lag');
  $query->addField('wsd_3', 'data', 'your_email');
  $query->addField('u', 'name', 'username');

  $query->innerJoin('users', 'u', "ws.uid = u.uid");
  $query->innerJoin('node', 'n', "ws.nid = n.nid AND n.uuid = :webform_uuid",
    array(':webform_uuid' => $webform_uuid));
  $query->innerJoin('webform_component', 'wfc_1', "ws.nid = wfc_1.nid");
  $query->innerJoin('webform_submitted_data', 'wsd_1',
    "wfc_1.form_key = 'enrd_lag_database_contact_this_lag_coop_offer' AND wsd_1.sid = ws.sid
    AND wfc_1.cid = wsd_1.cid AND wsd_1.data IS NOT NULL");
  $query->innerJoin('webform_component', 'wfc_2', "ws.nid = wfc_2.nid");
  $query->innerJoin('webform_submitted_data', 'wsd_2',
    "wfc_2.form_key = 'enrd_lag_database_contact_this_lag_lag'
    AND wsd_2.sid = ws.sid AND wfc_2.cid = wsd_2.cid AND wsd_2.data = :nid",
    array(':nid' => $nid));
  $query->innerJoin('webform_component', 'wfc_3', "ws.nid = wfc_3.nid");
  $query->innerJoin('webform_submitted_data', 'wsd_3',
    "wfc_3.form_key = 'enrd_lag_database_contact_this_lag_your_email'
    AND wsd_3.sid = ws.sid AND wfc_3.cid = wsd_3.cid AND wsd_3.data IS NOT NULL");

  $query->fields('ws');
  $query = $query->extend('TableSort')->orderByHeader($header);
  $query = $query->extend('PagerDefault')->limit(25);

  $result = $query->execute();

  $rows = $result->fetchAllAssoc('sid');

  return array(
    'header' => $header,
    'rows' => $rows,
  );
}

/**
 * Helper function to retrieve all Webform Submissions data.
 *
 * @param string $webform_uuid
 *   The UUID of default webform used for submissions.
 *
 * @return array
 *   A keyed array containing header labels, sorting and submissions data.
 */
function _enrd_lag_dashboard_get_submissions_top($webform_uuid) {

  $header = array(
    array('data' => t('LAG'), 'field' => 'lag'),
    array('data' => t('Total submissions'), 'field' => 'count_submissions'),
  );

  $query = db_select('webform_submissions', 'ws');
  $query->addTag('enrd_webform_submissions_top');

  $query->addField('wsd_1', 'data', 'coop_offer');
  $query->addField('wsd_2', 'data', 'lag');

  $query->innerJoin('node', 'n', "ws.nid = n.nid AND n.uuid = :webform_uuid",
    array(':webform_uuid' => $webform_uuid));
  // Referenced coop offer component join.
  $query->innerJoin('webform_component', 'wfc_1', "ws.nid = wfc_1.nid");
  $query->innerJoin('webform_submitted_data', 'wsd_1',
    "wfc_1.form_key = 'enrd_lag_database_contact_this_lag_coop_offer' AND wsd_1.sid = ws.sid
    AND wfc_1.cid = wsd_1.cid AND wsd_1.data IS NOT NULL");
  // Referenced LAG component join.
  $query->innerJoin('webform_component', 'wfc_2', "ws.nid = wfc_2.nid");
  $query->innerJoin('webform_submitted_data', 'wsd_2',
    "wfc_2.form_key = 'enrd_lag_database_contact_this_lag_lag'
    AND wsd_2.sid = ws.sid AND wfc_2.cid = wsd_2.cid AND wsd_2.data IS NOT NULL");

  $query->fields('ws');
  $query->addExpression('COUNT(ws.sid)', 'count_submissions');
  $query->groupBy('lag');
  $query->orderBy('count_submissions', 'DESC');
  $query = $query->extend('TableSort')->orderByHeader($header);
  // Low limit value for testing. Set to a higher number.
  $query = $query->extend('PagerDefault')->limit(25);

  $result = $query->execute();
  $rows = $result->fetchAllAssoc('sid');

  return array(
    'header' => $header,
    'rows' => $rows,
  );
}
