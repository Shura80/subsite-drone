<?php

/**
 * @file
 * agri_publications.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function agri_publications_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'publications-full-node';
  $context->description = 'Active on Publication, displays publication details block.';
  $context->tag = 'AGRI Publications';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'publication' => 'publication',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'content/*' => 'content/*',
        'node/*/draft' => 'node/*/draft',
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
    'breadcrumb' => 'publications',
    'menu' => 'publications',
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Publications');
  t('Active on Publication, displays publication details block.');
  $export['publications-full-node'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'publications-search';
  $context->description = 'Active on Publication search section';
  $context->tag = 'AGRI Publications';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'publications_search:page' => 'publications_search:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'facetapi-KIOvlTAOVQYF1ibMIjYqWNcS0EIPjQa0' => array(
          'module' => 'facetapi',
          'delta' => 'KIOvlTAOVQYF1ibMIjYqWNcS0EIPjQa0',
          'region' => 'sidebar_left',
          'weight' => '-10',
        ),
        'facetapi-6nehxqA6qlto9TjKHYDVZTu2tc0FfeS1' => array(
          'module' => 'facetapi',
          'delta' => '6nehxqA6qlto9TjKHYDVZTu2tc0FfeS1',
          'region' => 'sidebar_left',
          'weight' => '-9',
        ),
        'search_api_saved_searches-core_node_index' => array(
          'module' => 'search_api_saved_searches',
          'delta' => 'core_node_index',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Publications');
  t('Active on Publication search section');
  $export['publications-search'] = $context;

  return $export;
}
