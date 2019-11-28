<?php

/**
 * @file
 * agri_stakeholder.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function agri_stakeholder_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'agri-stakeholders-area';
  $context->description = '';
  $context->tag = 'AGRI Stakeholder';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'eip-agri-projects' => 'eip-agri-projects',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-7c38f6a3996d3b9b7016048f83918be7' => array(
          'module' => 'views',
          'delta' => '7c38f6a3996d3b9b7016048f83918be7',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-1dbf569dc9b6be812113e109aba84542' => array(
          'module' => 'views',
          'delta' => '1dbf569dc9b6be812113e109aba84542',
          'region' => 'content_right',
          'weight' => '-10',
        ),
        'views-778c714f89405a3f72cac5489a071dd2' => array(
          'module' => 'views',
          'delta' => '778c714f89405a3f72cac5489a071dd2',
          'region' => 'content_bottom_first',
          'weight' => '-10',
        ),
        'views-d9fc9c927f8096f499df1d8bc1f4a6bd' => array(
          'module' => 'views',
          'delta' => 'd9fc9c927f8096f499df1d8bc1f4a6bd',
          'region' => 'content_bottom_second',
          'weight' => '-10',
        ),
        'views-2a2427e2ddeae72339de69ef07a6114c' => array(
          'module' => 'views',
          'delta' => '2a2427e2ddeae72339de69ef07a6114c',
          'region' => 'content_bottom_third',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Stakeholder');
  $export['agri-stakeholders-area'] = $context;

  return $export;
}
