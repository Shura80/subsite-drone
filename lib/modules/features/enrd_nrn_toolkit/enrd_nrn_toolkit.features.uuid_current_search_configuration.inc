<?php

/**
 * @file
 * enrd_nrn_toolkit.features.uuid_current_search_configuration.inc
 */

/**
 * Implements hook_uuid_features_default_current_search_configurations().
 */
function enrd_nrn_toolkit_uuid_features_default_current_search_configurations() {
  $current_search_configurations = array();

  $current_search_configurations[] = array(
    'delta' => 'nrn_toolkit',
    'searcher' => 'apachesolr@solr',
  );
  return $current_search_configurations;
}
