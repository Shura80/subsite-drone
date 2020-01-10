<?php

/**
 * @file
 * enrd_projects.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function enrd_projects_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'enrd_projects_export';
  $view->description = 'DG BUDG projects export in CSV and XLSX formats.';
  $view->tag = 'ENRD';
  $view->base_table = 'node';
  $view->human_name = 'ENRD DG BUDG projects export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Projects export';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'manage enrd projects export';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '5';
  $handler->display->display_options['pager']['options']['tags']['first'] = '«';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹';
  $handler->display->display_options['pager']['options']['tags']['next'] = '›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '»';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_enrd_prj_full_proj_summary' => 'field_enrd_prj_full_proj_summary',
    'field_enrd_prj_results' => 'field_enrd_prj_results',
    'field_enrd_prj_timeframe' => 'field_enrd_prj_timeframe',
    'field_enrd_prj_timeframe_1' => 'field_enrd_prj_timeframe_1',
    'field_enrd_prj_eu_budg_mff_head' => 'field_enrd_prj_eu_budg_mff_head',
    'field_enrd_prj_programme_name' => 'field_enrd_prj_programme_name',
    'field_enrd_prj_ec_priorities' => 'field_enrd_prj_ec_priorities',
    'field_enrd_prj_eu_budget_contrib' => 'field_enrd_prj_eu_budget_contrib',
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
    'field_enrd_prj_full_proj_summary' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_prj_results' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_prj_timeframe' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_prj_timeframe_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_prj_eu_budg_mff_head' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_prj_programme_name' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_prj_ec_priorities' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_prj_eu_budget_contrib' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'No projects available to display.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Project summary */
  $handler->display->display_options['fields']['field_enrd_prj_full_proj_summary']['id'] = 'field_enrd_prj_full_proj_summary';
  $handler->display->display_options['fields']['field_enrd_prj_full_proj_summary']['table'] = 'field_data_field_enrd_prj_full_proj_summary';
  $handler->display->display_options['fields']['field_enrd_prj_full_proj_summary']['field'] = 'field_enrd_prj_full_proj_summary';
  $handler->display->display_options['fields']['field_enrd_prj_full_proj_summary']['label'] = 'Description';
  $handler->display->display_options['fields']['field_enrd_prj_full_proj_summary']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['field_enrd_prj_full_proj_summary']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_prj_full_proj_summary']['element_label_colon'] = FALSE;
  /* Field: Content: Project results */
  $handler->display->display_options['fields']['field_enrd_prj_results']['id'] = 'field_enrd_prj_results';
  $handler->display->display_options['fields']['field_enrd_prj_results']['table'] = 'field_data_field_enrd_prj_results';
  $handler->display->display_options['fields']['field_enrd_prj_results']['field'] = 'field_enrd_prj_results';
  $handler->display->display_options['fields']['field_enrd_prj_results']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['field_enrd_prj_results']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_prj_results']['element_label_colon'] = FALSE;
  /* Field: Content: Timeframe */
  $handler->display->display_options['fields']['field_enrd_prj_timeframe']['id'] = 'field_enrd_prj_timeframe';
  $handler->display->display_options['fields']['field_enrd_prj_timeframe']['table'] = 'field_data_field_enrd_prj_timeframe';
  $handler->display->display_options['fields']['field_enrd_prj_timeframe']['field'] = 'field_enrd_prj_timeframe';
  $handler->display->display_options['fields']['field_enrd_prj_timeframe']['label'] = 'Start year';
  $handler->display->display_options['fields']['field_enrd_prj_timeframe']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_timeframe']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Timeframe */
  $handler->display->display_options['fields']['field_enrd_prj_timeframe_1']['id'] = 'field_enrd_prj_timeframe_1';
  $handler->display->display_options['fields']['field_enrd_prj_timeframe_1']['table'] = 'field_data_field_enrd_prj_timeframe';
  $handler->display->display_options['fields']['field_enrd_prj_timeframe_1']['field'] = 'field_enrd_prj_timeframe';
  $handler->display->display_options['fields']['field_enrd_prj_timeframe_1']['label'] = 'End year';
  $handler->display->display_options['fields']['field_enrd_prj_timeframe_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_timeframe_1']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: EU Budget MFF heading */
  $handler->display->display_options['fields']['field_enrd_prj_eu_budg_mff_head']['id'] = 'field_enrd_prj_eu_budg_mff_head';
  $handler->display->display_options['fields']['field_enrd_prj_eu_budg_mff_head']['table'] = 'field_data_field_enrd_prj_eu_budg_mff_head';
  $handler->display->display_options['fields']['field_enrd_prj_eu_budg_mff_head']['field'] = 'field_enrd_prj_eu_budg_mff_head';
  $handler->display->display_options['fields']['field_enrd_prj_eu_budg_mff_head']['element_label_colon'] = FALSE;
  /* Field: Content: Programme name */
  $handler->display->display_options['fields']['field_enrd_prj_programme_name']['id'] = 'field_enrd_prj_programme_name';
  $handler->display->display_options['fields']['field_enrd_prj_programme_name']['table'] = 'field_data_field_enrd_prj_programme_name';
  $handler->display->display_options['fields']['field_enrd_prj_programme_name']['field'] = 'field_enrd_prj_programme_name';
  $handler->display->display_options['fields']['field_enrd_prj_programme_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_programme_name']['delta_offset'] = '0';
  /* Field: Content: EC priorities */
  $handler->display->display_options['fields']['field_enrd_prj_ec_priorities']['id'] = 'field_enrd_prj_ec_priorities';
  $handler->display->display_options['fields']['field_enrd_prj_ec_priorities']['table'] = 'field_data_field_enrd_prj_ec_priorities';
  $handler->display->display_options['fields']['field_enrd_prj_ec_priorities']['field'] = 'field_enrd_prj_ec_priorities';
  $handler->display->display_options['fields']['field_enrd_prj_ec_priorities']['element_label_colon'] = FALSE;
  /* Field: Content: EU Budget contribution to the project */
  $handler->display->display_options['fields']['field_enrd_prj_eu_budget_contrib']['id'] = 'field_enrd_prj_eu_budget_contrib';
  $handler->display->display_options['fields']['field_enrd_prj_eu_budget_contrib']['table'] = 'field_data_field_enrd_prj_eu_budget_contrib';
  $handler->display->display_options['fields']['field_enrd_prj_eu_budget_contrib']['field'] = 'field_enrd_prj_eu_budget_contrib';
  $handler->display->display_options['fields']['field_enrd_prj_eu_budget_contrib']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_eu_budget_contrib']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
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
    'project' => 'project',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Date: Between Dates (node) */
  $handler->display->display_options['filters']['between_date_filter']['id'] = 'between_date_filter';
  $handler->display->display_options['filters']['between_date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['between_date_filter']['field'] = 'between_date_filter';
  $handler->display->display_options['filters']['between_date_filter']['group'] = 1;
  $handler->display->display_options['filters']['between_date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['between_date_filter']['expose']['operator_id'] = 'between_date_filter_op';
  $handler->display->display_options['filters']['between_date_filter']['expose']['label'] = 'Project period';
  $handler->display->display_options['filters']['between_date_filter']['expose']['operator'] = 'between_date_filter_op';
  $handler->display->display_options['filters']['between_date_filter']['expose']['identifier'] = 'between_date_project_filter';
  $handler->display->display_options['filters']['between_date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    10 => 0,
    24 => 0,
    8 => 0,
    9 => 0,
    7 => 0,
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
  );
  $handler->display->display_options['filters']['between_date_filter']['granularity'] = 'year';
  $handler->display->display_options['filters']['between_date_filter']['start_date_field'] = 'field_data_field_enrd_prj_timeframe.field_enrd_prj_timeframe_value';
  $handler->display->display_options['filters']['between_date_filter']['end_date_field'] = 'field_data_field_enrd_prj_timeframe.field_enrd_prj_timeframe_value2';
  /* Filter criterion: Content: Ready to export (field_enrd_prj_export) */
  $handler->display->display_options['filters']['field_enrd_prj_export_value']['id'] = 'field_enrd_prj_export_value';
  $handler->display->display_options['filters']['field_enrd_prj_export_value']['table'] = 'field_data_field_enrd_prj_export';
  $handler->display->display_options['filters']['field_enrd_prj_export_value']['field'] = 'field_enrd_prj_export_value';
  $handler->display->display_options['filters']['field_enrd_prj_export_value']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_prj_export_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_prj_export_value']['expose']['operator_id'] = 'field_enrd_prj_export_value_op';
  $handler->display->display_options['filters']['field_enrd_prj_export_value']['expose']['label'] = 'Export status';
  $handler->display->display_options['filters']['field_enrd_prj_export_value']['expose']['operator'] = 'field_enrd_prj_export_value_op';
  $handler->display->display_options['filters']['field_enrd_prj_export_value']['expose']['identifier'] = 'field_enrd_prj_export_value';
  $handler->display->display_options['filters']['field_enrd_prj_export_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    10 => 0,
    24 => 0,
    8 => 0,
    9 => 0,
    7 => 0,
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
  );
  $handler->display->display_options['filters']['field_enrd_prj_export_value']['reduce_duplicates'] = TRUE;

  /* Display: Page: Projects Export */
  $handler = $view->new_display('page', 'Page: Projects Export', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'DG BUDG projects export';
  $handler->display->display_options['field_language'] = '***DEFAULT_LANGUAGE***';
  $handler->display->display_options['path'] = 'admin/enrd/projects';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'DG BUDG projects export';
  $handler->display->display_options['menu']['description'] = 'Allows to export DG BUDG projects in CSV and XLSX format.';
  $handler->display->display_options['menu']['weight'] = '15';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export: Projects Export */
  $handler = $view->new_display('views_data_export', 'Data export: Projects Export', 'views_data_export_projects_csv');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['attach_text'] = 'Export';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = '1';
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Programming period */
  $handler->display->display_options['fields']['field_enrd_prj_program_period']['id'] = 'field_enrd_prj_program_period';
  $handler->display->display_options['fields']['field_enrd_prj_program_period']['table'] = 'field_data_field_enrd_prj_program_period';
  $handler->display->display_options['fields']['field_enrd_prj_program_period']['field'] = 'field_enrd_prj_program_period';
  /* Field: Content: Rural Development Policy */
  $handler->display->display_options['fields']['field_tax_rural_dev_policy']['id'] = 'field_tax_rural_dev_policy';
  $handler->display->display_options['fields']['field_tax_rural_dev_policy']['table'] = 'field_data_field_tax_rural_dev_policy';
  $handler->display->display_options['fields']['field_tax_rural_dev_policy']['field'] = 'field_tax_rural_dev_policy';
  $handler->display->display_options['fields']['field_tax_rural_dev_policy']['label'] = 'Priority';
  $handler->display->display_options['fields']['field_tax_rural_dev_policy']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tax_rural_dev_policy']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_tax_rural_dev_policy']['separator'] = ',';
  /* Field: Content: Focus Area */
  $handler->display->display_options['fields']['field_enrd_prj_focus_area']['id'] = 'field_enrd_prj_focus_area';
  $handler->display->display_options['fields']['field_enrd_prj_focus_area']['table'] = 'field_data_field_enrd_prj_focus_area';
  $handler->display->display_options['fields']['field_enrd_prj_focus_area']['field'] = 'field_enrd_prj_focus_area';
  $handler->display->display_options['fields']['field_enrd_prj_focus_area']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: Measure */
  $handler->display->display_options['fields']['field_enrd_prj_measure']['id'] = 'field_enrd_prj_measure';
  $handler->display->display_options['fields']['field_enrd_prj_measure']['table'] = 'field_data_field_enrd_prj_measure';
  $handler->display->display_options['fields']['field_enrd_prj_measure']['field'] = 'field_enrd_prj_measure';
  $handler->display->display_options['fields']['field_enrd_prj_measure']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: Project acronym */
  $handler->display->display_options['fields']['field_enrd_prj_acronym']['id'] = 'field_enrd_prj_acronym';
  $handler->display->display_options['fields']['field_enrd_prj_acronym']['table'] = 'field_data_field_enrd_prj_acronym';
  $handler->display->display_options['fields']['field_enrd_prj_acronym']['field'] = 'field_enrd_prj_acronym';
  $handler->display->display_options['fields']['field_enrd_prj_acronym']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_acronym']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_acronym']['type'] = 'text_plain';
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_enrd_prj_thumbnail']['id'] = 'field_enrd_prj_thumbnail';
  $handler->display->display_options['fields']['field_enrd_prj_thumbnail']['table'] = 'field_data_field_enrd_prj_thumbnail';
  $handler->display->display_options['fields']['field_enrd_prj_thumbnail']['field'] = 'field_enrd_prj_thumbnail';
  $handler->display->display_options['fields']['field_enrd_prj_thumbnail']['label'] = 'Visual';
  $handler->display->display_options['fields']['field_enrd_prj_thumbnail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_prj_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_thumbnail']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_enrd_prj_thumbnail']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Project summary */
  $handler->display->display_options['fields']['field_enrd_prj_full_proj_summary']['id'] = 'field_enrd_prj_full_proj_summary';
  $handler->display->display_options['fields']['field_enrd_prj_full_proj_summary']['table'] = 'field_data_field_enrd_prj_full_proj_summary';
  $handler->display->display_options['fields']['field_enrd_prj_full_proj_summary']['field'] = 'field_enrd_prj_full_proj_summary';
  $handler->display->display_options['fields']['field_enrd_prj_full_proj_summary']['label'] = 'Project description';
  $handler->display->display_options['fields']['field_enrd_prj_full_proj_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_full_proj_summary']['element_default_classes'] = FALSE;
  /* Field: Content: Project results */
  $handler->display->display_options['fields']['field_enrd_prj_results']['id'] = 'field_enrd_prj_results';
  $handler->display->display_options['fields']['field_enrd_prj_results']['table'] = 'field_data_field_enrd_prj_results';
  $handler->display->display_options['fields']['field_enrd_prj_results']['field'] = 'field_enrd_prj_results';
  $handler->display->display_options['fields']['field_enrd_prj_results']['label'] = 'Project Results';
  $handler->display->display_options['fields']['field_enrd_prj_results']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_results']['element_default_classes'] = FALSE;
  /* Field: Content: Project promoter */
  $handler->display->display_options['fields']['field_enrd_prj_promoter']['id'] = 'field_enrd_prj_promoter';
  $handler->display->display_options['fields']['field_enrd_prj_promoter']['table'] = 'field_data_field_enrd_prj_promoter';
  $handler->display->display_options['fields']['field_enrd_prj_promoter']['field'] = 'field_enrd_prj_promoter';
  $handler->display->display_options['fields']['field_enrd_prj_promoter']['label'] = 'Coordinating organisation';
  $handler->display->display_options['fields']['field_enrd_prj_promoter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_promoter']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_promoter']['type'] = 'text_plain';
  /* Field: Content: Project partners */
  $handler->display->display_options['fields']['field_enrd_prj_partners']['id'] = 'field_enrd_prj_partners';
  $handler->display->display_options['fields']['field_enrd_prj_partners']['table'] = 'field_data_field_enrd_prj_partners';
  $handler->display->display_options['fields']['field_enrd_prj_partners']['field'] = 'field_enrd_prj_partners';
  $handler->display->display_options['fields']['field_enrd_prj_partners']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_partners']['element_default_classes'] = FALSE;
  /* Field: Content: Project Location - Thoroughfare (i.e. Street address) */
  $handler->display->display_options['fields']['field_enrd_prj_location_thoroughfare']['id'] = 'field_enrd_prj_location_thoroughfare';
  $handler->display->display_options['fields']['field_enrd_prj_location_thoroughfare']['table'] = 'field_data_field_enrd_prj_location';
  $handler->display->display_options['fields']['field_enrd_prj_location_thoroughfare']['field'] = 'field_enrd_prj_location_thoroughfare';
  $handler->display->display_options['fields']['field_enrd_prj_location_thoroughfare']['label'] = 'Project address(es)';
  $handler->display->display_options['fields']['field_enrd_prj_location_thoroughfare']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_location_thoroughfare']['element_default_classes'] = FALSE;
  /* Field: Content: Project Location - Postal code */
  $handler->display->display_options['fields']['field_enrd_prj_location_postal_code']['id'] = 'field_enrd_prj_location_postal_code';
  $handler->display->display_options['fields']['field_enrd_prj_location_postal_code']['table'] = 'field_data_field_enrd_prj_location';
  $handler->display->display_options['fields']['field_enrd_prj_location_postal_code']['field'] = 'field_enrd_prj_location_postal_code';
  $handler->display->display_options['fields']['field_enrd_prj_location_postal_code']['label'] = 'Project postal code(s)';
  $handler->display->display_options['fields']['field_enrd_prj_location_postal_code']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_location_postal_code']['element_default_classes'] = FALSE;
  /* Field: Content: Project Location - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_enrd_prj_location_locality']['id'] = 'field_enrd_prj_location_locality';
  $handler->display->display_options['fields']['field_enrd_prj_location_locality']['table'] = 'field_data_field_enrd_prj_location';
  $handler->display->display_options['fields']['field_enrd_prj_location_locality']['field'] = 'field_enrd_prj_location_locality';
  $handler->display->display_options['fields']['field_enrd_prj_location_locality']['label'] = 'Project town(s)';
  $handler->display->display_options['fields']['field_enrd_prj_location_locality']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_location_locality']['element_default_classes'] = FALSE;
  /* Field: Content: Project Location - Country */
  $handler->display->display_options['fields']['field_enrd_prj_location_country']['id'] = 'field_enrd_prj_location_country';
  $handler->display->display_options['fields']['field_enrd_prj_location_country']['table'] = 'field_data_field_enrd_prj_location';
  $handler->display->display_options['fields']['field_enrd_prj_location_country']['field'] = 'field_enrd_prj_location_country';
  $handler->display->display_options['fields']['field_enrd_prj_location_country']['label'] = 'Project country(ies)';
  $handler->display->display_options['fields']['field_enrd_prj_location_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_location_country']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_location_country']['display_name'] = 1;
  /* Field: Content: Project lat/long */
  $handler->display->display_options['fields']['field_enrd_prj_lat_long']['id'] = 'field_enrd_prj_lat_long';
  $handler->display->display_options['fields']['field_enrd_prj_lat_long']['table'] = 'field_data_field_enrd_prj_lat_long';
  $handler->display->display_options['fields']['field_enrd_prj_lat_long']['field'] = 'field_enrd_prj_lat_long';
  $handler->display->display_options['fields']['field_enrd_prj_lat_long']['label'] = 'Project latitude(s)';
  $handler->display->display_options['fields']['field_enrd_prj_lat_long']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_lat_long']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_lat_long']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_enrd_prj_lat_long']['type'] = 'geofield_lat';
  $handler->display->display_options['fields']['field_enrd_prj_lat_long']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
  );
  /* Field: Content: Project lat/long */
  $handler->display->display_options['fields']['field_enrd_prj_lat_long_1']['id'] = 'field_enrd_prj_lat_long_1';
  $handler->display->display_options['fields']['field_enrd_prj_lat_long_1']['table'] = 'field_data_field_enrd_prj_lat_long';
  $handler->display->display_options['fields']['field_enrd_prj_lat_long_1']['field'] = 'field_enrd_prj_lat_long';
  $handler->display->display_options['fields']['field_enrd_prj_lat_long_1']['label'] = 'Project longitude(s)';
  $handler->display->display_options['fields']['field_enrd_prj_lat_long_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_lat_long_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_lat_long_1']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_enrd_prj_lat_long_1']['type'] = 'geofield_lon';
  $handler->display->display_options['fields']['field_enrd_prj_lat_long_1']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
  );
  /* Field: Content: Timeframe */
  $handler->display->display_options['fields']['field_enrd_prj_timeframe']['id'] = 'field_enrd_prj_timeframe';
  $handler->display->display_options['fields']['field_enrd_prj_timeframe']['table'] = 'field_data_field_enrd_prj_timeframe';
  $handler->display->display_options['fields']['field_enrd_prj_timeframe']['field'] = 'field_enrd_prj_timeframe';
  $handler->display->display_options['fields']['field_enrd_prj_timeframe']['label'] = 'Project Timeframe start year';
  $handler->display->display_options['fields']['field_enrd_prj_timeframe']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_timeframe']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_timeframe']['settings'] = array(
    'format_type' => 'enrd_project_data_export',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Timeframe */
  $handler->display->display_options['fields']['field_enrd_prj_timeframe_1']['id'] = 'field_enrd_prj_timeframe_1';
  $handler->display->display_options['fields']['field_enrd_prj_timeframe_1']['table'] = 'field_data_field_enrd_prj_timeframe';
  $handler->display->display_options['fields']['field_enrd_prj_timeframe_1']['field'] = 'field_enrd_prj_timeframe';
  $handler->display->display_options['fields']['field_enrd_prj_timeframe_1']['label'] = 'Project Timeframe end year';
  $handler->display->display_options['fields']['field_enrd_prj_timeframe_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_timeframe_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_timeframe_1']['settings'] = array(
    'format_type' => 'enrd_project_data_export',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_enrd_prj_website']['id'] = 'field_enrd_prj_website';
  $handler->display->display_options['fields']['field_enrd_prj_website']['table'] = 'field_data_field_enrd_prj_website';
  $handler->display->display_options['fields']['field_enrd_prj_website']['field'] = 'field_enrd_prj_website';
  $handler->display->display_options['fields']['field_enrd_prj_website']['label'] = 'Project webpage';
  $handler->display->display_options['fields']['field_enrd_prj_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_website']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_enrd_prj_website']['type'] = 'link_title_plain';
  /* Field: Content: Related links */
  $handler->display->display_options['fields']['field_enrd_prj_related_link']['id'] = 'field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link']['table'] = 'field_data_field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link']['field'] = 'field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link']['label'] = 'Related link 1 Title';
  $handler->display->display_options['fields']['field_enrd_prj_related_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_enrd_prj_related_link']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_enrd_prj_related_link']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_enrd_prj_related_link']['delta_offset'] = '0';
  /* Field: Content: Related links */
  $handler->display->display_options['fields']['field_enrd_prj_related_link_1']['id'] = 'field_enrd_prj_related_link_1';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_1']['table'] = 'field_data_field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_1']['field'] = 'field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_1']['label'] = 'Related link 1 URL';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_1']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_1']['delta_offset'] = '0';
  /* Field: Content: Related links */
  $handler->display->display_options['fields']['field_enrd_prj_related_link_2']['id'] = 'field_enrd_prj_related_link_2';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_2']['table'] = 'field_data_field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_2']['field'] = 'field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_2']['label'] = 'Related link 2 Title';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_2']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_2']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_2']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_2']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_2']['delta_offset'] = '1';
  /* Field: Content: Related links */
  $handler->display->display_options['fields']['field_enrd_prj_related_link_3']['id'] = 'field_enrd_prj_related_link_3';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_3']['table'] = 'field_data_field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_3']['field'] = 'field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_3']['label'] = 'Related link 2 URL';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_3']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_3']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_3']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_3']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_3']['delta_offset'] = '1';
  /* Field: Content: Related links */
  $handler->display->display_options['fields']['field_enrd_prj_related_link_4']['id'] = 'field_enrd_prj_related_link_4';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_4']['table'] = 'field_data_field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_4']['field'] = 'field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_4']['label'] = 'Related link 3 Title';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_4']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_4']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_4']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_4']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_4']['delta_offset'] = '2';
  /* Field: Content: Related links */
  $handler->display->display_options['fields']['field_enrd_prj_related_link_5']['id'] = 'field_enrd_prj_related_link_5';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_5']['table'] = 'field_data_field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_5']['field'] = 'field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_5']['label'] = 'Related link 3 URL';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_5']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_5']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_5']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_5']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_5']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_5']['delta_offset'] = '2';
  /* Field: Content: Related links */
  $handler->display->display_options['fields']['field_enrd_prj_related_link_6']['id'] = 'field_enrd_prj_related_link_6';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_6']['table'] = 'field_data_field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_6']['field'] = 'field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_6']['label'] = 'Related link 4 Title';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_6']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_6']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_6']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_6']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_6']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_6']['delta_offset'] = '3';
  /* Field: Content: Related links */
  $handler->display->display_options['fields']['field_enrd_prj_related_link_7']['id'] = 'field_enrd_prj_related_link_7';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_7']['table'] = 'field_data_field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_7']['field'] = 'field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_7']['label'] = 'Related link 4 URL';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_7']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_7']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_7']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_7']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_7']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_7']['delta_offset'] = '3';
  /* Field: Content: Related links */
  $handler->display->display_options['fields']['field_enrd_prj_related_link_8']['id'] = 'field_enrd_prj_related_link_8';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_8']['table'] = 'field_data_field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_8']['field'] = 'field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_8']['label'] = 'Related link 5 Title';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_8']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_8']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_8']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_8']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_8']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_8']['delta_offset'] = '4';
  /* Field: Content: Related links */
  $handler->display->display_options['fields']['field_enrd_prj_related_link_9']['id'] = 'field_enrd_prj_related_link_9';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_9']['table'] = 'field_data_field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_9']['field'] = 'field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_9']['label'] = 'Related link 5 URL';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_9']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_9']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_9']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_9']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_9']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_9']['delta_offset'] = '4';
  /* Field: Content: EU Budget MFF heading */
  $handler->display->display_options['fields']['field_enrd_prj_eu_budg_mff_head']['id'] = 'field_enrd_prj_eu_budg_mff_head';
  $handler->display->display_options['fields']['field_enrd_prj_eu_budg_mff_head']['table'] = 'field_data_field_enrd_prj_eu_budg_mff_head';
  $handler->display->display_options['fields']['field_enrd_prj_eu_budg_mff_head']['field'] = 'field_enrd_prj_eu_budg_mff_head';
  $handler->display->display_options['fields']['field_enrd_prj_eu_budg_mff_head']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_eu_budg_mff_head']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_eu_budg_mff_head']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: Programme name */
  $handler->display->display_options['fields']['field_enrd_prj_programme_name']['id'] = 'field_enrd_prj_programme_name';
  $handler->display->display_options['fields']['field_enrd_prj_programme_name']['table'] = 'field_data_field_enrd_prj_programme_name';
  $handler->display->display_options['fields']['field_enrd_prj_programme_name']['field'] = 'field_enrd_prj_programme_name';
  $handler->display->display_options['fields']['field_enrd_prj_programme_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_programme_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_programme_name']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_enrd_prj_programme_name']['delta_offset'] = '0';
  /* Field: Content: Funding area */
  $handler->display->display_options['fields']['field_enrd_prj_funding_area']['id'] = 'field_enrd_prj_funding_area';
  $handler->display->display_options['fields']['field_enrd_prj_funding_area']['table'] = 'field_data_field_enrd_prj_funding_area';
  $handler->display->display_options['fields']['field_enrd_prj_funding_area']['field'] = 'field_enrd_prj_funding_area';
  $handler->display->display_options['fields']['field_enrd_prj_funding_area']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_funding_area']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_funding_area']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: EC priorities */
  $handler->display->display_options['fields']['field_enrd_prj_ec_priorities']['id'] = 'field_enrd_prj_ec_priorities';
  $handler->display->display_options['fields']['field_enrd_prj_ec_priorities']['table'] = 'field_data_field_enrd_prj_ec_priorities';
  $handler->display->display_options['fields']['field_enrd_prj_ec_priorities']['field'] = 'field_enrd_prj_ec_priorities';
  $handler->display->display_options['fields']['field_enrd_prj_ec_priorities']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_ec_priorities']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: EU Budget contribution to the project */
  $handler->display->display_options['fields']['field_enrd_prj_eu_budget_contrib']['id'] = 'field_enrd_prj_eu_budget_contrib';
  $handler->display->display_options['fields']['field_enrd_prj_eu_budget_contrib']['table'] = 'field_data_field_enrd_prj_eu_budget_contrib';
  $handler->display->display_options['fields']['field_enrd_prj_eu_budget_contrib']['field'] = 'field_enrd_prj_eu_budget_contrib';
  $handler->display->display_options['fields']['field_enrd_prj_eu_budget_contrib']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_eu_budget_contrib']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_eu_budget_contrib']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Total project budget */
  $handler->display->display_options['fields']['field_enrd_prj_total_budget']['id'] = 'field_enrd_prj_total_budget';
  $handler->display->display_options['fields']['field_enrd_prj_total_budget']['table'] = 'field_data_field_enrd_prj_total_budget';
  $handler->display->display_options['fields']['field_enrd_prj_total_budget']['field'] = 'field_enrd_prj_total_budget';
  $handler->display->display_options['fields']['field_enrd_prj_total_budget']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_total_budget']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_total_budget']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_tax_country']['id'] = 'field_tax_country';
  $handler->display->display_options['fields']['field_tax_country']['table'] = 'field_data_field_tax_country';
  $handler->display->display_options['fields']['field_tax_country']['field'] = 'field_tax_country';
  $handler->display->display_options['fields']['field_tax_country']['type'] = 'ds_taxonomy_separator';
  $handler->display->display_options['fields']['field_tax_country']['delta_offset'] = '0';
  /* Field: Content: Beneficiary location address - Thoroughfare (i.e. Street address) */
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_thoroughfare']['id'] = 'field_enrd_prj_benef_loc_addr_thoroughfare';
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_thoroughfare']['table'] = 'field_data_field_enrd_prj_benef_loc_addr';
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_thoroughfare']['field'] = 'field_enrd_prj_benef_loc_addr_thoroughfare';
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_thoroughfare']['label'] = 'Beneficiary location address1';
  /* Field: Content: Beneficiary location address - Postal code */
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_postal_code']['id'] = 'field_enrd_prj_benef_loc_addr_postal_code';
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_postal_code']['table'] = 'field_data_field_enrd_prj_benef_loc_addr';
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_postal_code']['field'] = 'field_enrd_prj_benef_loc_addr_postal_code';
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_postal_code']['label'] = 'Beneficiary location postal code';
  /* Field: Content: Beneficiary location address - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_locality']['id'] = 'field_enrd_prj_benef_loc_addr_locality';
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_locality']['table'] = 'field_data_field_enrd_prj_benef_loc_addr';
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_locality']['field'] = 'field_enrd_prj_benef_loc_addr_locality';
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_locality']['label'] = 'Beneficiary location city';
  /* Field: Content: Beneficiary location address - Country */
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_country']['id'] = 'field_enrd_prj_benef_loc_addr_country';
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_country']['table'] = 'field_data_field_enrd_prj_benef_loc_addr';
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_country']['field'] = 'field_enrd_prj_benef_loc_addr_country';
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_country']['label'] = 'Beneficiary location country';
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_country']['display_name'] = 1;
  /* Field: Content: GPS coordinates beneficiary */
  $handler->display->display_options['fields']['field_enrd_prj_gps_coord_benef']['id'] = 'field_enrd_prj_gps_coord_benef';
  $handler->display->display_options['fields']['field_enrd_prj_gps_coord_benef']['table'] = 'field_data_field_enrd_prj_gps_coord_benef';
  $handler->display->display_options['fields']['field_enrd_prj_gps_coord_benef']['field'] = 'field_enrd_prj_gps_coord_benef';
  $handler->display->display_options['fields']['field_enrd_prj_gps_coord_benef']['label'] = 'Beneficiary location latitude';
  $handler->display->display_options['fields']['field_enrd_prj_gps_coord_benef']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_enrd_prj_gps_coord_benef']['type'] = 'geofield_lat';
  $handler->display->display_options['fields']['field_enrd_prj_gps_coord_benef']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
  );
  /* Field: Content: GPS coordinates beneficiary */
  $handler->display->display_options['fields']['field_enrd_prj_gps_coord_benef_1']['id'] = 'field_enrd_prj_gps_coord_benef_1';
  $handler->display->display_options['fields']['field_enrd_prj_gps_coord_benef_1']['table'] = 'field_data_field_enrd_prj_gps_coord_benef';
  $handler->display->display_options['fields']['field_enrd_prj_gps_coord_benef_1']['field'] = 'field_enrd_prj_gps_coord_benef';
  $handler->display->display_options['fields']['field_enrd_prj_gps_coord_benef_1']['label'] = 'Beneficiary location longitude';
  $handler->display->display_options['fields']['field_enrd_prj_gps_coord_benef_1']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_enrd_prj_gps_coord_benef_1']['type'] = 'geofield_lon';
  $handler->display->display_options['fields']['field_enrd_prj_gps_coord_benef_1']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
  );
  $handler->display->display_options['path'] = 'admin/enrd/projects/enrd_projects_export.csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Data export: Projects Export xslx */
  $handler = $view->new_display('views_data_export', 'Data export: Projects Export xslx', 'views_data_export_projects_xslx');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xlsx';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Programming period */
  $handler->display->display_options['fields']['field_enrd_prj_program_period']['id'] = 'field_enrd_prj_program_period';
  $handler->display->display_options['fields']['field_enrd_prj_program_period']['table'] = 'field_data_field_enrd_prj_program_period';
  $handler->display->display_options['fields']['field_enrd_prj_program_period']['field'] = 'field_enrd_prj_program_period';
  /* Field: Content: Rural Development Policy */
  $handler->display->display_options['fields']['field_tax_rural_dev_policy']['id'] = 'field_tax_rural_dev_policy';
  $handler->display->display_options['fields']['field_tax_rural_dev_policy']['table'] = 'field_data_field_tax_rural_dev_policy';
  $handler->display->display_options['fields']['field_tax_rural_dev_policy']['field'] = 'field_tax_rural_dev_policy';
  $handler->display->display_options['fields']['field_tax_rural_dev_policy']['label'] = 'Priority';
  $handler->display->display_options['fields']['field_tax_rural_dev_policy']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tax_rural_dev_policy']['delta_offset'] = '0';
  /* Field: Content: Focus Area */
  $handler->display->display_options['fields']['field_enrd_prj_focus_area']['id'] = 'field_enrd_prj_focus_area';
  $handler->display->display_options['fields']['field_enrd_prj_focus_area']['table'] = 'field_data_field_enrd_prj_focus_area';
  $handler->display->display_options['fields']['field_enrd_prj_focus_area']['field'] = 'field_enrd_prj_focus_area';
  $handler->display->display_options['fields']['field_enrd_prj_focus_area']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: Measure */
  $handler->display->display_options['fields']['field_enrd_prj_measure']['id'] = 'field_enrd_prj_measure';
  $handler->display->display_options['fields']['field_enrd_prj_measure']['table'] = 'field_data_field_enrd_prj_measure';
  $handler->display->display_options['fields']['field_enrd_prj_measure']['field'] = 'field_enrd_prj_measure';
  $handler->display->display_options['fields']['field_enrd_prj_measure']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: Project acronym */
  $handler->display->display_options['fields']['field_enrd_prj_acronym']['id'] = 'field_enrd_prj_acronym';
  $handler->display->display_options['fields']['field_enrd_prj_acronym']['table'] = 'field_data_field_enrd_prj_acronym';
  $handler->display->display_options['fields']['field_enrd_prj_acronym']['field'] = 'field_enrd_prj_acronym';
  $handler->display->display_options['fields']['field_enrd_prj_acronym']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_acronym']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_acronym']['type'] = 'text_plain';
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_enrd_prj_thumbnail']['id'] = 'field_enrd_prj_thumbnail';
  $handler->display->display_options['fields']['field_enrd_prj_thumbnail']['table'] = 'field_data_field_enrd_prj_thumbnail';
  $handler->display->display_options['fields']['field_enrd_prj_thumbnail']['field'] = 'field_enrd_prj_thumbnail';
  $handler->display->display_options['fields']['field_enrd_prj_thumbnail']['label'] = 'Visual';
  $handler->display->display_options['fields']['field_enrd_prj_thumbnail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_prj_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_thumbnail']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_enrd_prj_thumbnail']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Project summary */
  $handler->display->display_options['fields']['field_enrd_prj_full_proj_summary']['id'] = 'field_enrd_prj_full_proj_summary';
  $handler->display->display_options['fields']['field_enrd_prj_full_proj_summary']['table'] = 'field_data_field_enrd_prj_full_proj_summary';
  $handler->display->display_options['fields']['field_enrd_prj_full_proj_summary']['field'] = 'field_enrd_prj_full_proj_summary';
  $handler->display->display_options['fields']['field_enrd_prj_full_proj_summary']['label'] = 'Project description';
  $handler->display->display_options['fields']['field_enrd_prj_full_proj_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_full_proj_summary']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_full_proj_summary']['type'] = 'text_plain';
  /* Field: Content: Project results */
  $handler->display->display_options['fields']['field_enrd_prj_results']['id'] = 'field_enrd_prj_results';
  $handler->display->display_options['fields']['field_enrd_prj_results']['table'] = 'field_data_field_enrd_prj_results';
  $handler->display->display_options['fields']['field_enrd_prj_results']['field'] = 'field_enrd_prj_results';
  $handler->display->display_options['fields']['field_enrd_prj_results']['label'] = 'Project Results';
  $handler->display->display_options['fields']['field_enrd_prj_results']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_results']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_results']['type'] = 'text_plain';
  /* Field: Content: Project promoter */
  $handler->display->display_options['fields']['field_enrd_prj_promoter']['id'] = 'field_enrd_prj_promoter';
  $handler->display->display_options['fields']['field_enrd_prj_promoter']['table'] = 'field_data_field_enrd_prj_promoter';
  $handler->display->display_options['fields']['field_enrd_prj_promoter']['field'] = 'field_enrd_prj_promoter';
  $handler->display->display_options['fields']['field_enrd_prj_promoter']['label'] = 'Coordinating organisation';
  $handler->display->display_options['fields']['field_enrd_prj_promoter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_promoter']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_promoter']['type'] = 'text_plain';
  /* Field: Content: Project partners */
  $handler->display->display_options['fields']['field_enrd_prj_partners']['id'] = 'field_enrd_prj_partners';
  $handler->display->display_options['fields']['field_enrd_prj_partners']['table'] = 'field_data_field_enrd_prj_partners';
  $handler->display->display_options['fields']['field_enrd_prj_partners']['field'] = 'field_enrd_prj_partners';
  $handler->display->display_options['fields']['field_enrd_prj_partners']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_partners']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_partners']['type'] = 'text_plain';
  /* Field: Content: Project Location - Thoroughfare (i.e. Street address) */
  $handler->display->display_options['fields']['field_enrd_prj_location_thoroughfare']['id'] = 'field_enrd_prj_location_thoroughfare';
  $handler->display->display_options['fields']['field_enrd_prj_location_thoroughfare']['table'] = 'field_data_field_enrd_prj_location';
  $handler->display->display_options['fields']['field_enrd_prj_location_thoroughfare']['field'] = 'field_enrd_prj_location_thoroughfare';
  $handler->display->display_options['fields']['field_enrd_prj_location_thoroughfare']['label'] = 'Project address(es)';
  $handler->display->display_options['fields']['field_enrd_prj_location_thoroughfare']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_location_thoroughfare']['element_default_classes'] = FALSE;
  /* Field: Content: Project Location - Postal code */
  $handler->display->display_options['fields']['field_enrd_prj_location_postal_code']['id'] = 'field_enrd_prj_location_postal_code';
  $handler->display->display_options['fields']['field_enrd_prj_location_postal_code']['table'] = 'field_data_field_enrd_prj_location';
  $handler->display->display_options['fields']['field_enrd_prj_location_postal_code']['field'] = 'field_enrd_prj_location_postal_code';
  $handler->display->display_options['fields']['field_enrd_prj_location_postal_code']['label'] = 'Project postal code(s)';
  $handler->display->display_options['fields']['field_enrd_prj_location_postal_code']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_location_postal_code']['element_default_classes'] = FALSE;
  /* Field: Content: Project Location - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_enrd_prj_location_locality']['id'] = 'field_enrd_prj_location_locality';
  $handler->display->display_options['fields']['field_enrd_prj_location_locality']['table'] = 'field_data_field_enrd_prj_location';
  $handler->display->display_options['fields']['field_enrd_prj_location_locality']['field'] = 'field_enrd_prj_location_locality';
  $handler->display->display_options['fields']['field_enrd_prj_location_locality']['label'] = 'Project town(s)';
  $handler->display->display_options['fields']['field_enrd_prj_location_locality']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_location_locality']['element_default_classes'] = FALSE;
  /* Field: Content: Project Location - Country */
  $handler->display->display_options['fields']['field_enrd_prj_location_country']['id'] = 'field_enrd_prj_location_country';
  $handler->display->display_options['fields']['field_enrd_prj_location_country']['table'] = 'field_data_field_enrd_prj_location';
  $handler->display->display_options['fields']['field_enrd_prj_location_country']['field'] = 'field_enrd_prj_location_country';
  $handler->display->display_options['fields']['field_enrd_prj_location_country']['label'] = 'Project country(ies)';
  $handler->display->display_options['fields']['field_enrd_prj_location_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_location_country']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_location_country']['display_name'] = 1;
  /* Field: Content: Project lat/long */
  $handler->display->display_options['fields']['field_enrd_prj_lat_long']['id'] = 'field_enrd_prj_lat_long';
  $handler->display->display_options['fields']['field_enrd_prj_lat_long']['table'] = 'field_data_field_enrd_prj_lat_long';
  $handler->display->display_options['fields']['field_enrd_prj_lat_long']['field'] = 'field_enrd_prj_lat_long';
  $handler->display->display_options['fields']['field_enrd_prj_lat_long']['label'] = 'Project latitude(s)';
  $handler->display->display_options['fields']['field_enrd_prj_lat_long']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_lat_long']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_lat_long']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_enrd_prj_lat_long']['type'] = 'geofield_lat';
  $handler->display->display_options['fields']['field_enrd_prj_lat_long']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
  );
  /* Field: Content: Project lat/long */
  $handler->display->display_options['fields']['field_enrd_prj_lat_long_1']['id'] = 'field_enrd_prj_lat_long_1';
  $handler->display->display_options['fields']['field_enrd_prj_lat_long_1']['table'] = 'field_data_field_enrd_prj_lat_long';
  $handler->display->display_options['fields']['field_enrd_prj_lat_long_1']['field'] = 'field_enrd_prj_lat_long';
  $handler->display->display_options['fields']['field_enrd_prj_lat_long_1']['label'] = 'Project longitude(s)';
  $handler->display->display_options['fields']['field_enrd_prj_lat_long_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_lat_long_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_lat_long_1']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_enrd_prj_lat_long_1']['type'] = 'geofield_lon';
  $handler->display->display_options['fields']['field_enrd_prj_lat_long_1']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
  );
  /* Field: Content: Timeframe */
  $handler->display->display_options['fields']['field_enrd_prj_timeframe']['id'] = 'field_enrd_prj_timeframe';
  $handler->display->display_options['fields']['field_enrd_prj_timeframe']['table'] = 'field_data_field_enrd_prj_timeframe';
  $handler->display->display_options['fields']['field_enrd_prj_timeframe']['field'] = 'field_enrd_prj_timeframe';
  $handler->display->display_options['fields']['field_enrd_prj_timeframe']['label'] = 'Project Timeframe start year';
  $handler->display->display_options['fields']['field_enrd_prj_timeframe']['alter']['text'] = '[field_enrd_prj_timeframe-value]';
  $handler->display->display_options['fields']['field_enrd_prj_timeframe']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_prj_timeframe']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_timeframe']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_timeframe']['settings'] = array(
    'format_type' => 'enrd_project_data_export',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Timeframe */
  $handler->display->display_options['fields']['field_enrd_prj_timeframe_1']['id'] = 'field_enrd_prj_timeframe_1';
  $handler->display->display_options['fields']['field_enrd_prj_timeframe_1']['table'] = 'field_data_field_enrd_prj_timeframe';
  $handler->display->display_options['fields']['field_enrd_prj_timeframe_1']['field'] = 'field_enrd_prj_timeframe';
  $handler->display->display_options['fields']['field_enrd_prj_timeframe_1']['label'] = 'Project Timeframe end year';
  $handler->display->display_options['fields']['field_enrd_prj_timeframe_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_prj_timeframe_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_timeframe_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_timeframe_1']['settings'] = array(
    'format_type' => 'enrd_project_data_export',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_enrd_prj_website']['id'] = 'field_enrd_prj_website';
  $handler->display->display_options['fields']['field_enrd_prj_website']['table'] = 'field_data_field_enrd_prj_website';
  $handler->display->display_options['fields']['field_enrd_prj_website']['field'] = 'field_enrd_prj_website';
  $handler->display->display_options['fields']['field_enrd_prj_website']['label'] = 'Project webpage';
  $handler->display->display_options['fields']['field_enrd_prj_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_website']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_enrd_prj_website']['type'] = 'link_title_plain';
  /* Field: Content: Related links */
  $handler->display->display_options['fields']['field_enrd_prj_related_link']['id'] = 'field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link']['table'] = 'field_data_field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link']['field'] = 'field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link']['label'] = 'Related link 1 Title';
  $handler->display->display_options['fields']['field_enrd_prj_related_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_enrd_prj_related_link']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_enrd_prj_related_link']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_enrd_prj_related_link']['delta_offset'] = '0';
  /* Field: Content: Related links */
  $handler->display->display_options['fields']['field_enrd_prj_related_link_1']['id'] = 'field_enrd_prj_related_link_1';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_1']['table'] = 'field_data_field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_1']['field'] = 'field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_1']['label'] = 'Related link 1 URL';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_1']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_1']['delta_offset'] = '0';
  /* Field: Content: Related links */
  $handler->display->display_options['fields']['field_enrd_prj_related_link_2']['id'] = 'field_enrd_prj_related_link_2';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_2']['table'] = 'field_data_field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_2']['field'] = 'field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_2']['label'] = 'Related link 2 Title';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_2']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_2']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_2']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_2']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_2']['delta_offset'] = '1';
  /* Field: Content: Related links */
  $handler->display->display_options['fields']['field_enrd_prj_related_link_3']['id'] = 'field_enrd_prj_related_link_3';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_3']['table'] = 'field_data_field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_3']['field'] = 'field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_3']['label'] = 'Related link 2 URL';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_3']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_3']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_3']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_3']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_3']['delta_offset'] = '1';
  /* Field: Content: Related links */
  $handler->display->display_options['fields']['field_enrd_prj_related_link_4']['id'] = 'field_enrd_prj_related_link_4';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_4']['table'] = 'field_data_field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_4']['field'] = 'field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_4']['label'] = 'Related link 3 Title';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_4']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_4']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_4']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_4']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_4']['delta_offset'] = '2';
  /* Field: Content: Related links */
  $handler->display->display_options['fields']['field_enrd_prj_related_link_5']['id'] = 'field_enrd_prj_related_link_5';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_5']['table'] = 'field_data_field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_5']['field'] = 'field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_5']['label'] = 'Related link 3 URL';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_5']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_5']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_5']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_5']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_5']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_5']['delta_offset'] = '2';
  /* Field: Content: Related links */
  $handler->display->display_options['fields']['field_enrd_prj_related_link_6']['id'] = 'field_enrd_prj_related_link_6';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_6']['table'] = 'field_data_field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_6']['field'] = 'field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_6']['label'] = 'Related link 4 Title';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_6']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_6']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_6']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_6']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_6']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_6']['delta_offset'] = '3';
  /* Field: Content: Related links */
  $handler->display->display_options['fields']['field_enrd_prj_related_link_7']['id'] = 'field_enrd_prj_related_link_7';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_7']['table'] = 'field_data_field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_7']['field'] = 'field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_7']['label'] = 'Related link 4 URL';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_7']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_7']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_7']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_7']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_7']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_7']['delta_offset'] = '3';
  /* Field: Content: Related links */
  $handler->display->display_options['fields']['field_enrd_prj_related_link_8']['id'] = 'field_enrd_prj_related_link_8';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_8']['table'] = 'field_data_field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_8']['field'] = 'field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_8']['label'] = 'Related link 5 Title';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_8']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_8']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_8']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_8']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_8']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_8']['delta_offset'] = '4';
  /* Field: Content: Related links */
  $handler->display->display_options['fields']['field_enrd_prj_related_link_9']['id'] = 'field_enrd_prj_related_link_9';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_9']['table'] = 'field_data_field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_9']['field'] = 'field_enrd_prj_related_link';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_9']['label'] = 'Related link 5 URL';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_9']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_9']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_related_link_9']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_9']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_9']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_enrd_prj_related_link_9']['delta_offset'] = '4';
  /* Field: Content: EU Budget MFF heading */
  $handler->display->display_options['fields']['field_enrd_prj_eu_budg_mff_head']['id'] = 'field_enrd_prj_eu_budg_mff_head';
  $handler->display->display_options['fields']['field_enrd_prj_eu_budg_mff_head']['table'] = 'field_data_field_enrd_prj_eu_budg_mff_head';
  $handler->display->display_options['fields']['field_enrd_prj_eu_budg_mff_head']['field'] = 'field_enrd_prj_eu_budg_mff_head';
  $handler->display->display_options['fields']['field_enrd_prj_eu_budg_mff_head']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_eu_budg_mff_head']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_eu_budg_mff_head']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: Programme name */
  $handler->display->display_options['fields']['field_enrd_prj_programme_name']['id'] = 'field_enrd_prj_programme_name';
  $handler->display->display_options['fields']['field_enrd_prj_programme_name']['table'] = 'field_data_field_enrd_prj_programme_name';
  $handler->display->display_options['fields']['field_enrd_prj_programme_name']['field'] = 'field_enrd_prj_programme_name';
  $handler->display->display_options['fields']['field_enrd_prj_programme_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_programme_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_programme_name']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_enrd_prj_programme_name']['delta_offset'] = '0';
  /* Field: Content: Funding area */
  $handler->display->display_options['fields']['field_enrd_prj_funding_area']['id'] = 'field_enrd_prj_funding_area';
  $handler->display->display_options['fields']['field_enrd_prj_funding_area']['table'] = 'field_data_field_enrd_prj_funding_area';
  $handler->display->display_options['fields']['field_enrd_prj_funding_area']['field'] = 'field_enrd_prj_funding_area';
  $handler->display->display_options['fields']['field_enrd_prj_funding_area']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_funding_area']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_funding_area']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: EC priorities */
  $handler->display->display_options['fields']['field_enrd_prj_ec_priorities']['id'] = 'field_enrd_prj_ec_priorities';
  $handler->display->display_options['fields']['field_enrd_prj_ec_priorities']['table'] = 'field_data_field_enrd_prj_ec_priorities';
  $handler->display->display_options['fields']['field_enrd_prj_ec_priorities']['field'] = 'field_enrd_prj_ec_priorities';
  $handler->display->display_options['fields']['field_enrd_prj_ec_priorities']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_ec_priorities']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: EU Budget contribution to the project */
  $handler->display->display_options['fields']['field_enrd_prj_eu_budget_contrib']['id'] = 'field_enrd_prj_eu_budget_contrib';
  $handler->display->display_options['fields']['field_enrd_prj_eu_budget_contrib']['table'] = 'field_data_field_enrd_prj_eu_budget_contrib';
  $handler->display->display_options['fields']['field_enrd_prj_eu_budget_contrib']['field'] = 'field_enrd_prj_eu_budget_contrib';
  $handler->display->display_options['fields']['field_enrd_prj_eu_budget_contrib']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_eu_budget_contrib']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_eu_budget_contrib']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Total project budget */
  $handler->display->display_options['fields']['field_enrd_prj_total_budget']['id'] = 'field_enrd_prj_total_budget';
  $handler->display->display_options['fields']['field_enrd_prj_total_budget']['table'] = 'field_data_field_enrd_prj_total_budget';
  $handler->display->display_options['fields']['field_enrd_prj_total_budget']['field'] = 'field_enrd_prj_total_budget';
  $handler->display->display_options['fields']['field_enrd_prj_total_budget']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_total_budget']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_total_budget']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_tax_country']['id'] = 'field_tax_country';
  $handler->display->display_options['fields']['field_tax_country']['table'] = 'field_data_field_tax_country';
  $handler->display->display_options['fields']['field_tax_country']['field'] = 'field_tax_country';
  $handler->display->display_options['fields']['field_tax_country']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tax_country']['delta_offset'] = '0';
  /* Field: Content: Beneficiary location address - Thoroughfare (i.e. Street address) */
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_thoroughfare']['id'] = 'field_enrd_prj_benef_loc_addr_thoroughfare';
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_thoroughfare']['table'] = 'field_data_field_enrd_prj_benef_loc_addr';
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_thoroughfare']['field'] = 'field_enrd_prj_benef_loc_addr_thoroughfare';
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_thoroughfare']['label'] = 'Beneficiary location address1';
  /* Field: Content: Beneficiary location address - Postal code */
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_postal_code']['id'] = 'field_enrd_prj_benef_loc_addr_postal_code';
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_postal_code']['table'] = 'field_data_field_enrd_prj_benef_loc_addr';
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_postal_code']['field'] = 'field_enrd_prj_benef_loc_addr_postal_code';
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_postal_code']['label'] = 'Beneficiary location postal code';
  /* Field: Content: Beneficiary location address - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_locality']['id'] = 'field_enrd_prj_benef_loc_addr_locality';
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_locality']['table'] = 'field_data_field_enrd_prj_benef_loc_addr';
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_locality']['field'] = 'field_enrd_prj_benef_loc_addr_locality';
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_locality']['label'] = 'Beneficiary location city';
  /* Field: Content: Beneficiary location address - Country */
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_country']['id'] = 'field_enrd_prj_benef_loc_addr_country';
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_country']['table'] = 'field_data_field_enrd_prj_benef_loc_addr';
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_country']['field'] = 'field_enrd_prj_benef_loc_addr_country';
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_country']['label'] = 'Beneficiary location country';
  $handler->display->display_options['fields']['field_enrd_prj_benef_loc_addr_country']['display_name'] = 1;
  /* Field: Content: GPS coordinates beneficiary */
  $handler->display->display_options['fields']['field_enrd_prj_gps_coord_benef']['id'] = 'field_enrd_prj_gps_coord_benef';
  $handler->display->display_options['fields']['field_enrd_prj_gps_coord_benef']['table'] = 'field_data_field_enrd_prj_gps_coord_benef';
  $handler->display->display_options['fields']['field_enrd_prj_gps_coord_benef']['field'] = 'field_enrd_prj_gps_coord_benef';
  $handler->display->display_options['fields']['field_enrd_prj_gps_coord_benef']['label'] = 'Beneficiary location latitude';
  $handler->display->display_options['fields']['field_enrd_prj_gps_coord_benef']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_enrd_prj_gps_coord_benef']['type'] = 'geofield_lat';
  $handler->display->display_options['fields']['field_enrd_prj_gps_coord_benef']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
  );
  /* Field: Content: GPS coordinates beneficiary */
  $handler->display->display_options['fields']['field_enrd_prj_gps_coord_benef_1']['id'] = 'field_enrd_prj_gps_coord_benef_1';
  $handler->display->display_options['fields']['field_enrd_prj_gps_coord_benef_1']['table'] = 'field_data_field_enrd_prj_gps_coord_benef';
  $handler->display->display_options['fields']['field_enrd_prj_gps_coord_benef_1']['field'] = 'field_enrd_prj_gps_coord_benef';
  $handler->display->display_options['fields']['field_enrd_prj_gps_coord_benef_1']['label'] = 'Beneficiary location longitude';
  $handler->display->display_options['fields']['field_enrd_prj_gps_coord_benef_1']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_enrd_prj_gps_coord_benef_1']['type'] = 'geofield_lon';
  $handler->display->display_options['fields']['field_enrd_prj_gps_coord_benef_1']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
  );
  $handler->display->display_options['path'] = 'admin/enrd/projects/enrd_projects_export.xslx';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['segment_size'] = '50';
  $export['enrd_projects_export'] = $view;

  $view = new view();
  $view->name = 'enrd_projects_list';
  $view->description = 'Generated RSS Feed based on the latest published projects.';
  $view->tag = 'ENRD';
  $view->base_table = 'node';
  $view->human_name = 'ENRD Projects RSS Feed';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Projects & Practice';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 1,
      'secondary_label' => 'Advanced search',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'combine' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'term_node_tid_depth_i18n' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_select_all_none_nested' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'field_enrd_prj_keywords_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_select_all_none_nested' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'field_enrd_prj_measure_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_select_all_none_nested' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 1,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'field_enrd_prj_focus_area_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_select_all_none_nested' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 1,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '5';
  $handler->display->display_options['pager']['options']['tags']['first'] = '«';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹';
  $handler->display->display_options['pager']['options']['tags']['next'] = '›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '»';
  $handler->display->display_options['style_plugin'] = 'enrd_mastermind_media_plugin_style';
  $handler->display->display_options['style_options']['row_class'] = 'img-250 metadata-before';
  $handler->display->display_options['row_plugin'] = 'enrd_mastermind_media_plugin_rows';
  $handler->display->display_options['row_options']['image_field'] = 'field_enrd_prj_thumbnail';
  $handler->display->display_options['row_options']['heading_field'] = 'title_field';
  $handler->display->display_options['row_options']['abstract_field'] = 'field_enrd_prj_headline';
  $handler->display->display_options['row_options']['metadata_field'] = array(
    'field_enrd_prj_keywords' => 'field_enrd_prj_keywords',
    'field_tax_country' => 'field_tax_country',
    'title_field' => 0,
    'field_enrd_prj_full_proj_summary' => 0,
    'field_enrd_prj_results' => 0,
    'field_enrd_prj_headline' => 0,
    'field_enrd_prj_thumbnail' => 0,
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No projects available to display.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_type'] = '0';
  $handler->display->display_options['fields']['title_field']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title_field']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: Content: Keywords */
  $handler->display->display_options['fields']['field_enrd_prj_keywords']['id'] = 'field_enrd_prj_keywords';
  $handler->display->display_options['fields']['field_enrd_prj_keywords']['table'] = 'field_data_field_enrd_prj_keywords';
  $handler->display->display_options['fields']['field_enrd_prj_keywords']['field'] = 'field_enrd_prj_keywords';
  $handler->display->display_options['fields']['field_enrd_prj_keywords']['element_type'] = '0';
  $handler->display->display_options['fields']['field_enrd_prj_keywords']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_enrd_prj_keywords']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_enrd_prj_keywords']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_enrd_prj_keywords']['delta_limit'] = '4';
  $handler->display->display_options['fields']['field_enrd_prj_keywords']['delta_offset'] = '0';
  /* Field: Content: Project summary */
  $handler->display->display_options['fields']['field_enrd_prj_full_proj_summary']['id'] = 'field_enrd_prj_full_proj_summary';
  $handler->display->display_options['fields']['field_enrd_prj_full_proj_summary']['table'] = 'field_data_field_enrd_prj_full_proj_summary';
  $handler->display->display_options['fields']['field_enrd_prj_full_proj_summary']['field'] = 'field_enrd_prj_full_proj_summary';
  $handler->display->display_options['fields']['field_enrd_prj_full_proj_summary']['label'] = '';
  $handler->display->display_options['fields']['field_enrd_prj_full_proj_summary']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_prj_full_proj_summary']['element_label_colon'] = FALSE;
  /* Field: Content: Project results */
  $handler->display->display_options['fields']['field_enrd_prj_results']['id'] = 'field_enrd_prj_results';
  $handler->display->display_options['fields']['field_enrd_prj_results']['table'] = 'field_data_field_enrd_prj_results';
  $handler->display->display_options['fields']['field_enrd_prj_results']['field'] = 'field_enrd_prj_results';
  $handler->display->display_options['fields']['field_enrd_prj_results']['label'] = '';
  $handler->display->display_options['fields']['field_enrd_prj_results']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_prj_results']['element_label_colon'] = FALSE;
  /* Field: Content: Headline */
  $handler->display->display_options['fields']['field_enrd_prj_headline']['id'] = 'field_enrd_prj_headline';
  $handler->display->display_options['fields']['field_enrd_prj_headline']['table'] = 'field_data_field_enrd_prj_headline';
  $handler->display->display_options['fields']['field_enrd_prj_headline']['field'] = 'field_enrd_prj_headline';
  $handler->display->display_options['fields']['field_enrd_prj_headline']['label'] = '';
  $handler->display->display_options['fields']['field_enrd_prj_headline']['alter']['text'] = '[field_enrd_prj_headline]<br />
