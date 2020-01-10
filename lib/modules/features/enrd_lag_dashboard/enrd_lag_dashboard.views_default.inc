<?php

/**
 * @file
 * enrd_lag_dashboard.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function enrd_lag_dashboard_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'enrd_lag_dashboard_contextual_cooperation_offers';
  $view->description = 'Custom dashboard to allow the management of Cooperation Offers from a contextual LAG';
  $view->tag = 'ENRD LAG Dashboard';
  $view->base_table = 'node_revision';
  $view->human_name = 'ENRD Contextual Cooperation offers Custom Dashboard';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Page: LAG users - Coop Offers';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'esi_fund_context';
  $handler->display->display_options['access']['perm'] = '';
  $handler->display->display_options['access']['lag_perm'] = 'access lag dashboards';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'full_html',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
  );
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title_field-revision_id' => 'title_field-revision_id',
    'timestamp' => 'timestamp',
    'name' => 'name',
    'field_enrd_coop_expiry_date-revision_id' => 'field_enrd_coop_expiry_date-revision_id',
    'state' => 'state',
    'nothing' => 'edit_node',
    'nid' => 'nid',
    'vid' => 'vid',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_field-revision_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
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
    'field_enrd_coop_expiry_date-revision_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'vid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No pending for publication Cooperation Offers available.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['label'] = 'Get the actual content from a content revision (NID)';
  /* Relationship: OG membership: OG membership from Content */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['relationship'] = 'nid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['id'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['field'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['required'] = TRUE;
  /* Relationship: Content revision: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Bulk operations: Content revision */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node_revision';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::enrd_lag_dashboard_action_delete_coop_offer_draft' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_enrd_moderate_content_to_ready_to_be_published' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Ask for publication',
    ),
  );
  /* Field: Content (historical data): Title */
  $handler->display->display_options['fields']['title_field-revision_id']['id'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['table'] = 'field_revision_title_field';
  $handler->display->display_options['fields']['title_field-revision_id']['field'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['label'] = 'Offer name';
  /* Field: Content revision: Updated date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Update date';
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'enrd_lag_database_d_m_y';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Update author';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content (historical data): Expiry date */
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['id'] = 'field_enrd_coop_expiry_date-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['table'] = 'field_revision_field_enrd_coop_expiry_date';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['field'] = 'field_enrd_coop_expiry_date-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['settings'] = array(
    'format_type' => 'enrd_lag_database_d_m_y',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Workbench Moderation: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Status';
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  /* Field: Content revision: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content revision: Vid */
  $handler->display->display_options['fields']['vid']['id'] = 'vid';
  $handler->display->display_options['fields']['vid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['vid']['field'] = 'vid';
  $handler->display->display_options['fields']['vid']['label'] = '';
  $handler->display->display_options['fields']['vid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['vid']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Link to current revision';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'view';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'node/[nid]/current-revision';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'edit';
  /* Sort criterion: Content revision: Updated date */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'lag' => 'lag',
  );
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'access denied';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cooperation_offer' => 'cooperation_offer',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    'draft' => 'draft',
  );
  $handler->display->display_options['filters']['state']['group'] = 1;
  /* Filter criterion: Workbench Moderation: Current */
  $handler->display->display_options['filters']['is_current']['id'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['value'] = '1';
  $handler->display->display_options['filters']['is_current']['group'] = 1;

  /* Display: Block: Cooperation offers - Draft */
  $handler = $view->new_display('block', 'Block: Cooperation offers - Draft', 'coop_offers_draft');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Cooperation offers update';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['label'] = 'Get the actual content from a content revision (NID)';
  /* Relationship: OG membership: OG membership from Content */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['relationship'] = 'nid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['id'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['field'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['required'] = TRUE;
  /* Relationship: Workbench Moderation: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content revision */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node_revision';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['skip_batching'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::enrd_lag_dashboard_action_delete_coop_offer_draft' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_enrd_moderate_content_to_ready_to_be_published' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Ask for publication',
    ),
  );
  /* Field: Content (historical data): Title */
  $handler->display->display_options['fields']['title_field-revision_id']['id'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['table'] = 'field_revision_title_field';
  $handler->display->display_options['fields']['title_field-revision_id']['field'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['label'] = 'Offer name';
  /* Field: Content revision: Updated date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Update date';
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'enrd_lag_database_d_m_y';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Update author';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content (historical data): Expiry date */
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['id'] = 'field_enrd_coop_expiry_date-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['table'] = 'field_revision_field_enrd_coop_expiry_date';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['field'] = 'field_enrd_coop_expiry_date-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['settings'] = array(
    'format_type' => 'enrd_lag_database_d_m_y',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Workbench Moderation: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Status';
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  /* Field: Content revision: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content revision: Vid */
  $handler->display->display_options['fields']['vid']['id'] = 'vid';
  $handler->display->display_options['fields']['vid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['vid']['field'] = 'vid';
  $handler->display->display_options['fields']['vid']['label'] = '';
  $handler->display->display_options['fields']['vid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['vid']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Link to current revision';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'view';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'node/[nid]/current-revision';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'edit';
  $handler->display->display_options['fields']['edit_node']['destination'] = FALSE;
  $handler->display->display_options['block_description'] = 'Cooperation offers - Draft';

  /* Display: Block: Cooperation offers - Pending */
  $handler = $view->new_display('block', 'Block: Cooperation offers - Pending', 'coop_offers_pending');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Cooperation offers pending for publication';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<span class="text-muted">These updates will be validated and put online by the webmaster</span>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['label'] = 'Get the actual content from a content revision (NID)';
  /* Relationship: OG membership: OG membership from Content */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['relationship'] = 'nid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['id'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['field'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['required'] = TRUE;
  /* Relationship: Workbench Moderation: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content (historical data): Title */
  $handler->display->display_options['fields']['title_field-revision_id']['id'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['table'] = 'field_revision_title_field';
  $handler->display->display_options['fields']['title_field-revision_id']['field'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['label'] = 'Offer name';
  /* Field: Content revision: Updated date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Update date';
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'enrd_lag_database_d_m_y';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Update author';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content (historical data): Expiry date */
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['id'] = 'field_enrd_coop_expiry_date-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['table'] = 'field_revision_field_enrd_coop_expiry_date';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['field'] = 'field_enrd_coop_expiry_date-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['settings'] = array(
    'format_type' => 'enrd_lag_database_d_m_y',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Workbench Moderation: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Status';
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  /* Field: Content revision: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content revision: Vid */
  $handler->display->display_options['fields']['vid']['id'] = 'vid';
  $handler->display->display_options['fields']['vid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['vid']['field'] = 'vid';
  $handler->display->display_options['fields']['vid']['label'] = '';
  $handler->display->display_options['fields']['vid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['vid']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Link to current revision';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'view';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'node/[nid]/current-revision';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'edit';
  $handler->display->display_options['fields']['edit_node']['destination'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cooperation_offer' => 'cooperation_offer',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    'ready_to_be_published' => 'ready_to_be_published',
  );
  $handler->display->display_options['filters']['state']['group'] = 1;
  /* Filter criterion: Workbench Moderation: Current */
  $handler->display->display_options['filters']['is_current']['id'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['value'] = '1';
  $handler->display->display_options['filters']['is_current']['group'] = 1;
  $handler->display->display_options['block_description'] = 'Cooperation offers - Pending for publication';

  /* Display: Block: Cooperation offers - Archived */
  $handler = $view->new_display('block', 'Block: Cooperation offers - Archived', 'coop_offers_archived');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Archived cooperation offers';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['label'] = 'Get the actual content from a content revision (NID)';
  /* Relationship: OG membership: OG membership from Content */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['relationship'] = 'nid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['id'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['field'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['required'] = TRUE;
  /* Relationship: Workbench Moderation: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content revision */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node_revision';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['skip_batching'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::rules_enrd_moderate_content_to_draft' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Create new draft',
    ),
  );
  /* Field: Content (historical data): Title */
  $handler->display->display_options['fields']['title_field-revision_id']['id'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['table'] = 'field_revision_title_field';
  $handler->display->display_options['fields']['title_field-revision_id']['field'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['label'] = 'Offer name';
  /* Field: Content revision: Updated date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Update date';
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'enrd_lag_database_d_m_y';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Update author';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content (historical data): Expiry date */
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['id'] = 'field_enrd_coop_expiry_date-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['table'] = 'field_revision_field_enrd_coop_expiry_date';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['field'] = 'field_enrd_coop_expiry_date-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['settings'] = array(
    'format_type' => 'enrd_lag_database_d_m_y',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Workbench Moderation: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Status';
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  /* Field: Content revision: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content revision: Vid */
  $handler->display->display_options['fields']['vid']['id'] = 'vid';
  $handler->display->display_options['fields']['vid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['vid']['field'] = 'vid';
  $handler->display->display_options['fields']['vid']['label'] = '';
  $handler->display->display_options['fields']['vid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['vid']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Link to current revision';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'view';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'node/[nid]/current-revision';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'edit';
  $handler->display->display_options['fields']['edit_node']['destination'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cooperation_offer' => 'cooperation_offer',
  );
  /* Filter criterion: Workbench Moderation: Current */
  $handler->display->display_options['filters']['is_current']['id'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['value'] = '1';
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    'archived' => 'archived',
  );
  $handler->display->display_options['block_description'] = 'Cooperation offers - Archived';
  $export['enrd_lag_dashboard_contextual_cooperation_offers'] = $view;

  $view = new view();
  $view->name = 'enrd_lag_dashboard_manage_lag_nsu';
  $view->description = 'Custom LAG Admins\'s dashboard the management of any LAG users.';
  $view->tag = 'ENRD LAG Dashboard';
  $view->base_table = 'users';
  $view->human_name = 'ENRD Manage NSU users';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'NSU users';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access lag dashboards';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'name' => 'name',
    'term_node_tid' => 'term_node_tid',
    'field_enrd_lag_country' => 'field_enrd_lag_country',
    'status' => 'status',
    'mail' => 'mail',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
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
    'term_node_tid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_country' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
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
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No LAG users have been created yet with the selected criteria.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: OG membership: OG Roles from membership */
  $handler->display->display_options['relationships']['og_users_roles']['id'] = 'og_users_roles';
  $handler->display->display_options['relationships']['og_users_roles']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_users_roles']['field'] = 'og_users_roles';
  /* Relationship: OG membership: OG membership from User */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['og_group_ref_target_id']['id'] = 'og_group_ref_target_id';
  $handler->display->display_options['relationships']['og_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_group_ref_target_id']['field'] = 'og_group_ref_target_id';
  $handler->display->display_options['relationships']['og_group_ref_target_id']['relationship'] = 'og_membership_rel';
  /* Field: Bulk operations: OG membership */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_og_membership';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::og_set_state_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Set status',
    ),
    'action::og_membership_delete_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Remove from NSU',
    ),
    'rules_component::rules_enrd_lag_dashboard_send_mail_from_og_membership' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Send an email',
    ),
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['relationship'] = 'og_group_ref_target_id';
  $handler->display->display_options['fields']['term_node_tid']['label'] = 'ESI Fund';
  $handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = FALSE;
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
    'enrd_rdps' => 0,
    'enrd_rural_development_policy' => 0,
    'enrd_translation_status' => 0,
    'enrd_transversal_topics' => 0,
    'enrd_update_status' => 0,
    'eu_budget_mff_headings' => 0,
    'event_types' => 0,
    'faq_categories' => 0,
    'focus_areas' => 0,
    'measures' => 0,
    'media_tags' => 0,
    'metatags_ess_gf' => 0,
    'programme_name' => 0,
    'newsletter' => 0,
    'nuts_regions' => 0,
    'organization_type' => 0,
    'project_key_words' => 0,
    'resources' => 0,
    'tags' => 0,
    'ec_priorities' => 0,
  );
  /* Field: Field: Country */
  $handler->display->display_options['fields']['field_enrd_lag_country']['id'] = 'field_enrd_lag_country';
  $handler->display->display_options['fields']['field_enrd_lag_country']['table'] = 'field_data_field_enrd_lag_country';
  $handler->display->display_options['fields']['field_enrd_lag_country']['field'] = 'field_enrd_lag_country';
  $handler->display->display_options['fields']['field_enrd_lag_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrd_lag_country']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: OG membership: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'og_membership';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Sort criterion: Field: Country (field_enrd_lag_country) */
  $handler->display->display_options['sorts']['field_enrd_lag_country_tid']['id'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['sorts']['field_enrd_lag_country_tid']['table'] = 'field_data_field_enrd_lag_country';
  $handler->display->display_options['sorts']['field_enrd_lag_country_tid']['field'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  /* Filter criterion: Field: Groups audience (og_group_ref) */
  $handler->display->display_options['filters']['og_group_ref_target_id']['id'] = 'og_group_ref_target_id';
  $handler->display->display_options['filters']['og_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['filters']['og_group_ref_target_id']['field'] = 'og_group_ref_target_id';
  $handler->display->display_options['filters']['og_group_ref_target_id']['operator'] = 'not empty';
  $handler->display->display_options['filters']['og_group_ref_target_id']['group'] = 1;
  /* Filter criterion: User: The user ID */
  $handler->display->display_options['filters']['uid_raw']['id'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['table'] = 'users';
  $handler->display->display_options['filters']['uid_raw']['field'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['operator'] = '!=';
  $handler->display->display_options['filters']['uid_raw']['value']['value'] = '1';
  $handler->display->display_options['filters']['uid_raw']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'og_group_ref_target_id';
  $handler->display->display_options['filters']['type']['value'] = array(
    'esi_funds_og' => 'esi_funds_og',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: OG user roles: Role Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'og_role';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'og_users_roles';
  $handler->display->display_options['filters']['name']['value'] = array(
    'National manager' => 'National manager',
  );
  $handler->display->display_options['filters']['name']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Free search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    11 => 0,
    7 => 0,
    6 => 0,
    12 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'name' => 'name',
  );
  /* Filter criterion: Field: Country (field_enrd_lag_country) */
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['id'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['table'] = 'field_data_field_enrd_lag_country';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['field'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['operator_id'] = 'field_enrd_lag_country_tid_op';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['operator'] = 'field_enrd_lag_country_tid_op';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['identifier'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    10 => 0,
    7 => 0,
    6 => 0,
    11 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['vocabulary'] = 'enrd_countries';
  /* Filter criterion: Content: Main ESI Fund (field_enrd_main_esi_fund) */
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['id'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['table'] = 'field_data_field_enrd_main_esi_fund';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['field'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['relationship'] = 'og_group_ref_target_id';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['operator_id'] = 'field_enrd_main_esi_fund_tid_op';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['label'] = 'ESI Fund';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['operator'] = 'field_enrd_main_esi_fund_tid_op';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['identifier'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    10 => 0,
    7 => 0,
    6 => 0,
    11 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['vocabulary'] = 'enrd_esi_funds';

  /* Display: Page: NSU users */
  $handler = $view->new_display('page', 'Page: NSU users', 'lag_users_page');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'lag-dashboard/users/nsu';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'NSU users';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 1;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Contacts/Users';
  $handler->display->display_options['tab_options']['weight'] = '8';
  $export['enrd_lag_dashboard_manage_lag_nsu'] = $view;

  $view = new view();
  $view->name = 'enrd_lag_dashboard_my_lag_contacts';
  $view->description = '';
  $view->tag = 'og';
  $view->base_table = 'users';
  $view->human_name = 'My LAGs Contacts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'LAGs contacts list';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'esi_fund_context';
  $handler->display->display_options['access']['perm'] = 'access lag dashboards';
  $handler->display->display_options['access']['lag_perm'] = 'access lag dashboards';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'mail' => 'mail',
    'name' => 'name',
    'og_roles' => 'og_roles',
    'created' => 'created',
    'delete_membership' => 'delete_membership',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'mail' => array(
      'sortable' => 0,
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
    'og_roles' => array(
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
    'delete_membership' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: OG membership: Group membership overview */
  $handler->display->display_options['header']['og_membership_overview']['id'] = 'og_membership_overview';
  $handler->display->display_options['header']['og_membership_overview']['table'] = 'og_membership';
  $handler->display->display_options['header']['og_membership_overview']['field'] = 'og_membership_overview';
  $handler->display->display_options['header']['og_membership_overview']['manager'] = 0;
  $handler->display->display_options['header']['og_membership_overview']['total_members_1'] = 0;
  $handler->display->display_options['header']['og_membership_overview']['total_members_2'] = 0;
  $handler->display->display_options['header']['og_membership_overview']['total_members_3'] = 0;
  $handler->display->display_options['header']['og_membership_overview']['total_members'] = 1;
  $handler->display->display_options['header']['og_membership_overview']['total_content'] = 0;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No LAG contacts have been added to your LAG yet.<br />
You can start adding or inviting someone.';
  /* Relationship: OG membership: OG membership from User */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = TRUE;
  /* Relationship: OG membership: OG Roles from membership */
  $handler->display->display_options['relationships']['og_users_roles']['id'] = 'og_users_roles';
  $handler->display->display_options['relationships']['og_users_roles']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_users_roles']['field'] = 'og_users_roles';
  $handler->display->display_options['relationships']['og_users_roles']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_users_roles']['required'] = TRUE;
  /* Field: Bulk operations: OG membership */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_og_membership';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::og_membership_delete_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Remove from LAG',
    ),
  );
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'LAG member';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[name]<br />
<em>[mail]</em>';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: OG membership: OG user roles in group */
  $handler->display->display_options['fields']['og_roles']['id'] = 'og_roles';
  $handler->display->display_options['fields']['og_roles']['table'] = 'og_membership';
  $handler->display->display_options['fields']['og_roles']['field'] = 'og_roles';
  $handler->display->display_options['fields']['og_roles']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['fields']['og_roles']['label'] = 'Roles';
  $handler->display->display_options['fields']['og_roles']['type'] = 'ul';
  /* Field: OG membership: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'og_membership';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['fields']['created']['label'] = 'Member since';
  $handler->display->display_options['fields']['created']['date_format'] = 'today time ago';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Sort criterion: User: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['gid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['gid']['title'] = 'Manage my LAG: %1';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['gid']['validate_options']['types'] = array(
    'lag' => 'lag',
  );
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: OG membership: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'og_membership';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['filters']['state']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'State';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  /* Filter criterion: OG user roles: Role Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'og_role';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'og_users_roles';
  $handler->display->display_options['filters']['name']['value'] = array(
    'LAG Contact' => 'LAG Contact',
    'LAG Manager' => 'LAG Manager',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'my-lags/%/manage/contacts/active';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Active contacts';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 1;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Contacts';
  $handler->display->display_options['tab_options']['weight'] = '20';
  $export['enrd_lag_dashboard_my_lag_contacts'] = $view;

  $view = new view();
  $view->name = 'enrd_lag_dashboard_my_lags';
  $view->description = 'Show groups of a user.';
  $view->tag = 'ENRD';
  $view->base_table = 'node';
  $view->human_name = 'ENRD My LAGS page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My LAGs';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'esi_fund_context';
  $handler->display->display_options['access']['perm'] = '';
  $handler->display->display_options['access']['lag_perm'] = 'access lag dashboards';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_enrd_lag_code' => 'field_enrd_lag_code',
    'title' => 'title',
    'view_node' => 'view_node',
    'nid' => 'nid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_enrd_lag_code' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: OG membership: OG membership from Content group */
  $handler->display->display_options['relationships']['og_membership_rel_group']['id'] = 'og_membership_rel_group';
  $handler->display->display_options['relationships']['og_membership_rel_group']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel_group']['field'] = 'og_membership_rel_group';
  /* Field: Content: LAG code */
  $handler->display->display_options['fields']['field_enrd_lag_code']['id'] = 'field_enrd_lag_code';
  $handler->display->display_options['fields']['field_enrd_lag_code']['table'] = 'field_data_field_enrd_lag_code';
  $handler->display->display_options['fields']['field_enrd_lag_code']['field'] = 'field_enrd_lag_code';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'LAG name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'LAG profile';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'view';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Manage profile & Cooperation offers';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'manage';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'my-lags/[nid]/manage';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: OG membership: Entity id */
  $handler->display->display_options['arguments']['etid']['id'] = 'etid';
  $handler->display->display_options['arguments']['etid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['etid']['field'] = 'etid';
  $handler->display->display_options['arguments']['etid']['relationship'] = 'og_membership_rel_group';
  $handler->display->display_options['arguments']['etid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['etid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['etid']['default_argument_skip_url'] = TRUE;
  $handler->display->display_options['arguments']['etid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['etid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['etid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Group (group_group) */
  $handler->display->display_options['filters']['group_group_value']['id'] = 'group_group_value';
  $handler->display->display_options['filters']['group_group_value']['table'] = 'field_data_group_group';
  $handler->display->display_options['filters']['group_group_value']['field'] = 'group_group_value';
  $handler->display->display_options['filters']['group_group_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['group_group_value']['group'] = 1;
  /* Filter criterion: OG membership: Entity_type */
  $handler->display->display_options['filters']['entity_type']['id'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['table'] = 'og_membership';
  $handler->display->display_options['filters']['entity_type']['field'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['relationship'] = 'og_membership_rel_group';
  $handler->display->display_options['filters']['entity_type']['value'] = 'user';
  $handler->display->display_options['filters']['entity_type']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'lag' => 'lag',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: My LAGs */
  $handler = $view->new_display('page', 'My LAGs', 'my_lags_page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'my-lags';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Manage my LAGs';
  $handler->display->display_options['menu']['weight'] = '4';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['enrd_lag_dashboard_my_lags'] = $view;

  $view = new view();
  $view->name = 'enrd_lag_dashboard_published_cooperation_offers';
  $view->description = 'Custom dashboard to allow the management of published LAG-related Cooperation Offers';
  $view->tag = 'ENRD LAG Dashboard';
  $view->base_table = 'node';
  $view->human_name = 'ENRD Published Cooperation offers Custom Dashboard';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Cooperation offers currently online';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'esi_fund_context';
  $handler->display->display_options['access']['perm'] = '';
  $handler->display->display_options['access']['lag_perm'] = 'access lag dashboards';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'changed' => 'changed',
    'name' => 'name',
    'field_enrd_coop_expiry_date' => 'field_enrd_coop_expiry_date',
    'state' => 'state',
    'view_node' => 'view_node',
    'edit_node' => 'view_node',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
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
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_expiry_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no published cooperation offers.
Create a new update and ask the webmaster to publish it online.';
  $handler->display->display_options['empty']['area']['format'] = 'basic_html';
  /* Relationship: OG membership: OG membership from Content */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['id'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['field'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['required'] = TRUE;
  /* Relationship: Workbench Moderation: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Offer name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Update date';
  $handler->display->display_options['fields']['changed']['date_format'] = 'enrd_lag_database_d_m_y';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Update author';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Expiry date */
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date']['id'] = 'field_enrd_coop_expiry_date';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date']['table'] = 'field_data_field_enrd_coop_expiry_date';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date']['field'] = 'field_enrd_coop_expiry_date';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date']['settings'] = array(
    'format_type' => 'enrd_lag_database_d_m_y',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Workbench Moderation: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Status';
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'Operations';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
  $handler->display->display_options['fields']['edit_node']['text'] = 'edit';
  $handler->display->display_options['fields']['edit_node']['destination'] = FALSE;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'lag' => 'lag',
  );
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'access denied';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cooperation_offer' => 'cooperation_offer',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Workbench Moderation: Published */
  $handler->display->display_options['filters']['published']['id'] = 'published';
  $handler->display->display_options['filters']['published']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['published']['field'] = 'published';
  $handler->display->display_options['filters']['published']['value'] = '1';
  $handler->display->display_options['filters']['published']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;

  /* Display: Block: Cooperation offers - Published */
  $handler = $view->new_display('block', 'Block: Cooperation offers - Published', 'coop_offers_published');
  $handler->display->display_options['block_description'] = 'Cooperation offers - Published';
  $export['enrd_lag_dashboard_published_cooperation_offers'] = $view;

  $view = new view();
  $view->name = 'enrd_lag_database_cooperation_offers_dashboard';
  $view->description = 'Custom dashboard to allow the management of any Cooperation Offers';
  $view->tag = 'ENRD LAG Dashboard';
  $view->base_table = 'node_revision';
  $view->human_name = 'ENRD Admin Cooperation offers Custom Dashboard';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Page: Pending requests - Admins - Coop Offers';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'full_html',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'state' => array(
      'bef_format' => 'bef_hidden',
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
    'combine' => array(
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
    'field_enrd_coop_expiry_date_value' => array(
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
        'datepicker_options' => '',
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'timestamp' => 'timestamp',
    'field_enrd_coop_type' => 'field_enrd_coop_type',
    'field_enrd_coop_topic_of_project' => 'field_enrd_coop_topic_of_project',
    'field_enrd_coop_context' => 'field_enrd_coop_context',
    'field_enrd_coop_brief_summary' => 'field_enrd_coop_brief_summary',
    'field_enrd_coop_objectives' => 'field_enrd_coop_objectives',
    'field_enrd_coop_partner_region' => 'field_enrd_coop_partner_region',
    'field_enrd_coop_type_of_partner' => 'field_enrd_coop_type_of_partner',
    'title_field' => 'title_field',
    'field_tax_country' => 'field_tax_country',
    'field_enrd_main_esi_fund' => 'field_enrd_main_esi_fund',
    'field_enrd_esif_programme' => 'field_enrd_esif_programme',
    'field_enrd_coop_expiry_date' => 'field_enrd_coop_expiry_date',
    'state' => 'state',
    'stamp' => 'stamp',
  );
  $handler->display->display_options['style_options']['default'] = 'stamp';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_topic_of_project' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_context' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_brief_summary' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_objectives' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_partner_region' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_type_of_partner' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_field' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tax_country' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_main_esi_fund' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_esif_programme' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_expiry_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'stamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No Cooperation offers have been created yet with the selected criteria.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['label'] = 'Get the actual content from a content revision (NID)';
  /* Field: Content revision: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Offer name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node_revision'] = TRUE;
  /* Field: Content revision: Updated date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Expiry date */
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date']['id'] = 'field_enrd_coop_expiry_date';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date']['table'] = 'field_data_field_enrd_coop_expiry_date';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date']['field'] = 'field_enrd_coop_expiry_date';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date']['relationship'] = 'vid';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Workbench Moderation: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Workflow state';
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  /* Field: Workbench Moderation: Timestamp */
  $handler->display->display_options['fields']['stamp']['id'] = 'stamp';
  $handler->display->display_options['fields']['stamp']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['stamp']['field'] = 'stamp';
  $handler->display->display_options['fields']['stamp']['label'] = 'Requested on';
  $handler->display->display_options['fields']['stamp']['date_format'] = 'short';
  $handler->display->display_options['fields']['stamp']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Sort criterion: Content revision: Updated date */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';

  /* Display: Page: Active Cooperation offers - Admins */
  $handler = $view->new_display('page', 'Page: Active Cooperation offers - Admins', 'coop_offers_page_active');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Cooperation offers';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'esi_fund_context';
  $handler->display->display_options['access']['perm'] = 'access lag dashboards';
  $handler->display->display_options['access']['esi_fund_perm'] = 'access lag dashboards';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'full_html',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'combine' => array(
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
    'shs_term_node_tid_depth' => array(
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
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'shs_term_node_tid_depth_1' => array(
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
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_enrd_lag_country_tid' => array(
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
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_enrd_main_esi_fund_tid' => array(
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
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_enrd_esif_programme_tid' => array(
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
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'state' => array(
      'bef_format' => 'bef_links',
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
    'field_enrd_coop_expiry_date_value' => array(
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
        'datepicker_options' => '',
      ),
    ),
  );
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title_field-revision_id' => 'title_field-revision_id',
    'field_enrd_coop_type-revision_id' => 'field_enrd_coop_type-revision_id',
    'field_enrd_coop_topic_of_project-revision_id' => 'field_enrd_coop_topic_of_project-revision_id',
    'title_field' => 'title_field',
    'field_tax_country' => 'field_tax_country',
    'field_enrd_main_esi_fund' => 'field_enrd_main_esi_fund',
    'field_enrd_esif_programme' => 'field_enrd_esif_programme',
    'field_enrd_coop_expiry_date-revision_id' => 'field_enrd_coop_expiry_date-revision_id',
    'state' => 'state',
    'stamp' => 'stamp',
    'field_enrd_coop_context-revision_id' => 'field_enrd_coop_context-revision_id',
    'field_enrd_coop_brief_summary-revision_id' => 'field_enrd_coop_brief_summary-revision_id',
    'field_enrd_coop_objectives-revision_id' => 'field_enrd_coop_objectives-revision_id',
    'field_enrd_coop_partner_region-revision_id' => 'field_enrd_coop_partner_region-revision_id',
    'field_enrd_coop_type_of_partner-revision_id' => 'field_enrd_coop_type_of_partner-revision_id',
  );
  $handler->display->display_options['style_options']['default'] = 'stamp';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_field-revision_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_type-revision_id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_topic_of_project-revision_id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_field' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tax_country' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_main_esi_fund' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_esif_programme' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_expiry_date-revision_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'stamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_context-revision_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_brief_summary-revision_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_objectives-revision_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_partner_region-revision_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_type_of_partner-revision_id' => array(
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
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['label'] = 'Get the actual content from a content revision (NID)';
  /* Relationship: OG membership: OG membership from Content */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['relationship'] = 'nid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['id'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['field'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content revision */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node_revision';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::enrd_lag_dashboard_action_delete_coop_offer_draft' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_enrd_moderate_content_to_archived' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Archived',
    ),
    'rules_component::rules_enrd_moderate_content_to_draft' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Draft',
    ),
    'rules_component::rules_enrd_moderate_content_to_expired' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Expired',
    ),
    'rules_component::rules_enrd_moderate_content_to_published' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Published',
    ),
    'rules_component::rules_enrd_moderate_content_to_ready_to_be_published' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Ready to be published',
    ),
  );
  /* Field: Content revision: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content revision: Vid */
  $handler->display->display_options['fields']['vid']['id'] = 'vid';
  $handler->display->display_options['fields']['vid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['vid']['field'] = 'vid';
  $handler->display->display_options['fields']['vid']['label'] = '';
  $handler->display->display_options['fields']['vid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['vid']['element_label_colon'] = FALSE;
  /* Field: Content (historical data): Title */
  $handler->display->display_options['fields']['title_field-revision_id']['id'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['table'] = 'field_revision_title_field';
  $handler->display->display_options['fields']['title_field-revision_id']['field'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['label'] = 'Offer name';
  $handler->display->display_options['fields']['title_field-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_field-revision_id']['alter']['text'] = '[title_field-revision_id]';
  $handler->display->display_options['fields']['title_field-revision_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_field-revision_id']['alter']['path'] = 'node/[nid]/current-revision';
  /* Field: Content (historical data): Project type */
  $handler->display->display_options['fields']['field_enrd_coop_type-revision_id']['id'] = 'field_enrd_coop_type-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_type-revision_id']['table'] = 'field_revision_field_enrd_coop_type';
  $handler->display->display_options['fields']['field_enrd_coop_type-revision_id']['field'] = 'field_enrd_coop_type-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_type-revision_id']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_enrd_coop_type-revision_id']['delta_offset'] = '0';
  /* Field: Content (historical data): Project topic */
  $handler->display->display_options['fields']['field_enrd_coop_topic_of_project-revision_id']['id'] = 'field_enrd_coop_topic_of_project-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_topic_of_project-revision_id']['table'] = 'field_revision_field_enrd_coop_topic_of_project';
  $handler->display->display_options['fields']['field_enrd_coop_topic_of_project-revision_id']['field'] = 'field_enrd_coop_topic_of_project-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_topic_of_project-revision_id']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_enrd_coop_topic_of_project-revision_id']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['fields']['title_field']['label'] = 'LAG name';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: Content (historical data): Country */
  $handler->display->display_options['fields']['field_tax_country-revision_id']['id'] = 'field_tax_country-revision_id';
  $handler->display->display_options['fields']['field_tax_country-revision_id']['table'] = 'field_revision_field_tax_country';
  $handler->display->display_options['fields']['field_tax_country-revision_id']['field'] = 'field_tax_country-revision_id';
  $handler->display->display_options['fields']['field_tax_country-revision_id']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tax_country-revision_id']['delta_offset'] = '0';
  /* Field: Content: Main ESI Fund */
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['id'] = 'field_enrd_main_esi_fund';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['table'] = 'field_data_field_enrd_main_esi_fund';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['field'] = 'field_enrd_main_esi_fund';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: ESIF Programme */
  $handler->display->display_options['fields']['field_enrd_esif_programme']['id'] = 'field_enrd_esif_programme';
  $handler->display->display_options['fields']['field_enrd_esif_programme']['table'] = 'field_data_field_enrd_esif_programme';
  $handler->display->display_options['fields']['field_enrd_esif_programme']['field'] = 'field_enrd_esif_programme';
  $handler->display->display_options['fields']['field_enrd_esif_programme']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['fields']['field_enrd_esif_programme']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content (historical data): Expiry date */
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['id'] = 'field_enrd_coop_expiry_date-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['table'] = 'field_revision_field_enrd_coop_expiry_date';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['field'] = 'field_enrd_coop_expiry_date-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Workbench Moderation: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Workflow state';
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  /* Field: Workbench Moderation: Timestamp */
  $handler->display->display_options['fields']['stamp']['id'] = 'stamp';
  $handler->display->display_options['fields']['stamp']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['stamp']['field'] = 'stamp';
  $handler->display->display_options['fields']['stamp']['label'] = 'Revised on';
  $handler->display->display_options['fields']['stamp']['date_format'] = 'short';
  $handler->display->display_options['fields']['stamp']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Content (historical data): Context */
  $handler->display->display_options['fields']['field_enrd_coop_context-revision_id']['id'] = 'field_enrd_coop_context-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_context-revision_id']['table'] = 'field_revision_field_enrd_coop_context';
  $handler->display->display_options['fields']['field_enrd_coop_context-revision_id']['field'] = 'field_enrd_coop_context-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_context-revision_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_coop_context-revision_id']['type'] = 'text_plain';
  /* Field: Content (historical data): Project idea summary */
  $handler->display->display_options['fields']['field_enrd_coop_brief_summary-revision_id']['id'] = 'field_enrd_coop_brief_summary-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_brief_summary-revision_id']['table'] = 'field_revision_field_enrd_coop_brief_summary';
  $handler->display->display_options['fields']['field_enrd_coop_brief_summary-revision_id']['field'] = 'field_enrd_coop_brief_summary-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_brief_summary-revision_id']['exclude'] = TRUE;
  /* Field: Content (historical data): Objectives */
  $handler->display->display_options['fields']['field_enrd_coop_objectives-revision_id']['id'] = 'field_enrd_coop_objectives-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_objectives-revision_id']['table'] = 'field_revision_field_enrd_coop_objectives';
  $handler->display->display_options['fields']['field_enrd_coop_objectives-revision_id']['field'] = 'field_enrd_coop_objectives-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_objectives-revision_id']['exclude'] = TRUE;
  /* Field: Content (historical data): Region */
  $handler->display->display_options['fields']['field_enrd_coop_partner_region-revision_id']['id'] = 'field_enrd_coop_partner_region-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_partner_region-revision_id']['table'] = 'field_revision_field_enrd_coop_partner_region';
  $handler->display->display_options['fields']['field_enrd_coop_partner_region-revision_id']['field'] = 'field_enrd_coop_partner_region-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_partner_region-revision_id']['exclude'] = TRUE;
  /* Field: Content (historical data): Type of partner */
  $handler->display->display_options['fields']['field_enrd_coop_type_of_partner-revision_id']['id'] = 'field_enrd_coop_type_of_partner-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_type_of_partner-revision_id']['table'] = 'field_revision_field_enrd_coop_type_of_partner';
  $handler->display->display_options['fields']['field_enrd_coop_type_of_partner-revision_id']['field'] = 'field_enrd_coop_type_of_partner-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_type_of_partner-revision_id']['exclude'] = TRUE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'View online version';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['group'] = 1;
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'State';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['state']['group_info']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['group_info']['optional'] = FALSE;
  $handler->display->display_options['filters']['state']['group_info']['default_group'] = '1';
  $handler->display->display_options['filters']['state']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Currently online',
      'operator' => 'in',
      'value' => array(
        'published' => 'published',
        'all' => 0,
        'draft' => 0,
        'ready_to_be_published' => 0,
        'needs_review' => 0,
        'validated' => 0,
        'archived' => 0,
      ),
    ),
    2 => array(
      'title' => 'Archived',
      'operator' => 'in',
      'value' => array(
        'archived' => 'archived',
        'all' => 0,
        'draft' => 0,
        'ready_to_be_published' => 0,
        'needs_review' => 0,
        'validated' => 0,
        'published' => 0,
      ),
    ),
    3 => array(
      'title' => 'Updates',
      'operator' => 'in',
      'value' => array(
        'draft' => 'draft',
        'all' => 0,
        'ready_to_be_published' => 0,
        'needs_review' => 0,
        'validated' => 0,
        'published' => 0,
        'archived' => 0,
      ),
    ),
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search in the CLLD Partner Search Tool';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title_field-revision_id' => 'title_field-revision_id',
    'field_enrd_coop_context-revision_id' => 'field_enrd_coop_context-revision_id',
    'field_enrd_coop_brief_summary-revision_id' => 'field_enrd_coop_brief_summary-revision_id',
    'field_enrd_coop_objectives-revision_id' => 'field_enrd_coop_objectives-revision_id',
    'field_enrd_coop_partner_region-revision_id' => 'field_enrd_coop_partner_region-revision_id',
    'field_enrd_coop_type_of_partner-revision_id' => 'field_enrd_coop_type_of_partner-revision_id',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cooperation_offer' => 'cooperation_offer',
  );
  $handler->display->display_options['filters']['type']['group'] = 2;
  /* Filter criterion: Content: Has taxonomy terms (with depth; Simple hierarchical select) */
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['id'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['field'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['relationship'] = 'nid';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['group'] = 2;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator_id'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['label'] = 'Type of project';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['identifier'] = 'filter_project_type';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['vocabulary'] = 'enrd_project_types';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['depth'] = '3';
  /* Filter criterion: Content: Has taxonomy terms (with depth; Simple hierarchical select) */
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['id'] = 'shs_term_node_tid_depth_1';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['table'] = 'node';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['field'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['relationship'] = 'nid';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['group'] = 2;
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['expose']['operator_id'] = 'shs_term_node_tid_depth_1_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['expose']['label'] = 'Topic of the project';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['expose']['operator'] = 'shs_term_node_tid_depth_1_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['expose']['identifier'] = 'filter_project_topic';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['vocabulary'] = 'enrd_key_themes_of_strategy';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['depth'] = '3';
  /* Filter criterion: Field: Country (field_enrd_lag_country) */
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['id'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['table'] = 'field_data_field_enrd_lag_country';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['field'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['operator_id'] = 'field_enrd_lag_country_tid_op';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['operator'] = 'field_enrd_lag_country_tid_op';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['identifier'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['vocabulary'] = 'enrd_countries';
  /* Filter criterion: Content: Main ESI Fund (field_enrd_main_esi_fund) */
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['id'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['table'] = 'field_data_field_enrd_main_esi_fund';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['field'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['operator_id'] = 'field_enrd_main_esi_fund_tid_op';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['label'] = 'ESI Fund';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['operator'] = 'field_enrd_main_esi_fund_tid_op';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['identifier'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['vocabulary'] = 'enrd_esi_funds';
  /* Filter criterion: Content: Has taxonomy terms (with depth; Simple hierarchical select) */
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['id'] = 'shs_term_node_tid_depth_2';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['table'] = 'node';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['field'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['group'] = 2;
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['expose']['operator_id'] = 'shs_term_node_tid_depth_2_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['expose']['label'] = 'ESIF Programme';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['expose']['operator'] = 'shs_term_node_tid_depth_2_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['expose']['identifier'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['vocabulary'] = 'enrd_esif_programme';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['use_chosen'] = 'always';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['depth'] = '2';
  /* Filter criterion: Content (historical data): Expiry date (field_enrd_coop_expiry_date) */
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['id'] = 'field_enrd_coop_expiry_date_value';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['table'] = 'field_revision_field_enrd_coop_expiry_date';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['field'] = 'field_enrd_coop_expiry_date_value';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['group'] = 2;
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['expose']['operator_id'] = 'field_enrd_coop_expiry_date_value_op';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['expose']['label'] = 'Expiry date (field_enrd_coop_expiry_date)';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['expose']['operator'] = 'field_enrd_coop_expiry_date_value_op';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['expose']['identifier'] = 'field_enrd_coop_expiry_date_value';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['group_info']['label'] = 'Status';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['group_info']['identifier'] = 'field_enrd_coop_expiry_date';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['group_info']['optional'] = FALSE;
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['group_info']['default_group'] = '1';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Active',
      'operator' => '>=',
      'value' => array(
        'value_group' => array(
          'value_choose_input_type' => 'relative',
          'value' => NULL,
          'default_date' => 'now',
        ),
        'min_group' => array(
          'min_choose_input_type' => 'relative',
          'min' => NULL,
          'default_date' => 'now',
        ),
        'max_group' => array(
          'max_choose_input_type' => 'date',
          'max' => NULL,
          'default_to_date' => '',
        ),
      ),
    ),
    2 => array(
      'title' => 'Expired',
      'operator' => '<',
      'value' => array(
        'value_group' => array(
          'value_choose_input_type' => 'relative',
          'value' => NULL,
          'default_date' => 'now',
        ),
        'min_group' => array(
          'min_choose_input_type' => 'relative',
          'min' => NULL,
          'default_date' => 'now',
        ),
        'max_group' => array(
          'max_choose_input_type' => 'date',
          'max' => NULL,
          'default_to_date' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['default_date'] = 'now';
  /* Filter criterion: Workbench Moderation: Current */
  $handler->display->display_options['filters']['is_current']['id'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['value'] = '1';
  $handler->display->display_options['path'] = 'lag-dashboard/cooperation-offers/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Active';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 1;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Cooperation offers';
  $handler->display->display_options['tab_options']['weight'] = '5';

  /* Display: Page: Expired Cooperation offers - Admins */
  $handler = $view->new_display('page', 'Page: Expired Cooperation offers - Admins', 'coop_offers_page_expired');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Cooperation offers';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'esi_fund_context';
  $handler->display->display_options['access']['perm'] = 'access lag dashboards';
  $handler->display->display_options['access']['esi_fund_perm'] = 'access lag dashboards';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'full_html',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'combine' => array(
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
    'shs_term_node_tid_depth' => array(
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
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'shs_term_node_tid_depth_1' => array(
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
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_enrd_lag_country_tid' => array(
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
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_enrd_main_esi_fund_tid' => array(
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
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_enrd_esif_programme_tid' => array(
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
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'state' => array(
      'bef_format' => 'bef_links',
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
    'field_enrd_coop_expiry_date_value' => array(
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
        'datepicker_options' => '',
      ),
    ),
  );
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title_field-revision_id' => 'title_field-revision_id',
    'field_enrd_coop_type-revision_id' => 'field_enrd_coop_type-revision_id',
    'field_enrd_coop_topic_of_project-revision_id' => 'field_enrd_coop_topic_of_project-revision_id',
    'title_field' => 'title_field',
    'field_tax_country' => 'field_tax_country',
    'field_enrd_main_esi_fund' => 'field_enrd_main_esi_fund',
    'field_enrd_esif_programme' => 'field_enrd_esif_programme',
    'field_enrd_coop_expiry_date-revision_id' => 'field_enrd_coop_expiry_date-revision_id',
    'state' => 'state',
    'stamp' => 'stamp',
    'field_enrd_coop_context-revision_id' => 'field_enrd_coop_context-revision_id',
    'field_enrd_coop_brief_summary-revision_id' => 'field_enrd_coop_brief_summary-revision_id',
    'field_enrd_coop_objectives-revision_id' => 'field_enrd_coop_objectives-revision_id',
    'field_enrd_coop_partner_region-revision_id' => 'field_enrd_coop_partner_region-revision_id',
    'field_enrd_coop_type_of_partner-revision_id' => 'field_enrd_coop_type_of_partner-revision_id',
  );
  $handler->display->display_options['style_options']['default'] = 'stamp';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_field-revision_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_type-revision_id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_topic_of_project-revision_id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_field' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tax_country' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_main_esi_fund' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_esif_programme' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_expiry_date-revision_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'stamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_context-revision_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_brief_summary-revision_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_objectives-revision_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_partner_region-revision_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_type_of_partner-revision_id' => array(
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
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['label'] = 'Get the actual content from a content revision (NID)';
  /* Relationship: OG membership: OG membership from Content */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['relationship'] = 'nid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['id'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['field'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content revision */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node_revision';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::enrd_lag_dashboard_action_delete_coop_offer_draft' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_enrd_moderate_content_to_archived' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Archived',
    ),
    'rules_component::rules_enrd_moderate_content_to_draft' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Draft',
    ),
    'rules_component::rules_enrd_moderate_content_to_expired' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Expired',
    ),
    'rules_component::rules_enrd_moderate_content_to_published' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Published',
    ),
    'rules_component::rules_enrd_moderate_content_to_ready_to_be_published' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Ready to be published',
    ),
  );
  /* Field: Content revision: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content revision: Vid */
  $handler->display->display_options['fields']['vid']['id'] = 'vid';
  $handler->display->display_options['fields']['vid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['vid']['field'] = 'vid';
  $handler->display->display_options['fields']['vid']['label'] = '';
  $handler->display->display_options['fields']['vid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['vid']['element_label_colon'] = FALSE;
  /* Field: Content (historical data): Title */
  $handler->display->display_options['fields']['title_field-revision_id']['id'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['table'] = 'field_revision_title_field';
  $handler->display->display_options['fields']['title_field-revision_id']['field'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['label'] = 'Offer name';
  $handler->display->display_options['fields']['title_field-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_field-revision_id']['alter']['text'] = '[title_field-revision_id]';
  $handler->display->display_options['fields']['title_field-revision_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_field-revision_id']['alter']['path'] = 'node/[nid]/current-revision';
  /* Field: Content (historical data): Project type */
  $handler->display->display_options['fields']['field_enrd_coop_type-revision_id']['id'] = 'field_enrd_coop_type-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_type-revision_id']['table'] = 'field_revision_field_enrd_coop_type';
  $handler->display->display_options['fields']['field_enrd_coop_type-revision_id']['field'] = 'field_enrd_coop_type-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_type-revision_id']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_enrd_coop_type-revision_id']['delta_offset'] = '0';
  /* Field: Content (historical data): Project topic */
  $handler->display->display_options['fields']['field_enrd_coop_topic_of_project-revision_id']['id'] = 'field_enrd_coop_topic_of_project-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_topic_of_project-revision_id']['table'] = 'field_revision_field_enrd_coop_topic_of_project';
  $handler->display->display_options['fields']['field_enrd_coop_topic_of_project-revision_id']['field'] = 'field_enrd_coop_topic_of_project-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_topic_of_project-revision_id']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_enrd_coop_topic_of_project-revision_id']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['fields']['title_field']['label'] = 'LAG name';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_tax_country']['id'] = 'field_tax_country';
  $handler->display->display_options['fields']['field_tax_country']['table'] = 'field_data_field_tax_country';
  $handler->display->display_options['fields']['field_tax_country']['field'] = 'field_tax_country';
  $handler->display->display_options['fields']['field_tax_country']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_tax_country']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tax_country']['delta_offset'] = '0';
  /* Field: Content: Main ESI Fund */
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['id'] = 'field_enrd_main_esi_fund';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['table'] = 'field_data_field_enrd_main_esi_fund';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['field'] = 'field_enrd_main_esi_fund';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: ESIF Programme */
  $handler->display->display_options['fields']['field_enrd_esif_programme']['id'] = 'field_enrd_esif_programme';
  $handler->display->display_options['fields']['field_enrd_esif_programme']['table'] = 'field_data_field_enrd_esif_programme';
  $handler->display->display_options['fields']['field_enrd_esif_programme']['field'] = 'field_enrd_esif_programme';
  $handler->display->display_options['fields']['field_enrd_esif_programme']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['fields']['field_enrd_esif_programme']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content (historical data): Expiry date */
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['id'] = 'field_enrd_coop_expiry_date-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['table'] = 'field_revision_field_enrd_coop_expiry_date';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['field'] = 'field_enrd_coop_expiry_date-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Workbench Moderation: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Workflow state';
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  /* Field: Workbench Moderation: Timestamp */
  $handler->display->display_options['fields']['stamp']['id'] = 'stamp';
  $handler->display->display_options['fields']['stamp']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['stamp']['field'] = 'stamp';
  $handler->display->display_options['fields']['stamp']['label'] = 'Revised on';
  $handler->display->display_options['fields']['stamp']['date_format'] = 'short';
  $handler->display->display_options['fields']['stamp']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Content (historical data): Context */
  $handler->display->display_options['fields']['field_enrd_coop_context-revision_id']['id'] = 'field_enrd_coop_context-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_context-revision_id']['table'] = 'field_revision_field_enrd_coop_context';
  $handler->display->display_options['fields']['field_enrd_coop_context-revision_id']['field'] = 'field_enrd_coop_context-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_context-revision_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_coop_context-revision_id']['type'] = 'text_plain';
  /* Field: Content (historical data): Project idea summary */
  $handler->display->display_options['fields']['field_enrd_coop_brief_summary-revision_id']['id'] = 'field_enrd_coop_brief_summary-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_brief_summary-revision_id']['table'] = 'field_revision_field_enrd_coop_brief_summary';
  $handler->display->display_options['fields']['field_enrd_coop_brief_summary-revision_id']['field'] = 'field_enrd_coop_brief_summary-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_brief_summary-revision_id']['exclude'] = TRUE;
  /* Field: Content (historical data): Objectives */
  $handler->display->display_options['fields']['field_enrd_coop_objectives-revision_id']['id'] = 'field_enrd_coop_objectives-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_objectives-revision_id']['table'] = 'field_revision_field_enrd_coop_objectives';
  $handler->display->display_options['fields']['field_enrd_coop_objectives-revision_id']['field'] = 'field_enrd_coop_objectives-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_objectives-revision_id']['exclude'] = TRUE;
  /* Field: Content (historical data): Region */
  $handler->display->display_options['fields']['field_enrd_coop_partner_region-revision_id']['id'] = 'field_enrd_coop_partner_region-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_partner_region-revision_id']['table'] = 'field_revision_field_enrd_coop_partner_region';
  $handler->display->display_options['fields']['field_enrd_coop_partner_region-revision_id']['field'] = 'field_enrd_coop_partner_region-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_partner_region-revision_id']['exclude'] = TRUE;
  /* Field: Content (historical data): Type of partner */
  $handler->display->display_options['fields']['field_enrd_coop_type_of_partner-revision_id']['id'] = 'field_enrd_coop_type_of_partner-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_type_of_partner-revision_id']['table'] = 'field_revision_field_enrd_coop_type_of_partner';
  $handler->display->display_options['fields']['field_enrd_coop_type_of_partner-revision_id']['field'] = 'field_enrd_coop_type_of_partner-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_type_of_partner-revision_id']['exclude'] = TRUE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'View online version';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['group'] = 1;
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'State';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['state']['group_info']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['group_info']['optional'] = FALSE;
  $handler->display->display_options['filters']['state']['group_info']['default_group'] = '1';
  $handler->display->display_options['filters']['state']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Currently online',
      'operator' => 'in',
      'value' => array(
        'published' => 'published',
        'all' => 0,
        'draft' => 0,
        'ready_to_be_published' => 0,
        'needs_review' => 0,
        'validated' => 0,
        'archived' => 0,
      ),
    ),
    2 => array(
      'title' => 'Archived',
      'operator' => 'in',
      'value' => array(
        'archived' => 'archived',
        'all' => 0,
        'draft' => 0,
        'ready_to_be_published' => 0,
        'needs_review' => 0,
        'validated' => 0,
        'published' => 0,
      ),
    ),
    3 => array(
      'title' => 'Updates',
      'operator' => 'in',
      'value' => array(
        'draft' => 'draft',
        'all' => 0,
        'ready_to_be_published' => 0,
        'needs_review' => 0,
        'validated' => 0,
        'published' => 0,
        'archived' => 0,
      ),
    ),
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search in the CLLD Partner Search Tool';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title_field-revision_id' => 'title_field-revision_id',
    'field_enrd_coop_context-revision_id' => 'field_enrd_coop_context-revision_id',
    'field_enrd_coop_brief_summary-revision_id' => 'field_enrd_coop_brief_summary-revision_id',
    'field_enrd_coop_objectives-revision_id' => 'field_enrd_coop_objectives-revision_id',
    'field_enrd_coop_partner_region-revision_id' => 'field_enrd_coop_partner_region-revision_id',
    'field_enrd_coop_type_of_partner-revision_id' => 'field_enrd_coop_type_of_partner-revision_id',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cooperation_offer' => 'cooperation_offer',
  );
  $handler->display->display_options['filters']['type']['group'] = 2;
  /* Filter criterion: Content: Has taxonomy terms (with depth; Simple hierarchical select) */
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['id'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['field'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['relationship'] = 'nid';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['group'] = 2;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator_id'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['label'] = 'Type of project';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['identifier'] = 'filter_project_type';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['vocabulary'] = 'enrd_project_types';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['depth'] = '3';
  /* Filter criterion: Content: Has taxonomy terms (with depth; Simple hierarchical select) */
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['id'] = 'shs_term_node_tid_depth_1';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['table'] = 'node';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['field'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['relationship'] = 'nid';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['group'] = 2;
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['expose']['operator_id'] = 'shs_term_node_tid_depth_1_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['expose']['label'] = 'Topic of the project';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['expose']['operator'] = 'shs_term_node_tid_depth_1_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['expose']['identifier'] = 'filter_project_topic';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['vocabulary'] = 'enrd_key_themes_of_strategy';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['depth'] = '3';
  /* Filter criterion: Field: Country (field_enrd_lag_country) */
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['id'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['table'] = 'field_data_field_enrd_lag_country';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['field'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['operator_id'] = 'field_enrd_lag_country_tid_op';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['operator'] = 'field_enrd_lag_country_tid_op';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['identifier'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['vocabulary'] = 'enrd_countries';
  /* Filter criterion: Content: Main ESI Fund (field_enrd_main_esi_fund) */
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['id'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['table'] = 'field_data_field_enrd_main_esi_fund';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['field'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['operator_id'] = 'field_enrd_main_esi_fund_tid_op';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['label'] = 'ESI Fund';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['operator'] = 'field_enrd_main_esi_fund_tid_op';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['identifier'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['vocabulary'] = 'enrd_esi_funds';
  /* Filter criterion: Content: Has taxonomy terms (with depth; Simple hierarchical select) */
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['id'] = 'shs_term_node_tid_depth_2';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['table'] = 'node';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['field'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['group'] = 2;
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['expose']['operator_id'] = 'shs_term_node_tid_depth_2_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['expose']['label'] = 'ESIF Programme';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['expose']['operator'] = 'shs_term_node_tid_depth_2_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['expose']['identifier'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['vocabulary'] = 'enrd_esif_programme';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['use_chosen'] = 'always';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['depth'] = '2';
  /* Filter criterion: Content (historical data): Expiry date (field_enrd_coop_expiry_date) */
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['id'] = 'field_enrd_coop_expiry_date_value';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['table'] = 'field_revision_field_enrd_coop_expiry_date';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['field'] = 'field_enrd_coop_expiry_date_value';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['group'] = 2;
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['expose']['operator_id'] = 'field_enrd_coop_expiry_date_value_op';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['expose']['label'] = 'Expiry date (field_enrd_coop_expiry_date)';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['expose']['operator'] = 'field_enrd_coop_expiry_date_value_op';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['expose']['identifier'] = 'field_enrd_coop_expiry_date_value';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['group_info']['label'] = 'Status';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['group_info']['identifier'] = 'field_enrd_coop_expiry_date';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['group_info']['optional'] = FALSE;
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['group_info']['default_group'] = '1';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Active',
      'operator' => '>=',
      'value' => array(
        'value_group' => array(
          'value_choose_input_type' => 'relative',
          'value' => NULL,
          'default_date' => 'now',
        ),
        'min_group' => array(
          'min_choose_input_type' => 'relative',
          'min' => NULL,
          'default_date' => 'now',
        ),
        'max_group' => array(
          'max_choose_input_type' => 'date',
          'max' => NULL,
          'default_to_date' => '',
        ),
      ),
    ),
    2 => array(
      'title' => 'Expired',
      'operator' => '<',
      'value' => array(
        'value_group' => array(
          'value_choose_input_type' => 'relative',
          'value' => NULL,
          'default_date' => 'now',
        ),
        'min_group' => array(
          'min_choose_input_type' => 'relative',
          'min' => NULL,
          'default_date' => 'now',
        ),
        'max_group' => array(
          'max_choose_input_type' => 'date',
          'max' => NULL,
          'default_to_date' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['default_date'] = 'now';
  /* Filter criterion: Workbench Moderation: Current */
  $handler->display->display_options['filters']['is_current']['id'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['value'] = '1';
  $handler->display->display_options['filters']['is_current']['group'] = 2;
  $handler->display->display_options['path'] = 'lag-dashboard/cooperation-offers/expired';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Expired';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 1;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Cooperation Offers';
  $handler->display->display_options['tab_options']['weight'] = '5';

  /* Display: Page: Pending requests - Admins - Coop Offers */
  $handler = $view->new_display('page', 'Page: Pending requests - Admins - Coop Offers', 'pending_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Cooperation offers';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'esi_fund_context';
  $handler->display->display_options['access']['perm'] = 'access lag dashboards';
  $handler->display->display_options['access']['esi_fund_perm'] = 'access lag dashboards';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title_field-revision_id' => 'title_field-revision_id',
    'field_enrd_coop_type-revision_id' => 'field_enrd_coop_type-revision_id',
    'field_enrd_coop_topic_of_project-revision_id' => 'field_enrd_coop_topic_of_project-revision_id',
    'field_enrd_coop_context-revision_id' => 'field_enrd_coop_context-revision_id',
    'field_enrd_coop_brief_summary-revision_id' => 'field_enrd_coop_brief_summary-revision_id',
    'field_enrd_coop_objectives-revision_id' => 'field_enrd_coop_objectives-revision_id',
    'field_enrd_coop_partner_region-revision_id' => 'field_enrd_coop_partner_region-revision_id',
    'field_enrd_coop_type_of_partner-revision_id' => 'field_enrd_coop_type_of_partner-revision_id',
    'title_field' => 'title_field',
    'field_tax_country' => 'field_tax_country',
    'field_enrd_main_esi_fund' => 'field_enrd_main_esi_fund',
    'field_enrd_esif_programme' => 'field_enrd_esif_programme',
    'field_enrd_coop_expiry_date-revision_id' => 'field_enrd_coop_expiry_date-revision_id',
    'state' => 'state',
    'stamp' => 'stamp',
  );
  $handler->display->display_options['style_options']['default'] = 'stamp';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_field-revision_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_type-revision_id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_topic_of_project-revision_id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_context-revision_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_brief_summary-revision_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_objectives-revision_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_partner_region-revision_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_type_of_partner-revision_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_field' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tax_country' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_main_esi_fund' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_esif_programme' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_coop_expiry_date-revision_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'stamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['label'] = 'Get the actual content from a content revision (NID)';
  /* Relationship: OG membership: OG membership from Content */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['relationship'] = 'nid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['id'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['field'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content revision */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node_revision';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::rules_enrd_moderate_content_to_archived' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Archived',
    ),
    'rules_component::rules_enrd_moderate_content_to_draft' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Draft',
    ),
    'rules_component::rules_enrd_moderate_content_to_expired' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Expired',
    ),
    'rules_component::rules_enrd_moderate_content_to_published' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Published',
    ),
    'rules_component::rules_enrd_moderate_content_to_ready_to_be_published' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Ready to be published',
    ),
  );
  /* Field: Content revision: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content revision: Vid */
  $handler->display->display_options['fields']['vid']['id'] = 'vid';
  $handler->display->display_options['fields']['vid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['vid']['field'] = 'vid';
  $handler->display->display_options['fields']['vid']['label'] = '';
  $handler->display->display_options['fields']['vid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['vid']['element_label_colon'] = FALSE;
  /* Field: Content (historical data): Title */
  $handler->display->display_options['fields']['title_field-revision_id']['id'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['table'] = 'field_revision_title_field';
  $handler->display->display_options['fields']['title_field-revision_id']['field'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['label'] = 'Offer name';
  $handler->display->display_options['fields']['title_field-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_field-revision_id']['alter']['text'] = '[title_field-revision_id]';
  $handler->display->display_options['fields']['title_field-revision_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_field-revision_id']['alter']['path'] = 'node/[nid]/current-revision';
  /* Field: Content (historical data): Project type */
  $handler->display->display_options['fields']['field_enrd_coop_type-revision_id']['id'] = 'field_enrd_coop_type-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_type-revision_id']['table'] = 'field_revision_field_enrd_coop_type';
  $handler->display->display_options['fields']['field_enrd_coop_type-revision_id']['field'] = 'field_enrd_coop_type-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_type-revision_id']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_enrd_coop_type-revision_id']['delta_offset'] = '0';
  /* Field: Content (historical data): Project topic */
  $handler->display->display_options['fields']['field_enrd_coop_topic_of_project-revision_id']['id'] = 'field_enrd_coop_topic_of_project-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_topic_of_project-revision_id']['table'] = 'field_revision_field_enrd_coop_topic_of_project';
  $handler->display->display_options['fields']['field_enrd_coop_topic_of_project-revision_id']['field'] = 'field_enrd_coop_topic_of_project-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_topic_of_project-revision_id']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_enrd_coop_topic_of_project-revision_id']['delta_offset'] = '0';
  /* Field: Content (historical data): Context */
  $handler->display->display_options['fields']['field_enrd_coop_context-revision_id']['id'] = 'field_enrd_coop_context-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_context-revision_id']['table'] = 'field_revision_field_enrd_coop_context';
  $handler->display->display_options['fields']['field_enrd_coop_context-revision_id']['field'] = 'field_enrd_coop_context-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_context-revision_id']['exclude'] = TRUE;
  /* Field: Content (historical data): Project idea summary */
  $handler->display->display_options['fields']['field_enrd_coop_brief_summary-revision_id']['id'] = 'field_enrd_coop_brief_summary-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_brief_summary-revision_id']['table'] = 'field_revision_field_enrd_coop_brief_summary';
  $handler->display->display_options['fields']['field_enrd_coop_brief_summary-revision_id']['field'] = 'field_enrd_coop_brief_summary-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_brief_summary-revision_id']['exclude'] = TRUE;
  /* Field: Content (historical data): Objectives */
  $handler->display->display_options['fields']['field_enrd_coop_objectives-revision_id']['id'] = 'field_enrd_coop_objectives-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_objectives-revision_id']['table'] = 'field_revision_field_enrd_coop_objectives';
  $handler->display->display_options['fields']['field_enrd_coop_objectives-revision_id']['field'] = 'field_enrd_coop_objectives-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_objectives-revision_id']['exclude'] = TRUE;
  /* Field: Content (historical data): Region */
  $handler->display->display_options['fields']['field_enrd_coop_partner_region-revision_id']['id'] = 'field_enrd_coop_partner_region-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_partner_region-revision_id']['table'] = 'field_revision_field_enrd_coop_partner_region';
  $handler->display->display_options['fields']['field_enrd_coop_partner_region-revision_id']['field'] = 'field_enrd_coop_partner_region-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_partner_region-revision_id']['exclude'] = TRUE;
  /* Field: Content (historical data): Type of partner */
  $handler->display->display_options['fields']['field_enrd_coop_type_of_partner-revision_id']['id'] = 'field_enrd_coop_type_of_partner-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_type_of_partner-revision_id']['table'] = 'field_revision_field_enrd_coop_type_of_partner';
  $handler->display->display_options['fields']['field_enrd_coop_type_of_partner-revision_id']['field'] = 'field_enrd_coop_type_of_partner-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_type_of_partner-revision_id']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['fields']['title_field']['label'] = 'LAG name';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_tax_country']['id'] = 'field_tax_country';
  $handler->display->display_options['fields']['field_tax_country']['table'] = 'field_data_field_tax_country';
  $handler->display->display_options['fields']['field_tax_country']['field'] = 'field_tax_country';
  $handler->display->display_options['fields']['field_tax_country']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_tax_country']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tax_country']['delta_offset'] = '0';
  /* Field: Content: Main ESI Fund */
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['id'] = 'field_enrd_main_esi_fund';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['table'] = 'field_data_field_enrd_main_esi_fund';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['field'] = 'field_enrd_main_esi_fund';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: ESIF Programme */
  $handler->display->display_options['fields']['field_enrd_esif_programme']['id'] = 'field_enrd_esif_programme';
  $handler->display->display_options['fields']['field_enrd_esif_programme']['table'] = 'field_data_field_enrd_esif_programme';
  $handler->display->display_options['fields']['field_enrd_esif_programme']['field'] = 'field_enrd_esif_programme';
  $handler->display->display_options['fields']['field_enrd_esif_programme']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['fields']['field_enrd_esif_programme']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content (historical data): Expiry date */
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['id'] = 'field_enrd_coop_expiry_date-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['table'] = 'field_revision_field_enrd_coop_expiry_date';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['field'] = 'field_enrd_coop_expiry_date-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Workbench Moderation: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Workflow state';
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  /* Field: Workbench Moderation: Timestamp */
  $handler->display->display_options['fields']['stamp']['id'] = 'stamp';
  $handler->display->display_options['fields']['stamp']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['stamp']['field'] = 'stamp';
  $handler->display->display_options['fields']['stamp']['label'] = 'Requested on';
  $handler->display->display_options['fields']['stamp']['date_format'] = 'short';
  $handler->display->display_options['fields']['stamp']['second_date_format'] = 'enrd_lag_database_d_m_y';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['group'] = 1;
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'State';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['state']['group_info']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['group_info']['optional'] = FALSE;
  $handler->display->display_options['filters']['state']['group_info']['default_group'] = '1';
  $handler->display->display_options['filters']['state']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Ready to be published',
      'operator' => 'in',
      'value' => array(
        'ready_to_be_published' => 'ready_to_be_published',
        'all' => 0,
        'draft' => 0,
        'needs_review' => 0,
        'validated' => 0,
        'published' => 0,
        'archived' => 0,
      ),
    ),
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search in the CLLD Partner Search Tool';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title_field-revision_id' => 'title_field-revision_id',
    'field_enrd_coop_context-revision_id' => 'field_enrd_coop_context-revision_id',
    'field_enrd_coop_brief_summary-revision_id' => 'field_enrd_coop_brief_summary-revision_id',
    'field_enrd_coop_objectives-revision_id' => 'field_enrd_coop_objectives-revision_id',
    'field_enrd_coop_partner_region-revision_id' => 'field_enrd_coop_partner_region-revision_id',
    'field_enrd_coop_type_of_partner-revision_id' => 'field_enrd_coop_type_of_partner-revision_id',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cooperation_offer' => 'cooperation_offer',
  );
  $handler->display->display_options['filters']['type']['group'] = 2;
  /* Filter criterion: Content: Has taxonomy terms (with depth; Simple hierarchical select) */
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['id'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['field'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['relationship'] = 'nid';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['group'] = 2;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator_id'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['label'] = 'Type of project';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['identifier'] = 'filter_project_type';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['vocabulary'] = 'enrd_project_types';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['depth'] = '3';
  /* Filter criterion: Content: Has taxonomy terms (with depth; Simple hierarchical select) */
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['id'] = 'shs_term_node_tid_depth_1';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['table'] = 'node';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['field'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['relationship'] = 'nid';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['group'] = 2;
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['expose']['operator_id'] = 'shs_term_node_tid_depth_1_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['expose']['label'] = 'Topic of the project';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['expose']['operator'] = 'shs_term_node_tid_depth_1_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['expose']['identifier'] = 'filter_project_topic';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['vocabulary'] = 'enrd_key_themes_of_strategy';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['depth'] = '3';
  /* Filter criterion: Field: Country (field_enrd_lag_country) */
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['id'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['table'] = 'field_data_field_enrd_lag_country';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['field'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['operator_id'] = 'field_enrd_lag_country_tid_op';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['operator'] = 'field_enrd_lag_country_tid_op';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['identifier'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['vocabulary'] = 'enrd_countries';
  /* Filter criterion: Content: Main ESI Fund (field_enrd_main_esi_fund) */
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['id'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['table'] = 'field_data_field_enrd_main_esi_fund';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['field'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['operator_id'] = 'field_enrd_main_esi_fund_tid_op';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['label'] = 'ESI Fund';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['operator'] = 'field_enrd_main_esi_fund_tid_op';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['identifier'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['vocabulary'] = 'enrd_esi_funds';
  /* Filter criterion: Content: Has taxonomy terms (with depth; Simple hierarchical select) */
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['id'] = 'shs_term_node_tid_depth_2';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['table'] = 'node';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['field'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['group'] = 2;
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['expose']['operator_id'] = 'shs_term_node_tid_depth_2_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['expose']['label'] = 'ESIF Programme';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['expose']['operator'] = 'shs_term_node_tid_depth_2_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['expose']['identifier'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['vocabulary'] = 'enrd_esif_programme';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['use_chosen'] = 'always';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['depth'] = '2';
  /* Filter criterion: Workbench Moderation: Current */
  $handler->display->display_options['filters']['is_current']['id'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['value'] = '1';
  $handler->display->display_options['filters']['is_current']['group'] = 2;
  /* Filter criterion: Workbench Moderation: Published */
  $handler->display->display_options['filters']['published']['id'] = 'published';
  $handler->display->display_options['filters']['published']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['published']['field'] = 'published';
  $handler->display->display_options['filters']['published']['value'] = '0';
  $handler->display->display_options['filters']['published']['group'] = 2;
  $handler->display->display_options['path'] = 'lag-dashboard/cooperation-offers/pending';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Pending for publication';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 1;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export: Cooperation offers - Admins */
  $handler = $view->new_display('views_data_export', 'Data export: Cooperation offers - Admins', 'views_data_export_coop_offers_active');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Cooperation offers';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'esi_fund_context';
  $handler->display->display_options['access']['perm'] = 'access lag dashboards';
  $handler->display->display_options['access']['esi_fund_perm'] = 'access lag dashboards';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['attach_text'] = 'Export';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'cooperation-offers.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['quote'] = '1';
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['label'] = 'Get the actual content from a content revision (NID)';
  /* Relationship: OG membership: OG membership from Content */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['relationship'] = 'nid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['id'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['field'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content (historical data): Title */
  $handler->display->display_options['fields']['title_field-revision_id']['id'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['table'] = 'field_revision_title_field';
  $handler->display->display_options['fields']['title_field-revision_id']['field'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['label'] = 'Offer name';
  /* Field: Content (historical data): Project type */
  $handler->display->display_options['fields']['field_enrd_coop_type-revision_id']['id'] = 'field_enrd_coop_type-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_type-revision_id']['table'] = 'field_revision_field_enrd_coop_type';
  $handler->display->display_options['fields']['field_enrd_coop_type-revision_id']['field'] = 'field_enrd_coop_type-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_type-revision_id']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_enrd_coop_type-revision_id']['delta_offset'] = '0';
  /* Field: Content (historical data): Project topic */
  $handler->display->display_options['fields']['field_enrd_coop_topic_of_project-revision_id']['id'] = 'field_enrd_coop_topic_of_project-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_topic_of_project-revision_id']['table'] = 'field_revision_field_enrd_coop_topic_of_project';
  $handler->display->display_options['fields']['field_enrd_coop_topic_of_project-revision_id']['field'] = 'field_enrd_coop_topic_of_project-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_topic_of_project-revision_id']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_enrd_coop_topic_of_project-revision_id']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['fields']['title_field']['label'] = 'LAG name';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_tax_country']['id'] = 'field_tax_country';
  $handler->display->display_options['fields']['field_tax_country']['table'] = 'field_data_field_tax_country';
  $handler->display->display_options['fields']['field_tax_country']['field'] = 'field_tax_country';
  $handler->display->display_options['fields']['field_tax_country']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_tax_country']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tax_country']['delta_offset'] = '0';
  /* Field: Content: Main ESI Fund */
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['id'] = 'field_enrd_main_esi_fund';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['table'] = 'field_data_field_enrd_main_esi_fund';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['field'] = 'field_enrd_main_esi_fund';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: ESIF Programme */
  $handler->display->display_options['fields']['field_enrd_esif_programme']['id'] = 'field_enrd_esif_programme';
  $handler->display->display_options['fields']['field_enrd_esif_programme']['table'] = 'field_data_field_enrd_esif_programme';
  $handler->display->display_options['fields']['field_enrd_esif_programme']['field'] = 'field_enrd_esif_programme';
  $handler->display->display_options['fields']['field_enrd_esif_programme']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['fields']['field_enrd_esif_programme']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content (historical data): Expiry date */
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['id'] = 'field_enrd_coop_expiry_date-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['table'] = 'field_revision_field_enrd_coop_expiry_date';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['field'] = 'field_enrd_coop_expiry_date-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Workbench Moderation: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Workflow state';
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  /* Field: Workbench Moderation: Timestamp */
  $handler->display->display_options['fields']['stamp']['id'] = 'stamp';
  $handler->display->display_options['fields']['stamp']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['stamp']['field'] = 'stamp';
  $handler->display->display_options['fields']['stamp']['label'] = 'Revised on';
  $handler->display->display_options['fields']['stamp']['date_format'] = 'short';
  $handler->display->display_options['fields']['stamp']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Content (historical data): Objectives */
  $handler->display->display_options['fields']['field_enrd_coop_objectives-revision_id']['id'] = 'field_enrd_coop_objectives-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_objectives-revision_id']['table'] = 'field_revision_field_enrd_coop_objectives';
  $handler->display->display_options['fields']['field_enrd_coop_objectives-revision_id']['field'] = 'field_enrd_coop_objectives-revision_id';
  /* Field: Content (historical data): Project idea summary */
  $handler->display->display_options['fields']['field_enrd_coop_brief_summary-revision_id']['id'] = 'field_enrd_coop_brief_summary-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_brief_summary-revision_id']['table'] = 'field_revision_field_enrd_coop_brief_summary';
  $handler->display->display_options['fields']['field_enrd_coop_brief_summary-revision_id']['field'] = 'field_enrd_coop_brief_summary-revision_id';
  /* Field: Content (historical data): Region */
  $handler->display->display_options['fields']['field_enrd_coop_partner_region-revision_id']['id'] = 'field_enrd_coop_partner_region-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_partner_region-revision_id']['table'] = 'field_revision_field_enrd_coop_partner_region';
  $handler->display->display_options['fields']['field_enrd_coop_partner_region-revision_id']['field'] = 'field_enrd_coop_partner_region-revision_id';
  /* Field: Content (historical data): Type of partner */
  $handler->display->display_options['fields']['field_enrd_coop_type_of_partner-revision_id']['id'] = 'field_enrd_coop_type_of_partner-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_type_of_partner-revision_id']['table'] = 'field_revision_field_enrd_coop_type_of_partner';
  $handler->display->display_options['fields']['field_enrd_coop_type_of_partner-revision_id']['field'] = 'field_enrd_coop_type_of_partner-revision_id';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content revision: Updated date */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Sort criterion: Field: Country (field_enrd_lag_country) */
  $handler->display->display_options['sorts']['field_enrd_lag_country_tid']['id'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['sorts']['field_enrd_lag_country_tid']['table'] = 'field_data_field_enrd_lag_country';
  $handler->display->display_options['sorts']['field_enrd_lag_country_tid']['field'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['sorts']['field_enrd_lag_country_tid']['relationship'] = 'nid';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['group'] = 1;
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'State';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['state']['group_info']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['group_info']['optional'] = FALSE;
  $handler->display->display_options['filters']['state']['group_info']['default_group'] = '1';
  $handler->display->display_options['filters']['state']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Currently online',
      'operator' => 'in',
      'value' => array(
        'published' => 'published',
        'all' => 0,
        'draft' => 0,
        'ready_to_be_published' => 0,
        'needs_review' => 0,
        'validated' => 0,
        'archived' => 0,
      ),
    ),
    2 => array(
      'title' => 'Archived',
      'operator' => 'in',
      'value' => array(
        'archived' => 'archived',
        'all' => 0,
        'draft' => 0,
        'ready_to_be_published' => 0,
        'needs_review' => 0,
        'validated' => 0,
        'published' => 0,
      ),
    ),
    3 => array(
      'title' => 'Updates',
      'operator' => 'in',
      'value' => array(
        'draft' => 'draft',
        'all' => 0,
        'ready_to_be_published' => 0,
        'needs_review' => 0,
        'validated' => 0,
        'published' => 0,
        'archived' => 0,
      ),
    ),
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search in the CLLD Partner Search Tool';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title_field-revision_id' => 'title_field-revision_id',
    'field_enrd_coop_context-revision_id' => 'field_enrd_coop_context-revision_id',
    'field_enrd_coop_objectives-revision_id' => 'field_enrd_coop_objectives-revision_id',
    'field_enrd_coop_brief_summary-revision_id' => 'field_enrd_coop_brief_summary-revision_id',
    'field_enrd_coop_partner_region-revision_id' => 'field_enrd_coop_partner_region-revision_id',
    'field_enrd_coop_type_of_partner-revision_id' => 'field_enrd_coop_type_of_partner-revision_id',
  );
  /* Filter criterion: Content (historical data): Expiry date (field_enrd_coop_expiry_date) */
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['id'] = 'field_enrd_coop_expiry_date_value';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['table'] = 'field_revision_field_enrd_coop_expiry_date';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['field'] = 'field_enrd_coop_expiry_date_value';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['expose']['operator_id'] = 'field_enrd_coop_expiry_date_value_op';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['expose']['label'] = 'Expiry date';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['expose']['operator'] = 'field_enrd_coop_expiry_date_value_op';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['expose']['identifier'] = 'field_enrd_coop_expiry_date_value';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cooperation_offer' => 'cooperation_offer',
  );
  $handler->display->display_options['filters']['type']['group'] = 2;
  /* Filter criterion: Workbench Moderation: Current */
  $handler->display->display_options['filters']['is_current']['id'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['value'] = '1';
  $handler->display->display_options['filters']['is_current']['group'] = 2;
  /* Filter criterion: Content: Has taxonomy terms (with depth; Simple hierarchical select) */
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['id'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['field'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['relationship'] = 'nid';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['group'] = 2;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator_id'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['label'] = 'Type of project';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['identifier'] = 'filter_project_type';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['vocabulary'] = 'enrd_project_types';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['depth'] = '3';
  /* Filter criterion: Content: Has taxonomy terms (with depth; Simple hierarchical select) */
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['id'] = 'shs_term_node_tid_depth_1';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['table'] = 'node';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['field'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['relationship'] = 'nid';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['group'] = 2;
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['expose']['operator_id'] = 'shs_term_node_tid_depth_1_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['expose']['label'] = 'Topic of the project';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['expose']['operator'] = 'shs_term_node_tid_depth_1_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['expose']['identifier'] = 'filter_project_topic';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['vocabulary'] = 'enrd_key_themes_of_strategy';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['depth'] = '3';
  /* Filter criterion: Field: Country (field_enrd_lag_country) */
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['id'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['table'] = 'field_data_field_enrd_lag_country';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['field'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['operator_id'] = 'field_enrd_lag_country_tid_op';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['operator'] = 'field_enrd_lag_country_tid_op';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['identifier'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['vocabulary'] = 'enrd_countries';
  /* Filter criterion: Content: Main ESI Fund (field_enrd_main_esi_fund) */
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['id'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['table'] = 'field_data_field_enrd_main_esi_fund';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['field'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['operator_id'] = 'field_enrd_main_esi_fund_tid_op';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['label'] = 'ESI Fund';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['operator'] = 'field_enrd_main_esi_fund_tid_op';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['identifier'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['vocabulary'] = 'enrd_esi_funds';
  /* Filter criterion: Content: Has taxonomy terms (with depth; Simple hierarchical select) */
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['id'] = 'shs_term_node_tid_depth_2';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['table'] = 'node';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['field'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['group'] = 2;
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['expose']['operator_id'] = 'shs_term_node_tid_depth_2_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['expose']['label'] = 'ESIF Programme';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['expose']['operator'] = 'shs_term_node_tid_depth_2_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['expose']['identifier'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['vocabulary'] = 'enrd_esif_programme';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['use_chosen'] = 'always';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['depth'] = '2';
  $handler->display->display_options['path'] = 'lag-dashboard/cooperation-offers.csv';
  $handler->display->display_options['displays'] = array(
    'coop_offers_page_active' => 'coop_offers_page_active',
    'default' => 0,
    'coop_offers_page_expired' => 0,
    'coop_offers_contextual' => 0,
    'pending_page' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'lag-dashboard/cooperation-offers';
  $handler->display->display_options['segment_size'] = '50';

  /* Display: Data export: Cooperation offers expired - Admins */
  $handler = $view->new_display('views_data_export', 'Data export: Cooperation offers expired - Admins', 'views_data_export_coop_offers_expired');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Cooperation offers';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'esi_fund_context';
  $handler->display->display_options['access']['perm'] = 'access lag dashboards';
  $handler->display->display_options['access']['esi_fund_perm'] = 'access lag dashboards';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['attach_text'] = 'Export';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'cooperation-offers-expired.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['quote'] = '1';
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['label'] = 'Get the actual content from a content revision (NID)';
  /* Relationship: OG membership: OG membership from Content */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['relationship'] = 'nid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['id'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['field'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content (historical data): Title */
  $handler->display->display_options['fields']['title_field-revision_id']['id'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['table'] = 'field_revision_title_field';
  $handler->display->display_options['fields']['title_field-revision_id']['field'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['label'] = 'Offer name';
  /* Field: Content (historical data): Project type */
  $handler->display->display_options['fields']['field_enrd_coop_type-revision_id']['id'] = 'field_enrd_coop_type-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_type-revision_id']['table'] = 'field_revision_field_enrd_coop_type';
  $handler->display->display_options['fields']['field_enrd_coop_type-revision_id']['field'] = 'field_enrd_coop_type-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_type-revision_id']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_enrd_coop_type-revision_id']['delta_offset'] = '0';
  /* Field: Content (historical data): Project topic */
  $handler->display->display_options['fields']['field_enrd_coop_topic_of_project-revision_id']['id'] = 'field_enrd_coop_topic_of_project-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_topic_of_project-revision_id']['table'] = 'field_revision_field_enrd_coop_topic_of_project';
  $handler->display->display_options['fields']['field_enrd_coop_topic_of_project-revision_id']['field'] = 'field_enrd_coop_topic_of_project-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_topic_of_project-revision_id']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_enrd_coop_topic_of_project-revision_id']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['fields']['title_field']['label'] = 'LAG name';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_tax_country']['id'] = 'field_tax_country';
  $handler->display->display_options['fields']['field_tax_country']['table'] = 'field_data_field_tax_country';
  $handler->display->display_options['fields']['field_tax_country']['field'] = 'field_tax_country';
  $handler->display->display_options['fields']['field_tax_country']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_tax_country']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tax_country']['delta_offset'] = '0';
  /* Field: Content: Main ESI Fund */
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['id'] = 'field_enrd_main_esi_fund';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['table'] = 'field_data_field_enrd_main_esi_fund';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['field'] = 'field_enrd_main_esi_fund';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: ESIF Programme */
  $handler->display->display_options['fields']['field_enrd_esif_programme']['id'] = 'field_enrd_esif_programme';
  $handler->display->display_options['fields']['field_enrd_esif_programme']['table'] = 'field_data_field_enrd_esif_programme';
  $handler->display->display_options['fields']['field_enrd_esif_programme']['field'] = 'field_enrd_esif_programme';
  $handler->display->display_options['fields']['field_enrd_esif_programme']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['fields']['field_enrd_esif_programme']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content (historical data): Expiry date */
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['id'] = 'field_enrd_coop_expiry_date-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['table'] = 'field_revision_field_enrd_coop_expiry_date';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['field'] = 'field_enrd_coop_expiry_date-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_expiry_date-revision_id']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Workbench Moderation: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Workflow state';
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  /* Field: Workbench Moderation: Timestamp */
  $handler->display->display_options['fields']['stamp']['id'] = 'stamp';
  $handler->display->display_options['fields']['stamp']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['stamp']['field'] = 'stamp';
  $handler->display->display_options['fields']['stamp']['label'] = 'Revised on';
  $handler->display->display_options['fields']['stamp']['date_format'] = 'short';
  $handler->display->display_options['fields']['stamp']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Content (historical data): Objectives */
  $handler->display->display_options['fields']['field_enrd_coop_objectives-revision_id']['id'] = 'field_enrd_coop_objectives-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_objectives-revision_id']['table'] = 'field_revision_field_enrd_coop_objectives';
  $handler->display->display_options['fields']['field_enrd_coop_objectives-revision_id']['field'] = 'field_enrd_coop_objectives-revision_id';
  /* Field: Content (historical data): Project idea summary */
  $handler->display->display_options['fields']['field_enrd_coop_brief_summary-revision_id']['id'] = 'field_enrd_coop_brief_summary-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_brief_summary-revision_id']['table'] = 'field_revision_field_enrd_coop_brief_summary';
  $handler->display->display_options['fields']['field_enrd_coop_brief_summary-revision_id']['field'] = 'field_enrd_coop_brief_summary-revision_id';
  /* Field: Content (historical data): Region */
  $handler->display->display_options['fields']['field_enrd_coop_partner_region-revision_id']['id'] = 'field_enrd_coop_partner_region-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_partner_region-revision_id']['table'] = 'field_revision_field_enrd_coop_partner_region';
  $handler->display->display_options['fields']['field_enrd_coop_partner_region-revision_id']['field'] = 'field_enrd_coop_partner_region-revision_id';
  /* Field: Content (historical data): Type of partner */
  $handler->display->display_options['fields']['field_enrd_coop_type_of_partner-revision_id']['id'] = 'field_enrd_coop_type_of_partner-revision_id';
  $handler->display->display_options['fields']['field_enrd_coop_type_of_partner-revision_id']['table'] = 'field_revision_field_enrd_coop_type_of_partner';
  $handler->display->display_options['fields']['field_enrd_coop_type_of_partner-revision_id']['field'] = 'field_enrd_coop_type_of_partner-revision_id';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content revision: Updated date */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Sort criterion: Field: Country (field_enrd_lag_country) */
  $handler->display->display_options['sorts']['field_enrd_lag_country_tid']['id'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['sorts']['field_enrd_lag_country_tid']['table'] = 'field_data_field_enrd_lag_country';
  $handler->display->display_options['sorts']['field_enrd_lag_country_tid']['field'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['sorts']['field_enrd_lag_country_tid']['relationship'] = 'nid';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['group'] = 1;
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'State';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['state']['group_info']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['group_info']['optional'] = FALSE;
  $handler->display->display_options['filters']['state']['group_info']['default_group'] = '1';
  $handler->display->display_options['filters']['state']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Currently online',
      'operator' => 'in',
      'value' => array(
        'published' => 'published',
        'all' => 0,
        'draft' => 0,
        'ready_to_be_published' => 0,
        'needs_review' => 0,
        'validated' => 0,
        'archived' => 0,
      ),
    ),
    2 => array(
      'title' => 'Archived',
      'operator' => 'in',
      'value' => array(
        'archived' => 'archived',
        'all' => 0,
        'draft' => 0,
        'ready_to_be_published' => 0,
        'needs_review' => 0,
        'validated' => 0,
        'published' => 0,
      ),
    ),
    3 => array(
      'title' => 'Updates',
      'operator' => 'in',
      'value' => array(
        'draft' => 'draft',
        'all' => 0,
        'ready_to_be_published' => 0,
        'needs_review' => 0,
        'validated' => 0,
        'published' => 0,
        'archived' => 0,
      ),
    ),
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search in the CLLD Partner Search Tool';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title_field-revision_id' => 'title_field-revision_id',
    'field_enrd_coop_context-revision_id' => 'field_enrd_coop_context-revision_id',
    'field_enrd_coop_objectives-revision_id' => 'field_enrd_coop_objectives-revision_id',
    'field_enrd_coop_brief_summary-revision_id' => 'field_enrd_coop_brief_summary-revision_id',
    'field_enrd_coop_partner_region-revision_id' => 'field_enrd_coop_partner_region-revision_id',
    'field_enrd_coop_type_of_partner-revision_id' => 'field_enrd_coop_type_of_partner-revision_id',
  );
  /* Filter criterion: Content (historical data): Expiry date (field_enrd_coop_expiry_date) */
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['id'] = 'field_enrd_coop_expiry_date_value';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['table'] = 'field_revision_field_enrd_coop_expiry_date';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['field'] = 'field_enrd_coop_expiry_date_value';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_coop_expiry_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cooperation_offer' => 'cooperation_offer',
  );
  $handler->display->display_options['filters']['type']['group'] = 2;
  /* Filter criterion: Workbench Moderation: Current */
  $handler->display->display_options['filters']['is_current']['id'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['value'] = '1';
  $handler->display->display_options['filters']['is_current']['group'] = 2;
  /* Filter criterion: Content: Has taxonomy terms (with depth; Simple hierarchical select) */
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['id'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['field'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['relationship'] = 'nid';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['group'] = 2;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator_id'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['label'] = 'Type of project';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['identifier'] = 'filter_project_type';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['vocabulary'] = 'enrd_project_types';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['depth'] = '3';
  /* Filter criterion: Content: Has taxonomy terms (with depth; Simple hierarchical select) */
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['id'] = 'shs_term_node_tid_depth_1';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['table'] = 'node';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['field'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['relationship'] = 'nid';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['group'] = 2;
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['expose']['operator_id'] = 'shs_term_node_tid_depth_1_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['expose']['label'] = 'Topic of the project';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['expose']['operator'] = 'shs_term_node_tid_depth_1_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['expose']['identifier'] = 'filter_project_topic';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['vocabulary'] = 'enrd_key_themes_of_strategy';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_1']['depth'] = '3';
  /* Filter criterion: Field: Country (field_enrd_lag_country) */
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['id'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['table'] = 'field_data_field_enrd_lag_country';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['field'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['operator_id'] = 'field_enrd_lag_country_tid_op';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['operator'] = 'field_enrd_lag_country_tid_op';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['identifier'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['vocabulary'] = 'enrd_countries';
  /* Filter criterion: Content: Main ESI Fund (field_enrd_main_esi_fund) */
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['id'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['table'] = 'field_data_field_enrd_main_esi_fund';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['field'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['operator_id'] = 'field_enrd_main_esi_fund_tid_op';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['label'] = 'ESI Fund';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['operator'] = 'field_enrd_main_esi_fund_tid_op';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['identifier'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['vocabulary'] = 'enrd_esi_funds';
  /* Filter criterion: Content: Has taxonomy terms (with depth; Simple hierarchical select) */
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['id'] = 'shs_term_node_tid_depth_2';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['table'] = 'node';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['field'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['group'] = 2;
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['expose']['operator_id'] = 'shs_term_node_tid_depth_2_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['expose']['label'] = 'ESIF Programme';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['expose']['operator'] = 'shs_term_node_tid_depth_2_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['expose']['identifier'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['vocabulary'] = 'enrd_esif_programme';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['use_chosen'] = 'always';
  $handler->display->display_options['filters']['shs_term_node_tid_depth_2']['depth'] = '2';
  $handler->display->display_options['path'] = 'lag-dashboard/cooperation-offers-expired.csv';
  $handler->display->display_options['displays'] = array(
    'coop_offers_page_expired' => 'coop_offers_page_expired',
    'default' => 0,
    'coop_offers_page_active' => 0,
    'coop_offers_contextual' => 0,
    'pending_page' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'lag-dashboard/cooperation-offers/expired';
  $handler->display->display_options['segment_size'] = '50';
  $export['enrd_lag_database_cooperation_offers_dashboard'] = $view;

  $view = new view();
  $view->name = 'enrd_lag_database_custom_dashboard';
  $view->description = 'Custom LAG dashboard to allow the management of pending LAG profiles.';
  $view->tag = 'ENRD LAG Dashboard';
  $view->base_table = 'node_revision';
  $view->human_name = 'ENRD LAG profiles Custom Dashboard';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'LAG profiles';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'esi_fund_context';
  $handler->display->display_options['access']['perm'] = 'access lag dashboards';
  $handler->display->display_options['access']['esi_fund_perm'] = 'access lag dashboards';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'full_html',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'state' => array(
      'bef_format' => 'bef_links',
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
    'combine' => array(
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
    'field_enrd_lag_country_tid' => array(
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
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_enrd_main_esi_fund_tid' => array(
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
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'term_node_tid_depth' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
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
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_enrd_lag_code' => 'field_enrd_lag_code',
    'field_enrd_lag_country' => 'field_enrd_lag_country',
    'field_enrd_main_esi_fund' => 'field_enrd_main_esi_fund',
    'field_enrd_esif_programme' => 'field_enrd_esif_programme',
    'field_enrd_additional_esi_funds' => 'field_enrd_additional_esi_funds',
    'state' => 'state',
    'field_enrd_lag_email' => 'field_enrd_lag_email',
    'stamp' => 'stamp',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'stamp';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_code' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_country' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_main_esi_fund' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_esif_programme' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_additional_esi_funds' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'stamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No LAGs have been created yet with the selected criteria.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['label'] = 'Get the actual content from a content revision (NID)';
  /* Field: Content revision: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['label'] = 'LAG name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node_revision'] = TRUE;
  /* Field: Content: LAG code */
  $handler->display->display_options['fields']['field_enrd_lag_code']['id'] = 'field_enrd_lag_code';
  $handler->display->display_options['fields']['field_enrd_lag_code']['table'] = 'field_data_field_enrd_lag_code';
  $handler->display->display_options['fields']['field_enrd_lag_code']['field'] = 'field_enrd_lag_code';
  $handler->display->display_options['fields']['field_enrd_lag_code']['relationship'] = 'nid';
  /* Field: Field: Country */
  $handler->display->display_options['fields']['field_enrd_lag_country']['id'] = 'field_enrd_lag_country';
  $handler->display->display_options['fields']['field_enrd_lag_country']['table'] = 'field_data_field_enrd_lag_country';
  $handler->display->display_options['fields']['field_enrd_lag_country']['field'] = 'field_enrd_lag_country';
  $handler->display->display_options['fields']['field_enrd_lag_country']['relationship'] = 'nid';
  /* Field: Content: Main ESI Fund */
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['id'] = 'field_enrd_main_esi_fund';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['table'] = 'field_data_field_enrd_main_esi_fund';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['field'] = 'field_enrd_main_esi_fund';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['label'] = 'ESI Fund';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Sort criterion: Content revision: Updated date */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Sort criterion: Field: Country (field_enrd_lag_country) */
  $handler->display->display_options['sorts']['field_enrd_lag_country_tid']['id'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['sorts']['field_enrd_lag_country_tid']['table'] = 'field_data_field_enrd_lag_country';
  $handler->display->display_options['sorts']['field_enrd_lag_country_tid']['field'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['sorts']['field_enrd_lag_country_tid']['relationship'] = 'nid';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'lag' => 'lag',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search in the LAG Database';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_enrd_lag_code' => 'field_enrd_lag_code',
    'field_enrd_lag_email' => 'field_enrd_lag_email',
  );
  /* Filter criterion: Field: Country (field_enrd_lag_country) */
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['id'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['table'] = 'field_data_field_enrd_lag_country';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['field'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['relationship'] = 'vid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['operator_id'] = 'field_enrd_lag_country_tid_op';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['operator'] = 'field_enrd_lag_country_tid_op';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['identifier'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['vocabulary'] = 'enrd_countries';
  /* Filter criterion: Content: Main ESI Fund (field_enrd_main_esi_fund) */
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['id'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['table'] = 'field_data_field_enrd_main_esi_fund';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['field'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['relationship'] = 'vid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['operator_id'] = 'field_enrd_main_esi_fund_tid_op';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['label'] = 'ESI Fund';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['operator'] = 'field_enrd_main_esi_fund_tid_op';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['identifier'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['vocabulary'] = 'enrd_esi_funds';
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['relationship'] = 'vid';
  $handler->display->display_options['filters']['term_node_tid_depth']['value'] = '';
  $handler->display->display_options['filters']['term_node_tid_depth']['group'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'ESIF Programme';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'enrd_esif_programme';
  $handler->display->display_options['filters']['term_node_tid_depth']['hierarchy'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '2';

  /* Display: Page:  LAG profiles */
  $handler = $view->new_display('page', 'Page:  LAG profiles', 'lag_profiles_page');
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'full_html',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'combine' => array(
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
    'field_enrd_lag_country_tid' => array(
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
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_enrd_main_esi_fund_tid' => array(
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
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'shs_term_node_tid_depth' => array(
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
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'state' => array(
      'bef_format' => 'bef_links',
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
  );
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'nid' => 'nid',
    'vid' => 'vid',
    'title_field-revision_id' => 'title_field-revision_id',
    'field_enrd_lag_code-revision_id' => 'field_enrd_lag_code-revision_id',
    'field_enrd_lag_country-revision_id' => 'field_enrd_lag_country-revision_id',
    'field_enrd_main_esi_fund-revision_id' => 'field_enrd_main_esi_fund-revision_id',
    'field_enrd_esif_programme' => 'field_enrd_esif_programme',
    'field_enrd_additional_esi_funds-revision_id' => 'field_enrd_additional_esi_funds-revision_id',
    'field_enrd_lag_email-revision_id' => 'field_enrd_lag_email-revision_id',
    'state' => 'state',
    'stamp' => 'stamp',
    'view_node' => 'view_node',
    'published' => 'published',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'stamp';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'vid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_field-revision_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_code-revision_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_country-revision_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_main_esi_fund-revision_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_esif_programme' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_additional_esi_funds-revision_id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_email-revision_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'stamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'published' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['label'] = 'Get the actual content from a content revision (NID)';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content revision */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node_revision';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::rules_enrd_moderate_content_to_archived' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Archived',
    ),
    'rules_component::rules_enrd_moderate_content_to_draft' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Draft',
    ),
    'rules_component::rules_enrd_moderate_content_to_expired' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Expired',
    ),
    'rules_component::rules_enrd_moderate_content_to_published' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Published',
    ),
    'rules_component::rules_enrd_moderate_content_to_ready_to_be_published' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Ready to be published',
    ),
    'action::enrd_lag_invite_action_invite_lag_manager' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content revision: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content revision: Vid */
  $handler->display->display_options['fields']['vid']['id'] = 'vid';
  $handler->display->display_options['fields']['vid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['vid']['field'] = 'vid';
  $handler->display->display_options['fields']['vid']['label'] = '';
  $handler->display->display_options['fields']['vid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['vid']['element_label_colon'] = FALSE;
  /* Field: Content (historical data): Title */
  $handler->display->display_options['fields']['title_field-revision_id']['id'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['table'] = 'field_revision_title_field';
  $handler->display->display_options['fields']['title_field-revision_id']['field'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['label'] = 'LAG name';
  $handler->display->display_options['fields']['title_field-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_field-revision_id']['alter']['text'] = '[title_field-revision_id]';
  $handler->display->display_options['fields']['title_field-revision_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_field-revision_id']['alter']['path'] = 'node/[nid]/current-revision';
  /* Field: Content (historical data): LAG code */
  $handler->display->display_options['fields']['field_enrd_lag_code-revision_id']['id'] = 'field_enrd_lag_code-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_code-revision_id']['table'] = 'field_revision_field_enrd_lag_code';
  $handler->display->display_options['fields']['field_enrd_lag_code-revision_id']['field'] = 'field_enrd_lag_code-revision_id';
  /* Field: Field (historical data): Country */
  $handler->display->display_options['fields']['field_enrd_lag_country-revision_id']['id'] = 'field_enrd_lag_country-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_country-revision_id']['table'] = 'field_revision_field_enrd_lag_country';
  $handler->display->display_options['fields']['field_enrd_lag_country-revision_id']['field'] = 'field_enrd_lag_country-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_country-revision_id']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content (historical data): Main ESI Fund */
  $handler->display->display_options['fields']['field_enrd_main_esi_fund-revision_id']['id'] = 'field_enrd_main_esi_fund-revision_id';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund-revision_id']['table'] = 'field_revision_field_enrd_main_esi_fund';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund-revision_id']['field'] = 'field_enrd_main_esi_fund-revision_id';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund-revision_id']['label'] = 'ESI Fund';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund-revision_id']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content (historical data): ESIF Programme */
  $handler->display->display_options['fields']['field_enrd_esif_programme-revision_id']['id'] = 'field_enrd_esif_programme-revision_id';
  $handler->display->display_options['fields']['field_enrd_esif_programme-revision_id']['table'] = 'field_revision_field_enrd_esif_programme';
  $handler->display->display_options['fields']['field_enrd_esif_programme-revision_id']['field'] = 'field_enrd_esif_programme-revision_id';
  $handler->display->display_options['fields']['field_enrd_esif_programme-revision_id']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content (historical data): Additional ESI Funds */
  $handler->display->display_options['fields']['field_enrd_additional_esi_funds-revision_id']['id'] = 'field_enrd_additional_esi_funds-revision_id';
  $handler->display->display_options['fields']['field_enrd_additional_esi_funds-revision_id']['table'] = 'field_revision_field_enrd_additional_esi_funds';
  $handler->display->display_options['fields']['field_enrd_additional_esi_funds-revision_id']['field'] = 'field_enrd_additional_esi_funds-revision_id';
  $handler->display->display_options['fields']['field_enrd_additional_esi_funds-revision_id']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_enrd_additional_esi_funds-revision_id']['delta_offset'] = '0';
  /* Field: Content (historical data): LAG email */
  $handler->display->display_options['fields']['field_enrd_lag_email-revision_id']['id'] = 'field_enrd_lag_email-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_email-revision_id']['table'] = 'field_revision_field_enrd_lag_email';
  $handler->display->display_options['fields']['field_enrd_lag_email-revision_id']['field'] = 'field_enrd_lag_email-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_email-revision_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_lag_email-revision_id']['type'] = 'email_plain';
  /* Field: Workbench Moderation: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Workflow state';
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  /* Field: Workbench Moderation: Timestamp */
  $handler->display->display_options['fields']['stamp']['id'] = 'stamp';
  $handler->display->display_options['fields']['stamp']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['stamp']['field'] = 'stamp';
  $handler->display->display_options['fields']['stamp']['label'] = 'Revised on';
  $handler->display->display_options['fields']['stamp']['date_format'] = 'short';
  $handler->display->display_options['fields']['stamp']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'View online version';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    'ready_to_be_published' => 'ready_to_be_published',
  );
  $handler->display->display_options['filters']['state']['group'] = 1;
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'State';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['state']['group_info']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['group_info']['optional'] = FALSE;
  $handler->display->display_options['filters']['state']['group_info']['default_group'] = '2';
  $handler->display->display_options['filters']['state']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Updates',
      'operator' => 'in',
      'value' => array(
        'draft' => 'draft',
        'all' => 0,
        'ready_to_be_published' => 0,
        'needs_review' => 0,
        'validated' => 0,
        'published' => 0,
        'archived' => 0,
      ),
    ),
    2 => array(
      'title' => 'Published',
      'operator' => 'in',
      'value' => array(
        'published' => 'published',
        'all' => 0,
        'draft' => 0,
        'ready_to_be_published' => 0,
        'needs_review' => 0,
        'validated' => 0,
        'archived' => 0,
      ),
    ),
    3 => array(
      'title' => 'Archived',
      'operator' => 'in',
      'value' => array(
        'archived' => 'archived',
        'all' => 0,
        'draft' => 0,
        'ready_to_be_published' => 0,
        'needs_review' => 0,
        'validated' => 0,
        'published' => 0,
      ),
    ),
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search in the LAG Database';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title_field-revision_id' => 'title_field-revision_id',
    'field_enrd_lag_code-revision_id' => 'field_enrd_lag_code-revision_id',
    'field_enrd_lag_email-revision_id' => 'field_enrd_lag_email-revision_id',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'lag' => 'lag',
  );
  $handler->display->display_options['filters']['type']['group'] = 2;
  /* Filter criterion: Field (historical data): Country (field_enrd_lag_country) */
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['id'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['table'] = 'field_revision_field_enrd_lag_country';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['field'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['operator_id'] = 'field_enrd_lag_country_tid_op';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['operator'] = 'field_enrd_lag_country_tid_op';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['identifier'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['vocabulary'] = 'enrd_countries';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['use_chosen'] = 'always';
  /* Filter criterion: Content (historical data): Main ESI Fund (field_enrd_main_esi_fund) */
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['id'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['table'] = 'field_revision_field_enrd_main_esi_fund';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['field'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['operator_id'] = 'field_enrd_main_esi_fund_tid_op';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['label'] = 'ESI Fund';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['operator'] = 'field_enrd_main_esi_fund_tid_op';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['identifier'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['vocabulary'] = 'enrd_esi_funds';
  /* Filter criterion: Content: Has taxonomy terms (with depth; Simple hierarchical select) */
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['id'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['field'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['relationship'] = 'nid';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['group'] = 2;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator_id'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['label'] = 'ESIF Programme';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['identifier'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['vocabulary'] = 'enrd_esif_programme';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['use_chosen'] = 'always';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['depth'] = '2';
  /* Filter criterion: Workbench Moderation: Current */
  $handler->display->display_options['filters']['is_current']['id'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['value'] = '1';
  $handler->display->display_options['filters']['is_current']['group'] = 2;
  $handler->display->display_options['path'] = 'lag-dashboard/lag-profiles/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 1;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'LAG profiles';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Page:  LAG pending */
  $handler = $view->new_display('page', 'Page:  LAG pending', 'pending_lags');
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'full_html',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'combine' => array(
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
    'field_enrd_lag_country_tid' => array(
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
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_enrd_main_esi_fund_tid' => array(
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
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'shs_term_node_tid_depth' => array(
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
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'state' => array(
      'bef_format' => 'bef_hidden',
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
  );
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'nid' => 'nid',
    'title_field-revision_id' => 'title_field-revision_id',
    'field_enrd_lag_code-revision_id' => 'field_enrd_lag_code-revision_id',
    'field_enrd_lag_country-revision_id' => 'field_enrd_lag_country-revision_id',
    'field_enrd_main_esi_fund-revision_id' => 'field_enrd_main_esi_fund-revision_id',
    'field_enrd_esif_programme-revision_id' => 'field_enrd_esif_programme-revision_id',
    'field_enrd_additional_esi_funds-revision_id' => 'field_enrd_additional_esi_funds-revision_id',
    'field_enrd_lag_email-revision_id' => 'field_enrd_lag_email-revision_id',
    'state' => 'state',
    'stamp' => 'stamp',
  );
  $handler->display->display_options['style_options']['default'] = 'stamp';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_field-revision_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_code-revision_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_country-revision_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_main_esi_fund-revision_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_esif_programme-revision_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_additional_esi_funds-revision_id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_email-revision_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'stamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['label'] = 'Get the actual content from a content revision (NID)';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content revision */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node_revision';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::rules_enrd_moderate_content_to_archived' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Archived',
    ),
    'rules_component::rules_enrd_moderate_content_to_draft' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Draft',
    ),
    'rules_component::rules_enrd_moderate_content_to_expired' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Expired',
    ),
    'rules_component::rules_enrd_moderate_content_to_published' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Published',
    ),
    'rules_component::rules_enrd_moderate_content_to_ready_to_be_published' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Ready to be published',
    ),
  );
  /* Field: Content revision: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content revision: Vid */
  $handler->display->display_options['fields']['vid']['id'] = 'vid';
  $handler->display->display_options['fields']['vid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['vid']['field'] = 'vid';
  $handler->display->display_options['fields']['vid']['label'] = '';
  $handler->display->display_options['fields']['vid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['vid']['element_label_colon'] = FALSE;
  /* Field: Content (historical data): Title */
  $handler->display->display_options['fields']['title_field-revision_id']['id'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['table'] = 'field_revision_title_field';
  $handler->display->display_options['fields']['title_field-revision_id']['field'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['label'] = 'LAG name';
  $handler->display->display_options['fields']['title_field-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_field-revision_id']['alter']['text'] = '[title_field-revision_id]';
  $handler->display->display_options['fields']['title_field-revision_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_field-revision_id']['alter']['path'] = 'node/[nid]/current-revision';
  /* Field: Content (historical data): LAG code */
  $handler->display->display_options['fields']['field_enrd_lag_code-revision_id']['id'] = 'field_enrd_lag_code-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_code-revision_id']['table'] = 'field_revision_field_enrd_lag_code';
  $handler->display->display_options['fields']['field_enrd_lag_code-revision_id']['field'] = 'field_enrd_lag_code-revision_id';
  /* Field: Field (historical data): Country */
  $handler->display->display_options['fields']['field_enrd_lag_country-revision_id']['id'] = 'field_enrd_lag_country-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_country-revision_id']['table'] = 'field_revision_field_enrd_lag_country';
  $handler->display->display_options['fields']['field_enrd_lag_country-revision_id']['field'] = 'field_enrd_lag_country-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_country-revision_id']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content (historical data): Main ESI Fund */
  $handler->display->display_options['fields']['field_enrd_main_esi_fund-revision_id']['id'] = 'field_enrd_main_esi_fund-revision_id';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund-revision_id']['table'] = 'field_revision_field_enrd_main_esi_fund';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund-revision_id']['field'] = 'field_enrd_main_esi_fund-revision_id';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund-revision_id']['label'] = 'ESI Fund';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund-revision_id']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content (historical data): ESIF Programme */
  $handler->display->display_options['fields']['field_enrd_esif_programme-revision_id']['id'] = 'field_enrd_esif_programme-revision_id';
  $handler->display->display_options['fields']['field_enrd_esif_programme-revision_id']['table'] = 'field_revision_field_enrd_esif_programme';
  $handler->display->display_options['fields']['field_enrd_esif_programme-revision_id']['field'] = 'field_enrd_esif_programme-revision_id';
  $handler->display->display_options['fields']['field_enrd_esif_programme-revision_id']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content (historical data): Additional ESI Funds */
  $handler->display->display_options['fields']['field_enrd_additional_esi_funds-revision_id']['id'] = 'field_enrd_additional_esi_funds-revision_id';
  $handler->display->display_options['fields']['field_enrd_additional_esi_funds-revision_id']['table'] = 'field_revision_field_enrd_additional_esi_funds';
  $handler->display->display_options['fields']['field_enrd_additional_esi_funds-revision_id']['field'] = 'field_enrd_additional_esi_funds-revision_id';
  $handler->display->display_options['fields']['field_enrd_additional_esi_funds-revision_id']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_enrd_additional_esi_funds-revision_id']['delta_offset'] = '0';
  /* Field: Content (historical data): LAG email */
  $handler->display->display_options['fields']['field_enrd_lag_email-revision_id']['id'] = 'field_enrd_lag_email-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_email-revision_id']['table'] = 'field_revision_field_enrd_lag_email';
  $handler->display->display_options['fields']['field_enrd_lag_email-revision_id']['field'] = 'field_enrd_lag_email-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_email-revision_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_lag_email-revision_id']['type'] = 'email_plain';
  /* Field: Workbench Moderation: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Workflow state';
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  /* Field: Workbench Moderation: Timestamp */
  $handler->display->display_options['fields']['stamp']['id'] = 'stamp';
  $handler->display->display_options['fields']['stamp']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['stamp']['field'] = 'stamp';
  $handler->display->display_options['fields']['stamp']['label'] = 'Requested on';
  $handler->display->display_options['fields']['stamp']['date_format'] = 'short';
  $handler->display->display_options['fields']['stamp']['second_date_format'] = 'enrd_lag_database_d_m_y';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    'ready_to_be_published' => 'ready_to_be_published',
  );
  $handler->display->display_options['filters']['state']['group'] = 1;
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'State';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['state']['group_info']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['group_info']['optional'] = FALSE;
  $handler->display->display_options['filters']['state']['group_info']['default_group'] = '1';
  $handler->display->display_options['filters']['state']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Ready to be published',
      'operator' => 'in',
      'value' => array(
        'ready_to_be_published' => 'ready_to_be_published',
        'all' => 0,
        'draft' => 0,
        'needs_review' => 0,
        'validated' => 0,
        'published' => 0,
        'archived' => 0,
      ),
    ),
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search in the LAG Database';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_enrd_lag_code-revision_id' => 'field_enrd_lag_code-revision_id',
    'field_enrd_lag_email-revision_id' => 'field_enrd_lag_email-revision_id',
    'title_field-revision_id' => 'title_field-revision_id',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'lag' => 'lag',
  );
  $handler->display->display_options['filters']['type']['group'] = 2;
  /* Filter criterion: Field (historical data): Country (field_enrd_lag_country) */
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['id'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['table'] = 'field_revision_field_enrd_lag_country';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['field'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['operator_id'] = 'field_enrd_lag_country_tid_op';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['operator'] = 'field_enrd_lag_country_tid_op';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['identifier'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['vocabulary'] = 'enrd_countries';
  /* Filter criterion: Content (historical data): Main ESI Fund (field_enrd_main_esi_fund) */
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['id'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['table'] = 'field_revision_field_enrd_main_esi_fund';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['field'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['operator_id'] = 'field_enrd_main_esi_fund_tid_op';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['label'] = 'ESI Fund';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['operator'] = 'field_enrd_main_esi_fund_tid_op';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['identifier'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['vocabulary'] = 'enrd_esi_funds';
  /* Filter criterion: Content: Has taxonomy terms (with depth; Simple hierarchical select) */
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['id'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['field'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['relationship'] = 'nid';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['group'] = 2;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator_id'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['label'] = 'ESIF Programme';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['identifier'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['vocabulary'] = 'enrd_esif_programme';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['use_chosen'] = 'always';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['depth'] = '2';
  /* Filter criterion: Workbench Moderation: Current */
  $handler->display->display_options['filters']['is_current']['id'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['value'] = '1';
  $handler->display->display_options['filters']['is_current']['group'] = 2;
  /* Filter criterion: Workbench Moderation: Published */
  $handler->display->display_options['filters']['published']['id'] = 'published';
  $handler->display->display_options['filters']['published']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['published']['field'] = 'published';
  $handler->display->display_options['filters']['published']['value'] = '0';
  $handler->display->display_options['filters']['published']['group'] = 2;
  $handler->display->display_options['path'] = 'lag-dashboard/lag-profiles/pending-requests';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Pending for publication';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 1;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export: LAG Profiles - Admins */
  $handler = $view->new_display('views_data_export', 'Data export: LAG Profiles - Admins', 'views_data_export_lag_profiles');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['attach_text'] = 'Export';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'lag-profiles.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['quote'] = '1';
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['label'] = 'Get the actual content from a content revision (NID)';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content (historical data): Title */
  $handler->display->display_options['fields']['title_field-revision_id']['id'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['table'] = 'field_revision_title_field';
  $handler->display->display_options['fields']['title_field-revision_id']['field'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['label'] = 'LAG name';
  /* Field: Content (historical data): LAG code */
  $handler->display->display_options['fields']['field_enrd_lag_code-revision_id']['id'] = 'field_enrd_lag_code-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_code-revision_id']['table'] = 'field_revision_field_enrd_lag_code';
  $handler->display->display_options['fields']['field_enrd_lag_code-revision_id']['field'] = 'field_enrd_lag_code-revision_id';
  /* Field: Field (historical data): Country */
  $handler->display->display_options['fields']['field_enrd_lag_country-revision_id']['id'] = 'field_enrd_lag_country-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_country-revision_id']['table'] = 'field_revision_field_enrd_lag_country';
  $handler->display->display_options['fields']['field_enrd_lag_country-revision_id']['field'] = 'field_enrd_lag_country-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_country-revision_id']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content (historical data): Main ESI Fund */
  $handler->display->display_options['fields']['field_enrd_main_esi_fund-revision_id']['id'] = 'field_enrd_main_esi_fund-revision_id';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund-revision_id']['table'] = 'field_revision_field_enrd_main_esi_fund';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund-revision_id']['field'] = 'field_enrd_main_esi_fund-revision_id';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund-revision_id']['label'] = 'ESI Fund';
  $handler->display->display_options['fields']['field_enrd_main_esi_fund-revision_id']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content (historical data): ESIF Programme */
  $handler->display->display_options['fields']['field_enrd_esif_programme-revision_id']['id'] = 'field_enrd_esif_programme-revision_id';
  $handler->display->display_options['fields']['field_enrd_esif_programme-revision_id']['table'] = 'field_revision_field_enrd_esif_programme';
  $handler->display->display_options['fields']['field_enrd_esif_programme-revision_id']['field'] = 'field_enrd_esif_programme-revision_id';
  $handler->display->display_options['fields']['field_enrd_esif_programme-revision_id']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content (historical data): Address */
  $handler->display->display_options['fields']['field_enrd_lag_manager_address-revision_id']['id'] = 'field_enrd_lag_manager_address-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_manager_address-revision_id']['table'] = 'field_revision_field_enrd_lag_manager_address';
  $handler->display->display_options['fields']['field_enrd_lag_manager_address-revision_id']['field'] = 'field_enrd_lag_manager_address-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_manager_address-revision_id']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_enrd_lag_manager_address-revision_id']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content (historical data): Coordinates */
  $handler->display->display_options['fields']['field_enrd_lag_coordinates-revision_id']['id'] = 'field_enrd_lag_coordinates-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_coordinates-revision_id']['table'] = 'field_revision_field_enrd_lag_coordinates';
  $handler->display->display_options['fields']['field_enrd_lag_coordinates-revision_id']['field'] = 'field_enrd_lag_coordinates-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_coordinates-revision_id']['label'] = 'Coordinates (Latitude)';
  $handler->display->display_options['fields']['field_enrd_lag_coordinates-revision_id']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_enrd_lag_coordinates-revision_id']['type'] = 'geofield_lat';
  $handler->display->display_options['fields']['field_enrd_lag_coordinates-revision_id']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
  );
  /* Field: Content (historical data): Coordinates */
  $handler->display->display_options['fields']['field_enrd_lag_coordinates-revision_id_1']['id'] = 'field_enrd_lag_coordinates-revision_id_1';
  $handler->display->display_options['fields']['field_enrd_lag_coordinates-revision_id_1']['table'] = 'field_revision_field_enrd_lag_coordinates';
  $handler->display->display_options['fields']['field_enrd_lag_coordinates-revision_id_1']['field'] = 'field_enrd_lag_coordinates-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_coordinates-revision_id_1']['label'] = 'Coordinates (Longitude)';
  $handler->display->display_options['fields']['field_enrd_lag_coordinates-revision_id_1']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_enrd_lag_coordinates-revision_id_1']['type'] = 'geofield_lon';
  $handler->display->display_options['fields']['field_enrd_lag_coordinates-revision_id_1']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
  );
  /* Field: Content (historical data): LAG email */
  $handler->display->display_options['fields']['field_enrd_lag_email-revision_id']['id'] = 'field_enrd_lag_email-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_email-revision_id']['table'] = 'field_revision_field_enrd_lag_email';
  $handler->display->display_options['fields']['field_enrd_lag_email-revision_id']['field'] = 'field_enrd_lag_email-revision_id';
  /* Field: Content (historical data): LAG manager (Name and Surname) */
  $handler->display->display_options['fields']['field_enrd_lag_manager_name-revision_id']['id'] = 'field_enrd_lag_manager_name-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_manager_name-revision_id']['table'] = 'field_revision_field_enrd_lag_manager_name';
  $handler->display->display_options['fields']['field_enrd_lag_manager_name-revision_id']['field'] = 'field_enrd_lag_manager_name-revision_id';
  /* Field: Content (historical data): LAG manager email */
  $handler->display->display_options['fields']['field_enrd_lag_manager_email-revision_id']['id'] = 'field_enrd_lag_manager_email-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_manager_email-revision_id']['table'] = 'field_revision_field_enrd_lag_manager_email';
  $handler->display->display_options['fields']['field_enrd_lag_manager_email-revision_id']['field'] = 'field_enrd_lag_manager_email-revision_id';
  /* Field: Content (historical data): Phone */
  $handler->display->display_options['fields']['field_enrd_lag_phone-revision_id']['id'] = 'field_enrd_lag_phone-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_phone-revision_id']['table'] = 'field_revision_field_enrd_lag_phone';
  $handler->display->display_options['fields']['field_enrd_lag_phone-revision_id']['field'] = 'field_enrd_lag_phone-revision_id';
  /* Field: Content (historical data): LAG website */
  $handler->display->display_options['fields']['field_enrd_lag_website-revision_id']['id'] = 'field_enrd_lag_website-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_website-revision_id']['table'] = 'field_revision_field_enrd_lag_website';
  $handler->display->display_options['fields']['field_enrd_lag_website-revision_id']['field'] = 'field_enrd_lag_website-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_website-revision_id']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_enrd_lag_website-revision_id']['type'] = 'link_url';
  /* Field: Content (historical data): LinkedIn */
  $handler->display->display_options['fields']['field_enrd_lag_linkedin-revision_id']['id'] = 'field_enrd_lag_linkedin-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_linkedin-revision_id']['table'] = 'field_revision_field_enrd_lag_linkedin';
  $handler->display->display_options['fields']['field_enrd_lag_linkedin-revision_id']['field'] = 'field_enrd_lag_linkedin-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_linkedin-revision_id']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_enrd_lag_linkedin-revision_id']['type'] = 'link_url';
  /* Field: Content (historical data): Facebook */
  $handler->display->display_options['fields']['field_enrd_lag_facebook-revision_id']['id'] = 'field_enrd_lag_facebook-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_facebook-revision_id']['table'] = 'field_revision_field_enrd_lag_facebook';
  $handler->display->display_options['fields']['field_enrd_lag_facebook-revision_id']['field'] = 'field_enrd_lag_facebook-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_facebook-revision_id']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_enrd_lag_facebook-revision_id']['type'] = 'link_url';
  /* Field: Content (historical data): Twitter */
  $handler->display->display_options['fields']['field_enrd_lag_twitter-revision_id']['id'] = 'field_enrd_lag_twitter-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_twitter-revision_id']['table'] = 'field_revision_field_enrd_lag_twitter';
  $handler->display->display_options['fields']['field_enrd_lag_twitter-revision_id']['field'] = 'field_enrd_lag_twitter-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_twitter-revision_id']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_enrd_lag_twitter-revision_id']['type'] = 'link_url';
  /* Field: Content (historical data): Extended profile */
  $handler->display->display_options['fields']['field_enrd_lag_extended_profile-revision_id']['id'] = 'field_enrd_lag_extended_profile-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_extended_profile-revision_id']['table'] = 'field_revision_field_enrd_lag_extended_profile';
  $handler->display->display_options['fields']['field_enrd_lag_extended_profile-revision_id']['field'] = 'field_enrd_lag_extended_profile-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_extended_profile-revision_id']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_enrd_lag_extended_profile-revision_id']['type'] = 'link_plain';
  /* Field: Content (historical data): Spoken languages */
  $handler->display->display_options['fields']['field_enrd_lag_spoken_languages-revision_id']['id'] = 'field_enrd_lag_spoken_languages-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_spoken_languages-revision_id']['table'] = 'field_revision_field_enrd_lag_spoken_languages';
  $handler->display->display_options['fields']['field_enrd_lag_spoken_languages-revision_id']['field'] = 'field_enrd_lag_spoken_languages-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_spoken_languages-revision_id']['type'] = 'ds_taxonomy_separator_localized';
  $handler->display->display_options['fields']['field_enrd_lag_spoken_languages-revision_id']['delta_offset'] = '0';
  /* Field: Content (historical data): Key themes of LAG strategy */
  $handler->display->display_options['fields']['field_enrd_lag_key_themes-revision_id']['id'] = 'field_enrd_lag_key_themes-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_key_themes-revision_id']['table'] = 'field_revision_field_enrd_lag_key_themes';
  $handler->display->display_options['fields']['field_enrd_lag_key_themes-revision_id']['field'] = 'field_enrd_lag_key_themes-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_key_themes-revision_id']['type'] = 'ds_taxonomy_separator_localized';
  $handler->display->display_options['fields']['field_enrd_lag_key_themes-revision_id']['delta_offset'] = '0';
  /* Field: Content (historical data): Additional information on the strategy */
  $handler->display->display_options['fields']['field_enrd_lag_strategy_info-revision_id']['id'] = 'field_enrd_lag_strategy_info-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_strategy_info-revision_id']['table'] = 'field_revision_field_enrd_lag_strategy_info';
  $handler->display->display_options['fields']['field_enrd_lag_strategy_info-revision_id']['field'] = 'field_enrd_lag_strategy_info-revision_id';
  /* Field: Content (historical data): Physical & demographic characteristics of LAG area */
  $handler->display->display_options['fields']['field_enrd_lag_phys_demographic-revision_id']['id'] = 'field_enrd_lag_phys_demographic-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_phys_demographic-revision_id']['table'] = 'field_revision_field_enrd_lag_phys_demographic';
  $handler->display->display_options['fields']['field_enrd_lag_phys_demographic-revision_id']['field'] = 'field_enrd_lag_phys_demographic-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_phys_demographic-revision_id']['type'] = 'ds_taxonomy_separator_localized';
  $handler->display->display_options['fields']['field_enrd_lag_phys_demographic-revision_id']['delta_offset'] = '0';
  /* Field: Content (historical data): Assets & land use of the LAG area */
  $handler->display->display_options['fields']['field_enrd_lag_assets_land_use-revision_id']['id'] = 'field_enrd_lag_assets_land_use-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_assets_land_use-revision_id']['table'] = 'field_revision_field_enrd_lag_assets_land_use';
  $handler->display->display_options['fields']['field_enrd_lag_assets_land_use-revision_id']['field'] = 'field_enrd_lag_assets_land_use-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_assets_land_use-revision_id']['type'] = 'ds_taxonomy_separator_localized';
  $handler->display->display_options['fields']['field_enrd_lag_assets_land_use-revision_id']['delta_offset'] = '0';
  /* Field: Content (historical data): Size of territory (km²) */
  $handler->display->display_options['fields']['field_enrd_lag_size_territory-revision_id']['id'] = 'field_enrd_lag_size_territory-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_size_territory-revision_id']['table'] = 'field_revision_field_enrd_lag_size_territory';
  $handler->display->display_options['fields']['field_enrd_lag_size_territory-revision_id']['field'] = 'field_enrd_lag_size_territory-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_size_territory-revision_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content (historical data): Municipalities covered */
  $handler->display->display_options['fields']['field_enrd_lag_geo_coverage-revision_id']['id'] = 'field_enrd_lag_geo_coverage-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_geo_coverage-revision_id']['table'] = 'field_revision_field_enrd_lag_geo_coverage';
  $handler->display->display_options['fields']['field_enrd_lag_geo_coverage-revision_id']['field'] = 'field_enrd_lag_geo_coverage-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_geo_coverage-revision_id']['settings'] = array(
    'trim_length' => '200',
    'trim_ellipsis' => 1,
    'effect' => 'slide',
    'css3' => 1,
    'trigger_expanded_label' => 'Expand',
    'trigger_collapsed_label' => '',
    'trigger_classes' => 'button',
    'inline' => 1,
    'js_duration' => '500',
  );
  /* Field: Content (historical data): Sub-municipal level */
  $handler->display->display_options['fields']['field_enrd_lag_geo_coverage_sub-revision_id']['id'] = 'field_enrd_lag_geo_coverage_sub-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_geo_coverage_sub-revision_id']['table'] = 'field_revision_field_enrd_lag_geo_coverage_sub';
  $handler->display->display_options['fields']['field_enrd_lag_geo_coverage_sub-revision_id']['field'] = 'field_enrd_lag_geo_coverage_sub-revision_id';
  /* Field: Content (historical data): No. of inhabitants */
  $handler->display->display_options['fields']['field_enrd_lag_inhabitants-revision_id']['id'] = 'field_enrd_lag_inhabitants-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_inhabitants-revision_id']['table'] = 'field_revision_field_enrd_lag_inhabitants';
  $handler->display->display_options['fields']['field_enrd_lag_inhabitants-revision_id']['field'] = 'field_enrd_lag_inhabitants-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_inhabitants-revision_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content (historical data): Number of entities in LAG decision body */
  $handler->display->display_options['fields']['field_enrd_lag_entities_num-revision_id']['id'] = 'field_enrd_lag_entities_num-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_entities_num-revision_id']['table'] = 'field_revision_field_enrd_lag_entities_num';
  $handler->display->display_options['fields']['field_enrd_lag_entities_num-revision_id']['field'] = 'field_enrd_lag_entities_num-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_entities_num-revision_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content (historical data): Number of LAG staff */
  $handler->display->display_options['fields']['field_enrd_lag_staff_num-revision_id']['id'] = 'field_enrd_lag_staff_num-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_staff_num-revision_id']['table'] = 'field_revision_field_enrd_lag_staff_num';
  $handler->display->display_options['fields']['field_enrd_lag_staff_num-revision_id']['field'] = 'field_enrd_lag_staff_num-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_staff_num-revision_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content (historical data): Total LAG budget */
  $handler->display->display_options['fields']['field_enrd_lag_total_budget-revision_id']['id'] = 'field_enrd_lag_total_budget-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_total_budget-revision_id']['table'] = 'field_revision_field_enrd_lag_total_budget';
  $handler->display->display_options['fields']['field_enrd_lag_total_budget-revision_id']['field'] = 'field_enrd_lag_total_budget-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_total_budget-revision_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content (historical data): Additional ESI Funds */
  $handler->display->display_options['fields']['field_enrd_additional_esi_funds-revision_id']['id'] = 'field_enrd_additional_esi_funds-revision_id';
  $handler->display->display_options['fields']['field_enrd_additional_esi_funds-revision_id']['table'] = 'field_revision_field_enrd_additional_esi_funds';
  $handler->display->display_options['fields']['field_enrd_additional_esi_funds-revision_id']['field'] = 'field_enrd_additional_esi_funds-revision_id';
  $handler->display->display_options['fields']['field_enrd_additional_esi_funds-revision_id']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_enrd_additional_esi_funds-revision_id']['delta_offset'] = '0';
  /* Field: Content (historical data): EAFRD contribution */
  $handler->display->display_options['fields']['field_enrd_lag_eafrd_contrib-revision_id']['id'] = 'field_enrd_lag_eafrd_contrib-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_eafrd_contrib-revision_id']['table'] = 'field_revision_field_enrd_lag_eafrd_contrib';
  $handler->display->display_options['fields']['field_enrd_lag_eafrd_contrib-revision_id']['field'] = 'field_enrd_lag_eafrd_contrib-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_eafrd_contrib-revision_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content (historical data): ESF contribution */
  $handler->display->display_options['fields']['field_enrd_lag_esf_contrib-revision_id']['id'] = 'field_enrd_lag_esf_contrib-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_esf_contrib-revision_id']['table'] = 'field_revision_field_enrd_lag_esf_contrib';
  $handler->display->display_options['fields']['field_enrd_lag_esf_contrib-revision_id']['field'] = 'field_enrd_lag_esf_contrib-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_esf_contrib-revision_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content (historical data): ERDF contribution */
  $handler->display->display_options['fields']['field_enrd_lag_erdf_contrib-revision_id']['id'] = 'field_enrd_lag_erdf_contrib-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_erdf_contrib-revision_id']['table'] = 'field_revision_field_enrd_lag_erdf_contrib';
  $handler->display->display_options['fields']['field_enrd_lag_erdf_contrib-revision_id']['field'] = 'field_enrd_lag_erdf_contrib-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_erdf_contrib-revision_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content (historical data): EMFF contribution */
  $handler->display->display_options['fields']['field_enrd_lag_emff_contrib-revision_id']['id'] = 'field_enrd_lag_emff_contrib-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_emff_contrib-revision_id']['table'] = 'field_revision_field_enrd_lag_emff_contrib';
  $handler->display->display_options['fields']['field_enrd_lag_emff_contrib-revision_id']['field'] = 'field_enrd_lag_emff_contrib-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_emff_contrib-revision_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content (historical data): National contribution */
  $handler->display->display_options['fields']['field_enrd_lag_national_contrib-revision_id']['id'] = 'field_enrd_lag_national_contrib-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_national_contrib-revision_id']['table'] = 'field_revision_field_enrd_lag_national_contrib';
  $handler->display->display_options['fields']['field_enrd_lag_national_contrib-revision_id']['field'] = 'field_enrd_lag_national_contrib-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_national_contrib-revision_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content (historical data): Private contribution */
  $handler->display->display_options['fields']['field_enrd_lag_private_contrib-revision_id']['id'] = 'field_enrd_lag_private_contrib-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_private_contrib-revision_id']['table'] = 'field_revision_field_enrd_lag_private_contrib';
  $handler->display->display_options['fields']['field_enrd_lag_private_contrib-revision_id']['field'] = 'field_enrd_lag_private_contrib-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_private_contrib-revision_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content (historical data): Other funding schemes used */
  $handler->display->display_options['fields']['field_enrd_lag_other_funding-revision_id']['id'] = 'field_enrd_lag_other_funding-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_other_funding-revision_id']['table'] = 'field_revision_field_enrd_lag_other_funding';
  $handler->display->display_options['fields']['field_enrd_lag_other_funding-revision_id']['field'] = 'field_enrd_lag_other_funding-revision_id';
  /* Field: Content (historical data): Is your LAG interested in future CLLD Cooperation? */
  $handler->display->display_options['fields']['field_enrd_lag_interested_in-revision_id']['id'] = 'field_enrd_lag_interested_in-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_interested_in-revision_id']['table'] = 'field_revision_field_enrd_lag_interested_in';
  $handler->display->display_options['fields']['field_enrd_lag_interested_in-revision_id']['field'] = 'field_enrd_lag_interested_in-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_interested_in-revision_id']['label'] = 'Interest in CLLD Cooperation';
  $handler->display->display_options['fields']['field_enrd_lag_interested_in-revision_id']['type'] = 'list_key';
  /* Field: Content (historical data): Themes of interest for cooperation activities */
  $handler->display->display_options['fields']['field_enrd_lag_themes_interests-revision_id']['id'] = 'field_enrd_lag_themes_interests-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_themes_interests-revision_id']['table'] = 'field_revision_field_enrd_lag_themes_interests';
  $handler->display->display_options['fields']['field_enrd_lag_themes_interests-revision_id']['field'] = 'field_enrd_lag_themes_interests-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_themes_interests-revision_id']['type'] = 'ds_taxonomy_separator_localized';
  $handler->display->display_options['fields']['field_enrd_lag_themes_interests-revision_id']['delta_offset'] = '0';
  /* Field: Content (historical data): Contact name */
  $handler->display->display_options['fields']['field_enrd_lag_clld_name-revision_id']['id'] = 'field_enrd_lag_clld_name-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_clld_name-revision_id']['table'] = 'field_revision_field_enrd_lag_clld_name';
  $handler->display->display_options['fields']['field_enrd_lag_clld_name-revision_id']['field'] = 'field_enrd_lag_clld_name-revision_id';
  /* Field: Content (historical data): Contact email */
  $handler->display->display_options['fields']['field_enrd_lag_clld_email-revision_id']['id'] = 'field_enrd_lag_clld_email-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_clld_email-revision_id']['table'] = 'field_revision_field_enrd_lag_clld_email';
  $handler->display->display_options['fields']['field_enrd_lag_clld_email-revision_id']['field'] = 'field_enrd_lag_clld_email-revision_id';
  /* Field: Content (historical data): LAG project examples */
  $handler->display->display_options['fields']['field_enrd_lag_project_examples-revision_id']['id'] = 'field_enrd_lag_project_examples-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_project_examples-revision_id']['table'] = 'field_revision_field_enrd_lag_project_examples';
  $handler->display->display_options['fields']['field_enrd_lag_project_examples-revision_id']['field'] = 'field_enrd_lag_project_examples-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_project_examples-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_lag_project_examples-revision_id']['alter']['text'] = '[field_enrd_lag_project_examples-revision_id-title]|[field_enrd_lag_project_examples-revision_id-url]';
  $handler->display->display_options['fields']['field_enrd_lag_project_examples-revision_id']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_enrd_lag_project_examples-revision_id']['delta_offset'] = '0';
  /* Field: Content (historical data): Documentation */
  $handler->display->display_options['fields']['field_enrd_lag_documentation-revision_id']['id'] = 'field_enrd_lag_documentation-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_documentation-revision_id']['table'] = 'field_revision_field_enrd_lag_documentation';
  $handler->display->display_options['fields']['field_enrd_lag_documentation-revision_id']['field'] = 'field_enrd_lag_documentation-revision_id';
  $handler->display->display_options['fields']['field_enrd_lag_documentation-revision_id']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_enrd_lag_documentation-revision_id']['type'] = 'enrd_file_name_path';
  $handler->display->display_options['fields']['field_enrd_lag_documentation-revision_id']['settings'] = array(
    'text' => 'Download [file:name]',
  );
  $handler->display->display_options['fields']['field_enrd_lag_documentation-revision_id']['delta_offset'] = '0';
  /* Field: Workbench Moderation: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Workflow state';
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  /* Field: Workbench Moderation: Timestamp */
  $handler->display->display_options['fields']['stamp']['id'] = 'stamp';
  $handler->display->display_options['fields']['stamp']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['stamp']['field'] = 'stamp';
  $handler->display->display_options['fields']['stamp']['label'] = 'Revised on';
  $handler->display->display_options['fields']['stamp']['date_format'] = 'short';
  $handler->display->display_options['fields']['stamp']['second_date_format'] = 'enrd_lag_database_d_m_y';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['group'] = 1;
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'State';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['state']['group_info']['label'] = 'State';
  $handler->display->display_options['filters']['state']['group_info']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['group_info']['optional'] = FALSE;
  $handler->display->display_options['filters']['state']['group_info']['default_group'] = '2';
  $handler->display->display_options['filters']['state']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Updates',
      'operator' => 'in',
      'value' => array(
        'draft' => 'draft',
        'all' => 0,
        'ready_to_be_published' => 0,
        'needs_review' => 0,
        'validated' => 0,
        'published' => 0,
        'archived' => 0,
      ),
    ),
    2 => array(
      'title' => 'Published',
      'operator' => 'in',
      'value' => array(
        'published' => 'published',
        'all' => 0,
        'draft' => 0,
        'ready_to_be_published' => 0,
        'needs_review' => 0,
        'validated' => 0,
        'archived' => 0,
      ),
    ),
    3 => array(
      'title' => 'Archived',
      'operator' => 'in',
      'value' => array(
        'archived' => 'archived',
        'all' => 0,
        'draft' => 0,
        'ready_to_be_published' => 0,
        'needs_review' => 0,
        'validated' => 0,
        'published' => 0,
      ),
    ),
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search in the LAG Database';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title_field-revision_id' => 'title_field-revision_id',
    'field_enrd_lag_code-revision_id' => 'field_enrd_lag_code-revision_id',
    'field_enrd_lag_email-revision_id' => 'field_enrd_lag_email-revision_id',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'lag' => 'lag',
  );
  $handler->display->display_options['filters']['type']['group'] = 2;
  /* Filter criterion: Workbench Moderation: Current */
  $handler->display->display_options['filters']['is_current']['id'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['value'] = '1';
  $handler->display->display_options['filters']['is_current']['group'] = 2;
  /* Filter criterion: Field: Country (field_enrd_lag_country) */
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['id'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['table'] = 'field_data_field_enrd_lag_country';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['field'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['relationship'] = 'nid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['operator_id'] = 'field_enrd_lag_country_tid_op';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['operator'] = 'field_enrd_lag_country_tid_op';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['identifier'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['vocabulary'] = 'enrd_countries';
  /* Filter criterion: Content: Main ESI Fund (field_enrd_main_esi_fund) */
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['id'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['table'] = 'field_data_field_enrd_main_esi_fund';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['field'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['relationship'] = 'nid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['operator_id'] = 'field_enrd_main_esi_fund_tid_op';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['label'] = 'ESI Fund';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['operator'] = 'field_enrd_main_esi_fund_tid_op';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['identifier'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['vocabulary'] = 'enrd_esi_funds';
  /* Filter criterion: Content: Has taxonomy terms (with depth; Simple hierarchical select) */
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['id'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['field'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['relationship'] = 'nid';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator_id'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['label'] = 'ESIF Programme';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['identifier'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['vocabulary'] = 'enrd_esif_programme';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['use_chosen'] = 'always';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['depth'] = '2';
  $handler->display->display_options['path'] = 'lag-dashboard/lag-profiles.csv';
  $handler->display->display_options['displays'] = array(
    'lag_profiles_page' => 'lag_profiles_page',
    'default' => 0,
    'pending_lags' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'lag-dashboard/lag-profiles';
  $handler->display->display_options['segment_size'] = '50';
  $export['enrd_lag_database_custom_dashboard'] = $view;

  $view = new view();
  $view->name = 'enrd_lag_database_lag_users_dashboard';
  $view->description = 'Custom LAG Admins\'s dashboard the management of any LAG users.';
  $view->tag = 'ENRD LAG Dashboard';
  $view->base_table = 'users';
  $view->human_name = 'ENRD Manage LAG users Custom Dashboard';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'LAG Contacts';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'esi_fund_context';
  $handler->display->display_options['access']['perm'] = 'access lag dashboards';
  $handler->display->display_options['access']['esi_fund_perm'] = 'access lag dashboards';
  $handler->display->display_options['access']['lag_perm'] = 'access lag dashboards';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'mail' => 'mail',
    'name' => 'name',
    'realname' => 'realname',
    'og_roles' => 'og_roles',
    'title_field' => 'title_field',
    'field_enrd_lag_country' => 'field_enrd_lag_country',
    'field_enrd_lag_code' => 'field_enrd_lag_code',
    'created' => 'created',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'realname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'og_roles' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_field' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_country' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enrd_lag_code' => array(
      'sortable' => 0,
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
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No LAG users have been created yet with the selected criteria.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: OG membership: OG membership from User */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Relationship: OG membership: OG Roles from membership */
  $handler->display->display_options['relationships']['og_users_roles']['id'] = 'og_users_roles';
  $handler->display->display_options['relationships']['og_users_roles']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_users_roles']['field'] = 'og_users_roles';
  $handler->display->display_options['relationships']['og_users_roles']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_users_roles']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['id'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['field'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_lag_group_ref_target_id']['required'] = TRUE;
  /* Field: Bulk operations: OG membership */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_og_membership';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::og_membership_delete_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Remove from LAG',
    ),
    'rules_component::rules_enrd_lag_dashboard_send_mail_from_og_membership' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Send an email',
    ),
  );
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'User';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[name]<br />
<em>[mail]</em>
';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['label'] = '';
  $handler->display->display_options['fields']['realname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['realname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['realname']['link_to_user'] = FALSE;
  /* Field: OG membership: OG user roles in group */
  $handler->display->display_options['fields']['og_roles']['id'] = 'og_roles';
  $handler->display->display_options['fields']['og_roles']['table'] = 'og_membership';
  $handler->display->display_options['fields']['og_roles']['field'] = 'og_roles';
  $handler->display->display_options['fields']['og_roles']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['fields']['og_roles']['label'] = 'LAG Role';
  $handler->display->display_options['fields']['og_roles']['empty'] = 'LAG Webmaster';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['fields']['title_field']['label'] = 'LAG';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: Field: Country */
  $handler->display->display_options['fields']['field_enrd_lag_country']['id'] = 'field_enrd_lag_country';
  $handler->display->display_options['fields']['field_enrd_lag_country']['table'] = 'field_data_field_enrd_lag_country';
  $handler->display->display_options['fields']['field_enrd_lag_country']['field'] = 'field_enrd_lag_country';
  $handler->display->display_options['fields']['field_enrd_lag_country']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['fields']['field_enrd_lag_country']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: LAG code */
  $handler->display->display_options['fields']['field_enrd_lag_code']['id'] = 'field_enrd_lag_code';
  $handler->display->display_options['fields']['field_enrd_lag_code']['table'] = 'field_data_field_enrd_lag_code';
  $handler->display->display_options['fields']['field_enrd_lag_code']['field'] = 'field_enrd_lag_code';
  $handler->display->display_options['fields']['field_enrd_lag_code']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['fields']['field_enrd_lag_code']['label'] = '';
  $handler->display->display_options['fields']['field_enrd_lag_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_enrd_lag_code']['element_label_colon'] = FALSE;
  /* Field: OG membership: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'og_membership';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['fields']['created']['label'] = 'Member since';
  $handler->display->display_options['fields']['created']['date_format'] = 'today time ago';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'enrd_lag_database_d_m_y';
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  /* Filter criterion: Field: Groups audience (og_group_ref) */
  $handler->display->display_options['filters']['og_group_ref_target_id']['id'] = 'og_group_ref_target_id';
  $handler->display->display_options['filters']['og_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['filters']['og_group_ref_target_id']['field'] = 'og_group_ref_target_id';
  $handler->display->display_options['filters']['og_group_ref_target_id']['operator'] = 'not empty';
  $handler->display->display_options['filters']['og_group_ref_target_id']['group'] = 1;
  /* Filter criterion: User: The user ID */
  $handler->display->display_options['filters']['uid_raw']['id'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['table'] = 'users';
  $handler->display->display_options['filters']['uid_raw']['field'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['operator'] = '!=';
  $handler->display->display_options['filters']['uid_raw']['value']['value'] = '1';
  $handler->display->display_options['filters']['uid_raw']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['filters']['type']['value'] = array(
    'lag' => 'lag',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Free search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'mail' => 'mail',
    'name' => 'name',
    'realname' => 'realname',
    'title_field' => 'title_field',
    'field_enrd_lag_code' => 'field_enrd_lag_code',
  );
  /* Filter criterion: Field: Country (field_enrd_lag_country) */
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['id'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['table'] = 'field_data_field_enrd_lag_country';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['field'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['operator_id'] = 'field_enrd_lag_country_tid_op';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['operator'] = 'field_enrd_lag_country_tid_op';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['identifier'] = 'field_enrd_lag_country_tid';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    10 => 0,
    7 => 0,
    6 => 0,
    11 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_enrd_lag_country_tid']['vocabulary'] = 'enrd_countries';
  /* Filter criterion: Content: Main ESI Fund (field_enrd_main_esi_fund) */
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['id'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['table'] = 'field_data_field_enrd_main_esi_fund';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['field'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['operator_id'] = 'field_enrd_main_esi_fund_tid_op';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['label'] = 'ESI Fund';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['operator'] = 'field_enrd_main_esi_fund_tid_op';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['identifier'] = 'field_enrd_main_esi_fund_tid';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    10 => 0,
    7 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_enrd_main_esi_fund_tid']['vocabulary'] = 'enrd_esi_funds';
  /* Filter criterion: Only LAG roles */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'og_role';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'og_users_roles';
  $handler->display->display_options['filters']['name']['ui_name'] = 'Only LAG roles';
  $handler->display->display_options['filters']['name']['value'] = array(
    'LAG Contact' => 'LAG Contact',
    'LAG Manager' => 'LAG Manager',
  );
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'LAG Role';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    10 => 0,
    7 => 0,
    6 => 0,
    11 => 0,
    12 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['name']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['name']['reduce_duplicates'] = TRUE;
  /* Filter criterion: OG user roles: Role Name */
  $handler->display->display_options['filters']['name_1']['id'] = 'name_1';
  $handler->display->display_options['filters']['name_1']['table'] = 'og_role';
  $handler->display->display_options['filters']['name_1']['field'] = 'name';
  $handler->display->display_options['filters']['name_1']['relationship'] = 'og_users_roles';
  $handler->display->display_options['filters']['name_1']['operator'] = 'not';
  $handler->display->display_options['filters']['name_1']['value'] = array(
    'administrator member' => 'administrator member',
  );

  /* Display: Page: LAG users */
  $handler = $view->new_display('page', 'Page: LAG users', 'lag_users_page');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'lag-dashboard/users/lag-users';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'LAG Contacts';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 1;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Contacts/Users';
  $handler->display->display_options['tab_options']['weight'] = '10';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'admin_users_export');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'users.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = '1';
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: OG membership: OG user roles in group */
  $handler->display->display_options['fields']['og_roles']['id'] = 'og_roles';
  $handler->display->display_options['fields']['og_roles']['table'] = 'og_membership';
  $handler->display->display_options['fields']['og_roles']['field'] = 'og_roles';
  $handler->display->display_options['fields']['og_roles']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['fields']['og_roles']['label'] = 'Roles';
  $handler->display->display_options['fields']['og_roles']['empty'] = 'LAG Webmaster';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['fields']['title_field']['label'] = 'LAG';
  $handler->display->display_options['fields']['title_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Field: Country */
  $handler->display->display_options['fields']['field_enrd_lag_country']['id'] = 'field_enrd_lag_country';
  $handler->display->display_options['fields']['field_enrd_lag_country']['table'] = 'field_data_field_enrd_lag_country';
  $handler->display->display_options['fields']['field_enrd_lag_country']['field'] = 'field_enrd_lag_country';
  $handler->display->display_options['fields']['field_enrd_lag_country']['relationship'] = 'og_lag_group_ref_target_id';
  $handler->display->display_options['fields']['field_enrd_lag_country']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: User: Active */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['type'] = 'active-blocked';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: OG membership: Created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'og_membership';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['granularity'] = 'day';
  $handler->display->display_options['path'] = 'lag-dashboard/users.csv';
  $handler->display->display_options['displays'] = array(
    'lag_users_page' => 'lag_users_page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'lag-dashboard/users';
  $handler->display->display_options['segment_size'] = '25';
  $export['enrd_lag_database_lag_users_dashboard'] = $view;

  return $export;
}
