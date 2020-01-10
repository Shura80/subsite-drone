<?php

/**
 * @file
 * enrd_sfr_pub.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enrd_sfr_pub_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function enrd_sfr_pub_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_enrd_sfr_type().
 */
function enrd_sfr_pub_default_enrd_sfr_type() {
  $items = array();
  $items['enrd_sfr_pub_contact_cp'] = entity_import('enrd_sfr_type', '{
    "name" : "enrd_sfr_pub_contact_cp",
    "label" : "CP Contact",
    "description" : "CP Publications contact requests.",
    "weight" : 0,
    "entity_type" : "enrd_sfr_type",
    "rdf_mapping" : []
  }');
  $items['enrd_sfr_pub_contact_ehd'] = entity_import('enrd_sfr_type', '{
    "name" : "enrd_sfr_pub_contact_ehd",
    "label" : "EHD Contact",
    "description" : "Evaluation Helpdesk\\u0027s Publications contact requests.",
    "weight" : 0,
    "entity_type" : "enrd_sfr_type",
    "rdf_mapping" : []
  }');
  $items['enrd_sfr_pub_subscribe_cp'] = entity_import('enrd_sfr_type', '{
    "name" : "enrd_sfr_pub_subscribe_cp",
    "label" : "CP Subscription",
    "description" : "CP Publications subscribe requests.",
    "weight" : 0,
    "entity_type" : "enrd_sfr_type",
    "rdf_mapping" : []
  }');
  $items['enrd_sfr_pub_subscribe_ehd'] = entity_import('enrd_sfr_type', '{
    "name" : "enrd_sfr_pub_subscribe_ehd",
    "label" : "EHD Subscription",
    "description" : "Evaluation Helpdesk\\u0027s Publications subscribe requests.",
    "weight" : 0,
    "entity_type" : "enrd_sfr_type",
    "rdf_mapping" : []
  }');
  return $items;
}
