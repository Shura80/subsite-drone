<?php

/**
 * @file
 * enrd_publications.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function enrd_publications_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|publication_ehd|enrd_nrn_toolkit_resource';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'publication_ehd';
  $ds_fieldsetting->view_mode = 'enrd_nrn_toolkit_resource';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => 'media-heading',
        'ft' => array(),
      ),
    ),
    'field_enrd_nrn_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Type',
        ),
      ),
    ),
    'field_enrd_nrn_title' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|publication_ehd|enrd_nrn_toolkit_resource'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|publication_ehd|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'publication_ehd';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => 'media-heading',
        'ft' => array(),
      ),
    ),
  );
  $export['node|publication_ehd|search_result'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|publication|enrd_nrn_toolkit_resource';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'publication';
  $ds_fieldsetting->view_mode = 'enrd_nrn_toolkit_resource';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => 'media-heading',
        'ft' => array(),
      ),
    ),
    'field_enrd_nrn_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Type',
        ),
      ),
    ),
    'field_enrd_nrn_title' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|publication|enrd_nrn_toolkit_resource'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|publication|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'publication';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
  );
  $export['node|publication|search_result'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function enrd_publications_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|publication_ehd|enrd_nrn_toolkit_resource';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'publication_ehd';
  $ds_layout->view_mode = 'enrd_nrn_toolkit_resource';
  $ds_layout->layout = 'nrn_page';
  $ds_layout->settings = array(
    'regions' => array(
      'headline' => array(
        0 => 'title',
      ),
      'nrn_title' => array(
        1 => 'field_enrd_nrn_title',
      ),
      'nrn_description' => array(
        2 => 'field_enrd_nrn_alter_description',
      ),
      'abstract' => array(
        3 => 'field_enrd_publ_ehd_abstract',
      ),
      'meta' => array(
        4 => 'field_enrd_nrn_type',
        5 => 'field_enrd_nrn_date',
        6 => 'group_nrn_toolkit_fieldset',
      ),
    ),
    'fields' => array(
      'title' => 'headline',
      'field_enrd_nrn_title' => 'nrn_title',
      'field_enrd_nrn_alter_description' => 'nrn_description',
      'field_enrd_publ_ehd_abstract' => 'abstract',
      'field_enrd_nrn_type' => 'meta',
      'field_enrd_nrn_date' => 'meta',
      'group_nrn_toolkit_fieldset' => 'meta',
    ),
    'classes' => array(),
    'wrappers' => array(
      'thumb' => 'div',
      'headline' => 'div',
      'abstract' => 'div',
      'meta' => 'div',
      'nrn_title' => 'div',
      'nrn_description' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|publication_ehd|enrd_nrn_toolkit_resource'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|publication_ehd|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'publication_ehd';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'publication_ehd_page';
  $ds_layout->settings = array(
    'regions' => array(
      'thumb' => array(
        0 => 'field_enrd_publ_ehd_title_image',
        1 => 'field_enrd_publ_ehd_public_date',
      ),
      'abstract' => array(
        2 => 'field_enrd_publ_ehd_description',
      ),
      'meta' => array(
        3 => 'field_enrd_publ_ehd_pages',
        4 => 'field_enrd_publ_ehd_file',
        5 => 'field_enrd_publ_ehd_related_docs',
        6 => 'field_enrd_publ_ehd_author',
        7 => 'field_enrd_publ_ehd_editor',
        8 => 'field_tax_country',
        9 => 'field_enrd_publ_ehd_rdp',
        10 => 'field_tags',
        11 => 'field_enrd_publ_ehd_content_type',
        12 => 'field_tax_languages',
        13 => 'field_enrd_publ_ehd_progr_period',
        14 => 'field_enrd_publ_ehd_eval_theme',
        15 => 'field_enrd_publ_ehd_eval_type',
        16 => 'field_enrd_publ_ehd_further_info',
        17 => 'field_enrd_publ_ehd_contact',
        18 => 'field_enrd_publ_ehd_last_updated',
        19 => 'field_enrd_publ_ehd_history',
      ),
    ),
    'fields' => array(
      'field_enrd_publ_ehd_title_image' => 'thumb',
      'field_enrd_publ_ehd_public_date' => 'thumb',
      'field_enrd_publ_ehd_description' => 'abstract',
      'field_enrd_publ_ehd_pages' => 'meta',
      'field_enrd_publ_ehd_file' => 'meta',
      'field_enrd_publ_ehd_related_docs' => 'meta',
      'field_enrd_publ_ehd_author' => 'meta',
      'field_enrd_publ_ehd_editor' => 'meta',
      'field_tax_country' => 'meta',
      'field_enrd_publ_ehd_rdp' => 'meta',
      'field_tags' => 'meta',
      'field_enrd_publ_ehd_content_type' => 'meta',
      'field_tax_languages' => 'meta',
      'field_enrd_publ_ehd_progr_period' => 'meta',
      'field_enrd_publ_ehd_eval_theme' => 'meta',
      'field_enrd_publ_ehd_eval_type' => 'meta',
      'field_enrd_publ_ehd_further_info' => 'meta',
      'field_enrd_publ_ehd_contact' => 'meta',
      'field_enrd_publ_ehd_last_updated' => 'meta',
      'field_enrd_publ_ehd_history' => 'meta',
    ),
    'classes' => array(),
    'wrappers' => array(
      'thumb' => 'div',
      'headline' => 'div',
      'abstract' => 'div',
      'meta' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|publication_ehd|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|publication_ehd|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'publication_ehd';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'publication_ehd_page';
  $ds_layout->settings = array(
    'regions' => array(
      'meta' => array(
        0 => 'field_enrd_publ_ehd_public_date',
        3 => 'field_enrd_publ_ehd_eval_type',
        4 => 'field_enrd_publ_ehd_author',
      ),
      'headline' => array(
        1 => 'title',
      ),
      'thumb' => array(
        2 => 'field_enrd_publ_ehd_title_image',
      ),
      'abstract' => array(
        5 => 'field_enrd_publ_ehd_abstract',
      ),
    ),
    'fields' => array(
      'field_enrd_publ_ehd_public_date' => 'meta',
      'title' => 'headline',
      'field_enrd_publ_ehd_title_image' => 'thumb',
      'field_enrd_publ_ehd_eval_type' => 'meta',
      'field_enrd_publ_ehd_author' => 'meta',
      'field_enrd_publ_ehd_abstract' => 'abstract',
    ),
    'classes' => array(),
    'wrappers' => array(
      'thumb' => 'div',
      'headline' => 'div',
      'abstract' => 'div',
      'meta' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|publication_ehd|search_result'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|publication|enrd_nrn_toolkit_resource';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'publication';
  $ds_layout->view_mode = 'enrd_nrn_toolkit_resource';
  $ds_layout->layout = 'nrn_page';
  $ds_layout->settings = array(
    'regions' => array(
      'nrn_description' => array(
        0 => 'field_enrd_nrn_alter_description',
      ),
      'nrn_title' => array(
        1 => 'field_enrd_nrn_title',
      ),
      'headline' => array(
        2 => 'title',
      ),
      'abstract' => array(
        3 => 'field_enrd_publication_desc',
      ),
      'meta' => array(
        4 => 'field_enrd_nrn_type',
        5 => 'field_enrd_nrn_date',
        6 => 'group_nrn_toolkit_fieldset',
      ),
    ),
    'fields' => array(
      'field_enrd_nrn_alter_description' => 'nrn_description',
      'field_enrd_nrn_title' => 'nrn_title',
      'title' => 'headline',
      'field_enrd_publication_desc' => 'abstract',
      'field_enrd_nrn_type' => 'meta',
      'field_enrd_nrn_date' => 'meta',
      'group_nrn_toolkit_fieldset' => 'meta',
    ),
    'classes' => array(),
    'wrappers' => array(
      'thumb' => 'div',
      'headline' => 'div',
      'abstract' => 'div',
      'meta' => 'div',
      'nrn_title' => 'div',
      'nrn_description' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|publication|enrd_nrn_toolkit_resource'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|publication|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'publication';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'publication_page';
  $ds_layout->settings = array(
    'regions' => array(
      'thumb' => array(
        0 => 'field_enrd_publication_image',
      ),
      'abstract' => array(
        1 => 'field_enrd_publication_desc',
      ),
      'meta' => array(
        2 => 'field_enrd_publication_date',
        3 => 'field_enrd_publications_pages',
        4 => 'field_enrd_publication_file',
        5 => 'field_enrd_publications_rel_docs',
        6 => 'field_enrd_publication_keywords',
        7 => 'field_enrd_publication_catal_num',
        8 => 'field_enrd_publication_link_book',
      ),
      'side' => array(
        10 => 'field_enrd_publication_type',
      ),
    ),
    'fields' => array(
      'field_enrd_publication_image' => 'thumb',
      'field_enrd_publication_desc' => 'abstract',
      'field_enrd_publication_date' => 'meta',
      'field_enrd_publications_pages' => 'meta',
      'field_enrd_publication_file' => 'meta',
      'field_enrd_publications_rel_docs' => 'meta',
      'field_enrd_publication_keywords' => 'meta',
      'field_enrd_publication_catal_num' => 'meta',
      'field_enrd_publication_link_book' => 'meta',
      'field_enrd_publication_type' => 'side',
    ),
    'classes' => array(),
    'wrappers' => array(
      'thumb' => 'div',
      'headline' => 'div',
      'abstract' => 'div',
      'meta' => 'div',
      'side' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|publication|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|publication|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'publication';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'publication_page';
  $ds_layout->settings = array(
    'regions' => array(
      'thumb' => array(
        0 => 'field_enrd_publication_image',
      ),
      'headline' => array(
        1 => 'title',
      ),
      'abstract' => array(
        2 => 'field_enrd_publication_desc',
      ),
      'meta' => array(
        3 => 'field_enrd_publication_file',
        4 => 'field_enrd_publication_date',
        5 => 'field_enrd_publication_keywords',
      ),
    ),
    'fields' => array(
      'field_enrd_publication_image' => 'thumb',
      'title' => 'headline',
      'field_enrd_publication_desc' => 'abstract',
      'field_enrd_publication_file' => 'meta',
      'field_enrd_publication_date' => 'meta',
      'field_enrd_publication_keywords' => 'meta',
    ),
    'classes' => array(),
    'wrappers' => array(
      'thumb' => 'div',
      'headline' => 'div',
      'abstract' => 'div',
      'meta' => 'div',
      'side' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|publication|search_result'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function enrd_publications_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'enrd_publication_type_details';
  $ds_view_mode->label = 'Publication type details';
  $ds_view_mode->entities = array(
    'taxonomy_term' => 'taxonomy_term',
  );
  $export['enrd_publication_type_details'] = $ds_view_mode;

  return $export;
}
