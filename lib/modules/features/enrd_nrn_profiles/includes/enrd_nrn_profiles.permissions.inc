<?php

/**
 * @file
 * Code for managing custom permissions.
 */

/**
 * Overrides some global permissions for the NRN Editor role.
 */
function _enrd_nrn_profiles_overrides_permission() {

  // Grant Permissions.
  $grant = array(
    'NRN Editor' => array(
      'access media browser',
      'add media from remote sources',
    ),
  );

  $roles = user_roles(FALSE);
  foreach ($roles as $rid => $role) {
    if (isset($grant[$role])) {
      user_role_grant_permissions($rid, $grant[$role]);
    }
  }

  drupal_set_message(t('Added global NRN Editor permissions.'));
}
