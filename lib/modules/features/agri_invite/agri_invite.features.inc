<?php

/**
 * @file
 * agri_invite.features.inc
 */

/**
 * Implements hook_views_api().
 */
function agri_invite_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_invite_type().
 */
function agri_invite_default_invite_type() {
  $items = array();
  $items['agri_invite'] = entity_import('invite_type', '{
    "type" : "agri_invite",
    "label" : "AGRI invite",
    "weight" : 0,
    "argument_keys" : [],
    "argument" : [],
    "invite_sending_controller" : { "agri_invite" : "agri_invite" },
    "description" : "Email invitation to join Collaborative Area",
    "data" : [],
    "rdf_mapping" : []
  }');
  return $items;
}
