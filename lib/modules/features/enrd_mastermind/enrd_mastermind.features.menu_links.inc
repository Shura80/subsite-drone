<?php

/**
 * @file
 * enrd_mastermind.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function enrd_mastermind_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-breadcrumb-menu_enrd-home:<front>.
  $menu_links['menu-breadcrumb-menu_enrd-home:<front>'] = array(
    'menu_name' => 'menu-breadcrumb-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'ENRD Home',
    'options' => array(
      'attributes' => array(
        'data-display-title' => 1,
        'data-hide-children' => 0,
        'data-remove-class' => 1,
      ),
      'item_attributes' => array(
        'data-image' => '',
        'data-display-title' => 1,
        'data-hide-children' => 0,
        'id' => '',
        'class' => '',
        'data-remove-class' => 0,
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-breadcrumb-menu_enrd-home:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => 10,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('ENRD Home');

  return $menu_links;
}
