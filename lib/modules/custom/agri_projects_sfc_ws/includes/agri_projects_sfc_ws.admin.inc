<?php

/**
 * @file
 * Admin settings for module AGRI SFC projects SOAP web service.
 */

define('AGRI_PROJECTS_SFC_WS_READ_PROJECT_EMPTY_QUERY', <<<XML
<read>
   <cci>
      <year></year>
      <targetArea></targetArea>
      <leadDg></leadDg>
      <budgetSource></budgetSource>
      <objectSubType></objectSubType>
      <sequence></sequence>
   </cci>
   <version></version>
   <workVersion></workVersion>
</read>
XML
);

/**
 * Implements hook_form().
 */
function agri_projects_sfc_ws_config_form($form, &$form_state) {

  $settings = variable_get('sfc_soap_ws', array());
  $last_time = variable_get('agri_projects_sfc_ws_last_time', 0);

  $status = TRUE;
  if (empty($settings)) {
    $status = FALSE;

    $conf['sfc_soap_ws'] = array(
      'host' => 'host',
      'local_cert' => 'Full path of the certificate',
      'local_cert_passphrase' => 'Passphrase of certificate if exist',
    );

    drupal_set_message(t('Please, set in your settings.php the following configuration: !init_message', array(
      '!init_message' => '<pre>$conf["sfc_soap_ws"] = ' . var_export($conf['sfc_soap_ws'], TRUE) . ';</pre>',
    )), 'warning');
  }

  $form['agri_projects_sfc_ws_enable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable SFC importer from web service.'),
    '#default_value' => variable_get('agri_projects_sfc_ws_enable', FALSE),
    '#disabled' => !$status,
  );

  $form['agri_projects_sfc_ws_reset_date'] = array(
    '#type' => 'checkbox',
    '#title' => t('Reset date of the last import'),
    '#description' => t('<b>WARNING!</b> All projects will be re-imported from the set date, creating new revisions to the already imported projects.'),
    '#disabled' => !$status,
  );

  $form['agri_projects_sfc_ws_last_time_date'] = array(
    '#type' => 'date_select',
    '#title' => t('Date of the last import'),
    '#description' => t('Set manually the date of the last import.'),
    '#default_value' => $last_time ? format_date($last_time, 'custom', 'Y-m-d H:i:s') : NULL,
    '#date_label_position' => 'within',
    '#date_timezone' => date_default_timezone(),
    '#states' => array(
      'visible' => array(
        ':input[name="agri_projects_sfc_ws_reset_date"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['sfc_ws_show_setting_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Saved settings'),
    '#collapsible' => FALSE,
  );

  $form['sfc_ws_show_setting_fieldset']['sfc_ws_show_setting'] = array(
    '#markup' => (!empty($settings) ? t('Host: !host', array(
      '!host' => l($settings['host'], $settings['host']),
    )) : t('No settings available.')),
    '#prefix' => '<div>',
    '#suffix' => '</div>',
  );

  $form['sfc_ws_show_setting_fieldset']['sfc_ws_show_cert_path'] = array(
    '#markup' => (!empty($settings) ? t('Cert: !cert', array(
      '!cert' => $settings['local_cert'],
    )) : t('No settings available.')),
    '#prefix' => '<div>',
    '#suffix' => '</div>',
  );

  $form['sfc_ws_show_setting_fieldset']['sfc_ws_show_cert_pass'] = array(
    '#markup' => 'Passphrase: ' . (!empty($settings['local_cert_passphrase']) ? t('Yes') : t('No')),
    '#prefix' => '<div>',
    '#suffix' => '</div>',
  );

  $form['sfc_ws_show_setting_fieldset']['sfc_ws_show_last_time'] = array(
    '#markup' => t('Last call to WS: %time', array(
      '%time' => ($last_time == 0) ? t('never') : format_date($last_time, 'custom', 'd M Y H:i:s'),
    )),
    '#prefix' => '<div>',
    '#suffix' => '</div>',
  );

  $queue = DrupalQueue::get('agri_projects_sfc_ws');
  $queue->createQueue();

  $form['sfc_ws_show_setting_fieldset']['queue_elements'] = array(
    '#type' => 'item',
    '#title' => t('Projects in queue'),
    '#markup' => $queue->numberOfItems(),
  );

  $form['actions']['sfc_ws_fill_queue'] = array(
    '#type' => 'submit',
    '#value' => t('Fill queue manually'),
    '#submit' => array('_agri_projects_sfc_ws_fill_queue_manually'),
    '#weight' => 99,
  );

  $form['actions']['sfc_ws_truncate_queue'] = array(
    '#type' => 'submit',
    '#value' => t('Truncate queue'),
    '#submit' => array('_agri_projects_sfc_ws_truncate_queue'),
    '#weight' => 99,
  );

  $form['#validate'] = array('agri_projects_sfc_ws_config_form_validate');
  $form['#submit'][] = 'agri_projects_sfc_ws_config_form_submit';
  return system_settings_form($form);

}

/**
 * Implements hook_form_validate().
 */
function agri_projects_sfc_ws_config_form_validate($form, $form_state) {
  $settings = variable_get('sfc_soap_ws', array());
  if (empty($settings)) {
    form_set_error('sfc_ws_show_setting_fieldset', t('No settings available.'));
  }
  else {
    if (fopen($settings['local_cert'], 'r') === FALSE) {
      form_set_error('agri_projects_sfc_ws_enable', t('The certificate is not available on the path %path', array(
        '%path' => $settings['local_cert'],
      )));
    }
    else {
      $passphrase = isset($settings['local_cert_passphrase']) ? $settings['local_cert_passphrase'] : '';
      $cert_path = 'file://' . $settings['local_cert'];
      if (openssl_pkey_get_private($cert_path, $passphrase) === FALSE) {
        form_set_error('agri_projects_sfc_ws_enable', t('The certificate is not valid.'));
      }
    }
  }
}

/**
 * Implements hook_form_submit().
 */
function agri_projects_sfc_ws_config_form_submit($form, &$form_state) {
  if ($form_state['values']['agri_projects_sfc_ws_reset_date'] == 1) {
    if (is_null($form_state['values']['agri_projects_sfc_ws_last_time_date'])) {
      variable_del('agri_projects_sfc_ws_last_time');
      drupal_set_message(t('The date of the last import was reset.'));
    }
    else {
      variable_set('agri_projects_sfc_ws_last_time', strtotime($form_state['values']['agri_projects_sfc_ws_last_time_date']));
      drupal_set_message(t('The date of the last import was set to @date', array(
        '@date' => $form_state['values']['agri_projects_sfc_ws_last_time_date'],
      )));
    }
  }
}

/**
 * Callback for button sfc_ws_fill_queue.
 */
function _agri_projects_sfc_ws_fill_queue_manually() {
  _agri_projects_sfc_ws_fill_queue();
}

/**
 * Callback for button sfc_ws_truncate_queue.
 */
function _agri_projects_sfc_ws_truncate_queue() {
  $queue = DrupalQueue::get('agri_projects_sfc_ws');
  $queue->deleteQueue();
}

/**
 * Implements hook_form().
 */
function agri_projects_sfc_ws_test_form($form, &$form_state) {

  // Attaches css and js from the field group module.
  $form['#attached']['css'] = [
    drupal_get_path('module', 'field_group') . '/horizontal-tabs/horizontal-tabs.css',
  ];
  $form['#attached']['js'] = [
    drupal_get_path('module', 'field_group') . '/horizontal-tabs/horizontal-tabs.js',
  ];

  $form['sfc_ws'] = array(
    '#type' => 'horizontal_tabs',
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  $form['sfc_ws']['search'] = array(
    '#type' => 'fieldset',
    '#title' => t('EIP::search'),
  );

  $form['sfc_ws']['search']['xml_search'] = array(
    '#type' => 'textarea',
    '#title' => t('XML'),
    '#default_value' => variable_get('agri_projects_sfc_ws_search_project_query', AGRI_PROJECTS_SFC_WS_SEARCH_PROJECT_QUERY),
  );

  $form['sfc_ws']['search']['submit_search'] = array(
    '#type' => 'submit',
    '#value' => t('search'),
    '#submit' => array('_agri_projects_sfc_ws_search'),
  );

  $form['sfc_ws']['read'] = array(
    '#type' => 'fieldset',
    '#title' => t('EIP::read'),
  );

  $form['sfc_ws']['read']['xml_read'] = array(
    '#type' => 'textarea',
    '#title' => t('XML'),
    '#default_value' => AGRI_PROJECTS_SFC_WS_READ_PROJECT_EMPTY_QUERY,
  );

  $form['sfc_ws']['read']['read_search'] = array(
    '#type' => 'submit',
    '#value' => t('read'),
    '#submit' => array('_agri_projects_sfc_ws_read'),
  );

  $form['sfc_ws']['global'] = array(
    '#type' => 'fieldset',
    '#title' => t('SFC::getFunctions'),
  );

  $form['sfc_ws']['global']['sfc_ws_get_functions'] = array(
    '#type' => 'submit',
    '#value' => t('__getFunctions()'),
    '#submit' => array('_agri_projects_sfc_ws_get_functions'),
  );

  $form['results'] = array(
    '#type' => 'horizontal_tabs',
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  $form['results']['print_r'] = array(
    '#type' => 'fieldset',
    '#title' => t('Result'),
  );

  $form['results']['print_r']['result'] = array(
    '#type' => 'textarea',
    '#title' => t('Result'),
    '#default_value' => isset($form_state['values']) ? $form_state['values']['result'] : '',
    '#rows' => 20,
    '#access' => isset($form_state['values']['result']),
  );

  $form['results']['xml'] = array(
    '#type' => 'fieldset',
    '#title' => t('XML Result'),
  );

  $form['results']['xml']['xml_result'] = array(
    '#type' => 'textarea',
    '#title' => t('XML Result'),
    '#default_value' => isset($form_state['values']) ? $form_state['values']['xml_result'] : '',
    '#rows' => 20,
    '#access' => isset($form_state['values']['xml_result']),
  );

  return $form;
}

/**
 * Implements hook_form().
 */
function agri_projects_sfc_ws_manual_import_form($form, &$form_state) {
  $form['puid'] = array(
    '#type' => 'textarea',
    '#title' => t('Project PUID(s)'),
    '#description' => t('Insert the PUIDs of the projects that you want to add manually to the import queue. Enter one PUID per line.'),
    '#rows' => 10,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Import'),
  );

  return $form;
}

/**
 * Implements hook_form_submit().
 */
function agri_projects_sfc_ws_manual_import_form_submit($form, &$form_state) {

  $puid = explode(PHP_EOL, trim($form_state['values']['puid']));

  foreach ($puid as $value) {
    if ($cci = _agri_projects_sfc_ws_get_cci_from_puid($value)) {
      $cci_projects[] = $cci;
    }
  }

  // Add the projects in a queue.
  if (!empty($cci_projects)) {
    $queue = DrupalQueue::get('agri_projects_sfc_ws');
    foreach ($cci_projects as $cci_project) {
      $queue->createItem($cci_project);
    }

    drupal_set_message(format_plural(count($cci_projects), 'The SFC project has been added to the queue. It will be processed when cron is executed.',
      '@count SFC projects have been added to the queue. They will be processed when cron is executed.'));
  }

}

/**
 * Set a custom input value.
 *
 * @param mixed $state
 *   Form state Drupal array.
 * @param mixed $key
 *   Element key.
 * @param mixed $value
 *   New value for the element.
 */
function _agri_projects_sfc_force_form_state_input(&$state, $key, $value = '') {
  $state['input'][$key] = $value;
}

/**
 * Callback for button sfc_ws_test_connection.
 *
 * @param mixed $form
 *   The form array.
 * @param mixed $form_state
 *   The form_state array.
 */
function _agri_projects_sfc_ws_search($form, &$form_state) {
  // Prepare form for the output.
  $form_state['rebuild'] = TRUE;
  $xml_search = $form_state['values']['xml_search'];

  // Retrieve the ws settings.
  $settings = variable_get('sfc_soap_ws', array());
  $wsdl = $settings['host'] . AGRI_PROJECTS_SFC_WS_EIP_SERVICE . '?wsdl';

  try {
    if ($obj = simplexml_load_string($xml_search)) {
      $query = drupal_json_decode(drupal_json_encode((array) $obj));

      // Call the read method and get a single SFC project.
      $wrapper_eip_service = new AgriProjectsSfcWs($wsdl, array('trace' => TRUE));
      $sfc_project = $wrapper_eip_service->searchProject($query, TRUE);

      _agri_projects_sfc_force_form_state_input($form_state, 'result', (string) print_r($sfc_project, TRUE));
      _agri_projects_sfc_force_form_state_input($form_state, 'xml_result', $wrapper_eip_service->__getLastResponse());
    }
  }
  catch (Exception $e) {
    _agri_projects_sfc_force_form_state_input($form_state, 'result', (string) $e);
    _agri_projects_sfc_force_form_state_input($form_state, 'xml_result');
  }

}

/**
 * Callback for button sfc_ws_test_connection.
 *
 * @param mixed $form
 *   The form array.
 * @param mixed $form_state
 *   The form_state array.
 */
function _agri_projects_sfc_ws_read($form, &$form_state) {
  // Prepare form for the output.
  $form_state['rebuild'] = TRUE;

  $xml_read = $form_state['values']['xml_read'];

  // Retrieve the ws settings.
  $settings = variable_get('sfc_soap_ws', array());
  $wsdl = $settings['host'] . AGRI_PROJECTS_SFC_WS_EIP_SERVICE . '?wsdl';

  try {
    if ($obj = simplexml_load_string($xml_read)) {
      $request = drupal_json_decode(drupal_json_encode((array) $obj));

      // Call the read method and get a single SFC project.
      $wrapper_eip_service = new AgriProjectsSfcWs($wsdl, array('trace' => TRUE));
      $sfc_project = $wrapper_eip_service->readProject($request);

      _agri_projects_sfc_force_form_state_input($form_state, 'result', (string) print_r($sfc_project, TRUE));
      _agri_projects_sfc_force_form_state_input($form_state, 'xml_result', $wrapper_eip_service->__getLastResponse());
    }
  }
  catch (Exception $e) {
    _agri_projects_sfc_force_form_state_input($form_state, 'result', (string) $e);
    _agri_projects_sfc_force_form_state_input($form_state, 'xml_result');
  }

}

/**
 * Callback for button sfc_ws_test_connection.
 *
 * @param mixed $form
 *   The form array.
 * @param mixed $form_state
 *   The form_state array.
 */
function _agri_projects_sfc_ws_get_functions($form, &$form_state) {
  // Prepare form for the output.
  $form_state['rebuild'] = TRUE;
  _agri_projects_sfc_force_form_state_input($form_state, 'result');
  _agri_projects_sfc_force_form_state_input($form_state, 'xml_result');

  $settings = variable_get('sfc_soap_ws', array());
  try {

    $wsdl = $settings['host'] . AGRI_PROJECTS_SFC_WS_EIP_SERVICE . '?wsdl';
    $wrapper_eip_service = new AgriProjectsSfcWs($wsdl, array('trace' => TRUE));
    $data['items'] = $wrapper_eip_service->__getFunctions();
    drupal_set_message(t('Successful connection to WS %name: !list', array(
      '%name' => AGRI_PROJECTS_SFC_WS_EIP_SERVICE,
      '!list' => theme('item_list', $data),
    )));

  }
  catch (Exception $e) {
    _agri_projects_sfc_force_form_state_input($form_state, 'result', (string) $e);
  }

  try {
    $wsdl = $settings['host'] . AGRI_PROJECTS_SFC_WS_DIRECTORY_SERVICE . '?wsdl';
    $wrapper_eip_service = new AgriProjectsSfcWs($wsdl, array('trace' => TRUE));
    $data['items'] = $wrapper_eip_service->__getFunctions();
    drupal_set_message(t('Successful connection to WS %name: !list', array(
      '%name' => AGRI_PROJECTS_SFC_WS_DIRECTORY_SERVICE,
      '!list' => theme('item_list', $data),
    )));

  }
  catch (Exception $e) {
    _agri_projects_sfc_force_form_state_input($form_state, 'result', (string) $e);
  }
}
