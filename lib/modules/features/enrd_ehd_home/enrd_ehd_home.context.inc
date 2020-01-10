<?php

/**
 * @file
 * enrd_ehd_home.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function enrd_ehd_home_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_evaluation_landing_page';
  $context->description = 'Custom context for the Evaluation Landing page.';
  $context->tag = 'ENRD Evaluation';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'evaluation' => 'evaluation',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-ehdtwitterfeeds' => array(
          'module' => 'bean',
          'delta' => 'ehdtwitterfeeds',
          'region' => 'sidebar_right',
          'weight' => '-20',
        ),
        'views-fa23ee05765476d40bd97bcee550387e' => array(
          'module' => 'views',
          'delta' => 'fa23ee05765476d40bd97bcee550387e',
          'region' => 'sidebar_right',
          'weight' => '-15',
        ),
        'views-3fb303b2833266fa6da1f466eb5be9a5' => array(
          'module' => 'views',
          'delta' => '3fb303b2833266fa6da1f466eb5be9a5',
          'region' => 'content',
          'weight' => '5',
        ),
        'views-0325f88e4e84bd25fd45819490465639' => array(
          'module' => 'views',
          'delta' => '0325f88e4e84bd25fd45819490465639',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Custom context for the Evaluation Landing page.');
  t('ENRD Evaluation');
  $export['enrd_evaluation_landing_page'] = $context;

  return $export;
}
