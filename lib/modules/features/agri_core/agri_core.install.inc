<?php

/**
 * @file
 * agri_core.install.inc
 */

/**
 * Defining terms as simple strings.
 *
 * @return array
 *   term names
 */
function _agri_core_get_default_core_themes_terms() {
  return array(
    "Increased agricultural productivity, output, and resource efficiency",
    "Innovation in support of the bio-based economy",
    "Biodiversity, Ecosystem services, and soil functionality",
    "Innovative products and services in the value chain",
    "Food quality, food safety and healthy lifestyles",
  );
}

/**
 * Defining terms as simple strings.
 *
 * @return array
 *   term names
 */
function _agri_core_get_default_core_geographical_area_terms() {
  return array(
    "Other" => "Other",
    "Austria" => "Austria",
    "Belgium" => array(
      "Vlaanderen",
      "Wallonie",
    ),
    "Bulgaria" => "Bulgaria",
    "Croazia" => "Croazia",
    "Cyprus" => "Cyprus",
    "Czech Republic" => "Czech Republic",
    "Denmark" => "Denmark",
    "Estonia" => "Estonia",
    "Finland" => "Finland",
    "France" => array(
      "Corse",
      "Guadeloupe",
      "Guyane",
      "Martinique",
      "Réunion",
      "Mayotte",
      "Nord Pas-de-Calais",
      "Picardie",
      "Champagne-Ardennes",
      "Lorraine",
      "Alsace",
      "Ile-de-France",
      "Haute-Normandie",
      "Basse-Normandie",
      "Pays de Loire",
      "Bretagne",
      "Centre",
      "Bourgogne",
      "Franche-Comté",
      "Rhône-Alpes",
      "Auverge",
      "Limousin",
      "Poitou-Charente",
      "Aquitaine",
      "Midi-Pyrénées",
      "Languedoc-Roussillon",
      "Provence-Alpes-Côte d'Azur",
    ),
    "Germany" => array(
      "Baden-Württemberg",
      "Bavaria",
      "Brandenburg-Berlin",
      "Hambourg",
      "Hessen",
      "Mecklenburg-Vorpommern",
      "Niedersachsen und Bremen",
      "Nordrhrein-Westfalen",
      "Rahmenregelung",
      "Rheinland-Pfalz",
      "Saarland",
      "Sachsen-Anhalt",
      "Sachsen",
      "Schleswig-Holstein",
      "Thüringen",
    ),
    "Greece" => "Greece",
    "Hungary" => "Hungary",
    "Ireland" => "Ireland",
    "Italy" => array(
      "Abruzzo",
      "Basilicata",
      "Bolzano",
      "Calabria",
      "Campania",
      "Emilia Romagna",
      "Friuli Venezia Giulia",
      "Lazio",
      "Liguria",
      "Lombardia",
      "Marche",
      "Molise",
      "Piemonte",
      "Puglia",
      "Sardegna",
      "Sicilia",
      "Toscana",
      "Trento",
      "Umbria",
      "Valle d'Aosta",
      "Veneto",
    ),
    "Latvia" => "Latvia",
    "Lithuania" => "Lithuania",
    "Luxembourg" => "Luxembourg",
    "Malta" => "Malta",
    "Netherlands" => "Netherlands",
    "Poland" => "Poland",
    "Portugal" => array(
      "Azores",
      "Continente",
      "Madeira",
      "Portugal",
    ),
    "Romania" => "Romania",
    "Slovakia" => "Slovakia",
    "Slovenia" => "Slovenia",
    "Spain" => array(
      "Andalusia",
      "Aragon",
      "Asturias",
      "Baleares",
      "Canarias",
      "Cantabria",
      "Castilla La-Mancha",
      "Castilla Y Leon",
      "Cataluña",
      "Extremadura",
      "España",
      "Galicia",
      "Murcia",
      "Madrid",
      "Navarra",
      "Pais Vasco",
      "Rioja",
      "Valencia",
    ),
    "Sweden" => "Sweden",
    "United Kingdom" => array(
      "England",
      "Northern Ireland",
      "Scotland",
      "Wales",
    ),
  );
}

/**
 * Defining terms as simple strings.
 *
 * @return array
 *   term names
 */
function _agri_core_get_default_core_user_type_terms() {
  return array(
    "Farmer",
    "Land owner",
    "Forester",
    "Adviser",
    "Innovation support agent",
    "Researcher",
    "Industry",
    "Retailer",
    "Wholesaler",
    "Representative of an NGO",
    "Press/media collaborator",
    "Civil servant",
    "Student",
    "SME",
    "Other",
  );
}

