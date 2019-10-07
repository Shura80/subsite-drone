<?php

/**
 * @file
 * agri_projects.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function agri_projects_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access manage projects view'.
  $permissions['access manage projects view'] = array(
    'name' => 'access manage projects view',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'agri_projects',
  );

  // Exported permission: 'create innovative_action content'.
  $permissions['create innovative_action content'] = array(
    'name' => 'create innovative_action content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create needs_for_research_from_practice content'.
  $permissions['create needs_for_research_from_practice content'] = array(
    'name' => 'create needs_for_research_from_practice content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'contributor' => 'contributor',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create operational_group content'.
  $permissions['create operational_group content'] = array(
    'name' => 'create operational_group content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create project content'.
  $permissions['create project content'] = array(
    'name' => 'create project content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'project manager' => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create project_ideas content'.
  $permissions['create project_ideas content'] = array(
    'name' => 'create project_ideas content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'contributor' => 'contributor',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create research_project content'.
  $permissions['create research_project content'] = array(
    'name' => 'create research_project content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any innovative_action content'.
  $permissions['delete any innovative_action content'] = array(
    'name' => 'delete any innovative_action content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any needs_for_research_from_practice content'.
  $permissions['delete any needs_for_research_from_practice content'] = array(
    'name' => 'delete any needs_for_research_from_practice content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any operational_group content'.
  $permissions['delete any operational_group content'] = array(
    'name' => 'delete any operational_group content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any project content'.
  $permissions['delete any project content'] = array(
    'name' => 'delete any project content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any project_ideas content'.
  $permissions['delete any project_ideas content'] = array(
    'name' => 'delete any project_ideas content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any research_project content'.
  $permissions['delete any research_project content'] = array(
    'name' => 'delete any research_project content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own innovative_action content'.
  $permissions['delete own innovative_action content'] = array(
    'name' => 'delete own innovative_action content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own needs_for_research_from_practice content'.
  $permissions['delete own needs_for_research_from_practice content'] = array(
    'name' => 'delete own needs_for_research_from_practice content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'contributor' => 'contributor',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own operational_group content'.
  $permissions['delete own operational_group content'] = array(
    'name' => 'delete own operational_group content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own project content'.
  $permissions['delete own project content'] = array(
    'name' => 'delete own project content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'project manager' => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own project_ideas content'.
  $permissions['delete own project_ideas content'] = array(
    'name' => 'delete own project_ideas content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'contributor' => 'contributor',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own research_project content'.
  $permissions['delete own research_project content'] = array(
    'name' => 'delete own research_project content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any innovative_action content'.
  $permissions['edit any innovative_action content'] = array(
    'name' => 'edit any innovative_action content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any needs_for_research_from_practice content'.
  $permissions['edit any needs_for_research_from_practice content'] = array(
    'name' => 'edit any needs_for_research_from_practice content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any operational_group content'.
  $permissions['edit any operational_group content'] = array(
    'name' => 'edit any operational_group content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any project content'.
  $permissions['edit any project content'] = array(
    'name' => 'edit any project content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any project_ideas content'.
  $permissions['edit any project_ideas content'] = array(
    'name' => 'edit any project_ideas content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any research_project content'.
  $permissions['edit any research_project content'] = array(
    'name' => 'edit any research_project content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own innovative_action content'.
  $permissions['edit own innovative_action content'] = array(
    'name' => 'edit own innovative_action content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own needs_for_research_from_practice content'.
  $permissions['edit own needs_for_research_from_practice content'] = array(
    'name' => 'edit own needs_for_research_from_practice content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'contributor' => 'contributor',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own operational_group content'.
  $permissions['edit own operational_group content'] = array(
    'name' => 'edit own operational_group content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own project content'.
  $permissions['edit own project content'] = array(
    'name' => 'edit own project content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'project manager' => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own project_ideas content'.
  $permissions['edit own project_ideas content'] = array(
    'name' => 'edit own project_ideas content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'contributor' => 'contributor',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own research_project content'.
  $permissions['edit own research_project content'] = array(
    'name' => 'edit own research_project content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'flag agri_privacy_policy'.
  $permissions['flag agri_privacy_policy'] = array(
    'name' => 'flag agri_privacy_policy',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag agri_privacy_policy'.
  $permissions['unflag agri_privacy_policy'] = array(
    'name' => 'unflag agri_privacy_policy',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  return $permissions;
}
