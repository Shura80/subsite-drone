<?php

/**
 * @file
 * List of custom entity beans to import into AGRI-EIP.
 */

/**
 * Get the default beans.
 *
 * If the $bundle_name is set, an array will return with only those beans
 * of that type.
 *
 * @param string $bundle_name
 *   The bundle name.
 *
 * @return array
 *   Return an array of beans.
 */
function _agri_core_get_custom_beans($bundle_name = '') {
  $beans = array(
    // Bundle "agri_static_block".
    'agri_static_block' => array(
      'funding_opportunities' => array(
        'label' => 'Home block - Funding opportunities',
        'title' => 'Funding opportunities',
        'fields' => array(
          'field_agri_core_bean_body' => array(
            'value' => 'Find funding opportunities for your innovation project in agriculture, food and forestry.',
            'format' => 'basic_html',
          ),
          'field_agri_core_bean_link' => array(
            'url' => 'find-connect/funding-opportunities',
            'title' => 'All funding opportunities',
            'attributes' => array(),
          ),
          'field_agri_core_bean_image' => array(
            'alt' => 'Funding opportunities',
            'title' => 'Funding opportunities',
          ),
        ),
        'files' => array(
          'field_agri_core_bean_image' => drupal_get_path('theme', 'agri_theme') . '/images/beans/funding_opportunities.png',
        ),
      ),
      'videos' => array(
        'label' => 'Home block - Videos',
        'title' => 'Videos',
        'fields' => array(
          'field_agri_core_bean_link' => array(
            'url' => 'eip-agri-video-gallery',
            'title' => 'Video gallery',
            'attributes' => array(),
          ),
          'field_agri_core_bean_image' => array(
            'alt' => 'Videos',
            'title' => 'Videos',
          ),
        ),
        'files' => array(
          'field_agri_core_bean_image' => drupal_get_path('theme', 'agri_theme') . '/images/beans/video.png',
        ),
      ),
      'digital_agriculture' => array(
        'label' => 'Home block - Digital agriculture',
        'title' => 'Digital agriculture',
        'fields' => array(
          'field_agri_core_bean_body' => array(
            'value' => 'Be inspired by digital technologies and innovative projects for the farming and forestry community.  Find out how to improve your digital knowledge and skills.',
            'format' => 'basic_html',
          ),
          'field_agri_core_bean_link' => array(
            'url' => defined('AGRI_DIGITIZATION_TOOLBOX_SECTION_PATH') ? AGRI_DIGITIZATION_TOOLBOX_SECTION_PATH : '',
            'title' => 'Go to digitising agriculture',
            'attributes' => array(),
          ),
          'field_agri_core_bean_image' => array(
            'alt' => 'Digital agriculture',
            'title' => 'Digital agriculture',
          ),
        ),
        'files' => array(
          'field_agri_core_bean_image' => drupal_get_path('theme', 'agri_theme') . '/images/beans/digital_agriculture.png',
        ),
      ),
      'enrd' => array(
        'label' => 'Home block - ENRD',
        'title' => 'Connect to',
        'fields' => array(
          'field_agri_core_bean_link' => array(
            'url' => AGRI_CORE_ENRD_PATH,
            'title' => 'Go to ENRD website',
            'attributes' => array(
              'target' => LINK_TARGET_NEW_WINDOW,
            ),
          ),
          'field_agri_core_bean_image' => array(
            'alt' => 'ENRD Logo',
            'title' => 'Visit ENRD website',
          ),
        ),
        'files' => array(
          'field_agri_core_bean_image' => drupal_get_path('theme', 'agri_theme') . '/images/beans/logo-enrd.png',
        ),
      ),
      'find_people' => array(
        'label' => 'Home block - Find people',
        'title' => 'Find people',
        'fields' => array(
          'field_agri_core_bean_body' => array(
            'value' => 'Connect with other innovators across Europe and share your expertise and project ideas. Register to the website and join the EIP-AGRI network!',
            'format' => 'basic_html',
          ),
          'field_agri_core_bean_link' => array(
            'url' => 'find-people',
            'title' => 'Join the EIP-AGRI network',
            'attributes' => array(),
          ),
          'field_agri_core_bean_image' => array(
            'alt' => 'Find people',
            'title' => 'Find people',
          ),
        ),
        'files' => array(
          'field_agri_core_bean_image' => drupal_get_path('theme', 'agri_theme') . '/images/beans/find_people.png',
        ),
      ),
    ),
  );

  if (!empty($bundle_name) && isset($beans[$bundle_name])) {
    $return = $beans[$bundle_name];
  }
  else {
    // Return all beans.
    $return = $beans;
  }

  return $return;
}