/**
 * Defining terms as simple strings.
 *
 * @return array
 *   term names
 */
function _agri_core_get_default_field_of_activity_terms() {
  return array(
    "Agricultural producers associations & cooperatives",
    "Land owners' organizations",
    "Foresters associations & cooperatives",
    "Agriculture",
    "Forestry",
    "Innovation Support Service",
    "Agricultural chambers",
    "Certification & inspection organizations",
    "Industry",
    "Trade organizations (banks, retail, others)",
    "Trade unions",
    "RD Programming/Managing Authorities",
    "Local Action Groups (LEADER LAGs)",
    "National or Regional Rural Network Support Units",
    "National or Regional EIP-AGRI Networks",
    "Thematic Networks funded by Horizon 2020",
    "Other networks and platforms",
    "Research organizations",
    "Educational organizations",
    "Environment organizations",
    "Research & scientific \"publishers\"",
    "Media/press (especially agriculture-related specialist media and press)",
    "Funding entity (state / private; rural development/research)",
    "Other state organizations (engaged in agriculture, forestry, rural development, food safety/quality, environment etc)",
    "Other type of organizations (e.g., consumer organization, municipality)",
  );
}

/**
 * Defines Stakeholders taxonomy terms.
 *
 * @return array
 *   Term names.
 */
function _agri_core_get_default_core_stakeholder_terms() {
  return array(
    "Operational Groups",
    "Farmers",
    "Farm Advisers",
    "Managing Authorities",
    "National Support Groups",
    "Researchers",
    "Agribusiness",
    "Thematic Networks",
    "Multi-Actor Projects",
  );
}

/**
 * Agri_core_disable_views().
 *
 * @param array $views
 *
 *   A simple array of view's names strings.
 */
function _agri_core_disable_views(array $views) {
  $views_status = variable_get('views_defaults', array());
  foreach ($views as $view_name) {
    $views_status[$view_name] = TRUE;
  }

  // Reset the variable with the new list and empty cache.
  variable_set('views_defaults', $views_status);
  if (function_exists('views_invalidate_cache')) {
    views_invalidate_cache();
  }
}

/**
 * A function used to populate vocabularies with terms.
 */
function _agri_core_import_default_menu_items() {
  features_revert(array('agri_core' => array('menu_custom')));

  $user_quicklinks = array(
    array(
      'title' => 'Publish an innovative action',
      'path'  => 'node/add/innovative-action',
    ),
    array(
      'title' => 'Share your needs for research from practice',
      'path'  => 'node/add/needs-for-research-from-practice',
    ),
    array(
      'title' => 'Share your project ideas',
      'path'  => 'node/add/project-ideas',
    ),
  );

  $i = 0;
  foreach ($user_quicklinks as $user_quicklink) {
    $item = array(
      'menu_name' => 'menu-core-user-quicklinks',
      'module' => 'menu',
      'customized' => 1,
      'link_path' => $user_quicklink['path'],
      'link_title' => $user_quicklink['title'],
      'weight' => $i,
    );
    $i++;
    menu_link_save($item);
  }

  $quicklinks = array(
    array(
      'title' => 'Register or login to "EIP-AGRI"',
      'path'  => 'user',
      'class' => 'menu-link-user-register',
    ),
    array(
      'title' => 'Ask a question or provide feedback',
      'path'  => '<front>',
      'class' => 'menu-link-ask-question',
    ),
  );

  $i = 0;
  foreach ($quicklinks as $quicklink) {
    $item = array(
      'menu_name' => 'menu-core-quicklinks',
      'module' => 'menu',
      'customized' => 1,
      'link_path' => $quicklink['path'],
      'link_title' => $quicklink['title'],
      'weight' => $i,
      'options' => array(
        'attributes' => array(
          'class' => array($quicklink['class']),
        ),
      ),
    );
    $i++;
    menu_link_save($item);
  }

  $search_find = array(
    array(
      'title'       => 'Share with us',
      'path'        => 'find-connect/share-with-us',
      'class'       => 'menu-link-share-with-us',
      'description' => 'information about you, your projects and projects ideas, research needs, etc.',
    ),
    array(
      'title'       => 'Search and find',
      'path'        => 'find-connect',
      'class'       => 'menu-link-search-and-find',
      'description' => 'funding opportunities, partners, interesting projects... on EIP-AGRI meeting point',
    ),
    array(
      'title'       => 'Focus on',
      'path'        => '<front>',
      'class'       => 'menu-link-focus-on',
      'description' => 'practical innovative solutions to problems and opportunities provided in the EIP-AGRI Focus Group chapter',
    ),
    array(
      'title'       => 'Deepen your knowledge',
      'path'        => 'publications',
      'class'       => 'menu-link-deepen-your-knowledge',
      'description' => 'by different EIP-AGRI related publications in our library',
    ),
    array(
      'title'       => 'Stay up to date',
      'path'        => 'news-events',
      'class'       => 'menu-link-stay-up-to-date',
      'description' => 'on innovation related agricultural topics and read about the latest EIP-AGRI news and events',
    ),
    array(
      'title'       => 'My Account',
      'path'        => 'user',
      'class'       => 'menu-link-my-eip-agri',
      'description' => 'connects you to your own EIP-AGRI dashboard and enables you to follow the information and people you are interested in',
    ),
  );

  $i = 0;
  foreach ($search_find as $search_link) {
    $item = array(
      'menu_name' => 'menu-core-search-find',
      'module' => 'menu',
      'customized' => 1,
      'link_path' => $search_link['path'],
      'link_title' => $search_link['title'],
      'weight' => $i,
      'options' => array(
        'attributes' => array(
          'title' => $search_link['description'],
          'class' => array($search_link['class']),
        ),
      ),
    );
    $i++;
    menu_link_save($item);
  }

  menu_cache_clear_all();
}

