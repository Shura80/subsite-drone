<?php

/**
 * @file
 * enrd_sfr_pub.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function enrd_sfr_pub_user_default_roles() {
  $roles = array();

  // Exported role: ehd subscriptions manager.
  $roles['ehd subscriptions manager'] = (object) array(
    'name' => 'ehd subscriptions manager',
    'weight' => 12,
  );

  return $roles;
}
