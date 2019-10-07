<?php

/**
 * @file
 * agri_news.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function agri_news_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_agri_stakeholders|node|news|form';
  $field_group->group_name = 'group_agri_stakeholders';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Stakeholders',
    'weight' => '1',
    'children' => array(
      0 => 'field_core_keywords',
      1 => 'field_core_stakeholders',
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
  $field_groups['group_agri_stakeholders|node|news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_funding_community|node|funding_opportunities|form';
  $field_group->group_name = 'group_funding_community';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'funding_opportunities';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Community',
    'weight' => '2',
    'children' => array(
      0 => 'group_content_access',
      1 => 'og_group_ref',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-funding-community field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_funding_community|node|funding_opportunities|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_funding_content|node|funding_opportunities|form';
  $field_group->group_name = 'group_funding_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'funding_opportunities';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_core_additional_info',
      2 => 'field_core_attachments',
      3 => 'field_core_email',
      4 => 'field_core_geographical_area',
      5 => 'field_core_keywords',
      6 => 'field_core_other_location',
      7 => 'field_core_publication_date',
      8 => 'field_news_maximum_support',
      9 => 'field_news_objectives',
      10 => 'field_news_programme_description',
      11 => 'field_news_target_group',
      12 => 'field_news_total_program_funding',
      13 => 'field_news_website',
      14 => 'field_organization_collection',
      15 => 'field_core_agricultural_sectors',
      16 => 'field_news_type_of_funding',
      17 => 'field_news_geographical_area',
      18 => 'field_news_other_location',
      19 => 'title',
      20 => 'twitter',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-funding-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_funding_content|node|funding_opportunities|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_funding_metadata|node|funding_opportunities|form';
  $field_group->group_name = 'group_funding_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'funding_opportunities';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '1',
    'children' => array(
      0 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-funding-metadata field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_funding_metadata|node|funding_opportunities|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_news_scheduled_publication|node|news|form';
  $field_group->group_name = 'group_news_scheduled_publication';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Scheduled publication',
    'weight' => '2',
    'children' => array(
      0 => 'field_news_publication_date',
      1 => 'field_news_unpublication_date',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-news-scheduled-publication field-group-fieldset field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_news_scheduled_publication|node|news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_online_resource_content|node|online_resource|form';
  $field_group->group_name = 'group_online_resource_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'online_resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_core_additional_info',
      2 => 'field_core_keywords',
      3 => 'field_core_link',
      4 => 'field_core_title_eng',
      5 => 'field_news_language',
      6 => 'field_core_geographical_area',
      7 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-online-resource-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_online_resource_content|node|online_resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_online_resource_metadata|node|online_resource|form';
  $field_group->group_name = 'group_online_resource_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'online_resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '1',
    'children' => array(
      0 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-online-resource-metadata field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_online_resource_metadata|node|online_resource|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Community');
  t('Content');
  t('Metadata');
  t('Scheduled publication');
  t('Stakeholders');

  return $field_groups;
}
