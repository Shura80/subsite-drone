<?php

/**
 * @file
 * enrd_country_pages.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function enrd_country_pages_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create rdp_information content'.
  $permissions['create rdp_information content'] = array(
    'name' => 'create rdp_information content',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any rdp_information content'.
  $permissions['delete any rdp_information content'] = array(
    'name' => 'delete any rdp_information content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own rdp_information content'.
  $permissions['delete own rdp_information content'] = array(
    'name' => 'delete own rdp_information content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any rdp_information content'.
  $permissions['edit any rdp_information content'] = array(
    'name' => 'edit any rdp_information content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own rdp_information content'.
  $permissions['edit own rdp_information content'] = array(
    'name' => 'edit own rdp_information content',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  return $permissions;
}
