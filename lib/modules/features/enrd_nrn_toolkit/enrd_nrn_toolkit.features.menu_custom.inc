<?php

/**
 * @file
 * enrd_nrn_toolkit.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function enrd_nrn_toolkit_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-enrd-nrn-static-pages.
  $menus['menu-enrd-nrn-static-pages'] = array(
    'menu_name' => 'menu-enrd-nrn-static-pages',
    'title' => 'NRN static pages',
    'description' => 'ENRD NRN static pages menu',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('ENRD NRN static pages menu');
  t('NRN static pages');

  return $menus;
}
