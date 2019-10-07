<?php

/**
 * @file
 * agri_events.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function agri_events_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_agri_stakeholders|node|event|form';
  $field_group->group_name = 'group_agri_stakeholders';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Stakeholders',
    'weight' => '1',
    'children' => array(
      0 => 'field_core_stakeholders',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-agri-stakeholders field-group-tab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_agri_stakeholders|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_community|node|event|form';
  $field_group->group_name = 'group_event_community';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
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
        'classes' => 'group-event-community field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_event_community|node|event|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Community');
  t('Stakeholders');

  return $field_groups;
}
