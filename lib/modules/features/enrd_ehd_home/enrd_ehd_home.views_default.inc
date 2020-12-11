<?php

/**
 * @file
 * enrd_ehd_home.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function enrd_ehd_home_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'enrd_evaluation_events_landing_page';
  $view->description = 'Custom block to display the evaluation pages and news in a slider.';
  $view->tag = 'ENRD Evaluation';
  $view->base_table = 'node';
  $view->human_name = 'ENRD Evaluation events Landing page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['style_plugin'] = 'enrd_mastermind_media_plugin_style';
  $handler->display->display_options['style_options']['row_class'] = 'img-50 metadata-before';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'enrd_mastermind_media_plugin_rows';
  $handler->display->display_options['row_options']['image_field'] = 'field_picture_upload';
  $handler->display->display_options['row_options']['heading_field'] = 'title';
  $handler->display->display_options['row_options']['abstract_field'] = '';
  $handler->display->display_options['row_options']['metadata_field'] = array(
    'field_event_date' => 'field_event_date',
    'field_event_location_country' => 'field_event_location_country',
    'field_picture_upload' => 0,
    'title' => 0,
    'field_event_location' => 0,
  );
  /* Relationship: Content: Origin (field_tax_origin) */
  $handler->display->display_options['relationships']['field_tax_origin_tid']['id'] = 'field_tax_origin_tid';
  $handler->display->display_options['relationships']['field_tax_origin_tid']['table'] = 'field_data_field_tax_origin';
  $handler->display->display_options['relationships']['field_tax_origin_tid']['field'] = 'field_tax_origin_tid';
  /* Field: Content: Images */
  $handler->display->display_options['fields']['field_picture_upload']['id'] = 'field_picture_upload';
  $handler->display->display_options['fields']['field_picture_upload']['table'] = 'field_data_field_picture_upload';
  $handler->display->display_options['fields']['field_picture_upload']['field'] = 'field_picture_upload';
  $handler->display->display_options['fields']['field_picture_upload']['label'] = '';
  $handler->display->display_options['fields']['field_picture_upload']['element_type'] = '0';
  $handler->display->display_options['fields']['field_picture_upload']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_picture_upload']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_picture_upload']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_picture_upload']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_picture_upload']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_picture_upload']['settings'] = array(
    'image_style' => 'newsroom',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_picture_upload']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_picture_upload']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_picture_upload']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_class'] = 'media-heading';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Dates */
  $handler->display->display_options['fields']['field_event_date']['id'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['fields']['field_event_date']['field'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_event_date']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_event_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_event_date']['settings'] = array(
    'format_type' => 'enrd_newsroom_d_m_y',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_event_location']['id'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['table'] = 'field_data_field_event_location';
  $handler->display->display_options['fields']['field_event_location']['field'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['label'] = '';
  $handler->display->display_options['fields']['field_event_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_location']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_event_location']['alter']['text'] = '[field_event_location-locality]';
  $handler->display->display_options['fields']['field_event_location']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_event_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_location']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_event_location']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: field_event_location_full_country */
  $handler->display->display_options['fields']['field_event_location_country']['id'] = 'field_event_location_country';
  $handler->display->display_options['fields']['field_event_location_country']['table'] = 'field_data_field_event_location';
  $handler->display->display_options['fields']['field_event_location_country']['field'] = 'field_event_location_country';
  $handler->display->display_options['fields']['field_event_location_country']['ui_name'] = 'field_event_location_full_country';
  $handler->display->display_options['fields']['field_event_location_country']['label'] = 'Location';
  $handler->display->display_options['fields']['field_event_location_country']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_event_location_country']['alter']['text'] = '[field_event_location], [field_event_location_country]';
  $handler->display->display_options['fields']['field_event_location_country']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_event_location_country']['display_name'] = 1;
  /* Sort criterion: Content: Dates - end date (field_event_date:value2) */
  $handler->display->display_options['sorts']['field_event_date_value2']['id'] = 'field_event_date_value2';
  $handler->display->display_options['sorts']['field_event_date_value2']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['sorts']['field_event_date_value2']['field'] = 'field_event_date_value2';
  $handler->display->display_options['sorts']['field_event_date_value2']['order'] = 'DESC';
  /* Sort criterion: Content: Dates -  start date (field_event_date) */
  $handler->display->display_options['sorts']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['sorts']['field_event_date_value']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['sorts']['field_event_date_value']['field'] = 'field_event_date_value';
  $handler->display->display_options['sorts']['field_event_date_value']['order'] = 'DESC';
  /* Filter criterion: Content: Published status */
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
    'event' => 'event',
  );
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name_1']['id'] = 'name_1';
  $handler->display->display_options['filters']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name_1']['field'] = 'name';
  $handler->display->display_options['filters']['name_1']['relationship'] = 'field_tax_origin_tid';
  $handler->display->display_options['filters']['name_1']['value'] = 'Evaluation Helpdesk';

  /* Display: Events */
  $handler = $view->new_display('block', 'Events', 'evaluation_events');
  $handler->display->display_options['display_description'] = 'Evaluation events list, the newest first.';
  $export['enrd_evaluation_events_landing_page'] = $view;

  $view = new view();
  $view->name = 'enrd_evaluation_landing_page';
  $view->description = 'Custom block to display the pinned and unpinned evaluation publications in a slider.';
  $view->tag = 'ENRD Evaluation';
  $view->base_table = 'node';
  $view->human_name = 'ENRD Evaluation Publications Landing page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Latest publications';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Read our publications';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_carousel_plugin_style';
  $handler->display->display_options['style_options']['interval'] = '9000';
  $handler->display->display_options['style_options']['navigation'] = 1;
  $handler->display->display_options['style_options']['indicators'] = 1;
  $handler->display->display_options['style_options']['pause'] = 1;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title page image */
  $handler->display->display_options['fields']['field_enrd_publ_ehd_title_image']['id'] = 'field_enrd_publ_ehd_title_image';
  $handler->display->display_options['fields']['field_enrd_publ_ehd_title_image']['table'] = 'field_data_field_enrd_publ_ehd_title_image';
  $handler->display->display_options['fields']['field_enrd_publ_ehd_title_image']['field'] = 'field_enrd_publ_ehd_title_image';
  $handler->display->display_options['fields']['field_enrd_publ_ehd_title_image']['label'] = '';
  $handler->display->display_options['fields']['field_enrd_publ_ehd_title_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_publ_ehd_title_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_enrd_publ_ehd_title_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Abstract */
  $handler->display->display_options['fields']['field_enrd_publ_ehd_abstract']['id'] = 'field_enrd_publ_ehd_abstract';
  $handler->display->display_options['fields']['field_enrd_publ_ehd_abstract']['table'] = 'field_data_field_enrd_publ_ehd_abstract';
  $handler->display->display_options['fields']['field_enrd_publ_ehd_abstract']['field'] = 'field_enrd_publ_ehd_abstract';
  $handler->display->display_options['fields']['field_enrd_publ_ehd_abstract']['label'] = '';
  $handler->display->display_options['fields']['field_enrd_publ_ehd_abstract']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_publ_ehd_abstract']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['field_enrd_publ_ehd_abstract']['settings'] = array(
    'trim_link' => '0',
    'trim_length' => '500',
    'trim_type' => 'chars',
    'trim_suffix' => '...',
    'more_link' => '0',
    'more_text' => 'Read more',
    'trim_options' => array(
      'text' => 0,
    ),
    'trim_preserve_tags' => '',
  );
  /* Sort criterion: Content: Sticky status */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  /* Filter criterion: Content: Published status */
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
    'publication_ehd' => 'publication_ehd',
  );

  /* Display: Latest publications */
  $handler = $view->new_display('block', 'Latest publications', 'latest_publ_block');
  $handler->display->display_options['display_description'] = 'Pinned and unpinned publications list, the newest first.';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Sticky status */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Publication date (field_enrd_publ_ehd_public_date) */
  $handler->display->display_options['sorts']['field_enrd_publ_ehd_public_date_value']['id'] = 'field_enrd_publ_ehd_public_date_value';
  $handler->display->display_options['sorts']['field_enrd_publ_ehd_public_date_value']['table'] = 'field_data_field_enrd_publ_ehd_public_date';
  $handler->display->display_options['sorts']['field_enrd_publ_ehd_public_date_value']['field'] = 'field_enrd_publ_ehd_public_date_value';
  $handler->display->display_options['sorts']['field_enrd_publ_ehd_public_date_value']['order'] = 'DESC';
  $export['enrd_evaluation_landing_page'] = $view;

  $view = new view();
  $view->name = 'enrd_evaluation_rss_feed';
  $view->description = 'Generated RSS Feed based on the latest published Evaluation content.';
  $view->tag = 'ENRD Evaluation home';
  $view->base_table = 'node';
  $view->human_name = 'ENRD Evaluation Rss Feed';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'ENRD Evaluation';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Relationship: Content: Origin (field_tax_origin) */
  $handler->display->display_options['relationships']['field_tax_origin_tid']['id'] = 'field_tax_origin_tid';
  $handler->display->display_options['relationships']['field_tax_origin_tid']['table'] = 'field_data_field_tax_origin';
  $handler->display->display_options['relationships']['field_tax_origin_tid']['field'] = 'field_tax_origin_tid';
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
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  /* Filter criterion: Workbench Moderation: Published */
  $handler->display->display_options['filters']['published']['id'] = 'published';
  $handler->display->display_options['filters']['published']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['published']['field'] = 'published';
  $handler->display->display_options['filters']['published']['value'] = '1';
  $handler->display->display_options['filters']['published']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'page' => 'page',
    'news' => 'news',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'field_tax_origin_tid';
  $handler->display->display_options['filters']['name']['value'] = 'Evaluation Helpdesk';
  $handler->display->display_options['filters']['name']['group'] = 1;
  /* Filter criterion: Workbench Moderation: Published */
  $handler->display->display_options['filters']['published_1']['id'] = 'published_1';
  $handler->display->display_options['filters']['published_1']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['published_1']['field'] = 'published';
  $handler->display->display_options['filters']['published_1']['value'] = '1';
  $handler->display->display_options['filters']['published_1']['group'] = 2;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'publication_ehd' => 'publication_ehd',
  );
  $handler->display->display_options['filters']['type']['group'] = 2;

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'evaluation_feed');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['style_options']['description'] = 'Latest updates about ENRD Evaluation content';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['row_options']['item_length'] = 'teaser';
  $handler->display->display_options['path'] = 'rss/evaluation';
  $handler->display->display_options['displays'] = array(
    'default' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $export['enrd_evaluation_rss_feed'] = $view;

  $view = new view();
  $view->name = 'enrd_evaluation_updates_landing_page';
  $view->description = 'Custom block to display the evaluation pages and news in a slider.';
  $view->tag = 'ENRD Evaluation';
  $view->base_table = 'node';
  $view->human_name = 'ENRD Evaluation updates Landing page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Evaluation updates';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_carousel_plugin_style';
  $handler->display->display_options['style_options']['interval'] = '9000';
  $handler->display->display_options['style_options']['navigation'] = 1;
  $handler->display->display_options['style_options']['indicators'] = 1;
  $handler->display->display_options['style_options']['pause'] = 1;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Origin (field_tax_origin) */
  $handler->display->display_options['relationships']['field_tax_origin_tid']['id'] = 'field_tax_origin_tid';
  $handler->display->display_options['relationships']['field_tax_origin_tid']['table'] = 'field_data_field_tax_origin';
  $handler->display->display_options['relationships']['field_tax_origin_tid']['field'] = 'field_tax_origin_tid';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_news_image']['id'] = 'field_news_image';
  $handler->display->display_options['fields']['field_news_image']['table'] = 'field_data_field_news_image';
  $handler->display->display_options['fields']['field_news_image']['field'] = 'field_news_image';
  $handler->display->display_options['fields']['field_news_image']['label'] = '';
  $handler->display->display_options['fields']['field_news_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_news_image']['settings'] = array(
    'image_style' => 'newsroom_slider',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '500',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published status */
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
    'news' => 'news',
  );
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'field_tax_origin_tid';
  $handler->display->display_options['filters']['name']['value'] = 'Evaluation Helpdesk';

  /* Display: Evaluation updates */
  $handler = $view->new_display('block', 'Evaluation updates', 'evaluation_updates');
  $handler->display->display_options['display_description'] = 'Evaluation basic pages and news list, the newest first.';
  $export['enrd_evaluation_updates_landing_page'] = $view;

  return $export;
}
