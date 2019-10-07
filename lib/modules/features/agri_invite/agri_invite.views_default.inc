<?php

/**
 * @file
 * agri_invite.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function agri_invite_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'agri_invite_manage_invite';
  $view->description = 'Allow to manage invite sent to users to participate to Collaborative areas.';
  $view->tag = 'AGRI invite';
  $view->base_table = 'invite';
  $view->human_name = 'AGRI Invite - manage invite';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Invite list';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'og_context';
  $handler->display->display_options['access']['perm'] = 'invite people';
  $handler->display->display_options['access']['group_id_arg'] = '2';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No invite items to manage. Send an invite and it will appear in this list.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Bulk operations: Invite */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_invite';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
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
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Invite: Email */
  $handler->display->display_options['fields']['field_invitation_email']['id'] = 'field_invitation_email';
  $handler->display->display_options['fields']['field_invitation_email']['table'] = 'field_data_field_invitation_email';
  $handler->display->display_options['fields']['field_invitation_email']['field'] = 'field_invitation_email';
  /* Field: Invite: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'invite';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  /* Field: Invite: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'invite';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'eip_agri_long';
  /* Field: Invite: Expiry */
  $handler->display->display_options['fields']['expiry']['id'] = 'expiry';
  $handler->display->display_options['fields']['expiry']['table'] = 'invite';
  $handler->display->display_options['fields']['expiry']['field'] = 'expiry';
  $handler->display->display_options['fields']['expiry']['date_format'] = 'short';
  $handler->display->display_options['fields']['expiry']['second_date_format'] = 'eip_agri_long';
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Invite: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'invite';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'agri_invite' => 'agri_invite',
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
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Invite status';
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
  $handler->display->display_options['filters']['status']['expose']['reduce'] = TRUE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'group/node/%/admin/manage-invite';
  $handler->display->display_options['menu']['title'] = 'Invite list';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['agri_invite_manage_invite'] = $view;

  return $export;
}
