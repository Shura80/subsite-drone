<?php

/**
 * @file
 * agri_core.features.workbench_moderation_transitions.inc
 */

/**
 * Implements hook_workbench_moderation_export_transitions().
 */
function agri_core_workbench_moderation_export_transitions() {
  $items = array(
    'needs_review:validated' => (object) array(
      'from_name' => 'needs_review',
      'to_name' => 'validated',
      'name' => 'Needs Review to Validated',
    ),
    'published:archived' => (object) array(
      'from_name' => 'published',
      'to_name' => 'archived',
      'name' => 'Published to Archived',
    ),
    'published:validated' => (object) array(
      'from_name' => 'published',
      'to_name' => 'validated',
      'name' => 'Published to Validated',
    ),
    'validated:needs_review' => (object) array(
      'from_name' => 'validated',
      'to_name' => 'needs_review',
      'name' => 'Validated to Needs Review',
    ),
    'validated:published' => (object) array(
      'from_name' => 'validated',
      'to_name' => 'published',
      'name' => 'Validated to Published',
    ),
  );
  return $items;
}
