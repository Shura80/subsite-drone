<?php

/**
 * @file
 * enrd_sfr_pub.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function enrd_sfr_pub_default_rules_configuration() {
  $items = array();
  $items['rules_enrd_subscription_form_requests_finalize_cp_contact_mod'] = entity_import('rules_config', '{ "rules_enrd_subscription_form_requests_finalize_cp_contact_mod" : {
      "LABEL" : "ENRD Subscription Form Requests: Finalize CP Contact (Mod)",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "3",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD Subscription Form Requests" ],
      "REQUIRES" : [ "rules", "enrd_sfr" ],
      "ON" : { "enrd_sfr_finalize" : [] },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "enrd-sfr" ], "type" : "enrd_sfr" } },
        { "entity_is_of_bundle" : {
            "entity" : [ "enrd-sfr" ],
            "type" : "enrd_sfr",
            "bundle" : { "value" : { "enrd_sfr_pub_contact_cp" : "enrd_sfr_pub_contact_cp" } }
          }
        },
        { "data_is" : {
            "data" : [ "enrd-sfr:field-enrd-sfr-pub-contcp-reas" ],
            "value" : "modify subscription data"
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "publication@enrd.eu",
            "subject" : "Request to modify subscriptions #[enrd-sfr:sfrid]",
            "message" : "The new contact request #[enrd-sfr:sfrid] has been submitted:\\r\\n\\r\\nName: [enrd-sfr:field-enrd-sfr-pub-contcp-name]\\r\\nSurname: [enrd-sfr:field-enrd-sfr-pub-contcp-surn]\\r\\nEmail: [enrd-sfr:field-enrd-sfr-pub-contcp-email]\\r\\n\\r\\nReason: [enrd-sfr:field-enrd-sfr-pub-contcp-reas]\\r\\nType of publication(s): [enrd-sfr:field-enrd-sfr-pub-contcp-type]\\r\\nNotes provided by the user: [enrd-sfr:field-enrd-sfr-pub-contcp-modif]",
            "from" : "[site:mail]",
            "language" : [ "enrd-sfr:type" ]
          }
        }
      ]
    }
  }');
  $items['rules_enrd_subscription_form_requests_finalize_cp_contact_un'] = entity_import('rules_config', '{ "rules_enrd_subscription_form_requests_finalize_cp_contact_un" : {
      "LABEL" : "ENRD Subscription Form Requests: Finalize CP Contact (Unsub)",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "2",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD Subscription Form Requests" ],
      "REQUIRES" : [ "rules", "enrd_sfr" ],
      "ON" : { "enrd_sfr_finalize" : [] },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "enrd-sfr" ], "type" : "enrd_sfr" } },
        { "entity_is_of_bundle" : {
            "entity" : [ "enrd-sfr" ],
            "type" : "enrd_sfr",
            "bundle" : { "value" : { "enrd_sfr_pub_contact_cp" : "enrd_sfr_pub_contact_cp" } }
          }
        },
        { "data_is" : {
            "data" : [ "enrd-sfr:field-enrd-sfr-pub-contcp-reas" ],
            "value" : "unsubscribe"
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "publication@enrd.eu",
            "subject" : "Request to unsubscribe #[enrd-sfr:sfrid]",
            "message" : "The new contact request #[enrd-sfr:sfrid] has been submitted:\\r\\n\\r\\nName: [enrd-sfr:field-enrd-sfr-pub-contcp-name]\\r\\nSurname: [enrd-sfr:field-enrd-sfr-pub-contcp-surn]\\r\\nEmail: [enrd-sfr:field-enrd-sfr-pub-contcp-email]\\r\\nType of publication(s): [enrd-sfr:field-enrd-sfr-pub-contcp-type]\\r\\n\\r\\nReason: [enrd-sfr:field-enrd-sfr-pub-contcp-reas]\\r\\nElectronic or paper: [enrd-sfr:field-enrd-sfr-pub-contcp-papel]\\r\\nNotes provided by the user: [enrd-sfr:field-enrd-sfr-pub-contcp-comm]",
            "from" : "[site:mail]",
            "language" : [ "enrd-sfr:type" ]
          }
        }
      ]
    }
  }');
  $items['rules_enrd_subscription_form_requests_finalize_cp_subscription'] = entity_import('rules_config', '{ "rules_enrd_subscription_form_requests_finalize_cp_subscription" : {
      "LABEL" : "ENRD Subscription Form Requests: Finalize CP Subscription",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD Subscription Form Requests" ],
      "REQUIRES" : [ "rules", "enrd_sfr" ],
      "ON" : { "enrd_sfr_finalize" : [] },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "enrd-sfr" ], "type" : "enrd_sfr" } },
        { "entity_is_of_bundle" : {
            "entity" : [ "enrd-sfr" ],
            "type" : "enrd_sfr",
            "bundle" : { "value" : { "enrd_sfr_pub_subscribe_cp" : "enrd_sfr_pub_subscribe_cp" } }
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "publication@enrd.eu",
            "subject" : "Request to subscribe #[enrd-sfr:sfrid]",
            "message" : "The new subscription request #[enrd-sfr:sfrid] has been submitted. You can check it on the Contact Point\\u0027s Publications Subscriptions list admin page: [site:base-url]\\/admin\\/content\\/enrd-sfr\\/cp\\/subscriptions",
            "from" : "[site:mail]",
            "language" : [ "enrd-sfr:type" ]
          }
        }
      ]
    }
  }');
  $items['rules_enrd_subscription_form_requests_finalize_ehd_contact_req'] = entity_import('rules_config', '{ "rules_enrd_subscription_form_requests_finalize_ehd_contact_req" : {
      "LABEL" : "ENRD Subscription Form Requests: Finalize EHD contact request",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "3",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD Subscription Form Requests" ],
      "REQUIRES" : [ "rules", "enrd_sfr" ],
      "ON" : { "enrd_sfr_finalize" : [] },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "enrd-sfr" ], "type" : "enrd_sfr" } },
        { "entity_is_of_bundle" : {
            "entity" : [ "enrd-sfr" ],
            "type" : "enrd_sfr",
            "bundle" : { "value" : { "enrd_sfr_pub_contact_ehd" : "enrd_sfr_pub_contact_ehd" } }
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "publication@ruralevaluation.eu",
            "subject" : "Request to [enrd-sfr:field-enrd-sfr-pub-contehd-reas] #[enrd-sfr:sfrid]",
            "message" : "The new contact request #[enrd-sfr:sfrid] has been submitted:\\r\\n\\r\\nName: [enrd-sfr:field-enrd-sfr-pub-contehd-name]\\r\\nSurname: [enrd-sfr:field-enrd-sfr-pub-contehd-surn]\\r\\nEmail: [enrd-sfr:field-enrd-sfr-pub-contehd-email]\\r\\n\\r\\nRequest: [enrd-sfr:field-enrd-sfr-pub-contehd-reas]\\r\\nComments provided by the user: [enrd-sfr:field-enrd-sfr-pub-contehd-not] [enrd-sfr:field-enrd-sfr-pub-contehd-modif]",
            "from" : "[site:mail]",
            "language" : [ "enrd-sfr:type" ]
          }
        }
      ]
    }
  }');
  $items['rules_enrd_subscription_form_requests_finalize_ehd_subscription'] = entity_import('rules_config', '{ "rules_enrd_subscription_form_requests_finalize_ehd_subscription" : {
      "LABEL" : "ENRD Subscription Form Requests: Finalize EHD Subscription",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "4",
      "OWNER" : "rules",
      "TAGS" : [ "ENRD Subscription Form Requests" ],
      "REQUIRES" : [ "rules", "enrd_sfr" ],
      "ON" : { "enrd_sfr_finalize" : [] },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "enrd-sfr" ], "type" : "enrd_sfr" } },
        { "entity_is_of_bundle" : {
            "entity" : [ "enrd-sfr" ],
            "type" : "enrd_sfr",
            "bundle" : { "value" : { "enrd_sfr_pub_subscribe_ehd" : "enrd_sfr_pub_subscribe_ehd" } }
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "publication@ruralevaluation.eu",
            "subject" : "Request to subscribe #[enrd-sfr:sfrid]",
            "message" : "The new subscription request #[enrd-sfr:sfrid] has been submitted. You can check it on the Evaluation Helpdesk\\u0027s Publications Subscriptions list admin page: [site:base-url]\\/admin\\/content\\/enrd-sfr\\/ehd\\/subscriptions",
            "from" : "[site:mail]",
            "language" : [ "enrd-sfr:type" ]
          }
        }
      ]
    }
  }');
  return $items;
}
