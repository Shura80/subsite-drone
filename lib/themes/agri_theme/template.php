<?php

/**
 * @file
 * Template file for agri_theme theme.
 */

/**
 * Implements theme('menu_tree') using extra Menu Block hook suggestions.
 *
 * See README.txt.
 */
function agri_theme_menu_tree__menu_block__agri_pages_side_menu($variables) {
  $attributes = array(
    'class' => 'nav nav-pills nav-stacked',
  );

  return theme('item_list', array(
    'items' => array($variables['tree']),
    'title' => NULL,
    'type' => 'ul',
    'attributes' => $attributes,
  ));
}

/**
 * Implements theme('menu_tree') using extra Menu Block hook suggestions.
 */
function agri_theme_menu_tree__menu_block__agri_core_user_menu($variables) {
  $attributes = array(
    'class' => 'nav nav-pills nav-stacked',
  );

  return theme('item_list', array(
    'items' => array($variables['tree']),
    'title' => NULL,
    'type' => 'ul',
    'attributes' => $attributes,
  ));
}

/**
 * Implements theme('menu_tree') using extra Menu Block hook suggestions.
 */
function agri_theme_menu_tree__menu_block__og_single_menu_block($variables) {
  $attributes = array(
    'class' => 'nav nav-pills nav-stacked',
  );

  return theme('item_list', array(
    'items' => array($variables['tree']),
    'title' => NULL,
    'type' => 'ul',
    'attributes' => $attributes,
  ));
}

/**
 * Implements theme('menu_tree') using extra Menu Block hook suggestions.
 */
function agri_theme_menu_tree__menu_core_search_find($variables) {
  $attributes = array(
    'class' => 'search-find nav nav-pills nav-stacked',
  );

  return theme('item_list', array(
    'items' => array($variables['tree']),
    'title' => NULL,
    'type' => 'ul',
    'attributes' => $attributes,
  ));
}

/**
 * Implements theme('menu_tree') using extra Menu Block hook suggestions.
 */
function agri_theme_menu_tree__menu_core_action_menu($variables) {
  $attributes = array(
    'class' => 'nav nav-pills nav-stacked',
  );

  return theme('item_list', array(
    'items' => array($variables['tree']),
    'title' => NULL,
    'type' => 'ul',
    'attributes' => $attributes,
  ));
}

/**
 * Implements theme('menu_tree') using extra Menu Block hook suggestions.
 */
function agri_theme_menu_tree__menu_core_quicklinks($variables) {
  return '<ul>' . $variables['tree'] . '</ul>';
}

/**
 * Implements theme('menu_tree').
 */
function agri_theme_menu_tree__menu_digitization_toolbox($variables) {
  return '<ul class="nav nav-pills nav-stacked">' . $variables['tree'] . '</ul>';
}

/**
 * Implements theme_preprocess_page().
 */
