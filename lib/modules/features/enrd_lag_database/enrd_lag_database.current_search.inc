<?php

/**
 * @file
 * enrd_lag_database.current_search.inc
 */

/**
 * Implements hook_current_search_default_items().
 */
function enrd_lag_database_current_search_default_items() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->name = 'cooperation_offer';
  $item->label = 'CLLD Partner Tool current search';
  $item->settings = array(
    'items' => array(
      'results' => array(
        'id' => 'text',
        'label' => 'Results',
        'text' => ' [facetapi_results:result-count] Cooperation offer found',
        'plural' => 1,
        'text_plural' => '[facetapi_results:result-count] Cooperation offers found',
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 1,
        'element' => 'p',
        'css' => 0,
        'classes' => '',
        'weight' => '-50',
      ),
      'active_items' => array(
        'id' => 'active',
        'label' => 'Active items',
        'pattern' => '[facetapi_active:active-value]',
        'keys' => 1,
        'css' => 0,
        'classes' => '',
        'nofollow' => 1,
        'weight' => '-49',
      ),
      'reset' => array(
        'id' => 'reset_filters',
        'label' => 'Reset',
        'text' => 'Clear filters',
        'plural' => 0,
        'text_plural' => '',
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 1,
        'element' => '0',
        'css' => 0,
        'classes' => '',
        'weight' => '0',
      ),
    ),
    'advanced' => array(
      'empty_searches' => '3',
    ),
  );
  $export['cooperation_offer'] = $item;

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->name = 'lag';
  $item->label = 'LAG current search';
  $item->settings = array(
    'items' => array(
      'results' => array(
        'id' => 'text',
        'label' => 'Results',
        'text' => ' [facetapi_results:result-count] LAG found',
        'plural' => 1,
        'text_plural' => '[facetapi_results:result-count] LAGs found',
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 1,
        'element' => 'p',
        'css' => 0,
        'classes' => '',
        'weight' => '-50',
      ),
      'active_items' => array(
        'id' => 'active',
        'label' => 'Active items',
        'pattern' => '[facetapi_active:active-value]',
        'keys' => 1,
        'css' => 0,
        'classes' => '',
        'nofollow' => 1,
        'weight' => '-49',
      ),
      'reset' => array(
        'id' => 'reset_filters',
        'label' => 'Reset',
        'text' => 'Clear filters',
        'plural' => 0,
        'text_plural' => '',
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 1,
        'element' => '0',
        'css' => 0,
        'classes' => '',
        'weight' => '0',
      ),
    ),
    'advanced' => array(
      'empty_searches' => '3',
    ),
  );
  $export['lag'] = $item;

  return $export;
}
