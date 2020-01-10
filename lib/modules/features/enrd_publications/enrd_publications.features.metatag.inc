<?php

/**
 * @file
 * enrd_publications.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function enrd_publications_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node:publication_ehd.
  $config['node:publication_ehd'] = array(
    'instance' => 'node:publication_ehd',
    'disabled' => FALSE,
    'config' => array(
      'dcterms.creator' => array(
        'value' => '[node:field_enrd_publ_ehd_author]',
      ),
    ),
  );

  return $config;
}
