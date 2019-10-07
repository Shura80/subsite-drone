<?php

/**
 * @file
 * agri_core.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function agri_core_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer checked out documents'.
  $permissions['administer checked out documents'] = array(
    'name' => 'administer checked out documents',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'content_lock',
  );

  // Exported permission: 'administer persistent menu items'.
  $permissions['administer persistent menu items'] = array(
    'name' => 'administer persistent menu items',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'persistent_menu_items',
  );

  // Exported permission: 'administer search_api'.
  $permissions['administer search_api'] = array(
    'name' => 'administer search_api',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_api',
  );

  // Exported permission: 'administer search_api_exclude'.
  $permissions['administer search_api_exclude'] = array(
    'name' => 'administer search_api_exclude',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_api_exclude',
  );

  // Exported permission: 'administer search_api_saved_searches'.
  $permissions['administer search_api_saved_searches'] = array(
    'name' => 'administer search_api_saved_searches',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_api_saved_searches',
  );

  // Exported permission: 'check out documents'.
  $permissions['check out documents'] = array(
    'name' => 'check out documents',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'content_lock',
  );

  // Exported permission: 'delete own comments'.
  $permissions['delete own comments'] = array(
    'name' => 'delete own comments',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'agri_core',
  );

  // Exported permission: 'delete terms in agricultural_sectors'.
  $permissions['delete terms in agricultural_sectors'] = array(
    'name' => 'delete terms in agricultural_sectors',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in core_geographical_area'.
  $permissions['delete terms in core_geographical_area'] = array(
    'name' => 'delete terms in core_geographical_area',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in core_stakeholders'.
  $permissions['delete terms in core_stakeholders'] = array(
    'name' => 'delete terms in core_stakeholders',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in core_user_type'.
  $permissions['delete terms in core_user_type'] = array(
    'name' => 'delete terms in core_user_type',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in field_of_activity'.
  $permissions['delete terms in field_of_activity'] = array(
    'name' => 'delete terms in field_of_activity',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in forums'.
  $permissions['delete terms in forums'] = array(
    'name' => 'delete terms in forums',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in newsletter'.
  $permissions['delete terms in newsletter'] = array(
    'name' => 'delete terms in newsletter',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in nuts_regions'.
  $permissions['delete terms in nuts_regions'] = array(
    'name' => 'delete terms in nuts_regions',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in publication_type'.
  $permissions['delete terms in publication_type'] = array(
    'name' => 'delete terms in publication_type',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in tags'.
  $permissions['delete terms in tags'] = array(
    'name' => 'delete terms in tags',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit terms in agricultural_sectors'.
  $permissions['edit terms in agricultural_sectors'] = array(
    'name' => 'edit terms in agricultural_sectors',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in core_geographical_area'.
  $permissions['edit terms in core_geographical_area'] = array(
    'name' => 'edit terms in core_geographical_area',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in core_stakeholders'.
  $permissions['edit terms in core_stakeholders'] = array(
    'name' => 'edit terms in core_stakeholders',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in core_user_type'.
  $permissions['edit terms in core_user_type'] = array(
    'name' => 'edit terms in core_user_type',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in field_of_activity'.
  $permissions['edit terms in field_of_activity'] = array(
    'name' => 'edit terms in field_of_activity',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in forums'.
  $permissions['edit terms in forums'] = array(
    'name' => 'edit terms in forums',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in newsletter'.
  $permissions['edit terms in newsletter'] = array(
    'name' => 'edit terms in newsletter',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in nuts_regions'.
  $permissions['edit terms in nuts_regions'] = array(
    'name' => 'edit terms in nuts_regions',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in publication_type'.
  $permissions['edit terms in publication_type'] = array(
    'name' => 'edit terms in publication_type',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in tags'.
  $permissions['edit terms in tags'] = array(
    'name' => 'edit terms in tags',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'flag agri_core_report_forum_topics'.
  $permissions['flag agri_core_report_forum_topics'] = array(
    'name' => 'flag agri_core_report_forum_topics',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag agri_core_report_topic_comments'.
  $permissions['flag agri_core_report_topic_comments'] = array(
    'name' => 'flag agri_core_report_topic_comments',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'moderate content from draft to needs_review'.
  $permissions['moderate content from draft to needs_review'] = array(
    'name' => 'moderate content from draft to needs_review',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'funding opportunities manager' => 'funding opportunities manager',
      'project manager' => 'project manager',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from needs_review to draft'.
  $permissions['moderate content from needs_review to draft'] = array(
    'name' => 'moderate content from needs_review to draft',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'funding opportunities manager' => 'funding opportunities manager',
      'project manager' => 'project manager',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from needs_review to validated'.
  $permissions['moderate content from needs_review to validated'] = array(
    'name' => 'moderate content from needs_review to validated',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from published to archived'.
  $permissions['moderate content from published to archived'] = array(
    'name' => 'moderate content from published to archived',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from published to validated'.
  $permissions['moderate content from published to validated'] = array(
    'name' => 'moderate content from published to validated',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from validated to needs_review'.
  $permissions['moderate content from validated to needs_review'] = array(
    'name' => 'moderate content from validated to needs_review',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from validated to published'.
  $permissions['moderate content from validated to published'] = array(
    'name' => 'moderate content from validated to published',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'unflag agri_core_report_forum_topics'.
  $permissions['unflag agri_core_report_forum_topics'] = array(
    'name' => 'unflag agri_core_report_forum_topics',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag agri_core_report_topic_comments'.
  $permissions['unflag agri_core_report_topic_comments'] = array(
    'name' => 'unflag agri_core_report_topic_comments',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'use search_api_saved_searches'.
  $permissions['use search_api_saved_searches'] = array(
    'name' => 'use search_api_saved_searches',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search_api_saved_searches',
  );

  return $permissions;
}
