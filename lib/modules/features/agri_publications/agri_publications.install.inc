<?php

/**
 * @file
 * Functions needed by the agri_publications feature.
 */

/**
 * A function to return an array of strings used to populate a vocabulary.
 *
 * @return array
 *   Array of strings.
 */
function _agri_publications_get_default_publication_type_terms() {
  return array(
    'Study',
    'Report',
    'Brochure',
    'Book',
    'EIP-AGRI document',
    'Factsheet',
    'Magazine',
    'Good-practice paper',
    'Article',
  );
}

/**
 * Set administrative permissions on publication_type vocabulary.
 */
function _agri_publications_set_permissions() {
  $voc = taxonomy_vocabulary_machine_name_load('publication_type');
  $roles[] = user_role_load_by_name('editor');
  $roles[] = user_role_load_by_name('administrator');

  foreach ($roles as $role) {
    user_role_grant_permissions($role->rid, array(
      'delete terms in ' . $voc->vid,
      'edit terms in ' . $voc->vid,
    ));
  }
}
