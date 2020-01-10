<?php

/**
 * @file
 * enrd_notifications.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function enrd_notifications_default_rules_configuration() {
  $items = array();
  $items['rules_enrd_flag_read_unread'] = entity_import('rules_config', '{ "rules_enrd_flag_read_unread" : {
      "LABEL" : "Flag Read\\/Unread",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD Notifications" ],
      "REQUIRES" : [ "flag" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "flag_read_unread" : { "label" : "Flag Read\\/Unread", "type" : "message" } },
      "ACTION SET" : [
        { "flag_flagmessage" : {
            "flag" : "enrd_message_read_unread",
            "message" : [ "flag-read-unread" ],
            "flagging_user" : [ "site:current-user" ],
            "permission_check" : "1"
          }
        }
      ]
    }
  }');
  return $items;
}
