<?php

/**
 * @file
 * enrd_multilingual.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function enrd_multilingual_user_default_roles() {
  $roles = array();

  // Exported role: local translator.
  $roles['local translator'] = (object) array(
    'name' => 'local translator',
    'weight' => 6,
  );

  return $roles;
}
