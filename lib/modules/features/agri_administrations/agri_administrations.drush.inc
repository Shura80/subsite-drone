<?php

/**
 * @file
 * Drush commands to assign a default role to the user that creates a group.
 */

/**
 * Implements drush_drush_help().
 */
function agri_administrations_drush_help($command) {

  switch ($command) {
    case 'drush:agri-administrations-set-admin-rid':
      return dt('Assign default admin role when creating an administration.');
  }
}

/**
 * Implements hook_drush_command().
 */
function agri_administrations_drush_command() {

  $items = array();
  $items['agri-administrations-set-admin-rid'] = array(
    'description' => dt('Assign default admin role when creating an administration.'),
    'aliases' => array('agri-admrid'),
    'callback' => 'drush_agri_administrations_set_admin_rid',
  );

  return $items;

}

/**
 * Helper function to set administrator role rid in administrations.
 */
function drush_agri_administrations_set_admin_rid() {

  $data = db_select('og_role', 'ogr')
    ->fields('ogr', array('rid', 'name'))
    ->condition('group_bundle', 'administration')
    ->condition('name', 'administrator member')
    ->execute()->fetchAssoc();

  $rid = $data['rid'];

  variable_set('og_group_manager_default_rids_node_administration',
    array($rid => $rid)
  );

  drush_print("Set role when creating an administration: " . $data['name']);
}
