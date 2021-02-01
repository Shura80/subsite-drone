<?php

/**
 * @file
 * enrd_ruralstory.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function enrd_ruralstory_taxonomy_default_vocabularies() {
  return array(
    'enrd_ruralstory_topics' => (object) array(
      'name' => 'ENRD Rural Story Topics',
      'machine_name' => 'enrd_ruralstory_topics',
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