function agri_theme_preprocess_page(&$variables) {

  global $base_url;

  if (module_exists('libraries')) {
    libraries_load('bootstrap-hover-dropdown');
  }

  // Format regions.
  $variables['region_header_right'] = (isset($variables['regions']['header_right']) ? render($variables['regions']['header_right']) : '');
  $variables['region_header_top'] = (isset($variables['page']['header_top']) ? render($variables['page']['header_top']) : '');
  $variables['region_featured'] = (isset($variables['page']['featured']) ? render($variables['page']['featured']) : '');
  $variables['region_sidebar_left'] = (isset($variables['page']['sidebar_left']) ? render($variables['page']['sidebar_left']) : '');
  $variables['region_tools'] = (isset($variables['page']['tools']) ? render($variables['page']['tools']) : '');
  $variables['region_content_top'] = (isset($variables['page']['content_top']) ? render($variables['page']['content_top']) : '');
  $variables['region_help'] = (isset($variables['page']['help']) ? render($variables['page']['help']) : '');
  $variables['region_content'] = (isset($variables['page']['content']) ? render($variables['page']['content']) : '');
  $variables['region_content_right'] = (isset($variables['page']['content_right']) ? render($variables['page']['content_right']) : '');
  $variables['region_content_bottom'] = (isset($variables['page']['content_bottom']) ? render($variables['page']['content_bottom']) : '');
  $variables['region_content_first'] = (isset($variables['page']['content_first']) ? render($variables['page']['content_first']) : '');
  $variables['region_content_second'] = (isset($variables['page']['content_second']) ? render($variables['page']['content_second']) : '');
  $variables['region_content_third'] = (isset($variables['page']['content_third']) ? render($variables['page']['content_third']) : '');
  $variables['region_sidebar_right'] = (isset($variables['page']['sidebar_right']) ? render($variables['page']['sidebar_right']) : '');
  $variables['region_footer'] = (isset($variables['regions']['footer']) ? render($variables['regions']['footer']) : '');

  // Check if there is a responsive sidebar or not.
  $variables['has_responsive_sidebar'] = ($variables['region_header_right'] || $variables['region_sidebar_left'] || $variables['region_sidebar_right'] ? 1 : 0);
  if ($variables['has_responsive_sidebar']) {
    $variables['sidebar_visible_sm'] = 'sidebar-visible-sm';
  }

  // Calculate the width of the region_content_x.
  $region_content_index = 0;
  $region_content_index = (!empty($variables['region_content_first']) ? $region_content_index + 1 : $region_content_index);
  $region_content_index = (!empty($variables['region_content_second']) ? $region_content_index + 1 : $region_content_index);
  $region_content_index = (!empty($variables['region_content_third']) ? $region_content_index + 1 : $region_content_index);
  if ($region_content_index > 0) {
    $variables['region_content_index'] = TRUE;
    $variables['col_content_first'] = array(
      'lg' => 12 / $region_content_index,
      'md' => 12 / $region_content_index,
      'sm' => 12,
      'xs' => 12,
    );

    $variables['col_content_second'] = array(
      'lg' => 12 / $region_content_index,
      'md' => 12 / $region_content_index,
      'sm' => 12,
      'xs' => 12,
    );

    $variables['col_content_third'] = array(
      'lg' => 12 / $region_content_index,
      'md' => 12 / $region_content_index,
      'sm' => 12,
      'xs' => 12,
    );
  }

  // Calculate size of regions.
  // Sidebars.
  $variables['col_sidebar_left'] = array(
    'lg' => (!empty($variables['region_sidebar_left']) ? 3 : 0),
    'md' => (!empty($variables['region_sidebar_left']) ? 3 : 0),
    'sm' => 0,
    'xs' => 0,
  );

  $variables['col_sidebar_right'] = array(
    'lg' => (!empty($variables['region_sidebar_right']) ? 3 : 0),
    'md' => (!empty($variables['region_sidebar_right']) ? (!empty($variables['region_sidebar_left']) ? 3 : 4) : 0),
    'sm' => 0,
    'xs' => 0,
  );

  // Content.
  $variables['col_content_main'] = array(
    'lg' => 12 - $variables['col_sidebar_left']['lg'] - $variables['col_sidebar_right']['lg'],
    'md' => 12 - $variables['col_sidebar_left']['md'] - $variables['col_sidebar_right']['md'],
    'sm' => 12,
    'xs' => 12,
  );

  $variables['col_content_right'] = array(
    'lg' => (!empty($variables['region_content_right']) ? 4 : 0),
    'md' => (!empty($variables['region_content_right']) ? 4 : 0),
    'sm' => (!empty($variables['region_content_right']) ? 12 : 0),
    'xs' => (!empty($variables['region_content_right']) ? 12 : 0),
  );

  $variables['col_content'] = array(
    'lg' => 12 - $variables['col_content_right']['lg'],
    'md' => 12 - $variables['col_content_right']['md'],
    'sm' => 12,
    'xs' => 12,
  );

  // Tools.
  $variables['col_sidebar_button'] = array(
    'sm' => ($variables['has_responsive_sidebar'] ? 2 : 0),
    'xs' => ($variables['has_responsive_sidebar'] ? 2 : 0),
  );

  $variables['col_tools'] = array(
    'lg' => 4,
    'md' => 4,
    'sm' => 12,
    'xs' => 12,
  );

  // Title.
  $variables['col_title'] = array(
    'lg' => 12 - $variables['col_tools']['lg'],
    'md' => 12 - $variables['col_tools']['md'],
    'sm' => 12,
    'xs' => 12,
  );

  $variables['col_content_top_left'] = array(
    'lg' => 12 - ($variables['page']['content_top_right'] ? ($variables['is_front'] ? 3 : 6) : 0),
    'md' => 12 - ($variables['page']['content_top_right'] ? ($variables['is_front'] ? 3 : 6) : 0),
    'sm' => 12,
    'xs' => 12,
  );

  $variables['col_content_top_right'] = array(
    'lg' => 12 - ($variables['page']['content_top_left'] ? ($variables['is_front'] ? 9 : 6) : 0),
    'md' => 12 - ($variables['page']['content_top_left'] ? ($variables['is_front'] ? 9 : 6) : 0),
    'sm' => 12,
    'xs' => 12,
  );

  // New structure for the regions multi col "content_bottom_x".
  $quotient = 0;
  $variables['print_region_content_bottom_x'] = FALSE;

  // Declaration format regions.
  $region_content_bottom_x = array(
    'region_content_bottom_1' => (isset($variables['page']['content_bottom_first']) ? render($variables['page']['content_bottom_first']) : ''),
    'region_content_bottom_2' => (isset($variables['page']['content_bottom_second']) ? render($variables['page']['content_bottom_second']) : ''),
    'region_content_bottom_3' => (isset($variables['page']['content_bottom_third']) ? render($variables['page']['content_bottom_third']) : ''),
  );

  foreach ($region_content_bottom_x as $name => $content) {
    if (!empty($content)) {
      $quotient++;
      $variables['print_region_content_bottom_x'] = TRUE;
    }
  }

  if ($variables['print_region_content_bottom_x']) {
    $col_content_bottom_n = array(
      'lg' => 12 / $quotient,
      'md' => 12 / $quotient,
      'sm' => 12,
      'xs' => 12,
    );

    $classes_array = array();
    foreach ($col_content_bottom_n as $key => $value) {
      $classes_array[] = 'col-' . $key . '-' . $value;
    }

    $content_bottom_x = array();
    foreach ($region_content_bottom_x as $name => $content) {
      $content_bottom_x[] = array(
        'content' => $region_content_bottom_x[$name],
        'attributes' => array(
          'id' => $name,
          'class' => $classes_array,
        ),
      );
    }

    $variables['content_bottom_x'] = $content_bottom_x;
  }

  $logo = l(theme('image', array(
    'path' => $base_url . '/' . drupal_get_path('theme', 'agri_theme') . "/images/logo/logo_en.gif",
    'alt' => 'eip-agri logo',
    'title' => 'EIP-AGRI',
  )), '<front>', array(
    'attributes' => array(
      'id' => 'agri-logo',
    ),
    'html' => TRUE,
  ));
  $variables['logo'] = $logo;

  // Add dynamically class attributes for title page.
  $variables['title_attributes_array']['class'][] = 'title';
}

