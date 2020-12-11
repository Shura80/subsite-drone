<?php

/**
 * @file
 * Display Suite LAG Search Result page configuration.
 */

/**
 * The LAG Search Result page display configuration.
 *
 * @return array
 *   The array configuration.
 */
function ds_lag_search() {
  return array(
    'label' => t('LAG Search Results'),
    'regions' => array(
      'lag_country' => t('Country'),
      'lag_name' => t('LAG name'),
      'lag_main_esi_fund' => t('Main ESI Fund'),
      'lag_esif_programme' => t('ESIF Programme'),
    ),
    'image' => TRUE,
  );
}
