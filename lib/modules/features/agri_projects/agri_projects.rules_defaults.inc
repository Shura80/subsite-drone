<?php

/**
 * @file
 * agri_projects.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function agri_projects_default_rules_configuration() {
  $items = array();
  $items['agri_projects_hide_partners_info'] = entity_import('rules_config', '{ "agri_projects_hide_partners_info" : {
      "LABEL" : "Hide Partners information (Project node)",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "AGRI Projects" ],
      "REQUIRES" : [ "flag" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "hide_partners_information" : { "label" : "Flag item to hide Partners information", "type" : "node" } },
      "IF" : [
        { "NOT flag_flagged_node" : {
            "flag" : "agri_privacy_policy",
            "node" : [ "hide-partners-information" ],
            "flagging_user" : [ "site:current-user" ]
          }
        }
      ],
      "DO" : [
        { "flag_flagnode" : {
            "flag" : "agri_privacy_policy",
            "node" : [ "hide-partners-information" ],
            "flagging_user" : [ "site:current-user" ],
            "permission_check" : "0"
          }
        }
      ]
    }
  }');
  $items['agri_projects_show_partners_info'] = entity_import('rules_config', '{ "agri_projects_show_partners_info" : {
      "LABEL" : "Show Partners information (Project node)",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "AGRI Projects" ],
      "REQUIRES" : [ "flag" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "show_partners_info" : { "label" : "Unflag item to show Partners information", "type" : "node" } },
      "IF" : [
        { "flag_flagged_node" : {
            "flag" : "agri_privacy_policy",
            "node" : [ "show-partners-info" ],
            "flagging_user" : [ "site:current-user" ]
          }
        }
      ],
      "DO" : [
        { "flag_unflagnode" : {
            "flag" : "agri_privacy_policy",
            "node" : [ "show-partners-info" ],
            "flagging_user" : [ "site:current-user" ],
            "permission_check" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_agri_innovative_action_project_type'] = entity_import('rules_config', '{ "rules_agri_innovative_action_project_type" : {
      "LABEL" : "AGRI Innovative Action - Project type",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "AGRI Projects" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_presave--project" : { "bundle" : "project" } },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_proj_funding_source_list" } },
        { "data_is" : {
            "data" : [ "node:field-proj-funding-source-list" ],
            "op" : "IN",
            "value" : { "value" : { "1" : "1", "2" : "2", "3" : "3", "8" : "8", "9" : "9" } }
          }
        }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "node:field-proj-project-type" ],
            "value" : "Innovative action"
          }
        }
      ]
    }
  }');
  $items['rules_agri_operational_group_project_type'] = entity_import('rules_config', '{ "rules_agri_operational_group_project_type" : {
      "LABEL" : "AGRI Operational Group - Project type",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "AGRI Projects" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_presave--project" : { "bundle" : "project" } },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_proj_funding_source_list" } },
        { "data_is" : { "data" : [ "node:field-proj-funding-source-list" ], "value" : "0" } }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "node:field-proj-project-type" ],
            "value" : "Operational group"
          }
        }
      ]
    }
  }');
  $items['rules_agri_research_project_project_type'] = entity_import('rules_config', '{ "rules_agri_research_project_project_type" : {
      "LABEL" : "AGRI Research Project - Project type",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "AGRI Projects" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_presave--project" : { "bundle" : "project" } },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_proj_funding_source_list" } },
        { "data_is" : {
            "data" : [ "node:field-proj-funding-source-list" ],
            "op" : "IN",
            "value" : { "value" : { "4" : "4", "5" : "5", "6" : "6", "7" : "7" } }
          }
        }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "node:field-proj-project-type" ],
            "value" : "Research project"
          }
        }
      ]
    }
  }');
  return $items;
}
