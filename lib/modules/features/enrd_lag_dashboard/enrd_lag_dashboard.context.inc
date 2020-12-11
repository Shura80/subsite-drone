<?php

/**
 * @file
 * enrd_lag_dashboard.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function enrd_lag_dashboard_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_lag_dashboard_tasks';
  $context->description = 'Shows a block to LAG contact mangers/contacts to manage their LAG.';
  $context->tag = 'ENRD LAG Dashboard';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        'enrd_lag_page' => 'enrd_lag_page',
        'enrd_cooperation_offer_page' => 'enrd_cooperation_offer_page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'enrd_lag_dashboard-enrd_menu_local_tasks' => array(
          'module' => 'enrd_lag_dashboard',
          'delta' => 'enrd_menu_local_tasks',
          'region' => 'sidebar_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('ENRD LAG Dashboard');
  t('Shows a block to LAG contact mangers/contacts to manage their LAG.');
  $export['enrd_lag_dashboard_tasks'] = $context;

  return $export;
}
