<?php

/**
 * @file
 * enrd_mastermind.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function enrd_mastermind_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'basic_sidebar';
  $context->description = 'sidebar for basic page';
  $context->tag = 'ENRD sidebar';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'page' => 'page',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'ds_extras-sidebarblock' => array(
          'module' => 'ds_extras',
          'delta' => 'sidebarblock',
          'region' => 'sidebar_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('ENRD sidebar');
  t('sidebar for basic page');
  $export['basic_sidebar'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_communities_all';
  $context->description = 'ENRD context for all page into community';
  $context->tag = 'ENRD communities';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'community' => 'community',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'community/*' => 'community/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-communities-menu' => array(
          'delta' => 'menu-communities-menu',
          'module' => 'menu',
          'region' => 'sidebar_right',
          'weight' => -20,
        ),
        'multisite_og_button-og-contextual-links' => array(
          'delta' => 'og-contextual-links',
          'module' => 'multisite_og_button',
          'region' => 'sidebar_right',
          'weight' => -10,
        ),
        'views-2d4875e6d03384eb9958118db936eec9' => array(
          'module' => 'views',
          'delta' => '2d4875e6d03384eb9958118db936eec9',
          'region' => 'sidebar_right',
          'weight' => '-7',
        ),
        'views-enrd_community_content-block' => array(
          'module' => 'views',
          'delta' => 'enrd_community_content-block',
          'region' => 'sidebar_right',
          'weight' => '-9',
        ),
        'views-og_pending_membership-block' => array(
          'delta' => 'og_pending_membership-block',
          'module' => 'views',
          'region' => 'sidebar_right',
          'weight' => -6,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('ENRD communities');
  t('ENRD context for all page into community');
  $export['enrd_communities_all'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_communities_directory';
  $context->description = 'ENRD context for community directory list';
  $context->tag = 'ENRD communities';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'myenrd' => 'myenrd',
        'myenrd/*' => 'myenrd/*',
        '~myenrd/my' => '~myenrd/my',
        '~myenrd/my/*' => '~myenrd/my/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-2ca3215fded5e0f38601dc3a36e7d035' => array(
          'module' => 'views',
          'delta' => '2ca3215fded5e0f38601dc3a36e7d035',
          'region' => 'content',
          'weight' => '30',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('ENRD communities');
  t('ENRD context for community directory list');
  $export['enrd_communities_directory'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_communities_directory_my';
  $context->description = 'ENRD context for community directory my list';
  $context->tag = 'ENRD communities';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'myenrd/my' => 'myenrd/my',
        'myenrd/my/*' => 'myenrd/my/*',
        '~myenrd/*/' => '~myenrd/*/',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-cae0291113d51380b1849125d8e9fb7a' => array(
          'module' => 'views',
          'delta' => 'cae0291113d51380b1849125d8e9fb7a',
          'region' => 'content',
          'weight' => '30',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('ENRD communities');
  t('ENRD context for community directory my list');
  $export['enrd_communities_directory_my'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_communities_homepage';
  $context->description = 'ENRD context for community home page';
  $context->tag = 'ENRD communities';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'community' => 'community',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'community/*/' => 'community/*/',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-e24f636c8814348437ec102c6ad8fabe' => array(
          'module' => 'views',
          'delta' => 'e24f636c8814348437ec102c6ad8fabe',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('ENRD communities');
  t('ENRD context for community home page');
  $export['enrd_communities_homepage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_homepage';
  $context->description = 'ENRD context for the homepage';
  $context->tag = 'ENRD global';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'enrd_mastermind-agri_block' => array(
          'module' => 'enrd_mastermind',
          'delta' => 'agri_block',
          'region' => 'sidebar_left',
          'weight' => '-5',
        ),
        'views-enrd_focus_on-focus_on_carousel' => array(
          'module' => 'views',
          'delta' => 'enrd_focus_on-focus_on_carousel',
          'region' => 'focus',
          'weight' => '-10',
        ),
        'bean-eucountrymap' => array(
          'module' => 'bean',
          'delta' => 'eucountrymap',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'bean-twitterfeeds' => array(
          'module' => 'bean',
          'delta' => 'twitterfeeds',
          'region' => 'content_right',
          'weight' => '0',
        ),
        'views-enrd_news-newsroom_carousel' => array(
          'module' => 'views',
          'delta' => 'enrd_news-newsroom_carousel',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('ENRD context for the homepage');
  t('ENRD global');
  $export['enrd_homepage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_search';
  $context->description = 'Custom context for the global search page.';
  $context->tag = 'ENRD search';
  $context->conditions = array(
    'apachesolr_page' => array(
      'values' => array(
        'core_search' => 'core_search',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'current_search-standard' => array(
          'module' => 'current_search',
          'delta' => 'standard',
          'region' => 'sidebar_right',
          'weight' => '-10',
        ),
        'facetapi-GiIy4zr9Gu0ZSa0bumw1Y9qIIpIDf1wu' => array(
          'module' => 'facetapi',
          'delta' => 'GiIy4zr9Gu0ZSa0bumw1Y9qIIpIDf1wu',
          'region' => 'sidebar_right',
          'weight' => '-9',
        ),
        'apachesolr_search-sort' => array(
          'module' => 'apachesolr_search',
          'delta' => 'sort',
          'region' => 'sidebar_right',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Custom context for the global search page.');
  t('ENRD search');
  $export['enrd_search'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_search_exception';
  $context->description = 'Custom context exception for the global search page.';
  $context->tag = 'ENRD search';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        'enrd_sitewide' => 'enrd_sitewide',
        '~enrd_search' => '~enrd_search',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'tools',
          'weight' => '3',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Custom context exception for the global search page.');
  t('ENRD search');
  $export['enrd_search_exception'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_sidebar_left';
  $context->description = 'ENRD sidebar left context';
  $context->tag = 'ENRD global';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~node/add/*' => '~node/add/*',
        '~node/*/edit' => '~node/*/edit',
      ),
    ),
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main-menu' => array(
          'module' => 'system',
          'delta' => 'main-menu',
          'region' => 'sidebar_left',
          'weight' => '-10',
        ),
        'menu-menu-enrd-tools' => array(
          'module' => 'menu',
          'delta' => 'menu-enrd-tools',
          'region' => 'sidebar_left',
          'weight' => '-9',
        ),
        'menu-menu-enrd-portals' => array(
          'module' => 'menu',
          'delta' => 'menu-enrd-portals',
          'region' => 'sidebar_left',
          'weight' => '-8',
        ),
        'menu-menu-enrd-join-us' => array(
          'module' => 'menu',
          'delta' => 'menu-enrd-join-us',
          'region' => 'sidebar_left',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('ENRD global');
  t('ENRD sidebar left context');
  $export['enrd_sidebar_left'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_sitewide';
  $context->description = 'ENRD sitewide context';
  $context->tag = 'ENRD global';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'language_selector_site-language_selector_site' => array(
          'module' => 'language_selector_site',
          'delta' => 'language_selector_site',
          'region' => 'header_top',
          'weight' => '-10',
        ),
        'enrd_mastermind-header_enrd_ipg' => array(
          'module' => 'enrd_mastermind',
          'delta' => 'header_enrd_ipg',
          'region' => 'header_top',
          'weight' => '0',
        ),
        'easy_breadcrumb-easy_breadcrumb' => array(
          'module' => 'easy_breadcrumb',
          'delta' => 'easy_breadcrumb',
          'region' => 'featured',
          'weight' => '-10',
        ),
        'system-user-menu' => array(
          'module' => 'system',
          'delta' => 'user-menu',
          'region' => 'tools',
          'weight' => '2',
        ),
        'print_ui-print-links' => array(
          'module' => 'print_ui',
          'delta' => 'print-links',
          'region' => 'tools_buttons',
          'weight' => '-89',
        ),
        'enrd_mastermind-enrd_rss_button' => array(
          'module' => 'enrd_mastermind',
          'delta' => 'enrd_rss_button',
          'region' => 'tools_buttons',
          'weight' => '-88',
        ),
        'bean-sharebuttons' => array(
          'module' => 'bean',
          'delta' => 'sharebuttons',
          'region' => 'tools_buttons',
          'weight' => '-87',
        ),
        'views-registration-block' => array(
          'module' => 'views',
          'delta' => 'registration-block',
          'region' => 'sidebar_right',
          'weight' => '-7',
        ),
        'views-registration_management-block' => array(
          'module' => 'views',
          'delta' => 'registration_management-block',
          'region' => 'sidebar_right',
          'weight' => '-6',
        ),
        'language_selector_page-language_selector_page' => array(
          'module' => 'language_selector_page',
          'delta' => 'language_selector_page',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'bean-footertopdisclaimer' => array(
          'module' => 'bean',
          'delta' => 'footertopdisclaimer',
          'region' => 'footer_top',
          'weight' => '-10',
        ),
        'enrd_mastermind-footer_enrd' => array(
          'module' => 'enrd_mastermind',
          'delta' => 'footer_enrd',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('ENRD global');
  t('ENRD sitewide context');
  $export['enrd_sitewide'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'enrd_workbench_moderation_filters';
  $context->description = 'Add the filters block above Workbench Moderation moderate-all view.';
  $context->tag = 'ENRD views';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'workbench_moderation:moderate_all_page' => 'workbench_moderation:moderate_all_page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-59508d0f437626106c5ca550ee37ee6e' => array(
          'module' => 'views',
          'delta' => '59508d0f437626106c5ca550ee37ee6e',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Add the filters block above Workbench Moderation moderate-all view.');
  t('ENRD views');
  $export['enrd_workbench_moderation_filters'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'organization';
  $context->description = 'The context for the organization block';
  $context->tag = 'ENRD views';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'networks-and-networking/eu-organisations' => 'networks-and-networking/eu-organisations',
        '~networks-and-networking/eu-organisations/*' => '~networks-and-networking/eu-organisations/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-eu_organizations-block' => array(
          'module' => 'views',
          'delta' => 'eu_organizations-block',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('ENRD views');
  t('The context for the organization block');
  $export['organization'] = $context;

  return $export;
}
