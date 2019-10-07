<?php

/**
 * @file
 * agri_sfc_project_import.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function agri_sfc_project_import_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer_settings_sfc_importer'.
  $permissions['administer_settings_sfc_importer'] = array(
    'name' => 'administer_settings_sfc_importer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'agri_sfc_project_import',
  );

  // Exported permission: 'use_sfc_importer'.
  $permissions['use_sfc_importer'] = array(
    'name' => 'use_sfc_importer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'agri_sfc_project_import',
  );

  return $permissions;
}
