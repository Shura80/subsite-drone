<?php

/**
 * @file
 * enrd_mastermind.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function enrd_mastermind_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'enrd_bean';
  $bean_type->label = 'ENRD bean';
  $bean_type->options = '';
  $bean_type->description = 'Provides the ENRD block type.';
  $export['enrd_bean'] = $bean_type;

  return $export;
}
