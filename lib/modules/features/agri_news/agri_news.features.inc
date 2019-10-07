<?php

/**
 * @file
 * agri_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function agri_news_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
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
 * Implements hook_views_api().
 */
function agri_news_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function agri_news_node_info() {
  $items = array(
    'funding_opportunities' => array(
      'name' => t('Funding opportunities'),
      'base' => 'node_content',
      'description' => t('Funding opportunities content type.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'online_resource' => array(
      'name' => t('Online resource'),
      'base' => 'node_content',
      'description' => t('Publish an online resource.'),
      'has_title' => '1',
      'title_label' => t('Title (Original Language)'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
