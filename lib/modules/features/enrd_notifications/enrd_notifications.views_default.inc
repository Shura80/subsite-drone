<?php

/**
 * @file
 * enrd_notifications.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function enrd_notifications_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'enrd_notifications_messages';
  $view->description = 'Show messages that were created for notifications or to be sent by email.';
  $view->tag = 'ENRD Notifications';
  $view->base_table = 'message';
  $view->human_name = 'ENRD Notifications Messages';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Notifications';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access notifications list';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'mid' => 'mid',
    'user' => 'user',
    'timestamp' => 'timestamp',
    'type' => 'type',
    'message_render' => 'message_render',
    'ops' => 'ops',
    'timestamp_1' => 'ops',
  );
  $handler->display->display_options['style_options']['default'] = 'timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'user' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'message_render' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ops' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No Messages were sent by email.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Relationship: Message: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'message';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  /* Field: Message: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'message';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'today time ago';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'short';
  /* Field: Message: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'message';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Message: Render message (Get text) */
  $handler->display->display_options['fields']['message_render']['id'] = 'message_render';
  $handler->display->display_options['fields']['message_render']['table'] = 'message';
  $handler->display->display_options['fields']['message_render']['field'] = 'message_render';
  $handler->display->display_options['fields']['message_render']['label'] = 'Message';
  $handler->display->display_options['fields']['message_render']['partials'] = 0;
  $handler->display->display_options['fields']['message_render']['partials_delta'] = '0';
  /* Sort criterion: Message: Timestamp */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'message';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Contextual filter: Message: User uid */
  $handler->display->display_options['arguments']['user']['id'] = 'user';
  $handler->display->display_options['arguments']['user']['table'] = 'message';
  $handler->display->display_options['arguments']['user']['field'] = 'user';
  $handler->display->display_options['arguments']['user']['default_action'] = 'default';
  $handler->display->display_options['arguments']['user']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['user']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['user']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['user']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['user']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['user']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['user']['validate']['fail'] = 'empty';
  /* Filter criterion: Message: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'message';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'enrd_notifications_content_publication_no_groups' => 'enrd_notifications_content_publication_no_groups',
  );

  /* Display: Notifications */
  $handler = $view->new_display('page', 'Notifications', 'notifications_messages');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = '[flagged]';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'mid' => 'mid',
    'user' => 'user',
    'type' => 'type',
    'field_enrd_notif_target_nodes' => 'field_enrd_notif_target_nodes',
    'field_enrd_notif_target_nodes_1' => 'field_enrd_notif_target_nodes_1',
    'timestamp' => 'timestamp',
    'nothing' => 'nothing',
    'flagged' => 'flagged',
    'ops_1' => 'ops_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'user' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_notif_target_nodes' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_notif_target_nodes_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'flagged' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ops_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'You have 0 notifcations to read.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Message: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'message';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  /* Relationship: Flags: enrd_message_read_unread */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'message';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'flag enrd_message_read_unread';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'enrd_message_read_unread';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_enrd_notif_target_nodes_target_id']['id'] = 'field_enrd_notif_target_nodes_target_id';
  $handler->display->display_options['relationships']['field_enrd_notif_target_nodes_target_id']['table'] = 'field_data_field_enrd_notif_target_nodes';
  $handler->display->display_options['relationships']['field_enrd_notif_target_nodes_target_id']['field'] = 'field_enrd_notif_target_nodes_target_id';
  $handler->display->display_options['relationships']['field_enrd_notif_target_nodes_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Message */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_message';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::rules_enrd_flag_read_unread' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Mark message as read',
    ),
  );
  /* Field: Message: Message ID */
  $handler->display->display_options['fields']['mid']['id'] = 'mid';
  $handler->display->display_options['fields']['mid']['table'] = 'message';
  $handler->display->display_options['fields']['mid']['field'] = 'mid';
  $handler->display->display_options['fields']['mid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mid']['separator'] = '';
  /* Field: Message: User uid */
  $handler->display->display_options['fields']['user']['id'] = 'user';
  $handler->display->display_options['fields']['user']['table'] = 'message';
  $handler->display->display_options['fields']['user']['field'] = 'user';
  $handler->display->display_options['fields']['user']['label'] = 'User';
  $handler->display->display_options['fields']['user']['exclude'] = TRUE;
  $handler->display->display_options['fields']['user']['separator'] = '';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'field_enrd_notif_target_nodes_target_id';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  /* Field: Message: Node Reference */
  $handler->display->display_options['fields']['field_enrd_notif_target_nodes']['id'] = 'field_enrd_notif_target_nodes';
  $handler->display->display_options['fields']['field_enrd_notif_target_nodes']['table'] = 'field_data_field_enrd_notif_target_nodes';
  $handler->display->display_options['fields']['field_enrd_notif_target_nodes']['field'] = 'field_enrd_notif_target_nodes';
  $handler->display->display_options['fields']['field_enrd_notif_target_nodes']['label'] = 'Node Reference nid';
  $handler->display->display_options['fields']['field_enrd_notif_target_nodes']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_notif_target_nodes']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_enrd_notif_target_nodes']['settings'] = array(
    'link' => 0,
  );
  /* Field: Message: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'message';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Received';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'today time ago';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'short';
  /* Field: Message: Node Reference */
  $handler->display->display_options['fields']['field_enrd_notif_target_nodes_1']['id'] = 'field_enrd_notif_target_nodes_1';
  $handler->display->display_options['fields']['field_enrd_notif_target_nodes_1']['table'] = 'field_data_field_enrd_notif_target_nodes';
  $handler->display->display_options['fields']['field_enrd_notif_target_nodes_1']['field'] = 'field_enrd_notif_target_nodes';
  $handler->display->display_options['fields']['field_enrd_notif_target_nodes_1']['label'] = 'Message';
  $handler->display->display_options['fields']['field_enrd_notif_target_nodes_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_notif_target_nodes_1']['alter']['text'] = 'The new [type] [field_enrd_notif_target_nodes_1] has been published.';
  $handler->display->display_options['fields']['field_enrd_notif_target_nodes_1']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Flags: Flagged */
  $handler->display->display_options['fields']['flagged']['id'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['table'] = 'flagging';
  $handler->display->display_options['fields']['flagged']['field'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['flagged']['label'] = '';
  $handler->display->display_options['fields']['flagged']['exclude'] = TRUE;
  $handler->display->display_options['fields']['flagged']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['flagged']['type'] = 'custom';
  $handler->display->display_options['fields']['flagged']['type_custom_true'] = 'read';
  $handler->display->display_options['fields']['flagged']['type_custom_false'] = 'unread';
  $handler->display->display_options['fields']['flagged']['not'] = 0;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops_1']['id'] = 'ops_1';
  $handler->display->display_options['fields']['ops_1']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops_1']['field'] = 'ops';
  $handler->display->display_options['fields']['ops_1']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops_1']['label'] = '';
  $handler->display->display_options['fields']['ops_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops_1']['link_type'] = 'normal';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Message: Timestamp */
  $handler->display->display_options['sorts']['timestamp_1']['id'] = 'timestamp_1';
  $handler->display->display_options['sorts']['timestamp_1']['table'] = 'message';
  $handler->display->display_options['sorts']['timestamp_1']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp_1']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Message: User uid */
  $handler->display->display_options['arguments']['user']['id'] = 'user';
  $handler->display->display_options['arguments']['user']['table'] = 'message';
  $handler->display->display_options['arguments']['user']['field'] = 'user';
  $handler->display->display_options['arguments']['user']['default_action'] = 'default';
  $handler->display->display_options['arguments']['user']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['user']['title'] = 'Notifications for %1';
  $handler->display->display_options['arguments']['user']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['user']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['user']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['user']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['user']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['user']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['user']['validate']['fail'] = 'empty';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Message: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'message';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'enrd_notifications_content_publication_no_groups' => 'enrd_notifications_content_publication_no_groups',
    'enrd_notifications_lag_content_publication' => 'enrd_notifications_lag_content_publication',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'user/%/notifications';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Follow ENRD';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Latest Unread Notifications Panel */
  $handler = $view->new_display('block', 'Latest Unread Notifications Panel', 'latest_notifications');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Latest Notifications';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'View all notifications';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['total_pages'] = '1';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '3,5,10';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'flagged',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'timestamp' => 'timestamp',
    'message_render' => 'message_render',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'You have no notifications.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Message: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'message';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  /* Relationship: Flags: enrd_message_read_unread */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'message';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'enrd_read_unread';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'enrd_message_read_unread';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_enrd_notif_target_nodes_target_id']['id'] = 'field_enrd_notif_target_nodes_target_id';
  $handler->display->display_options['relationships']['field_enrd_notif_target_nodes_target_id']['table'] = 'field_data_field_enrd_notif_target_nodes';
  $handler->display->display_options['relationships']['field_enrd_notif_target_nodes_target_id']['field'] = 'field_enrd_notif_target_nodes_target_id';
  $handler->display->display_options['relationships']['field_enrd_notif_target_nodes_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Flags: Flagged */
  $handler->display->display_options['fields']['flagged']['id'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['table'] = 'flagging';
  $handler->display->display_options['fields']['flagged']['field'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['flagged']['label'] = '';
  $handler->display->display_options['fields']['flagged']['exclude'] = TRUE;
  $handler->display->display_options['fields']['flagged']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['flagged']['type'] = 'custom';
  $handler->display->display_options['fields']['flagged']['type_custom_true'] = 'read';
  $handler->display->display_options['fields']['flagged']['type_custom_false'] = 'unread';
  $handler->display->display_options['fields']['flagged']['not'] = 0;
  /* Field: Message: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'message';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['exclude'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'today time ago';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'short';
  /* Field: Message: Message ID */
  $handler->display->display_options['fields']['mid']['id'] = 'mid';
  $handler->display->display_options['fields']['mid']['table'] = 'message';
  $handler->display->display_options['fields']['mid']['field'] = 'mid';
  $handler->display->display_options['fields']['mid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mid']['separator'] = '';
  /* Field: Message: User uid */
  $handler->display->display_options['fields']['user']['id'] = 'user';
  $handler->display->display_options['fields']['user']['table'] = 'message';
  $handler->display->display_options['fields']['user']['field'] = 'user';
  $handler->display->display_options['fields']['user']['exclude'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'field_enrd_notif_target_nodes_target_id';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  /* Field: Message: Node Reference */
  $handler->display->display_options['fields']['field_enrd_notif_target_nodes']['id'] = 'field_enrd_notif_target_nodes';
  $handler->display->display_options['fields']['field_enrd_notif_target_nodes']['table'] = 'field_data_field_enrd_notif_target_nodes';
  $handler->display->display_options['fields']['field_enrd_notif_target_nodes']['field'] = 'field_enrd_notif_target_nodes';
  $handler->display->display_options['fields']['field_enrd_notif_target_nodes']['label'] = 'Node Reference nid';
  $handler->display->display_options['fields']['field_enrd_notif_target_nodes']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_notif_target_nodes']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_enrd_notif_target_nodes']['settings'] = array(
    'link' => 0,
  );
  /* Field: Message: Node Reference */
  $handler->display->display_options['fields']['field_enrd_notif_target_nodes_1']['id'] = 'field_enrd_notif_target_nodes_1';
  $handler->display->display_options['fields']['field_enrd_notif_target_nodes_1']['table'] = 'field_data_field_enrd_notif_target_nodes';
  $handler->display->display_options['fields']['field_enrd_notif_target_nodes_1']['field'] = 'field_enrd_notif_target_nodes';
  $handler->display->display_options['fields']['field_enrd_notif_target_nodes_1']['label'] = '';
  $handler->display->display_options['fields']['field_enrd_notif_target_nodes_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_notif_target_nodes_1']['alter']['text'] = 'The new [type] [field_enrd_notif_target_nodes_1] has been published.';
  $handler->display->display_options['fields']['field_enrd_notif_target_nodes_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_notif_target_nodes_1']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Flags: Flagged */
  $handler->display->display_options['sorts']['flagged']['id'] = 'flagged';
  $handler->display->display_options['sorts']['flagged']['table'] = 'flagging';
  $handler->display->display_options['sorts']['flagged']['field'] = 'flagged';
  $handler->display->display_options['sorts']['flagged']['relationship'] = 'flag_content_rel';
  /* Sort criterion: Message: Timestamp */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'message';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Message: User uid */
  $handler->display->display_options['arguments']['user']['id'] = 'user';
  $handler->display->display_options['arguments']['user']['table'] = 'message';
  $handler->display->display_options['arguments']['user']['field'] = 'user';
  $handler->display->display_options['arguments']['user']['default_action'] = 'default';
  $handler->display->display_options['arguments']['user']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['user']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['user']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['user']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['user']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['user']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['user']['validate']['fail'] = 'access denied';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Message: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'message';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'enrd_notifications_content_publication_no_groups' => 'enrd_notifications_content_publication_no_groups',
    'enrd_notifications_lag_content_publication' => 'enrd_notifications_lag_content_publication',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Badge count */
  $handler = $view->new_display('block', 'Badge count', 'notifications_badge_count');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Badge count';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'View all notifications';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '<span class="badge">@total</span>';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Message: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'message';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  /* Relationship: Flags: enrd_message_read_unread */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'message';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'flag enrd_message_read_unread';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'enrd_message_read_unread';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_enrd_notif_target_nodes_target_id']['id'] = 'field_enrd_notif_target_nodes_target_id';
  $handler->display->display_options['relationships']['field_enrd_notif_target_nodes_target_id']['table'] = 'field_data_field_enrd_notif_target_nodes';
  $handler->display->display_options['relationships']['field_enrd_notif_target_nodes_target_id']['field'] = 'field_enrd_notif_target_nodes_target_id';
  $handler->display->display_options['relationships']['field_enrd_notif_target_nodes_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Message: User uid */
  $handler->display->display_options['fields']['user']['id'] = 'user';
  $handler->display->display_options['fields']['user']['table'] = 'message';
  $handler->display->display_options['fields']['user']['field'] = 'user';
  $handler->display->display_options['fields']['user']['label'] = '';
  $handler->display->display_options['fields']['user']['exclude'] = TRUE;
  $handler->display->display_options['fields']['user']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['user']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Message: User uid */
  $handler->display->display_options['arguments']['user']['id'] = 'user';
  $handler->display->display_options['arguments']['user']['table'] = 'message';
  $handler->display->display_options['arguments']['user']['field'] = 'user';
  $handler->display->display_options['arguments']['user']['default_action'] = 'default';
  $handler->display->display_options['arguments']['user']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['user']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['user']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['user']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['user']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['user']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['user']['validate']['fail'] = 'access denied';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Message: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'message';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'enrd_notifications_content_publication_no_groups' => 'enrd_notifications_content_publication_no_groups',
    'enrd_notifications_lag_content_publication' => 'enrd_notifications_lag_content_publication',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Flags: Flagged */
  $handler->display->display_options['filters']['flagged']['id'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['table'] = 'flagging';
  $handler->display->display_options['filters']['flagged']['field'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['flagged']['value'] = '0';
  $handler->display->display_options['filters']['flagged']['group'] = 1;
  $export['enrd_notifications_messages'] = $view;

  $view = new view();
  $view->name = 'enrd_notifications_node_flags';
  $view->description = 'Shows communities or LAGs related flag subscriptions.';
  $view->tag = 'ENRD Notifications';
  $view->base_table = 'node';
  $view->human_name = 'ENRD Notifications Node Flags (OG Groups)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access notifications settings panel';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'ops_1' => 'ops_1',
    'ops' => 'ops',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ops_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ops' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<span class="enrd-notifications-lag-display intro"><span class="glyphicon glyphicon-info-sign"></span>In this panel you can manage your single LAG notifications.<br />If you follow a single LAG you will only be notified when a Cooperation offer is published inside the LAG itself.</span>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Relationship: Flags: enrd_follow_lags */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'enrd_follow_lags';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'enrd_follow_lags';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = 'Follow?';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops_1']['id'] = 'ops_1';
  $handler->display->display_options['fields']['ops_1']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops_1']['field'] = 'ops';
  $handler->display->display_options['fields']['ops_1']['relationship'] = 'flag_content_rel';
  /* Contextual filter: Flags: User uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'flagging';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['uid']['validate']['fail'] = 'access denied';
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'lag' => 'lag',
  );
  /* Filter criterion: Flags: Flagged */
  $handler->display->display_options['filters']['flagged']['id'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['table'] = 'flagging';
  $handler->display->display_options['filters']['flagged']['field'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['flagged']['value'] = '1';

  /* Display: LAGs you follow */
  $handler = $view->new_display('page', 'LAGs you follow', 'flag_group_lags');
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'full_html',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'LAGs per page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '25, 50, 75, 100';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = 'All';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'ops' => 'ops',
    'ops_1' => 'ops_1',
    'field_enrd_lag_strategy_info' => 'field_enrd_lag_strategy_info',
    'field_enrd_lag_clld_email' => 'field_enrd_lag_clld_email',
    'field_enrd_lag_clld_name' => 'field_enrd_lag_clld_name',
    'field_enrd_lag_code' => 'field_enrd_lag_code',
    'field_enrd_lag_manager_name' => 'field_enrd_lag_manager_name',
    'field_enrd_lag_manager_email' => 'field_enrd_lag_manager_email',
    'field_enrd_lag_geo_coverage' => 'field_enrd_lag_geo_coverage',
    'field_enrd_lag_other_funding' => 'field_enrd_lag_other_funding',
    'field_enrd_lag_phone' => 'field_enrd_lag_phone',
    'field_enrd_lag_geo_coverage_sub' => 'field_enrd_lag_geo_coverage_sub',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ops' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ops_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_strategy_info' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_clld_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_clld_name' => array(
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
    'field_enrd_lag_manager_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_manager_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_geo_coverage' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_other_funding' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_geo_coverage_sub' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<span class="enrd-notifications-lag-display intro"><span class="glyphicon glyphicon-info-sign"></span>Here you can set your notifications for specific LAGs. If you follow a LAG, you will receive notifications only for cooperation offers related to that specific LAG.<br />
Browse through the full list of LAGs in the search box below. You can choose to receive both onsite messages and email notifications - click on \'follow\' and on the checkbox \'Send Email?\'.</span>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'You are not following any LAG.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: enrd_follow_lags */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'enrd_follow_lags';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'enrd_follow_lags';
  /* Relationship: Flags: email_lags */
  $handler->display->display_options['relationships']['flag_content_rel_1']['id'] = 'flag_content_rel_1';
  $handler->display->display_options['relationships']['flag_content_rel_1']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel_1']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel_1']['label'] = 'enrd_email_lags';
  $handler->display->display_options['relationships']['flag_content_rel_1']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel_1']['flag'] = 'email_lags';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'LAG name';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = 'Follow?';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops_1']['id'] = 'ops_1';
  $handler->display->display_options['fields']['ops_1']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops_1']['field'] = 'ops';
  $handler->display->display_options['fields']['ops_1']['relationship'] = 'flag_content_rel_1';
  $handler->display->display_options['fields']['ops_1']['label'] = 'Send Email?';
  /* Field: Content: Additional information on the strategy */
  $handler->display->display_options['fields']['field_enrd_lag_strategy_info']['id'] = 'field_enrd_lag_strategy_info';
  $handler->display->display_options['fields']['field_enrd_lag_strategy_info']['table'] = 'field_data_field_enrd_lag_strategy_info';
  $handler->display->display_options['fields']['field_enrd_lag_strategy_info']['field'] = 'field_enrd_lag_strategy_info';
  $handler->display->display_options['fields']['field_enrd_lag_strategy_info']['exclude'] = TRUE;
  /* Field: Content: Contact email */
  $handler->display->display_options['fields']['field_enrd_lag_clld_email']['id'] = 'field_enrd_lag_clld_email';
  $handler->display->display_options['fields']['field_enrd_lag_clld_email']['table'] = 'field_data_field_enrd_lag_clld_email';
  $handler->display->display_options['fields']['field_enrd_lag_clld_email']['field'] = 'field_enrd_lag_clld_email';
  $handler->display->display_options['fields']['field_enrd_lag_clld_email']['exclude'] = TRUE;
  /* Field: Content: Contact name */
  $handler->display->display_options['fields']['field_enrd_lag_clld_name']['id'] = 'field_enrd_lag_clld_name';
  $handler->display->display_options['fields']['field_enrd_lag_clld_name']['table'] = 'field_data_field_enrd_lag_clld_name';
  $handler->display->display_options['fields']['field_enrd_lag_clld_name']['field'] = 'field_enrd_lag_clld_name';
  $handler->display->display_options['fields']['field_enrd_lag_clld_name']['exclude'] = TRUE;
  /* Field: Content: LAG code */
  $handler->display->display_options['fields']['field_enrd_lag_code']['id'] = 'field_enrd_lag_code';
  $handler->display->display_options['fields']['field_enrd_lag_code']['table'] = 'field_data_field_enrd_lag_code';
  $handler->display->display_options['fields']['field_enrd_lag_code']['field'] = 'field_enrd_lag_code';
  $handler->display->display_options['fields']['field_enrd_lag_code']['exclude'] = TRUE;
  /* Field: Content: LAG manager (Name and Surname) */
  $handler->display->display_options['fields']['field_enrd_lag_manager_name']['id'] = 'field_enrd_lag_manager_name';
  $handler->display->display_options['fields']['field_enrd_lag_manager_name']['table'] = 'field_data_field_enrd_lag_manager_name';
  $handler->display->display_options['fields']['field_enrd_lag_manager_name']['field'] = 'field_enrd_lag_manager_name';
  $handler->display->display_options['fields']['field_enrd_lag_manager_name']['label'] = 'LAG manager';
  $handler->display->display_options['fields']['field_enrd_lag_manager_name']['exclude'] = TRUE;
  /* Field: Content: LAG manager email */
  $handler->display->display_options['fields']['field_enrd_lag_manager_email']['id'] = 'field_enrd_lag_manager_email';
  $handler->display->display_options['fields']['field_enrd_lag_manager_email']['table'] = 'field_data_field_enrd_lag_manager_email';
  $handler->display->display_options['fields']['field_enrd_lag_manager_email']['field'] = 'field_enrd_lag_manager_email';
  $handler->display->display_options['fields']['field_enrd_lag_manager_email']['exclude'] = TRUE;
  /* Field: Content: Municipalities covered */
  $handler->display->display_options['fields']['field_enrd_lag_geo_coverage']['id'] = 'field_enrd_lag_geo_coverage';
  $handler->display->display_options['fields']['field_enrd_lag_geo_coverage']['table'] = 'field_data_field_enrd_lag_geo_coverage';
  $handler->display->display_options['fields']['field_enrd_lag_geo_coverage']['field'] = 'field_enrd_lag_geo_coverage';
  $handler->display->display_options['fields']['field_enrd_lag_geo_coverage']['exclude'] = TRUE;
  /* Field: Content: Other funding schemes used */
  $handler->display->display_options['fields']['field_enrd_lag_other_funding']['id'] = 'field_enrd_lag_other_funding';
  $handler->display->display_options['fields']['field_enrd_lag_other_funding']['table'] = 'field_data_field_enrd_lag_other_funding';
  $handler->display->display_options['fields']['field_enrd_lag_other_funding']['field'] = 'field_enrd_lag_other_funding';
  $handler->display->display_options['fields']['field_enrd_lag_other_funding']['exclude'] = TRUE;
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_enrd_lag_phone']['id'] = 'field_enrd_lag_phone';
  $handler->display->display_options['fields']['field_enrd_lag_phone']['table'] = 'field_data_field_enrd_lag_phone';
  $handler->display->display_options['fields']['field_enrd_lag_phone']['field'] = 'field_enrd_lag_phone';
  $handler->display->display_options['fields']['field_enrd_lag_phone']['exclude'] = TRUE;
  /* Field: Content: Sub-municipal level */
  $handler->display->display_options['fields']['field_enrd_lag_geo_coverage_sub']['id'] = 'field_enrd_lag_geo_coverage_sub';
  $handler->display->display_options['fields']['field_enrd_lag_geo_coverage_sub']['table'] = 'field_data_field_enrd_lag_geo_coverage_sub';
  $handler->display->display_options['fields']['field_enrd_lag_geo_coverage_sub']['field'] = 'field_enrd_lag_geo_coverage_sub';
  $handler->display->display_options['fields']['field_enrd_lag_geo_coverage_sub']['exclude'] = TRUE;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_enrd_lag_manager_address']['id'] = 'field_enrd_lag_manager_address';
  $handler->display->display_options['fields']['field_enrd_lag_manager_address']['table'] = 'field_data_field_enrd_lag_manager_address';
  $handler->display->display_options['fields']['field_enrd_lag_manager_address']['field'] = 'field_enrd_lag_manager_address';
  $handler->display->display_options['fields']['field_enrd_lag_manager_address']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_lag_manager_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_enrd_lag_manager_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Flags: Flagged */
  $handler->display->display_options['sorts']['flagged']['id'] = 'flagged';
  $handler->display->display_options['sorts']['flagged']['table'] = 'flagging';
  $handler->display->display_options['sorts']['flagged']['field'] = 'flagged';
  $handler->display->display_options['sorts']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['sorts']['flagged']['order'] = 'DESC';
  /* Sort criterion: Content: Title (title_field) */
  $handler->display->display_options['sorts']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['sorts']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'lag' => 'lag',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['use_ajax_flags'] = array(
    'enrd_follow_lags' => 'enrd_follow_lags',
    'enrd_follow_cooperation_offers' => 0,
    'enrd_follow_events' => 0,
    'enrd_follow_news' => 0,
    'email_news' => 0,
    'email_events' => 0,
    'enrd_message_read_unread' => 0,
    'email_cooperation_offers' => 0,
    'email_lags' => 0,
  );
  $handler->display->display_options['path'] = 'user/%/notifications/%';

  /* Display: All flaggable LAGs */
  $handler = $view->new_display('page', 'All flaggable LAGs', 'flag_all_lags');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 1,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => '',
          'format' => 'full_html',
        ),
      ),
      'allow_secondary' => 1,
      'secondary_label' => 'Advanced search',
      'secondary_collapse_override' => '1',
    ),
    'combine' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_enrd_lag_country_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_select_all_none_nested' => 0,
        'bef_term_description' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 1,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_enrd_main_esi_fund_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_select_all_none_nested' => 0,
        'bef_term_description' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 1,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_enrd_esif_programme_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_select_all_none_nested' => 0,
        'bef_term_description' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 1,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '1';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'LAGs per page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '25, 50, 75, 100';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = 'All';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'ops' => 'ops',
    'ops_1' => 'ops_1',
    'field_enrd_lag_strategy_info' => 'field_enrd_lag_strategy_info',
    'field_enrd_lag_clld_email' => 'field_enrd_lag_clld_email',
    'field_enrd_lag_clld_name' => 'field_enrd_lag_clld_name',
    'field_enrd_lag_code' => 'field_enrd_lag_code',
    'field_enrd_lag_manager_name' => 'field_enrd_lag_manager_name',
    'field_enrd_lag_manager_email' => 'field_enrd_lag_manager_email',
    'field_enrd_lag_geo_coverage' => 'field_enrd_lag_geo_coverage',
    'field_enrd_lag_other_funding' => 'field_enrd_lag_other_funding',
    'field_enrd_lag_phone' => 'field_enrd_lag_phone',
    'field_enrd_lag_geo_coverage_sub' => 'field_enrd_lag_geo_coverage_sub',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ops' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ops_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_strategy_info' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_clld_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_clld_name' => array(
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
    'field_enrd_lag_manager_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_manager_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_geo_coverage' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_other_funding' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_geo_coverage_sub' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['empty'] = TRUE;
  $handler->display->display_options['header']['view']['view_to_insert'] = 'enrd_notifications_node_flags:flag_group_lags';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<h2>Search LAGs</h2>
<p>Start to type in the "Search in the LAG Database" field or use the "Advanced search" filters to find LAGs you may be interested in.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '<span class=\'enrd-notifications-lag-display results-count\'>Displaying @start - @end of @total</span>';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No LAG found with the provided search filters.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: enrd_follow_lags */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'enrd_follow_lags';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'enrd_follow_lags';
  /* Relationship: Flags: email_lags */
  $handler->display->display_options['relationships']['flag_content_rel_1']['id'] = 'flag_content_rel_1';
  $handler->display->display_options['relationships']['flag_content_rel_1']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel_1']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel_1']['label'] = 'enrd_email_lags';
  $handler->display->display_options['relationships']['flag_content_rel_1']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel_1']['flag'] = 'email_lags';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'LAG name';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = 'Follow?';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops_1']['id'] = 'ops_1';
  $handler->display->display_options['fields']['ops_1']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops_1']['field'] = 'ops';
  $handler->display->display_options['fields']['ops_1']['relationship'] = 'flag_content_rel_1';
  $handler->display->display_options['fields']['ops_1']['label'] = 'Send Email?';
  /* Field: Content: Additional information on the strategy */
  $handler->display->display_options['fields']['field_enrd_lag_strategy_info']['id'] = 'field_enrd_lag_strategy_info';
  $handler->display->display_options['fields']['field_enrd_lag_strategy_info']['table'] = 'field_data_field_enrd_lag_strategy_info';
  $handler->display->display_options['fields']['field_enrd_lag_strategy_info']['field'] = 'field_enrd_lag_strategy_info';
  $handler->display->display_options['fields']['field_enrd_lag_strategy_info']['exclude'] = TRUE;
  /* Field: Content: Contact email */
  $handler->display->display_options['fields']['field_enrd_lag_clld_email']['id'] = 'field_enrd_lag_clld_email';
  $handler->display->display_options['fields']['field_enrd_lag_clld_email']['table'] = 'field_data_field_enrd_lag_clld_email';
  $handler->display->display_options['fields']['field_enrd_lag_clld_email']['field'] = 'field_enrd_lag_clld_email';
  $handler->display->display_options['fields']['field_enrd_lag_clld_email']['exclude'] = TRUE;
  /* Field: Content: Contact name */
  $handler->display->display_options['fields']['field_enrd_lag_clld_name']['id'] = 'field_enrd_lag_clld_name';
  $handler->display->display_options['fields']['field_enrd_lag_clld_name']['table'] = 'field_data_field_enrd_lag_clld_name';
  $handler->display->display_options['fields']['field_enrd_lag_clld_name']['field'] = 'field_enrd_lag_clld_name';
  $handler->display->display_options['fields']['field_enrd_lag_clld_name']['exclude'] = TRUE;
  /* Field: Content: LAG code */
  $handler->display->display_options['fields']['field_enrd_lag_code']['id'] = 'field_enrd_lag_code';
  $handler->display->display_options['fields']['field_enrd_lag_code']['table'] = 'field_data_field_enrd_lag_code';
  $handler->display->display_options['fields']['field_enrd_lag_code']['field'] = 'field_enrd_lag_code';
  $handler->display->display_options['fields']['field_enrd_lag_code']['exclude'] = TRUE;
  /* Field: Content: LAG manager (Name and Surname) */
  $handler->display->display_options['fields']['field_enrd_lag_manager_name']['id'] = 'field_enrd_lag_manager_name';
  $handler->display->display_options['fields']['field_enrd_lag_manager_name']['table'] = 'field_data_field_enrd_lag_manager_name';
  $handler->display->display_options['fields']['field_enrd_lag_manager_name']['field'] = 'field_enrd_lag_manager_name';
  $handler->display->display_options['fields']['field_enrd_lag_manager_name']['label'] = 'LAG manager';
  $handler->display->display_options['fields']['field_enrd_lag_manager_name']['exclude'] = TRUE;
  /* Field: Content: LAG manager email */
  $handler->display->display_options['fields']['field_enrd_lag_manager_email']['id'] = 'field_enrd_lag_manager_email';
  $handler->display->display_options['fields']['field_enrd_lag_manager_email']['table'] = 'field_data_field_enrd_lag_manager_email';
  $handler->display->display_options['fields']['field_enrd_lag_manager_email']['field'] = 'field_enrd_lag_manager_email';
  $handler->display->display_options['fields']['field_enrd_lag_manager_email']['exclude'] = TRUE;
  /* Field: Content: Municipalities covered */
  $handler->display->display_options['fields']['field_enrd_lag_geo_coverage']['id'] = 'field_enrd_lag_geo_coverage';
  $handler->display->display_options['fields']['field_enrd_lag_geo_coverage']['table'] = 'field_data_field_enrd_lag_geo_coverage';
  $handler->display->display_options['fields']['field_enrd_lag_geo_coverage']['field'] = 'field_enrd_lag_geo_coverage';
  $handler->display->display_options['fields']['field_enrd_lag_geo_coverage']['exclude'] = TRUE;
  /* Field: Content: Other funding schemes used */
  $handler->display->display_options['fields']['field_enrd_lag_other_funding']['id'] = 'field_enrd_lag_other_funding';
  $handler->display->display_options['fields']['field_enrd_lag_other_funding']['table'] = 'field_data_field_enrd_lag_other_funding';
  $handler->display->display_options['fields']['field_enrd_lag_other_funding']['field'] = 'field_enrd_lag_other_funding';
  $handler->display->display_options['fields']['field_enrd_lag_other_funding']['exclude'] = TRUE;
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_enrd_lag_phone']['id'] = 'field_enrd_lag_phone';
  $handler->display->display_options['fields']['field_enrd_lag_phone']['table'] = 'field_data_field_enrd_lag_phone';
  $handler->display->display_options['fields']['field_enrd_lag_phone']['field'] = 'field_enrd_lag_phone';
  $handler->display->display_options['fields']['field_enrd_lag_phone']['exclude'] = TRUE;
  /* Field: Content: Sub-municipal level */
  $handler->display->display_options['fields']['field_enrd_lag_geo_coverage_sub']['id'] = 'field_enrd_lag_geo_coverage_sub';
  $handler->display->display_options['fields']['field_enrd_lag_geo_coverage_sub']['table'] = 'field_data_field_enrd_lag_geo_coverage_sub';
  $handler->display->display_options['fields']['field_enrd_lag_geo_coverage_sub']['field'] = 'field_enrd_lag_geo_coverage_sub';
  $handler->display->display_options['fields']['field_enrd_lag_geo_coverage_sub']['exclude'] = TRUE;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_enrd_lag_manager_address']['id'] = 'field_enrd_lag_manager_address';
  $handler->display->display_options['fields']['field_enrd_lag_manager_address']['table'] = 'field_data_field_enrd_lag_manager_address';
  $handler->display->display_options['fields']['field_enrd_lag_manager_address']['field'] = 'field_enrd_lag_manager_address';
  $handler->display->display_options['fields']['field_enrd_lag_manager_address']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_lag_manager_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_enrd_lag_manager_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Flags: Flagged */
  $handler->display->display_options['sorts']['flagged']['id'] = 'flagged';
  $handler->display->display_options['sorts']['flagged']['table'] = 'flagging';
  $handler->display->display_options['sorts']['flagged']['field'] = 'flagged';
  $handler->display->display_options['sorts']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['sorts']['flagged']['order'] = 'DESC';
  /* Sort criterion: Content: Title (title_field) */
  $handler->display->display_options['sorts']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['sorts']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'lag' => 'lag',
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
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search in the LAG Database';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'search';
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
    'title' => 'title',
    'field_enrd_lag_strategy_info' => 'field_enrd_lag_strategy_info',
    'field_enrd_lag_clld_email' => 'field_enrd_lag_clld_email',
    'field_enrd_lag_clld_name' => 'field_enrd_lag_clld_name',
    'field_enrd_lag_code' => 'field_enrd_lag_code',
    'field_enrd_lag_manager_name' => 'field_enrd_lag_manager_name',
    'field_enrd_lag_manager_email' => 'field_enrd_lag_manager_email',
    'field_enrd_lag_geo_coverage' => 'field_enrd_lag_geo_coverage',
    'field_enrd_lag_other_funding' => 'field_enrd_lag_other_funding',
    'field_enrd_lag_phone' => 'field_enrd_lag_phone',
    'field_enrd_lag_geo_coverage_sub' => 'field_enrd_lag_geo_coverage_sub',
    'field_enrd_lag_manager_address' => 'field_enrd_lag_manager_address',
  );
  /* Filter criterion: Field: Country (field_enrd_lag_country) */
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['id'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['table'] = 'field_data_field_enrd_lag_country';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['field'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['operator_id'] = 'field_enrd_lag_country_tid_op';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['operator'] = 'field_enrd_lag_country_tid_op';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['identifier'] = 'country';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['vocabulary'] = 'enrd_countries';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Main ESI Fund (field_enrd_main_esi_fund) */
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['id'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['table'] = 'field_data_field_enrd_main_esi_fund';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['field'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['operator_id'] = 'field_enrd_main_esi_fund_tid_op';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['label'] = 'ESI Fund';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['operator'] = 'field_enrd_main_esi_fund_tid_op';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['identifier'] = 'esi_fund';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['vocabulary'] = 'enrd_esi_funds';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: ESIF Programme (field_enrd_esif_programme) */
  $handler->display->display_options['filters']['field_enrd_esif_programme_tid']['id'] = 'field_enrd_esif_programme_tid';
  $handler->display->display_options['filters']['field_enrd_esif_programme_tid']['table'] = 'field_data_field_enrd_esif_programme';
  $handler->display->display_options['filters']['field_enrd_esif_programme_tid']['field'] = 'field_enrd_esif_programme_tid';
  $handler->display->display_options['filters']['field_enrd_esif_programme_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_esif_programme_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_esif_programme_tid']['expose']['operator_id'] = 'field_enrd_esif_programme_tid_op';
  $handler->display->display_options['filters']['field_enrd_esif_programme_tid']['expose']['label'] = 'ESIF Programme';
  $handler->display->display_options['filters']['field_enrd_esif_programme_tid']['expose']['operator'] = 'field_enrd_esif_programme_tid_op';
  $handler->display->display_options['filters']['field_enrd_esif_programme_tid']['expose']['identifier'] = 'esif_programme';
  $handler->display->display_options['filters']['field_enrd_esif_programme_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_esif_programme_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_enrd_esif_programme_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_esif_programme_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_enrd_esif_programme_tid']['vocabulary'] = 'enrd_esif_programme';
  $handler->display->display_options['filters']['field_enrd_esif_programme_tid']['hierarchy'] = 1;
  /* Filter criterion: Flags: Flagged */
  $handler->display->display_options['filters']['flagged']['id'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['table'] = 'flagging';
  $handler->display->display_options['filters']['flagged']['field'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['flagged']['value'] = '0';
  $handler->display->display_options['use_ajax_flags'] = array(
    'enrd_follow_lags' => 'enrd_follow_lags',
    'enrd_follow_cooperation_offers' => 0,
    'enrd_follow_events' => 0,
    'enrd_follow_news' => 0,
    'email_news' => 0,
    'email_events' => 0,
    'enrd_message_read_unread' => 0,
    'email_cooperation_offers' => 0,
    'email_lags' => 0,
  );
  $handler->display->display_options['path'] = 'user/%/notifications/%';
  $export['enrd_notifications_node_flags'] = $view;

  $view = new view();
  $view->name = 'enrd_notifications_user_flags';
  $view->description = 'Shows content types a user has flagged in notifications settings panel.';
  $view->tag = 'ENRD Notifications';
  $view->base_table = 'users';
  $view->human_name = 'ENRD Notifications Node types flags';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<span class="enrd-notifications-content-display intro"><span class="glyphicon glyphicon-info-sign"></span>Here you can configure the notifications for News, Events, Cooperation offers (all cooperation offers of all Lags). If you want to receive also email notifications, after having clicked on “follow” you need to select also the checkbox “Send Email?”.</span>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'You\'re not following anything of this type.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Relationship: Flags: enrd_follow_news */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'enrd_follow_news';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'enrd_follow_news';
  /* Relationship: Flags: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'flagging';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'flag_content_rel';
  /* Relationship: Flags: email_news */
  $handler->display->display_options['relationships']['flag_content_rel_1']['id'] = 'flag_content_rel_1';
  $handler->display->display_options['relationships']['flag_content_rel_1']['table'] = 'users';
  $handler->display->display_options['relationships']['flag_content_rel_1']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel_1']['label'] = 'email_news';
  $handler->display->display_options['relationships']['flag_content_rel_1']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel_1']['flag'] = 'email_news';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops_1']['id'] = 'ops_1';
  $handler->display->display_options['fields']['ops_1']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops_1']['field'] = 'ops';
  $handler->display->display_options['fields']['ops_1']['relationship'] = 'flag_content_rel_1';
  $handler->display->display_options['fields']['ops_1']['label'] = 'Send email?';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['uid']['validate']['fail'] = 'access denied';

  /* Display: Content type a user follows */
  $handler = $view->new_display('page', 'Content type a user follows', 'flag_node_type_list');
  $handler->display->display_options['display_description'] = 'Shows content types a user follows.';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<span class="enrd-notifications-content-display intro"><span class="glyphicon glyphicon-info-sign"></span>Here you can set your notifications for ENRD news, events, and cooperation offers. You can choose to receive both onsite messages and email notifications - click on \'follow\' and on the checkbox \'Send Email?\'.</span>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: enrd_follow_news */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'enrd_follow_news';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'enrd_follow_news';
  /* Relationship: Flags: enrd_follow_events */
  $handler->display->display_options['relationships']['flag_content_rel_2']['id'] = 'flag_content_rel_2';
  $handler->display->display_options['relationships']['flag_content_rel_2']['table'] = 'users';
  $handler->display->display_options['relationships']['flag_content_rel_2']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel_2']['label'] = 'enrd_follow_events';
  $handler->display->display_options['relationships']['flag_content_rel_2']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel_2']['flag'] = 'enrd_follow_events';
  /* Relationship: Flags: enrd_follow_cooperation_offers */
  $handler->display->display_options['relationships']['flag_content_rel_4']['id'] = 'flag_content_rel_4';
  $handler->display->display_options['relationships']['flag_content_rel_4']['table'] = 'users';
  $handler->display->display_options['relationships']['flag_content_rel_4']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel_4']['label'] = 'enrd_follow_cooperation_offers';
  $handler->display->display_options['relationships']['flag_content_rel_4']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel_4']['flag'] = 'enrd_follow_cooperation_offers';
  /* Relationship: Flags: email_news */
  $handler->display->display_options['relationships']['flag_content_rel_1']['id'] = 'flag_content_rel_1';
  $handler->display->display_options['relationships']['flag_content_rel_1']['table'] = 'users';
  $handler->display->display_options['relationships']['flag_content_rel_1']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel_1']['label'] = 'email_news';
  $handler->display->display_options['relationships']['flag_content_rel_1']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel_1']['flag'] = 'email_news';
  /* Relationship: Flags: email_events */
  $handler->display->display_options['relationships']['flag_content_rel_3']['id'] = 'flag_content_rel_3';
  $handler->display->display_options['relationships']['flag_content_rel_3']['table'] = 'users';
  $handler->display->display_options['relationships']['flag_content_rel_3']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel_3']['label'] = 'email_events';
  $handler->display->display_options['relationships']['flag_content_rel_3']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel_3']['flag'] = 'email_events';
  /* Relationship: Flags: email_cooperation_offers */
  $handler->display->display_options['relationships']['flag_content_rel_5']['id'] = 'flag_content_rel_5';
  $handler->display->display_options['relationships']['flag_content_rel_5']['table'] = 'users';
  $handler->display->display_options['relationships']['flag_content_rel_5']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel_5']['label'] = 'email_cooperation_offers';
  $handler->display->display_options['relationships']['flag_content_rel_5']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel_5']['flag'] = 'email_cooperation_offers';
  /* Relationship: Flags: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'flagging';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'flag_content_rel';
  /* Relationship: Flags: User */
  $handler->display->display_options['relationships']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['relationships']['uid_1']['table'] = 'flagging';
  $handler->display->display_options['relationships']['uid_1']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid_1']['relationship'] = 'flag_content_rel_2';
  /* Relationship: Flags: User */
  $handler->display->display_options['relationships']['uid_2']['id'] = 'uid_2';
  $handler->display->display_options['relationships']['uid_2']['table'] = 'flagging';
  $handler->display->display_options['relationships']['uid_2']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid_2']['relationship'] = 'flag_content_rel_4';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = 'News';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops_1']['id'] = 'ops_1';
  $handler->display->display_options['fields']['ops_1']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops_1']['field'] = 'ops';
  $handler->display->display_options['fields']['ops_1']['relationship'] = 'flag_content_rel_1';
  $handler->display->display_options['fields']['ops_1']['label'] = 'Send email?';
  $handler->display->display_options['fields']['ops_1']['element_label_colon'] = FALSE;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops_2']['id'] = 'ops_2';
  $handler->display->display_options['fields']['ops_2']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops_2']['field'] = 'ops';
  $handler->display->display_options['fields']['ops_2']['relationship'] = 'flag_content_rel_2';
  $handler->display->display_options['fields']['ops_2']['label'] = 'Events';
  $handler->display->display_options['fields']['ops_2']['element_label_colon'] = FALSE;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops_3']['id'] = 'ops_3';
  $handler->display->display_options['fields']['ops_3']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops_3']['field'] = 'ops';
  $handler->display->display_options['fields']['ops_3']['relationship'] = 'flag_content_rel_3';
  $handler->display->display_options['fields']['ops_3']['label'] = 'Send email?';
  $handler->display->display_options['fields']['ops_3']['element_label_colon'] = FALSE;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops_4']['id'] = 'ops_4';
  $handler->display->display_options['fields']['ops_4']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops_4']['field'] = 'ops';
  $handler->display->display_options['fields']['ops_4']['relationship'] = 'flag_content_rel_4';
  $handler->display->display_options['fields']['ops_4']['label'] = 'Cooperation offers';
  $handler->display->display_options['fields']['ops_4']['element_label_colon'] = FALSE;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops_5']['id'] = 'ops_5';
  $handler->display->display_options['fields']['ops_5']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops_5']['field'] = 'ops';
  $handler->display->display_options['fields']['ops_5']['relationship'] = 'flag_content_rel_5';
  $handler->display->display_options['fields']['ops_5']['label'] = 'Send email?';
  $handler->display->display_options['fields']['ops_5']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'user/%/notifications/content';
  $export['enrd_notifications_user_flags'] = $view;

  return $export;
}
