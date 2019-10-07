<?php

/**
 * @file
 * agri_projects.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function agri_projects_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'agri_digitization_toolbox_projects_indexed_search';
  $view->description = 'Projects flagged by Digitisation.';
  $view->tag = 'AGRI Digitisation Toolbox ';
  $view->base_table = 'search_api_index_core_node_index';
  $view->human_name = 'AGRI Digitisation Toolbox Projects list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Projects';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'created' => 'created',
    'title' => 'title',
    'type' => 'type',
    'field_proj_project_type' => 'field_proj_project_type',
    'view_node' => 'view_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
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
    'field_proj_project_type' => array(
      'sortable' => 1,
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
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  /* Field: Indexed Content: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Published on';
  $handler->display->display_options['fields']['created']['date_format'] = 'eip_agri_medium';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'eip_agri_long';
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Sort criterion: Indexed Content: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'innovative_action' => 'innovative_action',
    'operational_group' => 'operational_group',
    'project' => 'project',
    'research_project' => 'research_project',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_core_node_index';
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
  /* Filter criterion: Indexed Content: Keywords */
  $handler->display->display_options['filters']['field_core_keywords']['id'] = 'field_core_keywords';
  $handler->display->display_options['filters']['field_core_keywords']['table'] = 'search_api_index_core_node_index';
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
    10 => 0,
    8 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
  );
  /* Filter criterion: Indexed Content: Main funding source */
  $handler->display->display_options['filters']['field_proj_funding_source_list']['id'] = 'field_proj_funding_source_list';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['field'] = 'field_proj_funding_source_list';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['value'] = array();
  $handler->display->display_options['filters']['field_proj_funding_source_list']['group'] = 1;
  $handler->display->display_options['filters']['field_proj_funding_source_list']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_proj_funding_source_list']['expose']['operator_id'] = 'field_proj_funding_source_list_op';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['expose']['label'] = 'Main funding source';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['expose']['operator'] = 'field_proj_funding_source_list_op';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['expose']['identifier'] = 'field_proj_funding_source_list';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Indexed Content: Geographical location */
  $handler->display->display_options['filters']['field_proj_geographical_area']['id'] = 'field_proj_geographical_area';
  $handler->display->display_options['filters']['field_proj_geographical_area']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_proj_geographical_area']['field'] = 'field_proj_geographical_area';
  $handler->display->display_options['filters']['field_proj_geographical_area']['value'] = array();
  $handler->display->display_options['filters']['field_proj_geographical_area']['group'] = 1;
  $handler->display->display_options['filters']['field_proj_geographical_area']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['operator_id'] = 'field_proj_geographical_area_op';
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['label'] = 'Geographical location';
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['operator'] = 'field_proj_geographical_area_op';
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['identifier'] = 'field_proj_geographical_area';
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Indexed Content: Agricultural sectors */
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['id'] = 'field_core_agricultural_sectors';
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['field'] = 'field_core_agricultural_sectors';
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['value'] = array();
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['group'] = 1;
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['expose']['operator_id'] = 'field_core_agricultural_sectors_op';
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['expose']['label'] = 'Agricultural sectors';
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['expose']['operator'] = 'field_core_agricultural_sectors_op';
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['expose']['identifier'] = 'field_core_agricultural_sectors';
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Indexed Content: Language */
  $handler->display->display_options['filters']['field_projects_language']['id'] = 'field_projects_language';
  $handler->display->display_options['filters']['field_projects_language']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_projects_language']['field'] = 'field_projects_language';
  $handler->display->display_options['filters']['field_projects_language']['value'] = array();
  $handler->display->display_options['filters']['field_projects_language']['group'] = 1;
  $handler->display->display_options['filters']['field_projects_language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_projects_language']['expose']['operator_id'] = 'field_projects_language_op';
  $handler->display->display_options['filters']['field_projects_language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['field_projects_language']['expose']['operator'] = 'field_projects_language_op';
  $handler->display->display_options['filters']['field_projects_language']['expose']['identifier'] = 'field_projects_language';
  $handler->display->display_options['filters']['field_projects_language']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_projects_language']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Indexed Content: Whether the entity is flagged with flag agri_digitization_toolbox */
  $handler->display->display_options['filters']['flag_agri_digitization_toolbox']['id'] = 'flag_agri_digitization_toolbox';
  $handler->display->display_options['filters']['flag_agri_digitization_toolbox']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['flag_agri_digitization_toolbox']['field'] = 'flag_agri_digitization_toolbox';
  $handler->display->display_options['filters']['flag_agri_digitization_toolbox']['value'] = '1';
  /* Filter criterion: Indexed Content: Partners categories */
  $handler->display->display_options['filters']['field_proj_partners_categories']['id'] = 'field_proj_partners_categories';
  $handler->display->display_options['filters']['field_proj_partners_categories']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_proj_partners_categories']['field'] = 'field_proj_partners_categories';
  $handler->display->display_options['filters']['field_proj_partners_categories']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_proj_partners_categories']['expose']['operator_id'] = 'field_proj_partners_categories_op';
  $handler->display->display_options['filters']['field_proj_partners_categories']['expose']['label'] = 'Partners categories';
  $handler->display->display_options['filters']['field_proj_partners_categories']['expose']['operator'] = 'field_proj_partners_categories_op';
  $handler->display->display_options['filters']['field_proj_partners_categories']['expose']['identifier'] = 'field_proj_partners_categories';

  /* Display: Digitization - Projects list */
  $handler = $view->new_display('page', 'Digitization - Projects list', 'projects_list');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Digitising Agriculture Projects';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'created' => 'created',
    'field_proj_title' => 'field_proj_title',
    'type' => 'type',
    'field_proj_geographical_area' => 'field_proj_geographical_area',
    'field_proj_project_type' => 'field_proj_project_type',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_proj_title' => array(
      'sortable' => 1,
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
    'field_proj_geographical_area' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_proj_project_type' => array(
      'sortable' => 1,
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
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No Digitisation Projects available.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Content: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Published on';
  $handler->display->display_options['fields']['created']['date_format'] = 'eip_agri_short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'eip_agri_long';
  $handler->display->display_options['fields']['created']['link_to_entity'] = 0;
  /* Field: Indexed Content: Project title */
  $handler->display->display_options['fields']['field_proj_title']['id'] = 'field_proj_title';
  $handler->display->display_options['fields']['field_proj_title']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_title']['field'] = 'field_proj_title';
  $handler->display->display_options['fields']['field_proj_title']['label'] = 'Title';
  $handler->display->display_options['fields']['field_proj_title']['link_to_entity'] = 1;
  /* Field: Indexed Content: Content type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['format_name'] = 1;
  /* Field: Indexed Content: Geographical location */
  $handler->display->display_options['fields']['field_proj_geographical_area']['id'] = 'field_proj_geographical_area';
  $handler->display->display_options['fields']['field_proj_geographical_area']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_geographical_area']['field'] = 'field_proj_geographical_area';
  $handler->display->display_options['fields']['field_proj_geographical_area']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_proj_geographical_area']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_proj_geographical_area']['bypass_access'] = 0;
  /* Field: Indexed Content: Project type */
  $handler->display->display_options['fields']['field_proj_project_type']['id'] = 'field_proj_project_type';
  $handler->display->display_options['fields']['field_proj_project_type']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_project_type']['field'] = 'field_proj_project_type';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'innovative_action' => 'innovative_action',
    'operational_group' => 'operational_group',
    'project' => 'project',
    'research_project' => 'research_project',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Fulltext search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Indexed Content: Main funding source */
  $handler->display->display_options['filters']['field_proj_funding_source_list']['id'] = 'field_proj_funding_source_list';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['field'] = 'field_proj_funding_source_list';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['value'] = array();
  $handler->display->display_options['filters']['field_proj_funding_source_list']['group'] = 1;
  $handler->display->display_options['filters']['field_proj_funding_source_list']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_proj_funding_source_list']['expose']['operator_id'] = 'field_proj_funding_source_list_op';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['expose']['label'] = 'Main funding source';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['expose']['operator'] = 'field_proj_funding_source_list_op';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['expose']['identifier'] = 'field_proj_funding_source_list';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Indexed Content: Geographical location */
  $handler->display->display_options['filters']['field_proj_geographical_area']['id'] = 'field_proj_geographical_area';
  $handler->display->display_options['filters']['field_proj_geographical_area']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_proj_geographical_area']['field'] = 'field_proj_geographical_area';
  $handler->display->display_options['filters']['field_proj_geographical_area']['value'] = array();
  $handler->display->display_options['filters']['field_proj_geographical_area']['group'] = 1;
  $handler->display->display_options['filters']['field_proj_geographical_area']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['operator_id'] = 'field_proj_geographical_area_op';
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['label'] = 'Geographical location';
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['operator'] = 'field_proj_geographical_area_op';
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['identifier'] = 'field_proj_geographical_area';
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Indexed Content: Whether the entity is flagged with flag agri_digitization_toolbox */
  $handler->display->display_options['filters']['flag_agri_digitization_toolbox']['id'] = 'flag_agri_digitization_toolbox';
  $handler->display->display_options['filters']['flag_agri_digitization_toolbox']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['flag_agri_digitization_toolbox']['field'] = 'flag_agri_digitization_toolbox';
  $handler->display->display_options['filters']['flag_agri_digitization_toolbox']['value'] = '1';
  $handler->display->display_options['filters']['flag_agri_digitization_toolbox']['group'] = 1;
  /* Filter criterion: Indexed Content: Keywords */
  $handler->display->display_options['filters']['field_core_keywords']['id'] = 'field_core_keywords';
  $handler->display->display_options['filters']['field_core_keywords']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_core_keywords']['field'] = 'field_core_keywords';
  $handler->display->display_options['filters']['field_core_keywords']['value'] = array();
  $handler->display->display_options['filters']['field_core_keywords']['group'] = 2;
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
    10 => 0,
    8 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
  );
  $handler->display->display_options['path'] = 'digitising-agriculture/projects';

  /* Display: Digitization toolbox - Projects keywords filtered */
  $handler = $view->new_display('block', 'Digitization toolbox - Projects keywords filtered', 'digitization_toolbox_projects_keywords');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Projects';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '2';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_table_plugin_style';
  $handler->display->display_options['style_options']['columns'] = array(
    'created' => 'created',
    'title' => 'title',
    'type' => 'type',
    'field_proj_project_type_1' => 'field_proj_project_type_1',
    'field_proj_geographical_area' => 'field_proj_geographical_area',
    'field_core_keywords' => 'field_core_keywords',
    'field_agri_proj_internal_kwords' => 'field_core_keywords',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
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
    'field_proj_project_type_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_proj_geographical_area' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_core_keywords' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_agri_proj_internal_kwords' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['bootstrap_styles'] = array(
    'striped' => 'striped',
    'bordered' => 0,
    'hover' => 0,
    'condensed' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Content: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Published on';
  $handler->display->display_options['fields']['created']['date_format'] = 'eip_agri_short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'eip_agri_long';
  $handler->display->display_options['fields']['created']['link_to_entity'] = 0;
  /* Field: Indexed Content: Project title */
  $handler->display->display_options['fields']['field_proj_title']['id'] = 'field_proj_title';
  $handler->display->display_options['fields']['field_proj_title']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_title']['field'] = 'field_proj_title';
  $handler->display->display_options['fields']['field_proj_title']['label'] = 'Title';
  $handler->display->display_options['fields']['field_proj_title']['link_to_entity'] = 1;
  /* Field: Indexed Content: Content type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['format_name'] = 1;
  /* Field: Indexed Content: Project type */
  $handler->display->display_options['fields']['field_proj_project_type_1']['id'] = 'field_proj_project_type_1';
  $handler->display->display_options['fields']['field_proj_project_type_1']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_project_type_1']['field'] = 'field_proj_project_type';
  $handler->display->display_options['fields']['field_proj_project_type_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_proj_project_type_1']['empty'] = '[type]';
  /* Field: Indexed Content: Geographical location */
  $handler->display->display_options['fields']['field_proj_geographical_area']['id'] = 'field_proj_geographical_area';
  $handler->display->display_options['fields']['field_proj_geographical_area']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_geographical_area']['field'] = 'field_proj_geographical_area';
  $handler->display->display_options['fields']['field_proj_geographical_area']['label'] = 'Country';
  $handler->display->display_options['fields']['field_proj_geographical_area']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_proj_geographical_area']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_proj_geographical_area']['bypass_access'] = 0;
  /* Field: Indexed Content: Keywords */
  $handler->display->display_options['fields']['field_core_keywords']['id'] = 'field_core_keywords';
  $handler->display->display_options['fields']['field_core_keywords']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_core_keywords']['field'] = 'field_core_keywords';
  $handler->display->display_options['fields']['field_core_keywords']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_core_keywords']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_core_keywords']['bypass_access'] = 0;
  /* Field: Indexed Content: Internal keywords */
  $handler->display->display_options['fields']['field_agri_proj_internal_kwords']['id'] = 'field_agri_proj_internal_kwords';
  $handler->display->display_options['fields']['field_agri_proj_internal_kwords']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_agri_proj_internal_kwords']['field'] = 'field_agri_proj_internal_kwords';
  $handler->display->display_options['fields']['field_agri_proj_internal_kwords']['label'] = 'Internal Keywords';
  $handler->display->display_options['fields']['field_agri_proj_internal_kwords']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_agri_proj_internal_kwords']['alter']['text'] = ', [field_agri_proj_internal_kwords]';
  $handler->display->display_options['fields']['field_agri_proj_internal_kwords']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_agri_proj_internal_kwords']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_agri_proj_internal_kwords']['bypass_access'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Search: Indexed taxonomy term fields */
  $handler->display->display_options['arguments']['search_api_views_taxonomy_term']['id'] = 'search_api_views_taxonomy_term';
  $handler->display->display_options['arguments']['search_api_views_taxonomy_term']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['arguments']['search_api_views_taxonomy_term']['field'] = 'search_api_views_taxonomy_term';
  $handler->display->display_options['arguments']['search_api_views_taxonomy_term']['default_action'] = 'default';
  $handler->display->display_options['arguments']['search_api_views_taxonomy_term']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['search_api_views_taxonomy_term']['default_argument_options']['term_page'] = FALSE;
  $handler->display->display_options['arguments']['search_api_views_taxonomy_term']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['search_api_views_taxonomy_term']['default_argument_options']['anyall'] = '+';
  $handler->display->display_options['arguments']['search_api_views_taxonomy_term']['default_argument_options']['limit'] = TRUE;
  $handler->display->display_options['arguments']['search_api_views_taxonomy_term']['default_argument_options']['vocabularies'] = array(
    'tags' => 'tags',
  );
  $handler->display->display_options['arguments']['search_api_views_taxonomy_term']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['search_api_views_taxonomy_term']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['search_api_views_taxonomy_term']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['search_api_views_taxonomy_term']['not'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'innovative_action' => 'innovative_action',
    'operational_group' => 'operational_group',
    'project' => 'project',
    'research_project' => 'research_project',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Indexed Content: Whether the entity is flagged with flag agri_digitization_toolbox */
  $handler->display->display_options['filters']['flag_agri_digitization_toolbox']['id'] = 'flag_agri_digitization_toolbox';
  $handler->display->display_options['filters']['flag_agri_digitization_toolbox']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['flag_agri_digitization_toolbox']['field'] = 'flag_agri_digitization_toolbox';
  $handler->display->display_options['filters']['flag_agri_digitization_toolbox']['value'] = '1';
  /* Filter criterion: Indexed Content: Geographical location */
  $handler->display->display_options['filters']['field_proj_geographical_area']['id'] = 'field_proj_geographical_area';
  $handler->display->display_options['filters']['field_proj_geographical_area']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_proj_geographical_area']['field'] = 'field_proj_geographical_area';
  $handler->display->display_options['filters']['field_proj_geographical_area']['value'] = array();
  $handler->display->display_options['filters']['field_proj_geographical_area']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['operator_id'] = 'field_proj_geographical_area_op';
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['label'] = 'Filter by country';
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['operator'] = 'field_proj_geographical_area_op';
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['identifier'] = 'country';
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['reduce'] = 0;
  $handler->display->display_options['block_description'] = 'AGRI Digitisation Toolbox - Projects keywords filtered';

  /* Display: Digitization toolbox - Projects landing block */
  $handler = $view->new_display('block', 'Digitization toolbox - Projects landing block', 'digitization_toolbox_projects_landing');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'New Digitisation Projects';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'digitization-toolbox projects';
  $handler->display->display_options['display_description'] = 'Block for projects in Digitisation toolbox landing page.';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'View all projects';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'projects_list';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Content: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd F Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'eip_agri_long';
  $handler->display->display_options['fields']['created']['link_to_entity'] = 0;
  /* Field: Indexed Content: Project title */
  $handler->display->display_options['fields']['field_proj_title']['id'] = 'field_proj_title';
  $handler->display->display_options['fields']['field_proj_title']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_title']['field'] = 'field_proj_title';
  $handler->display->display_options['fields']['field_proj_title']['label'] = '';
  $handler->display->display_options['fields']['field_proj_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_proj_title']['link_to_entity'] = 1;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Indexed Content: Whether the entity is flagged with flag agri_digitization_toolbox */
  $handler->display->display_options['filters']['flag_agri_digitization_toolbox']['id'] = 'flag_agri_digitization_toolbox';
  $handler->display->display_options['filters']['flag_agri_digitization_toolbox']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['flag_agri_digitization_toolbox']['field'] = 'flag_agri_digitization_toolbox';
  $handler->display->display_options['filters']['flag_agri_digitization_toolbox']['value'] = '1';
  $handler->display->display_options['filters']['flag_agri_digitization_toolbox']['group'] = 1;
  /* Filter criterion: Indexed Content: Geographical location */
  $handler->display->display_options['filters']['field_proj_geographical_area']['id'] = 'field_proj_geographical_area';
  $handler->display->display_options['filters']['field_proj_geographical_area']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_proj_geographical_area']['field'] = 'field_proj_geographical_area';
  $handler->display->display_options['filters']['field_proj_geographical_area']['value'] = array();
  $handler->display->display_options['filters']['field_proj_geographical_area']['group'] = 1;
  $handler->display->display_options['filters']['field_proj_geographical_area']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['operator_id'] = 'field_proj_geographical_area_op';
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['label'] = 'Filter by country';
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['operator'] = 'field_proj_geographical_area_op';
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['identifier'] = 'country';
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['reduce'] = 0;
  $handler->display->display_options['block_description'] = 'AGRI Digitisation Toolbox - Projects landing block';
  $export['agri_digitization_toolbox_projects_indexed_search'] = $view;

  $view = new view();
  $view->name = 'agri_projects_manage_projects';
  $view->description = 'Manage AGRI Projects and privacy policy configurations.';
  $view->tag = 'AGRI Projects';
  $view->base_table = 'node';
  $view->human_name = 'Manage Projects';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Manage Projects';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access manage projects view';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_table_plugin_style';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'field_project_puid' => 'field_project_puid',
    'title' => 'title',
    'field_proj_funding_source_list' => 'field_proj_funding_source_list',
    'field_proj_geographical_area' => 'field_proj_geographical_area',
    'status' => 'status',
    'changed' => 'changed',
    'ops' => 'ops',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
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
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_proj_funding_source_list' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_proj_geographical_area' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
    'ops' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['bootstrap_styles'] = array(
    'striped' => 'striped',
    'bordered' => 0,
    'hover' => 0,
    'condensed' => 0,
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No projects available to display.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Flags: agri_privacy_policy */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'flag_agri_privacy_policy';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'agri_privacy_policy';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
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
  );
  /* Field: Content: PUID (Project Unique ID) */
  $handler->display->display_options['fields']['field_project_puid']['id'] = 'field_project_puid';
  $handler->display->display_options['fields']['field_project_puid']['table'] = 'field_data_field_project_puid';
  $handler->display->display_options['fields']['field_project_puid']['field'] = 'field_project_puid';
  $handler->display->display_options['fields']['field_project_puid']['label'] = 'PUID';
  $handler->display->display_options['fields']['field_project_puid']['type'] = 'text_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Main funding source */
  $handler->display->display_options['fields']['field_proj_funding_source_list']['id'] = 'field_proj_funding_source_list';
  $handler->display->display_options['fields']['field_proj_funding_source_list']['table'] = 'field_data_field_proj_funding_source_list';
  $handler->display->display_options['fields']['field_proj_funding_source_list']['field'] = 'field_proj_funding_source_list';
  /* Field: Content: Geographical location */
  $handler->display->display_options['fields']['field_proj_geographical_area']['id'] = 'field_proj_geographical_area';
  $handler->display->display_options['fields']['field_proj_geographical_area']['table'] = 'field_data_field_proj_geographical_area';
  $handler->display->display_options['fields']['field_proj_geographical_area']['field'] = 'field_proj_geographical_area';
  $handler->display->display_options['fields']['field_proj_geographical_area']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_proj_geographical_area']['delta_offset'] = '0';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'Y-m-d H:i:s';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'eip_agri_long';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = 'Hide/Show Partners info';
  $handler->display->display_options['fields']['ops']['link_type'] = 'toggle';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: PUID (Project Unique ID) (field_project_puid) */
  $handler->display->display_options['filters']['field_project_puid_value']['id'] = 'field_project_puid_value';
  $handler->display->display_options['filters']['field_project_puid_value']['table'] = 'field_data_field_project_puid';
  $handler->display->display_options['filters']['field_project_puid_value']['field'] = 'field_project_puid_value';
  $handler->display->display_options['filters']['field_project_puid_value']['group'] = 1;
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
    9 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title contains';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Is published';
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
  /* Filter criterion: Flags: Flagged */
  $handler->display->display_options['filters']['flagged']['id'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['table'] = 'flagging';
  $handler->display->display_options['filters']['flagged']['field'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['flagged']['value'] = 'All';
  $handler->display->display_options['filters']['flagged']['group'] = 1;
  $handler->display->display_options['filters']['flagged']['exposed'] = TRUE;
  $handler->display->display_options['filters']['flagged']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['flagged']['expose']['label'] = 'Has hidden Partners';
  $handler->display->display_options['filters']['flagged']['expose']['operator'] = 'flagged_op';
  $handler->display->display_options['filters']['flagged']['expose']['identifier'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Main funding source (field_proj_funding_source_list) */
  $handler->display->display_options['filters']['field_proj_funding_source_list_value']['id'] = 'field_proj_funding_source_list_value';
  $handler->display->display_options['filters']['field_proj_funding_source_list_value']['table'] = 'field_data_field_proj_funding_source_list';
  $handler->display->display_options['filters']['field_proj_funding_source_list_value']['field'] = 'field_proj_funding_source_list_value';
  $handler->display->display_options['filters']['field_proj_funding_source_list_value']['group'] = 1;
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
    9 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
  );
  $handler->display->display_options['filters']['field_proj_funding_source_list_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['group'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'Geographical location';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['term_node_tid_depth']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'core_geographical_area';
  $handler->display->display_options['filters']['term_node_tid_depth']['hierarchy'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '1';

  /* Display: Manage Projects */
  $handler = $view->new_display('page', 'Manage Projects', 'page');
  $handler->display->display_options['path'] = 'sfc-projects/manage-projects';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Manage Projects';
  $handler->display->display_options['menu']['weight'] = '4';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['agri_projects_manage_projects'] = $view;

  $view = new view();
  $view->name = 'projects_blocks';
  $view->description = '';
  $view->tag = 'AGRI Projects';
  $view->base_table = 'node';
  $view->human_name = 'Projects Blocks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
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
  );
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
    'innovative_action' => 'innovative_action',
  );

  /* Display: Block: Latest research projects */
  $handler = $view->new_display('block', 'Block: Latest research projects', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Latest research projects';
  $handler->display->display_options['display_description'] = 'Latest research projects displayed on entrance page';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Published on';
  $handler->display->display_options['fields']['created']['date_format'] = 'eip_agri_short';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Project name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Start/ending dates */
  $handler->display->display_options['fields']['field_projects_dates']['id'] = 'field_projects_dates';
  $handler->display->display_options['fields']['field_projects_dates']['table'] = 'field_data_field_projects_dates';
  $handler->display->display_options['fields']['field_projects_dates']['field'] = 'field_projects_dates';
  $handler->display->display_options['fields']['field_projects_dates']['settings'] = array(
    'format_type' => 'eip_agri_medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Project code */
  $handler->display->display_options['fields']['field_projects_project_code']['id'] = 'field_projects_project_code';
  $handler->display->display_options['fields']['field_projects_project_code']['table'] = 'field_data_field_projects_project_code';
  $handler->display->display_options['fields']['field_projects_project_code']['field'] = 'field_projects_project_code';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'View project';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
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
    'research_project' => 'research_project',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  $handler->display->display_options['filters']['status_1']['group'] = 2;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'project' => 'project',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 2;
  /* Filter criterion: Content: Project type (field_proj_project_type) */
  $handler->display->display_options['filters']['field_proj_project_type_value']['id'] = 'field_proj_project_type_value';
  $handler->display->display_options['filters']['field_proj_project_type_value']['table'] = 'field_data_field_proj_project_type';
  $handler->display->display_options['filters']['field_proj_project_type_value']['field'] = 'field_proj_project_type_value';
  $handler->display->display_options['filters']['field_proj_project_type_value']['value'] = 'Research project';
  $handler->display->display_options['filters']['field_proj_project_type_value']['group'] = 2;

  /* Display: Block: Latest innovative actions */
  $handler = $view->new_display('block', 'Block: Latest innovative actions', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Latest innovative actions';
  $handler->display->display_options['display_description'] = 'Latest Innovative actions displayed on entrance page';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Published on';
  $handler->display->display_options['fields']['created']['date_format'] = 'eip_agri_short';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Action name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'View action';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
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
    'innovative_action' => 'innovative_action',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Multi-stakeholder innovative action or project (field_projects_status) */
  $handler->display->display_options['filters']['field_projects_status_value']['id'] = 'field_projects_status_value';
  $handler->display->display_options['filters']['field_projects_status_value']['table'] = 'field_data_field_projects_status';
  $handler->display->display_options['filters']['field_projects_status_value']['field'] = 'field_projects_status_value';
  $handler->display->display_options['filters']['field_projects_status_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_projects_status_value']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  $handler->display->display_options['filters']['status_1']['group'] = 2;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'project' => 'project',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 2;
  /* Filter criterion: Content: Project type (field_proj_project_type) */
  $handler->display->display_options['filters']['field_proj_project_type_value']['id'] = 'field_proj_project_type_value';
  $handler->display->display_options['filters']['field_proj_project_type_value']['table'] = 'field_data_field_proj_project_type';
  $handler->display->display_options['filters']['field_proj_project_type_value']['field'] = 'field_proj_project_type_value';
  $handler->display->display_options['filters']['field_proj_project_type_value']['value'] = 'Innovative action';
  $handler->display->display_options['filters']['field_proj_project_type_value']['group'] = 2;

  /* Display: Block: Latest needs for research from practice */
  $handler = $view->new_display('block', 'Block: Latest needs for research from practice', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Latest needs for research from practice';
  $handler->display->display_options['display_description'] = 'Latest needs for research from practice displayed on entrance page';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Published on';
  $handler->display->display_options['fields']['created']['date_format'] = 'eip_agri_short';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'View NFRFP';
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
    'needs_for_research_from_practice' => 'needs_for_research_from_practice',
  );
  $export['projects_blocks'] = $view;

  $view = new view();
  $view->name = 'projects_indexed_search_sub_pages';
  $view->description = '';
  $view->tag = 'AGRI Projects';
  $view->base_table = 'search_api_index_core_node_index';
  $view->human_name = 'Projects indexed search sub-pages';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Projects';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'created' => 'created',
    'title' => 'title',
    'type' => 'type',
    'field_proj_project_type_1' => 'field_proj_project_type_1',
    'view_node' => 'view_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
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
    'field_proj_project_type_1' => array(
      'sortable' => 1,
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
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  /* Field: Indexed Content: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Published on';
  $handler->display->display_options['fields']['created']['date_format'] = 'eip_agri_medium';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'eip_agri_long';
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Content: Content type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['format_name'] = 1;
  /* Field: Indexed Content: Project type */
  $handler->display->display_options['fields']['field_proj_project_type_1']['id'] = 'field_proj_project_type_1';
  $handler->display->display_options['fields']['field_proj_project_type_1']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_project_type_1']['field'] = 'field_proj_project_type';
  $handler->display->display_options['fields']['field_proj_project_type_1']['empty'] = '[type]';
  /* Sort criterion: Indexed Content: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'innovative_action' => 'innovative_action',
    'operational_group' => 'operational_group',
    'project' => 'project',
    'research_project' => 'research_project',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Indexed Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Indexed Content: Keywords */
  $handler->display->display_options['filters']['field_core_keywords']['id'] = 'field_core_keywords';
  $handler->display->display_options['filters']['field_core_keywords']['table'] = 'search_api_index_core_node_index';
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
    10 => 0,
    8 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
  );
  /* Filter criterion: Indexed Content: Geographical location */
  $handler->display->display_options['filters']['field_proj_geographical_area']['id'] = 'field_proj_geographical_area';
  $handler->display->display_options['filters']['field_proj_geographical_area']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_proj_geographical_area']['field'] = 'field_proj_geographical_area';
  $handler->display->display_options['filters']['field_proj_geographical_area']['value'] = array();
  $handler->display->display_options['filters']['field_proj_geographical_area']['group'] = 1;
  $handler->display->display_options['filters']['field_proj_geographical_area']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['operator_id'] = 'field_proj_geographical_area_op';
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['label'] = 'Geographical location';
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['operator'] = 'field_proj_geographical_area_op';
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['identifier'] = 'field_proj_geographical_area';
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Indexed Content: Main funding source */
  $handler->display->display_options['filters']['field_proj_funding_source_list']['id'] = 'field_proj_funding_source_list';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['field'] = 'field_proj_funding_source_list';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['value'] = array();
  $handler->display->display_options['filters']['field_proj_funding_source_list']['group'] = 1;
  $handler->display->display_options['filters']['field_proj_funding_source_list']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_proj_funding_source_list']['expose']['operator_id'] = 'field_proj_funding_source_list_op';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['expose']['label'] = 'Main funding source';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['expose']['operator'] = 'field_proj_funding_source_list_op';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['expose']['identifier'] = 'field_proj_funding_source_list';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Indexed Content: Language */
  $handler->display->display_options['filters']['field_projects_language']['id'] = 'field_projects_language';
  $handler->display->display_options['filters']['field_projects_language']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_projects_language']['field'] = 'field_projects_language';
  $handler->display->display_options['filters']['field_projects_language']['value'] = array();
  $handler->display->display_options['filters']['field_projects_language']['group'] = 1;
  $handler->display->display_options['filters']['field_projects_language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_projects_language']['expose']['operator_id'] = 'field_projects_language_op';
  $handler->display->display_options['filters']['field_projects_language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['field_projects_language']['expose']['operator'] = 'field_projects_language_op';
  $handler->display->display_options['filters']['field_projects_language']['expose']['identifier'] = 'field_projects_language';
  $handler->display->display_options['filters']['field_projects_language']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_projects_language']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Indexed Content: Agricultural sectors */
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['id'] = 'field_core_agricultural_sectors';
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['field'] = 'field_core_agricultural_sectors';
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['value'] = array();
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['expose']['operator_id'] = 'field_core_agricultural_sectors_op';
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['expose']['label'] = 'Agricultural sectors';
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['expose']['operator'] = 'field_core_agricultural_sectors_op';
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['expose']['identifier'] = 'field_core_agricultural_sectors';
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['operator'] = 'OR';
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
  /* Filter criterion: Indexed Content: Partner's categories */
  $handler->display->display_options['filters']['field_user_type']['id'] = 'field_user_type';
  $handler->display->display_options['filters']['field_user_type']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_user_type']['field'] = 'field_user_type';
  $handler->display->display_options['filters']['field_user_type']['value'] = array();
  $handler->display->display_options['filters']['field_user_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_type']['expose']['operator_id'] = 'field_user_type_op';
  $handler->display->display_options['filters']['field_user_type']['expose']['label'] = 'Partner\'s categories';
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
    10 => 0,
    8 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'created' => 'created',
    'field_proj_title' => 'field_proj_title',
    'type' => 'type',
    'field_proj_geographical_area' => 'field_proj_geographical_area',
    'field_proj_project_type_1' => 'field_proj_project_type_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_proj_title' => array(
      'sortable' => 1,
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
    'field_proj_geographical_area' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_proj_project_type_1' => array(
      'sortable' => 1,
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Content: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Published on';
  $handler->display->display_options['fields']['created']['date_format'] = 'eip_agri_short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'eip_agri_long';
  $handler->display->display_options['fields']['created']['link_to_entity'] = 0;
  /* Field: Indexed Content: Project title */
  $handler->display->display_options['fields']['field_proj_title']['id'] = 'field_proj_title';
  $handler->display->display_options['fields']['field_proj_title']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_title']['field'] = 'field_proj_title';
  $handler->display->display_options['fields']['field_proj_title']['label'] = 'Title';
  $handler->display->display_options['fields']['field_proj_title']['link_to_entity'] = 1;
  /* Field: Indexed Content: Content type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['format_name'] = 1;
  /* Field: Indexed Content: Geographical location */
  $handler->display->display_options['fields']['field_proj_geographical_area']['id'] = 'field_proj_geographical_area';
  $handler->display->display_options['fields']['field_proj_geographical_area']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_geographical_area']['field'] = 'field_proj_geographical_area';
  $handler->display->display_options['fields']['field_proj_geographical_area']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_proj_geographical_area']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_proj_geographical_area']['bypass_access'] = 0;
  /* Field: Indexed Content: Project type */
  $handler->display->display_options['fields']['field_proj_project_type_1']['id'] = 'field_proj_project_type_1';
  $handler->display->display_options['fields']['field_proj_project_type_1']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_project_type_1']['field'] = 'field_proj_project_type';
  $handler->display->display_options['fields']['field_proj_project_type_1']['empty'] = '[type]';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Indexed Content: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    3 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'innovative_action' => 'innovative_action',
    'operational_group' => 'operational_group',
    'project' => 'project',
    'research_project' => 'research_project',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Fulltext search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Indexed Content: Keywords */
  $handler->display->display_options['filters']['field_core_keywords']['id'] = 'field_core_keywords';
  $handler->display->display_options['filters']['field_core_keywords']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_core_keywords']['field'] = 'field_core_keywords';
  $handler->display->display_options['filters']['field_core_keywords']['value'] = array();
  $handler->display->display_options['filters']['field_core_keywords']['group'] = 2;
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
    10 => 0,
    8 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
  );
  /* Filter criterion: Indexed Content: Main funding source */
  $handler->display->display_options['filters']['field_proj_funding_source_list']['id'] = 'field_proj_funding_source_list';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['field'] = 'field_proj_funding_source_list';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['value'] = array();
  $handler->display->display_options['filters']['field_proj_funding_source_list']['group'] = 3;
  $handler->display->display_options['filters']['field_proj_funding_source_list']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_proj_funding_source_list']['expose']['operator_id'] = 'field_proj_funding_source_list_op';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['expose']['label'] = 'Main funding source';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['expose']['operator'] = 'field_proj_funding_source_list_op';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['expose']['identifier'] = 'field_proj_funding_source_list';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Indexed Content: Geographical location */
  $handler->display->display_options['filters']['field_proj_geographical_area']['id'] = 'field_proj_geographical_area';
  $handler->display->display_options['filters']['field_proj_geographical_area']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_proj_geographical_area']['field'] = 'field_proj_geographical_area';
  $handler->display->display_options['filters']['field_proj_geographical_area']['value'] = array();
  $handler->display->display_options['filters']['field_proj_geographical_area']['group'] = 3;
  $handler->display->display_options['filters']['field_proj_geographical_area']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['operator_id'] = 'field_proj_geographical_area_op';
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['label'] = 'Geographical location';
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['operator'] = 'field_proj_geographical_area_op';
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['identifier'] = 'field_proj_geographical_area';
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['path'] = 'find-connect/projects';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Projects';
  $handler->display->display_options['menu']['weight'] = '-50';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['title'] = 'Projects';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_indexed');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['attach_text'] = 'Export';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = '1';
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Content: Title (in English) */
  $handler->display->display_options['fields']['field_proj_title_eng']['id'] = 'field_proj_title_eng';
  $handler->display->display_options['fields']['field_proj_title_eng']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_title_eng']['field'] = 'field_proj_title_eng';
  /* Field: Indexed Content: Language */
  $handler->display->display_options['fields']['field_projects_language']['id'] = 'field_projects_language';
  $handler->display->display_options['fields']['field_projects_language']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_projects_language']['field'] = 'field_projects_language';
  /* Field: Indexed Content: Objective of the project (native language) */
  $handler->display->display_options['fields']['field_proj_problems']['id'] = 'field_proj_problems';
  $handler->display->display_options['fields']['field_proj_problems']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_problems']['field'] = 'field_proj_problems';
  /* Field: Indexed Content: Objective of the project (in English) */
  $handler->display->display_options['fields']['field_proj_problems_eng']['id'] = 'field_proj_problems_eng';
  $handler->display->display_options['fields']['field_proj_problems_eng']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_problems_eng']['field'] = 'field_proj_problems_eng';
  /* Field: Indexed Content: Description of activities (native language) */
  $handler->display->display_options['fields']['field_proj_desc']['id'] = 'field_proj_desc';
  $handler->display->display_options['fields']['field_proj_desc']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_desc']['field'] = 'field_proj_desc';
  /* Field: Indexed Content: Description of activities (in English) */
  $handler->display->display_options['fields']['field_proj_desc_eng']['id'] = 'field_proj_desc_eng';
  $handler->display->display_options['fields']['field_proj_desc_eng']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_desc_eng']['field'] = 'field_proj_desc_eng';
  /* Field: Indexed Content: Total budget */
  $handler->display->display_options['fields']['field_proj_og_budget']['id'] = 'field_proj_og_budget';
  $handler->display->display_options['fields']['field_proj_og_budget']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_og_budget']['field'] = 'field_proj_og_budget';
  /* Field: Indexed Content: EU contribution */
  $handler->display->display_options['fields']['field_proj_og_eu_contribution']['id'] = 'field_proj_og_eu_contribution';
  $handler->display->display_options['fields']['field_proj_og_eu_contribution']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_og_eu_contribution']['field'] = 'field_proj_og_eu_contribution';
  /* Field: Indexed Content: Contact person */
  $handler->display->display_options['fields']['field_proj_ia_contact_person']['id'] = 'field_proj_ia_contact_person';
  $handler->display->display_options['fields']['field_proj_ia_contact_person']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_ia_contact_person']['field'] = 'field_proj_ia_contact_person';
  /* Field: Indexed Content: Contact e-mail */
  $handler->display->display_options['fields']['field_proj_contact_e_mail']['id'] = 'field_proj_contact_e_mail';
  $handler->display->display_options['fields']['field_proj_contact_e_mail']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_contact_e_mail']['field'] = 'field_proj_contact_e_mail';
  /* Field: Indexed Content: Editor of the text */
  $handler->display->display_options['fields']['field_proj_editor_of_text']['id'] = 'field_proj_editor_of_text';
  $handler->display->display_options['fields']['field_proj_editor_of_text']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_editor_of_text']['field'] = 'field_proj_editor_of_text';
  /* Field: Indexed Content: Geographical location */
  $handler->display->display_options['fields']['field_proj_geographical_area']['id'] = 'field_proj_geographical_area';
  $handler->display->display_options['fields']['field_proj_geographical_area']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_geographical_area']['field'] = 'field_proj_geographical_area';
  /* Field: Indexed Content: Other location */
  $handler->display->display_options['fields']['field_proj_other_location']['id'] = 'field_proj_other_location';
  $handler->display->display_options['fields']['field_proj_other_location']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_other_location']['field'] = 'field_proj_other_location';
  /* Field: Indexed Content: Starting date */
  $handler->display->display_options['fields']['field_proj_starting_date']['id'] = 'field_proj_starting_date';
  $handler->display->display_options['fields']['field_proj_starting_date']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_starting_date']['field'] = 'field_proj_starting_date';
  /* Field: Indexed Content: End date */
  $handler->display->display_options['fields']['field_proj_end_date']['id'] = 'field_proj_end_date';
  $handler->display->display_options['fields']['field_proj_end_date']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_end_date']['field'] = 'field_proj_end_date';
  /* Field: Indexed Content: Project coordinator */
  $handler->display->display_options['fields']['field_proj_coordinator_fc']['id'] = 'field_proj_coordinator_fc';
  $handler->display->display_options['fields']['field_proj_coordinator_fc']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_coordinator_fc']['field'] = 'field_proj_coordinator_fc';
  $handler->display->display_options['fields']['field_proj_coordinator_fc']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_proj_coordinator_fc']['display'] = 'view';
  $handler->display->display_options['fields']['field_proj_coordinator_fc']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_proj_coordinator_fc']['bypass_access'] = 0;
  /* Field: Indexed Content: Keywords */
  $handler->display->display_options['fields']['field_core_keywords']['id'] = 'field_core_keywords';
  $handler->display->display_options['fields']['field_core_keywords']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_core_keywords']['field'] = 'field_core_keywords';
  /* Field: Indexed Content: Agricultural sectors */
  $handler->display->display_options['fields']['field_core_agricultural_sectors']['id'] = 'field_core_agricultural_sectors';
  $handler->display->display_options['fields']['field_core_agricultural_sectors']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_core_agricultural_sectors']['field'] = 'field_core_agricultural_sectors';
  $handler->display->display_options['fields']['field_core_agricultural_sectors']['link_to_entity'] = 1;
  /* Field: Indexed Content: Main funding source */
  $handler->display->display_options['fields']['field_proj_funding_source_list']['id'] = 'field_proj_funding_source_list';
  $handler->display->display_options['fields']['field_proj_funding_source_list']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_funding_source_list']['field'] = 'field_proj_funding_source_list';
  /* Field: Indexed Content: Project type */
  $handler->display->display_options['fields']['field_proj_project_type_1']['id'] = 'field_proj_project_type_1';
  $handler->display->display_options['fields']['field_proj_project_type_1']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_project_type_1']['field'] = 'field_proj_project_type';
  $handler->display->display_options['fields']['field_proj_project_type_1']['empty'] = '[type]';
  /* Field: Indexed Content: Project acronym */
  $handler->display->display_options['fields']['field_proj_rp_acronym']['id'] = 'field_proj_rp_acronym';
  $handler->display->display_options['fields']['field_proj_rp_acronym']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_rp_acronym']['field'] = 'field_proj_rp_acronym';
  /* Field: Indexed Content: Project status */
  $handler->display->display_options['fields']['field_proj_og_project_status']['id'] = 'field_proj_og_project_status';
  $handler->display->display_options['fields']['field_proj_og_project_status']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_og_project_status']['field'] = 'field_proj_og_project_status';
  /* Field: Indexed Content: Website */
  $handler->display->display_options['fields']['field_proj_website']['id'] = 'field_proj_website';
  $handler->display->display_options['fields']['field_proj_website']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_website']['field'] = 'field_proj_website';
  $handler->display->display_options['fields']['field_proj_website']['click_sort_column'] = 'url';
  /* Field: Indexed Content: Links to other website(s) */
  $handler->display->display_options['fields']['field_proj_other_websites']['id'] = 'field_proj_other_websites';
  $handler->display->display_options['fields']['field_proj_other_websites']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_other_websites']['field'] = 'field_proj_other_websites';
  $handler->display->display_options['fields']['field_proj_other_websites']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_proj_other_websites']['delta_offset'] = '0';
  /* Field: Indexed Content: Audiovisual material */
  $handler->display->display_options['fields']['field_proj_audiovisual_material']['id'] = 'field_proj_audiovisual_material';
  $handler->display->display_options['fields']['field_proj_audiovisual_material']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_audiovisual_material']['field'] = 'field_proj_audiovisual_material';
  $handler->display->display_options['fields']['field_proj_audiovisual_material']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_proj_audiovisual_material']['delta_offset'] = '0';
  /* Field: Indexed Content: Additional information */
  $handler->display->display_options['fields']['field_proj_additional_info']['id'] = 'field_proj_additional_info';
  $handler->display->display_options['fields']['field_proj_additional_info']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_additional_info']['field'] = 'field_proj_additional_info';
  /* Field: Indexed Content: Description of the context of the project */
  $handler->display->display_options['fields']['field_proj_desc_context']['id'] = 'field_proj_desc_context';
  $handler->display->display_options['fields']['field_proj_desc_context']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_desc_context']['field'] = 'field_proj_desc_context';
  /* Field: Indexed Content: Project report / relevant documents */
  $handler->display->display_options['fields']['field_proj_attachment']['id'] = 'field_proj_attachment';
  $handler->display->display_options['fields']['field_proj_attachment']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_attachment']['field'] = 'field_proj_attachment';
  $handler->display->display_options['fields']['field_proj_attachment']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_proj_attachment']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_proj_attachment']['delta_offset'] = '0';
  /* Field: Indexed Content: PUID (Project Unique ID) */
  $handler->display->display_options['fields']['field_project_puid']['id'] = 'field_project_puid';
  $handler->display->display_options['fields']['field_project_puid']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_project_puid']['field'] = 'field_project_puid';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
    3 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_core_node_index';
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
    9 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
  );
  /* Filter criterion: Indexed Content: Main funding source */
  $handler->display->display_options['filters']['field_proj_funding_source_list']['id'] = 'field_proj_funding_source_list';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['field'] = 'field_proj_funding_source_list';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['value'] = array();
  $handler->display->display_options['filters']['field_proj_funding_source_list']['group'] = 2;
  $handler->display->display_options['filters']['field_proj_funding_source_list']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_proj_funding_source_list']['expose']['operator_id'] = 'field_proj_funding_source_list_op';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['expose']['label'] = 'Main funding source';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['expose']['operator'] = 'field_proj_funding_source_list_op';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['expose']['identifier'] = 'field_proj_funding_source_list';
  $handler->display->display_options['filters']['field_proj_funding_source_list']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_proj_funding_source_list']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Content: Geographical location */
  $handler->display->display_options['filters']['field_proj_geographical_area']['id'] = 'field_proj_geographical_area';
  $handler->display->display_options['filters']['field_proj_geographical_area']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_proj_geographical_area']['field'] = 'field_proj_geographical_area';
  $handler->display->display_options['filters']['field_proj_geographical_area']['value'] = array();
  $handler->display->display_options['filters']['field_proj_geographical_area']['group'] = 2;
  $handler->display->display_options['filters']['field_proj_geographical_area']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['operator_id'] = 'field_proj_geographical_area_op';
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['label'] = 'Geographical location';
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['operator'] = 'field_proj_geographical_area_op';
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['identifier'] = 'field_proj_geographical_area';
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_proj_geographical_area']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Content: Keywords */
  $handler->display->display_options['filters']['field_core_keywords']['id'] = 'field_core_keywords';
  $handler->display->display_options['filters']['field_core_keywords']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_core_keywords']['field'] = 'field_core_keywords';
  $handler->display->display_options['filters']['field_core_keywords']['value'] = array();
  $handler->display->display_options['filters']['field_core_keywords']['group'] = 3;
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
    9 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
  );
  $handler->display->display_options['filters']['field_core_keywords']['expose']['reduce'] = 0;
  $handler->display->display_options['path'] = 'find-connect/projects/projects_export.csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'find-connect/projects';
  $handler->display->display_options['segment_size'] = '25';
  $export['projects_indexed_search_sub_pages'] = $view;

  $view = new view();
  $view->name = 'projects_operational_groups_list';
  $view->description = '';
  $view->tag = 'AGRI Projects';
  $view->base_table = 'node';
  $view->human_name = 'projects operational groups list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Operational groups';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
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
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
  );
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
    'operational_group' => 'operational_group',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Funding type (field_projects_funding_type) (translated) */
  $handler->display->display_options['filters']['field_projects_funding_type_value_i18n']['id'] = 'field_projects_funding_type_value_i18n';
  $handler->display->display_options['filters']['field_projects_funding_type_value_i18n']['table'] = 'field_data_field_projects_funding_type';
  $handler->display->display_options['filters']['field_projects_funding_type_value_i18n']['field'] = 'field_projects_funding_type_value_i18n';
  $handler->display->display_options['filters']['field_projects_funding_type_value_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_projects_funding_type_value_i18n']['expose']['operator_id'] = 'field_projects_funding_type_value_i18n_op';
  $handler->display->display_options['filters']['field_projects_funding_type_value_i18n']['expose']['label'] = 'Funding type';
  $handler->display->display_options['filters']['field_projects_funding_type_value_i18n']['expose']['operator'] = 'field_projects_funding_type_value_i18n_op';
  $handler->display->display_options['filters']['field_projects_funding_type_value_i18n']['expose']['identifier'] = 'field_projects_funding_type_value_i18n';
  $handler->display->display_options['filters']['field_projects_funding_type_value_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_projects_funding_type_value_i18n']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_projects_funding_type_value_i18n']['reduce_duplicates'] = TRUE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'find-connect/operational-groups';
  $export['projects_operational_groups_list'] = $view;

  $view = new view();
  $view->name = 'projects_search_sub_pages';
  $view->description = '';
  $view->tag = 'AGRI Projects';
  $view->base_table = 'node';
  $view->human_name = 'Projects search sub-pages';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Research projects';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'created' => 'created',
    'title' => 'title',
    'view_node' => 'view_node',
    'field_core_email' => 'field_projects_name',
    'field_projects_name' => 'field_projects_name',
    'field_projects_surname' => 'field_projects_name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'created' => array(
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
    'view_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_core_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_projects_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_projects_surname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
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
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'research_project' => 'research_project',
  );

  /* Display: Page: Needs for research */
  $handler = $view->new_display('page', 'Page: Needs for research', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Needs for research from practice';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Published on';
  $handler->display->display_options['fields']['created']['date_format'] = 'eip_agri_medium';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Name */
  $handler->display->display_options['fields']['field_projects_name']['id'] = 'field_projects_name';
  $handler->display->display_options['fields']['field_projects_name']['table'] = 'field_data_field_projects_name';
  $handler->display->display_options['fields']['field_projects_name']['field'] = 'field_projects_name';
  $handler->display->display_options['fields']['field_projects_name']['label'] = 'Contact';
  $handler->display->display_options['fields']['field_projects_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_projects_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_projects_name']['alter']['text'] = '[field_projects_name-value] ';
  $handler->display->display_options['fields']['field_projects_name']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_projects_name']['element_wrapper_class'] = 'name-list';
  /* Field: Content: Surname */
  $handler->display->display_options['fields']['field_projects_surname']['id'] = 'field_projects_surname';
  $handler->display->display_options['fields']['field_projects_surname']['table'] = 'field_data_field_projects_surname';
  $handler->display->display_options['fields']['field_projects_surname']['field'] = 'field_projects_surname';
  $handler->display->display_options['fields']['field_projects_surname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_projects_surname']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_projects_surname']['alter']['text'] = '[field_projects_surname-value]  ';
  $handler->display->display_options['fields']['field_projects_surname']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_projects_surname']['element_wrapper_class'] = 'name-list';
  /* Field: Field: Contact e-mail */
  $handler->display->display_options['fields']['field_core_email']['id'] = 'field_core_email';
  $handler->display->display_options['fields']['field_core_email']['table'] = 'field_data_field_core_email';
  $handler->display->display_options['fields']['field_core_email']['field'] = 'field_core_email';
  $handler->display->display_options['fields']['field_core_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_core_email']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_core_email']['alter']['text'] = '<div class="email-list">[field_core_email]</div>';
  $handler->display->display_options['fields']['field_core_email']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_core_email']['element_wrapper_class'] = 'email-list';
  $handler->display->display_options['fields']['field_core_email']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_core_email']['type'] = 'email_contact';
  /* Field: Content: Interested in getting involved */
  $handler->display->display_options['fields']['field_projects_interested']['id'] = 'field_projects_interested';
  $handler->display->display_options['fields']['field_projects_interested']['table'] = 'field_data_field_projects_interested';
  $handler->display->display_options['fields']['field_projects_interested']['field'] = 'field_projects_interested';
  $handler->display->display_options['fields']['field_projects_interested']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_projects_interested']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_projects_interested']['alter']['text'] = '[field_projects_name] [field_projects_surname][field_core_email]';
  /* Field: Content: Interested in: */
  $handler->display->display_options['fields']['field_projects_interested_in']['id'] = 'field_projects_interested_in';
  $handler->display->display_options['fields']['field_projects_interested_in']['table'] = 'field_data_field_projects_interested_in';
  $handler->display->display_options['fields']['field_projects_interested_in']['field'] = 'field_projects_interested_in';
  $handler->display->display_options['fields']['field_projects_interested_in']['label'] = 'Contact';
  $handler->display->display_options['fields']['field_projects_interested_in']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_projects_interested_in']['alter']['text'] = '[field_projects_name] [field_projects_surname][field_core_email]';
  $handler->display->display_options['fields']['field_projects_interested_in']['empty'] = '[field_projects_interested] ';
  $handler->display->display_options['fields']['field_projects_interested_in']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_projects_interested_in']['delta_offset'] = '0';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
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
    'needs_for_research_from_practice' => 'needs_for_research_from_practice',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
  );
  /* Filter criterion: Field: Keywords (field_core_keywords) */
  $handler->display->display_options['filters']['field_core_keywords_tid']['id'] = 'field_core_keywords_tid';
  $handler->display->display_options['filters']['field_core_keywords_tid']['table'] = 'field_data_field_core_keywords';
  $handler->display->display_options['filters']['field_core_keywords_tid']['field'] = 'field_core_keywords_tid';
  $handler->display->display_options['filters']['field_core_keywords_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_core_keywords_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['operator_id'] = 'field_core_keywords_tid_op';
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['label'] = 'Keywords';
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['operator'] = 'field_core_keywords_tid_op';
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['identifier'] = 'field_core_keywords_tid';
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['multiple'] = TRUE;
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
  $handler->display->display_options['filters']['field_core_keywords_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_core_keywords_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_core_keywords_tid']['vocabulary'] = 'tags';
  /* Filter criterion: Field: Geographical scope (field_core_geographical_area) (translated) */
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['id'] = 'field_core_geographical_area_tid_i18n';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['table'] = 'field_data_field_core_geographical_area';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['field'] = 'field_core_geographical_area_tid_i18n';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['expose']['operator_id'] = 'field_core_geographical_area_tid_i18n_op';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['expose']['label'] = 'Geographical scope';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['expose']['operator'] = 'field_core_geographical_area_tid_i18n_op';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['expose']['identifier'] = 'field_core_geographical_area_tid_i18n';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['type'] = 'select';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['vocabulary'] = 'core_geographical_area';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['hierarchy'] = 1;
  /* Filter criterion: Content: Language (field_projects_language) (translated) */
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['id'] = 'field_projects_language_value_i18n';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['table'] = 'field_data_field_projects_language';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['field'] = 'field_projects_language_value_i18n';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['expose']['operator_id'] = 'field_projects_language_value_i18n_op';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['expose']['operator'] = 'field_projects_language_value_i18n_op';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['expose']['identifier'] = 'field_projects_language_value_i18n';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['path'] = 'find-connect/needs-for-research';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Research needs';
  $handler->display->display_options['menu']['weight'] = '-48';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page: Projects */
  $handler = $view->new_display('page', 'Page: Projects', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Projects';
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'created' => 'created',
    'title' => 'title',
    'field_projects_name' => 'field_projects_name',
    'field_projects_surname' => 'field_projects_surname',
    'field_core_email' => 'field_core_email',
    'view_node' => 'view_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'created' => array(
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
    'field_projects_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_projects_surname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_core_email' => array(
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
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Published on';
  $handler->display->display_options['fields']['created']['date_format'] = 'eip_agri_medium';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Project type';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Project type */
  $handler->display->display_options['fields']['field_proj_project_type']['id'] = 'field_proj_project_type';
  $handler->display->display_options['fields']['field_proj_project_type']['table'] = 'field_data_field_proj_project_type';
  $handler->display->display_options['fields']['field_proj_project_type']['field'] = 'field_proj_project_type';
  $handler->display->display_options['fields']['field_proj_project_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_proj_project_type']['empty'] = '[type] ';
  $handler->display->display_options['fields']['field_proj_project_type']['type'] = 'text_plain';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
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
    'innovative_action' => 'innovative_action',
    'operational_group' => 'operational_group',
    'project' => 'project',
    'research_project' => 'research_project',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
  );
  /* Filter criterion: Field: Keywords (field_core_keywords) */
  $handler->display->display_options['filters']['field_core_keywords_tid']['id'] = 'field_core_keywords_tid';
  $handler->display->display_options['filters']['field_core_keywords_tid']['table'] = 'field_data_field_core_keywords';
  $handler->display->display_options['filters']['field_core_keywords_tid']['field'] = 'field_core_keywords_tid';
  $handler->display->display_options['filters']['field_core_keywords_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_core_keywords_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['operator_id'] = 'field_core_keywords_tid_op';
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['label'] = 'Keywords';
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['operator'] = 'field_core_keywords_tid_op';
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['identifier'] = 'field_core_keywords_tid';
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['multiple'] = TRUE;
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
  $handler->display->display_options['filters']['field_core_keywords_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_core_keywords_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_core_keywords_tid']['vocabulary'] = 'tags';
  $handler->display->display_options['filters']['field_core_keywords_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Geographical location (field_proj_geographical_area) */
  $handler->display->display_options['filters']['field_proj_geographical_area_tid']['id'] = 'field_proj_geographical_area_tid';
  $handler->display->display_options['filters']['field_proj_geographical_area_tid']['table'] = 'field_data_field_proj_geographical_area';
  $handler->display->display_options['filters']['field_proj_geographical_area_tid']['field'] = 'field_proj_geographical_area_tid';
  $handler->display->display_options['filters']['field_proj_geographical_area_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_proj_geographical_area_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_proj_geographical_area_tid']['expose']['operator_id'] = 'field_proj_geographical_area_tid_op';
  $handler->display->display_options['filters']['field_proj_geographical_area_tid']['expose']['label'] = 'Geographical scope';
  $handler->display->display_options['filters']['field_proj_geographical_area_tid']['expose']['operator'] = 'field_proj_geographical_area_tid_op';
  $handler->display->display_options['filters']['field_proj_geographical_area_tid']['expose']['identifier'] = 'field_proj_geographical_area_tid';
  $handler->display->display_options['filters']['field_proj_geographical_area_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_proj_geographical_area_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_proj_geographical_area_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_proj_geographical_area_tid']['vocabulary'] = 'core_geographical_area';
  $handler->display->display_options['filters']['field_proj_geographical_area_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Main funding source (field_proj_funding_source_list) (translated) */
  $handler->display->display_options['filters']['field_proj_funding_source_list_value_i18n']['id'] = 'field_proj_funding_source_list_value_i18n';
  $handler->display->display_options['filters']['field_proj_funding_source_list_value_i18n']['table'] = 'field_data_field_proj_funding_source_list';
  $handler->display->display_options['filters']['field_proj_funding_source_list_value_i18n']['field'] = 'field_proj_funding_source_list_value_i18n';
  $handler->display->display_options['filters']['field_proj_funding_source_list_value_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_proj_funding_source_list_value_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_proj_funding_source_list_value_i18n']['expose']['operator_id'] = 'field_proj_funding_source_list_value_i18n_op';
  $handler->display->display_options['filters']['field_proj_funding_source_list_value_i18n']['expose']['label'] = 'Main funding source';
  $handler->display->display_options['filters']['field_proj_funding_source_list_value_i18n']['expose']['operator'] = 'field_proj_funding_source_list_value_i18n_op';
  $handler->display->display_options['filters']['field_proj_funding_source_list_value_i18n']['expose']['identifier'] = 'field_proj_funding_source_list_value_i18n';
  $handler->display->display_options['filters']['field_proj_funding_source_list_value_i18n']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_proj_funding_source_list_value_i18n']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Content: Language (field_projects_language) (translated) */
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['id'] = 'field_projects_language_value_i18n';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['table'] = 'field_data_field_projects_language';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['field'] = 'field_projects_language_value_i18n';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['expose']['operator_id'] = 'field_projects_language_value_i18n_op';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['expose']['operator'] = 'field_projects_language_value_i18n_op';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['expose']['identifier'] = 'field_projects_language_value_i18n';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['path'] = 'find-connect/projects';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Search Interesting Projects';
  $handler->display->display_options['menu']['weight'] = '-48';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page: Project ideas */
  $handler = $view->new_display('page', 'Page: Project ideas', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Project Ideas';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Published on';
  $handler->display->display_options['fields']['created']['date_format'] = 'eip_agri_medium';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Name */
  $handler->display->display_options['fields']['field_projects_name']['id'] = 'field_projects_name';
  $handler->display->display_options['fields']['field_projects_name']['table'] = 'field_data_field_projects_name';
  $handler->display->display_options['fields']['field_projects_name']['field'] = 'field_projects_name';
  $handler->display->display_options['fields']['field_projects_name']['label'] = 'Contact';
  $handler->display->display_options['fields']['field_projects_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_projects_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_projects_name']['alter']['text'] = '[field_projects_name-value] ';
  $handler->display->display_options['fields']['field_projects_name']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_projects_name']['element_wrapper_class'] = 'name-list';
  /* Field: Content: Surname */
  $handler->display->display_options['fields']['field_projects_surname']['id'] = 'field_projects_surname';
  $handler->display->display_options['fields']['field_projects_surname']['table'] = 'field_data_field_projects_surname';
  $handler->display->display_options['fields']['field_projects_surname']['field'] = 'field_projects_surname';
  $handler->display->display_options['fields']['field_projects_surname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_projects_surname']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_projects_surname']['alter']['text'] = '[field_projects_surname-value]  ';
  $handler->display->display_options['fields']['field_projects_surname']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_projects_surname']['element_wrapper_class'] = 'name-list';
  /* Field: Field: Contact e-mail */
  $handler->display->display_options['fields']['field_core_email']['id'] = 'field_core_email';
  $handler->display->display_options['fields']['field_core_email']['table'] = 'field_data_field_core_email';
  $handler->display->display_options['fields']['field_core_email']['field'] = 'field_core_email';
  $handler->display->display_options['fields']['field_core_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_core_email']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_core_email']['alter']['text'] = '<div class="email-list">[field_core_email]</div>';
  $handler->display->display_options['fields']['field_core_email']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_core_email']['element_wrapper_class'] = 'email-list';
  $handler->display->display_options['fields']['field_core_email']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_core_email']['type'] = 'email_contact';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
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
    'project_ideas' => 'project_ideas',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
  );
  /* Filter criterion: Field: Keywords (field_core_keywords) */
  $handler->display->display_options['filters']['field_core_keywords_tid']['id'] = 'field_core_keywords_tid';
  $handler->display->display_options['filters']['field_core_keywords_tid']['table'] = 'field_data_field_core_keywords';
  $handler->display->display_options['filters']['field_core_keywords_tid']['field'] = 'field_core_keywords_tid';
  $handler->display->display_options['filters']['field_core_keywords_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_core_keywords_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['operator_id'] = 'field_core_keywords_tid_op';
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['label'] = 'Keywords';
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['operator'] = 'field_core_keywords_tid_op';
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['identifier'] = 'field_core_keywords_tid';
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['multiple'] = TRUE;
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
  $handler->display->display_options['filters']['field_core_keywords_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_core_keywords_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_core_keywords_tid']['vocabulary'] = 'tags';
  /* Filter criterion: Field: Geographical scope (field_core_geographical_area) (translated) */
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['id'] = 'field_core_geographical_area_tid_i18n';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['table'] = 'field_data_field_core_geographical_area';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['field'] = 'field_core_geographical_area_tid_i18n';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['expose']['operator_id'] = 'field_core_geographical_area_tid_i18n_op';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['expose']['label'] = 'Geographical scope';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['expose']['operator'] = 'field_core_geographical_area_tid_i18n_op';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['expose']['identifier'] = 'field_core_geographical_area_tid_i18n';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['type'] = 'select';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['vocabulary'] = 'core_geographical_area';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['hierarchy'] = 1;
  /* Filter criterion: Content: Language (field_projects_language) (translated) */
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['id'] = 'field_projects_language_value_i18n';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['table'] = 'field_data_field_projects_language';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['field'] = 'field_projects_language_value_i18n';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['expose']['operator_id'] = 'field_projects_language_value_i18n_op';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['expose']['operator'] = 'field_projects_language_value_i18n_op';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['expose']['identifier'] = 'field_projects_language_value_i18n';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['path'] = 'find-connect/project-ideas';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Project Ideas';
  $handler->display->display_options['menu']['weight'] = '-44';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export: Needs for research */
  $handler = $view->new_display('views_data_export', 'Data export: Needs for research', 'views_data_export_nfr');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Data export: Needs for research';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['attach_text'] = 'Export';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = '1';
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Published on';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'eip_agri_medium';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'eip_agri_long';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body_1']['id'] = 'body_1';
  $handler->display->display_options['fields']['body_1']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_1']['field'] = 'body';
  $handler->display->display_options['fields']['body_1']['label'] = 'This is the problem';
  /* Field: Content: Description in english */
  $handler->display->display_options['fields']['field_core_description_eng']['id'] = 'field_core_description_eng';
  $handler->display->display_options['fields']['field_core_description_eng']['table'] = 'field_data_field_core_description_eng';
  $handler->display->display_options['fields']['field_core_description_eng']['field'] = 'field_core_description_eng';
  $handler->display->display_options['fields']['field_core_description_eng']['label'] = 'This is the problem (summary in English)';
  /* Field: Field: Geographical scope */
  $handler->display->display_options['fields']['field_core_geographical_area']['id'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['table'] = 'field_data_field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['field'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_core_geographical_area']['delta_offset'] = '0';
  /* Field: Field: Specify other location */
  $handler->display->display_options['fields']['field_core_other_location']['id'] = 'field_core_other_location';
  $handler->display->display_options['fields']['field_core_other_location']['table'] = 'field_data_field_core_other_location';
  $handler->display->display_options['fields']['field_core_other_location']['field'] = 'field_core_other_location';
  /* Field: Field: Keywords */
  $handler->display->display_options['fields']['field_core_keywords']['id'] = 'field_core_keywords';
  $handler->display->display_options['fields']['field_core_keywords']['table'] = 'field_data_field_core_keywords';
  $handler->display->display_options['fields']['field_core_keywords']['field'] = 'field_core_keywords';
  $handler->display->display_options['fields']['field_core_keywords']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_core_keywords']['delta_offset'] = '0';
  /* Field: Field: Agricultural sectors */
  $handler->display->display_options['fields']['field_core_agricultural_sectors']['id'] = 'field_core_agricultural_sectors';
  $handler->display->display_options['fields']['field_core_agricultural_sectors']['table'] = 'field_data_field_core_agricultural_sectors';
  $handler->display->display_options['fields']['field_core_agricultural_sectors']['field'] = 'field_core_agricultural_sectors';
  $handler->display->display_options['fields']['field_core_agricultural_sectors']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_core_agricultural_sectors']['delta_offset'] = '0';
  /* Field: Content: Name */
  $handler->display->display_options['fields']['field_projects_name']['id'] = 'field_projects_name';
  $handler->display->display_options['fields']['field_projects_name']['table'] = 'field_data_field_projects_name';
  $handler->display->display_options['fields']['field_projects_name']['field'] = 'field_projects_name';
  /* Field: Content: Surname */
  $handler->display->display_options['fields']['field_projects_surname']['id'] = 'field_projects_surname';
  $handler->display->display_options['fields']['field_projects_surname']['table'] = 'field_data_field_projects_surname';
  $handler->display->display_options['fields']['field_projects_surname']['field'] = 'field_projects_surname';
  /* Field: Field: Contact e-mail */
  $handler->display->display_options['fields']['field_core_email']['id'] = 'field_core_email';
  $handler->display->display_options['fields']['field_core_email']['table'] = 'field_data_field_core_email';
  $handler->display->display_options['fields']['field_core_email']['field'] = 'field_core_email';
  /* Field: Content: Interested in: */
  $handler->display->display_options['fields']['field_projects_interested_in']['id'] = 'field_projects_interested_in';
  $handler->display->display_options['fields']['field_projects_interested_in']['table'] = 'field_data_field_projects_interested_in';
  $handler->display->display_options['fields']['field_projects_interested_in']['field'] = 'field_projects_interested_in';
  $handler->display->display_options['fields']['field_projects_interested_in']['delta_offset'] = '0';
  /* Field: Content: Language */
  $handler->display->display_options['fields']['field_projects_language']['id'] = 'field_projects_language';
  $handler->display->display_options['fields']['field_projects_language']['table'] = 'field_data_field_projects_language';
  $handler->display->display_options['fields']['field_projects_language']['field'] = 'field_projects_language';
  /* Field: Field: Spoken languages */
  $handler->display->display_options['fields']['field_user_language_spoken']['id'] = 'field_user_language_spoken';
  $handler->display->display_options['fields']['field_user_language_spoken']['table'] = 'field_data_field_user_language_spoken';
  $handler->display->display_options['fields']['field_user_language_spoken']['field'] = 'field_user_language_spoken';
  $handler->display->display_options['fields']['field_user_language_spoken']['label'] = 'Other languages spoken';
  $handler->display->display_options['fields']['field_user_language_spoken']['delta_offset'] = '0';
  /* Field: Field: Additional information */
  $handler->display->display_options['fields']['field_core_additional_info']['id'] = 'field_core_additional_info';
  $handler->display->display_options['fields']['field_core_additional_info']['table'] = 'field_data_field_core_additional_info';
  $handler->display->display_options['fields']['field_core_additional_info']['field'] = 'field_core_additional_info';
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
    'needs_for_research_from_practice' => 'needs_for_research_from_practice',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['title']['group_info']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['group_info']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['title']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Field: Keywords (field_core_keywords) */
  $handler->display->display_options['filters']['field_core_keywords_tid']['id'] = 'field_core_keywords_tid';
  $handler->display->display_options['filters']['field_core_keywords_tid']['table'] = 'field_data_field_core_keywords';
  $handler->display->display_options['filters']['field_core_keywords_tid']['field'] = 'field_core_keywords_tid';
  $handler->display->display_options['filters']['field_core_keywords_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['operator_id'] = 'field_core_keywords_tid_op';
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['label'] = 'Keywords';
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['operator'] = 'field_core_keywords_tid_op';
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['identifier'] = 'field_core_keywords_tid';
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_core_keywords_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_core_keywords_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_core_keywords_tid']['vocabulary'] = 'tags';
  /* Filter criterion: Field: Geographical scope (field_core_geographical_area) (translated) */
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['id'] = 'field_core_geographical_area_tid_i18n';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['table'] = 'field_data_field_core_geographical_area';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['field'] = 'field_core_geographical_area_tid_i18n';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['expose']['operator_id'] = 'field_core_geographical_area_tid_i18n_op';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['expose']['label'] = 'Geographical scope';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['expose']['operator'] = 'field_core_geographical_area_tid_i18n_op';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['expose']['identifier'] = 'field_core_geographical_area_tid_i18n';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['type'] = 'select';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['vocabulary'] = 'core_geographical_area';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['hierarchy'] = 1;
  /* Filter criterion: Content: Language (field_projects_language) (translated) */
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['id'] = 'field_projects_language_value_i18n';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['table'] = 'field_data_field_projects_language';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['field'] = 'field_projects_language_value_i18n';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['expose']['operator_id'] = 'field_projects_language_value_i18n_op';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['expose']['operator'] = 'field_projects_language_value_i18n_op';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['expose']['identifier'] = 'field_projects_language_value_i18n';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['path'] = 'find-connect/needs-for-research/needs_for_research_export.csv';
  $handler->display->display_options['displays'] = array(
    'page_2' => 'page_2',
    'default' => 0,
    'page_1' => 0,
    'page_3' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'find-connect/needs-for-research';
  $handler->display->display_options['segment_size'] = '28';

  /* Display: Data export: Projects */
  $handler = $view->new_display('views_data_export', 'Data export: Projects', 'views_data_export_projects');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Data export: Projects';
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['attach_text'] = 'Export';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = '1';
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['style_options']['encoding'] = 'utf8_decode';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Published on';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'eip_agri_medium';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'eip_agri_long';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Project type */
  $handler->display->display_options['fields']['field_proj_project_type']['id'] = 'field_proj_project_type';
  $handler->display->display_options['fields']['field_proj_project_type']['table'] = 'field_data_field_proj_project_type';
  $handler->display->display_options['fields']['field_proj_project_type']['field'] = 'field_proj_project_type';
  $handler->display->display_options['fields']['field_proj_project_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_proj_project_type']['empty'] = '[type]';
  $handler->display->display_options['fields']['field_proj_project_type']['type'] = 'text_plain';
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
    'innovative_action' => 'innovative_action',
    'operational_group' => 'operational_group',
    'project' => 'project',
    'research_project' => 'research_project',
  );
  $handler->display->display_options['path'] = 'find-connect/projects/projects_export';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
    'page_2' => 0,
    'page_3' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Data export: Project ideas */
  $handler = $view->new_display('views_data_export', 'Data export: Project ideas', 'views_data_export_ideas');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Data export: Project ideas';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['attach_text'] = 'Export';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = '1';
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Published on';
  $handler->display->display_options['fields']['created']['date_format'] = 'eip_agri_medium';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'eip_agri_long';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Description in english */
  $handler->display->display_options['fields']['field_core_description_eng']['id'] = 'field_core_description_eng';
  $handler->display->display_options['fields']['field_core_description_eng']['table'] = 'field_data_field_core_description_eng';
  $handler->display->display_options['fields']['field_core_description_eng']['field'] = 'field_core_description_eng';
  /* Field: Content: Attachments */
  $handler->display->display_options['fields']['field_projects_publications']['id'] = 'field_projects_publications';
  $handler->display->display_options['fields']['field_projects_publications']['table'] = 'field_data_field_projects_publications';
  $handler->display->display_options['fields']['field_projects_publications']['field'] = 'field_projects_publications';
  $handler->display->display_options['fields']['field_projects_publications']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_projects_publications']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_projects_publications']['delta_offset'] = '0';
  /* Field: Content: Deadline for contact */
  $handler->display->display_options['fields']['field_projects_deadline']['id'] = 'field_projects_deadline';
  $handler->display->display_options['fields']['field_projects_deadline']['table'] = 'field_data_field_projects_deadline';
  $handler->display->display_options['fields']['field_projects_deadline']['field'] = 'field_projects_deadline';
  $handler->display->display_options['fields']['field_projects_deadline']['settings'] = array(
    'format_type' => 'eip_agri_long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Expected duration */
  $handler->display->display_options['fields']['field_projects_duration_months']['id'] = 'field_projects_duration_months';
  $handler->display->display_options['fields']['field_projects_duration_months']['table'] = 'field_data_field_projects_duration_months';
  $handler->display->display_options['fields']['field_projects_duration_months']['field'] = 'field_projects_duration_months';
  $handler->display->display_options['fields']['field_projects_duration_months']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Expected starting date of the project */
  $handler->display->display_options['fields']['field_projects_starting']['id'] = 'field_projects_starting';
  $handler->display->display_options['fields']['field_projects_starting']['table'] = 'field_data_field_projects_starting';
  $handler->display->display_options['fields']['field_projects_starting']['field'] = 'field_projects_starting';
  $handler->display->display_options['fields']['field_projects_starting']['settings'] = array(
    'format_type' => 'eip_agri_long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Language */
  $handler->display->display_options['fields']['field_projects_language']['id'] = 'field_projects_language';
  $handler->display->display_options['fields']['field_projects_language']['table'] = 'field_data_field_projects_language';
  $handler->display->display_options['fields']['field_projects_language']['field'] = 'field_projects_language';
  /* Field: Content: Practice oriented results (English) */
  $handler->display->display_options['fields']['field_projects_outcomes_eng']['id'] = 'field_projects_outcomes_eng';
  $handler->display->display_options['fields']['field_projects_outcomes_eng']['table'] = 'field_data_field_projects_outcomes_eng';
  $handler->display->display_options['fields']['field_projects_outcomes_eng']['field'] = 'field_projects_outcomes_eng';
  /* Field: Content: Practice oriented results (original language) */
  $handler->display->display_options['fields']['field_projects_outcomes']['id'] = 'field_projects_outcomes';
  $handler->display->display_options['fields']['field_projects_outcomes']['table'] = 'field_data_field_projects_outcomes';
  $handler->display->display_options['fields']['field_projects_outcomes']['field'] = 'field_projects_outcomes';
  /* Field: Content: Project coordinator is searching for… */
  $handler->display->display_options['fields']['field_project_searching']['id'] = 'field_project_searching';
  $handler->display->display_options['fields']['field_project_searching']['table'] = 'field_data_field_project_searching';
  $handler->display->display_options['fields']['field_project_searching']['field'] = 'field_project_searching';
  /* Field: Content: Proposing person or organization */
  $handler->display->display_options['fields']['field_project_partners']['id'] = 'field_project_partners';
  $handler->display->display_options['fields']['field_project_partners']['table'] = 'field_data_field_project_partners';
  $handler->display->display_options['fields']['field_project_partners']['field'] = 'field_project_partners';
  /* Field: Field: Additional information */
  $handler->display->display_options['fields']['field_core_additional_info']['id'] = 'field_core_additional_info';
  $handler->display->display_options['fields']['field_core_additional_info']['table'] = 'field_data_field_core_additional_info';
  $handler->display->display_options['fields']['field_core_additional_info']['field'] = 'field_core_additional_info';
  /* Field: Field: Agricultural sectors */
  $handler->display->display_options['fields']['field_core_agricultural_sectors']['id'] = 'field_core_agricultural_sectors';
  $handler->display->display_options['fields']['field_core_agricultural_sectors']['table'] = 'field_data_field_core_agricultural_sectors';
  $handler->display->display_options['fields']['field_core_agricultural_sectors']['field'] = 'field_core_agricultural_sectors';
  $handler->display->display_options['fields']['field_core_agricultural_sectors']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_core_agricultural_sectors']['delta_offset'] = '0';
  /* Field: Field: Contact e-mail */
  $handler->display->display_options['fields']['field_core_email']['id'] = 'field_core_email';
  $handler->display->display_options['fields']['field_core_email']['table'] = 'field_data_field_core_email';
  $handler->display->display_options['fields']['field_core_email']['field'] = 'field_core_email';
  /* Field: Field: Geographical scope */
  $handler->display->display_options['fields']['field_core_geographical_area']['id'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['table'] = 'field_data_field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['field'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_core_geographical_area']['delta_offset'] = '0';
  /* Field: Field: Specify other location */
  $handler->display->display_options['fields']['field_core_other_location']['id'] = 'field_core_other_location';
  $handler->display->display_options['fields']['field_core_other_location']['table'] = 'field_data_field_core_other_location';
  $handler->display->display_options['fields']['field_core_other_location']['field'] = 'field_core_other_location';
  /* Field: Field: Spoken languages */
  $handler->display->display_options['fields']['field_user_language_spoken']['id'] = 'field_user_language_spoken';
  $handler->display->display_options['fields']['field_user_language_spoken']['table'] = 'field_data_field_user_language_spoken';
  $handler->display->display_options['fields']['field_user_language_spoken']['field'] = 'field_user_language_spoken';
  $handler->display->display_options['fields']['field_user_language_spoken']['delta_offset'] = '0';
  /* Field: Field: Keywords */
  $handler->display->display_options['fields']['field_core_keywords']['id'] = 'field_core_keywords';
  $handler->display->display_options['fields']['field_core_keywords']['table'] = 'field_data_field_core_keywords';
  $handler->display->display_options['fields']['field_core_keywords']['field'] = 'field_core_keywords';
  $handler->display->display_options['fields']['field_core_keywords']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_core_keywords']['delta_offset'] = '0';
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
    'project_ideas' => 'project_ideas',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Field: Keywords (field_core_keywords) */
  $handler->display->display_options['filters']['field_core_keywords_tid_1']['id'] = 'field_core_keywords_tid_1';
  $handler->display->display_options['filters']['field_core_keywords_tid_1']['table'] = 'field_data_field_core_keywords';
  $handler->display->display_options['filters']['field_core_keywords_tid_1']['field'] = 'field_core_keywords_tid';
  $handler->display->display_options['filters']['field_core_keywords_tid_1']['group'] = 1;
  $handler->display->display_options['filters']['field_core_keywords_tid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_keywords_tid_1']['expose']['operator_id'] = 'field_core_keywords_tid_1_op';
  $handler->display->display_options['filters']['field_core_keywords_tid_1']['expose']['label'] = 'Keywords';
  $handler->display->display_options['filters']['field_core_keywords_tid_1']['expose']['operator'] = 'field_core_keywords_tid_1_op';
  $handler->display->display_options['filters']['field_core_keywords_tid_1']['expose']['identifier'] = 'field_core_keywords_tid';
  $handler->display->display_options['filters']['field_core_keywords_tid_1']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_core_keywords_tid_1']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_core_keywords_tid_1']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_core_keywords_tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['field_core_keywords_tid_1']['vocabulary'] = 'tags';
  /* Filter criterion: Field: Geographical scope (field_core_geographical_area) (translated) */
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['id'] = 'field_core_geographical_area_tid_i18n';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['table'] = 'field_data_field_core_geographical_area';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['field'] = 'field_core_geographical_area_tid_i18n';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['expose']['operator_id'] = 'field_core_geographical_area_tid_i18n_op';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['expose']['label'] = 'Geographical scope';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['expose']['operator'] = 'field_core_geographical_area_tid_i18n_op';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['expose']['identifier'] = 'field_core_geographical_area_tid_i18n';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['type'] = 'select';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['vocabulary'] = 'core_geographical_area';
  $handler->display->display_options['filters']['field_core_geographical_area_tid_i18n']['hierarchy'] = 1;
  /* Filter criterion: Content: Language (field_projects_language) (translated) */
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['id'] = 'field_projects_language_value_i18n';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['table'] = 'field_data_field_projects_language';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['field'] = 'field_projects_language_value_i18n';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['expose']['operator_id'] = 'field_projects_language_value_i18n_op';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['expose']['operator'] = 'field_projects_language_value_i18n_op';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['expose']['identifier'] = 'field_projects_language_value_i18n';
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_projects_language_value_i18n']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['path'] = 'find-connect/projects-ideas/projects_ideas_export.csv';
  $handler->display->display_options['displays'] = array(
    'page_3' => 'page_3',
    'default' => 0,
    'page_2' => 0,
    'page_1' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'find-connect/project-ideas';
  $handler->display->display_options['segment_size'] = '25';
  $export['projects_search_sub_pages'] = $view;

  return $export;
}
