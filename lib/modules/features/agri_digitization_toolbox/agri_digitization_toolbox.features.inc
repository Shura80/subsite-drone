<?php

/**
 * @file
 * agri_digitization_toolbox.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function agri_digitization_toolbox_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
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
function agri_digitization_toolbox_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function agri_digitization_toolbox_flag_default_flags() {
  $flags = array();
  // Exported flag: "Digitisation toolbox".
  $flags['agri_digitization_toolbox'] = array(
    'entity_type' => 'node',
    'title' => 'Digitisation toolbox',
    'global' => 1,
    'types' => array(
      0 => 'page',
      1 => 'event',
      2 => 'news',
      3 => 'online_resource',
      4 => 'press_release',
      5 => 'project',
      6 => 'publication',
    ),
    'flag_short' => 'Add to Digitisation toolbox',
    'flag_long' => 'Add this item to Digitisation toolbox',
    'flag_message' => '',
    'unflag_short' => 'Remove from Digitisation toolbox',
    'unflag_long' => 'Remove this item from Digitisation toolbox',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'diff_standard' => 0,
      'print' => 0,
      'email_plain' => 0,
      'email_html' => 0,
      'email_textalt' => 0,
      'token' => 0,
      'core_small_teaser' => 0,
      'core_spotlight' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 1,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'agri_digitization_toolbox',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function agri_digitization_toolbox_node_info() {
  $items = array(
    'digitisation_toolbox' => array(
      'name' => t('Digitisation Toolbox page'),
      'base' => 'node_content',
      'description' => t('Content type used to create Digitisation toolbox pages.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
