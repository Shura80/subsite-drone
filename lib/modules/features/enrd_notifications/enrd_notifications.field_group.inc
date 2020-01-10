<?php

/**
 * @file
 * enrd_notifications.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function enrd_notifications_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_notifications|user|user|form';
  $field_group->group_name = 'group_enrd_notifications';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Notifications',
    'weight' => '9',
    'children' => array(
      0 => 'message_subscribe_email_freq',
      1 => 'field_enrd_notifications_remind',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-enrd-notifications field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_enrd_notifications|user|user|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Notifications');

  return $field_groups;
}
