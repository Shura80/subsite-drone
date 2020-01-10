<?php

/**
 * @file
 * enrd_taxonomies.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function enrd_taxonomies_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'enrd_custom_rss_feed';
  $view->description = 'Generate custom Content RSS Feed by selecting taxonomy exposed filter(s).';
  $view->tag = 'ENRD Taxonomies';
  $view->base_table = 'node';
  $view->human_name = 'ENRD Custom RSS Feed';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Content Feed';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'page';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'input_required';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['text_input_required'] = '';
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'full_html';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Workbench Moderation: Published */
  $handler->display->display_options['filters']['published']['id'] = 'published';
  $handler->display->display_options['filters']['published']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['published']['field'] = 'published';
  $handler->display->display_options['filters']['published']['value'] = '1';
  $handler->display->display_options['filters']['published']['group'] = 1;
  /* Filter criterion: Content: Has taxonomy terms (with depth, translated) */
  $handler->display->display_options['filters']['term_node_tid_depth_i18n']['id'] = 'term_node_tid_depth_i18n';
  $handler->display->display_options['filters']['term_node_tid_depth_i18n']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth_i18n']['field'] = 'term_node_tid_depth_i18n';
  $handler->display->display_options['filters']['term_node_tid_depth_i18n']['group'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth_i18n']['expose']['operator_id'] = 'term_node_tid_depth_i18n_op';
  $handler->display->display_options['filters']['term_node_tid_depth_i18n']['expose']['label'] = 'Topics';
  $handler->display->display_options['filters']['term_node_tid_depth_i18n']['expose']['operator'] = 'term_node_tid_depth_i18n_op';
  $handler->display->display_options['filters']['term_node_tid_depth_i18n']['expose']['identifier'] = 'topics';
  $handler->display->display_options['filters']['term_node_tid_depth_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth_i18n']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['term_node_tid_depth_i18n']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth_i18n']['vocabulary'] = 'enrd_transversal_topics';
  $handler->display->display_options['filters']['term_node_tid_depth_i18n']['error_message'] = FALSE;
  $handler->display->display_options['filters']['term_node_tid_depth_i18n']['depth'] = '0';
  /* Filter criterion: Content: Has taxonomy terms (with depth, translated) */
  $handler->display->display_options['filters']['term_node_tid_depth_i18n_1']['id'] = 'term_node_tid_depth_i18n_1';
  $handler->display->display_options['filters']['term_node_tid_depth_i18n_1']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth_i18n_1']['field'] = 'term_node_tid_depth_i18n';
  $handler->display->display_options['filters']['term_node_tid_depth_i18n_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth_i18n_1']['expose']['operator_id'] = 'term_node_tid_depth_i18n_1_op';
  $handler->display->display_options['filters']['term_node_tid_depth_i18n_1']['expose']['label'] = 'Countries';
  $handler->display->display_options['filters']['term_node_tid_depth_i18n_1']['expose']['operator'] = 'term_node_tid_depth_i18n_1_op';
  $handler->display->display_options['filters']['term_node_tid_depth_i18n_1']['expose']['identifier'] = 'countries';
  $handler->display->display_options['filters']['term_node_tid_depth_i18n_1']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth_i18n_1']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['term_node_tid_depth_i18n_1']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth_i18n_1']['vocabulary'] = 'enrd_countries';
  $handler->display->display_options['filters']['term_node_tid_depth_i18n_1']['hierarchy'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth_i18n_1']['error_message'] = FALSE;
  $handler->display->display_options['filters']['term_node_tid_depth_i18n_1']['depth'] = '4';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'Select one or more elements from the filters below to retrieve the specific RSS link.';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'rss/content';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'ENRD content';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'feed';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['style_options']['description'] = 'Latest updates about ENRD content';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'rss/content/feed';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $export['enrd_custom_rss_feed'] = $view;

  $view = new view();
  $view->name = 'taxonomy_node_tagging';
  $view->description = 'Bulk operations on nodes';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Tagging';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Content tagging';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '5';
  $handler->display->display_options['pager']['options']['tags']['first'] = '«';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹';
  $handler->display->display_options['pager']['options']['tags']['next'] = '›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '»';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There is no content to display.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';

  /* Display: Content tagging */
  $handler = $view->new_display('page', 'Content tagging', 'page');
  $handler->display->display_options['display_description'] = 'Allows to tag content with classification taxonomies';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer nodes';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'type' => 'type',
    'language' => 'language',
    'status' => 'status',
    'changed' => 'changed',
    'body' => 'title',
    'field_tags' => 'field_tags',
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => 'views-align-left',
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
    'language' => array(
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
    'changed' => array(
      'sortable' => 1,
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
    'field_tags' => array(
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
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['label'] = 'AUTHOR';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'OPERATIONS';
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
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Manage taxonomy terms',
      'settings' => array(
        'show_all_tokens' => 0,
        'display_values' => array(
          'article::field_tax_country' => 'article::field_tax_country',
          'article::field_tax_evaluation' => 'article::field_tax_evaluation',
          'article::field_tax_networking' => 'article::field_tax_networking',
          'article::field_tax_origin' => 'article::field_tax_origin',
          'article::field_tax_rural_dev_policy' => 'article::field_tax_rural_dev_policy',
          'article::field_tax_translation_status' => 'article::field_tax_translation_status',
          'article::field_tax_transversal_topics' => 'article::field_tax_transversal_topics',
          'article::field_tax_update_status' => 'article::field_tax_update_status',
          'page::field_tax_country' => 'page::field_tax_country',
          'page::field_tax_evaluation' => 'page::field_tax_evaluation',
          'page::field_tax_networking' => 'page::field_tax_networking',
          'page::field_tax_origin' => 'page::field_tax_origin',
          'page::field_tax_rural_dev_policy' => 'page::field_tax_rural_dev_policy',
          'page::field_tax_translation_status' => 'page::field_tax_translation_status',
          'page::field_tax_transversal_topics' => 'page::field_tax_transversal_topics',
          'page::field_tax_update_status' => 'page::field_tax_update_status',
          'discussion::field_tax_country' => 'discussion::field_tax_country',
          'discussion::field_tax_evaluation' => 'discussion::field_tax_evaluation',
          'discussion::field_tax_networking' => 'discussion::field_tax_networking',
          'discussion::field_tax_origin' => 'discussion::field_tax_origin',
          'discussion::field_tax_rural_dev_policy' => 'discussion::field_tax_rural_dev_policy',
          'discussion::field_tax_translation_status' => 'discussion::field_tax_translation_status',
          'discussion::field_tax_transversal_topics' => 'discussion::field_tax_transversal_topics',
          'discussion::field_tax_update_status' => 'discussion::field_tax_update_status',
          'document::field_tax_country' => 'document::field_tax_country',
          'document::field_tax_evaluation' => 'document::field_tax_evaluation',
          'document::field_tax_networking' => 'document::field_tax_networking',
          'document::field_tax_origin' => 'document::field_tax_origin',
          'document::field_tax_rural_dev_policy' => 'document::field_tax_rural_dev_policy',
          'document::field_tax_translation_status' => 'document::field_tax_translation_status',
          'document::field_tax_transversal_topics' => 'document::field_tax_transversal_topics',
          'document::field_tax_update_status' => 'document::field_tax_update_status',
          'event::field_tax_country' => 'event::field_tax_country',
          'event::field_tax_evaluation' => 'event::field_tax_evaluation',
          'event::field_tax_networking' => 'event::field_tax_networking',
          'event::field_tax_origin' => 'event::field_tax_origin',
          'event::field_tax_rural_dev_policy' => 'event::field_tax_rural_dev_policy',
          'event::field_tax_translation_status' => 'event::field_tax_translation_status',
          'event::field_tax_transversal_topics' => 'event::field_tax_transversal_topics',
          'event::field_tax_update_status' => 'event::field_tax_update_status',
          'f_a_q::field_tax_country' => 'f_a_q::field_tax_country',
          'f_a_q::field_tax_evaluation' => 'f_a_q::field_tax_evaluation',
          'f_a_q::field_tax_networking' => 'f_a_q::field_tax_networking',
          'f_a_q::field_tax_origin' => 'f_a_q::field_tax_origin',
          'f_a_q::field_tax_rural_dev_policy' => 'f_a_q::field_tax_rural_dev_policy',
          'f_a_q::field_tax_translation_status' => 'f_a_q::field_tax_translation_status',
          'f_a_q::field_tax_transversal_topics' => 'f_a_q::field_tax_transversal_topics',
          'f_a_q::field_tax_update_status' => 'f_a_q::field_tax_update_status',
          'focus_group::field_tax_country' => 'focus_group::field_tax_country',
          'focus_group::field_tax_evaluation' => 'focus_group::field_tax_evaluation',
          'focus_group::field_tax_networking' => 'focus_group::field_tax_networking',
          'focus_group::field_tax_origin' => 'focus_group::field_tax_origin',
          'focus_group::field_tax_rural_dev_policy' => 'focus_group::field_tax_rural_dev_policy',
          'focus_group::field_tax_translation_status' => 'focus_group::field_tax_translation_status',
          'focus_group::field_tax_transversal_topics' => 'focus_group::field_tax_transversal_topics',
          'focus_group::field_tax_update_status' => 'focus_group::field_tax_update_status',
          'news::field_tax_country' => 'news::field_tax_country',
          'news::field_tax_evaluation' => 'news::field_tax_evaluation',
          'news::field_tax_networking' => 'news::field_tax_networking',
          'news::field_tax_origin' => 'news::field_tax_origin',
          'news::field_tax_rural_dev_policy' => 'news::field_tax_rural_dev_policy',
          'news::field_tax_translation_status' => 'news::field_tax_translation_status',
          'news::field_tax_transversal_topics' => 'news::field_tax_transversal_topics',
          'news::field_tax_update_status' => 'news::field_tax_update_status',
          'rdp_information::field_tax_country' => 'rdp_information::field_tax_country',
          'rdp_information::field_tax_evaluation' => 'rdp_information::field_tax_evaluation',
          'rdp_information::field_tax_networking' => 'rdp_information::field_tax_networking',
          'rdp_information::field_tax_origin' => 'rdp_information::field_tax_origin',
          'rdp_information::field_tax_rural_dev_policy' => 'rdp_information::field_tax_rural_dev_policy',
          'rdp_information::field_tax_translation_status' => 'rdp_information::field_tax_translation_status',
          'rdp_information::field_tax_transversal_topics' => 'rdp_information::field_tax_transversal_topics',
          'rdp_information::field_tax_update_status' => 'rdp_information::field_tax_update_status',
          'organization::field_tax_country' => 'organization::field_tax_country',
          'organization::field_tax_evaluation' => 'organization::field_tax_evaluation',
          'organization::field_tax_networking' => 'organization::field_tax_networking',
          'organization::field_tax_origin' => 'organization::field_tax_origin',
          'organization::field_tax_rural_dev_policy' => 'organization::field_tax_rural_dev_policy',
          'organization::field_tax_translation_status' => 'organization::field_tax_translation_status',
          'organization::field_tax_transversal_topics' => 'organization::field_tax_transversal_topics',
          'organization::field_tax_update_status' => 'organization::field_tax_update_status',
        ),
      ),
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
  $handler->display->display_options['fields']['title']['label'] = 'TITLE';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'TYPE';
  /* Field: Content: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'node';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  $handler->display->display_options['fields']['language']['label'] = 'LANGUAGE';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'PUBLISHED';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'UPDATED';
  $handler->display->display_options['fields']['changed']['date_format'] = 'archive_F_Y';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'archive_F_Y';
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = 'TAXONOMY TERMS';
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'forums' => 0,
    'classification' => 0,
    'ec_world_countries' => 0,
    'enrd_countries' => 0,
    'enrd_meetings_events' => 0,
    'enrd_themes' => 0,
    'enrd_evaluation' => 0,
    'event_categories' => 0,
    'faq_categories' => 0,
    'idea_categories' => 0,
    'enrd_languages' => 0,
    'media_categories_images' => 0,
    'media_catgories_videos' => 0,
    'media_tags' => 0,
    'enrd_networking' => 0,
    'newsletter' => 0,
    'organization_type' => 0,
    'resources' => 0,
    'enrd_rural_development_policy' => 0,
    'subsites' => 0,
    'tags' => 0,
    'tool_audience' => 0,
    'tool_categories' => 0,
    'enrd_transversal_topics' => 0,
    'enrd_update_status' => 0,
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'AUTHOR';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
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
    10 => 0,
    7 => 0,
    6 => 0,
    8 => 0,
    9 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
    'discussion' => 'discussion',
    'document' => 'document',
    'event' => 'event',
    'f_a_q' => 'f_a_q',
    'focus_group' => 'focus_group',
    'news' => 'news',
    'organization' => 'organization',
    'page' => 'page',
    'rdp_information' => 'rdp_information',
  );
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    10 => 0,
    7 => 0,
    6 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    10 => 0,
    7 => 0,
    6 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['path'] = 'admin/enrd/content/tagging';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Content tagging';
  $handler->display->display_options['menu']['description'] = 'Allows to tag content with classification taxonomies';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['taxonomy_node_tagging'] = $view;

  return $export;
}
