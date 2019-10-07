<?php

/**
 * @file
 * agri_digitization_toolbox.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function agri_digitization_toolbox_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-digitization-toolbox.
  $menus['menu-digitization-toolbox'] = array(
    'menu_name' => 'menu-digitization-toolbox',
    'title' => 'Digitisation Toolbox',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Digitisation Toolbox');

  return $menus;
}
