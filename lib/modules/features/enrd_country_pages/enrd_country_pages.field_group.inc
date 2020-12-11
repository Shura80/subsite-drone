<?php

/**
 * @file
 * enrd_country_pages.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function enrd_country_pages_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_additional_info|field_collection_item|field_enrd_rdp_info_region|form';
  $field_group->group_name = 'group_additional_info';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_enrd_rdp_info_region';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_regional_information';
  $field_group->data = array(
    'label' => 'Additional Information',
    'weight' => '16',
    'children' => array(
      0 => 'field_enrd_rdp_info_region_auth',
      1 => 'field_enrd_rdp_info_region_pay',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Additional Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-additional-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_additional_info|field_collection_item|field_enrd_rdp_info_region|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_classification|node|rdp_information|form';
  $field_group->group_name = 'group_enrd_classification';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'rdp_information';
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
        'description' => '',
        'classes' => 'group-enrd-classification field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_enrd_classification|node|rdp_information|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata|node|rdp_information|form';
  $field_group->group_name = 'group_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'rdp_information';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '6',
    'children' => array(
      0 => 'field_tags',
      1 => 'path',
      2 => 'language',
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
  $field_groups['group_metadata|node|rdp_information|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_national_information|node|rdp_information|form';
  $field_group->group_name = 'group_national_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'rdp_information';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'National Information',
    'weight' => '0',
    'children' => array(
      0 => 'title_field',
      1 => 'field_enrd_rdp_info_country',
      2 => 'group_national_intro_partnership',
      3 => 'group_national_rdp_info',
      4 => 'group_national_rural_network',
      5 => 'group_page_additional_info',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-national-information field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_national_information|node|rdp_information|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_national_intro_partnership|node|rdp_information|form';
  $field_group->group_name = 'group_national_intro_partnership';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'rdp_information';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_national_information';
  $field_group->data = array(
    'label' => 'Introductory text and Partnership Agreement',
    'weight' => '-3',
    'children' => array(
      0 => 'field_enrd_rdp_info_intro_text',
      1 => 'field_enrd_rdp_info_partner_agr',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Introductory text and Partnership Agreement',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-national-intro-partnership field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_national_intro_partnership|node|rdp_information|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_national_rdp_info|node|rdp_information|form';
  $field_group->group_name = 'group_national_rdp_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'rdp_information';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_national_information';
  $field_group->data = array(
    'label' => 'Country Information',
    'weight' => '-2',
    'children' => array(
      0 => 'field_enrd_rdp_info_partner_docs',
      1 => 'field_enrd_rdp_info_rdp',
      2 => 'field_enrd_rdp_info_rdp_docs',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Country Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-rdp-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_national_rdp_info|node|rdp_information|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_national_reg_rural_network|field_collection_item|field_enrd_rdp_info_region|form';
  $field_group->group_name = 'group_national_reg_rural_network';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_enrd_rdp_info_region';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_regional_information';
  $field_group->data = array(
    'label' => 'National Rural Network',
    'weight' => '15',
    'children' => array(
      0 => 'field_enrd_rdp_info_region_image',
      1 => 'field_enrd_rdp_info_region_nrn',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'National Rural Network',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-national-reg-rural-network field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_national_reg_rural_network|field_collection_item|field_enrd_rdp_info_region|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_national_rural_network|node|rdp_information|form';
  $field_group->group_name = 'group_national_rural_network';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'rdp_information';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_national_information';
  $field_group->data = array(
    'label' => 'National Rural Network',
    'weight' => '-1',
    'children' => array(
      0 => 'field_enrd_rdp_info_nrn_info',
      1 => 'field_rdp_info_nrn_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'National Rural Network',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-national-rural-network field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_national_rural_network|node|rdp_information|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_old_rdp_info|node|rdp_information|form';
  $field_group->group_name = 'group_old_rdp_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'rdp_information';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Old Country Information',
    'weight' => '2',
    'children' => array(
      0 => 'body',
      1 => 'field_page_sidebar',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Old Country Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-old-rdp-info field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_old_rdp_info|node|rdp_information|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_additional_info|node|rdp_information|form';
  $field_group->group_name = 'group_page_additional_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'rdp_information';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_national_information';
  $field_group->data = array(
    'label' => 'Additional Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_enrd_rdp_info_nat_pay_agen',
      1 => 'field_enrd_rdp_info_nation_auth',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Additional Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-additional-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_page_additional_info|node|rdp_information|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_regional_information|field_collection_item|field_enrd_rdp_info_region|form';
  $field_group->group_name = 'group_regional_information';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_enrd_rdp_info_region';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Regional information',
    'weight' => '0',
    'children' => array(
      0 => 'field_enrd_rdp_info_region_name',
      1 => 'group_additional_info',
      2 => 'group_national_reg_rural_network',
      3 => 'group_regional_intro_partnership',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-regional-information field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_regional_information|field_collection_item|field_enrd_rdp_info_region|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_regional_info|node|rdp_information|form';
  $field_group->group_name = 'group_regional_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'rdp_information';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Regional Information',
    'weight' => '1',
    'children' => array(
      0 => 'field_enrd_rdp_info_region',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-regional-info field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_regional_info|node|rdp_information|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_regional_intro_partnership|field_collection_item|field_enrd_rdp_info_region|form';
  $field_group->group_name = 'group_regional_intro_partnership';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_enrd_rdp_info_region';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_regional_information';
  $field_group->data = array(
    'label' => 'Introductory text and RDP documents',
    'weight' => '12',
    'children' => array(
      0 => 'field_enrd_rdp_info_region_docs',
      1 => 'field_enrd_rdp_info_region_intro',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Introductory text and RDP documents',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-regional-intro-partnership field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_regional_intro_partnership|field_collection_item|field_enrd_rdp_info_region|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_technical_taxonomy|node|rdp_information|form';
  $field_group->group_name = 'group_technical_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'rdp_information';
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
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_technical_taxonomy|node|rdp_information|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Additional Information');
  t('Classification');
  t('Country Information');
  t('Introductory text and Partnership Agreement');
  t('Introductory text and RDP documents');
  t('Metadata');
  t('National Information');
  t('National Rural Network');
  t('Old Country Information');
  t('Regional Information');
  t('Regional information');
  t('Technical taxonomy');

  return $field_groups;
}
