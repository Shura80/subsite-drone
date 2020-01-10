<?php

/**
 * @file
 * Provides support for the Views module.
 */

/**
 * Implements hook_views_plugins().
 */
function enrd_lag_dashboard_views_plugins() {
  return array(
    'access' => array(
      'esi_fund_context' => array(
        'title' => t('LAG DB permissions'),
        'handler' => 'enrd_lag_dashboard_plugin_access_esi_fund_perm',
        'uses options' => TRUE,
      ),
    ),
  );
}
