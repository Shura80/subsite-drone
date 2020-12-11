<?php

/**
 * @file
 * Include file with views hooks.
 */

/**
 * Implements hook_views_plugins().
 */
function enrd_sfr_pub_views_plugins() {
  $path = drupal_get_path('module', 'enrd_sfr_pub');

  return array(
    'style' => array(
      'enrd_sfr_pub_cp_csv' => array(
        'title' => t('CSV - Contact Point Subscription'),
        'help' => t('Custom export for Contact Point Subscription.'),
        'handler' => 'views_data_export_plugin_style_export_csv',
        'export headers' => array('Content-type' => 'text/csv; charset=utf-8'),
        'export feed type' => 'csv',
        'export feed text' => 'CSV',
        'export feed file' => '%view.csv',
        'export feed icon' => drupal_get_path('module', 'views_data_export') . '/images/csv.png',
        'parent' => 'views_data_export_csv',
        'theme' => 'enrd_sfr_pub_cp_csv',
        'theme file' => 'enrd_sfr_pub.theme.inc',
        'theme path' => $path . '/theme',
        'additional themes base' => 'enrd_sfr_pub_cp_csv',
        'additional themes' => array(
          'enrd_sfr_pub_cp_csv_header' => 'style',
          'enrd_sfr_pub_cp_csv_body' => 'style',
        ),
        'uses row plugin' => FALSE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'data_export',
      ),
    ),
  );
}
