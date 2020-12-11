<?php

/**
 * @file
 * enrd_sfr_pub.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function enrd_sfr_pub_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'field_collection_item|field_enrd_sfr_pub_subcp_type|type_of_publication_name';
  $ds_fieldsetting->entity_type = 'field_collection_item';
  $ds_fieldsetting->bundle = 'field_enrd_sfr_pub_subcp_type';
  $ds_fieldsetting->view_mode = 'type_of_publication_name';
  $ds_fieldsetting->settings = array(
    'field_enrd_sfr_pub_subcp_typepub' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['field_collection_item|field_enrd_sfr_pub_subcp_type|type_of_publication_name'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function enrd_sfr_pub_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_enrd_sfr_pub_subcp_type|type_of_publication_name';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_enrd_sfr_pub_subcp_type';
  $ds_layout->view_mode = 'type_of_publication_name';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_enrd_sfr_pub_subcp_typepub',
      ),
    ),
    'fields' => array(
      'field_enrd_sfr_pub_subcp_typepub' => 'ds_content',
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
  $export['field_collection_item|field_enrd_sfr_pub_subcp_type|type_of_publication_name'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function enrd_sfr_pub_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'type_of_publication_name';
  $ds_view_mode->label = 'Type of publication name';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['type_of_publication_name'] = $ds_view_mode;

  return $export;
}
