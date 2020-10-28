<?php

/**
 * @file
 * enrd_nrn_toolkit.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function enrd_nrn_toolkit_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create nrn_resource content'.
  $permissions['create nrn_resource content'] = array(
    'name' => 'create nrn_resource content',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any nrn_resource content'.
  $permissions['delete any nrn_resource content'] = array(
    'name' => 'delete any nrn_resource content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own nrn_resource content'.
  $permissions['delete own nrn_resource content'] = array(
    'name' => 'delete own nrn_resource content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in enrd_networking'.
  $permissions['delete terms in enrd_networking'] = array(
    'name' => 'delete terms in enrd_networking',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in enrd_resource_type'.
  $permissions['delete terms in enrd_resource_type'] = array(
    'name' => 'delete terms in enrd_resource_type',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any nrn_resource content'.
  $permissions['edit any nrn_resource content'] = array(
    'name' => 'edit any nrn_resource content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own nrn_resource content'.
  $permissions['edit own nrn_resource content'] = array(
    'name' => 'edit own nrn_resource content',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in enrd_networking'.
  $permissions['edit terms in enrd_networking'] = array(
    'name' => 'edit terms in enrd_networking',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in enrd_resource_type'.
  $permissions['edit terms in enrd_resource_type'] = array(
    'name' => 'edit terms in enrd_resource_type',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'use nrn toolkit shared fields'.
  $permissions['use nrn toolkit shared fields'] = array(
    'name' => 'use nrn toolkit shared fields',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'webmaster' => 'webmaster',
    ),
    'module' => 'enrd_nrn_toolkit',
  );

  return $permissions;
}
