<?php

/**
 * @file
 * enrd_mastermind.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function enrd_mastermind_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'User management' => 'User management',
      'administrator' => 'administrator',
      'editor' => 'editor',
      'ehd subscriptions manager' => 'ehd subscriptions manager',
      'rural story submissions manager' => 'rural story submissions manager',
      'webmaster' => 'webmaster',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'User management' => 'User management',
      'administrator' => 'administrator',
      'editor' => 'editor',
      'ehd subscriptions manager' => 'ehd subscriptions manager',
      'rural story submissions manager' => 'rural story submissions manager',
      'webmaster' => 'webmaster',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access bean overview'.
  $permissions['access bean overview'] = array(
    'name' => 'access bean overview',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'activate enrd users'.
  $permissions['activate enrd users'] = array(
    'name' => 'activate enrd users',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'enrd_mastermind',
  );

  // Exported permission: 'administer bean types'.
  $permissions['administer bean types'] = array(
    'name' => 'administer bean types',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'administer beans'.
  $permissions['administer beans'] = array(
    'name' => 'administer beans',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'administer enrd configuration'.
  $permissions['administer enrd configuration'] = array(
    'name' => 'administer enrd configuration',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'enrd_mastermind',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'webmaster' => 'webmaster',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer redirects'.
  $permissions['administer redirects'] = array(
    'name' => 'administer redirects',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'redirect',
  );

  // Exported permission: 'create any enrd_bean bean'.
  $permissions['create any enrd_bean bean'] = array(
    'name' => 'create any enrd_bean bean',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any webtools bean'.
  $permissions['create any webtools bean'] = array(
    'name' => 'create any webtools bean',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create focus_group content'.
  $permissions['create focus_group content'] = array(
    'name' => 'create focus_group content',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create organization content'.
  $permissions['create organization content'] = array(
    'name' => 'create organization content',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'webmaster' => 'webmaster',
    ),
    'module' => 'path',
  );

  // Exported permission: 'create webform content'.
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any enrd_bean bean'.
  $permissions['delete any enrd_bean bean'] = array(
    'name' => 'delete any enrd_bean bean',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any focus_group content'.
  $permissions['delete any focus_group content'] = array(
    'name' => 'delete any focus_group content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any organization content'.
  $permissions['delete any organization content'] = array(
    'name' => 'delete any organization content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any webform content'.
  $permissions['delete any webform content'] = array(
    'name' => 'delete any webform content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any webtools bean'.
  $permissions['delete any webtools bean'] = array(
    'name' => 'delete any webtools bean',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete own focus_group content'.
  $permissions['delete own focus_group content'] = array(
    'name' => 'delete own focus_group content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own organization content'.
  $permissions['delete own organization content'] = array(
    'name' => 'delete own organization content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform content'.
  $permissions['delete own webform content'] = array(
    'name' => 'delete own webform content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'download any document files'.
  $permissions['download any document files'] = array(
    'name' => 'download any document files',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'webmaster' => 'webmaster',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any enrd_bean bean'.
  $permissions['edit any enrd_bean bean'] = array(
    'name' => 'edit any enrd_bean bean',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any focus_group content'.
  $permissions['edit any focus_group content'] = array(
    'name' => 'edit any focus_group content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any organization content'.
  $permissions['edit any organization content'] = array(
    'name' => 'edit any organization content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any webform content'.
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any webtools bean'.
  $permissions['edit any webtools bean'] = array(
    'name' => 'edit any webtools bean',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit bean view mode'.
  $permissions['edit bean view mode'] = array(
    'name' => 'edit bean view mode',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit own focus_group content'.
  $permissions['edit own focus_group content'] = array(
    'name' => 'edit own focus_group content',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own organization content'.
  $permissions['edit own organization content'] = array(
    'name' => 'edit own organization content',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform content'.
  $permissions['edit own webform content'] = array(
    'name' => 'edit own webform content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'enrd nexteuropa token ckeditor'.
  $permissions['enrd nexteuropa token ckeditor'] = array(
    'name' => 'enrd nexteuropa token ckeditor',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'webmaster' => 'webmaster',
    ),
    'module' => 'enrd_mastermind',
  );

  // Exported permission: 'import media'.
  $permissions['import media'] = array(
    'name' => 'import media',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'media_bulk_upload',
  );

  // Exported permission: 'moderate content from needs_review to validated'.
  $permissions['moderate content from needs_review to validated'] = array(
    'name' => 'moderate content from needs_review to validated',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'webmaster' => 'webmaster',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from published to archived'.
  $permissions['moderate content from published to archived'] = array(
    'name' => 'moderate content from published to archived',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'webmaster' => 'webmaster',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from validated to published'.
  $permissions['moderate content from validated to published'] = array(
    'name' => 'moderate content from validated to published',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'webmaster' => 'webmaster',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'node-specific print configuration'.
  $permissions['node-specific print configuration'] = array(
    'name' => 'node-specific print configuration',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'print_ui',
  );

  // Exported permission: 'show format selection for bean'.
  $permissions['show format selection for bean'] = array(
    'name' => 'show format selection for bean',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for field_collection_item'.
  $permissions['show format selection for field_collection_item'] = array(
    'name' => 'show format selection for field_collection_item',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'webmaster' => 'webmaster',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'use text format enrd_safe_html'.
  $permissions['use text format enrd_safe_html'] = array(
    'name' => 'use text format enrd_safe_html',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'webmaster' => 'webmaster',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view any enrd_bean bean'.
  $permissions['view any enrd_bean bean'] = array(
    'name' => 'view any enrd_bean bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any webtools bean'.
  $permissions['view any webtools bean'] = array(
    'name' => 'view any webtools bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'webmaster' => 'webmaster',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view bean page'.
  $permissions['view bean page'] = array(
    'name' => 'view bean page',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view bean revisions'.
  $permissions['view bean revisions'] = array(
    'name' => 'view bean revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
