<?php

/**
 * @file
 * agri_publications.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function agri_publications_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|publication|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'publication';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h4',
        'class' => '',
      ),
    ),
  );
  $export['node|publication|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function agri_publications_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|publication|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'publication';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'footer' => array(
        0 => 'field_publication_institution',
        1 => 'field_core_title_eng',
        2 => 'field_publication_abstract',
        3 => 'body',
        4 => 'field_publication_attachments',
        5 => 'flag_agri_digitization_toolbox',
      ),
    ),
    'fields' => array(
      'field_publication_institution' => 'footer',
      'field_core_title_eng' => 'footer',
      'field_publication_abstract' => 'footer',
      'body' => 'footer',
      'field_publication_attachments' => 'footer',
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
  $export['node|publication|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|publication|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'publication';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'title',
      ),
      'left' => array(
        1 => 'field_publication_abstract',
      ),
      'right' => array(
        2 => 'field_publication_date',
        3 => 'field_publication_type',
        4 => 'field_core_geographical_area',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'field_publication_abstract' => 'left',
      'field_publication_date' => 'right',
      'field_publication_type' => 'right',
      'field_core_geographical_area' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        'row' => 'row',
      ),
      'header' => array(
        'col-lg-12' => 'col-lg-12',
      ),
      'left' => array(
        'col-lg-8' => 'col-lg-8',
        'col-md-8' => 'col-md-8',
        'col-sm-8' => 'col-sm-8',
      ),
      'right' => array(
        'col-lg-4' => 'col-lg-4',
        'col-md-4' => 'col-md-4',
        'col-sm-4' => 'col-sm-4',
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
  );
  $export['node|publication|teaser'] = $ds_layout;

  return $export;
}
