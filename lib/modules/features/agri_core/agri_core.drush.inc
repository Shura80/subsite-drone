<?php

/**
 * @file
 * Drush commands for import keywords from .csv.
 */

/**
 * Implements drush_drush_help().
 */
function agri_core_drush_help($command) {

  switch ($command) {
    case 'drush:agri-core-import-macro-keywords':
      return dt('Import keyword(s) from file .csv');

    case 'drush:agri-core-collab-area-set-admin-rid':
      return dt('Assign default admin role when creating a collaborative area.');

    case 'drush:agri-core-collab-area-enable-menu':
      return dt('Enable OG smenu for existing collaborative area nodes.');

    case 'drush:agri-core-reset-bundle-solr-search':
      return dt('Reset the bundles to index from Solr Search.');

    case 'drush:override-multisite-components':
      return dt('Override some Multisite core components.');
  }
}

/**
 * Implements hook_drush_command().
 */
function agri_core_drush_command() {

  $items = array();

  $items['agri-core-import-macro-keywords'] = array(
    'description' => dt('Import macrocategories keyword(s) from file .csv'),
    'aliases' => array('agri-imk'),
    'callback' => 'drush_agri_import_macro_keywords_callback',
    'allow-additional-options' => TRUE,
    'options' => array(
      'file' => 'File',
    ),
  );

  $items['agri-core-update-name-keywords'] = array(
    'description' => dt('Update name of keyword(s) from file .csv'),
    'callback' => 'drush_agri_update_name_keywords_callback',
  );

  $items['agri-core-import-keywords'] = array(
    'description' => dt('Import keyword(s) from file .csv'),
    'aliases' => array('agri-ik'),
    'callback' => 'drush_agri_import_keywords_callback',
  );

  $items['agri-core-collab-area-set-admin-rid'] = array(
    'description' => dt('Assign default admin role when creating an administration.'),
    'aliases' => array('agri-colrid'),
    'callback' => 'drush_agri_core_collab_set_admin_rid',
  );

  $items['agri-core-collab-area-enable-menu'] = array(
    'description' => dt('Enable OG smenu for existing collaborative area nodes.'),
    'aliases' => array('agri-col-ogmenu'),
    'callback' => 'drush_agri_core_collab_area_enable_menu',
  );

  $items['override-multisite-components'] = array(
    'description' => 'Override some Multisite core components.',
    'aliases' => array('omc'),
  );

  $items['agri-core-reset-bundle-solr-search'] = array(
    'description' => 'Reset the bundles to index from Solr Search.',
    'callback' => 'drush_agri_core_reset_bundle_solr_callback',
  );

  return $items;

}

/**
 * Define selection of file(s) to import.
 *
 * @param string $file
 *   The $file selected.
 */
function drush_agri_import_macro_keywords_callback($file = NULL) {
  // Start process.
  drush_print('Checking options...');

  $options = drush_agri_core_import_get_options();

  if (!isset($file)) {
    $choice_file = drush_choice($options, dt('Select the file you want to import'));
  }

  if ($choice_file === FALSE) {
    return;
  }
  else {
    drush_print($options[$choice_file]);
    _agri_core_drush_import_macrokeywords($options[$choice_file]);
  }
}

/**
 * Callback for update name of keyword(s) from file .csv.
 */
function drush_agri_update_name_keywords_callback() {
  _agri_core_drush_update_name_keywords();
}

/**
 * Callback for set batch operation.
 */
function drush_agri_import_keywords_callback() {
  agri_core_drush_batch_config();
}

/**
 * Return the options list.
 *
 * @return array
 *   Return an option list for select operation to execute.
 */
function drush_agri_core_import_get_options() {
  return glob(drupal_get_path('module', 'agri_core') . '/csv/*.csv');
}

/**
 * Provides progress bar.
 *
 * @param float $ratio
 *   The value to be represented in the progress bar.
 */
