<?php

/**
 * @file
 * agri_core.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function agri_core_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'agri_communities_content';
  $view->description = 'Shows latest content of a community.';
  $view->tag = 'AGRI Administrations';
  $view->base_table = 'node';
  $view->human_name = 'AGRI OG Communities Content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Latest Content';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '7';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = ' No content has been added recently.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: OG membership: OG membership from Content */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Publication date - end date (field_core_publication_date:value2) */
  $handler->display->display_options['filters']['field_core_publication_date_value2']['id'] = 'field_core_publication_date_value2';
  $handler->display->display_options['filters']['field_core_publication_date_value2']['table'] = 'field_data_field_core_publication_date';
  $handler->display->display_options['filters']['field_core_publication_date_value2']['field'] = 'field_core_publication_date_value2';
  $handler->display->display_options['filters']['field_core_publication_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_core_publication_date_value2']['group'] = 2;
  $handler->display->display_options['filters']['field_core_publication_date_value2']['default_date'] = 'today';

  /* Display: AGRI OG Communities Content */
  $handler = $view->new_display('block', 'AGRI OG Communities Content', 'block_content');
  $handler->display->display_options['display_description'] = 'Shows latest content of a community.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = ' <i class="icon-[type]"></i>[title]';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['link_class'] = 'list-group-item';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '65';
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $export['agri_communities_content'] = $view;

  $view = new view();
  $view->name = 'agri_communities_members';
  $view->description = 'Newest group members.';
  $view->tag = 'AGRI Administrations';
  $view->base_table = 'users';
  $view->human_name = 'AGRI Communities Members';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Latest Members';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No users\' list available.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: OG membership: OG membership from User */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_firstname']['id'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['table'] = 'field_data_field_firstname';
  $handler->display->display_options['fields']['field_firstname']['field'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['label'] = '';
  $handler->display->display_options['fields']['field_firstname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_firstname']['element_label_colon'] = FALSE;
  /* Field: User: Last name */
  $handler->display->display_options['fields']['field_lastname']['id'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['table'] = 'field_data_field_lastname';
  $handler->display->display_options['fields']['field_lastname']['field'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['label'] = '';
  $handler->display->display_options['fields']['field_lastname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lastname']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[field_firstname] [field_lastname]';
  $handler->display->display_options['fields']['name']['alter']['path'] = 'users/[name]';
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['link_class'] = 'list-group-item';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: Link */
  $handler->display->display_options['fields']['view_user']['id'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['table'] = 'users';
  $handler->display->display_options['fields']['view_user']['field'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['label'] = '';
  $handler->display->display_options['fields']['view_user']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_user']['alter']['text'] = '[name]';
  $handler->display->display_options['fields']['view_user']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['view_user']['alter']['path'] = '[view_user]';
  $handler->display->display_options['fields']['view_user']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['view_user']['alter']['link_class'] = 'list-group-item';
  $handler->display->display_options['fields']['view_user']['element_label_colon'] = FALSE;
  /* Sort criterion: OG membership: Created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'og_membership';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: OG membership: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'og_membership';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['filters']['state']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: User: The user ID */
  $handler->display->display_options['filters']['uid_raw']['id'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['table'] = 'users';
  $handler->display->display_options['filters']['uid_raw']['field'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['operator'] = '!=';
  $handler->display->display_options['filters']['uid_raw']['value']['value'] = '1';

  /* Display: Latest members */
  $handler = $view->new_display('block', 'Latest members', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['agri_communities_members'] = $view;

  $view = new view();
  $view->name = 'agri_core_content_admin';
  $view->description = 'Emulates the Drupal content administration page.';
  $view->tag = 'AGRI Core';
  $view->base_table = 'node';
  $view->human_name = 'AGRI Core Content Administration';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Manage content';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer nodes';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'timestamp' => 'title',
    'state' => 'state',
    'type' => 'type',
    'name' => 'name',
    'created' => 'created',
    'changed' => 'changed',
    'view_node' => 'view_node',
    'edit_node' => 'view_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
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
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '&nbsp;',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No content available.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
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
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'New?';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['link_class'] = 'btn btn-default btn-xs';
  $handler->display->display_options['fields']['view_node']['element_class'] = 'no-wrap';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['link_class'] = 'btn btn-default btn-xs btn-success';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 0;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title contains';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 0;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Node: Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = 'All';
  $handler->display->display_options['filters']['promote']['group'] = 0;
  $handler->display->display_options['filters']['promote']['exposed'] = TRUE;
  $handler->display->display_options['filters']['promote']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['promote']['expose']['label'] = 'Promoted';
  $handler->display->display_options['filters']['promote']['expose']['operator'] = 'promote_op';
  $handler->display->display_options['filters']['promote']['expose']['identifier'] = 'promote';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 0;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title contains';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 0;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = 'All';
  $handler->display->display_options['filters']['promote']['group'] = 0;
  $handler->display->display_options['filters']['promote']['exposed'] = TRUE;
  $handler->display->display_options['filters']['promote']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['promote']['expose']['label'] = 'Promoted';
  $handler->display->display_options['filters']['promote']['expose']['operator'] = 'promote_op';
  $handler->display->display_options['filters']['promote']['expose']['identifier'] = 'promote';
  $handler->display->display_options['filters']['promote']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    10 => 0,
    8 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    10 => 0,
    8 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
  );
  $handler->display->display_options['path'] = 'manage/content';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Content management';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-core-action-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Content Management';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'user-menu';
  $export['agri_core_content_admin'] = $view;

  $view = new view();
  $view->name = 'agri_og_user_groups';
  $view->description = 'Show groups of a user.';
  $view->tag = 'AGRI Core';
  $view->base_table = 'og_membership';
  $view->human_name = 'AGRI OG User groups';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My Collaborative Areas';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'state' => 'state',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'state' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'User is not a member of any group.';
  /* Relationship: OG membership: Group Content from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_node_group']['id'] = 'og_membership_related_node_group';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['field'] = 'og_membership_related_node_group';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: OG membership: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'og_membership';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Member since';
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'time ago';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'og_membership_related_node_group';
  /* Contextual filter: We pass the user ID as the Entity ID. */
  $handler->display->display_options['arguments']['etid']['id'] = 'etid';
  $handler->display->display_options['arguments']['etid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['etid']['field'] = 'etid';
  $handler->display->display_options['arguments']['etid']['ui_name'] = 'We pass the user ID as the Entity ID.';
  $handler->display->display_options['arguments']['etid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['etid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['etid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['etid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['etid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['etid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['etid']['validate']['type'] = 'user';
  /* Filter criterion: OG membership: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'og_membership';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['relationship'] = 'og_membership';
  $handler->display->display_options['filters']['state']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: OG membership: Entity_type */
  $handler->display->display_options['filters']['entity_type']['id'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['table'] = 'og_membership';
  $handler->display->display_options['filters']['entity_type']['field'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['value'] = 'user';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['filters']['type']['value'] = array(
    'collaborative_area' => 'collaborative_area',
  );

  /* Display: Collaborative Areas */
  $handler = $view->new_display('block', 'Collaborative Areas', 'block_1');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'User is not a member of any collaborative area.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $export['agri_og_user_groups'] = $view;

  $view = new view();
  $view->name = 'agri_reported_forum_topics';
  $view->description = 'Shows a list of forum topics reported by users.';
  $view->tag = 'AGRI Core';
  $view->base_table = 'node';
  $view->human_name = 'AGRI Reported forum topics';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Reported forum topics';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'timestamp' => 'timestamp',
    'name' => 'name',
    'count' => 'count',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
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
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'count' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'There are no reported topics.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Flags: agri_core_report_forum_topics */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'agri_core_report_forum_topics';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  /* Relationship: Flags: agri_core_report_forum_topics counter */
  $handler->display->display_options['relationships']['flag_count_rel']['id'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_count_rel']['field'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['flag'] = 'agri_core_report_forum_topics';
  /* Relationship: Flags: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'flagging';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'flag_content_rel';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Operations';
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
      'label' => 'Delete topic',
    ),
    'action::flag_node_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Unflag (or flag) topic',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Topic';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Flags: Flagged time */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'flagging';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'custom';
  $handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'd/m/Y - H:i:s';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'eip_agri_long';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Flagging user';
  /* Field: Flags: Flag counter */
  $handler->display->display_options['fields']['count']['id'] = 'count';
  $handler->display->display_options['fields']['count']['table'] = 'flag_counts';
  $handler->display->display_options['fields']['count']['field'] = 'count';
  $handler->display->display_options['fields']['count']['relationship'] = 'flag_count_rel';
  $handler->display->display_options['fields']['count']['separator'] = '.';
  /* Sort criterion: Flags: Flagged time */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'flagging';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/reports/agri-reported-topics';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Reported forum topics';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['agri_reported_forum_topics'] = $view;

  $view = new view();
  $view->name = 'agri_reported_topics_comments';
  $view->description = 'Shows a list of topics comments reported by users.';
  $view->tag = 'AGRI Core';
  $view->base_table = 'comment';
  $view->human_name = 'AGRI Reported topics comments';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Reported topics comments';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'subject' => 'subject',
    'timestamp' => 'timestamp',
    'name' => 'name',
    'count' => 'count',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'subject' => array(
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
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'count' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'There are no reported comments.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Comment: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'comment';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Relationship: Flags: agri_core_report_topic_comments */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'comment';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'agri_core_report_topic_comments';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  /* Relationship: Flags: agri_core_report_topic_comments counter */
  $handler->display->display_options['relationships']['flag_count_rel']['id'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['table'] = 'comment';
  $handler->display->display_options['relationships']['flag_count_rel']['field'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['flag'] = 'agri_core_report_topic_comments';
  /* Relationship: Flags: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'flagging';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'flag_content_rel';
  /* Field: Bulk operations: Comment */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_comment';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Operations';
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
      'label' => 'Delete comment',
    ),
    'action::flag_comment_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Unflag (or flag) comment',
    ),
  );
  /* Field: Comment: Title */
  $handler->display->display_options['fields']['subject']['id'] = 'subject';
  $handler->display->display_options['fields']['subject']['table'] = 'comment';
  $handler->display->display_options['fields']['subject']['field'] = 'subject';
  $handler->display->display_options['fields']['subject']['label'] = 'Comment';
  $handler->display->display_options['fields']['subject']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['subject']['alter']['ellipsis'] = FALSE;
  /* Field: Flags: Flagged time */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'flagging';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'custom';
  $handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'd/m/Y - H:i:s';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'eip_agri_long';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Flagging user';
  /* Field: Flags: Flag counter */
  $handler->display->display_options['fields']['count']['id'] = 'count';
  $handler->display->display_options['fields']['count']['table'] = 'flag_counts';
  $handler->display->display_options['fields']['count']['field'] = 'count';
  $handler->display->display_options['fields']['count']['relationship'] = 'flag_count_rel';
  /* Filter criterion: Comment: Approved */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'comment';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_node']['id'] = 'status_node';
  $handler->display->display_options['filters']['status_node']['table'] = 'node';
  $handler->display->display_options['filters']['status_node']['field'] = 'status';
  $handler->display->display_options['filters']['status_node']['relationship'] = 'nid';
  $handler->display->display_options['filters']['status_node']['value'] = 1;
  $handler->display->display_options['filters']['status_node']['group'] = 1;
  $handler->display->display_options['filters']['status_node']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/reports/agri-reported-topics-comments';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Reported topics comments';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['agri_reported_topics_comments'] = $view;

  $view = new view();
  $view->name = 'agri_taxonomy_term';
  $view->description = 'A view to emulate Drupal core\'s handling of taxonomy/term.';
  $view->tag = 'AGRI Core';
  $view->base_table = 'node';
  $view->human_name = 'agri taxonomy term';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['term_node_tid_depth']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = '%1';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Has taxonomy term ID depth modifier */
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['id'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['field'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['specify_validation'] = TRUE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['empty'] = TRUE;
  $handler->display->display_options['header']['view']['view_to_insert'] = 'organizations_node_blocks:page_1';
  $handler->display->display_options['path'] = 'taxonomy/term/%';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 15;
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'taxonomy/term/%/%/feed';
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'page' => 0,
  );
  $export['agri_taxonomy_term'] = $view;

  $view = new view();
  $view->name = 'core_collaborative_area_events';
  $view->description = 'Shows events in a collaborative area.';
  $view->tag = 'AGRI Core';
  $view->base_table = 'node';
  $view->human_name = 'Core collaborative area events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Latest events';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'node|created';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'teaser';
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No events related to this collaborative area.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: OG membership: OG membership from Content */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Geographical scope */
  $handler->display->display_options['fields']['field_core_geographical_area']['id'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['table'] = 'field_data_field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['field'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['label'] = 'Country';
  $handler->display->display_options['fields']['field_core_geographical_area']['delta_offset'] = '0';
  /* Sort criterion: Content: Dates -  start date (field_event_date) */
  $handler->display->display_options['sorts']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['sorts']['field_event_date_value']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['sorts']['field_event_date_value']['field'] = 'field_event_date_value';
  $handler->display->display_options['sorts']['field_event_date_value']['order'] = 'DESC';
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
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
    'event' => 'event',
  );

  /* Display: Events in collaborative area */
  $handler = $view->new_display('block', 'Events in collaborative area', 'block');
  $export['core_collaborative_area_events'] = $view;

  $view = new view();
  $view->name = 'core_collaborative_area_pages';
  $view->description = 'Shows events in a collaborative area.';
  $view->tag = 'AGRI Core';
  $view->base_table = 'node';
  $view->human_name = 'Core collaborative area pages';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Latest pages';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'created' => 'created',
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
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No pages related to this collaborative area.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: OG membership: OG membership from Content */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['label'] = 'Author';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Authored by';
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
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
    'page' => 'page',
  );

  /* Display: Pages in collaborative area */
  $handler = $view->new_display('block', 'Pages in collaborative area', 'block');
  $export['core_collaborative_area_pages'] = $view;

  $view = new view();
  $view->name = 'core_collaborative_area_people';
  $view->description = '';
  $view->tag = 'AGRI Core';
  $view->base_table = 'users';
  $view->human_name = 'Core collaborative area people';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Members';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = 'Displaying users @start - @end of @total';
  /* Relationship: OG membership: OG membership from User */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Relationship: Field: Organization (field_organization_collection) */
  $handler->display->display_options['relationships']['field_organization_collection_value']['id'] = 'field_organization_collection_value';
  $handler->display->display_options['relationships']['field_organization_collection_value']['table'] = 'field_data_field_organization_collection';
  $handler->display->display_options['relationships']['field_organization_collection_value']['field'] = 'field_organization_collection_value';
  $handler->display->display_options['relationships']['field_organization_collection_value']['delta'] = '-1';
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_firstname']['id'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['table'] = 'field_data_field_firstname';
  $handler->display->display_options['fields']['field_firstname']['field'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['label'] = '';
  $handler->display->display_options['fields']['field_firstname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_firstname']['element_label_colon'] = FALSE;
  /* Field: User: Last name */
  $handler->display->display_options['fields']['field_lastname']['id'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['table'] = 'field_data_field_lastname';
  $handler->display->display_options['fields']['field_lastname']['field'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['label'] = '';
  $handler->display->display_options['fields']['field_lastname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lastname']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Full name';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[field_firstname] [field_lastname]';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Field: Geographical scope */
  $handler->display->display_options['fields']['field_core_geographical_area']['id'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['table'] = 'field_data_field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['field'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['label'] = 'Country';
  $handler->display->display_options['fields']['field_core_geographical_area']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_core_geographical_area']['delta_offset'] = '0';
  /* Field: Field collection item: Organization/Institution name (original language) */
  $handler->display->display_options['fields']['field_organization_name']['id'] = 'field_organization_name';
  $handler->display->display_options['fields']['field_organization_name']['table'] = 'field_data_field_organization_name';
  $handler->display->display_options['fields']['field_organization_name']['field'] = 'field_organization_name';
  $handler->display->display_options['fields']['field_organization_name']['relationship'] = 'field_organization_collection_value';
  $handler->display->display_options['fields']['field_organization_name']['label'] = 'Organization';
  /* Field: Field collection item: Field of activity of the organisation/institution */
  $handler->display->display_options['fields']['field_organization_activity']['id'] = 'field_organization_activity';
  $handler->display->display_options['fields']['field_organization_activity']['table'] = 'field_data_field_organization_activity';
  $handler->display->display_options['fields']['field_organization_activity']['field'] = 'field_organization_activity';
  $handler->display->display_options['fields']['field_organization_activity']['relationship'] = 'field_organization_collection_value';
  $handler->display->display_options['fields']['field_organization_activity']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_organization_activity']['delta_offset'] = '0';
  /* Sort criterion: OG membership: Created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'og_membership';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['granularity'] = 'day';
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'og';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: OG membership: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'og_membership';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['filters']['state']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: User: The user ID */
  $handler->display->display_options['filters']['uid_raw']['id'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['table'] = 'users';
  $handler->display->display_options['filters']['uid_raw']['field'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['operator'] = '!=';
  $handler->display->display_options['filters']['uid_raw']['value']['value'] = '1';

  /* Display: Collaborative area members */
  $handler = $view->new_display('block', 'Collaborative area members', 'block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_firstname']['id'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['table'] = 'field_data_field_firstname';
  $handler->display->display_options['fields']['field_firstname']['field'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['label'] = '';
  $handler->display->display_options['fields']['field_firstname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_firstname']['element_label_colon'] = FALSE;
  /* Field: User: Last name */
  $handler->display->display_options['fields']['field_lastname']['id'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['table'] = 'field_data_field_lastname';
  $handler->display->display_options['fields']['field_lastname']['field'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['label'] = '';
  $handler->display->display_options['fields']['field_lastname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lastname']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Full name';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[field_firstname] [field_lastname]';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Field: Geographical scope */
  $handler->display->display_options['fields']['field_core_geographical_area']['id'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['table'] = 'field_data_field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['field'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['relationship'] = 'field_organization_collection_value';
  $handler->display->display_options['fields']['field_core_geographical_area']['label'] = 'Country';
  $handler->display->display_options['fields']['field_core_geographical_area']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_core_geographical_area']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_core_geographical_area']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_core_geographical_area']['delta_offset'] = '0';
  /* Field: Field: Geographical scope */
  $handler->display->display_options['fields']['field_core_geographical_area_1']['id'] = 'field_core_geographical_area_1';
  $handler->display->display_options['fields']['field_core_geographical_area_1']['table'] = 'field_data_field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area_1']['field'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area_1']['label'] = 'Country';
  $handler->display->display_options['fields']['field_core_geographical_area_1']['empty'] = '[field_core_geographical_area]';
  $handler->display->display_options['fields']['field_core_geographical_area_1']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_core_geographical_area_1']['delta_offset'] = '0';
  /* Field: Field collection item: Organization/Institution name (original language) */
  $handler->display->display_options['fields']['field_organization_name']['id'] = 'field_organization_name';
  $handler->display->display_options['fields']['field_organization_name']['table'] = 'field_data_field_organization_name';
  $handler->display->display_options['fields']['field_organization_name']['field'] = 'field_organization_name';
  $handler->display->display_options['fields']['field_organization_name']['relationship'] = 'field_organization_collection_value';
  $handler->display->display_options['fields']['field_organization_name']['label'] = 'Organization';
  /* Field: Field collection item: Field of activity of the organisation/institution */
  $handler->display->display_options['fields']['field_organization_activity']['id'] = 'field_organization_activity';
  $handler->display->display_options['fields']['field_organization_activity']['table'] = 'field_data_field_organization_activity';
  $handler->display->display_options['fields']['field_organization_activity']['field'] = 'field_organization_activity';
  $handler->display->display_options['fields']['field_organization_activity']['relationship'] = 'field_organization_collection_value';
  $handler->display->display_options['fields']['field_organization_activity']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_organization_activity']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'og';
  $export['core_collaborative_area_people'] = $view;

  $view = new view();
  $view->name = 'core_community_events';
  $view->description = 'Shows events in a community.';
  $view->tag = 'AGRI Core';
  $view->base_table = 'node';
  $view->human_name = 'Core Community events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Latest events';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'node|created';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'teaser';
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No events related to this collaborative area.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: OG membership: OG membership from Content */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Geographical scope */
  $handler->display->display_options['fields']['field_core_geographical_area']['id'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['table'] = 'field_data_field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['field'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['label'] = 'Country';
  $handler->display->display_options['fields']['field_core_geographical_area']['delta_offset'] = '0';
  /* Sort criterion: Content: Dates -  start date (field_event_date) */
  $handler->display->display_options['sorts']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['sorts']['field_event_date_value']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['sorts']['field_event_date_value']['field'] = 'field_event_date_value';
  $handler->display->display_options['sorts']['field_event_date_value']['order'] = 'DESC';
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
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
    'event' => 'event',
  );

  /* Display: Events in community */
  $handler = $view->new_display('block', 'Events in community', 'block');
  $export['core_community_events'] = $view;

  $view = new view();
  $view->name = 'core_community_pages';
  $view->description = 'Shows pages in a community.';
  $view->tag = 'AGRI Core';
  $view->base_table = 'node';
  $view->human_name = 'Core Community pages';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Latest pages';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'created' => 'created',
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
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No pages related to this collaborative area.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: OG membership: OG membership from Content */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['label'] = 'Author';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Authored by';
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
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
    'page' => 'page',
  );

  /* Display: Pages in community */
  $handler = $view->new_display('block', 'Pages in community', 'block');
  $handler->display->display_options['display_description'] = 'Show pages in a community.';
  $export['core_community_pages'] = $view;

  $view = new view();
  $view->name = 'core_community_people';
  $view->description = 'Shows members of a community.';
  $view->tag = 'AGRI Core';
  $view->base_table = 'users';
  $view->human_name = 'Core Community people';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Members';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = 'Displaying users @start - @end of @total';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No active members.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: OG membership: OG membership from User */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Relationship: Field: Organization (field_organization_collection) */
  $handler->display->display_options['relationships']['field_organization_collection_value']['id'] = 'field_organization_collection_value';
  $handler->display->display_options['relationships']['field_organization_collection_value']['table'] = 'field_data_field_organization_collection';
  $handler->display->display_options['relationships']['field_organization_collection_value']['field'] = 'field_organization_collection_value';
  $handler->display->display_options['relationships']['field_organization_collection_value']['delta'] = '-1';
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_firstname']['id'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['table'] = 'field_data_field_firstname';
  $handler->display->display_options['fields']['field_firstname']['field'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['label'] = '';
  $handler->display->display_options['fields']['field_firstname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_firstname']['element_label_colon'] = FALSE;
  /* Field: User: Last name */
  $handler->display->display_options['fields']['field_lastname']['id'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['table'] = 'field_data_field_lastname';
  $handler->display->display_options['fields']['field_lastname']['field'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['label'] = '';
  $handler->display->display_options['fields']['field_lastname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lastname']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Full name';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[field_firstname] [field_lastname]';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Field: Geographical scope */
  $handler->display->display_options['fields']['field_core_geographical_area']['id'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['table'] = 'field_data_field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['field'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['label'] = 'Country';
  $handler->display->display_options['fields']['field_core_geographical_area']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_core_geographical_area']['delta_offset'] = '0';
  /* Field: Field collection item: Organization/Institution name (original language) */
  $handler->display->display_options['fields']['field_organization_name']['id'] = 'field_organization_name';
  $handler->display->display_options['fields']['field_organization_name']['table'] = 'field_data_field_organization_name';
  $handler->display->display_options['fields']['field_organization_name']['field'] = 'field_organization_name';
  $handler->display->display_options['fields']['field_organization_name']['relationship'] = 'field_organization_collection_value';
  $handler->display->display_options['fields']['field_organization_name']['label'] = 'Organization';
  /* Field: Field collection item: Field of activity of the organisation/institution */
  $handler->display->display_options['fields']['field_organization_activity']['id'] = 'field_organization_activity';
  $handler->display->display_options['fields']['field_organization_activity']['table'] = 'field_data_field_organization_activity';
  $handler->display->display_options['fields']['field_organization_activity']['field'] = 'field_organization_activity';
  $handler->display->display_options['fields']['field_organization_activity']['relationship'] = 'field_organization_collection_value';
  $handler->display->display_options['fields']['field_organization_activity']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_organization_activity']['delta_offset'] = '0';
  /* Sort criterion: OG membership: Created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'og_membership';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['granularity'] = 'day';
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'og';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: OG membership: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'og_membership';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['filters']['state']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: User: The user ID */
  $handler->display->display_options['filters']['uid_raw']['id'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['table'] = 'users';
  $handler->display->display_options['filters']['uid_raw']['field'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['operator'] = '!=';
  $handler->display->display_options['filters']['uid_raw']['value']['value'] = '1';

  /* Display: Community members */
  $handler = $view->new_display('block', 'Community members', 'block');
  $handler->display->display_options['display_description'] = 'Shows members of a community';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_firstname']['id'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['table'] = 'field_data_field_firstname';
  $handler->display->display_options['fields']['field_firstname']['field'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['label'] = '';
  $handler->display->display_options['fields']['field_firstname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_firstname']['element_label_colon'] = FALSE;
  /* Field: User: Last name */
  $handler->display->display_options['fields']['field_lastname']['id'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['table'] = 'field_data_field_lastname';
  $handler->display->display_options['fields']['field_lastname']['field'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['label'] = '';
  $handler->display->display_options['fields']['field_lastname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lastname']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Full name';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[field_firstname] [field_lastname]';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Field: Geographical scope */
  $handler->display->display_options['fields']['field_core_geographical_area']['id'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['table'] = 'field_data_field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['field'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['relationship'] = 'field_organization_collection_value';
  $handler->display->display_options['fields']['field_core_geographical_area']['label'] = 'Country';
  $handler->display->display_options['fields']['field_core_geographical_area']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_core_geographical_area']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_core_geographical_area']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_core_geographical_area']['delta_offset'] = '0';
  /* Field: Field: Geographical scope */
  $handler->display->display_options['fields']['field_core_geographical_area_1']['id'] = 'field_core_geographical_area_1';
  $handler->display->display_options['fields']['field_core_geographical_area_1']['table'] = 'field_data_field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area_1']['field'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area_1']['label'] = 'Country';
  $handler->display->display_options['fields']['field_core_geographical_area_1']['empty'] = '[field_core_geographical_area]';
  $handler->display->display_options['fields']['field_core_geographical_area_1']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_core_geographical_area_1']['delta_offset'] = '0';
  /* Field: Field collection item: Organization/Institution name (original language) */
  $handler->display->display_options['fields']['field_organization_name']['id'] = 'field_organization_name';
  $handler->display->display_options['fields']['field_organization_name']['table'] = 'field_data_field_organization_name';
  $handler->display->display_options['fields']['field_organization_name']['field'] = 'field_organization_name';
  $handler->display->display_options['fields']['field_organization_name']['relationship'] = 'field_organization_collection_value';
  $handler->display->display_options['fields']['field_organization_name']['label'] = 'Organization';
  /* Field: Field collection item: Field of activity of the organisation/institution */
  $handler->display->display_options['fields']['field_organization_activity']['id'] = 'field_organization_activity';
  $handler->display->display_options['fields']['field_organization_activity']['table'] = 'field_data_field_organization_activity';
  $handler->display->display_options['fields']['field_organization_activity']['field'] = 'field_organization_activity';
  $handler->display->display_options['fields']['field_organization_activity']['relationship'] = 'field_organization_collection_value';
  $handler->display->display_options['fields']['field_organization_activity']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_organization_activity']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'og';
  $export['core_community_people'] = $view;

  $view = new view();
  $view->name = 'core_find_people';
  $view->description = '';
  $view->tag = 'AGRI Core';
  $view->base_table = 'users';
  $view->human_name = 'Core find people';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Find people';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_user_picture' => 'field_user_picture',
    'realname' => 'realname',
    'mail' => 'realname',
    'field_core_geographical_area' => 'field_core_geographical_area',
    'field_organization_name' => 'field_organization_name',
    'field_organization_activity' => 'field_organization_name',
    'field_user_type' => 'field_user_type',
    'contact' => 'realname',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_user_picture' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'realname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_core_geographical_area' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_organization_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_organization_activity' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'contact' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Field: Organization (field_organization_collection) */
  $handler->display->display_options['relationships']['field_organization_collection_value']['id'] = 'field_organization_collection_value';
  $handler->display->display_options['relationships']['field_organization_collection_value']['table'] = 'field_data_field_organization_collection';
  $handler->display->display_options['relationships']['field_organization_collection_value']['field'] = 'field_organization_collection_value';
  $handler->display->display_options['relationships']['field_organization_collection_value']['delta'] = '-1';
  /* Field: User: Profile picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['label'] = 'Full name';
  $handler->display->display_options['fields']['realname']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['realname']['alter']['text'] = '<b>[realname]</b>';
  $handler->display->display_options['fields']['realname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['realname']['link_to_user'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mail']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['mail']['alter']['text'] = '<div class="grey small">[mail]</div>';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: User: Link to contact page */
  $handler->display->display_options['fields']['contact']['id'] = 'contact';
  $handler->display->display_options['fields']['contact']['table'] = 'users';
  $handler->display->display_options['fields']['contact']['field'] = 'contact';
  $handler->display->display_options['fields']['contact']['label'] = 'Contact';
  $handler->display->display_options['fields']['contact']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['contact']['alter']['text'] = '<div>[contact]</div>';
  $handler->display->display_options['fields']['contact']['text'] = 'Contact this user';
  /* Field: Field: Geographical scope */
  $handler->display->display_options['fields']['field_core_geographical_area']['id'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['table'] = 'field_data_field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['field'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['label'] = 'Country';
  $handler->display->display_options['fields']['field_core_geographical_area']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_core_geographical_area']['delta_offset'] = '0';
  /* Field: Field: User type */
  $handler->display->display_options['fields']['field_user_type']['id'] = 'field_user_type';
  $handler->display->display_options['fields']['field_user_type']['table'] = 'field_data_field_user_type';
  $handler->display->display_options['fields']['field_user_type']['field'] = 'field_user_type';
  $handler->display->display_options['fields']['field_user_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_type']['delta_offset'] = '0';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Featured in internal database (field_user_featured_internal_db) */
  $handler->display->display_options['filters']['field_user_featured_internal_db_value']['id'] = 'field_user_featured_internal_db_value';
  $handler->display->display_options['filters']['field_user_featured_internal_db_value']['table'] = 'field_data_field_user_featured_internal_db';
  $handler->display->display_options['filters']['field_user_featured_internal_db_value']['field'] = 'field_user_featured_internal_db_value';
  $handler->display->display_options['filters']['field_user_featured_internal_db_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: User: First name (field_firstname) */
  $handler->display->display_options['filters']['field_firstname_value']['id'] = 'field_firstname_value';
  $handler->display->display_options['filters']['field_firstname_value']['table'] = 'field_data_field_firstname';
  $handler->display->display_options['filters']['field_firstname_value']['field'] = 'field_firstname_value';
  $handler->display->display_options['filters']['field_firstname_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_firstname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_firstname_value']['expose']['operator_id'] = 'field_firstname_value_op';
  $handler->display->display_options['filters']['field_firstname_value']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_firstname_value']['expose']['operator'] = 'field_firstname_value_op';
  $handler->display->display_options['filters']['field_firstname_value']['expose']['identifier'] = 'field_firstname_value';
  $handler->display->display_options['filters']['field_firstname_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
  );
  /* Filter criterion: User: Last name (field_lastname) */
  $handler->display->display_options['filters']['field_lastname_value']['id'] = 'field_lastname_value';
  $handler->display->display_options['filters']['field_lastname_value']['table'] = 'field_data_field_lastname';
  $handler->display->display_options['filters']['field_lastname_value']['field'] = 'field_lastname_value';
  $handler->display->display_options['filters']['field_lastname_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_lastname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lastname_value']['expose']['operator_id'] = 'field_lastname_value_op';
  $handler->display->display_options['filters']['field_lastname_value']['expose']['label'] = 'Last name ';
  $handler->display->display_options['filters']['field_lastname_value']['expose']['operator'] = 'field_lastname_value_op';
  $handler->display->display_options['filters']['field_lastname_value']['expose']['identifier'] = 'field_lastname_value';
  $handler->display->display_options['filters']['field_lastname_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
  );
  /* Filter criterion: Field: User type (field_user_type) */
  $handler->display->display_options['filters']['field_user_type_tid']['id'] = 'field_user_type_tid';
  $handler->display->display_options['filters']['field_user_type_tid']['table'] = 'field_data_field_user_type';
  $handler->display->display_options['filters']['field_user_type_tid']['field'] = 'field_user_type_tid';
  $handler->display->display_options['filters']['field_user_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_type_tid']['expose']['operator_id'] = 'field_user_type_tid_op';
  $handler->display->display_options['filters']['field_user_type_tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_user_type_tid']['expose']['operator'] = 'field_user_type_tid_op';
  $handler->display->display_options['filters']['field_user_type_tid']['expose']['identifier'] = 'field_user_type_tid';
  $handler->display->display_options['filters']['field_user_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_user_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_user_type_tid']['vocabulary'] = 'core_user_type';
  /* Filter criterion: Field: Geographical scope (field_core_geographical_area) */
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['id'] = 'field_core_geographical_area_tid';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['table'] = 'field_data_field_core_geographical_area';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['field'] = 'field_core_geographical_area_tid';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['value'] = 'All';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['expose']['operator_id'] = 'field_core_geographical_area_tid_op';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['expose']['operator'] = 'field_core_geographical_area_tid_op';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['expose']['identifier'] = 'field_core_geographical_area_tid';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['vocabulary'] = 'core_geographical_area';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['hierarchy'] = 1;
  /* Filter criterion: Field: Keywords (field_core_keywords) */
  $handler->display->display_options['filters']['field_core_keywords_tid']['id'] = 'field_core_keywords_tid';
  $handler->display->display_options['filters']['field_core_keywords_tid']['table'] = 'field_data_field_core_keywords';
  $handler->display->display_options['filters']['field_core_keywords_tid']['field'] = 'field_core_keywords_tid';
  $handler->display->display_options['filters']['field_core_keywords_tid']['value'] = '';
  $handler->display->display_options['filters']['field_core_keywords_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['operator_id'] = 'field_core_keywords_tid_op';
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['label'] = 'Keywords';
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['operator'] = 'field_core_keywords_tid_op';
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['identifier'] = 'field_core_keywords_tid';
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_core_keywords_tid']['vocabulary'] = 'tags';

  /* Display: Find people */
  $handler = $view->new_display('page', 'Find people', 'page');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['path'] = 'disabled/find-people/all';
  $handler->display->display_options['menu']['title'] = 'All people';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Find people';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'user-menu';

  /* Display: people block in user profile */
  $handler = $view->new_display('block', 'people block in user profile', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'People';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'find-people';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No active users found.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field: Organization (field_organization_collection) */
  $handler->display->display_options['relationships']['field_organization_collection_value']['id'] = 'field_organization_collection_value';
  $handler->display->display_options['relationships']['field_organization_collection_value']['table'] = 'field_data_field_organization_collection';
  $handler->display->display_options['relationships']['field_organization_collection_value']['field'] = 'field_organization_collection_value';
  $handler->display->display_options['relationships']['field_organization_collection_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Profile picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['label'] = '';
  $handler->display->display_options['fields']['realname']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['realname']['alter']['text'] = '<b>[realname]</b>';
  $handler->display->display_options['fields']['realname']['element_type'] = 'strong';
  $handler->display->display_options['fields']['realname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['realname']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['realname']['link_to_user'] = FALSE;
  /* Field: Field: User type */
  $handler->display->display_options['fields']['field_user_type']['id'] = 'field_user_type';
  $handler->display->display_options['fields']['field_user_type']['table'] = 'field_data_field_user_type';
  $handler->display->display_options['fields']['field_user_type']['field'] = 'field_user_type';
  $handler->display->display_options['fields']['field_user_type']['label'] = 'Role';
  $handler->display->display_options['fields']['field_user_type']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_user_type']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_user_type']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_user_type']['element_wrapper_class'] = 'small';
  $handler->display->display_options['fields']['field_user_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_type']['delta_offset'] = '0';
  /* Field: Field: Geographical scope */
  $handler->display->display_options['fields']['field_core_geographical_area']['id'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['table'] = 'field_data_field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['field'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['relationship'] = 'field_organization_collection_value';
  $handler->display->display_options['fields']['field_core_geographical_area']['label'] = 'Location';
  $handler->display->display_options['fields']['field_core_geographical_area']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_core_geographical_area']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_core_geographical_area']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_core_geographical_area']['element_wrapper_class'] = 'small';
  $handler->display->display_options['fields']['field_core_geographical_area']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_core_geographical_area']['delta_offset'] = '0';
  /* Field: Field: Keywords */
  $handler->display->display_options['fields']['field_core_keywords']['id'] = 'field_core_keywords';
  $handler->display->display_options['fields']['field_core_keywords']['table'] = 'field_data_field_core_keywords';
  $handler->display->display_options['fields']['field_core_keywords']['field'] = 'field_core_keywords';
  $handler->display->display_options['fields']['field_core_keywords']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_core_keywords']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_core_keywords']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_core_keywords']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_core_keywords']['element_wrapper_class'] = 'small';
  $handler->display->display_options['fields']['field_core_keywords']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['not'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Featured in internal database (field_user_featured_internal_db) */
  $handler->display->display_options['filters']['field_user_featured_internal_db_value']['id'] = 'field_user_featured_internal_db_value';
  $handler->display->display_options['filters']['field_user_featured_internal_db_value']['table'] = 'field_data_field_user_featured_internal_db';
  $handler->display->display_options['filters']['field_user_featured_internal_db_value']['field'] = 'field_user_featured_internal_db_value';
  $handler->display->display_options['filters']['field_user_featured_internal_db_value']['value'] = array(
    1 => '1',
  );

  /* Display: Find advisers */
  $handler = $view->new_display('page', 'Find advisers', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Find advisers';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Profile picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['label'] = 'Full name';
  $handler->display->display_options['fields']['realname']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['realname']['alter']['text'] = '<b>[realname]</b>';
  $handler->display->display_options['fields']['realname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['realname']['link_to_user'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mail']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['mail']['alter']['text'] = '<div class="grey small">[mail]</div>';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: User: Link to contact page */
  $handler->display->display_options['fields']['contact']['id'] = 'contact';
  $handler->display->display_options['fields']['contact']['table'] = 'users';
  $handler->display->display_options['fields']['contact']['field'] = 'contact';
  $handler->display->display_options['fields']['contact']['label'] = 'Contact';
  $handler->display->display_options['fields']['contact']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['contact']['alter']['text'] = '<div>[contact]</div>';
  $handler->display->display_options['fields']['contact']['text'] = 'Contact this user';
  /* Field: Field: Geographical scope */
  $handler->display->display_options['fields']['field_core_geographical_area']['id'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['table'] = 'field_data_field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['field'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['label'] = 'Country';
  $handler->display->display_options['fields']['field_core_geographical_area']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_core_geographical_area']['delta_offset'] = '0';
  /* Field: Field: User type */
  $handler->display->display_options['fields']['field_user_type']['id'] = 'field_user_type';
  $handler->display->display_options['fields']['field_user_type']['table'] = 'field_data_field_user_type';
  $handler->display->display_options['fields']['field_user_type']['field'] = 'field_user_type';
  $handler->display->display_options['fields']['field_user_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_type']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Featured in internal database (field_user_featured_internal_db) */
  $handler->display->display_options['filters']['field_user_featured_internal_db_value']['id'] = 'field_user_featured_internal_db_value';
  $handler->display->display_options['filters']['field_user_featured_internal_db_value']['table'] = 'field_data_field_user_featured_internal_db';
  $handler->display->display_options['filters']['field_user_featured_internal_db_value']['field'] = 'field_user_featured_internal_db_value';
  $handler->display->display_options['filters']['field_user_featured_internal_db_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: User: First name (field_firstname) */
  $handler->display->display_options['filters']['field_firstname_value']['id'] = 'field_firstname_value';
  $handler->display->display_options['filters']['field_firstname_value']['table'] = 'field_data_field_firstname';
  $handler->display->display_options['filters']['field_firstname_value']['field'] = 'field_firstname_value';
  $handler->display->display_options['filters']['field_firstname_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_firstname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_firstname_value']['expose']['operator_id'] = 'field_firstname_value_op';
  $handler->display->display_options['filters']['field_firstname_value']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_firstname_value']['expose']['operator'] = 'field_firstname_value_op';
  $handler->display->display_options['filters']['field_firstname_value']['expose']['identifier'] = 'field_firstname_value';
  $handler->display->display_options['filters']['field_firstname_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
  );
  /* Filter criterion: User: Last name (field_lastname) */
  $handler->display->display_options['filters']['field_lastname_value']['id'] = 'field_lastname_value';
  $handler->display->display_options['filters']['field_lastname_value']['table'] = 'field_data_field_lastname';
  $handler->display->display_options['filters']['field_lastname_value']['field'] = 'field_lastname_value';
  $handler->display->display_options['filters']['field_lastname_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_lastname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lastname_value']['expose']['operator_id'] = 'field_lastname_value_op';
  $handler->display->display_options['filters']['field_lastname_value']['expose']['label'] = 'Last name ';
  $handler->display->display_options['filters']['field_lastname_value']['expose']['operator'] = 'field_lastname_value_op';
  $handler->display->display_options['filters']['field_lastname_value']['expose']['identifier'] = 'field_lastname_value';
  $handler->display->display_options['filters']['field_lastname_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
  );
  /* Filter criterion: Field: Geographical scope (field_core_geographical_area) */
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['id'] = 'field_core_geographical_area_tid';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['table'] = 'field_data_field_core_geographical_area';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['field'] = 'field_core_geographical_area_tid';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['value'] = 'All';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['expose']['operator_id'] = 'field_core_geographical_area_tid_op';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['expose']['operator'] = 'field_core_geographical_area_tid_op';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['expose']['identifier'] = 'field_core_geographical_area_tid';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['vocabulary'] = 'core_geographical_area';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['hierarchy'] = 1;
  /* Filter criterion: Field: Keywords (field_core_keywords) */
  $handler->display->display_options['filters']['field_core_keywords_tid']['id'] = 'field_core_keywords_tid';
  $handler->display->display_options['filters']['field_core_keywords_tid']['table'] = 'field_data_field_core_keywords';
  $handler->display->display_options['filters']['field_core_keywords_tid']['field'] = 'field_core_keywords_tid';
  $handler->display->display_options['filters']['field_core_keywords_tid']['value'] = '';
  $handler->display->display_options['filters']['field_core_keywords_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['operator_id'] = 'field_core_keywords_tid_op';
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['label'] = 'Keywords';
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['operator'] = 'field_core_keywords_tid_op';
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['identifier'] = 'field_core_keywords_tid';
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_core_keywords_tid']['vocabulary'] = 'tags';
  /* Filter criterion: User: Adviser sector (field_user_spec_advisor_sector) (translated) */
  $handler->display->display_options['filters']['field_user_spec_advisor_sector_value_i18n']['id'] = 'field_user_spec_advisor_sector_value_i18n';
  $handler->display->display_options['filters']['field_user_spec_advisor_sector_value_i18n']['table'] = 'field_data_field_user_spec_advisor_sector';
  $handler->display->display_options['filters']['field_user_spec_advisor_sector_value_i18n']['field'] = 'field_user_spec_advisor_sector_value_i18n';
  $handler->display->display_options['filters']['field_user_spec_advisor_sector_value_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_spec_advisor_sector_value_i18n']['expose']['operator_id'] = 'field_user_spec_advisor_sector_value_i18n_op';
  $handler->display->display_options['filters']['field_user_spec_advisor_sector_value_i18n']['expose']['label'] = 'Adviser sector';
  $handler->display->display_options['filters']['field_user_spec_advisor_sector_value_i18n']['expose']['operator'] = 'field_user_spec_advisor_sector_value_i18n_op';
  $handler->display->display_options['filters']['field_user_spec_advisor_sector_value_i18n']['expose']['identifier'] = 'field_user_spec_advisor_sector_value_i18n';
  $handler->display->display_options['filters']['field_user_spec_advisor_sector_value_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_user_spec_advisor_sector_value_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    10 => 0,
    8 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['field_user_spec_advisor_sector_value_i18n']['reduce_duplicates'] = TRUE;
  /* Filter criterion: User: Adviser type (field_user_spec_advisor_type) (translated) */
  $handler->display->display_options['filters']['field_user_spec_advisor_type_value_i18n']['id'] = 'field_user_spec_advisor_type_value_i18n';
  $handler->display->display_options['filters']['field_user_spec_advisor_type_value_i18n']['table'] = 'field_data_field_user_spec_advisor_type';
  $handler->display->display_options['filters']['field_user_spec_advisor_type_value_i18n']['field'] = 'field_user_spec_advisor_type_value_i18n';
  $handler->display->display_options['filters']['field_user_spec_advisor_type_value_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_spec_advisor_type_value_i18n']['expose']['operator_id'] = 'field_user_spec_advisor_type_value_i18n_op';
  $handler->display->display_options['filters']['field_user_spec_advisor_type_value_i18n']['expose']['label'] = 'Adviser type';
  $handler->display->display_options['filters']['field_user_spec_advisor_type_value_i18n']['expose']['operator'] = 'field_user_spec_advisor_type_value_i18n_op';
  $handler->display->display_options['filters']['field_user_spec_advisor_type_value_i18n']['expose']['identifier'] = 'field_user_spec_advisor_type_value_i18n';
  $handler->display->display_options['filters']['field_user_spec_advisor_type_value_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_user_spec_advisor_type_value_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    10 => 0,
    8 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['field_user_spec_advisor_type_value_i18n']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Field: User type (field_user_type) */
  $handler->display->display_options['filters']['field_user_type_tid']['id'] = 'field_user_type_tid';
  $handler->display->display_options['filters']['field_user_type_tid']['table'] = 'field_data_field_user_type';
  $handler->display->display_options['filters']['field_user_type_tid']['field'] = 'field_user_type_tid';
  $handler->display->display_options['filters']['field_user_type_tid']['value'] = array(
    208 => '208',
  );
  $handler->display->display_options['filters']['field_user_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_user_type_tid']['vocabulary'] = 'core_user_type';
  $handler->display->display_options['filters']['field_user_type_tid']['hierarchy'] = 1;
  $handler->display->display_options['path'] = 'find-people/advisors';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Advisers';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Find people';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'user-menu';
  $export['core_find_people'] = $view;

  $view = new view();
  $view->name = 'core_find_people_search';
  $view->description = '';
  $view->tag = 'AGRI Core';
  $view->base_table = 'search_api_index_core_people_index';
  $view->human_name = 'Core find people search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Find people';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'url' => 'url',
    'uid' => 'uid',
    'field_lastname' => 'field_lastname',
    'field_firstname' => 'field_firstname',
    'field_core_geographical_area' => 'field_core_geographical_area',
    'field_user_language_spoken' => 'field_user_language_spoken',
    'field_user_type' => 'field_user_type',
  );
  $handler->display->display_options['style_options']['default'] = 'field_firstname';
  $handler->display->display_options['style_options']['info'] = array(
    'url' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lastname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_firstname' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_core_geographical_area' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_language_spoken' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Indexed User: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_core_people_index';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  /* Field: Indexed User: User ID */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'search_api_index_core_people_index';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = 'Contact this user';
  $handler->display->display_options['fields']['uid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['path'] = 'user/[uid]/contact';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['separator'] = '';
  $handler->display->display_options['fields']['uid']['link_to_entity'] = 0;
  /* Field: Indexed User: Last name */
  $handler->display->display_options['fields']['field_lastname']['id'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['table'] = 'search_api_index_core_people_index';
  $handler->display->display_options['fields']['field_lastname']['field'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['label'] = '';
  $handler->display->display_options['fields']['field_lastname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lastname']['element_label_colon'] = FALSE;
  /* Field: Indexed User: First name */
  $handler->display->display_options['fields']['field_firstname']['id'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['table'] = 'search_api_index_core_people_index';
  $handler->display->display_options['fields']['field_firstname']['field'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['label'] = 'Full name';
  $handler->display->display_options['fields']['field_firstname']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_firstname']['alter']['text'] = '<div class="bold">[field_firstname] [field_lastname]</div>
<div class="small">[uid]</div>';
  $handler->display->display_options['fields']['field_firstname']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_firstname']['alter']['path'] = '[url]';
  /* Field: Indexed User: Country / Geographical area */
  $handler->display->display_options['fields']['field_core_geographical_area']['id'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['table'] = 'search_api_index_core_people_index';
  $handler->display->display_options['fields']['field_core_geographical_area']['field'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['label'] = 'Country';
  /* Field: Indexed User: Spoken languages */
  $handler->display->display_options['fields']['field_user_language_spoken']['id'] = 'field_user_language_spoken';
  $handler->display->display_options['fields']['field_user_language_spoken']['table'] = 'search_api_index_core_people_index';
  $handler->display->display_options['fields']['field_user_language_spoken']['field'] = 'field_user_language_spoken';
  $handler->display->display_options['fields']['field_user_language_spoken']['label'] = 'Language';
  $handler->display->display_options['fields']['field_user_language_spoken']['element_label_colon'] = FALSE;
  /* Field: Indexed User: User type */
  $handler->display->display_options['fields']['field_user_type']['id'] = 'field_user_type';
  $handler->display->display_options['fields']['field_user_type']['table'] = 'search_api_index_core_people_index';
  $handler->display->display_options['fields']['field_user_type']['field'] = 'field_user_type';
  /* Sort criterion: Indexed User: Created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'search_api_index_core_people_index';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Indexed User: Featured in internal database */
  $handler->display->display_options['filters']['field_user_featured_internal_db']['id'] = 'field_user_featured_internal_db';
  $handler->display->display_options['filters']['field_user_featured_internal_db']['table'] = 'search_api_index_core_people_index';
  $handler->display->display_options['filters']['field_user_featured_internal_db']['field'] = 'field_user_featured_internal_db';
  $handler->display->display_options['filters']['field_user_featured_internal_db']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_user_featured_internal_db']['group'] = 1;
  /* Filter criterion: Indexed User: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_core_people_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Indexed User: First name */
  $handler->display->display_options['filters']['field_firstname']['id'] = 'field_firstname';
  $handler->display->display_options['filters']['field_firstname']['table'] = 'search_api_index_core_people_index';
  $handler->display->display_options['filters']['field_firstname']['field'] = 'field_firstname';
  $handler->display->display_options['filters']['field_firstname']['group'] = 1;
  $handler->display->display_options['filters']['field_firstname']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_firstname']['expose']['operator_id'] = 'field_firstname_op';
  $handler->display->display_options['filters']['field_firstname']['expose']['label'] = 'First name';
  $handler->display->display_options['filters']['field_firstname']['expose']['operator'] = 'field_firstname_op';
  $handler->display->display_options['filters']['field_firstname']['expose']['identifier'] = 'field_firstname';
  $handler->display->display_options['filters']['field_firstname']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    10 => 0,
    8 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
  );
  /* Filter criterion: Indexed User: Last name */
  $handler->display->display_options['filters']['field_lastname']['id'] = 'field_lastname';
  $handler->display->display_options['filters']['field_lastname']['table'] = 'search_api_index_core_people_index';
  $handler->display->display_options['filters']['field_lastname']['field'] = 'field_lastname';
  $handler->display->display_options['filters']['field_lastname']['group'] = 1;
  $handler->display->display_options['filters']['field_lastname']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lastname']['expose']['operator_id'] = 'field_lastname_op';
  $handler->display->display_options['filters']['field_lastname']['expose']['label'] = 'Last name';
  $handler->display->display_options['filters']['field_lastname']['expose']['operator'] = 'field_lastname_op';
  $handler->display->display_options['filters']['field_lastname']['expose']['identifier'] = 'field_lastname';
  $handler->display->display_options['filters']['field_lastname']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    10 => 0,
    8 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
  );
  /* Filter criterion: Indexed User: User type */
  $handler->display->display_options['filters']['field_user_type']['id'] = 'field_user_type';
  $handler->display->display_options['filters']['field_user_type']['table'] = 'search_api_index_core_people_index';
  $handler->display->display_options['filters']['field_user_type']['field'] = 'field_user_type';
  $handler->display->display_options['filters']['field_user_type']['value'] = array();
  $handler->display->display_options['filters']['field_user_type']['group'] = 1;
  $handler->display->display_options['filters']['field_user_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_type']['expose']['operator_id'] = 'field_user_type_op';
  $handler->display->display_options['filters']['field_user_type']['expose']['label'] = 'User type';
  $handler->display->display_options['filters']['field_user_type']['expose']['operator'] = 'field_user_type_op';
  $handler->display->display_options['filters']['field_user_type']['expose']['identifier'] = 'field_user_type';
  $handler->display->display_options['filters']['field_user_type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_user_type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    6 => 0,
  );
  /* Filter criterion: Indexed User: Keywords */
  $handler->display->display_options['filters']['field_core_keywords']['id'] = 'field_core_keywords';
  $handler->display->display_options['filters']['field_core_keywords']['table'] = 'search_api_index_core_people_index';
  $handler->display->display_options['filters']['field_core_keywords']['field'] = 'field_core_keywords';
  $handler->display->display_options['filters']['field_core_keywords']['value'] = array();
  $handler->display->display_options['filters']['field_core_keywords']['group'] = 1;
  $handler->display->display_options['filters']['field_core_keywords']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_keywords']['expose']['operator_id'] = 'field_core_keywords_op';
  $handler->display->display_options['filters']['field_core_keywords']['expose']['label'] = 'Keywords';
  $handler->display->display_options['filters']['field_core_keywords']['expose']['operator'] = 'field_core_keywords_op';
  $handler->display->display_options['filters']['field_core_keywords']['expose']['identifier'] = 'field_core_keywords';
  $handler->display->display_options['filters']['field_core_keywords']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_core_keywords']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    6 => 0,
  );
  /* Filter criterion: Indexed User: Agricultural sectors */
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['id'] = 'field_core_agricultural_sectors';
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['table'] = 'search_api_index_core_people_index';
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['field'] = 'field_core_agricultural_sectors';
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['value'] = array();
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['group'] = 1;
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['expose']['operator_id'] = 'field_core_agricultural_sectors_op';
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['expose']['label'] = 'Agricultural sectors';
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['expose']['operator'] = 'field_core_agricultural_sectors_op';
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['expose']['identifier'] = 'field_core_agricultural_sectors';
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    10 => 0,
    35 => 0,
    8 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
    22 => 0,
    23 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    28 => 0,
    29 => 0,
    30 => 0,
    31 => 0,
    32 => 0,
    33 => 0,
    34 => 0,
  );
  /* Filter criterion: Indexed User: Country / Geographical area */
  $handler->display->display_options['filters']['field_core_geographical_area']['id'] = 'field_core_geographical_area';
  $handler->display->display_options['filters']['field_core_geographical_area']['table'] = 'search_api_index_core_people_index';
  $handler->display->display_options['filters']['field_core_geographical_area']['field'] = 'field_core_geographical_area';
  $handler->display->display_options['filters']['field_core_geographical_area']['value'] = array();
  $handler->display->display_options['filters']['field_core_geographical_area']['group'] = 1;
  $handler->display->display_options['filters']['field_core_geographical_area']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_geographical_area']['expose']['operator_id'] = 'field_core_geographical_area_op';
  $handler->display->display_options['filters']['field_core_geographical_area']['expose']['label'] = 'Country / Geographical area';
  $handler->display->display_options['filters']['field_core_geographical_area']['expose']['operator'] = 'field_core_geographical_area_op';
  $handler->display->display_options['filters']['field_core_geographical_area']['expose']['identifier'] = 'field_core_geographical_area';
  $handler->display->display_options['filters']['field_core_geographical_area']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_core_geographical_area']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    6 => 0,
  );
  /* Filter criterion: Indexed User: Spoken languages */
  $handler->display->display_options['filters']['field_user_language_spoken']['id'] = 'field_user_language_spoken';
  $handler->display->display_options['filters']['field_user_language_spoken']['table'] = 'search_api_index_core_people_index';
  $handler->display->display_options['filters']['field_user_language_spoken']['field'] = 'field_user_language_spoken';
  $handler->display->display_options['filters']['field_user_language_spoken']['value'] = array();
  $handler->display->display_options['filters']['field_user_language_spoken']['group'] = 1;
  $handler->display->display_options['filters']['field_user_language_spoken']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_language_spoken']['expose']['operator_id'] = 'field_user_language_spoken_op';
  $handler->display->display_options['filters']['field_user_language_spoken']['expose']['label'] = 'Spoken languages';
  $handler->display->display_options['filters']['field_user_language_spoken']['expose']['operator'] = 'field_user_language_spoken_op';
  $handler->display->display_options['filters']['field_user_language_spoken']['expose']['identifier'] = 'field_user_language_spoken';
  $handler->display->display_options['filters']['field_user_language_spoken']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_user_language_spoken']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_user_language_spoken']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    10 => 0,
    8 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
  );
  /* Filter criterion: Indexed User: User ID */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'search_api_index_core_people_index';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['operator'] = '>';
  $handler->display->display_options['filters']['uid']['value'] = '1';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_core_people_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Fulltext search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    10 => 0,
    8 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'find-people/all';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'All people';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Find people';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'user-menu';
  $export['core_find_people_search'] = $view;

  $view = new view();
  $view->name = 'core_manage_people';
  $view->description = '';
  $view->tag = 'AGRI Core';
  $view->base_table = 'users';
  $view->human_name = 'Core manage people';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Manage people';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer users';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'name' => 'name',
    'field_core_geographical_area' => 'field_core_geographical_area',
    'created' => 'created',
    'access' => 'access',
    'status' => 'status',
    'mail' => 'name',
    'edit_node' => 'edit_node',
    'field_firstname' => 'field_firstname',
    'field_lastname' => 'field_lastname',
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
    'field_core_geographical_area' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
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
    'field_firstname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lastname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Field: Organization (field_organization_collection) */
  $handler->display->display_options['relationships']['field_organization_collection_value']['id'] = 'field_organization_collection_value';
  $handler->display->display_options['relationships']['field_organization_collection_value']['table'] = 'field_data_field_organization_collection';
  $handler->display->display_options['relationships']['field_organization_collection_value']['field'] = 'field_organization_collection_value';
  $handler->display->display_options['relationships']['field_organization_collection_value']['delta'] = '-1';
  /* Field: Bulk operations: User */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_user';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::user_block_user_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Delete user',
    ),
    'action::agri_core_export_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Export in Excel',
      'settings' => array(
        'view_display' => 'core_manage_people:views_data_export_1',
      ),
    ),
    'action::views_bulk_operations_user_roles_action' => array(
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
  $handler->display->display_options['fields']['name']['label'] = 'Full name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Geographical scope */
  $handler->display->display_options['fields']['field_core_geographical_area']['id'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['table'] = 'field_data_field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['field'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['label'] = 'Country';
  $handler->display->display_options['fields']['field_core_geographical_area']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_core_geographical_area']['delta_offset'] = '0';
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  /* Field: User: Last access */
  $handler->display->display_options['fields']['access']['id'] = 'access';
  $handler->display->display_options['fields']['access']['table'] = 'users';
  $handler->display->display_options['fields']['access']['field'] = 'access';
  /* Field: User: Active */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['type'] = 'active-blocked';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['mail']['alter']['text'] = '<div class="small grey">[mail]</div>';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_firstname']['id'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['table'] = 'field_data_field_firstname';
  $handler->display->display_options['fields']['field_firstname']['field'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['exclude'] = TRUE;
  /* Field: User: Last name */
  $handler->display->display_options['fields']['field_lastname']['id'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['table'] = 'field_data_field_lastname';
  $handler->display->display_options['fields']['field_lastname']['field'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['exclude'] = TRUE;
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: First name (field_firstname) */
  $handler->display->display_options['filters']['field_firstname_value']['id'] = 'field_firstname_value';
  $handler->display->display_options['filters']['field_firstname_value']['table'] = 'field_data_field_firstname';
  $handler->display->display_options['filters']['field_firstname_value']['field'] = 'field_firstname_value';
  $handler->display->display_options['filters']['field_firstname_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_firstname_value']['group'] = 1;
  $handler->display->display_options['filters']['field_firstname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_firstname_value']['expose']['operator_id'] = 'field_firstname_value_op';
  $handler->display->display_options['filters']['field_firstname_value']['expose']['label'] = 'First name';
  $handler->display->display_options['filters']['field_firstname_value']['expose']['operator'] = 'field_firstname_value_op';
  $handler->display->display_options['filters']['field_firstname_value']['expose']['identifier'] = 'field_firstname_value';
  $handler->display->display_options['filters']['field_firstname_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
  );
  /* Filter criterion: User: Last name (field_lastname) */
  $handler->display->display_options['filters']['field_lastname_value']['id'] = 'field_lastname_value';
  $handler->display->display_options['filters']['field_lastname_value']['table'] = 'field_data_field_lastname';
  $handler->display->display_options['filters']['field_lastname_value']['field'] = 'field_lastname_value';
  $handler->display->display_options['filters']['field_lastname_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_lastname_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lastname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lastname_value']['expose']['operator_id'] = 'field_lastname_value_op';
  $handler->display->display_options['filters']['field_lastname_value']['expose']['label'] = 'Last name';
  $handler->display->display_options['filters']['field_lastname_value']['expose']['operator'] = 'field_lastname_value_op';
  $handler->display->display_options['filters']['field_lastname_value']['expose']['identifier'] = 'field_lastname_value';
  $handler->display->display_options['filters']['field_lastname_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
  );
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
    7 => 0,
    8 => 0,
    6 => 0,
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['operator'] = 'not in';
  $handler->display->display_options['filters']['uid']['value'] = array(
    0 => 0,
    1 => '1',
  );
  /* Filter criterion: Field: Geographical scope (field_core_geographical_area) */
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['id'] = 'field_core_geographical_area_tid';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['table'] = 'field_data_field_core_geographical_area';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['field'] = 'field_core_geographical_area_tid';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['expose']['operator_id'] = 'field_core_geographical_area_tid_op';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['expose']['label'] = 'Geographical scope';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['expose']['operator'] = 'field_core_geographical_area_tid_op';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['expose']['identifier'] = 'field_core_geographical_area_tid';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['vocabulary'] = 'core_geographical_area';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['hierarchy'] = 1;
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['error_message'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: User */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_user';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
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
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Delete user',
    ),
    'action::agri_core_export_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Export in Excel',
      'settings' => array(
        'view_display' => 'core_manage_people:views_data_export_1',
      ),
    ),
    'action::views_bulk_operations_user_roles_action' => array(
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
  $handler->display->display_options['fields']['name']['label'] = 'Full name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Geographical scope */
  $handler->display->display_options['fields']['field_core_geographical_area']['id'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['table'] = 'field_data_field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['field'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['relationship'] = 'field_organization_collection_value';
  $handler->display->display_options['fields']['field_core_geographical_area']['label'] = 'Country';
  $handler->display->display_options['fields']['field_core_geographical_area']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_core_geographical_area']['delta_offset'] = '0';
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  /* Field: User: Last access */
  $handler->display->display_options['fields']['access']['id'] = 'access';
  $handler->display->display_options['fields']['access']['table'] = 'users';
  $handler->display->display_options['fields']['access']['field'] = 'access';
  /* Field: User: Active */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['type'] = 'active-blocked';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['mail']['alter']['text'] = '<div class="small grey">[mail]</div>';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_firstname']['id'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['table'] = 'field_data_field_firstname';
  $handler->display->display_options['fields']['field_firstname']['field'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['exclude'] = TRUE;
  /* Field: User: Last name */
  $handler->display->display_options['fields']['field_lastname']['id'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['table'] = 'field_data_field_lastname';
  $handler->display->display_options['fields']['field_lastname']['field'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['exclude'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: First name (field_firstname) */
  $handler->display->display_options['filters']['field_firstname_value']['id'] = 'field_firstname_value';
  $handler->display->display_options['filters']['field_firstname_value']['table'] = 'field_data_field_firstname';
  $handler->display->display_options['filters']['field_firstname_value']['field'] = 'field_firstname_value';
  $handler->display->display_options['filters']['field_firstname_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_firstname_value']['group'] = 1;
  $handler->display->display_options['filters']['field_firstname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_firstname_value']['expose']['operator_id'] = 'field_firstname_value_op';
  $handler->display->display_options['filters']['field_firstname_value']['expose']['label'] = 'First name';
  $handler->display->display_options['filters']['field_firstname_value']['expose']['operator'] = 'field_firstname_value_op';
  $handler->display->display_options['filters']['field_firstname_value']['expose']['identifier'] = 'field_firstname_value';
  $handler->display->display_options['filters']['field_firstname_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
  );
  /* Filter criterion: User: Last name (field_lastname) */
  $handler->display->display_options['filters']['field_lastname_value']['id'] = 'field_lastname_value';
  $handler->display->display_options['filters']['field_lastname_value']['table'] = 'field_data_field_lastname';
  $handler->display->display_options['filters']['field_lastname_value']['field'] = 'field_lastname_value';
  $handler->display->display_options['filters']['field_lastname_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_lastname_value']['group'] = 1;
  $handler->display->display_options['filters']['field_lastname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lastname_value']['expose']['operator_id'] = 'field_lastname_value_op';
  $handler->display->display_options['filters']['field_lastname_value']['expose']['label'] = 'Last name';
  $handler->display->display_options['filters']['field_lastname_value']['expose']['operator'] = 'field_lastname_value_op';
  $handler->display->display_options['filters']['field_lastname_value']['expose']['identifier'] = 'field_lastname_value';
  $handler->display->display_options['filters']['field_lastname_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
  );
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
    7 => 0,
    8 => 0,
    6 => 0,
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['operator'] = 'not in';
  $handler->display->display_options['filters']['uid']['value'] = array(
    0 => 0,
    1 => '1',
  );
  /* Filter criterion: Field: Geographical scope (field_core_geographical_area) */
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['id'] = 'field_core_geographical_area_tid';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['table'] = 'field_data_field_core_geographical_area';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['field'] = 'field_core_geographical_area_tid';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['expose']['operator_id'] = 'field_core_geographical_area_tid_op';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['expose']['label'] = 'Geographical scope';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['expose']['operator'] = 'field_core_geographical_area_tid_op';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['expose']['identifier'] = 'field_core_geographical_area_tid';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['vocabulary'] = 'core_geographical_area';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['hierarchy'] = 1;
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['error_message'] = FALSE;
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
    7 => 0,
    10 => 0,
    8 => 0,
    9 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['rid']['reduce_duplicates'] = TRUE;
  /* Filter criterion: User: Featured in internal database (field_user_featured_internal_db) (translated) */
  $handler->display->display_options['filters']['field_user_featured_internal_db_value_i18n']['id'] = 'field_user_featured_internal_db_value_i18n';
  $handler->display->display_options['filters']['field_user_featured_internal_db_value_i18n']['table'] = 'field_data_field_user_featured_internal_db';
  $handler->display->display_options['filters']['field_user_featured_internal_db_value_i18n']['field'] = 'field_user_featured_internal_db_value_i18n';
  $handler->display->display_options['filters']['field_user_featured_internal_db_value_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_featured_internal_db_value_i18n']['expose']['operator_id'] = 'field_user_featured_internal_db_value_i18n_op';
  $handler->display->display_options['filters']['field_user_featured_internal_db_value_i18n']['expose']['label'] = 'Featured in internal database';
  $handler->display->display_options['filters']['field_user_featured_internal_db_value_i18n']['expose']['operator'] = 'field_user_featured_internal_db_value_i18n_op';
  $handler->display->display_options['filters']['field_user_featured_internal_db_value_i18n']['expose']['identifier'] = 'field_user_featured_internal_db_value_i18n';
  $handler->display->display_options['filters']['field_user_featured_internal_db_value_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    10 => 0,
    8 => 0,
    9 => 0,
    6 => 0,
  );
  $handler->display->display_options['path'] = 'manage/people';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'User management';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-core-action-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'agri-user-export-%timestamp-full.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field: Organization (field_organization_collection) */
  $handler->display->display_options['relationships']['field_organization_collection_value']['id'] = 'field_organization_collection_value';
  $handler->display->display_options['relationships']['field_organization_collection_value']['table'] = 'field_data_field_organization_collection';
  $handler->display->display_options['relationships']['field_organization_collection_value']['field'] = 'field_organization_collection_value';
  $handler->display->display_options['relationships']['field_organization_collection_value']['label'] = 'FIeld Organization Collection';
  $handler->display->display_options['relationships']['field_organization_collection_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_firstname']['id'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['table'] = 'field_data_field_firstname';
  $handler->display->display_options['fields']['field_firstname']['field'] = 'field_firstname';
  /* Field: User: Last name */
  $handler->display->display_options['fields']['field_lastname']['id'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['table'] = 'field_data_field_lastname';
  $handler->display->display_options['fields']['field_lastname']['field'] = 'field_lastname';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Username';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  $handler->display->display_options['fields']['name']['format_username'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['mail']['alter']['text'] = '<div class="small grey">[mail]</div>';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: User: Title */
  $handler->display->display_options['fields']['field_user_gender']['id'] = 'field_user_gender';
  $handler->display->display_options['fields']['field_user_gender']['table'] = 'field_data_field_user_gender';
  $handler->display->display_options['fields']['field_user_gender']['field'] = 'field_user_gender';
  /* Field: Field: Geographical scope */
  $handler->display->display_options['fields']['field_core_geographical_area']['id'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['table'] = 'field_data_field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['field'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['relationship'] = 'field_organization_collection_value';
  $handler->display->display_options['fields']['field_core_geographical_area']['label'] = 'Country';
  $handler->display->display_options['fields']['field_core_geographical_area']['delta_offset'] = '0';
  /* Field: Field collection item: Address */
  $handler->display->display_options['fields']['field_organization_address']['id'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['field'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['relationship'] = 'field_organization_collection_value';
  /* Field: User: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'users';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  /* Field: Field collection item: City */
  $handler->display->display_options['fields']['field_organization_city']['id'] = 'field_organization_city';
  $handler->display->display_options['fields']['field_organization_city']['table'] = 'field_data_field_organization_city';
  $handler->display->display_options['fields']['field_organization_city']['field'] = 'field_organization_city';
  $handler->display->display_options['fields']['field_organization_city']['relationship'] = 'field_organization_collection_value';
  /* Field: Field: Phone */
  $handler->display->display_options['fields']['field_user_phone']['id'] = 'field_user_phone';
  $handler->display->display_options['fields']['field_user_phone']['table'] = 'field_data_field_user_phone';
  $handler->display->display_options['fields']['field_user_phone']['field'] = 'field_user_phone';
  $handler->display->display_options['fields']['field_user_phone']['relationship'] = 'field_organization_collection_value';
  /* Field: Field: Organization */
  $handler->display->display_options['fields']['field_organization_collection']['id'] = 'field_organization_collection';
  $handler->display->display_options['fields']['field_organization_collection']['table'] = 'field_data_field_organization_collection';
  $handler->display->display_options['fields']['field_organization_collection']['field'] = 'field_organization_collection';
  $handler->display->display_options['fields']['field_organization_collection']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 0,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_organization_collection']['delta_offset'] = '0';
  /* Field: Field: User type */
  $handler->display->display_options['fields']['field_user_type']['id'] = 'field_user_type';
  $handler->display->display_options['fields']['field_user_type']['table'] = 'field_data_field_user_type';
  $handler->display->display_options['fields']['field_user_type']['field'] = 'field_user_type';
  $handler->display->display_options['fields']['field_user_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_type']['delta_offset'] = '0';
  /* Field: Field: Specify User Type */
  $handler->display->display_options['fields']['field_user_specify_other']['id'] = 'field_user_specify_other';
  $handler->display->display_options['fields']['field_user_specify_other']['table'] = 'field_data_field_user_specify_other';
  $handler->display->display_options['fields']['field_user_specify_other']['field'] = 'field_user_specify_other';
  $handler->display->display_options['fields']['field_user_specify_other']['label'] = 'Specify (user type)';
  /* Field: Field: Keywords */
  $handler->display->display_options['fields']['field_core_keywords']['id'] = 'field_core_keywords';
  $handler->display->display_options['fields']['field_core_keywords']['table'] = 'field_data_field_core_keywords';
  $handler->display->display_options['fields']['field_core_keywords']['field'] = 'field_core_keywords';
  $handler->display->display_options['fields']['field_core_keywords']['delta_offset'] = '0';
  /* Field: User: Administrative level */
  $handler->display->display_options['fields']['field_user_spec_admin_level']['id'] = 'field_user_spec_admin_level';
  $handler->display->display_options['fields']['field_user_spec_admin_level']['table'] = 'field_data_field_user_spec_admin_level';
  $handler->display->display_options['fields']['field_user_spec_admin_level']['field'] = 'field_user_spec_admin_level';
  $handler->display->display_options['fields']['field_user_spec_admin_level']['delta_offset'] = '0';
  /* Field: User: Type of production */
  $handler->display->display_options['fields']['field_user_spec_type']['id'] = 'field_user_spec_type';
  $handler->display->display_options['fields']['field_user_spec_type']['table'] = 'field_data_field_user_spec_type';
  $handler->display->display_options['fields']['field_user_spec_type']['field'] = 'field_user_spec_type';
  $handler->display->display_options['fields']['field_user_spec_type']['delta_offset'] = '0';
  /* Field: User: Specify (Type of production) */
  $handler->display->display_options['fields']['field_user_spec_type_other']['id'] = 'field_user_spec_type_other';
  $handler->display->display_options['fields']['field_user_spec_type_other']['table'] = 'field_data_field_user_spec_type_other';
  $handler->display->display_options['fields']['field_user_spec_type_other']['field'] = 'field_user_spec_type_other';
  /* Field: User: Adviser sector */
  $handler->display->display_options['fields']['field_user_spec_advisor_sector']['id'] = 'field_user_spec_advisor_sector';
  $handler->display->display_options['fields']['field_user_spec_advisor_sector']['table'] = 'field_data_field_user_spec_advisor_sector';
  $handler->display->display_options['fields']['field_user_spec_advisor_sector']['field'] = 'field_user_spec_advisor_sector';
  $handler->display->display_options['fields']['field_user_spec_advisor_sector']['delta_offset'] = '0';
  /* Field: User: Adviser type */
  $handler->display->display_options['fields']['field_user_spec_advisor_type']['id'] = 'field_user_spec_advisor_type';
  $handler->display->display_options['fields']['field_user_spec_advisor_type']['table'] = 'field_data_field_user_spec_advisor_type';
  $handler->display->display_options['fields']['field_user_spec_advisor_type']['field'] = 'field_user_spec_advisor_type';
  $handler->display->display_options['fields']['field_user_spec_advisor_type']['delta_offset'] = '0';
  /* Field: User: Specify (adviser type) */
  $handler->display->display_options['fields']['field_user_spec_advisor_other']['id'] = 'field_user_spec_advisor_other';
  $handler->display->display_options['fields']['field_user_spec_advisor_other']['table'] = 'field_data_field_user_spec_advisor_other';
  $handler->display->display_options['fields']['field_user_spec_advisor_other']['field'] = 'field_user_spec_advisor_other';
  /* Field: User: Position in the organization (adviser) */
  $handler->display->display_options['fields']['field_user_spec_position_2']['id'] = 'field_user_spec_position_2';
  $handler->display->display_options['fields']['field_user_spec_position_2']['table'] = 'field_data_field_user_spec_position';
  $handler->display->display_options['fields']['field_user_spec_position_2']['field'] = 'field_user_spec_position';
  /* Field: User: Position in the organization (researcher) */
  $handler->display->display_options['fields']['field_user_position_researcher']['id'] = 'field_user_position_researcher';
  $handler->display->display_options['fields']['field_user_position_researcher']['table'] = 'field_data_field_user_position_researcher';
  $handler->display->display_options['fields']['field_user_position_researcher']['field'] = 'field_user_position_researcher';
  /* Field: User: Position in the organization (industry) */
  $handler->display->display_options['fields']['field_user_position_industry']['id'] = 'field_user_position_industry';
  $handler->display->display_options['fields']['field_user_position_industry']['table'] = 'field_data_field_user_position_industry';
  $handler->display->display_options['fields']['field_user_position_industry']['field'] = 'field_user_position_industry';
  /* Field: User: Sector working in (industry) */
  $handler->display->display_options['fields']['field_user_spec_sector_1']['id'] = 'field_user_spec_sector_1';
  $handler->display->display_options['fields']['field_user_spec_sector_1']['table'] = 'field_data_field_user_spec_sector';
  $handler->display->display_options['fields']['field_user_spec_sector_1']['field'] = 'field_user_spec_sector';
  /* Field: User: Specify (industry) */
  $handler->display->display_options['fields']['field_user_spec_sector_other']['id'] = 'field_user_spec_sector_other';
  $handler->display->display_options['fields']['field_user_spec_sector_other']['table'] = 'field_data_field_user_spec_sector_other';
  $handler->display->display_options['fields']['field_user_spec_sector_other']['field'] = 'field_user_spec_sector_other';
  /* Field: User: Position in the organization (retailer) */
  $handler->display->display_options['fields']['field_user_position_retailer']['id'] = 'field_user_position_retailer';
  $handler->display->display_options['fields']['field_user_position_retailer']['table'] = 'field_data_field_user_position_retailer';
  $handler->display->display_options['fields']['field_user_position_retailer']['field'] = 'field_user_position_retailer';
  /* Field: User: Sector working in (retailer) */
  $handler->display->display_options['fields']['field_user_sector_retailer']['id'] = 'field_user_sector_retailer';
  $handler->display->display_options['fields']['field_user_sector_retailer']['table'] = 'field_data_field_user_sector_retailer';
  $handler->display->display_options['fields']['field_user_sector_retailer']['field'] = 'field_user_sector_retailer';
  /* Field: User: Specify (retailer) */
  $handler->display->display_options['fields']['field_user_specify_ret']['id'] = 'field_user_specify_ret';
  $handler->display->display_options['fields']['field_user_specify_ret']['table'] = 'field_data_field_user_specify_ret';
  $handler->display->display_options['fields']['field_user_specify_ret']['field'] = 'field_user_specify_ret';
  /* Field: User: Position in the organization (wholesaler) */
  $handler->display->display_options['fields']['field_user_position_whole']['id'] = 'field_user_position_whole';
  $handler->display->display_options['fields']['field_user_position_whole']['table'] = 'field_data_field_user_position_whole';
  $handler->display->display_options['fields']['field_user_position_whole']['field'] = 'field_user_position_whole';
  /* Field: User: Sector working in (wholesaler) */
  $handler->display->display_options['fields']['field_user_sector_whole']['id'] = 'field_user_sector_whole';
  $handler->display->display_options['fields']['field_user_sector_whole']['table'] = 'field_data_field_user_sector_whole';
  $handler->display->display_options['fields']['field_user_sector_whole']['field'] = 'field_user_sector_whole';
  /* Field: User: Specify (wholesaler) */
  $handler->display->display_options['fields']['field_user_specify_whole']['id'] = 'field_user_specify_whole';
  $handler->display->display_options['fields']['field_user_specify_whole']['table'] = 'field_data_field_user_specify_whole';
  $handler->display->display_options['fields']['field_user_specify_whole']['field'] = 'field_user_specify_whole';
  /* Field: User: Position in the organization (representative of an NGO) */
  $handler->display->display_options['fields']['field_user_position_rep']['id'] = 'field_user_position_rep';
  $handler->display->display_options['fields']['field_user_position_rep']['table'] = 'field_data_field_user_position_rep';
  $handler->display->display_options['fields']['field_user_position_rep']['field'] = 'field_user_position_rep';
  /* Field: User: Position in the organization (civil servant) */
  $handler->display->display_options['fields']['field_user_position_civil']['id'] = 'field_user_position_civil';
  $handler->display->display_options['fields']['field_user_position_civil']['table'] = 'field_data_field_user_position_civil';
  $handler->display->display_options['fields']['field_user_position_civil']['field'] = 'field_user_position_civil';
  /* Field: User: Do you have RDP funding? */
  $handler->display->display_options['fields']['field_user_spec_rdp']['id'] = 'field_user_spec_rdp';
  $handler->display->display_options['fields']['field_user_spec_rdp']['table'] = 'field_data_field_user_spec_rdp';
  $handler->display->display_options['fields']['field_user_spec_rdp']['field'] = 'field_user_spec_rdp';
  /* Field: User: Portfolio */
  $handler->display->display_options['fields']['field_user_spec_portfolio']['id'] = 'field_user_spec_portfolio';
  $handler->display->display_options['fields']['field_user_spec_portfolio']['table'] = 'field_data_field_user_spec_portfolio';
  $handler->display->display_options['fields']['field_user_spec_portfolio']['field'] = 'field_user_spec_portfolio';
  /* Field: User: Forest type */
  $handler->display->display_options['fields']['field_user_spec_forest_type']['id'] = 'field_user_spec_forest_type';
  $handler->display->display_options['fields']['field_user_spec_forest_type']['table'] = 'field_data_field_user_spec_forest_type';
  $handler->display->display_options['fields']['field_user_spec_forest_type']['field'] = 'field_user_spec_forest_type';
  $handler->display->display_options['fields']['field_user_spec_forest_type']['delta_offset'] = '0';
  /* Field: User: Forest utilization */
  $handler->display->display_options['fields']['field_user_spec_forest_utilizati']['id'] = 'field_user_spec_forest_utilizati';
  $handler->display->display_options['fields']['field_user_spec_forest_utilizati']['table'] = 'field_data_field_user_spec_forest_utilizati';
  $handler->display->display_options['fields']['field_user_spec_forest_utilizati']['field'] = 'field_user_spec_forest_utilizati';
  $handler->display->display_options['fields']['field_user_spec_forest_utilizati']['delta_offset'] = '0';
  /* Field: User: Specify (forest utilization) */
  $handler->display->display_options['fields']['field_user_spec_forest_other']['id'] = 'field_user_spec_forest_other';
  $handler->display->display_options['fields']['field_user_spec_forest_other']['table'] = 'field_data_field_user_spec_forest_other';
  $handler->display->display_options['fields']['field_user_spec_forest_other']['field'] = 'field_user_spec_forest_other';
  /* Field: User: Forester type */
  $handler->display->display_options['fields']['field_user_spec_forester_type']['id'] = 'field_user_spec_forester_type';
  $handler->display->display_options['fields']['field_user_spec_forester_type']['table'] = 'field_data_field_user_spec_forester_type';
  $handler->display->display_options['fields']['field_user_spec_forester_type']['field'] = 'field_user_spec_forester_type';
  $handler->display->display_options['fields']['field_user_spec_forester_type']['delta_offset'] = '0';
  /* Field: User: Predominant type of land use */
  $handler->display->display_options['fields']['field_user_spec_land_type']['id'] = 'field_user_spec_land_type';
  $handler->display->display_options['fields']['field_user_spec_land_type']['table'] = 'field_data_field_user_spec_land_type';
  $handler->display->display_options['fields']['field_user_spec_land_type']['field'] = 'field_user_spec_land_type';
  $handler->display->display_options['fields']['field_user_spec_land_type']['delta_offset'] = '0';
  /* Field: User: Specify (predominant type of land use) */
  $handler->display->display_options['fields']['field_user_spec_land_type_other']['id'] = 'field_user_spec_land_type_other';
  $handler->display->display_options['fields']['field_user_spec_land_type_other']['table'] = 'field_data_field_user_spec_land_type_other';
  $handler->display->display_options['fields']['field_user_spec_land_type_other']['field'] = 'field_user_spec_land_type_other';
  /* Field: User: Size of the forest */
  $handler->display->display_options['fields']['field_user_spec_size']['id'] = 'field_user_spec_size';
  $handler->display->display_options['fields']['field_user_spec_size']['table'] = 'field_data_field_user_spec_size';
  $handler->display->display_options['fields']['field_user_spec_size']['field'] = 'field_user_spec_size';
  /* Field: User: Size of the farm/land */
  $handler->display->display_options['fields']['field_user_spec_size_farm_land']['id'] = 'field_user_spec_size_farm_land';
  $handler->display->display_options['fields']['field_user_spec_size_farm_land']['table'] = 'field_data_field_user_spec_size_farm_land';
  $handler->display->display_options['fields']['field_user_spec_size_farm_land']['field'] = 'field_user_spec_size_farm_land';
  /* Field: User: Type of media */
  $handler->display->display_options['fields']['field_user_spec_media_type']['id'] = 'field_user_spec_media_type';
  $handler->display->display_options['fields']['field_user_spec_media_type']['table'] = 'field_data_field_user_spec_media_type';
  $handler->display->display_options['fields']['field_user_spec_media_type']['field'] = 'field_user_spec_media_type';
  $handler->display->display_options['fields']['field_user_spec_media_type']['delta_offset'] = '0';
  /* Field: User: Featured in internal database */
  $handler->display->display_options['fields']['field_user_featured_internal_db']['id'] = 'field_user_featured_internal_db';
  $handler->display->display_options['fields']['field_user_featured_internal_db']['table'] = 'field_data_field_user_featured_internal_db';
  $handler->display->display_options['fields']['field_user_featured_internal_db']['field'] = 'field_user_featured_internal_db';
  /* Field: User: Involved in */
  $handler->display->display_options['fields']['field_user_involved']['id'] = 'field_user_involved';
  $handler->display->display_options['fields']['field_user_involved']['table'] = 'field_data_field_user_involved';
  $handler->display->display_options['fields']['field_user_involved']['field'] = 'field_user_involved';
  $handler->display->display_options['fields']['field_user_involved']['delta_offset'] = '0';
  /* Field: User: CV */
  $handler->display->display_options['fields']['field_user_cv']['id'] = 'field_user_cv';
  $handler->display->display_options['fields']['field_user_cv']['table'] = 'field_data_field_user_cv';
  $handler->display->display_options['fields']['field_user_cv']['field'] = 'field_user_cv';
  $handler->display->display_options['fields']['field_user_cv']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_cv']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_user_cv']['settings'] = array(
    'text' => 'Download [file:name]',
  );
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: User: Last access */
  $handler->display->display_options['fields']['access']['id'] = 'access';
  $handler->display->display_options['fields']['access']['table'] = 'users';
  $handler->display->display_options['fields']['access']['field'] = 'access';
  $handler->display->display_options['fields']['access']['date_format'] = 'short';
  $handler->display->display_options['fields']['access']['second_date_format'] = 'long';
  /* Field: User: Group membership */
  $handler->display->display_options['fields']['og_user_node']['id'] = 'og_user_node';
  $handler->display->display_options['fields']['og_user_node']['table'] = 'og_membership';
  $handler->display->display_options['fields']['og_user_node']['field'] = 'og_user_node';
  $handler->display->display_options['fields']['og_user_node']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['og_user_node']['delta_offset'] = '0';
  /* Field: Field: Additional information */
  $handler->display->display_options['fields']['field_core_additional_info']['id'] = 'field_core_additional_info';
  $handler->display->display_options['fields']['field_core_additional_info']['table'] = 'field_data_field_core_additional_info';
  $handler->display->display_options['fields']['field_core_additional_info']['field'] = 'field_core_additional_info';
  /* Field: Field collection item: Department (original language) */
  $handler->display->display_options['fields']['field_organization_department']['id'] = 'field_organization_department';
  $handler->display->display_options['fields']['field_organization_department']['table'] = 'field_data_field_organization_department';
  $handler->display->display_options['fields']['field_organization_department']['field'] = 'field_organization_department';
  $handler->display->display_options['fields']['field_organization_department']['relationship'] = 'field_organization_collection_value';
  /* Field: Field collection item: Unit (original language) */
  $handler->display->display_options['fields']['field_organization_unit']['id'] = 'field_organization_unit';
  $handler->display->display_options['fields']['field_organization_unit']['table'] = 'field_data_field_organization_unit';
  $handler->display->display_options['fields']['field_organization_unit']['field'] = 'field_organization_unit';
  $handler->display->display_options['fields']['field_organization_unit']['relationship'] = 'field_organization_collection_value';
  /* Field: Field collection item: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'views_entity_field_collection_item';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['relationship'] = 'field_organization_collection_value';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Field collection item: Website */
  $handler->display->display_options['fields']['field_organization_website']['id'] = 'field_organization_website';
  $handler->display->display_options['fields']['field_organization_website']['table'] = 'field_data_field_organization_website';
  $handler->display->display_options['fields']['field_organization_website']['field'] = 'field_organization_website';
  $handler->display->display_options['fields']['field_organization_website']['relationship'] = 'field_organization_collection_value';
  $handler->display->display_options['fields']['field_organization_website']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_organization_website']['alter']['text'] = '[field_organization_website-title] - [field_organization_website-url]';
  $handler->display->display_options['fields']['field_organization_website']['click_sort_column'] = 'url';
  /* Field: Field: Contact e-mail */
  $handler->display->display_options['fields']['field_core_email']['id'] = 'field_core_email';
  $handler->display->display_options['fields']['field_core_email']['table'] = 'field_data_field_core_email';
  $handler->display->display_options['fields']['field_core_email']['field'] = 'field_core_email';
  $handler->display->display_options['fields']['field_core_email']['relationship'] = 'field_organization_collection_value';
  $handler->display->display_options['fields']['field_core_email']['label'] = 'E-mail organizations ';
  /* Field: Field: Agricultural sectors */
  $handler->display->display_options['fields']['field_core_agricultural_sectors']['id'] = 'field_core_agricultural_sectors';
  $handler->display->display_options['fields']['field_core_agricultural_sectors']['table'] = 'field_data_field_core_agricultural_sectors';
  $handler->display->display_options['fields']['field_core_agricultural_sectors']['field'] = 'field_core_agricultural_sectors';
  $handler->display->display_options['fields']['field_core_agricultural_sectors']['delta_offset'] = '0';
  $handler->display->display_options['path'] = 'manage/people/export/xsl';
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '100';
  $export['core_manage_people'] = $view;

  $view = new view();
  $view->name = 'core_news_events';
  $view->description = '';
  $view->tag = 'AGRI Core';
  $view->base_table = 'node';
  $view->human_name = 'Core News and Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Block: Homepage';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'border-bottom';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
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
    'event' => 'event',
    'news' => 'news',
  );

  /* Display: Block: Homepage */
  $handler = $view->new_display('block', 'Block: Homepage', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Latest news & events';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'View All';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'border-bottom';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['text'] = '<a href="[path]">Read more</a>';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Publication date (field_news_publication_date) */
  $handler->display->display_options['sorts']['field_news_publication_date_value']['id'] = 'field_news_publication_date_value';
  $handler->display->display_options['sorts']['field_news_publication_date_value']['table'] = 'field_data_field_news_publication_date';
  $handler->display->display_options['sorts']['field_news_publication_date_value']['field'] = 'field_news_publication_date_value';
  $handler->display->display_options['sorts']['field_news_publication_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
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
    'event' => 'event',
    'news' => 'news',
  );

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'news-events/feed';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'block' => 0,
  );
  $export['core_news_events'] = $view;

  $view = new view();
  $view->name = 'core_node_related_content';
  $view->description = '';
  $view->tag = 'AGRI Core';
  $view->base_table = 'node';
  $view->human_name = 'core node related content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Latest related content';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'border-bottom grey';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['element_type'] = 'span';
  $handler->display->display_options['fields']['type']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['type']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['type']['element_wrapper_class'] = 'small';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Posted on';
  $handler->display->display_options['fields']['created']['element_type'] = 'span';
  $handler->display->display_options['fields']['created']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['created']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['created']['element_wrapper_class'] = 'small';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['term_page'] = FALSE;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['anyall'] = '+';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['limit'] = TRUE;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['vocabularies'] = array(
    'tags' => 'tags',
  );
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = TRUE;
  $handler->display->display_options['arguments']['tid']['add_table'] = TRUE;
  $handler->display->display_options['arguments']['tid']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Content: Published */
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
    'event' => 'event',
    'funding_opportunities' => 'funding_opportunities',
    'innovative_action' => 'innovative_action',
    'needs_for_research_from_practice' => 'needs_for_research_from_practice',
    'news' => 'news',
    'online_resource' => 'online_resource',
    'operational_group' => 'operational_group',
    'press_release' => 'press_release',
    'press_clipping' => 'press_clipping',
    'project_ideas' => 'project_ideas',
    'publication' => 'publication',
    'research_project' => 'research_project',
  );

  /* Display: Related content (similar terms) */
  $handler = $view->new_display('block', 'Related content (similar terms)', 'block');
  $export['core_node_related_content'] = $view;

  $view = new view();
  $view->name = 'core_profile_user_details';
  $view->description = '';
  $view->tag = 'AGRI Core';
  $view->base_table = 'users';
  $view->human_name = 'Core profile user details';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: User: Profile picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'profile_thumbnail',
    'image_link' => '',
  );
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_firstname']['id'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['table'] = 'field_data_field_firstname';
  $handler->display->display_options['fields']['field_firstname']['field'] = 'field_firstname';
  $handler->display->display_options['fields']['field_firstname']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_firstname']['element_label_type'] = 'strong';
  /* Field: User: Last name */
  $handler->display->display_options['fields']['field_lastname']['id'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['table'] = 'field_data_field_lastname';
  $handler->display->display_options['fields']['field_lastname']['field'] = 'field_lastname';
  $handler->display->display_options['fields']['field_lastname']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_lastname']['element_label_type'] = 'strong';
  /* Field: Field: Geographical scope */
  $handler->display->display_options['fields']['field_core_geographical_area']['id'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['table'] = 'field_data_field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['field'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['label'] = 'Country / Geographical area';
  $handler->display->display_options['fields']['field_core_geographical_area']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_core_geographical_area']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_core_geographical_area']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_core_geographical_area']['delta_offset'] = '0';
  /* Field: User: City */
  $handler->display->display_options['fields']['field_user_city']['id'] = 'field_user_city';
  $handler->display->display_options['fields']['field_user_city']['table'] = 'field_data_field_user_city';
  $handler->display->display_options['fields']['field_user_city']['field'] = 'field_user_city';
  $handler->display->display_options['fields']['field_user_city']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_user_city']['element_label_type'] = 'strong';
  /* Field: User: Website */
  $handler->display->display_options['fields']['field_user_website']['id'] = 'field_user_website';
  $handler->display->display_options['fields']['field_user_website']['table'] = 'field_data_field_user_website';
  $handler->display->display_options['fields']['field_user_website']['field'] = 'field_user_website';
  $handler->display->display_options['fields']['field_user_website']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_user_website']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_user_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_user_website']['type'] = 'link_url';
  /* Field: Field: User type */
  $handler->display->display_options['fields']['field_user_type']['id'] = 'field_user_type';
  $handler->display->display_options['fields']['field_user_type']['table'] = 'field_data_field_user_type';
  $handler->display->display_options['fields']['field_user_type']['field'] = 'field_user_type';
  $handler->display->display_options['fields']['field_user_type']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_user_type']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_user_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_type']['delta_offset'] = '0';
  /* Field: Field: Organization */
  $handler->display->display_options['fields']['field_organization_collection']['id'] = 'field_organization_collection';
  $handler->display->display_options['fields']['field_organization_collection']['table'] = 'field_data_field_organization_collection';
  $handler->display->display_options['fields']['field_organization_collection']['field'] = 'field_organization_collection';
  $handler->display->display_options['fields']['field_organization_collection']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_collection']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_organization_collection']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_organization_collection']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_organization_collection']['separator'] = '';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['core_profile_user_details'] = $view;

  $view = new view();
  $view->name = 'core_profile_user_related_content';
  $view->description = '';
  $view->tag = 'AGRI Core';
  $view->base_table = 'node';
  $view->human_name = 'Core profile user related content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'News and events';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'type' => 'type',
    'title' => 'title',
    'created' => 'created',
    'view_node' => 'view_node',
    'field_event_date' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_event_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = TRUE;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'tags' => 'tags',
    'forums' => 0,
    'agricultural_sectors' => 0,
    'classification' => 0,
    'event_type' => 0,
    'field_of_activity' => 0,
    'core_geographical_area' => 0,
    'newsletter' => 0,
    'publication_type' => 0,
    'core_user_type' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Published on';
  $handler->display->display_options['fields']['created']['date_format'] = 'eip_agri_medium';
  /* Field: Content: Publication date */
  $handler->display->display_options['fields']['field_core_publication_date']['id'] = 'field_core_publication_date';
  $handler->display->display_options['fields']['field_core_publication_date']['table'] = 'field_data_field_core_publication_date';
  $handler->display->display_options['fields']['field_core_publication_date']['field'] = 'field_core_publication_date';
  $handler->display->display_options['fields']['field_core_publication_date']['label'] = 'Opening/closing dates';
  $handler->display->display_options['fields']['field_core_publication_date']['settings'] = array(
    'format_type' => 'eip_agri_medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Total programme funding */
  $handler->display->display_options['fields']['field_news_total_program_funding']['id'] = 'field_news_total_program_funding';
  $handler->display->display_options['fields']['field_news_total_program_funding']['table'] = 'field_data_field_news_total_program_funding';
  $handler->display->display_options['fields']['field_news_total_program_funding']['field'] = 'field_news_total_program_funding';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
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
    'funding_opportunities' => 'funding_opportunities',
  );

  /* Display: Block: Funding opportunities */
  $handler = $view->new_display('block', 'Block: Funding opportunities', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Funding opportunities';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No published funding opportunities.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';

  /* Display: Block: News and events */
  $handler = $view->new_display('block', 'Block: News and events', 'block_1');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No news or events found.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Published on';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['date_format'] = 'eip_agri_medium';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
  /* Field: Content: Dates */
  $handler->display->display_options['fields']['field_event_date']['id'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['fields']['field_event_date']['field'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_event_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_event_date']['alter']['text'] = '<div class="small grey">[field_event_date]</div>';
  $handler->display->display_options['fields']['field_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
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
    'event' => 'event',
    'news' => 'news',
  );
  $export['core_profile_user_related_content'] = $view;

  $view = new view();
  $view->name = 'core_spotlight';
  $view->description = '';
  $view->tag = 'AGRI Core';
  $view->base_table = 'node';
  $view->human_name = 'Core Spotlight';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Feature News';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Spotlight */
  $handler = $view->new_display('block', 'Spotlight', 'block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_news_image' => 0,
    'title' => 0,
    'body' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_news_image' => 0,
    'title' => 0,
    'body' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['view_mode'] = 'core_spotlight';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'node|created';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'core_spotlight';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_news_image']['id'] = 'field_news_image';
  $handler->display->display_options['fields']['field_news_image']['table'] = 'field_data_field_news_image';
  $handler->display->display_options['fields']['field_news_image']['field'] = 'field_news_image';
  $handler->display->display_options['fields']['field_news_image']['label'] = '';
  $handler->display->display_options['fields']['field_news_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_news_image']['settings'] = array(
    'image_style' => 'spotlight',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: It is a Top News (field_top_news) */
  $handler->display->display_options['filters']['field_top_news_value']['id'] = 'field_top_news_value';
  $handler->display->display_options['filters']['field_top_news_value']['table'] = 'field_data_field_top_news';
  $handler->display->display_options['filters']['field_top_news_value']['field'] = 'field_top_news_value';
  $handler->display->display_options['filters']['field_top_news_value']['value'] = array(
    1 => '1',
  );
  $export['core_spotlight'] = $view;

  $view = new view();
  $view->name = 'core_tweets';
  $view->description = '';
  $view->tag = 'AGRI Core';
  $view->base_table = 'twitter';
  $view->human_name = 'Core Tweets';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Latest Tweets';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Twitter Account: Profile image */
  $handler->display->display_options['fields']['profile_image_url']['id'] = 'profile_image_url';
  $handler->display->display_options['fields']['profile_image_url']['table'] = 'twitter_account';
  $handler->display->display_options['fields']['profile_image_url']['field'] = 'profile_image_url';
  $handler->display->display_options['fields']['profile_image_url']['label'] = '';
  $handler->display->display_options['fields']['profile_image_url']['element_label_colon'] = FALSE;
  /* Field: Twitter Account: Login name */
  $handler->display->display_options['fields']['screen_name']['id'] = 'screen_name';
  $handler->display->display_options['fields']['screen_name']['table'] = 'twitter_account';
  $handler->display->display_options['fields']['screen_name']['field'] = 'screen_name';
  $handler->display->display_options['fields']['screen_name']['label'] = '';
  $handler->display->display_options['fields']['screen_name']['element_label_colon'] = FALSE;
  /* Field: Twitter: Message text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'twitter';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['element_type'] = 'div';
  $handler->display->display_options['fields']['text']['element_class'] = 'italic grey';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['link_urls'] = 1;
  $handler->display->display_options['fields']['text']['link_usernames'] = 1;
  $handler->display->display_options['fields']['text']['link_hashtags'] = 0;
  $handler->display->display_options['fields']['text']['link_attributes'] = 1;
  /* Field: Twitter: Created time */
  $handler->display->display_options['fields']['created_time']['id'] = 'created_time';
  $handler->display->display_options['fields']['created_time']['table'] = 'twitter';
  $handler->display->display_options['fields']['created_time']['field'] = 'created_time';
  $handler->display->display_options['fields']['created_time']['label'] = '';
  $handler->display->display_options['fields']['created_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created_time']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['created_time']['element_wrapper_class'] = 'small grey align-right';
  $handler->display->display_options['fields']['created_time']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created_time']['date_format'] = 'time ago';
  /* Sort criterion: Twitter: Created time */
  $handler->display->display_options['sorts']['created_time']['id'] = 'created_time';
  $handler->display->display_options['sorts']['created_time']['table'] = 'twitter';
  $handler->display->display_options['sorts']['created_time']['field'] = 'created_time';
  $handler->display->display_options['sorts']['created_time']['order'] = 'DESC';
  /* Filter criterion: Twitter Account: Protected status */
  $handler->display->display_options['filters']['protected']['id'] = 'protected';
  $handler->display->display_options['filters']['protected']['table'] = 'twitter_account';
  $handler->display->display_options['filters']['protected']['field'] = 'protected';
  $handler->display->display_options['filters']['protected']['value'] = '0';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['core_tweets'] = $view;

  $view = new view();
  $view->name = 'core_user_collaborative_areas';
  $view->description = 'Shows Collaborative Areas of a user.';
  $view->tag = 'AGRI Core';
  $view->base_table = 'og_membership';
  $view->human_name = 'Core user collaborative areas';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My collaborative areas';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: OG membership: User from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_user']['id'] = 'og_membership_related_user';
  $handler->display->display_options['relationships']['og_membership_related_user']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_user']['field'] = 'og_membership_related_user';
  /* Relationship: OG membership: Group Content from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_node_group']['id'] = 'og_membership_related_node_group';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['field'] = 'og_membership_related_node_group';
  /* Field: OG membership: Og membership ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'og_membership';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['fields']['title']['label'] = 'Collaborative area';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'og_membership_related_user';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  /* Field: OG membership: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'og_membership';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Membership state';
  /* Field: OG membership: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'og_membership';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Member since';
  $handler->display->display_options['fields']['created']['date_format'] = 'eip_agri_medium';
  /* Field: OG membership: Edit link */
  $handler->display->display_options['fields']['edit_membership']['id'] = 'edit_membership';
  $handler->display->display_options['fields']['edit_membership']['table'] = 'og_membership';
  $handler->display->display_options['fields']['edit_membership']['field'] = 'edit_membership';
  $handler->display->display_options['fields']['edit_membership']['label'] = '';
  $handler->display->display_options['fields']['edit_membership']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_membership']['text'] = 'Modify membership';
  /* Sort criterion: OG membership: Created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'og_membership';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'og_membership_related_user';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: OG membership: Group_type */
  $handler->display->display_options['filters']['group_type']['id'] = 'group_type';
  $handler->display->display_options['filters']['group_type']['table'] = 'og_membership';
  $handler->display->display_options['filters']['group_type']['field'] = 'group_type';
  $handler->display->display_options['filters']['group_type']['value'] = array(
    'node' => 'node',
  );
  /* Filter criterion: Content: Status (field_projects_active) */
  $handler->display->display_options['filters']['field_projects_active_value']['id'] = 'field_projects_active_value';
  $handler->display->display_options['filters']['field_projects_active_value']['table'] = 'field_data_field_projects_active';
  $handler->display->display_options['filters']['field_projects_active_value']['field'] = 'field_projects_active_value';
  $handler->display->display_options['filters']['field_projects_active_value']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['filters']['field_projects_active_value']['value'] = array(
    1 => '1',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'my/collaborative-areas';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'My collaborative areas';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'My collaborative areas';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'user-menu';
  $export['core_user_collaborative_areas'] = $view;

  $view = new view();
  $view->name = 'core_user_content';
  $view->description = 'Lists content edited by the user.';
  $view->tag = 'Workbench';
  $view->base_table = 'node_revision';
  $view->human_name = 'Core user content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'My content';
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'view all';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 25, 50, 100, 200';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'type' => 'type',
    'status' => 'status',
    'timestamp' => 'timestamp',
    'edit_node' => 'edit_node',
    'is_published' => 'is_published',
  );
  $handler->display->display_options['style_options']['default'] = 'timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
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
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'is_published' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'You haven\'t created or edited any content.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Relationship: Content revision: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['vid']['id'] = 'vid';
  $handler->display->display_options['relationships']['vid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['vid']['field'] = 'vid';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'vid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content revision: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'vid';
  $handler->display->display_options['fields']['title']['link_to_node'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'vid';
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'vid';
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content revision: Updated date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Last updated';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'vid';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['link_class'] = 'btn btn-default btn-xs btn-success';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['relationship'] = 'vid';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'vid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content revision: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node_revision';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_1_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_1_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'vid';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'vid';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'published';
  $handler->display->display_options['filters']['status']['expose']['remember'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'vid';
  $handler->display->display_options['filters']['type_1']['operator'] = 'not empty';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'my/content';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'My content';
  $handler->display->display_options['menu']['weight'] = '';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['core_user_content'] = $view;

  $view = new view();
  $view->name = 'core_user_webform_submissions';
  $view->description = '';
  $view->tag = 'AGRI Core';
  $view->base_table = 'webform_submissions';
  $view->human_name = 'Core user webform submissions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My form submissions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'sid' => 'sid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'sid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Webform submissions: Node */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  /* Relationship: Webform submissions: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['label'] = 'Submission form';
  /* Field: Webform submissions: Submitted */
  $handler->display->display_options['fields']['submitted']['id'] = 'submitted';
  $handler->display->display_options['fields']['submitted']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['submitted']['field'] = 'submitted';
  $handler->display->display_options['fields']['submitted']['date_format'] = 'eip_agri_medium';
  /* Field: Webform submissions: View link */
  $handler->display->display_options['fields']['view_submission']['id'] = 'view_submission';
  $handler->display->display_options['fields']['view_submission']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['view_submission']['field'] = 'view_submission';
  $handler->display->display_options['fields']['view_submission']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_submission']['text'] = 'View';
  /* Field: Webform submissions: Edit link */
  $handler->display->display_options['fields']['edit_submission']['id'] = 'edit_submission';
  $handler->display->display_options['fields']['edit_submission']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['edit_submission']['field'] = 'edit_submission';
  $handler->display->display_options['fields']['edit_submission']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_submission']['text'] = 'Edit';
  /* Field: Webform submissions: Delete link */
  $handler->display->display_options['fields']['delete_submission']['id'] = 'delete_submission';
  $handler->display->display_options['fields']['delete_submission']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['delete_submission']['field'] = 'delete_submission';
  $handler->display->display_options['fields']['delete_submission']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_submission']['text'] = 'Delete';
  /* Sort criterion: Webform submissions: Submitted */
  $handler->display->display_options['sorts']['submitted']['id'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['table'] = 'webform_submissions';
  $handler->display->display_options['sorts']['submitted']['field'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['order'] = 'DESC';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';

  /* Display: All forms submissions */
  $handler = $view->new_display('page', 'All forms submissions', 'page');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
  );
  $handler->display->display_options['path'] = 'my/webform-submissions';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'My form submissions';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Events Submissions */
  $handler = $view->new_display('page', 'Events Submissions', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My events';
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
  );
  $handler->display->display_options['path'] = 'my/webform-events-submissions';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'My events';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['core_user_webform_submissions'] = $view;

  $view = new view();
  $view->name = 'organizations';
  $view->description = 'View to list values for Organization\'s entity references.';
  $view->tag = 'AGRI Core';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'Organizations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Field collection item: Organization/Institution name (original language) */
  $handler->display->display_options['fields']['field_organization_name']['id'] = 'field_organization_name';
  $handler->display->display_options['fields']['field_organization_name']['table'] = 'field_data_field_organization_name';
  $handler->display->display_options['fields']['field_organization_name']['field'] = 'field_organization_name';
  $handler->display->display_options['fields']['field_organization_name']['label'] = 'Organization';

  /* Display: Organizations */
  $handler = $view->new_display('entityreference', 'Organizations', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_organization_name' => 'field_organization_name',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['organizations'] = $view;

  return $export;
}
