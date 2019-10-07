<?php

/**
 * @file
 * agri_pages.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function agri_pages_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|page|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'page';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_agri_pages_is_focus_group',
        2 => 'body',
        3 => 'field_core_keywords',
        4 => 'field_core_geographical_area',
        5 => 'field_core_attachments',
        6 => 'group_images',
        7 => 'field_page_related',
        8 => 'language',
        9 => 'group_page_content',
        10 => 'group_agri_stakeholders',
        11 => 'group_page_metadata',
        12 => 'group_page_community',
        13 => 'field_core_stakeholders',
        14 => 'twitter',
        15 => 'field_image_top',
        16 => 'field_stakeholders_short_title',
        17 => 'xmlsitemap',
        18 => 'field_image_left',
        19 => 'path',
        20 => 'field_stakeholders_short_weight',
        21 => 'field_image_right',
        22 => 'redirect',
        24 => 'field_core_bulk_image_upload',
        25 => 'og_group_ref',
        26 => 'group_content_access',
      ),
      'hidden' => array(
        23 => 'flag',
        27 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_agri_pages_is_focus_group' => 'ds_content',
      'body' => 'ds_content',
      'field_core_keywords' => 'ds_content',
      'field_core_geographical_area' => 'ds_content',
      'field_core_attachments' => 'ds_content',
      'group_images' => 'ds_content',
      'field_page_related' => 'ds_content',
      'language' => 'ds_content',
      'group_page_content' => 'ds_content',
      'group_agri_stakeholders' => 'ds_content',
      'group_page_metadata' => 'ds_content',
      'group_page_community' => 'ds_content',
      'field_core_stakeholders' => 'ds_content',
      'twitter' => 'ds_content',
      'field_image_top' => 'ds_content',
      'field_stakeholders_short_title' => 'ds_content',
      'xmlsitemap' => 'ds_content',
      'field_image_left' => 'ds_content',
      'path' => 'ds_content',
      'field_stakeholders_short_weight' => 'ds_content',
      'field_image_right' => 'ds_content',
      'redirect' => 'ds_content',
      'flag' => 'hidden',
      'field_core_bulk_image_upload' => 'ds_content',
      'og_group_ref' => 'ds_content',
      'group_content_access' => 'ds_content',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|page|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|page|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'page';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_3col_stacked_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_image_top',
      ),
      'left' => array(
        1 => 'field_image_left',
      ),
      'middle' => array(
        2 => 'body',
        3 => 'webform',
        4 => 'field_page_related',
        5 => 'field_core_bulk_image_upload',
        6 => 'field_core_attachments',
      ),
      'right' => array(
        7 => 'field_image_right',
      ),
      'footer' => array(
        8 => 'flag_agri_digitization_toolbox',
      ),
    ),
    'fields' => array(
      'field_image_top' => 'header',
      'field_image_left' => 'left',
      'body' => 'middle',
      'webform' => 'middle',
      'field_page_related' => 'middle',
      'field_core_bulk_image_upload' => 'middle',
      'field_core_attachments' => 'middle',
      'field_image_right' => 'right',
      'flag_agri_digitization_toolbox' => 'footer',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'middle' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|page|full'] = $ds_layout;

  return $export;
}
