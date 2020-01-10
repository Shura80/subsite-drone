<?php

/**
 * @file
 * enrd_mastermind.features.workbench_moderation_states.inc
 */

/**
 * Implements hook_workbench_moderation_export_states().
 */
function enrd_mastermind_workbench_moderation_export_states() {
  $items = array(
    'archived' => (object) array(
      'name' => 'archived',
      'label' => 'Archived',
      'description' => 'Content is not published anymore',
      'weight' => 100,
    ),
    'draft' => (object) array(
      'name' => 'draft',
      'label' => 'Draft',
      'description' => 'Work in progress',
      'weight' => -99,
    ),
    'needs_review' => (object) array(
      'name' => 'needs_review',
      'label' => 'Needs Review',
      'description' => 'Ready for moderation',
      'weight' => 0,
    ),
    'published' => (object) array(
      'name' => 'published',
      'label' => 'Published',
      'description' => 'Make this version live',
      'weight' => 99,
    ),
    'ready_to_be_published' => (object) array(
      'name' => 'ready_to_be_published',
      'label' => 'Ready to be published',
      'description' => 'Content is ready to be published',
      'weight' => -6,
    ),
    'validated' => (object) array(
      'name' => 'validated',
      'label' => 'Validated',
      'description' => 'Approved by administrator',
      'weight' => 10,
    ),
  );
  return $items;
}
