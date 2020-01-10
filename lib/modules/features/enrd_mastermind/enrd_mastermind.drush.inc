<?php

/**
 * @file
 * Drush integration for enrd_mastermind.
 */

/**
 * Implements hook_drush_command().
 */
function enrd_mastermind_drush_command() {
  $items = array();
  $items['fix-aliases'] = array(
    'description' => 'Fixes duplicated nodes and alias for the same alias and languages.',
  );
  $items['fix-menu-items'] = array(
    'description' => 'Fix many menu items issues from Mastermind feature.',
    'arguments' => array(
      'action' => 'Select kind of fix.',
    ),
  );
  $items['clean-comments'] = array(
    'description' => 'Clean comments tables.',
  );
  $items['purge-fields'] = array(
    'description' => 'Purge empty fields data.',
  );
  $items['fix-main-menu-items'] = array(
    'description' => 'Fixes wrong main menu links.',
  );
  $items['delete-old-content'] = array(
    'description' => 'Delete old nodes, content types, fields.',
  );
  $items['override-multisite-components'] = array(
    'description' => 'Override some Multisite core components.',
    'aliases' => array('omc'),
  );
  return $items;
}

/**
 * Drush command that delete nodes with same alias.
 */
function drush_enrd_mastermind_fix_aliases() {
  $duplicated_aliases = 'SELECT ua.alias, ua.language, npid, SUBSTR(ua.source, 6) nid, ua.pid
FROM (
	SELECT count(pid) npid, alias, language
	FROM {url_alias}
    WHERE source LIKE \'node/%\'
	GROUP BY alias, language
) AS da
LEFT JOIN {url_alias} ua ON da.alias = ua.alias AND da.language = ua.language
WHERE da.npid > 1
ORDER BY da.alias ASC, da.language, da.npid DESC, ua.source ASC';

  $result = db_query($duplicated_aliases);

  $ids_to_del = array();
  $pids_to_del = array();
  $nids_to_save = array();

  while ($first_element = $result->fetchObject()) {

    $nids = array($first_element->nid);
    $pids = array($first_element->pid);
    for ($i = 1; $i < $first_element->npid; $i++) {
      $d_element = $result->fetchObject();

      $nids[] = $d_element->nid;
      $pids[] = $d_element->pid;
    }

    // Get the real nid and pid.
    $nid = (int) drupal_substr(drupal_get_normal_path($first_element->alias, $first_element->language), 5);
    $path = path_load(array(
      'source' => 'node/' . $nid,
      'language' => $first_element->language,
    ));
    $pid = $path['pid'];

    $nids_to_save[] = $nid;

    // Calculate duplicated nids and pids.
    $ids_to_del = array_merge($ids_to_del, array_diff($nids, array($nid)));
    $pids_to_del = array_merge($pids_to_del, array_diff($pids, array($pid)));
  }

  $ids_to_del = array_diff($ids_to_del, $nids_to_save);

  drush_log(count($pids_to_del) . " duplicated alias(es).", 'ok');
  drush_log(count($ids_to_del) . " inert node(s).", 'ok');

  if (drush_confirm(dt('Do you want to fix nodes and aliases?'))) {
    // Delete nodes.
    if (!empty($ids_to_del)) {
      entity_delete_multiple('node', $ids_to_del);
    }
    // Delete pids.
    if (!empty($pids_to_del)) {
      foreach ($pids_to_del as $pid) {
        path_delete(array('pid' => $pid));
      }
      drupal_clear_path_cache();
    }
    drush_log(dt('Cleaned.'), 'success');
  }
  else {
    drush_user_abort();
  }
}

/**
 * Drush command that set new module on menu links for nodes.
 *
 * @param mixed $action
 *   Select kind of fix.
 */
