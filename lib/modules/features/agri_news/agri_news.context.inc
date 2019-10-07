<?php

/**
 * @file
 * agri_news.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function agri_news_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'agri-news-related-content';
  $context->description = 'Context to show Solr search news related content.';
  $context->tag = 'AGRI News';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'news' => 'news',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'apachesolr_search-agri-mlt-news' => array(
          'module' => 'apachesolr_search',
          'delta' => 'agri-mlt-news',
          'region' => 'sidebar_left',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI News');
  t('Context to show Solr search news related content.');
  $export['agri-news-related-content'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'news-full-node';
  $context->description = 'Active on News.';
  $context->tag = 'AGRI News';
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
        'community/news/*' => 'community/news/*',
        'news/*' => 'news/*',
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
    'breadcrumb' => 'news-events/news',
    'menu' => 'news-events/news',
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI News');
  t('Active on News.');
  $export['news-full-node'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'news-funding-opportunities-full-node';
  $context->description = 'Active on Funding opportunities.';
  $context->tag = 'AGRI News';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'funding_opportunities' => 'funding_opportunities',
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
          'weight' => '0',
        ),
      ),
    ),
    'breadcrumb' => array(
      0 => 'main-menu:find-connect/funding-opportunities',
    ),
    'menu' => array(
      0 => 'main-menu:find-connect/funding-opportunities',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI News');
  t('Active on Funding opportunities.');
  $export['news-funding-opportunities-full-node'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'news-funding-opportunities-og';
  $context->description = 'Shows blocks for funding opportunities inside Administrations';
  $context->tag = 'AGRI News';
  $context->conditions = array(
    'context_og_condition_group_type' => array(
      'values' => array(
        'administration' => 'administration',
      ),
      'options' => array(
        'node_form' => 1,
      ),
    ),
    'node' => array(
      'values' => array(
        'funding_opportunities' => 'funding_opportunities',
      ),
      'options' => array(
        'node_form' => '0',
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
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI News');
  t('Shows blocks for funding opportunities inside Administrations');
  $export['news-funding-opportunities-og'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'news-funding-opportunities-search';
  $context->description = 'Active on Funding Opportunities search section';
  $context->tag = 'AGRI News';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'news_funding_opportunities_archived:page' => 'news_funding_opportunities_archived:page',
        'news_funding_opportunities_search:page' => 'news_funding_opportunities_search:page',
        'news_funding_opportunities_search:page_2' => 'news_funding_opportunities_search:page_2',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
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
  t('AGRI News');
  t('Active on Funding Opportunities search section');
  $export['news-funding-opportunities-search'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'news-funding-opportunities-search-archived';
  $context->description = 'Active on Funding Opportunities Archived search section';
  $context->tag = 'AGRI News';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'agri_archived_funding_opportunities:page' => 'agri_archived_funding_opportunities:page',
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
        'views-1b1f08b4efb09a689136221681ed3562' => array(
          'module' => 'views',
          'delta' => '1b1f08b4efb09a689136221681ed3562',
          'region' => 'sidebar_left',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI News');
  t('Active on Funding Opportunities Archived search section');
  $export['news-funding-opportunities-search-archived'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'news-online-resource-full-node';
  $context->description = 'Active on Online Resource.';
  $context->tag = 'AGRI News';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'online_resource' => 'online_resource',
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
    'breadcrumb' => 'find-connect/online-resources',
    'menu' => 'find-connect/online-resources',
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI News');
  t('Active on Online Resource.');
  $export['news-online-resource-full-node'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'news-search';
  $context->description = 'Active on News & Events section';
  $context->tag = 'AGRI News';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'news_search:page' => 'news_search:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'facetapi-LHb8Agj2qkYH0MoJIJ8Wgc7U8QZ1vCpL' => array(
          'module' => 'facetapi',
          'delta' => 'LHb8Agj2qkYH0MoJIJ8Wgc7U8QZ1vCpL',
          'region' => 'sidebar_left',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI News');
  t('Active on News & Events section');
  $export['news-search'] = $context;

  return $export;
}
