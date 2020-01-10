<?php

/**
 * @file
 * enrd_publications.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function enrd_publications_user_default_roles() {
  $roles = array();

  // Exported role: evaluation helpdesk.
  $roles['evaluation helpdesk'] = (object) array(
    'name' => 'evaluation helpdesk',
    'weight' => 9,
  );

  return $roles;
}
