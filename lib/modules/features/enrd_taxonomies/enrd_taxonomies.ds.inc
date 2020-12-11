<?php

/**
 * @file
 * enrd_taxonomies.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function enrd_taxonomies_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'enrd_country_images';
  $ds_view_mode->label = 'Country images';
  $ds_view_mode->entities = array(
    'taxonomy_term' => 'taxonomy_term',
  );
  $export['enrd_country_images'] = $ds_view_mode;

  return $export;
}
