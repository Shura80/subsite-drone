<?php

/**
 * @file
 * enrd_focus_on.entityqueue_default.inc
 */

/**
 * Implements hook_entityqueue_default_queues().
 */
function enrd_focus_on_entityqueue_default_queues() {
  $export = array();

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'focus_on_home_page_slider';
  $queue->label = 'Focus on - Home page slider';
  $queue->language = 'en';
  $queue->handler = 'simple';
  $queue->target_type = 'node';
  $queue->settings = array(
    'target_bundles' => array(
      'focus_on' => 'focus_on',
    ),
    'min_size' => '0',
    'max_size' => '6',
    'act_as_queue' => 1,
  );
  $export['focus_on_home_page_slider'] = $queue;

  return $export;
}
