<?php

/**
 * @file
 * enrd_nrn_toolkit.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function enrd_nrn_toolkit_taxonomy_default_vocabularies() {
  return array(
    'enrd_networking' => (object) array(
      'name' => 'ENRD Networking',
      'machine_name' => 'enrd_networking',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
      'base_i18n_mode' => 1,
      'base_language' => 'und',
      'entity_type' => 'taxonomy_vocabulary',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'enrd_resource_type' => (object) array(
      'name' => 'ENRD Resource Type',
      'machine_name' => 'enrd_resource_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
      'base_i18n_mode' => 1,
      'base_language' => 'und',
      'entity_type' => 'taxonomy_vocabulary',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
