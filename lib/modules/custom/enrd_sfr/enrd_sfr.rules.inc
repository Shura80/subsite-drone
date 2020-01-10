<?php

/**
 * @file
 * Rules integration for the enrd_sfr module.
 */

/**
 * Implements hook_rules_event_info().
 */
function enrd_sfr_rules_event_info() {
  return array(
    'enrd_sfr_finalize' => array(
      'label' => t('An ENRD Subscription Form Request has been finalized'),
      'group' => t('ENRD Subscription Form Request'),
      'variables' => array(
        'enrd_sfr' => array(
          'type' => 'enrd_sfr',
          'label' => t('ENRD Sfr entity'),
        ),
      ),
    ),
  );
}
