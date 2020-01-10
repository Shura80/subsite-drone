<?php

/**
 * @file
 * List of taxonomy terms to import into NRN Toolkit vocabularies.
 */

/**
 * Terms of ENRD Networking vocabulary.
 *
 * @return array
 *   Return an array of terms.
 */
function _enrd_nrn_toolkit_enrd_networking() {
  return array(
    'Running the NRNs',
    array(
      'Setting up the NRN',
      'NRN Operation',
      'NRN Self-assessment',
      'Networking added value',

    ),
    'NRN Objectives',
    array(
      'Increasing stakeholder involvement',
      'Improving RDP implementation',
      'Informing the broader public',
      'Fostering innovation',
    ),
    'NRN Tasks',
    array(
      'Collection of examples',
      'Thematic & analytical exchanges',
      'LAGs and cooperation',
      'Advisors & innovation support services',
      'Monitoring & evaluation findings',
      'Communication',
      'Contribution to the ENRD',
    ),
  );
}

/**
 * Array of ENRD Resource Type terms.
 */
function _enrd_nrn_toolkit_enrd_resource_type() {
  return array(
    'Event',
    'Article',
    'Publication',
    'Web page',
    'Presentation',
    'Good practice',
  );
}

/**
 * Helper function to create ENRD NRN Toolkit vocabularies and terms on install.
 *
 * @param string $machine_name
 *   The machine name of the vocabulary to create.
 *
 * @return mixed
 *   Return terms structure for the vocabulary.
 */
function _enrd_nrn_toolkit_taxonomies($machine_name) {
  $list_function = "_enrd_nrn_toolkit_$machine_name";
  if (function_exists($list_function)) {
    return $list_function();
  }
  else {
    return array();
  }
}
