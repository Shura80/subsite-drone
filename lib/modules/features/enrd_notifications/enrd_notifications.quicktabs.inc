<?php

/**
 * @file
 * enrd_notifications.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function enrd_notifications_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'enrd_notifications_settings';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = TRUE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'ENRD Notifications tabs';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'enrd_notifications_user_flags',
      'display' => 'flag_node_type_list',
      'args' => '',
      'use_title' => 0,
      'title' => 'Contents you follow',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'enrd_notifications_node_flags',
      'display' => 'flag_all_lags',
      'args' => '%1/%3',
      'use_title' => 0,
      'title' => 'LAGs you follow',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'path' => 'user/%/notifications/settings/email',
      'use_title' => 0,
      'title' => 'Email settings',
      'weight' => '-98',
      'type' => 'callback',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Contents you follow');
  t('ENRD Notifications tabs');
  t('Email settings');
  t('LAGs you follow');

  $export['enrd_notifications_settings'] = $quicktabs;

  return $export;
}
