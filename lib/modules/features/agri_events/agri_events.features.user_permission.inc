<?php

/**
 * @file
 * agri_events.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function agri_events_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'delete terms in event_type'.
  $permissions['delete terms in event_type'] = array(
    'name' => 'delete terms in event_type',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in event_type'.
  $permissions['edit terms in event_type'] = array(
    'name' => 'edit terms in event_type',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'update any fullcalendar event'.
  $permissions['update any fullcalendar event'] = array(
    'name' => 'update any fullcalendar event',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fullcalendar',
  );

  return $permissions;
}
