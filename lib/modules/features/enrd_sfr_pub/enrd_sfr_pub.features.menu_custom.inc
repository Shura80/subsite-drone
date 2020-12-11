<?php

/**
 * @file
 * enrd_sfr_pub.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function enrd_sfr_pub_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-enrd-sfr-pub-subscribe.
  $menus['menu-enrd-sfr-pub-subscribe'] = array(
    'menu_name' => 'menu-enrd-sfr-pub-subscribe',
    'title' => 'Subscribe',
    'description' => 'ENRD Subscriptions menu',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('ENRD Subscriptions menu');
  t('Subscribe');

  return $menus;
}
