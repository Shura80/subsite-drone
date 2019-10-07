<?php

/**
 * @file
 * agri_news.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function agri_news_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'agri_archived_funding_opportunities';
  $view->description = 'Shows archived funding opportunities.';
  $view->tag = 'AGRI News';
  $view->base_table = 'node';
  $view->human_name = 'AGRI Archived Funding Opportunities';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Second Exposed Filters';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view all unpublished content';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
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
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['relationship'] = 'nid';
  $handler->display->display_options['filters']['state']['value'] = array(
    'archived' => 'archived',
  );
  $handler->display->display_options['filters']['state']['group'] = 1;
  /* Filter criterion: Content: Geographical scope (field_news_geographical_area) */
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['id'] = 'field_news_geographical_area_tid';
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['table'] = 'field_data_field_news_geographical_area';
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['field'] = 'field_news_geographical_area_tid';
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['expose']['operator_id'] = 'field_news_geographical_area_tid_op';
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['expose']['label'] = 'Geographical scope';
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['expose']['operator'] = 'field_news_geographical_area_tid_op';
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['expose']['identifier'] = 'field_news_geographical_area_tid';
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['vocabulary'] = 'core_geographical_area';
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['hierarchy'] = 1;
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'funding_opportunities' => 'funding_opportunities',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Target group (field_news_target_group) */
  $handler->display->display_options['filters']['field_news_target_group_tid']['id'] = 'field_news_target_group_tid';
  $handler->display->display_options['filters']['field_news_target_group_tid']['table'] = 'field_data_field_news_target_group';
  $handler->display->display_options['filters']['field_news_target_group_tid']['field'] = 'field_news_target_group_tid';
  $handler->display->display_options['filters']['field_news_target_group_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_news_target_group_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_news_target_group_tid']['expose']['operator_id'] = 'field_news_target_group_tid_op';
  $handler->display->display_options['filters']['field_news_target_group_tid']['expose']['label'] = 'Target group';
  $handler->display->display_options['filters']['field_news_target_group_tid']['expose']['operator'] = 'field_news_target_group_tid_op';
  $handler->display->display_options['filters']['field_news_target_group_tid']['expose']['identifier'] = 'field_news_target_group_tid';
  $handler->display->display_options['filters']['field_news_target_group_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_news_target_group_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_news_target_group_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_news_target_group_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_news_target_group_tid']['vocabulary'] = 'core_user_type';
  $handler->display->display_options['filters']['field_news_target_group_tid']['hierarchy'] = 1;
  $handler->display->display_options['filters']['field_news_target_group_tid']['error_message'] = FALSE;
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
    10 => 0,
    8 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['field_core_keywords_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_core_keywords_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_core_keywords_tid']['vocabulary'] = 'tags';
  $handler->display->display_options['filters']['field_core_keywords_tid']['hierarchy'] = 1;
  $handler->display->display_options['filters']['field_core_keywords_tid']['error_message'] = FALSE;
  /* Filter criterion: Workbench Moderation: Current */
  $handler->display->display_options['filters']['is_current']['id'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['relationship'] = 'nid';
  $handler->display->display_options['filters']['is_current']['value'] = '1';
  $handler->display->display_options['filters']['is_current']['group'] = 1;

  /* Display: AGRI Archived Funding Opportunities */
  $handler = $view->new_display('page', 'AGRI Archived Funding Opportunities', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Archived Funding Opportunities';
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['display_description'] = 'Shows archived funding opportunities';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Publication date -  start date (field_core_publication_date) */
  $handler->display->display_options['sorts']['field_core_publication_date_value']['id'] = 'field_core_publication_date_value';
  $handler->display->display_options['sorts']['field_core_publication_date_value']['table'] = 'field_data_field_core_publication_date';
  $handler->display->display_options['sorts']['field_core_publication_date_value']['field'] = 'field_core_publication_date_value';
  $handler->display->display_options['sorts']['field_core_publication_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Publication date -  start date (field_core_publication_date) */
  $handler->display->display_options['arguments']['field_core_publication_date_value']['id'] = 'field_core_publication_date_value';
  $handler->display->display_options['arguments']['field_core_publication_date_value']['table'] = 'field_data_field_core_publication_date';
  $handler->display->display_options['arguments']['field_core_publication_date_value']['field'] = 'field_core_publication_date_value';
  $handler->display->display_options['arguments']['field_core_publication_date_value']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['field_core_publication_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_core_publication_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_core_publication_date_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_core_publication_date_value']['granularity'] = 'year';
  $handler->display->display_options['arguments']['field_core_publication_date_value']['use_fromto'] = 'no';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Workbench Moderation: Current */
  $handler->display->display_options['filters']['is_current']['id'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['relationship'] = 'nid';
  $handler->display->display_options['filters']['is_current']['value'] = '1';
  $handler->display->display_options['filters']['is_current']['group'] = 1;
  /* Filter criterion: Content: Geographical scope (field_news_geographical_area) */
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['id'] = 'field_news_geographical_area_tid';
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['table'] = 'field_data_field_news_geographical_area';
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['field'] = 'field_news_geographical_area_tid';
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['expose']['operator_id'] = 'field_news_geographical_area_tid_op';
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['expose']['label'] = 'Geographical scope';
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['expose']['operator'] = 'field_news_geographical_area_tid_op';
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['expose']['identifier'] = 'field_news_geographical_area_tid';
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['vocabulary'] = 'core_geographical_area';
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['hierarchy'] = 1;
  $handler->display->display_options['filters']['field_news_geographical_area_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'funding_opportunities' => 'funding_opportunities',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Target group (field_news_target_group) */
  $handler->display->display_options['filters']['field_news_target_group_tid']['id'] = 'field_news_target_group_tid';
  $handler->display->display_options['filters']['field_news_target_group_tid']['table'] = 'field_data_field_news_target_group';
  $handler->display->display_options['filters']['field_news_target_group_tid']['field'] = 'field_news_target_group_tid';
  $handler->display->display_options['filters']['field_news_target_group_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_news_target_group_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_news_target_group_tid']['expose']['operator_id'] = 'field_news_target_group_tid_op';
  $handler->display->display_options['filters']['field_news_target_group_tid']['expose']['label'] = 'Target group';
  $handler->display->display_options['filters']['field_news_target_group_tid']['expose']['operator'] = 'field_news_target_group_tid_op';
  $handler->display->display_options['filters']['field_news_target_group_tid']['expose']['identifier'] = 'field_news_target_group_tid';
  $handler->display->display_options['filters']['field_news_target_group_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_news_target_group_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_news_target_group_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_news_target_group_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_news_target_group_tid']['vocabulary'] = 'core_user_type';
  $handler->display->display_options['filters']['field_news_target_group_tid']['hierarchy'] = 1;
  $handler->display->display_options['filters']['field_news_target_group_tid']['error_message'] = FALSE;
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
    10 => 0,
    8 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['field_core_keywords_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_core_keywords_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_core_keywords_tid']['vocabulary'] = 'tags';
  $handler->display->display_options['filters']['field_core_keywords_tid']['hierarchy'] = 1;
  $handler->display->display_options['filters']['field_core_keywords_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Publication date - end date (field_core_publication_date:value2) */
  $handler->display->display_options['filters']['field_core_publication_date_value2']['id'] = 'field_core_publication_date_value2';
  $handler->display->display_options['filters']['field_core_publication_date_value2']['table'] = 'field_data_field_core_publication_date';
  $handler->display->display_options['filters']['field_core_publication_date_value2']['field'] = 'field_core_publication_date_value2';
  $handler->display->display_options['filters']['field_core_publication_date_value2']['operator'] = '<';
  $handler->display->display_options['filters']['field_core_publication_date_value2']['group'] = 1;
  $handler->display->display_options['filters']['field_core_publication_date_value2']['default_date'] = 'today';
  $handler->display->display_options['path'] = 'find-connect/funding-opportunities/archived';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Archived';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Archive links block */
  $handler = $view->new_display('block', 'Archive links block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Filter by publication year';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'fo-archive';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Publication date -  start date (field_core_publication_date) */
  $handler->display->display_options['arguments']['field_core_publication_date_value']['id'] = 'field_core_publication_date_value';
  $handler->display->display_options['arguments']['field_core_publication_date_value']['table'] = 'field_data_field_core_publication_date';
  $handler->display->display_options['arguments']['field_core_publication_date_value']['field'] = 'field_core_publication_date_value';
  $handler->display->display_options['arguments']['field_core_publication_date_value']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['field_core_publication_date_value']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['field_core_publication_date_value']['summary']['sort_order'] = 'desc';
  $handler->display->display_options['arguments']['field_core_publication_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_core_publication_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_core_publication_date_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_core_publication_date_value']['granularity'] = 'year';
  $handler->display->display_options['arguments']['field_core_publication_date_value']['granularity_reset'] = 0;
  $handler->display->display_options['arguments']['field_core_publication_date_value']['use_fromto'] = 'no';
  $handler->display->display_options['arguments']['field_core_publication_date_value']['title_format'] = 'custom';
  $handler->display->display_options['arguments']['field_core_publication_date_value']['title_format_custom'] = 'Y';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Workbench Moderation: Current */
  $handler->display->display_options['filters']['is_current']['id'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['relationship'] = 'nid';
  $handler->display->display_options['filters']['is_current']['value'] = '1';
  $handler->display->display_options['filters']['is_current']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'funding_opportunities' => 'funding_opportunities',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Publication date - end date (field_core_publication_date:value2) */
  $handler->display->display_options['filters']['field_core_publication_date_value2']['id'] = 'field_core_publication_date_value2';
  $handler->display->display_options['filters']['field_core_publication_date_value2']['table'] = 'field_data_field_core_publication_date';
  $handler->display->display_options['filters']['field_core_publication_date_value2']['field'] = 'field_core_publication_date_value2';
  $handler->display->display_options['filters']['field_core_publication_date_value2']['operator'] = '<';
  $handler->display->display_options['filters']['field_core_publication_date_value2']['group'] = 1;
  $handler->display->display_options['filters']['field_core_publication_date_value2']['default_date'] = 'today';
  $export['agri_archived_funding_opportunities'] = $view;

  $view = new view();
  $view->name = 'news_blocks';
  $view->description = '';
  $view->tag = 'AGRI News';
  $view->base_table = 'node';
  $view->human_name = 'News Blocks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Latest News';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['view_mode'] = 'core_small_teaser';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'node|created';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'core_small_teaser';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Publication date (field_news_publication_date) */
  $handler->display->display_options['sorts']['field_news_publication_date_value']['id'] = 'field_news_publication_date_value';
  $handler->display->display_options['sorts']['field_news_publication_date_value']['table'] = 'field_data_field_news_publication_date';
  $handler->display->display_options['sorts']['field_news_publication_date_value']['field'] = 'field_news_publication_date_value';
  $handler->display->display_options['sorts']['field_news_publication_date_value']['order'] = 'DESC';
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
    'news' => 'news',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['news_blocks'] = $view;

  $view = new view();
  $view->name = 'news_funding_opportunities_list';
  $view->description = '';
  $view->tag = 'AGRI News';
  $view->base_table = 'node';
  $view->human_name = 'news funding opportunities list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Latest funding opportunities ';
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
    'funding_opportunities' => 'funding_opportunities',
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
    7 => 0,
    8 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_core_keywords_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_core_keywords_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_core_keywords_tid']['vocabulary'] = 'tags';
  $handler->display->display_options['filters']['field_core_keywords_tid']['hierarchy'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'disabled/find-connect/funding-opportunities';
  $handler->display->display_options['menu']['title'] = 'Funding Opportunities';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['news_funding_opportunities_list'] = $view;

  $view = new view();
  $view->name = 'news_funding_opportunities_search';
  $view->description = '';
  $view->tag = 'AGRI News';
  $view->base_table = 'search_api_index_core_node_index';
  $view->human_name = 'News Funding Opportunities Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Funding Opportunities';
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
  /* Sort criterion: Date: Start date (indexed) */
  $handler->display->display_options['sorts']['field_core_publication_date_value']['id'] = 'field_core_publication_date_value';
  $handler->display->display_options['sorts']['field_core_publication_date_value']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['sorts']['field_core_publication_date_value']['field'] = 'field_core_publication_date_value';
  $handler->display->display_options['sorts']['field_core_publication_date_value']['order'] = 'DESC';
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'funding_opportunities' => 'funding_opportunities',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Content: Target group */
  $handler->display->display_options['filters']['field_news_target_group']['id'] = 'field_news_target_group';
  $handler->display->display_options['filters']['field_news_target_group']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_news_target_group']['field'] = 'field_news_target_group';
  $handler->display->display_options['filters']['field_news_target_group']['value'] = array();
  $handler->display->display_options['filters']['field_news_target_group']['group'] = 1;
  $handler->display->display_options['filters']['field_news_target_group']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_news_target_group']['expose']['operator_id'] = 'field_news_target_group_op';
  $handler->display->display_options['filters']['field_news_target_group']['expose']['label'] = 'Target group';
  $handler->display->display_options['filters']['field_news_target_group']['expose']['operator'] = 'field_news_target_group_op';
  $handler->display->display_options['filters']['field_news_target_group']['expose']['identifier'] = 'field_news_target_group';
  $handler->display->display_options['filters']['field_news_target_group']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_news_target_group']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_news_target_group']['expose']['reduce'] = 0;
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
    8 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Content: Geographical scope */
  $handler->display->display_options['filters']['field_news_geographical_area']['id'] = 'field_news_geographical_area';
  $handler->display->display_options['filters']['field_news_geographical_area']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_news_geographical_area']['field'] = 'field_news_geographical_area';
  $handler->display->display_options['filters']['field_news_geographical_area']['value'] = array();
  $handler->display->display_options['filters']['field_news_geographical_area']['group'] = 1;
  $handler->display->display_options['filters']['field_news_geographical_area']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_news_geographical_area']['expose']['operator_id'] = 'field_news_geographical_area_op';
  $handler->display->display_options['filters']['field_news_geographical_area']['expose']['label'] = 'Geographical scope';
  $handler->display->display_options['filters']['field_news_geographical_area']['expose']['operator'] = 'field_news_geographical_area_op';
  $handler->display->display_options['filters']['field_news_geographical_area']['expose']['identifier'] = 'field_news_geographical_area';
  $handler->display->display_options['filters']['field_news_geographical_area']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_news_geographical_area']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_news_geographical_area']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Content: Type of funding */
  $handler->display->display_options['filters']['field_news_type_of_funding']['id'] = 'field_news_type_of_funding';
  $handler->display->display_options['filters']['field_news_type_of_funding']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_news_type_of_funding']['field'] = 'field_news_type_of_funding';
  $handler->display->display_options['filters']['field_news_type_of_funding']['value'] = array();
  $handler->display->display_options['filters']['field_news_type_of_funding']['group'] = 1;
  $handler->display->display_options['filters']['field_news_type_of_funding']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_news_type_of_funding']['expose']['operator_id'] = 'field_news_type_of_funding_op';
  $handler->display->display_options['filters']['field_news_type_of_funding']['expose']['label'] = 'Type of funding';
  $handler->display->display_options['filters']['field_news_type_of_funding']['expose']['operator'] = 'field_news_type_of_funding_op';
  $handler->display->display_options['filters']['field_news_type_of_funding']['expose']['identifier'] = 'field_news_type_of_funding';
  $handler->display->display_options['filters']['field_news_type_of_funding']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_news_type_of_funding']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_news_type_of_funding']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_news_type_of_funding']['expose']['reduce'] = 0;
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

  /* Display: Main Page */
  $handler = $view->new_display('page', 'Main Page', 'page_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'funding_opportunities' => 'funding_opportunities',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Content: Target group */
  $handler->display->display_options['filters']['field_news_target_group']['id'] = 'field_news_target_group';
  $handler->display->display_options['filters']['field_news_target_group']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_news_target_group']['field'] = 'field_news_target_group';
  $handler->display->display_options['filters']['field_news_target_group']['value'] = array();
  $handler->display->display_options['filters']['field_news_target_group']['group'] = 1;
  $handler->display->display_options['filters']['field_news_target_group']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_news_target_group']['expose']['operator_id'] = 'field_news_target_group_op';
  $handler->display->display_options['filters']['field_news_target_group']['expose']['label'] = 'Target group';
  $handler->display->display_options['filters']['field_news_target_group']['expose']['operator'] = 'field_news_target_group_op';
  $handler->display->display_options['filters']['field_news_target_group']['expose']['identifier'] = 'field_news_target_group';
  $handler->display->display_options['filters']['field_news_target_group']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_news_target_group']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_news_target_group']['expose']['reduce'] = 0;
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
    8 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['field_core_agricultural_sectors']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Content: Geographical scope */
  $handler->display->display_options['filters']['field_news_geographical_area']['id'] = 'field_news_geographical_area';
  $handler->display->display_options['filters']['field_news_geographical_area']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_news_geographical_area']['field'] = 'field_news_geographical_area';
  $handler->display->display_options['filters']['field_news_geographical_area']['value'] = array();
  $handler->display->display_options['filters']['field_news_geographical_area']['group'] = 1;
  $handler->display->display_options['filters']['field_news_geographical_area']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_news_geographical_area']['expose']['operator_id'] = 'field_news_geographical_area_op';
  $handler->display->display_options['filters']['field_news_geographical_area']['expose']['label'] = 'Geographical scope';
  $handler->display->display_options['filters']['field_news_geographical_area']['expose']['operator'] = 'field_news_geographical_area_op';
  $handler->display->display_options['filters']['field_news_geographical_area']['expose']['identifier'] = 'field_news_geographical_area';
  $handler->display->display_options['filters']['field_news_geographical_area']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_news_geographical_area']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_news_geographical_area']['expose']['reduce'] = 0;
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
    2 => 0,
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
  $handler->display->display_options['filters']['field_core_keywords']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Content: Type of funding */
  $handler->display->display_options['filters']['field_news_type_of_funding']['id'] = 'field_news_type_of_funding';
  $handler->display->display_options['filters']['field_news_type_of_funding']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_news_type_of_funding']['field'] = 'field_news_type_of_funding';
  $handler->display->display_options['filters']['field_news_type_of_funding']['value'] = array();
  $handler->display->display_options['filters']['field_news_type_of_funding']['group'] = 1;
  $handler->display->display_options['filters']['field_news_type_of_funding']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_news_type_of_funding']['expose']['operator_id'] = 'field_news_type_of_funding_op';
  $handler->display->display_options['filters']['field_news_type_of_funding']['expose']['label'] = 'Type of funding';
  $handler->display->display_options['filters']['field_news_type_of_funding']['expose']['operator'] = 'field_news_type_of_funding_op';
  $handler->display->display_options['filters']['field_news_type_of_funding']['expose']['identifier'] = 'field_news_type_of_funding';
  $handler->display->display_options['filters']['field_news_type_of_funding']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_news_type_of_funding']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_news_type_of_funding']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_news_type_of_funding']['expose']['reduce'] = 0;
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
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Date: End date (indexed) */
  $handler->display->display_options['filters']['field_core_publication_date_value2']['id'] = 'field_core_publication_date_value2';
  $handler->display->display_options['filters']['field_core_publication_date_value2']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_core_publication_date_value2']['field'] = 'field_core_publication_date_value2';
  $handler->display->display_options['filters']['field_core_publication_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_core_publication_date_value2']['value'] = 'today';
  $handler->display->display_options['path'] = 'find-connect/funding-opportunities';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Funding';
  $handler->display->display_options['menu']['weight'] = '-49';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Active */
  $handler = $view->new_display('page', 'Active', 'page');
  $handler->display->display_options['display_description'] = 'Shows active funding opportunities';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'funding_opportunities' => 'funding_opportunities',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Content: Target group */
  $handler->display->display_options['filters']['field_news_target_group']['id'] = 'field_news_target_group';
  $handler->display->display_options['filters']['field_news_target_group']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_news_target_group']['field'] = 'field_news_target_group';
  $handler->display->display_options['filters']['field_news_target_group']['value'] = array();
  $handler->display->display_options['filters']['field_news_target_group']['group'] = 1;
  $handler->display->display_options['filters']['field_news_target_group']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_news_target_group']['expose']['operator_id'] = 'field_news_target_group_op';
  $handler->display->display_options['filters']['field_news_target_group']['expose']['label'] = 'Target group';
  $handler->display->display_options['filters']['field_news_target_group']['expose']['operator'] = 'field_news_target_group_op';
  $handler->display->display_options['filters']['field_news_target_group']['expose']['identifier'] = 'field_news_target_group';
  $handler->display->display_options['filters']['field_news_target_group']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_news_target_group']['expose']['remember_roles'] = array(
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
    8 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
  );
  /* Filter criterion: Indexed Content: Geographical scope */
  $handler->display->display_options['filters']['field_news_geographical_area']['id'] = 'field_news_geographical_area';
  $handler->display->display_options['filters']['field_news_geographical_area']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_news_geographical_area']['field'] = 'field_news_geographical_area';
  $handler->display->display_options['filters']['field_news_geographical_area']['value'] = array();
  $handler->display->display_options['filters']['field_news_geographical_area']['group'] = 1;
  $handler->display->display_options['filters']['field_news_geographical_area']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_news_geographical_area']['expose']['operator_id'] = 'field_news_geographical_area_op';
  $handler->display->display_options['filters']['field_news_geographical_area']['expose']['label'] = 'Geographical scope';
  $handler->display->display_options['filters']['field_news_geographical_area']['expose']['operator'] = 'field_news_geographical_area_op';
  $handler->display->display_options['filters']['field_news_geographical_area']['expose']['identifier'] = 'field_news_geographical_area';
  $handler->display->display_options['filters']['field_news_geographical_area']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_news_geographical_area']['expose']['remember_roles'] = array(
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
    2 => 0,
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
  /* Filter criterion: Indexed Content: Type of funding */
  $handler->display->display_options['filters']['field_news_type_of_funding']['id'] = 'field_news_type_of_funding';
  $handler->display->display_options['filters']['field_news_type_of_funding']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_news_type_of_funding']['field'] = 'field_news_type_of_funding';
  $handler->display->display_options['filters']['field_news_type_of_funding']['value'] = array();
  $handler->display->display_options['filters']['field_news_type_of_funding']['group'] = 1;
  $handler->display->display_options['filters']['field_news_type_of_funding']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_news_type_of_funding']['expose']['operator_id'] = 'field_news_type_of_funding_op';
  $handler->display->display_options['filters']['field_news_type_of_funding']['expose']['label'] = 'Type of funding';
  $handler->display->display_options['filters']['field_news_type_of_funding']['expose']['operator'] = 'field_news_type_of_funding_op';
  $handler->display->display_options['filters']['field_news_type_of_funding']['expose']['identifier'] = 'field_news_type_of_funding';
  $handler->display->display_options['filters']['field_news_type_of_funding']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_news_type_of_funding']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_news_type_of_funding']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Date: End date (indexed) */
  $handler->display->display_options['filters']['field_core_publication_date_value2']['id'] = 'field_core_publication_date_value2';
  $handler->display->display_options['filters']['field_core_publication_date_value2']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_core_publication_date_value2']['field'] = 'field_core_publication_date_value2';
  $handler->display->display_options['filters']['field_core_publication_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_core_publication_date_value2']['value'] = 'today';
  $handler->display->display_options['filters']['field_core_publication_date_value2']['group'] = 1;
  $handler->display->display_options['path'] = 'find-connect/funding-opportunities/active';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Active';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Archived */
  $handler = $view->new_display('page', 'Archived', 'archived');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Archived Funding Opportunities';
  $handler->display->display_options['display_description'] = 'Shows archived funding opportunities';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Date: End date (indexed) */
  $handler->display->display_options['sorts']['field_core_publication_date_value2']['id'] = 'field_core_publication_date_value2';
  $handler->display->display_options['sorts']['field_core_publication_date_value2']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['sorts']['field_core_publication_date_value2']['field'] = 'field_core_publication_date_value2';
  $handler->display->display_options['sorts']['field_core_publication_date_value2']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'funding_opportunities' => 'funding_opportunities',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Content: Geographical scope */
  $handler->display->display_options['filters']['field_news_geographical_area']['id'] = 'field_news_geographical_area';
  $handler->display->display_options['filters']['field_news_geographical_area']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_news_geographical_area']['field'] = 'field_news_geographical_area';
  $handler->display->display_options['filters']['field_news_geographical_area']['value'] = array();
  $handler->display->display_options['filters']['field_news_geographical_area']['group'] = 1;
  $handler->display->display_options['filters']['field_news_geographical_area']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_news_geographical_area']['expose']['operator_id'] = 'field_news_geographical_area_op';
  $handler->display->display_options['filters']['field_news_geographical_area']['expose']['label'] = 'Geographical scope';
  $handler->display->display_options['filters']['field_news_geographical_area']['expose']['operator'] = 'field_news_geographical_area_op';
  $handler->display->display_options['filters']['field_news_geographical_area']['expose']['identifier'] = 'field_news_geographical_area';
  $handler->display->display_options['filters']['field_news_geographical_area']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_news_geographical_area']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Indexed Content: Target group */
  $handler->display->display_options['filters']['field_news_target_group']['id'] = 'field_news_target_group';
  $handler->display->display_options['filters']['field_news_target_group']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_news_target_group']['field'] = 'field_news_target_group';
  $handler->display->display_options['filters']['field_news_target_group']['value'] = array();
  $handler->display->display_options['filters']['field_news_target_group']['group'] = 1;
  $handler->display->display_options['filters']['field_news_target_group']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_news_target_group']['expose']['operator_id'] = 'field_news_target_group_op';
  $handler->display->display_options['filters']['field_news_target_group']['expose']['label'] = 'Target group';
  $handler->display->display_options['filters']['field_news_target_group']['expose']['operator'] = 'field_news_target_group_op';
  $handler->display->display_options['filters']['field_news_target_group']['expose']['identifier'] = 'field_news_target_group';
  $handler->display->display_options['filters']['field_news_target_group']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_news_target_group']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Indexed Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['path'] = 'find-connect/funding-opportunities/archived';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Archived';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['news_funding_opportunities_search'] = $view;

  $view = new view();
  $view->name = 'news_list';
  $view->description = '';
  $view->tag = 'AGRI News';
  $view->base_table = 'node';
  $view->human_name = 'News list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Latest news';
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
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'node|created';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'teaser';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Publication date (field_news_publication_date) */
  $handler->display->display_options['sorts']['field_news_publication_date_value']['id'] = 'field_news_publication_date_value';
  $handler->display->display_options['sorts']['field_news_publication_date_value']['table'] = 'field_data_field_news_publication_date';
  $handler->display->display_options['sorts']['field_news_publication_date_value']['field'] = 'field_news_publication_date_value';
  $handler->display->display_options['sorts']['field_news_publication_date_value']['order'] = 'DESC';
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
    'news' => 'news',
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'news-events/news';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Search news';
  $handler->display->display_options['menu']['weight'] = '-50';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Digitization - News keywords filtered */
  $handler = $view->new_display('block', 'Digitization - News keywords filtered', 'digitization_news_filtered');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_table_plugin_style';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_news_publication_date' => 'field_news_publication_date',
    'title' => 'title',
    'field_core_geographical_area' => 'field_core_geographical_area',
    'field_core_keywords' => 'field_core_keywords',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_news_publication_date' => array(
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
    'field_core_geographical_area' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_core_keywords' => array(
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
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: agri_digitization_toolbox */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'flag_digitization_toolbox';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'agri_digitization_toolbox';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Publication date */
  $handler->display->display_options['fields']['field_news_publication_date']['id'] = 'field_news_publication_date';
  $handler->display->display_options['fields']['field_news_publication_date']['table'] = 'field_data_field_news_publication_date';
  $handler->display->display_options['fields']['field_news_publication_date']['field'] = 'field_news_publication_date';
  $handler->display->display_options['fields']['field_news_publication_date']['label'] = 'Published on';
  $handler->display->display_options['fields']['field_news_publication_date']['settings'] = array(
    'format_type' => 'eip_agri_short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Geographical scope */
  $handler->display->display_options['fields']['field_core_geographical_area']['id'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['table'] = 'field_data_field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['field'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['label'] = 'Country';
  $handler->display->display_options['fields']['field_core_geographical_area']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_core_geographical_area']['delta_offset'] = '0';
  /* Field: Field: Keywords */
  $handler->display->display_options['fields']['field_core_keywords']['id'] = 'field_core_keywords';
  $handler->display->display_options['fields']['field_core_keywords']['table'] = 'field_data_field_core_keywords';
  $handler->display->display_options['fields']['field_core_keywords']['field'] = 'field_core_keywords';
  $handler->display->display_options['fields']['field_core_keywords']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_core_keywords']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'default';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['term_page'] = FALSE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['anyall'] = '+';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['limit'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['vocabularies'] = array(
    'tags' => 'tags',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = TRUE;
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
    'news' => 'news',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'Filter by country';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'country';
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
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '0';
  $handler->display->display_options['block_description'] = 'AGRI Digitisation Toolbox - News keywords filtered';
  $export['news_list'] = $view;

  $view = new view();
  $view->name = 'news_online_resources_list';
  $view->description = '';
  $view->tag = 'AGRI News';
  $view->base_table = 'node';
  $view->human_name = 'Online resources list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Online resources ';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
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
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No online resources available.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_core_link']['id'] = 'field_core_link';
  $handler->display->display_options['fields']['field_core_link']['table'] = 'field_data_field_core_link';
  $handler->display->display_options['fields']['field_core_link']['field'] = 'field_core_link';
  $handler->display->display_options['fields']['field_core_link']['label'] = 'Link';
  $handler->display->display_options['fields']['field_core_link']['click_sort_column'] = 'url';
  /* Field: Content: Language of the website */
  $handler->display->display_options['fields']['field_news_language']['id'] = 'field_news_language';
  $handler->display->display_options['fields']['field_news_language']['table'] = 'field_data_field_news_language';
  $handler->display->display_options['fields']['field_news_language']['field'] = 'field_news_language';
  $handler->display->display_options['fields']['field_news_language']['label'] = 'Language';
  $handler->display->display_options['fields']['field_news_language']['delta_offset'] = '0';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Post date';
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
    'online_resource' => 'online_resource',
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
  /* Filter criterion: Content: Language of the website (field_news_language) */
  $handler->display->display_options['filters']['field_news_language_value']['id'] = 'field_news_language_value';
  $handler->display->display_options['filters']['field_news_language_value']['table'] = 'field_data_field_news_language';
  $handler->display->display_options['filters']['field_news_language_value']['field'] = 'field_news_language_value';
  $handler->display->display_options['filters']['field_news_language_value']['group'] = 1;
  $handler->display->display_options['filters']['field_news_language_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_news_language_value']['expose']['operator_id'] = 'field_news_language_value_op';
  $handler->display->display_options['filters']['field_news_language_value']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['field_news_language_value']['expose']['operator'] = 'field_news_language_value_op';
  $handler->display->display_options['filters']['field_news_language_value']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['field_news_language_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_news_language_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_news_language_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  $handler->display->display_options['filters']['status_1']['group'] = 1;

  /* Display: Online resources */
  $handler = $view->new_display('page', 'Online resources', 'page');
  $handler->display->display_options['path'] = 'find-connect/online-resources';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Online resources';
  $handler->display->display_options['menu']['weight'] = '-42';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Digitization toolbox - Online resources */
  $handler = $view->new_display('block', 'Digitization toolbox - Online resources', 'digitization_toolbox_resources_keywords');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Online (external) resources ';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '1';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_table_plugin_style';
  $handler->display->display_options['style_options']['columns'] = array(
    'created' => 'created',
    'field_core_link' => 'field_core_link',
    'body' => 'body',
    'title' => 'title',
    'field_core_geographical_area' => 'field_core_geographical_area',
    'field_core_keywords' => 'field_core_keywords',
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
    'field_core_link' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
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
    'field_core_geographical_area' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_core_keywords' => array(
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
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: agri_digitization_toolbox */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'flag_digitization_toolbox';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'agri_digitization_toolbox';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Published on';
  $handler->display->display_options['fields']['created']['date_format'] = 'eip_agri_short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'eip_agri_long';
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_core_link']['id'] = 'field_core_link';
  $handler->display->display_options['fields']['field_core_link']['table'] = 'field_data_field_core_link';
  $handler->display->display_options['fields']['field_core_link']['field'] = 'field_core_link';
  $handler->display->display_options['fields']['field_core_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_core_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_core_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_core_link']['type'] = 'link_plain';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Website';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href="[field_core_link]" title="[body]">[title] </a>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Geographical scope */
  $handler->display->display_options['fields']['field_core_geographical_area']['id'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['table'] = 'field_data_field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['field'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['label'] = 'Country';
  $handler->display->display_options['fields']['field_core_geographical_area']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_core_geographical_area']['delta_offset'] = '0';
  /* Field: Field: Keywords */
  $handler->display->display_options['fields']['field_core_keywords']['id'] = 'field_core_keywords';
  $handler->display->display_options['fields']['field_core_keywords']['table'] = 'field_data_field_core_keywords';
  $handler->display->display_options['fields']['field_core_keywords']['field'] = 'field_core_keywords';
  $handler->display->display_options['fields']['field_core_keywords']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_core_keywords']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Post date';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'default';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['term_page'] = FALSE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['anyall'] = '+';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['limit'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['vocabularies'] = array(
    'tags' => 'tags',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '1';
  $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = TRUE;
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
    'online_resource' => 'online_resource',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'Filter by country';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'country';
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
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '0';
  $handler->display->display_options['block_description'] = 'AGRI Digitisation Toolbox - Online resources keywords filtered';
  $export['news_online_resources_list'] = $view;

  return $export;
}
