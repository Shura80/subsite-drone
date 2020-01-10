<?php

/**
 * @file
 * Display Suite NRN Profile page configuration.
 */

/**
 * The NRN Profiles page display configuration.
 *
 * @return array
 *   The array configuration.
 */
function ds_nrn_profiles_page() {
  return array(
    'label' => t('NRN Profile Page'),
    'regions' => array(
      'main' => t('Main'),
      'links' => t('Links'),
      'nsu_operation' => t('NSU Operation'),
      'side_right' => t('Sidebar right'),
    ),
  );
}
