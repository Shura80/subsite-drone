<?php

/**
 * @file
 * enrd_focus_on.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function enrd_focus_on_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'enrd_focus_on';
  $view->description = 'Shows a home page block specifically designed to put in highlight specific content.';
  $view->tag = 'ENRD Focus on';
  $view->base_table = 'node';
  $view->human_name = 'ENRD Focus on	';
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
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_carousel_plugin_style';
  $handler->display->display_options['style_options']['interval'] = '9000';
  $handler->display->display_options['style_options']['navigation'] = 1;
  $handler->display->display_options['style_options']['indicators'] = 1;
  $handler->display->display_options['style_options']['pause'] = 1;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entityqueue: Content Queue */
  $handler->display->display_options['relationships']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['table'] = 'node';
  $handler->display->display_options['relationships']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['required'] = TRUE;
  $handler->display->display_options['relationships']['entityqueue_relationship']['limit'] = 1;
  $handler->display->display_options['relationships']['entityqueue_relationship']['queues'] = array(
    'focus_on_home_page_slider' => 'focus_on_home_page_slider',
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_enrd_focus_on_highlight_target_id']['id'] = 'field_enrd_focus_on_highlight_target_id';
  $handler->display->display_options['relationships']['field_enrd_focus_on_highlight_target_id']['table'] = 'field_data_field_enrd_focus_on_highlight';
  $handler->display->display_options['relationships']['field_enrd_focus_on_highlight_target_id']['field'] = 'field_enrd_focus_on_highlight_target_id';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_enrd_focus_on_highlight_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_enrd_focus_on_image']['id'] = 'field_enrd_focus_on_image';
  $handler->display->display_options['fields']['field_enrd_focus_on_image']['table'] = 'field_data_field_enrd_focus_on_image';
  $handler->display->display_options['fields']['field_enrd_focus_on_image']['field'] = 'field_enrd_focus_on_image';
  $handler->display->display_options['fields']['field_enrd_focus_on_image']['label'] = '';
  $handler->display->display_options['fields']['field_enrd_focus_on_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_focus_on_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_enrd_focus_on_image']['settings'] = array(
    'image_style' => 'focus_on_slider',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_field']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['title_field']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_enrd_focus_on_description']['id'] = 'field_enrd_focus_on_description';
  $handler->display->display_options['fields']['field_enrd_focus_on_description']['table'] = 'field_data_field_enrd_focus_on_description';
  $handler->display->display_options['fields']['field_enrd_focus_on_description']['field'] = 'field_enrd_focus_on_description';
  $handler->display->display_options['fields']['field_enrd_focus_on_description']['label'] = '';
  $handler->display->display_options['fields']['field_enrd_focus_on_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_focus_on_description']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['field_enrd_focus_on_description']['settings'] = array(
    'trim_link' => '0',
    'trim_length' => '800',
    'trim_type' => 'chars',
    'trim_suffix' => '...',
    'more_link' => '0',
    'more_text' => 'Read more',
    'trim_options' => array(
      'text' => 0,
    ),
    'trim_preserve_tags' => '',
  );
  /* Sort criterion: Entityqueue: Content Queue Position */
  $handler->display->display_options['sorts']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['sorts']['entityqueue_relationship']['table'] = 'node';
  $handler->display->display_options['sorts']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'focus_on' => 'focus_on',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Workbench Moderation: Published */
  $handler->display->display_options['filters']['published']['id'] = 'published';
  $handler->display->display_options['filters']['published']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['published']['field'] = 'published';
  $handler->display->display_options['filters']['published']['value'] = '1';

  /* Display: ENRD Focus on carousel */
  $handler = $view->new_display('block', 'ENRD Focus on carousel', 'focus_on_carousel');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'normalize';
  $handler->display->display_options['block_description'] = 'ENRD Focus on carousel';
  $export['enrd_focus_on'] = $view;

  return $export;
}
