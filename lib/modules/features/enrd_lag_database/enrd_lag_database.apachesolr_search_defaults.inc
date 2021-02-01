<?php

/**
 * @file
 * enrd_lag_database.apachesolr_search_defaults.inc
 */

/**
 * Implements hook_apachesolr_search_default_searchers().
 */
function enrd_lag_database_apachesolr_search_default_searchers() {
  $export = array();

  $searcher = new stdClass();
  $searcher->disabled = FALSE; /* Edit this to true to make a default searcher disabled initially */
  $searcher->api_version = 3;
  $searcher->page_id = 'lag_database';
  $searcher->label = 'LAG Database';
  $searcher->description = 'LAG Database';
  $searcher->search_path = 'leader-clld/lag-database';
  $searcher->page_title = 'LAG Database';
  $searcher->env_id = 'solr';
  $searcher->settings = array(
    'fq' => array(
      0 => 'bundle:lag',
    ),
    'apachesolr_search_custom_enable' => 1,
    'apachesolr_search_search_type' => 'custom',
    'apachesolr_search_per_page' => 25,
    'apachesolr_search_spellcheck' => 1,
    'apachesolr_search_search_box' => 1,
    'apachesolr_search_allow_user_input' => 0,
    'apachesolr_search_browse' => 'results',
    'apachesolr_ds_search_view_mode' => 'ds_search_default',
    'apachesolr_noresults_message' => array(
      'value' => '<div class="alert alert-info" role="alert">No LAGs found, matching with your search criteria.</div>',
      'format' => 'full_html',
    ),
    'apachesolr_intro_message' => array(
      'value' => '<p class="solr-page-intro">The ENRD LAG database allows Local Action Groups (LAGs) to get in touch, network and cooperate with each other. Find out how to search the tool in the <a href="[site:base-url]/[site:public-folder-path]/leader_lag-database_how-to-search_guide.pdf" target="_blank">ENRD Guide</a>.<br>
	LAG managers can log in to their accounts via the button above and start managing their LAGs’ online profiles, explore the <a href="[node:25074:url]">Guide for LAGs</a>.<br>
	In case of difficulties, please write to <a href="mailto:LAG-database-webmaster@enrd.eu">LAG-database-webmaster@enrd.eu</a>.</p>
',
      'format' => 'full_html',
    ),
    'apachesolr_multilingual_auto_language_filter' => 1,
    'apachesolr_multilingual_auto_language_filter_detachable' => 0,
    'apachesolr_multilingual_show_language_undefined_results' => 1,
  );
  $export['lag_database'] = $searcher;

  $searcher = new stdClass();
  $searcher->disabled = FALSE; /* Edit this to true to make a default searcher disabled initially */
  $searcher->api_version = 3;
  $searcher->page_id = 'partner_search';
  $searcher->label = 'CLLD Partner Search Active';
  $searcher->description = 'CLLD Partner Search Active';
  $searcher->search_path = 'leader-clld/clld-partner-search/active';
  $searcher->page_title = 'Active offers';
  $searcher->env_id = 'solr';
  $searcher->settings = array(
    'fq' => array(
      0 => 'bundle:cooperation_offer',
      1 => 'ds_field_enrd_coop_expiry_date:[NOW-1DAY/DAY TO *]',
    ),
    'apachesolr_search_custom_enable' => 1,
    'apachesolr_search_search_type' => 'custom',
    'apachesolr_search_per_page' => 25,
    'apachesolr_search_spellcheck' => 1,
    'apachesolr_search_search_box' => 1,
    'apachesolr_search_allow_user_input' => 0,
    'apachesolr_search_browse' => 'results',
    'apachesolr_ds_search_view_mode' => 'ds_search_default',
    'apachesolr_noresults_message' => array(
      'value' => '<div class="alert alert-info" role="alert">No cooperation offers found, matching with your search criteria.</div>',
      'format' => 'full_html',
    ),
    'apachesolr_intro_message' => array(
      'value' => '<p class="solr-page-intro">The ENRD CLLD Partner Search tool allows Local Action Groups (LAGs) to create cooperation offers and find project partners.<br>
	LAG managers can log in to their accounts via the button above and start creating cooperation offers for their LAGs,&nbsp;explore the&nbsp;<a href="[node:25074:url]">Guide for LAGs</a>.<br>
	In case of difficulties, please write to <a href="mailto:LAG-database-webmaster@enrd.eu">LAG-database-webmaster@enrd.eu</a>.</p>
',
      'format' => 'full_html',
    ),
    'apachesolr_multilingual_auto_language_filter' => 1,
    'apachesolr_multilingual_auto_language_filter_detachable' => 0,
    'apachesolr_multilingual_show_language_undefined_results' => 1,
  );
  $export['partner_search'] = $searcher;

  $searcher = new stdClass();
  $searcher->disabled = FALSE; /* Edit this to true to make a default searcher disabled initially */
  $searcher->api_version = 3;
  $searcher->page_id = 'partner_search_expired';
  $searcher->label = 'CLLD Partner Search Expired';
  $searcher->description = 'CLLD Partner Search';
  $searcher->search_path = 'leader-clld/clld-partner-search/expired';
  $searcher->page_title = 'Expired offers';
  $searcher->env_id = 'solr';
  $searcher->settings = array(
    'fq' => array(
      0 => 'bundle:cooperation_offer',
      1 => 'ds_field_enrd_coop_expiry_date:[* TO NOW-1DAY/DAY]',
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
      'value' => '<div class="alert alert-info" role="alert">No cooperation offers found, matching with your search criteria.</div>',
      'format' => 'full_html',
    ),
    'apachesolr_intro_message' => array(
      'value' => '<p class="solr-page-intro">The ENRD CLLD Partner Search tool allows Local Action Groups (LAGs) to create cooperation offers and find project partners.<br>
	LAG managers can log in to their accounts via the button above and start creating cooperation offers for their LAGs,&nbsp;explore the&nbsp;<a href="[node:25074:url]">Guide for LAGs</a>.<br>
	In case of difficulties, please write to <a href="mailto:LAG-database-webmaster@enrd.eu">LAG-database-webmaster@enrd.eu</a>.</p>
',
      'format' => 'full_html',
    ),
    'apachesolr_multilingual_auto_language_filter' => 1,
    'apachesolr_multilingual_auto_language_filter_detachable' => 0,
    'apachesolr_multilingual_show_language_undefined_results' => 1,
  );
  $export['partner_search_expired'] = $searcher;

  return $export;
}
