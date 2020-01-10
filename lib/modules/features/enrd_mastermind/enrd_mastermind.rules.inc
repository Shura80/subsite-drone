<?php

/**
 * @file
 * Rules integration for the subscriptions_rules module.
 */

/**
 * Implements hook_rules_action_info().
 */
function enrd_mastermind_rules_action_info() {

  $items['enrd_mastermind_add_user_to_digest'] = array(
    'label' => t('Subscribe user to og digest'),
    'base' => '_enrd_mastermind_add_user_to_digest_callback',
    'type' => 'subscriptions',
    'parameter' => array(
      'user' => array(
        'type' => 'user',
        'label' => t('User'),
        'description' => t('The user who will be subscribed.'),
        'wrapped' => TRUE,
      ),
      'group' => array(
        'type' => array_keys(og_get_all_group_entity()),
        'label' => t('Group'),
        'wrapped' => TRUE,
      ),
    ),
    'group' => t('ENRD Mastermind'),
    'access callback' => 'og_rules_integration_access',
  );

  $items['enrd_mastermind_delete_user_to_digest'] = array(
    'label' => t('Unsubscribe user to og digest'),
    'base' => '_enrd_mastermind_delete_user_to_digest_callback',
    'type' => 'subscriptions',
    'parameter' => array(
      'user' => array(
        'type' => 'user',
        'label' => t('User'),
        'description' => t('The user who will be subscribed.'),
        'wrapped' => TRUE,
      ),
      'group' => array(
        'type' => array_keys(og_get_all_group_entity()),
        'label' => t('Group'),
        'wrapped' => TRUE,
      ),
    ),
    'group' => t('ENRD Mastermind'),
    'access callback' => 'og_rules_integration_access',
  );

  return $items;
}

/**
 * Rule enrd_mastermind_add_user_to_digest callback.
 *
 * @param Object|int $user
 *   Drupal wrapper for user or uid.
 * @param Object|int $group
 *   Drupal wrapper for og group or gid.
 */
function _enrd_mastermind_add_user_to_digest_callback($user, $group) {
  enrd_mastermind_add_user_to_digest_callback($user, $group);
}

/**
 * Rule enrd_mastermind_delete_user_to_digest callback.
 *
 * @param EntityDrupalWrapper $user
 *   Drupal wrapper for user.
 * @param EntityDrupalWrapper $group
 *   Drupal wrapper for og group.
 */
function _enrd_mastermind_delete_user_to_digest_callback(EntityDrupalWrapper $user, EntityDrupalWrapper $group) {

  $uid = $user->getIdentifier();
  $module = 'node';
  $field = 'group_audience';
  $value = $group->getIdentifier();

  subscriptions_delete($uid, $module, $field, $value, '-1');
}
