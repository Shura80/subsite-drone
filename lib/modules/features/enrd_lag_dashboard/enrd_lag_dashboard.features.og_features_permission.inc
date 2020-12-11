<?php

/**
 * @file
 * enrd_lag_dashboard.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function enrd_lag_dashboard_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:esi_funds_og:access lag dashboards'
  $permissions['node:esi_funds_og:access lag dashboards'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:lag:access group webform results'
  $permissions['node:lag:access group webform results'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:access lag dashboards'
  $permissions['node:lag:access lag dashboards'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  return $permissions;
}
