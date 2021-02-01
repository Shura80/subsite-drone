<?php

/**
 * @file
 * enrd_lag_database.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function enrd_lag_database_default_rules_configuration() {
  $items = array();
  $items['enrd_mastermind_enrd_lag_database_member_subscribe_active'] = entity_import('rules_config', '{ "enrd_mastermind_enrd_lag_database_member_subscribe_active" : {
      "LABEL" : "ENRD LAG member subscribe (Active)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD LAG DATABASE" ],
      "REQUIRES" : [ "rules", "og" ],
      "ON" : { "og_user_insert" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "og-membership:state" ], "value" : "1" } },
        { "entity_is_of_type" : { "entity" : [ "og-membership:group" ], "type" : "node" } },
        { "node_is_of_type" : {
            "node" : [ "og-membership:group" ],
            "type" : { "value" : { "lag" : "lag" } }
          }
        },
        { "NOT data_is" : { "data" : [ "account:uid" ], "value" : "1" } }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "node", "value" : [ "og-membership:group" ] },
            "PROVIDE" : { "variable_added" : { "group" : "Group" } }
          }
        },
        { "mail" : {
            "to" : "[account:mail]",
            "subject" : "Thank you for joining the ENRD LAG Database!",
            "message" : "Dear [account:name],\\r\\n\\r\\nThank you for joining the ENRD LAG Database!\\r\\n\\r\\nYou are now a member of Local Action Group:\\r\\n[group:title_field] located at: [group:url].\\r\\n\\r\\nPlease click this link: [site:login-url] to log in and proceed with setting up your account.\\r\\nFor more information on EU Login, please refer to the following documentation: [site:eu-login-tutorial].\\r\\n\\r\\nFind out how to update your LAG profile, and create cooperation offers here: [site:base-url]\\/leader-clld\\/lag-database\\/guide-lags_en.\\r\\n\\r\\nBest Regards,\\r\\n\\r\\nThe ENRD Contact Point team",
            "language" : [ "" ]
          }
        },
        { "mail" : {
            "to" : "LAG-database-webmaster@enrd.eu",
            "subject" : "ENRD LAG Database - [account:name] joined [group:title_field]",
            "message" : "Dear LAG Database webmaster,\\r\\n\\r\\n[account:name] joined: [group:title_field]\\r\\n\\r\\nlocated at: [group:url] .\\r\\n\\r\\nBest regards,\\r\\n\\r\\nThe ENRD Contact Point team",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_enrd_coop_notify_node_authors'] = entity_import('rules_config', '{ "rules_enrd_coop_notify_node_authors" : {
      "LABEL" : "ENRD LAG Database Notify Coopeeration Offers Node Authors",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD COOPERATION OFFER" ],
      "REQUIRES" : [ "rules", "workbench_moderation" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "cooperation_offer" : "cooperation_offer" } }
          }
        },
        { "contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "ready_to_be_published" } },
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "published" } },
        { "NOT data_is" : { "data" : [ "node:author:uid" ], "value" : "1" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[node:author:mail]",
            "subject" : "ENRD LAG Database - your Cooperation offer is now published online",
            "message" : "Dear [node:author],\\r\\n\\r\\nYour LAG\\u2019s Cooperation Offer [node:title] is now published online.\\r\\n\\r\\nYou can see the offer by clicking this link: [node:url]\\r\\n\\r\\nBest Regards,\\r\\n\\r\\nThe ENRD Contact Point team",
            "from" : "no-reply@enrd.ec.europa.eu",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_enrd_coop_offers_archived_to_draft'] = entity_import('rules_config', '{ "rules_enrd_coop_offers_archived_to_draft" : {
      "LABEL" : "ENRD Coop Offers Archived to Draft",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD COOPERATION OFFER" ],
      "REQUIRES" : [ "rules", "workbench_moderation", "enrd_lag_database" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "cooperation_offer" : "cooperation_offer" } }
          }
        },
        { "AND" : [
            { "content_is_using_workbench_moderation" : { "node" : [ "node" ] } },
            { "contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "archived" } },
            { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "draft" } }
          ]
        }
      ],
      "DO" : [
        { "enrd_lag_database_get_members_with_role_in_group" : {
            "USING" : {
              "group" : [ "node:og-lag-group-ref" ],
              "og_role" : { "value" : { "LAG Contact" : "LAG Contact", "LAG Manager" : "LAG Manager" } }
            },
            "PROVIDE" : { "group_members_with_role_in_group" : { "group_members_with_role_in_group" : "List of group members with selected role(s) in group" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "group-members-with-role-in-group" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "mail" : {
                  "to" : "[list-item:mail]",
                  "subject" : "ENRD LAG Database - your LAG\\u0027s archived Cooperation Offer has been updated",
                  "message" : "Dear [list-item:name],\\r\\n\\r\\nYour LAG\\u0027s archived Cooperation Offer [node:title] has been updated and now it is in draft state.\\r\\n\\r\\nReview this draft by clicking this link: [node:url]\\r\\n\\r\\nBest Regards,\\r\\n\\r\\nThe ENRD Contact Point team",
                  "language" : [ "" ]
                }
              }
            ]
          }
        },
        { "mail" : {
            "to" : "[node:author:mail]",
            "subject" : "ENRD LAG Database - your LAG\\u0027s archived Cooperation Offer has been updated",
            "message" : "Dear [node:author],\\r\\n\\r\\nYour LAG\\u0027s archived Cooperation Offer [node:title] has been updated and now it is in draft state.\\r\\n\\r\\nReview this draft by clicking this link: [node:url]\\r\\n\\r\\nBest Regards,\\r\\n\\r\\nThe ENRD Contact Point team\\r\\n",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_enrd_coop_offers_draft_to_ready_to_be_published'] = entity_import('rules_config', '{ "rules_enrd_coop_offers_draft_to_ready_to_be_published" : {
      "LABEL" : "ENRD Coop Offers Draft to Ready to be Published",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD COOPERATION OFFER" ],
      "REQUIRES" : [ "rules", "workbench_moderation" ],
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
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "LAG-database-webmaster@enrd.eu",
            "subject" : "ENRD LAG Database - Cooperation Offer update ready for publication online",
            "message" : "Dear LAG Database webmaster,\\r\\n\\r\\nThe following LAG\\u2019s Cooperation Offer [node:title] has been submitted for publication and is ready for your review.\\r\\n\\r\\nYou can see the offer by clicking this link: [node:url]\\r\\n \\r\\nThis is the log message:\\r\\n[node:log].\\r\\n\\r\\nBest Regards,\\r\\n\\r\\nThe ENRD Contact Point team",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_enrd_coop_offers_ready_to_be_published_to_published'] = entity_import('rules_config', '{ "rules_enrd_coop_offers_ready_to_be_published_to_published" : {
      "LABEL" : "ENRD Coop Offers Ready to be Published to Published",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD COOPERATION OFFER" ],
      "REQUIRES" : [ "rules", "workbench_moderation", "enrd_lag_database" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "cooperation_offer" : "cooperation_offer" } }
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
        { "enrd_lag_database_get_members_with_role_in_group" : {
            "USING" : {
              "group" : [ "node:og-lag-group-ref" ],
              "og_role" : { "value" : { "LAG Contact" : "LAG Contact", "LAG Manager" : "LAG Manager" } }
            },
            "PROVIDE" : { "group_members_with_role_in_group" : { "group_members_with_role_in_group" : "List of group members with selected role(s) in group" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "group-members-with-role-in-group" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "mail" : {
                  "to" : "[list-item:mail]",
                  "subject" : "ENRD LAG Database - your LAG\\u0027s Cooperation Offer is now published online",
                  "message" : "Dear [list-item:name],\\r\\n\\r\\nYour LAG\\u2019s Cooperation Offer [node:title] is now published online.\\r\\n\\r\\nYou can see the offer by clicking this link: [node:url]\\r\\n\\r\\nBest Regards,\\r\\n\\r\\nThe ENRD Contact Point team",
                  "language" : [ "" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_enrd_coop_offers_save_new_draft'] = entity_import('rules_config', '{ "rules_enrd_coop_offers_save_new_draft" : {
      "LABEL" : "ENRD Coop Offers Save new Draft",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD COOPERATION OFFER" ],
      "REQUIRES" : [ "workbench_moderation", "rules" ],
      "ON" : { "node_update--cooperation_offer" : { "bundle" : "cooperation_offer" } },
      "IF" : [
        { "content_is_using_workbench_moderation" : { "node" : [ "node" ] } },
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "draft" } },
        { "contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "draft" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[site:current-user:mail]",
            "subject" : "ENRD LAG Database - your LAG\\u0027s Cooperation Offer has been saved",
            "message" : "Dear [site:current-user]\\r\\n\\r\\nYour LAG\\u0027s Cooperation Offer [node:title] has been saved. The offer is still a draft and has not been published online.\\r\\n\\r\\nPlease click this link [site:base-url]\\/my-lags\\/[node:og-lag-group-ref:nid]\\/manage\\/cooperation-offers_en and press the \\u0027Ask for publication\\u0027 button to ask the webmaster to put the Cooperation offer online.\\r\\n\\r\\nBest Regards,\\r\\n\\r\\nThe ENRD Contact Point team",
            "from" : "no-reply@enrd.ec.europa.eu",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_enrd_coop_ready_to_be_published_to_draft'] = entity_import('rules_config', '{ "rules_enrd_coop_ready_to_be_published_to_draft" : {
      "LABEL" : "ENRD Coop Offers Ready to be Published to Draft",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD COOPERATION OFFER" ],
      "REQUIRES" : [ "rules", "workbench_moderation" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "cooperation_offer" : "cooperation_offer" } }
          }
        },
        { "content_is_using_workbench_moderation" : { "node" : [ "node" ] } },
        { "contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "ready_to_be_published" } },
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "draft" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[node:revision-author-mail]",
            "subject" : "ENRD LAG Database - your LAG\\u0027s Cooperation Offer has been rejected by the LAG webmaster",
            "message" : "Dear [node:revision-author],\\r\\n\\r\\nYour LAG\\u0027s Cooperation Offer [node:title] has been rejected by the LAG webmaster and has not been published online.\\r\\n\\r\\nReview your draft offer by clicking this link: [node:url]\\r\\n\\r\\nOr contact the LAG webmaster at LAG-database-webmaster@enrd.eu\\r\\n\\r\\nBest Regards,\\r\\n\\r\\nThe ENRD Contact Point team",
            "from" : "no-reply@enrd.ec.europa.eu",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_enrd_lag_archived_to_draft'] = entity_import('rules_config', '{ "rules_enrd_lag_archived_to_draft" : {
      "LABEL" : "ENRD LAG Archived to Draft",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD LAG DATABASE" ],
      "REQUIRES" : [ "rules", "workbench_moderation", "enrd_lag_database" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "lag" : "lag" } } } },
        { "AND" : [
            { "content_is_using_workbench_moderation" : { "node" : [ "node" ] } },
            { "contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "archived" } },
            { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "draft" } }
          ]
        }
      ],
      "DO" : [
        { "enrd_lag_database_get_members_with_role_in_group" : {
            "USING" : {
              "group" : [ "node" ],
              "og_role" : { "value" : { "LAG Contact" : "LAG Contact", "LAG Manager" : "LAG Manager" } }
            },
            "PROVIDE" : { "group_members_with_role_in_group" : { "group_members_with_role_in_group" : "List of group members with selected role(s) in group" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "group-members-with-role-in-group" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "mail" : {
                  "to" : "[list-item:mail]",
                  "subject" : "ENRD LAG Database - your archived LAG has been updated",
                  "message" : "Dear [list-item:field-firstname] [list-item:field-lastname],\\r\\n\\r\\nYour archived LAG [node:title] has been updated and now it is in a draft state.\\r\\n\\r\\nReview this draft by clicking this link: [node:url]\\r\\n\\r\\nBest Regards,\\r\\n\\r\\nThe ENRD Contact Point team",
                  "from" : "no-reply@enrd.ec.europa.eu",
                  "language" : [ "" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_enrd_lag_database_create_schedule_after_esi_fund_creation'] = entity_import('rules_config', '{ "rules_enrd_lag_database_create_schedule_after_esi_fund_creation" : {
      "LABEL" : "ENRD LAG Database: Create Schedule after ESI fund creation",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD LAG DATABASE" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--esi_funds_og" : { "bundle" : "esi_funds_og" } },
      "DO" : [
        { "component_rules_enrd_lag_database_set_nsu_schedule" : { "node" : [ "node" ] } }
      ]
    }
  }');
  $items['rules_enrd_lag_database_create_schedule_after_lag_creation'] = entity_import('rules_config', '{ "rules_enrd_lag_database_create_schedule_after_lag_creation" : {
      "LABEL" : "ENRD LAG Database: Create Schedule after LAG creation",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD LAG DATABASE" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--lag" : { "bundle" : "lag" } },
      "DO" : [
        { "component_rules_enrd_lag_database_set_schedule" : { "node" : [ "node" ] } }
      ]
    }
  }');
  $items['rules_enrd_lag_database_delete_schedule_after_esi_deletion'] = entity_import('rules_config', '{ "rules_enrd_lag_database_delete_schedule_after_esi_deletion" : {
      "LABEL" : "ENRD LAG Database: Delete Schedule after ESI Funds OG deletion",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD LAG DATABASE" ],
      "REQUIRES" : [ "rules", "rules_scheduler" ],
      "ON" : { "node_delete--esi_funds_og" : { "bundle" : "esi_funds_og" } },
      "DO" : [
        { "schedule_delete" : {
            "component" : "rules_enrd_lag_database_solicit_nsu_notification",
            "task" : "[node:field-enrd-main-esi-fund]-lag-notification"
          }
        }
      ]
    }
  }');
  $items['rules_enrd_lag_database_delete_schedule_after_lag_deletion'] = entity_import('rules_config', '{ "rules_enrd_lag_database_delete_schedule_after_lag_deletion" : {
      "LABEL" : "ENRD LAG Database: Delete Schedule after LAG deletion",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD LAG DATABASE" ],
      "REQUIRES" : [ "rules", "rules_scheduler" ],
      "ON" : { "node_delete--lag" : { "bundle" : "lag" } },
      "DO" : [
        { "schedule_delete" : {
            "component" : "rules_enrd_lag_database_solicit_manager_notification",
            "task" : "[node:field-enrd-lag-code]-lag-notification"
          }
        }
      ]
    }
  }');
  $items['rules_enrd_lag_database_save_new_draft'] = entity_import('rules_config', '{ "rules_enrd_lag_database_save_new_draft" : {
      "LABEL" : "ENRD LAG Database Save new Draft",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD LAG DATABASE" ],
      "REQUIRES" : [ "workbench_moderation", "enrd_lag_database", "rules" ],
      "ON" : { "node_update--lag" : { "bundle" : "lag" } },
      "IF" : [
        { "content_is_using_workbench_moderation" : { "node" : [ "node" ] } },
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "draft" } },
        { "contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "draft" } }
      ],
      "DO" : [
        { "enrd_lag_database_get_members_with_role_in_group" : {
            "USING" : {
              "group" : [ "node" ],
              "og_role" : { "value" : { "LAG Contact" : "LAG Contact", "LAG Manager" : "LAG Manager" } }
            },
            "PROVIDE" : { "group_members_with_role_in_group" : { "group_members_with_role_in_group" : "List of group members with selected role(s) in group" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "group-members-with-role-in-group" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "mail" : {
                  "to" : "[list-item:mail]",
                  "subject" : "ENRD LAG Database - your LAG\\u0027s profile has been updated",
                  "message" : "Dear [list-item:field-firstname] [list-item:field-lastname],\\r\\n \\r\\nYour LAG\\u0027s profile [node:title] has been updated. This update is still a draft and has not been published online.\\r\\n\\r\\nPlease click this link [site:base-url]\\/lag-dashboard_en and press the \\u0027Ask for publication\\u0027 button to ask the webmaster to put your update online.\\r\\n\\r\\n\\r\\nBest Regards,\\r\\n\\r\\nThe ENRD Contact Point team",
                  "from" : "no-reply@enrd.ec.europa.eu",
                  "language" : [ "" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_enrd_lag_database_set_nsu_schedule'] = entity_import('rules_config', '{ "rules_enrd_lag_database_set_nsu_schedule" : {
      "LABEL" : "ENRD LAG Database: Set Schedule (NSU)",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD LAG DATABASE" ],
      "REQUIRES" : [ "rules", "rules_scheduler" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "ACTION SET" : [
        { "schedule" : {
            "component" : "rules_enrd_lag_database_solicit_nsu_notification",
            "date" : "+6 Months",
            "identifier" : "[node:field-enrd-main-esi-fund]-lag-notification",
            "param_node" : [ "node" ]
          }
        }
      ]
    }
  }');
  $items['rules_enrd_lag_database_set_schedule'] = entity_import('rules_config', '{ "rules_enrd_lag_database_set_schedule" : {
      "LABEL" : "ENRD LAG Database: Set Schedule",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD LAG DATABASE" ],
      "REQUIRES" : [ "rules", "rules_scheduler" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "ACTION SET" : [
        { "schedule" : {
            "component" : "rules_enrd_lag_database_solicit_manager_notification",
            "date" : "+6 Months",
            "identifier" : "[node:field-enrd-lag-code]-lag-notification",
            "param_node" : [ "node" ]
          }
        }
      ]
    }
  }');
  $items['rules_enrd_lag_database_solicit_manager_notification'] = entity_import('rules_config', '{ "rules_enrd_lag_database_solicit_manager_notification" : {
      "LABEL" : "ENRD LAG Database: Solicit LAG Manager Update Notification",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD LAG DATABASE" ],
      "REQUIRES" : [ "rules", "enrd_lag_database", "rules_scheduler" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "lag" : "lag" } } } }
      ],
      "DO" : [
        { "enrd_lag_database_get_lag_managers_in_group" : {
            "USING" : { "group" : [ "node" ] },
            "PROVIDE" : { "group_members_with_role_man_in_group" : { "group_members_with_role_man_in_group" : "List of group members with \\u0022LAG Manager\\u0022 role in group" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "group-members-with-role-man-in-group" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "mail" : {
                  "to" : "[list-item:mail]",
                  "subject" : "ENRD LAG Database - invitation to update your LAG profile",
                  "message" : "Dear [list-item:field-firstname] [list-item:field-lastname],\\r\\n\\r\\nWe would like to kindly invite you - as LAG manager of [node:title] - to review and update your LAG profile by clicking this link: [node:url] and logging in with your ECAS account.\\r\\n\\r\\nForgotten your ECAS account?\\r\\nhttps:\\/\\/ecas.ec.europa.eu\\/cas\\/login\\r\\n\\r\\nFor more information on EU Login, please refer to the following documentation: [site:eu-login-tutorial]\\r\\n\\r\\nBest Regards,\\r\\n\\r\\nThe ENRD Contact Point team",
                  "from" : "no-reply@enrd.ec.europa.eu",
                  "language" : [ "" ]
                }
              }
            ]
          }
        },
        { "schedule" : {
            "component" : "rules_enrd_lag_database_solicit_manager_notification",
            "date" : "+6 Months",
            "identifier" : "[node:field-enrd-lag-code]-lag-notification",
            "param_node" : [ "node" ]
          }
        }
      ]
    }
  }');
  $items['rules_enrd_lag_database_solicit_nsu_notification'] = entity_import('rules_config', '{ "rules_enrd_lag_database_solicit_nsu_notification" : {
      "LABEL" : "ENRD LAG Database: Solicit National manager Update Notification",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD LAG DATABASE" ],
      "REQUIRES" : [ "rules", "enrd_lag_database", "rules_scheduler" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "esi_funds_og" : "esi_funds_og" } }
          }
        }
      ],
      "DO" : [
        { "enrd_lag_database_get_nsu_in_group" : {
            "USING" : { "group" : [ "node" ] },
            "PROVIDE" : { "group_members_with_role_nsu_in_group" : { "group_members_with_role_nsu_in_group" : "List of group members with \\u0022National manager\\u0022 role in group" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "group-members-with-role-nsu-in-group" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "mail" : {
                  "to" : "[list-item:mail]",
                  "subject" : "ENRD LAG Database - invitation to update your LAG profiles list",
                  "message" : "Dear [list-item:field-firstname] [list-item:field-lastname],\\r\\n\\r\\nWe would like to kindly invite you to review and update your LAG profiles list in your capacity of national manager of LAGs from [list-item:field-enrd-lag-country].\\r\\n\\r\\nPlease click the following link to access your LAG profiles list [site:base-url]\\/lag-dashboard and log in with your ECAS account.\\r\\n\\r\\nForgotten your ECAS account?\\r\\nhttps:\\/\\/ecas.ec.europa.eu\\/cas\\/login\\r\\n\\r\\nFor more information on EU Login, please refer to the following documentation: [site:eu-login-tutorial]\\r\\n\\r\\nBest Regards,\\r\\n\\r\\nThe ENRD Contact Point team",
                  "from" : "no-reply@enrd.ec.europa.eu",
                  "language" : [ "" ]
                }
              }
            ]
          }
        },
        { "schedule" : {
            "component" : "rules_enrd_lag_database_solicit_nsu_notification",
            "date" : "+6 Months",
            "identifier" : "[node:field-enrd-main-esi-fund]-lag-notification",
            "param_node" : [ "node" ]
          }
        }
      ]
    }
  }');
  $items['rules_enrd_lag_draft_to_ready_to_be_published'] = entity_import('rules_config', '{ "rules_enrd_lag_draft_to_ready_to_be_published" : {
      "LABEL" : "ENRD LAG Draft to Ready to be Published",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD LAG DATABASE" ],
      "REQUIRES" : [ "rules", "workbench_moderation" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "lag" : "lag" } } } },
        { "AND" : [
            { "content_is_using_workbench_moderation" : { "node" : [ "node" ] } },
            { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "ready_to_be_published" } }
          ]
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "LAG-database-webmaster@enrd.eu",
            "subject" : "LAG profile update ready for publication online",
            "message" : "Dear LAG Database webmaster,\\r\\n\\r\\nThe following LAG has been submitted for publication and is ready for your review: [node:title] .\\r\\n\\r\\nYou can see the updated LAG profile by clicking this link: [node:url] .\\r\\n\\r\\nThis is the log message:\\r\\n[node:log]\\r\\n\\r\\nBest Regards,\\r\\n\\r\\nThe ENRD Contact Point team",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_enrd_lag_notify_node_authors'] = entity_import('rules_config', '{ "rules_enrd_lag_notify_node_authors" : {
      "LABEL" : "ENRD LAG Database Notify Node Authors",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD LAG DATABASE" ],
      "REQUIRES" : [ "rules", "workbench_moderation" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "lag" : "lag" } } } },
        { "contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "ready_to_be_published" } },
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "published" } },
        { "NOT data_is" : { "data" : [ "node:author:uid" ], "value" : "1" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[node:author:mail]",
            "subject" : "ENRD LAG Database - your LAG is now published online",
            "message" : "Dear [node:author],\\r\\n\\r\\nThe update of your LAG [node:title] is now published online.\\r\\n\\r\\nYou can see your updated LAG profile by clicking this link: [node:url]\\r\\n\\r\\nBest Regards,\\r\\n\\r\\nThe ENRD Contact Point team",
            "from" : "no-reply@enrd.ec.europa.eu",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_enrd_lag_ready_to_be_published_to_draft'] = entity_import('rules_config', '{ "rules_enrd_lag_ready_to_be_published_to_draft" : {
      "LABEL" : "ENRD LAG Database Ready to be Published to Draft",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD COOPERATION OFFER", "ENRD LAG DATABASE" ],
      "REQUIRES" : [ "rules", "workbench_moderation" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "lag" : "lag" } } } },
        { "content_is_using_workbench_moderation" : { "node" : [ "node" ] } },
        { "contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "ready_to_be_published" } },
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "draft" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[node:revision-author-mail]",
            "subject" : "ENRD LAG Database - your LAG\\u0027s profile update has been rejected by the LAG webmaster",
            "message" : "Dear [node:revision-author]\\r\\n\\r\\nYour LAG\\u0027s profile update of [node:title] has been rejected by the LAG webmaster and has not been published online.\\r\\n\\r\\nReview your draft profile update by clicking this link: [node:url]\\r\\n\\r\\nOr contact the LAG webmaster at LAG-database-webmaster@enrd.eu\\r\\n\\r\\nBest Regards,\\r\\n\\r\\nThe ENRD Contact Point team",
            "from" : "no-reply@enrd.ec.europa.eu",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_enrd_lag_ready_to_be_published_to_published'] = entity_import('rules_config', '{ "rules_enrd_lag_ready_to_be_published_to_published" : {
      "LABEL" : "ENRD LAG Ready to be Published to Published",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD LAG DATABASE" ],
      "REQUIRES" : [ "rules", "workbench_moderation", "enrd_lag_database" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "lag" : "lag" } } } },
        { "AND" : [
            { "content_is_using_workbench_moderation" : { "node" : [ "node" ] } },
            { "contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "ready_to_be_published" } },
            { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "published" } }
          ]
        }
      ],
      "DO" : [
        { "enrd_lag_database_get_members_with_role_in_group" : {
            "USING" : {
              "group" : [ "node" ],
              "og_role" : { "value" : { "LAG Contact" : "LAG Contact", "LAG Manager" : "LAG Manager" } }
            },
            "PROVIDE" : { "group_members_with_role_in_group" : { "group_members_with_role_in_group" : "List of group members with selected role(s) in group" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "group-members-with-role-in-group" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "mail" : {
                  "to" : "[list-item:mail]",
                  "subject" : "ENRD LAG Database - your LAG\\u0027s profile update is now published online",
                  "message" : "Dear [list-item:field-firstname] [list-item:field-lastname],\\r\\n\\r\\nThe update of your LAG [node:title] is now published online.\\r\\n\\r\\nYou can see your updated LAG profile by clicking this link: [node:url].\\r\\n\\r\\nBest Regards,\\r\\n\\r\\nThe ENRD Contact Point team",
                  "from" : "no-reply@enrd.ec.europa.eu",
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
