<?php

/**
 * @file
 * File for batch import functions.
 */

/**
 * Callback for batch process.
 *
 * @param string $term_name
 *   The term name that processing.
 * @param array $term_parent
 *   The term(s) parent.
 */
function agri_core_batch_add_op_callback($term_name, array $term_parent) {

  global $language;

  $voc = taxonomy_vocabulary_machine_name_load('tags');
  $parents = array();

  foreach ($term_parent as $tid_parent) {
    $parents[] = $tid_parent;
  }

  $new_term = new stdClass();
  $new_term->name = $term_name;
  $new_term->vid = $voc->vid;
  $new_term->parent = $parents;
  $new_term->language = $language->language;
  $new_term->format = 'plain_text';
  taxonomy_term_save($new_term);
  drush_print('Added term: ' . $term_name);
}

/**
 * Callback for batch process.
 *
 * @param string $term_name
 *   The term name that processing.
 * @param array $term_parent
 *   The term(s) parent.
 */
function agri_core_batch_edit_op_callback($term_name, array $term_parent) {
  global $language;

  $terms = taxonomy_get_term_by_name($term_name, 'tags');

  foreach ($terms as $term_obj) {
    if ($term_name == $term_obj->name) {
      $term_obj->parent = $term_parent;
      $term_obj->language = $language->language;
      taxonomy_term_save($term_obj);
      drush_print('Updated term: ' . $term_name);
    }
  }
}

/**
 * Batch finished callback.
 *
 * @param bool $success
 *   TRUE of FALSE.
 * @param array $results
 *   Optional array.
 * @param array $operations
 *   Operations array.
 */
function agri_core_batch_finished_callback($success, array $results, array $operations) {

  if ($success) {
    drush_print('End process.');
  }
  else {
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments',
      array(
        '%error_operation' => $error_operation[0],
        '@arguments' => print_r($error_operation[1], TRUE),
      )
    );
    drush_log($message, 'error');
  }

}
