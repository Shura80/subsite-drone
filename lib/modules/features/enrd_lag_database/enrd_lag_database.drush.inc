<?php

/**
 * @file
 * Drush integration for enrd_lag_database.
 */

/**
 * Implements hook_drush_help().
 */
function enrd_lag_database_drush_help($command) {

  switch ($command) {
    case 'drush:enrd-lag-database-override-multisite-permissions':
      return dt('Override multisite permissions for standard & group users.');

    case 'drush:enrd-lag-database-set-admin-rids':
      return dt('Set default admin roles when creating a group.');
  }
}

/**
 * Implements hook_drush_command().
 */
function enrd_lag_database_drush_command() {
  $items = array();
  $items['enrd-lag-database-override-multisite-permissions'] = array(
    'description' => 'Override Multisite core permissions.',
    'aliases' => array('enrd-ov-perms'),
  );
  $items['enrd-lag-database-set-admin-rids'] = array(
    'description' => dt('Assign default admin roles in LAG Database groups'),
    'aliases' => array('enrd-set-admins'),
  );

  return $items;
}

/**
 * Override some Multisite core components.
 */
function drush_enrd_lag_database_override_multisite_permissions() {
  _enrd_lag_database_overrides_all();
}

/**
 * Helper function to set administrator role rid in LAG and RDPs.
 */
function drush_enrd_lag_database_set_admin_rids() {
  _enrd_lag_database_set_admin_rids(ENRD_LAG_DATABASE_LAG_GROUP_NODE);
  _enrd_lag_database_set_admin_rids(ENRD_LAG_DATABASE_ESI_FUND_GROUP_NODE);
}

/**
 * Provides progress bar.
 *
 * @param int $ratio
 *   Operation progress in percentage.
 */
function _enrd_lag_database_drush_print_progress($ratio) {
  _enrd_mastermind_drush_print_progress($ratio);
}

/**
 * Set ESI Funds Long Names.
 */
function drush_lag_database_set_fund_long_name() {
  _enrd_lag_database_save_fund_long_name();
}
