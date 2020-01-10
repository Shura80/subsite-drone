<?php

/**
 * @file
 * List of menu items to import into NRN Toolkit menus.
 */

/**
 * Menu items of NRN static pages menu.
 *
 * @return array
 *   Return an array of menu items.
 */
function _enrd_nrn_toolkit_menu_enrd_nrn_static_pages() {

  return array(
    array(
      'link_title' => 'NRN Profiles',
      'link_path' => '<front>',
      'menu_name' => 'menu-enrd-nrn-static-pages',
      'weight' => 0,
      'expanded' => 0,
      'options' => array(
        'attributes' => array(
          'data-remove-class' => 1,
          'class' => array(
            'icon',
            'icon-nrn-profiles',
          ),
        ),
      ),
    ),
    array(
      'link_title' => 'NRN meetings & workshops',
      'link_path' => '<front>',
      'menu_name' => 'menu-enrd-nrn-static-pages',
      'weight' => 10,
      'expanded' => 0,
      'options' => array(
        'attributes' => array(
          'data-remove-class' => 1,
          'class' => array(
            'icon',
            'icon-nrn-meetings-workshops',
          ),
        ),
      ),
    ),
    array(
      'link_title' => 'Multimedia',
      'link_path' => '<front>',
      'menu_name' => 'menu-enrd-nrn-static-pages',
      'weight' => 20,
      'expanded' => 0,
      'options' => array(
        'attributes' => array(
          'data-remove-class' => 1,
          'class' => array(
            'icon',
            'icon-nrn-multimedia',
          ),
        ),
      ),
    ),
  );
}
