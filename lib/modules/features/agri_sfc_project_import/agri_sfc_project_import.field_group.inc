<?php

/**
 * @file
 * agri_sfc_project_import.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function agri_sfc_project_import_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_agri_projects_sfc|node|project|form';
  $field_group->group_name = 'group_agri_projects_sfc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'SFC Fields',
    'weight' => '36',
    'children' => array(
      0 => 'field_proj_is_sfc',
      1 => 'field_proj_nuts_region_other_1',
      2 => 'field_proj_nuts_region_other_2',
      3 => 'field_proj_rdp',
      4 => 'field_proj_sfc_attachments',
      5 => 'field_project_puid',
      6 => 'nuts_region',
      7 => 'field_proj_desc_context',
      8 => 'field_proj_editor_of_text',
      9 => 'field_proj_sfc_modification_date',
      10 => 'field_proj_sfc_identification',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_agri_projects_sfc|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_agri_projects_sfc|node|project|full';
  $field_group->group_name = 'group_agri_projects_sfc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Practice summary',
    'weight' => '30',
    'children' => array(
      0 => 'field_sfc_proj_summary',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Practice summary',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-proj-summary field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_agri_projects_sfc|node|project|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_agri_projects_sfc|node|project|print';
  $field_group->group_name = 'group_agri_projects_sfc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'print';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Short summary for practitioners',
    'weight' => '28',
    'children' => array(
      0 => 'field_sfc_proj_summary',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Short summary for practitioners',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_agri_projects_sfc|node|project|print'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Practice summary');
  t('SFC Fields');
  t('Short summary for practitioners');

  return $field_groups;
}
