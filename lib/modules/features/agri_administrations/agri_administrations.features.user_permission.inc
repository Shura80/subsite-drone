<?php

/**
 * @file
 * agri_administrations.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function agri_administrations_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create administration content'.
  $permissions['create administration content'] = array(
    'name' => 'create administration content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any administration content'.
  $permissions['delete any administration content'] = array(
    'name' => 'delete any administration content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own administration content'.
  $permissions['delete own administration content'] = array(
    'name' => 'delete own administration content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any administration content'.
  $permissions['edit any administration content'] = array(
    'name' => 'edit any administration content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own administration content'.
  $permissions['edit own administration content'] = array(
    'name' => 'edit own administration content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
