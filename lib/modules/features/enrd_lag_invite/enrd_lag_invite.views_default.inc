<?php

/**
 * @file
 * enrd_lag_invite.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function enrd_lag_invite_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'enrd_lag_dashboard_my_lag_contacts_invites';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'invite';
  $view->human_name = 'Invites';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My LAG invites';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'esi_fund_context';
  $handler->display->display_options['access']['perm'] = 'access lag dashboards';
  $handler->display->display_options['access']['lag_perm'] = 'access lag dashboards';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_lag_invitation_email' => 'field_lag_invitation_email',
    'field_lag_invitation_name' => 'field_lag_invitation_name',
    'field_lag_invitation_role' => 'field_lag_invitation_role',
    'created' => 'created',
    'expiry' => 'expiry',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'field_lag_invitation_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lag_invitation_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lag_invitation_role' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'expiry' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No active pending invites.';
  /* Field: Invite: Email */
  $handler->display->display_options['fields']['field_lag_invitation_email']['id'] = 'field_lag_invitation_email';
  $handler->display->display_options['fields']['field_lag_invitation_email']['table'] = 'field_data_field_lag_invitation_email';
  $handler->display->display_options['fields']['field_lag_invitation_email']['field'] = 'field_lag_invitation_email';
  $handler->display->display_options['fields']['field_lag_invitation_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lag_invitation_email']['type'] = 'email_plain';
  /* Field: Invite: Name and Surname */
  $handler->display->display_options['fields']['field_lag_invitation_name']['id'] = 'field_lag_invitation_name';
  $handler->display->display_options['fields']['field_lag_invitation_name']['table'] = 'field_data_field_lag_invitation_name';
  $handler->display->display_options['fields']['field_lag_invitation_name']['field'] = 'field_lag_invitation_name';
  $handler->display->display_options['fields']['field_lag_invitation_name']['label'] = 'LAG member invitee';
  $handler->display->display_options['fields']['field_lag_invitation_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_lag_invitation_name']['alter']['text'] = '[field_lag_invitation_name]<br />
