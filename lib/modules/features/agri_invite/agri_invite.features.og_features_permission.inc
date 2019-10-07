<?php

/**
 * @file
 * agri_invite.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function agri_invite_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:administration:invite people'
  $permissions['node:administration:invite people'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:collaborative_area:invite people'
  $permissions['node:collaborative_area:invite people'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  return $permissions;
}