function _drush_print_progress($ratio) {
  $percentage = floor($ratio * 100) . '%';
  $columns = drush_get_context('DRUSH_COLUMNS', 80);
  // Subtract 8 characters for the percentage, brackets, spaces and arrow.
  $progress_columns = $columns - 8;
  // If ratio is 1 (complete), the > becomes a = to make a full bar.
  $arrow = ($ratio < 1) ? '>' : '=';
  // Print a new line if ratio is 1 (complete). Otherwise, use a CR.
  $line_ending = ($ratio < 1) ? "\r" : "\n";

  // Determine the current length of the progress string.
  $current_length = floor($ratio * $progress_columns);
  $progress_string = str_pad('', $current_length, '=');

  $output = '[';
  $output .= $progress_string . $arrow;
  $output .= str_pad('', $progress_columns - $current_length);
  $output .= ']';
  $output .= str_pad('', 5 - drupal_strlen($percentage)) . $percentage;
  $output .= $line_ending;

  print $output;
}

/**
 * Helper function to set administrator role rid in collaborative areas.
 */
function drush_agri_core_collab_set_admin_rid() {

  $data = db_select('og_role', 'ogr')
    ->fields('ogr', array('rid', 'name'))
    ->condition('group_bundle', 'collaborative_area')
    ->condition('name', 'administrator member')
    ->execute()->fetchAssoc();

  $rid = $data['rid'];

  variable_set('og_group_manager_default_rids_node_collaborative_area',
    array($rid => $rid)
  );

  drush_print("Set role when creating a collaborative area: " . $data['name']);
}

/**
 * Helper function enable OG menus in collaborative area nodes.
 */
function drush_agri_core_collab_area_enable_menu() {
  // Get nids of existing collaborative areas to enable OG menu for them.
  $query = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->condition('type', 'collaborative_area')
    ->execute();

  while ($result = $query->fetchAssoc()) {
    $nids[] = $result['nid'];
  }

  foreach ($nids as $nid) {

    $node = node_load($nid);
    $menu_name = "menu-og-$nid";

    db_insert('og_menu')
      ->fields(array(
        'menu_name' => $menu_name,
        'gid' => $nid,
        'group_type' => 'node',
      ))
      ->execute();

    menu_save(array(
      'menu_name' => 'menu-og-' . $nid,
      'title' => $node->title,
      'description' => 'OG Menu for ' . check_plain($node->title),
    ));

    module_load_include('module', 'og_menu_default_links', 'og_menu_default_links.module');
    _og_menu_default_links_set_default_links($menu_name, 'update');

    drush_print("Enabled OG menu for " . $node->title);
  }
}

/**
 * Override some Multisite core components.
 */
function drush_agri_core_override_multisite_components() {
  _agri_core_overrides_all();
}

/**
 * Reset the bundles to index from Solr Search.
 */
function drush_agri_core_reset_bundle_solr_callback() {
  _agri_core_apache_solr_set_bundle_to_index();
}

/**
 * Provides progress bar.
 *
 * @param int $ratio
 *   Operation progress in percentage.
 */
function _agri_core_drush_print_progress($ratio) {
  $percentage = floor($ratio * 100) . '%';
  $columns = drush_get_context('DRUSH_COLUMNS', 80);
  // Subtract 8 characters for the percentage, brackets, spaces and arrow.
  $progress_columns = $columns - 8;
  // If ratio is 1 (complete), the > becomes a = to make a full bar.
  $arrow = ($ratio < 1) ? '>' : '=';
  // Print a new line if ratio is 1 (complete). Otherwise, use a CR.
  $line_ending = ($ratio < 1) ? "\r" : "\n";
  // Determine the current length of the progress string.
  $current_length = floor($ratio * $progress_columns);
  $progress_string = str_pad('', $current_length, '=');
  $output = '[';
  $output .= $progress_string . $arrow;
  $output .= str_pad('', $progress_columns - $current_length);
  $output .= ']';
  $output .= str_pad('', 5 - drupal_strlen($percentage)) . $percentage;
  $output .= $line_ending;
  print $output;
}
