<?php

/**
 * @file
 * agri_digitization_toolbox.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function agri_digitization_toolbox_default_rules_configuration() {
  $items = array();
  $items['rules_agri_digitization_toolbox_add_item'] = entity_import('rules_config', '{ "rules_agri_digitization_toolbox_add_item" : {
      "LABEL" : "Add to Digitisation toolbox",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "AGRI Digitisation Toolbox" ],
      "REQUIRES" : [ "flag" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "add_digitization_item" : { "label" : "Flag item as Digitisation toolbox item", "type" : "node" } },
      "IF" : [
        { "NOT flag_flagged_node" : {
            "flag" : "agri_digitization_toolbox",
            "node" : [ "add-digitization-item" ],
            "flagging_user" : [ "site:current-user" ]
          }
        }
      ],
      "DO" : [
        { "flag_flagnode" : {
            "flag" : "agri_digitization_toolbox",
            "node" : [ "add-digitization-item" ],
            "flagging_user" : [ "site:current-user" ],
            "permission_check" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_agri_digitization_toolbox_remove_item'] = entity_import('rules_config', '{ "rules_agri_digitization_toolbox_remove_item" : {
      "LABEL" : "Remove from Digitisation toolbox",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "AGRI Digitisation Toolbox" ],
      "REQUIRES" : [ "flag" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "remove_digitization_item" : { "label" : "Unflag item as Digitisation toolbox item", "type" : "node" } },
      "IF" : [
        { "flag_flagged_node" : {
            "flag" : "agri_digitization_toolbox",
            "node" : [ "remove-digitization-item" ],
            "flagging_user" : [ "site:current-user" ]
          }
        }
      ],
      "DO" : [
        { "flag_unflagnode" : {
            "flag" : "agri_digitization_toolbox",
            "node" : [ "remove-digitization-item" ],
            "flagging_user" : [ "site:current-user" ],
            "permission_check" : "0"
          }
        }
      ]
    }
  }');
  return $items;
}
