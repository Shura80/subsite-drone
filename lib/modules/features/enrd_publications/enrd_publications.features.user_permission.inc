<?php

/**
 * @file
 * enrd_publications.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function enrd_publications_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create publication content'.
  $permissions['create publication content'] = array(
    'name' => 'create publication content',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create publication_ehd content'.
  $permissions['create publication_ehd content'] = array(
    'name' => 'create publication_ehd content',
    'roles' => array(
      'administrator' => 'administrator',
      'evaluation helpdesk' => 'evaluation helpdesk',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any publication content'.
  $permissions['delete any publication content'] = array(
    'name' => 'delete any publication content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any publication_ehd content'.
  $permissions['delete any publication_ehd content'] = array(
    'name' => 'delete any publication_ehd content',
    'roles' => array(
      'administrator' => 'administrator',
      'evaluation helpdesk' => 'evaluation helpdesk',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own publication content'.
  $permissions['delete own publication content'] = array(
    'name' => 'delete own publication content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own publication_ehd content'.
  $permissions['delete own publication_ehd content'] = array(
    'name' => 'delete own publication_ehd content',
    'roles' => array(
      'administrator' => 'administrator',
      'evaluation helpdesk' => 'evaluation helpdesk',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in enrd_evaluation_content_type'.
  $permissions['delete terms in enrd_evaluation_content_type'] = array(
    'name' => 'delete terms in enrd_evaluation_content_type',
    'roles' => array(
      'evaluation helpdesk' => 'evaluation helpdesk',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in enrd_evaluation_theme'.
  $permissions['delete terms in enrd_evaluation_theme'] = array(
    'name' => 'delete terms in enrd_evaluation_theme',
    'roles' => array(
      'evaluation helpdesk' => 'evaluation helpdesk',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in enrd_evaluation_type'.
  $permissions['delete terms in enrd_evaluation_type'] = array(
    'name' => 'delete terms in enrd_evaluation_type',
    'roles' => array(
      'evaluation helpdesk' => 'evaluation helpdesk',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in enrd_programming_period'.
  $permissions['delete terms in enrd_programming_period'] = array(
    'name' => 'delete terms in enrd_programming_period',
    'roles' => array(
      'evaluation helpdesk' => 'evaluation helpdesk',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in enrd_publications'.
  $permissions['delete terms in enrd_publications'] = array(
    'name' => 'delete terms in enrd_publications',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any publication content'.
  $permissions['edit any publication content'] = array(
    'name' => 'edit any publication content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any publication_ehd content'.
  $permissions['edit any publication_ehd content'] = array(
    'name' => 'edit any publication_ehd content',
    'roles' => array(
      'administrator' => 'administrator',
      'evaluation helpdesk' => 'evaluation helpdesk',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own publication content'.
  $permissions['edit own publication content'] = array(
    'name' => 'edit own publication content',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own publication_ehd content'.
  $permissions['edit own publication_ehd content'] = array(
    'name' => 'edit own publication_ehd content',
    'roles' => array(
      'administrator' => 'administrator',
      'evaluation helpdesk' => 'evaluation helpdesk',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in enrd_evaluation_content_type'.
  $permissions['edit terms in enrd_evaluation_content_type'] = array(
    'name' => 'edit terms in enrd_evaluation_content_type',
    'roles' => array(
      'evaluation helpdesk' => 'evaluation helpdesk',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in enrd_evaluation_theme'.
  $permissions['edit terms in enrd_evaluation_theme'] = array(
    'name' => 'edit terms in enrd_evaluation_theme',
    'roles' => array(
      'evaluation helpdesk' => 'evaluation helpdesk',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in enrd_evaluation_type'.
  $permissions['edit terms in enrd_evaluation_type'] = array(
    'name' => 'edit terms in enrd_evaluation_type',
    'roles' => array(
      'evaluation helpdesk' => 'evaluation helpdesk',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in enrd_programming_period'.
  $permissions['edit terms in enrd_programming_period'] = array(
    'name' => 'edit terms in enrd_programming_period',
    'roles' => array(
      'evaluation helpdesk' => 'evaluation helpdesk',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in enrd_publications'.
  $permissions['edit terms in enrd_publications'] = array(
    'name' => 'edit terms in enrd_publications',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'merge enrd_publications terms'.
  $permissions['merge enrd_publications terms'] = array(
    'name' => 'merge enrd_publications terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  return $permissions;
}
