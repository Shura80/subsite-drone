<?php

/**
 * @file
 * Drush integration for enrd_taxonomies.
 */

/**
 * Implements hook_drush_command().
 */
function enrd_taxonomies_drush_command() {
  $items = array();

  $items['enrd-taxonomies-add-parents'] = array(
    'aliases' => array('enrd-add-parents'),
    'callback' => 'drush_enrd_taxonomies_add_parents',
    'description' => 'Add term parent to existing term',
    'arguments' => array(
      'parent_name' => 'Name of the term parent.',
      'term_name' => 'Name of the orphan term.',
      'vocabolary_name' => 'The machine-name of vocabolary. Optional.',
    ),
  );

  $items['enrd-taxonomies-set-rdp'] = array(
    'description' => 'Set RDP taxonomy MS field and children terms as groups.',
    'aliases' => array('enrd-set-rdp'),
  );

  return $items;
}

/**
 * Set a term parent to another term.
 *
 * @param string $parent_name
 *   Name of the new parent term.
 * @param string $term_name
 *   Name of the term.
 * @param string $vocabolary_name
 *   Vocabolary machine-name.
 */
function drush_enrd_taxonomies_add_parents($parent_name = NULL, $term_name = NULL, $vocabolary_name = NULL) {

  if (!isset($parent_name) || !isset($term_name) || !isset($vocabolary_name)) {
    drush_log(dt('You need to set the correct arguments.'), 'error');
    return;
  }

  // Validate vocabolary machine name.
  if (isset($vocabolary_name)) {
    $vocabulary = taxonomy_vocabulary_machine_name_load($vocabolary_name);
    if ($vocabulary == FALSE) {
      drush_log(dt('Vocabolary not exists.'), 'error');
      return;
    }
  }

  // Validate term parent name.
  $term_parent = taxonomy_get_term_by_name($parent_name, $vocabolary_name);
  if (empty($term_parent)) {
    drush_log(dt('You need to set a term parent existing.'), 'error');
    return;
  }
  else {
    foreach ($term_parent as $tid_parent => $term_parent_obj) {
      $new_parent_tid = $tid_parent;
      $new_parent_name = $term_parent_obj->name;
    }
  }

  // Validate term name.
  $terms = taxonomy_get_term_by_name($term_name, $vocabolary_name);
  if (empty($terms)) {
    drush_log(dt('You need to set a term existing.'), 'error');
    return;
  }

  foreach ($terms as $tid => $term_obj) {

    $current_term_parents = taxonomy_get_parents($tid);
    foreach ($current_term_parents as $key => $value) {
      $current_parents[] = $key;
    }

    $current_parents[] = $new_parent_tid;

    $term_obj->parent = $current_parents;
    taxonomy_term_save($term_obj);

    drush_log(dt('Add parent @new_parent_name to term @term_obj_name.', array('@new_parent_name' => $new_parent_name, '@term_obj_name' => $term_obj->name)), 'success');
  }
}

/**
 * Set RDP MS field and children terms as OG groups.
 */
function drush_enrd_taxonomies_set_rdp() {
  _enrd_taxonomies_save_rdp();
}
