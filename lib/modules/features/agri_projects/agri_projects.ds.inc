<?php

/**
 * @file
 * agri_projects.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function agri_projects_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|needs_for_research_from_practice|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'needs_for_research_from_practice';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'post_date' => array(
      'weight' => '8',
      'label' => 'inline',
      'format' => 'ds_post_date_eip_agri_medium',
    ),
  );
  $export['node|needs_for_research_from_practice|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|needs_for_research_from_practice|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'needs_for_research_from_practice';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h5',
        'class' => '',
      ),
    ),
  );
  $export['node|needs_for_research_from_practice|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|operational_group|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'operational_group';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h4',
        'class' => '',
      ),
    ),
  );
  $export['node|operational_group|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|project_ideas|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'project_ideas';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'post_date' => array(
      'weight' => '11',
      'label' => 'inline',
      'format' => 'ds_post_date_eip_agri_medium',
    ),
  );
  $export['node|project_ideas|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|project|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'project';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|project|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|project|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'project';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h5',
        'class' => '',
      ),
    ),
  );
  $export['node|project|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function agri_projects_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|innovative_action|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'innovative_action';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_projects_dates',
        1 => 'field_projects_status',
        2 => 'field_projects_funding_source',
        4 => 'field_core_keywords',
        5 => 'field_projects_active',
        6 => 'field_projects_website',
        7 => 'field_core_email',
        8 => 'field_projects_budget',
      ),
      'footer' => array(
        9 => 'field_organization_collection',
        10 => 'body',
        11 => 'field_projects_results',
        12 => 'field_projects_problems',
        13 => 'field_projects_group',
        14 => 'field_projects_outcomes_eng',
        15 => 'field_projects_outcomes',
        16 => 'field_core_title_eng',
        17 => 'field_core_additional_info',
        18 => 'field_core_description_eng',
        19 => 'field_projects_contact_info',
        20 => 'field_projects_publications',
      ),
    ),
    'fields' => array(
      'field_projects_dates' => 'header',
      'field_projects_status' => 'header',
      'field_projects_funding_source' => 'header',
      'field_core_keywords' => 'header',
      'field_projects_active' => 'header',
      'field_projects_website' => 'header',
      'field_core_email' => 'header',
      'field_projects_budget' => 'header',
      'field_organization_collection' => 'footer',
      'body' => 'footer',
      'field_projects_results' => 'footer',
      'field_projects_problems' => 'footer',
      'field_projects_group' => 'footer',
      'field_projects_outcomes_eng' => 'footer',
      'field_projects_outcomes' => 'footer',
      'field_core_title_eng' => 'footer',
      'field_core_additional_info' => 'footer',
      'field_core_description_eng' => 'footer',
      'field_projects_contact_info' => 'footer',
      'field_projects_publications' => 'footer',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|innovative_action|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|needs_for_research_from_practice|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'needs_for_research_from_practice';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_core_geographical_area',
        1 => 'field_core_other_location',
        2 => 'field_core_keywords',
      ),
      'footer' => array(
        3 => 'body',
        4 => 'field_core_description_eng',
        5 => 'field_core_additional_info',
        6 => 'group_contact_infomation',
        7 => 'field_projects_name',
        8 => 'field_projects_surname',
        9 => 'field_core_attachments',
        10 => 'field_user_language_spoken',
        11 => 'field_core_email',
        12 => 'post_date',
      ),
    ),
    'fields' => array(
      'field_core_geographical_area' => 'header',
      'field_core_other_location' => 'header',
      'field_core_keywords' => 'header',
      'body' => 'footer',
      'field_core_description_eng' => 'footer',
      'field_core_additional_info' => 'footer',
      'group_contact_infomation' => 'footer',
      'field_projects_name' => 'footer',
      'field_projects_surname' => 'footer',
      'field_core_attachments' => 'footer',
      'field_user_language_spoken' => 'footer',
      'field_core_email' => 'footer',
      'post_date' => 'footer',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|needs_for_research_from_practice|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|needs_for_research_from_practice|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'needs_for_research_from_practice';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|needs_for_research_from_practice|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|operational_group|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'operational_group';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_projects_funding_type',
        1 => 'field_user_type',
        2 => 'field_core_geographical_area',
        4 => 'field_core_keywords',
        5 => 'field_projects_website',
        6 => 'field_core_email',
      ),
      'footer' => array(
        7 => 'field_projects_active',
        8 => 'body',
        9 => 'field_core_description_eng',
        10 => 'field_projects_outcomes',
        11 => 'field_projects_outcomes_eng',
        12 => 'field_core_additional_info',
        13 => 'field_projects_contact_point',
        14 => 'field_organization_collection',
        15 => 'field_projects_other_partners',
        16 => 'field_core_attachments',
      ),
    ),
    'fields' => array(
      'field_projects_funding_type' => 'header',
      'field_user_type' => 'header',
      'field_core_geographical_area' => 'header',
      'field_core_keywords' => 'header',
      'field_projects_website' => 'header',
      'field_core_email' => 'header',
      'field_projects_active' => 'footer',
      'body' => 'footer',
      'field_core_description_eng' => 'footer',
      'field_projects_outcomes' => 'footer',
      'field_projects_outcomes_eng' => 'footer',
      'field_core_additional_info' => 'footer',
      'field_projects_contact_point' => 'footer',
      'field_organization_collection' => 'footer',
      'field_projects_other_partners' => 'footer',
      'field_core_attachments' => 'footer',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|operational_group|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|operational_group|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'operational_group';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'body',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|operational_group|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|project_ideas|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'project_ideas';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_projects_duration_months',
        1 => 'field_user_language_spoken',
        2 => 'field_core_email',
      ),
      'footer' => array(
        3 => 'field_core_title_eng',
        4 => 'body',
        5 => 'field_core_description_eng',
        6 => 'field_projects_outcomes',
        7 => 'field_projects_outcomes_eng',
        8 => 'field_project_searching',
        9 => 'field_core_additional_info',
        10 => 'field_projects_publications',
        11 => 'post_date',
      ),
    ),
    'fields' => array(
      'field_projects_duration_months' => 'header',
      'field_user_language_spoken' => 'header',
      'field_core_email' => 'header',
      'field_core_title_eng' => 'footer',
      'body' => 'footer',
      'field_core_description_eng' => 'footer',
      'field_projects_outcomes' => 'footer',
      'field_projects_outcomes_eng' => 'footer',
      'field_project_searching' => 'footer',
      'field_core_additional_info' => 'footer',
      'field_projects_publications' => 'footer',
      'post_date' => 'footer',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|project_ideas|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|project|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'project';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_proj_geographical_area',
        1 => 'field_proj_other_location',
        2 => 'nuts_region',
        3 => 'field_proj_nuts_region_other_2',
        4 => 'field_proj_nuts_region_other_1',
        5 => 'field_core_keywords',
        6 => 'field_agri_proj_internal_kwords',
        7 => 'field_core_agricultural_sectors',
        8 => 'field_proj_funding_source_list',
        9 => 'field_proj_rp_acronym',
        10 => 'field_proj_sfc_identification',
        11 => 'field_proj_project_type',
        12 => 'field_proj_starting_date',
        13 => 'field_proj_end_date',
        14 => 'field_proj_og_project_status',
        15 => 'field_proj_website',
      ),
      'footer' => array(
        16 => 'field_proj_title_eng',
        17 => 'field_projects_language',
        18 => 'field_proj_problems',
        19 => 'field_proj_problems_eng',
        20 => 'field_proj_desc',
        21 => 'field_proj_desc_eng',
        22 => 'field_proj_og_budget',
        23 => 'field_proj_og_eu_contribution',
        24 => 'field_proj_ia_contact_person',
        25 => 'field_proj_contact_e_mail',
        26 => 'field_proj_og_cross_border',
        27 => 'field_proj_coordinator_fc',
        28 => 'field_proj_partner_fc',
        29 => 'flag_agri_privacy_policy',
        30 => 'group_proj_partners',
        31 => 'field_proj_partners_categories',
        32 => 'group_agri_projects_sfc',
        33 => 'group_proj_further_details',
        34 => 'field_proj_attachment',
        35 => 'field_sfc_proj_summary',
        36 => 'field_proj_other_websites',
        37 => 'flag_agri_digitization_toolbox',
        38 => 'field_proj_audiovisual_material',
        39 => 'field_proj_desc_context',
        40 => 'field_proj_additional_info',
        41 => 'field_proj_additional_comments',
      ),
    ),
    'fields' => array(
      'field_proj_geographical_area' => 'header',
      'field_proj_other_location' => 'header',
      'nuts_region' => 'header',
      'field_proj_nuts_region_other_2' => 'header',
      'field_proj_nuts_region_other_1' => 'header',
      'field_core_keywords' => 'header',
      'field_agri_proj_internal_kwords' => 'header',
      'field_core_agricultural_sectors' => 'header',
      'field_proj_funding_source_list' => 'header',
      'field_proj_rp_acronym' => 'header',
      'field_proj_sfc_identification' => 'header',
      'field_proj_project_type' => 'header',
      'field_proj_starting_date' => 'header',
      'field_proj_end_date' => 'header',
      'field_proj_og_project_status' => 'header',
      'field_proj_website' => 'header',
      'field_proj_title_eng' => 'footer',
      'field_projects_language' => 'footer',
      'field_proj_problems' => 'footer',
      'field_proj_problems_eng' => 'footer',
      'field_proj_desc' => 'footer',
      'field_proj_desc_eng' => 'footer',
      'field_proj_og_budget' => 'footer',
      'field_proj_og_eu_contribution' => 'footer',
      'field_proj_ia_contact_person' => 'footer',
      'field_proj_contact_e_mail' => 'footer',
      'field_proj_og_cross_border' => 'footer',
      'field_proj_coordinator_fc' => 'footer',
      'field_proj_partner_fc' => 'footer',
      'flag_agri_privacy_policy' => 'footer',
      'group_proj_partners' => 'footer',
      'field_proj_partners_categories' => 'footer',
      'group_agri_projects_sfc' => 'footer',
      'group_proj_further_details' => 'footer',
      'field_proj_attachment' => 'footer',
      'field_sfc_proj_summary' => 'footer',
      'field_proj_other_websites' => 'footer',
      'flag_agri_digitization_toolbox' => 'footer',
      'field_proj_audiovisual_material' => 'footer',
      'field_proj_desc_context' => 'footer',
      'field_proj_additional_info' => 'footer',
      'field_proj_additional_comments' => 'footer',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|project|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|project|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'project';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|project|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|research_project|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'research_project';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_projects_dates',
        1 => 'field_projects_budget',
        2 => 'field_projects_code',
        3 => 'field_projects_active',
        4 => 'field_core_email',
        5 => 'field_projects_website',
        7 => 'field_core_keywords',
      ),
      'footer' => array(
        8 => 'field_core_title_eng',
        9 => 'body',
        10 => 'field_core_description_eng',
        11 => 'field_projects_problems',
        12 => 'field_projects_objectives',
        13 => 'field_projects_group',
        14 => 'field_projects_outcomes',
        15 => 'field_projects_outcomes_eng',
        16 => 'field_core_additional_info',
        17 => 'field_organization_collection',
        18 => 'field_projects_funding_source',
        19 => 'field_projects_publications',
      ),
    ),
    'fields' => array(
      'field_projects_dates' => 'header',
      'field_projects_budget' => 'header',
      'field_projects_code' => 'header',
      'field_projects_active' => 'header',
      'field_core_email' => 'header',
      'field_projects_website' => 'header',
      'field_core_keywords' => 'header',
      'field_core_title_eng' => 'footer',
      'body' => 'footer',
      'field_core_description_eng' => 'footer',
      'field_projects_problems' => 'footer',
      'field_projects_objectives' => 'footer',
      'field_projects_group' => 'footer',
      'field_projects_outcomes' => 'footer',
      'field_projects_outcomes_eng' => 'footer',
      'field_core_additional_info' => 'footer',
      'field_organization_collection' => 'footer',
      'field_projects_funding_source' => 'footer',
      'field_projects_publications' => 'footer',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|research_project|full'] = $ds_layout;

  return $export;
}
