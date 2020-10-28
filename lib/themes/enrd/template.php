<?php

/**
 * @file
 * Default theme functions.
 */

/**
 * Implements hook_css_alter().
 */
function enrd_css_alter(&$css) {
  // Remove unnecessary css.
  unset($css[drupal_get_path('module', 'system') . '/system.menus.css']);
  unset($css[drupal_get_path('theme', 'ec_resp') . '/css/ec_resp.css']);
  unset($css[drupal_get_path('theme', 'ec_resp') . '/css/ec_resp.min.css']);
}

/**
 * Implements hook_js_alter().
 */
function enrd_js_alter(&$js) {
  $js[drupal_get_path('theme', 'enrd') . '/scripts/enrd.js']['scope'] = 'footer';
}

/**
 * Implements hook_preprocess_HOOK().
 */
function enrd_preprocess_enrd_token_menu(&$variables) {

  $menu_attributes = menu_attributes_get_menu_attribute_info();
  foreach ($variables['menu_tree'] as $key => $item) {
    $span_attributes = [];
    if ((is_int($key))) {
      // Add active class to current active list item.
      if (($item['#href'] == $_GET['q'] || ($item['#href'] == '<front>' && drupal_is_front_page())) && (empty($item['#localized_options']['language']))) {
        $item['#attributes']['class'][] = 'active';
      }
      // Get icon or classes for the menu item.
      $icon = isset($item['#localized_options']['attributes']['data-image']) ? $item['#localized_options']['attributes']['data-image'] : '';
      $class = isset($item['#localized_options']['attributes']['class']) ? $item['#localized_options']['attributes']['class'] : '';

      if (in_array($icon, array_keys($menu_attributes['data-image']['form']['#options'][ENRD_MASTERMIND_ENRD_ICONS]))) {
        // Add the enrd icon class name.
        $span_attributes['class'] = 'icon ' . $icon;
      }
      elseif (in_array($icon, $menu_attributes['data-image']['form']['#options'][ENRD_MASTERMIND_GLYPHICONS_ICONS])) {
        // Add the default glyphicon class name.
        $span_attributes['class'] = 'glyphicon glyphicon-' . $icon;
      }
      else {
        // Add the css class in span element.
        if ($class) {
          // Remove class applied on link, and use only class on span element.
          unset($item['#localized_options']['attributes']['class']);
          $span_attributes['class'] = $class;
        }
      }

      // Icon html tag to render.
      $icon_tag = [
        '#type' => 'html_tag',
        '#tag' => 'span',
        '#attributes' => $span_attributes,
        '#value' => '',
      ];

      // Render icon html tag.
      $item['#title'] = drupal_render($icon_tag) . $item['#title'];

      $items[] = [
        'data' => l($item['#title'], $item['#href'], [
          'html' => TRUE,
          'attributes' => $item['#localized_options']['attributes'],
        ]),
        // Classes for list item.
        'class' => $item['#attributes']['class'],
      ];
    }
  }

  if (!empty($items)) {
    $data = [
      'items' => $items,
      'type' => 'ul',
    ];

    $variables['content'] = theme('item_list', $data);
  }
}

/**
 * Implements hook_preprocess_block().
 */
