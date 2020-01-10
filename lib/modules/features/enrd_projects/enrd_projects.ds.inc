<?php

/**
 * @file
 * enrd_projects.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function enrd_projects_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|project|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'project';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'post_date' => array(
      'weight' => '5',
      'label' => 'inline',
      'format' => 'ds_post_date_short',
    ),
  );
  $export['node|project|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|project|enrd_nrn_toolkit_resource';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'project';
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
    'field_enrd_nrn_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Type',
        ),
      ),
    ),
    'field_enrd_nrn_title' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|project|enrd_nrn_toolkit_resource'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|project|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'project';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'field_enrd_prj_keywords' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lbw' => 1,
          'lbw-el' => 'dt',
          'fi' => TRUE,
          'fi-el' => 'dd',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_tax_country' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Countries',
          'lbw' => 1,
          'lbw-el' => 'dt',
          'fi' => TRUE,
          'fi-el' => 'dd',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|project|search_result'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function enrd_projects_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|project|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'project';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'project_page';
  $ds_layout->settings = array(
    'regions' => array(
      'thumb' => array(
        0 => 'field_enrd_prj_thumbnail',
      ),
      'headline' => array(
        1 => 'field_enrd_prj_headline',
        2 => 'field_enrd_prj_pdf',
      ),
      'main' => array(
        3 => 'field_enrd_prj_full_proj_summary',
        4 => 'field_enrd_prj_results',
        5 => 'post_date',
      ),
    ),
    'fields' => array(
      'field_enrd_prj_thumbnail' => 'thumb',
      'field_enrd_prj_headline' => 'headline',
      'field_enrd_prj_pdf' => 'headline',
      'field_enrd_prj_full_proj_summary' => 'main',
      'field_enrd_prj_results' => 'main',
      'post_date' => 'main',
    ),
    'classes' => array(),
    'wrappers' => array(
      'thumb' => 'div',
      'headline' => 'div',
      'main' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|project|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|project|enrd_nrn_toolkit_resource';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'project';
  $ds_layout->view_mode = 'enrd_nrn_toolkit_resource';
  $ds_layout->layout = 'nrn_page';
  $ds_layout->settings = array(
    'regions' => array(
      'headline' => array(
        0 => 'title',
      ),
      'nrn_title' => array(
        1 => 'field_enrd_nrn_title',
      ),
      'nrn_description' => array(
        2 => 'field_enrd_nrn_alter_description',
      ),
      'abstract' => array(
        3 => 'field_enrd_prj_headline',
      ),
      'meta' => array(
        4 => 'field_enrd_nrn_type',
        5 => 'field_enrd_nrn_date',
        6 => 'group_nrn_toolkit_fieldset',
      ),
    ),
    'fields' => array(
      'title' => 'headline',
      'field_enrd_nrn_title' => 'nrn_title',
      'field_enrd_nrn_alter_description' => 'nrn_description',
      'field_enrd_prj_headline' => 'abstract',
      'field_enrd_nrn_type' => 'meta',
      'field_enrd_nrn_date' => 'meta',
      'group_nrn_toolkit_fieldset' => 'meta',
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
  $export['node|project|enrd_nrn_toolkit_resource'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|project|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'project';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'project_page';
  $ds_layout->settings = array(
    'regions' => array(
      'thumb' => array(
        0 => 'field_enrd_prj_thumbnail',
      ),
      'headline' => array(
        1 => 'field_enrd_prj_headline',
        2 => 'field_enrd_prj_pdf',
      ),
      'main' => array(
        3 => 'field_enrd_prj_full_proj_summary',
        4 => 'field_enrd_prj_results',
        5 => 'post_date',
      ),
      'project_details' => array(
        6 => 'field_tax_country',
        7 => 'field_enrd_prj_program_period',
        8 => 'field_tax_rural_dev_policy',
        9 => 'field_enrd_prj_focus_area',
        10 => 'field_enrd_prj_measure',
        11 => 'field_enrd_prj_funding',
        12 => 'field_enrd_prj_timeframe',
        13 => 'field_enrd_prj_promoter',
        14 => 'field_enrd_prj_contact_person',
        15 => 'group_prj_contact',
        16 => 'field_enrd_prj_website',
        17 => 'field_enrd_prj_contact_email',
        18 => 'field_enrd_prj_contact_phone_num',
        19 => 'field_enrd_prj_keywords',
      ),
    ),
    'fields' => array(
      'field_enrd_prj_thumbnail' => 'thumb',
      'field_enrd_prj_headline' => 'headline',
      'field_enrd_prj_pdf' => 'headline',
      'field_enrd_prj_full_proj_summary' => 'main',
      'field_enrd_prj_results' => 'main',
      'post_date' => 'main',
      'field_tax_country' => 'project_details',
      'field_enrd_prj_program_period' => 'project_details',
      'field_tax_rural_dev_policy' => 'project_details',
      'field_enrd_prj_focus_area' => 'project_details',
      'field_enrd_prj_measure' => 'project_details',
      'field_enrd_prj_funding' => 'project_details',
      'field_enrd_prj_timeframe' => 'project_details',
      'field_enrd_prj_promoter' => 'project_details',
      'field_enrd_prj_contact_person' => 'project_details',
      'group_prj_contact' => 'project_details',
      'field_enrd_prj_website' => 'project_details',
      'field_enrd_prj_contact_email' => 'project_details',
      'field_enrd_prj_contact_phone_num' => 'project_details',
      'field_enrd_prj_keywords' => 'project_details',
    ),
    'classes' => array(),
    'wrappers' => array(
      'thumb' => 'div',
      'headline' => 'div',
      'main' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|project|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|project|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'project';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'project_search';
  $ds_layout->settings = array(
    'regions' => array(
      'thumb' => array(
        0 => 'field_enrd_prj_thumbnail',
      ),
      'headline' => array(
        1 => 'title_field',
      ),
      'abstract' => array(
        2 => 'field_enrd_prj_headline',
      ),
      'meta' => array(
        3 => 'field_enrd_prj_keywords',
        4 => 'field_tax_country',
      ),
    ),
    'fields' => array(
      'field_enrd_prj_thumbnail' => 'thumb',
      'title_field' => 'headline',
      'field_enrd_prj_headline' => 'abstract',
      'field_enrd_prj_keywords' => 'meta',
      'field_tax_country' => 'meta',
    ),
    'classes' => array(),
    'wrappers' => array(
      'thumb' => 'div',
      'headline' => 'div',
      'abstract' => 'div',
      'meta' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|project|search_result'] = $ds_layout;

  return $export;
}
