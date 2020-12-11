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
  $view->name = 'enrd_taxonomies_countries_eu';
  $view->description = 'List only "European Union" Countries, to be used in a field widget.';
  $view->tag = 'ENRD Taxonomies';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'ENRD Countries: show only EU countries';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'enrd_countries' => 'enrd_countries',
  );
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'parent';
  $handler->display->display_options['filters']['name']['value'] = 'European union';
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name_1']['id'] = 'name_1';
  $handler->display->display_options['filters']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name_1']['field'] = 'name';
  $handler->display->display_options['filters']['name_1']['operator'] = '!=';
  $handler->display->display_options['filters']['name_1']['value'] = 'United Kingdom';

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_eu_countries');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Entity Reference View Widget */
  $handler = $view->new_display('entityreference_view_widget', 'Entity Reference View Widget', 'entityreference_eu_widget');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['enrd_taxonomies_countries_eu'] = $view;

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
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'full_html',
        ),
      ),
      'allow_secondary' => 1,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'title' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'type' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'language' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'status' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_tax_country_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_select_all_none_nested' => FALSE,
        'bef_term_description' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 1,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_tax_languages_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 1,
        'any_label' => '',
        'bef_filter_description' => 'The "Language" field used to manually tag content.',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_tax_transversal_topics_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 1,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_tax_rural_dev_policy_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_select_all_none_nested' => FALSE,
        'bef_term_description' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 1,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_tax_evaluation_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_select_all_none_nested' => FALSE,
        'bef_term_description' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 1,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_tax_origin_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 1,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_tags_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_select_all_none_nested' => FALSE,
        'bef_term_description' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 1,
        'any_label' => '',
        'bef_filter_description' => 'the "Metadata" autocomplete field.',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
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
  $handler->display->display_options['empty']['area']['content'] = 'No content available to display.';
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
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Filter criterion: Content: Published status */
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
    'term_node_tid' => 'term_node_tid',
    'name' => 'name',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
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
    'term_node_tid' => array(
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
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Content author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['label'] = 'Author';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Operations';
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
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'log' => 0,
      ),
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Manage taxonomy terms',
      'settings' => array(
        'show_all_tokens' => 0,
        'display_values' => array(
          'article::field_tax_country' => 'article::field_tax_country',
          'article::field_tax_evaluation' => 'article::field_tax_evaluation',
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
          'rdp_information::field_tax_country' => 'rdp_information::field_tax_country',
          'rdp_information::field_tax_evaluation' => 'rdp_information::field_tax_evaluation',
          'rdp_information::field_tax_origin' => 'rdp_information::field_tax_origin',
          'rdp_information::field_tax_rural_dev_policy' => 'rdp_information::field_tax_rural_dev_policy',
          'rdp_information::field_tax_translation_status' => 'rdp_information::field_tax_translation_status',
          'rdp_information::field_tax_transversal_topics' => 'rdp_information::field_tax_transversal_topics',
          'rdp_information::field_tax_update_status' => 'rdp_information::field_tax_update_status',
          'discussion::field_tax_country' => 'discussion::field_tax_country',
          'discussion::field_tax_evaluation' => 'discussion::field_tax_evaluation',
          'discussion::field_tax_origin' => 'discussion::field_tax_origin',
          'discussion::field_tax_rural_dev_policy' => 'discussion::field_tax_rural_dev_policy',
          'discussion::field_tax_translation_status' => 'discussion::field_tax_translation_status',
          'discussion::field_tax_transversal_topics' => 'discussion::field_tax_transversal_topics',
          'discussion::field_tax_update_status' => 'discussion::field_tax_update_status',
          'document::field_tax_country' => 'document::field_tax_country',
          'document::field_tax_evaluation' => 'document::field_tax_evaluation',
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
          'f_a_q::field_tax_origin' => 'f_a_q::field_tax_origin',
          'f_a_q::field_tax_rural_dev_policy' => 'f_a_q::field_tax_rural_dev_policy',
          'f_a_q::field_tax_translation_status' => 'f_a_q::field_tax_translation_status',
          'f_a_q::field_tax_transversal_topics' => 'f_a_q::field_tax_transversal_topics',
          'f_a_q::field_tax_update_status' => 'f_a_q::field_tax_update_status',
          'focus_group::field_tax_country' => 'focus_group::field_tax_country',
          'focus_group::field_tax_evaluation' => 'focus_group::field_tax_evaluation',
          'focus_group::field_tax_origin' => 'focus_group::field_tax_origin',
          'focus_group::field_tax_rural_dev_policy' => 'focus_group::field_tax_rural_dev_policy',
          'focus_group::field_tax_translation_status' => 'focus_group::field_tax_translation_status',
          'focus_group::field_tax_transversal_topics' => 'focus_group::field_tax_transversal_topics',
          'focus_group::field_tax_update_status' => 'focus_group::field_tax_update_status',
          'news::field_tax_country' => 'news::field_tax_country',
          'news::field_tax_evaluation' => 'news::field_tax_evaluation',
          'news::field_tax_origin' => 'news::field_tax_origin',
          'news::field_tax_rural_dev_policy' => 'news::field_tax_rural_dev_policy',
          'news::field_tax_translation_status' => 'news::field_tax_translation_status',
          'news::field_tax_transversal_topics' => 'news::field_tax_transversal_topics',
          'news::field_tax_update_status' => 'news::field_tax_update_status',
          'organization::field_tax_country' => 'organization::field_tax_country',
          'organization::field_tax_evaluation' => 'organization::field_tax_evaluation',
          'organization::field_tax_origin' => 'organization::field_tax_origin',
          'organization::field_tax_rural_dev_policy' => 'organization::field_tax_rural_dev_policy',
          'organization::field_tax_translation_status' => 'organization::field_tax_translation_status',
          'organization::field_tax_transversal_topics' => 'organization::field_tax_transversal_topics',
          'organization::field_tax_update_status' => 'organization::field_tax_update_status',
        ),
      ),
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
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
  /* Field: Content: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'node';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  /* Field: Content: Published status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'archive_F_Y';
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = 'Taxonomy terms';
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'forums' => 0,
    'budget_broad_areas' => 0,
    'classification' => 0,
    'ec_world_countries' => 0,
    'enrd_additional_keywords' => 0,
    'enrd_assets' => 0,
    'enrd_countries' => 0,
    'enrd_esi_funds' => 0,
    'enrd_esif_programme' => 0,
    'enrd_evaluation' => 0,
    'enrd_evaluation_content_type' => 0,
    'enrd_evaluation_theme' => 0,
    'enrd_evaluation_type' => 0,
    'enrd_key_themes_of_strategy' => 0,
    'enrd_languages' => 0,
    'enrd_networking' => 0,
    'enrd_origin' => 0,
    'enrd_physical_demographic_characteristics_of_lag_area' => 0,
    'enrd_programming_period' => 0,
    'enrd_project_types' => 0,
    'enrd_publications' => 0,
    'enrd_rdps' => 0,
    'enrd_resource_type' => 0,
    'enrd_rural_development_policy' => 0,
    'enrd_translation_status' => 0,
    'enrd_transversal_topics' => 0,
    'enrd_update_status' => 0,
    'eu_budget_mff_headings' => 0,
    'evaluation_theme' => 0,
    'event_types' => 0,
    'faq_categories' => 0,
    'focus_areas' => 0,
    'idea_categories' => 0,
    'measures' => 0,
    'media_tags' => 0,
    'metatags_ess_gf' => 0,
    'programme_name' => 0,
    'newsletter' => 0,
    'nuts_regions' => 0,
    'organization_type' => 0,
    'priority_focus_area_summaries' => 0,
    'project_key_words' => 0,
    'resources' => 0,
    'tags' => 0,
    'ec_priorities' => 0,
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  /* Field: Content: Link to edit content */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'edit';
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
    12 => 0,
    8 => 0,
    9 => 0,
    11 => 0,
    15 => 0,
    14 => 0,
    16 => 0,
    17 => 0,
    20 => 0,
    18 => 0,
    19 => 0,
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['group'] = 1;
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language']['expose']['description'] = 'The content language.';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
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
    20 => 0,
    18 => 0,
    19 => 0,
  );
  /* Filter criterion: Content: Published status */
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
    12 => 0,
    8 => 0,
    9 => 0,
    11 => 0,
    15 => 0,
    14 => 0,
    16 => 0,
    17 => 0,
    20 => 0,
    18 => 0,
    19 => 0,
  );
  /* Filter criterion: Field: Tags (field_tags) */
  $handler->display->display_options['filters']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['filters']['field_tags_tid']['field'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid']['expose']['operator_id'] = 'field_tags_tid_op';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['label'] = 'Tags';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['operator'] = 'field_tags_tid_op';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['identifier'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['remember_roles'] = array(
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
    20 => 0,
    18 => 0,
    19 => 0,
  );
  $handler->display->display_options['filters']['field_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_tags_tid']['vocabulary'] = 'tags';
  $handler->display->display_options['filters']['field_tags_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Country (field_tax_country) */
  $handler->display->display_options['filters']['field_tax_country_tid']['id'] = 'field_tax_country_tid';
  $handler->display->display_options['filters']['field_tax_country_tid']['table'] = 'field_data_field_tax_country';
  $handler->display->display_options['filters']['field_tax_country_tid']['field'] = 'field_tax_country_tid';
  $handler->display->display_options['filters']['field_tax_country_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_tax_country_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tax_country_tid']['expose']['operator_id'] = 'field_tax_country_tid_op';
  $handler->display->display_options['filters']['field_tax_country_tid']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_tax_country_tid']['expose']['operator'] = 'field_tax_country_tid_op';
  $handler->display->display_options['filters']['field_tax_country_tid']['expose']['identifier'] = 'field_tax_country_tid';
  $handler->display->display_options['filters']['field_tax_country_tid']['expose']['remember_roles'] = array(
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
    20 => 0,
    18 => 0,
    19 => 0,
  );
  $handler->display->display_options['filters']['field_tax_country_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_tax_country_tid']['vocabulary'] = 'enrd_countries';
  $handler->display->display_options['filters']['field_tax_country_tid']['hierarchy'] = 1;
  $handler->display->display_options['filters']['field_tax_country_tid']['use_chosen'] = 'always';
  /* Filter criterion: Content: Language (field_tax_languages) */
  $handler->display->display_options['filters']['field_tax_languages_tid']['id'] = 'field_tax_languages_tid';
  $handler->display->display_options['filters']['field_tax_languages_tid']['table'] = 'field_data_field_tax_languages';
  $handler->display->display_options['filters']['field_tax_languages_tid']['field'] = 'field_tax_languages_tid';
  $handler->display->display_options['filters']['field_tax_languages_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_tax_languages_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tax_languages_tid']['expose']['operator_id'] = 'field_tax_languages_tid_op';
  $handler->display->display_options['filters']['field_tax_languages_tid']['expose']['label'] = 'Taxonomy Language';
  $handler->display->display_options['filters']['field_tax_languages_tid']['expose']['operator'] = 'field_tax_languages_tid_op';
  $handler->display->display_options['filters']['field_tax_languages_tid']['expose']['identifier'] = 'field_tax_languages_tid';
  $handler->display->display_options['filters']['field_tax_languages_tid']['expose']['remember_roles'] = array(
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
    20 => 0,
    18 => 0,
    19 => 0,
  );
  $handler->display->display_options['filters']['field_tax_languages_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_tax_languages_tid']['vocabulary'] = 'enrd_languages';
  /* Filter criterion: Content: Transversal topics (field_tax_transversal_topics) */
  $handler->display->display_options['filters']['field_tax_transversal_topics_tid']['id'] = 'field_tax_transversal_topics_tid';
  $handler->display->display_options['filters']['field_tax_transversal_topics_tid']['table'] = 'field_data_field_tax_transversal_topics';
  $handler->display->display_options['filters']['field_tax_transversal_topics_tid']['field'] = 'field_tax_transversal_topics_tid';
  $handler->display->display_options['filters']['field_tax_transversal_topics_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_tax_transversal_topics_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tax_transversal_topics_tid']['expose']['operator_id'] = 'field_tax_transversal_topics_tid_op';
  $handler->display->display_options['filters']['field_tax_transversal_topics_tid']['expose']['label'] = 'Transversal topics';
  $handler->display->display_options['filters']['field_tax_transversal_topics_tid']['expose']['operator'] = 'field_tax_transversal_topics_tid_op';
  $handler->display->display_options['filters']['field_tax_transversal_topics_tid']['expose']['identifier'] = 'field_tax_transversal_topics_tid';
  $handler->display->display_options['filters']['field_tax_transversal_topics_tid']['expose']['remember_roles'] = array(
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
    20 => 0,
    18 => 0,
    19 => 0,
  );
  $handler->display->display_options['filters']['field_tax_transversal_topics_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_tax_transversal_topics_tid']['vocabulary'] = 'enrd_transversal_topics';
  $handler->display->display_options['filters']['field_tax_transversal_topics_tid']['use_chosen'] = 'always';
  /* Filter criterion: Content: Rural Development Policy (field_tax_rural_dev_policy) */
  $handler->display->display_options['filters']['field_tax_rural_dev_policy_tid']['id'] = 'field_tax_rural_dev_policy_tid';
  $handler->display->display_options['filters']['field_tax_rural_dev_policy_tid']['table'] = 'field_data_field_tax_rural_dev_policy';
  $handler->display->display_options['filters']['field_tax_rural_dev_policy_tid']['field'] = 'field_tax_rural_dev_policy_tid';
  $handler->display->display_options['filters']['field_tax_rural_dev_policy_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_tax_rural_dev_policy_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tax_rural_dev_policy_tid']['expose']['operator_id'] = 'field_tax_rural_dev_policy_tid_op';
  $handler->display->display_options['filters']['field_tax_rural_dev_policy_tid']['expose']['label'] = 'Rural Development Policy';
  $handler->display->display_options['filters']['field_tax_rural_dev_policy_tid']['expose']['operator'] = 'field_tax_rural_dev_policy_tid_op';
  $handler->display->display_options['filters']['field_tax_rural_dev_policy_tid']['expose']['identifier'] = 'field_tax_rural_dev_policy_tid';
  $handler->display->display_options['filters']['field_tax_rural_dev_policy_tid']['expose']['remember_roles'] = array(
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
    20 => 0,
    18 => 0,
    19 => 0,
  );
  $handler->display->display_options['filters']['field_tax_rural_dev_policy_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_tax_rural_dev_policy_tid']['vocabulary'] = 'enrd_rural_development_policy';
  $handler->display->display_options['filters']['field_tax_rural_dev_policy_tid']['hierarchy'] = 1;
  $handler->display->display_options['filters']['field_tax_rural_dev_policy_tid']['use_chosen'] = 'always';
  /* Filter criterion: Content: Evaluation (field_tax_evaluation) */
  $handler->display->display_options['filters']['field_tax_evaluation_tid']['id'] = 'field_tax_evaluation_tid';
  $handler->display->display_options['filters']['field_tax_evaluation_tid']['table'] = 'field_data_field_tax_evaluation';
  $handler->display->display_options['filters']['field_tax_evaluation_tid']['field'] = 'field_tax_evaluation_tid';
  $handler->display->display_options['filters']['field_tax_evaluation_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_tax_evaluation_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tax_evaluation_tid']['expose']['operator_id'] = 'field_tax_evaluation_tid_op';
  $handler->display->display_options['filters']['field_tax_evaluation_tid']['expose']['label'] = 'Evaluation';
  $handler->display->display_options['filters']['field_tax_evaluation_tid']['expose']['operator'] = 'field_tax_evaluation_tid_op';
  $handler->display->display_options['filters']['field_tax_evaluation_tid']['expose']['identifier'] = 'field_tax_evaluation_tid';
  $handler->display->display_options['filters']['field_tax_evaluation_tid']['expose']['remember_roles'] = array(
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
    20 => 0,
    18 => 0,
    19 => 0,
  );
  $handler->display->display_options['filters']['field_tax_evaluation_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_tax_evaluation_tid']['vocabulary'] = 'enrd_evaluation';
  $handler->display->display_options['filters']['field_tax_evaluation_tid']['hierarchy'] = 1;
  $handler->display->display_options['filters']['field_tax_evaluation_tid']['use_chosen'] = 'always';
  /* Filter criterion: Content: Origin (field_tax_origin) */
  $handler->display->display_options['filters']['field_tax_origin_tid']['id'] = 'field_tax_origin_tid';
  $handler->display->display_options['filters']['field_tax_origin_tid']['table'] = 'field_data_field_tax_origin';
  $handler->display->display_options['filters']['field_tax_origin_tid']['field'] = 'field_tax_origin_tid';
  $handler->display->display_options['filters']['field_tax_origin_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_tax_origin_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tax_origin_tid']['expose']['operator_id'] = 'field_tax_origin_tid_op';
  $handler->display->display_options['filters']['field_tax_origin_tid']['expose']['label'] = 'Origin';
  $handler->display->display_options['filters']['field_tax_origin_tid']['expose']['operator'] = 'field_tax_origin_tid_op';
  $handler->display->display_options['filters']['field_tax_origin_tid']['expose']['identifier'] = 'field_tax_origin_tid';
  $handler->display->display_options['filters']['field_tax_origin_tid']['expose']['remember_roles'] = array(
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
    20 => 0,
    18 => 0,
    19 => 0,
  );
  $handler->display->display_options['filters']['field_tax_origin_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_tax_origin_tid']['vocabulary'] = 'enrd_origin';
  $handler->display->display_options['filters']['field_tax_origin_tid']['use_chosen'] = 'always';
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
