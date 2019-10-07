<?php

/**
 * @file
 * Provide views data and handlers.
 */

/**
 * Implements hook_views_plugins().
 */
function agri_project_map_views_plugins() {
  $module_path = drupal_get_path('module', 'agri_project_map');

  return array(
    'style' => array(
      'agri_project_map_plugin_style' => array(
        'title' => t('Project Map (EU map)'),
        'path' => $module_path . '/views/plugins',
        'handler' => 'agri_project_map_plugin_style',
        'type' => 'normal',
        'uses row plugin' => TRUE,
        'uses grouping' => TRUE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'use pager' => FALSE,
        'even empty' => TRUE,
      ),
    ),
  );
}
