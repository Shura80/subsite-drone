<?php

/**
 * @file
 * Display Suite LAG profile page configuration.
 */

/**
 * The content type LAG page display configuration.
 *
 * @return array
 *   The array configuration.
 */
function ds_lag_page() {
  return array(
    'label' => t('LAG profile page'),
    'regions' => array(
      'headline' => t('Headline'),
      'main' => t('Main'),
      'contact' => t('Contact information'),
      'additional' => t('Additional information'),
      'funding' => t('LAG Funding'),
    ),
  );
}