/**
 * Implements theme('menu_local_tasks').
 */
function agri_theme_menu_local_tasks(&$variables) {
  $output = '';

  if (!empty($variables['primary'])) {
    $variables['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    $variables['primary']['#prefix'] .= '<ul class="nav nav-tabs tabs-primary">';
    $variables['primary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['primary']);
  }
  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<h2 class="element-invisible">' . t('Secondary tabs') . '</h2>';
    $variables['secondary']['#prefix'] .= '<ul class="margin-top nav nav-pills tabs-secondary">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }

  return $output;
}

/**
 * Implements theme('menu_local_action').
 */
function agri_theme_menu_local_action($variables) {
  $link = $variables['element']['#link'];
  $options = isset($link['localized_options']) ? $link['localized_options'] : array();
  $options['attributes']['class'][] = 'btn';

  $output = '';
  if (isset($link['href'])) {
    $output .= l($link['title'], $link['href'], $options);
  }
  elseif (!empty($link['localized_options']['html'])) {
    $output .= $link['title'];
  }
  else {
    $output .= check_plain($link['title']);
  }
  $output .= "";

  return $output;
}

/**
 * Implements theme_field__field_type().
 */
function agri_theme_field__taxonomy_term_reference($variables) {
  $output = '';

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . trim($variables['label']) . ':&nbsp;</div>';
  }

  // Render the items.
  $output .= '<div class="field-items"' . $variables['content_attributes'] . '>';
  foreach ($variables['items'] as $delta => $item) {
    $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
    $output .= '<div class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</div>';
  }
  $output .= '</div>';

  // Render the top-level DIV.
  $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';

  return $output;
}

/**
 * Implements hook_css_alter().
 */
function agri_theme_css_alter(&$css) {

  // Remove Display Suite default CSS allowing Bootstrap grid to take control.
  if (module_exists('ds')) {
    $excludes = array();
    $layouts = ds_get_layout_info();
    foreach ($layouts as $name => $layout) {
      $excludes[] = $layout['path'] . DIRECTORY_SEPARATOR . $name . '.css';
    }
    if (!empty($excludes)) {
      $css = array_diff_key($css, drupal_map_assoc($excludes));
    }
  }
}

/**
 * Override or insert variables into the block template.
 */
function agri_theme_preprocess_block(&$variables) {

  switch ($variables['block_html_id']) {

    case 'block-views-core-spotlight-block':
    case 'block-views-core-spotlight-block-1':
    case 'block-views-agri-stakeholders-block-1':
    case 'block-views-4eeb0a1180a820bd7a2ec9acdaf60fb7':
      $variables['classes_array'][] = drupal_html_class('views-spotlight-block');
      break;

    case 'block-views-core-find-people-block-1':
      $variables['classes_array'][] = 'col-sm-6';
      break;

    case 'block-views-bff5610dca6e97cea5eac763a692275d':
      $variables['classes_array'][] = 'col-sm-6';
      break;

    case 'block-menu-menu-core-user-quicklinks':
      $variables['classes_array'][] = 'block-no-title';
      break;

    case 'block-menu-menu-digitization-toolbox':
      // Change the Digitization Toolbox menu title in landing page block.
      $variables['block']->subject = t('Key questions & information');
      break;

    case 'block-menu-block-agri-digitization-toolbox-menu':
      // Check if querystring parameters are set.
      $params = drupal_get_query_parameters();

      // Check if country parameter exists add querystring to block title link.
      if ($params && !empty($params['country'])) {
        // Add the country querystring to internal path.
        $variables['block']->subject = l(t('Digital Agriculture'), AGRI_DIGITIZATION_TOOLBOX_SECTION_PATH, ['query' => ['country' => $params['country']]]);
      }
      // Print normal block title link.
      else {
        $variables['block']->subject = l(t('Digital Agriculture'), AGRI_DIGITIZATION_TOOLBOX_SECTION_PATH);
      }
      break;

    // Get node object and add specific tpl suggestion if block matches.
    case (preg_match('/agri-mlt-/', $variables['block_html_id']) ? TRUE : FALSE):

      // Add a specific suggestion for solr mlt searches.
      $variables['theme_hook_suggestions'][] = 'block__agri__solr_mlt_search';
      // Don't add the "Show more" link on digitisation's related content.
      if ($variables['block']->context != 'agri_digitization_toolbox_navigation') {
        // Let the node object available for related content blocks.
        $variables['node'] = menu_get_object();

        // Build "Show more" block link.
        $link_path = 'node/' . $variables['node']->nid . '/related';
        $variables['related_link'] = l(t('Show more'), $link_path,
          [
            'attributes' => [
              'title' => t('Show more suggestions'),
            ],
          ]);
      }

      break;

  }

  // List of all block than don't need a panel.
  $block_no_panel = array(
    'agri_core' => array('agri_user_login'),
    'search' => array('form'),
    'print' => array('print-links'),
    'workbench' => array('block'),
    'social_bookmark' => array('social-bookmark'),
    'system' => array(
      'main',
      'help',
    ),
    'menu' => array(
      'menu-service-tools',
      'menu-social-footer',
    ),
    'views' => array(
      'view_ec_content_slider-block',
      'news_node_blocks-block_1',
      'event_node_blocks-block_1',
      'core_spotlight-block',
      'core_spotlight-block_1',
      'agri_stakeholders-block_1',
      // Digitization toolbox news spotlight block.
      '4eeb0a1180a820bd7a2ec9acdaf60fb7',
    ),
  );

  $block_no_title = array(
    'menu' => array(
      'menu-service-tools',
      'menu-social-footer',
    ),
    'fat_footer' => array('fat-footer'),
  );

  $block_no_body_class = array(
    'views' => 'community_content-block_content',
  );

  $variables['panel'] = TRUE;
  foreach ($block_no_panel as $key => $deltas) {
    foreach ($deltas as $value) {
      if ($variables['block']->module == $key && $variables['block']->delta == $value) {
        $variables['panel'] = FALSE;
      }
    }
  }

  $variables['title'] = TRUE;
  foreach ($block_no_title as $key => $deltas) {
    foreach ($deltas as $value) {
      if ($variables['block']->module == $key && $variables['block']->delta == $value) {
        $variables['title'] = FALSE;
      }
    }
  }

  $variables['body_class'] = TRUE;
  foreach ($block_no_body_class as $key => $value) {
    if ($variables['block']->module == $key && $variables['block']->delta == $value) {
      $variables['body_class'] = FALSE;
    }
  }

  // For bean blocks.
  if ($variables['block']->module == 'bean') {
    // Get the bean elements.
    $beans = $variables['elements']['bean'];
    // There is only 1 bean per block.
    $bean = reset($beans);
    // Add bean type classes to the parent block.
    $variables['classes_array'][] = drupal_html_class('block-bean-' . $bean['#bundle']);
    // Add template suggestions for bean types.
    $variables['theme_hook_suggestions'][] = 'block__bean__' . $bean['#bundle'];
  }
}

/**
 * Overrides theme_menu_link().
 */
function agri_theme_menu_link__menu_block__agri_pages_side_menu($variables) {
  $element = $variables['element'];
  $element['#localized_options']['html'] = TRUE;
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  // On primary navigation menu, class 'active' is not set on active menu item.
  // @see https://drupal.org/node/1896674
  if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']))) {
    $element['#attributes']['class'][] = 'active';
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>";
}

/**
 * Overrides theme_menu_link().
 */
function agri_theme_menu_link__menu_block__menu_core_action_menu($variables) {
  $element = $variables['element'];
  $element['#localized_options']['html'] = TRUE;
  $sub_menu = '';

  // On primary navigation menu, class 'active' is not set on active menu item.
  // @see https://drupal.org/node/1896674
  if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']))) {
    $element['#attributes']['class'][] = 'active';
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>";
}

/**
 * Overrides theme_menu_link().
 *
 * This is the Digitization toolbox 1st level menu navigation block.
 */
function agri_theme_menu_link__menu_block__agri_digitization_toolbox_menu($variables) {
  $element = $variables['element'];
  $element['#localized_options']['html'] = TRUE;

  // Check for a set querytring.
  $params = drupal_get_query_parameters();

  // If a querystring is set and contains a numeric tid for country.
  if (!empty($params['country'])) {
    // Add the exisiting country querystring parameter to menu items.
    $element['#localized_options']['query']['country'] = $params['country'];
  }

  // Build menu item link.
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);

  // If a menu item in this menu has children, render them.
  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
    return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>";
  }

  // Render menu items with no children.
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . "</li>";
}

