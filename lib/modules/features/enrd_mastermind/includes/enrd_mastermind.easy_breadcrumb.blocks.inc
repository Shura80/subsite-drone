<?php

/**
 * @file
 * ENRD Easy Breadcrumb block customization.
 */

// Include the original easy_breadcrumb build functions.
module_load_include('inc', 'easy_breadcrumb', 'includes/easy_breadcrumb.blocks');

/**
 * Obtains the 'easy_breadcrumb' block.
 *
 * @return array
 *   Return a renderizable array for breadcrumb.
 */
function _enrd_mastermind_easy_breadcrumb_block() {

  // Array storing the breadcrumb's segments.
  $breadcrumb = array();
  // Default classes for the segments.
  $segments_classes = array('easy-breadcrumb_segment');
  // Gets the flag saying if the front page segment should be included.
  $include_front_page_segment = variable_get(EasyBreadcrumbConstants::DB_VAR_INCLUDE_HOME_SEGMENT, TRUE);

  // Conditionally include the front page segment in the breadcrumb.
  if ($include_front_page_segment) {
    $front_text = _easy_breadcrumb_obtain_home_title();
    // Marks the front--segment with an identifier class (useful for CSS).
    $segments_classes[1] = 'easy-breadcrumb_segment-front';
    // Adds a segment for the front page.
    $breadcrumb[] = _easy_breadcrumb_build_item($front_text, $segments_classes, '<front>');
  }

  // No more segments if visiting the front page, the don't waste resources.
  if (!drupal_is_front_page()) {

    // Flag for including invalid paths as plain-text segments.
    $include_invalid_paths = variable_get(EasyBreadcrumbConstants::DB_VAR_INCLUDE_INVALID_PATHS, TRUE);

    // Obtains the alias of the current path.
    $alias = drupal_get_path_alias();

    // Get the segments of the current path.
    $alias_arr = explode('/', $alias);

    // Get the quantity of segments in the current path.
    $segments_quantity = count($alias_arr);

    $segment_url_arr = array();

    // Iterates over the segments of the current URL
    // ("blog/article/hello-world") excepting the last segment
    // (the title, 'hello-world' in that case).
    for ($idx_0 = 0, $idx_1 = 1; $idx_1 < $segments_quantity; ++$idx_0, ++$idx_1) {

      // Build an array containing the URL of the segment being currently
      // processed. E.g., having $alias as "blog/article/hello-world", at the
      // first iteration this array will be array('blog'), the second
      // (and last in that case) the array will be array('blog','article').
      $segment_url_arr[] = $alias_arr[$idx_0];
      // Potential-path of segment being processed (e.g.: 'blog/article').
      $segment_url = implode('/', $segment_url_arr);

      // Jump to the next segment if this url is configured to be excluded.
      $excluded_path = _easy_breadcrumb_check_excluded_path($segment_url);
      if ($excluded_path) {
        continue;
      }

      $segments_classes[1] = 'easy-breadcrumb_segment-' . $idx_1;
      // Obtain the internal path it represents.
      $segment_normal_path = drupal_get_normal_path($segment_url);

      // Check if this is a valid path.
      $segment_valid_path = _easy_breadcrumb_validate_segment_path($segment_normal_path);

      // Get the segment's raw text from the URL.
      $segment_text = $alias_arr[$idx_0];
      // Normalized segment's text (e.g. 'Blog').
      $segment_title = _enrd_mastermind_easy_breadcrumb_obtain_segment_title($segment_normal_path,
        $segment_valid_path, $segment_text);

      if ($segment_valid_path || $include_invalid_paths) {
        $breadcrumb[] = _easy_breadcrumb_build_item($segment_title, $segments_classes, $segment_url, $segment_valid_path);
      }
    }

    // Gets the flag saying if the title should be appended to the breadcrumb.
    $include_page_title_segment = variable_get(EasyBreadcrumbConstants::DB_VAR_INCLUDE_TITLE_SEGMENT, TRUE);

    // Adds the page's title to the breadcrumb.
    if ($include_page_title_segment) {
      // Marks page's-title-segment with an identifier class (useful for CSS).
      $segments_classes[1] = 'easy-breadcrumb_segment-title';
      // The title is the last segment in the URL.
      $segment_text = $alias_arr[$segments_quantity - 1];
      $segment_title = _enrd_mastermind_easy_breadcrumb_obtain_page_title($segment_text, drupal_get_normal_path($alias));
      $title_segment_as_link = variable_get(EasyBreadcrumbConstants::DB_VAR_TITLE_SEGMENT_AS_LINK, FALSE);
      // If the page's title will be a link or just a text.
      $breadcrumb[] = _easy_breadcrumb_build_item($segment_title, $segments_classes, $alias, $title_segment_as_link);
    }
  }

  // Gets the configured segments separator.
  $separator = variable_get(EasyBreadcrumbConstants::DB_VAR_SEGMENTS_SEPARATOR, '>>');
  $separator = check_plain($separator);
  $segments_quantity = count($breadcrumb);

  $build = array();
  $build['easy_breadcrumb'] = array(
    '#theme' => 'easy_breadcrumb',
    '#breadcrumb' => $breadcrumb,
    '#segments_quantity' => $segments_quantity,
    '#separator' => $separator,
  );

  return $build;
}

