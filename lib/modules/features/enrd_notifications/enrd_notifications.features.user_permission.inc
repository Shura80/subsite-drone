<?php

/**
 * @file
 * enrd_notifications.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function enrd_notifications_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access notifications list'.
  $permissions['access notifications list'] = array(
    'name' => 'access notifications list',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'enrd_notifications',
  );

  // Exported permission: 'access notifications settings panel'.
  $permissions['access notifications settings panel'] = array(
    'name' => 'access notifications settings panel',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'enrd_notifications',
  );

  // Exported permission: 'administer message subscribe'.
  $permissions['administer message subscribe'] = array(
    'name' => 'administer message subscribe',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_subscribe',
  );

  // Exported permission: 'create messages'.
  $permissions['create messages'] = array(
    'name' => 'create messages',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'message',
  );

  // Exported permission: 'flag email_cooperation_offers'.
  $permissions['flag email_cooperation_offers'] = array(
    'name' => 'flag email_cooperation_offers',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag email_events'.
  $permissions['flag email_events'] = array(
    'name' => 'flag email_events',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag email_lags'.
  $permissions['flag email_lags'] = array(
    'name' => 'flag email_lags',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag email_news'.
  $permissions['flag email_news'] = array(
    'name' => 'flag email_news',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag enrd_follow_cooperation_offers'.
  $permissions['flag enrd_follow_cooperation_offers'] = array(
    'name' => 'flag enrd_follow_cooperation_offers',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag enrd_follow_events'.
  $permissions['flag enrd_follow_events'] = array(
    'name' => 'flag enrd_follow_events',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag enrd_follow_lags'.
  $permissions['flag enrd_follow_lags'] = array(
    'name' => 'flag enrd_follow_lags',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag enrd_follow_news'.
  $permissions['flag enrd_follow_news'] = array(
    'name' => 'flag enrd_follow_news',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag enrd_message_read_unread'.
  $permissions['flag enrd_message_read_unread'] = array(
    'name' => 'flag enrd_message_read_unread',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag email_cooperation_offers'.
  $permissions['unflag email_cooperation_offers'] = array(
    'name' => 'unflag email_cooperation_offers',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag email_events'.
  $permissions['unflag email_events'] = array(
    'name' => 'unflag email_events',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag email_lags'.
  $permissions['unflag email_lags'] = array(
    'name' => 'unflag email_lags',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag email_news'.
  $permissions['unflag email_news'] = array(
    'name' => 'unflag email_news',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag enrd_follow_cooperation_offers'.
  $permissions['unflag enrd_follow_cooperation_offers'] = array(
    'name' => 'unflag enrd_follow_cooperation_offers',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag enrd_follow_events'.
  $permissions['unflag enrd_follow_events'] = array(
    'name' => 'unflag enrd_follow_events',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag enrd_follow_lags'.
  $permissions['unflag enrd_follow_lags'] = array(
    'name' => 'unflag enrd_follow_lags',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag enrd_follow_news'.
  $permissions['unflag enrd_follow_news'] = array(
    'name' => 'unflag enrd_follow_news',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag enrd_message_read_unread'.
  $permissions['unflag enrd_message_read_unread'] = array(
    'name' => 'unflag enrd_message_read_unread',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'use Rules component rules_enrd_flag_read_unread'.
  $permissions['use Rules component rules_enrd_flag_read_unread'] = array(
    'name' => 'use Rules component rules_enrd_flag_read_unread',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'rules',
  );

  return $permissions;
}
