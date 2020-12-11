<?php

/**
 * @file
 * List of menu items to import into ENRD Subscribe menu.
 */

/**
 * Menu items for the Subscribe menu.
 *
 * @return array
 *   Return an array of menu items.
 */
function _enrd_sfr_pub_menu_enrd_sfr_pub_subscribe() {

  return array(
    array(
      'link_title' => 'Publications',
      'link_path' => ENRD_SFR_PUB_ADD_REQUEST . _enrd_sfr_type_path_replace(ENRD_SFR_PUB_SUB_CP_FORM),
      'menu_name' => 'menu-enrd-sfr-pub-subscribe',
      'weight' => 0,
      'expanded' => 0,
      'options' => array(
        'attributes' => array(
          'data-remove-class' => 1,
          'class' => array(
            'icon',
            'icon-publications',
          ),
        ),
        'query' => array(
          'destination' => '',
        ),
      ),
    ),
    array(
      'link_title' => 'Evaluation Publications',
      'link_path' => ENRD_SFR_PUB_ADD_REQUEST . _enrd_sfr_type_path_replace(ENRD_SFR_PUB_SUB_EHD_FORM),
      'menu_name' => 'menu-enrd-sfr-pub-subscribe',
      'weight' => 10,
      'expanded' => 0,
      'options' => array(
        'attributes' => array(
          'data-remove-class' => 1,
          'class' => array(
            'icon',
            'icon-evaluation-publications',
          ),
        ),
        'query' => array(
          'destination' => '',
        ),
      ),
    ),
    array(
      'link_title' => 'Newsletter',
      'link_path' => ENRD_SFR_PUB_NEWSLETTER_URL,
      'menu_name' => 'menu-enrd-sfr-pub-subscribe',
      'weight' => 20,
      'expanded' => 0,
      'options' => array(
        'attributes' => array(
          'data-remove-class' => 1,
          'class' => array(
            'icon',
            'icon-newsletter',
          ),
          'target' => '_blank',
        ),
      ),
    ),
  );
}
