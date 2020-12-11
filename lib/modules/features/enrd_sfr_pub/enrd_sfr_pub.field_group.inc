<?php

/**
 * @file
 * enrd_sfr_pub.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function enrd_sfr_pub_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_cp_choice|enrd_sfr|enrd_sfr_pub_subscribe_cp|form';
  $field_group->group_name = 'group_contact_cp_choice';
  $field_group->entity_type = 'enrd_sfr';
  $field_group->bundle = 'enrd_sfr_pub_subscribe_cp';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Your choice of publications',
    'weight' => '1',
    'children' => array(
      0 => 'field_enrd_sfr_pub_subcp_type',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Your choice of publications',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => 'public-choices',
        'classes' => 'group-public-choices',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_contact_cp_choice|enrd_sfr|enrd_sfr_pub_subscribe_cp|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_cp_contact_details|enrd_sfr|enrd_sfr_pub_subscribe_cp|form';
  $field_group->group_name = 'group_contact_cp_contact_details';
  $field_group->entity_type = 'enrd_sfr';
  $field_group->bundle = 'enrd_sfr_pub_subscribe_cp';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact details',
    'weight' => '0',
    'children' => array(
      0 => 'field_enrd_sfr_pub_subcp_email',
      1 => 'field_enrd_sfr_pub_subcp_name',
      2 => 'field_enrd_sfr_pub_subcp_org',
      3 => 'field_enrd_sfr_pub_subcp_surname',
      4 => 'field_enrd_sfr_pub_subcp_petitle',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact details',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => 'contact-details',
        'classes' => 'group-contact-details',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_contact_cp_contact_details|enrd_sfr|enrd_sfr_pub_subscribe_cp|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_cp_delivery_addr|enrd_sfr|enrd_sfr_pub_subscribe_cp|form';
  $field_group->group_name = 'group_contact_cp_delivery_addr';
  $field_group->entity_type = 'enrd_sfr';
  $field_group->bundle = 'enrd_sfr_pub_subscribe_cp';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Delivery address',
    'weight' => '2',
    'children' => array(
      0 => 'field_enrd_sfr_pub_subcp_addr',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Delivery address',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => 'delivery-address',
        'classes' => 'group-delivery-address',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_contact_cp_delivery_addr|enrd_sfr|enrd_sfr_pub_subscribe_cp|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contact details');
  t('Delivery address');
  t('Your choice of publications');

  return $field_groups;
}