function drush_enrd_mastermind_fix_menu_items($action = NULL) {

  $actions = array(
    'mastermind-import' => 'Release menu items from Mastermind feature in favour of menu module',
    'fix-external' => 'Delete non external menu items with absolute link path',
    'localize-menu' => 'Merge menu items in same translation set',
    'delete-disabled' => 'Purge disabled menu items',
    'force-language' => 'Force default menu items to be language neutral and delete',
  );

  if (!$action) {
    $action = drush_choice($actions, dt('Choose the fix tool:'));
  }

  switch ($action) {
    case 'mastermind-import':
      $query = db_query("
UPDATE {menu_links} ml
INNER JOIN {url_alias} ua ON ml.link_path = ua.alias AND ml.language = ua.language
SET ml.link_path=ua.source, ml.router_path = 'node/%'
WHERE ml.module = 'ENRD_mastermind' AND ml.router_path = ''");

      drush_log(dt('!num menu items assigned to theirs node.', array('!num' => $query->rowCount())), 'success');

      $num_updated = db_update('menu_links')
        ->fields(array('module' => 'menu'))
        ->condition('module', 'ENRD_mastermind')
        ->execute();

      drush_log(dt('!num menu item(s) released.', array('!num' => $num_updated)), 'success');

      $select = db_select('menu_links', 'ml')
        ->condition('ml.module', 'menu')
        ->condition('ml.router_path', 'node/%')
        ->isNull('n.nid')
        ->fields('ml', array('mlid'));
      $select->leftJoin('node', 'n', "ml.link_path = CONCAT('node/', CAST(n.nid AS CHAR))");

      $menu_links = $select->execute()->fetchCol();

      $deleted = 0;
      foreach ($menu_links as $mlid) {
        menu_link_delete($mlid);
        _enrd_mastermind_drush_print_progress(++$deleted / count($menu_links));
      }

      drush_log(dt('!num orphan menu link(s) deleted.', array('!num' => count($menu_links))), 'success');
      break;

    case 'fix-external':
      $num_deleted = db_delete('menu_links')
        ->condition('router_path', '')
        ->condition('external', 0)
        ->execute();

      drush_log(dt('!num menu item(s) deleted.', array('!num' => $num_deleted)), 'success');
      break;

    case 'localize-menu':
      // All menu link item into a translation set.
      $menu_links = db_select('menu_links', 'ml')
        ->condition('ml.i18n_tsid', 0, '<>')
        ->condition('ml.language', 'en')
        ->fields('ml', array('mlid', 'i18n_tsid'))
        ->execute()
        ->fetchAllKeyed();

      $item_disabled = 0;
      $tset_del = 0;

      foreach ($menu_links as $mlid => $i18n_tsid) {
        $translation_set = i18n_translation_set_load($i18n_tsid);
        $translations = $translation_set->get_translations();

        list($textgroup, $context) = i18n_string_context(explode(':', "menu:item:$mlid:title"));

        if (isset($translations[language_default('language')])) {
          $item = $translations[language_default('language')];

          // Create translation string source.
          i18n_string_textgroup($textgroup)->context_update($context, $item['link_title'], array('watchdog' => FALSE));

          // Menu item will be 'und'.
          $item['language'] = LANGUAGE_NONE;
          menu_link_save($item);

          unset($translations[language_default('language')]);

          foreach ($translations as $langcode => $item) {
            // Add translation to default language.
            i18n_string_textgroup($textgroup)->update_translation($context, $langcode, $item['link_title']);
            // Hide menu item translated.
            $item['hidden'] = 1;
            menu_link_save($item);
            ++$item_disabled;

          }
        }
        $translation_set->delete();
        _enrd_mastermind_drush_print_progress(++$tset_del / count($menu_links));

      }

      // Remove empty translation set too.
      $query = db_select('i18n_translation_set', 'its');
      $query->leftJoin('menu_links', 'ml', 'ml.i18n_tsid = its.tsid');
      $query->fields('its', array('tsid'))
        ->condition('its.type', 'menu_link')
        ->isNull('ml.i18n_tsid');
      $menu_links = $query->execute()->fetchAllKeyed(0, 0);

      foreach ($menu_links as $i18n_tsid) {
        $translation_set = i18n_translation_set_load($i18n_tsid);
        $translation_set->delete();
        ++$tset_del;
      }

      drush_log(dt('!num translation set(s) deleted.', array('!num' => $tset_del)), 'success');
      drush_log(dt('!num menu item(s) disabled.', array('!num' => $item_disabled)), 'success');
      break;

    case 'delete-disabled':
      $menu_links = db_select('menu_links', 'ml')
        ->condition('ml.module', 'menu')
        ->condition('hidden', 1)
        ->fields('ml', array('mlid'))
        ->execute()->fetchCol();

      $deleted = 0;
      foreach ($menu_links as $mlid) {
        menu_link_delete($mlid);
        _enrd_mastermind_drush_print_progress(++$deleted / count($menu_links));
      }

      drush_log(dt('!num disabled menu link(s) deleted.', array('!num' => count($menu_links))), 'success');
      break;

    case 'force-language':
      $num_updated = db_update('menu_links')
        ->fields(array('language' => LANGUAGE_NONE))
        ->condition('language', language_default('language'))
        ->execute();

      drush_log(dt('!num menu item(s) are now language neutral.', array('!num' => $num_updated)), 'success');

      $num_deleted = db_delete('menu_links')
        ->condition('language', LANGUAGE_NONE, '<>')
        ->execute();

      drush_log(dt('!num menu remaining item(s) deleted.', array('!num' => $num_deleted)), 'success');
      break;

    case FALSE:
    default:
      drush_log(dt('Aborted.'), 'success');
      return;
  }

  menu_cache_clear_all();

}

/**
 * Drush command to clean comments tables.
 */
function drush_enrd_mastermind_clean_comments() {

  // Delete all existing comments (if any).
  $tables = array(
    'comment',
    'field_data_comment_body',
    'field_revision_comment_body',
  );

  foreach ($tables as $table) {
    $count = db_delete($table)
      ->execute();

    drush_log("Deleted $count rows from $table");
  }

}

/**
 * Purge empty fields data.
 */
function drush_enrd_mastermind_purge_fields() {
  $info = field_info_fields();

  $deleted = 0;
  foreach ($info as $field_name => $field) {
    if ($field['module'] == 'text' && $field['type'] != 'text_with_summary') {
      $tables_prefix = array('field_data_', 'field_revision_');

      foreach ($tables_prefix as $prefix) {
        $deleted += db_delete($prefix . $field_name)
          ->isNull($field_name . '_value')
          ->execute();
      }
    }
  }
  drush_log(dt('!num records purged.', array('!num' => $deleted)), 'success');

  drupal_flush_all_caches();
  cache_clear_all();
  drush_log(dt('Cache was cleared.'));
}

/**
 * Drush command that delete/updated menu item from main menu.
 */
function drush_enrd_mastermind_fix_main_menu_items() {
  // Delete item Publication and Media -> Rur@L Newsflash in main menu.
  $select = db_select('menu_links', 'ml')
    ->condition('ml.link_path', 'publications-and-media/rural-news')
    ->fields('ml', array('mlid'));

  $menu_links = $select->execute()->fetchCol();
  foreach ($menu_links as $mlid) {
    menu_link_delete($mlid);
  }

  drush_log(dt('!num menu link(s) deleted.', array('!num' => count($menu_links))), 'success');

  // Path alias modified for Rural Development Policy in Figures in main menu.
  $num_updated = db_update('menu_links')
    ->fields(array('link_path' => 'policy-in-action/rural-development-policy-in-figures/rdp-figures'))
    ->condition('link_path', 'policy-in-action/rural-development-policy-overview/rural-development-policy-in-figures/rdp-figures')
    ->execute();

  drush_log(dt('!num menu item(s) updated.', array('!num' => $num_updated)), 'success');

  // Delete item Publication and Media -> ENRD Main Stories Archives.
  $select = db_select('menu_links', 'ml')
    ->condition('ml.link_path', 'publications-and-media/enrd-main-stories-archive/top-story-semi-subsistence-farming-seminar-tackles-key-issues')
    ->fields('ml', array('mlid'));

  $menu_links = $select->execute()->fetchCol();
  foreach ($menu_links as $mlid) {
    menu_link_delete($mlid);
  }

  drush_log(dt('!num Main Stories menu item deleted.', array('!num' => $num_updated)), 'success');

  // Delete item Publication and Media -> ENRD News Archives in main menu.
  $num_updated = db_update('menu_links')
    ->fields(array('hidden' => 1))
    ->condition('link_path', 'publications-and-media/en_rd_news_archive')
    ->execute();

  drush_log(dt('!num ENRD News Archives menu item updated.', array('!num' => $num_updated)), 'success');

  menu_cache_clear_all();
}

/**
 * Drush command to cleanup contents, fields, instances, content_type.
 */
function drush_enrd_mastermind_delete_old_content() {

  $nids = array();

  // Remove nodes without title or with not set language.
  $results = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->condition(db_or()
      ->condition('language', array_merge(array_keys(language_list('language')), array(LANGUAGE_NONE)), 'NOT IN')
      ->condition('title', ''))
    ->execute();

  foreach ($results as $result) {
    $nids[] = $result->nid;
  }

  // Remove all old news.
  $results = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->condition('type', 'news', '=')
    ->condition('created', mktime(0, 0, 0, 1, 1, 2016), '<')
    ->execute();

  foreach ($results as $result) {
    $nids[] = $result->nid;
  }

  if (!empty($nids)) {
    $deleted = 0;
    foreach (array_chunk($nids, 100) as $chunk_nids) {
      node_delete_multiple($chunk_nids);
      $deleted += count($chunk_nids);
      _enrd_mastermind_drush_print_progress($deleted / count($nids));
    }

    drush_log(dt('Deleted !count old nodes.', array('!count' => count($nids))), 'success');
  }

  // Than remove some old content types.
  $variables = array(
    'comment_anonymous_:ctype',
    'comment_default_mode_:ctype',
    'comment_default_per_page_:ctype',
    'comment_form_location_:ctype',
    'comment_:ctype',
    'comment_preview_:ctype',
    'comment_subject_field_:ctype',
    'diff_enable_revisions_page_node_:ctype',
    'diff_show_preview_changes_node_:ctype',
    'diff_view_mode_preview_node_:ctype',
    'field_bundle_settings_node__:ctype',
    'i18n_node_extended_:ctype',
    'i18n_node_options_:ctype',
    'language_content_type_:ctype',
    'menu_options_:ctype',
    'menu_parent_:ctype',
    'node_options_:ctype',
    'node_preview_:ctype',
    'node_submitted_:ctype',
    'workbench_moderation_default_state_:ctype',
    'pathauto_node_:ctype_pattern',
  );

  $node_types = array(
    'l_a_g',
    'project',
    'project_idea',
    'member',
    'information_tool',
    'rural_dev_priority',
    'nrn_self_assesment_profile',
  );

  foreach ($node_types as $node_type) {
    $results = db_select('node', 'n')
      ->fields('n', array('nid'))
      ->condition('type', $node_type)
      ->execute();

    $nids = array();
    foreach ($results as $result) {
      $nids[] = $result->nid;
    }

    if (!empty($nids)) {

      $deleted = 0;
      foreach (array_chunk($nids, 100) as $chunk_nids) {
        node_delete_multiple($chunk_nids);
        $deleted += count($chunk_nids);
        _enrd_mastermind_drush_print_progress($deleted / count($nids));
      }

      drush_log(dt('Deleted !count !content_type nodes.', array(
        '!count' => count($nids),
        '!content_type' => $node_type,
      )), 'success');
    }

    multisite_drupal_toolbox_config_solr_bundle($node_type, 'delete');
    node_type_delete($node_type);

    foreach ($variables as $variable) {
      variable_del(str_replace(':ctype', $node_type, $variable));
    }
  }

  field_purge_batch(200);

}

/**
 * Override some Multisite core components.
 */
function drush_enrd_mastermind_override_multisite_components() {
  _enrd_mastermind_overrides_all();
}

/**
 * Provides progress bar.
 *
 * @param int $ratio
 *   Operation progress in percentage.
 */
function _enrd_mastermind_drush_print_progress($ratio) {
  $percentage = floor($ratio * 100) . '%';
  $columns = drush_get_context('DRUSH_COLUMNS', 80);
  // Subtract 8 characters for the percentage, brackets, spaces and arrow.
  $progress_columns = $columns - 8;
  // If ratio is 1 (complete), the > becomes a = to make a full bar.
  $arrow = ($ratio < 1) ? '>' : '=';
  // Print a new line if ratio is 1 (complete). Otherwise, use a CR.
  $line_ending = ($ratio < 1) ? "\r" : "\n";

  // Determine the current length of the progress string.
  $current_length = floor($ratio * $progress_columns);
  $progress_string = str_pad('', $current_length, '=');

  $output = '[';
  $output .= $progress_string . $arrow;
  $output .= str_pad('', $progress_columns - $current_length);
  $output .= ']';
  $output .= str_pad('', 5 - drupal_strlen($percentage)) . $percentage;
  $output .= $line_ending;

  print $output;
}
