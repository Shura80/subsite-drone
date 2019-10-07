<?php

/**
 * @file
 * agri_digitization_toolbox.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function agri_digitization_toolbox_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access digitization toolbox views'.
  $permissions['access digitization toolbox views'] = array(
    'name' => 'access digitization toolbox views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'agri_digitization_toolbox',
  );

  // Exported permission: 'create digitisation_toolbox content'.
  $permissions['create digitisation_toolbox content'] = array(
    'name' => 'create digitisation_toolbox content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any digitisation_toolbox content'.
  $permissions['delete any digitisation_toolbox content'] = array(
    'name' => 'delete any digitisation_toolbox content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own digitisation_toolbox content'.
  $permissions['delete own digitisation_toolbox content'] = array(
    'name' => 'delete own digitisation_toolbox content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any digitisation_toolbox content'.
  $permissions['edit any digitisation_toolbox content'] = array(
    'name' => 'edit any digitisation_toolbox content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own digitisation_toolbox content'.
  $permissions['edit own digitisation_toolbox content'] = array(
    'name' => 'edit own digitisation_toolbox content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'flag agri_digitization_toolbox'.
  $permissions['flag agri_digitization_toolbox'] = array(
    'name' => 'flag agri_digitization_toolbox',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag agri_digitization_toolbox'.
  $permissions['unflag agri_digitization_toolbox'] = array(
    'name' => 'unflag agri_digitization_toolbox',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  return $permissions;
}
