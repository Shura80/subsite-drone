<?php

/**
 * @file
 * agri_events.install.inc
 */

/**
 * Implements hook__post_features_enable_feature().
 */
function agri_events_post_features_enable_feature($component) {
  if ($component == 'features_api') {

    // Grab list of views that are already disabled
    // and Calendar exported view.
    $views_status = variable_get('views_defaults', array());
    foreach (array('calendar') as $view_name) {
      $views_status[$view_name] = TRUE;
    }

    // Reset the variable with the new list and empty cache.
    variable_set('views_defaults', $views_status);
    if (function_exists('views_invalidate_cache')) {
      views_invalidate_cache();
    }
  }
}
