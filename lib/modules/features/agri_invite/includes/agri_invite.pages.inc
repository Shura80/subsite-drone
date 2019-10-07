<?php

/**
 * @file
 * AGRI Invite code for Invite People form.
 */

/**
 * Implements hook_form().
 */
function agri_invite_invite_form($form, &$form_state, $group_type, $gid) {

  $group = entity_load_single($group_type, $gid);

  $form['group_type'] = array('#type' => 'value', '#value' => $group_type);
  $form['gid'] = array('#type' => 'value', '#value' => $gid);

  $form['container'] = array(
    '#type' => 'fieldset',
    '#title' => t('Invite new users to %group', array('%group' => $group->title)),
    '#description' => t('This page allows you to send invitations email to all the participants of a specific event related to this Collaborative Area.'),
  );
  $form['container']['email'] = array(
    '#type' => 'textarea',
    '#title' => t('User email(s)'),
    '#description' => t('The list of the email address that should receive the email (one address per line).'),
    '#required' => TRUE,
  );
  $form['container']['event_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Event name'),
    '#description' => t('The name of the event to be shown in the email body.'),
    '#required' => TRUE,
  );
  $form['container']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Invite user(s)'),
  );

  og_set_breadcrumb($group_type, $gid, array(l(t('Group'), "$group_type/$gid/group")));

  return $form;
}

/**
 * Implements hook_form_validate().
 */
function agri_invite_invite_form_validate($form, &$form_state) {

  $group_type = $form_state['values']['group_type'];
  $gid = $form_state['values']['gid'];

  $mail_not_valid = array();
  $mail_already_exist = array();
  $error_messages = array();

  $mail_addresses = array_values(array_filter(preg_split('/\r\n|[\r\n]/', $form_state['values']['email'])));

  foreach ($mail_addresses as $mail_address) {
    if (!valid_email_address(trim($mail_address))) {
      $mail_not_valid[] = $mail_address;
    }
    else {
      if ($user = user_load_by_mail($mail_address)) {
        if (og_get_membership($group_type, $gid, 'user', $user->uid)) {
          $mail_already_exist[] = $mail_address;
        }
      }
    }
  }

  if (!empty($mail_not_valid)) {
    $error_messages['email'][] = t('The following email address(es) are not valid: !mail', array(
      '!mail' => theme('item_list', array(
        'items' => $mail_not_valid,
      )),
    ));
  }

  if (!empty($mail_already_exist)) {
    $error_messages['email'][] = t('The following email address(es) is already subscribed to Collaborative Area: !mail', array(
      '!mail' => theme('item_list', array(
        'items' => $mail_already_exist,
      )),
    ));

  }

  foreach ($error_messages as $element => $messages) {
    form_set_error($element, t('Invitation not send because of following error(s): !error', array(
      '!error' => theme('item_list', array(
        'items' => $messages,
      )),
    )));
  }

}

/**
 * Implements hook_form_submit().
 */
function agri_invite_invite_form_submit($form, &$form_state) {
  $mail_addresses = array_values(array_filter(preg_split('/\r\n|[\r\n]/', $form_state['values']['email'])));
  $gid = $form_state['values']['gid'];
  $event_title = $form_state['values']['event_title'];

  foreach ($mail_addresses as $email) {
    $return = _agri_invite_invite_by_mail($gid, trim($email), $event_title);
    if (!empty($return)) {
      $messages[$return['op']][] = $return['email'];
    }
  }

  $type = 'status';
  foreach (drupal_get_messages($type) as $key => $message) {
    if ($message == 'Invitation has been sent.') {
      unset($_SESSION['messages'][$type][$key]);
    }
  }

  if (isset($messages['send']) && !empty($messages['send'])) {
    drupal_set_message(t('Invitation sent to: !send', array(
      '!send' => theme('item_list', array(
        'items' => $messages['send'],
      )),
    )));
  }

  if (isset($messages['resend']) && !empty($messages['resend'])) {
    drupal_set_message(t('Invitation re-sent to: !resend', array(
      '!resend' => theme('item_list', array(
        'items' => $messages['resend'],
      )),
    )));
  }
}
