<?php

/**
 * @file
 * File enrd_lag_dashboard.admin.inc.
 */

/**
 * Custom admin form to configure user redirects.
 */
function enrd_lag_dashboard_redirect_form($form, &$form_state) {

  $form['enrd_lag_dashboard_redirect'] = [
    '#type' => 'fieldset',
    '#title' => t('Configure User login redirects'),
    '#description' => t('This form is used to configure the Dashboard where a LAG user is redirected after login. Depending on user role, the redirection can be towards LAG Dashboard, My-LAGS or a more generic site path if users has no LAG role assigned.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  ];

  $form['enrd_lag_dashboard_redirect']['enrd_lag_dashboard_nsu_redirect'] = [
    '#type' => 'textfield',
    '#default_value' => variable_get('enrd_lag_dashboard_nsu_redirect', ENRD_LAG_DASHBOARD_NSU_REDIRECT),
    '#description' => t('Path of Dashboard for NSU Managers. The dashboard contains all LAGs and Cooperation offers for the country the National Manager belongs to.'),
    '#title' => t('NSU Managers'),
  ];

  $form['enrd_lag_dashboard_redirect']['enrd_lag_dashboard_lag_redirect'] = [
    '#type' => 'textfield',
    '#default_value' => variable_get('enrd_lag_dashboard_lag_redirect', ENRD_LAG_DASHBOARD_LAG_REDIRECT),
    '#description' => t('Path of Dashboard for LAG users. This dashboard contains all LAGs and Cooperation offers that a LAG member is allowed to moderate or ask for moderation.'),
    '#title' => t('LAG Managers / LAG Contacts'),
  ];

  $form['enrd_lag_dashboard_redirect']['enrd_lag_dashboard_common_redirect'] = [
    '#type' => 'textfield',
    '#default_value' => variable_get('enrd_lag_dashboard_common_redirect', '<front>'),
    '#description' => t('Path of redirect page for all other users (Not member of any LAG).'),
    '#title' => t('Non LAG members'),
  ];

  return system_settings_form($form);
}
