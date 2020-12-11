<?php

/**
 * @file
 * List of menu items to import into ENRD menus.
 */

/**
 * Menu items for the Join Us menu.
 *
 * @return array
 *   Return an array of menu items.
 */
function _enrd_mastermind_menu_enrd_join_us() {

  return array(
    array(
      'link_title' => 'Facebook',
      'link_path' => '<front>',
      'menu_name' => 'menu-enrd-join-us',
      'weight' => 0,
      'expanded' => 0,
      'options' => array(
        'attributes' => array(
          'data-remove-class' => 1,
          'class' => array(
            'icon',
            'icon-facebook',
          ),
          'target' => '_blank',
        ),
      ),
    ),
    array(
      'link_title' => 'Twitter',
      'link_path' => '<front>',
      'menu_name' => 'menu-enrd-join-us',
      'weight' => 10,
      'expanded' => 1,
      'options' => array(
        'attributes' => array(
          'data-remove-class' => 1,
          'class' => array(
            'icon',
            'icon-twitter',
          ),
        ),
      ),
      '#children' => array(
        array(
          'link_title' => '@ENRD_CP',
          'link_path' => 'https://twitter.com/ENRD_CP',
          'menu_name' => 'menu-enrd-join-us',
          'weight' => 5,
          'expanded' => 0,
          'options' => array(
            'attributes' => array(
              'title' => 'ENRD Contact Point',
              'data-display-title' => 1,
              'target' => '_blank',
            ),
          ),
        ),
        array(
          'link_title' => '@ENRD_Evaluation',
          'link_path' => 'https://twitter.com/ENRD_Evaluation',
          'menu_name' => 'menu-enrd-join-us',
          'weight' => 10,
          'expanded' => 0,
          'options' => array(
            'attributes' => array(
              'title' => 'Evaluation Helpdesk',
              'data-display-title' => 1,
              'target' => '_blank',
            ),
          ),
        ),
      ),
    ),
    array(
      'link_title' => 'Linkedin',
      'link_path' => '<front>',
      'menu_name' => 'menu-enrd-join-us',
      'weight' => 20,
      'expanded' => 0,
      'options' => array(
        'attributes' => array(
          'data-remove-class' => 1,
          'class' => array(
            'icon',
            'icon-linkedin',
          ),
          'target' => '_blank',
        ),
      ),
    ),
    array(
      'link_title' => 'Youtube',
      'link_path' => '<front>',
      'menu_name' => 'menu-enrd-join-us',
      'weight' => 30,
      'expanded' => 0,
      'options' => array(
        'attributes' => array(
          'data-remove-class' => 1,
          'class' => array(
            'icon',
            'icon-youtube-play',
          ),
          'target' => '_blank',
        ),
      ),
    ),
    array(
      'link_title' => 'Instagram',
      'link_path' => 'https://www.instagram.com/enrdcp',
      'menu_name' => 'menu-enrd-join-us',
      'weight' => 40,
      'expanded' => 0,
      'options' => array(
        'attributes' => array(
          'data-remove-class' => 1,
          'class' => array(
            'icon',
            'icon-instagram',
          ),
          'target' => '_blank',
        ),
      ),
    ),
  );
}
