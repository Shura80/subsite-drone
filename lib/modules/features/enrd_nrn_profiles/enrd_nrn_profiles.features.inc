<?php

/**
 * @file
 * enrd_nrn_profiles.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enrd_nrn_profiles_ctools_plugin_api($module = NULL, $api = NULL) {
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
 * Implements hook_views_api().
 */
function enrd_nrn_profiles_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function enrd_nrn_profiles_image_default_styles() {
  $styles = array();

  // Exported image style: enrd_nrn_profile_logo_preview.
  $styles['enrd_nrn_profile_logo_preview'] = array(
    'label' => 'NRN Profile logo preview',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'height' => '',
          'width' => 70,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: nrn_profile_logo_page.
  $styles['nrn_profile_logo_page'] = array(
    'label' => 'NRN Profile Logo Page',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 300,
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
function enrd_nrn_profiles_node_info() {
  $items = array(
    'nrn_profile' => array(
      'name' => t('NRN Profile'),
      'base' => 'node_content',
      'description' => t('Use <em>NRN profiles</em> to define National Rural Networks (NRNs) pages for the EU Member States.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
