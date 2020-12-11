<?php

/**
 * @file
 * enrd_country_pages.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enrd_country_pages_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function enrd_country_pages_image_default_styles() {
  $styles = array();

  // Exported image style: enrd_country_page_images.
  $styles['enrd_country_page_images'] = array(
    'label' => 'Country page images',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 150,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function enrd_country_pages_node_info() {
  $items = array(
    'rdp_information' => array(
      'name' => t('Country Information'),
      'base' => 'node_content',
      'description' => t('Use <em>Country Information</em> to provide data about a country and, eventually, its related regions.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
