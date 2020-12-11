<?php

/**
 * @file
 * enrd_projects.apachesolr_search_defaults.inc
 */

/**
 * Implements hook_apachesolr_search_default_searchers().
 */
function enrd_projects_apachesolr_search_default_searchers() {
  $export = array();

  $searcher = new stdClass();
  $searcher->disabled = FALSE; /* Edit this to true to make a default searcher disabled initially */
  $searcher->api_version = 3;
  $searcher->page_id = 'projects_database';
  $searcher->label = 'Projects Database';
  $searcher->description = 'ENRD Projects Database';
  $searcher->search_path = 'projects-practice';
  $searcher->page_title = 'Projects & Practice';
  $searcher->env_id = 'solr';
  $searcher->settings = array(
    'fq' => array(
      0 => 'bundle:project',
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
      'value' => '<div class="alert alert-info" role="alert">No projects found, matching with your search criteria.</div>',
      'format' => 'full_html',
    ),
    'apachesolr_multilingual_auto_language_filter' => 1,
    'apachesolr_multilingual_auto_language_filter_detachable' => 0,
    'apachesolr_multilingual_show_language_undefined_results' => 0,
  );
  $export['projects_database'] = $searcher;

  return $export;
}
