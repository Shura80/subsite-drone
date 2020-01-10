<?php

/**
 * @file
 * enrd_nrnp_invite.features.inc
 */

/**
 * Implements hook_views_api().
 */
function enrd_nrnp_invite_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_invite_type().
 */
function enrd_nrnp_invite_default_invite_type() {
  $items = array();
  $items['enrd_nrnp_invite'] = entity_import('invite_type', '{
    "type" : "enrd_nrnp_invite",
    "label" : "ENRD NRN Profiles invitation",
    "weight" : 0,
    "argument_keys" : [],
    "argument" : [],
    "invite_sending_controller" : { "enrd_nrnp_invite" : "enrd_nrnp_invite" },
    "description" : "Email invitation to edit the NRN profile page",
    "data" : [],
    "entity_type" : "invite_type",
    "rdf_mapping" : []
  }');
  return $items;
}
