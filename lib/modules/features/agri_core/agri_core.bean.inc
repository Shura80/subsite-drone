<?php

/**
 * @file
 * agri_core.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function agri_core_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'agri_static_block';
  $bean_type->label = 'AGRI static block';
  $bean_type->options = '';
  $bean_type->description = 'Provides the AGRI Static block to link an internal site page or an external site.';
  $export['agri_static_block'] = $bean_type;

  return $export;
}
