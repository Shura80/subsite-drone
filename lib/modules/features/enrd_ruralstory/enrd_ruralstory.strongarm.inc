<?php

/**
 * @file
 * enrd_ruralstory.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function enrd_ruralstory_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_enrd_sfr__enrd_ruralstory';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'enrd_sfr_full_email' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'redirect' => array(
          'weight' => '12',
        ),
      ),
      'display' => array(
        'flag_enrd_ruralstory_status' => array(
          'full' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'enrd_sfr_full_email' => array(
            'weight' => '14',
            'visible' => FALSE,
          ),
        ),
        'field_enrd_ruralstory_back_to_report' => array(
          'full' => array(
            'weight' => '6',
            'visible' => TRUE,
          ),
          'enrd_sfr_full_email' => array(
            'weight' => '13',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_enrd_sfr__enrd_ruralstory'] = $strongarm;

  return $export;
}
