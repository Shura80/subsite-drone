<?php

/**
 * @file
 * enrd_lag_dashboard.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function enrd_lag_dashboard_default_rules_configuration() {
  $items = array();
  $items['enrd_coop_offer_set_message_after_ready_to_be_published'] = entity_import('rules_config', '{ "enrd_coop_offer_set_message_after_ready_to_be_published" : {
      "LABEL" : "ENRD Coop Offers Set Message after Ready to be published",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD LAG DASHBOARD, ENRD COOPERATION OFFER" ],
      "REQUIRES" : [ "rules", "workbench_moderation", "og" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "cooperation_offer" : "cooperation_offer" } }
          }
        },
        { "AND" : [
            { "content_is_using_workbench_moderation" : { "node" : [ "node" ] } },
            { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "ready_to_be_published" } }
          ]
        },
        { "OR" : [
            { "og_user_has_role" : {
                "account" : [ "site:current-user" ],
                "group" : [ "node:og-lag-group-ref" ],
                "roles" : { "value" : { "LAG Manager" : "LAG Manager" } }
              }
            },
            { "og_user_has_role" : {
                "account" : [ "site:current-user" ],
                "group" : [ "node:og-lag-group-ref" ],
                "roles" : { "value" : { "LAG Contact" : "LAG Contact" } }
              }
            }
          ]
        }
      ],
      "DO" : [
        { "drupal_message" : {
            "message" : "This update has been sent to the webmaster for publication online.",
            "repeat" : "0"
          }
        }
      ]
    }
  }');
  $items['enrd_lag_set_message_after_ready_to_be_published'] = entity_import('rules_config', '{ "enrd_lag_set_message_after_ready_to_be_published" : {
      "LABEL" : "ENRD LAG Set Message after Ready to be published",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD LAG DASHBOARD, ENRD LAG DATABASE" ],
      "REQUIRES" : [ "rules", "workbench_moderation", "og" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "lag" : "lag" } } } },
        { "AND" : [
            { "content_is_using_workbench_moderation" : { "node" : [ "node" ] } },
            { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "ready_to_be_published" } }
          ]
        },
        { "OR" : [
            { "og_user_has_role" : {
                "account" : [ "site:current-user" ],
                "group" : [ "node" ],
                "roles" : { "value" : { "LAG Manager" : "LAG Manager" } }
              }
            },
            { "og_user_has_role" : {
                "account" : [ "site:current-user" ],
                "group" : [ "node" ],
                "roles" : { "value" : { "LAG Contact" : "LAG Contact" } }
              }
            },
            { "og_user_has_role" : {
                "account" : [ "site:current-user" ],
                "group" : [ "node:og-group-ref:0" ],
                "roles" : { "value" : { "National manager" : "National manager" } }
              }
            }
          ]
        }
      ],
      "DO" : [
        { "drupal_message" : {
            "message" : "This update has been sent to the webmaster for publication online.",
            "repeat" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_enrd_lag_dashboard_add_new_national_manager'] = entity_import('rules_config', '{ "rules_enrd_lag_dashboard_add_new_national_manager" : {
      "LABEL" : "ENRD LAG Dashboard: send e-mail to newly added National manager",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD LAG DASHBOARD" ],
      "REQUIRES" : [ "rules" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "national_manager" : { "label" : "National manager", "type" : "user" } },
      "ACTION SET" : [
        { "mail" : {
            "to" : "[national-manager:mail]",
            "subject" : "Thank you for joining the ENRD LAG Database!",
            "message" : "Dear [national-manager:name],\\r\\n\\r\\nThank you for joining the ENRD LAG Database!\\r\\n\\r\\nYou are now the national manager of the following country: [national-manager:field-enrd-lag-country].\\r\\n\\r\\nPlease click this link: [site:login-url] to log in and proceed to manage and monitor the LAGs within your competence.\\r\\nFor more information on EU Login, please refer to the following documentation: [site:eu-login-tutorial].\\r\\n\\r\\nBest Regards,\\r\\n\\r\\nThe ENRD Contact Point team",
            "language" : [ "national-manager:language" ]
          }
        }
      ]
    }
  }');
  $items['rules_enrd_lag_dashboard_send_mail_from_og_membership'] = entity_import('rules_config', '{ "rules_enrd_lag_dashboard_send_mail_from_og_membership" : {
      "LABEL" : "Send an email to OG Membership from LAG webmaster",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD LAG DASHBOARD" ],
      "REQUIRES" : [ "rules" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : {
        "og_membership" : { "label" : "LAG membership", "type" : "og_membership" },
        "mail_subject" : { "label" : "Email subject", "type" : "text" },
        "mail_body" : { "label" : "Email body", "type" : "text" }
      },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "og-membership:entity" ],
            "type" : "user",
            "bundle" : { "value" : { "user" : "user" } }
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "og-membership:entity:mail" ],
            "subject" : [ "mail-subject" ],
            "message" : [ "mail-body" ],
            "from" : "LAG-database-webmaster@enrd.eu",
            "language" : [ "og-membership:entity:language" ]
          }
        }
      ]
    }
  }');
  $items['rules_enrd_moderate_content_to_archived'] = entity_import('rules_config', '{ "rules_enrd_moderate_content_to_archived" : {
      "LABEL" : "ENRD moderate content to Archived",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD LAG DASHBOARD" ],
      "REQUIRES" : [ "workbench_moderation" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "node" : { "label" : "Node", "type" : "node" } },
      "ACTION SET" : [
        { "workbench_moderation_set_state" : {
            "node" : [ "node" ],
            "moderation_state" : "archived",
            "force_transition" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_enrd_moderate_content_to_draft'] = entity_import('rules_config', '{ "rules_enrd_moderate_content_to_draft" : {
      "LABEL" : "ENRD moderate content to Draft",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD LAG DASHBOARD" ],
      "REQUIRES" : [ "workbench_moderation" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "node" : { "label" : "Node", "type" : "node" } },
      "ACTION SET" : [
        { "workbench_moderation_set_state" : {
            "node" : [ "node" ],
            "moderation_state" : "draft",
            "force_transition" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_enrd_moderate_content_to_expired'] = entity_import('rules_config', '{ "rules_enrd_moderate_content_to_expired" : {
      "LABEL" : "ENRD moderate content to Expired",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD LAG DASHBOARD" ],
      "REQUIRES" : [ "rules", "workbench_moderation" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "node" : { "label" : "Node", "type" : "node" } },
      "ACTION SET" : [
        { "node_unpublish" : { "node" : [ "node" ] } },
        { "workbench_moderation_set_state_during_save" : { "node" : [ "node" ], "moderation_state" : "expired" } }
      ]
    }
  }');
  $items['rules_enrd_moderate_content_to_published'] = entity_import('rules_config', '{ "rules_enrd_moderate_content_to_published" : {
      "LABEL" : "ENRD moderate content to Published",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD LAG DASHBOARD" ],
      "REQUIRES" : [ "workbench_moderation" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "node" : { "label" : "Node", "type" : "node" } },
      "ACTION SET" : [
        { "workbench_moderation_set_state" : {
            "node" : [ "node" ],
            "moderation_state" : "published",
            "force_transition" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_enrd_moderate_content_to_ready_to_be_published'] = entity_import('rules_config', '{ "rules_enrd_moderate_content_to_ready_to_be_published" : {
      "LABEL" : "ENRD moderate content to Ready to be published",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD LAG DASHBOARD" ],
      "REQUIRES" : [ "workbench_moderation" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "ACTION SET" : [
        { "workbench_moderation_set_state" : {
            "node" : [ "node" ],
            "moderation_state" : "ready_to_be_published",
            "force_transition" : "0"
          }
        }
      ]
    }
  }');
  return $items;
}
