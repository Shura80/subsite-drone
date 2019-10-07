<?php

/**
 * @file
 * agri_projects.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function agri_projects_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'projects-find-connect-splash-page';
  $context->description = 'Active only on Projects & Actions section front page';
  $context->tag = 'AGRI Projects';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'find-connect' => 'find-connect',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-projects_blocks-block_1' => array(
          'module' => 'views',
          'delta' => 'projects_blocks-block_1',
          'region' => 'content_top_left',
          'weight' => '-10',
        ),
        'views-projects_blocks-block_2' => array(
          'module' => 'views',
          'delta' => 'projects_blocks-block_2',
          'region' => 'content_top_right',
          'weight' => '-10',
        ),
        'views-projects_blocks-block' => array(
          'module' => 'views',
          'delta' => 'projects_blocks-block',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Projects');
  t('Active only on Projects & Actions section front page');
  $export['projects-find-connect-splash-page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'projects-needs-for-research-full-node';
  $context->description = 'Active on Needs for research from practice content types.';
  $context->tag = 'AGRI Projects';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'needs_for_research_from_practice' => 'needs_for_research_from_practice',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-agri_pages_side_menu' => array(
          'module' => 'menu_block',
          'delta' => 'agri_pages_side_menu',
          'region' => 'sidebar_left',
          'weight' => '-10',
        ),
      ),
    ),
    'breadcrumb' => 'find-connect/needs-for-research',
    'menu' => 'find-connect/needs-for-research',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Projects');
  t('Active on Needs for research from practice content types.');
  $export['projects-needs-for-research-full-node'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'projects-proj-full-node';
  $context->description = 'Active on Project content type.';
  $context->tag = 'AGRI Projects';
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
        'menu_block-agri_pages_side_menu' => array(
          'module' => 'menu_block',
          'delta' => 'agri_pages_side_menu',
          'region' => 'sidebar_left',
          'weight' => '-10',
        ),
      ),
    ),
    'breadcrumb' => 'find-connect/projects',
    'menu' => 'find-connect/projects',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Projects');
  t('Active on Project content type.');
  $export['projects-proj-full-node'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'projects-search';
  $context->description = 'Active on Projects search section';
  $context->tag = 'AGRI Projects';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'projects_indexed_search_sub_pages:page' => 'projects_indexed_search_sub_pages:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'search_api_saved_searches-core_node_index' => array(
          'module' => 'search_api_saved_searches',
          'delta' => 'core_node_index',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Projects');
  t('Active on Projects search section');
  $export['projects-search'] = $context;

  return $export;
}
