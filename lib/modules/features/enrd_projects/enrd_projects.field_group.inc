<?php

/**
 * @file
 * enrd_projects.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function enrd_projects_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_classification|node|project|form';
  $field_group->group_name = 'group_enrd_classification';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Classification',
    'weight' => '3',
    'children' => array(
      0 => 'field_tax_evaluation',
      1 => 'field_tax_languages',
      2 => 'field_tax_transversal_topics',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group_enrd_classification field-group-tab',
        'required_fields' => FALSE,
      ),
    ),
  );
  $field_groups['group_enrd_classification|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_project|node|project|form';
  $field_group->group_name = 'group_enrd_project';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'ENRD Project',
    'weight' => '0',
    'children' => array(
      0 => 'field_enrd_prj_contact_email',
      1 => 'field_enrd_prj_contact_person',
      2 => 'field_enrd_prj_contact_phone_num',
      3 => 'field_enrd_prj_focus_area',
      4 => 'field_enrd_prj_full_proj_summary',
      5 => 'field_enrd_prj_funding',
      6 => 'field_enrd_prj_headline',
      7 => 'field_enrd_prj_keywords',
      8 => 'field_enrd_prj_measure',
      9 => 'field_enrd_prj_pdf',
      10 => 'field_enrd_prj_program_period',
      11 => 'field_enrd_prj_promoter',
      12 => 'field_enrd_prj_results',
      13 => 'field_enrd_prj_thumbnail',
      14 => 'field_enrd_prj_timeframe',
      15 => 'field_enrd_prj_website',
      16 => 'field_tax_country',
      17 => 'field_tax_rural_dev_policy',
      18 => 'title_field',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-enrd-project field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_enrd_project|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_eu_budg_specific|node|project|form';
  $field_group->group_name = 'group_eu_budg_specific';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'EU BUDG specific',
    'weight' => '1',
    'children' => array(
      0 => 'field_enrd_prj_acronym',
      1 => 'field_enrd_prj_benef_loc_addr',
      2 => 'field_enrd_prj_benef_region_nuts',
      3 => 'field_enrd_prj_ec_priorities',
      4 => 'field_enrd_prj_eu_budg_mff_head',
      5 => 'field_enrd_prj_eu_budget_contrib',
      6 => 'field_enrd_prj_export',
      7 => 'field_enrd_prj_funding_area',
      8 => 'field_enrd_prj_gps_coord_benef',
      9 => 'field_enrd_prj_lat_long',
      10 => 'field_enrd_prj_partners',
      11 => 'field_enrd_prj_programme_name',
      12 => 'field_enrd_prj_related_link',
      13 => 'field_enrd_prj_total_budget',
      14 => 'nuts_region',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-eu-budg-specific field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_eu_budg_specific|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata|node|project|form';
  $field_group->group_name = 'group_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '6',
    'children' => array(
      0 => 'path',
      1 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-metadata field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_metadata|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nrn_toolkit_fieldset|node|project|enrd_nrn_toolkit_resource';
  $field_group->group_name = 'group_nrn_toolkit_fieldset';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'enrd_nrn_toolkit_resource';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '55',
    'children' => array(
      0 => 'field_enrd_nrn_date',
      1 => 'field_enrd_nrn_type',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-nrn-toolkit-fieldset content-highlight clearfix',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_nrn_toolkit_fieldset|node|project|enrd_nrn_toolkit_resource'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nrn_toolkit|node|project|form';
  $field_group->group_name = 'group_nrn_toolkit';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'NRN Toolkit',
    'weight' => '5',
    'children' => array(
      0 => 'field_enrd_nrn_date',
      1 => 'field_enrd_nrn_include_toolkit',
      2 => 'field_enrd_nrn_type',
      3 => 'field_tax_networking',
      4 => 'field_enrd_nrn_title',
      5 => 'field_enrd_nrn_alter_description',
      6 => 'field_enrd_nrn_description',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group_nrn_toolkit field-group-tab',
        'required_fields' => FALSE,
      ),
    ),
  );
  $field_groups['group_nrn_toolkit|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prj_contact|node|project|default';
  $field_group->group_name = 'group_prj_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact:',
    'weight' => '14',
    'children' => array(
      0 => 'field_enrd_prj_contact_email',
      1 => 'field_enrd_prj_contact_person',
      2 => 'field_enrd_prj_contact_phone_num',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact:',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-prj-contact field-group-div field-label',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_prj_contact|node|project|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_location|node|project|form';
  $field_group->group_name = 'group_project_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Project Location',
    'weight' => '2',
    'children' => array(
      0 => 'field_enrd_prj_location',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-project-location field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_project_location|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_technical_taxonomy|node|project|form';
  $field_group->group_name = 'group_technical_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Technical taxonomy',
    'weight' => '4',
    'children' => array(
      0 => 'field_tax_origin',
      1 => 'field_tax_translation_status',
      2 => 'field_tax_update_status',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group_technical_taxonomy field-group-tab',
        'required_fields' => FALSE,
      ),
    ),
  );
  $field_groups['group_technical_taxonomy|node|project|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Classification');
  t('Contact:');
  t('ENRD Project');
  t('EU BUDG specific');
  t('Metadata');
  t('NRN Toolkit');
  t('Project Location');
  t('Technical taxonomy');

  return $field_groups;
}
