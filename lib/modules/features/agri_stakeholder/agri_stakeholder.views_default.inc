<?php

/**
 * @file
 * agri_stakeholder.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function agri_stakeholder_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'agri_stakeholder_list_page';
  $view->description = '';
  $view->tag = 'AGRI Stakeholder';
  $view->base_table = 'node';
  $view->human_name = 'AGRI Stakeholder list page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'More about...';
  $handler->display->display_options['css_class'] = 'block block-menu-block';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'nav nav-pills nav-stacked';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Field: Stakeholders (field_core_stakeholders) (translated) */
  $handler->display->display_options['relationships']['field_core_stakeholders_tid_i18n']['id'] = 'field_core_stakeholders_tid_i18n';
  $handler->display->display_options['relationships']['field_core_stakeholders_tid_i18n']['table'] = 'field_data_field_core_stakeholders';
  $handler->display->display_options['relationships']['field_core_stakeholders_tid_i18n']['field'] = 'field_core_stakeholders_tid_i18n';
  $handler->display->display_options['relationships']['field_core_stakeholders_tid_i18n']['required'] = TRUE;
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
  /* Field: Content: Short title */
  $handler->display->display_options['fields']['field_stakeholders_short_title']['id'] = 'field_stakeholders_short_title';
  $handler->display->display_options['fields']['field_stakeholders_short_title']['table'] = 'field_data_field_stakeholders_short_title';
  $handler->display->display_options['fields']['field_stakeholders_short_title']['field'] = 'field_stakeholders_short_title';
  $handler->display->display_options['fields']['field_stakeholders_short_title']['label'] = '';
  $handler->display->display_options['fields']['field_stakeholders_short_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stakeholders_short_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stakeholders_short_title']['empty'] = '[title]';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['text'] = '[field_stakeholders_short_title]';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Short title weight (field_stakeholders_short_weight) */
  $handler->display->display_options['sorts']['field_stakeholders_short_weight_value']['id'] = 'field_stakeholders_short_weight_value';
  $handler->display->display_options['sorts']['field_stakeholders_short_weight_value']['table'] = 'field_data_field_stakeholders_short_weight';
  $handler->display->display_options['sorts']['field_stakeholders_short_weight_value']['field'] = 'field_stakeholders_short_weight_value';
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
  /* Filter criterion: Taxonomy term: Active (field_core_stakeholders_active) */
  $handler->display->display_options['filters']['field_core_stakeholders_active_value']['id'] = 'field_core_stakeholders_active_value';
  $handler->display->display_options['filters']['field_core_stakeholders_active_value']['table'] = 'field_data_field_core_stakeholders_active';
  $handler->display->display_options['filters']['field_core_stakeholders_active_value']['field'] = 'field_core_stakeholders_active_value';
  $handler->display->display_options['filters']['field_core_stakeholders_active_value']['relationship'] = 'field_core_stakeholders_tid_i18n';
  $handler->display->display_options['filters']['field_core_stakeholders_active_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_core_stakeholders_active_value']['group'] = 1;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'AGRI Stakeholder list page';
  $export['agri_stakeholder_list_page'] = $view;

  $view = new view();
  $view->name = 'agri_stakeholder_projects_blocks';
  $view->description = '';
  $view->tag = 'AGRI Stakeholder';
  $view->base_table = 'node';
  $view->human_name = 'AGRI Stakeholder projects blocks';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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

  /* Display: Projects stakeholders - Operational group */
  $handler = $view->new_display('block', 'Projects stakeholders - Operational group', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Latest Operational Groups';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'project-stakeholder-block';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Create a custom link page */
  $handler->display->display_options['footer']['agri_core_link_page']['id'] = 'agri_core_link_page';
  $handler->display->display_options['footer']['agri_core_link_page']['table'] = 'views';
  $handler->display->display_options['footer']['agri_core_link_page']['field'] = 'agri_core_link_page';
  $handler->display->display_options['footer']['agri_core_link_page']['text'] = 'View all Operational Groups';
  $handler->display->display_options['footer']['agri_core_link_page']['path'] = 'eip-agri-projects/projects/operational-groups';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Geographical location */
  $handler->display->display_options['fields']['field_proj_geographical_area']['id'] = 'field_proj_geographical_area';
  $handler->display->display_options['fields']['field_proj_geographical_area']['table'] = 'field_data_field_proj_geographical_area';
  $handler->display->display_options['fields']['field_proj_geographical_area']['field'] = 'field_proj_geographical_area';
  $handler->display->display_options['fields']['field_proj_geographical_area']['label'] = '';
  $handler->display->display_options['fields']['field_proj_geographical_area']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_proj_geographical_area']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_proj_geographical_area']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_proj_geographical_area']['delta_offset'] = '0';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['text'] = '[field_proj_geographical_area] - [created]';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd F Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
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
  /* Field: Content: Title (in English) */
  $handler->display->display_options['fields']['field_proj_title_eng']['id'] = 'field_proj_title_eng';
  $handler->display->display_options['fields']['field_proj_title_eng']['table'] = 'field_data_field_proj_title_eng';
  $handler->display->display_options['fields']['field_proj_title_eng']['field'] = 'field_proj_title_eng';
  $handler->display->display_options['fields']['field_proj_title_eng']['label'] = '';
  $handler->display->display_options['fields']['field_proj_title_eng']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_proj_title_eng']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_proj_title_eng']['empty'] = '[title]';
  /* Field: Title fallback (native/eng) */
  $handler->display->display_options['fields']['view_node_1']['id'] = 'view_node_1';
  $handler->display->display_options['fields']['view_node_1']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node_1']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node_1']['ui_name'] = 'Title fallback (native/eng)';
  $handler->display->display_options['fields']['view_node_1']['label'] = '';
  $handler->display->display_options['fields']['view_node_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_node_1']['alter']['text'] = '[field_proj_title_eng]';
  $handler->display->display_options['fields']['view_node_1']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_wrapper_class'] = 'text-right';
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more';
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
    'project' => 'project',
  );
  /* Filter criterion: Content: Project type (field_proj_project_type) */
  $handler->display->display_options['filters']['field_proj_project_type_value']['id'] = 'field_proj_project_type_value';
  $handler->display->display_options['filters']['field_proj_project_type_value']['table'] = 'field_data_field_proj_project_type';
  $handler->display->display_options['filters']['field_proj_project_type_value']['field'] = 'field_proj_project_type_value';
  $handler->display->display_options['filters']['field_proj_project_type_value']['value'] = 'Operational group';

  /* Display: Projects stakeholders - Horizon 2020 */
  $handler = $view->new_display('block', 'Projects stakeholders - Horizon 2020', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Latest Horizon 2020 projects';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'project-stakeholder-block';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Create a custom link page */
  $handler->display->display_options['footer']['agri_core_link_page']['id'] = 'agri_core_link_page';
  $handler->display->display_options['footer']['agri_core_link_page']['table'] = 'views';
  $handler->display->display_options['footer']['agri_core_link_page']['field'] = 'agri_core_link_page';
  $handler->display->display_options['footer']['agri_core_link_page']['text'] = 'View all Multi-Actor Projects';
  $handler->display->display_options['footer']['agri_core_link_page']['path'] = 'eip-agri-projects/projects/multi-actor-projects';
  /* Footer: Global: Create a custom link page */
  $handler->display->display_options['footer']['agri_core_link_page_1']['id'] = 'agri_core_link_page_1';
  $handler->display->display_options['footer']['agri_core_link_page_1']['table'] = 'views';
  $handler->display->display_options['footer']['agri_core_link_page_1']['field'] = 'agri_core_link_page';
  $handler->display->display_options['footer']['agri_core_link_page_1']['text'] = 'View all Thematic Networks';
  $handler->display->display_options['footer']['agri_core_link_page_1']['path'] = 'eip-agri-projects/projects/thematic-networks';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Project Identification */
  $handler->display->display_options['fields']['field_proj_sfc_identification']['id'] = 'field_proj_sfc_identification';
  $handler->display->display_options['fields']['field_proj_sfc_identification']['table'] = 'field_data_field_proj_sfc_identification';
  $handler->display->display_options['fields']['field_proj_sfc_identification']['field'] = 'field_proj_sfc_identification';
  $handler->display->display_options['fields']['field_proj_sfc_identification']['label'] = '';
  $handler->display->display_options['fields']['field_proj_sfc_identification']['element_label_colon'] = FALSE;
  /* Field: Content: Geographical location */
  $handler->display->display_options['fields']['field_proj_geographical_area']['id'] = 'field_proj_geographical_area';
  $handler->display->display_options['fields']['field_proj_geographical_area']['table'] = 'field_data_field_proj_geographical_area';
  $handler->display->display_options['fields']['field_proj_geographical_area']['field'] = 'field_proj_geographical_area';
  $handler->display->display_options['fields']['field_proj_geographical_area']['label'] = '';
  $handler->display->display_options['fields']['field_proj_geographical_area']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_proj_geographical_area']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_proj_geographical_area']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_proj_geographical_area']['delta_offset'] = '0';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['text'] = '[field_proj_geographical_area] - [created]';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd F Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
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
  /* Field: Content: Title (in English) */
  $handler->display->display_options['fields']['field_proj_title_eng']['id'] = 'field_proj_title_eng';
  $handler->display->display_options['fields']['field_proj_title_eng']['table'] = 'field_data_field_proj_title_eng';
  $handler->display->display_options['fields']['field_proj_title_eng']['field'] = 'field_proj_title_eng';
  $handler->display->display_options['fields']['field_proj_title_eng']['label'] = '';
  $handler->display->display_options['fields']['field_proj_title_eng']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_proj_title_eng']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_proj_title_eng']['empty'] = '[title]';
  /* Field: Title fallback (native/eng) */
  $handler->display->display_options['fields']['view_node_1']['id'] = 'view_node_1';
  $handler->display->display_options['fields']['view_node_1']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node_1']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node_1']['ui_name'] = 'Title fallback (native/eng)';
  $handler->display->display_options['fields']['view_node_1']['label'] = '';
  $handler->display->display_options['fields']['view_node_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_node_1']['alter']['text'] = '[field_proj_title_eng]';
  $handler->display->display_options['fields']['view_node_1']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_wrapper_class'] = 'text-right';
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more';
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
    'project' => 'project',
  );
  /* Filter criterion: Content: Main funding source (field_proj_funding_source_list) */
  $handler->display->display_options['filters']['field_proj_funding_source_list_value']['id'] = 'field_proj_funding_source_list_value';
  $handler->display->display_options['filters']['field_proj_funding_source_list_value']['table'] = 'field_data_field_proj_funding_source_list';
  $handler->display->display_options['filters']['field_proj_funding_source_list_value']['field'] = 'field_proj_funding_source_list_value';
  $handler->display->display_options['filters']['field_proj_funding_source_list_value']['value'] = array(
    4 => '4',
  );
  /* Filter criterion: Content: Project Identification (field_proj_sfc_identification) */
  $handler->display->display_options['filters']['field_proj_sfc_identification_value']['id'] = 'field_proj_sfc_identification_value';
  $handler->display->display_options['filters']['field_proj_sfc_identification_value']['table'] = 'field_data_field_proj_sfc_identification';
  $handler->display->display_options['filters']['field_proj_sfc_identification_value']['field'] = 'field_proj_sfc_identification_value';
  $handler->display->display_options['filters']['field_proj_sfc_identification_value']['value'] = array(
    'thematic-network' => 'thematic-network',
    'multi-actor-project' => 'multi-actor-project',
  );
  $export['agri_stakeholder_projects_blocks'] = $view;

  $view = new view();
  $view->name = 'agri_stakeholder_projects_page';
  $view->description = '';
  $view->tag = 'AGRI Stakeholder';
  $view->base_table = 'search_api_index_core_node_index';
  $view->human_name = 'AGRI Stakeholder Projects indexed search';
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
    'title' => 'title',
    'field_proj_project_type' => 'field_proj_project_type',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_proj_project_type' => array(
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
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
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

  /* Display: Page Projects - Operational groups */
  $handler = $view->new_display('page', 'Page Projects - Operational groups', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Projects - Operational groups';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'created' => 'created',
    'field_proj_title' => 'field_proj_title',
    'field_proj_geographical_area' => 'field_proj_geographical_area',
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
    'field_proj_geographical_area' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
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
  /* Field: Indexed Content: Geographical location */
  $handler->display->display_options['fields']['field_proj_geographical_area']['id'] = 'field_proj_geographical_area';
  $handler->display->display_options['fields']['field_proj_geographical_area']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_geographical_area']['field'] = 'field_proj_geographical_area';
  $handler->display->display_options['fields']['field_proj_geographical_area']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_proj_geographical_area']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_proj_geographical_area']['bypass_access'] = 0;
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
  /* Filter criterion: Indexed Content: Project type */
  $handler->display->display_options['filters']['field_proj_project_type']['id'] = 'field_proj_project_type';
  $handler->display->display_options['filters']['field_proj_project_type']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_proj_project_type']['field'] = 'field_proj_project_type';
  $handler->display->display_options['filters']['field_proj_project_type']['value'] = 'Operational group';
  $handler->display->display_options['filters']['field_proj_project_type']['group'] = 1;
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
  $handler->display->display_options['path'] = 'eip-agri-projects/projects/operational-groups';

  /* Display: Page Projects - Thematic Networks */
  $handler = $view->new_display('page', 'Page Projects - Thematic Networks', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Projects - Thematic Networks';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'created' => 'created',
    'field_proj_title' => 'field_proj_title',
    'field_proj_geographical_area' => 'field_proj_geographical_area',
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
    'field_proj_geographical_area' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
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
  /* Field: Indexed Content: Geographical location */
  $handler->display->display_options['fields']['field_proj_geographical_area']['id'] = 'field_proj_geographical_area';
  $handler->display->display_options['fields']['field_proj_geographical_area']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_geographical_area']['field'] = 'field_proj_geographical_area';
  $handler->display->display_options['fields']['field_proj_geographical_area']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_proj_geographical_area']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_proj_geographical_area']['bypass_access'] = 0;
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
  $handler->display->display_options['filters']['field_proj_funding_source_list_1']['id'] = 'field_proj_funding_source_list_1';
  $handler->display->display_options['filters']['field_proj_funding_source_list_1']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_proj_funding_source_list_1']['field'] = 'field_proj_funding_source_list';
  $handler->display->display_options['filters']['field_proj_funding_source_list_1']['value'] = array(
    4 => '4',
  );
  $handler->display->display_options['filters']['field_proj_funding_source_list_1']['group'] = 1;
  /* Filter criterion: Indexed Content: Project Identification */
  $handler->display->display_options['filters']['field_proj_sfc_identification']['id'] = 'field_proj_sfc_identification';
  $handler->display->display_options['filters']['field_proj_sfc_identification']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_proj_sfc_identification']['field'] = 'field_proj_sfc_identification';
  $handler->display->display_options['filters']['field_proj_sfc_identification']['value'] = array(
    'thematic-network' => 'thematic-network',
  );
  $handler->display->display_options['filters']['field_proj_sfc_identification']['group'] = 1;
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
  $handler->display->display_options['path'] = 'eip-agri-projects/projects/thematic-networks';

  /* Display: Page Projects - Multi-Actor Projects */
  $handler = $view->new_display('page', 'Page Projects - Multi-Actor Projects', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Projects - Multi-Actor Projects';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'created' => 'created',
    'field_proj_title' => 'field_proj_title',
    'field_proj_geographical_area' => 'field_proj_geographical_area',
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
    'field_proj_geographical_area' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
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
  /* Field: Indexed Content: Geographical location */
  $handler->display->display_options['fields']['field_proj_geographical_area']['id'] = 'field_proj_geographical_area';
  $handler->display->display_options['fields']['field_proj_geographical_area']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['fields']['field_proj_geographical_area']['field'] = 'field_proj_geographical_area';
  $handler->display->display_options['fields']['field_proj_geographical_area']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_proj_geographical_area']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_proj_geographical_area']['bypass_access'] = 0;
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
  $handler->display->display_options['filters']['field_proj_funding_source_list_1']['id'] = 'field_proj_funding_source_list_1';
  $handler->display->display_options['filters']['field_proj_funding_source_list_1']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_proj_funding_source_list_1']['field'] = 'field_proj_funding_source_list';
  $handler->display->display_options['filters']['field_proj_funding_source_list_1']['value'] = array(
    4 => '4',
  );
  $handler->display->display_options['filters']['field_proj_funding_source_list_1']['group'] = 1;
  /* Filter criterion: Indexed Content: Project Identification */
  $handler->display->display_options['filters']['field_proj_sfc_identification']['id'] = 'field_proj_sfc_identification';
  $handler->display->display_options['filters']['field_proj_sfc_identification']['table'] = 'search_api_index_core_node_index';
  $handler->display->display_options['filters']['field_proj_sfc_identification']['field'] = 'field_proj_sfc_identification';
  $handler->display->display_options['filters']['field_proj_sfc_identification']['value'] = array(
    'multi-actor-project' => 'multi-actor-project',
  );
  $handler->display->display_options['filters']['field_proj_sfc_identification']['group'] = 1;
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
  $handler->display->display_options['path'] = 'eip-agri-projects/projects/multi-actor-projects';
  $export['agri_stakeholder_projects_page'] = $view;

  $view = new view();
  $view->name = 'agri_stakeholder_publication';
  $view->description = '';
  $view->tag = 'AGRI Stakeholder';
  $view->base_table = 'node';
  $view->human_name = 'AGRI Stakeholder publication';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Relevant EIP-AGRI documents';
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'view more';
  $handler->display->display_options['link_display'] = 'page';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Field: Stakeholders (field_core_stakeholders) (translated) */
  $handler->display->display_options['relationships']['field_core_stakeholders_tid_i18n']['id'] = 'field_core_stakeholders_tid_i18n';
  $handler->display->display_options['relationships']['field_core_stakeholders_tid_i18n']['table'] = 'field_data_field_core_stakeholders';
  $handler->display->display_options['relationships']['field_core_stakeholders_tid_i18n']['field'] = 'field_core_stakeholders_tid_i18n';
  $handler->display->display_options['relationships']['field_core_stakeholders_tid_i18n']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
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
  /* Filter criterion: Taxonomy term: Active (field_core_stakeholders_active) */
  $handler->display->display_options['filters']['field_core_stakeholders_active_value']['id'] = 'field_core_stakeholders_active_value';
  $handler->display->display_options['filters']['field_core_stakeholders_active_value']['table'] = 'field_data_field_core_stakeholders_active';
  $handler->display->display_options['filters']['field_core_stakeholders_active_value']['field'] = 'field_core_stakeholders_active_value';
  $handler->display->display_options['filters']['field_core_stakeholders_active_value']['relationship'] = 'field_core_stakeholders_tid_i18n';
  $handler->display->display_options['filters']['field_core_stakeholders_active_value']['value'] = array(
    1 => '1',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Year of publication (field_publication_date) */
  $handler->display->display_options['sorts']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'eip-agri-projects/publications';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Relevant EIP-AGRI documents';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Create a custom link page */
  $handler->display->display_options['footer']['agri_core_link_page']['id'] = 'agri_core_link_page';
  $handler->display->display_options['footer']['agri_core_link_page']['table'] = 'views';
  $handler->display->display_options['footer']['agri_core_link_page']['field'] = 'agri_core_link_page';
  $handler->display->display_options['footer']['agri_core_link_page']['text'] = 'view more';
  $handler->display->display_options['footer']['agri_core_link_page']['path'] = 'eip-agri-projects/publications';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Publication type */
  $handler->display->display_options['fields']['field_publication_type']['id'] = 'field_publication_type';
  $handler->display->display_options['fields']['field_publication_type']['table'] = 'field_data_field_publication_type';
  $handler->display->display_options['fields']['field_publication_type']['field'] = 'field_publication_type';
  $handler->display->display_options['fields']['field_publication_type']['label'] = '';
  $handler->display->display_options['fields']['field_publication_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $export['agri_stakeholder_publication'] = $view;

  return $export;
}
