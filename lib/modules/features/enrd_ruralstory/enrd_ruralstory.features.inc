<?php

/**
 * @file
 * enrd_ruralstory.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enrd_ruralstory_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function enrd_ruralstory_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_enrd_sfr_type().
 */
function enrd_ruralstory_default_enrd_sfr_type() {
  $items = array();
  $items['enrd_ruralstory'] = entity_import('enrd_sfr_type', '{
    "name" : "enrd_ruralstory",
    "label" : "ENRD Rural Story",
    "description" : "ENRD Share your Rural Story Form Submission.",
    "weight" : 0,
    "entity_type" : "enrd_sfr_type",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_flag_default_flags().
 */
function enrd_ruralstory_flag_default_flags() {
  $flags = array();
  // Exported flag: "ENRD Rural Story Submission Status".
  $flags['enrd_ruralstory_status'] = array(
    'entity_type' => 'enrd_sfr',
    'title' => 'ENRD Rural Story Submission Status',
    'global' => 1,
    'types' => array(
      0 => 'enrd_ruralstory',
    ),
    'flag_short' => 'Set status',
    'flag_long' => 'Click this option to apply or change the submission status.',
    'flag_message' => 'You have successly applied the following status: [flagging:field-enrd-ruralstory-status]',
    'unflag_short' => 'Remove status',
    'unflag_long' => 'Click this option to remove the submission status.',
    'unflag_message' => 'You have successly removed the status previously applied.',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'diff_standard' => 0,
      'token' => 0,
      'enrd_sfr_full_email' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'module' => 'enrd_ruralstory',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}
