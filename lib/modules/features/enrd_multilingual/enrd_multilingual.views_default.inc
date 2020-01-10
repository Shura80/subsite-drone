<?php

/**
 * @file
 * enrd_multilingual.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function enrd_multilingual_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'enrd_content_translation_report';
  $view->description = '';
  $view->tag = 'ENRD Multilingual';
  $view->base_table = 'node';
  $view->human_name = 'ENRD Content translation report';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Content translation report';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['field_language'] = '***DEFAULT_LANGUAGE***';
  $handler->display->display_options['field_language_add_to_query'] = 0;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'translate node entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_tags'] = array(
    0 => 'enrd_multilingual',
    1 => 'translations',
  );
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'created' => 'created',
    'changed_5' => 'changed_5',
    'type' => 'type',
    'changed_6' => 'changed_6',
    'status' => 'status',
    'changed' => 'changed',
    'status_1' => 'status_1',
    'changed_1' => 'changed_1',
    'status_2' => 'status_2',
    'changed_2' => 'changed_2',
    'status_3' => 'status_3',
    'changed_3' => 'changed_3',
    'status_4' => 'status_4',
    'changed_4' => 'changed_4',
  );
  $handler->display->display_options['style_options']['default'] = 'changed_5';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
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
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed_5' => array(
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
    'changed_6' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
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
    'status_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed_2' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status_3' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed_3' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status_4' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed_4' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
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
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results found matching current search criteria (content may be not translatable).';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Relationship: Entity translation EN */
  $handler->display->display_options['relationships']['entity_translations_5']['id'] = 'entity_translations_5';
  $handler->display->display_options['relationships']['entity_translations_5']['table'] = 'node';
  $handler->display->display_options['relationships']['entity_translations_5']['field'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations_5']['ui_name'] = 'Entity translation EN';
  $handler->display->display_options['relationships']['entity_translations_5']['label'] = 'Entity translation EN';
  /* Relationship: Entity translation FR */
  $handler->display->display_options['relationships']['entity_translations_3']['id'] = 'entity_translations_3';
  $handler->display->display_options['relationships']['entity_translations_3']['table'] = 'node';
  $handler->display->display_options['relationships']['entity_translations_3']['field'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations_3']['ui_name'] = 'Entity translation FR';
  $handler->display->display_options['relationships']['entity_translations_3']['label'] = 'Entity translation FR';
  /* Relationship: Entity translation DE */
  $handler->display->display_options['relationships']['entity_translations_2']['id'] = 'entity_translations_2';
  $handler->display->display_options['relationships']['entity_translations_2']['table'] = 'node';
  $handler->display->display_options['relationships']['entity_translations_2']['field'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations_2']['ui_name'] = 'Entity translation DE';
  $handler->display->display_options['relationships']['entity_translations_2']['label'] = 'Entity translation DE';
  /* Relationship: Entity translation IT */
  $handler->display->display_options['relationships']['entity_translations_1']['id'] = 'entity_translations_1';
  $handler->display->display_options['relationships']['entity_translations_1']['table'] = 'node';
  $handler->display->display_options['relationships']['entity_translations_1']['field'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations_1']['ui_name'] = 'Entity translation IT';
  $handler->display->display_options['relationships']['entity_translations_1']['label'] = 'Entity translation IT';
  /* Relationship: Entity translation ES */
  $handler->display->display_options['relationships']['entity_translations']['id'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['table'] = 'node';
  $handler->display->display_options['relationships']['entity_translations']['field'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['ui_name'] = 'Entity translation ES';
  $handler->display->display_options['relationships']['entity_translations']['label'] = 'Entity translation ES';
  /* Relationship: Entity translation PL */
  $handler->display->display_options['relationships']['entity_translations_4']['id'] = 'entity_translations_4';
  $handler->display->display_options['relationships']['entity_translations_4']['table'] = 'node';
  $handler->display->display_options['relationships']['entity_translations_4']['field'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations_4']['ui_name'] = 'Entity translation PL';
  $handler->display->display_options['relationships']['entity_translations_4']['label'] = 'Entity translation PL';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'ID';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Source title (EN)';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]/translate';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created on';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m/y H:i:s';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed_5']['id'] = 'changed_5';
  $handler->display->display_options['fields']['changed_5']['table'] = 'node';
  $handler->display->display_options['fields']['changed_5']['field'] = 'changed';
  $handler->display->display_options['fields']['changed_5']['label'] = 'Updated on';
  $handler->display->display_options['fields']['changed_5']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed_5']['custom_date_format'] = 'd/m/y H:i:s';
  $handler->display->display_options['fields']['changed_5']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Content type';
  /* Field: Last update (EN) */
  $handler->display->display_options['fields']['changed_6']['id'] = 'changed_6';
  $handler->display->display_options['fields']['changed_6']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['changed_6']['field'] = 'changed';
  $handler->display->display_options['fields']['changed_6']['relationship'] = 'entity_translations_5';
  $handler->display->display_options['fields']['changed_6']['ui_name'] = 'Last update (EN)';
  $handler->display->display_options['fields']['changed_6']['label'] = 'Last Update (EN)';
  $handler->display->display_options['fields']['changed_6']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed_6']['custom_date_format'] = 'd/m/y H:i:s';
  $handler->display->display_options['fields']['changed_6']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Translation status (FR) */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'entity_translations_3';
  $handler->display->display_options['fields']['status']['ui_name'] = 'Translation status (FR)';
  $handler->display->display_options['fields']['status']['label'] = 'Translation status (FR)';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Last update (FR) */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['relationship'] = 'entity_translations_3';
  $handler->display->display_options['fields']['changed']['ui_name'] = 'Last update (FR)';
  $handler->display->display_options['fields']['changed']['label'] = 'Last update (FR)';
  $handler->display->display_options['fields']['changed']['empty'] = '[status]';
  $handler->display->display_options['fields']['changed']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'd/m/y H:i:s';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Translation status (DE) */
  $handler->display->display_options['fields']['status_1']['id'] = 'status_1';
  $handler->display->display_options['fields']['status_1']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['status_1']['field'] = 'status';
  $handler->display->display_options['fields']['status_1']['relationship'] = 'entity_translations_2';
  $handler->display->display_options['fields']['status_1']['ui_name'] = 'Translation status (DE)';
  $handler->display->display_options['fields']['status_1']['label'] = 'Translation status (DE)';
  $handler->display->display_options['fields']['status_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status_1']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['status_1']['not'] = 0;
  /* Field: Last update (DE) */
  $handler->display->display_options['fields']['changed_1']['id'] = 'changed_1';
  $handler->display->display_options['fields']['changed_1']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['changed_1']['field'] = 'changed';
  $handler->display->display_options['fields']['changed_1']['relationship'] = 'entity_translations_2';
  $handler->display->display_options['fields']['changed_1']['ui_name'] = 'Last update (DE)';
  $handler->display->display_options['fields']['changed_1']['label'] = 'Last update (DE)';
  $handler->display->display_options['fields']['changed_1']['empty'] = '[status_1]';
  $handler->display->display_options['fields']['changed_1']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['changed_1']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed_1']['custom_date_format'] = 'd/m/y H:i:s';
  $handler->display->display_options['fields']['changed_1']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Translation status (IT) */
  $handler->display->display_options['fields']['status_2']['id'] = 'status_2';
  $handler->display->display_options['fields']['status_2']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['status_2']['field'] = 'status';
  $handler->display->display_options['fields']['status_2']['relationship'] = 'entity_translations_1';
  $handler->display->display_options['fields']['status_2']['ui_name'] = 'Translation status (IT)';
  $handler->display->display_options['fields']['status_2']['label'] = 'Translation status (IT)';
  $handler->display->display_options['fields']['status_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status_2']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['status_2']['not'] = 0;
  /* Field: Last update (IT) */
  $handler->display->display_options['fields']['changed_2']['id'] = 'changed_2';
  $handler->display->display_options['fields']['changed_2']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['changed_2']['field'] = 'changed';
  $handler->display->display_options['fields']['changed_2']['relationship'] = 'entity_translations_1';
  $handler->display->display_options['fields']['changed_2']['ui_name'] = 'Last update (IT)';
  $handler->display->display_options['fields']['changed_2']['label'] = 'Last update (IT)';
  $handler->display->display_options['fields']['changed_2']['empty'] = '[status_2]';
  $handler->display->display_options['fields']['changed_2']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['changed_2']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed_2']['custom_date_format'] = 'd/m/y H:i:s';
  $handler->display->display_options['fields']['changed_2']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Translation status (ES) */
  $handler->display->display_options['fields']['status_3']['id'] = 'status_3';
  $handler->display->display_options['fields']['status_3']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['status_3']['field'] = 'status';
  $handler->display->display_options['fields']['status_3']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['status_3']['ui_name'] = 'Translation status (ES)';
  $handler->display->display_options['fields']['status_3']['label'] = 'Translation status (ES)';
  $handler->display->display_options['fields']['status_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status_3']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['status_3']['not'] = 0;
  /* Field: Last update (ES) */
  $handler->display->display_options['fields']['changed_3']['id'] = 'changed_3';
  $handler->display->display_options['fields']['changed_3']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['changed_3']['field'] = 'changed';
  $handler->display->display_options['fields']['changed_3']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['changed_3']['ui_name'] = 'Last update (ES)';
  $handler->display->display_options['fields']['changed_3']['label'] = 'Last update (ES)';
  $handler->display->display_options['fields']['changed_3']['empty'] = '[status_3]';
  $handler->display->display_options['fields']['changed_3']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['changed_3']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed_3']['custom_date_format'] = 'd/m/y H:i:s';
  $handler->display->display_options['fields']['changed_3']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Translation status (PL) */
  $handler->display->display_options['fields']['status_4']['id'] = 'status_4';
  $handler->display->display_options['fields']['status_4']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['status_4']['field'] = 'status';
  $handler->display->display_options['fields']['status_4']['relationship'] = 'entity_translations_4';
  $handler->display->display_options['fields']['status_4']['ui_name'] = 'Translation status (PL)';
  $handler->display->display_options['fields']['status_4']['label'] = 'Translation status (PL)';
  $handler->display->display_options['fields']['status_4']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status_4']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['status_4']['not'] = 0;
  /* Field: Last update (PL) */
  $handler->display->display_options['fields']['changed_4']['id'] = 'changed_4';
  $handler->display->display_options['fields']['changed_4']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['changed_4']['field'] = 'changed';
  $handler->display->display_options['fields']['changed_4']['relationship'] = 'entity_translations_4';
  $handler->display->display_options['fields']['changed_4']['ui_name'] = 'Last update (PL)';
  $handler->display->display_options['fields']['changed_4']['label'] = 'Last update (PL)';
  $handler->display->display_options['fields']['changed_4']['empty'] = '[status_4]';
  $handler->display->display_options['fields']['changed_4']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['changed_4']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed_4']['custom_date_format'] = 'd/m/y H:i:s';
  $handler->display->display_options['fields']['changed_4']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Filter criterion: Filter by title */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['ui_name'] = 'Filter by title';
  $handler->display->display_options['filters']['title_field_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_field_value']['group'] = 1;
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Filter by title';
  $handler->display->display_options['filters']['title_field_value']['expose']['description'] = 'Filter is available in any language.';
  $handler->display->display_options['filters']['title_field_value']['expose']['operator'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
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
    16 => 0,
  );
  $handler->display->display_options['filters']['title_field_value']['group_info']['label'] = 'Title (title_field)';
  $handler->display->display_options['filters']['title_field_value']['group_info']['identifier'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['title_field_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Filter by type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['ui_name'] = 'Filter by type';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Filter by type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
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
    16 => 0,
  );
  /* Filter criterion: Entity translation: Created */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['relationship'] = 'entity_translations_5';
  $handler->display->display_options['filters']['created']['operator'] = 'not empty';
  $handler->display->display_options['filters']['created']['group'] = 1;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter_1']['group'] = 1;
  $handler->display->display_options['filters']['date_filter_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator_id'] = 'created_date_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['label'] = 'Created';
  $handler->display->display_options['filters']['date_filter_1']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['identifier'] = 'created_date';
  $handler->display->display_options['filters']['date_filter_1']['expose']['remember_roles'] = array(
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
    16 => 0,
  );
  $handler->display->display_options['filters']['date_filter_1']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter_1']['year_range'] = '-5:+0';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'updated_date_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Updated';
  $handler->display->display_options['filters']['date_filter']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'updated_date';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
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
    16 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-5:+0';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node.changed' => 'node.changed',
  );
  /* Filter criterion: Last update (EN) */
  $handler->display->display_options['filters']['date_filter_2']['id'] = 'date_filter_2';
  $handler->display->display_options['filters']['date_filter_2']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['date_filter_2']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_2']['relationship'] = 'entity_translations_5';
  $handler->display->display_options['filters']['date_filter_2']['ui_name'] = 'Last update (EN)';
  $handler->display->display_options['filters']['date_filter_2']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter_2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter_2']['expose']['operator_id'] = 'last_update_en_op';
  $handler->display->display_options['filters']['date_filter_2']['expose']['label'] = 'Last Update (EN)';
  $handler->display->display_options['filters']['date_filter_2']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['date_filter_2']['expose']['operator'] = 'date_filter_2_op';
  $handler->display->display_options['filters']['date_filter_2']['expose']['identifier'] = 'last_update_en';
  $handler->display->display_options['filters']['date_filter_2']['expose']['remember_roles'] = array(
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
    16 => 0,
    17 => 0,
  );
  $handler->display->display_options['filters']['date_filter_2']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter_2']['year_range'] = '-5:+0';
  $handler->display->display_options['filters']['date_filter_2']['date_fields'] = array(
    'entity_translation.changed' => 'entity_translation.changed',
  );

  /* Display: Translated content */
  $handler = $view->new_display('page', 'Translated content', 'translated_content_list');
  $handler->display->display_options['display_description'] = 'Shows a list of translated content in available langauges.';
  $handler->display->display_options['field_language'] = '***DEFAULT_LANGUAGE***';
  $handler->display->display_options['field_language_add_to_query'] = 0;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<div class="description"><strong>*</strong> The column <strong>"Updated on"</strong> shows the date of the last revision of the node, including also those ones in "draft" status; while the other columns show the date of the translation in the various languages, considering only the published revisions.</div>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'ID';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Source title (EN)';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]/translate';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created on';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m/y H:i:s';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed_5']['id'] = 'changed_5';
  $handler->display->display_options['fields']['changed_5']['table'] = 'node';
  $handler->display->display_options['fields']['changed_5']['field'] = 'changed';
  $handler->display->display_options['fields']['changed_5']['label'] = 'Updated on *';
  $handler->display->display_options['fields']['changed_5']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed_5']['custom_date_format'] = 'd/m/y H:i:s';
  $handler->display->display_options['fields']['changed_5']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Content type';
  /* Field: Last update (EN) */
  $handler->display->display_options['fields']['changed_6']['id'] = 'changed_6';
  $handler->display->display_options['fields']['changed_6']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['changed_6']['field'] = 'changed';
  $handler->display->display_options['fields']['changed_6']['relationship'] = 'entity_translations_5';
  $handler->display->display_options['fields']['changed_6']['ui_name'] = 'Last update (EN)';
  $handler->display->display_options['fields']['changed_6']['label'] = 'Last Update (EN)';
  $handler->display->display_options['fields']['changed_6']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed_6']['custom_date_format'] = 'd/m/y H:i:s';
  $handler->display->display_options['fields']['changed_6']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Translation status (FR) */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'entity_translations_3';
  $handler->display->display_options['fields']['status']['ui_name'] = 'Translation status (FR)';
  $handler->display->display_options['fields']['status']['label'] = 'Translation status (FR)';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Last update (FR) */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['relationship'] = 'entity_translations_3';
  $handler->display->display_options['fields']['changed']['ui_name'] = 'Last update (FR)';
  $handler->display->display_options['fields']['changed']['label'] = 'Last update (FR)';
  $handler->display->display_options['fields']['changed']['empty'] = '[status]';
  $handler->display->display_options['fields']['changed']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'd/m/y H:i:s';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Translation status (DE) */
  $handler->display->display_options['fields']['status_1']['id'] = 'status_1';
  $handler->display->display_options['fields']['status_1']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['status_1']['field'] = 'status';
  $handler->display->display_options['fields']['status_1']['relationship'] = 'entity_translations_2';
  $handler->display->display_options['fields']['status_1']['ui_name'] = 'Translation status (DE)';
  $handler->display->display_options['fields']['status_1']['label'] = 'Translation status (DE)';
  $handler->display->display_options['fields']['status_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status_1']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['status_1']['not'] = 0;
  /* Field: Last update (DE) */
  $handler->display->display_options['fields']['changed_1']['id'] = 'changed_1';
  $handler->display->display_options['fields']['changed_1']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['changed_1']['field'] = 'changed';
  $handler->display->display_options['fields']['changed_1']['relationship'] = 'entity_translations_2';
  $handler->display->display_options['fields']['changed_1']['ui_name'] = 'Last update (DE)';
  $handler->display->display_options['fields']['changed_1']['label'] = 'Last update (DE)';
  $handler->display->display_options['fields']['changed_1']['empty'] = '[status_1]';
  $handler->display->display_options['fields']['changed_1']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['changed_1']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed_1']['custom_date_format'] = 'd/m/y H:i:s';
  $handler->display->display_options['fields']['changed_1']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Translation status (IT) */
  $handler->display->display_options['fields']['status_2']['id'] = 'status_2';
  $handler->display->display_options['fields']['status_2']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['status_2']['field'] = 'status';
  $handler->display->display_options['fields']['status_2']['relationship'] = 'entity_translations_1';
  $handler->display->display_options['fields']['status_2']['ui_name'] = 'Translation status (IT)';
  $handler->display->display_options['fields']['status_2']['label'] = 'Translation status (IT)';
  $handler->display->display_options['fields']['status_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status_2']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['status_2']['not'] = 0;
  /* Field: Last update (IT) */
  $handler->display->display_options['fields']['changed_2']['id'] = 'changed_2';
  $handler->display->display_options['fields']['changed_2']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['changed_2']['field'] = 'changed';
  $handler->display->display_options['fields']['changed_2']['relationship'] = 'entity_translations_1';
  $handler->display->display_options['fields']['changed_2']['ui_name'] = 'Last update (IT)';
  $handler->display->display_options['fields']['changed_2']['label'] = 'Last update (IT)';
  $handler->display->display_options['fields']['changed_2']['empty'] = '[status_2]';
  $handler->display->display_options['fields']['changed_2']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['changed_2']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed_2']['custom_date_format'] = 'd/m/y H:i:s';
  $handler->display->display_options['fields']['changed_2']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Translation status (ES) */
  $handler->display->display_options['fields']['status_3']['id'] = 'status_3';
  $handler->display->display_options['fields']['status_3']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['status_3']['field'] = 'status';
  $handler->display->display_options['fields']['status_3']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['status_3']['ui_name'] = 'Translation status (ES)';
  $handler->display->display_options['fields']['status_3']['label'] = 'Translation status (ES)';
  $handler->display->display_options['fields']['status_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status_3']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['status_3']['not'] = 0;
  /* Field: Last update (ES) */
  $handler->display->display_options['fields']['changed_3']['id'] = 'changed_3';
  $handler->display->display_options['fields']['changed_3']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['changed_3']['field'] = 'changed';
  $handler->display->display_options['fields']['changed_3']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['changed_3']['ui_name'] = 'Last update (ES)';
  $handler->display->display_options['fields']['changed_3']['label'] = 'Last update (ES)';
  $handler->display->display_options['fields']['changed_3']['empty'] = '[status_3]';
  $handler->display->display_options['fields']['changed_3']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['changed_3']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed_3']['custom_date_format'] = 'd/m/y H:i:s';
  $handler->display->display_options['fields']['changed_3']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Translation status (PL) */
  $handler->display->display_options['fields']['status_4']['id'] = 'status_4';
  $handler->display->display_options['fields']['status_4']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['status_4']['field'] = 'status';
  $handler->display->display_options['fields']['status_4']['relationship'] = 'entity_translations_4';
  $handler->display->display_options['fields']['status_4']['ui_name'] = 'Translation status (PL)';
  $handler->display->display_options['fields']['status_4']['label'] = 'Translation status (PL)';
  $handler->display->display_options['fields']['status_4']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status_4']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['status_4']['not'] = 0;
  /* Field: Last update (PL) */
  $handler->display->display_options['fields']['changed_4']['id'] = 'changed_4';
  $handler->display->display_options['fields']['changed_4']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['changed_4']['field'] = 'changed';
  $handler->display->display_options['fields']['changed_4']['relationship'] = 'entity_translations_4';
  $handler->display->display_options['fields']['changed_4']['ui_name'] = 'Last update (PL)';
  $handler->display->display_options['fields']['changed_4']['label'] = 'Last update (PL)';
  $handler->display->display_options['fields']['changed_4']['empty'] = '[status_4]';
  $handler->display->display_options['fields']['changed_4']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['changed_4']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed_4']['custom_date_format'] = 'd/m/y H:i:s';
  $handler->display->display_options['fields']['changed_4']['second_date_format'] = 'enrd_lag_database_d_m_y';
  $handler->display->display_options['path'] = 'admin/tmgmt/translation-report';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Content translation report';
  $handler->display->display_options['menu']['description'] = 'Shows the status of existing content translations.';
  $handler->display->display_options['menu']['weight'] = '12';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'translated_content_export');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xlsx';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'Content translation report.xlsx';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'ID';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Source title (EN)';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created on';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m/y H:i:s';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed_5']['id'] = 'changed_5';
  $handler->display->display_options['fields']['changed_5']['table'] = 'node';
  $handler->display->display_options['fields']['changed_5']['field'] = 'changed';
  $handler->display->display_options['fields']['changed_5']['label'] = 'Updated on';
  $handler->display->display_options['fields']['changed_5']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed_5']['custom_date_format'] = 'd/m/y H:i:s';
  $handler->display->display_options['fields']['changed_5']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Content type';
  /* Field: Last Update (EN) */
  $handler->display->display_options['fields']['changed_6']['id'] = 'changed_6';
  $handler->display->display_options['fields']['changed_6']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['changed_6']['field'] = 'changed';
  $handler->display->display_options['fields']['changed_6']['relationship'] = 'entity_translations_5';
  $handler->display->display_options['fields']['changed_6']['ui_name'] = 'Last Update (EN)';
  $handler->display->display_options['fields']['changed_6']['label'] = 'Last update (EN)';
  $handler->display->display_options['fields']['changed_6']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed_6']['custom_date_format'] = 'd/m/y H:i:s';
  $handler->display->display_options['fields']['changed_6']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Translation status (FR) */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'entity_translations_3';
  $handler->display->display_options['fields']['status']['ui_name'] = 'Translation status (FR)';
  $handler->display->display_options['fields']['status']['label'] = 'Translation status (FR)';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Last update (FR) */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['relationship'] = 'entity_translations_3';
  $handler->display->display_options['fields']['changed']['ui_name'] = 'Last update (FR)';
  $handler->display->display_options['fields']['changed']['label'] = 'Last update (FR)';
  $handler->display->display_options['fields']['changed']['empty'] = '[status]';
  $handler->display->display_options['fields']['changed']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'd/m/y H:i:s';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Entity translation: Translation status */
  $handler->display->display_options['fields']['status_1']['id'] = 'status_1';
  $handler->display->display_options['fields']['status_1']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['status_1']['field'] = 'status';
  $handler->display->display_options['fields']['status_1']['relationship'] = 'entity_translations_2';
  $handler->display->display_options['fields']['status_1']['label'] = 'Translation status (DE)';
  $handler->display->display_options['fields']['status_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status_1']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['status_1']['not'] = 0;
  /* Field: Last update (DE) */
  $handler->display->display_options['fields']['changed_1']['id'] = 'changed_1';
  $handler->display->display_options['fields']['changed_1']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['changed_1']['field'] = 'changed';
  $handler->display->display_options['fields']['changed_1']['relationship'] = 'entity_translations_2';
  $handler->display->display_options['fields']['changed_1']['ui_name'] = 'Last update (DE)';
  $handler->display->display_options['fields']['changed_1']['label'] = 'Last update (DE)';
  $handler->display->display_options['fields']['changed_1']['empty'] = '[status_1]';
  $handler->display->display_options['fields']['changed_1']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['changed_1']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed_1']['custom_date_format'] = 'd/m/y H:i:s';
  $handler->display->display_options['fields']['changed_1']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Translation status (IT) */
  $handler->display->display_options['fields']['status_2']['id'] = 'status_2';
  $handler->display->display_options['fields']['status_2']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['status_2']['field'] = 'status';
  $handler->display->display_options['fields']['status_2']['relationship'] = 'entity_translations_1';
  $handler->display->display_options['fields']['status_2']['ui_name'] = 'Translation status (IT)';
  $handler->display->display_options['fields']['status_2']['label'] = 'Translation status (IT)';
  $handler->display->display_options['fields']['status_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status_2']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['status_2']['not'] = 0;
  /* Field: Last update (IT) */
  $handler->display->display_options['fields']['changed_2']['id'] = 'changed_2';
  $handler->display->display_options['fields']['changed_2']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['changed_2']['field'] = 'changed';
  $handler->display->display_options['fields']['changed_2']['relationship'] = 'entity_translations_1';
  $handler->display->display_options['fields']['changed_2']['ui_name'] = 'Last update (IT)';
  $handler->display->display_options['fields']['changed_2']['label'] = 'Last update (IT)';
  $handler->display->display_options['fields']['changed_2']['empty'] = '[status_2]';
  $handler->display->display_options['fields']['changed_2']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['changed_2']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed_2']['custom_date_format'] = 'd/m/y H:i:s';
  $handler->display->display_options['fields']['changed_2']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Translation status (ES) */
  $handler->display->display_options['fields']['status_3']['id'] = 'status_3';
  $handler->display->display_options['fields']['status_3']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['status_3']['field'] = 'status';
  $handler->display->display_options['fields']['status_3']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['status_3']['ui_name'] = 'Translation status (ES)';
  $handler->display->display_options['fields']['status_3']['label'] = 'Translation status (ES)';
  $handler->display->display_options['fields']['status_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status_3']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['status_3']['not'] = 0;
  /* Field: Last update (ES) */
  $handler->display->display_options['fields']['changed_3']['id'] = 'changed_3';
  $handler->display->display_options['fields']['changed_3']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['changed_3']['field'] = 'changed';
  $handler->display->display_options['fields']['changed_3']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['changed_3']['ui_name'] = 'Last update (ES)';
  $handler->display->display_options['fields']['changed_3']['label'] = 'Last update (ES)';
  $handler->display->display_options['fields']['changed_3']['empty'] = '[status_3]';
  $handler->display->display_options['fields']['changed_3']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['changed_3']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed_3']['custom_date_format'] = 'd/m/y H:i:s';
  $handler->display->display_options['fields']['changed_3']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Translation status (PL) */
  $handler->display->display_options['fields']['status_4']['id'] = 'status_4';
  $handler->display->display_options['fields']['status_4']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['status_4']['field'] = 'status';
  $handler->display->display_options['fields']['status_4']['relationship'] = 'entity_translations_4';
  $handler->display->display_options['fields']['status_4']['ui_name'] = 'Translation status (PL)';
  $handler->display->display_options['fields']['status_4']['label'] = 'Translation status (PL)';
  $handler->display->display_options['fields']['status_4']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status_4']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['status_4']['not'] = 0;
  /* Field: Last update (PL) */
  $handler->display->display_options['fields']['changed_4']['id'] = 'changed_4';
  $handler->display->display_options['fields']['changed_4']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['changed_4']['field'] = 'changed';
  $handler->display->display_options['fields']['changed_4']['relationship'] = 'entity_translations_4';
  $handler->display->display_options['fields']['changed_4']['ui_name'] = 'Last update (PL)';
  $handler->display->display_options['fields']['changed_4']['label'] = 'Last update (PL)';
  $handler->display->display_options['fields']['changed_4']['empty'] = '[status_4]';
  $handler->display->display_options['fields']['changed_4']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['changed_4']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed_4']['custom_date_format'] = 'd/m/y H:i:s';
  $handler->display->display_options['fields']['changed_4']['second_date_format'] = 'enrd_lag_database_d_m_y';
  $handler->display->display_options['path'] = 'admin/enrd/content/translation-report/export';
  $handler->display->display_options['displays'] = array(
    'translated_content_list' => 'translated_content_list',
    'default' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'admin/tmgmt/translation-report';
  $handler->display->display_options['segment_size'] = '50';
  $export['enrd_content_translation_report'] = $view;

  return $export;
}
