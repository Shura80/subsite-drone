<?php

/**
 * @file
 * Display Suite Project page configuration.
 */

/**
 * The content type project page display configuration.
 *
 * @return array
 *   The array configuration.
 */
function ds_project_page() {
  return array(
    'label' => t('Project page'),
    'regions' => array(
      'thumb' => t('Thumb'),
      'headline' => t('Headline'),
      'main' => t('Main'),
    ),
  );
}
