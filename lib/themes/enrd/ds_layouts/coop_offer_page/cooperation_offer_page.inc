<?php

/**
 * @file
 * Display Suite Cooperation offer page configuration.
 */

/**
 * The content type Cooperation offer page display configuration.
 *
 * @return array
 *   The array configuration.
 */
function ds_cooperation_offer_page() {
  return array(
    'label' => t('Cooperation offer page'),
    'regions' => array(
      'main' => t('Main'),
    ),
  );
}
