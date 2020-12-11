<?php

/**
 * @file
 * enrd_ruralstory.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function enrd_ruralstory_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_information|enrd_sfr|enrd_ruralstory|form';
  $field_group->group_name = 'group_contact_information';
  $field_group->entity_type = 'enrd_sfr';
  $field_group->bundle = 'enrd_ruralstory';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact information',
    'weight' => '8',
    'children' => array(
      0 => 'field_enrd_ruralstory_email',
      1 => 'field_enrd_ruralstory_tel',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact information',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => 'ruralstory-contact-info',
        'classes' => 'group-ruralstory-contact-info field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_contact_information|enrd_sfr|enrd_ruralstory|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_information|enrd_sfr|enrd_ruralstory|full';
  $field_group->group_name = 'group_contact_information';
  $field_group->entity_type = 'enrd_sfr';
  $field_group->bundle = 'enrd_ruralstory';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact information',
    'weight' => '7',
    'children' => array(
      0 => 'field_enrd_ruralstory_email',
      1 => 'field_enrd_ruralstory_tel',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact information',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-contact-information field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_contact_information|enrd_sfr|enrd_ruralstory|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_ruralstory_flags|enrd_sfr|enrd_ruralstory|full';
  $field_group->group_name = 'group_enrd_ruralstory_flags';
  $field_group->entity_type = 'enrd_sfr';
  $field_group->bundle = 'enrd_ruralstory';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Status',
    'weight' => '2',
    'children' => array(
      0 => 'flag_enrd_ruralstory_status',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Status',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-enrd-ruralstory-flags field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_enrd_ruralstory_flags|enrd_sfr|enrd_ruralstory|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_geo_info|enrd_sfr|enrd_ruralstory|full';
  $field_group->group_name = 'group_geo_info';
  $field_group->entity_type = 'enrd_sfr';
  $field_group->bundle = 'enrd_ruralstory';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Geographical information',
    'weight' => '4',
    'children' => array(
      0 => 'field_enrd_ruralstory_country',
      1 => 'field_enrd_ruralstory_region',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Geographical information',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-geo-info field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_geo_info|enrd_sfr|enrd_ruralstory|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_personal_info|enrd_sfr|enrd_ruralstory|full';
  $field_group->group_name = 'group_personal_info';
  $field_group->entity_type = 'enrd_sfr';
  $field_group->bundle = 'enrd_ruralstory';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Personal information',
    'weight' => '3',
    'children' => array(
      0 => 'field_enrd_ruralstory_email',
      1 => 'field_enrd_ruralstory_name',
      2 => 'field_enrd_ruralstory_org',
      3 => 'field_enrd_ruralstory_surname',
      4 => 'field_enrd_ruralstory_tel',
      5 => 'field_enrd_ruralstory_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Personal information',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-personal-info field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_personal_info|enrd_sfr|enrd_ruralstory|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rural_story|enrd_sfr|enrd_ruralstory|full';
  $field_group->group_name = 'group_rural_story';
  $field_group->entity_type = 'enrd_sfr';
  $field_group->bundle = 'enrd_ruralstory';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'About the Rural Story',
    'weight' => '0',
    'children' => array(
      0 => 'field_enrd_ruralstory_files',
      1 => 'field_enrd_ruralstory_links',
      2 => 'field_enrd_ruralstory_short_desc',
      3 => 'field_enrd_ruralstory_subject',
      4 => 'field_enrd_ruralstory_topic',
      5 => 'field_enrd_ruralstory_back_to_report',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'About the Rural Story',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-rural-story field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_rural_story|enrd_sfr|enrd_ruralstory|full'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('About the Rural Story');
  t('Contact information');
  t('Geographical information');
  t('Personal information');
  t('Status');

  return $field_groups;
}