/**
 * Overrides theme_menu_link().
 */
function agri_theme_menu_link__menu_core_search_find($variables) {
  $element = $variables['element'];
  $element['#localized_options']['html'] = TRUE;
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }

  $title = $element['#title'];
  $id = isset($element['#localized_options']['attributes']) ? $element['#localized_options']['attributes']['class'][0] : '';
  $description = isset($element['#localized_options']['attributes']['title']) ? $element['#localized_options']['attributes']['title'] : '';
  $icon = theme('image', array('path' => drupal_get_path('theme', 'agri_theme') . '/images/icons-' . $id . '.png'));

  $element['#title'] = '<span class="menu-link--search-find--icon">' . $icon . '</span> ';
  $element['#title'] .= '<span class="menu-link--search-find--title">' . $title . '</span> ';
  $element['#title'] .= '<span class="menu-link--search-find--description">' . $description . '</span> ';
  $element['#localized_options']['attributes']['title'] = $title . ' ' . $description;
  $element['#localized_options']['attributes']['class'][] = 'clearfix';

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>";
}

/**
 * Overrides theme_menu_link().
 */
function agri_theme_menu_link__main_menu(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    // Prevent dropdown functions from being added to management menu so it
    // does not affect the navbar module.
    if (($element['#original_link']['menu_name'] == 'management') && (module_exists('navbar'))) {
      $sub_menu = drupal_render($element['#below']);
    }
    elseif ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] == 1)) {

      // Check if menu item has the hide-children setting in configuration.
      $hide_children = isset($element['#localized_options']['attributes']['data-hide-children'])
        && $element['#localized_options']['attributes']['data-hide-children'] == 1;

      // Print item children of menu items with no hide-children property set.
      if (!$hide_children) {
        // Add our own wrapper.
        unset($element['#below']['#theme_wrappers']);
        $sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';
        // Generate as standard dropdown.
        $element['#title'] .= ' <span class="caret"></span>';
        $element['#attributes']['class'][] = 'dropdown';
        $element['#localized_options']['html'] = TRUE;

        // Set dropdown trigger element to # to prevent inadvertant page loading
        // when a submenu link is clicked.
        $element['#localized_options']['attributes']['data-target'] = '#';
        $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
        $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
        $element['#localized_options']['attributes']['data-hover'] = 'dropdown';
      }
    }
  }
  // On primary navigation menu, class 'active' is not set on active menu item.
  // @see https://drupal.org/node/1896674
  if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']))) {
    $element['#attributes']['class'][] = 'active';
  }
  $element['#localized_options']['html'] = TRUE;
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>";
}

