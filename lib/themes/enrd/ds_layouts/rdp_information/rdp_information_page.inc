<?php

/**
 * @file
 * Display Suite RDP information page configuration.
 */

/**
 * The content type RDP information page display configuration.
 *
 * @return array
 *   The array configuration.
 */
function ds_rdp_information_page() {
  return array(
    'label' => t('RDP information Page'),
    'regions' => array(
      'headline' => t('Headline'),
      'introductory_text' => t('Introductory text'),
      'partnership_agreement' => t('Partnership Agreement'),
      'rdp_documents' => t('RDP documents'),
      'partnership_agreement_docs' => t('Partnership Agreement documents'),
      'nrn_information' => t('NRN Information'),
      'nrn_image' => t('NRN Image'),
      'managing_authority' => t('Managing Authority'),
      'paying_agency' => t('Paying Agency'),
      'region' => t('Region'),
      'main' => t('Main'),
    ),
  );
}