/**
 * Adding a direct link to the menus administration page.
 */
function _agri_core_add_user_menu_link() {
  $menu = menu_load('menu-core-action-menu');

  if ($menu) {
    $item = array(
      'menu_name' => 'menu-core-action-menu',
      'module' => 'menu',
      'customized' => 1,
      'link_path' => 'admin/structure/menu',
      'language'  => 'en',
      'link_title' => t('Menu management'),
      'weight' => 9,
      'options' => array(),
    );

    menu_link_save($item);

    $item = array(
      'menu_name' => 'menu-core-action-menu',
      'module' => 'menu',
      'customized' => 1,
      'link_path' => 'admin/structure/taxonomy',
      'language'  => 'en',
      'link_title' => t('Categories management'),
      'weight' => 8,
      'options' => array(),
    );

    menu_link_save($item);
  }

  menu_cache_clear_all();
}

/**
 * Return a file object after saving a default image and storing the fid.
 *
 * @param array $image
 *   An associative array that represents the data of image to create:
 *    - scheme: public or private;
 *    - dest_directory: the folder name of the folder that will store image;
 *    - source_path: the path to the image;
 *    - file_name: the name of the image:
 *    - variable: the variable that will store the image fid.
 *
 * @return object
 *   A file object of the saved default image file.
 */
function _agri_core_create_default_image(array $image) {

  // Create the default user image field's default file reference.
  $filename = 'default-avatar.png';
  $public_dir = "public://";
  $default_folder = 'default_images';
  $origfile = drupal_get_path('module', 'agri_core') . '/images/' . $filename;
  $uri = $public_dir . $default_folder . "/" . $filename;

  $file = (object) array(
    'uid' => 1,
    'filename' => $filename,
    'uri' => $origfile,
    'filemime' => 'image/png',
    'filesize' => filesize($origfile),
    'status' => FILE_STATUS_PERMANENT,
  );

  $imgdirpath = $public_dir . $default_folder;
  file_prepare_directory($imgdirpath, FILE_CREATE_DIRECTORY);

  $file = file_copy($file, $uri, FILE_EXISTS_REPLACE);
  variable_set('profile_default_image_fid', $file->fid);

  return $file;
}

/**
 * A function used to create the items for a menù.
 */
function _agri_core_footer_menu_links() {
  features_revert(array('agri_core' => array('menu_custom')));
  $social = array('RSS', 'Twitter' , 'Facebook');
  $i = 0;
  foreach ($social as $social_link) {
    $item = array(
      'menu_name' => 'menu-social-footer',
      'module' => 'menu',
      'customized' => 1,
      'link_path' => '<front>',
      'language'  => 'en',
      'link_title' => $social_link,
      'weight' => $i,
      'options' => array(
        'attributes' => array(
          'class' => array(
            drupal_strtolower($social_link) . '-icon',
          ),
        ),
      ),
    );
    $i++;
    menu_link_save($item);
  }
  menu_cache_clear_all();
}

