<?php

/**
 * @file
 * enrd_nrn_profiles.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function enrd_nrn_profiles_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer nrn profiles'.
  $permissions['administer nrn profiles'] = array(
    'name' => 'administer nrn profiles',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'enrd_nrn_profiles',
  );

  // Exported permission: 'bypass alter form nrn profiles'.
  $permissions['bypass alter form nrn profiles'] = array(
    'name' => 'bypass alter form nrn profiles',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'enrd_nrn_profiles',
  );

  // Exported permission: 'create new service'.
  $permissions['create new service'] = array(
    'name' => 'create new service',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'socialfield',
  );

  // Exported permission: 'create nrn_profile content'.
  $permissions['create nrn_profile content'] = array(
    'name' => 'create nrn_profile content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any nrn_profile content'.
  $permissions['delete any nrn_profile content'] = array(
    'name' => 'delete any nrn_profile content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any service'.
  $permissions['delete any service'] = array(
    'name' => 'delete any service',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'socialfield',
  );

  // Exported permission: 'delete own nrn_profile content'.
  $permissions['delete own nrn_profile content'] = array(
    'name' => 'delete own nrn_profile content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any nrn_profile content'.
  $permissions['edit any nrn_profile content'] = array(
    'name' => 'edit any nrn_profile content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any service'.
  $permissions['edit any service'] = array(
    'name' => 'edit any service',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'socialfield',
  );

  // Exported permission: 'edit own nrn_profile content'.
  $permissions['edit own nrn_profile content'] = array(
    'name' => 'edit own nrn_profile content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view services'.
  $permissions['view services'] = array(
    'name' => 'view services',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'socialfield',
  );

  return $permissions;
}
