<?php

/**
 * @file
 * enrd_country_pages.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function enrd_country_pages_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'field_collection_item|field_enrd_rdp_info_region|full';
  $ds_fieldsetting->entity_type = 'field_collection_item';
  $ds_fieldsetting->bundle = 'field_enrd_rdp_info_region';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'field_enrd_rdp_info_region_docs' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'div',
          'lb-cl' => 'field-label',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'div',
          'lbw-cl' => 'field field-name-field-enrd-rdp-info-region-docs field-type-text-with-summary field-label-above',
        ),
      ),
    ),
  );
  $export['field_collection_item|field_enrd_rdp_info_region|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|rdp_information|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'rdp_information';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'field_enrd_rdp_info_partner_docs' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'div',
          'lb-cl' => 'field-label',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'div',
          'lbw-cl' => 'field field-name-field-enrd-rdp-info-partner-docs field-type-text-with-summary field-label-above',
        ),
      ),
    ),
    'field_enrd_rdp_info_rdp_docs' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'div',
          'lb-cl' => 'field-label',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'div',
          'lbw-cl' => 'field field-name-field-enrd-rdp-info-rdp-docs field-type-text-with-summary field-label-above',
        ),
      ),
    ),
    'field_enrd_rdp_info_partner_agr' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'div',
          'lb-cl' => 'field-label',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'div',
          'lbw-cl' => 'field field-name-field-enrd-rdp-info-partner-agr field-type-text-with-summary field-label-above',
        ),
      ),
    ),
  );
  $export['node|rdp_information|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function enrd_country_pages_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_enrd_rdp_info_region|full';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_enrd_rdp_info_region';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'rdp_information_region';
  $ds_layout->settings = array(
    'regions' => array(
      'headline' => array(
        0 => 'field_enrd_rdp_info_region_name',
      ),
      'introductory_text' => array(
        1 => 'field_enrd_rdp_info_region_intro',
      ),
      'rdp_documents' => array(
        2 => 'field_enrd_rdp_info_region_docs',
      ),
      'nrn_information' => array(
        3 => 'field_enrd_rdp_info_region_nrn',
      ),
      'nrn_image' => array(
        4 => 'field_enrd_rdp_info_region_image',
      ),
      'managing_authority' => array(
        5 => 'field_enrd_rdp_info_region_auth',
      ),
      'paying_agency' => array(
        6 => 'field_enrd_rdp_info_region_pay',
      ),
    ),
    'fields' => array(
      'field_enrd_rdp_info_region_name' => 'headline',
      'field_enrd_rdp_info_region_intro' => 'introductory_text',
      'field_enrd_rdp_info_region_docs' => 'rdp_documents',
      'field_enrd_rdp_info_region_nrn' => 'nrn_information',
      'field_enrd_rdp_info_region_image' => 'nrn_image',
      'field_enrd_rdp_info_region_auth' => 'managing_authority',
      'field_enrd_rdp_info_region_pay' => 'paying_agency',
    ),
    'classes' => array(),
    'wrappers' => array(
      'headline' => 'div',
      'introductory_text' => 'div',
      'rdp_documents' => 'div',
      'nrn_information' => 'div',
      'nrn_image' => 'div',
      'managing_authority' => 'div',
      'paying_agency' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['field_collection_item|field_enrd_rdp_info_region|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|rdp_information|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'rdp_information';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'rdp_information_page';
  $ds_layout->settings = array(
    'regions' => array(
      'headline' => array(
        0 => 'field_enrd_rdp_info_country',
      ),
      'introductory_text' => array(
        1 => 'field_enrd_rdp_info_intro_text',
      ),
      'partnership_agreement' => array(
        2 => 'field_enrd_rdp_info_partner_agr',
      ),
      'rdp_documents' => array(
        3 => 'field_enrd_rdp_info_rdp_docs',
      ),
      'partnership_agreement_docs' => array(
        4 => 'field_enrd_rdp_info_partner_docs',
      ),
      'nrn_information' => array(
        5 => 'field_enrd_rdp_info_nrn_info',
      ),
      'nrn_image' => array(
        6 => 'field_rdp_info_nrn_image',
      ),
      'managing_authority' => array(
        7 => 'field_enrd_rdp_info_nation_auth',
      ),
      'paying_agency' => array(
        8 => 'field_enrd_rdp_info_nat_pay_agen',
      ),
      'region' => array(
        9 => 'field_enrd_rdp_info_region',
      ),
      'main' => array(
        10 => 'body',
      ),
    ),
    'fields' => array(
      'field_enrd_rdp_info_country' => 'headline',
      'field_enrd_rdp_info_intro_text' => 'introductory_text',
      'field_enrd_rdp_info_partner_agr' => 'partnership_agreement',
      'field_enrd_rdp_info_rdp_docs' => 'rdp_documents',
      'field_enrd_rdp_info_partner_docs' => 'partnership_agreement_docs',
      'field_enrd_rdp_info_nrn_info' => 'nrn_information',
      'field_rdp_info_nrn_image' => 'nrn_image',
      'field_enrd_rdp_info_nation_auth' => 'managing_authority',
      'field_enrd_rdp_info_nat_pay_agen' => 'paying_agency',
      'field_enrd_rdp_info_region' => 'region',
      'body' => 'main',
    ),
    'classes' => array(),
    'wrappers' => array(
      'headline' => 'div',
      'introductory_text' => 'div',
      'partnership_agreement' => 'div',
      'rdp_documents' => 'div',
      'partnership_agreement_docs' => 'div',
      'nrn_information' => 'div',
      'nrn_image' => 'div',
      'managing_authority' => 'div',
      'paying_agency' => 'div',
      'region' => 'div',
      'main' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|rdp_information|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|rdp_information|print';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'rdp_information';
  $ds_layout->view_mode = 'print';
  $ds_layout->layout = 'rdp_information_page';
  $ds_layout->settings = array(
    'regions' => array(
      'headline' => array(
        0 => 'field_enrd_rdp_info_country',
      ),
      'introductory_text' => array(
        1 => 'field_enrd_rdp_info_intro_text',
        2 => 'body',
      ),
      'rdp_documents' => array(
        3 => 'field_enrd_rdp_info_rdp_docs',
      ),
      'partnership_agreement_docs' => array(
        4 => 'field_enrd_rdp_info_partner_docs',
      ),
      'nrn_information' => array(
        5 => 'field_enrd_rdp_info_nrn_info',
      ),
      'nrn_image' => array(
        6 => 'field_rdp_info_nrn_image',
      ),
      'managing_authority' => array(
        7 => 'field_enrd_rdp_info_nation_auth',
      ),
      'paying_agency' => array(
        8 => 'field_enrd_rdp_info_nat_pay_agen',
      ),
      'region' => array(
        9 => 'field_enrd_rdp_info_region',
      ),
    ),
    'fields' => array(
      'field_enrd_rdp_info_country' => 'headline',
      'field_enrd_rdp_info_intro_text' => 'introductory_text',
      'body' => 'introductory_text',
      'field_enrd_rdp_info_rdp_docs' => 'rdp_documents',
      'field_enrd_rdp_info_partner_docs' => 'partnership_agreement_docs',
      'field_enrd_rdp_info_nrn_info' => 'nrn_information',
      'field_rdp_info_nrn_image' => 'nrn_image',
      'field_enrd_rdp_info_nation_auth' => 'managing_authority',
      'field_enrd_rdp_info_nat_pay_agen' => 'paying_agency',
      'field_enrd_rdp_info_region' => 'region',
    ),
    'classes' => array(),
    'wrappers' => array(
      'headline' => 'div',
      'introductory_text' => 'div',
      'rdp_documents' => 'div',
      'partnership_agreement_docs' => 'div',
      'nrn_information' => 'div',
      'nrn_image' => 'div',
      'managing_authority' => 'div',
      'paying_agency' => 'div',
      'region' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|rdp_information|print'] = $ds_layout;

  return $export;
}
