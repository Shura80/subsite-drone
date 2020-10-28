<?php

/**
 * @file
 * File enrd_lag_dashboard.nsu_admin.inc.
 */

/**
 * Form to add NSU users.
 */
function enrd_lag_dashboard_add_nsu_form() {

  // Force the title page to the local action menu name.
  $item = menu_get_item();
  drupal_set_title($item['title_callback']($item['title']));

  $search_description = t('Search for an existing ENRD website user by full name, email or username.');
  $admin_msg = $search_description . ' ' . t('Note: adding a blocked user implicates its activation.');
  $standard_msg = $search_description . ' ' . t('Note: blocked users cannot be added. Please contact the LAG webmaster to request activation.');

  $form['username'] = array(
    '#type' => 'textfield',
    '#title' => t('User'),
    '#description' => user_access('activate enrd users') ? $admin_msg : $standard_msg,
    '#maxlength' => 60,
    '#autocomplete_path' => 'enrd/user/autocomplete/all',
    '#required' => TRUE,
    '#element_validate' => array('_enrd_lag_dashboard_user_validate'),
  );

  $form['eu_countries'] = array(
    '#type' => 'select',
    '#title' => t('Country'),
    '#description' => t('Type the name of a country to display all available options. This selection will restrict the management of LAGs of a specific country.'),
    '#options' => _enrd_lag_database_get_eu_countries_options(),
    '#required' => TRUE,
    '#chosen' => TRUE,
  );

  $form['esi_funds_og'] = array(
    '#type' => 'checkboxes',
    '#title' => t('ESI Fund(s)'),
    '#description' => t('This selection will restrict the management of LAGs of one or more specific ESI Funds.'),
    '#options' => _enrd_lag_database_get_main_esi_fund_og_list(),
    '#required' => TRUE,
    '#default_value' => drupal_map_assoc(array_keys(_enrd_lag_database_get_main_esi_fund_og_list())),
  );

  $form['send_email'] = array(
    '#type' => 'checkbox',
    '#title' => t('Send an e-mail'),
    '#description' => t('Notify the user that she/he has been successfully added.'),
    '#default_value' => TRUE,
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add user'),
    '#submit' => array('enrd_lag_dashboard_add_nsu_user_submit'),
  );

  $form['actions']['cancel'] = array(
    '#markup' => l(t('Cancel'), 'lag-dashboard/users/nsu'),
  );

  return $form;
}

/**
 * Custom submit function for the add user action button.
 *
 * @param mixed $form
 *   Drupal form array.
 * @param mixed $form_state
 *   Drupal form state array.
 */
function enrd_lag_dashboard_add_nsu_user_submit($form, &$form_state) {
  $user_to_add = $form_state['values']['username'];
  $esi_funds_og = node_load_multiple($form_state['values']['esi_funds_og']);
  $country = taxonomy_term_load($form_state['values']['eu_countries']);
  $send_email = $form_state['values']['send_email'];

  // Add National Manager to group and country.
  $add_result = _enrd_lag_dashboard_add_national_manager($user_to_add, $country, $esi_funds_og, ENRD_LAG_DATABASE_NATIONAL_MANAGER_ROLE);

  // Redirect only if user has been added.
  if ($add_result) {
    // Redirect to NSU users list in positive case.
    $form_state['redirect'] = 'lag-dashboard/users/nsu';

    // Send e-mail only if checkbox is checked.
    if ($send_email) {
      // Invoke rules action: send e-mail to newly added National manager.
      if (module_exists('rules')) {
        $user_to_notify = user_load_by_name($user_to_add);
        rules_invoke_component(ENRD_LAG_DASHBOARD_SEND_EMAIL_NSU, $user_to_notify);
      }
    }
  }
  else {
    // Keep entered data.
    $form_state['rebuild'] = TRUE;
  }
}

/**
 * Add a National Manager to the ESI Funds and set the user country.
 *
 * @param mixed $user_param
 *   User to be added.
 * @param mixed $country
 *   The user country.
 * @param mixed $esi_funds_og_nodes
 *   The ESI Fund nodes.
 * @param string $og_role
 *   OG role to assign.
 *
 * @return bool
 *   Return TRUE if user is active.
 */
function _enrd_lag_dashboard_add_national_manager($user_param, $country, $esi_funds_og_nodes, $og_role = ENRD_LAG_DATABASE_NATIONAL_MANAGER_ROLE) {
  if ($user = user_load_by_name($user_param)) {

    // Check if user is blocked & current user can activate.
    if (user_is_blocked($user->name) !== FALSE && user_access('activate enrd users')) {
      // Activate user.
      user_user_operations_unblock([$user->uid]);
    }

    // Add "Country" field to User.
    $wrapper = entity_metadata_wrapper('user', $user);
    $wrapper->field_enrd_lag_country->set($country);
    $wrapper->save();

    $esi_funds_ogs = [];

    // Add the user to the group(s).
    foreach ($esi_funds_og_nodes as $esi_fund_node) {
      og_group('node', $esi_fund_node->nid, [
        'entity type' => 'user',
        'entity' => $user,
        'membership type' => OG_MEMBERSHIP_TYPE_DEFAULT,
        'field_name' => 'og_user_node',
      ]);

      // Assign the OG role.
      if ($role = multisite_config_service('og')->getOgRole('node', $esi_fund_node->type, $og_role)) {
        og_role_grant('node', $esi_fund_node->nid, $user->uid, $role->rid);
      }

      array_push($esi_funds_ogs, $esi_fund_node->title);
    }

    $esi_funds_og_titles = implode(', ', $esi_funds_ogs);
    drupal_set_message(t('User: !name has been added as NSU of the Fund(s): %esi_funds_og and country: %country.', [
      '!name' => theme('username', [
        'account' => $user,
      ]),
      '%esi_funds_og' => $esi_funds_og_titles,
      '%country' => $country->name,
    ]));

    return TRUE;
  }
  else {
    drupal_set_message(t('User: "!name" does not exist.', ['!name' => $user_param]), 'error');
  }

  return FALSE;
}

/**
 * Validate function for the "User" field.
 *
 * @param array $element
 *   Drupal form element array.
 * @param array $form_state
 *   Drupal form_state array.
 */
function _enrd_lag_dashboard_user_validate(array $element, array &$form_state) {
  // Check that field is not empty.
  if (!empty($form_state['values']['username'])) {
    $user = user_load_by_name($form_state['values']['username']);
    $user_is_blocked = !empty($user) && user_is_blocked($user->name) !== FALSE;

    // Check if user is blocked & current user can't activate.
    if ($user_is_blocked && !user_access('activate enrd users')) {
      form_error($element, t('User "!name (@username)" is blocked. Please contact the LAG webmaster to request activation.', [
        '!name' => theme('username', array(
          'account' => $user,
          'nolink' => TRUE,
        )),
        '@username' => $user->name,
      ]));
    }
  }
}
