<?php

/**
 * @file
 * Display Suite Region field collection configuration.
 */

/**
 * The Region field collection display configuration.
 *
 * @return array
 *   The array configuration.
 */
function ds_rdp_information_region() {
  return array(
    'label' => t('RDP information Region'),
    'regions' => array(
      'headline' => t('Headline'),
      'introductory_text' => t('Introductory text'),
      'rdp_documents' => t('RDP documents'),
      'nrn_information' => t('NRN Information'),
      'nrn_image' => t('NRN Image'),
      'managing_authority' => t('Managing Authority'),
      'paying_agency' => t('Paying Agency'),
    ),
  );
}
