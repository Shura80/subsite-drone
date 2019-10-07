<?php

/**
 * @file
 * Provides support for the views module.
 */

/**
 * Implements hook_views_data().
 */
function agri_core_views_data() {
  $data = array();
  $data['views']['agri_core_link_page'] = array(
    'title' => t('Create a custom link page'),
    'help' => t('Display a link custom for redirect a specific page.'),
    'area' => array(
      'handler' => 'agri_core_views_handler_area_link_page',
    ),
  );
  return $data;
}
