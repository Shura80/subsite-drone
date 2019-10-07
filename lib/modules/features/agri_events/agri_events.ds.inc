<?php

/**
 * @file
 * agri_events.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function agri_events_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|core_small_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'core_small_teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h4',
        'class' => '',
      ),
    ),
  );
  $export['node|event|core_small_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => '',
      ),
    ),
  );
  $export['node|event|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function agri_events_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|core_small_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'core_small_teaser';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_event_image',
      ),
      'right' => array(
        1 => 'title',
        2 => 'field_event_date',
      ),
    ),
    'fields' => array(
      'field_event_image' => 'left',
      'title' => 'right',
      'field_event_date' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        'row' => 'row',
      ),
      'left' => array(
        'col-lg-4' => 'col-lg-4',
        'col-md-4' => 'col-md-4',
        'col-sm-4' => 'col-sm-4',
      ),
      'right' => array(
        'col-lg-8' => 'col-lg-8',
        'col-md-8' => 'col-md-8',
        'col-sm-8' => 'col-sm-8',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|event|core_small_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_event_date',
        1 => 'field_event_type',
        2 => 'field_event_type_other',
        3 => 'field_core_geographical_area',
        4 => 'field_core_other_location',
      ),
      'footer' => array(
        5 => 'body',
        6 => 'field_event_pictures',
        7 => 'field_event_address',
        8 => 'field_event_related',
        9 => 'field_event_attachments',
        10 => 'webform',
        11 => 'flag_agri_digitization_toolbox',
      ),
    ),
    'fields' => array(
      'field_event_date' => 'header',
      'field_event_type' => 'header',
      'field_event_type_other' => 'header',
      'field_core_geographical_area' => 'header',
      'field_core_other_location' => 'header',
      'body' => 'footer',
      'field_event_pictures' => 'footer',
      'field_event_address' => 'footer',
      'field_event_related' => 'footer',
      'field_event_attachments' => 'footer',
      'webform' => 'footer',
      'flag_agri_digitization_toolbox' => 'footer',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|event|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_event_image',
      ),
      'right' => array(
        1 => 'title',
        2 => 'body',
        3 => 'field_event_type',
        4 => 'field_event_date',
        5 => 'field_core_geographical_area',
        6 => 'field_core_other_location',
      ),
    ),
    'fields' => array(
      'field_event_image' => 'left',
      'title' => 'right',
      'body' => 'right',
      'field_event_type' => 'right',
      'field_event_date' => 'right',
      'field_core_geographical_area' => 'right',
      'field_core_other_location' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        'row' => 'row',
      ),
      'left' => array(
        'col-lg-4' => 'col-lg-4',
        'col-md-4' => 'col-md-4',
        'col-sm-4' => 'col-sm-4',
      ),
      'right' => array(
        'col-lg-8' => 'col-lg-8',
        'col-md-8' => 'col-md-8',
        'col-sm-8' => 'col-sm-8',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|event|teaser'] = $ds_layout;

  return $export;
}
