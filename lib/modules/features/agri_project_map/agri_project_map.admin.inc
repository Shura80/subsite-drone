<?php

/**
 * @file
 * Administration forms for the AGRI Project Map feature.
 */

/**
 * Form construction for the NextEuropa Webtools settings form.
 */
function agri_project_map_settings_form() {
  $form = array();

  $form['agri_project_map_smartloader_prurl'] = array(
    '#type' => 'textfield',
    '#title' => t('Smartloader Protocol-Relative URL'),
    '#default_value' => variable_get('agri_project_map_smartloader_prurl', ''),
    '#description' => t("The URL of the webtools smartloader script. e.g. '//europa.eu/webtools/load.js'"),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}
