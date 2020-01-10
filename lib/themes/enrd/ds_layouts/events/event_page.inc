<?php

/**
 * @file
 * Display Suite Event page configuration.
 */

/**
 * The content type project page display configuration.
 *
 * @return array
 *   The array configuration.
 */
function ds_event_page() {
  return array(
    'label' => t('Event Page'),
    'regions' => array(
      'thumb' => t('Thumb'),
      'headline' => t('Headline'),
      'abstract' => t('Abstract'),
      'meta' => t('Metadata'),
    ),
  );
}
