<?php

/**
 * @file
 * Display Suite News page configuration.
 */

/**
 * The content type project page display configuration.
 *
 * @return array
 *   The array configuration.
 */
function ds_news_page() {
  return array(
    'label' => t('News Page'),
    'regions' => array(
      'thumb' => t('Thumb'),
      'headline' => t('Headline'),
      'abstract' => t('Abstract'),
      'meta' => t('Metadata'),
    ),
  );
}
