<?php

/**
 * @file
 * enrd_lag_invite.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function enrd_lag_invite_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer invite types'.
  $permissions['administer invite types'] = array(
    'name' => 'administer invite types',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'invite',
  );

  // Exported permission: 'administer lag invites'.
  $permissions['administer lag invites'] = array(
    'name' => 'administer lag invites',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'enrd_lag_invite',
  );

  // Exported permission: 'create any invite entities'.
  $permissions['create any invite entities'] = array(
    'name' => 'create any invite entities',
    'roles' => array(),
    'module' => 'invite',
  );

  // Exported permission: 'create enrd_lag_invite entity'.
  $permissions['create enrd_lag_invite entity'] = array(
    'name' => 'create enrd_lag_invite entity',
    'roles' => array(),
    'module' => 'invite',
  );

  // Exported permission: 'create lag invite'.
  $permissions['create lag invite'] = array(
    'name' => 'create lag invite',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'enrd_lag_invite',
  );

  // Exported permission: 'edit any invite entities'.
  $permissions['edit any invite entities'] = array(
    'name' => 'edit any invite entities',
    'roles' => array(),
    'module' => 'invite',
  );

  // Exported permission: 'edit own invite entities'.
  $permissions['edit own invite entities'] = array(
    'name' => 'edit own invite entities',
    'roles' => array(),
    'module' => 'invite',
  );

  // Exported permission: 'show format selection for invite'.
  $permissions['show format selection for invite'] = array(
    'name' => 'show format selection for invite',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'view any invite entities'.
  $permissions['view any invite entities'] = array(
    'name' => 'view any invite entities',
    'roles' => array(),
    'module' => 'invite',
  );

  return $permissions;
}
