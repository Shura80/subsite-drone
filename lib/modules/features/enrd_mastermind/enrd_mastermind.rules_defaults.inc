<?php

/**
 * @file
 * enrd_mastermind.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function enrd_mastermind_default_rules_configuration() {
  $items = array();
  $items['activity_enrd_content_moderation_draft'] = entity_import('rules_config', '{ "activity_enrd_content_moderation_draft" : {
      "LABEL" : "ENRD content moderation new Draft log",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD" ],
      "REQUIRES" : [ "workbench_moderation", "og", "rules" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "content_is_using_workbench_moderation" : { "node" : [ "node" ] } },
        { "AND" : [
            { "contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "draft" } },
            { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "draft" } }
          ]
        },
        { "OR" : [
            { "og_entity_is_group_content" : { "entity" : [ "node" ] } },
            { "NOT og_entity_is_group_content" : { "entity" : [ "node" ] } }
          ]
        }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "enrd_content_moderation_as_draft",
              "param_user" : [ "node:author" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_log" : "Entity log" } }
          }
        },
        { "data_set" : { "data" : [ "entity-log:field-node-ref" ], "value" : [ "node" ] } },
        { "data_set" : {
            "data" : [ "entity-log:field-enrd-message-logger" ],
            "value" : [ "site:current-user" ]
          }
        }
      ]
    }
  }');
  $items['activity_enrd_deleted_content_log'] = entity_import('rules_config', '{ "activity_enrd_deleted_content_log" : {
      "LABEL" : "ENRD deleted content log",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD" ],
      "REQUIRES" : [ "workbench_moderation", "og", "rules" ],
      "ON" : { "node_delete" : [] },
      "IF" : [
        { "content_is_using_workbench_moderation" : { "node" : [ "node" ] } },
        { "OR" : [
            { "NOT og_entity_is_group_content" : { "entity" : [ "node" ] } },
            { "AND" : [
                { "entity_has_field" : { "entity" : [ "node" ], "field" : "og_group_ref" } },
                { "data_is_empty" : { "data" : [ "node:og-group-ref" ] } }
              ]
            }
          ]
        }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "enrd_content_deletion",
              "param_user" : [ "node:author" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_log" : "Entity log" } }
          }
        },
        { "data_set" : { "data" : [ "entity-log:field-node-ref" ], "value" : [ "node" ] } },
        { "data_set" : {
            "data" : [ "entity-log:field-enrd-message-logger" ],
            "value" : [ "site:current-user" ]
          }
        }
      ]
    }
  }');
  $items['activity_enrd_new_content_log'] = entity_import('rules_config', '{ "activity_enrd_new_content_log" : {
      "LABEL" : "ENRD new content log",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD" ],
      "REQUIRES" : [ "workbench_moderation", "og", "rules" ],
      "ON" : { "node_insert" : [] },
      "IF" : [
        { "content_is_using_workbench_moderation" : { "node" : [ "node" ] } },
        { "OR" : [
            { "NOT og_entity_is_group_content" : { "entity" : [ "node" ] } },
            { "AND" : [
                { "entity_has_field" : { "entity" : [ "node" ], "field" : "og_group_ref" } },
                { "data_is_empty" : { "data" : [ "node:og-group-ref" ] } }
              ]
            }
          ]
        }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "enrd_new_content_creation",
              "param_user" : [ "node:author" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_log" : "Entity log" } }
          }
        },
        { "data_set" : { "data" : [ "entity-log:field-node-ref" ], "value" : [ "node" ] } },
        { "data_set" : {
            "data" : [ "entity-log:field-enrd-message-logger" ],
            "value" : [ "node:author" ]
          }
        }
      ]
    }
  }');
  $items['activity_enrd_og_deleted_content_log'] = entity_import('rules_config', '{ "activity_enrd_og_deleted_content_log" : {
      "LABEL" : "ENRD OG deleted content log ",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD" ],
      "REQUIRES" : [ "og", "rules" ],
      "ON" : { "node_delete" : [] },
      "IF" : [
        { "og_entity_is_group_content" : { "entity" : [ "node" ] } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "og_group_ref" } },
        { "NOT data_is_empty" : { "data" : [ "node:og-group-ref" ] } }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "enrd_og_content_deletion",
              "param_user" : [ "node:author" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_log" : "Entity log" } }
          }
        },
        { "data_set" : { "data" : [ "entity-log:field-node-ref" ], "value" : [ "node" ] } },
        { "data_set" : {
            "data" : [ "entity-log:field-enrd-message-logger" ],
            "value" : [ "site:current-user" ]
          }
        }
      ]
    }
  }');
  $items['activity_enrd_og_new_content_log'] = entity_import('rules_config', '{ "activity_enrd_og_new_content_log" : {
      "LABEL" : "ENRD OG new content log",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD" ],
      "REQUIRES" : [ "og", "rules" ],
      "ON" : { "node_insert" : [] },
      "IF" : [
        { "og_entity_is_group_content" : { "entity" : [ "node" ] } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "og_group_ref" } },
        { "NOT data_is_empty" : { "data" : [ "node:og-group-ref" ] } }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "enrd_og_new_content_creation",
              "param_user" : [ "node:author" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_log" : "Entity log" } }
          }
        },
        { "data_set" : { "data" : [ "entity-log:field-node-ref" ], "value" : [ "node" ] } },
        { "data_set" : {
            "data" : [ "entity-log:field-enrd-message-logger" ],
            "value" : [ "node:author" ]
          }
        }
      ]
    }
  }');
  $items['activity_enrd_og_updated_content_log'] = entity_import('rules_config', '{ "activity_enrd_og_updated_content_log" : {
      "LABEL" : "ENRD OG updated content log",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD" ],
      "REQUIRES" : [ "og", "rules" ],
      "ON" : { "node_update" : [] },
      "IF" : [
        { "og_entity_is_group_content" : { "entity" : [ "node" ] } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "og_group_ref" } },
        { "NOT data_is_empty" : { "data" : [ "node:og-group-ref" ] } }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "enrd_og_content_update",
              "param_user" : [ "node:author" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_log" : "Entity log" } }
          }
        },
        { "data_set" : { "data" : [ "entity-log:field-node-ref" ], "value" : [ "node" ] } },
        { "data_set" : {
            "data" : [ "entity-log:field-enrd-message-logger" ],
            "value" : [ "site:current-user" ]
          }
        }
      ]
    }
  }');
  $items['activity_enrd_updated_content_log'] = entity_import('rules_config', '{ "activity_enrd_updated_content_log" : {
      "LABEL" : "ENRD updated content log",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD" ],
      "REQUIRES" : [ "workbench_moderation", "og", "rules" ],
      "ON" : { "node_update" : [] },
      "IF" : [
        { "content_is_using_workbench_moderation" : { "node" : [ "node" ] } },
        { "OR" : [
            { "NOT og_entity_is_group_content" : { "entity" : [ "node" ] } },
            { "AND" : [
                { "entity_has_field" : { "entity" : [ "node" ], "field" : "og_group_ref" } },
                { "data_is_empty" : { "data" : [ "node:og-group-ref" ] } }
              ]
            }
          ]
        }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "enrd_content_update",
              "param_user" : [ "node:author" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_log" : "Entity log" } }
          }
        },
        { "data_set" : { "data" : [ "entity-log:field-node-ref" ], "value" : [ "node" ] } },
        { "data_set" : {
            "data" : [ "entity-log:field-enrd-message-logger" ],
            "value" : [ "site:current-user" ]
          }
        }
      ]
    }
  }');
  $items['enrd_mastermind_enrd_content_moderation_log'] = entity_import('rules_config', '{ "enrd_mastermind_enrd_content_moderation_log" : {
      "LABEL" : "ENRD content moderation log",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD" ],
      "REQUIRES" : [ "workbench_moderation", "og", "rules" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "content_is_using_workbench_moderation" : { "node" : [ "node" ] } },
        { "OR" : [
            { "og_entity_is_group_content" : { "entity" : [ "node" ] } },
            { "NOT og_entity_is_group_content" : { "entity" : [ "node" ] } }
          ]
        },
        { "OR" : [
            { "AND" : [
                { "contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "draft" } },
                { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "needs_review" } }
              ]
            },
            { "AND" : [
                { "contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "needs_review" } },
                { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "draft" } }
              ]
            },
            { "AND" : [
                { "contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "needs_review" } },
                { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "published" } }
              ]
            },
            { "AND" : [
                { "contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "needs_review" } },
                { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "validated" } }
              ]
            },
            { "AND" : [
                { "contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "validated" } },
                { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "published" } }
              ]
            },
            { "AND" : [
                { "contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "published" } },
                { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "archived" } }
              ]
            },
            { "AND" : [
                { "contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "published" } },
                { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "draft" } }
              ]
            }
          ]
        }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "enrd_content_moderation",
              "param_user" : [ "node:author" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_log" : "Entity log" } }
          }
        },
        { "data_set" : { "data" : [ "entity-log:field-node-ref" ], "value" : [ "node" ] } },
        { "data_set" : {
            "data" : [ "entity-log:field-enrd-message-logger" ],
            "value" : [ "site:current-user" ]
          }
        }
      ]
    }
  }');
  $items['enrd_mastermind_enrd_og_updated_content_notification'] = entity_import('rules_config', '{ "enrd_mastermind_enrd_og_updated_content_notification" : {
      "LABEL" : "ENRD OG updated content notification",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "TAGS" : [ "ENRD" ],
      "REQUIRES" : [ "og", "rules" ],
      "ON" : { "node_update" : [] },
      "IF" : [
        { "og_entity_is_group_content" : { "entity" : [ "node" ] } },
        { "node_is_published" : { "node" : [ "node" ] } },
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "community" : "community" } }
          }
        }
      ],
      "DO" : [
        { "og_get_members" : {
            "USING" : { "group_content" : [ "node" ] },
            "PROVIDE" : { "group_members" : { "group_members" : "List of group members" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "group-members" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "mail" : {
                  "to" : [ "list-item:mail" ],
                  "subject" : "Updated post in group",
                  "message" : "Hello [list-item:name],\\r\\n\\r\\nThere is an updated post called [node:title] of type [node:content-type] that belongs to [node:og-group-ref] the groups you are subscribed to [node:og-group-ref:url].\\r\\n\\r\\n[site:name]\\r\\n",
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
  $items['og_enrd_member_subscribe_active'] = entity_import('rules_config', '{ "og_enrd_member_subscribe_active" : {
      "LABEL" : "ENRD OG member subscribe (Active)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD" ],
      "REQUIRES" : [ "rules", "enrd_mastermind", "og" ],
      "ON" : { "og_user_insert" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "og-membership:state" ], "value" : "1" } },
        { "entity_is_of_type" : { "entity" : [ "og-membership:group" ], "type" : "node" } },
        { "node_is_of_type" : {
            "node" : [ "og-membership:group" ],
            "type" : { "value" : { "community" : "community" } }
          }
        }
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
            "message" : "Dear [account:name],\\r\\n\\r\\nYou are now a member in the group \\u0027[group:title]\\u0027 located at: [group:url].",
            "language" : [ "" ]
          }
        },
        { "mail" : {
            "to" : [ "group:author:mail" ],
            "subject" : "[account:name] joined [group:title]",
            "message" : "Dear [group:author:name],\\r\\n\\r\\n[account:name] joined [group:title] located at: [group:url].",
            "language" : [ "" ]
          }
        },
        { "enrd_mastermind_add_user_to_digest" : { "user" : [ "account" ], "group" : [ "group" ] } }
      ]
    }
  }');
  $items['og_enrd_member_subscribe_pending'] = entity_import('rules_config', '{ "og_enrd_member_subscribe_pending" : {
      "LABEL" : "ENRD OG member subscribe (Pending)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD" ],
      "REQUIRES" : [ "rules", "og" ],
      "ON" : { "og_user_insert" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "og-membership:state" ], "value" : "2" } },
        { "entity_is_of_type" : { "entity" : [ "og-membership:group" ], "type" : "node" } },
        { "node_is_of_type" : {
            "node" : [ "og-membership:group" ],
            "type" : { "value" : { "community" : "community" } }
          }
        }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "node", "value" : [ "og-membership:group" ] },
            "PROVIDE" : { "variable_added" : { "group" : "Added variable" } }
          }
        },
        { "mail" : {
            "to" : [ "account:mail" ],
            "subject" : "Your membership request for \\u0027[group:title]\\u0027",
            "message" : "[account:name],\\r\\n\\r\\nYour membership to group \\u0027[group:title]\\u0027 located at [group:url] is pending approval."
          }
        },
        { "mail" : {
            "to" : [ "group:author:mail" ],
            "subject" : "[account:name] membership request [group:title]",
            "message" : "[group:author:name],\\r\\n\\r\\n[account:name] requests membership for group \\u0027[group:title]\\u0027 in [group:url].\\r\\n\\r\\n[og_membership:og-membership-request]"
          }
        }
      ]
    }
  }');
  $items['og_enrd_new_content_notification'] = entity_import('rules_config', '{ "og_enrd_new_content_notification" : {
      "LABEL" : "ENRD OG new content notification",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "TAGS" : [ "ENRD" ],
      "REQUIRES" : [ "og", "rules" ],
      "ON" : { "node_insert" : [] },
      "IF" : [
        { "og_entity_is_group_content" : { "entity" : [ "node" ] } },
        { "node_is_published" : { "node" : [ "node" ] } },
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "community" : "community" } }
          }
        }
      ],
      "DO" : [
        { "og_get_members" : {
            "USING" : { "group_content" : [ "node" ] },
            "PROVIDE" : { "group_members" : { "group_members" : "List of group members" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "group-members" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "mail" : {
                  "to" : [ "list-item:mail" ],
                  "subject" : "New post in group",
                  "message" : "Hello [list-item:name],\\r\\n\\r\\nThere is a new post called [node:title] of type [node:content-type] that belongs to [node:og-group-ref] the groups you are subscribed to [node:og-group-ref:url].\\r\\n\\r\\n[site:name]\\r\\n",
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
  $items['rules_enrd_og_member_subscribe_approved_'] = entity_import('rules_config', '{ "rules_enrd_og_member_subscribe_approved_" : {
      "LABEL" : "ENRD OG member subscribe (Approved)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD" ],
      "REQUIRES" : [ "rules", "enrd_mastermind", "og" ],
      "ON" : { "og_user_approved" : [] },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "og-membership:group" ], "type" : "node" } },
        { "node_is_of_type" : {
            "node" : [ "og-membership:group" ],
            "type" : { "value" : { "community" : "community" } }
          }
        }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "node", "value" : [ "og-membership:group" ] },
            "PROVIDE" : { "variable_added" : { "group" : "Added variable" } }
          }
        },
        { "mail" : {
            "to" : [ "account:mail" ],
            "subject" : "Your membership request was approved for \\u0027[group:title]\\u0027",
            "message" : "[account:name],\\r\\n\\r\\nYou are now a member in the group \\u0027[group:title]\\u0027 located at [group:url]",
            "language" : [ "" ]
          }
        },
        { "mail" : {
            "to" : [ "group:author:mail" ],
            "subject" : "[account:name] joined [group:title]",
            "message" : "[group:author:name],\\r\\n\\r\\n[account:name] joined [group:title] in [group:url]",
            "language" : [ "" ]
          }
        },
        { "enrd_mastermind_add_user_to_digest" : { "user" : [ "account" ], "group" : [ "group" ] } }
      ]
    }
  }');
  $items['rules_enrd_og_member_subscribe_blocked_'] = entity_import('rules_config', '{ "rules_enrd_og_member_subscribe_blocked_" : {
      "LABEL" : "ENRD OG member subscribe (Blocked)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD" ],
      "REQUIRES" : [ "rules", "enrd_mastermind", "og" ],
      "ON" : { "og_user_blocked" : [] },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "og-membership:group" ], "type" : "node" } },
        { "node_is_of_type" : {
            "node" : [ "og-membership:group" ],
            "type" : { "value" : { "community" : "community" } }
          }
        }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "node", "value" : [ "og-membership:group" ] },
            "PROVIDE" : { "variable_added" : { "group" : "Added variable" } }
          }
        },
        { "mail" : {
            "to" : [ "account:mail" ],
            "subject" : "Your membership has been blocked for \\u0027[group:title]\\u0027",
            "message" : "[account:name],\\r\\n\\r\\nYour membership has been blocked for \\u0027[group:title]\\u0027 located at [group:url]",
            "language" : [ "" ]
          }
        },
        { "mail" : {
            "to" : [ "group:author:mail" ],
            "subject" : "[account:name] blocked for [group:title]",
            "message" : "[group:author:name],\\r\\n\\r\\n[account:name] blocked for [group:title] in [group:url]",
            "language" : [ "" ]
          }
        },
        { "enrd_mastermind_delete_user_to_digest" : { "user" : [ "account" ], "group" : [ "group" ] } }
      ]
    }
  }');
  $items['rules_enrd_og_member_subscribe_remove_'] = entity_import('rules_config', '{ "rules_enrd_og_member_subscribe_remove_" : {
      "LABEL" : "ENRD OG member subscribe (Remove)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD" ],
      "REQUIRES" : [ "rules", "enrd_mastermind", "og" ],
      "ON" : { "og_user_delete" : [] },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "og-membership:group" ], "type" : "node" } },
        { "node_is_of_type" : {
            "node" : [ "og-membership:group" ],
            "type" : { "value" : { "community" : "community" } }
          }
        }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "node", "value" : [ "og-membership:group" ] },
            "PROVIDE" : { "variable_added" : { "group" : "Added variable" } }
          }
        },
        { "mail" : {
            "to" : [ "account:mail" ],
            "subject" : "Group \\u0027[group:title]\\u0027 removal",
            "message" : "[account:name],\\r\\n\\r\\nYou have been removed from \\u0027[group:title]\\u0027",
            "language" : [ "" ]
          }
        },
        { "mail" : {
            "to" : [ "group:author:mail" ],
            "subject" : "[account:name] removed from [group:title]",
            "message" : "[group:author:name],\\r\\n\\r\\n[account:name] removed from [group:title] in [group:url]",
            "language" : [ "" ]
          }
        },
        { "enrd_mastermind_delete_user_to_digest" : { "user" : [ "account" ], "group" : [ "group" ] } }
      ]
    }
  }');
  return $items;
}
