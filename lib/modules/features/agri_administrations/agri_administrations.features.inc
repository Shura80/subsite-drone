<?php

/**
 * @file
 * agri_administrations.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function agri_administrations_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function agri_administrations_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function agri_administrations_node_info() {
  $items = array(
    'administration' => array(
      'name' => t('Administration'),
      'base' => 'node_content',
      'description' => t('A Group content type to allow different workflows for Funding opportunities content type.'),
      'has_title' => '1',
      'title_label' => t('Administration name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
