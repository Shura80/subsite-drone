<?php

/**
 * @file
 * agri_core.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function agri_core_default_rules_configuration() {
  $items = array();
  $items['agri_core_activate_selected_users'] = entity_import('rules_config', '{ "agri_core_activate_selected_users" : {
      "LABEL" : "Activate selected users",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "AGRI Core" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "user" : { "label" : "User", "type" : "user" } },
      "ACTION SET" : [ { "user_unblock" : { "account" : [ "user" ] } } ]
    }
  }');
  return $items;
}
