<?php

/**
 * @file
 * agri_press.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function agri_press_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|press_clipping|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'press_clipping';
  $ds_fieldsetting->view_mode = 'full';
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
  $export['node|press_clipping|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|press_clipping|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'press_clipping';
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
  $export['node|press_clipping|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|press_release|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'press_release';
  $ds_fieldsetting->view_mode = 'full';
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
  $export['node|press_release|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|press_release|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'press_release';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h4',
        'class' => '',
      ),
    ),
  );
  $export['node|press_release|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function agri_press_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|press_clipping|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'press_clipping';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_core_publication_date',
        2 => 'field_core_keywords',
      ),
      'footer' => array(
        3 => 'body',
        4 => 'field_press_clipping_source',
        5 => 'field_press_clipping_links',
        6 => 'field_press_clipping_related',
        7 => 'field_press_clipping_documents',
      ),
    ),
    'fields' => array(
      'field_core_publication_date' => 'header',
      'field_core_keywords' => 'header',
      'body' => 'footer',
      'field_press_clipping_source' => 'footer',
      'field_press_clipping_links' => 'footer',
      'field_press_clipping_related' => 'footer',
      'field_press_clipping_documents' => 'footer',
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
  );
  $export['node|press_clipping|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|press_clipping|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'press_clipping';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'title',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'title' => 'ds_content',
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
  );
  $export['node|press_clipping|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|press_release|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'press_release';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_core_publication_date',
        1 => 'field_core_keywords',
      ),
      'footer' => array(
        2 => 'body',
        3 => 'field_press_release_links',
        4 => 'field_press_release_related',
        5 => 'field_press_release_documents',
        6 => 'flag_agri_digitization_toolbox',
      ),
    ),
    'fields' => array(
      'field_core_publication_date' => 'header',
      'field_core_keywords' => 'header',
      'body' => 'footer',
      'field_press_release_links' => 'footer',
      'field_press_release_related' => 'footer',
      'field_press_release_documents' => 'footer',
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
  $export['node|press_release|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|press_release|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'press_release';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'body',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'body' => 'ds_content',
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
  );
  $export['node|press_release|teaser'] = $ds_layout;

  return $export;
}
