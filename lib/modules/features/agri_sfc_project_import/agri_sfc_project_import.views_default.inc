<?php

/**
 * @file
 * agri_sfc_project_import.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function agri_sfc_project_import_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'agri_sfc_import_moderation';
  $view->description = 'Imported SFC projects Excel sheets.';
  $view->tag = 'AGRI SFC project import';
  $view->base_table = 'node';
  $view->human_name = 'AGRI SFC project import moderation';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'SFC Projects';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'use_sfc_importer';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'views_bulk_operations' => 'views_bulk_operations',
    'field_project_puid' => 'field_project_puid',
    'field_proj_title_eng' => 'field_proj_title_eng',
    'title' => 'title',
    'field_proj_editor_of_text' => 'field_proj_editor_of_text',
    'field_proj_starting_date' => 'field_proj_starting_date',
    'field_proj_end_date' => 'field_proj_starting_date',
    'field_proj_project_type' => 'field_proj_project_type',
    'field_proj_og_project_status' => 'field_proj_og_project_status',
    'field_proj_website' => 'field_proj_website',
    'created' => 'created',
    'changed' => 'changed',
    'field_proj_sfc_attachments' => 'field_proj_sfc_attachments',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_project_puid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_proj_title_eng' => array(
      'sortable' => 1,
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
    'field_proj_editor_of_text' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_proj_starting_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' - ',
      'empty_column' => 0,
    ),
    'field_proj_end_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_proj_project_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_proj_og_project_status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_proj_website' => array(
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
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_proj_sfc_attachments' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No projects to review.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Flags: agri_privacy_policy */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'flag_agri_privacy_policy';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'agri_privacy_policy';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::agri_projects_hide_partners_info' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Hide Partners info',
    ),
    'rules_component::agri_projects_show_partners_info' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Show Parners info',
    ),
    'action::agri_core_wb_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Publish selected projects',
    ),
  );
  /* Field: Content: PUID (Project Unique ID) */
  $handler->display->display_options['fields']['field_project_puid']['id'] = 'field_project_puid';
  $handler->display->display_options['fields']['field_project_puid']['table'] = 'field_data_field_project_puid';
  $handler->display->display_options['fields']['field_project_puid']['field'] = 'field_project_puid';
  $handler->display->display_options['fields']['field_project_puid']['label'] = 'Project ID';
  $handler->display->display_options['fields']['field_project_puid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_project_puid']['alter']['text'] = '<strong>[field_project_puid]</strong>';
  /* Field: Content: Title (in English) */
  $handler->display->display_options['fields']['field_proj_title_eng']['id'] = 'field_proj_title_eng';
  $handler->display->display_options['fields']['field_proj_title_eng']['table'] = 'field_data_field_proj_title_eng';
  $handler->display->display_options['fields']['field_proj_title_eng']['field'] = 'field_proj_title_eng';
  $handler->display->display_options['fields']['field_proj_title_eng']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_proj_title_eng']['alter']['path'] = 'node/[nid]';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Editor of the text */
  $handler->display->display_options['fields']['field_proj_editor_of_text']['id'] = 'field_proj_editor_of_text';
  $handler->display->display_options['fields']['field_proj_editor_of_text']['table'] = 'field_data_field_proj_editor_of_text';
  $handler->display->display_options['fields']['field_proj_editor_of_text']['field'] = 'field_proj_editor_of_text';
  /* Field: Content: Starting date */
  $handler->display->display_options['fields']['field_proj_starting_date']['id'] = 'field_proj_starting_date';
  $handler->display->display_options['fields']['field_proj_starting_date']['table'] = 'field_data_field_proj_starting_date';
  $handler->display->display_options['fields']['field_proj_starting_date']['field'] = 'field_proj_starting_date';
  $handler->display->display_options['fields']['field_proj_starting_date']['label'] = 'Dates (Start/End)';
  $handler->display->display_options['fields']['field_proj_starting_date']['settings'] = array(
    'format_type' => 'eip_agri_long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: End date */
  $handler->display->display_options['fields']['field_proj_end_date']['id'] = 'field_proj_end_date';
  $handler->display->display_options['fields']['field_proj_end_date']['table'] = 'field_data_field_proj_end_date';
  $handler->display->display_options['fields']['field_proj_end_date']['field'] = 'field_proj_end_date';
  $handler->display->display_options['fields']['field_proj_end_date']['settings'] = array(
    'format_type' => 'eip_agri_long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Project type */
  $handler->display->display_options['fields']['field_proj_project_type']['id'] = 'field_proj_project_type';
  $handler->display->display_options['fields']['field_proj_project_type']['table'] = 'field_data_field_proj_project_type';
  $handler->display->display_options['fields']['field_proj_project_type']['field'] = 'field_proj_project_type';
  $handler->display->display_options['fields']['field_proj_project_type']['label'] = '';
  $handler->display->display_options['fields']['field_proj_project_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_proj_project_type']['element_label_colon'] = FALSE;
  /* Field: Content: Project status */
  $handler->display->display_options['fields']['field_proj_og_project_status']['id'] = 'field_proj_og_project_status';
  $handler->display->display_options['fields']['field_proj_og_project_status']['table'] = 'field_data_field_proj_og_project_status';
  $handler->display->display_options['fields']['field_proj_og_project_status']['field'] = 'field_proj_og_project_status';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Added';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'Y-m-d H:i:s';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'eip_agri_long';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'Y-m-d H:i:s';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'eip_agri_long';
  /* Field: Workbench Moderation: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Moderation state';
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  /* Field: Content: Main funding source */
  $handler->display->display_options['fields']['field_proj_funding_source_list']['id'] = 'field_proj_funding_source_list';
  $handler->display->display_options['fields']['field_proj_funding_source_list']['table'] = 'field_data_field_proj_funding_source_list';
  $handler->display->display_options['fields']['field_proj_funding_source_list']['field'] = 'field_proj_funding_source_list';
  /* Field: Content: Version Count */
  $handler->display->display_options['fields']['version_count']['id'] = 'version_count';
  $handler->display->display_options['fields']['version_count']['table'] = 'node';
  $handler->display->display_options['fields']['version_count']['field'] = 'version_count';
  $handler->display->display_options['fields']['version_count']['separator'] = '';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = 'Hide/Show Partners info';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops']['link_type'] = 'toggle';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: SFC (field_proj_is_sfc) */
  $handler->display->display_options['filters']['field_proj_is_sfc_value']['id'] = 'field_proj_is_sfc_value';
  $handler->display->display_options['filters']['field_proj_is_sfc_value']['table'] = 'field_data_field_proj_is_sfc';
  $handler->display->display_options['filters']['field_proj_is_sfc_value']['field'] = 'field_proj_is_sfc_value';
  $handler->display->display_options['filters']['field_proj_is_sfc_value']['value'] = array(
    1 => 1,
  );
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    'needs_review' => 'needs_review',
  );
  $handler->display->display_options['filters']['state']['group'] = 1;
  /* Filter criterion: Workbench Moderation: Current */
  $handler->display->display_options['filters']['is_current']['id'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['value'] = '1';
  /* Filter criterion: Content: Main funding source (field_proj_funding_source_list) */
  $handler->display->display_options['filters']['field_proj_funding_source_list_value']['id'] = 'field_proj_funding_source_list_value';
  $handler->display->display_options['filters']['field_proj_funding_source_list_value']['table'] = 'field_data_field_proj_funding_source_list';
  $handler->display->display_options['filters']['field_proj_funding_source_list_value']['field'] = 'field_proj_funding_source_list_value';
  $handler->display->display_options['filters']['field_proj_funding_source_list_value']['value'] = array(
    0 => '0',
    4 => '4',
  );
  $handler->display->display_options['filters']['field_proj_funding_source_list_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_proj_funding_source_list_value']['expose']['operator_id'] = 'field_proj_funding_source_list_value_op';
  $handler->display->display_options['filters']['field_proj_funding_source_list_value']['expose']['label'] = 'Main funding source';
  $handler->display->display_options['filters']['field_proj_funding_source_list_value']['expose']['operator'] = 'field_proj_funding_source_list_value_op';
  $handler->display->display_options['filters']['field_proj_funding_source_list_value']['expose']['identifier'] = 'field_proj_funding_source_list_value';
  $handler->display->display_options['filters']['field_proj_funding_source_list_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
  );
  $handler->display->display_options['filters']['field_proj_funding_source_list_value']['expose']['reduce'] = TRUE;

  /* Display: SFC */
  $handler = $view->new_display('page', 'SFC', 'sfc');
  $handler->display->display_options['display_description'] = 'Projects imported from SFC Excel templates.';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['path'] = 'sfc-projects';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'SFC Projects';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-core-action-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['agri_sfc_import_moderation'] = $view;

  $view = new view();
  $view->name = 'sfc_final_report';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'SFC Final report';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'SFC Final report';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'use_sfc_importer';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Load final report',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          'project::field_proj_attachment' => 'project::field_proj_attachment',
        ),
      ),
    ),
  );
  /* Field: Content: PUID (Project Unique ID) */
  $handler->display->display_options['fields']['field_project_puid']['id'] = 'field_project_puid';
  $handler->display->display_options['fields']['field_project_puid']['table'] = 'field_data_field_project_puid';
  $handler->display->display_options['fields']['field_project_puid']['field'] = 'field_project_puid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
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
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );
  /* Filter criterion: Content: SFC (field_proj_is_sfc) */
  $handler->display->display_options['filters']['field_proj_is_sfc_value']['id'] = 'field_proj_is_sfc_value';
  $handler->display->display_options['filters']['field_proj_is_sfc_value']['table'] = 'field_data_field_proj_is_sfc';
  $handler->display->display_options['filters']['field_proj_is_sfc_value']['field'] = 'field_proj_is_sfc_value';
  $handler->display->display_options['filters']['field_proj_is_sfc_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: PUID (Project Unique ID) (field_project_puid) */
  $handler->display->display_options['filters']['field_project_puid_value']['id'] = 'field_project_puid_value';
  $handler->display->display_options['filters']['field_project_puid_value']['table'] = 'field_data_field_project_puid';
  $handler->display->display_options['filters']['field_project_puid_value']['field'] = 'field_project_puid_value';
  $handler->display->display_options['filters']['field_project_puid_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_puid_value']['expose']['operator_id'] = 'field_project_puid_value_op';
  $handler->display->display_options['filters']['field_project_puid_value']['expose']['label'] = 'PUID (Project Unique ID)';
  $handler->display->display_options['filters']['field_project_puid_value']['expose']['operator'] = 'field_project_puid_value_op';
  $handler->display->display_options['filters']['field_project_puid_value']['expose']['identifier'] = 'field_project_puid_value';
  $handler->display->display_options['filters']['field_project_puid_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
  );

  /* Display: SFC Final report */
  $handler = $view->new_display('page', 'SFC Final report', 'page');
  $handler->display->display_options['display_description'] = 'Views bulk for import the final report';
  $handler->display->display_options['path'] = 'sfc-projects/final-report';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Load final report';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Delete prj */
  $handler = $view->new_display('page', 'Delete prj', 'page_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '30';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_revision' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: PUID (Project Unique ID) */
  $handler->display->display_options['fields']['field_project_puid']['id'] = 'field_project_puid';
  $handler->display->display_options['fields']['field_project_puid']['table'] = 'field_data_field_project_puid';
  $handler->display->display_options['fields']['field_project_puid']['field'] = 'field_project_puid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
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
    8 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );
  /* Filter criterion: Content: SFC (field_proj_is_sfc) */
  $handler->display->display_options['filters']['field_proj_is_sfc_value']['id'] = 'field_proj_is_sfc_value';
  $handler->display->display_options['filters']['field_proj_is_sfc_value']['table'] = 'field_data_field_proj_is_sfc';
  $handler->display->display_options['filters']['field_proj_is_sfc_value']['field'] = 'field_proj_is_sfc_value';
  $handler->display->display_options['filters']['field_proj_is_sfc_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: PUID (Project Unique ID) (field_project_puid) */
  $handler->display->display_options['filters']['field_project_puid_value']['id'] = 'field_project_puid_value';
  $handler->display->display_options['filters']['field_project_puid_value']['table'] = 'field_data_field_project_puid';
  $handler->display->display_options['filters']['field_project_puid_value']['field'] = 'field_project_puid_value';
  $handler->display->display_options['filters']['field_project_puid_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_puid_value']['expose']['operator_id'] = 'field_project_puid_value_op';
  $handler->display->display_options['filters']['field_project_puid_value']['expose']['label'] = 'PUID (Project Unique ID)';
  $handler->display->display_options['filters']['field_project_puid_value']['expose']['operator'] = 'field_project_puid_value_op';
  $handler->display->display_options['filters']['field_project_puid_value']['expose']['identifier'] = 'field_project_puid_value';
  $handler->display->display_options['filters']['field_project_puid_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
  );
  /* Filter criterion: Content: Modification date (field_proj_sfc_modification_date) */
  $handler->display->display_options['filters']['field_proj_sfc_modification_date_value']['id'] = 'field_proj_sfc_modification_date_value';
  $handler->display->display_options['filters']['field_proj_sfc_modification_date_value']['table'] = 'field_data_field_proj_sfc_modification_date';
  $handler->display->display_options['filters']['field_proj_sfc_modification_date_value']['field'] = 'field_proj_sfc_modification_date_value';
  $handler->display->display_options['filters']['field_proj_sfc_modification_date_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_proj_sfc_modification_date_value']['expose']['operator_id'] = 'field_proj_sfc_modification_date_value_op';
  $handler->display->display_options['filters']['field_proj_sfc_modification_date_value']['expose']['label'] = 'Modification date';
  $handler->display->display_options['filters']['field_proj_sfc_modification_date_value']['expose']['operator'] = 'field_proj_sfc_modification_date_value_op';
  $handler->display->display_options['filters']['field_proj_sfc_modification_date_value']['expose']['identifier'] = 'field_proj_sfc_modification_date_value';
  $handler->display->display_options['filters']['field_proj_sfc_modification_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
  );
  $handler->display->display_options['filters']['field_proj_sfc_modification_date_value']['granularity'] = 'second';
  $handler->display->display_options['filters']['field_proj_sfc_modification_date_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_proj_sfc_modification_date_value']['year_range'] = '1950:2050';
  $handler->display->display_options['path'] = 'sfc-projects/delete-sfc';
  $export['sfc_final_report'] = $view;

  return $export;
}
