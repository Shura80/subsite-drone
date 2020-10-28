<?php

/**
 * @file
 * enrd_lag_database.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function enrd_lag_database_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_coop_content|node|cooperation_offer|form';
  $field_group->group_name = 'group_coop_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cooperation_offer';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_coop_offer_container';
  $field_group->data = array(
    'label' => 'My LAG',
    'weight' => '0',
    'children' => array(
      0 => 'og_lag_group_ref',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'label' => 'My LAG',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-coop-my-lag',
        'description' => '',
      ),
      'formatter' => 'start',
    ),
  );
  $field_groups['group_coop_content|node|cooperation_offer|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_coop_offer_container|node|cooperation_offer|form';
  $field_group->group_name = 'group_coop_offer_container';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cooperation_offer';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Cooperation offer',
    'weight' => '0',
    'children' => array(
      0 => 'group_coop_content',
      1 => 'group_enrd_coop_contact_info',
      2 => 'group_enrd_coop_looking_for',
      3 => 'group_enrd_coop_project_idea',
    ),
    'format_type' => 'multipage-group',
    'format_settings' => array(
      'label' => 'Cooperation offer',
      'instance_settings' => array(
        'classes' => 'group-coop-offer-container',
        'page_header' => '3',
        'page_counter' => '1',
        'move_button' => '1',
        'move_additional' => '1',
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_coop_offer_container|node|cooperation_offer|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_classification|node|cooperation_offer|form';
  $field_group->group_name = 'group_enrd_classification';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cooperation_offer';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Classification',
    'weight' => '1',
    'children' => array(
      0 => 'field_tax_country',
      1 => 'field_tax_evaluation',
      2 => 'field_tax_languages',
      3 => 'field_tax_rural_dev_policy',
      4 => 'field_tax_transversal_topics',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-enrd-classification field-group-tab',
        'required_fields' => FALSE,
      ),
    ),
  );
  $field_groups['group_enrd_classification|node|cooperation_offer|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_classification|node|esi_funds_og|form';
  $field_group->group_name = 'group_enrd_classification';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'esi_funds_og';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Classification',
    'weight' => '2',
    'children' => array(
      0 => 'field_tax_country',
      1 => 'field_tax_evaluation',
      2 => 'field_tax_languages',
      3 => 'field_tax_rural_dev_policy',
      4 => 'field_tax_transversal_topics',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-enrd-classification field-group-tab',
        'required_fields' => FALSE,
      ),
    ),
  );
  $field_groups['group_enrd_classification|node|esi_funds_og|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_classification|node|lag|form';
  $field_group->group_name = 'group_enrd_classification';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lag';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Classification',
    'weight' => '7',
    'children' => array(
      0 => 'field_tax_country',
      1 => 'field_tax_evaluation',
      2 => 'field_tax_languages',
      3 => 'field_tax_rural_dev_policy',
      4 => 'field_tax_transversal_topics',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-enrd-classification field-group-tab',
        'required_fields' => FALSE,
      ),
    ),
  );
  $field_groups['group_enrd_classification|node|lag|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_coop_contact_info|node|cooperation_offer|form';
  $field_group->group_name = 'group_enrd_coop_contact_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cooperation_offer';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_coop_offer_container';
  $field_group->data = array(
    'label' => 'Contact information',
    'weight' => '3',
    'children' => array(
      0 => 'field_enrd_coop_lag_email',
      1 => 'field_enrd_coop_spoken_languages',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'formatter' => 'no-start',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-enrd-coop-contact-info',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_enrd_coop_contact_info|node|cooperation_offer|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_coop_looking_for|node|cooperation_offer|default';
  $field_group->group_name = 'group_enrd_coop_looking_for';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cooperation_offer';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Looking for',
    'weight' => '3',
    'children' => array(
      0 => 'field_enrd_coop_assets_area',
      1 => 'field_enrd_coop_partner_country',
      2 => 'field_enrd_coop_non_eu_name',
      3 => 'field_enrd_coop_partner_region',
      4 => 'field_enrd_coop_type_of_area',
      5 => 'field_enrd_coop_type_of_partner',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-enrd-coop-looking-for field-group-fieldset',
        'id' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
    ),
  );
  $field_groups['group_enrd_coop_looking_for|node|cooperation_offer|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_coop_looking_for|node|cooperation_offer|form';
  $field_group->group_name = 'group_enrd_coop_looking_for';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cooperation_offer';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_coop_offer_container';
  $field_group->data = array(
    'label' => 'Looking for',
    'weight' => '2',
    'children' => array(
      0 => 'field_enrd_coop_assets_area',
      1 => 'field_enrd_coop_partner_country',
      2 => 'field_enrd_coop_partner_region',
      3 => 'field_enrd_coop_type_of_area',
      4 => 'field_enrd_coop_type_of_partner',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'formatter' => 'no-start',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-enrd-coop-looking-for',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_enrd_coop_looking_for|node|cooperation_offer|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_coop_looking_for|node|cooperation_offer|full';
  $field_group->group_name = 'group_enrd_coop_looking_for';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cooperation_offer';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Looking to cooperate with',
    'weight' => '4',
    'children' => array(
      0 => 'field_enrd_coop_assets_area',
      1 => 'field_enrd_coop_partner_country',
      2 => 'field_enrd_coop_partner_region',
      3 => 'field_enrd_coop_type_of_area',
      4 => 'field_enrd_coop_type_of_partner',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Looking to cooperate with',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-enrd-coop-looking-for field-group-fieldset',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_enrd_coop_looking_for|node|cooperation_offer|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_coop_project_idea|node|cooperation_offer|default';
  $field_group->group_name = 'group_enrd_coop_project_idea';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cooperation_offer';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Project idea',
    'weight' => '4',
    'children' => array(
      0 => 'field_enrd_coop_brief_summary',
      1 => 'field_enrd_coop_context',
      2 => 'field_enrd_coop_objectives',
      3 => 'field_enrd_coop_topic_of_project',
      4 => 'field_enrd_coop_type',
      5 => 'field_enrd_coop_addit_keywords',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-enrd-coop-project-idea field-group-fieldset',
        'id' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
    ),
  );
  $field_groups['group_enrd_coop_project_idea|node|cooperation_offer|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_coop_project_idea|node|cooperation_offer|form';
  $field_group->group_name = 'group_enrd_coop_project_idea';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cooperation_offer';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_coop_offer_container';
  $field_group->data = array(
    'label' => 'Project idea',
    'weight' => '1',
    'children' => array(
      0 => 'field_enrd_coop_brief_summary',
      1 => 'field_enrd_coop_context',
      2 => 'field_enrd_coop_expiry_date',
      3 => 'field_enrd_coop_objectives',
      4 => 'field_enrd_coop_topic_of_project',
      5 => 'field_enrd_coop_type',
      6 => 'title_field',
      7 => 'field_enrd_coop_addit_keywords',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'formatter' => 'no-start',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-enrd-coop-project-idea',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_enrd_coop_project_idea|node|cooperation_offer|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_coop_project_idea|node|cooperation_offer|full';
  $field_group->group_name = 'group_enrd_coop_project_idea';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cooperation_offer';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Project idea',
    'weight' => '5',
    'children' => array(
      0 => 'field_enrd_coop_addit_keywords',
      1 => 'field_enrd_coop_brief_summary',
      2 => 'field_enrd_coop_context',
      3 => 'field_enrd_coop_objectives',
      4 => 'field_enrd_coop_topic_of_project',
      5 => 'field_enrd_coop_type',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Project idea',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-enrd-coop-project-idea field-group-fieldset',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_enrd_coop_project_idea|node|cooperation_offer|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_esi_access_rights|node|esi_funds_og|form';
  $field_group->group_name = 'group_enrd_esi_access_rights';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'esi_funds_og';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Access rights',
    'weight' => '3',
    'children' => array(
      0 => 'group_group',
      1 => 'group_access',
      2 => 'group_content_access',
      3 => 'og_roles_permissions',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-enrd-esi-access-rights field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_enrd_esi_access_rights|node|esi_funds_og|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_lag_access_rights|node|lag|form';
  $field_group->group_name = 'group_enrd_lag_access_rights';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lag';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Access rights',
    'weight' => '5',
    'children' => array(
      0 => 'group_access',
      1 => 'group_content_access',
      2 => 'group_group',
      3 => 'og_roles_permissions',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-enrd-lag-lag-access-rights field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_enrd_lag_access_rights|node|lag|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_lag_additional_doc|node|lag|form';
  $field_group->group_name = 'group_enrd_lag_additional_doc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lag';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'LAG projects and documents',
    'weight' => '4',
    'children' => array(
      0 => 'field_enrd_lag_documentation',
      1 => 'field_enrd_lag_project_examples',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-enrd-lag-additional-doc field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_enrd_lag_additional_doc|node|lag|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_lag_basic_lag_data|node|lag|form';
  $field_group->group_name = 'group_enrd_lag_basic_lag_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lag';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'LAG contact info',
    'weight' => '0',
    'children' => array(
      0 => 'field_enrd_esif_programme',
      1 => 'field_enrd_lag_code',
      2 => 'field_enrd_lag_coordinates',
      3 => 'field_enrd_lag_country',
      4 => 'field_enrd_lag_manager_address',
      5 => 'field_enrd_main_esi_fund',
      6 => 'og_group_ref',
      7 => 'title_field',
      8 => 'group_enrd_lag_contacts',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'LAG contact info',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_enrd_lag_basic_lag_data|node|lag|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_lag_budgets|node|lag|form';
  $field_group->group_name = 'group_enrd_lag_budgets';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lag';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'LAG funding',
    'weight' => '2',
    'children' => array(
      0 => 'field_enrd_additional_esi_funds',
      1 => 'field_enrd_lag_eafrd_contrib',
      2 => 'field_enrd_lag_emff_contrib',
      3 => 'field_enrd_lag_erdf_contrib',
      4 => 'field_enrd_lag_esf_contrib',
      5 => 'field_enrd_lag_national_contrib',
      6 => 'field_enrd_lag_other_funding',
      7 => 'field_enrd_lag_private_contrib',
      8 => 'field_enrd_lag_total_budget',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_enrd_lag_budgets|node|lag|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_lag_clld_coop|node|lag|form';
  $field_group->group_name = 'group_enrd_lag_clld_coop';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lag';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Cooperation details',
    'weight' => '3',
    'children' => array(
      0 => 'field_enrd_lag_clld_email',
      1 => 'field_enrd_lag_clld_name',
      2 => 'field_enrd_lag_interested_in',
      3 => 'field_enrd_lag_themes_interests',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_enrd_lag_clld_coop|node|lag|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_lag_contacts|node|lag|form';
  $field_group->group_name = 'group_enrd_lag_contacts';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lag';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_enrd_lag_basic_lag_data';
  $field_group->data = array(
    'label' => 'LAG contacts',
    'weight' => '67',
    'children' => array(
      0 => 'field_enrd_lag_email',
      1 => 'field_enrd_lag_extended_profile',
      2 => 'field_enrd_lag_facebook',
      3 => 'field_enrd_lag_linkedin',
      4 => 'field_enrd_lag_manager_email',
      5 => 'field_enrd_lag_manager_name',
      6 => 'field_enrd_lag_phone',
      7 => 'field_enrd_lag_spoken_languages',
      8 => 'field_enrd_lag_twitter',
      9 => 'field_enrd_lag_website',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'LAG contacts',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-lag-manager-contact field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_enrd_lag_contacts|node|lag|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_lag_detailed_lag_info|node|lag|form';
  $field_group->group_name = 'group_enrd_lag_detailed_lag_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lag';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Additional LAG info',
    'weight' => '1',
    'children' => array(
      0 => 'field_enrd_lag_assets_land_use',
      1 => 'field_enrd_lag_entities_num',
      2 => 'field_enrd_lag_geo_coverage',
      3 => 'field_enrd_lag_geo_coverage_sub',
      4 => 'field_enrd_lag_inhabitants',
      5 => 'field_enrd_lag_key_themes',
      6 => 'field_enrd_lag_logo',
      7 => 'field_enrd_lag_phys_demographic',
      8 => 'field_enrd_lag_size_territory',
      9 => 'field_enrd_lag_staff_num',
      10 => 'field_enrd_lag_strategy_info',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Additional LAG info',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_enrd_lag_detailed_lag_info|node|lag|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_esi_funds_og_content|node|esi_funds_og|form';
  $field_group->group_name = 'group_esi_funds_og_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'esi_funds_og';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_enrd_main_esi_fund',
      2 => 'title_field',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-esi-funds-og-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_esi_funds_og_content|node|esi_funds_og|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata|node|esi_funds_og|form';
  $field_group->group_name = 'group_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'esi_funds_og';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '1',
    'children' => array(
      0 => 'metatags',
      1 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-metadata field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_metadata|node|esi_funds_og|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_technical_taxonomy|node|cooperation_offer|form';
  $field_group->group_name = 'group_technical_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cooperation_offer';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Technical taxonomy',
    'weight' => '3',
    'children' => array(
      0 => 'field_tax_origin',
      1 => 'field_tax_translation_status',
      2 => 'field_tax_update_status',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-technical-taxonomy field-group-tab',
        'required_fields' => FALSE,
      ),
    ),
  );
  $field_groups['group_technical_taxonomy|node|cooperation_offer|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_technical_taxonomy|node|esi_funds_og|form';
  $field_group->group_name = 'group_technical_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'esi_funds_og';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Technical taxonomy',
    'weight' => '4',
    'children' => array(
      0 => 'field_tax_origin',
      1 => 'field_tax_translation_status',
      2 => 'field_tax_update_status',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-technical-taxonomy field-group-tab',
        'required_fields' => FALSE,
      ),
    ),
  );
  $field_groups['group_technical_taxonomy|node|esi_funds_og|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_technical_taxonomy|node|lag|form';
  $field_group->group_name = 'group_technical_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'lag';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Technical taxonomy',
    'weight' => '6',
    'children' => array(
      0 => 'field_tax_origin',
      1 => 'field_tax_translation_status',
      2 => 'field_tax_update_status',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-technical-taxonomy field-group-tab',
        'required_fields' => FALSE,
      ),
    ),
  );
  $field_groups['group_technical_taxonomy|node|lag|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Access rights');
  t('Additional LAG info');
  t('Classification');
  t('Contact information');
  t('Content');
  t('Cooperation details');
  t('Cooperation offer');
  t('LAG contact info');
  t('LAG contacts');
  t('LAG funding');
  t('LAG projects and documents');
  t('Looking for');
  t('Looking to cooperate with');
  t('Metadata');
  t('My LAG');
  t('Project idea');
  t('Technical taxonomy');

  return $field_groups;
}
