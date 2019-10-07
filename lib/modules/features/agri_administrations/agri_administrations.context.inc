<?php

/**
 * @file
 * agri_administrations.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function agri_administrations_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'core-administrations-group-page';
  $context->description = 'Adds OG contextual blocks to an administration home page.';
  $context->tag = 'AGRI Administrations';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'administration' => 'administration',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'administration/*' => 'administration/*',
        '~administration/*/*' => '~administration/*/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'multisite_og_button-og-contextual-links' => array(
          'module' => 'multisite_og_button',
          'delta' => 'og-contextual-links',
          'region' => 'sidebar_left',
          'weight' => '-10',
        ),
        'views-61881c61e444a55353db59eaa3ab1eea' => array(
          'module' => 'views',
          'delta' => '61881c61e444a55353db59eaa3ab1eea',
          'region' => 'sidebar_left',
          'weight' => '-9',
        ),
        'views-ecf8b023e9fe7977331422f269bbed34' => array(
          'module' => 'views',
          'delta' => 'ecf8b023e9fe7977331422f269bbed34',
          'region' => 'sidebar_left',
          'weight' => '-8',
        ),
        'views-82e30bb9aa29dc5b938de99d8c600b2e' => array(
          'module' => 'views',
          'delta' => '82e30bb9aa29dc5b938de99d8c600b2e',
          'region' => 'content_top_left',
          'weight' => '-9',
        ),
        'quicktabs-administrations_content_tabs' => array(
          'module' => 'quicktabs',
          'delta' => 'administrations_content_tabs',
          'region' => 'content_top_right',
          'weight' => '-10',
        ),
        'views-9666194e7d9cd38199f8e806364bca0a' => array(
          'module' => 'views',
          'delta' => '9666194e7d9cd38199f8e806364bca0a',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Administrations');
  t('Adds OG contextual blocks to an administration home page.');
  $export['core-administrations-group-page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'core-dashboard-front-administrations';
  $context->description = 'Always active on user profile page.';
  $context->tag = 'AGRI Administrations';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
    'user_page' => array(
      'values' => array(
        'view' => 'view',
      ),
      'options' => array(
        'mode' => 'all',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-agri_og_administrations-block_2' => array(
          'module' => 'views',
          'delta' => 'agri_og_administrations-block_2',
          'region' => 'content_top_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Administrations');
  t('Always active on user profile page.');
  $export['core-dashboard-front-administrations'] = $context;

  return $export;
}
