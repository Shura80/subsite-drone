<?php

/**
 * @file
 * enrd_lag_database.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enrd_lag_database_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "apachesolr_search" && $api == "apachesolr_search_defaults") {
    return array("version" => "3");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "current_search" && $api == "current_search") {
    return array("version" => "1");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function enrd_lag_database_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function enrd_lag_database_image_default_styles() {
  $styles = array();

  // Exported image style: enrd_lag_logo.
  $styles['enrd_lag_logo'] = array(
    'label' => 'LAG logo',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'height' => 200,
          'width' => 250,
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
function enrd_lag_database_node_info() {
  $items = array(
    'cooperation_offer' => array(
      'name' => t('Cooperation Offer'),
      'base' => 'node_content',
      'description' => t('Related to a Local Action Group.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'esi_funds_og' => array(
      'name' => t('ESI Funds OG'),
      'base' => 'node_content',
      'description' => t('Administrative ESI Fund Group for NSU.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'lag' => array(
      'name' => t('LAG'),
      'base' => 'node_content',
      'description' => t('Local Action Group.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
