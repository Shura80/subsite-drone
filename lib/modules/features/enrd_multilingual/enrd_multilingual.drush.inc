<?php

/**
 * @file
 * Drush commands for ENRD multilingual supports.
 */

/**
 * Implements hook_drush_command().
 */
function enrd_multilingual_drush_command() {
  $items = array();

  $items['upgrade-title-field'] = array(
    'description' => "Upgrades all title filed of nodes of the specified content type from Content translation to Entity translation.",
    'arguments' => array(
      'content_type' => 'Content type of nodes to be upgraded.',
    ),
    'aliases' => array('up-title'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  $items['etu-purge-stale'] = array(
    'description' => "Delete all yet migrated nodes with entity translation upgrade.",
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  $items['alias-force-language'] = array(
    'description' => "Force aliases to be Language Neutral of not yet translated nodes.",
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  return $items;
}

/**
 * Run the batch upgrading title field nodes of the specified content_type.
 *
 * @param string $content_type
 *   The content type of which the nodes shall be upgraded.
 *
 * @return bool
 *   TRUE if no op was executed.
 */
function drush_enrd_multilingual_upgrade_title_field($content_type = '') {
  // Get all installed content types.
  $available_types = array();
  $available_types_chose = array();
  $available_types_str = '';
  foreach (node_type_get_types() as $type) {
    $available_types[$type->type] = $type->type;
    $available_types_chose[$type->type] = $type->name;
    if (drupal_strlen($available_types_str) > 0) {
      $available_types_str .= ', ';
    }
    $available_types_str .= $type->type;
  }

  // If argument content_type is empty, prompt user for content type.
  if (!$content_type) {
    $content_type = drush_choice($available_types_chose, dt('Choose the content type of the nodes needs the new title field:'));
  }

  // Do content type argument checks.
  if (!$content_type) {
    return TRUE;
  }
  if (drupal_strlen($available_types_str) == 0) {
    return drush_set_error(dt('Title fields cannot be updated on a content type has been installed.'));
  }
  if (!in_array($content_type, $available_types)) {
    return drush_set_error(dt('"@content_type" is not a valid content type machine name. Please use one of these installed content types as argument: @available_types_str.', array('@content_type' => $content_type, '@available_types_str' => $available_types_str)));
  }

  // Title substitution.
  $entity_type = 'node';
  $legacy_field = 'title';

  // Verify istances of field.
  $info = title_field_replacement_info($entity_type, $legacy_field);
  if (!$info || is_null(field_info_instance($entity_type, $info['field']['field_name'], $content_type))) {
    title_field_replacement_toggle($entity_type, $content_type, $legacy_field);
  }

  // Batch of fields synchronization.
  $batch = array(
    'title' => t('Replacing field values for %field', array('%field' => $legacy_field)),
    'operations' => array(
      array('title_field_replacement_batch', array(
        $entity_type,
        $content_type,
        $legacy_field,
      ),
      ),
    ),
    'file' => drupal_get_path('module', 'title') . '/title.module',
  );
  batch_set($batch);

  drush_backend_batch_process();
  return TRUE;
}

/**
 * Run the procedure to delete unpublished nodes after ET upgrade.
 */
function drush_enrd_multilingual_etu_purge_stale() {
  $nids = db_select('entity_translation_upgrade_history', 'etuh')
    ->condition('etuh.complete', 1)
    ->fields('etuh', array('nid'))
    ->execute()->fetchCol();

  if (!empty($nids)) {
    $deleted = 0;
    foreach (array_chunk($nids, 100) as $chunk_nids) {
      node_delete_multiple($chunk_nids);
      $deleted += count($chunk_nids);

      // Remove from history.
      db_delete('entity_translation_upgrade_history')
        ->condition('nid', $chunk_nids, 'IN')
        ->execute();

      _enrd_mastermind_drush_print_progress($deleted / count($nids));
    }

    drush_log(dt('Deleted !count stale translation nodes.', array('!count' => count($nids))), 'success');
  }
}

/**
 * Force aliases to be Language Neutral of not yet translated nodes.
 */
function drush_enrd_multilingual_alias_force_language() {

  $query = db_query("
UPDATE {url_alias} ua
INNER JOIN {node} n ON ua.source = CONCAT('node/', n.nid)
SET ua.language = 'und'
WHERE ua.language = 'en' AND ua.source LIKE 'node/%'");

  drush_log(dt('!num aliases forced to be language neutral.', array('!num' => $query->rowCount())), 'success');
}
