<?php

/**
 * @file
 * Contains views access plugin for LAG DB permissions.
 */

/**
 * Access to only users with a specified global permission or in ESI Fund OG.
 */
class enrd_lag_dashboard_plugin_access_esi_fund_perm extends views_plugin_access_perm {

  /**
   * Determine if the current user has access or not.
   *
   * @inheritdoc
   */
  public function access($account) {
    return _enrd_lag_dashboard_check_esi_fund_perm($this->options['perm'], $this->options['esi_fund_perm'], $this->options['lag_perm'], $account);
  }

  /**
   * Determine the access callback and arguments.
   */
  public function get_access_callback() {
    return array(
      '_enrd_lag_dashboard_check_esi_fund_perm',
      array(
        $this->options['perm'],
        $this->options['esi_fund_perm'],
        $this->options['lag_perm'],
      ),
    );
  }

  /**
   * Return a string to display as the clickable title for the access control.
   */
  public function summary_title() {
    return t('Settings');
  }

  /**
   * Retrieve the options when this is a new access control plugin.
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['esi_fund_perm'] = array('default' => '');
    $options['lag_perm'] = array('default' => '');

    return $options;
  }

  /**
   * Provide the default form for setting options.
   *
   * @inheritdoc
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $none_value = array('' => t('None'));

    $perms = array();
    // Get list of permissions.
    $module_info = system_get_info('module');
    foreach (og_get_permissions() as $perm => $info) {
      $module_name = $module_info[$info['module']]['name'];
      $perms[$module_name][$perm] = strip_tags($info['title']);
    }

    $form['perm']['#options'] = $none_value + $form['perm']['#options'];

    $form['esi_fund_perm'] = array(
      '#type' => 'select',
      '#options' => $none_value + $perms,
      '#title' => t('Main ESI Fund permission'),
      '#default_value' => $this->options['esi_fund_perm'],
    );

    $form['lag_perm'] = array(
      '#type' => 'select',
      '#options' => $none_value + $perms,
      '#title' => t('LAG permission'),
      '#default_value' => $this->options['lag_perm'],
    );

  }

}
