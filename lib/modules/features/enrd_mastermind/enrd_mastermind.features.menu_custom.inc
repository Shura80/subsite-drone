<?php

/**
 * @file
 * enrd_mastermind.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function enrd_mastermind_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-enrd-join-us.
  $menus['menu-enrd-join-us'] = array(
    'menu_name' => 'menu-enrd-join-us',
    'title' => 'Join Us',
    'description' => 'ENRD Join Us menu',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-enrd-tools.
  $menus['menu-enrd-tools'] = array(
    'menu_name' => 'menu-enrd-tools',
    'title' => 'Tools',
    'description' => 'ENRD Tools menu',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('ENRD Join Us menu');
  t('ENRD Tools menu');
  t('Join Us');
  t('Tools');

  return $menus;
}
