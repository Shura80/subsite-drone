<?php

/**
 * @file
 * agri_core.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function agri_core_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|collaborative_area|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'collaborative_area';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'comments' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|collaborative_area|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|forum|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'forum';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'links' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|forum|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|gallery|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'gallery';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'comments' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|gallery|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'taxonomy_term|core_stakeholders|core_spotlight';
  $ds_fieldsetting->entity_type = 'taxonomy_term';
  $ds_fieldsetting->bundle = 'core_stakeholders';
  $ds_fieldsetting->view_mode = 'core_spotlight';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h4',
        'class' => '',
      ),
    ),
  );
  $export['taxonomy_term|core_stakeholders|core_spotlight'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function agri_core_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|agri_static_block|default';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'agri_static_block';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_agri_core_bean_image',
        1 => 'field_agri_core_bean_body',
        2 => 'field_agri_core_bean_link',
      ),
    ),
    'fields' => array(
      'field_agri_core_bean_image' => 'ds_content',
      'field_agri_core_bean_body' => 'ds_content',
      'field_agri_core_bean_link' => 'ds_content',
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
    'layout_disable_css' => FALSE,
  );
  $export['bean|agri_static_block|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|collaborative_area|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'collaborative_area';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'field_collaborative_attachments',
        2 => 'webform',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'field_collaborative_attachments' => 'ds_content',
      'webform' => 'ds_content',
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
  $export['node|collaborative_area|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|collaborative_area|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'collaborative_area';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'field_collaborative_attachments',
        2 => 'comments',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'field_collaborative_attachments' => 'ds_content',
      'comments' => 'ds_content',
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
  $export['node|collaborative_area|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|forum|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'forum';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'taxonomy_forums',
      ),
      'footer' => array(
        1 => 'body',
        2 => 'links',
        3 => 'comments',
      ),
    ),
    'fields' => array(
      'taxonomy_forums' => 'header',
      'body' => 'footer',
      'links' => 'footer',
      'comments' => 'footer',
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
  $export['node|forum|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|gallery|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'gallery';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_3col_stacked_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'middle' => array(
        0 => 'comments',
        1 => 'body',
        2 => 'field_pictures',
      ),
    ),
    'fields' => array(
      'comments' => 'middle',
      'body' => 'middle',
      'field_pictures' => 'middle',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'middle' => 'div',
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
  $export['node|gallery|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'taxonomy_term|core_stakeholders|core_spotlight';
  $ds_layout->entity_type = 'taxonomy_term';
  $ds_layout->bundle = 'core_stakeholders';
  $ds_layout->view_mode = 'core_spotlight';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_core_stakeholder_image',
      ),
      'right' => array(
        1 => 'title',
        2 => 'field_core_stakeholder_summary',
      ),
    ),
    'fields' => array(
      'field_core_stakeholder_image' => 'left',
      'title' => 'right',
      'field_core_stakeholder_summary' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        'row' => 'row',
      ),
      'left' => array(
        'col-md-8' => 'col-md-8',
      ),
      'right' => array(
        'col-md-4' => 'col-md-4',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['taxonomy_term|core_stakeholders|core_spotlight'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|default';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
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
  $export['user|user|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|form';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_firstname',
        1 => 'field_lastname',
        2 => 'account',
        3 => 'group_user_main',
        4 => 'group_user_details',
        5 => 'group_user_tags',
        6 => 'field_organization_collection',
        7 => 'group_user_other_info',
        8 => 'field_user_gender',
        9 => 'field_user_spec_admin_level',
        10 => 'field_core_geographical_area',
        11 => 'field_core_keywords',
        12 => 'field_core_other_location',
        13 => 'field_core_agricultural_sectors',
        14 => 'field_user_city',
        15 => 'field_user_type',
        16 => 'field_user_address',
        17 => 'field_user_involved',
        18 => 'field_user_specify_other',
        19 => 'field_user_spec_type',
        20 => 'field_user_phone',
        21 => 'group_user_farmer',
        22 => 'field_user_website',
        23 => 'field_user_spec_type_other',
        24 => 'group_user_land_owner',
        25 => 'field_user_birthdate',
        26 => 'field_user_spec_land_type',
        27 => 'field_user_spec_size_farm_land',
        28 => 'field_user_spec_forester_type',
        29 => 'field_user_spec_land_type_other',
        30 => 'field_user_spec_advisor_type',
        31 => 'field_user_spec_forest_type',
        32 => 'group_user_forester',
        33 => 'field_user_spec_advisor_other',
        34 => 'field_user_spec_forest_utilizati',
        35 => 'field_user_spec_advisor_sector',
        36 => 'field_user_spec_forest_other',
        37 => 'field_user_spec_size',
        38 => 'group_user_advisor',
        40 => 'field_user_language_spoken',
        41 => 'field_user_spec_rdp',
        42 => 'field_user_accept_terms',
        43 => 'group_user_research_repres',
        45 => 'field_user_spec_media_type',
        46 => 'field_core_specify_language',
        47 => 'field_user_spec_portfolio',
        49 => 'field_user_specify_media',
        50 => 'group_user_press',
        51 => 'field_user_featured_internal_db',
        53 => 'group_user_civil',
        54 => 'field_user_picture',
        55 => 'field_user_cv',
        57 => 'og_user_node',
        59 => 'locale',
        61 => 'timezone',
        62 => 'contact',
        63 => 'field_core_additional_info',
        64 => 'field_user_spec_position',
        65 => 'field_user_position_researcher',
        66 => 'field_user_position_industry',
        67 => 'field_user_spec_sector',
        68 => 'field_user_spec_sector_other',
        69 => 'field_user_position_retailer',
        70 => 'field_user_sector_retailer',
        72 => 'field_user_position_whole',
        73 => 'field_user_sector_whole',
        75 => 'field_user_position_rep',
        76 => 'field_user_position_civil',
      ),
      'hidden' => array(
        39 => 'mimemail',
        44 => 'googleanalytics',
        48 => 'picture',
        52 => 'wysiwyg',
        56 => 'field_creator',
        58 => 'xmlsitemap',
        60 => 'group_industry_retail_wholesale',
        71 => 'field_user_specify_ret',
        74 => 'field_user_specify_whole',
        77 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_firstname' => 'ds_content',
      'field_lastname' => 'ds_content',
      'account' => 'ds_content',
      'group_user_main' => 'ds_content',
      'group_user_details' => 'ds_content',
      'group_user_tags' => 'ds_content',
      'field_organization_collection' => 'ds_content',
      'group_user_other_info' => 'ds_content',
      'field_user_gender' => 'ds_content',
      'field_user_spec_admin_level' => 'ds_content',
      'field_core_geographical_area' => 'ds_content',
      'field_core_keywords' => 'ds_content',
      'field_core_other_location' => 'ds_content',
      'field_core_agricultural_sectors' => 'ds_content',
      'field_user_city' => 'ds_content',
      'field_user_type' => 'ds_content',
      'field_user_address' => 'ds_content',
      'field_user_involved' => 'ds_content',
      'field_user_specify_other' => 'ds_content',
      'field_user_spec_type' => 'ds_content',
      'field_user_phone' => 'ds_content',
      'group_user_farmer' => 'ds_content',
      'field_user_website' => 'ds_content',
      'field_user_spec_type_other' => 'ds_content',
      'group_user_land_owner' => 'ds_content',
      'field_user_birthdate' => 'ds_content',
      'field_user_spec_land_type' => 'ds_content',
      'field_user_spec_size_farm_land' => 'ds_content',
      'field_user_spec_forester_type' => 'ds_content',
      'field_user_spec_land_type_other' => 'ds_content',
      'field_user_spec_advisor_type' => 'ds_content',
      'field_user_spec_forest_type' => 'ds_content',
      'group_user_forester' => 'ds_content',
      'field_user_spec_advisor_other' => 'ds_content',
      'field_user_spec_forest_utilizati' => 'ds_content',
      'field_user_spec_advisor_sector' => 'ds_content',
      'field_user_spec_forest_other' => 'ds_content',
      'field_user_spec_size' => 'ds_content',
      'group_user_advisor' => 'ds_content',
      'mimemail' => 'hidden',
      'field_user_language_spoken' => 'ds_content',
      'field_user_spec_rdp' => 'ds_content',
      'field_user_accept_terms' => 'ds_content',
      'group_user_research_repres' => 'ds_content',
      'googleanalytics' => 'hidden',
      'field_user_spec_media_type' => 'ds_content',
      'field_core_specify_language' => 'ds_content',
      'field_user_spec_portfolio' => 'ds_content',
      'picture' => 'hidden',
      'field_user_specify_media' => 'ds_content',
      'group_user_press' => 'ds_content',
      'field_user_featured_internal_db' => 'ds_content',
      'wysiwyg' => 'hidden',
      'group_user_civil' => 'ds_content',
      'field_user_picture' => 'ds_content',
      'field_user_cv' => 'ds_content',
      'field_creator' => 'hidden',
      'og_user_node' => 'ds_content',
      'xmlsitemap' => 'hidden',
      'locale' => 'ds_content',
      'group_industry_retail_wholesale' => 'hidden',
      'timezone' => 'ds_content',
      'contact' => 'ds_content',
      'field_core_additional_info' => 'ds_content',
      'field_user_spec_position' => 'ds_content',
      'field_user_position_researcher' => 'ds_content',
      'field_user_position_industry' => 'ds_content',
      'field_user_spec_sector' => 'ds_content',
      'field_user_spec_sector_other' => 'ds_content',
      'field_user_position_retailer' => 'ds_content',
      'field_user_sector_retailer' => 'ds_content',
      'field_user_specify_ret' => 'hidden',
      'field_user_position_whole' => 'ds_content',
      'field_user_sector_whole' => 'ds_content',
      'field_user_specify_whole' => 'hidden',
      'field_user_position_rep' => 'ds_content',
      'field_user_position_civil' => 'ds_content',
      '_add_existing_field' => 'hidden',
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
  $export['user|user|form'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function agri_core_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'core_small_teaser';
  $ds_view_mode->label = 'Small Teaser';
  $ds_view_mode->entities = array(
    'node' => 'node',
    'taxonomy_term' => 'taxonomy_term',
  );
  $export['core_small_teaser'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'core_spotlight';
  $ds_view_mode->label = 'Spotlight';
  $ds_view_mode->entities = array(
    'node' => 'node',
    'taxonomy_term' => 'taxonomy_term',
  );
  $export['core_spotlight'] = $ds_view_mode;

  return $export;
}