/**
 * Overrides theme_menu_link().
 *
 * This is the Digitization toolbox menu.
 */
function agri_theme_menu_link__menu_digitization_toolbox($variables) {
  $element = $variables['element'];
  $element['#localized_options']['html'] = TRUE;

  $params = drupal_get_query_parameters();

  // If a querystring is set and contains a numeric tid for country.
  if (!empty($params['country'])) {
    // Add the exisiting country querystring parameter to menu items.
    $element['#localized_options']['query']['country'] = $params['country'];
  }

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . "</li>";
}

/**
 * Returns HTML for a link to a file.
 *
 * @param array $variables
 *   An associative array containing:
 *   - file: A file object to which the link will be created.
 *   - icon_directory: (optional) A path to a directory of icons to be used for
 *     files. Defaults to the value of the "file_icon_directory" variable.
 *
 * @ingroup themeable
 *
 * @throws \Exception
 *
 * @return string
 *   returns the html containing the file span.
 */
function agri_theme_file_link(array $variables) {
  $file = $variables['file'];
  $icon_directory = $variables['icon_directory'];

  $url = file_create_url($file->uri);
  $icon = theme('file_icon', array(
    'file' => $file,
    'icon_directory' => $icon_directory,
  ));

  // Set options as per anchor format described at
  // http://microformats.org/wiki/file-format-examples
  $options = array(
    'attributes' => array(
      'type' => $file->filemime . '; length=' . $file->filesize,
    ),
  );

  // Use the description as the link text if available.
  if (empty($file->description)) {
    $link_text = $file->filename;
  }
  else {
    $link_text = $file->description;
    $options['attributes']['title'] = check_plain($file->filename);
  }

  $options['attributes']['target'] = '_blank';
  return '<span class="file">' . $icon . ' ' . l($link_text, $url, $options) . '</span>';
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function agri_theme_form_search_block_form_alter(&$form, &$form_state, $form_id) {
  $form['actions']['submit']['#type'] = 'submit';
  $form['search_block_form']['#attributes']['placeholder'] = array();
}

/**
 * Implements template_preprocess_taxonomy_term().
 */
function agri_theme_preprocess_taxonomy_term(&$variables) {
  $vocabulary = $variables['vocabulary_machine_name'];
  $view_mode = $variables['view_mode'];
  $variables['theme_hook_suggestions'][] = 'taxonomy_term__' . $vocabulary . '__' . $view_mode;
}

/**
 * Returns HTML for the deactivation widget.
 *
 * @param mixed $variables
 *   An associative array containing the keys 'text', 'path', and 'options'. See
 *   the l() function for information about these variables.
 *
 * @see l()
 * @see theme_facetapi_link_active()
 *
 * @ingroup themable
 */
function agri_theme_facetapi_deactivate_widget($variables) {
  // Theme the "remove" facet filter with a glyphicon.
  return '<span class="glyphicon glyphicon-remove" aria-hidden="true"></span> ';
}

/**
 * Implements theme_apachesolr_search_mlt_recommendation_block().
 */
function agri_theme_apachesolr_search_mlt_recommendation_block($vars) {

  $attributes = array(
    'class' => 'nav nav-pills nav-stacked',
  );

  $docs = $vars['docs'];
  $links = array();
  foreach ($docs as $result) {
    // Suitable for single-site mode. Label is already safe.
    $links[] = l($result->label, $result->path, array('html' => TRUE));
  }
  $links = array(
    '#theme' => 'item_list',
    '#items' => $links,
    '#type' => 'ul',
    '#attributes' => $attributes,
  );
  return render($links);
}

/**
 * Implements theme_easy_breadcrumb().
 */
function agri_theme_easy_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];
  $segments_quantity = $variables['segments_quantity'];
  $separator = $variables['separator'];

  $html = '';

  if ($segments_quantity > 0) {

    $html .= '<div class="easy-breadcrumb">';

    for ($i = 0, $s = $segments_quantity - 1; $i < $segments_quantity; ++$i) {
      $it = $breadcrumb[$i];
      $content = decode_entities($it['content']);
      if (isset($it['url'])) {
        // Check if breadcrumb link points to Digitisation toolbox.
        if (strpos($it['url'], AGRI_DIGITIZATION_TOOLBOX_SECTION_PATH) !== FALSE) {
          // Then get query string.
          $params = drupal_get_query_parameters();
          // Check if country parameter exists to do query string manipulation.
          if ($params && !empty($params['country'])) {
            // Build the query string.
            $query = drupal_http_build_query($params);
            $it['url'] .= '?' . $query;
          }
        }
        // Build the breadcrumb item.
        $html .= urldecode(l($content, $it['url'], ['attributes' => ['class' => $it['class']]]));
      }
      else {
        $class = implode(' ', $it['class']);
        $html .= '<span class="' . $class . '">' . filter_xss($content) . '</span>';
      }
      if ($i < $s) {
        $html .= '<span class="easy-breadcrumb_segment-separator"> ' . $separator . ' </span>';
      }
    }

    $html .= '</div>';
  }

  return $html;
}

