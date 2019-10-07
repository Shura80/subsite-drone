<?php

/**
 * @file
 * File for batch "user merge".
 */

/**
 * Callback for batch process.
 *
 * @param mixed $users_to_merge
 *   An array of pairs of UIDs to be merged.
 * @param mixed $context
 *   The batch context.
 */
function agri_usermerge_batch_merge_callback($users_to_merge, &$context) {
  if (empty($context['sandbox'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current'] = 0;
    $context['sandbox']['max'] = count($users_to_merge);
  }

  $limit = 5;
  $action = 'block';

  $account_to_work = array_slice($users_to_merge, $context['sandbox']['current'], $limit);

  foreach ($account_to_work as $account) {

    $user_to_block = user_load($account[0]);
    $user_to_keep = user_load($account[1]);

    agri_usermerge_usermerge_do($user_to_block, $user_to_keep, $action);

    $message = t('@user_to_block merged with @user_to_keep', array(
      '@user_to_block' => $user_to_block->name,
      '@user_to_keep' => $user_to_keep->name,
    ));

    $context['sandbox']['progress']++;
    $context['results']['users_blocked'][] = $user_to_block;
    $context['results'][] = $message;
    $context['message'] = $message;

  }

  $context['sandbox']['current'] += $limit;
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

/**
 * Callback for batch process.
 *
 * @param mixed $context
 *   The batch context.
 */
function agri_usermerge_batch_flag_callback(&$context) {
  $users_blocked = $context['results']['users_blocked'];

  if (empty($context['sandbox'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current'] = 0;
    $context['sandbox']['max'] = count($users_blocked);
  }

  $limit = 5;
  $account_to_work = array_slice($users_blocked, $context['sandbox']['current'], $limit);

  foreach ($account_to_work as $user_obj) {
    try {
      $user_wrapper = entity_metadata_wrapper('user', $user_obj);
      $user_wrapper->field_user_merged->set(1);
      $user_wrapper->save();
    }
    catch (EntityMetadataWrapperException $exc) {
      watchdog(
        'agri_usermerge',
        'EntityMetadataWrapper exception in %function() <pre>@trace</pre>',
        array(
          '%function' => __FUNCTION__,
          '@trace' => $exc->getTraceAsString(),
        ),
        WATCHDOG_ERROR
      );
    }

    $message = t('@count users clean of @max', array(
      '@count' => $context['sandbox']['current'],
      '@max' => $context['sandbox']['max'],
    ));
    $context['message'] = $message;
    $context['sandbox']['progress']++;
  }

  $context['sandbox']['current'] += $limit;
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

/**
 * Batch finished callback.
 *
 * @param bool $success
 *   TRUE of FALSE.
 * @param array $results
 *   Optional array.
 * @param array $operations
 *   Operations array.
 */
function agri_usermerge_batch_finished($success, array $results, array $operations) {

  unset($results['users_blocked']);

  // Rehabilitate og rules.
  $og_rules = rules_config_load('agri_og_administration_member_subscribe_active');
  $og_rules->active = TRUE;
  $og_rules->save();

  if ($success) {
    $message = t('@count items successfully processed:', array('@count' => count($results)));
    $message .= theme('item_list', array('items' => $results));
    drupal_set_message($message);
  }
  else {
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments',
      array(
        '%error_operation' => $error_operation[0],
        '@arguments' => print_r($error_operation[1], TRUE),
      )
    );
    drupal_set_message($message, 'error');
  }

}
