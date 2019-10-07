<?php

/**
 * @file
 * agri_press.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function agri_press_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'agri-press-related-content';
  $context->description = 'Context to show Solr search press related content.';
  $context->tag = 'AGRI Press';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'press_release' => 'press_release',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'apachesolr_search-agri-mlt-press_release' => array(
          'module' => 'apachesolr_search',
          'delta' => 'agri-mlt-press_release',
          'region' => 'sidebar_left',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Press');
  t('Context to show Solr search press related content.');
  $export['agri-press-related-content'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'press-full-node';
  $context->description = 'Active on Press releaseas and press clippings.';
  $context->tag = 'AGRI Press';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'press_clipping' => 'press_clipping',
        'press_release' => 'press_release',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-agri_pages_side_menu' => array(
          'module' => 'menu_block',
          'delta' => 'agri_pages_side_menu',
          'region' => 'sidebar_left',
          'weight' => '-10',
        ),
      ),
    ),
    'breadcrumb' => 'news-events/press-media',
    'menu' => 'news-events/press-media',
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Press');
  t('Active on Press releaseas and press clippings.');
  $export['press-full-node'] = $context;

  return $export;
}
