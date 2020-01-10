<?php

/**
 * @file
 * enrd_mastermind.features.workbench_moderation_transitions.inc
 */

/**
 * Implements hook_workbench_moderation_export_transitions().
 */
function enrd_mastermind_workbench_moderation_export_transitions() {
  $items = array(
    'archived:draft' => (object) array(
      'from_name' => 'archived',
      'to_name' => 'draft',
      'name' => 'Create new Draft',
    ),
    'archived:ready_to_be_published' => (object) array(
      'from_name' => 'archived',
      'to_name' => 'ready_to_be_published',
      'name' => 'Ready to be published	',
    ),
    'draft:needs_review' => (object) array(
      'from_name' => 'draft',
      'to_name' => 'needs_review',
      'name' => 'Submit for Review',
    ),
    'draft:ready_to_be_published' => (object) array(
      'from_name' => 'draft',
      'to_name' => 'ready_to_be_published',
      'name' => 'Ask for publishing',
    ),
    'needs_review:draft' => (object) array(
      'from_name' => 'needs_review',
      'to_name' => 'draft',
      'name' => 'Reject',
    ),
    'needs_review:published' => (object) array(
      'from_name' => 'needs_review',
      'to_name' => 'published',
      'name' => 'Publish',
    ),
    'needs_review:validated' => (object) array(
      'from_name' => 'needs_review',
      'to_name' => 'validated',
      'name' => 'Validate',
    ),
    'published:archived' => (object) array(
      'from_name' => 'published',
      'to_name' => 'archived',
      'name' => 'Archive',
    ),
    'ready_to_be_published:draft' => (object) array(
      'from_name' => 'ready_to_be_published',
      'to_name' => 'draft',
      'name' => 'Reject publication',
    ),
    'ready_to_be_published:published' => (object) array(
      'from_name' => 'ready_to_be_published',
      'to_name' => 'published',
      'name' => 'Publish',
    ),
    'validated:published' => (object) array(
      'from_name' => 'validated',
      'to_name' => 'published',
      'name' => 'Publish',
    ),
  );
  return $items;
}
