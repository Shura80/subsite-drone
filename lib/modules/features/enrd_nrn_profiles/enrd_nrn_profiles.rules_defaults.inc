<?php

/**
 * @file
 * enrd_nrn_profiles.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function enrd_nrn_profiles_default_rules_configuration() {
  $items = array();
  $items['rules_enrd_nrn_profile_draft_ready_published'] = entity_import('rules_config', '{ "rules_enrd_nrn_profile_draft_ready_published" : {
      "LABEL" : "ENRD NRN Profile: Draft to Ready to be published",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD NRN Profiles" ],
      "REQUIRES" : [ "rules", "workbench_moderation", "enrd_nrn_profiles" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "nrn_profile" : "nrn_profile" } }
          }
        },
        { "content_is_using_workbench_moderation" : { "node" : [ "node" ] } },
        { "AND" : [
            { "NOT contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "ready_to_be_published" } },
            { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "ready_to_be_published" } }
          ]
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "nrn-profiles@enrd.eu",
            "subject" : "NRN Profile update ready for publication",
            "message" : "Dear ENRD Admin,\\r\\n\\r\\nThe following NRN Profile has been submitted for publication and is ready for your review: \\u0022[node:title_field]\\u0022.\\r\\n\\r\\nYou can see the updated NRN Profile by clicking this link: [node:url].\\r\\n\\r\\nThis is the log message:\\r\\n[node:log]",
            "language" : [ "" ]
          }
        },
        { "enrd_nrn_profiles_nrn_editors_list" : {
            "USING" : { "node" : [ "node" ] },
            "PROVIDE" : { "nrn_editor_users" : { "nrn_editor_users" : "List of NRN Editor users" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "nrn-editor-users" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "mail" : {
                  "to" : "[list-item:mail]",
                  "subject" : "ENRD NRN Profiles \\u2013 NRN Profile sent for publication",
                  "message" : "Dear [list-item:name],\\r\\n\\r\\nThe latest update of the NRN profile: \\u0022[node:title_field]\\u0022 has been submitted for publication. This draft has been sent for ENRD CP\\u0027s approval and cannot be modified until its assessment by the ENRD CP.\\r\\n\\r\\nIf necessary, you can contact the ENRD CP at: nrn-profiles@enrd.eu.\\r\\n\\r\\nBest Regards,\\r\\nThe ENRD Contact Point team",
                  "language" : [ "" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_enrd_nrn_profile_ready_to_be_published_draft'] = entity_import('rules_config', '{ "rules_enrd_nrn_profile_ready_to_be_published_draft" : {
      "LABEL" : "ENRD NRN Profile: Ready to be published to Draft",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD NRN Profiles" ],
      "REQUIRES" : [ "rules", "workbench_moderation", "enrd_nrn_profiles" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "nrn_profile" : "nrn_profile" } }
          }
        },
        { "AND" : [
            { "content_is_using_workbench_moderation" : { "node" : [ "node" ] } },
            { "contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "ready_to_be_published" } },
            { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "draft" } }
          ]
        }
      ],
      "DO" : [
        { "enrd_nrn_profiles_nrn_editors_list" : {
            "USING" : { "node" : [ "node" ] },
            "PROVIDE" : { "nrn_editor_users" : { "nrn_editor_users" : "List of NRN Editor users" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "nrn-editor-users" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "mail" : {
                  "to" : "[list-item:mail]",
                  "subject" : "ENRD NRN Profile \\u2013 NRN Profile rejected",
                  "message" : "Dear [list-item:name],\\r\\n\\r\\nThe latest update of the NRN Profile: \\u0022[node:title_field]\\u0022, submitted for publication, has been rejected by the ENRD CP and has not been published online.\\r\\n\\r\\nThe reason of Rejection is: [node:revision-log]\\r\\nReview the rejected draft profile update by clicking this link: [node:url].\\r\\n\\r\\nIf necessary, you can contact the ENRD CP at nrn-profiles@enrd.eu.\\r\\n\\r\\nBest Regards,\\r\\nThe ENRD Contact Point team",
                  "language" : [ "" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_enrd_nrn_profile_ready_to_be_published_published'] = entity_import('rules_config', '{ "rules_enrd_nrn_profile_ready_to_be_published_published" : {
      "LABEL" : "ENRD NRN Profile: Ready to be published to Published",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD NRN Profiles" ],
      "REQUIRES" : [ "rules", "workbench_moderation", "enrd_nrn_profiles" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "nrn_profile" : "nrn_profile" } }
          }
        },
        { "AND" : [
            { "content_is_using_workbench_moderation" : { "node" : [ "node" ] } },
            { "contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "ready_to_be_published" } },
            { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "published" } }
          ]
        }
      ],
      "DO" : [
        { "enrd_nrn_profiles_nrn_editors_list" : {
            "USING" : { "node" : [ "node" ] },
            "PROVIDE" : { "nrn_editor_users" : { "nrn_editor_users" : "List of NRN Editor users" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "nrn-editor-users" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "mail" : {
                  "to" : "[list-item:mail]",
                  "subject" : "ENRD NRN Profiles \\u2013 NRN Profile published",
                  "message" : "Dear [list-item:name],\\r\\n\\r\\nThe latest update of your NRN Profile: \\u0022[node:title_field]\\u0022 has been published and it is now available online.\\r\\n\\r\\nYou can see your updated NRN Profile by clicking this link: [node:url].\\r\\n\\r\\nBest Regards,\\r\\nThe ENRD Contact Point team",
                  "language" : [ "" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  return $items;
}
