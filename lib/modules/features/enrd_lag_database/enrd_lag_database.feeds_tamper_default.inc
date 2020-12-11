<?php

/**
 * @file
 * enrd_lag_database.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function enrd_lag_database_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'enrd_lag_database-city-enrd_lag_addr_city_required';
  $feeds_tamper->importer = 'enrd_lag_database';
  $feeds_tamper->source = 'City';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Required field';
  $export['enrd_lag_database-city-enrd_lag_addr_city_required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'enrd_lag_database-country-country_to_code';
  $feeds_tamper->importer = 'enrd_lag_database';
  $feeds_tamper->source = 'Country';
  $feeds_tamper->plugin_id = 'country_to_code';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Convert country to ISO code';
  $export['enrd_lag_database-country-country_to_code'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'enrd_lag_database-country-enrd_lag_addr_country_required';
  $feeds_tamper->importer = 'enrd_lag_database';
  $feeds_tamper->source = 'Country';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Required field';
  $export['enrd_lag_database-country-enrd_lag_addr_country_required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'enrd_lag_database-country__classification_-copy';
  $feeds_tamper->importer = 'enrd_lag_database';
  $feeds_tamper->source = 'Country (classification)';
  $feeds_tamper->plugin_id = 'copy';
  $feeds_tamper->settings = array(
    'to_from' => 'from',
    'source' => 'country',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Copy source value';
  $export['enrd_lag_database-country__classification_-copy'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'enrd_lag_database-email_address-enrd_lag_manager_email_required';
  $feeds_tamper->importer = 'enrd_lag_database';
  $feeds_tamper->source = 'Email address';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Required field';
  $export['enrd_lag_database-email_address-enrd_lag_manager_email_required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'enrd_lag_database-esi_funds_og-copy';
  $feeds_tamper->importer = 'enrd_lag_database';
  $feeds_tamper->source = 'ESI Funds OG';
  $feeds_tamper->plugin_id = 'copy';
  $feeds_tamper->settings = array(
    'to_from' => 'from',
    'source' => 'main esi fund',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Copy source value';
  $export['enrd_lag_database-esi_funds_og-copy'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'enrd_lag_database-esi_funds_og-eafrd_replace';
  $feeds_tamper->importer = 'enrd_lag_database';
  $feeds_tamper->source = 'ESI Funds OG';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'EAFRD',
    'replace' => 'European Agricultural Fund for Rural Development (EAFRD)',
    'case_sensitive' => 1,
    'word_boundaries' => 1,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^EAFRD$/u',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'EAFRD replace';
  $export['enrd_lag_database-esi_funds_og-eafrd_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'enrd_lag_database-esi_funds_og-emff_replace';
  $feeds_tamper->importer = 'enrd_lag_database';
  $feeds_tamper->source = 'ESI Funds OG';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'EMFF',
    'replace' => 'European Maritime and Fisheries Fund (EMFF)',
    'case_sensitive' => 1,
    'word_boundaries' => 1,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^EMFF$/u',
  );
  $feeds_tamper->weight = 4;
  $feeds_tamper->description = 'EMFF replace';
  $export['enrd_lag_database-esi_funds_og-emff_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'enrd_lag_database-esi_funds_og-erdf_replace';
  $feeds_tamper->importer = 'enrd_lag_database';
  $feeds_tamper->source = 'ESI Funds OG';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'ERDF',
    'replace' => 'European Regional Development Fund (ERDF)',
    'case_sensitive' => 1,
    'word_boundaries' => 1,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^ERDF$/u',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'ERDF replace';
  $export['enrd_lag_database-esi_funds_og-erdf_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'enrd_lag_database-esi_funds_og-esf_replace';
  $feeds_tamper->importer = 'enrd_lag_database';
  $feeds_tamper->source = 'ESI Funds OG';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'ESF',
    'replace' => 'European Social Fund (ESF)',
    'case_sensitive' => 1,
    'word_boundaries' => 1,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^ESF$/u',
  );
  $feeds_tamper->weight = 3;
  $feeds_tamper->description = 'ESF replace';
  $export['enrd_lag_database-esi_funds_og-esf_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'enrd_lag_database-esif_programme-required';
  $feeds_tamper->importer = 'enrd_lag_database';
  $feeds_tamper->source = 'ESIF Programme';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Required field';
  $export['enrd_lag_database-esif_programme-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'enrd_lag_database-extended_profile-urldecode';
  $feeds_tamper->importer = 'enrd_lag_database';
  $feeds_tamper->source = 'Extended profile';
  $feeds_tamper->plugin_id = 'urldecode';
  $feeds_tamper->settings = array(
    'method' => 'raw',
    'function' => 'rawurldecode',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'URL Decode';
  $export['enrd_lag_database-extended_profile-urldecode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'enrd_lag_database-lag_code-enrd_lag_code_required';
  $feeds_tamper->importer = 'enrd_lag_database';
  $feeds_tamper->source = 'LAG code';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Required field';
  $export['enrd_lag_database-lag_code-enrd_lag_code_required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'enrd_lag_database-lag_email_address-enrd_lag_email_required';
  $feeds_tamper->importer = 'enrd_lag_database';
  $feeds_tamper->source = 'LAG email address';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Required field';
  $export['enrd_lag_database-lag_email_address-enrd_lag_email_required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'enrd_lag_database-lag_name-enrd_lag_name_required';
  $feeds_tamper->importer = 'enrd_lag_database';
  $feeds_tamper->source = 'LAG name';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Required field';
  $export['enrd_lag_database-lag_name-enrd_lag_name_required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'enrd_lag_database-lag_website-urldecode';
  $feeds_tamper->importer = 'enrd_lag_database';
  $feeds_tamper->source = 'LAG website';
  $feeds_tamper->plugin_id = 'urldecode';
  $feeds_tamper->settings = array(
    'method' => 'raw',
    'function' => 'rawurldecode',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'URL Decode';
  $export['enrd_lag_database-lag_website-urldecode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'enrd_lag_database-last_name-enrd_lag_manager_required';
  $feeds_tamper->importer = 'enrd_lag_database';
  $feeds_tamper->source = 'Last name';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Required field';
  $export['enrd_lag_database-last_name-enrd_lag_manager_required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'enrd_lag_database-last_name-rewrite';
  $feeds_tamper->importer = 'enrd_lag_database';
  $feeds_tamper->source = 'Last name';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '[first name] [last name]',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'First name and Last name concat.';
  $export['enrd_lag_database-last_name-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'enrd_lag_database-main_esi_fund-required';
  $feeds_tamper->importer = 'enrd_lag_database';
  $feeds_tamper->source = 'Main ESI Fund';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Required field';
  $export['enrd_lag_database-main_esi_fund-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'enrd_lag_database-origin-required';
  $feeds_tamper->importer = 'enrd_lag_database';
  $feeds_tamper->source = 'Origin';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Required field';
  $export['enrd_lag_database-origin-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'enrd_lag_database-published-default_value';
  $feeds_tamper->importer = 'enrd_lag_database';
  $feeds_tamper->source = 'Published';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => '1',
    'only_if_empty' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set imported LAG Feeds as published by default.';
  $export['enrd_lag_database-published-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'enrd_lag_database-street_1-enrd_lag_addr_treet1_required';
  $feeds_tamper->importer = 'enrd_lag_database';
  $feeds_tamper->source = 'Street 1';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Required field';
  $export['enrd_lag_database-street_1-enrd_lag_addr_treet1_required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'enrd_lag_database-zip_code-enrd_lag_addr_postal_required';
  $feeds_tamper->importer = 'enrd_lag_database';
  $feeds_tamper->source = 'Zip code';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Required field';
  $export['enrd_lag_database-zip_code-enrd_lag_addr_postal_required'] = $feeds_tamper;

  return $export;
}
