<?php

/**
 * @file
 * enrd_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function enrd_news_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function enrd_news_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function enrd_news_image_default_styles() {
  $styles = array();

  // Exported image style: news_rolling_block.
  $styles['news_rolling_block'] = array(
    'label' => 'News rolling block',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 400,
          'height' => 200,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: newsroom.
  $styles['newsroom'] = array(
    'label' => 'Newsroom',
    'effects' => array(
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 300,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: newsroom_slider.
  $styles['newsroom_slider'] = array(
    'label' => 'Newsroom slider (400)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 400,
          'height' => 200,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}
