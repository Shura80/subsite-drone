<?php

/**
 * @file
 * enrd_lag_invite.features.inc
 */

/**
 * Implements hook_views_api().
 */
function enrd_lag_invite_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_invite_type().
 */
function enrd_lag_invite_default_invite_type() {
  $items = array();
  $items['enrd_lag_invite'] = entity_import('invite_type', '{
    "type" : "enrd_lag_invite",
    "label" : "ENRD LAG invite",
    "weight" : 0,
    "argument_keys" : [],
    "argument" : [],
    "invite_sending_controller" : { "enrd_lag_invite" : "enrd_lag_invite" },
    "description" : "Email invitation to join lag contacts",
    "data" : [],
    "entity_type" : "invite_type",
    "rdf_mapping" : []
  }');
  return $items;
}
