<?php

/**
 * @file
 * agri_core.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function agri_core_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:administration:group contributor'.
  $roles['node:administration:group contributor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'administration',
    'name' => 'group contributor',
  );

  // Exported OG Role: 'node:administration:group editor'.
  $roles['node:administration:group editor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'administration',
    'name' => 'group editor',
  );

  return $roles;
}
