<?php

/**
 * @file
 * agri_usermerge.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function agri_usermerge_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'agri_usermerge_drupal_account';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'AGRI Usermerge drupal account';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'AGRI Usermerge - drupal account';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'name' => 'name',
    'rid' => 'rid',
    'created' => 'created',
    'access' => 'access',
    'login' => 'login',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'access' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'login' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Field: Bulk operations: User */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_user';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::agri_core_activate_selected_users' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::user_block_user_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_user_cancel_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['type'] = 'ul';
  /* Field: User: Active */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'eip_agri_long';
  /* Field: User: Last access */
  $handler->display->display_options['fields']['access']['id'] = 'access';
  $handler->display->display_options['fields']['access']['table'] = 'users';
  $handler->display->display_options['fields']['access']['field'] = 'access';
  $handler->display->display_options['fields']['access']['date_format'] = 'short';
  $handler->display->display_options['fields']['access']['second_date_format'] = 'eip_agri_long';
  /* Field: User: Last login */
  $handler->display->display_options['fields']['login']['id'] = 'login';
  $handler->display->display_options['fields']['login']['table'] = 'users';
  $handler->display->display_options['fields']['login']['field'] = 'login';
  $handler->display->display_options['fields']['login']['date_format'] = 'short';
  $handler->display->display_options['fields']['login']['second_date_format'] = 'eip_agri_long';
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Active';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
  );
  /* Filter criterion: User: Merged with EU-Login account (field_user_merged) */
  $handler->display->display_options['filters']['field_user_merged_value']['id'] = 'field_user_merged_value';
  $handler->display->display_options['filters']['field_user_merged_value']['table'] = 'field_data_field_user_merged';
  $handler->display->display_options['filters']['field_user_merged_value']['field'] = 'field_user_merged_value';
  $handler->display->display_options['filters']['field_user_merged_value']['value'] = array(
    'all' => 'all',
    1 => '1',
  );
  $handler->display->display_options['filters']['field_user_merged_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_merged_value']['expose']['operator_id'] = 'field_user_merged_value_op';
  $handler->display->display_options['filters']['field_user_merged_value']['expose']['label'] = 'Merged with EU-Login account (field_user_merged)';
  $handler->display->display_options['filters']['field_user_merged_value']['expose']['operator'] = 'field_user_merged_value_op';
  $handler->display->display_options['filters']['field_user_merged_value']['expose']['identifier'] = 'field_user_merged_value';
  $handler->display->display_options['filters']['field_user_merged_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
  );
  $handler->display->display_options['filters']['field_user_merged_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: User: The user ID */
  $handler->display->display_options['filters']['uid_raw']['id'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['table'] = 'users';
  $handler->display->display_options['filters']['uid_raw']['field'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['operator'] = '>';
  $handler->display->display_options['filters']['uid_raw']['value']['value'] = '4';
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['rid']['expose']['operator_id'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['label'] = 'Roles';
  $handler->display->display_options['filters']['rid']['expose']['operator'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['identifier'] = 'rid';
  $handler->display->display_options['filters']['rid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
  );
  $handler->display->display_options['filters']['rid']['group_info']['label'] = 'Roles';
  $handler->display->display_options['filters']['rid']['group_info']['identifier'] = 'rid';
  $handler->display->display_options['filters']['rid']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['rid']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );

  /* Display: Merged user */
  $handler = $view->new_display('page', 'Merged user', 'merged_user');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Active';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
  );
  /* Filter criterion: User: Merged with EU-Login account (field_user_merged) */
  $handler->display->display_options['filters']['field_user_merged_value']['id'] = 'field_user_merged_value';
  $handler->display->display_options['filters']['field_user_merged_value']['table'] = 'field_data_field_user_merged';
  $handler->display->display_options['filters']['field_user_merged_value']['field'] = 'field_user_merged_value';
  $handler->display->display_options['filters']['field_user_merged_value']['value'] = array(
    'all' => 'all',
    1 => '1',
  );
  $handler->display->display_options['filters']['field_user_merged_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_merged_value']['expose']['operator_id'] = 'field_user_merged_value_op';
  $handler->display->display_options['filters']['field_user_merged_value']['expose']['label'] = 'Merged with EU-Login account';
  $handler->display->display_options['filters']['field_user_merged_value']['expose']['operator'] = 'field_user_merged_value_op';
  $handler->display->display_options['filters']['field_user_merged_value']['expose']['identifier'] = 'field_user_merged_value';
  $handler->display->display_options['filters']['field_user_merged_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
  );
  $handler->display->display_options['filters']['field_user_merged_value']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_user_merged_value']['group_info']['label'] = 'Merged with EU-Login account (field_user_merged)';
  $handler->display->display_options['filters']['field_user_merged_value']['group_info']['identifier'] = 'field_user_merged_value';
  $handler->display->display_options['filters']['field_user_merged_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_user_merged_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: User: The user ID */
  $handler->display->display_options['filters']['uid_raw']['id'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['table'] = 'users';
  $handler->display->display_options['filters']['uid_raw']['field'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['operator'] = '>';
  $handler->display->display_options['filters']['uid_raw']['value']['value'] = '4';
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['rid']['expose']['operator_id'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['label'] = 'Roles';
  $handler->display->display_options['filters']['rid']['expose']['operator'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['identifier'] = 'rid';
  $handler->display->display_options['filters']['rid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
  );
  $handler->display->display_options['filters']['rid']['group_info']['label'] = 'Roles';
  $handler->display->display_options['filters']['rid']['group_info']['identifier'] = 'rid';
  $handler->display->display_options['filters']['rid']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['rid']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
  );
  $handler->display->display_options['path'] = 'admin/config/people/agri_usermerge/drupal-account/merged';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Merged drupal user';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Merged drupal user';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Unmerged user */
  $handler = $view->new_display('page', 'Unmerged user', 'unmerged_user');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Active';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
  );
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['rid']['expose']['operator_id'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['label'] = 'Roles';
  $handler->display->display_options['filters']['rid']['expose']['operator'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['identifier'] = 'rid';
  $handler->display->display_options['filters']['rid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
  );
  $handler->display->display_options['filters']['rid']['group_info']['label'] = 'Roles';
  $handler->display->display_options['filters']['rid']['group_info']['identifier'] = 'rid';
  $handler->display->display_options['filters']['rid']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['rid']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
  );
  /* Filter criterion: User: The user ID */
  $handler->display->display_options['filters']['uid_raw']['id'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['table'] = 'users';
  $handler->display->display_options['filters']['uid_raw']['field'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['operator'] = '>';
  $handler->display->display_options['filters']['uid_raw']['value']['value'] = '4';
  $handler->display->display_options['path'] = 'admin/config/people/agri_usermerge/drupal-account/not-merged';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'UnMerged drupal user';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['agri_usermerge_drupal_account'] = $view;

  return $export;
}
