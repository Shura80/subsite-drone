<?php

/**
 * @file
 * enrd_country_pages.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function enrd_country_pages_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_country_data_page';
  $context->description = 'Custom context for the ENRD Country data page.';
  $context->tag = 'ENRD Country Pages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'contact/country-data' => 'contact/country-data',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-eucountrymap' => array(
          'module' => 'bean',
          'delta' => 'eucountrymap',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Custom context for the ENRD Country data page.');
  t('ENRD Country Pages');
  $export['enrd_country_data_page'] = $context;

  return $export;
}
