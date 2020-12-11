<?php

/**
 * @file
 * Adds an option to taxonomy facets to sort by term weight.
 */

/**
 * Tests whether a field is a term reference field.
 *
 * @param array $facet
 *   The facet definition as returned by facetapi_facet_load().
 *
 * @return bool
 *   TRUE if the field is a term reference field.
 */
function _enrd_mastermind_facetapi_taxonomy_sort_is_term_reference_field(array $facet) {

  if (isset($facet['field api name'])) {
    $field_info = field_info_field($facet['field api name']);
    if ($field_info) {
      // Handling Term-Reference fields.
      if ('taxonomy_term_reference' == $field_info['type']) {
        return TRUE;
      }

      // Handling Entity-Reference fields.
      if ('entityreference' == $field_info['type']) {
        return ('taxonomy_term' == $field_info['settings']['target_type']);
      }
    }
  }

  // SearchAPI allows to define Aggregated and Combined fields, that are virtual
  // fields, thus not available as a standard field to field_info_field() call.
  if (isset($facet['field type']) && ('taxonomy_term' == $facet['field type'])) {
    // For Search API, fall back to the field type key.
    // @see http://drupal.org/node/1377734
    return TRUE;
  }

  return FALSE;
}

/**
 * Implements hook_facetapi_facet_info_alter().
 */
function enrd_mastermind_facetapi_facet_info_alter(array &$facet_info, array $searcher_info) {
  foreach ($facet_info as $name => $facet) {
    // Only act on taxonomy term reference fields.
    if (_enrd_mastermind_facetapi_taxonomy_sort_is_term_reference_field($facet)) {
      $facet_info[$name]['alter callbacks'][] = '_enrd_mastermind_facetapi_taxonomy_sort_add_taxonomy_weights';
    }
  }
}

/**
 * Alter callback that adds taxonomy weights to render array.
 *
 * @param array $build
 *   The render array to display.
 * @param \FacetapiAdapter $adapter
 *   FacetapiAdapter adapter instance.
 */
function _enrd_mastermind_facetapi_taxonomy_sort_add_taxonomy_weights(array &$build, FacetapiAdapter $adapter) {
  foreach (taxonomy_term_load_multiple(array_keys($build)) as $tid => $term) {
    // If term has multilingual content managed by entity_translation.module,
    // and title.module is used to replace it's $term->name field with trans-
    // lations, and if the current display language isn't the term's original
    // language, let's get original language value for term->name field.
    // This will This use the same logic as the taxonomy module to sort terms.
    if (isset($term->translations) && module_exists('title') && isset($term->name_original)) {
      global $language;
      if ($term->translations->original != $language->language) {
        $term->name = $term->name_original;
      }
    }
    // Save weight and name (for proper sort like in core, we need both)
    $build[$tid]['#taxonomy_weight'] = $term->weight;
    $build[$tid]['#taxonomy_name'] = $term->name;
  }
}

/**
 * Implements hook_facetapi_sort_info().
 */
function enrd_mastermind_facetapi_sort_info() {
  $sorts = array();

  $sorts['taxonomy_weight'] = array(
    'label' => t('Taxonomy weight'),
    'callback' => '_enrd_mastermind_facetapi_taxonomy_sort_sort_taxonomy',
    'description' => t('Sort by the taxonomy term weight.'),
    'requirements' => array('_enrd_mastermind_facetapi_taxonomy_sort_is_taxonomy_facet' => TRUE),
    'weight' => -40,
  );

  return $sorts;
}

/**
 * Checks whether the facet indexes taxonomy terms.
 *
 * @param array $realm
 *   The realm definition as returned by facetapi_realm_load().
 * @param array $facet
 *   The facet definition as returned by facetapi_facet_load().
 * @param bool $option
 *   If TRUE, the the requirements will pass if the facet indexes taxonomy
 *   terms. If FALSE, the facet must NOT index taxonomy terms in order to pass
 *   the requirements.
 *
 * @return bool
 *   TRUE if the hierarchical status matches $option, FALSE otherwise.
 */
function _enrd_mastermind_facetapi_taxonomy_sort_is_taxonomy_facet(array $realm, array $facet, $option) {
  $is_taxonomy_facet = _enrd_mastermind_facetapi_taxonomy_sort_is_term_reference_field($facet);
  return ($option) ? $is_taxonomy_facet : !$is_taxonomy_facet;
}

/**
 * Sorts by taxonomy weight + name consistency with core taxonomy term sorting.
 *
 * Takes two term arrays as parameters to compare their weights and, in case
 * of equal weights, compares term names to determine sort order.
 *
 * @param array $term_a
 *   The first term array for the comparison of weight and name.
 * @param array $term_b
 *   The first term array for the comparison of weight and name.
 *
 * @return int
 *   Returns value of the term weight/name comparison.
 */
function _enrd_mastermind_facetapi_taxonomy_sort_sort_taxonomy(array $term_a, array $term_b) {
  $a_count = (isset($term_a['#taxonomy_weight'])) ? $term_a['#taxonomy_weight'] : 0;
  $b_count = (isset($term_b['#taxonomy_weight'])) ? $term_b['#taxonomy_weight'] : 0;
  if ($a_count == $b_count) {
    $a_name = (isset($term_a['#taxonomy_name'])) ? $term_a['#taxonomy_name'] : 0;
    $b_name = (isset($term_b['#taxonomy_name'])) ? $term_b['#taxonomy_name'] : 0;
    if ($a_name == $b_name) {
      return 0;
    }
    else {
      return ($a_name < $b_name) ? -1 : 1;
    }
  }
  return ($a_count < $b_count) ? -1 : 1;
}
