<?php

/**
 * @file
 * agri_press.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function agri_press_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_press_clipping_content|node|press_clipping|form';
  $field_group->group_name = 'group_press_clipping_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_clipping';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_core_keywords',
      2 => 'field_press_clipping_documents',
      3 => 'field_press_clipping_links',
      4 => 'field_press_clipping_related',
      5 => 'field_press_clipping_source',
      6 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-press-clipping-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_press_clipping_content|node|press_clipping|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_press_clipping_dates|node|press_clipping|form';
  $field_group->group_name = 'group_press_clipping_dates';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_clipping';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Dates',
    'weight' => '1',
    'children' => array(
      0 => 'field_core_publication_date',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-press-clipping-dates field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_press_clipping_dates|node|press_clipping|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_press_clipping_metadata|node|press_clipping|form';
  $field_group->group_name = 'group_press_clipping_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_clipping';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '2',
    'children' => array(
      0 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-press-clipping-metadata field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_press_clipping_metadata|node|press_clipping|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_press_release_content|node|press_release|form';
  $field_group->group_name = 'group_press_release_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_release';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_core_keywords',
      2 => 'field_press_release_documents',
      3 => 'field_press_release_links',
      4 => 'field_press_release_related',
      5 => 'field_core_geographical_area',
      6 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-press-release-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_press_release_content|node|press_release|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_press_release_dates|node|press_release|form';
  $field_group->group_name = 'group_press_release_dates';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_release';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Dates',
    'weight' => '1',
    'children' => array(
      0 => 'field_core_publication_date',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-press-release-dates field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_press_release_dates|node|press_release|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_press_release_metadata|node|press_release|form';
  $field_group->group_name = 'group_press_release_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_release';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '2',
    'children' => array(
      0 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-press-release-metadata field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_press_release_metadata|node|press_release|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Content');
  t('Dates');
  t('Metadata');

  return $field_groups;
}
