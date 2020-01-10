<?php

/**
 * @file
 * enrd_sfr_pub.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function enrd_sfr_pub_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_sfr_pub_publication_cp';
  $context->description = 'Custom context for the Apache Solr page set up for the Subscription requests.';
  $context->tag = 'ENRD Publication Subscriptions forms';
  $context->conditions = array(
    'apachesolr_page' => array(
      'values' => array(
        'publications_elibrary' => 'publications_elibrary',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'enrd_sfr_pub-enrd_sfr_pub_cp' => array(
          'module' => 'enrd_sfr_pub',
          'delta' => 'enrd_sfr_pub_cp',
          'region' => 'sidebar_right',
          'weight' => '-20',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Custom context for the Apache Solr page set up for the Subscription requests.');
  t('ENRD Publication Subscriptions forms');
  $export['enrd_sfr_pub_publication_cp'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_sfr_pub_publication_ehd';
  $context->description = 'Custom context for Evaluation Publication nodes, Apache Solr page and Rural Evaluation News basic page, set up for Subscription requests.';
  $context->tag = 'ENRD Publication Subscriptions forms';
  $context->conditions = array(
    'apachesolr_page' => array(
      'values' => array(
        'evaluation_publications_elibrary' => 'evaluation_publications_elibrary',
      ),
    ),
    'node' => array(
      'values' => array(
        'publication_ehd' => 'publication_ehd',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'evaluation/publications/evaluation-helpdesks-publications-rural-evaluation-news' => 'evaluation/publications/evaluation-helpdesks-publications-rural-evaluation-news',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'enrd_sfr_pub-enrd_sfr_pub_ehd' => array(
          'module' => 'enrd_sfr_pub',
          'delta' => 'enrd_sfr_pub_ehd',
          'region' => 'sidebar_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Custom context for Evaluation Publication nodes, Apache Solr page and Rural Evaluation News basic page, set up for Subscription requests.');
  t('ENRD Publication Subscriptions forms');
  $export['enrd_sfr_pub_publication_ehd'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_sfr_pub_publications_hub_page';
  $context->description = 'Custom context for the Main Publications page.';
  $context->tag = 'ENRD Publication Subscriptions forms';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'publications' => 'publications',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'enrd_sfr_pub-enrd_sfr_pub_cp' => array(
          'module' => 'enrd_sfr_pub',
          'delta' => 'enrd_sfr_pub_cp',
          'region' => 'sidebar_right',
          'weight' => '1',
        ),
        'enrd_sfr_pub-enrd_sfr_pub_ehd' => array(
          'module' => 'enrd_sfr_pub',
          'delta' => 'enrd_sfr_pub_ehd',
          'region' => 'sidebar_right',
          'weight' => '5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Custom context for the Main Publications page.');
  t('ENRD Publication Subscriptions forms');
  $export['enrd_sfr_pub_publications_hub_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_sfr_pub_subscribe';
  $context->description = 'Sitewide menu displayed on the left sidebar.';
  $context->tag = 'ENRD Publication Subscriptions forms';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~node/add/*' => '~node/add/*',
        '~node/*/edit' => '~node/*/edit',
      ),
    ),
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-enrd-sfr-pub-subscribe' => array(
          'module' => 'menu',
          'delta' => 'menu-enrd-sfr-pub-subscribe',
          'region' => 'sidebar_left',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('ENRD Publication Subscriptions forms');
  t('Sitewide menu displayed on the left sidebar.');
  $export['enrd_sfr_pub_subscribe'] = $context;

  return $export;
}
