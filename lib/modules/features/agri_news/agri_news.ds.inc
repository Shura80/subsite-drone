<?php

/**
 * @file
 * agri_news.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function agri_news_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|funding_opportunities|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'funding_opportunities';
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
  $export['node|funding_opportunities|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|news|core_small_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'news';
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
  $export['node|news|core_small_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|news|core_spotlight';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'news';
  $ds_fieldsetting->view_mode = 'core_spotlight';
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
  $export['node|news|core_spotlight'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|news|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'news';
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
    'post_date' => array(
      'weight' => '3',
      'label' => 'inline',
      'format' => 'ds_post_date_medium',
    ),
  );
  $export['node|news|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function agri_news_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|funding_opportunities|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'funding_opportunities';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_core_publication_date',
        1 => 'field_news_target_group',
        2 => 'field_news_total_program_funding',
        3 => 'field_news_geographical_area',
        4 => 'field_news_other_location',
        5 => 'field_core_keywords',
      ),
      'footer' => array(
        6 => 'field_organization_collection',
        7 => 'field_news_programme_description',
        8 => 'body',
        9 => 'field_news_objectives',
        10 => 'field_core_additional_info',
        11 => 'field_news_maximum_support',
        12 => 'field_core_attachments',
      ),
    ),
    'fields' => array(
      'field_core_publication_date' => 'header',
      'field_news_target_group' => 'header',
      'field_news_total_program_funding' => 'header',
      'field_news_geographical_area' => 'header',
      'field_news_other_location' => 'header',
      'field_core_keywords' => 'header',
      'field_organization_collection' => 'footer',
      'field_news_programme_description' => 'footer',
      'body' => 'footer',
      'field_news_objectives' => 'footer',
      'field_core_additional_info' => 'footer',
      'field_news_maximum_support' => 'footer',
      'field_core_attachments' => 'footer',
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
  $export['node|funding_opportunities|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|funding_opportunities|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'funding_opportunities';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'title',
      ),
      'left' => array(
        1 => 'body',
      ),
      'right' => array(
        2 => 'field_core_publication_date',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'body' => 'left',
      'field_core_publication_date' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        'row' => 'row',
      ),
      'header' => array(
        'col-md-12' => 'col-md-12',
      ),
      'left' => array(
        'col-md-8' => 'col-md-8',
      ),
      'right' => array(
        'col-md-4' => 'col-md-4',
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
  $export['node|funding_opportunities|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|news|core_small_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'news';
  $ds_layout->view_mode = 'core_small_teaser';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_news_image',
      ),
      'right' => array(
        1 => 'title',
        2 => 'field_news_publication_date',
      ),
    ),
    'fields' => array(
      'field_news_image' => 'left',
      'title' => 'right',
      'field_news_publication_date' => 'right',
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
  $export['node|news|core_small_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|news|core_spotlight';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'news';
  $ds_layout->view_mode = 'core_spotlight';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_news_image',
      ),
      'right' => array(
        1 => 'title',
        2 => 'body',
      ),
    ),
    'fields' => array(
      'field_news_image' => 'left',
      'title' => 'right',
      'body' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        'row' => 'row',
      ),
      'left' => array(
        'col-md-8' => 'col-md-8',
      ),
      'right' => array(
        'col-md-4' => 'col-md-4',
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
  $export['node|news|core_spotlight'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|news|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'news';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'field_link',
        2 => 'field_top_news',
        3 => 'field_news_publication_date',
        4 => 'field_news_unpublication_date',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'field_link' => 'ds_content',
      'field_top_news' => 'ds_content',
      'field_news_publication_date' => 'ds_content',
      'field_news_unpublication_date' => 'ds_content',
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
  $export['node|news|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|news|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'news';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'footer' => array(
        0 => 'body',
        1 => 'field_news_publication_date',
        5 => 'field_news_links',
        6 => 'field_news_sources',
        7 => 'field_news_related',
        8 => 'field_core_attachments',
        9 => 'flag_agri_digitization_toolbox',
      ),
      'header' => array(
        2 => 'field_core_geographical_area',
        3 => 'field_core_other_location',
        4 => 'field_core_keywords',
      ),
    ),
    'fields' => array(
      'body' => 'footer',
      'field_news_publication_date' => 'footer',
      'field_core_geographical_area' => 'header',
      'field_core_other_location' => 'header',
      'field_core_keywords' => 'header',
      'field_news_links' => 'footer',
      'field_news_sources' => 'footer',
      'field_news_related' => 'footer',
      'field_core_attachments' => 'footer',
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
  $export['node|news|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|news|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'news';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_news_image',
      ),
      'right' => array(
        1 => 'title',
        2 => 'body',
        3 => 'field_news_publication_date',
      ),
    ),
    'fields' => array(
      'field_news_image' => 'left',
      'title' => 'right',
      'body' => 'right',
      'field_news_publication_date' => 'right',
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
  $export['node|news|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|online_resource|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'online_resource';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_core_keywords',
      ),
      'footer' => array(
        1 => 'field_core_link',
        2 => 'field_news_language',
        3 => 'body',
        4 => 'field_core_additional_info',
        5 => 'flag_agri_digitization_toolbox',
      ),
    ),
    'fields' => array(
      'field_core_keywords' => 'header',
      'field_core_link' => 'footer',
      'field_news_language' => 'footer',
      'body' => 'footer',
      'field_core_additional_info' => 'footer',
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
  $export['node|online_resource|full'] = $ds_layout;

  return $export;
}
