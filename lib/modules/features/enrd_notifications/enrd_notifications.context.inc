<?php

/**
 * @file
 * enrd_notifications.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function enrd_notifications_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_notifications_panel';
  $context->description = 'Shows the block that contents the notifications panel dropdown.';
  $context->tag = 'ENRD Notifications';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        'enrd_sitewide' => 'enrd_sitewide',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'enrd_notifications-enrd_notifications_panel' => array(
          'module' => 'enrd_notifications',
          'delta' => 'enrd_notifications_panel',
          'region' => 'tools_buttons',
          'weight' => '-90',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('ENRD Notifications');
  t('Shows the block that contents the notifications panel dropdown.');
  $export['enrd_notifications_panel'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_notifications_settings_panel';
  $context->description = 'Shows Flag tabs in Notifications settings panel.';
  $context->tag = 'ENRD Notifications';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'user/*/notifications/settings' => 'user/*/notifications/settings',
        'user/*/notifications/settings*' => 'user/*/notifications/settings*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'quicktabs-enrd_notifications_settings' => array(
          'module' => 'quicktabs',
          'delta' => 'enrd_notifications_settings',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('ENRD Notifications');
  t('Shows Flag tabs in Notifications settings panel.');
  $export['enrd_notifications_settings_panel'] = $context;

  return $export;
}
