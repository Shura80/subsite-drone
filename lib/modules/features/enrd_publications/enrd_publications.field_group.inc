<?php

/**
 * @file
 * enrd_publications.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function enrd_publications_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_classification|node|publication_ehd|form';
  $field_group->group_name = 'group_enrd_classification';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication_ehd';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Classification',
    'weight' => '6',
    'children' => array(
      0 => 'field_tax_evaluation',
      1 => 'field_tax_rural_dev_policy',
      2 => 'field_tax_transversal_topics',
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
  $field_groups['group_enrd_classification|node|publication_ehd|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_classification|node|publication|form';
  $field_group->group_name = 'group_enrd_classification';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Classification',
    'weight' => '4',
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
        'classes' => 'group_enrd_classification field-group-tab',
        'required_fields' => FALSE,
      ),
    ),
  );
  $field_groups['group_enrd_classification|node|publication|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_publ_content|node|publication|form';
  $field_group->group_name = 'group_enrd_publ_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'field_enrd_publication_catal_num',
      1 => 'field_enrd_publication_date',
      2 => 'field_enrd_publication_desc',
      3 => 'field_enrd_publication_image',
      4 => 'field_enrd_publication_keywords',
      5 => 'field_enrd_publication_link_book',
      6 => 'field_enrd_publication_type',
      7 => 'field_enrd_publications_pages',
      8 => 'title_field',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-enrd-publ-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_enrd_publ_content|node|publication|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_publ_documentation|node|publication|form';
  $field_group->group_name = 'group_enrd_publ_documentation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Documentation',
    'weight' => '1',
    'children' => array(
      0 => 'field_enrd_publication_file',
      1 => 'field_enrd_publications_rel_docs',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-enrd-publ-documentation field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_enrd_publ_documentation|node|publication|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_publ_ehd_content|node|publication_ehd|form';
  $field_group->group_name = 'group_enrd_publ_ehd_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication_ehd';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'field_enrd_publ_ehd_abstract',
      1 => 'field_enrd_publ_ehd_author',
      2 => 'field_enrd_publ_ehd_content_type',
      3 => 'field_enrd_publ_ehd_description',
      4 => 'field_enrd_publ_ehd_editor',
      5 => 'field_enrd_publ_ehd_eval_theme',
      6 => 'field_enrd_publ_ehd_eval_type',
      7 => 'field_enrd_publ_ehd_pages',
      8 => 'field_enrd_publ_ehd_progr_period',
      9 => 'field_enrd_publ_ehd_rdp',
      10 => 'field_enrd_publ_ehd_title_image',
      11 => 'field_tags',
      12 => 'field_tax_country',
      13 => 'field_tax_languages',
      14 => 'title_field',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-enrd-publ-ehd-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_enrd_publ_ehd_content|node|publication_ehd|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_publ_ehd_doc|node|publication_ehd|form';
  $field_group->group_name = 'group_enrd_publ_ehd_doc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication_ehd';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Documentation',
    'weight' => '3',
    'children' => array(
      0 => 'field_enrd_publ_ehd_file',
      1 => 'field_enrd_publ_ehd_related_docs',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-enrd-publ-ehd-doc field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_enrd_publ_ehd_doc|node|publication_ehd|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_publ_ehd_further_info|node|publication_ehd|form';
  $field_group->group_name = 'group_enrd_publ_ehd_further_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication_ehd';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Further information',
    'weight' => '2',
    'children' => array(
      0 => 'field_enrd_publ_ehd_contact',
      1 => 'field_enrd_publ_ehd_further_info',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-enrd-publ-ehd-further-info field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_enrd_publ_ehd_further_info|node|publication_ehd|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_publ_ehd_history|node|publication_ehd|form';
  $field_group->group_name = 'group_enrd_publ_ehd_history';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication_ehd';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'History information',
    'weight' => '1',
    'children' => array(
      0 => 'field_enrd_publ_ehd_history',
      1 => 'field_enrd_publ_ehd_last_updated',
      2 => 'field_enrd_publ_ehd_public_date',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-enrd-publ-ehd-history field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_enrd_publ_ehd_history|node|publication_ehd|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_publ_ehd_metadata|node|publication_ehd|form';
  $field_group->group_name = 'group_enrd_publ_ehd_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication_ehd';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '4',
    'children' => array(
      0 => 'path',
      1 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Metadata',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-enrd-publ-ehd-metadata field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_enrd_publ_ehd_metadata|node|publication_ehd|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_publ_metadata|node|publication|form';
  $field_group->group_name = 'group_enrd_publ_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '2',
    'children' => array(
      0 => 'path',
      1 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-enrd-publ-metadata field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_enrd_publ_metadata|node|publication|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nrn_toolkit_fieldset|node|publication_ehd|enrd_nrn_toolkit_resource';
  $field_group->group_name = 'group_nrn_toolkit_fieldset';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication_ehd';
  $field_group->mode = 'enrd_nrn_toolkit_resource';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '34',
    'children' => array(
      0 => 'field_enrd_nrn_date',
      1 => 'field_enrd_nrn_type',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-nrn-toolkit-fieldset content-highlight clearfix',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_nrn_toolkit_fieldset|node|publication_ehd|enrd_nrn_toolkit_resource'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nrn_toolkit_fieldset|node|publication|enrd_nrn_toolkit_resource';
  $field_group->group_name = 'group_nrn_toolkit_fieldset';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'enrd_nrn_toolkit_resource';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '25',
    'children' => array(
      0 => 'field_enrd_nrn_date',
      1 => 'field_enrd_nrn_type',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-nrn-toolkit-fieldset content-highlight clearfix',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_nrn_toolkit_fieldset|node|publication|enrd_nrn_toolkit_resource'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nrn_toolkit|node|publication_ehd|form';
  $field_group->group_name = 'group_nrn_toolkit';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication_ehd';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'NRN Toolkit',
    'weight' => '7',
    'children' => array(
      0 => 'field_enrd_nrn_date',
      1 => 'field_enrd_nrn_include_toolkit',
      2 => 'field_enrd_nrn_type',
      3 => 'field_tax_networking',
      4 => 'field_enrd_nrn_title',
      5 => 'field_enrd_nrn_alter_description',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group_nrn_toolkit field-group-tab',
        'required_fields' => FALSE,
      ),
    ),
  );
  $field_groups['group_nrn_toolkit|node|publication_ehd|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nrn_toolkit|node|publication|form';
  $field_group->group_name = 'group_nrn_toolkit';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'NRN Toolkit',
    'weight' => '5',
    'children' => array(
      0 => 'field_enrd_nrn_date',
      1 => 'field_enrd_nrn_include_toolkit',
      2 => 'field_enrd_nrn_type',
      3 => 'field_tax_networking',
      4 => 'field_enrd_nrn_title',
      5 => 'field_enrd_nrn_alter_description',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group_nrn_toolkit field-group-tab',
        'required_fields' => FALSE,
      ),
    ),
  );
  $field_groups['group_nrn_toolkit|node|publication|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_technical_taxonomy|node|publication_ehd|form';
  $field_group->group_name = 'group_technical_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication_ehd';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Technical taxonomy',
    'weight' => '5',
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
  $field_groups['group_technical_taxonomy|node|publication_ehd|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_technical_taxonomy|node|publication|form';
  $field_group->group_name = 'group_technical_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
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
        'classes' => 'group_technical_taxonomy field-group-tab',
        'required_fields' => FALSE,
      ),
    ),
  );
  $field_groups['group_technical_taxonomy|node|publication|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Classification');
  t('Content');
  t('Documentation');
  t('Further information');
  t('History information');
  t('Metadata');
  t('NRN Toolkit');
  t('Technical taxonomy');

  return $field_groups;
}
