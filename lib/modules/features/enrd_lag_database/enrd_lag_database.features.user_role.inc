<?php

/**
 * @file
 * enrd_lag_database.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function enrd_lag_database_user_default_roles() {
  $roles = array();

  // Exported role: LAG User.
  $roles['LAG User'] = (object) array(
    'name' => 'LAG User',
    'weight' => 11,
  );

  return $roles;
}