function enrd_preprocess_block(&$variables) {
  global $user;

  // Add theme suggestion for blocks based on regions, module, delta and page.
  $variables['theme_hook_suggestions'][] = 'block__' . $variables['block']->region . '__' . $variables['block']->module;
  $variables['theme_hook_suggestions'][] = 'block__' . $variables['block']->region . '__' . $variables['block']->module . '__' . strtr($variables['block']->delta, '-', '_');
  $path_args = explode('/', current_path());
  if ($suggestions = theme_get_suggestions($path_args, 'block__' . $variables['block']->region . '__' . $variables['block']->module . '__' . strtr($variables['block']->delta, '-', '_'))) {
    $variables['theme_hook_suggestions'] = array_merge($variables['theme_hook_suggestions'], $suggestions);
  }

  if (isset($variables['block']->bid)) {
    switch ($variables['block']->bid) {
      case 'multisite_og_button-og-contextual-links':
        $link_options = array(
          'attributes' => array(
            'class' => array(
              'btn',
              'btn-default',
              'dropdown-toggle',
            ),
            'data-toggle' => 'dropdown',
          ),
          'html' => TRUE,
          'external' => TRUE,
        );

        $dropdown_toggle = array(
          '#theme' => 'link',
          '#text' => t('Create content') . ' <span class="caret"></span>',
          '#path' => '#',
          '#options' => $link_options,
        );
        $variables['dropdown_toggle'] = render($dropdown_toggle);
        break;

      case 'system-user-menu':

        if ($variables['logged_in']) {
          $name = theme('username', array(
            'account' => $user,
            'nolink' => TRUE,
          ));
          // Format welcome message.
          $variables['welcome_message'] = l(t('<span>Welcome, </span><strong>!user</strong> <span class="glyphicon glyphicon-chevron-down btn"></span>', array('!user' => $name)), '', array(
            'attributes' => array(
              'class' => 'dropdown-toggle',
              'data-toggle' => 'dropdown',
            ),
            'html' => TRUE,
            'external' => TRUE,
            'fragment' => '',
          ));
        }

        $menu = menu_navigation_links("user-menu");
        $items = array();

        // Manage redirection after login.
        $status = drupal_get_http_header('status');
        if (strpos($status, '404') !== FALSE) {
          $dest = 'home';
        }
        elseif (strpos(current_path(), 'user/register') !== FALSE) {
          $dest = 'home';
        }
        elseif (strpos(current_path(), 'user/login') !== FALSE) {
          $dest = 'home';
        }
        else {
          $dest = drupal_get_path_alias();
        }

        foreach ($menu as $item) {
          // Get icon links to menu item.
          $icon = (isset($item['attributes']['data-image']) ? $item['attributes']['data-image'] : '');

          // Get display title option.
          $display_title = (isset($item['attributes']['data-display-title']) ? $item['attributes']['data-display-title'] : 1);

          // Add the icon.
          if ($icon) {
            if ($display_title) {
              if ($variables['logged_in']) {
                $item['title'] = '<span class="glyphicon glyphicon-' . $icon . '" aria-hidden="true"></span> ' . $item['title'];
              }
              else {
                $item['title'] = '<span>' . $item['title'] . '</span>' . '<span class="glyphicon glyphicon-' . $icon . '" aria-hidden="true"></span>';
              }
            }
            else {
              // If the title is not supposed to be displayed, add a visually
              // hidden title that is accessible for screen readers.
              $item['title'] = '<span class="glyphicon glyphicon-' . $icon . ' menu-no-title" aria-hidden="true"></span><span class="sr-only">' . $item['title'] . '</span>';
            }
          }

          // Add redirection for login, logout and register.
          if ($item['href'] == 'user/login' || $item['href'] == 'user/register') {
            $item['query']['destination'] = $dest;
          }
          if ($item['href'] == 'user/logout') {
            $item['query']['destination'] = '<front>';
          }

          $items[] = array(
            'data' => l($item['title'], $item['href'], array(
              'html' => TRUE,
              'attributes' => $item['attributes'],
            )),
          );
        }

        $data = array(
          'items' => $items,
          'type' => 'ul',
        );
        $variables['link_list'] = theme('dropdown', $data);

        if ($variables['logged_in']) {
          $data['attributes']['class'] = 'dropdown-menu';
          $variables['link_list'] = theme('dropdown', $data);
        }
        else {
          $variables['link_list'] = theme('item_list', $data);
        }
        break;

      // Override language selector splash screen with dropdown list.
      case 'language_selector_site-language_selector_site':
        $languages = language_list('enabled')[1];
        $path = drupal_get_path_alias();
        foreach ($languages as $lang) {
          // Exclude current language from dropdown list.
          if ($lang->language != $variables['elements']['code']['#markup']) {
            // Collect list of link and attributes to print.
            $items[] = [
              'data' => l('<span class="lang-select-site__code">' . $lang->language . '</span>' .
                '<span class="lang-select-site__label">' . $lang->native . '</span>', $path,
                [
                  'html' => TRUE,
                  'attributes' => ['class' => ['lang-select-site__link']],
                  'language' => $lang,
                ]),
            ];
          }
        }
        $data = [
          'items' => $items,
          'type' => 'ul',
          'attributes' => ['class' => ['lang-select-site__list']],
        ];

        // Add languages list to template variables.
        $variables['languages_list'] = theme('item_list', $data);
        break;

      // Override language selector page block.
      case 'language_selector_page-language_selector_page':
        // Initialize variables.
        $not_available = '';
        $served = '';
        $other = '';

        // Render 'not_available' languages.
        if (!empty($variables['elements']['not_available']['#markup'])) {
          $not_available = '<li class="lang-select-page__not-available">' . $variables['elements']['not_available']['#markup']->native . ' ' . t('not available') . '</li>';
        }
        // Render 'served' languages.
        if (!empty($variables['elements']['served']['#markup'])) {
          $served = '<li class="lang-select-page__served">' . $variables['elements']['served']['#markup']->native . '</li>';
        }
        // Render 'other' languages.
        if (!empty($variables['elements']['other']['#markup'])) {
          // Order the language list by using language weight.
          uasort($variables['elements']['other']['#markup'], 'multisite_drupal_toolbox_sort_weight_object');

          // Render elements.
          foreach ($variables['elements']['other']['#markup'] as $code => $lang) {
            $options = array(
              'query' => drupal_get_query_parameters(),
            );
            $options['query']['2nd-language'] = $code;
            $other .= '<li title="' . $lang->native . '" class="lang-select-page__other">' . l($lang->language, current_path(), $options) . '</li>';
          }
        }
        // Add content to block.
        $content = '<ol>' . $not_available . $served . $other . '</ol>';
        $variables['content'] = $content;
        break;

      case 'enrd_notifications-enrd_notifications_panel':
        // Add a simple loading message on panel loading.
        $variables['panel_loading_message'] = t('Loading user notifications panel...');
        break;

      case 'enrd_lag_dashboard-enrd_menu_local_tasks':
        // Add class to lag contextual links menu items wrapper.
        $variables['classes_array'][] = 'enrd-list';
        break;

      // ENRD menus that use icons system.
      case 'menu-menu-enrd-tools':
      case 'menu-menu-enrd-sfr-pub-subscribe':
      case 'menu-menu-enrd-portals':

        $menu = menu_navigation_links($variables['block']->delta);
        $menu_attributes = menu_attributes_get_menu_attribute_info();

        foreach ($menu as $item) {
          // Get icon or classes for the menu item.
          $icon = (isset($item['attributes']['data-image']) ? $item['attributes']['data-image'] : '');
          $class = (isset($item['attributes']['class']) ? implode(" ", $item['attributes']['class']) : '');

          if (in_array($icon, array_keys($menu_attributes['data-image']['form']['#options'][ENRD_MASTERMIND_ENRD_ICONS]))) {
            // Add the enrd icon class name.
            $item['title'] = '<span class="icon ' . $icon . '"></span>' . $item['title'];
            unset($item['attributes']['class']);
          }
          elseif (in_array($icon, $menu_attributes['data-image']['form']['#options'][ENRD_MASTERMIND_GLYPHICONS_ICONS])) {
            // Add the default glyphicon class name.
            $item['title'] = '<span class="glyphicon glyphicon-' . $icon . '"></span>' . $item['title'];
            unset($item['attributes']['class']);
          }
          else {
            // Add the css class in span element.
            if ($class) {
              $item['title'] = '<span class="' . $class . '"></span>' . $item['title'];
              unset($item['attributes']['class']);
            }
          }

          $items[] = [
            'data' => l($item['title'], $item['href'], [
              'html' => TRUE,
              'attributes' => $item['attributes'],
            ]),
          ];
        }

        $data = [
          'items' => $items,
          'type' => 'ul',
        ];

        // Add specific classes to render icons in menu block.
        $variables['classes_array'][] = 'block-icons-menu';

        $variables['content'] = theme('item_list', $data);
        break;

      // Create menu_breadcrumb variable to be printed in breadcrumb block.
      case 'enrd_mastermind-enrd_easy_breadcrumb':
        $variables['menu_breadcrumb'] = menu_tree('menu-breadcrumb-menu');
        break;

    }
  }
}

/**
 * Implements hook_preprocess_page().
 */
function enrd_preprocess_page(&$variables) {

  $variables['includes_path'] = $variables['directory'] . '/templates/global/includes/';

  $item = menu_get_item();
  // Custom page template suggestion for views.
  if ($item['page_callback'] == 'views_page') {
    $arguments[] = $item['page_arguments'][0];
    if (is_string($item['page_arguments'][1])) {
      $arguments[] = $item['page_arguments'][1];
    }
    $variables['theme_hook_suggestions'] = array_merge($variables['theme_hook_suggestions'], theme_get_suggestions($arguments, 'page__view'));
  }

  // Add multiple suggestions for pages based on content type.
  if (isset($variables['node'])) {
    $variables['theme_hook_suggestions'][] = 'page__' . $variables['node']->type;
  }

  // Disable custom page.tpl for language selector.
  if (($key = array_search('page__language_selector__site_language', $variables['theme_hook_suggestions'])) !== FALSE) {
    unset($variables['theme_hook_suggestions'][$key]);
  }

  $regions = $variables['regions'];

  // Custom format region for theme "enrd".
  $regions['content_bottom_left'] = (isset($variables['page']['content_bottom_left']) ? render($variables['page']['content_bottom_left']) : '');
  $regions['content_bottom_right'] = (isset($variables['page']['content_bottom_right']) ? render($variables['page']['content_bottom_right']) : '');

  $regions['tools_buttons'] = (isset($variables['page']['tools_buttons']) ? render($variables['page']['tools_buttons']) : '');
  $regions['focus'] = (isset($variables['page']['focus']) ? render($variables['page']['focus']) : '');
  $regions['footer_top'] = (isset($variables['page']['footer_top']) ? render($variables['page']['footer_top']) : '');

  // Check if there is a responsive sidebar or not.
  $has_responsive_sidebar = $variables['has_responsive_sidebar'];

  // Calculate size of regions.
  $cols = array();

  // Sidebars.
  $cols['sidebar_left'] = array(
    'lg' => (!empty($regions['sidebar_left']) ? 3 : 0),
    'md' => (!empty($regions['sidebar_left']) ? 3 : 0),
    'sm' => (!empty($regions['sidebar_left']) ? 12 : 0),
    'xs' => (!empty($regions['sidebar_left']) ? 12 : 0),
  );

  $cols['sidebar_right'] = array(
    'lg' => (!empty($regions['sidebar_right']) ? 4 : 0),
    'md' => (!empty($regions['sidebar_right']) ? 4 : 0),
    'sm' => (!empty($regions['sidebar_right']) ? 12 : 0),
    'xs' => (!empty($regions['sidebar_right']) ? 12 : 0),
  );

  // Main content section - includes right sidebar.
  $cols['content_main'] = array(
    'lg' => 12 - $cols['sidebar_left']['lg'],
    'md' => 12 - $cols['sidebar_left']['md'],
    'sm' => 12,
    'xs' => 12,
  );

  $cols['content_right'] = array(
    'lg' => (!empty($regions['content_right']) ? 3 : 0),
    'md' => (!empty($regions['content_right']) ? 3 : 0),
    'sm' => (!empty($regions['content_right']) ? 12 : 0),
    'xs' => (!empty($regions['content_right']) ? 12 : 0),
  );

  $cols['content'] = array(
    'lg' => 12 - $cols['sidebar_right']['lg'] - $cols['content_right']['lg'],
    'md' => 12 - $cols['sidebar_right']['lg'] - $cols['content_right']['md'],
    'sm' => 12,
    'xs' => 12,
  );

  // Tools.
  $cols['sidebar_button'] = array(
    'xs' => ($has_responsive_sidebar ? 2 : 0),
  );
  $cols['tools'] = array(
    'lg' => 12,
    'md' => 12,
    'sm' => 12,
    'xs' => 0,
  );

  // Sidebar left offset.
  $cols['sidebar_left_offset'] = array(
    'lg' => $cols['content_main']['lg'],
    'md' => $cols['content_main']['md'],
  );

  // Content offset.
  $cols['content_main_offset'] = array(
    'lg' => (!empty($regions['sidebar_left']) ? $cols['sidebar_left']['lg'] : 0),
    'md' => (!empty($regions['sidebar_left']) ? $cols['sidebar_left']['md'] : 0),
  );

  // Add variables to template file.
  $variables['regions'] = $regions;
  $variables['cols'] = $cols;

  // Show content type in the page title in some content types.
  if (!empty($variables['node']) && $item['path'] == 'node/%') {
    switch ($variables['node']->type) {
      case 'cooperation_offer':
        $variables['title_prefix'] = '<span class="title-prefix ' . $variables['node']->type . '">' . t('Cooperation Offer') . '</span>';
        break;

      case 'lag':
        $variables['title_prefix'] = '<span class="title-prefix ' . $variables['node']->type . '">' . t('LAG Profile') . '</span>';
        break;
    }
  }

  // Change default "Edit" in "Update" before node type and title.
  if (!empty($variables['node']) && $variables['node']->type == ENRD_LAG_DATABASE_LAG_GROUP_NODE && $item['path'] == 'node/%/edit') {
    drupal_set_title(t('<em>Update @type</em> @title', [
      '@type' => node_type_get_name(ENRD_LAG_DATABASE_LAG_GROUP_NODE),
      '@title' => $variables['node']->title,
    ]), PASS_THROUGH);
  }

  // Hides the "RDP information" page title if the Country term has no value.
  if (!empty($variables['node']) && $variables['node']->type == 'rdp_information' && $item['path'] == 'node/%') {
    if (isset($variables['node']->title) && !empty($variables['node']->title)
      && !empty($variables['node']->field_enrd_rdp_info_country)) {
      $variables['title'] = FALSE;
    }
  }

}

