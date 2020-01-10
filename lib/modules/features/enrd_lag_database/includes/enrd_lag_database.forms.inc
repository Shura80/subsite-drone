<?php

/**
 * @file
 * Code for custom form validations.
 */

module_load_include('module', 'enrd_lag_database');

/**
 * Returns the 1st level term of ESIF Programme based on Main ESI Fund term.
 *
 * @param int $gid
 *   The group node id.
 *
 * @return array
 *   Returns an array with the term properties.
 */
function _enrd_lag_database_get_esif_programme_root($gid) {
  $terms = array();
  if ($node = node_load($gid)) {
    if ($fund_term = taxonomy_term_load($node->field_enrd_main_esi_fund[LANGUAGE_NONE][0]['tid'])) {
      $terms = taxonomy_get_term_by_name($fund_term->name, ENRD_LAG_DATABASE_ESIF_TAXONOMY);
    }
  }
  return $terms;
}

/**
 * Validation for field_enrd_esif_programme field based on ESIF Fund & Country.
 *
 * @param array $element
 *   Form element array.
 * @param array $form_state
 *   Form state array.
 */
function _enrd_lag_database_esif_programme_validate(array $element, array &$form_state) {

  // Skip validation if user cannot access the field.
  if ($element['#access'] == FALSE || user_access('skip lag country restriction')) {
    return;
  }

  // Catch a value for the ESIF Fund.
  $esif_tid = NULL;
  if ($form_state['values'][OG_AUDIENCE_FIELD][LANGUAGE_NONE][0]['default'] == '_none') {
    if (isset($form_state['values'][OG_AUDIENCE_FIELD][LANGUAGE_NONE][0]['admin'])) {
      $esif_tid = $form_state['values'][OG_AUDIENCE_FIELD][LANGUAGE_NONE][0]['admin'];
    }
  }
  else {
    $esif_tid = $form_state['values'][OG_AUDIENCE_FIELD][LANGUAGE_NONE][0]['default'];
  }

  $esif_fund_terms = _enrd_lag_database_get_esif_programme_root($esif_tid);
  $esif_fund_term = reset($esif_fund_terms);

  $country_label = $form_state['complete form']['field_enrd_lag_country'][LANGUAGE_NONE]['#options'][$form_state['values']['field_enrd_lag_country'][LANGUAGE_NONE]];

  if ($esif_fund_term) {
    $esif_countries = taxonomy_get_children($esif_fund_term->tid);

    $selected_country = NULL;
    foreach ($esif_countries as $esif_country) {
      if ($esif_country->name == $country_label) {
        $selected_country = $esif_country;
        break;
      }
    }

    if ($selected_country) {
      $esif_programmes = taxonomy_get_children($selected_country->tid);
      if (empty($esif_programmes)) {
        if ($element[LANGUAGE_NONE]['#value'] != '_none') {
          form_error($element, t("The current ESIF Fund and Country don't need an ESIF Programme."));
        }
      }
      else {
        if (!isset($esif_programmes[$element[LANGUAGE_NONE]['#value']])) {
          form_error($element, t('Select a valid ESIF Programme for the current ESIF Fund and Country.'));
        }
      }
    }
    else {
      form_error($element, t('Invalid selection of the ESIF Programme.'));
    }
  }
}

/**
 * Helper function that retrieves a list of European Union countries.
 *
 * @return array
 *   An array of options.
 */
function _enrd_lag_database_get_eu_countries_options() {
  $options = array();

  $terms = taxonomy_get_term_by_name('European Union', ENRD_LAG_DATABASE_COUNTRY_TAXONOMY);
  if (!empty($terms)) {
    foreach ($terms as $term) {
      $tree = taxonomy_get_tree($term->vid, $term->tid, 1);
      foreach ($tree as $term_obj) {
        $options[$term_obj->tid] = $term_obj->name;
      }
    }
  }
  return $options;
}

/**
 * Helper function retrieves LAG nodes by country.
 *
 * @param string $country
 *   tid of the Country term.
 *
 * @return array
 *   An array of options.
 */
function _enrd_lag_database_get_lag_list_options_by_country($country) {
  $options = array();

  if (!is_null($country)) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', ENRD_LAG_DATABASE_LAG_GROUP_NODE)
      ->fieldCondition('field_enrd_lag_country', 'tid', $country)
      ->propertyCondition('status', NODE_PUBLISHED);

    $domain = _enrd_lag_database_get_lag_domain();
    if (!user_access('skip lag country restriction')) {
      if ($domain['nsu']) {
        $query->fieldCondition('og_group_ref', 'target_id', $domain['esi_funds_og'], 'IN');
      }
      else {
        $query->entityCondition('entity_id', $domain['lags'], 'IN');
      }
    }
    $result = $query->execute();
  }

  if (isset($result['node'])) {
    $esi_funds_ogs = entity_load('node', array_keys($result['node']));
    foreach ($esi_funds_ogs as $nid => $esi_funds_og) {
      $options[$nid] = $esi_funds_og->title . ' (' . $esi_funds_og->field_enrd_lag_code[LANGUAGE_NONE][0]['value'] . ')';
    }
  }
  return $options;
}

/**
 * Helper function that retrives all Main ESI Funds OG group node.
 *
 * @return array
 *   Node list keyed per nid.
 */
function _enrd_lag_database_get_main_esi_fund_og_list() {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', ENRD_LAG_DATABASE_ESI_FUND_GROUP_NODE)
    ->propertyCondition('status', NODE_PUBLISHED);
  $result = $query->execute();

  $options = array();

  if (!empty($result['node'])) {
    $esi_funds_ogs = entity_load('node', array_keys($result['node']));

    foreach ($esi_funds_ogs as $nid => $esi_funds_og) {
      $options[$nid] = $esi_funds_og->title;
    }
  }
  return $options;
}

/**
 * AJAX form callback that selects right options for the LAG fields components.
 *
 * @return array
 *   Renderable array of the LAG_OG_GROUP_REF field.
 */
function _enrd_lag_database_lag_og_group_ref_ajax($form, &$form_state) {
  $form_state['rebuild'] = TRUE;
  return $form[ENRD_LAG_DATABASE_LAG_OG_GROUP_REF];
}
