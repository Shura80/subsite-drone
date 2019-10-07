<?php

/**
 * @file
 * agri_events.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function agri_events_user_default_roles() {
  $roles = array();

  // Exported role: event manager.
  $roles['event manager'] = (object) array(
    'name' => 'event manager',
    'weight' => 8,
  );

  return $roles;
}
