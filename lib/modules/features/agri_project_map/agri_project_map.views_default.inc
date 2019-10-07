<?php

/**
 * @file
 * agri_project_map.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function agri_project_map_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'projects_map';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Projects Map';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';

  /* Display: EU map - Operational Group */
  $handler = $view->new_display('block', 'EU map - Operational Group', 'block_eu_map_prj_op');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Discover Operational Group Projects';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'agri_project_map_plugin_style';
  $handler->display->display_options['style_options']['map_background'] = 'graybg_eu28';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field: NUTS region (nuts_region) */
  $handler->display->display_options['relationships']['nuts_region_tid']['id'] = 'nuts_region_tid';
  $handler->display->display_options['relationships']['nuts_region_tid']['table'] = 'field_data_nuts_region';
  $handler->display->display_options['relationships']['nuts_region_tid']['field'] = 'nuts_region_tid';
  $handler->display->display_options['relationships']['nuts_region_tid']['required'] = TRUE;
  /* Relationship: Content: Other geographical location (NUTS3) (field_proj_nuts_region_other_1) */
  $handler->display->display_options['relationships']['field_proj_nuts_region_other_1_tid']['id'] = 'field_proj_nuts_region_other_1_tid';
  $handler->display->display_options['relationships']['field_proj_nuts_region_other_1_tid']['table'] = 'field_data_field_proj_nuts_region_other_1';
  $handler->display->display_options['relationships']['field_proj_nuts_region_other_1_tid']['field'] = 'field_proj_nuts_region_other_1_tid';
  $handler->display->display_options['relationships']['field_proj_nuts_region_other_1_tid']['label'] = 'term from nuts_region_1';
  /* Relationship: Content: Other geographical location (NUTS3) (field_proj_nuts_region_other_2) */
  $handler->display->display_options['relationships']['field_proj_nuts_region_other_2_tid']['id'] = 'field_proj_nuts_region_other_2_tid';
  $handler->display->display_options['relationships']['field_proj_nuts_region_other_2_tid']['table'] = 'field_data_field_proj_nuts_region_other_2';
  $handler->display->display_options['relationships']['field_proj_nuts_region_other_2_tid']['field'] = 'field_proj_nuts_region_other_2_tid';
  $handler->display->display_options['relationships']['field_proj_nuts_region_other_2_tid']['label'] = 'term from nuts_region_2';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: NUTS Code */
  $handler->display->display_options['fields']['nuts_code']['id'] = 'nuts_code';
  $handler->display->display_options['fields']['nuts_code']['table'] = 'field_data_nuts_code';
  $handler->display->display_options['fields']['nuts_code']['field'] = 'nuts_code';
  $handler->display->display_options['fields']['nuts_code']['relationship'] = 'nuts_region_tid';
  /* Field: Taxonomy term: NUTS Code */
  $handler->display->display_options['fields']['nuts_code_1']['id'] = 'nuts_code_1';
  $handler->display->display_options['fields']['nuts_code_1']['table'] = 'field_data_nuts_code';
  $handler->display->display_options['fields']['nuts_code_1']['field'] = 'nuts_code';
  $handler->display->display_options['fields']['nuts_code_1']['relationship'] = 'nuts_region_tid';
  /* Field: Taxonomy term: NUTS Code */
  $handler->display->display_options['fields']['nuts_code_2']['id'] = 'nuts_code_2';
  $handler->display->display_options['fields']['nuts_code_2']['table'] = 'field_data_nuts_code';
  $handler->display->display_options['fields']['nuts_code_2']['field'] = 'nuts_code';
  $handler->display->display_options['fields']['nuts_code_2']['relationship'] = 'nuts_region_tid';
  /* Field: Taxonomy term: NUTS Country */
  $handler->display->display_options['fields']['nuts_country']['id'] = 'nuts_country';
  $handler->display->display_options['fields']['nuts_country']['table'] = 'field_data_nuts_country';
  $handler->display->display_options['fields']['nuts_country']['field'] = 'nuts_country';
  $handler->display->display_options['fields']['nuts_country']['relationship'] = 'nuts_region_tid';
  $handler->display->display_options['fields']['nuts_country']['label'] = '';
  $handler->display->display_options['fields']['nuts_country']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: NUTS Country */
  $handler->display->display_options['fields']['nuts_country_1']['id'] = 'nuts_country_1';
  $handler->display->display_options['fields']['nuts_country_1']['table'] = 'field_data_nuts_country';
  $handler->display->display_options['fields']['nuts_country_1']['field'] = 'nuts_country';
  $handler->display->display_options['fields']['nuts_country_1']['relationship'] = 'field_proj_nuts_region_other_1_tid';
  $handler->display->display_options['fields']['nuts_country_1']['label'] = '';
  $handler->display->display_options['fields']['nuts_country_1']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: NUTS Country */
  $handler->display->display_options['fields']['nuts_country_2']['id'] = 'nuts_country_2';
  $handler->display->display_options['fields']['nuts_country_2']['table'] = 'field_data_nuts_country';
  $handler->display->display_options['fields']['nuts_country_2']['field'] = 'nuts_country';
  $handler->display->display_options['fields']['nuts_country_2']['relationship'] = 'field_proj_nuts_region_other_2_tid';
  $handler->display->display_options['fields']['nuts_country_2']['label'] = '';
  $handler->display->display_options['fields']['nuts_country_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: Main funding source (field_proj_funding_source_list) */
  $handler->display->display_options['filters']['field_proj_funding_source_list_value']['id'] = 'field_proj_funding_source_list_value';
  $handler->display->display_options['filters']['field_proj_funding_source_list_value']['table'] = 'field_data_field_proj_funding_source_list';
  $handler->display->display_options['filters']['field_proj_funding_source_list_value']['field'] = 'field_proj_funding_source_list_value';
  $handler->display->display_options['filters']['field_proj_funding_source_list_value']['value'] = array(
    0 => '0',
  );

  /* Display: List of projects - Operational Group */
  $handler = $view->new_display('block', 'List of projects - Operational Group', 'block_result_op');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title (in English) */
  $handler->display->display_options['fields']['field_proj_title_eng']['id'] = 'field_proj_title_eng';
  $handler->display->display_options['fields']['field_proj_title_eng']['table'] = 'field_data_field_proj_title_eng';
  $handler->display->display_options['fields']['field_proj_title_eng']['field'] = 'field_proj_title_eng';
  $handler->display->display_options['fields']['field_proj_title_eng']['label'] = '';
  $handler->display->display_options['fields']['field_proj_title_eng']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_proj_title_eng']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_proj_title_eng]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'nuts_regions' => 'nuts_regions',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: Main funding source (field_proj_funding_source_list) */
  $handler->display->display_options['filters']['field_proj_funding_source_list_value']['id'] = 'field_proj_funding_source_list_value';
  $handler->display->display_options['filters']['field_proj_funding_source_list_value']['table'] = 'field_data_field_proj_funding_source_list';
  $handler->display->display_options['filters']['field_proj_funding_source_list_value']['field'] = 'field_proj_funding_source_list_value';
  $handler->display->display_options['filters']['field_proj_funding_source_list_value']['value'] = array(
    0 => '0',
  );
  $export['projects_map'] = $view;

  return $export;
}
