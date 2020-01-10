<?php

/**
 * @file
 * enrd_mastermind.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function enrd_mastermind_user_default_roles() {
  $roles = array();

  // Exported role: groups moderator.
  $roles['groups moderator'] = (object) array(
    'name' => 'groups moderator',
    'weight' => 8,
  );

  // Exported role: publisher.
  $roles['publisher'] = (object) array(
    'name' => 'publisher',
    'weight' => 7,
  );

  return $roles;
}
