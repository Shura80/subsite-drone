<?php

/**
 * @file
 * enrd_nrnp_invite.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function enrd_nrnp_invite_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'enrd_nrnp_invite_manage_invites';
  $view->description = '';
  $view->tag = 'ENRD NRN Profiles';
  $view->base_table = 'invite';
  $view->human_name = 'NRN Profiles manage invites';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Invitee list';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer nrn profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Bulk operations: Invite */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_invite';
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
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Delete invite(s)',
      'settings' => array(
        'log' => 0,
      ),
    ),
    'action::enrd_nrnp_invite_renew_invite' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Renew invite(s)',
    ),
  );
  /* Field: Invite: Name and Surname */
  $handler->display->display_options['fields']['field_enrd_nrnp_invite_name']['id'] = 'field_enrd_nrnp_invite_name';
  $handler->display->display_options['fields']['field_enrd_nrnp_invite_name']['table'] = 'field_data_field_enrd_nrnp_invite_name';
  $handler->display->display_options['fields']['field_enrd_nrnp_invite_name']['field'] = 'field_enrd_nrnp_invite_name';
  /* Field: Invite: Email */
  $handler->display->display_options['fields']['field_enrd_nrnp_invite_email']['id'] = 'field_enrd_nrnp_invite_email';
  $handler->display->display_options['fields']['field_enrd_nrnp_invite_email']['table'] = 'field_data_field_enrd_nrnp_invite_email';
  $handler->display->display_options['fields']['field_enrd_nrnp_invite_email']['field'] = 'field_enrd_nrnp_invite_email';
  $handler->display->display_options['fields']['field_enrd_nrnp_invite_email']['type'] = 'email_plain';
  /* Field: Invite: NRN Profile */
  $handler->display->display_options['fields']['field_enrd_nrnp_invite_page']['id'] = 'field_enrd_nrnp_invite_page';
  $handler->display->display_options['fields']['field_enrd_nrnp_invite_page']['table'] = 'field_data_field_enrd_nrnp_invite_page';
  $handler->display->display_options['fields']['field_enrd_nrnp_invite_page']['field'] = 'field_enrd_nrnp_invite_page';
  $handler->display->display_options['fields']['field_enrd_nrnp_invite_page']['settings'] = array(
    'bypass_access' => 0,
    'link' => 1,
  );
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
  $handler->display->display_options['fields']['expiry']['date_format'] = 'short';
  $handler->display->display_options['fields']['expiry']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Invite: Resend */
  $handler->display->display_options['fields']['field_enrd_nrnp_invite_resend']['id'] = 'field_enrd_nrnp_invite_resend';
  $handler->display->display_options['fields']['field_enrd_nrnp_invite_resend']['table'] = 'field_data_field_enrd_nrnp_invite_resend';
  $handler->display->display_options['fields']['field_enrd_nrnp_invite_resend']['field'] = 'field_enrd_nrnp_invite_resend';
  $handler->display->display_options['fields']['field_enrd_nrnp_invite_resend']['label'] = 'Renewed on';
  $handler->display->display_options['fields']['field_enrd_nrnp_invite_resend']['settings'] = array(
    'format_type' => 'short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['fields']['field_enrd_nrnp_invite_resend']['delta_offset'] = '0';
  /* Field: Invite: Joined */
  $handler->display->display_options['fields']['joined']['id'] = 'joined';
  $handler->display->display_options['fields']['joined']['table'] = 'invite';
  $handler->display->display_options['fields']['joined']['field'] = 'joined';
  $handler->display->display_options['fields']['joined']['label'] = 'Joined on';
  $handler->display->display_options['fields']['joined']['date_format'] = 'short';
  $handler->display->display_options['fields']['joined']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Filter criterion: Invite: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'invite';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'enrd_nrnp_invite' => 'enrd_nrnp_invite',
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Free text';
  $handler->display->display_options['filters']['combine']['expose']['description'] = 'Search by name, surname or email address';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    10 => 0,
    8 => 0,
    7 => 0,
    12 => 0,
    9 => 0,
    13 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_enrd_nrnp_invite_name' => 'field_enrd_nrnp_invite_name',
    'field_enrd_nrnp_invite_email' => 'field_enrd_nrnp_invite_email',
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
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    10 => 0,
    8 => 0,
    7 => 0,
    12 => 0,
    9 => 0,
    13 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['status']['expose']['reduce'] = TRUE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/enrd/nrn-profiles/invites';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Editors invitee list';
  $handler->display->display_options['menu']['description'] = 'Review and manage invitations already sent to NRN Editors.';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['enrd_nrnp_invite_manage_invites'] = $view;

  return $export;
}