/**
 * Implements template_quicktabs_alter().
 */
function agri_theme_quicktabs_alter($quicktabs) {
  if ($quicktabs->machine_name == 'agri_eip_digitization_activities') {
    // Change quicktabs title in frontend but preserves it in backend.
    $quicktabs->title = 'EIP-AGRI activities';
  }
}

/**
 * Implements template_preprocess_date_views_pager().
 *
 * @see template_preprocess_date_views_pager()
 */
function agri_theme_preprocess_date_views_pager(&$vars) {
  $view = $vars['plugin']->view;

  if ($view->name == 'agri_calendar') {

    $container_item_list_class = array(
      'date-nav',
      'item-list',
    );

    $date_info = $view->date_info;
    $granularity = !empty($date_info->granularity) ? $date_info->granularity : 'month';

    if (!empty($vars['prev_url'])) {
      $prev_text = '< ';
      $vars['prev_url'] = l($prev_text, $vars['prev_url'], $vars['prev_options']);
    }

    if (!empty($vars['next_url'])) {
      $next_text = ' >';
      $vars['next_url'] = l($next_text, $vars['next_url'], $vars['next_options']);
    }

    // Add a "current date" button.
    if (!$date_info->mini) {
      $options = array(
        'attributes' => array(
          'title' => t('Navigate to current @granularity', array(
            '@granularity' => $granularity,
          )),
          'rel' => 'nofollow',
        ),
        'HTML' => TRUE,
      );

      $url = '#';
      switch ($granularity) {
        case 'year':
          $url = date_pager_url($view, NULL, date('Y'));
          break;

        case 'month':
          $url = date_pager_url($view, NULL, date('Y-m'));
          break;

        case 'day':
          $url = date_pager_url($view, NULL, date('Y-m-d'));
          break;
      }

      $link_text = t('Current @granularity', array(
        '@granularity' => $granularity,
      ));

      $vars['current_date'] = l($link_text, $url, $options);
      $container_item_list_class[] = 'calendar-full';
    }
    else {
      $container_item_list_class[] = 'calendar-mini';
    }

    $vars['container_item_list_class'] = implode(' ', $container_item_list_class);
  }
}

