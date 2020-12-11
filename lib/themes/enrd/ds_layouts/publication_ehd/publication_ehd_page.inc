<?php

/**
 * @file
 * Display Suite Evaluation Publication page configuration.
 */

/**
 * The content type Evaluation Publication page display configuration.
 *
 * @return array
 *   The array configuration.
 */
function ds_publication_ehd_page() {
  return array(
    'label' => t('Evaluation Publication Page'),
    'regions' => array(
      'thumb' => t('Thumb'),
      'headline' => t('Headline'),
      'abstract' => t('Abstract'),
      'meta' => t('Metadata'),
    ),
  );
}
