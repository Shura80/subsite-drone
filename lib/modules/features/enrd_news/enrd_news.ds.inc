<?php

/**
 * @file
 * enrd_news.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function enrd_news_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|enrd_nrn_toolkit_resource';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
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
    'field_enrd_nrn_title' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|event|enrd_nrn_toolkit_resource'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|eventlist';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'eventlist';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => 'media-heading',
      ),
    ),
  );
  $export['node|event|eventlist'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'comments' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|event|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|news|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'news';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'links' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|news|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|news|newsroom';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'news';
  $ds_fieldsetting->view_mode = 'newsroom';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => 'media-heading',
      ),
    ),
  );
  $export['node|news|newsroom'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function enrd_news_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|enrd_nrn_toolkit_resource';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'enrd_nrn_toolkit_resource';
  $ds_layout->layout = 'nrn_page';
  $ds_layout->settings = array(
    'regions' => array(
      'nrn_title' => array(
        0 => 'field_enrd_nrn_title',
      ),
      'headline' => array(
        1 => 'title',
      ),
      'nrn_description' => array(
        2 => 'field_enrd_nrn_alter_description',
      ),
      'abstract' => array(
        3 => 'body',
      ),
      'meta' => array(
        4 => 'group_nrn_toolkit_fieldset',
        5 => 'field_enrd_nrn_type',
        6 => 'field_enrd_nrn_date',
      ),
    ),
    'fields' => array(
      'field_enrd_nrn_title' => 'nrn_title',
      'title' => 'headline',
      'field_enrd_nrn_alter_description' => 'nrn_description',
      'body' => 'abstract',
      'group_nrn_toolkit_fieldset' => 'meta',
      'field_enrd_nrn_type' => 'meta',
      'field_enrd_nrn_date' => 'meta',
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
  $export['node|event|enrd_nrn_toolkit_resource'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|eventlist';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'eventlist';
  $ds_layout->layout = 'event_page';
  $ds_layout->settings = array(
    'regions' => array(
      'thumb' => array(
        0 => 'field_picture_upload',
      ),
      'headline' => array(
        1 => 'title',
      ),
      'meta' => array(
        2 => 'field_event_date',
        3 => 'group_event_fieldset_eventlist',
        4 => 'field_event_location',
        5 => 'field_event_type',
        6 => 'field_tax_origin',
      ),
      'abstract' => array(
        7 => 'body',
      ),
    ),
    'fields' => array(
      'field_picture_upload' => 'thumb',
      'title' => 'headline',
      'field_event_date' => 'meta',
      'group_event_fieldset_eventlist' => 'meta',
      'field_event_location' => 'meta',
      'field_event_type' => 'meta',
      'field_tax_origin' => 'meta',
      'body' => 'abstract',
    ),
    'limit' => array(
      'field_picture_upload' => '1',
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
  );
  $export['node|event|eventlist'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'event_page';
  $ds_layout->settings = array(
    'regions' => array(
      'thumb' => array(
        0 => 'field_picture_upload',
      ),
      'meta' => array(
        1 => 'field_event_date',
        4 => 'field_event_location',
        7 => 'field_event_type',
        8 => 'field_tax_origin',
        10 => 'group_event_fieldset_eventlist',
      ),
      'abstract' => array(
        2 => 'body',
        3 => 'field_core_attachments',
        5 => 'field_location',
        6 => 'field_registration',
        9 => 'comments',
      ),
    ),
    'fields' => array(
      'field_picture_upload' => 'thumb',
      'field_event_date' => 'meta',
      'body' => 'abstract',
      'field_core_attachments' => 'abstract',
      'field_event_location' => 'meta',
      'field_location' => 'abstract',
      'field_registration' => 'abstract',
      'field_event_type' => 'meta',
      'field_tax_origin' => 'meta',
      'comments' => 'abstract',
      'group_event_fieldset_eventlist' => 'meta',
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
  );
  $export['node|event|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|news|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'news';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'news_page';
  $ds_layout->settings = array(
    'regions' => array(
      'thumb' => array(
        0 => 'field_news_image',
      ),
      'abstract' => array(
        1 => 'body',
      ),
      'meta' => array(
        2 => 'group_news_fieldset_newsroom',
        3 => 'field_tax_origin',
        4 => 'field_news_publication_date',
      ),
    ),
    'fields' => array(
      'field_news_image' => 'thumb',
      'body' => 'abstract',
      'group_news_fieldset_newsroom' => 'meta',
      'field_tax_origin' => 'meta',
      'field_news_publication_date' => 'meta',
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
  );
  $export['node|news|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|news|newsroom';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'news';
  $ds_layout->view_mode = 'newsroom';
  $ds_layout->layout = 'news_page';
  $ds_layout->settings = array(
    'regions' => array(
      'thumb' => array(
        0 => 'field_news_image',
      ),
      'headline' => array(
        1 => 'title',
      ),
      'meta' => array(
        2 => 'field_tax_origin',
        3 => 'group_news_fieldset_newsroom',
        4 => 'field_news_publication_date',
      ),
      'abstract' => array(
        5 => 'body',
      ),
    ),
    'fields' => array(
      'field_news_image' => 'thumb',
      'title' => 'headline',
      'field_tax_origin' => 'meta',
      'group_news_fieldset_newsroom' => 'meta',
      'field_news_publication_date' => 'meta',
      'body' => 'abstract',
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
  );
  $export['node|news|newsroom'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function enrd_news_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'eventlist';
  $ds_view_mode->label = 'Event list';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['eventlist'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'newsroom';
  $ds_view_mode->label = 'Newsroom';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['newsroom'] = $ds_view_mode;

  return $export;
}
