<?php

/**
 * @file
 * agri_usermerge.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function agri_usermerge_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer usermerge settings'.
  $permissions['administer usermerge settings'] = array(
    'name' => 'administer usermerge settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'usermerge',
  );

  // Exported permission: 'administer_agri_usermerge'.
  $permissions['administer_agri_usermerge'] = array(
    'name' => 'administer_agri_usermerge',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'agri_usermerge',
  );

  // Exported permission: 'merge accounts'.
  $permissions['merge accounts'] = array(
    'name' => 'merge accounts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'usermerge',
  );

  return $permissions;
}
