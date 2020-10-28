<?php

/**
 * @file
 * enrd_notifications.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enrd_notifications_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "enrd_notifications" && $api == "notifier") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function enrd_notifications_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function enrd_notifications_flag_default_flags() {
  $flags = array();
  // Exported flag: "ENRD Email Cooperation Offers".
  $flags['email_cooperation_offers'] = array(
    'entity_type' => 'user',
    'title' => 'ENRD Email Cooperation Offers',
    'global' => 0,
    'types' => array(),
    'flag_short' => 'Send email',
    'flag_long' => 'Check this option to be notified by email',
    'flag_message' => '',
    'unflag_short' => 'Don\'t send email',
    'unflag_long' => 'Uncheck this option to not receive email notifications',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'show_on_profile' => 0,
    'access_uid' => '',
    'module' => 'enrd_notifications',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "ENRD Email Events".
  $flags['email_events'] = array(
    'entity_type' => 'user',
    'title' => 'ENRD Email Events',
    'global' => 0,
    'types' => array(),
    'flag_short' => 'Send email',
    'flag_long' => 'Check this option to be notified by email',
    'flag_message' => '',
    'unflag_short' => 'Don\'t send email',
    'unflag_long' => 'Uncheck this option to not receive email notifications',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'show_on_profile' => 0,
    'access_uid' => '',
    'module' => 'enrd_notifications',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "ENRD Email LAGs".
  $flags['email_lags'] = array(
    'entity_type' => 'node',
    'title' => 'ENRD Email LAGs',
    'global' => 0,
    'types' => array(
      0 => 'lag',
    ),
    'flag_short' => 'Send email',
    'flag_long' => 'Check this option to be notified by email',
    'flag_message' => '',
    'unflag_short' => 'Don\'t send email',
    'unflag_long' => 'Uncheck this option to not receive email notifications',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'diff_standard' => 0,
      'gallery' => 0,
      'newsroom' => 0,
      'eventlist' => 0,
      'print' => 0,
      'token' => 0,
      'enrd_lag_database_shared_info' => 0,
      'enrd_nrn_toolkit_resource' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'enrd_notifications',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "ENRD Email News".
  $flags['email_news'] = array(
    'entity_type' => 'user',
    'title' => 'ENRD Email News',
    'global' => 0,
    'types' => array(),
    'flag_short' => 'Send email',
    'flag_long' => 'Check this option to be notified by email',
    'flag_message' => '',
    'unflag_short' => 'Don\'t send email',
    'unflag_long' => 'Uncheck this option to not receive email notifications',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'show_on_profile' => 0,
    'access_uid' => '',
    'module' => 'enrd_notifications',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "ENRD Follow Cooperation Offers".
  $flags['enrd_follow_cooperation_offers'] = array(
    'entity_type' => 'user',
    'title' => 'ENRD Follow Cooperation Offers',
    'global' => 0,
    'types' => array(),
    'flag_short' => 'Follow',
    'flag_long' => 'Click to follow LAGs\' Cooperation Offers',
    'flag_message' => '',
    'unflag_short' => 'Following',
    'unflag_long' => 'Click to unfollow LAGs\' Cooperation Offers',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'show_on_profile' => 0,
    'access_uid' => '',
    'module' => 'enrd_notifications',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "ENRD Follow Events".
  $flags['enrd_follow_events'] = array(
    'entity_type' => 'user',
    'title' => 'ENRD Follow Events',
    'global' => 0,
    'types' => array(),
    'flag_short' => 'Follow',
    'flag_long' => 'Click to follow site\'s events',
    'flag_message' => '',
    'unflag_short' => 'Following',
    'unflag_long' => 'Click to unfollow site\'s events',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'show_on_profile' => 0,
    'access_uid' => '',
    'module' => 'enrd_notifications',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "ENRD Follow LAGs".
  $flags['enrd_follow_lags'] = array(
    'entity_type' => 'node',
    'title' => 'ENRD Follow LAGs',
    'global' => 0,
    'types' => array(
      0 => 'lag',
    ),
    'flag_short' => 'Follow',
    'flag_long' => 'Click to follow this LAG\'s updates',
    'flag_message' => '',
    'unflag_short' => 'Following',
    'unflag_long' => 'Click to unfollow updates from this LAG',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'diff_standard' => 0,
      'gallery' => 0,
      'newsroom' => 0,
      'eventlist' => 0,
      'print' => 0,
      'token' => 0,
      'enrd_lag_database_shared_info' => 0,
      'enrd_nrn_toolkit_resource' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'enrd_notifications',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "ENRD Follow News".
  $flags['enrd_follow_news'] = array(
    'entity_type' => 'user',
    'title' => 'ENRD Follow News',
    'global' => 0,
    'types' => array(),
    'flag_short' => 'Follow',
    'flag_long' => 'Click to follow site\'s news',
    'flag_message' => '',
    'unflag_short' => 'Following',
    'unflag_long' => 'Click to unfollow site\'s news',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'show_on_profile' => 0,
    'access_uid' => '',
    'module' => 'enrd_notifications',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "ENRD Message Read/Unread".
  $flags['enrd_message_read_unread'] = array(
    'entity_type' => 'message',
    'title' => 'ENRD Message Read/Unread',
    'global' => 0,
    'types' => array(
      0 => 'enrd_notifications_content_publication_no_groups',
      1 => 'enrd_notifications_lag_content_publication',
    ),
    'flag_short' => 'Read',
    'flag_long' => 'Click to mark message as read',
    'flag_message' => '',
    'unflag_short' => 'Not read',
    'unflag_long' => 'Click to mark message as not read',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(),
    'show_as_field' => FALSE,
    'show_on_form' => FALSE,
    'access_author' => '',
    'show_contextual_link' => FALSE,
    'module' => 'enrd_notifications',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_default_message_type().
 */
