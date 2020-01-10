<?php

/**
 * @file
 * Display Suite Cooperation offer Search Result page configuration.
 */

/**
 * The Cooperation offer Search Result page display configuration.
 *
 * @return array
 *   The array configuration.
 */
function ds_cooperation_offer_search() {
  return array(
    'label' => t('Partner Search Results'),
    'regions' => array(
      'coop_lag_country' => t('Country'),
      'coop_offer_name' => t('Offer name'),
      'coop_offering_lag' => t('Offering LAG'),
      'coop_project_type' => t('Project type'),
      'coop_expiry_date' => t('Expiry date'),
    ),
    'image' => TRUE,
  );
}