/**
 * Sets what bundles on the specified entity type should be indexed.
 */
function _agri_core_apache_solr_set_bundle_to_index() {
  module_load_include('inc', 'apachesolr', 'apachesolr.index');
  $env_id = apachesolr_default_environment();
  $conf = array(
    'node' => array(
      'collaborative_area',
      'digitisation_toolbox',
      'event',
      'funding_opportunities',
      'gallery',
      'needs_for_research_from_practice',
      'news',
      'online_resource',
      'page',
      'press_release',
      'project',
      'project_ideas',
      'publication',
    ),
    'file' => array(
      'document',
    ),
  );

  foreach ($conf as $entity_type => $bundle) {
    apachesolr_index_set_bundles($env_id, $entity_type, $bundle);
  }
}

/**
 * Set administrative permissions on some vocabularies.
 */
function _agri_core_set_vocabulary_permissions() {
  $vocs[] = taxonomy_vocabulary_machine_name_load('tags');
  $vocs[] = taxonomy_vocabulary_machine_name_load('event_type');
  $vocs[] = taxonomy_vocabulary_machine_name_load('core_geographical_area');
  $vocs[] = taxonomy_vocabulary_machine_name_load('core_themes');
  $vocs[] = taxonomy_vocabulary_machine_name_load('newsletter');
  $vocs[] = taxonomy_vocabulary_machine_name_load('field_of_activity');
  $vocs[] = taxonomy_vocabulary_machine_name_load('core_user_type');
  $vocs[] = taxonomy_vocabulary_machine_name_load('publication_type');
  $vocs[] = taxonomy_vocabulary_machine_name_load('forums');
  $vocs[] = taxonomy_vocabulary_machine_name_load('agricultural_sectors');
  $vocs[] = taxonomy_vocabulary_machine_name_load('core_stakeholders');
  $roles[] = user_role_load_by_name('editor');
  $roles[] = user_role_load_by_name('administrator');
  foreach ($vocs as $voc) {
    foreach ($roles as $role) {
      user_role_grant_permissions($role->rid, array(
        'delete terms in ' . $voc->vid,
        'edit terms in ' . $voc->vid,
      ));
    }
  }
}

/**
 * Helper function to prepare fields for solr mlt blocks.
 *
 * @return array
 *   An array of settings to use with mlt block creation function.
 */
function _agri_core_prepare_apachesolr_mlt_fields() {

  $mlt_settings = [];

  // Vocabulary to use for related content.
  $mlt_settings['vocabularies'] = [
    'Tags',
  ];

  // Content types that will have a related content block.
  $mlt_settings['content_types'] = [
    'news',
    'press_release',
    'event',
    'page',
  ];

  // Content type to search in for content when a related block is displayed.
  $mlt_settings['related_results'] = [
    'news',
    'press_release',
    'event',
    'publication',
    'page',
  ];

  // Content type to search in for content when a related block is displayed.
  $mlt_settings['digitisation_related_results'] = [
    'page',
  ];

  return $mlt_settings;
}

/**
 * Helper function to create Apachesolr mlt blocks on install or update.
 */
function _agri_core_create_apachesolr_mlt_blocks() {

  // Get fields settings array.
  $mlt_settings = _agri_core_prepare_apachesolr_mlt_fields();

  // Prepare vocabulary fields array.
  foreach (taxonomy_get_vocabularies() as $vocab) {
    foreach ($mlt_settings['vocabularies'] as $vocabulary_name) {
      if ($vocab->name == $vocabulary_name) {
        $term_fields[] = 'tm_vid_' . $vocab->vid . '_names';
      }
    }
  }

  // Loop through types to create spcific solr related content blocks.
  foreach ($mlt_settings['content_types'] as $type) {
    // All content types.
    _agri_core_create_apachesolr_search_related_content_block(
      'Related content',
      $mlt_settings['related_results'],
      drupal_map_assoc($term_fields),
      "agri-mlt-$type",
      5
    );
  }

  // Digitisation related pages block.
  _agri_core_create_apachesolr_search_related_content_block(
    'Other related content',
    $mlt_settings['digitisation_related_results'],
    drupal_map_assoc($term_fields),
    "agri-mlt-digitisation_toolbox",
    5
  );
}
