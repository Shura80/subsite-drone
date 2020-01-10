<?php

/**
 * @file
 * enrd_sfr_pub.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function enrd_sfr_pub_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_field_collection_item__field_enrd_sfr_pub_subcp_type';
  $strongarm->value = array(
    'view_modes' => array(
      'type_of_publication_name' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_field_collection_item__field_enrd_sfr_pub_subcp_type'] = $strongarm;

  return $export;
}
