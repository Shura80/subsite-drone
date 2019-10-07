<?php

/**
 * @file
 * agri_pages.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function agri_pages_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_agri_stakeholders|node|page|form';
  $field_group->group_name = 'group_agri_stakeholders';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Stakeholders',
    'weight' => '1',
    'children' => array(
      0 => 'field_stakeholders_short_title',
      1 => 'field_stakeholders_short_weight',
      2 => 'field_core_stakeholders',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-agri-stakeholders field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_agri_stakeholders|node|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_community|node|page|form';
  $field_group->group_name = 'group_page_community';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Community',
    'weight' => '4',
    'children' => array(
      0 => 'og_group_ref',
      1 => 'group_content_access',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-page-community field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_page_community|node|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_content|node|page|form';
  $field_group->group_name = 'group_page_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_core_attachments',
      2 => 'field_core_keywords',
      3 => 'field_page_related',
      4 => 'field_core_geographical_area',
      5 => 'field_agri_pages_is_focus_group',
      6 => 'title',
      7 => 'group_images',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-page-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_page_content|node|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_metadata|node|page|form';
  $field_group->group_name = 'group_page_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '3',
    'children' => array(
      0 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-page-metadata field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_page_metadata|node|page|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Community');
  t('Content');
  t('Metadata');
  t('Stakeholders');

  return $field_groups;
}
