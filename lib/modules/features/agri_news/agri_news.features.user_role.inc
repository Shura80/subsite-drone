<?php

/**
 * @file
 * agri_news.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function agri_news_user_default_roles() {
  $roles = array();

  // Exported role: funding opportunities manager.
  $roles['funding opportunities manager'] = (object) array(
    'name' => 'funding opportunities manager',
    'weight' => 7,
  );

  return $roles;
}
