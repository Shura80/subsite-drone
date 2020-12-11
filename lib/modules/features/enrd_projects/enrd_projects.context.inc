<?php

/**
 * @file
 * enrd_projects.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function enrd_projects_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_projects_db_solr';
  $context->description = 'Custom context for the Projects Database Apache Solr page.';
  $context->tag = 'ENRD Projects Practice';
  $context->conditions = array(
    'apachesolr_page' => array(
      'values' => array(
        'projects_database' => 'projects_database',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'current_search-project' => array(
          'module' => 'current_search',
          'delta' => 'project',
          'region' => 'sidebar_right',
          'weight' => '-92',
        ),
        'facetapi-eSH6Rz1AhtKNFudKbiuFXt33nReNYY6M' => array(
          'module' => 'facetapi',
          'delta' => 'eSH6Rz1AhtKNFudKbiuFXt33nReNYY6M',
          'region' => 'sidebar_right',
          'weight' => '-91',
        ),
        'facetapi-Y1XZ30IV0NeXd6k9rlnteQ0V08eUKSDw' => array(
          'module' => 'facetapi',
          'delta' => 'Y1XZ30IV0NeXd6k9rlnteQ0V08eUKSDw',
          'region' => 'sidebar_right',
          'weight' => '-90',
        ),
        'facetapi-Yv0tO38XomOUjQ8DPgsO3t0NgyveMs2s' => array(
          'module' => 'facetapi',
          'delta' => 'Yv0tO38XomOUjQ8DPgsO3t0NgyveMs2s',
          'region' => 'sidebar_right',
          'weight' => '-89',
        ),
        'facetapi-ck9cOfyhGL4KwbTGZlGvzhkwus0CTTjr' => array(
          'module' => 'facetapi',
          'delta' => 'ck9cOfyhGL4KwbTGZlGvzhkwus0CTTjr',
          'region' => 'sidebar_right',
          'weight' => '-88',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Custom context for the Projects Database Apache Solr page.');
  t('ENRD Projects Practice');
  $export['enrd_projects_db_solr'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_projects_practice';
  $context->description = 'Custom context for Project & Practice Nodes';
  $context->tag = 'ENRD Projects Practice';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'project' => 'project',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'ds_extras-project_details' => array(
          'module' => 'ds_extras',
          'delta' => 'project_details',
          'region' => 'sidebar_right',
          'weight' => '-10',
        ),
      ),
    ),
    'menu' => array(
      0 => 'main-menu:projects-practice',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Custom context for Project & Practice Nodes');
  t('ENRD Projects Practice');
  $export['enrd_projects_practice'] = $context;

  return $export;
}
