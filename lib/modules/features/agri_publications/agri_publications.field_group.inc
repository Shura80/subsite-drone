<?php

/**
 * @file
 * agri_publications.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function agri_publications_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_agri_stakeholders|node|publication|form';
  $field_group->group_name = 'group_agri_stakeholders';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Stakeholders',
    'weight' => '1',
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
  $field_groups['group_agri_stakeholders|node|publication|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publication_content|node|publication|form';
  $field_group->group_name = 'group_publication_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_core_geographical_area',
      2 => 'field_core_keywords',
      3 => 'field_core_other_location',
      4 => 'field_core_title_eng',
      5 => 'field_publication_abstract',
      6 => 'field_publication_abstract_eng',
      7 => 'field_publication_attachments',
      8 => 'field_publication_authors',
      9 => 'field_publication_institution',
      10 => 'field_publication_type',
      11 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-publication-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_publication_content|node|publication|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publication_dates|node|publication|form';
  $field_group->group_name = 'group_publication_dates';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Dates',
    'weight' => '2',
    'children' => array(
      0 => 'field_publication_date',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-publication-dates field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_publication_dates|node|publication|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publication_metadata|node|publication|form';
  $field_group->group_name = 'group_publication_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '3',
    'children' => array(
      0 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-publication-metadata field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_publication_metadata|node|publication|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Content');
  t('Dates');
  t('Metadata');
  t('Stakeholders');

  return $field_groups;
}
