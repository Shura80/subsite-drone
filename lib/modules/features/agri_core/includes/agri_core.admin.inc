<?php

/**
 * @file
 * agri_core.admin.inc
 */

/**
 * Implements hook_form().
 */
function agri_core_brexit_disclaimer_form($form, &$form_state) {
  $brexit_disclaimer = variable_get('agri_core_brexit_disclaimer', array(
    'value' => AGRI_CORE_BREXIT_DISCLAIMER,
    'format' => 'full_html',
  ));

  $form['agri_core_brexit_visibility'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Brexit Disclaimer'),
    '#default_value' => variable_get('agri_core_brexit_visibility', FALSE),
    '#return_value' => TRUE,
  );
  $form['agri_core_brexit_disclaimer'] = array(
    '#type' => 'text_format',
    '#title' => t('Displayed text'),
    '#description' => t('The text specified will be be shown in specific areas of the website.'),
    '#format' => $brexit_disclaimer['format'],
    '#default_value' => $brexit_disclaimer['value'],
  );

  $form['#submit'][] = 'agri_core_brexit_disclaimer_form_submit';

  return system_settings_form($form);
}

/**
 * Custom form submission handler for agri_core_brexit_disclaimer_form.
 *
 * Display Varnish drupal_set_message() for the admin user.
 *
 * @param array $form
 *   The $form array to be manipulated.
 * @param array $form_state
 *   The $form_state array coming from submitted form.
 */
function agri_core_brexit_disclaimer_form_submit(array $form, array &$form_state) {
  if (module_exists('nexteuropa_varnish')) {
    drupal_set_message(t('Remember to <a href="!url">clear the Varnish cache</a>!',
      array('!url' => url('admin/config/system/nexteuropa-varnish'))
    ));
  }
}

/**
 * Form construction for the NextEuropa Webtools settings form.
 */
function agri_core_webtools_settings_form() {
  $form = array();

  $form['agri_core_webtools_smartloader_prurl'] = array(
    '#type' => 'textfield',
    '#title' => t('Smartloader Protocol-Relative URL'),
    '#default_value' => variable_get('agri_core_webtools_smartloader_prurl', AGRI_CORE_WEBTOOLS_SMARTLOADER_PRURL),
    '#description' => t("The URL of the webtools smartloader script. e.g. '!default'", array('!default' => AGRI_CORE_WEBTOOLS_SMARTLOADER_PRURL)),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}
