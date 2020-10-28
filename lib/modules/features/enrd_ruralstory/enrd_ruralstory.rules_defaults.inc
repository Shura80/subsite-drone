<?php

/**
 * @file
 * enrd_ruralstory.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function enrd_ruralstory_default_rules_configuration() {
  $items = array();
  $items['rules_enrd_ruralstory_notify_after_submission'] = entity_import('rules_config', '{ "rules_enrd_ruralstory_notify_after_submission" : {
      "LABEL" : "ENRD Rural Story: send e-mail after Submission",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD Rural Story Form" ],
      "REQUIRES" : [ "rules", "enrd_sfr" ],
      "ON" : { "enrd_sfr_finalize" : [] },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "enrd-sfr" ], "type" : "enrd_sfr" } },
        { "entity_is_of_bundle" : {
            "entity" : [ "enrd-sfr" ],
            "type" : "enrd_sfr",
            "bundle" : { "value" : { "enrd_ruralstory" : "enrd_ruralstory" } }
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "rural-stories@enrd.eu",
            "subject" : "New Rural Story submission #[enrd-sfr:sfrid]",
            "message" : "The new Rural Story #[enrd-sfr:sfrid] has been submitted:\\r\\n\\r\\nSubject: [enrd-sfr:field-enrd-ruralstory-subject]\\r\\nName: [enrd-sfr:field-enrd-ruralstory-name]\\r\\nSurname: [enrd-sfr:field-enrd-ruralstory-surname]\\r\\n\\r\\nYou can check further information on the \\u201cShare Your Story\\u201d submission  page: [enrd-sfr:url]",
            "from" : "[site:mail]",
            "language" : [ "" ]
          }
        },
        { "mail" : {
            "to" : "[enrd-sfr:field-enrd-ruralstory-email]",
            "subject" : "Rural Story submission on ENRD website",
            "message" : "Dear [enrd-sfr:field-enrd-ruralstory-name] [enrd-sfr:field-enrd-ruralstory-surname],\\r\\n\\r\\nYou have succesfully submitted the following information on the ENRD website:\\r\\n\\r\\n[enrd-sfr:view-mode:enrd_sfr_full_email]\\r\\n\\r\\nBest regards,\\r\\nThe ENRD Contact Point team",
            "from" : "rural-stories@enrd.eu",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_enrd_ruralstory_remove_status'] = entity_import('rules_config', '{ "rules_enrd_ruralstory_remove_status" : {
      "LABEL" : "ENRD Ruralstory Remove Status",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD Rural Story Form" ],
      "REQUIRES" : [ "flag" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "remove_status" : { "label" : "Remove status", "type" : "enrd_sfr" } },
      "ACTION SET" : [
        { "flag_unflagenrd_sfr" : {
            "flag" : "enrd_ruralstory_status",
            "enrd_sfr" : [ "remove-status" ],
            "flagging_user" : [ "site:current-user" ],
            "permission_check" : "1"
          }
        }
      ]
    }
  }');
  return $items;
}
