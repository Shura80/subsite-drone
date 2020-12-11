<?php

/**
 * @file
 * enrd_gallery.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function enrd_gallery_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|gallery|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'gallery';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_enrd_gallery_media' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|gallery|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|gallery|enrd_nrn_toolkit_resource';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'gallery';
  $ds_fieldsetting->view_mode = 'enrd_nrn_toolkit_resource';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => 'media-heading',
        'ft' => array(),
      ),
    ),
    'field_enrd_nrn_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Type',
        ),
      ),
    ),
  );
  $export['node|gallery|enrd_nrn_toolkit_resource'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function enrd_gallery_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|gallery|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'gallery';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'gallery_page';
  $ds_layout->settings = array(
    'regions' => array(
      'headline' => array(
        0 => 'body',
      ),
      'main' => array(
        1 => 'field_enrd_gallery_media',
      ),
    ),
    'fields' => array(
      'body' => 'headline',
      'field_enrd_gallery_media' => 'main',
    ),
    'classes' => array(),
    'wrappers' => array(
      'headline' => 'div',
      'main' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|gallery|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|gallery|enrd_nrn_toolkit_resource';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'gallery';
  $ds_layout->view_mode = 'enrd_nrn_toolkit_resource';
  $ds_layout->layout = 'nrn_page';
  $ds_layout->settings = array(
    'regions' => array(
      'headline' => array(
        0 => 'title',
      ),
      'abstract' => array(
        1 => 'body',
      ),
      'meta' => array(
        2 => 'group_nrn_toolkit_fieldset',
        3 => 'field_enrd_nrn_type',
        4 => 'field_enrd_nrn_date',
      ),
      'nrn_title' => array(
        5 => 'field_enrd_nrn_title',
      ),
      'nrn_description' => array(
        6 => 'field_enrd_nrn_alter_description',
      ),
    ),
    'fields' => array(
      'title' => 'headline',
      'body' => 'abstract',
      'group_nrn_toolkit_fieldset' => 'meta',
      'field_enrd_nrn_type' => 'meta',
      'field_enrd_nrn_date' => 'meta',
      'field_enrd_nrn_title' => 'nrn_title',
      'field_enrd_nrn_alter_description' => 'nrn_description',
    ),
    'classes' => array(),
    'wrappers' => array(
      'thumb' => 'div',
      'headline' => 'div',
      'abstract' => 'div',
      'meta' => 'div',
      'nrn_title' => 'div',
      'nrn_description' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|gallery|enrd_nrn_toolkit_resource'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function enrd_gallery_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'embedded_media_gallery';
  $ds_view_mode->label = 'Embedded Media Gallery';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['embedded_media_gallery'] = $ds_view_mode;

  return $export;
}