/**
 * Implements hook_preprocess_html().
 */
function enrd_preprocess_html(&$variables) {
  // Add conditional stylesheet for IE.
  drupal_add_css(path_to_theme() . '/css/enrd.ie.css', array(
    'group' => CSS_THEME,
    'browsers' => array(
      'IE' => 'lte IE 9',
      '!IE' => FALSE,
    ),
    'preprocess' => FALSE,
  ));

  // Change default "Edit" in "Update" before node type and title.
  if (isset($variables['page']['content']['system_main']['type']) && $variables['page']['content']['system_main']['type']['#value'] == ENRD_LAG_DATABASE_LAG_GROUP_NODE
    && isset($variables['page']['content']['system_main']['nid']['#value'])) {
    // Change default "Edit" in "Update" before node type and title.
    $variables['head_title'] = t('@title @separator @site_name', [
      '@title' => $variables['head_title_array']['title'],
      '@separator' => " | ",
      '@site_name' => $variables['head_title_array']['name'],
    ]);
  }
}

/**
 * Implements hook_preprocess_easy_breadcrumb().
 */
function enrd_preprocess_easy_breadcrumb(&$variables) {
  // Fix easy breadcrumb items with formatted.
  foreach ($variables['breadcrumb'] as &$crumb) {
    $crumb['content'] = strip_tags($crumb['content']);
  }

  $item = menu_get_item();

  // Change LAGs breacrumb in Edit (now Update).
  if ($item['path'] == 'node/%/edit' && $item['page_arguments'][1]->type == ENRD_LAG_DATABASE_LAG_GROUP_NODE
    && isset($item['page_arguments'][1]->nid)) {
    $variables['breadcrumb'][2]['content'] = t('Update @type @title', [
      '@type' => node_type_get_name(ENRD_LAG_DATABASE_LAG_GROUP_NODE),
      '@title' => $item['page_arguments'][1]->title,
    ]);
  }

  // Custom breadcrumb for "Contact this LAG" webform submission.
  if ((isset($item['page_arguments'][0]->uuid) && ($item['page_arguments'][0]->uuid == ENRD_LAG_DATABASE_LAG_CONTACT_UUID))
    && ($item['tab_root'] == 'node/%/submission/%')) {
    $submission = array_pop($variables['breadcrumb']);
    unset($variables['breadcrumb']);
    $variables['breadcrumb'][0] = array(
      'content' => t('Manage my LAG: Replies to my Cooperation offers'),
      'class' => $submission['class'],
      'url' => 'my-lags/' . $item['page_arguments'][1]->data[7][0] . '/manage/contact-form',
    );
    $variables['breadcrumb'][1] = $submission;
    $variables['segments_quantity'] = count($variables['breadcrumb']);
  }

  // Count and remove the last occurrence if present many time with same name.
  $content = array_column($variables['breadcrumb'], 'content');
  $occurrence = array_keys($content, end($content));
  if (count($occurrence) > 1) {
    array_pop($variables['breadcrumb']);
    $variables['segments_quantity']--;
  }

}

/**
 * Implements theme_menu_tree().
 */
function enrd_menu_tree__main_menu($variables) {
  return '<ul class="menu clearfix nav">' . $variables['tree'] . '</ul>';
}

/**
 * Implements theme_menu_link().
 */
function enrd_menu_link__main_menu(&$variables) {
  $element = $variables['element'];
  $sub_menu = '';
  $hide_children = (isset($variables['element']['#localized_options']['attributes']['data-hide-children']) ? $variables['element']['#localized_options']['attributes']['data-hide-children'] : 0);

  // Test if there is a sub menu and if it has to be displayed.
  if ($element['#below'] && !$hide_children) {

    // Render sub menu.
    $sub_menu = drupal_render($element['#below']);

    if (!theme_get_setting('disable_dropdown_menu') && !in_array('dropdown', $element['#attributes']['class'])) {
      // Add carret and class.
      $element['#attributes']['class'][] = 'dropdown';

      // Add attributes to children items.
      $element['#localized_options']['attributes']['class'] = array();
      $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
      $element['#localized_options']['attributes']['class'][] = 'disabled';
      $element['#localized_options']['attributes']['data-toggle'][] = 'dropdown';
      $element['#localized_options']['attributes']['data-hover'][] = 'dropdown';

      // Add CSS class to ul tag
      // Dirty, but I see no better way to do it.
      $replace = '<ul data-title="' . $element['#title'] . '"';
      $sub_menu = str_replace('<ul class="menu clearfix nav', $replace, $sub_menu);
    }
  }
  else {
    $element['#localized_options']['attributes']['class'] = array();
  }

  // On primary navigation menu, class 'active' is not set on active menu item.
  // @see https://drupal.org/node/1896674
  if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']))) {
    $element['#attributes']['class'][] = 'active';
  }

  $element['#localized_options']['html'] = TRUE;
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 * Implements hook_preprocess_image_style().
 *
 * @see http://getbootstrap.com/css/#overview-responsive-images
 */
