<?php

/**
 * @file
 * File for Admin.
 */

/**
 * Settings form for LAG Invites.
 *
 * @return array
 *   Return array with system settings form.
 */
function enrd_lag_invite_settings_form() {

  $form['enrd_lag_invite_send_invitation_on_lag_create'] = array(
    '#type' => 'checkbox',
    '#title' => t('Send automatically an invitation to the LAG Manager during LAG creation.'),
    '#default_value' => variable_get('enrd_lag_invite_send_invitation_on_lag_create', ENRD_LAG_INVITE_SEND_INVITATION_ON_LAG_CREATE_DEFAULT),
  );

  $form['templates'] = array(
    '#type' => 'vertical_tabs',
  );

  $form['mail_template'] = array(
    '#type' => 'fieldset',
    '#title' => t('Mail template'),
    '#group' => 'templates',
  );

  $form['mail_template']['enrd_lag_invite_mail_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#description' => t('Type the default subject of the invitation e-mail. Use the syntax [token] if you want to insert a replacement pattern.'),
    '#size' => 75,
    '#default_value' => variable_get('enrd_lag_invite_mail_subject', ENRD_LAG_INVITE_MAIL_SUBJECT),
    '#required' => TRUE,
  );

  $form['mail_template']['enrd_lag_invite_mail_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Mail template'),
    '#description' => t('Use the syntax [token] if you want to insert a replacement pattern.'),
    '#rows' => 15,
    '#default_value' => variable_get('enrd_lag_invite_mail_body', ENRD_LAG_INVITE_MAIL_BODY),
    '#required' => TRUE,
  );

  $form['renew_template'] = array(
    '#type' => 'fieldset',
    '#title' => t('Renew template'),
    '#group' => 'templates',
  );

  $form['renew_template']['enrd_lag_invite_mail_renew_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#description' => t('Type the default subject of the invitation e-mail. Use the syntax [token] if you want to insert a replacement pattern.'),
    '#size' => 75,
    '#default_value' => variable_get('enrd_lag_invite_mail_renew_subject', ENRD_LAG_INVITE_MAIL_RENEW_SUBJECT),
    '#required' => TRUE,
  );

  $form['renew_template']['enrd_lag_invite_mail_renew_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body template'),
    '#description' => t('Use the syntax [token] if you want to insert a replacement pattern.'),
    '#rows' => 15,
    '#default_value' => variable_get('enrd_lag_invite_mail_renew_body', ENRD_LAG_INVITE_MAIL_RENEW_BODY),
    '#required' => TRUE,
  );

  // Display the list of available placeholders if token module is installed.
  if (module_exists('token')) {
    $form['token_help'] = array(
      '#theme' => 'token_tree',
      '#dialog' => TRUE,
      '#token_types' => array(
        'invite',
      ),
    );
  }

  return system_settings_form($form);
}
