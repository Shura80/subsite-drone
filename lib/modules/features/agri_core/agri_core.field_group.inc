<?php

/**
 * @file
 * agri_core.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function agri_core_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_additional_information|field_collection_item|field_organization_collection|form';
  $field_group->group_name = 'group_additional_information';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_organization_collection';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Additional information',
    'weight' => '15',
    'children' => array(
      0 => 'field_core_additional_info',
      1 => 'field_projects_website',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Additional information',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-additional-information field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_additional_information|field_collection_item|field_organization_collection|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_agri_stakeholders|node|collaborative_area|form';
  $field_group->group_name = 'group_agri_stakeholders';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'collaborative_area';
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
  $field_groups['group_agri_stakeholders|node|collaborative_area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_collab_area_community|node|collaborative_area|form';
  $field_group->group_name = 'group_collab_area_community';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'collaborative_area';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Community',
    'weight' => '3',
    'children' => array(
      0 => 'group_group',
      1 => 'group_access',
      2 => 'og_menu',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-collab-area-community field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_collab_area_community|node|collaborative_area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_collab_area_metadata|node|collaborative_area|form';
  $field_group->group_name = 'group_collab_area_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'collaborative_area';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '2',
    'children' => array(
      0 => 'field_projects_active',
      1 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-collab-area-metadata field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_collab_area_metadata|node|collaborative_area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_collaborative_area_content|node|collaborative_area|form';
  $field_group->group_name = 'group_collaborative_area_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'collaborative_area';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_collaborative_attachments',
      2 => 'field_core_additional_info',
      3 => 'field_core_keywords',
      4 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-collaborative-area-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_collaborative_area_content|node|collaborative_area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gallery_community|node|gallery|form';
  $field_group->group_name = 'group_gallery_community';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'gallery';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Community',
    'weight' => '2',
    'children' => array(
      0 => 'og_group_ref',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-gallery-community field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_gallery_community|node|gallery|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gallery_content|node|gallery|form';
  $field_group->group_name = 'group_gallery_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'gallery';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_pictures',
      2 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-gallery-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_gallery_content|node|gallery|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gallery_metadata|node|gallery|form';
  $field_group->group_name = 'group_gallery_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'gallery';
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
        'classes' => 'group-gallery-metadata field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_gallery_metadata|node|gallery|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_images|node|page|form';
  $field_group->group_name = 'group_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_page_content';
  $field_group->data = array(
    'label' => 'Images',
    'weight' => '-5',
    'children' => array(
      0 => 'field_core_bulk_image_upload',
      1 => 'field_image_left',
      2 => 'field_image_right',
      3 => 'field_image_top',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-images field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_images|node|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_industry_retail_wholesale|user|user|form';
  $field_group->group_name = 'group_industry_retail_wholesale';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sector Working In hidden fields',
    'weight' => '22',
    'children' => array(),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Sector Working In hidden fields',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-sector-working-in field-group-tabs',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_industry_retail_wholesale|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_advisor|user|user|form';
  $field_group->group_name = 'group_user_advisor';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_details';
  $field_group->data = array(
    'label' => 'Advisor',
    'weight' => '16',
    'children' => array(
      0 => 'field_user_spec_advisor_sector',
      1 => 'field_user_spec_advisor_type',
      2 => 'field_user_spec_portfolio',
      3 => 'field_user_spec_rdp',
      4 => 'field_user_spec_advisor_other',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Advisor',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-user-advisor field-group-tabs',
        'description' => '',
        'element' => 'div',
        'attributes' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_user_advisor|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_civil|user|user|form';
  $field_group->group_name = 'group_user_civil';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_details';
  $field_group->data = array(
    'label' => 'Civil servant',
    'weight' => '19',
    'children' => array(
      0 => 'field_user_spec_admin_level',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Civil servant',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-user-civil field-group-tabs',
        'description' => '',
        'element' => 'div',
        'attributes' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_user_civil|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_details|user|user|form';
  $field_group->group_name = 'group_user_details';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'User\'s type details',
    'weight' => '1',
    'children' => array(
      0 => 'field_user_spec_size',
      1 => 'field_user_specify_other',
      2 => 'field_user_type',
      3 => 'field_user_spec_size_farm_land',
      4 => 'group_user_advisor',
      5 => 'group_user_civil',
      6 => 'group_user_farmer',
      7 => 'group_user_forester',
      8 => 'group_user_land_owner',
      9 => 'group_user_press',
      10 => 'group_user_research_repres',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'User\'s type details',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-user-details field-group-html5',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_user_details|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_farmer|user|user|form';
  $field_group->group_name = 'group_user_farmer';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_details';
  $field_group->data = array(
    'label' => 'Farmer',
    'weight' => '10',
    'children' => array(
      0 => 'field_user_spec_type',
      1 => 'field_user_spec_type_other',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Farmer',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'element' => 'span',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_user_farmer|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_forester|user|user|form';
  $field_group->group_name = 'group_user_forester';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_details';
  $field_group->data = array(
    'label' => 'Forester',
    'weight' => '14',
    'children' => array(
      0 => 'field_user_spec_forest_type',
      1 => 'field_user_spec_forest_utilizati',
      2 => 'field_user_spec_forester_type',
      3 => 'field_user_spec_forest_other',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Forester',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-user-forester field-group-tabs',
        'description' => '',
        'element' => 'div',
        'attributes' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_user_forester|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_land_owner|user|user|form';
  $field_group->group_name = 'group_user_land_owner';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_details';
  $field_group->data = array(
    'label' => 'Land owner',
    'weight' => '11',
    'children' => array(
      0 => 'field_user_spec_land_type',
      1 => 'field_user_spec_land_type_other',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Land owner ',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_user_land_owner|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_main|user|user|form';
  $field_group->group_name = 'group_user_main';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'User\'s main info',
    'weight' => '0',
    'children' => array(
      0 => 'field_firstname',
      1 => 'field_lastname',
      2 => 'field_user_gender',
      3 => 'account',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-user-main field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_user_main|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_other_info|user|user|form';
  $field_group->group_name = 'group_user_other_info';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Other info',
    'weight' => '4',
    'children' => array(
      0 => 'og_user_node',
      1 => 'field_user_cv',
      2 => 'field_user_featured_internal_db',
      3 => 'field_user_language_spoken',
      4 => 'field_user_picture',
      5 => 'field_core_additional_info',
      6 => 'field_core_specify_language',
      7 => 'timezone',
      8 => 'contact',
      9 => 'locale',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-user-other-info field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_user_other_info|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_press|user|user|form';
  $field_group->group_name = 'group_user_press';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_details';
  $field_group->data = array(
    'label' => 'Press',
    'weight' => '18',
    'children' => array(
      0 => 'field_user_spec_media_type',
      1 => 'field_user_specify_media',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_user_press|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_research_repres|user|user|form';
  $field_group->group_name = 'group_user_research_repres';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_details';
  $field_group->data = array(
    'label' => 'Position in the organization and Sector working in hidden fields',
    'weight' => '17',
    'children' => array(
      0 => 'field_user_spec_position',
      1 => 'field_user_spec_sector',
      2 => 'field_user_spec_sector_other',
      3 => 'field_user_position_civil',
      4 => 'field_user_position_industry',
      5 => 'field_user_position_rep',
      6 => 'field_user_position_researcher',
      7 => 'field_user_position_retailer',
      8 => 'field_user_position_whole',
      9 => 'field_user_sector_retailer',
      10 => 'field_user_sector_whole',
      11 => 'field_user_specify_ret',
      12 => 'field_user_specify_whole',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Position in the organization and Sector working in hidden fields',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-user-position-sector field-group-tabs',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_user_research_repres|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_tags|user|user|form';
  $field_group->group_name = 'group_user_tags';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'User\'s tags',
    'weight' => '2',
    'children' => array(
      0 => 'field_core_keywords',
      1 => 'field_user_involved',
      2 => 'field_core_agricultural_sectors',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-user-tags field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_user_tags|user|user|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Additional information');
  t('Advisor');
  t('Civil servant');
  t('Community');
  t('Content');
  t('Farmer');
  t('Forester');
  t('Images');
  t('Land owner');
  t('Metadata');
  t('Other info');
  t('Position in the organization and Sector working in hidden fields');
  t('Press');
  t('Sector Working In hidden fields');
  t('Stakeholders');
  t('User\'s main info');
  t('User\'s tags');
  t('User\'s type details');

  return $field_groups;
}