function enrd_preprocess_image_style(&$vars) {
  $vars['attributes']['class'][] = 'img-responsive';
}

/**
 * Implements hook_preprocess_taxonomy_term().
 */
function enrd_preprocess_taxonomy_term(&$variables) {
  $variables['theme_hook_suggestions'][] = 'taxonomy_term__' . $variables['term']->vocabulary_machine_name . '__' . $variables['elements']['#view_mode'];
}

/**
 * Implements theme_menu_tree().
 */
function enrd_menu_tree__menu_enrd_join_us($variables) {

  // Group all first level's children in a boostrap dropdown menu.
  $first_item = reset($variables['#tree']);
  if ($first_item['#original_link']['depth'] == 2) {
    return '<ul class="dropdown-menu">' . $variables['tree'] . '</ul>';
  }

  return '<ul>' . $variables['tree'] . '</ul>';
}

/**
 * Implements theme_menu_link().
 */
function enrd_menu_link__menu_enrd_join_us(&$variables) {
  $element = $variables['element'];

  // Only for first level menu items.
  if ($element['#original_link']['depth'] == 1) {
    $hide_children = (isset($variables['element']['#localized_options']['attributes']['data-hide-children']) ? $variables['element']['#localized_options']['attributes']['data-hide-children'] : 0);

    $span_attributes['class'] = (empty($element['#localized_options']['attributes']['class'])) ? array() : $element['#localized_options']['attributes']['class'];
    $link = '<span' . drupal_attributes($span_attributes) . '></span>';

    // Test if there is a sub menu and if it has to be displayed.
    if ($element['#below'] && !$hide_children) {
      // Use link as a dropdown toggle for the dropdown menu.
      $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
      $element['#localized_options']['attributes']['data-toggle'][] = 'dropdown';
      $element['#localized_options']['attributes']['data-hover'][] = 'dropdown';
    }

    $element['#localized_options']['attributes']['class'] = array();
    $element['#localized_options']['html'] = TRUE;
    $output = l($link, $element['#href'], $element['#localized_options']) . drupal_render($element['#below']);

    // Test if there is a sub menu and if it has to be displayed.
    if ($element['#below'] && !$hide_children) {
      // Render sub menu as a button group.
      $output = '<div class="dropdown dropup">' . $output . '</div>';
    }

  }
  else {
    $link = $element['#title'];
    $output = l($link, $element['#href'], $element['#localized_options']) . drupal_render($element['#below']);
  }

  return '<li>' . $output . "</li>\n";
}

/**
 * Implements theme_menu_tree().
 */
function enrd_menu_tree__menu_enrd_tools($variables) {
  return '<ul>' . $variables['tree'] . '</ul>';
}

/**
 * Implements theme_menu_link().
 */
function enrd_menu_link__menu_enrd_tools(&$variables) {
  $element = $variables['element'];

  $span_attributes['class'] = (empty($element['#localized_options']['attributes']['class'])) ? array() : $element['#localized_options']['attributes']['class'];
  $link = '<span' . drupal_attributes($span_attributes) . '></span>';
  $link .= $element['#title'];
  $element['#localized_options']['attributes']['class'] = array();
  $element['#localized_options']['html'] = TRUE;
  $output = l($link, $element['#href'], $element['#localized_options']);
  return '<li>' . $output . "</li>\n";
}

/**
 * Implements theme_menu_tree().
 */
function enrd_menu_tree__menu_enrd_sfr_pub_subscribe($variables) {
  return '<ul>' . $variables['tree'] . '</ul>';
}

/**
 * Implements theme_menu_link().
 */
function enrd_menu_link__menu_enrd_sfr_pub_subscribe(&$variables) {
  $element = $variables['element'];

  $span_attributes['class'] = (empty($element['#localized_options']['attributes']['class'])) ? array() : $element['#localized_options']['attributes']['class'];
  $link = '<span' . drupal_attributes($span_attributes) . '></span>';
  $link .= $element['#title'];
  $element['#localized_options']['attributes']['class'] = array();
  $element['#localized_options']['html'] = TRUE;
  $output = l($link, $element['#href'], $element['#localized_options']);
  return '<li>' . $output . "</li>\n";
}

/**
 * Implements theme_menu_tree__menu_communities_menu().
 */
function enrd_menu_tree__menu_communities_menu(&$variables) {
  return '<div class="enrd-list"><ul class="list-unstyled">' . $variables['tree'] . '</ul></div>';
}

/**
 * Implements theme_menu_link().
 */
function enrd_menu_link__menu_communities_menu(&$variables) {
  $element = $variables['element'];

  $link = $element['#title'];
  $output = l($link, $element['#href']);
  return '<li>' . $output . "</li>\n";
}

/**
 * Implements theme_menu_tree__menu_breadcrumb_menu().
 */
function enrd_menu_tree__menu_breadcrumb_menu($variables) {
  return $variables['tree'];
}

/**
 * Implements theme_menu_link__menu_breadcrumb_menu().
 */
function enrd_menu_link__menu_breadcrumb_menu(array $variables) {

  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }

  if (theme_get_setting('enable_interinstitutional_theme') && $element['#title'] == 'European Commission') {
    global $language;
    $element['#title'] = 'Europa';
    $element['#href'] = 'http://europa.eu/index_' . $language->language . '.htm';
  }

  // Format output.
  $element['#localized_options']['html'] = TRUE;
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li>' . $output . $sub_menu . '</li>';
}

/**
 * Implements theme_easy_breadcrumb().
 */
function enrd_easy_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];
  $segments_quantity = $variables['segments_quantity'];

  $html = '';

  if ($segments_quantity > 0) {
    for ($i = 0, $segments_quantity - 1; $i < $segments_quantity; ++$i) {
      $it = $breadcrumb[$i];
      $content = decode_entities($it['content']);
      if (isset($it['url'])) {
        $html .= '<li>' . l($content, $it['url'], [
          'attributes' => [
            'class' => $it['class'],
            'title' => $content,
          ],
        ]) . '</li>';
      }
      else {
        $class = implode(' ', $it['class']);
        $html .= '<li class="' . $class . '" title="' . filter_xss($content) . '">' . $content . '</li>';
      }
    }
  }

  return $html;
}

/**
 * Implements hook_preprocess_views_exposed_form().
 */
function enrd_preprocess_views_exposed_form(&$variables) {

  if (isset($variables['widgets']['filter-secondary'])) {
    $form = &$variables['form'];

    // Render again secondary form items into a new variable.
    $form['secondary']['#theme_wrappers'] = array();

    $variables['bef_advanced'] = $variables['widgets']['filter-secondary'];
    $variables['bef_advanced']->widget = render($form['secondary']);
    $variables['bef_advanced']->label = check_plain($form['secondary']['#title']);

    unset($variables['widgets']['filter-secondary']);
  }
}

/**
 * Format the Printer-friendly link.
 *
 * @param mixed $vars
 *   Theme variables.
 *
 * @return array
 *   Returns an array of formatted attributes for the Printer-friendly link.
 */
function enrd_print_ui_format_link($vars) {
  // Custom format for PDF link.
  if ($vars['location'] == 'block' && $vars['format'] == 'pdf') {
    if (function_exists('print_pdf_print_link')) {
      $link = print_pdf_print_link(array());
    }
    return array(
      'text' => '',
      'html' => FALSE,
      'attributes' => _print_ui_fill_attributes($link['description'], 'btn btn-default icon-acrobat', TRUE),
      'rel' => 'nofollow',
    );
  }

  return call_user_func("theme_{$vars['theme_hook_original']}", $vars);
}

/**
 * Implements hook_preprocess_search_result().
 */
