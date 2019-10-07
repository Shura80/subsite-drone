<?php

/**
 * @file
 * agri_publications.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function agri_publications_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'publications_list';
  $view->description = '';
  $view->tag = 'AGRI Publications';
  $view->base_table = 'node';
  $view->human_name = 'publications_list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Publications';
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
    'publication' => 'publication',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'allwords';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => 0,
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
  /* Filter criterion: Content: Year of publication (field_publication_date) */
  $handler->display->display_options['filters']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['filters']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_publication_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_publication_date_value']['expose']['operator_id'] = 'field_publication_date_value_op';
  $handler->display->display_options['filters']['field_publication_date_value']['expose']['label'] = 'Year of publication';
  $handler->display->display_options['filters']['field_publication_date_value']['expose']['operator'] = 'field_publication_date_value_op';
  $handler->display->display_options['filters']['field_publication_date_value']['expose']['identifier'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_publication_date_value']['granularity'] = 'year';
  $handler->display->display_options['filters']['field_publication_date_value']['year_range'] = '-10:+5';
  /* Filter criterion: Content: Publication type (field_publication_type) (translated) */
  $handler->display->display_options['filters']['field_publication_type_tid_i18n']['id'] = 'field_publication_type_tid_i18n';
  $handler->display->display_options['filters']['field_publication_type_tid_i18n']['table'] = 'field_data_field_publication_type';
  $handler->display->display_options['filters']['field_publication_type_tid_i18n']['field'] = 'field_publication_type_tid_i18n';
  $handler->display->display_options['filters']['field_publication_type_tid_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_publication_type_tid_i18n']['expose']['operator_id'] = 'field_publication_type_tid_i18n_op';
  $handler->display->display_options['filters']['field_publication_type_tid_i18n']['expose']['label'] = 'Publication type';
  $handler->display->display_options['filters']['field_publication_type_tid_i18n']['expose']['operator'] = 'field_publication_type_tid_i18n_op';
  $handler->display->display_options['filters']['field_publication_type_tid_i18n']['expose']['identifier'] = 'field_publication_type_tid_i18n';
  $handler->display->display_options['filters']['field_publication_type_tid_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_publication_type_tid_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_publication_type_tid_i18n']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_publication_type_tid_i18n']['type'] = 'select';
  $handler->display->display_options['filters']['field_publication_type_tid_i18n']['vocabulary'] = 'publication_type';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['path'] = 'disabled/publications';
  $handler->display->display_options['menu']['title'] = 'Reports & Publications';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['publications_list'] = $view;

  $view = new view();
  $view->name = 'publications_search';
  $view->description = '';
  $view->tag = 'AGRI Publications, AGRI Digitisation Toolbox';
  $view->base_table = 'search_api_index_core_node_index';
  $view->human_name = 'Publications search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Publications';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Field: Indexed Content: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Sort criterion: Indexed Content: Year of publication */
  $handler->display->display_options['sorts']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['sorts']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date']['order'] = 'DESC';
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
    8 => 0,
    9 => 0,
    6 => 0,
  );
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'publication' => 'publication',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
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
    8 => 0,
    9 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'body:value' => 'body:value',
    'title' => 'title',
  );
  /* Filter criterion: Indexed Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'publications';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Publications';
  $handler->display->display_options['menu']['weight'] = '-43';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Digitisation - Publications */
  $handler = $view->new_display('page', 'Digitisation - Publications', 'publications_list');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Digitising Agriculture Publications';
  $handler->display->display_options['display_description'] = 'Published Publications flagged by Digitisation.';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No Digitisation Publications available.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    8 => 0,
    9 => 0,
    6 => 0,
  );
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'publication' => 'publication',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
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
    8 => 0,
    9 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'body:value' => 'body:value',
    'title' => 'title',
  );
  /* Filter criterion: Indexed Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Indexed Content: Whether the entity is flagged with flag agri_digitization_toolbox */
  $handler->display->display_options['filters']['flag_agri_digitization_toolbox']['id'] = 'flag_agri_digitization_toolbox';
  $handler->display->display_options['filters']['flag_agri_digitization_toolbox']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['flag_agri_digitization_toolbox']['field'] = 'flag_agri_digitization_toolbox';
  $handler->display->display_options['filters']['flag_agri_digitization_toolbox']['value'] = '1';
  $handler->display->display_options['path'] = 'digitising-agriculture/publications';
  $handler->display->display_options['menu']['title'] = 'Publications';
  $handler->display->display_options['menu']['weight'] = '15';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Digitization Toolbox - Publications */
  $handler = $view->new_display('block', 'Digitization Toolbox - Publications', 'digitization_publications_filtered');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Publications';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '5';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_table_plugin_style';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_publication_date' => 'field_publication_date',
    'field_publication_type' => 'field_publication_type',
    'title' => 'title',
    'field_core_keywords' => 'field_core_keywords',
    'field_core_geographical_area' => 'field_core_geographical_area',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_publication_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_publication_type' => array(
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
    'field_core_keywords' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_core_geographical_area' => array(
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Content: Year of publication */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'eip_agri_short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Indexed Content: Publication type */
  $handler->display->display_options['fields']['field_publication_type']['id'] = 'field_publication_type';
  $handler->display->display_options['fields']['field_publication_type']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_publication_type']['field'] = 'field_publication_type';
  $handler->display->display_options['fields']['field_publication_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_publication_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_publication_type']['bypass_access'] = 0;
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Content: Geographical scope */
  $handler->display->display_options['fields']['field_core_geographical_area']['id'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_core_geographical_area']['field'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['label'] = 'Country';
  $handler->display->display_options['fields']['field_core_geographical_area']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_core_geographical_area']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_core_geographical_area']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_core_geographical_area']['bypass_access'] = 0;
  /* Field: Indexed Content: Keywords */
  $handler->display->display_options['fields']['field_core_keywords']['id'] = 'field_core_keywords';
  $handler->display->display_options['fields']['field_core_keywords']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_core_keywords']['field'] = 'field_core_keywords';
  $handler->display->display_options['fields']['field_core_keywords']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_core_keywords']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_core_keywords']['bypass_access'] = 0;
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
    'publication' => 'publication',
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
  /* Filter criterion: Indexed Content: Geographical scope */
  $handler->display->display_options['filters']['field_core_geographical_area']['id'] = 'field_core_geographical_area';
  $handler->display->display_options['filters']['field_core_geographical_area']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_core_geographical_area']['field'] = 'field_core_geographical_area';
  $handler->display->display_options['filters']['field_core_geographical_area']['value'] = array();
  $handler->display->display_options['filters']['field_core_geographical_area']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_geographical_area']['expose']['operator_id'] = 'field_core_geographical_area_op';
  $handler->display->display_options['filters']['field_core_geographical_area']['expose']['label'] = 'Filter by country';
  $handler->display->display_options['filters']['field_core_geographical_area']['expose']['operator'] = 'field_core_geographical_area_op';
  $handler->display->display_options['filters']['field_core_geographical_area']['expose']['identifier'] = 'country';
  $handler->display->display_options['filters']['field_core_geographical_area']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_core_geographical_area']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_core_geographical_area']['expose']['reduce'] = 0;
  $handler->display->display_options['block_description'] = 'AGRI Digitisation Toolbox - Publications keywords filtered';

  /* Display: Digitization Toolbox - Publications landing block */
  $handler = $view->new_display('block', 'Digitization Toolbox - Publications landing block', 'digitization_toolbox_publications_landing');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'New Digitisation Publications';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'digitization-toolbox publications';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'View more';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'publications_list';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '7';
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
  /* Field: Indexed Content: Publication type */
  $handler->display->display_options['fields']['field_publication_type']['id'] = 'field_publication_type';
  $handler->display->display_options['fields']['field_publication_type']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_publication_type']['field'] = 'field_publication_type';
  $handler->display->display_options['fields']['field_publication_type']['label'] = '';
  $handler->display->display_options['fields']['field_publication_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_publication_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_publication_type']['bypass_access'] = 0;
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
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
    'publication' => 'publication',
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
  /* Filter criterion: Indexed Content: Geographical scope */
  $handler->display->display_options['filters']['field_core_geographical_area']['id'] = 'field_core_geographical_area';
  $handler->display->display_options['filters']['field_core_geographical_area']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_core_geographical_area']['field'] = 'field_core_geographical_area';
  $handler->display->display_options['filters']['field_core_geographical_area']['value'] = array();
  $handler->display->display_options['filters']['field_core_geographical_area']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_geographical_area']['expose']['operator_id'] = 'field_core_geographical_area_op';
  $handler->display->display_options['filters']['field_core_geographical_area']['expose']['label'] = 'Filter by country';
  $handler->display->display_options['filters']['field_core_geographical_area']['expose']['operator'] = 'field_core_geographical_area_op';
  $handler->display->display_options['filters']['field_core_geographical_area']['expose']['identifier'] = 'country';
  $handler->display->display_options['filters']['field_core_geographical_area']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_core_geographical_area']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_core_geographical_area']['expose']['reduce'] = 0;
  $handler->display->display_options['block_description'] = 'AGRI Digitisation Toolbox - Publications landing';
  $export['publications_search'] = $view;

  return $export;
}