/**
 * Implements theme_preprocess_views_view().
 */
function agri_theme_preprocess_views_view(&$vars) {
  $view = $vars['view'];

  // Add css generated form colors module.
  if ($view->name == 'agri_calendar') {
    drupal_add_css(colors_create_css('agri_events'));
  }
}

/**
 * Implements template_preprocess_views_view_fields().
 */
function agri_theme_preprocess_views_view_fields(&$vars) {
  $view = $vars['view'];

  if ($view->name == 'core_profile_user_details' || $view->name == 'core_find_people') {

    $fields = $vars['fields'];
    $picture = '';

    // Take a picture from the field "field_user_picture".
    if (isset($fields['field_user_picture']) && !empty($fields['field_user_picture'])) {
      $picture = $fields['field_user_picture']->content;
      unset($vars['fields']['field_user_picture']);
    }

    // If not set a picture, retrieve the default picture.
    if (empty($picture)) {
      $default_picture = _agri_theme_get_profile_default_image();
      $picture = drupal_render($default_picture);
    }

    $vars['picture'] = $picture;
  }

}

/**
 * Get the default image profile for AGRI.
 *
 * @return array
 *   A image render array.
 */
function _agri_theme_get_profile_default_image() {
  $default_image = array();
  $fid = variable_get('profile_default_image_fid');

  $file = file_load($fid);
  $image = image_load($file->uri);
  if ($image) {
    $default_image = array(
      'file' => array(
        '#theme' => 'image_style',
        '#style_name' => 'profile_thumbnail',
        '#path' => $image->source,
      ),
    );
  }

  return $default_image;
}