function enrd_preprocess_search_result(&$variables) {
  // Remove node author information from search result.
  unset($variables['info_split']['user']);
  // Add Bundle and Date information to the search result view.
  if (isset($variables['result']['node']->bundle_name)) {
    if ($variables['result']['node']->bundle_name == 'Basic page') {
      // Replace "Basic page" with "Page".
      $variables['result']['node']->bundle_name = t('Page');
    }
    // Aggregate the Bundle and Date info.
    $variables['info_split']['type'] = $variables['result']['node']->bundle_name;
    $info_date = date_create_from_format('d/m/Y - H:i', $variables['info_split']['date']);
    $variables['info_date'] = date_format($info_date, 'd/m/Y');
    $variables['info'] = $variables['info_split']['type'] . ' - ' . $variables['info_date'];
  }
}

/**
 * Implements hook_preprocess_search_results().
 */
function enrd_preprocess_search_results(&$variables) {
  // Rewrite Apachesolr results count.
  if ($variables['response']) {
    $total = $variables['response']->response->numFound;

    $variables['description'] = format_plural($total, 'One result', 'Total results: @total.', array('@total' => $total));
  }
}

/**
 * Implements hook_form_alter().
 */
function enrd_form_alter(&$form, &$form_state, $form_id) {
  if ($form['#form_id'] == 'apachesolr_search_custom_page_search_form') {
    $form['basic']['keys']['#size'] = 60;
    $form['basic']['submit']['#type'] = 'submit';
    $form['basic']['submit']['#prefix'] = '<span class="input-group-btn">';
    $form['basic']['submit']['#suffix'] = '</span>';
  }

  // Hide Nexteuropa Multilingual warning message HTML element
  // as explicitly requested for LAG content type.
  // @see https://webgate.ec.europa.eu/CITnet/jira/browse/ENRDPORTAL-200
  if (function_exists('_enrd_lag_database_hide_multilingual_warning_message')) {
    _enrd_lag_database_hide_multilingual_warning_message($form);
  }

}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function enrd_form_search_block_form_alter(&$form, &$form_state, $form_id) {
  $form['search_block_form']['#attributes']['placeholder'][] = t('Search ENRD...');

  unset($form['actions']['submit']['#src']);
  $form['actions']['submit']['#type'] = 'submit';
  $form['actions']['submit']['#attributes']['class'][0] = 'btn-small';
  $form['actions']['submit']['#value'] = t('');
}

/**
 * Alter the way Facet API block titles are rendered.
 *
 * @param mixed $variables
 *   An associative array containing:
 *   - title;
 *   - subject.
 *
 * @return string
 *   Returns the title to print instead of Facet API module's one.
 */
function enrd_facetapi_title($variables) {
  // Rewrite rule to by applied from default field labels.
  $titles = array(
    'Content type' => 'Type',
    'Is your LAG interested in future CLLD Cooperation? Looking for a partner?' => '',
    'Project type' => 'Type of project',
    'Project topic' => 'Topic of the project',
    'Offering LAG' => 'ESI Fund',
    'Publication date' => 'Publication year',
    'Resource type' => 'Type',
  );

  if (isset($variables['title'])) {
    foreach ($titles as $key => $title) {
      if ($variables['title'] == $key) {
        $variables['title'] = $title;
      }
    }
  }

  return check_plain($variables['title']);

}

/**
 * Returns HTML for an active facet item.
 *
 * @param mixed $variables
 *   An associative array containing the keys 'text', 'path', and 'options'. See
 *   the l() function for information about these variables.
 *
 * @see l()
 *
 * @ingroup themeable
 *
 * @return array|string
 *   Rendered html or renderable array.
 */
function enrd_facetapi_link_active($variables) {
  // Replace the facet "Basic page" link with "Page".
  if ($variables['text'] == 'Basic page') {
    $variables['text'] = 'Page';
  }

  // Sanitizes the link text if necessary.
  $sanitize = empty($variables['options']['html']);
  // Align the "Current Search" block selected item text to the facet text.
  if ($variables['text'] == 'Looking for a partner') {
    $variables['text'] = 'LAGs interested in CLLD Cooperation';
  }
  $variables['label'] = ($sanitize) ? check_plain($variables['text']) : $variables['text'];

  // Theme function variables for accessible markup.
  // @see http://drupal.org/node/1316580
  $accessible_vars = array(
    'text' => $variables['text'],
    'active' => TRUE,
  );
  // Builds link, passes through t() which gives us the ability to change the
  // position of the widget on a per-language basis.
  $replacements = array(
    '!facetapi_deactivate_widget' => theme('facetapi_deactivate_widget', $variables),
    '!facetapi_accessible_markup' => theme('facetapi_accessible_markup', $accessible_vars),
  );

  $variables['text'] = t('!facetapi_deactivate_widget !facetapi_accessible_markup', $replacements);
  $variables['options']['html'] = TRUE;

  // Check if the active link is a facet, not a "Current Search" block element
  // and apply custom theme to "field_enrd_lag_interested_in" facet.
  if (isset($variables['count']) && strpos($variables['text'], 'LAGs interested in CLLD Cooperation')) {
    return theme('enrd_lag_database_checkbox_button', $variables);
  }
  elseif (strpos($variables['path'], 'nrn-toolkit') && !empty($variables['children'])) {
    // Apply wrapper and a background image around the active facet link.
    $variables['options']['attributes']['class'][] = 'facetapi-active-text-link';
    $variables['main_cluster_class'] = drupal_html_class($variables['label']);
    return theme('enrd_nrn_toolkit_active_text_link', $variables);
  }
  elseif (strpos($variables['path'], 'nrn-toolkit')
    && (isset($variables['options']['query']['f'][0])
    && (strpos($variables['options']['query']['f'][0], 'im_field_tax_networking:') === FALSE)
      || empty($variables['options']['query'])) && ($variables['path'] == 'networking/nrn-toolkit/')) {
    // Add CSS class to the selected NRN Classification active facet link.
    $variables['options']['attributes']['class'] = 'nrn-networking-selected-link';
    return theme('link', $variables) . $variables['label'];
  }
  else {
    return theme('link', $variables) . $variables['label'];
  }
}

/**
 * Returns HTML for an inactive facet item.
 *
 * Remove an empty space in $variable text when count is active.
 *
 * @param mixed $variables
 *   An associative array containing the keys 'text', 'path', 'options', and
 *   'count'. See the l() and theme_facetapi_count() functions for information
 *   about these variables.
 *
 * @ingroup themeable
 */
function enrd_facetapi_link_inactive($variables) {
  // Replace the facet "Basic page" link with "Page".
  if ($variables['text'] == 'Basic page') {
    $variables['text'] = 'Page';
  }

  // Builds accessible markup.
  // @see http://drupal.org/node/1316580
  $accessible_vars = array(
    'text' => $variables['text'],
    'active' => FALSE,
  );
  $accessible_markup = theme('facetapi_accessible_markup', $accessible_vars);

  // Sanitizes the link text if necessary.
  $sanitize = empty($variables['options']['html']);
  $variables['text'] = ($sanitize) ? check_plain($variables['text']) : $variables['text'];

  // Adds count to link if one was passed.
  if (isset($variables['count'])) {
    $variables['text'] .= theme('facetapi_count', $variables);
  }

  // Resets link text, sets to options to HTML since we already sanitized the
  // link text and are providing additional markup for accessibility.
  $variables['text'] .= $accessible_markup;
  $variables['options']['html'] = TRUE;

  $variables['label'] = $variables['text'];

  if (in_array('bm_field_enrd_lag_interested_in:true', $variables['options']['query']['f'])
    && (strpos($variables['text'], 'LAGs interested in CLLD Cooperation') === 0)) {
    // Check if facet is "field_enrd_lag_interested_in" and exclude the other
    // links after selection.
    return theme('enrd_lag_database_checkbox_button', $variables);
  }
  elseif (strpos($variables['options']['query']['f'][0], 'im_field_tax_networking') === 0
    && empty($variables['options']['query']['f'][1])) {
    // Customize "Networking" facet links as a drop-down.
    $nrn_classification = ltrim($variables['options']['query']['f'][0], 'im_field_tax_networking:');

    if (!empty($nrn_classification)) {
      if (taxonomy_get_children($nrn_classification)) {
        $variables['theme_id'] = $nrn_classification;
        $variables['options']['attributes']['class'][] = 'dropdown';
        return theme('enrd_nrn_toolkit_networking_link', $variables);
      }
    }
  }
  else {
    return theme('link', $variables);
  }
}

