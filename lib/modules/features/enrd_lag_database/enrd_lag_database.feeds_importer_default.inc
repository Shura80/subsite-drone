<?php

/**
 * @file
 * enrd_lag_database.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function enrd_lag_database_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'enrd_lag_database';
  $feeds_importer->config = array(
    'name' => 'LAG Database',
    'description' => 'Import Basic Data into ENRD LAG Database content type.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'csv',
        'direct' => 0,
        'directory' => 'private://feeds/lag',
        'allowed_schemes' => array(
          'public' => 'public',
          'private' => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ';',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'LAG code',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'LAG code',
            'target' => 'field_enrd_lag_code',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'LAG name',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Origin',
            'target' => 'field_enrd_lag_country',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Country (classification)',
            'target' => 'field_tax_country',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'ESIF Country',
            'target' => 'field_enrd_lag_country',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Main ESI Fund',
            'target' => 'field_enrd_main_esi_fund',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'ESI Funds OG',
            'target' => 'og_group_ref:label',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'ESIF Programme',
            'target' => 'field_enrd_esif_programme_hierarchical',
            'hierarchy_separator' => '>',
            'auto_create_terms' => 0,
            'save_term_lineage' => 0,
          ),
          9 => array(
            'source' => 'Street 1',
            'target' => 'field_enrd_lag_manager_address:thoroughfare',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Street 2',
            'target' => 'field_enrd_lag_manager_address:premise',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Zip code',
            'target' => 'field_enrd_lag_manager_address:postal_code',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'City',
            'target' => 'field_enrd_lag_manager_address:locality',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'Country',
            'target' => 'field_enrd_lag_manager_address:country',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'Municipalities covered',
            'target' => 'field_enrd_lag_geo_coverage',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'LAG email address',
            'target' => 'field_enrd_lag_email',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'First name',
            'target' => 'field_enrd_lag_manager_name',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'Last name',
            'target' => 'field_enrd_lag_manager_name',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'Email address',
            'target' => 'field_enrd_lag_manager_email',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => 'LAG website',
            'target' => 'field_enrd_lag_website:url',
            'unique' => FALSE,
          ),
          20 => array(
            'source' => 'Extended profile',
            'target' => 'field_enrd_lag_extended_profile:url',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 0,
        'bundle' => 'lag',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['enrd_lag_database'] = $feeds_importer;

  return $export;
}
