<?php

/**
 * @file
 * Display Suite NRN page configuration.
 */

/**
 * The NRN Toolkit search page display configuration.
 *
 * @return array
 *   The array configuration.
 */
function ds_nrn_page() {
  return array(
    'label' => t('NRN Toolkit Page'),
    'regions' => array(
      'thumb' => t('Thumb'),
      'headline' => t('Headline'),
      'abstract' => t('Abstract'),
      'meta' => t('Metadata'),
      'nrn_title' => t('NRN Title'),
      'nrn_description' => t('NRN Description'),
    ),
  );
}