/**
 * Format Text of active link facet.
 *
 * @param mixed $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #id, #attributes, #children, #header.
 *
 * @ingroup themeable
 *
 * @return array
 *   The HTML output for this theme implementation.
 */
function theme_enrd_nrn_toolkit_active_text_link($variables) {
  $output = '';

  $output .= '<div' . drupal_attributes($variables['options']['attributes']) . '>';
  $output .= '<span class="' . $variables['main_cluster_class'] . '"></span>';
  $output .= $variables['label'];
  $output .= '</div>';

  return $output;
}

/**
 * Format Drop-down Networking facet.
 *
 * @param mixed $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #id, #attributes, #children, #header.
 *
 * @ingroup themeable
 *
 * @return array
 *   The HTML output for this theme implementation.
 */
function theme_enrd_nrn_toolkit_networking_link($variables) {
  $output = '';

  $output .= '<div' . drupal_attributes($variables['options']['attributes']) . '>';
  $output .= '<button class="btn btn-default dropdown-toggle" type="button" id="dropdownMenu' . $variables['theme_id'] . '" data-toggle="dropdown" aria-haspopup="true" aria-expanded="true">'
    . $variables['label'] . '</button>';
  $output .= '<ul class="dropdown-menu" aria-labelledby="dropdownMenu' . $variables['theme_id'] . '">';
  $output .= '<li class="dropdown-header">' . $variables['label'] . '</li>';
  foreach ($variables['children'] as $child) {
    $output .= '<li><a href="' . check_plain(url($child['child']['path'], $child['child']['options'])) . '"' . drupal_attributes($child['child']['options']['attributes']) . '">' . $child['child']['text'] . '</a></li>';
  }
  $output .= '</ul>';
  $output .= '</div>';

  return $output;
}

/**
 * Format Checkbox Button facet.
 *
 * @param mixed $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #id, #attributes, #children, #header.
 *
 * @ingroup themeable
 *
 * @return array
 *   The HTML output for this theme implementation.
 */
function theme_enrd_lag_database_checkbox_button($variables) {
  $output = '';

  $output .= '<span class="button-checkbox"><button type="button" class="btn" data-color="default">';
  $output .= '<a href="' . check_plain(url($variables['path'], $variables['options'])) . '"' . drupal_attributes($variables['options']['attributes']) . '>' . $variables['label'] . '</a>';
  $output .= '</button></span>';

  return $output;
}

/**
 * Returns HTML for the active facet item's count.
 *
 * @param mixed $variables
 *   An associative array containing:
 *   - count: The item's facet count.
 *
 * @ingroup themeable
 */
