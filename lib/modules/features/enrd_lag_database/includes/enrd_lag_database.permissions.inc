<?php

/**
 * @file
 * Code for managing custom permissions.
 */

/**
 * Overrides some global permisssions to let Lag Webmaster act on group nodes.
 */
function _enrd_lag_database_overrides_permission() {

  // Grant Permissions.
  $grant = array(
    'LAG User' => array(
      'access media browser',
      'view moderation history',
    ),
  );

  $revoke = array(
    'LAG User' => array(
      'view moderation messages',
    ),
  );

  $roles = user_roles(FALSE);
  foreach ($roles as $rid => $role) {
    if (isset($grant[$role])) {
      user_role_grant_permissions($rid, $grant[$role]);
    }

    if (isset($revoke[$role])) {
      user_role_revoke_permissions($rid, $revoke[$role]);
    }
  }

  drupal_set_message(t('Added global LAG User permissions.'));

}
