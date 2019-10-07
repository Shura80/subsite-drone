<?php

/**
 * @file
 * agri_administrations.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function agri_administrations_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'administrations_content_tabs';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = TRUE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Unpublished content';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'agri_og_administrations_content_list',
      'display' => 'block_1',
      'args' => '',
      'title' => 'Draft',
      'weight' => '-99',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'agri_og_administrations_content_list',
      'display' => 'block_2',
      'args' => '',
      'title' => 'Needs review',
      'weight' => '-98',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'agri_og_administrations_content_list',
      'display' => 'block_3',
      'args' => '',
      'title' => 'Validated',
      'weight' => '-97',
      'type' => 'view',
    ),
    3 => array(
      'vid' => 'agri_og_administrations_content_list',
      'display' => 'block_4',
      'args' => '',
      'title' => 'Archived',
      'weight' => '-96',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'Agri tab secondary';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Archived');
  t('Draft');
  t('Needs review');
  t('Unpublished content');
  t('Validated');

  $export['administrations_content_tabs'] = $quicktabs;

  return $export;
}
