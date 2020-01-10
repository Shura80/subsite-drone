<?php

/**
 * @file
 * enrd_mastermind.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enrd_mastermind_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "apachesolr_search" && $api == "apachesolr_search_defaults") {
    return array("version" => "3");
  }
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
  if ($module == "captcha" && $api == "captcha") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function enrd_mastermind_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function enrd_mastermind_image_default_styles() {
  $styles = array();

  // Exported image style: at_a_glance.
  $styles['at_a_glance'] = array(
    'label' => 'at_a_glance',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 300,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_default_message_type().
 */
function enrd_mastermind_default_message_type() {
  $items = array();
  $items['enrd_content_deletion'] = entity_import('message_type', '{
    "name" : "enrd_content_deletion",
    "description" : "ENRD content deletion",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 1, "enabled" : 1, "quota" : "", "days" : "90" }
    },
    "language" : "en",
    "arguments" : [],
    "message_text" : { "en" : [
        {
          "value" : "\\u003Cp\\u003EThe @{message:field-node-ref:content-type}: \\u003Cstrong\\u003E@{message:field-node-ref:title-field}\\u003C\\/strong\\u003E has been deleted by @{current-user:name}\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "\\u003Cp\\u003E@{message:field-node-ref:content-type}\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "\\u003Cp\\u003E@{message:field-node-ref:title-field}\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "\\u003Cp\\u003E@{current-user:name}\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        }
      ]
    },
    "_drafty_revision_requested" : "FIELD_LOAD_CURRENT",
    "entity_type" : "message_type",
    "rdf_mapping" : []
  }');
  $items['enrd_content_moderation'] = entity_import('message_type', '{
    "name" : "enrd_content_moderation",
    "description" : "ENRD content moderation",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 1, "enabled" : 1, "quota" : "", "days" : "90" }
    },
    "language" : "en",
    "arguments" : [],
    "message_text" : { "en" : [
        {
          "value" : "\\u003Cp\\u003EThe @{message:field-node-ref:content-type}: \\u003Cstrong\\u003E\\u003Ca href=\\u0022[message:field-node-ref:url]\\u0022\\u003E@{message:field-node-ref:title-field}\\u003C\\/a\\u003E\\u003C\\/strong\\u003E has changed moderation state\\u0026nbsp;from\\u0026nbsp;\\u003Cem\\u003E@{message:field-node-ref:revision-from-state}\\u003C\\/em\\u003E\\u0026nbsp;to\\u0026nbsp;\\u003Cem\\u003E@{message:field-node-ref:revision-to-state}\\u003C\\/em\\u003E\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "\\u003Cp\\u003E@{message:field-node-ref:content-type}\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022[message:field-node-ref:url]\\u0022\\u003E@{message:field-node-ref:title-field}\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "\\u003Cp\\u003E@{message:field-node-ref:revision-author}\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        { "value" : "", "format" : "full_html" },
        {
          "value" : "\\u003Cp\\u003E@{message:field-node-ref:revision-from-state}\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "\\u003Cp\\u003E@{message:field-node-ref:revision-to-state}\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        }
      ]
    },
    "_drafty_revision_requested" : "FIELD_LOAD_CURRENT",
    "entity_type" : "message_type",
    "rdf_mapping" : []
  }');
  $items['enrd_content_moderation_as_draft'] = entity_import('message_type', '{
    "name" : "enrd_content_moderation_as_draft",
    "description" : "ENRD content moderation as Draft",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 1, "enabled" : 1, "quota" : "", "days" : "90" }
    },
    "language" : "en",
    "arguments" : [],
    "message_text" : { "en" : [
        {
          "value" : "\\u003Cp\\u003EA \\u003Cem\\u003EDraft\\u003C\\/em\\u003E\\u0026nbsp;of the @{message:field-node-ref:content-type}:\\u0026nbsp;\\u003Cstrong\\u003E\\u003Ca href=\\u0022[message:field-node-ref:url]\\u0022\\u003E@{message:field-node-ref:title-field}\\u003C\\/a\\u003E\\u003C\\/strong\\u003E\\u0026nbsp;has been created by @{message:field-node-ref:revision-author}\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "\\u003Cp\\u003E@{message:field-node-ref:content-type}\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022[message:field-node-ref:url]\\u0022\\u003E@{message:field-node-ref:title-field}\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "\\u003Cp\\u003E@{message:field-node-ref:revision-author}\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        }
      ]
    },
    "_drafty_revision_requested" : "FIELD_LOAD_CURRENT",
    "entity_type" : "message_type",
    "rdf_mapping" : []
  }');
  $items['enrd_content_update'] = entity_import('message_type', '{
    "name" : "enrd_content_update",
    "description" : "ENRD content update",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 1, "enabled" : 1, "quota" : "", "days" : "90" }
    },
    "language" : "en",
    "arguments" : [],
    "message_text" : { "en" : [
        {
          "value" : "\\u003Cp\\u003EThe @{message:field-node-ref:content-type}: \\u003Cstrong\\u003E\\u003Ca href=\\u0022[message:field-node-ref:url]\\u0022\\u003E@{message:field-node-ref:title-field}\\u003C\\/a\\u003E\\u003C\\/strong\\u003E has been updated by @{message:field-node-ref:revision-author}\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "\\u003Cp\\u003E@{message:field-node-ref:content-type}\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022[message:field-node-ref:url]\\u0022\\u003E@{message:field-node-ref:title-field}\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "\\u003Cp\\u003E@{message:field-node-ref:revision-author}\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        }
      ]
    },
    "_drafty_revision_requested" : "FIELD_LOAD_CURRENT",
    "entity_type" : "message_type",
    "rdf_mapping" : []
  }');
  $items['enrd_new_content_creation'] = entity_import('message_type', '{
    "name" : "enrd_new_content_creation",
    "description" : "ENRD new content creation",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 1, "enabled" : 1, "quota" : "", "days" : "90" }
    },
    "language" : "en",
    "arguments" : [],
    "message_text" : { "en" : [
        {
          "value" : "\\u003Cp\\u003EA new @{message:field-node-ref:content-type}: \\u003Cstrong\\u003E\\u003Ca href=\\u0022[message:field-node-ref:url]\\u0022\\u003E@{message:field-node-ref:title-field}\\u003C\\/a\\u003E \\u003C\\/strong\\u003Ehas been created by @{message:field-node-ref:author}\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "\\u003Cp\\u003E@{message:field-node-ref:content-type}\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022[message:field-node-ref:url]\\u0022\\u003E@{message:field-node-ref:title-field}\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "\\u003Cp\\u003E@{message:field-node-ref:author}\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        }
      ]
    },
    "_drafty_revision_requested" : "FIELD_LOAD_CURRENT",
    "entity_type" : "message_type",
    "rdf_mapping" : []
  }');
  $items['enrd_og_content_deletion'] = entity_import('message_type', '{
    "name" : "enrd_og_content_deletion",
    "description" : "ENRD OG content deletion",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 1, "enabled" : 1, "quota" : "", "days" : "90" }
    },
    "language" : "en",
    "arguments" : [],
    "message_text" : { "en" : [
        {
          "value" : "\\u003Cp\\u003EThe @{message:field-node-ref:content-type}: \\u003Cstrong\\u003E@{message:field-node-ref:title-field}\\u003C\\/strong\\u003E has been deleted by @{current-user:name} in group @{message:field-node-ref:og-group-ref}\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "\\u003Cp\\u003E@{message:field-node-ref:content-type}\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "\\u003Cp\\u003E@{message:field-node-ref:title-field}\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "\\u003Cp\\u003E@{current-user:name}\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "\\u003Cp\\u003E@{message:field-node-ref:og-group-ref}\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        }
      ]
    },
    "_drafty_revision_requested" : "FIELD_LOAD_CURRENT",
    "entity_type" : "message_type",
    "rdf_mapping" : []
  }');
  $items['enrd_og_content_update'] = entity_import('message_type', '{
    "name" : "enrd_og_content_update",
    "description" : "ENRD OG content update",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 1, "enabled" : 1, "quota" : "", "days" : "90" }
    },
    "language" : "en",
    "arguments" : [],
    "message_text" : { "en" : [
        {
          "value" : "\\u003Cp\\u003EThe @{message:field-node-ref:content-type}: \\u003Cstrong\\u003E\\u003Ca href=\\u0022[message:field-node-ref:url]\\u0022\\u003E@{message:field-node-ref:title-field}\\u003C\\/a\\u003E\\u003C\\/strong\\u003E has been updated by @{message:field-node-ref:revision-author} in group @{message:field-node-ref:og-group-ref}\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "\\u003Cp\\u003E@{message:field-node-ref:content-type}\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022[message:field-node-ref:url]\\u0022\\u003E@{message:field-node-ref:title-field}\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "\\u003Cp\\u003E@{message:field-node-ref:revision-author}\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "\\u003Cp\\u003E@{message:field-node-ref:og-group-ref}\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        }
      ]
    },
    "_drafty_revision_requested" : "FIELD_LOAD_CURRENT",
    "entity_type" : "message_type",
    "rdf_mapping" : []
  }');
  $items['enrd_og_new_content_creation'] = entity_import('message_type', '{
    "name" : "enrd_og_new_content_creation",
    "description" : "ENRD OG new content creation",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 1, "enabled" : 1, "quota" : "", "days" : "90" }
    },
    "language" : "en",
    "arguments" : [],
    "message_text" : { "en" : [
        {
          "value" : "\\u003Cp\\u003EA new @{message:field-node-ref:content-type} \\u003Cstrong\\u003E\\u003Ca href=\\u0022[message:field-node-ref:url]\\u0022\\u003E@{message:field-node-ref:title-field}\\u003C\\/a\\u003E\\u003C\\/strong\\u003E has been created by @{message:field-node-ref:author} in group @{message:field-node-ref:og-group-ref}\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "\\u003Cp\\u003E@{message:field-node-ref:content-type}\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022[message:field-node-ref:url]\\u0022\\u003E@{message:field-node-ref:title-field}\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "\\u003Cp\\u003E@{message:field-node-ref:author}\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "\\u003Cp\\u003E@{message:field-node-ref:og-group-ref}\\u003C\\/p\\u003E\\r\\n",
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

/**
 * Implements hook_node_info().
 */
function enrd_mastermind_node_info() {
  $items = array(
    'focus_group' => array(
      'name' => t('Focus group'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'organization' => array(
      'name' => t('Organization'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Webform'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
