<?php

/**
 * @file
 * agri_pages.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function agri_pages_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'agri-pages-related-content';
  $context->description = 'Context to show Solr search pages related content.';
  $context->tag = 'AGRI Pages';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'page' => 'page',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'focus-groups/*' => 'focus-groups/*',
        'content/focus-groups/*' => 'content/focus-groups/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'apachesolr_search-agri-mlt-page' => array(
          'module' => 'apachesolr_search',
          'delta' => 'agri-mlt-page',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Pages');
  t('Context to show Solr search pages related content.');
  $export['agri-pages-related-content'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'pages-full-node';
  $context->description = 'Active only on basic pages, displays a block on the left sidebar with page menu children';
  $context->tag = 'AGRI Pages';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'page' => 'page',
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
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Pages');
  t('Active only on basic pages, displays a block on the left sidebar with page menu children');
  $export['pages-full-node'] = $context;

  return $export;
}
