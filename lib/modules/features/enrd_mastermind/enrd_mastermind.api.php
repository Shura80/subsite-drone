<?php

/**
 * @file
 * Hooks provided by enrd_mastermind module.
 */

/**
 * Allow run custom code to override behavior of specific components.
 *
 * Note: if you need to use Drupal translation system use get_t()
 * because the hook is called at install time.
 *
 * @see get_t()
 * @see _enrd_mastermind_overrides_all()
 */
function hook_override_multisite_components() {

  // Example overriding rule in soft configuration.
  $rules_config = rules_config_load('rules_log_updates');
  $rules_config->active = FALSE;
  $rules_config->save();
}

/**
 * Allow to create default items for some components.
 *
 * Note: if you need to use Drupal translation system use get_t()
 * because the hook is called at install time.
 *
 * @see get_t()
 * @see _enrd_mastermind_environment_prepopulate()
 */
function hook_environment_prepopulate() {
  // Create custom role.
  multisite_config_service('user')->createRole('manager');
}

/**
 * Build list of path aliases where default last update info is displayed.
 *
 * @see _enrd_mastermind_last_update_build_ignore_list()
 *
 * @return array
 *   Returns an array of path aliases that display default last update info.
 */
function hook_last_update_ignore_list() {
  // Define here the custom list of paths to be ignored.
  return ['my/custom/path'];
}
