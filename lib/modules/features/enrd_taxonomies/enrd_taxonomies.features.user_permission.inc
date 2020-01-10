<?php

/**
 * @file
 * enrd_taxonomies.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function enrd_taxonomies_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'delete terms in enrd_countries'.
  $permissions['delete terms in enrd_countries'] = array(
    'name' => 'delete terms in enrd_countries',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in enrd_evaluation'.
  $permissions['delete terms in enrd_evaluation'] = array(
    'name' => 'delete terms in enrd_evaluation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in enrd_languages'.
  $permissions['delete terms in enrd_languages'] = array(
    'name' => 'delete terms in enrd_languages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in enrd_origin'.
  $permissions['delete terms in enrd_origin'] = array(
    'name' => 'delete terms in enrd_origin',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in enrd_rural_development_policy'.
  $permissions['delete terms in enrd_rural_development_policy'] = array(
    'name' => 'delete terms in enrd_rural_development_policy',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in enrd_translation_status'.
  $permissions['delete terms in enrd_translation_status'] = array(
    'name' => 'delete terms in enrd_translation_status',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in enrd_transversal_topics'.
  $permissions['delete terms in enrd_transversal_topics'] = array(
    'name' => 'delete terms in enrd_transversal_topics',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in enrd_update_status'.
  $permissions['delete terms in enrd_update_status'] = array(
    'name' => 'delete terms in enrd_update_status',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in enrd_countries'.
  $permissions['edit terms in enrd_countries'] = array(
    'name' => 'edit terms in enrd_countries',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in enrd_evaluation'.
  $permissions['edit terms in enrd_evaluation'] = array(
    'name' => 'edit terms in enrd_evaluation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in enrd_languages'.
  $permissions['edit terms in enrd_languages'] = array(
    'name' => 'edit terms in enrd_languages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in enrd_origin'.
  $permissions['edit terms in enrd_origin'] = array(
    'name' => 'edit terms in enrd_origin',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in enrd_rural_development_policy'.
  $permissions['edit terms in enrd_rural_development_policy'] = array(
    'name' => 'edit terms in enrd_rural_development_policy',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in enrd_translation_status'.
  $permissions['edit terms in enrd_translation_status'] = array(
    'name' => 'edit terms in enrd_translation_status',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in enrd_transversal_topics'.
  $permissions['edit terms in enrd_transversal_topics'] = array(
    'name' => 'edit terms in enrd_transversal_topics',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in enrd_update_status'.
  $permissions['edit terms in enrd_update_status'] = array(
    'name' => 'edit terms in enrd_update_status',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'tag enrd taxonomies tag'.
  $permissions['tag enrd taxonomies tag'] = array(
    'name' => 'tag enrd taxonomies tag',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
    ),
    'module' => 'enrd_taxonomies',
  );

  return $permissions;
}
