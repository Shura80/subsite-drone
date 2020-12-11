<?php

/**
 * @file
 * Display Suite Gallery page configuration.
 */

/**
 * The content type Gallery page display configuration.
 *
 * @return array
 *   The array configuration.
 */
function ds_gallery_page() {
  return array(
    'label' => t('Gallery Page'),
    'regions' => array(
      'headline' => t('Headline'),
      'main' => t('Main'),
    ),
  );
}
