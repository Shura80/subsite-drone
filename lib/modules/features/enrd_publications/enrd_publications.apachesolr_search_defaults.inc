<?php

/**
 * @file
 * enrd_publications.apachesolr_search_defaults.inc
 */

/**
 * Implements hook_apachesolr_search_default_searchers().
 */
function enrd_publications_apachesolr_search_default_searchers() {
  $export = array();

  $searcher = new stdClass();
  $searcher->disabled = FALSE; /* Edit this to true to make a default searcher disabled initially */
  $searcher->api_version = 3;
  $searcher->page_id = 'evaluation_publications_elibrary';
  $searcher->label = 'Evaluation Publications eLibrary';
  $searcher->description = 'Evaluation Publications eLibrary';
  $searcher->search_path = 'evaluation/publications';
  $searcher->page_title = 'Search Evaluation Publications';
  $searcher->env_id = 'solr';
  $searcher->settings = array(
    'fq' => array(
      0 => 'bundle:publication_ehd',
    ),
    'apachesolr_search_custom_enable' => 1,
    'apachesolr_search_search_type' => 'custom',
    'apachesolr_search_per_page' => 10,
    'apachesolr_search_spellcheck' => 1,
    'apachesolr_search_search_box' => 1,
    'apachesolr_search_allow_user_input' => 0,
    'apachesolr_search_browse' => 'results',
    'apachesolr_ds_search_view_mode' => 'ds_search_default',
    'apachesolr_noresults_message' => array(
      'value' => '<div class="alert alert-info" role="alert">No evaluation publications found, matching with your search criteria.</div>',
      'format' => 'full_html',
    ),
    'apachesolr_multilingual_auto_language_filter' => 1,
    'apachesolr_multilingual_auto_language_filter_detachable' => 0,
    'apachesolr_multilingual_show_language_undefined_results' => 0,
  );
  $export['evaluation_publications_elibrary'] = $searcher;

  $searcher = new stdClass();
  $searcher->disabled = FALSE; /* Edit this to true to make a default searcher disabled initially */
  $searcher->api_version = 3;
  $searcher->page_id = 'publications_elibrary';
  $searcher->label = 'Publications eLibrary';
  $searcher->description = 'ENRD Publications eLibrary';
  $searcher->search_path = 'publications/search';
  $searcher->page_title = 'Publications';
  $searcher->env_id = 'solr';
  $searcher->settings = array(
    'fq' => array(
      0 => 'bundle:publication',
    ),
    'apachesolr_search_custom_enable' => 1,
    'apachesolr_search_search_type' => 'custom',
    'apachesolr_search_per_page' => 10,
    'apachesolr_search_spellcheck' => 1,
    'apachesolr_search_search_box' => 1,
    'apachesolr_search_allow_user_input' => 0,
    'apachesolr_search_browse' => 'results',
    'apachesolr_ds_search_view_mode' => 'ds_search_default',
    'apachesolr_noresults_message' => array(
      'value' => '<div class="alert alert-info" role="alert">No publications found, matching with your search criteria.</div>',
      'format' => 'full_html',
    ),
    'apachesolr_multilingual_auto_language_filter' => 1,
    'apachesolr_multilingual_auto_language_filter_detachable' => 0,
    'apachesolr_multilingual_show_language_undefined_results' => 0,
  );
  $export['publications_elibrary'] = $searcher;

  return $export;
}
