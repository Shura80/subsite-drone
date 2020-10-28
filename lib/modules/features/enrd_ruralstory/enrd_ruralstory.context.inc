<?php

/**
 * @file
 * enrd_ruralstory.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function enrd_ruralstory_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_ruralstory_form_page';
  $context->description = 'Custom context for the ENRD Rural Story Form page.';
  $context->tag = 'ENRD Rural Story Form';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'enrd-sfr/add/enrd-ruralstory' => 'enrd-sfr/add/enrd-ruralstory',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-shareruralstoryintro' => array(
          'module' => 'bean',
          'delta' => 'shareruralstoryintro',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Custom context for the ENRD Rural Story Form page.');
  t('ENRD Rural Story Form');
  $export['enrd_ruralstory_form_page'] = $context;

  return $export;
}
