<?php

/**
 * @file
 * agri_administrations.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function agri_administrations_default_rules_configuration() {
  $items = array();
  $items['agri_og_administration_content_rejected'] = entity_import('rules_config', '{ "agri_og_administration_content_rejected" : {
      "LABEL" : "AGRI OG content rejected notification - From Needs Review to Draft (Group Contributors)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "AGRI Administrations" ],
      "REQUIRES" : [ "og", "rules", "workbench_moderation" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "og_entity_is_group_content" : { "entity" : [ "node" ] } },
        { "AND" : [
            { "entity_is_of_bundle" : {
                "entity" : [ "node" ],
                "type" : "node",
                "bundle" : { "value" : { "funding_opportunities" : "funding_opportunities" } }
              }
            },
            { "NOT og_user_has_role" : {
                "account" : [ "site:current-user" ],
                "group" : [ "site:current-user:og-user-node:0" ],
                "roles" : { "value" : { "group contributor" : "group contributor" } }
              }
            },
            { "contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "needs_review" } },
            { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "draft" } }
          ]
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[node:author:mail]",
            "subject" : "Rejected Funding Opportunity",
            "message" : "Hello [node:author],\\r\\n\\r\\nYour funding opportunity [node:title] has been rejected and now it\\u0027s in draft state. You can modify it again and send it for review:\\r\\n[node:edit-url].\\r\\n\\r\\n[site:name]\\r\\n",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['agri_og_administration_member_subscribe_active'] = entity_import('rules_config', '{ "agri_og_administration_member_subscribe_active" : {
      "LABEL" : "AGRI OG member subscribe (Active)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "AGRI Administrations" ],
      "REQUIRES" : [ "rules", "og" ],
      "ON" : { "og_user_insert" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "og-membership:state" ], "value" : "1" } },
        { "entity_is_of_type" : { "entity" : [ "og-membership:group" ], "type" : "node" } }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "node", "value" : [ "og-membership:group" ] },
            "PROVIDE" : { "variable_added" : { "group" : "Added variable" } }
          }
        },
        { "mail" : {
            "to" : [ "account:mail" ],
            "subject" : "Your membership request was approved for \\u0027[group:title]\\u0027\\r\\n",
            "message" : "[account:name],\\r\\n\\r\\nYou are now a member in the group \\u0027[group:title]\\u0027 located at [group:url]"
          }
        },
        { "mail" : {
            "to" : [ "group:author:mail" ],
            "subject" : "[account:name] joined [group:title]",
            "message" : "[group:author:name],\\r\\n\\r\\n[account:name] joined [group:title] in [group:url]"
          }
        }
      ]
    }
  }');
  $items['agri_og_administration_new_content_notification_editors'] = entity_import('rules_config', '{ "agri_og_administration_new_content_notification_editors" : {
      "LABEL" : "AGRI OG new content notification - From Needs Review - (Group Editors)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "AGRI Administrations" ],
      "REQUIRES" : [ "og", "rules", "workbench_moderation", "agri_administrations" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "og_entity_is_group_content" : { "entity" : [ "node" ] } },
        { "AND" : [
            { "entity_is_of_bundle" : {
                "entity" : [ "node" ],
                "type" : "node",
                "bundle" : { "value" : { "funding_opportunities" : "funding_opportunities" } }
              }
            },
            { "NOT og_user_has_role" : {
                "account" : [ "site:current-user" ],
                "group" : [ "site:current-user:og-user-node:0" ],
                "roles" : { "value" : { "group editor" : "group editor" } }
              }
            },
            { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "needs_review" } }
          ]
        }
      ],
      "DO" : [
        { "agri_send_email_to_group_editors" : {
            "USING" : { "group_content" : [ "node" ] },
            "PROVIDE" : { "group_editors" : { "group_editors" : "List of group editors" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "group-editors" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "mail" : {
                  "to" : [ "list-item:mail" ],
                  "subject" : "New funding opportunity created in your Administration",
                  "message" : "Hello [list-item:name],\\r\\n\\r\\nYou have a new funding opportunity [node:title] to validate and publish:\\r\\n[node:url].\\r\\n\\r\\n[site:name]\\r\\n",
                  "from" : [ "" ],
                  "language" : [ "" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['agri_og_administration_published_content_site_admins'] = entity_import('rules_config', '{ "agri_og_administration_published_content_site_admins" : {
      "LABEL" : "AGRI OG content notification - Any State to Published - (Site Admins)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "AGRI Administrations" ],
      "REQUIRES" : [ "og", "rules", "workbench_moderation" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "og_entity_is_group_content" : { "entity" : [ "node" ] } },
        { "AND" : [
            { "entity_is_of_bundle" : {
                "entity" : [ "node" ],
                "type" : "node",
                "bundle" : { "value" : { "funding_opportunities" : "funding_opportunities" } }
              }
            },
            { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "published" } }
          ]
        }
      ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "3" : "3" } },
            "subject" : "Published funding opportunity in your Administration",
            "message" : "Hello,\\r\\n\\r\\nA new funding opportunity [node:title] has been published:\\r\\n[node:url].\\r\\n\\r\\n[site:name]\\r\\n"
          }
        }
      ]
    }
  }');
  $items['agri_og_administration_published_notification_admins'] = entity_import('rules_config', '{ "agri_og_administration_published_notification_admins" : {
      "LABEL" : "AGRI OG published content notification (Group Admins)",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "TAGS" : [ "AGRI Administrations" ],
      "REQUIRES" : [ "og", "rules", "workbench_moderation", "agri_administrations" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "og_entity_is_group_content" : { "entity" : [ "node" ] } },
        { "AND" : [
            { "entity_is_of_bundle" : {
                "entity" : [ "node" ],
                "type" : "node",
                "bundle" : { "value" : { "funding_opportunities" : "funding_opportunities" } }
              }
            },
            { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "published" } },
            { "AND" : [
                { "NOT og_user_has_role" : {
                    "account" : [ "site:current-user" ],
                    "group" : [ "site:current-user:og-user-node:0" ],
                    "roles" : { "value" : { "administrator member" : "administrator member" } }
                  }
                }
              ]
            }
          ]
        }
      ],
      "DO" : [
        { "agri_send_email_to_group_admins" : {
            "USING" : { "group_content" : [ "node" ] },
            "PROVIDE" : { "group_admins" : { "group_admins" : "List of group admins" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "group-admins" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "mail" : {
                  "to" : [ "list-item:mail" ],
                  "subject" : "Published funding opportunity in your Administration",
                  "message" : "Hello [list-item:name],\\r\\n\\r\\nA new funding opportunity [node:title] has been published:\\r\\n[node:url].\\r\\n\\r\\n[site:name]\\r\\n",
                  "from" : [ "" ],
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
