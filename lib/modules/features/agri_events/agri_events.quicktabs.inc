<?php

/**
 * @file
 * agri_events.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function agri_events_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'agri_event_event_list';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'AGRI Event - Event list';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'events_list',
      'display' => 'block_1',
      'args' => '',
      'title' => 'Upcoming',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'events_list',
      'display' => 'block_2',
      'args' => '',
      'title' => 'Past',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'Agri tab primary';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Event - Event list');
  t('Past');
  t('Upcoming');

  $export['agri_event_event_list'] = $quicktabs;

  return $export;
}
