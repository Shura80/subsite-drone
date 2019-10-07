<?php

/**
 * @file
 * agri_projects.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function agri_projects_user_default_roles() {
  $roles = array();

  // Exported role: project manager.
  $roles['project manager'] = (object) array(
    'name' => 'project manager',
    'weight' => 9,
  );

  return $roles;
}
