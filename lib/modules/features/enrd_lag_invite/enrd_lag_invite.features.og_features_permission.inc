<?php

/**
 * @file
 * enrd_lag_invite.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function enrd_lag_invite_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:esi_funds_og:create lag invite'
  $permissions['node:esi_funds_og:create lag invite'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:lag:create lag invite'
  $permissions['node:lag:create lag invite'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  return $permissions;
}
