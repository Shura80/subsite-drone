<?php

/**
 * @file
 * Provide views data and handlers.
 */

/**
 * Implements hook_views_plugins().
 *
 * Missing the handler of the theme for rows.
 */
function enrd_mastermind_views_plugins() {
  $module_path = drupal_get_path('module', 'enrd_mastermind');

  return array(
    'style' => array(
      'enrd_mastermind_media_plugin_style' => array(
        'title' => t('ENRD Media Object'),
        'help' => t('ENRD Media Object Style'),
        'path' => $module_path . '/views/plugins',
        'handler' => 'enrd_mastermind_media_plugin_style',
        'parent' => 'default',
        'theme' => 'enrd_mastermind_media_plugin_style',
        'theme path' => $module_path . '/views/templates',
        'theme file' => 'theme.inc',
        'uses row plugin' => TRUE,
        'uses row class' => TRUE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'uses grouping' => FALSE,
        'type' => 'normal',
      ),
    ),
    'row' => array(
      'enrd_mastermind_media_plugin_rows' => array(
        'title' => t('ENRD Media Object field'),
        'help' => t('Choose the fields to display in ENRD Media Object.'),
        'path' => $module_path . '/views/plugins',
        'handler' => 'enrd_mastermind_media_plugin_rows',
        'theme' => 'enrd_mastermind_media_plugin_rows',
        'theme path' => $module_path . '/views/templates',
        'theme file' => 'theme.inc',
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
}
