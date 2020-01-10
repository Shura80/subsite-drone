<?php

/**
 * @file
 * enrd_nrn_toolkit.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function enrd_nrn_toolkit_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|nrn_resource|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'nrn_resource';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => 'media-heading',
        'ft' => array(),
      ),
    ),
    'field_enrd_nrn_date' => array(
      'formatter_settings' => array(
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
  $export['node|nrn_resource|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|nrn_resource|enrd_nrn_toolkit_resource';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'nrn_resource';
  $ds_fieldsetting->view_mode = 'enrd_nrn_toolkit_resource';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
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
  $export['node|nrn_resource|enrd_nrn_toolkit_resource'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|page|enrd_nrn_toolkit_resource';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'page';
  $ds_fieldsetting->view_mode = 'enrd_nrn_toolkit_resource';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
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
  $export['node|page|enrd_nrn_toolkit_resource'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function enrd_nrn_toolkit_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|nrn_resource|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'nrn_resource';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'nrn_page';
  $ds_layout->settings = array(
    'regions' => array(
      'headline' => array(
        0 => 'title',
        1 => 'field_enrd_nrn_file',
        2 => 'field_enrd_nrn_external_link',
      ),
      'abstract' => array(
        3 => 'field_enrd_nrn_description',
      ),
      'meta' => array(
        4 => 'field_enrd_nrn_type',
        5 => 'field_enrd_nrn_date',
        6 => 'group_nrn_toolkit_fieldset',
      ),
    ),
    'fields' => array(
      'title' => 'headline',
      'field_enrd_nrn_file' => 'headline',
      'field_enrd_nrn_external_link' => 'headline',
      'field_enrd_nrn_description' => 'abstract',
      'field_enrd_nrn_type' => 'meta',
      'field_enrd_nrn_date' => 'meta',
      'group_nrn_toolkit_fieldset' => 'meta',
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
  $export['node|nrn_resource|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|nrn_resource|enrd_nrn_toolkit_resource';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'nrn_resource';
  $ds_layout->view_mode = 'enrd_nrn_toolkit_resource';
  $ds_layout->layout = 'nrn_page';
  $ds_layout->settings = array(
    'regions' => array(
      'headline' => array(
        0 => 'title',
        2 => 'field_enrd_nrn_file',
        3 => 'field_enrd_nrn_external_link',
      ),
      'abstract' => array(
        1 => 'field_enrd_nrn_description',
      ),
      'meta' => array(
        4 => 'field_enrd_nrn_type',
        5 => 'field_enrd_nrn_date',
        6 => 'group_nrn_toolkit_fieldset',
      ),
    ),
    'fields' => array(
      'title' => 'headline',
      'field_enrd_nrn_description' => 'abstract',
      'field_enrd_nrn_file' => 'headline',
      'field_enrd_nrn_external_link' => 'headline',
      'field_enrd_nrn_type' => 'meta',
      'field_enrd_nrn_date' => 'meta',
      'group_nrn_toolkit_fieldset' => 'meta',
    ),
    'classes' => array(),
    'wrappers' => array(
      'thumb' => 'div',
      'headline' => 'div',
      'abstract' => 'div',
      'meta' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|nrn_resource|enrd_nrn_toolkit_resource'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|page|enrd_nrn_toolkit_resource';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'page';
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
        5 => 'field_enrd_nrn_date',
      ),
      'nrn_title' => array(
        4 => 'field_enrd_nrn_title',
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
      'field_enrd_nrn_title' => 'nrn_title',
      'field_enrd_nrn_date' => 'meta',
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
  $export['node|page|enrd_nrn_toolkit_resource'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function enrd_nrn_toolkit_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'enrd_nrn_toolkit_resource';
  $ds_view_mode->label = 'NRN Toolkit';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['enrd_nrn_toolkit_resource'] = $ds_view_mode;

  return $export;
}
