<?php

/**
 * @file
 * agri_core.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function agri_core_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "apachesolr_search" && $api == "apachesolr_search_defaults") {
    return array("version" => "3");
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
function agri_core_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function agri_core_flag_default_flags() {
  $flags = array();
  // Exported flag: "Report forum topics".
  $flags['agri_core_report_forum_topics'] = array(
    'entity_type' => 'node',
    'title' => 'Report forum topics',
    'global' => 0,
    'types' => array(
      0 => 'forum',
    ),
    'flag_short' => 'Report topic',
    'flag_long' => 'Report this topic to admin to moderate or delete.',
    'flag_message' => 'Topic reported to admin.',
    'unflag_short' => 'Do not report this topic',
    'unflag_long' => 'Remove this topic from topics reported to admins.',
    'unflag_message' => 'Topic removed from those reported to admins.',
    'unflag_denied_text' => '',
    'link_type' => 'confirm',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'diff_standard' => 0,
      'print' => 0,
      'email_plain' => 0,
      'email_html' => 0,
      'email_textalt' => 0,
      'token' => 0,
      'core_small_teaser' => 0,
      'core_spotlight' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'flag_confirmation' => 'Are you sure you want to report this forum topic?',
    'unflag_confirmation' => 'Are you sure you want to remove this forum topic from reported content?',
    'module' => 'agri_core',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Report forum topics comments".
  $flags['agri_core_report_topic_comments'] = array(
    'entity_type' => 'comment',
    'title' => 'Report forum topics comments',
    'global' => 0,
    'types' => array(
      0 => 'comment_node_forum',
    ),
    'flag_short' => 'Report this comment',
    'flag_long' => 'Report this comment to admin to moderate or delete.',
    'flag_message' => 'Comment reported to admin.',
    'unflag_short' => 'Do not report this comment',
    'unflag_long' => 'Remove this comment from comments reported to admins.',
    'unflag_message' => 'Comment removed from those reported to admins.',
    'unflag_denied_text' => '',
    'link_type' => 'confirm',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'flag_confirmation' => 'Are you sure you want to report this forum topic comment?',
    'unflag_confirmation' => 'Are you sure you want to remove this forum topic comment from reported comments?',
    'module' => 'agri_core',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_image_default_styles().
 */
