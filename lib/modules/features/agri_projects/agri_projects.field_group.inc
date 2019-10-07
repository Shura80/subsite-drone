<?php

/**
 * @file
 * agri_projects.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function agri_projects_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_agri_stakeholders|node|project|form';
  $field_group->group_name = 'group_agri_stakeholders';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Stakeholders',
    'weight' => '3',
    'children' => array(
      0 => 'field_core_stakeholders',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-agri-stakeholders field-group-tab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_agri_stakeholders|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_infomation|node|needs_for_research_from_practice|form';
  $field_group->group_name = 'group_contact_infomation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'needs_for_research_from_practice';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_needs_for_research_content';
  $field_group->data = array(
    'label' => 'Contact person',
    'weight' => '10',
    'children' => array(
      0 => 'field_core_email',
      1 => 'field_projects_interested',
      2 => 'field_projects_name',
      3 => 'field_projects_surname',
      4 => 'field_projects_interested_in',
      5 => 'field_user_language_spoken',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-contact-infomation field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_contact_infomation|node|needs_for_research_from_practice|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_infomation|node|needs_for_research_from_practice|full';
  $field_group->group_name = 'group_contact_infomation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'needs_for_research_from_practice';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact person',
    'weight' => '6',
    'children' => array(
      0 => 'field_core_email',
      1 => 'field_projects_name',
      2 => 'field_projects_surname',
      3 => 'field_user_language_spoken',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Contact person',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-contact-infomation field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_contact_infomation|node|needs_for_research_from_practice|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_needs_for_res_metadata|node|needs_for_research_from_practice|form';
  $field_group->group_name = 'group_needs_for_res_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'needs_for_research_from_practice';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '1',
    'children' => array(
      0 => 'field_projects_language',
      1 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-needs-for-res-metadata field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_needs_for_res_metadata|node|needs_for_research_from_practice|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_needs_for_research_content|node|needs_for_research_from_practice|form';
  $field_group->group_name = 'group_needs_for_research_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'needs_for_research_from_practice';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_core_additional_info',
      2 => 'field_core_attachments',
      3 => 'field_core_description_eng',
      4 => 'field_core_geographical_area',
      5 => 'field_core_keywords',
      6 => 'field_core_other_location',
      7 => 'field_core_agricultural_sectors',
      8 => 'title',
      9 => 'group_contact_infomation',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-needs-for-research-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_needs_for_research_content|node|needs_for_research_from_practice|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_proj_further_details|node|project|form';
  $field_group->group_name = 'group_proj_further_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Further details',
    'weight' => '28',
    'children' => array(
      0 => 'field_proj_additional_info',
      1 => 'field_proj_og_budget',
      2 => 'field_proj_og_cross_border',
      3 => 'field_proj_og_eu_contribution',
      4 => 'field_proj_website',
      5 => 'field_proj_additional_comments',
      6 => 'field_proj_audiovisual_material',
      7 => 'field_proj_other_websites',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-proj-further-details field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_proj_further_details|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_proj_further_details|node|project|full';
  $field_group->group_name = 'group_proj_further_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Further details',
    'weight' => '31',
    'children' => array(
      0 => 'field_proj_additional_info',
      1 => 'field_proj_additional_comments',
      2 => 'field_proj_audiovisual_material',
      3 => 'field_proj_desc_context',
      4 => 'field_proj_other_websites',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-proj-further-details field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_proj_further_details|node|project|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_proj_further_details|node|project|print';
  $field_group->group_name = 'group_proj_further_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'print';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Further details',
    'weight' => '31',
    'children' => array(
      0 => 'field_proj_additional_info',
      1 => 'field_proj_additional_comments',
      2 => 'field_proj_audiovisual_material',
      3 => 'field_proj_desc_context',
      4 => 'field_proj_other_websites',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-proj-further-details field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_proj_further_details|node|project|print'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_proj_partners|node|project|full';
  $field_group->group_name = 'group_proj_partners';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Project partners',
    'weight' => '29',
    'children' => array(
      0 => 'field_proj_partner_fc',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Project partners',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-proj-partners field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_proj_partners|node|project|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_proj_partners|node|project|print';
  $field_group->group_name = 'group_proj_partners';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'print';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Project partners',
    'weight' => '29',
    'children' => array(
      0 => 'field_proj_partner_fc',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-proj-partners field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_proj_partners|node|project|print'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_ideas_content|node|project_ideas|form';
  $field_group->group_name = 'group_project_ideas_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project_ideas';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_core_additional_info',
      2 => 'field_core_description_eng',
      3 => 'field_core_email',
      4 => 'field_core_geographical_area',
      5 => 'field_core_keywords',
      6 => 'field_core_title_eng',
      7 => 'field_project_partners',
      8 => 'field_project_searching',
      9 => 'field_projects_outcomes',
      10 => 'field_projects_outcomes_eng',
      11 => 'field_projects_publications',
      12 => 'field_core_other_location',
      13 => 'field_core_agricultural_sectors',
      14 => 'field_user_language_spoken',
      15 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-project-ideas-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_project_ideas_content|node|project_ideas|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_ideas_dates|node|project_ideas|form';
  $field_group->group_name = 'group_project_ideas_dates';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project_ideas';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Dates',
    'weight' => '1',
    'children' => array(
      0 => 'field_projects_deadline',
      1 => 'field_projects_duration',
      2 => 'field_projects_starting',
      3 => 'field_projects_duration_months',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-project-ideas-dates field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_project_ideas_dates|node|project_ideas|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_ideas_metadata|node|project_ideas|form';
  $field_group->group_name = 'group_project_ideas_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project_ideas';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '2',
    'children' => array(
      0 => 'field_projects_language',
      1 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-project-ideas-metadata field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_project_ideas_metadata|node|project_ideas|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sfc_proj_practice_abstract|field_collection_item|field_sfc_proj_summary|default';
  $field_group->group_name = 'group_sfc_proj_practice_abstract';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_sfc_proj_summary';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Practice abstract',
    'weight' => '0',
    'children' => array(
      0 => 'field_sfc_proj_results',
      1 => 'field_sfc_proj_results_eng',
      2 => 'field_sfc_proj_sheet_pa',
      3 => 'field_sfc_proj_results_title_eng',
      4 => 'field_sfc_proj_results_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Practice abstract',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-sfc-proj-practice-abstract field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_sfc_proj_practice_abstract|field_collection_item|field_sfc_proj_summary|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contact person');
  t('Content');
  t('Dates');
  t('Further details');
  t('Metadata');
  t('Practice abstract');
  t('Project partners');
  t('Stakeholders');

  return $field_groups;
}
