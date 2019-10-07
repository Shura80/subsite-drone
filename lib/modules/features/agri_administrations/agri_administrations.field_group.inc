<?php

/**
 * @file
 * agri_administrations.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function agri_administrations_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_administration_community|node|administration|form';
  $field_group->group_name = 'group_administration_community';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'administration';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Community',
    'weight' => '1',
    'children' => array(
      0 => 'group_access',
      1 => 'group_group',
      2 => 'og_menu',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-administration-community field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_administration_community|node|administration|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_administration_content|node|administration|form';
  $field_group->group_name = 'group_administration_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'administration';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-administration-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_administration_content|node|administration|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Community');
  t('Content');

  return $field_groups;
}
