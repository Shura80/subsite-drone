<?php

/**
 * @file
 * agri_projects.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function agri_projects_ctools_plugin_api($module = NULL, $api = NULL) {
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
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function agri_projects_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function agri_projects_flag_default_flags() {
  $flags = array();
  // Exported flag: "Manage privacy policy".
  $flags['agri_privacy_policy'] = array(
    'entity_type' => 'node',
    'title' => 'Manage privacy policy',
    'global' => 1,
    'types' => array(
      0 => 'project',
    ),
    'flag_short' => 'Hide Project Partners\' information',
    'flag_long' => 'Hide Project Partners\' information on this item',
    'flag_message' => '',
    'unflag_short' => 'Show Project Partners\' information',
    'unflag_long' => 'Show Project Partners\' information on this item',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'normal',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 0,
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
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'agri_projects',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function agri_projects_node_info() {
  $items = array(
    'innovative_action' => array(
      'name' => t('Innovative action'),
      'base' => 'node_content',
      'description' => t('Publish innovative actions ran by farmers or other stakeholders.'),
      'has_title' => '1',
      'title_label' => t('Name of innovative action or project (original language)'),
      'help' => '',
    ),
    'needs_for_research_from_practice' => array(
      'name' => t('Needs for research from practice'),
      'base' => 'node_content',
      'description' => t('Publish your need for scientific research, coming from your day-per-day practice.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'operational_group' => array(
      'name' => t('Operational group'),
      'base' => 'node_content',
      'description' => t('Operational group content type'),
      'has_title' => '1',
      'title_label' => t('Group name (original language)'),
      'help' => '',
    ),
    'project' => array(
      'name' => t('Project'),
      'base' => 'node_content',
      'description' => t('Project content type.'),
      'has_title' => '1',
      'title_label' => t('Title (native language)'),
      'help' => '',
    ),
    'project_ideas' => array(
      'name' => t('Project ideas'),
      'base' => 'node_content',
      'description' => t('Project ideas content type.'),
      'has_title' => '1',
      'title_label' => t('Title (native language)'),
      'help' => '',
    ),
    'research_project' => array(
      'name' => t('Research project'),
      'base' => 'node_content',
      'description' => t('Publish a research project.'),
      'has_title' => '1',
      'title_label' => t('Project name (original language)'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
