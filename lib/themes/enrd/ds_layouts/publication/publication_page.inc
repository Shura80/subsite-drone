<?php

/**
 * @file
 * Display Suite Publication page configuration.
 */

/**
 * The content type Publication page display configuration.
 *
 * @return array
 *   The array configuration.
 */
function ds_publication_page() {
  return array(
    'label' => t('Publication Page'),
    'regions' => array(
      'thumb' => t('Thumb'),
      'headline' => t('Headline'),
      'abstract' => t('Abstract'),
      'meta' => t('Metadata'),
      'side' => t('Sidebar'),
    ),
  );
}
