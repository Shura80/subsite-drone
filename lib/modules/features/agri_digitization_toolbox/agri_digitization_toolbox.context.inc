<?php

/**
 * @file
 * agri_digitization_toolbox.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function agri_digitization_toolbox_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'agri_digitization_toolbox_landing_page';
  $context->description = 'Context for Digitisation toolbox landing page';
  $context->tag = 'AGRI Digitisation Toolbox';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'digitising-agriculture' => 'digitising-agriculture',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-5343dff238b4d5aed9a5f2408505e8cc' => array(
          'module' => 'views',
          'delta' => '5343dff238b4d5aed9a5f2408505e8cc',
          'region' => 'sidebar_right',
          'weight' => '-10',
        ),
        'views-cdaf77c325866504fe537c40ad5bf85c' => array(
          'module' => 'views',
          'delta' => 'cdaf77c325866504fe537c40ad5bf85c',
          'region' => 'sidebar_right',
          'weight' => '-9',
        ),
        'views-84894e509c4e0a14bd6662c5287b6835' => array(
          'module' => 'views',
          'delta' => '84894e509c4e0a14bd6662c5287b6835',
          'region' => 'content_top_left',
          'weight' => '-10',
        ),
        'menu-menu-digitization-toolbox' => array(
          'module' => 'menu',
          'delta' => 'menu-digitization-toolbox',
          'region' => 'content_top_right',
          'weight' => '-10',
        ),
        'views-4eeb0a1180a820bd7a2ec9acdaf60fb7' => array(
          'module' => 'views',
          'delta' => '4eeb0a1180a820bd7a2ec9acdaf60fb7',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Digitisation Toolbox');
  t('Context for Digitisation toolbox landing page');
  $export['agri_digitization_toolbox_landing_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'agri_digitization_toolbox_navigation';
  $context->description = 'Context for Digitisation Toolbox menu navigation';
  $context->tag = 'AGRI Digitisation Toolbox';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'digitisation_toolbox' => 'digitisation_toolbox',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'digitising-agriculture/*' => 'digitising-agriculture/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-agri-digitization-toolbox-menu' => array(
          'module' => 'menu_block',
          'delta' => 'agri-digitization-toolbox-menu',
          'region' => 'sidebar_left',
          'weight' => '-9',
        ),
        'views-5343dff238b4d5aed9a5f2408505e8cc' => array(
          'module' => 'views',
          'delta' => '5343dff238b4d5aed9a5f2408505e8cc',
          'region' => 'sidebar_left',
          'weight' => '-8',
        ),
        'views-f7d5e8e41685943ba4e61c115e3b7105' => array(
          'module' => 'views',
          'delta' => 'f7d5e8e41685943ba4e61c115e3b7105',
          'region' => 'content_top_left',
          'weight' => '-10',
        ),
        'views-bd3c8186a9cb04481618e39dcbf5bc72' => array(
          'module' => 'views',
          'delta' => 'bd3c8186a9cb04481618e39dcbf5bc72',
          'region' => 'content_top_left',
          'weight' => '-9',
        ),
        'quicktabs-agri_eip_digitization_activities' => array(
          'module' => 'quicktabs',
          'delta' => 'agri_eip_digitization_activities',
          'region' => 'content_top_left',
          'weight' => '-8',
        ),
        'views-2eed0155346084f4f1713f0a64e5aec1' => array(
          'module' => 'views',
          'delta' => '2eed0155346084f4f1713f0a64e5aec1',
          'region' => 'content_top_left',
          'weight' => '-7',
        ),
        'views-2f860fba4fcb53d0aef3ad0498c2cc29' => array(
          'module' => 'views',
          'delta' => '2f860fba4fcb53d0aef3ad0498c2cc29',
          'region' => 'content_top_left',
          'weight' => '-6',
        ),
        'apachesolr_search-agri-mlt-digitisation_toolbox' => array(
          'module' => 'apachesolr_search',
          'delta' => 'agri-mlt-digitisation_toolbox',
          'region' => 'content_top_left',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Digitisation Toolbox');
  t('Context for Digitisation Toolbox menu navigation');
  $export['agri_digitization_toolbox_navigation'] = $context;

  return $export;
}
