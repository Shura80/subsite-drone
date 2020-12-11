<?php

/**
 * @file
 * enrd_nrn_toolkit.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function enrd_nrn_toolkit_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_classification|node|nrn_resource|form';
  $field_group->group_name = 'group_enrd_classification';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'nrn_resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Classification',
    'weight' => '2',
    'children' => array(
      0 => 'field_tax_country',
      1 => 'field_tax_evaluation',
      2 => 'field_tax_languages',
      3 => 'field_tax_rural_dev_policy',
      4 => 'field_tax_transversal_topics',
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
  $field_groups['group_enrd_classification|node|nrn_resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nrn_metadata|node|nrn_resource|form';
  $field_group->group_name = 'group_nrn_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'nrn_resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '4',
    'children' => array(
      0 => 'path',
      1 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-nrn-metadata field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_nrn_metadata|node|nrn_resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nrn_resource_content|node|nrn_resource|form';
  $field_group->group_name = 'group_nrn_resource_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'nrn_resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'field_enrd_nrn_description',
      1 => 'field_enrd_nrn_external_link',
      2 => 'field_enrd_nrn_file',
      3 => 'field_enrd_nrn_resource_type',
      4 => 'title_field',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-nrn-resource-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_nrn_resource_content|node|nrn_resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nrn_toolkit_fieldset|node|nrn_resource|default';
  $field_group->group_name = 'group_nrn_toolkit_fieldset';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'nrn_resource';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '28',
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
  $field_groups['group_nrn_toolkit_fieldset|node|nrn_resource|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nrn_toolkit_fieldset|node|nrn_resource|enrd_nrn_toolkit_resource';
  $field_group->group_name = 'group_nrn_toolkit_fieldset';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'nrn_resource';
  $field_group->mode = 'enrd_nrn_toolkit_resource';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '20',
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
  $field_groups['group_nrn_toolkit_fieldset|node|nrn_resource|enrd_nrn_toolkit_resource'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nrn_toolkit_fieldset|node|page|enrd_nrn_toolkit_resource';
  $field_group->group_name = 'group_nrn_toolkit_fieldset';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'enrd_nrn_toolkit_resource';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '2',
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
  $field_groups['group_nrn_toolkit_fieldset|node|page|enrd_nrn_toolkit_resource'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nrn_toolkit|node|nrn_resource|form';
  $field_group->group_name = 'group_nrn_toolkit';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'nrn_resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'NRN Toolkit',
    'weight' => '3',
    'children' => array(
      0 => 'field_enrd_nrn_date',
      1 => 'field_enrd_nrn_include_toolkit',
      2 => 'field_enrd_nrn_type',
      3 => 'field_tax_networking',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-nrn-toolkit field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_nrn_toolkit|node|nrn_resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nrn_toolkit|node|page|form';
  $field_group->group_name = 'group_nrn_toolkit';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
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
  $field_groups['group_nrn_toolkit|node|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_technical_taxonomy|node|nrn_resource|form';
  $field_group->group_name = 'group_technical_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'nrn_resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Technical taxonomy',
    'weight' => '1',
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
  $field_groups['group_technical_taxonomy|node|nrn_resource|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Classification');
  t('Content');
  t('Metadata');
  t('NRN Toolkit');
  t('Technical taxonomy');

  return $field_groups;
}
