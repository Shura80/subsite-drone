<?php

/**
 * @file
 * enrd_lag_dashboard.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function enrd_lag_dashboard_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access group webform results'.
  $permissions['access group webform results'] = array(
    'name' => 'access group webform results',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'enrd_lag_dashboard',
  );

  // Exported permission: 'access lag dashboards'.
  $permissions['access lag dashboards'] = array(
    'name' => 'access lag dashboards',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'enrd_lag_dashboard',
  );

  // Exported permission: 'administer lag dashboard login redirects'.
  $permissions['administer lag dashboard login redirects'] = array(
    'name' => 'administer lag dashboard login redirects',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'enrd_lag_dashboard',
  );

  // Exported permission: 'administer nsu users'.
  $permissions['administer nsu users'] = array(
    'name' => 'administer nsu users',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'enrd_lag_dashboard',
  );

  // Exported permission: 'use Rules component rules_enrd_lag_dashboard_add_new_national_manager'.
  $permissions['use Rules component rules_enrd_lag_dashboard_add_new_national_manager'] = array(
    'name' => 'use Rules component rules_enrd_lag_dashboard_add_new_national_manager',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'use Rules component rules_enrd_lag_dashboard_send_mail_from_og_membership'.
  $permissions['use Rules component rules_enrd_lag_dashboard_send_mail_from_og_membership'] = array(
    'name' => 'use Rules component rules_enrd_lag_dashboard_send_mail_from_og_membership',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'use Rules component rules_enrd_moderate_content_to_archived'.
  $permissions['use Rules component rules_enrd_moderate_content_to_archived'] = array(
    'name' => 'use Rules component rules_enrd_moderate_content_to_archived',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'use Rules component rules_enrd_moderate_content_to_draft'.
  $permissions['use Rules component rules_enrd_moderate_content_to_draft'] = array(
    'name' => 'use Rules component rules_enrd_moderate_content_to_draft',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'use Rules component rules_enrd_moderate_content_to_expired'.
  $permissions['use Rules component rules_enrd_moderate_content_to_expired'] = array(
    'name' => 'use Rules component rules_enrd_moderate_content_to_expired',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'use Rules component rules_enrd_moderate_content_to_published'.
  $permissions['use Rules component rules_enrd_moderate_content_to_published'] = array(
    'name' => 'use Rules component rules_enrd_moderate_content_to_published',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'use Rules component rules_enrd_moderate_content_to_ready_to_be_published'.
  $permissions['use Rules component rules_enrd_moderate_content_to_ready_to_be_published'] = array(
    'name' => 'use Rules component rules_enrd_moderate_content_to_ready_to_be_published',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'rules',
  );

  return $permissions;
}
