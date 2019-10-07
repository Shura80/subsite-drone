<?php

/**
 * @file
 * agri_digitization_toolbox.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function agri_digitization_toolbox_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|digitisation_toolbox|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'digitisation_toolbox';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'comments' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|digitisation_toolbox|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function agri_digitization_toolbox_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|digitisation_toolbox|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'digitisation_toolbox';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'comments',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'comments' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
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
  $export['node|digitisation_toolbox|full'] = $ds_layout;

  return $export;
}