/**
 * Obtain the title of the page.
 *
 * @param string $segment_text
 *   Raw text to be use as fallback to infer the page's title.
 * @param string $path
 *   The current page path.
 *
 * @return string
 *   The page's title.
 */
function _enrd_mastermind_easy_breadcrumb_obtain_page_title($segment_text, $path) {
  $use_page_title_when_available = variable_get(EasyBreadcrumbConstants::DB_VAR_TITLE_FROM_PAGE_WHEN_AVAILABLE, TRUE);
  // Tries to get the title of the current page (if available).
  if ($use_page_title_when_available) {
    $title = _enrd_mastermind_easy_breadcrumb_get_title(drupal_get_title(), $path);
  }
  // Just deduce the title from the given fallback.
  if (!isset($title) || $title === '') {
    $title = _easy_breadcrumb_normalize_text($segment_text);
  }
  return $title;
}

/**
 * Obtain the title of the given segment.
 *
 * @param string $normal_path
 *   Segment's normal path.
 * @param string $valid_path
 *   Flag if the URL of the segment if valid.
 * @param string $segment_text
 *   Raw text to be used as fallback to infer the segment's title.
 *
 * @return string
 *   Segment title.
 */
function _enrd_mastermind_easy_breadcrumb_obtain_segment_title($normal_path, $valid_path, $segment_text) {
  // If path is valid then try to obtain the title from the menu router.
  if ($valid_path) {
    $router_item = menu_get_item($normal_path);
    $title = _enrd_mastermind_easy_breadcrumb_get_title($router_item['title'], $normal_path);
  }
  // Just infer the title from the segment text.
  if (!isset($title) || $title === '') {
    $title = _easy_breadcrumb_normalize_text($segment_text);
  }
  return $title;
}

/**
 * Helper function to get menu item title from current page.
 *
 * @param string $default_title
 *   The page title to check against menu_title (if available).
 * @param string $path
 *   The path to check for menu link.
 *
 * @return string
 *   Returns either a page title or menu title.
 */
function _enrd_mastermind_easy_breadcrumb_get_title($default_title, $path) {

  // Do not search for shorter titles on some paths.
  $skip_menu_title_search = variable_get('easy_breadcrumb-fixed_title', []);
  if (in_array(drupal_get_path_alias($path), $skip_menu_title_search)) {
    $title = $default_title;
  }
  else {
    // Get menu link title from path.
    $mlid = db_select('menu_links', 'ml')
      ->fields('ml', ['mlid'])
      ->orderBy('menu_name')
      ->condition('link_path', $path)
      ->range(0, 1)
      ->execute()
      ->fetchField();

    if ($mlid) {
      $item = menu_link_load($mlid);
      // Use menu title or default page title.
      $title = ($item['title'] && $item['title'] != $default_title) ? $item['title'] : $default_title;
    }
    else {
      $title = $default_title;
    }
  }

  return $title;
}
