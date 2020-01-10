<?php

/**
 * @file
 * enrd_nrn_toolkit.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function enrd_nrn_toolkit_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'enrd_nrn_toolkit_rss';
  $view->description = 'Generated RSS Feed based on the latest NRN Toolkit content.';
  $view->tag = 'ENRD NRN Toolkit';
  $view->base_table = 'node';
  $view->human_name = 'ENRD NRN Toolkit RSS Feed';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'ENRD NRN Toolkit';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Field: Content: NRN Title */
  $handler->display->display_options['fields']['field_enrd_nrn_title']['id'] = 'field_enrd_nrn_title';
  $handler->display->display_options['fields']['field_enrd_nrn_title']['table'] = 'field_data_field_enrd_nrn_title';
  $handler->display->display_options['fields']['field_enrd_nrn_title']['field'] = 'field_enrd_nrn_title';
  $handler->display->display_options['fields']['field_enrd_nrn_title']['label'] = '';
  $handler->display->display_options['fields']['field_enrd_nrn_title']['element_label_colon'] = FALSE;
  /* Field: Content: NRN Description */
  $handler->display->display_options['fields']['field_enrd_nrn_alter_description']['id'] = 'field_enrd_nrn_alter_description';
  $handler->display->display_options['fields']['field_enrd_nrn_alter_description']['table'] = 'field_data_field_enrd_nrn_alter_description';
  $handler->display->display_options['fields']['field_enrd_nrn_alter_description']['field'] = 'field_enrd_nrn_alter_description';
  $handler->display->display_options['fields']['field_enrd_nrn_alter_description']['label'] = '';
  $handler->display->display_options['fields']['field_enrd_nrn_alter_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_nrn_alter_description']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['field_enrd_nrn_alter_description']['settings'] = array(
    'trim_link' => '0',
    'trim_length' => '300',
    'trim_type' => 'chars',
    'trim_suffix' => '...',
    'more_link' => '0',
    'more_text' => 'Read more',
    'trim_options' => array(
      'text' => 'text',
    ),
    'trim_preserve_tags' => '',
  );
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
  /* Filter criterion: Content: Include in the NRN Toolkit (field_enrd_nrn_include_toolkit) */
  $handler->display->display_options['filters']['field_enrd_nrn_include_toolkit_value']['id'] = 'field_enrd_nrn_include_toolkit_value';
  $handler->display->display_options['filters']['field_enrd_nrn_include_toolkit_value']['table'] = 'field_data_field_enrd_nrn_include_toolkit';
  $handler->display->display_options['filters']['field_enrd_nrn_include_toolkit_value']['field'] = 'field_enrd_nrn_include_toolkit_value';
  $handler->display->display_options['filters']['field_enrd_nrn_include_toolkit_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_enrd_nrn_include_toolkit_value']['reduce_duplicates'] = TRUE;

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_nrn_toolkit');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['style_options']['uses_fields'] = TRUE;
  $handler->display->display_options['style_options']['description'] = 'Latest updates about ENRD NRN Toolkit';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'rss/nrn-toolkit';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
  );
  $handler->display->display_options['sitename_title'] = 0;
  $export['enrd_nrn_toolkit_rss'] = $view;

  return $export;
}
