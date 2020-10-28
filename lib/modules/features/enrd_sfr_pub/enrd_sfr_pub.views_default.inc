<?php

/**
 * @file
 * enrd_sfr_pub.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function enrd_sfr_pub_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'enrd_sfr_pub_manage_enrd_subscription_cp';
  $view->description = 'Manage supscription, unsubscription, modification, etc requests for the CP Contact form.';
  $view->tag = 'ENRD Publication Subscriptions forms';
  $view->base_table = 'enrd_sfr';
  $view->human_name = 'Manage ENRD Subscription CP requests';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Subscription CP contact form';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'manage enrd_sfr_pub_contact_cp entity';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_table_plugin_style';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'sfrid' => 'sfrid',
    'field_enrd_sfr_pub_contcp_name' => 'field_enrd_sfr_pub_contcp_name',
    'field_enrd_sfr_pub_contcp_surn' => 'field_enrd_sfr_pub_contcp_surn',
    'field_enrd_sfr_pub_contcp_email' => 'field_enrd_sfr_pub_contcp_email',
    'field_enrd_sfr_pub_contcp_type' => 'field_enrd_sfr_pub_contcp_type',
    'field_enrd_sfr_pub_contcp_reas' => 'field_enrd_sfr_pub_contcp_reas',
    'finalized' => 'finalized',
  );
  $handler->display->display_options['style_options']['default'] = 'finalized';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sfrid' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_sfr_pub_contcp_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_sfr_pub_contcp_surn' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_sfr_pub_contcp_email' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_sfr_pub_contcp_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_sfr_pub_contcp_reas' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'finalized' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['summary'] = 'List of subscription requests for the CP publications.';
  $handler->display->display_options['style_options']['bootstrap_styles'] = array(
    'striped' => 0,
    'bordered' => 0,
    'hover' => 0,
    'condensed' => 0,
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  /* Relationship: ENRD Subscription Form Request: Type of publication (field_enrd_sfr_pub_subcp_type) */
  $handler->display->display_options['relationships']['field_enrd_sfr_pub_subcp_type_value']['id'] = 'field_enrd_sfr_pub_subcp_type_value';
  $handler->display->display_options['relationships']['field_enrd_sfr_pub_subcp_type_value']['table'] = 'field_data_field_enrd_sfr_pub_subcp_type';
  $handler->display->display_options['relationships']['field_enrd_sfr_pub_subcp_type_value']['field'] = 'field_enrd_sfr_pub_subcp_type_value';
  $handler->display->display_options['relationships']['field_enrd_sfr_pub_subcp_type_value']['delta'] = '-1';
  /* Field: Bulk operations: ENRD Subscription Form Request */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_enrd_sfr';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Delete subscription request(s)',
    ),
  );
  /* Field: ENRD Subscription Form Request: ENRD Sfr unique id */
  $handler->display->display_options['fields']['sfrid']['id'] = 'sfrid';
  $handler->display->display_options['fields']['sfrid']['table'] = 'enrd_sfr';
  $handler->display->display_options['fields']['sfrid']['field'] = 'sfrid';
  $handler->display->display_options['fields']['sfrid']['label'] = 'Request id';
  /* Field: ENRD Subscription Form Request: Name */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_name']['id'] = 'field_enrd_sfr_pub_subcp_name';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_name']['table'] = 'field_data_field_enrd_sfr_pub_subcp_name';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_name']['field'] = 'field_enrd_sfr_pub_subcp_name';
  /* Field: ENRD Subscription Form Request: Surname */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_surname']['id'] = 'field_enrd_sfr_pub_subcp_surname';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_surname']['table'] = 'field_data_field_enrd_sfr_pub_subcp_surname';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_surname']['field'] = 'field_enrd_sfr_pub_subcp_surname';
  /* Field: ENRD Subscription Form Request: Email */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_email']['id'] = 'field_enrd_sfr_pub_subcp_email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_email']['table'] = 'field_data_field_enrd_sfr_pub_subcp_email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_email']['field'] = 'field_enrd_sfr_pub_subcp_email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_email']['type'] = 'email_plain';
  /* Field: ENRD Subscription Form Request: Finalized */
  $handler->display->display_options['fields']['finalized']['id'] = 'finalized';
  $handler->display->display_options['fields']['finalized']['table'] = 'enrd_sfr';
  $handler->display->display_options['fields']['finalized']['field'] = 'finalized';
  $handler->display->display_options['fields']['finalized']['label'] = 'Valid since';
  $handler->display->display_options['fields']['finalized']['date_format'] = 'short';
  $handler->display->display_options['fields']['finalized']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Sort criterion: ENRD Subscription Form Request: Finalized */
  $handler->display->display_options['sorts']['finalized']['id'] = 'finalized';
  $handler->display->display_options['sorts']['finalized']['table'] = 'enrd_sfr';
  $handler->display->display_options['sorts']['finalized']['field'] = 'finalized';
  $handler->display->display_options['sorts']['finalized']['order'] = 'DESC';
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Name, Surname or E-mail contains';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    9 => 0,
    7 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_enrd_sfr_pub_subcp_name' => 'field_enrd_sfr_pub_subcp_name',
    'field_enrd_sfr_pub_subcp_surname' => 'field_enrd_sfr_pub_subcp_surname',
    'field_enrd_sfr_pub_subcp_email' => 'field_enrd_sfr_pub_subcp_email',
  );
  /* Filter criterion: Field collection item: Type of publication (field_enrd_sfr_pub_subcp_typepub) */
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['id'] = 'field_enrd_sfr_pub_subcp_typepub_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['table'] = 'field_data_field_enrd_sfr_pub_subcp_typepub';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['field'] = 'field_enrd_sfr_pub_subcp_typepub_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['relationship'] = 'field_enrd_sfr_pub_subcp_type_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['expose']['operator_id'] = 'field_enrd_sfr_pub_subcp_typepub_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['expose']['label'] = 'Publication Type(s)';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['expose']['operator'] = 'field_enrd_sfr_pub_subcp_typepub_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['expose']['identifier'] = 'field_enrd_sfr_pub_subcp_typepub_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    9 => 0,
    7 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
  );
  /* Filter criterion: Field collection item: Paper (field_enrd_sfr_pub_subcp_paper) */
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['id'] = 'field_enrd_sfr_pub_subcp_paper_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['table'] = 'field_data_field_enrd_sfr_pub_subcp_paper';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['field'] = 'field_enrd_sfr_pub_subcp_paper_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['relationship'] = 'field_enrd_sfr_pub_subcp_type_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['expose']['operator_id'] = 'field_enrd_sfr_pub_subcp_paper_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['expose']['label'] = 'Paper';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['expose']['operator'] = 'field_enrd_sfr_pub_subcp_paper_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['expose']['identifier'] = 'field_enrd_sfr_pub_subcp_paper_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    9 => 0,
    7 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['group_info']['label'] = 'Paper';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['group_info']['identifier'] = 'field_enrd_sfr_pub_subcp_paper_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Yes',
      'operator' => 'or',
      'value' => array(
        1 => '1',
      ),
    ),
    2 => array(
      'title' => 'No',
      'operator' => 'or',
      'value' => array(
        0 => '0',
      ),
    ),
    3 => array(
      'title' => '',
      'operator' => 'or',
      'value' => array(),
    ),
  );
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Field collection item: Electronic (field_enrd_sfr_pub_subcp_electr) */
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['id'] = 'field_enrd_sfr_pub_subcp_electr_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['table'] = 'field_data_field_enrd_sfr_pub_subcp_electr';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['field'] = 'field_enrd_sfr_pub_subcp_electr_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['relationship'] = 'field_enrd_sfr_pub_subcp_type_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['expose']['operator_id'] = 'field_enrd_sfr_pub_subcp_electr_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['expose']['label'] = 'Electronic';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['expose']['operator'] = 'field_enrd_sfr_pub_subcp_electr_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['expose']['identifier'] = 'field_enrd_sfr_pub_subcp_electr_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    9 => 0,
    7 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['group_info']['label'] = 'Electronic';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['group_info']['identifier'] = 'field_enrd_sfr_pub_subcp_electr_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Yes',
      'operator' => 'or',
      'value' => array(
        1 => '1',
      ),
    ),
    2 => array(
      'title' => 'No',
      'operator' => 'or',
      'value' => array(
        0 => '0',
      ),
    ),
    3 => array(
      'title' => '',
      'operator' => 'or',
      'value' => array(),
    ),
  );
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: ENRD Subscription Form Request: Bundle type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'enrd_sfr';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = 'enrd_sfr_pub_subscribe_cp';
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Subscription CP requests */
  $handler = $view->new_display('page', 'Subscription CP requests', 'sub_cp_req');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'CP subscription requests';
  $handler->display->display_options['display_description'] = 'List of subscription requests for the Contact Point publications.';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'manage enrd_sfr_pub_subscribe_cp entity';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_table_plugin_style';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'sfrid' => 'sfrid',
    'field_enrd_sfr_pub_subcp_name' => 'field_enrd_sfr_pub_subcp_name',
    'field_enrd_sfr_pub_subcp_surname' => 'field_enrd_sfr_pub_subcp_surname',
    'field_enrd_sfr_pub_subcp_email' => 'field_enrd_sfr_pub_subcp_email',
    'field_enrd_sfr_pub_subcp_type' => 'field_enrd_sfr_pub_subcp_type',
    'finalized' => 'finalized',
  );
  $handler->display->display_options['style_options']['default'] = 'finalized';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sfrid' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_sfr_pub_subcp_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_sfr_pub_subcp_surname' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_sfr_pub_subcp_email' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_sfr_pub_subcp_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'finalized' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['summary'] = 'List of subscription requests for the CP publications.';
  $handler->display->display_options['style_options']['bootstrap_styles'] = array(
    'striped' => 0,
    'bordered' => 0,
    'hover' => 0,
    'condensed' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No subscription requests available.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: ENRD Subscription Form Request: Type of publication (field_enrd_sfr_pub_subcp_type) */
  $handler->display->display_options['relationships']['field_enrd_sfr_pub_subcp_type_value']['id'] = 'field_enrd_sfr_pub_subcp_type_value';
  $handler->display->display_options['relationships']['field_enrd_sfr_pub_subcp_type_value']['table'] = 'field_data_field_enrd_sfr_pub_subcp_type';
  $handler->display->display_options['relationships']['field_enrd_sfr_pub_subcp_type_value']['field'] = 'field_enrd_sfr_pub_subcp_type_value';
  $handler->display->display_options['relationships']['field_enrd_sfr_pub_subcp_type_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: ENRD Subscription Form Request */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_enrd_sfr';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Delete',
    ),
    'action::nexteuropa_data_export_export_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Export',
      'settings' => array(
        'view_display' => 'enrd_sfr_pub_manage_enrd_subscription_cp:views_data_export_1',
      ),
    ),
  );
  /* Field: ENRD Subscription Form Request: ENRD Sfr unique id */
  $handler->display->display_options['fields']['sfrid']['id'] = 'sfrid';
  $handler->display->display_options['fields']['sfrid']['table'] = 'enrd_sfr';
  $handler->display->display_options['fields']['sfrid']['field'] = 'sfrid';
  $handler->display->display_options['fields']['sfrid']['label'] = 'Request id';
  /* Field: ENRD Subscription Form Request: Name */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_name']['id'] = 'field_enrd_sfr_pub_subcp_name';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_name']['table'] = 'field_data_field_enrd_sfr_pub_subcp_name';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_name']['field'] = 'field_enrd_sfr_pub_subcp_name';
  /* Field: ENRD Subscription Form Request: Surname */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_surname']['id'] = 'field_enrd_sfr_pub_subcp_surname';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_surname']['table'] = 'field_data_field_enrd_sfr_pub_subcp_surname';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_surname']['field'] = 'field_enrd_sfr_pub_subcp_surname';
  /* Field: ENRD Subscription Form Request: Email */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_email']['id'] = 'field_enrd_sfr_pub_subcp_email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_email']['table'] = 'field_data_field_enrd_sfr_pub_subcp_email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_email']['field'] = 'field_enrd_sfr_pub_subcp_email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_email']['type'] = 'email_plain';
  /* Field: ENRD Subscription Form Request: Type of publication */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_type']['id'] = 'field_enrd_sfr_pub_subcp_type';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_type']['table'] = 'field_data_field_enrd_sfr_pub_subcp_type';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_type']['field'] = 'field_enrd_sfr_pub_subcp_type';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_type']['label'] = 'Type(s) of publication';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_type']['settings'] = array(
    'add' => '',
    'edit' => '',
    'translate' => '',
    'delete' => '',
    'description' => 0,
    'view_mode' => 'type_of_publication_name',
  );
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_type']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_type']['multi_type'] = 'ul';
  /* Field: ENRD Subscription Form Request: Finalized */
  $handler->display->display_options['fields']['finalized']['id'] = 'finalized';
  $handler->display->display_options['fields']['finalized']['table'] = 'enrd_sfr';
  $handler->display->display_options['fields']['finalized']['field'] = 'finalized';
  $handler->display->display_options['fields']['finalized']['label'] = 'Submission date';
  $handler->display->display_options['fields']['finalized']['date_format'] = 'short';
  $handler->display->display_options['fields']['finalized']['second_date_format'] = 'enrd_lag_database_d_m_y';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: ENRD Subscription Form Request: Finalized */
  $handler->display->display_options['sorts']['finalized']['id'] = 'finalized';
  $handler->display->display_options['sorts']['finalized']['table'] = 'enrd_sfr';
  $handler->display->display_options['sorts']['finalized']['field'] = 'finalized';
  $handler->display->display_options['sorts']['finalized']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Name, Surname or E-mail contains';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    9 => 0,
    7 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_enrd_sfr_pub_subcp_name' => 'field_enrd_sfr_pub_subcp_name',
    'field_enrd_sfr_pub_subcp_surname' => 'field_enrd_sfr_pub_subcp_surname',
    'field_enrd_sfr_pub_subcp_email' => 'field_enrd_sfr_pub_subcp_email',
  );
  /* Filter criterion: Field collection item: Type of publication (field_enrd_sfr_pub_subcp_typepub) */
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['id'] = 'field_enrd_sfr_pub_subcp_typepub_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['table'] = 'field_data_field_enrd_sfr_pub_subcp_typepub';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['field'] = 'field_enrd_sfr_pub_subcp_typepub_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['relationship'] = 'field_enrd_sfr_pub_subcp_type_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['expose']['operator_id'] = 'field_enrd_sfr_pub_subcp_typepub_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['expose']['label'] = 'Publication Type(s)';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['expose']['operator'] = 'field_enrd_sfr_pub_subcp_typepub_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['expose']['identifier'] = 'field_enrd_sfr_pub_subcp_typepub_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    9 => 0,
    7 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
  );
  /* Filter criterion: Field collection item: Paper (field_enrd_sfr_pub_subcp_paper) */
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['id'] = 'field_enrd_sfr_pub_subcp_paper_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['table'] = 'field_data_field_enrd_sfr_pub_subcp_paper';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['field'] = 'field_enrd_sfr_pub_subcp_paper_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['relationship'] = 'field_enrd_sfr_pub_subcp_type_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['expose']['operator_id'] = 'field_enrd_sfr_pub_subcp_paper_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['expose']['label'] = 'Paper';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['expose']['operator'] = 'field_enrd_sfr_pub_subcp_paper_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['expose']['identifier'] = 'field_enrd_sfr_pub_subcp_paper_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['group_info']['label'] = 'Paper';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['group_info']['identifier'] = 'field_enrd_sfr_pub_subcp_paper_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Yes',
      'operator' => 'or',
      'value' => array(
        1 => '1',
      ),
    ),
    2 => array(
      'title' => 'No',
      'operator' => 'or',
      'value' => array(
        0 => '0',
      ),
    ),
    3 => array(
      'title' => '',
      'operator' => 'or',
      'value' => array(),
    ),
  );
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Field collection item: Electronic (field_enrd_sfr_pub_subcp_electr) */
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['id'] = 'field_enrd_sfr_pub_subcp_electr_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['table'] = 'field_data_field_enrd_sfr_pub_subcp_electr';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['field'] = 'field_enrd_sfr_pub_subcp_electr_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['relationship'] = 'field_enrd_sfr_pub_subcp_type_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['expose']['operator_id'] = 'field_enrd_sfr_pub_subcp_electr_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['expose']['label'] = 'Electronic';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['expose']['operator'] = 'field_enrd_sfr_pub_subcp_electr_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['expose']['identifier'] = 'field_enrd_sfr_pub_subcp_electr_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['group_info']['label'] = 'Electronic';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['group_info']['identifier'] = 'field_enrd_sfr_pub_subcp_electr_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Yes',
      'operator' => 'or',
      'value' => array(
        1 => '1',
      ),
    ),
    2 => array(
      'title' => 'No',
      'operator' => 'or',
      'value' => array(
        0 => '0',
      ),
    ),
    3 => array(
      'title' => '',
      'operator' => 'or',
      'value' => array(),
    ),
  );
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Date: Date (enrd_sfr) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'enrd_sfr';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Submission Date';
  $handler->display->display_options['filters']['date_filter']['expose']['description'] = 'Select both start and end date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'finalized';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    12 => 0,
    8 => 0,
    9 => 0,
    11 => 0,
    15 => 0,
    14 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-3:+0';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'enrd_sfr.finalized' => 'enrd_sfr.finalized',
  );
  $handler->display->display_options['filters']['date_filter']['date_method'] = 'AND';
  /* Filter criterion: ENRD Subscription Form Request: Bundle type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'enrd_sfr';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = 'enrd_sfr_pub_subscribe_cp';
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: ENRD Subscription Form Request: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'enrd_sfr';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['path'] = 'admin/enrd/enrd-sfr/cp/subscriptions';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Subscription requests CP';
  $handler->display->display_options['menu']['description'] = 'Manage subscription requests for the Contact Point.';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Subscription CP';
  $handler->display->display_options['tab_options']['description'] = 'Manage subscription requests for the Contact Point.';
  $handler->display->display_options['tab_options']['weight'] = '21';
  $handler->display->display_options['tab_options']['name'] = 'management';

  /* Display: Data export: Sub CP Export */
  $handler = $view->new_display('views_data_export', 'Data export: Sub CP Export', 'views_data_export_1');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'manage enrd_sfr_pub_subscribe_cp entity';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'enrd_sfr_pub_cp_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%timestamp-full_export-subscriptions-pub-cp.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = '1';
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: ENRD Subscription Form Request: Title */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_petitle']['id'] = 'field_enrd_sfr_pub_subcp_petitle';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_petitle']['table'] = 'field_data_field_enrd_sfr_pub_subcp_petitle';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_petitle']['field'] = 'field_enrd_sfr_pub_subcp_petitle';
  /* Field: ENRD Subscription Form Request: Name */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_name']['id'] = 'field_enrd_sfr_pub_subcp_name';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_name']['table'] = 'field_data_field_enrd_sfr_pub_subcp_name';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_name']['field'] = 'field_enrd_sfr_pub_subcp_name';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_name']['label'] = 'First Name';
  /* Field: ENRD Subscription Form Request: Surname */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_surname']['id'] = 'field_enrd_sfr_pub_subcp_surname';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_surname']['table'] = 'field_data_field_enrd_sfr_pub_subcp_surname';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_surname']['field'] = 'field_enrd_sfr_pub_subcp_surname';
  /* Field: ENRD Subscription Form Request: Organisation */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_org']['id'] = 'field_enrd_sfr_pub_subcp_org';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_org']['table'] = 'field_data_field_enrd_sfr_pub_subcp_org';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_org']['field'] = 'field_enrd_sfr_pub_subcp_org';
  /* Field: ENRD Subscription Form Request: Address - Thoroughfare (i.e. Street address) */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_addr_thoroughfare']['id'] = 'field_enrd_sfr_pub_subcp_addr_thoroughfare';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_addr_thoroughfare']['table'] = 'field_data_field_enrd_sfr_pub_subcp_addr';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_addr_thoroughfare']['field'] = 'field_enrd_sfr_pub_subcp_addr_thoroughfare';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_addr_thoroughfare']['label'] = 'Address Line 1';
  /* Field: ENRD Subscription Form Request: Address - Premise (i.e. Apartment / Suite number) */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_addr_premise']['id'] = 'field_enrd_sfr_pub_subcp_addr_premise';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_addr_premise']['table'] = 'field_data_field_enrd_sfr_pub_subcp_addr';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_addr_premise']['field'] = 'field_enrd_sfr_pub_subcp_addr_premise';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_addr_premise']['label'] = 'Address Line 2';
  /* Field: ENRD Subscription Form Request: Address - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_addr_locality']['id'] = 'field_enrd_sfr_pub_subcp_addr_locality';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_addr_locality']['table'] = 'field_data_field_enrd_sfr_pub_subcp_addr';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_addr_locality']['field'] = 'field_enrd_sfr_pub_subcp_addr_locality';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_addr_locality']['label'] = 'Town';
  /* Field: ENRD Subscription Form Request: Address - Postal code */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_addr_postal_code']['id'] = 'field_enrd_sfr_pub_subcp_addr_postal_code';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_addr_postal_code']['table'] = 'field_data_field_enrd_sfr_pub_subcp_addr';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_addr_postal_code']['field'] = 'field_enrd_sfr_pub_subcp_addr_postal_code';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_addr_postal_code']['label'] = 'Postcode';
  /* Field: ENRD Subscription Form Request: Address - Country */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_addr_country']['id'] = 'field_enrd_sfr_pub_subcp_addr_country';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_addr_country']['table'] = 'field_data_field_enrd_sfr_pub_subcp_addr';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_addr_country']['field'] = 'field_enrd_sfr_pub_subcp_addr_country';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_addr_country']['label'] = 'Country Name';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_addr_country']['display_name'] = 1;
  /* Field: ENRD Subscription Form Request: Email */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_email']['id'] = 'field_enrd_sfr_pub_subcp_email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_email']['table'] = 'field_data_field_enrd_sfr_pub_subcp_email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_email']['field'] = 'field_enrd_sfr_pub_subcp_email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subcp_email']['type'] = 'email_plain';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Name, Surname or E-mail contains';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    9 => 0,
    7 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_enrd_sfr_pub_subcp_name' => 'field_enrd_sfr_pub_subcp_name',
    'field_enrd_sfr_pub_subcp_surname' => 'field_enrd_sfr_pub_subcp_surname',
    'field_enrd_sfr_pub_subcp_email' => 'field_enrd_sfr_pub_subcp_email',
  );
  /* Filter criterion: Field collection item: Type of publication (field_enrd_sfr_pub_subcp_typepub) */
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['id'] = 'field_enrd_sfr_pub_subcp_typepub_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['table'] = 'field_data_field_enrd_sfr_pub_subcp_typepub';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['field'] = 'field_enrd_sfr_pub_subcp_typepub_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['relationship'] = 'field_enrd_sfr_pub_subcp_type_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['expose']['operator_id'] = 'field_enrd_sfr_pub_subcp_typepub_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['expose']['label'] = 'Publication Type(s)';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['expose']['operator'] = 'field_enrd_sfr_pub_subcp_typepub_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['expose']['identifier'] = 'field_enrd_sfr_pub_subcp_typepub_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_typepub_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    9 => 0,
    7 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
  );
  /* Filter criterion: Field collection item: Paper (field_enrd_sfr_pub_subcp_paper) */
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['id'] = 'field_enrd_sfr_pub_subcp_paper_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['table'] = 'field_data_field_enrd_sfr_pub_subcp_paper';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['field'] = 'field_enrd_sfr_pub_subcp_paper_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['relationship'] = 'field_enrd_sfr_pub_subcp_type_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['expose']['operator_id'] = 'field_enrd_sfr_pub_subcp_paper_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['expose']['label'] = 'Paper';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['expose']['operator'] = 'field_enrd_sfr_pub_subcp_paper_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['expose']['identifier'] = 'field_enrd_sfr_pub_subcp_paper_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    9 => 0,
    7 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['group_info']['label'] = 'Paper';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['group_info']['identifier'] = 'field_enrd_sfr_pub_subcp_paper_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Yes',
      'operator' => 'or',
      'value' => array(
        1 => '1',
      ),
    ),
    2 => array(
      'title' => 'No',
      'operator' => 'or',
      'value' => array(
        0 => '0',
      ),
    ),
    3 => array(
      'title' => '',
      'operator' => 'or',
      'value' => array(),
    ),
  );
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_paper_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Field collection item: Electronic (field_enrd_sfr_pub_subcp_electr) */
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['id'] = 'field_enrd_sfr_pub_subcp_electr_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['table'] = 'field_data_field_enrd_sfr_pub_subcp_electr';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['field'] = 'field_enrd_sfr_pub_subcp_electr_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['relationship'] = 'field_enrd_sfr_pub_subcp_type_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['expose']['operator_id'] = 'field_enrd_sfr_pub_subcp_electr_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['expose']['label'] = 'Electronic';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['expose']['operator'] = 'field_enrd_sfr_pub_subcp_electr_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['expose']['identifier'] = 'field_enrd_sfr_pub_subcp_electr_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    9 => 0,
    7 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['group_info']['label'] = 'Electronic';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['group_info']['identifier'] = 'field_enrd_sfr_pub_subcp_electr_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Yes',
      'operator' => 'or',
      'value' => array(
        1 => '1',
      ),
    ),
    2 => array(
      'title' => 'No',
      'operator' => 'or',
      'value' => array(
        0 => '0',
      ),
    ),
    3 => array(
      'title' => '',
      'operator' => 'or',
      'value' => array(),
    ),
  );
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subcp_electr_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Date: Date (enrd_sfr) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'enrd_sfr';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Submission Date';
  $handler->display->display_options['filters']['date_filter']['expose']['description'] = 'Select both start and end date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'finalized';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    12 => 0,
    8 => 0,
    9 => 0,
    11 => 0,
    15 => 0,
    14 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-3:+0';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'enrd_sfr.finalized' => 'enrd_sfr.finalized',
  );
  $handler->display->display_options['filters']['date_filter']['date_method'] = 'AND';
  /* Filter criterion: ENRD Subscription Form Request: Bundle type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'enrd_sfr';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = 'enrd_sfr_pub_subscribe_cp';
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: ENRD Subscription Form Request: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'enrd_sfr';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['path'] = 'admin/enrd/enrd-sfr/cp/subscriptions/export';
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'sub_cp_req' => 0,
    'cont_cp_req' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'admin/enrd/enrd-sfr/cp/subscriptions';
  $handler->display->display_options['segment_size'] = '500';

  /* Display: Subscription CP contact */
  $handler = $view->new_display('page', 'Subscription CP contact', 'cont_cp_req');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'CP contact form requests';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'manage enrd_sfr_pub_contact_cp entity';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_table_plugin_style';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'sfrid' => 'sfrid',
    'field_enrd_sfr_pub_contcp_name' => 'field_enrd_sfr_pub_contcp_name',
    'field_enrd_sfr_pub_contcp_surn' => 'field_enrd_sfr_pub_contcp_surn',
    'field_enrd_sfr_pub_contcp_email' => 'field_enrd_sfr_pub_contcp_email',
    'field_enrd_sfr_pub_contcp_type' => 'field_enrd_sfr_pub_contcp_type',
    'field_enrd_sfr_pub_contcp_reas' => 'field_enrd_sfr_pub_contcp_reas',
    'finalized' => 'finalized',
  );
  $handler->display->display_options['style_options']['default'] = 'finalized';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sfrid' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_sfr_pub_contcp_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_sfr_pub_contcp_surn' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_sfr_pub_contcp_email' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_sfr_pub_contcp_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_sfr_pub_contcp_reas' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'finalized' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['summary'] = 'List of subscription requests for the CP publications.';
  $handler->display->display_options['style_options']['bootstrap_styles'] = array(
    'striped' => 0,
    'bordered' => 0,
    'hover' => 0,
    'condensed' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No contact form requests available.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: ENRD Subscription Form Request */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_enrd_sfr';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Request id';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Delete',
      'settings' => array(
        'log' => 0,
      ),
    ),
    'action::nexteuropa_data_export_export_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Export',
      'settings' => array(
        'view_display' => 'enrd_sfr_pub_manage_enrd_subscription_cp:views_data_export_2',
      ),
    ),
  );
  /* Field: ENRD Subscription Form Request: ENRD Sfr unique id */
  $handler->display->display_options['fields']['sfrid']['id'] = 'sfrid';
  $handler->display->display_options['fields']['sfrid']['table'] = 'enrd_sfr';
  $handler->display->display_options['fields']['sfrid']['field'] = 'sfrid';
  $handler->display->display_options['fields']['sfrid']['label'] = 'Request id';
  /* Field: ENRD Subscription Form Request: Name */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_name']['id'] = 'field_enrd_sfr_pub_contcp_name';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_name']['table'] = 'field_data_field_enrd_sfr_pub_contcp_name';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_name']['field'] = 'field_enrd_sfr_pub_contcp_name';
  /* Field: ENRD Subscription Form Request: Surname */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_surn']['id'] = 'field_enrd_sfr_pub_contcp_surn';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_surn']['table'] = 'field_data_field_enrd_sfr_pub_contcp_surn';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_surn']['field'] = 'field_enrd_sfr_pub_contcp_surn';
  /* Field: ENRD Subscription Form Request: Email */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_email']['id'] = 'field_enrd_sfr_pub_contcp_email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_email']['table'] = 'field_data_field_enrd_sfr_pub_contcp_email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_email']['field'] = 'field_enrd_sfr_pub_contcp_email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_email']['type'] = 'email_plain';
  /* Field: ENRD Subscription Form Request: Type of publication(s) */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_type']['id'] = 'field_enrd_sfr_pub_contcp_type';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_type']['table'] = 'field_data_field_enrd_sfr_pub_contcp_type';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_type']['field'] = 'field_enrd_sfr_pub_contcp_type';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_type']['delta_offset'] = '0';
  /* Field: ENRD Subscription Form Request: Reason */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_reas']['id'] = 'field_enrd_sfr_pub_contcp_reas';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_reas']['table'] = 'field_data_field_enrd_sfr_pub_contcp_reas';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_reas']['field'] = 'field_enrd_sfr_pub_contcp_reas';
  /* Field: ENRD Subscription Form Request: Finalized */
  $handler->display->display_options['fields']['finalized']['id'] = 'finalized';
  $handler->display->display_options['fields']['finalized']['table'] = 'enrd_sfr';
  $handler->display->display_options['fields']['finalized']['field'] = 'finalized';
  $handler->display->display_options['fields']['finalized']['label'] = 'Submission date';
  $handler->display->display_options['fields']['finalized']['date_format'] = 'short';
  $handler->display->display_options['fields']['finalized']['second_date_format'] = 'enrd_lag_database_d_m_y';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Name, Surname or E-mail contains';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    9 => 0,
    7 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_enrd_sfr_pub_contcp_name' => 'field_enrd_sfr_pub_contcp_name',
    'field_enrd_sfr_pub_contcp_surn' => 'field_enrd_sfr_pub_contcp_surn',
    'field_enrd_sfr_pub_contcp_email' => 'field_enrd_sfr_pub_contcp_email',
  );
  /* Filter criterion: ENRD Subscription Form Request: Type of publication(s) (field_enrd_sfr_pub_contcp_type) */
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_type_value']['id'] = 'field_enrd_sfr_pub_contcp_type_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_type_value']['table'] = 'field_data_field_enrd_sfr_pub_contcp_type';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_type_value']['field'] = 'field_enrd_sfr_pub_contcp_type_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_type_value']['expose']['operator_id'] = 'field_enrd_sfr_pub_contcp_type_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_type_value']['expose']['label'] = 'Publication type(s)';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_type_value']['expose']['operator'] = 'field_enrd_sfr_pub_contcp_type_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_type_value']['expose']['identifier'] = 'field_enrd_sfr_pub_contcp_type_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_type_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    9 => 0,
    7 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
  );
  /* Filter criterion: ENRD Subscription Form Request: Reason (field_enrd_sfr_pub_contcp_reas) */
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_reas_value']['id'] = 'field_enrd_sfr_pub_contcp_reas_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_reas_value']['table'] = 'field_data_field_enrd_sfr_pub_contcp_reas';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_reas_value']['field'] = 'field_enrd_sfr_pub_contcp_reas_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_reas_value']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_reas_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_reas_value']['expose']['operator_id'] = 'field_enrd_sfr_pub_contcp_reas_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_reas_value']['expose']['label'] = 'Reason';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_reas_value']['expose']['operator'] = 'field_enrd_sfr_pub_contcp_reas_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_reas_value']['expose']['identifier'] = 'field_enrd_sfr_pub_contcp_reas_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_reas_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    9 => 0,
    7 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
  );
  /* Filter criterion: ENRD Subscription Form Request: Are you subscribed for electronic or paper copies? (field_enrd_sfr_pub_contcp_papel) */
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_papel_value']['id'] = 'field_enrd_sfr_pub_contcp_papel_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_papel_value']['table'] = 'field_data_field_enrd_sfr_pub_contcp_papel';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_papel_value']['field'] = 'field_enrd_sfr_pub_contcp_papel_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_papel_value']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_papel_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_papel_value']['expose']['operator_id'] = 'field_enrd_sfr_pub_contcp_papel_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_papel_value']['expose']['label'] = 'Electronic/Paper';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_papel_value']['expose']['operator'] = 'field_enrd_sfr_pub_contcp_papel_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_papel_value']['expose']['identifier'] = 'field_enrd_sfr_pub_contcp_papel_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_papel_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    9 => 0,
    7 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
  );
  /* Filter criterion: Date: Date (enrd_sfr) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'enrd_sfr';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Submission Date';
  $handler->display->display_options['filters']['date_filter']['expose']['description'] = 'Select both start and end date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'finalized';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    12 => 0,
    8 => 0,
    9 => 0,
    11 => 0,
    15 => 0,
    14 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-3:+0';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'enrd_sfr.finalized' => 'enrd_sfr.finalized',
  );
  $handler->display->display_options['filters']['date_filter']['date_method'] = 'AND';
  /* Filter criterion: ENRD Subscription Form Request: Bundle type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'enrd_sfr';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = 'enrd_sfr_pub_contact_cp';
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: ENRD Subscription Form Request: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'enrd_sfr';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['path'] = 'admin/enrd/enrd-sfr/cp/contact';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Unsubscribed / Modified';
  $handler->display->display_options['menu']['description'] = 'Manage modification or unsubscription requests for the CP.';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export: Sub CP Contact Form */
  $handler = $view->new_display('views_data_export', 'Data export: Sub CP Contact Form', 'views_data_export_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'CP contact form requests';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xlsx';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%timestamp-full_export-subscriptions-cont-cp.xlsx';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: ENRD Subscription Form Request: ENRD Sfr unique id */
  $handler->display->display_options['fields']['sfrid']['id'] = 'sfrid';
  $handler->display->display_options['fields']['sfrid']['table'] = 'enrd_sfr';
  $handler->display->display_options['fields']['sfrid']['field'] = 'sfrid';
  $handler->display->display_options['fields']['sfrid']['label'] = 'Request id';
  /* Field: ENRD Subscription Form Request: Name */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_name']['id'] = 'field_enrd_sfr_pub_contcp_name';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_name']['table'] = 'field_data_field_enrd_sfr_pub_contcp_name';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_name']['field'] = 'field_enrd_sfr_pub_contcp_name';
  /* Field: ENRD Subscription Form Request: Surname */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_surn']['id'] = 'field_enrd_sfr_pub_contcp_surn';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_surn']['table'] = 'field_data_field_enrd_sfr_pub_contcp_surn';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_surn']['field'] = 'field_enrd_sfr_pub_contcp_surn';
  /* Field: ENRD Subscription Form Request: Email */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_email']['id'] = 'field_enrd_sfr_pub_contcp_email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_email']['table'] = 'field_data_field_enrd_sfr_pub_contcp_email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_email']['field'] = 'field_enrd_sfr_pub_contcp_email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_email']['click_sort_column'] = 'email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_email']['type'] = 'evf_plain';
  /* Field: ENRD Subscription Form Request: Reason */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_reas']['id'] = 'field_enrd_sfr_pub_contcp_reas';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_reas']['table'] = 'field_data_field_enrd_sfr_pub_contcp_reas';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_reas']['field'] = 'field_enrd_sfr_pub_contcp_reas';
  /* Field: ENRD Subscription Form Request: Type of publication(s) */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_type']['id'] = 'field_enrd_sfr_pub_contcp_type';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_type']['table'] = 'field_data_field_enrd_sfr_pub_contcp_type';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_type']['field'] = 'field_enrd_sfr_pub_contcp_type';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_type']['delta_offset'] = '0';
  /* Field: ENRD Subscription Form Request: Are you subscribed for electronic or paper copies? */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_papel']['id'] = 'field_enrd_sfr_pub_contcp_papel';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_papel']['table'] = 'field_data_field_enrd_sfr_pub_contcp_papel';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_papel']['field'] = 'field_enrd_sfr_pub_contcp_papel';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_papel']['label'] = 'Electronic or paper';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_papel']['delta_offset'] = '0';
  /* Field: ENRD Subscription Form Request: To what postal address do you currently receive the ENRD publications? */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_oldadd']['id'] = 'field_enrd_sfr_pub_contcp_oldadd';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_oldadd']['table'] = 'field_data_field_enrd_sfr_pub_contcp_oldadd';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_oldadd']['field'] = 'field_enrd_sfr_pub_contcp_oldadd';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_oldadd']['label'] = 'Address';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_oldadd']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_oldadd']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_oldadd']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(),
  );
  /* Field: ENRD Subscription Form Request: Comments */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_comm']['id'] = 'field_enrd_sfr_pub_contcp_comm';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_comm']['table'] = 'field_data_field_enrd_sfr_pub_contcp_comm';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_comm']['field'] = 'field_enrd_sfr_pub_contcp_comm';
  /* Field: ENRD Subscription Form Request: Please specify how you would like to modify your subscription information */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_modif']['id'] = 'field_enrd_sfr_pub_contcp_modif';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_modif']['table'] = 'field_data_field_enrd_sfr_pub_contcp_modif';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_modif']['field'] = 'field_enrd_sfr_pub_contcp_modif';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contcp_modif']['label'] = 'Change requests';
  /* Field: ENRD Subscription Form Request: Finalized */
  $handler->display->display_options['fields']['finalized']['id'] = 'finalized';
  $handler->display->display_options['fields']['finalized']['table'] = 'enrd_sfr';
  $handler->display->display_options['fields']['finalized']['field'] = 'finalized';
  $handler->display->display_options['fields']['finalized']['label'] = 'Submission date';
  $handler->display->display_options['fields']['finalized']['date_format'] = 'short';
  $handler->display->display_options['fields']['finalized']['second_date_format'] = 'enrd_lag_database_d_m_y';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Name, Surname or E-mail contains';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    12 => 0,
    8 => 0,
    9 => 0,
    11 => 0,
    15 => 0,
    14 => 0,
    16 => 0,
    17 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_enrd_sfr_pub_contcp_name' => 'field_enrd_sfr_pub_contcp_name',
    'field_enrd_sfr_pub_contcp_surn' => 'field_enrd_sfr_pub_contcp_surn',
    'field_enrd_sfr_pub_contcp_email' => 'field_enrd_sfr_pub_contcp_email',
  );
  /* Filter criterion: ENRD Subscription Form Request: Type of publication(s) (field_enrd_sfr_pub_contcp_type) */
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_type_value']['id'] = 'field_enrd_sfr_pub_contcp_type_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_type_value']['table'] = 'field_data_field_enrd_sfr_pub_contcp_type';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_type_value']['field'] = 'field_enrd_sfr_pub_contcp_type_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_type_value']['expose']['operator_id'] = 'field_enrd_sfr_pub_contcp_type_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_type_value']['expose']['label'] = 'Publication type(s)';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_type_value']['expose']['operator'] = 'field_enrd_sfr_pub_contcp_type_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_type_value']['expose']['identifier'] = 'field_enrd_sfr_pub_contcp_type_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_type_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    12 => 0,
    8 => 0,
    9 => 0,
    11 => 0,
    15 => 0,
    14 => 0,
    16 => 0,
    17 => 0,
  );
  /* Filter criterion: ENRD Subscription Form Request: Reason (field_enrd_sfr_pub_contcp_reas) */
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_reas_value']['id'] = 'field_enrd_sfr_pub_contcp_reas_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_reas_value']['table'] = 'field_data_field_enrd_sfr_pub_contcp_reas';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_reas_value']['field'] = 'field_enrd_sfr_pub_contcp_reas_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_reas_value']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_reas_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_reas_value']['expose']['operator_id'] = 'field_enrd_sfr_pub_contcp_reas_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_reas_value']['expose']['label'] = 'Reason';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_reas_value']['expose']['operator'] = 'field_enrd_sfr_pub_contcp_reas_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_reas_value']['expose']['identifier'] = 'field_enrd_sfr_pub_contcp_reas_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_reas_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    12 => 0,
    8 => 0,
    9 => 0,
    11 => 0,
    15 => 0,
    14 => 0,
    16 => 0,
    17 => 0,
  );
  /* Filter criterion: ENRD Subscription Form Request: Are you subscribed for electronic or paper copies? (field_enrd_sfr_pub_contcp_papel) */
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_papel_value']['id'] = 'field_enrd_sfr_pub_contcp_papel_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_papel_value']['table'] = 'field_data_field_enrd_sfr_pub_contcp_papel';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_papel_value']['field'] = 'field_enrd_sfr_pub_contcp_papel_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_papel_value']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_papel_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_papel_value']['expose']['operator_id'] = 'field_enrd_sfr_pub_contcp_papel_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_papel_value']['expose']['label'] = 'Electronic/Paper';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_papel_value']['expose']['operator'] = 'field_enrd_sfr_pub_contcp_papel_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_papel_value']['expose']['identifier'] = 'field_enrd_sfr_pub_contcp_papel_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contcp_papel_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    12 => 0,
    8 => 0,
    9 => 0,
    11 => 0,
    15 => 0,
    14 => 0,
    16 => 0,
    17 => 0,
  );
  /* Filter criterion: Date: Date (enrd_sfr) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'enrd_sfr';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Submission Date';
  $handler->display->display_options['filters']['date_filter']['expose']['description'] = 'Select both start and end date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'finalized';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    12 => 0,
    8 => 0,
    9 => 0,
    11 => 0,
    15 => 0,
    14 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-3:+0';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'enrd_sfr.finalized' => 'enrd_sfr.finalized',
  );
  $handler->display->display_options['filters']['date_filter']['date_method'] = 'AND';
  /* Filter criterion: ENRD Subscription Form Request: Bundle type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'enrd_sfr';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = 'enrd_sfr_pub_contact_cp';
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: ENRD Subscription Form Request: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'enrd_sfr';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['path'] = 'admin/content/enrd-sfr/cp/contact/export/csv';
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'admin/enrd/enrd-sfr/cp/contact';
  $handler->display->display_options['segment_size'] = '500';
  $export['enrd_sfr_pub_manage_enrd_subscription_cp'] = $view;

  $view = new view();
  $view->name = 'enrd_sfr_pub_manage_enrd_subscription_ehd';
  $view->description = 'Manage supscription, unsubscription, modification, etc requests for the EHD Contact form.';
  $view->tag = 'ENRD Publication Subscriptions forms';
  $view->base_table = 'enrd_sfr';
  $view->human_name = 'Manage ENRD Subscription EHD requests';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Evaluation subscription requests';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'manage enrd_sfr_pub_contact_ehd entity';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_table_plugin_style';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'sfrid' => 'sfrid',
    'field_enrd_sfr_pub_subehd_name' => 'field_enrd_sfr_pub_subehd_name',
    'field_enrd_sfr_pub_subehd_surnam' => 'field_enrd_sfr_pub_subehd_surnam',
    'field_enrd_sfr_pub_subehd_email' => 'field_enrd_sfr_pub_subehd_email',
    'field_enrd_sfr_pub_subehd_type' => 'field_enrd_sfr_pub_subehd_type',
    'finalized' => 'finalized',
  );
  $handler->display->display_options['style_options']['default'] = 'finalized';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sfrid' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_sfr_pub_subehd_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_sfr_pub_subehd_surnam' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_sfr_pub_subehd_email' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_sfr_pub_subehd_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'finalized' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['bootstrap_styles'] = array(
    'striped' => 0,
    'bordered' => 0,
    'hover' => 0,
    'condensed' => 0,
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No subscription requests available.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: ENRD Subscription Form Request: ENRD Sfr unique id */
  $handler->display->display_options['fields']['sfrid']['id'] = 'sfrid';
  $handler->display->display_options['fields']['sfrid']['table'] = 'enrd_sfr';
  $handler->display->display_options['fields']['sfrid']['field'] = 'sfrid';
  $handler->display->display_options['fields']['sfrid']['label'] = 'Request id';
  /* Field: ENRD Subscription Form Request: Name */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_name']['id'] = 'field_enrd_sfr_pub_subehd_name';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_name']['table'] = 'field_data_field_enrd_sfr_pub_subehd_name';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_name']['field'] = 'field_enrd_sfr_pub_subehd_name';
  /* Field: ENRD Subscription Form Request: Surname */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_surnam']['id'] = 'field_enrd_sfr_pub_subehd_surnam';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_surnam']['table'] = 'field_data_field_enrd_sfr_pub_subehd_surnam';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_surnam']['field'] = 'field_enrd_sfr_pub_subehd_surnam';
  /* Field: ENRD Subscription Form Request: Email */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_email']['id'] = 'field_enrd_sfr_pub_subehd_email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_email']['table'] = 'field_data_field_enrd_sfr_pub_subehd_email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_email']['field'] = 'field_enrd_sfr_pub_subehd_email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_email']['type'] = 'email_plain';
  /* Field: ENRD Subscription Form Request: Finalized */
  $handler->display->display_options['fields']['finalized']['id'] = 'finalized';
  $handler->display->display_options['fields']['finalized']['table'] = 'enrd_sfr';
  $handler->display->display_options['fields']['finalized']['field'] = 'finalized';
  $handler->display->display_options['fields']['finalized']['label'] = 'Valid since';
  $handler->display->display_options['fields']['finalized']['date_format'] = 'short';
  $handler->display->display_options['fields']['finalized']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Sort criterion: ENRD Subscription Form Request: Finalized */
  $handler->display->display_options['sorts']['finalized']['id'] = 'finalized';
  $handler->display->display_options['sorts']['finalized']['table'] = 'enrd_sfr';
  $handler->display->display_options['sorts']['finalized']['field'] = 'finalized';
  $handler->display->display_options['sorts']['finalized']['order'] = 'DESC';
  /* Filter criterion: ENRD Subscription Form Request: Bundle type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'enrd_sfr';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = 'enrd_sfr_pub_contact_ehd';
  /* Filter criterion: ENRD Subscription Form Request: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'enrd_sfr';
  $handler->display->display_options['filters']['status']['field'] = 'status';

  /* Display: Subscription EHD requests */
  $handler = $view->new_display('page', 'Subscription EHD requests', 'sub_ehd_req');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Evaluation subscription requests';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'manage enrd_sfr_pub_subscribe_ehd entity';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: ENRD Subscription Form Request */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_enrd_sfr';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Delete',
    ),
    'action::nexteuropa_data_export_export_action' => array(
      'selected' => 1,
      'postpone_processing' => 1,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Export',
      'settings' => array(
        'view_display' => 'enrd_sfr_pub_manage_enrd_subscription_ehd:export_sub_ehd',
      ),
    ),
  );
  /* Field: ENRD Subscription Form Request: ENRD Sfr unique id */
  $handler->display->display_options['fields']['sfrid']['id'] = 'sfrid';
  $handler->display->display_options['fields']['sfrid']['table'] = 'enrd_sfr';
  $handler->display->display_options['fields']['sfrid']['field'] = 'sfrid';
  $handler->display->display_options['fields']['sfrid']['label'] = 'Request id';
  /* Field: ENRD Subscription Form Request: Name */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_name']['id'] = 'field_enrd_sfr_pub_subehd_name';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_name']['table'] = 'field_data_field_enrd_sfr_pub_subehd_name';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_name']['field'] = 'field_enrd_sfr_pub_subehd_name';
  /* Field: ENRD Subscription Form Request: Surname */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_surnam']['id'] = 'field_enrd_sfr_pub_subehd_surnam';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_surnam']['table'] = 'field_data_field_enrd_sfr_pub_subehd_surnam';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_surnam']['field'] = 'field_enrd_sfr_pub_subehd_surnam';
  /* Field: ENRD Subscription Form Request: Email */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_email']['id'] = 'field_enrd_sfr_pub_subehd_email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_email']['table'] = 'field_data_field_enrd_sfr_pub_subehd_email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_email']['field'] = 'field_enrd_sfr_pub_subehd_email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_email']['type'] = 'email_plain';
  /* Field: ENRD Subscription Form Request: Type(s) of Publication */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_type']['id'] = 'field_enrd_sfr_pub_subehd_type';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_type']['table'] = 'field_data_field_enrd_sfr_pub_subehd_type';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_type']['field'] = 'field_enrd_sfr_pub_subehd_type';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_type']['delta_offset'] = '0';
  /* Field: ENRD Subscription Form Request: Finalized */
  $handler->display->display_options['fields']['finalized']['id'] = 'finalized';
  $handler->display->display_options['fields']['finalized']['table'] = 'enrd_sfr';
  $handler->display->display_options['fields']['finalized']['field'] = 'finalized';
  $handler->display->display_options['fields']['finalized']['label'] = 'Submission date';
  $handler->display->display_options['fields']['finalized']['date_format'] = 'short';
  $handler->display->display_options['fields']['finalized']['second_date_format'] = 'enrd_lag_database_d_m_y';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Name, Surname or E-mail contains';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    9 => 0,
    7 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_enrd_sfr_pub_subehd_name' => 'field_enrd_sfr_pub_subehd_name',
    'field_enrd_sfr_pub_subehd_surnam' => 'field_enrd_sfr_pub_subehd_surnam',
    'field_enrd_sfr_pub_subehd_email' => 'field_enrd_sfr_pub_subehd_email',
  );
  /* Filter criterion: ENRD Subscription Form Request: Type(s) of Publication (field_enrd_sfr_pub_subehd_type) */
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subehd_type_value']['id'] = 'field_enrd_sfr_pub_subehd_type_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subehd_type_value']['table'] = 'field_data_field_enrd_sfr_pub_subehd_type';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subehd_type_value']['field'] = 'field_enrd_sfr_pub_subehd_type_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subehd_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subehd_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subehd_type_value']['expose']['operator_id'] = 'field_enrd_sfr_pub_subehd_type_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subehd_type_value']['expose']['label'] = 'Publication Type(s)';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subehd_type_value']['expose']['operator'] = 'field_enrd_sfr_pub_subehd_type_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subehd_type_value']['expose']['identifier'] = 'field_enrd_sfr_pub_subehd_type_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subehd_type_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subehd_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    9 => 0,
    7 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
  );
  /* Filter criterion: Date: Date (enrd_sfr) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'enrd_sfr';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Submission Date';
  $handler->display->display_options['filters']['date_filter']['expose']['description'] = 'Select both start and end date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'finalized';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    12 => 0,
    8 => 0,
    9 => 0,
    11 => 0,
    15 => 0,
    14 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-3:+0';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'enrd_sfr.finalized' => 'enrd_sfr.finalized',
  );
  $handler->display->display_options['filters']['date_filter']['date_method'] = 'AND';
  /* Filter criterion: ENRD Subscription Form Request: Bundle type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'enrd_sfr';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = 'enrd_sfr_pub_subscribe_ehd';
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: ENRD Subscription Form Request: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'enrd_sfr';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['path'] = 'admin/enrd/enrd-sfr/ehd/subscriptions';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Subscription requests EHD';
  $handler->display->display_options['menu']['description'] = 'Manage subscription requests for the Evaluation Help Desk.';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 1;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Subscription EHD';
  $handler->display->display_options['tab_options']['description'] = 'Manage subscription requests for the Evaluation Helpdesk.';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  /* Display: Data export: Sub EHD Export */
  $handler = $view->new_display('views_data_export', 'Data export: Sub EHD Export', 'export_sub_ehd');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'manage enrd_sfr_pub_subscribe_ehd entity';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xlsx';
  $handler->display->display_options['style_options']['attach_text'] = 'Export';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%timestamp-full_export-subscriptions-pub-ehd.xlsx';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: ENRD Subscription Form Request: ENRD Sfr unique id */
  $handler->display->display_options['fields']['sfrid']['id'] = 'sfrid';
  $handler->display->display_options['fields']['sfrid']['table'] = 'enrd_sfr';
  $handler->display->display_options['fields']['sfrid']['field'] = 'sfrid';
  $handler->display->display_options['fields']['sfrid']['label'] = 'Id';
  /* Field: ENRD Subscription Form Request: Name */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_name']['id'] = 'field_enrd_sfr_pub_subehd_name';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_name']['table'] = 'field_data_field_enrd_sfr_pub_subehd_name';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_name']['field'] = 'field_enrd_sfr_pub_subehd_name';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_name']['label'] = 'First name';
  /* Field: ENRD Subscription Form Request: Surname */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_surnam']['id'] = 'field_enrd_sfr_pub_subehd_surnam';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_surnam']['table'] = 'field_data_field_enrd_sfr_pub_subehd_surnam';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_surnam']['field'] = 'field_enrd_sfr_pub_subehd_surnam';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_surnam']['label'] = 'Last name';
  /* Field: ENRD Subscription Form Request: Email */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_email']['id'] = 'field_enrd_sfr_pub_subehd_email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_email']['table'] = 'field_data_field_enrd_sfr_pub_subehd_email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_email']['field'] = 'field_enrd_sfr_pub_subehd_email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_email']['label'] = 'E-mail';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_email']['click_sort_column'] = 'email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_email']['type'] = 'evf_plain';
  /* Field: ENRD Subscription Form Request: Country - Country */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_countr_country']['id'] = 'field_enrd_sfr_pub_subehd_countr_country';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_countr_country']['table'] = 'field_data_field_enrd_sfr_pub_subehd_countr';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_countr_country']['field'] = 'field_enrd_sfr_pub_subehd_countr_country';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_countr_country']['label'] = 'Country';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_countr_country']['display_name'] = 1;
  /* Field: ENRD Subscription Form Request: Type of organisation */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_organ']['id'] = 'field_enrd_sfr_pub_subehd_organ';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_organ']['table'] = 'field_data_field_enrd_sfr_pub_subehd_organ';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_organ']['field'] = 'field_enrd_sfr_pub_subehd_organ';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_organ']['label'] = 'Role/Type of organisation';
  /* Field: ENRD Subscription Form Request: Type(s) of Publication */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_type']['id'] = 'field_enrd_sfr_pub_subehd_type';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_type']['table'] = 'field_data_field_enrd_sfr_pub_subehd_type';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_type']['field'] = 'field_enrd_sfr_pub_subehd_type';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_type']['label'] = 'Type(s) of publications';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_subehd_type']['delta_offset'] = '0';
  /* Field: ENRD Subscription Form Request: Finalized */
  $handler->display->display_options['fields']['finalized']['id'] = 'finalized';
  $handler->display->display_options['fields']['finalized']['table'] = 'enrd_sfr';
  $handler->display->display_options['fields']['finalized']['field'] = 'finalized';
  $handler->display->display_options['fields']['finalized']['label'] = 'Submission date';
  $handler->display->display_options['fields']['finalized']['date_format'] = 'custom';
  $handler->display->display_options['fields']['finalized']['custom_date_format'] = 'Y-m-d H:i:s';
  $handler->display->display_options['fields']['finalized']['second_date_format'] = 'enrd_lag_database_d_m_y';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Name, Surname or E-mail contains';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    9 => 0,
    7 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_enrd_sfr_pub_subehd_name' => 'field_enrd_sfr_pub_subehd_name',
    'field_enrd_sfr_pub_subehd_surnam' => 'field_enrd_sfr_pub_subehd_surnam',
    'field_enrd_sfr_pub_subehd_email' => 'field_enrd_sfr_pub_subehd_email',
  );
  /* Filter criterion: ENRD Subscription Form Request: Type(s) of Publication (field_enrd_sfr_pub_subehd_type) */
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subehd_type_value']['id'] = 'field_enrd_sfr_pub_subehd_type_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subehd_type_value']['table'] = 'field_data_field_enrd_sfr_pub_subehd_type';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subehd_type_value']['field'] = 'field_enrd_sfr_pub_subehd_type_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subehd_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subehd_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subehd_type_value']['expose']['operator_id'] = 'field_enrd_sfr_pub_subehd_type_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subehd_type_value']['expose']['label'] = 'Type(s) of Publication';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subehd_type_value']['expose']['operator'] = 'field_enrd_sfr_pub_subehd_type_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subehd_type_value']['expose']['identifier'] = 'field_enrd_sfr_pub_subehd_type_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subehd_type_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_subehd_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    9 => 0,
    7 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
  );
  /* Filter criterion: Date: Date (enrd_sfr) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'enrd_sfr';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Submission Date';
  $handler->display->display_options['filters']['date_filter']['expose']['description'] = 'Select both start and end date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'finalized';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    12 => 0,
    8 => 0,
    9 => 0,
    11 => 0,
    15 => 0,
    14 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-3:+0';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'enrd_sfr.finalized' => 'enrd_sfr.finalized',
  );
  $handler->display->display_options['filters']['date_filter']['date_method'] = 'AND';
  /* Filter criterion: ENRD Subscription Form Request: Bundle type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'enrd_sfr';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = 'enrd_sfr_pub_subscribe_ehd';
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: ENRD Subscription Form Request: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'enrd_sfr';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['path'] = 'admin/enrd/enrd-sfr/ehd/subscriptions/export.xlsx';
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'sub_ehd_req' => 0,
    'cont_ehd_req' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'admin/enrd/enrd-sfr/ehd/subscriptions';
  $handler->display->display_options['segment_size'] = '25';

  /* Display: Subscription EHD contact form */
  $handler = $view->new_display('page', 'Subscription EHD contact form', 'cont_ehd_req');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Evaluation contact form requests';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'manage enrd_sfr_pub_contact_ehd entity';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_table_plugin_style';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'sfrid' => 'sfrid',
    'field_enrd_sfr_pub_contehd_name' => 'field_enrd_sfr_pub_contehd_name',
    'field_enrd_sfr_pub_contehd_surn' => 'field_enrd_sfr_pub_contehd_surn',
    'field_enrd_sfr_pub_contehd_email' => 'field_enrd_sfr_pub_contehd_email',
    'field_enrd_sfr_pub_contehd_type' => 'field_enrd_sfr_pub_contehd_type',
    'field_enrd_sfr_pub_contehd_reas' => 'field_enrd_sfr_pub_contehd_reas',
    'finalized' => 'finalized',
  );
  $handler->display->display_options['style_options']['default'] = 'finalized';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sfrid' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_sfr_pub_contehd_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_sfr_pub_contehd_surn' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_sfr_pub_contehd_email' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_sfr_pub_contehd_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_sfr_pub_contehd_reas' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'finalized' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['bootstrap_styles'] = array(
    'striped' => 0,
    'bordered' => 0,
    'hover' => 0,
    'condensed' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No contact form requests available.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: ENRD Subscription Form Request */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_enrd_sfr';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Request id';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Delete',
      'settings' => array(
        'log' => 0,
      ),
    ),
    'action::nexteuropa_data_export_export_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Export',
      'settings' => array(
        'view_display' => 'enrd_sfr_pub_manage_enrd_subscription_ehd:views_data_export_1',
      ),
    ),
  );
  /* Field: ENRD Subscription Form Request: ENRD Sfr unique id */
  $handler->display->display_options['fields']['sfrid']['id'] = 'sfrid';
  $handler->display->display_options['fields']['sfrid']['table'] = 'enrd_sfr';
  $handler->display->display_options['fields']['sfrid']['field'] = 'sfrid';
  $handler->display->display_options['fields']['sfrid']['label'] = 'Request id';
  /* Field: ENRD Subscription Form Request: Name */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_name']['id'] = 'field_enrd_sfr_pub_contehd_name';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_name']['table'] = 'field_data_field_enrd_sfr_pub_contehd_name';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_name']['field'] = 'field_enrd_sfr_pub_contehd_name';
  /* Field: ENRD Subscription Form Request: Surname */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_surn']['id'] = 'field_enrd_sfr_pub_contehd_surn';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_surn']['table'] = 'field_data_field_enrd_sfr_pub_contehd_surn';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_surn']['field'] = 'field_enrd_sfr_pub_contehd_surn';
  /* Field: ENRD Subscription Form Request: Email */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_email']['id'] = 'field_enrd_sfr_pub_contehd_email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_email']['table'] = 'field_data_field_enrd_sfr_pub_contehd_email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_email']['field'] = 'field_enrd_sfr_pub_contehd_email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_email']['type'] = 'email_plain';
  /* Field: ENRD Subscription Form Request: Type of publication(s) */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_type']['id'] = 'field_enrd_sfr_pub_contehd_type';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_type']['table'] = 'field_data_field_enrd_sfr_pub_contehd_type';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_type']['field'] = 'field_enrd_sfr_pub_contehd_type';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_type']['delta_offset'] = '0';
  /* Field: ENRD Subscription Form Request: Action */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_reas']['id'] = 'field_enrd_sfr_pub_contehd_reas';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_reas']['table'] = 'field_data_field_enrd_sfr_pub_contehd_reas';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_reas']['field'] = 'field_enrd_sfr_pub_contehd_reas';
  /* Field: ENRD Subscription Form Request: Finalized */
  $handler->display->display_options['fields']['finalized']['id'] = 'finalized';
  $handler->display->display_options['fields']['finalized']['table'] = 'enrd_sfr';
  $handler->display->display_options['fields']['finalized']['field'] = 'finalized';
  $handler->display->display_options['fields']['finalized']['label'] = 'Submission date';
  $handler->display->display_options['fields']['finalized']['date_format'] = 'short';
  $handler->display->display_options['fields']['finalized']['second_date_format'] = 'enrd_lag_database_d_m_y';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Name, Surname or E-mail contains';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    9 => 0,
    7 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_enrd_sfr_pub_contehd_name' => 'field_enrd_sfr_pub_contehd_name',
    'field_enrd_sfr_pub_contehd_surn' => 'field_enrd_sfr_pub_contehd_surn',
    'field_enrd_sfr_pub_contehd_mail' => 'field_enrd_sfr_pub_contehd_mail',
  );
  /* Filter criterion: ENRD Subscription Form Request: Type of publication(s) (field_enrd_sfr_pub_contehd_type) */
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_type_value']['id'] = 'field_enrd_sfr_pub_contehd_type_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_type_value']['table'] = 'field_data_field_enrd_sfr_pub_contehd_type';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_type_value']['field'] = 'field_enrd_sfr_pub_contehd_type_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_type_value']['expose']['operator_id'] = 'field_enrd_sfr_pub_contehd_type_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_type_value']['expose']['label'] = 'Publication type(s)';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_type_value']['expose']['operator'] = 'field_enrd_sfr_pub_contehd_type_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_type_value']['expose']['identifier'] = 'field_enrd_sfr_pub_contehd_type_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_type_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    9 => 0,
    7 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
  );
  /* Filter criterion: ENRD Subscription Form Request: Action (field_enrd_sfr_pub_contehd_reas) */
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_reas_value']['id'] = 'field_enrd_sfr_pub_contehd_reas_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_reas_value']['table'] = 'field_data_field_enrd_sfr_pub_contehd_reas';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_reas_value']['field'] = 'field_enrd_sfr_pub_contehd_reas_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_reas_value']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_reas_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_reas_value']['expose']['operator_id'] = 'field_enrd_sfr_pub_contehd_reas_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_reas_value']['expose']['label'] = 'Action';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_reas_value']['expose']['operator'] = 'field_enrd_sfr_pub_contehd_reas_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_reas_value']['expose']['identifier'] = 'field_enrd_sfr_pub_contehd_reas_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_reas_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    9 => 0,
    7 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
  );
  /* Filter criterion: Date: Date (enrd_sfr) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'enrd_sfr';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Submission Date';
  $handler->display->display_options['filters']['date_filter']['expose']['description'] = 'Select both start and end date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'finalized';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    12 => 0,
    8 => 0,
    9 => 0,
    11 => 0,
    15 => 0,
    14 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-3:+0';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'enrd_sfr.finalized' => 'enrd_sfr.finalized',
  );
  $handler->display->display_options['filters']['date_filter']['date_method'] = 'AND';
  /* Filter criterion: ENRD Subscription Form Request: Bundle type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'enrd_sfr';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = 'enrd_sfr_pub_contact_ehd';
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: ENRD Subscription Form Request: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'enrd_sfr';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['path'] = 'admin/enrd/enrd-sfr/ehd/contact';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Unsubscribed / Modified';
  $handler->display->display_options['menu']['description'] = 'Manage modification of unsubscription requests for the EHD.';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export: Sub EHD Contact Form */
  $handler = $view->new_display('views_data_export', 'Data export: Sub EHD Contact Form', 'views_data_export_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Evaluation contact form requests';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xlsx';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%timestamp-full_export-subscriptions-cont-ehd.xlsx';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: ENRD Subscription Form Request: ENRD Sfr unique id */
  $handler->display->display_options['fields']['sfrid']['id'] = 'sfrid';
  $handler->display->display_options['fields']['sfrid']['table'] = 'enrd_sfr';
  $handler->display->display_options['fields']['sfrid']['field'] = 'sfrid';
  $handler->display->display_options['fields']['sfrid']['label'] = 'Request id';
  /* Field: ENRD Subscription Form Request: Name */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_name']['id'] = 'field_enrd_sfr_pub_contehd_name';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_name']['table'] = 'field_data_field_enrd_sfr_pub_contehd_name';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_name']['field'] = 'field_enrd_sfr_pub_contehd_name';
  /* Field: ENRD Subscription Form Request: Surname */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_surn']['id'] = 'field_enrd_sfr_pub_contehd_surn';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_surn']['table'] = 'field_data_field_enrd_sfr_pub_contehd_surn';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_surn']['field'] = 'field_enrd_sfr_pub_contehd_surn';
  /* Field: ENRD Subscription Form Request: Email */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_email']['id'] = 'field_enrd_sfr_pub_contehd_email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_email']['table'] = 'field_data_field_enrd_sfr_pub_contehd_email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_email']['field'] = 'field_enrd_sfr_pub_contehd_email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_email']['click_sort_column'] = 'email';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_email']['type'] = 'evf_plain';
  /* Field: ENRD Subscription Form Request: Action */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_reas']['id'] = 'field_enrd_sfr_pub_contehd_reas';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_reas']['table'] = 'field_data_field_enrd_sfr_pub_contehd_reas';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_reas']['field'] = 'field_enrd_sfr_pub_contehd_reas';
  /* Field: ENRD Subscription Form Request: Notes */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_not']['id'] = 'field_enrd_sfr_pub_contehd_not';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_not']['table'] = 'field_data_field_enrd_sfr_pub_contehd_not';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_not']['field'] = 'field_enrd_sfr_pub_contehd_not';
  /* Field: ENRD Subscription Form Request: Please specify how you would like to modify your subscription information */
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_modif']['id'] = 'field_enrd_sfr_pub_contehd_modif';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_modif']['table'] = 'field_data_field_enrd_sfr_pub_contehd_modif';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_modif']['field'] = 'field_enrd_sfr_pub_contehd_modif';
  $handler->display->display_options['fields']['field_enrd_sfr_pub_contehd_modif']['label'] = 'Modify subscription information';
  /* Field: ENRD Subscription Form Request: Finalized */
  $handler->display->display_options['fields']['finalized']['id'] = 'finalized';
  $handler->display->display_options['fields']['finalized']['table'] = 'enrd_sfr';
  $handler->display->display_options['fields']['finalized']['field'] = 'finalized';
  $handler->display->display_options['fields']['finalized']['label'] = 'Submission date';
  $handler->display->display_options['fields']['finalized']['date_format'] = 'short';
  $handler->display->display_options['fields']['finalized']['second_date_format'] = 'enrd_lag_database_d_m_y';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Name, Surname or E-mail contains';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    12 => 0,
    8 => 0,
    9 => 0,
    11 => 0,
    15 => 0,
    14 => 0,
    16 => 0,
    17 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_enrd_sfr_pub_subehd_name' => 'field_enrd_sfr_pub_subehd_name',
    'field_enrd_sfr_pub_subehd_surnam' => 'field_enrd_sfr_pub_subehd_surnam',
    'field_enrd_sfr_pub_subehd_email' => 'field_enrd_sfr_pub_subehd_email',
  );
  /* Filter criterion: ENRD Subscription Form Request: Type of publication(s) (field_enrd_sfr_pub_contehd_type) */
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_type_value']['id'] = 'field_enrd_sfr_pub_contehd_type_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_type_value']['table'] = 'field_data_field_enrd_sfr_pub_contehd_type';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_type_value']['field'] = 'field_enrd_sfr_pub_contehd_type_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_type_value']['expose']['operator_id'] = 'field_enrd_sfr_pub_contehd_type_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_type_value']['expose']['label'] = 'Publication type(s)';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_type_value']['expose']['operator'] = 'field_enrd_sfr_pub_contehd_type_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_type_value']['expose']['identifier'] = 'field_enrd_sfr_pub_contehd_type_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_type_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    12 => 0,
    8 => 0,
    9 => 0,
    11 => 0,
    15 => 0,
    14 => 0,
    16 => 0,
    17 => 0,
  );
  /* Filter criterion: ENRD Subscription Form Request: Action (field_enrd_sfr_pub_contehd_reas) */
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_reas_value']['id'] = 'field_enrd_sfr_pub_contehd_reas_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_reas_value']['table'] = 'field_data_field_enrd_sfr_pub_contehd_reas';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_reas_value']['field'] = 'field_enrd_sfr_pub_contehd_reas_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_reas_value']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_reas_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_reas_value']['expose']['operator_id'] = 'field_enrd_sfr_pub_contehd_reas_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_reas_value']['expose']['label'] = 'Action';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_reas_value']['expose']['operator'] = 'field_enrd_sfr_pub_contehd_reas_value_op';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_reas_value']['expose']['identifier'] = 'field_enrd_sfr_pub_contehd_reas_value';
  $handler->display->display_options['filters']['field_enrd_sfr_pub_contehd_reas_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    12 => 0,
    8 => 0,
    9 => 0,
    11 => 0,
    15 => 0,
    14 => 0,
    16 => 0,
    17 => 0,
  );
  /* Filter criterion: Date: Date (enrd_sfr) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'enrd_sfr';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Submission Date';
  $handler->display->display_options['filters']['date_filter']['expose']['description'] = 'Select both start and end date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'finalized';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    12 => 0,
    8 => 0,
    9 => 0,
    11 => 0,
    15 => 0,
    14 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-3:+0';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'enrd_sfr.finalized' => 'enrd_sfr.finalized',
  );
  $handler->display->display_options['filters']['date_filter']['date_method'] = 'AND';
  /* Filter criterion: ENRD Subscription Form Request: Bundle type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'enrd_sfr';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = 'enrd_sfr_pub_contact_ehd';
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: ENRD Subscription Form Request: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'enrd_sfr';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['path'] = 'admin/enrd/enrd-sfr/ehd/contact/export';
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'admin/enrd/enrd-sfr/ehd/contact';
  $handler->display->display_options['segment_size'] = '500';
  $export['enrd_sfr_pub_manage_enrd_subscription_ehd'] = $view;

  return $export;
}
