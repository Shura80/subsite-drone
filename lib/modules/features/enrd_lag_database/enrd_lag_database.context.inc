<?php

/**
 * @file
 * enrd_lag_database.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function enrd_lag_database_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_coop_offer_solr';
  $context->description = 'Custom context for the CLLD Partner Search Apache Solr page.';
  $context->tag = 'ENRD CLLD Partner Search Tool';
  $context->conditions = array(
    'apachesolr_page' => array(
      'values' => array(
        'partner_search' => 'partner_search',
        'partner_search_expired' => 'partner_search_expired',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'current_search-cooperation_offer' => array(
          'module' => 'current_search',
          'delta' => 'cooperation_offer',
          'region' => 'sidebar_right',
          'weight' => '0',
        ),
        'facetapi-lv4mqIW4XbHQtLWgB8VnZlOo9UwxJBtC' => array(
          'module' => 'facetapi',
          'delta' => 'lv4mqIW4XbHQtLWgB8VnZlOo9UwxJBtC',
          'region' => 'sidebar_right',
          'weight' => '7',
        ),
        'facetapi-vuFTk4sjk6T0FYbpgxOJBXYY7uLGxJO1' => array(
          'module' => 'facetapi',
          'delta' => 'vuFTk4sjk6T0FYbpgxOJBXYY7uLGxJO1',
          'region' => 'sidebar_right',
          'weight' => '6',
        ),
        'facetapi-p4MY34PdAPUmqnfn6N0QDeMqLLtj1opU' => array(
          'module' => 'facetapi',
          'delta' => 'p4MY34PdAPUmqnfn6N0QDeMqLLtj1opU',
          'region' => 'sidebar_right',
          'weight' => '5',
        ),
        'facetapi-eBEiqd0gNtjHczynUGe3dhpeKnK1ZCiR' => array(
          'module' => 'facetapi',
          'delta' => 'eBEiqd0gNtjHczynUGe3dhpeKnK1ZCiR',
          'region' => 'sidebar_right',
          'weight' => '11',
        ),
        'apachesolr_search-sort' => array(
          'module' => 'apachesolr_search',
          'delta' => 'sort',
          'region' => 'sidebar_right',
          'weight' => '20',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Custom context for the CLLD Partner Search Apache Solr page.');
  t('ENRD CLLD Partner Search Tool');
  $export['enrd_coop_offer_solr'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_cooperation_offer_page';
  $context->description = 'Custom context for Cooperation offer Nodes';
  $context->tag = 'ENRD CLLD Partner Search Tool';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'cooperation_offer' => 'cooperation_offer',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'enrd_lag_database-contact_this_lag_webform' => array(
          'module' => 'enrd_lag_database',
          'delta' => 'contact_this_lag_webform',
          'region' => 'sidebar_right',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Custom context for Cooperation offer Nodes');
  t('ENRD CLLD Partner Search Tool');
  $export['enrd_cooperation_offer_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_lag_page';
  $context->description = 'Custom context for LAG Nodes';
  $context->tag = 'ENRD LAG Database';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'lag' => 'lag',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'ds_extras-enrd_lag_logo' => array(
          'module' => 'ds_extras',
          'delta' => 'enrd_lag_logo',
          'region' => 'sidebar_right',
          'weight' => '-10',
        ),
        'ds_extras-enrd_lag_cooperation_details' => array(
          'module' => 'ds_extras',
          'delta' => 'enrd_lag_cooperation_details',
          'region' => 'sidebar_right',
          'weight' => '-9',
        ),
        'views-dd6d333086b989b0d6b49e3e8167712b' => array(
          'module' => 'views',
          'delta' => 'dd6d333086b989b0d6b49e3e8167712b',
          'region' => 'sidebar_right',
          'weight' => '-8',
        ),
        'ds_extras-enrd_lag_other_useful_info' => array(
          'module' => 'ds_extras',
          'delta' => 'enrd_lag_other_useful_info',
          'region' => 'sidebar_right',
          'weight' => '-7',
        ),
        'ds_extras-enrd_lag_extended_profile' => array(
          'module' => 'ds_extras',
          'delta' => 'enrd_lag_extended_profile',
          'region' => 'sidebar_right',
          'weight' => '-6',
        ),
        'enrd_notifications-enrd_notifications_lag_flag_link' => array(
          'module' => 'enrd_notifications',
          'delta' => 'enrd_notifications_lag_flag_link',
          'region' => 'sidebar_right',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Custom context for LAG Nodes');
  t('ENRD LAG Database');
  $export['enrd_lag_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_lag_solr';
  $context->description = 'Custom context for the LAG Database Apache Solr page.';
  $context->tag = 'ENRD LAG Database';
  $context->conditions = array(
    'apachesolr_page' => array(
      'values' => array(
        'lag_database' => 'lag_database',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'current_search-lag' => array(
          'module' => 'current_search',
          'delta' => 'lag',
          'region' => 'sidebar_right',
          'weight' => '0',
        ),
        'facetapi-3U1wlDVicbix6hf678mkaqn1WobD2vAE' => array(
          'module' => 'facetapi',
          'delta' => '3U1wlDVicbix6hf678mkaqn1WobD2vAE',
          'region' => 'sidebar_right',
          'weight' => '5',
        ),
        'facetapi-chzm32wg69J9Bb17hD1Kit5KWfmXk8Wn' => array(
          'module' => 'facetapi',
          'delta' => 'chzm32wg69J9Bb17hD1Kit5KWfmXk8Wn',
          'region' => 'sidebar_right',
          'weight' => '6',
        ),
        'facetapi-4KYHPqLILincKWUmrQ4sIT9DDNJ79F30' => array(
          'module' => 'facetapi',
          'delta' => '4KYHPqLILincKWUmrQ4sIT9DDNJ79F30',
          'region' => 'sidebar_right',
          'weight' => '7',
        ),
        'facetapi-9QA6DJwELFF3wMoSCm3Q01ZHHpPohCbm' => array(
          'module' => 'facetapi',
          'delta' => '9QA6DJwELFF3wMoSCm3Q01ZHHpPohCbm',
          'region' => 'sidebar_right',
          'weight' => '8',
        ),
        'facetapi-N8NI97A4HtQVahoPoHEsZnAopOIAoen4' => array(
          'module' => 'facetapi',
          'delta' => 'N8NI97A4HtQVahoPoHEsZnAopOIAoen4',
          'region' => 'sidebar_right',
          'weight' => '9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Custom context for the LAG Database Apache Solr page.');
  t('ENRD LAG Database');
  $export['enrd_lag_solr'] = $context;

  return $export;
}
