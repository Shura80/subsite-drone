<?php

/**
 * @file
 * enrd_nrn_profiles.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function enrd_nrn_profiles_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_classification|node|nrn_profile|form';
  $field_group->group_name = 'group_enrd_classification';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'nrn_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Classification',
    'weight' => '6',
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
  $field_groups['group_enrd_classification|node|nrn_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_nrnp_contacts_ds|node|nrn_profile|full';
  $field_group->group_name = 'group_enrd_nrnp_contacts_ds';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'nrn_profile';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contacts',
    'weight' => '4',
    'children' => array(
      0 => 'field_enrd_nrnp_address',
      1 => 'field_enrd_nrnp_contact_persons',
      2 => 'field_enrd_nrnp_email',
      3 => 'field_enrd_nrnp_organisation',
      4 => 'field_enrd_nrnp_phone',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Contacts',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'gruop-enrd-nrnp-contacts-ds',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'p',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_enrd_nrnp_contacts_ds|node|nrn_profile|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_nrnp_contacts_ds|node|nrn_profile|print';
  $field_group->group_name = 'group_enrd_nrnp_contacts_ds';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'nrn_profile';
  $field_group->mode = 'print';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contacts',
    'weight' => '5',
    'children' => array(
      0 => 'field_enrd_nrnp_address',
      1 => 'field_enrd_nrnp_contact_persons',
      2 => 'field_enrd_nrnp_email',
      3 => 'field_enrd_nrnp_organisation',
      4 => 'field_enrd_nrnp_phone',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contacts',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'gruop-enrd-nrnp-contacts-ds',
        'description' => '',
        'wrapper' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_enrd_nrnp_contacts_ds|node|nrn_profile|print'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_nrnp_contacts|node|nrn_profile|form';
  $field_group->group_name = 'group_enrd_nrnp_contacts';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'nrn_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contacts',
    'weight' => '1',
    'children' => array(
      0 => 'field_enrd_nrnp_address',
      1 => 'field_enrd_nrnp_contact_persons',
      2 => 'field_enrd_nrnp_email',
      3 => 'field_enrd_nrnp_organisation',
      4 => 'field_enrd_nrnp_phone',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-enrd-nrnp-contacts field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_enrd_nrnp_contacts|node|nrn_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_nrnp_content|node|nrn_profile|form';
  $field_group->group_name = 'group_enrd_nrnp_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'nrn_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'field_enrd_nrnp_activities',
      1 => 'field_enrd_nrnp_brief_intro',
      2 => 'field_enrd_nrnp_cooperation',
      3 => 'field_enrd_nrnp_country_page',
      4 => 'field_enrd_nrnp_highlights',
      5 => 'field_enrd_nrnp_logo',
      6 => 'title_field',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-enrd-nrnp-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_enrd_nrnp_content|node|nrn_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_nrnp_docs_media|node|nrn_profile|form';
  $field_group->group_name = 'group_enrd_nrnp_docs_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'nrn_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Documents & Media',
    'weight' => '4',
    'children' => array(
      0 => 'field_enrd_nrnp_documents',
      1 => 'field_enrd_nrnp_image',
      2 => 'field_enrd_nrnp_video',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-enrd-nrnp-docs-media field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_enrd_nrnp_docs_media|node|nrn_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_nrnp_links_ds|node|nrn_profile|full';
  $field_group->group_name = 'group_enrd_nrnp_links_ds';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'nrn_profile';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Links',
    'weight' => '5',
    'children' => array(
      0 => 'field_enrd_nrnp_external_links',
      1 => 'field_enrd_nrnp_social_media',
      2 => 'field_enrd_nrnp_website',
      3 => 'field_enrd_nrnp_internal_links',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Links',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-enrd-nrnp-links-ds',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'p',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_enrd_nrnp_links_ds|node|nrn_profile|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_nrnp_links_ds|node|nrn_profile|print';
  $field_group->group_name = 'group_enrd_nrnp_links_ds';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'nrn_profile';
  $field_group->mode = 'print';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Links',
    'weight' => '6',
    'children' => array(
      0 => 'field_enrd_nrnp_external_links',
      1 => 'field_enrd_nrnp_social_media',
      2 => 'field_enrd_nrnp_website',
      3 => 'field_enrd_nrnp_internal_links',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Links',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-enrd-nrnp-links-ds',
        'description' => '',
        'wrapper' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_enrd_nrnp_links_ds|node|nrn_profile|print'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_nrnp_links|node|nrn_profile|form';
  $field_group->group_name = 'group_enrd_nrnp_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'nrn_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Links',
    'weight' => '2',
    'children' => array(
      0 => 'field_enrd_nrnp_external_links',
      1 => 'field_enrd_nrnp_social_media',
      2 => 'field_enrd_nrnp_website',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-enrd-nrnp-links field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_enrd_nrnp_links|node|nrn_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_nrnp_metadata|node|nrn_profile|form';
  $field_group->group_name = 'group_enrd_nrnp_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'nrn_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '8',
    'children' => array(
      0 => 'path',
      1 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-enrd-nrnp-metadata field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_enrd_nrnp_metadata|node|nrn_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_nrnp_nsu_operation_ds|node|nrn_profile|full';
  $field_group->group_name = 'group_enrd_nrnp_nsu_operation_ds';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'nrn_profile';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'NSU operation',
    'weight' => '6',
    'children' => array(
      0 => 'field_enrd_nrnp_finan_resources',
      1 => 'field_enrd_nrnp_governance',
      2 => 'field_enrd_nrnp_membership',
      3 => 'field_enrd_nrnp_nsu_rdp',
      4 => 'field_enrd_nrnp_objectives',
      5 => 'field_enrd_nrnp_reg_repres',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'NSU operation',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-enrd-nrnp-nsu-operation-ds',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'p',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_enrd_nrnp_nsu_operation_ds|node|nrn_profile|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_nrnp_nsu_operation_ds|node|nrn_profile|print';
  $field_group->group_name = 'group_enrd_nrnp_nsu_operation_ds';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'nrn_profile';
  $field_group->mode = 'print';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'NSU operation',
    'weight' => '7',
    'children' => array(
      0 => 'field_enrd_nrnp_finan_resources',
      1 => 'field_enrd_nrnp_governance',
      2 => 'field_enrd_nrnp_membership',
      3 => 'field_enrd_nrnp_nsu_rdp',
      4 => 'field_enrd_nrnp_objectives',
      5 => 'field_enrd_nrnp_reg_repres',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'NSU operation',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-enrd-nrnp-nsu-operation-ds',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_enrd_nrnp_nsu_operation_ds|node|nrn_profile|print'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enrd_nrnp_nsu_operation|node|nrn_profile|form';
  $field_group->group_name = 'group_enrd_nrnp_nsu_operation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'nrn_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'NSU operation',
    'weight' => '3',
    'children' => array(
      0 => 'field_enrd_nrnp_finan_resources',
      1 => 'field_enrd_nrnp_governance',
      2 => 'field_enrd_nrnp_membership',
      3 => 'field_enrd_nrnp_nsu_rdp',
      4 => 'field_enrd_nrnp_objectives',
      5 => 'field_enrd_nrnp_reg_repres',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-enrd-nrnp-nsu-operation field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_enrd_nrnp_nsu_operation|node|nrn_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nrn_toolkit_fieldset|node|nrn_profile|enrd_nrn_toolkit_resource';
  $field_group->group_name = 'group_nrn_toolkit_fieldset';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'nrn_profile';
  $field_group->mode = 'enrd_nrn_toolkit_resource';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '2',
    'children' => array(
      0 => 'field_enrd_nrnp_country_page',
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
  $field_groups['group_nrn_toolkit_fieldset|node|nrn_profile|enrd_nrn_toolkit_resource'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nrn_toolkit|node|nrn_profile|form';
  $field_group->group_name = 'group_nrn_toolkit';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'nrn_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'NRN Toolkit',
    'weight' => '7',
    'children' => array(
      0 => 'field_enrd_nrn_alter_description',
      1 => 'field_enrd_nrn_date',
      2 => 'field_enrd_nrn_include_toolkit',
      3 => 'field_enrd_nrn_title',
      4 => 'field_enrd_nrn_type',
      5 => 'field_tax_networking',
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
  $field_groups['group_nrn_toolkit|node|nrn_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_technical_taxonomy|node|nrn_profile|form';
  $field_group->group_name = 'group_technical_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'nrn_profile';
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
        'classes' => 'group_technical_taxonomy field-group-tab',
        'required_fields' => FALSE,
      ),
    ),
  );
  $field_groups['group_technical_taxonomy|node|nrn_profile|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Classification');
  t('Contacts');
  t('Content');
  t('Documents & Media');
  t('Links');
  t('Metadata');
  t('NRN Toolkit');
  t('NSU operation');
  t('Technical taxonomy');

  return $field_groups;
}
