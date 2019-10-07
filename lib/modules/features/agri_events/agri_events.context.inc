<?php

/**
 * @file
 * agri_events.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function agri_events_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'agri-events-related-content';
  $context->description = 'Context to show Solr search events related content.';
  $context->tag = 'AGRI Events';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'event' => 'event',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'apachesolr_search-agri-related-event' => array(
          'module' => 'apachesolr_search',
          'delta' => 'agri-mlt-event',
          'region' => 'content_bottom',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Events');
  t('Context to show Solr search events related content.');
  $export['agri-events-related-content'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'core-events-dashboard';
  $context->description = 'Shows main blocks in Events entry page.';
  $context->tag = 'AGRI Events';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'events' => 'events',
        'events/*' => 'events/*',
        '~events/calendar' => '~events/calendar',
        '~events/calendar/*' => '~events/calendar/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-agri_calendar-block_1' => array(
          'module' => 'views',
          'delta' => 'agri_calendar-block_1',
          'region' => 'sidebar_left',
          'weight' => '-10',
        ),
        'views--exp-events_list-splash_page' => array(
          'module' => 'views',
          'delta' => '-exp-events_list-splash_page',
          'region' => 'content_bottom',
          'weight' => '-9',
        ),
        'quicktabs-agri_event_event_list' => array(
          'module' => 'quicktabs',
          'delta' => 'agri_event_event_list',
          'region' => 'content_bottom',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Events');
  t('Shows main blocks in Events entry page.');
  $export['core-events-dashboard'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'event-full-node';
  $context->description = 'Active on Events, displays block of event informations.';
  $context->tag = 'AGRI Events';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'event' => 'event',
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
        'views-events_node_details-block' => array(
          'module' => 'views',
          'delta' => 'events_node_details-block',
          'region' => 'content_top',
          'weight' => '-9',
        ),
      ),
    ),
    'breadcrumb' => 'news-events/events',
    'menu' => 'news-events/events',
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Events');
  t('Active on Events, displays block of event informations.');
  $export['event-full-node'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'events-search';
  $context->description = 'Active on News & Events section';
  $context->tag = 'AGRI Events';
  $context->conditions = array();
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'facetapi-jXN2EqYaH5XsJucodoVPdZNdUnJVX8da' => array(
          'module' => 'facetapi',
          'delta' => 'jXN2EqYaH5XsJucodoVPdZNdUnJVX8da',
          'region' => 'sidebar_left',
          'weight' => '-8',
        ),
        'facetapi-CELDEidYQR1AZqApdxU9diSgNz1pRQ1L' => array(
          'module' => 'facetapi',
          'delta' => 'CELDEidYQR1AZqApdxU9diSgNz1pRQ1L',
          'region' => 'sidebar_left',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Events');
  t('Active on News & Events section');
  $export['events-search'] = $context;

  return $export;
}
