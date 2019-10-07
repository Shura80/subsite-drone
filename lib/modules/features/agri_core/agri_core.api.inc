<?php

/**
 * @file
 * Bunch of helper functions for the eip agri website.
 */

include_once 'agri_core.install.inc';

/**
 * Create a taxonomy term for a given vocabulary.
 *
 * @param string $vocabulary
 *   Vocabulary machine name.
 * @param string $name
 *   Name of the term to be created.
 * @param string $parent
 *   Name of the parent term, already existing
 *   in the specified vocabulary.
 * @param int $weight
 *   The weight of term.
 *
 * @return string
 *   Return value from Drupal's entity_save() API call,
 *   or FALSE if no vocabulary has been found.
 */
function _agri_core_api_create_term($vocabulary, $name, $parent = NULL, $weight = 0) {

  if ($vocabulary = taxonomy_vocabulary_machine_name_load($vocabulary)) {

    // Exit if term already exists for that vocabulary.
    if (db_select('taxonomy_term_data', 't')->fields('t', array('tid'))->condition('t.name', $name)->condition('t.vid', $vocabulary->vid)->execute()->fetch(PDO::FETCH_COLUMN)) {
      return FALSE;
    }

    $values = array();
    $values['vocabulary_machine_name'] = $vocabulary->machine_name;
    $values['vid'] = $vocabulary->vid;
    $values['name'] = $name;
    $values['weight'] = $weight;

    if ($parent) {
      $values['parent'] = (int) db_select('taxonomy_term_data', 't')->fields('t', array('tid'))->condition('t.name', $parent)->condition('t.vid', $vocabulary->vid)->execute()->fetch(PDO::FETCH_COLUMN);
    }

    $entity = entity_create('taxonomy_term', $values);
    return entity_save('taxonomy_term', $entity);
  }
  return FALSE;
}

/**
 * Creates field dependencies.
 *
 * @param array $ids
 *   A simple array containing tids or nids.
 *        array $fields
 *   A simple array containing fields machine names,
 *   one for the dependee field and one for the dependent one.
 *        string $entity
 *   Type of entities.
 *        string $bundle
 *   Field bundle.
 *        string $id
 *   Type of "id", tid or nid, basically.
 */
function _agri_core_field_dependencies(array $ids, $fields, $entity, $bundle, $id, $values_set = CONDITIONAL_FIELDS_DEPENDENCY_VALUES_WIDGET) {
  $values = '';

  // Create fields and dependencies.
  switch ($values_set) {

    case CONDITIONAL_FIELDS_DEPENDENCY_VALUES_WIDGET:
      foreach ($ids as $value) {
        $values[] = array($id => $value);
      }
      $dependency_options = array(
        'values_set' => $values_set,
        'grouping' => 'OR',
        'value_form' => $ids,
        'value' => $values,
      );
      break;

    case CONDITIONAL_FIELDS_DEPENDENCY_VALUES_OR:
      $dependency_options = array(
        'values_set' => $values_set,
        'grouping' => 'OR',
        'value_form' => NULL,
        'values' => $ids,
      );
      break;
  }

  $dependent_instance = field_info_instance($entity, $fields[1], $bundle);
  $dependee_instance = field_info_instance($entity, $fields[0], $bundle);
  conditional_fields_dependency_insert($dependee_instance['id'], $dependent_instance['id'], $dependency_options);
}

/**
 * Reset the weight of vocabulary terms.
 *
 * @param string $vocabulary
 *   The machine name of vocabulary.
 * @param string $function
 *   The function name that retrive the default terms order.
 */
function _agri_core_reset_taxonomy_default_order($vocabulary, $function) {
  if (function_exists($function)) {
    $default_terms = $function();

    foreach ($default_terms as $weight => $term_name) {
      $term_obj = taxonomy_get_term_by_name($term_name, $vocabulary);
      if (!empty($term_obj)) {
        $term_obj = reset($term_obj);
        $term_obj->weight = $weight;
        taxonomy_term_save($term_obj);
      }
    }
  }
}
