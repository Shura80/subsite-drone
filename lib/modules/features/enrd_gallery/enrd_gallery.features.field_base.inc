<?php

/**
 * @file
 * enrd_gallery.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function enrd_gallery_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_enrd_gallery_media'.
  $field_bases['field_enrd_gallery_media'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_gallery_media',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 1,
    'module' => 'mediafield',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'media',
  );

  return $field_bases;
}
