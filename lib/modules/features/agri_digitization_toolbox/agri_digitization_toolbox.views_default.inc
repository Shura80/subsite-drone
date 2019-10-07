<?php

/**
 * @file
 * agri_digitization_toolbox.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function agri_digitization_toolbox_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'agri_digitisation_toolbox_country_filter';
  $view->description = 'Exposed block to filter country.';
  $view->tag = 'AGRI Digitisation Toolbox ';
  $view->base_table = 'node';
  $view->human_name = 'AGRI Digitisation toolbox country filter';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'AGRI Digitisation Toolbox Country filter';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
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
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['group'] = 1;
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

  /* Display:  Digitisation Toolbox Country filter */
  $handler = $view->new_display('block', ' Digitisation Toolbox Country filter', 'digitisation_country_filter_block');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['block_description'] = 'Digitisation Toolbox Country filter';
  $export['agri_digitisation_toolbox_country_filter'] = $view;

  $view = new view();
  $view->name = 'agri_digitization_toolbox_content';
  $view->description = '';
  $view->tag = 'AGRI Digitisation Toolbox ';
  $view->base_table = 'node';
  $view->human_name = 'AGRI Digitisation toolbox';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Digitisation toolbox content';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access digitization toolbox views';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'type' => 'type',
    'field_core_keywords' => 'field_core_keywords',
    'field_core_geographical_area' => 'field_core_geographical_area',
    'ops' => 'ops',
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
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
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
    'ops' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
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
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';

  /* Display: Digitisation toolbox - Other content */
  $handler = $view->new_display('page', 'Digitisation toolbox - Other content', 'digitization_toolbox_content');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Digitisation toolbox - Other content';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '25, 50, 100';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = 'All items';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'type' => 'type',
    'field_core_keywords' => 'field_core_keywords',
    'field_core_geographical_area' => 'field_core_geographical_area',
    'ops' => 'ops',
    'edit_node' => 'edit_node',
    'changed' => 'changed',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
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
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
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
    'ops' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
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
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No content available.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: agri_digitization_toolbox */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'flag_digitization_toolbox';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'agri_digitization_toolbox';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::rules_agri_digitization_toolbox_add_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Update keywords and country',
      'settings' => array(
        'show_all_tokens' => 0,
        'display_values' => array(
          'page::field_core_keywords' => 'page::field_core_keywords',
          'page::field_core_geographical_area' => 'page::field_core_geographical_area',
          'event::field_core_keywords' => 'event::field_core_keywords',
          'event::field_core_geographical_area' => 'event::field_core_geographical_area',
          'news::field_core_geographical_area' => 'news::field_core_geographical_area',
          'news::field_core_keywords' => 'news::field_core_keywords',
          'online_resource::field_core_keywords' => 'online_resource::field_core_keywords',
          'online_resource::field_core_geographical_area' => 'online_resource::field_core_geographical_area',
          'press_release::field_core_keywords' => 'press_release::field_core_keywords',
          'press_release::field_core_geographical_area' => 'press_release::field_core_geographical_area',
          'publication::field_core_geographical_area' => 'publication::field_core_geographical_area',
          'publication::field_core_keywords' => 'publication::field_core_keywords',
        ),
      ),
    ),
    'rules_component::rules_agri_digitization_toolbox_remove_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Modification date';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'eip_agri_long';
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
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Field: Keywords */
  $handler->display->display_options['fields']['field_core_keywords']['id'] = 'field_core_keywords';
  $handler->display->display_options['fields']['field_core_keywords']['table'] = 'field_data_field_core_keywords';
  $handler->display->display_options['fields']['field_core_keywords']['field'] = 'field_core_keywords';
  $handler->display->display_options['fields']['field_core_keywords']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_core_keywords']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_core_keywords']['delta_offset'] = '0';
  /* Field: Field: Geographical scope */
  $handler->display->display_options['fields']['field_core_geographical_area']['id'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['table'] = 'field_data_field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['field'] = 'field_core_geographical_area';
  $handler->display->display_options['fields']['field_core_geographical_area']['label'] = 'Country';
  $handler->display->display_options['fields']['field_core_geographical_area']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_core_geographical_area']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_core_geographical_area']['delta_offset'] = '0';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = 'Digitisation toolbox';
  $handler->display->display_options['fields']['ops']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['ops']['alter']['text'] = '[ops]';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['ops']['element_default_classes'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    13 => 0,
    14 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
  );
  /* Filter criterion: Field: Keywords (field_core_keywords) */
  $handler->display->display_options['filters']['field_core_keywords_tid']['id'] = 'field_core_keywords_tid';
  $handler->display->display_options['filters']['field_core_keywords_tid']['table'] = 'field_data_field_core_keywords';
  $handler->display->display_options['filters']['field_core_keywords_tid']['field'] = 'field_core_keywords_tid';
  $handler->display->display_options['filters']['field_core_keywords_tid']['value'] = '';
  $handler->display->display_options['filters']['field_core_keywords_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_core_keywords_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['operator_id'] = 'field_core_keywords_tid_op';
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['label'] = 'Keywords';
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['description'] = 'Use a comma to separate multiple terms.';
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['operator'] = 'field_core_keywords_tid_op';
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['identifier'] = 'keyword';
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_core_keywords_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    13 => 0,
    14 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
  );
  $handler->display->display_options['filters']['field_core_keywords_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_core_keywords_tid']['vocabulary'] = 'tags';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'page' => 'page',
    'event' => 'event',
    'news' => 'news',
    'online_resource' => 'online_resource',
    'press_release' => 'press_release',
    'publication' => 'publication',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['value'] = '';
  $handler->display->display_options['filters']['term_node_tid_depth']['group'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['description'] = 'Use a comma to separate multiple terms.';
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
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'core_geographical_area';
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'page' => 'page',
    'event' => 'event',
    'news' => 'news',
    'online_resource' => 'online_resource',
    'press_release' => 'press_release',
    'publication' => 'publication',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    13 => 0,
    14 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
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
  $handler->display->display_options['filters']['flagged']['expose']['label'] = 'Digitisation';
  $handler->display->display_options['filters']['flagged']['expose']['operator'] = 'flagged_op';
  $handler->display->display_options['filters']['flagged']['expose']['identifier'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    13 => 0,
    14 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
  );
  $handler->display->display_options['path'] = 'admin/content/digitisation-toolbox';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Digitisation toolbox';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['agri_digitization_toolbox_content'] = $view;

  $view = new view();
  $view->name = 'agri_digitization_toolbox_landing_blocks';
  $view->description = '';
  $view->tag = 'AGRI Digitization Toolbox';
  $view->base_table = 'node';
  $view->human_name = 'AGRI Digitization Toolbox landing blocks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Feature Digitisation news';
  $handler->display->display_options['css_class'] = 'views-spotlight-block';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'slideshow';
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

  /* Display: News landing block */
  $handler = $view->new_display('block', 'News landing block', 'news');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Feature Digitisation news';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'views-spotlight-block';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'slideshow';
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
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: agri_digitization_toolbox */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'flag_digitization_toolbox';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'agri_digitization_toolbox';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
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
  /* Filter criterion: Field: Geographical scope (field_core_geographical_area) */
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['id'] = 'field_core_geographical_area_tid';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['table'] = 'field_data_field_core_geographical_area';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['field'] = 'field_core_geographical_area_tid';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['expose']['operator_id'] = 'field_core_geographical_area_tid_op';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['expose']['label'] = 'Filter by country';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['expose']['operator'] = 'field_core_geographical_area_tid_op';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['expose']['identifier'] = 'country';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['vocabulary'] = 'core_geographical_area';
  $handler->display->display_options['filters']['field_core_geographical_area_tid']['hierarchy'] = 1;
  $handler->display->display_options['block_description'] = 'AGRI Digitization Toolbox - News landing block';
  $export['agri_digitization_toolbox_landing_blocks'] = $view;

  $view = new view();
  $view->name = 'agri_digitization_toolbox_projects';
  $view->description = '';
  $view->tag = 'AGRI Digitisation Toolbox ';
  $view->base_table = 'node';
  $view->human_name = 'AGRI Digitisation toolbox - Projects';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Digitisation toolbox content';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access digitization toolbox views';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'field_project_puid' => 'field_project_puid',
    'title' => 'title',
    'field_core_keywords' => 'field_core_keywords',
    'field_agri_digitazion_int_kwords' => 'field_agri_digitazion_int_kwords',
    'ops' => 'ops',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
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
    'field_core_keywords' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_agri_digitazion_int_kwords' => array(
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
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
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

  /* Display: Digitisation toolbox - Projects */
  $handler = $view->new_display('page', 'Digitisation toolbox - Projects', 'digitization_toolbox_projects');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Digitisation toolbox - Projects';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '25, 50, 100';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = 'All items';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'field_project_puid' => 'field_project_puid',
    'title' => 'title',
    'field_core_keywords' => 'field_core_keywords',
    'field_agri_proj_internal_kwords' => 'field_agri_proj_internal_kwords',
    'ops' => 'ops',
    'edit_node' => 'edit_node',
    'nothing' => 'nothing',
    'field_proj_is_sfc' => 'field_proj_is_sfc',
    'field_proj_sfc_modification_date' => 'field_proj_sfc_modification_date',
    'field_proj_geographical_area' => 'field_proj_geographical_area',
  );
  $handler->display->display_options['style_options']['default'] = 'field_proj_sfc_modification_date';
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
    'ops' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_proj_is_sfc' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_proj_sfc_modification_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_proj_geographical_area' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No content available.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: agri_digitization_toolbox */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'flag_digitization_toolbox';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'agri_digitization_toolbox';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::rules_agri_digitization_toolbox_add_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Update internal keywords',
      'settings' => array(
        'show_all_tokens' => 0,
        'display_values' => array(
          'project::field_agri_proj_internal_kwords' => 'project::field_agri_proj_internal_kwords',
        ),
      ),
    ),
    'rules_component::rules_agri_digitization_toolbox_remove_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Modification date */
  $handler->display->display_options['fields']['field_proj_sfc_modification_date']['id'] = 'field_proj_sfc_modification_date';
  $handler->display->display_options['fields']['field_proj_sfc_modification_date']['table'] = 'field_data_field_proj_sfc_modification_date';
  $handler->display->display_options['fields']['field_proj_sfc_modification_date']['field'] = 'field_proj_sfc_modification_date';
  $handler->display->display_options['fields']['field_proj_sfc_modification_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_proj_sfc_modification_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: PUID (Project Unique ID) */
  $handler->display->display_options['fields']['field_project_puid']['id'] = 'field_project_puid';
  $handler->display->display_options['fields']['field_project_puid']['table'] = 'field_data_field_project_puid';
  $handler->display->display_options['fields']['field_project_puid']['field'] = 'field_project_puid';
  $handler->display->display_options['fields']['field_project_puid']['label'] = 'PUID';
  $handler->display->display_options['fields']['field_project_puid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project_puid']['type'] = 'text_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Keywords */
  $handler->display->display_options['fields']['field_core_keywords']['id'] = 'field_core_keywords';
  $handler->display->display_options['fields']['field_core_keywords']['table'] = 'field_data_field_core_keywords';
  $handler->display->display_options['fields']['field_core_keywords']['field'] = 'field_core_keywords';
  $handler->display->display_options['fields']['field_core_keywords']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_core_keywords']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_core_keywords']['delta_offset'] = '0';
  /* Field: Content: Internal keywords */
  $handler->display->display_options['fields']['field_agri_proj_internal_kwords']['id'] = 'field_agri_proj_internal_kwords';
  $handler->display->display_options['fields']['field_agri_proj_internal_kwords']['table'] = 'field_data_field_agri_proj_internal_kwords';
  $handler->display->display_options['fields']['field_agri_proj_internal_kwords']['field'] = 'field_agri_proj_internal_kwords';
  $handler->display->display_options['fields']['field_agri_proj_internal_kwords']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_agri_proj_internal_kwords']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_agri_proj_internal_kwords']['delta_offset'] = '0';
  /* Field: Content: Geographical location */
  $handler->display->display_options['fields']['field_proj_geographical_area']['id'] = 'field_proj_geographical_area';
  $handler->display->display_options['fields']['field_proj_geographical_area']['table'] = 'field_data_field_proj_geographical_area';
  $handler->display->display_options['fields']['field_proj_geographical_area']['field'] = 'field_proj_geographical_area';
  $handler->display->display_options['fields']['field_proj_geographical_area']['label'] = 'Country';
  $handler->display->display_options['fields']['field_proj_geographical_area']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_proj_geographical_area']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_proj_geographical_area']['delta_offset'] = '0';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = 'Digitisation toolbox';
  $handler->display->display_options['fields']['ops']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['ops']['alter']['text'] = '[ops]';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['ops']['element_default_classes'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = ' ';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: SFC */
  $handler->display->display_options['fields']['field_proj_is_sfc']['id'] = 'field_proj_is_sfc';
  $handler->display->display_options['fields']['field_proj_is_sfc']['table'] = 'field_data_field_proj_is_sfc';
  $handler->display->display_options['fields']['field_proj_is_sfc']['field'] = 'field_proj_is_sfc';
  $handler->display->display_options['fields']['field_proj_is_sfc']['label'] = 'Operations';
  $handler->display->display_options['fields']['field_proj_is_sfc']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_proj_is_sfc']['alter']['text'] = '[nothing]';
  $handler->display->display_options['fields']['field_proj_is_sfc']['empty'] = '[edit_node]';
  $handler->display->display_options['fields']['field_proj_is_sfc']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_proj_is_sfc']['type'] = 'list_key';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: PUID (Project Unique ID) (field_project_puid) */
  $handler->display->display_options['filters']['field_project_puid_value']['id'] = 'field_project_puid_value';
  $handler->display->display_options['filters']['field_project_puid_value']['table'] = 'field_data_field_project_puid';
  $handler->display->display_options['filters']['field_project_puid_value']['field'] = 'field_project_puid_value';
  $handler->display->display_options['filters']['field_project_puid_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_project_puid_value']['group'] = 1;
  $handler->display->display_options['filters']['field_project_puid_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_puid_value']['expose']['operator_id'] = 'field_project_puid_value_op';
  $handler->display->display_options['filters']['field_project_puid_value']['expose']['label'] = 'PUID';
  $handler->display->display_options['filters']['field_project_puid_value']['expose']['operator'] = 'field_project_puid_value_op';
  $handler->display->display_options['filters']['field_project_puid_value']['expose']['identifier'] = 'field_project_puid_value';
  $handler->display->display_options['filters']['field_project_puid_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    13 => 0,
    14 => 0,
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
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    13 => 0,
    14 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
  );
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['value'] = '';
  $handler->display->display_options['filters']['term_node_tid_depth']['group'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'Keywords/Internal keywords';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['description'] = 'Use a comma to separate multiple terms.';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'keyword';
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
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'tags';
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '0';
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth_1']['id'] = 'term_node_tid_depth_1';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['value'] = '';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['group'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['operator_id'] = 'term_node_tid_depth_1_op';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['description'] = 'Use a comma to separate multiple terms.';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['operator'] = 'term_node_tid_depth_1_op';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['identifier'] = 'country';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['term_node_tid_depth_1']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth_1']['vocabulary'] = 'core_geographical_area';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['depth'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'project' => 'project',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
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
  $handler->display->display_options['filters']['flagged']['expose']['label'] = 'Digitisation';
  $handler->display->display_options['filters']['flagged']['expose']['operator'] = 'flagged_op';
  $handler->display->display_options['filters']['flagged']['expose']['identifier'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    13 => 0,
    14 => 0,
    9 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
  );
  $handler->display->display_options['path'] = 'admin/content/digitisation-toolbox/projects';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Projects';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['agri_digitization_toolbox_projects'] = $view;

  return $export;
}
