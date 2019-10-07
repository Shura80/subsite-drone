<?php

/**
 * @file
 * agri_core.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function agri_core_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-core-action-menu.
  $menus['menu-core-action-menu'] = array(
    'menu_name' => 'menu-core-action-menu',
    'title' => 'Action menu',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-core-quicklinks.
  $menus['menu-core-quicklinks'] = array(
    'menu_name' => 'menu-core-quicklinks',
    'title' => 'Quicklinks',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-core-search-find.
  $menus['menu-core-search-find'] = array(
    'menu_name' => 'menu-core-search-find',
    'title' => 'The one-stop-shop for Agricultural Innovation in Europe',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-core-user-quicklinks.
  $menus['menu-core-user-quicklinks'] = array(
    'menu_name' => 'menu-core-user-quicklinks',
    'title' => 'User Quicklinks',
    'description' => 'Quicklinks menu displayed on user profile.',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-social-footer.
  $menus['menu-social-footer'] = array(
    'menu_name' => 'menu-social-footer',
    'title' => 'Social footer',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Action menu');
  t('Main menu');
  t('Quicklinks');
  t('Quicklinks menu displayed on user profile.');
  t('Social footer');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');
  t('The one-stop-shop for Agricultural Innovation in Europe');
  t('User Quicklinks');

  return $menus;
}
