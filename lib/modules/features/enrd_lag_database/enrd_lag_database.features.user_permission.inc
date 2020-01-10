<?php

/**
 * @file
 * enrd_lag_database.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function enrd_lag_database_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access all webform results'.
  $permissions['access all webform results'] = array(
    'name' => 'access all webform results',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'create cooperation_offer content'.
  $permissions['create cooperation_offer content'] = array(
    'name' => 'create cooperation_offer content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create lag content'.
  $permissions['create lag content'] = array(
    'name' => 'create lag content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any cooperation_offer content'.
  $permissions['delete any cooperation_offer content'] = array(
    'name' => 'delete any cooperation_offer content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any lag content'.
  $permissions['delete any lag content'] = array(
    'name' => 'delete any lag content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own cooperation_offer content'.
  $permissions['delete own cooperation_offer content'] = array(
    'name' => 'delete own cooperation_offer content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own lag content'.
  $permissions['delete own lag content'] = array(
    'name' => 'delete own lag content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in enrd_additional_keywords'.
  $permissions['delete terms in enrd_additional_keywords'] = array(
    'name' => 'delete terms in enrd_additional_keywords',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in enrd_assets'.
  $permissions['delete terms in enrd_assets'] = array(
    'name' => 'delete terms in enrd_assets',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in enrd_esi_funds'.
  $permissions['delete terms in enrd_esi_funds'] = array(
    'name' => 'delete terms in enrd_esi_funds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in enrd_esif_programme'.
  $permissions['delete terms in enrd_esif_programme'] = array(
    'name' => 'delete terms in enrd_esif_programme',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in enrd_key_themes_of_strategy'.
  $permissions['delete terms in enrd_key_themes_of_strategy'] = array(
    'name' => 'delete terms in enrd_key_themes_of_strategy',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in enrd_physical_demographic_characteristics_of_lag_area'.
  $permissions['delete terms in enrd_physical_demographic_characteristics_of_lag_area'] = array(
    'name' => 'delete terms in enrd_physical_demographic_characteristics_of_lag_area',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in enrd_project_types'.
  $permissions['delete terms in enrd_project_types'] = array(
    'name' => 'delete terms in enrd_project_types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any cooperation_offer content'.
  $permissions['edit any cooperation_offer content'] = array(
    'name' => 'edit any cooperation_offer content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any lag content'.
  $permissions['edit any lag content'] = array(
    'name' => 'edit any lag content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own cooperation_offer content'.
  $permissions['edit own cooperation_offer content'] = array(
    'name' => 'edit own cooperation_offer content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own lag content'.
  $permissions['edit own lag content'] = array(
    'name' => 'edit own lag content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in enrd_additional_keywords'.
  $permissions['edit terms in enrd_additional_keywords'] = array(
    'name' => 'edit terms in enrd_additional_keywords',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in enrd_assets'.
  $permissions['edit terms in enrd_assets'] = array(
    'name' => 'edit terms in enrd_assets',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in enrd_esi_funds'.
  $permissions['edit terms in enrd_esi_funds'] = array(
    'name' => 'edit terms in enrd_esi_funds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in enrd_esif_programme'.
  $permissions['edit terms in enrd_esif_programme'] = array(
    'name' => 'edit terms in enrd_esif_programme',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in enrd_key_themes_of_strategy'.
  $permissions['edit terms in enrd_key_themes_of_strategy'] = array(
    'name' => 'edit terms in enrd_key_themes_of_strategy',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in enrd_physical_demographic_characteristics_of_lag_area'.
  $permissions['edit terms in enrd_physical_demographic_characteristics_of_lag_area'] = array(
    'name' => 'edit terms in enrd_physical_demographic_characteristics_of_lag_area',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in enrd_project_types'.
  $permissions['edit terms in enrd_project_types'] = array(
    'name' => 'edit terms in enrd_project_types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit user profile LAG fields'.
  $permissions['edit user profile LAG fields'] = array(
    'name' => 'edit user profile LAG fields',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'enrd_lag_database',
  );

  // Exported permission: 'import enrd_lag_database feeds'.
  $permissions['import enrd_lag_database feeds'] = array(
    'name' => 'import enrd_lag_database feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'skip alter moderation form'.
  $permissions['skip alter moderation form'] = array(
    'name' => 'skip alter moderation form',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'enrd_lag_database',
  );

  // Exported permission: 'skip field access control'.
  $permissions['skip field access control'] = array(
    'name' => 'skip field access control',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'enrd_lag_database',
  );

  // Exported permission: 'skip lag country restriction'.
  $permissions['skip lag country restriction'] = array(
    'name' => 'skip lag country restriction',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'enrd_lag_database',
  );

  // Exported permission: 'use Rules component rules_enrd_lag_database_set_nsu_schedule'.
  $permissions['use Rules component rules_enrd_lag_database_set_nsu_schedule'] = array(
    'name' => 'use Rules component rules_enrd_lag_database_set_nsu_schedule',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'use Rules component rules_enrd_lag_database_set_schedule'.
  $permissions['use Rules component rules_enrd_lag_database_set_schedule'] = array(
    'name' => 'use Rules component rules_enrd_lag_database_set_schedule',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'use Rules component rules_enrd_lag_database_solicit_manager_notification'.
  $permissions['use Rules component rules_enrd_lag_database_solicit_manager_notification'] = array(
    'name' => 'use Rules component rules_enrd_lag_database_solicit_manager_notification',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'use Rules component rules_enrd_lag_database_solicit_nsu_notification'.
  $permissions['use Rules component rules_enrd_lag_database_solicit_nsu_notification'] = array(
    'name' => 'use Rules component rules_enrd_lag_database_solicit_nsu_notification',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  return $permissions;
}