function agri_core_image_default_styles() {
  $styles = array();

  // Exported image style: agri_gallery_preview.
  $styles['agri_gallery_preview'] = array(
    'label' => 'Gallery Preview',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 200,
          'height' => 120,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: core_spotlight.
  $styles['core_spotlight'] = array(
    'label' => 'Spotlight (550x300)',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 550,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: profile_thumbnail.
  $styles['profile_thumbnail'] = array(
    'label' => 'Profile Thumbnail (150x150)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 140,
          'height' => 140,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: spotlight.
  $styles['spotlight'] = array(
    'label' => 'spotlight',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 800,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function agri_core_node_info() {
  $items = array(
    'collaborative_area' => array(
      'name' => t('Collaborative area'),
      'base' => 'node_content',
      'description' => t('Collaborative area content type.'),
      'has_title' => '1',
      'title_label' => t('Collaborative area name'),
      'help' => '',
    ),
    'gallery' => array(
      'name' => t('Gallery'),
      'base' => 'node_content',
      'description' => t('A content type to show uploaded pictures as an interactive gallery.'),
      'has_title' => '1',
      'title_label' => t('Gallery'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function agri_core_default_search_api_index() {
  $items = array();
  $items['core_node_index'] = entity_import('search_api_index', '{
    "name" : "Core node index",
    "machine_name" : "core_node_index",
    "description" : null,
    "server" : "core_database",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:value" : { "type" : "text", "boost" : "8.0" },
        "created" : { "type" : "date" },
        "field_agri_proj_internal_kwords" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_core_agricultural_sectors" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_core_geographical_area" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_core_keywords" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_core_publication_date:value" : { "type" : "date" },
        "field_core_publication_date:value2" : { "type" : "date" },
        "field_core_stakeholders" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_event_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_news_geographical_area" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_news_target_group" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_news_type_of_funding" : { "type" : "string" },
        "field_proj_additional_comments:value" : { "type" : "text" },
        "field_proj_additional_info:value" : { "type" : "text" },
        "field_proj_contact_e_mail" : { "type" : "text" },
        "field_proj_desc:value" : { "type" : "text" },
        "field_proj_desc_context:value" : { "type" : "text" },
        "field_proj_desc_eng:value" : { "type" : "text" },
        "field_proj_editor_of_text" : { "type" : "text" },
        "field_proj_funding_source_list" : { "type" : "string" },
        "field_proj_geographical_area" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_proj_is_sfc" : { "type" : "boolean" },
        "field_proj_og_budget" : { "type" : "text" },
        "field_proj_og_project_status" : { "type" : "string" },
        "field_proj_partners_categories" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_proj_problems:value" : { "type" : "text" },
        "field_proj_problems_eng:value" : { "type" : "text" },
        "field_proj_project_type" : { "type" : "string" },
        "field_proj_rp_acronym" : { "type" : "text" },
        "field_proj_sfc_identification" : { "type" : "string" },
        "field_proj_starting_date" : { "type" : "date" },
        "field_proj_title" : { "type" : "string" },
        "field_proj_title_eng" : { "type" : "text" },
        "field_projects_language" : { "type" : "string" },
        "field_projects_name" : { "type" : "text" },
        "field_publication_date" : { "type" : "date" },
        "field_publication_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_user_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "flag_agri_digitization_toolbox" : { "type" : "boolean" },
        "language" : { "type" : "string" },
        "nuts_region" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "integer" },
        "title" : { "type" : "text", "boost" : "13.0" },
        "type" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : {
              "funding_opportunities" : "funding_opportunities",
              "project" : "project",
              "publication" : "publication"
            }
          }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "field_core_keywords:parents_all" : "field_core_keywords:parents_all",
              "field_core_geographical_area:parents_all" : "field_core_geographical_area:parents_all"
            }
          }
        }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true, "field_proj_title" : true, "body:value" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "title" : 1,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 1,
          "weight" : "15",
          "settings" : { "fields" : { "title" : true, "body:value" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 1,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  $items['core_people_index'] = entity_import('search_api_index', '{
    "name" : "Core people index",
    "machine_name" : "core_people_index",
    "description" : null,
    "server" : "core_database",
    "item_type" : "user",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "created" : { "type" : "date" },
        "field_core_agricultural_sectors" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_core_geographical_area" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_core_keywords" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_core_other_location" : { "type" : "text" },
        "field_core_specify_language" : { "type" : "text" },
        "field_firstname" : { "type" : "string" },
        "field_firstname_for_searching" : { "type" : "text" },
        "field_lastname" : { "type" : "string" },
        "field_lastname_for_searching" : { "type" : "text" },
        "field_user_address" : { "type" : "text" },
        "field_user_city" : { "type" : "text" },
        "field_user_featured_internal_db" : { "type" : "boolean" },
        "field_user_involved" : { "type" : "list\\u003Ctext\\u003E" },
        "field_user_language_spoken" : { "type" : "list\\u003Cstring\\u003E" },
        "field_user_position_civil" : { "type" : "text" },
        "field_user_position_industry" : { "type" : "text" },
        "field_user_position_rep" : { "type" : "text" },
        "field_user_position_researcher" : { "type" : "text" },
        "field_user_position_retailer" : { "type" : "text" },
        "field_user_position_whole" : { "type" : "text" },
        "field_user_sector_retailer" : { "type" : "text" },
        "field_user_sector_whole" : { "type" : "text" },
        "field_user_spec_admin_level" : { "type" : "list\\u003Ctext\\u003E" },
        "field_user_spec_advisor_other" : { "type" : "text" },
        "field_user_spec_advisor_sector" : { "type" : "list\\u003Ctext\\u003E" },
        "field_user_spec_advisor_type" : { "type" : "list\\u003Ctext\\u003E" },
        "field_user_spec_forest_other" : { "type" : "text" },
        "field_user_spec_forest_type" : { "type" : "list\\u003Ctext\\u003E" },
        "field_user_spec_forest_utilizati" : { "type" : "list\\u003Ctext\\u003E" },
        "field_user_spec_forester_type" : { "type" : "list\\u003Ctext\\u003E" },
        "field_user_spec_land_type" : { "type" : "list\\u003Ctext\\u003E" },
        "field_user_spec_land_type_other" : { "type" : "text" },
        "field_user_spec_media_type" : { "type" : "list\\u003Ctext\\u003E" },
        "field_user_spec_portfolio" : { "type" : "text" },
        "field_user_spec_position" : { "type" : "text" },
        "field_user_spec_rdp" : { "type" : "text" },
        "field_user_spec_sector" : { "type" : "text" },
        "field_user_spec_sector_other" : { "type" : "text" },
        "field_user_spec_size" : { "type" : "text" },
        "field_user_spec_size_farm_land" : { "type" : "string" },
        "field_user_spec_type" : { "type" : "list\\u003Ctext\\u003E" },
        "field_user_spec_type_other" : { "type" : "text" },
        "field_user_specify_media" : { "type" : "text" },
        "field_user_specify_other" : { "type" : "text" },
        "field_user_specify_ret" : { "type" : "text" },
        "field_user_specify_whole" : { "type" : "text" },
        "field_user_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "mail" : { "type" : "text" },
        "name" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "integer" },
        "uid" : { "type" : "integer" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_role_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "0", "roles" : { "2" : "2" } }
        },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "field_firstname" : true, "field_lastname" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "field_firstname" : true, "field_lastname" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 1,
          "weight" : "15",
          "settings" : { "fields" : { "field_firstname" : true, "field_lastname" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : { "field_firstname" : true, "field_lastname" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "field_firstname" : true, "field_lastname" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_saved_searches_settings().
 */
function agri_core_default_search_api_saved_searches_settings() {
  $items = array();
  $items['core_node_index'] = entity_import('search_api_saved_searches_settings', '{
    "delta" : "core_node_index",
    "index_id" : "core_node_index",
    "enabled" : "1",
    "options" : {
      "date_field" : "",
      "description" : "",
      "default_true" : "1",
      "ids_list" : [],
      "registered_choose_mail" : 0,
      "choose_name" : 1,
      "registered_user_delete_key" : 1,
      "show_empty_list" : 1,
      "user_select_interval" : 1,
      "interval_options" : { "86400" : "Daily", "604800" : "Weekly" },
      "set_interval" : "86400",
      "mail" : {
        "activate" : {
          "send" : 1,
          "title" : "Activate your saved search at [site:name]",
          "body" : "A saved search on [site:name] with this e-mail address was created.\\r\\nTo activate this saved search, click the following link:\\r\\n\\r\\n[search-api-saved-search:activate-url]\\r\\n\\r\\nIf you didn\\u0027t create this saved search, just ignore this mail and it will be deleted.\\r\\n\\r\\n--  [site:name] team"
        },
        "notify" : {
          "title" : "New results for your saved search at [site:name]",
          "body" : "[user:name],\\r\\n\\r\\nThere are new results for your saved search on [site:name]:\\r\\n\\r\\n[search-api-saved-searches:results]\\r\\n\\r\\nYou can configure your saved searches at the following address:\\r\\n[user:search-api-saved-searches-url]\\r\\n\\r\\n--  [site:name] team",
          "results" : "New results for search \\u0022[search-api-saved-search:name]\\u0022:\\r\\n[search-api-saved-search:items]\\r\\n[search-api-saved-search:results-capped]",
          "result" : "[search-api-saved-search-result:label] ([search-api-saved-search-result:url])",
          "max_results" : "0",
          "results_capped" : "\\u2026\\r\\nView all results: [search-api-saved-search:view-url]"
        }
      },
      "manual" : {
        "allow" : 0,
        "fulltext" : 0,
        "fields" : [],
        "page" : { "path" : "", "fulltext" : "", "direct_filter_params" : "0" }
      }
    },
    "rdf_mapping" : []
  }');
  $items['core_people_index'] = entity_import('search_api_saved_searches_settings', '{
    "delta" : "core_people_index",
    "index_id" : "core_people_index",
    "enabled" : "1",
    "options" : {
      "date_field" : "",
      "description" : "",
      "registered_choose_mail" : 0,
      "choose_name" : 1,
      "registered_user_delete_key" : 1,
      "show_empty_list" : 1,
      "default_true" : true,
      "ids_list" : [],
      "user_select_interval" : 1,
      "interval_options" : { "86400" : "Daily", "604800" : "Weekly" },
      "set_interval" : "86400",
      "mail" : {
        "activate" : {
          "send" : 1,
          "title" : "Activate your saved search at [site:name]",
          "body" : "A saved search on [site:name] with this e-mail address was created.\\r\\nTo activate this saved search, click the following link:\\r\\n\\r\\n[search-api-saved-search:activate-url]\\r\\n\\r\\nIf you didn\\u0027t create this saved search, just ignore this mail and it will be deleted.\\r\\n\\r\\n--  [site:name] team"
        },
        "notify" : {
          "title" : "New results for your saved search at [site:name]",
          "body" : "[user:name],\\r\\n\\r\\nThere are new results for your saved search on [site:name]:\\r\\n\\r\\n[search-api-saved-searches:results]\\r\\n\\r\\nYou can configure your saved searches at the following address:\\r\\n[user:search-api-saved-searches-url]\\r\\n\\r\\n--  [site:name] team",
          "results" : "New results for search \\u0022[search-api-saved-search:name]\\u0022:\\r\\n[search-api-saved-search:items]\\r\\n[search-api-saved-search:results-capped]",
          "result" : "[search-api-saved-search-result:label] ([search-api-saved-search-result:url])",
          "max_results" : "0",
          "results_capped" : "\\u2026\\r\\nView all results: [search-api-saved-search:view-url]"
        }
      },
      "manual" : {
        "allow" : 0,
        "fulltext" : 0,
        "fields" : [],
        "page" : { "path" : "", "fulltext" : "", "direct_filter_params" : "0" }
      }
    },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function agri_core_default_search_api_server() {
  $items = array();
  $items['core_database'] = entity_import('search_api_server', '{
    "name" : "Core Database",
    "machine_name" : "core_database",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "2",
      "indexes" : {
        "core_node_index" : {
          "type" : {
            "table" : "search_api_db_core_node_index",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_core_node_index_text",
            "type" : "text",
            "boost" : "13.0"
          },
          "language" : {
            "table" : "search_api_db_core_node_index",
            "column" : "language",
            "type" : "string",
            "boost" : "1.0"
          },
          "status" : {
            "table" : "search_api_db_core_node_index",
            "column" : "status",
            "type" : "integer",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_core_node_index",
            "column" : "created",
            "type" : "date",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_core_node_index",
            "column" : "author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_core_keywords" : {
            "table" : "search_api_db_core_node_index_field_core_keywords",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_core_geographical_area" : {
            "table" : "search_api_db_core_node_index_field_core_geographical_area",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_core_agricultural_sectors" : {
            "table" : "search_api_db_core_node_index_field_core_agricultural_sectors",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_news_target_group" : {
            "table" : "search_api_db_core_node_index_field_news_target_group",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_news_type_of_funding" : {
            "table" : "search_api_db_core_node_index",
            "column" : "field_news_type_of_funding",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_news_geographical_area" : {
            "table" : "search_api_db_core_node_index_field_news_geographical_area",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_projects_name" : {
            "table" : "search_api_db_core_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_projects_language" : {
            "table" : "search_api_db_core_node_index",
            "column" : "field_projects_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_user_type" : {
            "table" : "search_api_db_core_node_index_field_user_type",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_event_type" : {
            "table" : "search_api_db_core_node_index",
            "column" : "field_event_type",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_publication_date" : {
            "table" : "search_api_db_core_node_index",
            "column" : "field_publication_date",
            "type" : "date",
            "boost" : "1.0"
          },
          "field_publication_type" : {
            "table" : "search_api_db_core_node_index",
            "column" : "field_publication_type",
            "type" : "integer",
            "boost" : "1.0"
          },
          "nuts_region" : {
            "table" : "search_api_db_core_node_index",
            "column" : "nuts_region",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_proj_contact_e_mail" : {
            "table" : "search_api_db_core_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_proj_funding_source_list" : {
            "table" : "search_api_db_core_node_index",
            "column" : "field_proj_funding_source_list",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_proj_geographical_area" : {
            "table" : "search_api_db_core_node_index_field_proj_geographical_area",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_proj_partners_categories" : {
            "table" : "search_api_db_core_node_index_field_proj_partners_categories",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_proj_project_type" : {
            "table" : "search_api_db_core_node_index",
            "column" : "field_proj_project_type",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_proj_rp_acronym" : {
            "table" : "search_api_db_core_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_proj_title_eng" : {
            "table" : "search_api_db_core_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_proj_editor_of_text" : {
            "table" : "search_api_db_core_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_core_node_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_core_node_index_text",
            "type" : "text",
            "boost" : "8.0"
          },
          "field_core_publication_date:value" : {
            "table" : "search_api_db_core_node_index",
            "column" : "field_core_publication_date_value",
            "type" : "date",
            "boost" : "1.0"
          },
          "field_core_publication_date:value2" : {
            "table" : "search_api_db_core_node_index",
            "column" : "field_core_publication_date_value2",
            "type" : "date",
            "boost" : "1.0"
          },
          "field_proj_og_budget" : {
            "table" : "search_api_db_core_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_proj_og_project_status" : {
            "table" : "search_api_db_core_node_index",
            "column" : "field_proj_og_project_status",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_proj_starting_date" : {
            "table" : "search_api_db_core_node_index",
            "column" : "field_proj_starting_date",
            "type" : "date",
            "boost" : "1.0"
          },
          "field_proj_is_sfc" : {
            "table" : "search_api_db_core_node_index",
            "column" : "field_proj_is_sfc",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "field_core_stakeholders" : {
            "table" : "search_api_db_core_node_index_field_core_stakeholders",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_proj_sfc_identification" : {
            "table" : "search_api_db_core_node_index",
            "column" : "field_proj_sfc_identification",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_proj_additional_info:value" : {
            "table" : "search_api_db_core_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_proj_desc:value" : {
            "table" : "search_api_db_core_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_proj_desc_eng:value" : {
            "table" : "search_api_db_core_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_proj_problems:value" : {
            "table" : "search_api_db_core_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_proj_problems_eng:value" : {
            "table" : "search_api_db_core_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_proj_additional_comments:value" : {
            "table" : "search_api_db_core_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_proj_desc_context:value" : {
            "table" : "search_api_db_core_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "flag_agri_digitization_toolbox" : {
            "table" : "search_api_db_core_node_index",
            "column" : "flag_agri_digitization_toolbox",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "field_agri_proj_internal_kwords" : {
            "table" : "search_api_db_core_node_index_field_agri_proj_internal_kwords",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_proj_title" : {
            "table" : "search_api_db_core_node_index",
            "column" : "field_proj_title",
            "type" : "string",
            "boost" : "1.0"
          }
        },
        "core_people_index" : {
          "uid" : {
            "table" : "search_api_db_core_people_index",
            "column" : "uid",
            "type" : "integer",
            "boost" : "1.0"
          },
          "name" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "mail" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_core_people_index",
            "column" : "created",
            "type" : "date",
            "boost" : "1.0"
          },
          "status" : {
            "table" : "search_api_db_core_people_index",
            "column" : "status",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_firstname_for_searching" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_lastname_for_searching" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_core_other_location" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_core_geographical_area" : {
            "table" : "search_api_db_core_people_index_field_core_geographical_area",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_firstname" : {
            "table" : "search_api_db_core_people_index",
            "column" : "field_firstname",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_lastname" : {
            "table" : "search_api_db_core_people_index",
            "column" : "field_lastname",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_core_keywords" : {
            "table" : "search_api_db_core_people_index_field_core_keywords",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_user_address" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_user_city" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_user_featured_internal_db" : {
            "table" : "search_api_db_core_people_index",
            "column" : "field_user_featured_internal_db",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "field_user_language_spoken" : {
            "table" : "search_api_db_core_people_index_field_user_language_spoken",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "field_user_spec_admin_level" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_user_spec_advisor_sector" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_user_spec_advisor_type" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_user_spec_forest_type" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_user_spec_forest_utilizati" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_user_spec_forester_type" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_user_spec_land_type" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_user_spec_media_type" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_user_spec_portfolio" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_user_spec_position" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_user_spec_rdp" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_user_spec_sector" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_user_spec_size" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_user_spec_type" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_user_specify_other" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_user_type" : {
            "table" : "search_api_db_core_people_index_field_user_type",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_user_involved" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_core_agricultural_sectors" : {
            "table" : "search_api_db_core_people_index_field_core_agricultural_sector",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_core_specify_language" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_user_spec_advisor_other" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_user_spec_forest_other" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_user_spec_land_type_other" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_user_spec_sector_other" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_user_spec_size_farm_land" : {
            "table" : "search_api_db_core_people_index",
            "column" : "field_user_spec_size_farm_land",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_user_spec_type_other" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_user_specify_media" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_user_position_civil" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_user_position_industry" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_user_position_rep" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_user_position_researcher" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_user_position_retailer" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_user_position_whole" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_user_sector_retailer" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_user_sector_whole" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_user_specify_ret" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_user_specify_whole" : {
            "table" : "search_api_db_core_people_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_core_people_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