function enrd_notifications_default_message_type() {
  $items = array();
  $items['enrd_notifications_content_publication_no_groups'] = entity_import('message_type', '{
    "name" : "enrd_notifications_content_publication_no_groups",
    "description" : "ENRD Notifications Content Published No Groups",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 1, "enabled" : 1, "quota" : "", "days" : "90" },
      "enrd_notifications_message_auto_delete" : { "node" : "node" }
    },
    "language" : "en",
    "arguments" : [],
    "message_text" : { "en" : [
        {
          "value" : "The new @{message:field-enrd-notif-target-nodes:content-type} \\u003Ca href=\\u0022[message:field-enrd-notif-target-nodes:url]\\u0022\\u003E@{message:field-enrd-notif-target-nodes}\\u003C\\/a\\u003E has been published.",
          "format" : "full_html"
        }
      ]
    },
    "_drafty_revision_requested" : "FIELD_LOAD_CURRENT",
    "entity_type" : "message_type",
    "rdf_mapping" : []
  }');
  $items['enrd_notifications_lag_content_publication'] = entity_import('message_type', '{
    "name" : "enrd_notifications_lag_content_publication",
    "description" : "ENRD Notifications LAG Content Publication",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 1, "enabled" : 1, "quota" : "", "days" : "90" },
      "enrd_notifications_message_auto_delete" : { "node" : "node" }
    },
    "language" : "en",
    "arguments" : [],
    "message_text" : { "en" : [
        {
          "value" : "The new [message:field-enrd-notif-target-nodes:content-type] \\u003Ca href=\\u0022[message:field-enrd-notif-target-nodes:url]\\u0022\\u003E@{message:field-enrd-notif-target-nodes}\\u003C\\/a\\u003E has been published in the \\u003Ca href=\\u0022[message:field-enrd-notif-target-nodes:og-lag-group-ref:url]\\u0022\\u003E@{message:field-enrd-notif-target-nodes:og-lag-group-ref}\\u003C\\/a\\u003E [message:field-enrd-notif-target-nodes:og-lag-group-ref:content-type]",
          "format" : "full_html"
        }
      ]
    },
    "_drafty_revision_requested" : "FIELD_LOAD_CURRENT",
    "entity_type" : "message_type",
    "rdf_mapping" : []
  }');
  return $items;
}