function enrd_facetapi_count($variables) {
  // Modify the facet count theme with the bootstrap default "badge" class.
  return '<span class="badge">' . (int) $variables['count'] . '</span>';
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
function enrd_facetapi_deactivate_widget($variables) {
  // Theme the "remove" facet filter with a glyphicon.
  return '<span class="glyphicon glyphicon-remove" aria-hidden="true"></span> ';
}

/**
 * Returns HTML for a search keys facet item.
 *
 * @param mixed $variables
 *   An associative array containing the keys 'keys' and 'adapter'.
 *
 * @ingroup themeable
 */
function enrd_current_search_keys($variables) {
  return '<span class="search-key">' . check_plain($variables['keys']) . '</span>';
}

/**
 * Implements hook_preprocess_field().
 */
function enrd_preprocess_field(&$variables, $hook) {
  // Repeat label for every "Managing Authority" and "Paying Agency" fields.
  if (isset($variables['element']['#bundle']) && $variables['element']['#bundle'] == 'rdp_information') {
    $field_rdp_info_name = $variables['element']['#field_name'];
    if (!empty($field_rdp_info_name) && (
        $field_rdp_info_name == 'field_enrd_rdp_info_nation_auth' ||
        $field_rdp_info_name == 'field_enrd_rdp_info_nat_pay_agen')
    ) {
      foreach ($variables['items'] as &$item) {
        $item['#prefix'] = '<div class="field-label label-above">' . $variables['element']['#title'] . '</div>';
      }
    }

    // Repeat field label for every "Managing Authority" and "Paying Agency"
    // field specified within the "Region" field collection.
    if (!empty($field_rdp_info_name) && $field_rdp_info_name == 'field_enrd_rdp_info_region') {
      foreach ($variables['items'] as &$item) {
        foreach ($item['entity']['field_collection_item'] as &$field_collection_item) {
          if (isset($field_collection_item['field_enrd_rdp_info_region_auth'])) {
            foreach ($field_collection_item['field_enrd_rdp_info_region_auth'] as &$manage_auth) {
              if (is_array($manage_auth)) {
                $manage_auth['#prefix'] = '<div class="field-label label-above">' . $field_collection_item['field_enrd_rdp_info_region_auth']['#title'] . '</div>';
              }
            }
          }

          if (isset($field_collection_item['field_enrd_rdp_info_region_pay'])) {
            foreach ($field_collection_item['field_enrd_rdp_info_region_pay'] as &$manage_pay) {
              if (is_array($manage_pay)) {
                $manage_pay['#prefix'] = '<div class="field-label label-above">' . $field_collection_item['field_enrd_rdp_info_region_pay']['#title'] . '</div>';
              }
            }
          }
        }
      }
    }
  }

  if ($variables['element']['#bundle'] == 'lag') {
    // Removes from display field_enrd_lag_interested_in if value is "No".
    if (isset($variables['element']['#field_name']) && $variables['element']['#field_name'] == 'field_enrd_lag_interested_in'
      && $variables['element']['#items'][0]['value'] == '0') {
      $variables['label_hidden'] = TRUE;
      unset($variables['items'][0]);
    }
    // Apply button classes.
    if (isset($variables['element']['#field_name']) && $variables['element']['#field_name'] == 'field_enrd_lag_extended_profile') {
      $variables['classes_array'][] = 'btn btn-default';
    }
  }
}

/**
 * Returns HTML for a link to a file.
 *
 * @param mixed $variables
 *   An associative array containing:
 *   - file: A file object to which the link will be created.
 *   - icon_directory: (optional) A path to a directory of icons to be used for
 *     files. Defaults to the value of the "file_icon_directory" variable.
 *
 * @ingroup themeable
 *
 * @return string
 *   Rendered link.
 */
function enrd_file_link($variables) {
  $file = $variables['file'];
  $icon_directory = $variables['icon_directory'];

  $url = file_create_url($file->uri);

  // Human-readable names, for use as text-alternatives to icons.
  $mime_name = array(
    'application/msword' => t('Microsoft Office document icon'),
    'application/vnd.ms-excel' => t('Office spreadsheet icon'),
    'application/vnd.ms-powerpoint' => t('Office presentation icon'),
    'application/pdf' => t('PDF icon'),
    'video/quicktime' => t('Movie icon'),
    'audio/mpeg' => t('Audio icon'),
    'audio/wav' => t('Audio icon'),
    'image/jpeg' => t('Image icon'),
    'image/png' => t('Image icon'),
    'image/gif' => t('Image icon'),
    'application/zip' => t('Package icon'),
    'text/html' => t('HTML icon'),
    'text/plain' => t('Plain text icon'),
    'application/octet-stream' => t('Binary Data'),
  );

  $mimetype = file_get_mimetype($file->uri);

  $icon = theme('file_icon', array(
    'file' => $file,
    'icon_directory' => $icon_directory,
    'alt' => !empty($mime_name[$mimetype]) ? $mime_name[$mimetype] : t('File'),
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

  // Merge custom options for the links.
  if (isset($variables['file']->options)) {
    $options = array_merge_recursive($options, (array) $variables['file']->options);
  }

  return '<span class="file">' . $icon . ' ' . l($link_text, $url, $options) . '</span>';
}

/**
 * Override single views field template output for lags.
 *
 * @param mixed $vars
 *   Available variables for the template.
 *
 * @return array
 *   Return the modified $vars array.
 */
function enrd_views_view_field__enrd_lag_database_custom_dashboard__lag_profiles_page__view_node($vars) {
  if ($vars['row']->workbench_moderation_node_history_state == 'draft') {
    $revisions = node_revision_list(node_load($vars['row']->node_revision_nid));
    if (count($revisions) > 1) {
      return $vars['output'];
    }
  }
}

/**
 * Override single views field output for active cooperation offers.
 *
 * @param mixed $vars
 *   Available variables for the template.
 *
 * @return array
 *   Return the modified $vars array.
 */
function enrd_views_view_field__enrd_lag_database_cooperation_offers_dashboard__coop_offers_page_active__view_node($vars) {
  if ($vars['row']->workbench_moderation_node_history_state == 'draft') {
    $revisions = node_revision_list(node_load($vars['row']->node_revision_nid));
    if (count($revisions) > 1) {
      return $vars['output'];
    }
  }
}

/**
 * Override single views field output for expired cooperation offers.
 *
 * @param mixed $vars
 *   Available variables for the template.
 *
 * @return array
 *   Return the modified $vars array.
 */
function enrd_views_view_field__enrd_lag_database_cooperation_offers_dashboard__coop_offers_page_expired__view_node($vars) {
  if ($vars['row']->workbench_moderation_node_history_state == 'draft') {
    $revisions = node_revision_list(node_load($vars['row']->node_revision_nid));
    if (count($revisions) > 1) {
      return $vars['output'];
    }
  }
}

/**
 * Override single views field output for contextual cooperation offers.
 *
 * @param mixed $vars
 *   Available variables for the template.
 *
 * @return array
 *   Return the modified $vars array.
 */
function enrd_views_view_field__enrd_lag_database_cooperation_offers_dashboard__coop_offers_contextual__view_node($vars) {
  // Shows link to published revision only when there are multiple revisions.
  if ($vars['row']->workbench_moderation_node_history_state == 'draft') {
    $revisions = node_revision_list(node_load($vars['row']->node_revision_nid));
    if (count($revisions) > 1) {
      return $vars['output'];
    }
  }
  // If state is published prints always link to published.
  if ($vars['row']->workbench_moderation_node_history_state == 'published') {
    return $vars['output'];
  }
}

/**
 * Override single views field output for contextual cooperation offers.
 *
 * @param mixed $vars
 *   Available variables for the template.
 *
 * @return array
 *   Return the modified $vars array.
 */
function enrd_views_view_field__enrd_lag_database_cooperation_offers_dashboard__coop_offers_contextual__nothing($vars) {
  // Shows current revision link on contextual coop offers only in draft.
  if ($vars['row']->workbench_moderation_node_history_state != 'published') {
    return $vars['output'];
  }
}

/**
 * Implements template_quicktabs_alter().
 */
function enrd_quicktabs_alter($quicktabs) {
  if ($quicktabs->machine_name == 'enrd_notifications_settings') {
    // Hides block title rendering, but preserves it in admin UI.
    $quicktabs->title = '';
  }
}

/**
 * Implements template_views_more().
 */
function enrd_preprocess_views_more(&$variables) {

  global $user;

  if ($variables['view']->name == 'enrd_notifications_messages') {
    // Add suggestions for specific "More link" template.
    $variables['theme_hook_suggestions'][] = 'views_view' . '__' . $variables['view']->name . '__' . $variables['view']->current_display . '__' . 'views_more';
    // Remove the items_per_page exposed filter from url.
    $variables['more_url'] = drupal_substr($variables['more_url'], 0, strpos($variables['more_url'], "?"));
    // Add user uid to settings link.
    $uid = $user->uid;
    $settings_link_title = t('Settings');
    $settings_link_path = "user/$uid/notifications/settings";
    $settings_link = l($settings_link_title, $settings_link_path);
    $variables['count'] = $variables['view']->total_rows;
    $variables['settings_link'] = '<span class="glyphicon glyphicon-cog"></span>' . $settings_link;
  }
}

/**
 * Overrides theme_file_entity_download_link().
 *
 * Copy of the file_entity theme used for "Download link" formatter.
 * It adds specific info to the link for Matomo tracking.
 *
 * @param mixed $variables
 *   Available variables for the template.
 *
 * @return string
 *   The HTML markup.
 *
 * @throws Exception
 *
 * @see theme_file_entity_download_link()
 */
function enrd_file_entity_download_link($variables) {
  $file = $variables['file'];
  $icon_directory = $variables['icon_directory'];

  $uri = file_entity_download_uri($file);
  $icon = theme('file_icon', array('file' => $file, 'icon_directory' => $icon_directory));

  // Set options as per anchor format described at
  // http://microformats.org/wiki/file-format-examples
  $uri['options']['attributes']['type'] = $file->filemime . '; length=' . $file->filesize;

  // Add specific class and filename in uri for Matomo tracking.
  // @see https://developer.matomo.org/guides/tracking-javascript-guide
  $uri['options']['query']['filename'] = $file->filename;
  $uri['options']['attributes']['class'][] = 'piwik_download';

  // Provide the default link text.
  if (!isset($variables['text'])) {
    $variables['text'] = t('Download [file:name]');
  }

  // Perform unsanitized token replacement if $uri['options']['html'] is empty
  // since then l() will escape the link text.
  $variables['text'] = token_replace($variables['text'], array('file' => $file), array('clear' => TRUE, 'sanitize' => !empty($uri['options']['html'])));

  $output = '<span class="file">' . $icon . ' ' . l($variables['text'], $uri['path'], $uri['options']);
  $output .= ' ' . '<span class="file-size">(' . format_size($file->filesize) . ')</span>';
  $output .= '</span>';

  return $output;
}

/**
 * Implements hook_theme().
 */
function enrd_theme() {
  $path = drupal_get_path('theme', 'enrd') . '/templates/status_messages';

  return array(
    'modal_status_message' => array(
      'variables' => array(
        'modal_title' => NULL,
        'modal_dismiss_label' => NULL,
        'modal_dismiss_button' => NULL,
        'message' => NULL,
      ),
      'template' => 'modal-status-message',
      'path' => $path,
    ),
  );
}

/**
 * Returns HTML for status and/or error messages, grouped by type.
 *
 * An invisible heading identifies the messages for assistive technology.
 * Sighted users see a colored box. See http://www.w3.org/TR/WCAG-TECHS/H69.html
 * for info.
 *
 * @param mixed $variables
 *   An associative array containing:
 *   - display: (optional) Set to 'status' or 'error' to display only messages
 *     of that type.
 *
 * @return string
 *   The HTML string to render the messages.
 */
function enrd_status_messages($variables) {
  $display = $variables['display'];
  $output = '';
  $output_modal = '';

  $status_heading = array(
    'status' => t('Status message'),
    'error' => t('Error message'),
    'warning' => t('Warning message'),
  );
  foreach (drupal_get_messages($display) as $type => $messages) {
    if ($type == 'modal') {
      $modal_title = t('Info message');
      $modal_dismiss_label = t('Close');
      $modal_dismiss_button = t('OK');
      $modal_messages = '';

      if (count($messages) > 1) {
        $modal_messages .= " <ul>\n";
        foreach ($messages as $message) {
          $modal_messages .= '  <li>' . $message . "</li>\n";
        }
        $modal_messages .= " </ul>\n";
      }
      else {
        $modal_messages .= reset($messages);
      }

      $output_modal = theme(
        'modal_status_message',
        array(
          'modal_title' => $modal_title,
          'modal_dismiss_label' => $modal_dismiss_label,
          'modal_dismiss_button' => $modal_dismiss_button,
          'message' => $modal_messages,
        )
      );
      continue;
    }

    $output .= "<div class=\"messages $type\">\n";
    if (!empty($status_heading[$type])) {
      $output .= '<h2 class="element-invisible">' . $status_heading[$type] . "</h2>\n";
    }
    if (count($messages) > 1) {
      $output .= " <ul>\n";
      foreach ($messages as $message) {
        $output .= '  <li>' . $message . "</li>\n";
      }
      $output .= " </ul>\n";
    }
    else {
      $output .= reset($messages);
    }
    $output .= "</div>\n";
  }

  return $output . $output_modal;
}

/**
 * Implements hook_preprocess_user_profile().
 */
function enrd_preprocess_user_profile(&$variables) {
  // Check if user has at least one translation skill.
  $has_translation_skills = count($variables['user_profile']['tmgmt_translation_skills']['#items']);
  // Do not display translation skills on user profile if empty.
  if (!$has_translation_skills) {
    unset($variables['user_profile']['tmgmt_translation_skills']);
  }
}

/**
 * Custom theme output for SocialField widget.
 *
 * Overrides default theme to add a table header with the label.
 *
 * @see theme_socialfield_drag_components()
 */
function enrd_socialfield_drag_components($vars) {

  $element = $vars['element'];
  drupal_add_tabledrag('socialfield-table', 'order', 'sibling', 'item-row-weight');

  $services = variable_get('socialfield_services');
  $required = !empty($element['#required']) ? theme('form_required_marker', $vars) : '';
  $label = t('Social links');

  $header = array(
    array(
      'data' => '<label>' . t('!title !required', array(
        '!title' => $label,
        '!required' => $required,
      )) . "</label>",
      'colspan' => 3,
      'class' => array('field-label'),
    ),
  );

  $rows = array();
  $index = 0;

  for ($i = 0; $i < $element['#num_elements']; $i++) {
    while (!isset($element['element_' . $index])) {
      // There is no element with this index.
      // Moving on to the next possible element.
      $index++;
    }
    $current_element = $element['element_' . $index];

    $rows[] = array(
      'data' => array(
        '<div class="social-links">' . '<span class="service-' . $current_element['#service'] . '">' . '<i class="icon ' . $services[$current_element['#service']]['icon'] . '"></i>' . '</span>' . '</div>',
        drupal_render($current_element['url']),
        drupal_render($current_element['weight']),
        drupal_render($current_element['operation']),
      ),
      'class' => array('draggable'),
      'weight' => $current_element['weight']['#value'],
    );

    $index++;
  }

  // Sorting elements by their weight.
  uasort($rows, 'drupal_sort_weight');

  return theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array(
      'id' => 'socialfield-table',
      'class' => array('field-multiple-table'),
    ),
  )) . drupal_render($element['add_one_social']) . '<div class="description">' . drupal_render($element['description']) . '</div>';
}

/**
 * Implements theme_media_colorbox().
 *
 * Force Media Colorbox "Caption" display setting value,
 * both for image and video files.
 */
function enrd_media_colorbox($variables) {
  global $language;

  $entity_id = $variables['entity_id'];
  $file_id = $variables['file_id'];
  $field = $variables['field'];
  $field_name = isset($field['field_name']) ? $field['field_name'] : '';
  $settings = $variables['display_settings'];

  // Switch to figure out where caption should come from.
  if ($file_id != NULL) {
    $file = file_load($file_id);
    // Get File for the "ENRD Media colorbox" display.
    $file_enrd_media_colorbox_view = file_view($file, 'enrd_media_colorbox', $language->language);

    switch ($settings['colorbox_caption']) {
      case 'title':
        if ($file->type == 'image') {
          // Force theme_media_colorbox() to display Image "Caption".
          if (isset($file_enrd_media_colorbox_view['file']['#item']['title'])) {
            $caption = $file_enrd_media_colorbox_view['file']['#item']['title'];
          }
        }

        break;

      case 'mediafield':
        if ($file->type == 'image') {
          // Force theme_media_colorbox() to display Image "Title".
          if (isset($file_enrd_media_colorbox_view['field_caption'])) {
            $caption = $file_enrd_media_colorbox_view['field_caption'][0];
          }
        }
        elseif ($file->type == 'video') {
          // Force theme_media_colorbox() to display Video "Video Description".
          if (isset($file_enrd_media_colorbox_view['field_video_description'])) {
            $caption = $file_enrd_media_colorbox_view['field_video_description'][0];
          }
        }

        break;

      default:
        $caption = '';
    }
  }

  // Shorten caption for the ex. styles or when caption shortening is active.
  $trim_length = variable_get('colorbox_caption_trim_length', 75);
  if ((variable_get('colorbox_caption_trim', 0)) && (drupal_strlen($caption) > $trim_length)) {
    $caption = drupal_substr($caption, 0, $trim_length - 5) . '...';
  }

  // Build the gallery id.
  switch ($settings['colorbox_gallery']) {
    case 'post':
      $gallery_id = 'gallery-' . $entity_id;
      break;

    case 'page':
      $gallery_id = 'gallery-all';
      break;

    case 'field_post':
      $gallery_id = 'gallery-' . $entity_id . '-' . $field_name;
      break;

    case 'field_page':
      $gallery_id = 'gallery-' . $field_name;
      break;

    case 'custom':
      $gallery_id = $settings['colorbox_gallery_custom'];
      break;

    default:
      $gallery_id = '';
  }

  // Load file and render for select view mode.
  if ($file_id != NULL) {
    $file = file_load($file_id);
    $fview = file_view($file, $settings['file_view_mode'], $variables['langcode']);
    if ($file->type == 'image') {
      $variables['path'] = file_create_url($file->uri);
    }
    $text = drupal_render($fview);
  }
  elseif (isset($variables['item'])) {
    $text = drupal_render($variables['item']);
  }

  // Strip anchor tags as rendered output will be wrapped by another anchor tag
  // fix for issue #1477662.
  $stripped_text = media_colorbox_strip_only($text, 'a');
  $output = theme('link', array(
    'text' => $stripped_text,
    'path' => $variables['path'],
    'options' => array(
      'html' => TRUE,
      'attributes' => array(
        'title' => isset($caption) ? $caption : '',
        'class' => 'media-colorbox ' . $variables['item_class'],
        'style' => $variables['item_style'],
        'rel' => $gallery_id,
        'data-mediaColorboxFixedWidth' => $settings['fixed_width'],
        'data-mediaColorboxFixedHeight' => $settings['fixed_height'],
        'data-mediaColorboxAudioPlaylist' => $settings['audio_playlist'],
      ),
    ),
  ));

  return $output;
}
