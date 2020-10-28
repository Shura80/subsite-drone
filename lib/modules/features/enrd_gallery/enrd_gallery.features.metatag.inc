<?php

/**
 * @file
 * enrd_gallery.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function enrd_gallery_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node:gallery.
  $config['node:gallery'] = array(
    'instance' => 'node:gallery',
    'disabled' => FALSE,
    'config' => array(
      'robots' => array(
        'value' => array(
          'noindex' => 'noindex',
          'index' => 0,
          'follow' => 0,
          'nofollow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
          'noydir' => 0,
          'noimageindex' => 0,
          'notranslate' => 0,
        ),
      ),
      'revisit-after' => array(
        'value' => 15,
        'period' => '',
      ),
    ),
  );

  return $config;
}
