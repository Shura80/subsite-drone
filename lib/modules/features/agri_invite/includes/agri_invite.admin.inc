<?php

/**
 * @file
 * File for Admin.
 */

/**
 * Settings form for AGRI Invite.
 *
 * @return array
 *   Return array with system settings form.
 */
function agri_invite_settings_form() {

  $form['mail_template'] = array(
    '#type' => 'fieldset',
    '#title' => t('Mail template'),
    '#description' => t('This page allows you to configure the email message sent to invite people to the collaborative area'),
    '#collapsible' => FALSE,
  );
  $form['mail_template']['agri_invite_mail_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#description' => t('Subject of the email.'),
    '#default_value' => variable_get('agri_invite_mail_subject', AGRI_INVITE_MAIL_SUBJECT),
    '#required' => TRUE,
  );

  $available_tokens = array(
    '[invite:contact-user] => The link to the contact form of the user specified in the field "Contact user" defined below.',
    '[invite:eu-login-invite-accept-link] => The url to accept the invitation.',
    '[invite:field-invitation-group-ref:title] => The title of the "collaborative area"',
    '[invite:field_invitation_event_title] => The name of the event for which the invitation has been sent. It will be set in the form to send the invitation.',
  );

  $form['mail_template']['agri_invite_mail_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#description' => t('Body of the mail. </br> <b>WARNING!</b> Please, take care in modifying the body of the email because it contains the following tokens: !token', array(
      '!token' => theme('item_list', array('items' => $available_tokens)),
    )),
    '#default_value' => variable_get('agri_invite_mail_body', AGRI_INVITE_MAIL_BODY),
    '#required' => TRUE,
  );
  $form['mail_template']['agri_invite_mail_contact_person'] = array(
    '#type' => 'textfield',
    '#title' => t('Contact user'),
    '#description' => t('The user name of the contact person. It is used as sender of the email and within its body in relations to the above-mentioned token.'),
    '#autocomplete_path' => 'user/autocomplete',
    '#default_value' => variable_get('agri_invite_mail_contact_person', AGRI_INVITE_MAIL_CONTACT_PERSON),
    '#required' => TRUE,
  );
  return system_settings_form($form);
}
