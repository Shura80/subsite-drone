<?php

/**
 * @file
 * enrd_focus_on.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function enrd_focus_on_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer entityqueue'.
  $permissions['administer entityqueue'] = array(
    'name' => 'administer entityqueue',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'create focus_on content'.
  $permissions['create focus_on content'] = array(
    'name' => 'create focus_on content',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any focus_on content'.
  $permissions['delete any focus_on content'] = array(
    'name' => 'delete any focus_on content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own focus_on content'.
  $permissions['delete own focus_on content'] = array(
    'name' => 'delete own focus_on content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any focus_on content'.
  $permissions['edit any focus_on content'] = array(
    'name' => 'edit any focus_on content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own focus_on content'.
  $permissions['edit own focus_on content'] = array(
    'name' => 'edit own focus_on content',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'manipulate all entityqueues'.
  $permissions['manipulate all entityqueues'] = array(
    'name' => 'manipulate all entityqueues',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'manipulate entityqueues'.
  $permissions['manipulate entityqueues'] = array(
    'name' => 'manipulate entityqueues',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'webmaster' => 'webmaster',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'update focus_on_home_page_slider entityqueue'.
  $permissions['update focus_on_home_page_slider entityqueue'] = array(
    'name' => 'update focus_on_home_page_slider entityqueue',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'webmaster' => 'webmaster',
    ),
    'module' => 'entityqueue',
  );

  return $permissions;
}
