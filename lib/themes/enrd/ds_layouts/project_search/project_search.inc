<?php

/**
 * @file
 * Display Suite Project Search Result page configuration.
 */

/**
 * The Project Search Result page display configuration.
 *
 * @return array
 *   The array configuration.
 */
function ds_project_search() {
  return array(
    'label' => t('Project Search Results'),
    'regions' => array(
      'thumb' => t('Thumb'),
      'headline' => t('Headline'),
      'abstract' => t('Abstract'),
      'meta' => t('Metadata'),
    ),
  );
}
