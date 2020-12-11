<?php

/**
 * @file
 * enrd_sfr_pub.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function enrd_sfr_pub_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer enrd_sfr types'.
  $permissions['administer enrd_sfr types'] = array(
    'name' => 'administer enrd_sfr types',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'enrd_sfr',
  );

  // Exported permission: 'administer enrd_sfrs'.
  $permissions['administer enrd_sfrs'] = array(
    'name' => 'administer enrd_sfrs',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'enrd_sfr',
  );

  // Exported permission: 'create any enrd_sfr entities'.
  $permissions['create any enrd_sfr entities'] = array(
    'name' => 'create any enrd_sfr entities',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'enrd_sfr',
  );

  // Exported permission: 'create enrd_sfr_pub_contact_cp entity'.
  $permissions['create enrd_sfr_pub_contact_cp entity'] = array(
    'name' => 'create enrd_sfr_pub_contact_cp entity',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'enrd_sfr',
  );

  // Exported permission: 'create enrd_sfr_pub_contact_ehd entity'.
  $permissions['create enrd_sfr_pub_contact_ehd entity'] = array(
    'name' => 'create enrd_sfr_pub_contact_ehd entity',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'enrd_sfr',
  );

  // Exported permission: 'create enrd_sfr_pub_subscribe_cp entity'.
  $permissions['create enrd_sfr_pub_subscribe_cp entity'] = array(
    'name' => 'create enrd_sfr_pub_subscribe_cp entity',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'enrd_sfr',
  );

  // Exported permission: 'create enrd_sfr_pub_subscribe_ehd entity'.
  $permissions['create enrd_sfr_pub_subscribe_ehd entity'] = array(
    'name' => 'create enrd_sfr_pub_subscribe_ehd entity',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'enrd_sfr',
  );

  // Exported permission: 'delete any enrd_sfr entities'.
  $permissions['delete any enrd_sfr entities'] = array(
    'name' => 'delete any enrd_sfr entities',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'enrd_sfr',
  );

  // Exported permission: 'delete enrd_sfr_pub_contact_cp entity'.
  $permissions['delete enrd_sfr_pub_contact_cp entity'] = array(
    'name' => 'delete enrd_sfr_pub_contact_cp entity',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'enrd_sfr',
  );

  // Exported permission: 'delete enrd_sfr_pub_contact_ehd entity'.
  $permissions['delete enrd_sfr_pub_contact_ehd entity'] = array(
    'name' => 'delete enrd_sfr_pub_contact_ehd entity',
    'roles' => array(
      'administrator' => 'administrator',
      'ehd subscriptions manager' => 'ehd subscriptions manager',
      'webmaster' => 'webmaster',
    ),
    'module' => 'enrd_sfr',
  );

  // Exported permission: 'delete enrd_sfr_pub_subscribe_cp entity'.
  $permissions['delete enrd_sfr_pub_subscribe_cp entity'] = array(
    'name' => 'delete enrd_sfr_pub_subscribe_cp entity',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'enrd_sfr',
  );

  // Exported permission: 'delete enrd_sfr_pub_subscribe_ehd entity'.
  $permissions['delete enrd_sfr_pub_subscribe_ehd entity'] = array(
    'name' => 'delete enrd_sfr_pub_subscribe_ehd entity',
    'roles' => array(
      'administrator' => 'administrator',
      'ehd subscriptions manager' => 'ehd subscriptions manager',
      'webmaster' => 'webmaster',
    ),
    'module' => 'enrd_sfr',
  );

  // Exported permission: 'manage enrd_sfr_pub_contact_cp entity'.
  $permissions['manage enrd_sfr_pub_contact_cp entity'] = array(
    'name' => 'manage enrd_sfr_pub_contact_cp entity',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'enrd_sfr',
  );

  // Exported permission: 'manage enrd_sfr_pub_contact_ehd entity'.
  $permissions['manage enrd_sfr_pub_contact_ehd entity'] = array(
    'name' => 'manage enrd_sfr_pub_contact_ehd entity',
    'roles' => array(
      'administrator' => 'administrator',
      'ehd subscriptions manager' => 'ehd subscriptions manager',
      'webmaster' => 'webmaster',
    ),
    'module' => 'enrd_sfr',
  );

  // Exported permission: 'manage enrd_sfr_pub_subscribe_cp entity'.
  $permissions['manage enrd_sfr_pub_subscribe_cp entity'] = array(
    'name' => 'manage enrd_sfr_pub_subscribe_cp entity',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'enrd_sfr',
  );

  // Exported permission: 'manage enrd_sfr_pub_subscribe_ehd entity'.
  $permissions['manage enrd_sfr_pub_subscribe_ehd entity'] = array(
    'name' => 'manage enrd_sfr_pub_subscribe_ehd entity',
    'roles' => array(
      'administrator' => 'administrator',
      'ehd subscriptions manager' => 'ehd subscriptions manager',
      'webmaster' => 'webmaster',
    ),
    'module' => 'enrd_sfr',
  );

  // Exported permission: 'view any enrd_sfr entities'.
  $permissions['view any enrd_sfr entities'] = array(
    'name' => 'view any enrd_sfr entities',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'enrd_sfr',
  );

  // Exported permission: 'view enrd_sfr_pub_contact_cp entity'.
  $permissions['view enrd_sfr_pub_contact_cp entity'] = array(
    'name' => 'view enrd_sfr_pub_contact_cp entity',
    'roles' => array(),
    'module' => 'enrd_sfr',
  );

  // Exported permission: 'view enrd_sfr_pub_contact_ehd entity'.
  $permissions['view enrd_sfr_pub_contact_ehd entity'] = array(
    'name' => 'view enrd_sfr_pub_contact_ehd entity',
    'roles' => array(),
    'module' => 'enrd_sfr',
  );

  // Exported permission: 'view enrd_sfr_pub_subscribe_cp entity'.
  $permissions['view enrd_sfr_pub_subscribe_cp entity'] = array(
    'name' => 'view enrd_sfr_pub_subscribe_cp entity',
    'roles' => array(),
    'module' => 'enrd_sfr',
  );

  // Exported permission: 'view enrd_sfr_pub_subscribe_ehd entity'.
  $permissions['view enrd_sfr_pub_subscribe_ehd entity'] = array(
    'name' => 'view enrd_sfr_pub_subscribe_ehd entity',
    'roles' => array(),
    'module' => 'enrd_sfr',
  );

  return $permissions;
}
