<?php

/**
 * @file
 * agri_invite.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function agri_invite_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer agri invite'.
  $permissions['administer agri invite'] = array(
    'name' => 'administer agri invite',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'agri_invite',
  );

  // Exported permission: 'administer invitations'.
  $permissions['administer invitations'] = array(
    'name' => 'administer invitations',
    'roles' => array(),
    'module' => 'invite',
  );

  // Exported permission: 'administer invite types'.
  $permissions['administer invite types'] = array(
    'name' => 'administer invite types',
    'roles' => array(),
    'module' => 'invite',
  );

  // Exported permission: 'create agri_invite entity'.
  $permissions['create agri_invite entity'] = array(
    'name' => 'create agri_invite entity',
    'roles' => array(),
    'module' => 'invite',
  );

  // Exported permission: 'create any invite entities'.
  $permissions['create any invite entities'] = array(
    'name' => 'create any invite entities',
    'roles' => array(),
    'module' => 'invite',
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

  // Exported permission: 'invite people'.
  $permissions['invite people'] = array(
    'name' => 'invite people',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'agri_invite',
  );

  // Exported permission: 'resend any invitations'.
  $permissions['resend any invitations'] = array(
    'name' => 'resend any invitations',
    'roles' => array(),
    'module' => 'invite',
  );

  // Exported permission: 'resend own invitations'.
  $permissions['resend own invitations'] = array(
    'name' => 'resend own invitations',
    'roles' => array(),
    'module' => 'invite',
  );

  // Exported permission: 'resend unexpired invitations'.
  $permissions['resend unexpired invitations'] = array(
    'name' => 'resend unexpired invitations',
    'roles' => array(),
    'module' => 'invite',
  );

  // Exported permission: 'view any invite entities'.
  $permissions['view any invite entities'] = array(
    'name' => 'view any invite entities',
    'roles' => array(),
    'module' => 'invite',
  );

  // Exported permission: 'withdraw own accepted invitations'.
  $permissions['withdraw own accepted invitations'] = array(
    'name' => 'withdraw own accepted invitations',
    'roles' => array(),
    'module' => 'invite',
  );

  // Exported permission: 'withdraw own invitations'.
  $permissions['withdraw own invitations'] = array(
    'name' => 'withdraw own invitations',
    'roles' => array(),
    'module' => 'invite',
  );

  return $permissions;
}
