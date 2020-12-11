<?php

/**
 * @file
 * enrd_nrn_profiles.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function enrd_nrn_profiles_user_default_roles() {
  $roles = array();

  // Exported role: NRN Editor.
  $roles['NRN Editor'] = (object) array(
    'name' => 'NRN Editor',
    'weight' => 12,
  );

  return $roles;
}
