<?php

/**
 * @file
 * enrd_nrn_profiles.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function enrd_nrn_profiles_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|nrn_profile|enrd_nrn_toolkit_resource';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'nrn_profile';
  $ds_fieldsetting->view_mode = 'enrd_nrn_toolkit_resource';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => 'media-heading',
        'ft' => array(),
      ),
    ),
  );
  $export['node|nrn_profile|enrd_nrn_toolkit_resource'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|nrn_profile|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'nrn_profile';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'field_enrd_nrnp_activities' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_enrd_nrnp_cooperation' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_enrd_nrnp_highlights' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_enrd_nrnp_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_enrd_nrnp_video' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'lb-col' => TRUE,
        ),
      ),
    ),
  );
  $export['node|nrn_profile|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|nrn_profile|landing_page_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'nrn_profile';
  $ds_fieldsetting->view_mode = 'landing_page_teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'field_enrd_nrnp_brief_intro' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_enrd_nrnp_logo' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|nrn_profile|landing_page_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|nrn_profile|print';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'nrn_profile';
  $ds_fieldsetting->view_mode = 'print';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_enrd_nrnp_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_enrd_nrnp_video' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|nrn_profile|print'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function enrd_nrn_profiles_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|nrn_profile|enrd_nrn_toolkit_resource';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'nrn_profile';
  $ds_layout->view_mode = 'enrd_nrn_toolkit_resource';
  $ds_layout->layout = 'nrn_page';
  $ds_layout->settings = array(
    'regions' => array(
      'headline' => array(
        0 => 'title',
      ),
      'abstract' => array(
        1 => 'field_enrd_nrnp_brief_intro',
      ),
      'meta' => array(
        2 => 'group_nrn_toolkit_fieldset',
        3 => 'field_enrd_nrnp_country_page',
      ),
      'nrn_title' => array(
        4 => 'field_enrd_nrn_title',
      ),
      'nrn_description' => array(
        5 => 'field_enrd_nrn_alter_description',
      ),
    ),
    'fields' => array(
      'title' => 'headline',
      'field_enrd_nrnp_brief_intro' => 'abstract',
      'group_nrn_toolkit_fieldset' => 'meta',
      'field_enrd_nrnp_country_page' => 'meta',
      'field_enrd_nrn_title' => 'nrn_title',
      'field_enrd_nrn_alter_description' => 'nrn_description',
    ),
    'classes' => array(),
    'wrappers' => array(
      'thumb' => 'div',
      'headline' => 'div',
      'abstract' => 'div',
      'meta' => 'div',
      'nrn_title' => 'div',
      'nrn_description' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|nrn_profile|enrd_nrn_toolkit_resource'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|nrn_profile|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'nrn_profile';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'nrn_profiles_page';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'field_enrd_nrnp_brief_intro',
        1 => 'field_enrd_nrnp_highlights',
        2 => 'field_enrd_nrnp_activities',
        3 => 'field_enrd_nrnp_cooperation',
        4 => 'field_enrd_nrnp_organisation',
        5 => 'group_enrd_nrnp_contacts_ds',
        6 => 'field_enrd_nrnp_address',
        11 => 'field_enrd_nrnp_phone',
        13 => 'field_enrd_nrnp_email',
        19 => 'field_enrd_nrnp_contact_persons',
      ),
      'links' => array(
        7 => 'group_enrd_nrnp_links_ds',
        8 => 'field_enrd_nrnp_website',
        12 => 'field_enrd_nrnp_internal_links',
        14 => 'field_enrd_nrnp_external_links',
        17 => 'field_enrd_nrnp_social_media',
      ),
      'nsu_operation' => array(
        9 => 'field_enrd_nrnp_objectives',
        10 => 'group_enrd_nrnp_nsu_operation_ds',
        16 => 'field_enrd_nrnp_membership',
        20 => 'field_enrd_nrnp_nsu_rdp',
        22 => 'field_enrd_nrnp_reg_repres',
        24 => 'field_enrd_nrnp_governance',
        25 => 'field_enrd_nrnp_finan_resources',
      ),
      'side_right' => array(
        15 => 'field_enrd_nrnp_logo',
        18 => 'field_enrd_nrnp_documents',
        21 => 'field_enrd_nrnp_image',
        23 => 'field_enrd_nrnp_video',
      ),
    ),
    'fields' => array(
      'field_enrd_nrnp_brief_intro' => 'main',
      'field_enrd_nrnp_highlights' => 'main',
      'field_enrd_nrnp_activities' => 'main',
      'field_enrd_nrnp_cooperation' => 'main',
      'field_enrd_nrnp_organisation' => 'main',
      'group_enrd_nrnp_contacts_ds' => 'main',
      'field_enrd_nrnp_address' => 'main',
      'group_enrd_nrnp_links_ds' => 'links',
      'field_enrd_nrnp_website' => 'links',
      'field_enrd_nrnp_objectives' => 'nsu_operation',
      'group_enrd_nrnp_nsu_operation_ds' => 'nsu_operation',
      'field_enrd_nrnp_phone' => 'main',
      'field_enrd_nrnp_internal_links' => 'links',
      'field_enrd_nrnp_email' => 'main',
      'field_enrd_nrnp_external_links' => 'links',
      'field_enrd_nrnp_logo' => 'side_right',
      'field_enrd_nrnp_membership' => 'nsu_operation',
      'field_enrd_nrnp_social_media' => 'links',
      'field_enrd_nrnp_documents' => 'side_right',
      'field_enrd_nrnp_contact_persons' => 'main',
      'field_enrd_nrnp_nsu_rdp' => 'nsu_operation',
      'field_enrd_nrnp_image' => 'side_right',
      'field_enrd_nrnp_reg_repres' => 'nsu_operation',
      'field_enrd_nrnp_video' => 'side_right',
      'field_enrd_nrnp_governance' => 'nsu_operation',
      'field_enrd_nrnp_finan_resources' => 'nsu_operation',
    ),
    'classes' => array(),
    'wrappers' => array(
      'main' => 'div',
      'links' => 'div',
      'nsu_operation' => 'div',
      'side_right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|nrn_profile|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|nrn_profile|landing_page_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'nrn_profile';
  $ds_layout->view_mode = 'landing_page_teaser';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'title',
      ),
      'right' => array(
        1 => 'field_enrd_nrnp_brief_intro',
      ),
      'left' => array(
        2 => 'field_enrd_nrnp_logo',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'field_enrd_nrnp_brief_intro' => 'right',
      'field_enrd_nrnp_logo' => 'left',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'article',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|nrn_profile|landing_page_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|nrn_profile|print';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'nrn_profile';
  $ds_layout->view_mode = 'print';
  $ds_layout->layout = 'nrn_profiles_page';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'title',
        1 => 'field_enrd_nrnp_brief_intro',
        2 => 'field_enrd_nrnp_highlights',
        3 => 'field_enrd_nrnp_activities',
        4 => 'field_enrd_nrnp_cooperation',
        5 => 'field_enrd_nrnp_organisation',
        6 => 'field_enrd_nrnp_address',
        7 => 'group_enrd_nrnp_contacts_ds',
        12 => 'field_enrd_nrnp_phone',
        15 => 'field_enrd_nrnp_email',
        18 => 'field_enrd_nrnp_contact_persons',
      ),
      'links' => array(
        8 => 'field_enrd_nrnp_website',
        10 => 'group_enrd_nrnp_links_ds',
        11 => 'field_enrd_nrnp_internal_links',
        13 => 'field_enrd_nrnp_external_links',
        17 => 'field_enrd_nrnp_social_media',
      ),
      'nsu_operation' => array(
        9 => 'field_enrd_nrnp_objectives',
        14 => 'group_enrd_nrnp_nsu_operation_ds',
        16 => 'field_enrd_nrnp_membership',
        20 => 'field_enrd_nrnp_nsu_rdp',
        21 => 'field_enrd_nrnp_reg_repres',
        24 => 'field_enrd_nrnp_governance',
        26 => 'field_enrd_nrnp_finan_resources',
      ),
      'side_right' => array(
        19 => 'field_enrd_nrnp_documents',
        22 => 'field_enrd_nrnp_logo',
        23 => 'field_enrd_nrnp_image',
        25 => 'field_enrd_nrnp_video',
      ),
    ),
    'fields' => array(
      'title' => 'main',
      'field_enrd_nrnp_brief_intro' => 'main',
      'field_enrd_nrnp_highlights' => 'main',
      'field_enrd_nrnp_activities' => 'main',
      'field_enrd_nrnp_cooperation' => 'main',
      'field_enrd_nrnp_organisation' => 'main',
      'field_enrd_nrnp_address' => 'main',
      'group_enrd_nrnp_contacts_ds' => 'main',
      'field_enrd_nrnp_website' => 'links',
      'field_enrd_nrnp_objectives' => 'nsu_operation',
      'group_enrd_nrnp_links_ds' => 'links',
      'field_enrd_nrnp_internal_links' => 'links',
      'field_enrd_nrnp_phone' => 'main',
      'field_enrd_nrnp_external_links' => 'links',
      'group_enrd_nrnp_nsu_operation_ds' => 'nsu_operation',
      'field_enrd_nrnp_email' => 'main',
      'field_enrd_nrnp_membership' => 'nsu_operation',
      'field_enrd_nrnp_social_media' => 'links',
      'field_enrd_nrnp_contact_persons' => 'main',
      'field_enrd_nrnp_documents' => 'side_right',
      'field_enrd_nrnp_nsu_rdp' => 'nsu_operation',
      'field_enrd_nrnp_reg_repres' => 'nsu_operation',
      'field_enrd_nrnp_logo' => 'side_right',
      'field_enrd_nrnp_image' => 'side_right',
      'field_enrd_nrnp_governance' => 'nsu_operation',
      'field_enrd_nrnp_video' => 'side_right',
      'field_enrd_nrnp_finan_resources' => 'nsu_operation',
    ),
    'classes' => array(),
    'wrappers' => array(
      'main' => 'div',
      'links' => 'div',
      'nsu_operation' => 'div',
      'side_right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|nrn_profile|print'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function enrd_nrn_profiles_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'landing_page_teaser';
  $ds_view_mode->label = 'Landing Page Teaser';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['landing_page_teaser'] = $ds_view_mode;

  return $export;
}
