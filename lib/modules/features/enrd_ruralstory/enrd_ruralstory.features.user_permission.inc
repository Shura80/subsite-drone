<?php

/**
 * @file
 * enrd_ruralstory.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function enrd_ruralstory_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create enrd_ruralstory entity'.
  $permissions['create enrd_ruralstory entity'] = array(
    'name' => 'create enrd_ruralstory entity',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'enrd_sfr',
  );

  // Exported permission: 'delete enrd_ruralstory entity'.
  $permissions['delete enrd_ruralstory entity'] = array(
    'name' => 'delete enrd_ruralstory entity',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'enrd_sfr',
  );

  // Exported permission: 'delete terms in enrd_ruralstory_topics'.
  $permissions['delete terms in enrd_ruralstory_topics'] = array(
    'name' => 'delete terms in enrd_ruralstory_topics',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in enrd_ruralstory_topics'.
  $permissions['edit terms in enrd_ruralstory_topics'] = array(
    'name' => 'edit terms in enrd_ruralstory_topics',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'flag enrd_ruralstory_status'.
  $permissions['flag enrd_ruralstory_status'] = array(
    'name' => 'flag enrd_ruralstory_status',
    'roles' => array(
      'administrator' => 'administrator',
      'rural story submissions manager' => 'rural story submissions manager',
      'webmaster' => 'webmaster',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'manage enrd_ruralstory entity'.
  $permissions['manage enrd_ruralstory entity'] = array(
    'name' => 'manage enrd_ruralstory entity',
    'roles' => array(
      'administrator' => 'administrator',
      'rural story submissions manager' => 'rural story submissions manager',
      'webmaster' => 'webmaster',
    ),
    'module' => 'enrd_sfr',
  );

  // Exported permission: 'unflag enrd_ruralstory_status'.
  $permissions['unflag enrd_ruralstory_status'] = array(
    'name' => 'unflag enrd_ruralstory_status',
    'roles' => array(
      'administrator' => 'administrator',
      'rural story submissions manager' => 'rural story submissions manager',
      'webmaster' => 'webmaster',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'use Rules component rules_enrd_ruralstory_remove_status'.
  $permissions['use Rules component rules_enrd_ruralstory_remove_status'] = array(
    'name' => 'use Rules component rules_enrd_ruralstory_remove_status',
    'roles' => array(
      'administrator' => 'administrator',
      'rural story submissions manager' => 'rural story submissions manager',
      'webmaster' => 'webmaster',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'view enrd_ruralstory entity'.
  $permissions['view enrd_ruralstory entity'] = array(
    'name' => 'view enrd_ruralstory entity',
    'roles' => array(
      'administrator' => 'administrator',
      'rural story submissions manager' => 'rural story submissions manager',
      'webmaster' => 'webmaster',
    ),
    'module' => 'enrd_sfr',
  );

  return $permissions;
}
