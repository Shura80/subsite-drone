<?php

/**
 * @file
 * enrd_ruralstory.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function enrd_ruralstory_user_default_roles() {
  $roles = array();

  // Exported role: rural story submissions manager.
  $roles['rural story submissions manager'] = (object) array(
    'name' => 'rural story submissions manager',
    'weight' => 13,
  );

  return $roles;
}
