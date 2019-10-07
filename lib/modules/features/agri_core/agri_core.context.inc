<?php

/**
 * @file
 * agri_core.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function agri_core_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'agri_core_solr_search';
  $context->description = 'Context for search pages';
  $context->tag = 'AGRI Core';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search/*' => 'search/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'current_search-standard' => array(
          'module' => 'current_search',
          'delta' => 'standard',
          'region' => 'sidebar_left',
          'weight' => '-20',
        ),
        'facetapi-GiIy4zr9Gu0ZSa0bumw1Y9qIIpIDf1wu' => array(
          'module' => 'facetapi',
          'delta' => 'GiIy4zr9Gu0ZSa0bumw1Y9qIIpIDf1wu',
          'region' => 'sidebar_left',
          'weight' => '-10',
        ),
        'apachesolr_search-sort' => array(
          'module' => 'apachesolr_search',
          'delta' => 'sort',
          'region' => 'sidebar_right',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Core');
  t('Context for search pages');
  $export['agri_core_solr_search'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'collab-areas-content';
  $context->description = 'Active only content inside collaborative areas.';
  $context->tag = 'AGRI Core';
  $context->conditions = array(
    'context_og_condition_group_type' => array(
      'values' => array(
        'collaborative_area' => 'collaborative_area',
      ),
      'options' => array(
        'node_form' => 0,
      ),
    ),
    'path' => array(
      'values' => array(
        '~node/*/group' => '~node/*/group',
        '~group/node/*/admin/*' => '~group/node/*/admin/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-og-single-menu-block' => array(
          'module' => 'menu_block',
          'delta' => 'og-single-menu-block',
          'region' => 'sidebar_left',
          'weight' => '-10',
        ),
        'menu_block-agri_pages_side_menu' => array(
          'module' => 'menu_block',
          'delta' => 'agri_pages_side_menu',
          'region' => 'sidebar_left',
          'weight' => '-9',
        ),
        'multisite_og_button-og-contextual-links' => array(
          'module' => 'multisite_og_button',
          'delta' => 'og-contextual-links',
          'region' => 'sidebar_left',
          'weight' => '-8',
        ),
        'views-61881c61e444a55353db59eaa3ab1eea' => array(
          'module' => 'views',
          'delta' => '61881c61e444a55353db59eaa3ab1eea',
          'region' => 'sidebar_left',
          'weight' => '-7',
        ),
        'views-ecf8b023e9fe7977331422f269bbed34' => array(
          'module' => 'views',
          'delta' => 'ecf8b023e9fe7977331422f269bbed34',
          'region' => 'sidebar_left',
          'weight' => '-6',
        ),
        'workbench-block' => array(
          'module' => 'workbench',
          'delta' => 'block',
          'region' => 'content',
          'weight' => -10,
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Core');
  t('Active only content inside collaborative areas.');
  $export['collab-areas-content'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'core-collaborative-area-forum';
  $context->description = 'Active only on collaborative area forum section.';
  $context->tag = 'AGRI Core';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'forum' => 'forum',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'node/*/forum' => 'node/*/forum',
        'node/*/forum/*' => 'node/*/forum/*',
        'node/*/forum/*/*' => 'node/*/forum/*/*',
        'node/*/forum/*/*/*' => 'node/*/forum/*/*/*',
        'node/*/forum/*/*/*/*' => 'node/*/forum/*/*/*/*',
        '~node/add/forum' => '~node/add/forum',
        '~node/*/forum/*/edit' => '~node/*/forum/*/edit',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-og-single-menu-block' => array(
          'module' => 'menu_block',
          'delta' => 'og-single-menu-block',
          'region' => 'sidebar_left',
          'weight' => '-10',
        ),
        'menu_block-agri_pages_side_menu' => array(
          'module' => 'menu_block',
          'delta' => 'agri_pages_side_menu',
          'region' => 'sidebar_left',
          'weight' => '-9',
        ),
        'multisite_og_button-og-contextual-links' => array(
          'module' => 'multisite_og_button',
          'delta' => 'og-contextual-links',
          'region' => 'sidebar_left',
          'weight' => '-7',
        ),
        'views-61881c61e444a55353db59eaa3ab1eea' => array(
          'module' => 'views',
          'delta' => '61881c61e444a55353db59eaa3ab1eea',
          'region' => 'sidebar_left',
          'weight' => '-6',
        ),
        'views-ecf8b023e9fe7977331422f269bbed34' => array(
          'module' => 'views',
          'delta' => 'ecf8b023e9fe7977331422f269bbed34',
          'region' => 'sidebar_left',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Core');
  t('Active only on collaborative area forum section.');
  $export['core-collaborative-area-forum'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'core-collaborative-area-full-node';
  $context->description = 'Active only on collaborative area full node.';
  $context->tag = 'AGRI Core';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'collaborative_area' => 'collaborative_area',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-og-single-menu-block' => array(
          'module' => 'menu_block',
          'delta' => 'og-single-menu-block',
          'region' => 'sidebar_left',
          'weight' => '-10',
        ),
        'menu_block-agri_pages_side_menu' => array(
          'module' => 'menu_block',
          'delta' => 'agri_pages_side_menu',
          'region' => 'sidebar_left',
          'weight' => '-9',
        ),
        'multisite_og_button-og-contextual-links' => array(
          'module' => 'multisite_og_button',
          'delta' => 'og-contextual-links',
          'region' => 'sidebar_left',
          'weight' => '-7',
        ),
        'views-61881c61e444a55353db59eaa3ab1eea' => array(
          'module' => 'views',
          'delta' => '61881c61e444a55353db59eaa3ab1eea',
          'region' => 'sidebar_left',
          'weight' => '-6',
        ),
        'views-ecf8b023e9fe7977331422f269bbed34' => array(
          'module' => 'views',
          'delta' => 'ecf8b023e9fe7977331422f269bbed34',
          'region' => 'sidebar_left',
          'weight' => '-5',
        ),
        'views-core_community_events-block' => array(
          'module' => 'views',
          'delta' => 'core_community_events-block',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
        'views-core_community_pages-block' => array(
          'module' => 'views',
          'delta' => 'core_community_pages-block',
          'region' => 'content_bottom',
          'weight' => '-9',
        ),
        'views-core_community_people-block' => array(
          'module' => 'views',
          'delta' => 'core_community_people-block',
          'region' => 'content_bottom',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Core');
  t('Active only on collaborative area full node.');
  $export['core-collaborative-area-full-node'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'core-community-full-node';
  $context->description = 'Active only on community full node.';
  $context->tag = 'AGRI Core';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'community' => 'community',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-agri_pages_side_menu' => array(
          'module' => 'menu_block',
          'delta' => 'agri_pages_side_menu',
          'region' => 'sidebar_left',
          'weight' => '-10',
        ),
        'multisite_og_button-og-contextual-links' => array(
          'module' => 'multisite_og_button',
          'delta' => 'og-contextual-links',
          'region' => 'sidebar_left',
          'weight' => '-9',
        ),
        'views-61881c61e444a55353db59eaa3ab1eea' => array(
          'module' => 'views',
          'delta' => '61881c61e444a55353db59eaa3ab1eea',
          'region' => 'sidebar_left',
          'weight' => '-8',
        ),
        'views-ecf8b023e9fe7977331422f269bbed34' => array(
          'module' => 'views',
          'delta' => 'ecf8b023e9fe7977331422f269bbed34',
          'region' => 'sidebar_left',
          'weight' => '-7',
        ),
        'views-core_community_events-block' => array(
          'module' => 'views',
          'delta' => 'core_community_events-block',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
        'views-core_community_pages-block' => array(
          'module' => 'views',
          'delta' => 'core_community_pages-block',
          'region' => 'content_bottom',
          'weight' => '-9',
        ),
        'views-core_community_people-block' => array(
          'module' => 'views',
          'delta' => 'core_community_people-block',
          'region' => 'content_bottom',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Core');
  t('Active only on community full node.');
  $export['core-community-full-node'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'core-dashboard';
  $context->description = 'Always active on user related pages, like edit/view profile, content editing, etc.';
  $context->tag = 'AGRI Core';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'user' => 'user',
        'user/*' => 'user/*',
        'node/add' => 'node/add',
        'node/add/*' => 'node/add/*',
        'node/*/edit' => 'node/*/edit',
        'admin/workbench' => 'admin/workbench',
        'admin/workbench/*' => 'admin/workbench/*',
        'admin/workbench/*/*' => 'admin/workbench/*/*',
        'node/*/moderation' => 'node/*/moderation',
        'node/*/moderation/*' => 'node/*/moderation/*',
        'admin/structure/menu' => 'admin/structure/menu',
        'admin/structure/menu*' => 'admin/structure/menu*',
        'admin/structure/taxonomy' => 'admin/structure/taxonomy',
        'admin/structure/taxonomy/*' => 'admin/structure/taxonomy/*',
        'taxonomy/term/*/edit*' => 'taxonomy/term/*/edit*',
        'manage/*' => 'manage/*',
        'my/*' => 'my/*',
        'node/*/webform' => 'node/*/webform',
        'node/*/webform/*' => 'node/*/webform/*',
        'node/*/webform/*/*' => 'node/*/webform/*/*',
        'node/*/submissions' => 'node/*/submissions',
        'node/*/submission/*' => 'node/*/submission/*',
        'node/*/submission/*/*' => 'node/*/submission/*/*',
        'find-people' => 'find-people',
        'find-people/*' => 'find-people/*',
      ),
    ),
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-agri-core-user-menu' => array(
          'module' => 'menu_block',
          'delta' => 'agri-core-user-menu',
          'region' => 'sidebar_left',
          'weight' => '-10',
        ),
        'menu_block-agri-core-action-menu' => array(
          'module' => 'menu_block',
          'delta' => 'agri-core-action-menu',
          'region' => 'sidebar_left',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Core');
  t('Always active on user related pages, like edit/view profile, content editing, etc.');
  $export['core-dashboard'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'core-dashboard-front';
  $context->description = 'Always active on user profile page.';
  $context->tag = 'AGRI Core';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
    'user_page' => array(
      'values' => array(
        'view' => 'view',
      ),
      'options' => array(
        'mode' => 'all',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-core_profile_user_details-block' => array(
          'module' => 'views',
          'delta' => 'core_profile_user_details-block',
          'region' => 'content_top_left',
          'weight' => '-10',
        ),
        'views-agri_og_user_groups-block_1' => array(
          'module' => 'views',
          'delta' => 'agri_og_user_groups-block_1',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-agri_og_user_groups-block_2' => array(
          'module' => 'views',
          'delta' => 'agri_og_user_groups-block_2',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-c3d6bac0168833578b24fc3a222469fe' => array(
          'module' => 'views',
          'delta' => 'c3d6bac0168833578b24fc3a222469fe',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-bff5610dca6e97cea5eac763a692275d' => array(
          'module' => 'views',
          'delta' => 'bff5610dca6e97cea5eac763a692275d',
          'region' => 'content',
          'weight' => '-7',
        ),
        'views-core_find_people-block_1' => array(
          'module' => 'views',
          'delta' => 'core_find_people-block_1',
          'region' => 'content',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Core');
  t('Always active on user profile page.');
  $export['core-dashboard-front'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'core-dashboard-sidebar';
  $context->description = 'Displays two menus on the left sidebar and one only on the dashboard entrance page.';
  $context->tag = 'AGRI Core';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        'core-dashboard' => 'core-dashboard',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-agri-core-user-menu' => array(
          'module' => 'menu_block',
          'delta' => 'agri-core-user-menu',
          'region' => 'sidebar_left',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Core');
  t('Displays two menus on the left sidebar and one only on the dashboard entrance page.');
  $export['core-dashboard-sidebar'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'core-dashboard-taxonomy';
  $context->description = 'Mark "Administer taxonomy" active';
  $context->tag = 'AGRI Core';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'taxonomy/term/*/*' => 'taxonomy/term/*/*',
        'admin/structure/taxonomy' => 'admin/structure/taxonomy',
        'admin/structure/taxonomy/*' => 'admin/structure/taxonomy/*',
        'admin/structure/taxonomy/*/*' => 'admin/structure/taxonomy/*/*',
        'admin/structure/taxonomy/*/*/*' => 'admin/structure/taxonomy/*/*/*',
      ),
    ),
  );
  $context->reactions = array(
    'breadcrumb' => 'admin/structure/taxonomy',
    'menu' => 'admin/structure/taxonomy',
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Core');
  t('Mark "Administer taxonomy" active');
  $export['core-dashboard-taxonomy'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'core-find-connect';
  $context->description = 'Active on all Find & Connect section';
  $context->tag = 'AGRI Core';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'find-connect' => 'find-connect',
        'find-connect/*' => 'find-connect/*',
        '~find-connect/funding-opportunities' => '~find-connect/funding-opportunities',
        '~find-connect/funding-opportunities/*' => '~find-connect/funding-opportunities/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-agri_pages_side_menu' => array(
          'module' => 'menu_block',
          'delta' => 'agri_pages_side_menu',
          'region' => 'sidebar_left',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Core');
  t('Active on all Find & Connect section');
  $export['core-find-connect'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'core-find-people-search';
  $context->description = 'Active on Find People page.';
  $context->tag = 'AGRI Core';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'core_find_people_search:page' => 'core_find_people_search:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'search_api_saved_searches-core_people_index' => array(
          'module' => 'search_api_saved_searches',
          'delta' => 'core_people_index',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Core');
  t('Active on Find People page.');
  $export['core-find-people-search'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'core-front';
  $context->description = 'Active only on front page, usful for displaying homepage blocks.';
  $context->tag = 'AGRI Core';
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
        'menu-menu-core-quicklinks' => array(
          'module' => 'menu',
          'delta' => 'menu-core-quicklinks',
          'region' => 'sidebar_right',
          'weight' => '-42',
        ),
        'views-core_news_events-block' => array(
          'module' => 'views',
          'delta' => 'core_news_events-block',
          'region' => 'sidebar_right',
          'weight' => '-40',
        ),
        'agri_core-logo_enrd' => array(
          'module' => 'agri_core',
          'delta' => 'logo_enrd',
          'region' => 'sidebar_right',
          'weight' => '-10',
        ),
        'menu-menu-core-search-find' => array(
          'module' => 'menu',
          'delta' => 'menu-core-search-find',
          'region' => 'content_top_left',
          'weight' => '-10',
        ),
        'agri_digitization_toolbox-agri_digitization_entry_point' => array(
          'module' => 'agri_digitization_toolbox',
          'delta' => 'agri_digitization_entry_point',
          'region' => 'content_top_right',
          'weight' => '-10',
        ),
        'views-core_spotlight-block' => array(
          'module' => 'views',
          'delta' => 'core_spotlight-block',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'views-core_tweets-block' => array(
          'module' => 'views',
          'delta' => 'core_tweets-block',
          'region' => 'main_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Core');
  t('Active only on front page, usful for displaying homepage blocks.');
  $export['core-front'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'core-news-events';
  $context->description = 'Active on News & Events section';
  $context->tag = 'AGRI Core';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'news-events' => 'news-events',
        'news-events/*' => 'news-events/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-agri_pages_side_menu' => array(
          'module' => 'menu_block',
          'delta' => 'agri_pages_side_menu',
          'region' => 'sidebar_left',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Core');
  t('Active on News & Events section');
  $export['core-news-events'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'core-news-events-front';
  $context->description = 'Active only on News & Events section front page';
  $context->tag = 'AGRI Core';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'news-events' => 'news-events',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-agri_pages_side_menu' => array(
          'module' => 'menu_block',
          'delta' => 'agri_pages_side_menu',
          'region' => 'sidebar_left',
          'weight' => '-10',
        ),
        'views-news_blocks-block' => array(
          'module' => 'views',
          'delta' => 'news_blocks-block',
          'region' => 'content_top_left',
          'weight' => '-10',
        ),
        'views-press_blocks-block' => array(
          'module' => 'views',
          'delta' => 'press_blocks-block',
          'region' => 'content_top_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Core');
  t('Active only on News & Events section front page');
  $export['core-news-events-front'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'core-projects-actions-subpages';
  $context->description = 'Active on Projects & Actions section sub-pages.';
  $context->tag = 'AGRI Core';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'find-connect' => 'find-connect',
        'find-connect/*' => 'find-connect/*',
        'find-connect/*/*' => 'find-connect/*/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-agri_pages_side_menu' => array(
          'module' => 'menu_block',
          'delta' => 'agri_pages_side_menu',
          'region' => 'sidebar_left',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Core');
  t('Active on Projects & Actions section sub-pages.');
  $export['core-projects-actions-subpages'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'core-sitewide';
  $context->description = 'Always active, useful to display blocks availbale site-wide, like footer information, and so on.';
  $context->tag = 'AGRI Core';
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
        'agri_core-agri_user_login' => array(
          'module' => 'agri_core',
          'delta' => 'agri_user_login',
          'region' => 'header_right',
          'weight' => -9,
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'header_right',
          'weight' => '10',
        ),
        'system-main-menu' => array(
          'module' => 'system',
          'delta' => 'main-menu',
          'region' => 'featured',
          'weight' => '-10',
        ),
        'easy_breadcrumb-easy_breadcrumb' => array(
          'module' => 'easy_breadcrumb',
          'delta' => 'easy_breadcrumb',
          'region' => 'featured',
          'weight' => '-9',
        ),
        'print_ui-print-links' => array(
          'module' => 'print_ui',
          'delta' => 'print-links',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
        'menu-menu-social-footer' => array(
          'module' => 'menu',
          'delta' => 'menu-social-footer',
          'region' => 'footer',
          'weight' => '-46',
        ),
        'agri_core-footer_contacts' => array(
          'module' => 'agri_core',
          'delta' => 'footer_contacts',
          'region' => 'footer',
          'weight' => '-45',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Core');
  t('Always active, useful to display blocks availbale site-wide, like footer information, and so on.');
  $export['core-sitewide'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'core-subscription-block';
  $context->description = 'Display subscription block below content.';
  $context->tag = 'AGRI Core';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'funding_opportunities' => 'funding_opportunities',
        'innovative_action' => 'innovative_action',
        'needs_for_research_from_practice' => 'needs_for_research_from_practice',
        'operational_group' => 'operational_group',
        'project_ideas' => 'project_ideas',
        'publication' => 'publication',
        'research_project' => 'research_project',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'subscriptions_ui-0' => array(
          'module' => 'subscriptions_ui',
          'delta' => '0',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Core');
  t('Display subscription block below content.');
  $export['core-subscription-block'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'core-user-login';
  $context->description = 'Active on user login page.';
  $context->tag = 'AGRI Core';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'user' => 'user',
      ),
    ),
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'agri_core-agri_core_eu_login' => array(
          'module' => 'agri_core',
          'delta' => 'agri_core_eu_login',
          'region' => 'content',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Core');
  t('Active on user login page.');
  $export['core-user-login'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'core-workbench-information';
  $context->description = 'Add block workbench information by user role.';
  $context->tag = 'AGRI Core';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
        'editor' => 'editor',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'workbench-block' => array(
          'module' => 'workbench',
          'delta' => 'block',
          'region' => 'content',
          'weight' => -10,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('AGRI Core');
  t('Add block workbench information by user role.');
  $export['core-workbench-information'] = $context;

  return $export;
}
