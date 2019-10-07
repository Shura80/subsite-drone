<?php

/**
 * @file
 * agri_news.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function agri_news_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create funding_opportunities content'.
  $permissions['create funding_opportunities content'] = array(
    'name' => 'create funding_opportunities content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'funding opportunities manager' => 'funding opportunities manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create online_resource content'.
  $permissions['create online_resource content'] = array(
    'name' => 'create online_resource content',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'funding opportunities manager' => 'funding opportunities manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any funding_opportunities content'.
  $permissions['delete any funding_opportunities content'] = array(
    'name' => 'delete any funding_opportunities content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any online_resource content'.
  $permissions['delete any online_resource content'] = array(
    'name' => 'delete any online_resource content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own funding_opportunities content'.
  $permissions['delete own funding_opportunities content'] = array(
    'name' => 'delete own funding_opportunities content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'funding opportunities manager' => 'funding opportunities manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own online_resource content'.
  $permissions['delete own online_resource content'] = array(
    'name' => 'delete own online_resource content',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'funding opportunities manager' => 'funding opportunities manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any funding_opportunities content'.
  $permissions['edit any funding_opportunities content'] = array(
    'name' => 'edit any funding_opportunities content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any online_resource content'.
  $permissions['edit any online_resource content'] = array(
    'name' => 'edit any online_resource content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own funding_opportunities content'.
  $permissions['edit own funding_opportunities content'] = array(
    'name' => 'edit own funding_opportunities content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'funding opportunities manager' => 'funding opportunities manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own online_resource content'.
  $permissions['edit own online_resource content'] = array(
    'name' => 'edit own online_resource content',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'funding opportunities manager' => 'funding opportunities manager',
    ),
    'module' => 'node',
  );

  return $permissions;
}
