<?php

/**
 * @file
 * enrd_lag_database.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function enrd_lag_database_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:esi_funds_og:View all unpublished content'
  $permissions['node:esi_funds_og:View all unpublished content'] = array(
    'roles' => array(
      'National manager' => 'National manager',
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:create discussion content'
  $permissions['node:esi_funds_og:create discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:esi_funds_og:create document content'
  $permissions['node:esi_funds_og:create document content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:esi_funds_og:create lag content'
  $permissions['node:esi_funds_og:create lag content'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:delete any discussion content'
  $permissions['node:esi_funds_og:delete any discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:esi_funds_og:delete any document content'
  $permissions['node:esi_funds_og:delete any document content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:esi_funds_og:delete any lag content'
  $permissions['node:esi_funds_og:delete any lag content'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:delete own discussion content'
  $permissions['node:esi_funds_og:delete own discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:esi_funds_og:delete own document content'
  $permissions['node:esi_funds_og:delete own document content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:esi_funds_og:delete own lag content'
  $permissions['node:esi_funds_og:delete own lag content'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:moderate content from archived to draft'
  $permissions['node:esi_funds_og:moderate content from archived to draft'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:moderate content from archived to ready_to_be_published'
  $permissions['node:esi_funds_og:moderate content from archived to ready_to_be_published'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:esi_funds_og:moderate content from draft to ready_to_be_published'
  $permissions['node:esi_funds_og:moderate content from draft to ready_to_be_published'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:subscribe'
  $permissions['node:esi_funds_og:subscribe'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:esi_funds_og:unsubscribe'
  $permissions['node:esi_funds_og:unsubscribe'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:esi_funds_og:update any discussion content'
  $permissions['node:esi_funds_og:update any discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:esi_funds_og:update any document content'
  $permissions['node:esi_funds_og:update any document content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:esi_funds_og:update any lag content'
  $permissions['node:esi_funds_og:update any lag content'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_additional_esi_funds field'
  $permissions['node:esi_funds_og:update field_enrd_additional_esi_funds field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_esif_programme field'
  $permissions['node:esi_funds_og:update field_enrd_esif_programme field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_assets_land_use field'
  $permissions['node:esi_funds_og:update field_enrd_lag_assets_land_use field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_clld_email field'
  $permissions['node:esi_funds_og:update field_enrd_lag_clld_email field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_clld_name field'
  $permissions['node:esi_funds_og:update field_enrd_lag_clld_name field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_code field'
  $permissions['node:esi_funds_og:update field_enrd_lag_code field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_coordinates field'
  $permissions['node:esi_funds_og:update field_enrd_lag_coordinates field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_country field'
  $permissions['node:esi_funds_og:update field_enrd_lag_country field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_documentation field'
  $permissions['node:esi_funds_og:update field_enrd_lag_documentation field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_eafrd_contrib field'
  $permissions['node:esi_funds_og:update field_enrd_lag_eafrd_contrib field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_email field'
  $permissions['node:esi_funds_og:update field_enrd_lag_email field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_emff_contrib field'
  $permissions['node:esi_funds_og:update field_enrd_lag_emff_contrib field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_entities_num field'
  $permissions['node:esi_funds_og:update field_enrd_lag_entities_num field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_erdf_contrib field'
  $permissions['node:esi_funds_og:update field_enrd_lag_erdf_contrib field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_esf_contrib field'
  $permissions['node:esi_funds_og:update field_enrd_lag_esf_contrib field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_extended_profile field'
  $permissions['node:esi_funds_og:update field_enrd_lag_extended_profile field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_facebook field'
  $permissions['node:esi_funds_og:update field_enrd_lag_facebook field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_geo_coverage field'
  $permissions['node:esi_funds_og:update field_enrd_lag_geo_coverage field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_geo_coverage_sub field'
  $permissions['node:esi_funds_og:update field_enrd_lag_geo_coverage_sub field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_inhabitants field'
  $permissions['node:esi_funds_og:update field_enrd_lag_inhabitants field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_interested_in field'
  $permissions['node:esi_funds_og:update field_enrd_lag_interested_in field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_key_themes field'
  $permissions['node:esi_funds_og:update field_enrd_lag_key_themes field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_linkedin field'
  $permissions['node:esi_funds_og:update field_enrd_lag_linkedin field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_manager_address field'
  $permissions['node:esi_funds_og:update field_enrd_lag_manager_address field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_manager_email field'
  $permissions['node:esi_funds_og:update field_enrd_lag_manager_email field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_manager_name field'
  $permissions['node:esi_funds_og:update field_enrd_lag_manager_name field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_national_contrib field'
  $permissions['node:esi_funds_og:update field_enrd_lag_national_contrib field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_other_funding field'
  $permissions['node:esi_funds_og:update field_enrd_lag_other_funding field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_phone field'
  $permissions['node:esi_funds_og:update field_enrd_lag_phone field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_phys_demographic field'
  $permissions['node:esi_funds_og:update field_enrd_lag_phys_demographic field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_private_contrib field'
  $permissions['node:esi_funds_og:update field_enrd_lag_private_contrib field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_project_examples field'
  $permissions['node:esi_funds_og:update field_enrd_lag_project_examples field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_size_territory field'
  $permissions['node:esi_funds_og:update field_enrd_lag_size_territory field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_spoken_languages field'
  $permissions['node:esi_funds_og:update field_enrd_lag_spoken_languages field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_staff_num field'
  $permissions['node:esi_funds_og:update field_enrd_lag_staff_num field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_strategy_info field'
  $permissions['node:esi_funds_og:update field_enrd_lag_strategy_info field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_themes_interests field'
  $permissions['node:esi_funds_og:update field_enrd_lag_themes_interests field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_total_budget field'
  $permissions['node:esi_funds_og:update field_enrd_lag_total_budget field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_twitter field'
  $permissions['node:esi_funds_og:update field_enrd_lag_twitter field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_lag_website field'
  $permissions['node:esi_funds_og:update field_enrd_lag_website field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update field_enrd_main_esi_fund field'
  $permissions['node:esi_funds_og:update field_enrd_main_esi_fund field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update og_group_ref field'
  $permissions['node:esi_funds_og:update og_group_ref field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update own discussion content'
  $permissions['node:esi_funds_og:update own discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:esi_funds_og:update own document content'
  $permissions['node:esi_funds_og:update own document content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:esi_funds_og:update own lag content'
  $permissions['node:esi_funds_og:update own lag content'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:esi_funds_og:update title_field field'
  $permissions['node:esi_funds_og:update title_field field'] = array(
    'roles' => array(
      'National manager' => 'National manager',
    ),
  );

  // Exported og permission: 'node:lag:View all unpublished content'
  $permissions['node:lag:View all unpublished content'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:lag:administer group'
  $permissions['node:lag:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:lag:create cooperation_offer content'
  $permissions['node:lag:create cooperation_offer content'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:create discussion content'
  $permissions['node:lag:create discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:lag:create document content'
  $permissions['node:lag:create document content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:lag:delete any cooperation_offer content'
  $permissions['node:lag:delete any cooperation_offer content'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:delete any discussion content'
  $permissions['node:lag:delete any discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:lag:delete any document content'
  $permissions['node:lag:delete any document content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:lag:delete own cooperation_offer content'
  $permissions['node:lag:delete own cooperation_offer content'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:delete own discussion content'
  $permissions['node:lag:delete own discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:lag:delete own document content'
  $permissions['node:lag:delete own document content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:lag:manage members'
  $permissions['node:lag:manage members'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:lag:moderate content from archived to draft'
  $permissions['node:lag:moderate content from archived to draft'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:moderate content from archived to ready_to_be_published'
  $permissions['node:lag:moderate content from archived to ready_to_be_published'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:lag:moderate content from draft to ready_to_be_published'
  $permissions['node:lag:moderate content from draft to ready_to_be_published'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:subscribe'
  $permissions['node:lag:subscribe'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:lag:update any cooperation_offer content'
  $permissions['node:lag:update any cooperation_offer content'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update any discussion content'
  $permissions['node:lag:update any discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:lag:update any document content'
  $permissions['node:lag:update any document content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:lag:update field_enrd_additional_esi_funds field'
  $permissions['node:lag:update field_enrd_additional_esi_funds field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_assets_land_use field'
  $permissions['node:lag:update field_enrd_lag_assets_land_use field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_clld_email field'
  $permissions['node:lag:update field_enrd_lag_clld_email field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_clld_name field'
  $permissions['node:lag:update field_enrd_lag_clld_name field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_coordinates field'
  $permissions['node:lag:update field_enrd_lag_coordinates field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_documentation field'
  $permissions['node:lag:update field_enrd_lag_documentation field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_eafrd_contrib field'
  $permissions['node:lag:update field_enrd_lag_eafrd_contrib field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_emff_contrib field'
  $permissions['node:lag:update field_enrd_lag_emff_contrib field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_entities_num field'
  $permissions['node:lag:update field_enrd_lag_entities_num field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_erdf_contrib field'
  $permissions['node:lag:update field_enrd_lag_erdf_contrib field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_esf_contrib field'
  $permissions['node:lag:update field_enrd_lag_esf_contrib field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_extended_profile field'
  $permissions['node:lag:update field_enrd_lag_extended_profile field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_facebook field'
  $permissions['node:lag:update field_enrd_lag_facebook field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_geo_coverage field'
  $permissions['node:lag:update field_enrd_lag_geo_coverage field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_geo_coverage_sub field'
  $permissions['node:lag:update field_enrd_lag_geo_coverage_sub field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_inhabitants field'
  $permissions['node:lag:update field_enrd_lag_inhabitants field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_interested_in field'
  $permissions['node:lag:update field_enrd_lag_interested_in field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_key_themes field'
  $permissions['node:lag:update field_enrd_lag_key_themes field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_linkedin field'
  $permissions['node:lag:update field_enrd_lag_linkedin field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_logo field'
  $permissions['node:lag:update field_enrd_lag_logo field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_national_contrib field'
  $permissions['node:lag:update field_enrd_lag_national_contrib field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_other_funding field'
  $permissions['node:lag:update field_enrd_lag_other_funding field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_phone field'
  $permissions['node:lag:update field_enrd_lag_phone field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_phys_demographic field'
  $permissions['node:lag:update field_enrd_lag_phys_demographic field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_private_contrib field'
  $permissions['node:lag:update field_enrd_lag_private_contrib field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_project_examples field'
  $permissions['node:lag:update field_enrd_lag_project_examples field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_size_territory field'
  $permissions['node:lag:update field_enrd_lag_size_territory field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_spoken_languages field'
  $permissions['node:lag:update field_enrd_lag_spoken_languages field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_staff_num field'
  $permissions['node:lag:update field_enrd_lag_staff_num field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_strategy_info field'
  $permissions['node:lag:update field_enrd_lag_strategy_info field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_themes_interests field'
  $permissions['node:lag:update field_enrd_lag_themes_interests field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_total_budget field'
  $permissions['node:lag:update field_enrd_lag_total_budget field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_twitter field'
  $permissions['node:lag:update field_enrd_lag_twitter field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update field_enrd_lag_website field'
  $permissions['node:lag:update field_enrd_lag_website field'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update group'
  $permissions['node:lag:update group'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update own cooperation_offer content'
  $permissions['node:lag:update own cooperation_offer content'] = array(
    'roles' => array(
      'LAG Contact' => 'LAG Contact',
      'LAG Manager' => 'LAG Manager',
    ),
  );

  // Exported og permission: 'node:lag:update own discussion content'
  $permissions['node:lag:update own discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:lag:update own document content'
  $permissions['node:lag:update own document content'] = array(
    'roles' => array(),
  );

  return $permissions;
}
