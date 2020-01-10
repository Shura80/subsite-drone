<?php

/**
 * @file
 * enrd_news.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function enrd_news_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_event_inside_community';
  $context->description = '';
  $context->tag = 'ENRD News&Events';
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
        'community/*' => 'community/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-enrd_event_document_ref-block_1' => array(
          'module' => 'views',
          'delta' => 'enrd_event_document_ref-block_1',
          'region' => 'sidebar_right',
          'weight' => '-10',
        ),
        'views-enrd_calendar-calendar_block' => array(
          'module' => 'views',
          'delta' => 'enrd_calendar-calendar_block',
          'region' => 'sidebar_right',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('ENRD News&Events');
  $export['enrd_event_inside_community'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_events_public_new';
  $context->description = 'Shows ENRD public events.';
  $context->tag = 'ENRD News&Events';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'news-events/events*' => 'news-events/events*',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => 'main-menu:news-events/events',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('ENRD News&Events');
  t('Shows ENRD public events.');
  $export['enrd_events_public_new'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_news_events_page';
  $context->description = '';
  $context->tag = 'ENRD News&Events';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'news-events' => 'news-events',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-0a25238ad3fd01e3f05d8c0ab0753edd' => array(
          'module' => 'views',
          'delta' => '0a25238ad3fd01e3f05d8c0ab0753edd',
          'region' => 'content_right',
          'weight' => '-10',
        ),
        'views-enrd_news-newsroom_carousel' => array(
          'module' => 'views',
          'delta' => 'enrd_news-newsroom_carousel',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('ENRD News&Events');
  $export['enrd_news_events_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_news_inside_community';
  $context->description = '';
  $context->tag = 'ENRD News&Events';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'news' => 'news',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'community/*' => 'community/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-news-block_1' => array(
          'module' => 'views',
          'delta' => 'news-block_1',
          'region' => 'sidebar_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('ENRD News&Events');
  $export['enrd_news_inside_community'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_news_public';
  $context->description = 'Shows ENRD public news.';
  $context->tag = 'ENRD News&Events';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'news-events/news*' => 'news-events/news*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-enrd_news-news_archive' => array(
          'module' => 'views',
          'delta' => 'enrd_news-news_archive',
          'region' => 'sidebar_right',
          'weight' => '-50',
        ),
      ),
    ),
    'menu' => array(
      0 => 'main-menu:news-events/news',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('ENRD News&Events');
  t('Shows ENRD public news.');
  $export['enrd_news_public'] = $context;

  return $export;
}
