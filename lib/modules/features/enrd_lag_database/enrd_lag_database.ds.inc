<?php

/**
 * @file
 * enrd_lag_database.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function enrd_lag_database_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|cooperation_offer|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'cooperation_offer';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_enrd_coop_type' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_enrd_coop_non_eu_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Non-EU country',
        ),
      ),
    ),
  );
  $export['node|cooperation_offer|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|cooperation_offer|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'cooperation_offer';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'field_enrd_coop_topic_of_project' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_enrd_coop_non_eu_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Non-EU country',
        ),
      ),
    ),
  );
  $export['node|cooperation_offer|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|lag|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'lag';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_enrd_lag_interested_in' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Looking for a Cooperation partner?',
        ),
      ),
    ),
    'field_enrd_lag_manager_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'LAG manager',
        ),
      ),
    ),
  );
  $export['node|lag|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|lag|enrd_lag_database_shared_info';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'lag';
  $ds_fieldsetting->view_mode = 'enrd_lag_database_shared_info';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => '',
        'class' => '',
        'ft' => array(
          'lb' => 'Offering LAG',
        ),
      ),
    ),
    'field_enrd_lag_spoken_languages' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|lag|enrd_lag_database_shared_info'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|lag|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'lag';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'enrd_lag_database_ask_for_publishing' => array(
      'weight' => '35',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_enrd_lag_eafrd_contrib' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_enrd_lag_emff_contrib' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_enrd_lag_erdf_contrib' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_enrd_lag_esf_contrib' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_enrd_lag_interested_in' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Looking for a Cooperation partner?',
        ),
      ),
    ),
    'field_enrd_lag_manager_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'LAG manager',
        ),
      ),
    ),
    'field_enrd_lag_national_contrib' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_enrd_lag_private_contrib' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_enrd_lag_total_budget' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|lag|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|lag|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'lag';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'field_enrd_additional_esi_funds' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|lag|search_result'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function enrd_lag_database_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|cooperation_offer|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'cooperation_offer';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'cooperation_offer_page';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'title_field',
        1 => 'field_enrd_coop_expiry_date',
        2 => 'og_lag_group_ref',
        3 => 'group_enrd_coop_looking_for',
        4 => 'field_enrd_coop_type_of_partner',
        5 => 'group_enrd_coop_project_idea',
        6 => 'field_enrd_coop_partner_country',
        7 => 'field_enrd_coop_type',
        8 => 'field_enrd_coop_partner_region',
        9 => 'field_enrd_coop_topic_of_project',
        10 => 'field_enrd_coop_non_eu_name',
        11 => 'field_enrd_coop_addit_keywords',
        12 => 'field_enrd_coop_context',
        13 => 'field_enrd_coop_type_of_area',
        14 => 'field_enrd_coop_assets_area',
        15 => 'field_enrd_coop_brief_summary',
        16 => 'field_enrd_coop_objectives',
      ),
    ),
    'fields' => array(
      'title_field' => 'main',
      'field_enrd_coop_expiry_date' => 'main',
      'og_lag_group_ref' => 'main',
      'group_enrd_coop_looking_for' => 'main',
      'field_enrd_coop_type_of_partner' => 'main',
      'group_enrd_coop_project_idea' => 'main',
      'field_enrd_coop_partner_country' => 'main',
      'field_enrd_coop_type' => 'main',
      'field_enrd_coop_partner_region' => 'main',
      'field_enrd_coop_topic_of_project' => 'main',
      'field_enrd_coop_non_eu_name' => 'main',
      'field_enrd_coop_addit_keywords' => 'main',
      'field_enrd_coop_context' => 'main',
      'field_enrd_coop_type_of_area' => 'main',
      'field_enrd_coop_assets_area' => 'main',
      'field_enrd_coop_brief_summary' => 'main',
      'field_enrd_coop_objectives' => 'main',
    ),
    'classes' => array(),
    'wrappers' => array(
      'main' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|cooperation_offer|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|cooperation_offer|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'cooperation_offer';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'cooperation_offer_page';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'title_field',
        1 => 'field_enrd_coop_expiry_date',
        2 => 'og_lag_group_ref',
        3 => 'group_enrd_coop_looking_for',
        4 => 'group_enrd_coop_project_idea',
        5 => 'field_enrd_coop_type_of_partner',
        6 => 'field_enrd_coop_partner_country',
        7 => 'field_enrd_coop_type',
        8 => 'field_enrd_coop_partner_region',
        9 => 'field_enrd_coop_topic_of_project',
        10 => 'field_enrd_coop_addit_keywords',
        11 => 'field_enrd_coop_context',
        12 => 'field_enrd_coop_type_of_area',
        13 => 'field_enrd_coop_brief_summary',
        14 => 'field_enrd_coop_assets_area',
        15 => 'field_enrd_coop_objectives',
      ),
    ),
    'fields' => array(
      'title_field' => 'main',
      'field_enrd_coop_expiry_date' => 'main',
      'og_lag_group_ref' => 'main',
      'group_enrd_coop_looking_for' => 'main',
      'group_enrd_coop_project_idea' => 'main',
      'field_enrd_coop_type_of_partner' => 'main',
      'field_enrd_coop_partner_country' => 'main',
      'field_enrd_coop_type' => 'main',
      'field_enrd_coop_partner_region' => 'main',
      'field_enrd_coop_topic_of_project' => 'main',
      'field_enrd_coop_addit_keywords' => 'main',
      'field_enrd_coop_context' => 'main',
      'field_enrd_coop_type_of_area' => 'main',
      'field_enrd_coop_brief_summary' => 'main',
      'field_enrd_coop_assets_area' => 'main',
      'field_enrd_coop_objectives' => 'main',
    ),
    'classes' => array(),
    'wrappers' => array(
      'main' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|cooperation_offer|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|cooperation_offer|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'cooperation_offer';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'cooperation_offer_search';
  $ds_layout->settings = array(
    'regions' => array(
      'coop_lag_country' => array(
        0 => 'field_tax_country',
      ),
      'coop_offer_name' => array(
        1 => 'title_field',
      ),
      'coop_offering_lag' => array(
        2 => 'og_lag_group_ref',
      ),
      'coop_project_type' => array(
        3 => 'field_enrd_coop_type',
      ),
      'coop_expiry_date' => array(
        4 => 'field_enrd_coop_expiry_date',
      ),
    ),
    'fields' => array(
      'field_tax_country' => 'coop_lag_country',
      'title_field' => 'coop_offer_name',
      'og_lag_group_ref' => 'coop_offering_lag',
      'field_enrd_coop_type' => 'coop_project_type',
      'field_enrd_coop_expiry_date' => 'coop_expiry_date',
    ),
    'classes' => array(),
    'wrappers' => array(
      'coop_lag_country' => 'div',
      'coop_offer_name' => 'div',
      'coop_offering_lag' => 'div',
      'coop_project_type' => 'div',
      'coop_expiry_date' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|cooperation_offer|search_result'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|lag|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'lag';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'lag_page';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'title_field',
        1 => 'field_enrd_lag_logo',
        2 => 'field_enrd_lag_code',
        3 => 'field_enrd_lag_country',
        4 => 'og_group_ref',
        5 => 'field_enrd_esif_programme',
        6 => 'field_enrd_additional_esi_funds',
        7 => 'field_enrd_lag_spoken_languages',
        8 => 'field_enrd_lag_email',
        9 => 'field_enrd_lag_manager_name',
        10 => 'field_enrd_lag_manager_email',
        11 => 'field_enrd_lag_phone',
        12 => 'field_enrd_lag_manager_address',
        13 => 'field_enrd_lag_website',
        14 => 'field_enrd_lag_linkedin',
        15 => 'field_enrd_lag_facebook',
        16 => 'field_enrd_lag_twitter',
        17 => 'field_enrd_lag_extended_profile',
        18 => 'field_enrd_lag_key_themes',
        19 => 'field_enrd_lag_strategy_info',
        20 => 'field_enrd_lag_phys_demographic',
        21 => 'field_enrd_lag_assets_land_use',
        22 => 'field_enrd_lag_size_territory',
        23 => 'field_enrd_lag_inhabitants',
        24 => 'field_enrd_lag_geo_coverage',
        25 => 'field_enrd_lag_geo_coverage_sub',
        26 => 'field_enrd_lag_entities_num',
        27 => 'field_enrd_lag_staff_num',
        28 => 'field_enrd_lag_total_budget',
        29 => 'field_enrd_lag_eafrd_contrib',
        30 => 'field_enrd_lag_esf_contrib',
        31 => 'field_enrd_lag_erdf_contrib',
        32 => 'field_enrd_lag_emff_contrib',
        33 => 'field_enrd_lag_other_funding',
        34 => 'field_enrd_lag_national_contrib',
        35 => 'field_enrd_lag_private_contrib',
        36 => 'field_enrd_lag_interested_in',
        37 => 'field_enrd_lag_themes_interests',
        38 => 'field_enrd_lag_clld_name',
        39 => 'field_enrd_lag_clld_email',
        40 => 'field_enrd_lag_project_examples',
        41 => 'field_enrd_lag_documentation',
      ),
    ),
    'fields' => array(
      'title_field' => 'main',
      'field_enrd_lag_logo' => 'main',
      'field_enrd_lag_code' => 'main',
      'field_enrd_lag_country' => 'main',
      'og_group_ref' => 'main',
      'field_enrd_esif_programme' => 'main',
      'field_enrd_additional_esi_funds' => 'main',
      'field_enrd_lag_spoken_languages' => 'main',
      'field_enrd_lag_email' => 'main',
      'field_enrd_lag_manager_name' => 'main',
      'field_enrd_lag_manager_email' => 'main',
      'field_enrd_lag_phone' => 'main',
      'field_enrd_lag_manager_address' => 'main',
      'field_enrd_lag_website' => 'main',
      'field_enrd_lag_linkedin' => 'main',
      'field_enrd_lag_facebook' => 'main',
      'field_enrd_lag_twitter' => 'main',
      'field_enrd_lag_extended_profile' => 'main',
      'field_enrd_lag_key_themes' => 'main',
      'field_enrd_lag_strategy_info' => 'main',
      'field_enrd_lag_phys_demographic' => 'main',
      'field_enrd_lag_assets_land_use' => 'main',
      'field_enrd_lag_size_territory' => 'main',
      'field_enrd_lag_inhabitants' => 'main',
      'field_enrd_lag_geo_coverage' => 'main',
      'field_enrd_lag_geo_coverage_sub' => 'main',
      'field_enrd_lag_entities_num' => 'main',
      'field_enrd_lag_staff_num' => 'main',
      'field_enrd_lag_total_budget' => 'main',
      'field_enrd_lag_eafrd_contrib' => 'main',
      'field_enrd_lag_esf_contrib' => 'main',
      'field_enrd_lag_erdf_contrib' => 'main',
      'field_enrd_lag_emff_contrib' => 'main',
      'field_enrd_lag_other_funding' => 'main',
      'field_enrd_lag_national_contrib' => 'main',
      'field_enrd_lag_private_contrib' => 'main',
      'field_enrd_lag_interested_in' => 'main',
      'field_enrd_lag_themes_interests' => 'main',
      'field_enrd_lag_clld_name' => 'main',
      'field_enrd_lag_clld_email' => 'main',
      'field_enrd_lag_project_examples' => 'main',
      'field_enrd_lag_documentation' => 'main',
    ),
    'classes' => array(),
    'wrappers' => array(
      'headline' => 'div',
      'main' => 'div',
      'contact' => 'div',
      'additional' => 'div',
      'funding' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|lag|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|lag|enrd_lag_database_shared_info';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'lag';
  $ds_layout->view_mode = 'enrd_lag_database_shared_info';
  $ds_layout->layout = 'cooperation_offer_page';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'title',
        1 => 'field_enrd_lag_country',
        2 => 'field_enrd_lag_spoken_languages',
      ),
    ),
    'fields' => array(
      'title' => 'main',
      'field_enrd_lag_country' => 'main',
      'field_enrd_lag_spoken_languages' => 'main',
    ),
    'classes' => array(),
    'wrappers' => array(
      'main' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|lag|enrd_lag_database_shared_info'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|lag|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'lag';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'lag_page';
  $ds_layout->settings = array(
    'regions' => array(
      'enrd_lag_logo' => array(
        0 => 'field_enrd_lag_logo',
      ),
      'headline' => array(
        1 => 'field_enrd_lag_code',
        2 => 'field_enrd_lag_country',
        3 => 'og_group_ref',
        4 => 'field_enrd_esif_programme',
        5 => 'field_enrd_additional_esi_funds',
      ),
      'contact' => array(
        6 => 'field_enrd_lag_spoken_languages',
        7 => 'field_enrd_lag_email',
        8 => 'field_enrd_lag_manager_name',
        9 => 'field_enrd_lag_manager_email',
        10 => 'field_enrd_lag_phone',
        11 => 'field_enrd_lag_manager_address',
        12 => 'field_enrd_lag_website',
        13 => 'field_enrd_lag_linkedin',
        14 => 'field_enrd_lag_facebook',
        15 => 'field_enrd_lag_twitter',
      ),
      'additional' => array(
        16 => 'field_enrd_lag_key_themes',
        17 => 'field_enrd_lag_strategy_info',
        18 => 'field_enrd_lag_phys_demographic',
        19 => 'field_enrd_lag_assets_land_use',
        20 => 'field_enrd_lag_size_territory',
        21 => 'field_enrd_lag_inhabitants',
        22 => 'field_enrd_lag_geo_coverage',
        23 => 'field_enrd_lag_geo_coverage_sub',
        24 => 'field_enrd_lag_entities_num',
        25 => 'field_enrd_lag_staff_num',
      ),
      'funding' => array(
        26 => 'field_enrd_lag_total_budget',
        27 => 'field_enrd_lag_eafrd_contrib',
        28 => 'field_enrd_lag_esf_contrib',
        29 => 'field_enrd_lag_erdf_contrib',
        30 => 'field_enrd_lag_emff_contrib',
        31 => 'field_enrd_lag_other_funding',
        32 => 'field_enrd_lag_national_contrib',
        33 => 'field_enrd_lag_private_contrib',
      ),
      'moderation' => array(
        34 => 'enrd_lag_database_ask_for_publishing',
      ),
      'enrd_lag_cooperation_details' => array(
        35 => 'field_enrd_lag_interested_in',
        36 => 'field_enrd_lag_themes_interests',
        37 => 'field_enrd_lag_clld_name',
        38 => 'field_enrd_lag_clld_email',
      ),
      'enrd_lag_other_useful_info' => array(
        39 => 'field_enrd_lag_project_examples',
        40 => 'field_enrd_lag_documentation',
      ),
      'enrd_lag_extended_profile' => array(
        41 => 'field_enrd_lag_extended_profile',
      ),
    ),
    'fields' => array(
      'field_enrd_lag_logo' => 'enrd_lag_logo',
      'field_enrd_lag_code' => 'headline',
      'field_enrd_lag_country' => 'headline',
      'og_group_ref' => 'headline',
      'field_enrd_esif_programme' => 'headline',
      'field_enrd_additional_esi_funds' => 'headline',
      'field_enrd_lag_spoken_languages' => 'contact',
      'field_enrd_lag_email' => 'contact',
      'field_enrd_lag_manager_name' => 'contact',
      'field_enrd_lag_manager_email' => 'contact',
      'field_enrd_lag_phone' => 'contact',
      'field_enrd_lag_manager_address' => 'contact',
      'field_enrd_lag_website' => 'contact',
      'field_enrd_lag_linkedin' => 'contact',
      'field_enrd_lag_facebook' => 'contact',
      'field_enrd_lag_twitter' => 'contact',
      'field_enrd_lag_key_themes' => 'additional',
      'field_enrd_lag_strategy_info' => 'additional',
      'field_enrd_lag_phys_demographic' => 'additional',
      'field_enrd_lag_assets_land_use' => 'additional',
      'field_enrd_lag_size_territory' => 'additional',
      'field_enrd_lag_inhabitants' => 'additional',
      'field_enrd_lag_geo_coverage' => 'additional',
      'field_enrd_lag_geo_coverage_sub' => 'additional',
      'field_enrd_lag_entities_num' => 'additional',
      'field_enrd_lag_staff_num' => 'additional',
      'field_enrd_lag_total_budget' => 'funding',
      'field_enrd_lag_eafrd_contrib' => 'funding',
      'field_enrd_lag_esf_contrib' => 'funding',
      'field_enrd_lag_erdf_contrib' => 'funding',
      'field_enrd_lag_emff_contrib' => 'funding',
      'field_enrd_lag_other_funding' => 'funding',
      'field_enrd_lag_national_contrib' => 'funding',
      'field_enrd_lag_private_contrib' => 'funding',
      'enrd_lag_database_ask_for_publishing' => 'moderation',
      'field_enrd_lag_interested_in' => 'enrd_lag_cooperation_details',
      'field_enrd_lag_themes_interests' => 'enrd_lag_cooperation_details',
      'field_enrd_lag_clld_name' => 'enrd_lag_cooperation_details',
      'field_enrd_lag_clld_email' => 'enrd_lag_cooperation_details',
      'field_enrd_lag_project_examples' => 'enrd_lag_other_useful_info',
      'field_enrd_lag_documentation' => 'enrd_lag_other_useful_info',
      'field_enrd_lag_extended_profile' => 'enrd_lag_extended_profile',
    ),
    'classes' => array(),
    'wrappers' => array(
      'headline' => 'div',
      'main' => 'div',
      'contact' => 'div',
      'additional' => 'div',
      'funding' => 'div',
      'moderation' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|lag|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|lag|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'lag';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'lag_search';
  $ds_layout->settings = array(
    'regions' => array(
      'lag_country' => array(
        0 => 'field_enrd_lag_country',
      ),
      'lag_name' => array(
        1 => 'title_field',
      ),
      'lag_main_esi_fund' => array(
        2 => 'field_enrd_main_esi_fund',
      ),
      'lag_esif_programme' => array(
        3 => 'field_enrd_esif_programme',
      ),
    ),
    'fields' => array(
      'field_enrd_lag_country' => 'lag_country',
      'title_field' => 'lag_name',
      'field_enrd_main_esi_fund' => 'lag_main_esi_fund',
      'field_enrd_esif_programme' => 'lag_esif_programme',
    ),
    'classes' => array(),
    'wrappers' => array(
      'lag_country' => 'div',
      'lag_name' => 'div',
      'lag_main_esi_fund' => 'div',
      'lag_esif_programme' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|lag|search_result'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function enrd_lag_database_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'enrd_esi_fund_long_name';
  $ds_view_mode->label = 'Long Name';
  $ds_view_mode->entities = array(
    'taxonomy_term' => 'taxonomy_term',
  );
  $export['enrd_esi_fund_long_name'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'enrd_lag_database_shared_info';
  $ds_view_mode->label = 'Coop shared Info';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['enrd_lag_database_shared_info'] = $ds_view_mode;

  return $export;
}