[field_enrd_prj_keywords]';
  $handler->display->display_options['fields']['field_enrd_prj_headline']['alter']['max_length'] = '600';
  $handler->display->display_options['fields']['field_enrd_prj_headline']['element_label_colon'] = FALSE;
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_tax_country']['id'] = 'field_tax_country';
  $handler->display->display_options['fields']['field_tax_country']['table'] = 'field_data_field_tax_country';
  $handler->display->display_options['fields']['field_tax_country']['field'] = 'field_tax_country';
  $handler->display->display_options['fields']['field_tax_country']['label'] = 'Countries';
  $handler->display->display_options['fields']['field_tax_country']['element_type'] = '0';
  $handler->display->display_options['fields']['field_tax_country']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_tax_country']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_tax_country']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tax_country']['delta_offset'] = '0';
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_enrd_prj_thumbnail']['id'] = 'field_enrd_prj_thumbnail';
  $handler->display->display_options['fields']['field_enrd_prj_thumbnail']['table'] = 'field_data_field_enrd_prj_thumbnail';
  $handler->display->display_options['fields']['field_enrd_prj_thumbnail']['field'] = 'field_enrd_prj_thumbnail';
  $handler->display->display_options['fields']['field_enrd_prj_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_enrd_prj_thumbnail']['element_type'] = '0';
  $handler->display->display_options['fields']['field_enrd_prj_thumbnail']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_enrd_prj_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_thumbnail']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_enrd_prj_thumbnail']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_prj_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_enrd_prj_thumbnail']['settings'] = array(
    'image_style' => 'project_images',
    'image_link' => '',
  );
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
    'project' => 'project',
  );

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_projects');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'ENRD Projects and Practice';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['style_options']['description'] = 'Latest updates about ENRD Projects';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'rss/projects-practice';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $export['enrd_projects_list'] = $view;

  return $export;
}
