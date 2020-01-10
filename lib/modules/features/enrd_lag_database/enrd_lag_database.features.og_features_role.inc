<?php

/**
 * @file
 * enrd_lag_database.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function enrd_lag_database_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:esi_funds_og:National manager'.
  $roles['node:esi_funds_og:National manager'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'esi_funds_og',
    'name' => 'National manager',
  );

  // Exported OG Role: 'node:lag:LAG Contact'.
  $roles['node:lag:LAG Contact'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'lag',
    'name' => 'LAG Contact',
  );

  // Exported OG Role: 'node:lag:LAG Manager'.
  $roles['node:lag:LAG Manager'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'lag',
    'name' => 'LAG Manager',
  );

  return $roles;
}
