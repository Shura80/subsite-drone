<?php

/**
 * @file
 * enrd_nrn_profiles.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function enrd_nrn_profiles_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_nrn_profile';
  $context->description = 'View the list of the NRN Profile in the splash page';
  $context->tag = 'ENRD Profiles';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'networking/nrn-profiles' => 'networking/nrn-profiles',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-enrd_nrn_profile-block' => array(
          'module' => 'views',
          'delta' => 'enrd_nrn_profile-block',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('ENRD Profiles');
  t('View the list of the NRN Profile in the splash page');
  $export['enrd_nrn_profile'] = $context;

  return $export;
}
