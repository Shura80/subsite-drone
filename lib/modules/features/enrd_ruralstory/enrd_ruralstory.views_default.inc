<?php

/**
 * @file
 * enrd_ruralstory.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function enrd_ruralstory_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'enrd_ruralstory_submissions_report_list';
  $view->description = 'Show the report list of the submissions sent via the "Rural Story" Form.';
  $view->tag = 'ENRD Rural Story Form';
  $view->base_table = 'enrd_sfr';
  $view->human_name = 'ENRD Rural Story Form: submissions report';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Rural Story submissions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'manage enrd_ruralstory entity';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_table_plugin_style';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'sfrid' => 'sfrid',
    'field_enrd_ruralstory_subject' => 'field_enrd_ruralstory_subject',
    'field_enrd_ruralstory_country' => 'field_enrd_ruralstory_country',
    'field_enrd_ruralstory_email' => 'field_enrd_ruralstory_email',
    'ops' => 'field_enrd_ruralstory_status',
    'field_enrd_ruralstory_status' => 'field_enrd_ruralstory_status',
    'name' => 'field_enrd_ruralstory_status',
    'finalized' => 'finalized',
    'field_enrd_ruralstory_region' => 'field_enrd_ruralstory_region',
    'field_enrd_ruralstory_org' => 'field_enrd_ruralstory_org',
    'field_enrd_ruralstory_name' => 'field_enrd_ruralstory_name',
    'field_enrd_ruralstory_surname' => 'field_enrd_ruralstory_surname',
    'field_enrd_ruralstory_tel' => 'field_enrd_ruralstory_tel',
    'field_enrd_ruralstory_short_desc' => 'field_enrd_ruralstory_short_desc',
  );
  $handler->display->display_options['style_options']['default'] = 'finalized';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sfrid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_ruralstory_subject' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_ruralstory_country' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_ruralstory_email' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ops' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_ruralstory_status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
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
    'finalized' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_ruralstory_region' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_ruralstory_org' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_ruralstory_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_ruralstory_surname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_ruralstory_tel' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_ruralstory_short_desc' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['bootstrap_styles'] = array(
    'striped' => 'striped',
    'hover' => 'hover',
    'bordered' => 0,
    'condensed' => 0,
  );
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No submission found.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Relationship: Flags: enrd_ruralstory_status */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'enrd_sfr';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'enrd_ruralstory_status';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  /* Field: Bulk operations: ENRD Subscription Form Request */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_enrd_sfr';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::_enrd_ruralstory_flag_status' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 1,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Delete',
      'settings' => array(
        'log' => 1,
      ),
    ),
    'rules_component::rules_enrd_ruralstory_remove_status' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Remove status',
    ),
  );
  /* Field: ENRD Subscription Form Request: ENRD Sfr unique id */
  $handler->display->display_options['fields']['sfrid']['id'] = 'sfrid';
  $handler->display->display_options['fields']['sfrid']['table'] = 'enrd_sfr';
  $handler->display->display_options['fields']['sfrid']['field'] = 'sfrid';
  $handler->display->display_options['fields']['sfrid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['sfrid']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['sfrid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['sfrid']['separator'] = '';
  /* Field: ENRD Subscription Form Request: Subject */
  $handler->display->display_options['fields']['field_enrd_ruralstory_subject']['id'] = 'field_enrd_ruralstory_subject';
  $handler->display->display_options['fields']['field_enrd_ruralstory_subject']['table'] = 'field_data_field_enrd_ruralstory_subject';
  $handler->display->display_options['fields']['field_enrd_ruralstory_subject']['field'] = 'field_enrd_ruralstory_subject';
  $handler->display->display_options['fields']['field_enrd_ruralstory_subject']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_ruralstory_subject']['alter']['path'] = 'enrd-sfr/enrd-ruralstory/[sfrid]';
  $handler->display->display_options['fields']['field_enrd_ruralstory_subject']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_ruralstory_subject']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: ENRD Subscription Form Request: Theme / topic */
  $handler->display->display_options['fields']['field_enrd_ruralstory_topic']['id'] = 'field_enrd_ruralstory_topic';
  $handler->display->display_options['fields']['field_enrd_ruralstory_topic']['table'] = 'field_data_field_enrd_ruralstory_topic';
  $handler->display->display_options['fields']['field_enrd_ruralstory_topic']['field'] = 'field_enrd_ruralstory_topic';
  $handler->display->display_options['fields']['field_enrd_ruralstory_topic']['label'] = 'Topic(s)';
  $handler->display->display_options['fields']['field_enrd_ruralstory_topic']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_enrd_ruralstory_topic']['delta_offset'] = '0';
  /* Field: ENRD Subscription Form Request: Country */
  $handler->display->display_options['fields']['field_enrd_ruralstory_country']['id'] = 'field_enrd_ruralstory_country';
  $handler->display->display_options['fields']['field_enrd_ruralstory_country']['table'] = 'field_data_field_enrd_ruralstory_country';
  $handler->display->display_options['fields']['field_enrd_ruralstory_country']['field'] = 'field_enrd_ruralstory_country';
  $handler->display->display_options['fields']['field_enrd_ruralstory_country']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: ENRD Subscription Form Request: Email */
  $handler->display->display_options['fields']['field_enrd_ruralstory_email']['id'] = 'field_enrd_ruralstory_email';
  $handler->display->display_options['fields']['field_enrd_ruralstory_email']['table'] = 'field_data_field_enrd_ruralstory_email';
  $handler->display->display_options['fields']['field_enrd_ruralstory_email']['field'] = 'field_enrd_ruralstory_email';
  $handler->display->display_options['fields']['field_enrd_ruralstory_email']['label'] = 'Sent by';
  $handler->display->display_options['fields']['field_enrd_ruralstory_email']['type'] = 'email_plain';
  /* Field: ENRD Subscription Form Request: Finalized */
  $handler->display->display_options['fields']['finalized']['id'] = 'finalized';
  $handler->display->display_options['fields']['finalized']['table'] = 'enrd_sfr';
  $handler->display->display_options['fields']['finalized']['field'] = 'finalized';
  $handler->display->display_options['fields']['finalized']['label'] = 'Submission Date';
  $handler->display->display_options['fields']['finalized']['date_format'] = 'short';
  $handler->display->display_options['fields']['finalized']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = 'Operations';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  /* Field: Flagging: Status */
  $handler->display->display_options['fields']['field_enrd_ruralstory_status']['id'] = 'field_enrd_ruralstory_status';
  $handler->display->display_options['fields']['field_enrd_ruralstory_status']['table'] = 'field_data_field_enrd_ruralstory_status';
  $handler->display->display_options['fields']['field_enrd_ruralstory_status']['field'] = 'field_enrd_ruralstory_status';
  $handler->display->display_options['fields']['field_enrd_ruralstory_status']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['field_enrd_ruralstory_status']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_ruralstory_status']['alter']['text'] = '<div class=\'ruralstory-current-status\'>[field_enrd_ruralstory_status]</div>';
  /* Field: ENRD Subscription Form Request: Region */
  $handler->display->display_options['fields']['field_enrd_ruralstory_region']['id'] = 'field_enrd_ruralstory_region';
  $handler->display->display_options['fields']['field_enrd_ruralstory_region']['table'] = 'field_data_field_enrd_ruralstory_region';
  $handler->display->display_options['fields']['field_enrd_ruralstory_region']['field'] = 'field_enrd_ruralstory_region';
  $handler->display->display_options['fields']['field_enrd_ruralstory_region']['exclude'] = TRUE;
  /* Field: ENRD Subscription Form Request: Organisation */
  $handler->display->display_options['fields']['field_enrd_ruralstory_org']['id'] = 'field_enrd_ruralstory_org';
  $handler->display->display_options['fields']['field_enrd_ruralstory_org']['table'] = 'field_data_field_enrd_ruralstory_org';
  $handler->display->display_options['fields']['field_enrd_ruralstory_org']['field'] = 'field_enrd_ruralstory_org';
  $handler->display->display_options['fields']['field_enrd_ruralstory_org']['label'] = '';
  $handler->display->display_options['fields']['field_enrd_ruralstory_org']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_ruralstory_org']['element_label_colon'] = FALSE;
  /* Field: ENRD Subscription Form Request: Name */
  $handler->display->display_options['fields']['field_enrd_ruralstory_name']['id'] = 'field_enrd_ruralstory_name';
  $handler->display->display_options['fields']['field_enrd_ruralstory_name']['table'] = 'field_data_field_enrd_ruralstory_name';
  $handler->display->display_options['fields']['field_enrd_ruralstory_name']['field'] = 'field_enrd_ruralstory_name';
  $handler->display->display_options['fields']['field_enrd_ruralstory_name']['exclude'] = TRUE;
  /* Field: ENRD Subscription Form Request: Surname */
  $handler->display->display_options['fields']['field_enrd_ruralstory_surname']['id'] = 'field_enrd_ruralstory_surname';
  $handler->display->display_options['fields']['field_enrd_ruralstory_surname']['table'] = 'field_data_field_enrd_ruralstory_surname';
  $handler->display->display_options['fields']['field_enrd_ruralstory_surname']['field'] = 'field_enrd_ruralstory_surname';
  $handler->display->display_options['fields']['field_enrd_ruralstory_surname']['label'] = '';
  $handler->display->display_options['fields']['field_enrd_ruralstory_surname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_ruralstory_surname']['element_label_colon'] = FALSE;
  /* Field: ENRD Subscription Form Request: Tel. */
  $handler->display->display_options['fields']['field_enrd_ruralstory_tel']['id'] = 'field_enrd_ruralstory_tel';
  $handler->display->display_options['fields']['field_enrd_ruralstory_tel']['table'] = 'field_data_field_enrd_ruralstory_tel';
  $handler->display->display_options['fields']['field_enrd_ruralstory_tel']['field'] = 'field_enrd_ruralstory_tel';
  $handler->display->display_options['fields']['field_enrd_ruralstory_tel']['label'] = '';
  $handler->display->display_options['fields']['field_enrd_ruralstory_tel']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_ruralstory_tel']['element_label_colon'] = FALSE;
  /* Field: ENRD Subscription Form Request: Short description of your story */
  $handler->display->display_options['fields']['field_enrd_ruralstory_short_desc']['id'] = 'field_enrd_ruralstory_short_desc';
  $handler->display->display_options['fields']['field_enrd_ruralstory_short_desc']['table'] = 'field_data_field_enrd_ruralstory_short_desc';
  $handler->display->display_options['fields']['field_enrd_ruralstory_short_desc']['field'] = 'field_enrd_ruralstory_short_desc';
  $handler->display->display_options['fields']['field_enrd_ruralstory_short_desc']['label'] = '';
  $handler->display->display_options['fields']['field_enrd_ruralstory_short_desc']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_ruralstory_short_desc']['element_label_colon'] = FALSE;
  /* Sort criterion: ENRD Subscription Form Request: Finalized */
  $handler->display->display_options['sorts']['finalized']['id'] = 'finalized';
  $handler->display->display_options['sorts']['finalized']['table'] = 'enrd_sfr';
  $handler->display->display_options['sorts']['finalized']['field'] = 'finalized';
  $handler->display->display_options['sorts']['finalized']['order'] = 'DESC';
  /* Filter criterion: ENRD Subscription Form Request: Bundle type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'enrd_sfr';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = 'enrd_ruralstory';
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Free-text search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'search';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    9 => 0,
    8 => 0,
    7 => 0,
    12 => 0,
    10 => 0,
    14 => 0,
    11 => 0,
    13 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_enrd_ruralstory_subject' => 'field_enrd_ruralstory_subject',
    'field_enrd_ruralstory_email' => 'field_enrd_ruralstory_email',
    'field_enrd_ruralstory_region' => 'field_enrd_ruralstory_region',
    'field_enrd_ruralstory_org' => 'field_enrd_ruralstory_org',
    'field_enrd_ruralstory_name' => 'field_enrd_ruralstory_name',
    'field_enrd_ruralstory_surname' => 'field_enrd_ruralstory_surname',
    'field_enrd_ruralstory_tel' => 'field_enrd_ruralstory_tel',
    'field_enrd_ruralstory_short_desc' => 'field_enrd_ruralstory_short_desc',
  );
  /* Filter criterion: ENRD Subscription Form Request: Country (field_enrd_ruralstory_country) */
  $handler->display->display_options['filters']['field_enrd_ruralstory_country_target_id']['id'] = 'field_enrd_ruralstory_country_target_id';
  $handler->display->display_options['filters']['field_enrd_ruralstory_country_target_id']['table'] = 'field_data_field_enrd_ruralstory_country';
  $handler->display->display_options['filters']['field_enrd_ruralstory_country_target_id']['field'] = 'field_enrd_ruralstory_country_target_id';
  $handler->display->display_options['filters']['field_enrd_ruralstory_country_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_ruralstory_country_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_ruralstory_country_target_id']['expose']['operator_id'] = 'field_enrd_ruralstory_country_target_id_op';
  $handler->display->display_options['filters']['field_enrd_ruralstory_country_target_id']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_enrd_ruralstory_country_target_id']['expose']['operator'] = 'field_enrd_ruralstory_country_target_id_op';
  $handler->display->display_options['filters']['field_enrd_ruralstory_country_target_id']['expose']['identifier'] = 'field_enrd_ruralstory_country_target_id';
  $handler->display->display_options['filters']['field_enrd_ruralstory_country_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_ruralstory_country_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    9 => 0,
    8 => 0,
    7 => 0,
    12 => 0,
    10 => 0,
    14 => 0,
    11 => 0,
    13 => 0,
  );
  /* Filter criterion: ENRD Subscription Form Request: Theme / topic (field_enrd_ruralstory_topic) */
  $handler->display->display_options['filters']['field_enrd_ruralstory_topic_tid']['id'] = 'field_enrd_ruralstory_topic_tid';
  $handler->display->display_options['filters']['field_enrd_ruralstory_topic_tid']['table'] = 'field_data_field_enrd_ruralstory_topic';
  $handler->display->display_options['filters']['field_enrd_ruralstory_topic_tid']['field'] = 'field_enrd_ruralstory_topic_tid';
  $handler->display->display_options['filters']['field_enrd_ruralstory_topic_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_ruralstory_topic_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_ruralstory_topic_tid']['expose']['operator_id'] = 'field_enrd_ruralstory_topic_tid_op';
  $handler->display->display_options['filters']['field_enrd_ruralstory_topic_tid']['expose']['label'] = 'Theme / topic';
  $handler->display->display_options['filters']['field_enrd_ruralstory_topic_tid']['expose']['operator'] = 'field_enrd_ruralstory_topic_tid_op';
  $handler->display->display_options['filters']['field_enrd_ruralstory_topic_tid']['expose']['identifier'] = 'field_enrd_ruralstory_topic_tid';
  $handler->display->display_options['filters']['field_enrd_ruralstory_topic_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_ruralstory_topic_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_enrd_ruralstory_topic_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_enrd_ruralstory_topic_tid']['vocabulary'] = 'enrd_ruralstory_topics';
  $handler->display->display_options['filters']['field_enrd_ruralstory_topic_tid']['use_chosen'] = 'chosen';
  /* Filter criterion: Flagging: Status (field_enrd_ruralstory_status) */
  $handler->display->display_options['filters']['field_enrd_ruralstory_status_value']['id'] = 'field_enrd_ruralstory_status_value';
  $handler->display->display_options['filters']['field_enrd_ruralstory_status_value']['table'] = 'field_data_field_enrd_ruralstory_status';
  $handler->display->display_options['filters']['field_enrd_ruralstory_status_value']['field'] = 'field_enrd_ruralstory_status_value';
  $handler->display->display_options['filters']['field_enrd_ruralstory_status_value']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['field_enrd_ruralstory_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_ruralstory_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_ruralstory_status_value']['expose']['operator_id'] = 'field_enrd_ruralstory_status_value_op';
  $handler->display->display_options['filters']['field_enrd_ruralstory_status_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_enrd_ruralstory_status_value']['expose']['operator'] = 'field_enrd_ruralstory_status_value_op';
  $handler->display->display_options['filters']['field_enrd_ruralstory_status_value']['expose']['identifier'] = 'field_enrd_ruralstory_status_value';
  $handler->display->display_options['filters']['field_enrd_ruralstory_status_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_ruralstory_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    9 => 0,
    8 => 0,
    7 => 0,
    12 => 0,
    10 => 0,
    14 => 0,
    11 => 0,
    13 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['use_ajax_flags'] = array(
    'enrd_ruralstory_status' => 'enrd_ruralstory_status',
    'email_lags' => 0,
    'enrd_follow_lags' => 0,
    'enrd_message_read_unread' => 0,
    'email_cooperation_offers' => 0,
    'email_events' => 0,
    'email_news' => 0,
    'enrd_follow_cooperation_offers' => 0,
    'enrd_follow_events' => 0,
    'enrd_follow_news' => 0,
  );
  $handler->display->display_options['use_ajax_flags_noscrolltop'] = 1;
  $handler->display->display_options['path'] = 'admin/enrd/enrd-sfr-ruralstory';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Rural Story Submissions';
  $handler->display->display_options['menu']['description'] = 'Manage the "Rural Story" Form submissions.';
  $handler->display->display_options['menu']['weight'] = '24';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['enrd_ruralstory_submissions_report_list'] = $view;

  return $export;
}
