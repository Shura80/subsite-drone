<?php

/**
 * @file
 * enrd_publications.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function enrd_publications_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_evaluation_publications_page';
  $context->description = 'Custom context for Evaluation Publications Nodes';
  $context->tag = 'ENRD Evaluation';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'publication_ehd' => 'publication_ehd',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => 'main-menu:evaluation/publications',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Custom context for Evaluation Publications Nodes');
  t('ENRD Evaluation');
  $export['enrd_evaluation_publications_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_evaluation_publications_solr';
  $context->description = 'Custom context for the Apache Solr page of the Evaluation eLibrary.';
  $context->tag = 'ENRD Evaluation';
  $context->conditions = array(
    'apachesolr_page' => array(
      'values' => array(
        'evaluation_publications_elibrary' => 'evaluation_publications_elibrary',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'current_search-publication_ehd' => array(
          'module' => 'current_search',
          'delta' => 'publication_ehd',
          'region' => 'sidebar_right',
          'weight' => '-10',
        ),
        'facetapi-pDGf0ja9fVckmRwJjpSIB351E6Vg3m1a' => array(
          'module' => 'facetapi',
          'delta' => 'pDGf0ja9fVckmRwJjpSIB351E6Vg3m1a',
          'region' => 'sidebar_right',
          'weight' => '-9',
        ),
        'facetapi-nxSf6iRUIm6EVWHuyxFs69u2p0HpSylz' => array(
          'module' => 'facetapi',
          'delta' => 'nxSf6iRUIm6EVWHuyxFs69u2p0HpSylz',
          'region' => 'sidebar_right',
          'weight' => '-8',
        ),
        'facetapi-ZELOyIOX1GA6Ep4MKWH3ZmJDkltvz8wj' => array(
          'module' => 'facetapi',
          'delta' => 'ZELOyIOX1GA6Ep4MKWH3ZmJDkltvz8wj',
          'region' => 'sidebar_right',
          'weight' => '-7',
        ),
        'facetapi-eSH6Rz1AhtKNFudKbiuFXt33nReNYY6M' => array(
          'module' => 'facetapi',
          'delta' => 'eSH6Rz1AhtKNFudKbiuFXt33nReNYY6M',
          'region' => 'sidebar_right',
          'weight' => '-5',
        ),
        'facetapi-tmf1t3xQRdCLpZ0F4qbAaRLsM41oTFkR' => array(
          'module' => 'facetapi',
          'delta' => 'tmf1t3xQRdCLpZ0F4qbAaRLsM41oTFkR',
          'region' => 'sidebar_right',
          'weight' => '-4',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Custom context for the Apache Solr page of the Evaluation eLibrary.');
  t('ENRD Evaluation');
  $export['enrd_evaluation_publications_solr'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_publications_page';
  $context->description = 'Custom context for Publications Nodes';
  $context->tag = 'ENRD Publications';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'publication' => 'publication',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => 'main-menu:publications/search',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Custom context for Publications Nodes');
  t('ENRD Publications');
  $export['enrd_publications_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_publications_solr';
  $context->description = 'Custom context for the Apache Solr page of the Publications eLibrary.';
  $context->tag = 'ENRD Publications';
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
        'current_search-publication' => array(
          'module' => 'current_search',
          'delta' => 'publication',
          'region' => 'sidebar_right',
          'weight' => '-10',
        ),
        'facetapi-uxS0xDfq1zxkcprNdcj7awud0tYrQx1i' => array(
          'module' => 'facetapi',
          'delta' => 'uxS0xDfq1zxkcprNdcj7awud0tYrQx1i',
          'region' => 'sidebar_right',
          'weight' => '-9',
        ),
        'facetapi-mVwG1aGiT7cN9N32Fs9rG0kA1LDhm1gk' => array(
          'module' => 'facetapi',
          'delta' => 'mVwG1aGiT7cN9N32Fs9rG0kA1LDhm1gk',
          'region' => 'sidebar_right',
          'weight' => '-8',
        ),
        'facetapi-ZENrjErqh30eLI81BlfE0v1khbnTj7zN' => array(
          'module' => 'facetapi',
          'delta' => 'ZENrjErqh30eLI81BlfE0v1khbnTj7zN',
          'region' => 'sidebar_right',
          'weight' => '-7',
        ),
        'facetapi-akHdBqiI8AS0rSWbxE0VtGHyoBFoqUgC' => array(
          'module' => 'facetapi',
          'delta' => 'akHdBqiI8AS0rSWbxE0VtGHyoBFoqUgC',
          'region' => 'sidebar_right',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Custom context for the Apache Solr page of the Publications eLibrary.');
  t('ENRD Publications');
  $export['enrd_publications_solr'] = $context;

  return $export;
}
