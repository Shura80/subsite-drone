<?php

/**
 * @file
 * enrd_multilingual.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enrd_multilingual_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function enrd_multilingual_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_tmgmt_translator().
 */
function enrd_multilingual_default_tmgmt_translator() {
  $items = array();
  $items['enrd_local_translator'] = entity_import('tmgmt_translator', '{
    "name" : "enrd_local_translator",
    "label" : "Request translation to user",
    "description" : "Request translations from enabled site users with desired translation skills (eg: English to Italian).",
    "weight" : "1",
    "plugin" : "local",
    "settings" : { "auto_accept" : 0, "allow_all" : 0 },
    "entity_type" : "tmgmt_translator",
    "rdf_mapping" : []
  }');
  $items['enrd_xliff_translator'] = entity_import('tmgmt_translator', '{
    "name" : "enrd_xliff_translator",
    "label" : "Export translation as file",
    "description" : "Export translation as a file (to be reimported once translated).",
    "weight" : "0",
    "plugin" : "file",
    "settings" : {
      "auto_accept" : 0,
      "export_format" : "xlf",
      "xliff_cdata" : 0,
      "xliff_processing" : 0,
      "allow_override" : 1,
      "scheme" : "public",
      "remote_languages_mappings" : {
        "en" : "en",
        "fr" : "fr",
        "de" : "de",
        "it" : "it",
        "es" : "es",
        "pl" : "pl"
      }
    },
    "entity_type" : "tmgmt_translator",
    "rdf_mapping" : []
  }');
  return $items;
}
