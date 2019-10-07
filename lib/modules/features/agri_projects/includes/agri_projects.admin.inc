<?php

/**
 * @file
 * agri_projects.admin.inc
 */

/**
 * Implements hook_form().
 */
function agri_projects_country_privacy_config_form($form, &$form_state) {

  $vocabulary = taxonomy_vocabulary_machine_name_load('core_geographical_area');
  $country_terms = taxonomy_get_tree($vocabulary->vid, 0, 1);
  $country_list = array();

  foreach ($country_terms as $country_term) {
    if ($country_term->name == 'Other') {
      continue;
    }

    $country_list[$country_term->tid] = $country_term->name;
  }

  $form['partners_privacy'] = array(
    '#type' => 'fieldset',
    '#title' => t('OG Project partners privacy'),
    '#description' => t('The countries selected will not show the "project partners" information on OG projects display.'),
  );

  $form['partners_privacy']['agri_projects_countries_privacy'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Countries'),
    '#options' => $country_list,
    '#default_value' => variable_get('agri_projects_countries_privacy', array()),
  );

  $form['#submit'][] = 'agri_projects_privacy_settings_form_submit';

  return system_settings_form($form);
}

/**
 * Custom form submission handler for agri_projects_country_privacy_config_form.
 *
 * Instruct Solr to mark Project nodes to be reindexed,
 * otherwise it does not recognise them as modified and does not process them.
 *
 * @param array $form
 *   The $form array to be manipulated.
 * @param array $form_state
 *   The $form_state array coming from submitted form.
 */
function agri_projects_privacy_settings_form_submit(array $form, array &$form_state) {
  module_load_include('inc', 'apachesolr', 'apachesolr.index');

  $env_id = apachesolr_default_environment();
  apachesolr_index_delete_index($env_id, 'node', 'project');
  apachesolr_index_mark_for_reindex($env_id, 'project');
}
