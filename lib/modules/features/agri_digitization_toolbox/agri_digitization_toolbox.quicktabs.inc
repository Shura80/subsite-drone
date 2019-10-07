<?php

/**
 * @file
 * agri_digitization_toolbox.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function agri_digitization_toolbox_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'agri_eip_digitization_activities';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = TRUE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'AGRI Digitisation Toolbox - EIP-AGRI activities';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'events_list',
      'display' => 'digitization_events_filtered',
      'args' => '',
      'title' => 'Events',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'events_list',
      'display' => 'digitization_focus_groups_filtered',
      'args' => '',
      'title' => 'Focus Groups',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'Agri tab secondary';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Digitisation Toolbox - EIP-AGRI activities');
  t('Events');
  t('Focus Groups');

  $export['agri_eip_digitization_activities'] = $quicktabs;

  return $export;
}
