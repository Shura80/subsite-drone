<?php

/**
 * @file
 * enrd_ruralstory.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function enrd_ruralstory_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'enrd_sfr|enrd_ruralstory|enrd_sfr_full_email';
  $ds_fieldsetting->entity_type = 'enrd_sfr';
  $ds_fieldsetting->bundle = 'enrd_ruralstory';
  $ds_fieldsetting->view_mode = 'enrd_sfr_full_email';
  $ds_fieldsetting->settings = array(
    'field_enrd_ruralstory_topic' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['enrd_sfr|enrd_ruralstory|enrd_sfr_full_email'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'enrd_sfr|enrd_ruralstory|full';
  $ds_fieldsetting->entity_type = 'enrd_sfr';
  $ds_fieldsetting->bundle = 'enrd_ruralstory';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'field_enrd_ruralstory_files' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Photos/files',
        ),
      ),
    ),
    'field_enrd_ruralstory_short_desc' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Short description of the story',
        ),
      ),
    ),
  );
  $export['enrd_sfr|enrd_ruralstory|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function enrd_ruralstory_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'enrd_sfr|enrd_ruralstory|enrd_sfr_full_email';
  $ds_layout->entity_type = 'enrd_sfr';
  $ds_layout->bundle = 'enrd_ruralstory';
  $ds_layout->view_mode = 'enrd_sfr_full_email';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_enrd_ruralstory_subject',
        1 => 'field_enrd_ruralstory_topic',
        2 => 'field_enrd_ruralstory_country',
        3 => 'field_enrd_ruralstory_region',
        4 => 'field_enrd_ruralstory_org',
        5 => 'field_enrd_ruralstory_title',
        6 => 'field_enrd_ruralstory_name',
        7 => 'field_enrd_ruralstory_surname',
        8 => 'field_enrd_ruralstory_email',
        9 => 'field_enrd_ruralstory_tel',
        10 => 'field_enrd_ruralstory_short_desc',
        11 => 'field_enrd_ruralstory_links',
        12 => 'field_enrd_ruralstory_files',
      ),
    ),
    'fields' => array(
      'field_enrd_ruralstory_subject' => 'ds_content',
      'field_enrd_ruralstory_topic' => 'ds_content',
      'field_enrd_ruralstory_country' => 'ds_content',
      'field_enrd_ruralstory_region' => 'ds_content',
      'field_enrd_ruralstory_org' => 'ds_content',
      'field_enrd_ruralstory_title' => 'ds_content',
      'field_enrd_ruralstory_name' => 'ds_content',
      'field_enrd_ruralstory_surname' => 'ds_content',
      'field_enrd_ruralstory_email' => 'ds_content',
      'field_enrd_ruralstory_tel' => 'ds_content',
      'field_enrd_ruralstory_short_desc' => 'ds_content',
      'field_enrd_ruralstory_links' => 'ds_content',
      'field_enrd_ruralstory_files' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['enrd_sfr|enrd_ruralstory|enrd_sfr_full_email'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'enrd_sfr|enrd_ruralstory|full';
  $ds_layout->entity_type = 'enrd_sfr';
  $ds_layout->bundle = 'enrd_ruralstory';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'bootstrap_8_4';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'group_rural_story',
        1 => 'field_enrd_ruralstory_subject',
        4 => 'field_enrd_ruralstory_topic',
        7 => 'field_enrd_ruralstory_short_desc',
        11 => 'field_enrd_ruralstory_links',
        14 => 'field_enrd_ruralstory_files',
        16 => 'field_enrd_ruralstory_back_to_report',
      ),
      'right' => array(
        2 => 'group_enrd_ruralstory_flags',
        3 => 'flag_enrd_ruralstory_status',
        5 => 'field_enrd_ruralstory_country',
        6 => 'field_enrd_ruralstory_region',
        8 => 'group_personal_info',
        9 => 'field_enrd_ruralstory_title',
        10 => 'field_enrd_ruralstory_name',
        12 => 'group_geo_info',
        13 => 'field_enrd_ruralstory_surname',
        15 => 'field_enrd_ruralstory_email',
        17 => 'field_enrd_ruralstory_tel',
        18 => 'field_enrd_ruralstory_org',
      ),
    ),
    'fields' => array(
      'group_rural_story' => 'left',
      'field_enrd_ruralstory_subject' => 'left',
      'group_enrd_ruralstory_flags' => 'right',
      'flag_enrd_ruralstory_status' => 'right',
      'field_enrd_ruralstory_topic' => 'left',
      'field_enrd_ruralstory_country' => 'right',
      'field_enrd_ruralstory_region' => 'right',
      'field_enrd_ruralstory_short_desc' => 'left',
      'group_personal_info' => 'right',
      'field_enrd_ruralstory_title' => 'right',
      'field_enrd_ruralstory_name' => 'right',
      'field_enrd_ruralstory_links' => 'left',
      'group_geo_info' => 'right',
      'field_enrd_ruralstory_surname' => 'right',
      'field_enrd_ruralstory_files' => 'left',
      'field_enrd_ruralstory_email' => 'right',
      'field_enrd_ruralstory_back_to_report' => 'left',
      'field_enrd_ruralstory_tel' => 'right',
      'field_enrd_ruralstory_org' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['enrd_sfr|enrd_ruralstory|full'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function enrd_ruralstory_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'enrd_sfr_full_email';
  $ds_view_mode->label = 'Full e-mail';
  $ds_view_mode->entities = array(
    'enrd_sfr' => 'enrd_sfr',
  );
  $export['enrd_sfr_full_email'] = $ds_view_mode;

  return $export;
}