<em>[field_lag_invitation_email]</em>
';
  /* Field: Invite: LAG Role */
  $handler->display->display_options['fields']['field_lag_invitation_role']['id'] = 'field_lag_invitation_role';
  $handler->display->display_options['fields']['field_lag_invitation_role']['table'] = 'field_data_field_lag_invitation_role';
  $handler->display->display_options['fields']['field_lag_invitation_role']['field'] = 'field_lag_invitation_role';
  /* Field: Invite: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'invite';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Invite issued on';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Invite: Expiry */
  $handler->display->display_options['fields']['expiry']['id'] = 'expiry';
  $handler->display->display_options['fields']['expiry']['table'] = 'invite';
  $handler->display->display_options['fields']['expiry']['field'] = 'expiry';
  $handler->display->display_options['fields']['expiry']['label'] = 'Invite expiry date';
  $handler->display->display_options['fields']['expiry']['date_format'] = 'enrd_lag_database_d_m_y';
  $handler->display->display_options['fields']['expiry']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Contextual filter: Field: LAG (og_lag_group_ref) */
  $handler->display->display_options['arguments']['og_lag_group_ref_target_id']['id'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['arguments']['og_lag_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['og_lag_group_ref_target_id']['field'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['arguments']['og_lag_group_ref_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['og_lag_group_ref_target_id']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['og_lag_group_ref_target_id']['title'] = 'Manage my LAG: %1';
  $handler->display->display_options['arguments']['og_lag_group_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['og_lag_group_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['og_lag_group_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['og_lag_group_ref_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['og_lag_group_ref_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['og_lag_group_ref_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['og_lag_group_ref_target_id']['validate_options']['types'] = array(
    'lag' => 'lag',
  );
  /* Filter criterion: Invite: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'invite';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'enrd_lag_invite' => 'enrd_lag_invite',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Invite: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'invite';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'my-lags/%/manage/contacts/pending-invites';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Pending invites';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 1;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['enrd_lag_dashboard_my_lag_contacts_invites'] = $view;

  $view = new view();
  $view->name = 'enrd_lag_invite_dashboard';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'invite';
  $view->human_name = 'Invites';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'LAG invites';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'esi_fund_context';
  $handler->display->display_options['access']['perm'] = 'access lag dashboards';
  $handler->display->display_options['access']['esi_fund_perm'] = 'access lag dashboards';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'field_lag_invitation_email' => 'field_lag_invitation_email',
    'field_lag_invitation_name' => 'field_lag_invitation_name',
    'field_lag_invitation_role' => 'field_lag_invitation_role',
    'field_enrd_lag_code' => 'field_enrd_lag_code',
    'title_field' => 'title_field',
    'field_enrd_lag_country' => 'field_enrd_lag_country',
    'created' => 'created',
    'expiry' => 'expiry',
    'field_enrd_lag_invitation_resend' => 'field_enrd_lag_invitation_resend',
    'joined' => 'joined',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lag_invitation_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lag_invitation_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lag_invitation_role' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_code' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_field' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_country' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'expiry' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_invitation_resend' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'joined' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No invites available with the selected criteria.';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['id'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['field'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['label'] = 'LAG entity referenced from og_lag_group_ref';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['required'] = TRUE;
  /* Field: Bulk operations: Invite */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_invite';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::enrd_lag_invite_action_renew_invite' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Invite: Email */
  $handler->display->display_options['fields']['field_lag_invitation_email']['id'] = 'field_lag_invitation_email';
  $handler->display->display_options['fields']['field_lag_invitation_email']['table'] = 'field_data_field_lag_invitation_email';
  $handler->display->display_options['fields']['field_lag_invitation_email']['field'] = 'field_lag_invitation_email';
  $handler->display->display_options['fields']['field_lag_invitation_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lag_invitation_email']['type'] = 'email_plain';
  /* Field: Invite: Name and Surname */
  $handler->display->display_options['fields']['field_lag_invitation_name']['id'] = 'field_lag_invitation_name';
  $handler->display->display_options['fields']['field_lag_invitation_name']['table'] = 'field_data_field_lag_invitation_name';
  $handler->display->display_options['fields']['field_lag_invitation_name']['field'] = 'field_lag_invitation_name';
  $handler->display->display_options['fields']['field_lag_invitation_name']['label'] = 'LAG member invitee';
  $handler->display->display_options['fields']['field_lag_invitation_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_lag_invitation_name']['alter']['text'] = '[field_lag_invitation_name]<br />
<em>[field_lag_invitation_email]</em>
';
  /* Field: Invite: LAG Role */
  $handler->display->display_options['fields']['field_lag_invitation_role']['id'] = 'field_lag_invitation_role';
  $handler->display->display_options['fields']['field_lag_invitation_role']['table'] = 'field_data_field_lag_invitation_role';
  $handler->display->display_options['fields']['field_lag_invitation_role']['field'] = 'field_lag_invitation_role';
  /* Field: Content: LAG code */
  $handler->display->display_options['fields']['field_enrd_lag_code']['id'] = 'field_enrd_lag_code';
  $handler->display->display_options['fields']['field_enrd_lag_code']['table'] = 'field_data_field_enrd_lag_code';
  $handler->display->display_options['fields']['field_enrd_lag_code']['field'] = 'field_enrd_lag_code';
  $handler->display->display_options['fields']['field_enrd_lag_code']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['fields']['field_enrd_lag_code']['label'] = '';
  $handler->display->display_options['fields']['field_enrd_lag_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_lag_code']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['fields']['title_field']['label'] = 'LAG';
  $handler->display->display_options['fields']['title_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: Field: Country */
  $handler->display->display_options['fields']['field_enrd_lag_country']['id'] = 'field_enrd_lag_country';
  $handler->display->display_options['fields']['field_enrd_lag_country']['table'] = 'field_data_field_enrd_lag_country';
  $handler->display->display_options['fields']['field_enrd_lag_country']['field'] = 'field_enrd_lag_country';
  $handler->display->display_options['fields']['field_enrd_lag_country']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['fields']['field_enrd_lag_country']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Invite: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'invite';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Invite issued on';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Invite: Expiry */
  $handler->display->display_options['fields']['expiry']['id'] = 'expiry';
  $handler->display->display_options['fields']['expiry']['table'] = 'invite';
  $handler->display->display_options['fields']['expiry']['field'] = 'expiry';
  $handler->display->display_options['fields']['expiry']['label'] = 'Invite expiry date';
  $handler->display->display_options['fields']['expiry']['date_format'] = 'enrd_lag_database_d_m_y';
  $handler->display->display_options['fields']['expiry']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Invite: Resend */
  $handler->display->display_options['fields']['field_enrd_lag_invitation_resend']['id'] = 'field_enrd_lag_invitation_resend';
  $handler->display->display_options['fields']['field_enrd_lag_invitation_resend']['table'] = 'field_data_field_enrd_lag_invitation_resend';
  $handler->display->display_options['fields']['field_enrd_lag_invitation_resend']['field'] = 'field_enrd_lag_invitation_resend';
  $handler->display->display_options['fields']['field_enrd_lag_invitation_resend']['label'] = 'Renewed on';
  $handler->display->display_options['fields']['field_enrd_lag_invitation_resend']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_lag_invitation_resend']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_lag_invitation_resend']['settings'] = array(
    'format_type' => 'enrd_lag_database_d_m_y',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['fields']['field_enrd_lag_invitation_resend']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_enrd_lag_invitation_resend']['delta_reversed'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_lag_invitation_resend']['separator'] = '<br />';
  /* Field: Invite: Joined */
  $handler->display->display_options['fields']['joined']['id'] = 'joined';
  $handler->display->display_options['fields']['joined']['table'] = 'invite';
  $handler->display->display_options['fields']['joined']['field'] = 'joined';
  $handler->display->display_options['fields']['joined']['label'] = 'Joined on';
  $handler->display->display_options['fields']['joined']['date_format'] = 'enrd_lag_database_d_m_y';
  $handler->display->display_options['fields']['joined']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Filter criterion: Invite: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'invite';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'enrd_lag_invite' => 'enrd_lag_invite',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = ' Free search';
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
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_lag_invitation_email' => 'field_lag_invitation_email',
    'field_lag_invitation_name' => 'field_lag_invitation_name',
    'title_field' => 'title_field',
    'field_enrd_lag_code' => 'field_enrd_lag_code',
  );
  /* Filter criterion: Field: Country (field_enrd_lag_country) */
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['id'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['table'] = 'field_data_field_enrd_lag_country';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['field'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['operator_id'] = 'field_enrd_lag_country_tid_op';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['operator'] = 'field_enrd_lag_country_tid_op';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['identifier'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    10 => 0,
    7 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['vocabulary'] = 'enrd_countries';
  /* Filter criterion: Content: Main ESI Fund (field_enrd_main_esi_fund) */
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['id'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['table'] = 'field_data_field_enrd_main_esi_fund';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['field'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['operator_id'] = 'field_enrd_main_esi_fund_tid_op';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['label'] = 'ESI Fund';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['operator'] = 'field_enrd_main_esi_fund_tid_op';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['identifier'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    10 => 0,
    7 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['vocabulary'] = 'enrd_esi_funds';
  /* Filter criterion: Invite: LAG Role (field_lag_invitation_role) */
  $handler->display->display_options['filters']['field_lag_invitation_role_value']['id'] = 'field_lag_invitation_role_value';
  $handler->display->display_options['filters']['field_lag_invitation_role_value']['table'] = 'field_data_field_lag_invitation_role';
  $handler->display->display_options['filters']['field_lag_invitation_role_value']['field'] = 'field_lag_invitation_role_value';
  $handler->display->display_options['filters']['field_lag_invitation_role_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lag_invitation_role_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lag_invitation_role_value']['expose']['operator_id'] = 'field_lag_invitation_role_value_op';
  $handler->display->display_options['filters']['field_lag_invitation_role_value']['expose']['label'] = 'LAG Role';
  $handler->display->display_options['filters']['field_lag_invitation_role_value']['expose']['operator'] = 'field_lag_invitation_role_value_op';
  $handler->display->display_options['filters']['field_lag_invitation_role_value']['expose']['identifier'] = 'field_lag_invitation_role_value';
  $handler->display->display_options['filters']['field_lag_invitation_role_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    10 => 0,
    7 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
    9 => 0,
  );
  /* Filter criterion: Invite: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'invite';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['status']['expose']['reduce'] = TRUE;
  /* Filter criterion: Date: Date (invite) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'invite';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Issued on';
  $handler->display->display_options['filters']['date_filter']['expose']['description'] = 'Select both start and end date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
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
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-3:+0';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'invite.created' => 'invite.created',
  );
  $handler->display->display_options['filters']['date_filter']['date_method'] = 'AND';
  /* Filter criterion: Date: Date (invite) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'invite';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter_1']['group'] = 1;
  $handler->display->display_options['filters']['date_filter_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator_id'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['label'] = 'Renewed on';
  $handler->display->display_options['filters']['date_filter_1']['expose']['description'] = 'Select both start and end date';
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['identifier'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['date_filter_1']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter_1']['year_range'] = '-3:+0';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'field_data_field_enrd_lag_invitation_resend.field_enrd_lag_invitation_resend_value' => 'field_data_field_enrd_lag_invitation_resend.field_enrd_lag_invitation_resend_value',
  );
  $handler->display->display_options['filters']['date_filter_1']['date_method'] = 'AND';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'lag-dashboard/users/lag-invites';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Invitee list';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 1;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['enrd_lag_invite_dashboard'] = $view;

  return $export;
}
