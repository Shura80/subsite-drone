<?php

/**
 * @file
 * Menu callbacks for the ENRD Notifications pages.
 */

/**
 * Returns empty page to use as Notifications page context container.
 */
function enrd_notifications_settings_page() {
  // Custom empty menu callback to use as settings page default page.
  // Content of the page is managed in quicktabs.
  return t('This page allows you to set your notification rules. You can choose to be notified when new and updated ENRD events, news and cooperation offers are made available. You can enable email notifications or onsite messages, or both.');
}

/**
 * Form callback for configuring notification settings.
 */
function enrd_notifications_settings_form($form, &$form_state) {

  global $user;

  $account = user_load($user->uid);

  $form['account'] = [
    '#type' => 'value',
    '#value' => $account,
  ];

  $form['email-settings'] = [
    '#type' => 'container',
    '#attributes' => [
      'class' => ['enrd-notifications email-settings'],
    ],
  ];

  $form['email-settings']['description'] = [
    '#type' => 'item',
    '#description' => t('Here you can set the frequency of your notification emails (provided you have enabled the email notification option) or enable a reminder to receive a monthly email with the number of unread notifications you have.'),
  ];

  $form['email-settings']['message_subscribe_email_freq'] = [
    '#type' => 'select',
    '#options' => message_subscribe_email_frequency_allowed_values(),
    '#title' => t('How often would you like to receive email notifications?'),
    '#description' => t('Control how often you are notified by email of new content and activity you are subscribed to.'),
    '#ajax' => [
      'callback' => 'enrd_notifications_message_subscribe_email_freq_setting_submit',
    ],
    '#default_value' => isset($account->message_subscribe_email_freq[LANGUAGE_NONE][0]['value']) ? $account->message_subscribe_email_freq[LANGUAGE_NONE][0]['value'] : 'digest_month',
  ];

  $form['email-settings']['field_enrd_notifications_remind'] = [
    '#type' => 'checkbox',
    '#title' => t('Remind me of unread notifications.'),
    '#description' => t('If checked, an email will be sent to remind about unread notifications.'),
    '#ajax' => [
      'callback' => 'enrd_notifications_email_reminder_setting_submit',
    ],
    '#default_value' => isset($account->field_enrd_notifications_remind[LANGUAGE_NONE][0]['value']) ? $account->field_enrd_notifications_remind[LANGUAGE_NONE][0]['value'] : FALSE,
  ];

  $form['submit'] = [
    '#type' => 'submit',
    '#value' => t('Save email notification settings'),
    '#attributes' => [
      'class' => ['js-hide'],
    ],
  ];

  // Add the subit for email settings fields.
  $form['#submit'][] = 'enrd_notifications_message_subscribe_email_freq_setting_submit';

  return $form;
}

/**
 * Submit handler for message_subscribe_email_freq setting.
 */
function enrd_notifications_message_subscribe_email_freq_setting_submit($form, &$form_state) {
  if ($form_state['values']['message_subscribe_email_freq'] != $form['email-settings']['message_subscribe_email_freq']['#default_value']) {
    $account = $form['account']['#value'];
    $account->message_subscribe_email_freq[LANGUAGE_NONE][0]['value'] = $form_state['values']['message_subscribe_email_freq'];
    user_save($account);
  }
}

/**
 * Submit handler for field_enrd_notifications_remind setting.
 */
function enrd_notifications_email_reminder_setting_submit($form, &$form_state) {
  if ($form_state['values']['field_enrd_notifications_remind'] != $form['email-settings']['field_enrd_notifications_remind']['#default_value']) {
    $account = $form['account']['#value'];
    $account->field_enrd_notifications_remind[LANGUAGE_NONE][0]['value'] = $form_state['values']['field_enrd_notifications_remind'];
    user_save($account);
  }
}
