<?php

/**
 * @file
 * Helper functions for ENRD Multilingual install.
 */

/**
 * Helper function to import string translations from source file.
 *
 * @return array
 *   Return an array of string keyed by source string.
 */
function _enrd_multilingual_get_strings() {
  $path = drupal_get_path('module', 'enrd_multilingual') . '/data/enrd_multilingual.strings.json';
  $strings = drupal_json_decode(file_get_contents($path));
  $strings = reset($strings);

  return $strings['translations'];
}

/**
 * Helper function to set a string translation in multiple languages.
 */
function _enrd_multilingual_translate_strings() {

  // Get an array with list of source strings and translations.
  $strings = _enrd_multilingual_get_strings();
  $sources = array_keys(_enrd_multilingual_get_strings());

  // Initialize the array summarizing the number of changes done.
  $report = [
    'skips' => 0,
    'updates' => 0,
    'deletes' => 0,
    'additions' => 0,
  ];

  foreach ($sources as $source) {
    foreach ($strings[$source] as $lang => $translation) {
      _locale_import_one_string_db($report, $lang, '', $source, $translation, 'default', '', LOCALE_IMPORT_OVERWRITE);
    }
  }

  // Clear locale cache.
  cache_clear_all('locale:', 'cache', TRUE);
}
