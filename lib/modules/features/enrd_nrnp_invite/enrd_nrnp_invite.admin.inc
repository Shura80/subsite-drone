<?php

/**
 * @file
 * File for Admin.
 */

/**
 * Settings form for NRN Profiles.
 *
 * @return array
 *   Return array with system settings form.
 */
function enrd_nrnp_invite_invite_settings_form() {

  $form['templates'] = array(
    '#type' => 'vertical_tabs',
  );

  $form['mail_template'] = array(
    '#type' => 'fieldset',
    '#title' => t('Mail template'),
    '#group' => 'templates',
  );

  $form['mail_template']['enrd_nrnp_invite_mail_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#description' => t('Type the default subject of the invitation e-mail. Use the syntax [token] if you want to insert a replacement pattern.'),
    '#size' => 75,
    '#default_value' => variable_get('enrd_nrnp_invite_mail_subject', ENRD_NRNP_INVITE_MAIL_SUBJECT),
    '#required' => TRUE,
  );

  $form['mail_template']['enrd_nrnp_invite_mail_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#description' => t('Use the syntax [token] if you want to insert a replacement pattern.'),
    '#rows' => 15,
    '#default_value' => variable_get('enrd_nrnp_invite_mail_body', ENRD_NRNP_INVITE_MAIL_BODY),
    '#required' => TRUE,
  );

  $form['renew_template'] = array(
    '#type' => 'fieldset',
    '#title' => t('Renew template'),
    '#group' => 'templates',
  );

  $form['renew_template']['enrd_nrnp_invite_mail_renew_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#description' => t('Type the default subject of the invitation e-mail. Use the syntax [token] if you want to insert a replacement pattern.'),
    '#size' => 75,
    '#default_value' => variable_get('enrd_nrnp_invite_mail_renew_subject', ENRD_NRNP_INVITE_MAIL_RENEW_SUBJECT),
    '#required' => TRUE,
  );

  $form['renew_template']['enrd_nrnp_invite_mail_renew_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#description' => t('Use the syntax [token] if you want to insert a replacement pattern.'),
    '#rows' => 15,
    '#default_value' => variable_get('enrd_nrnp_invite_mail_renew_body', ENRD_NRNP_INVITE_MAIL_RENEW_BODY),
    '#required' => TRUE,
  );

  $form['confirm_editor_template'] = array(
    '#type' => 'fieldset',
    '#title' => t('Confirm for editors template'),
    '#group' => 'templates',
  );

  $form['confirm_editor_template']['enrd_nrnp_invite_mail_confirm_editor_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#description' => t('Type the default subject of the invitation e-mail. Use the syntax [token] if you want to insert a replacement pattern.'),
    '#size' => 75,
    '#default_value' => variable_get('enrd_nrnp_invite_mail_confirm_editor_subject', ENRD_NRNP_INVITE_MAIL_CONFIRM_EDITOR_SUBJECT),
    '#required' => TRUE,
  );

  $form['confirm_editor_template']['enrd_nrnp_invite_mail_confirm_editor_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#description' => t('Use the syntax [token] if you want to insert a replacement pattern.'),
    '#rows' => 15,
    '#default_value' => variable_get('enrd_nrnp_invite_mail_confirm_editor_body', ENRD_NRNP_INVITE_MAIL_CONFIRM_EDITOR_BODY),
    '#required' => TRUE,
  );

  $form['confirm_cp_template'] = array(
    '#type' => 'fieldset',
    '#title' => t('Confirm for CP template'),
    '#group' => 'templates',
  );

  $form['confirm_cp_template']['enrd_nrnp_invite_mail_confirm_cp_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#description' => t('Type the default subject of the invitation e-mail. Use the syntax [token] if you want to insert a replacement pattern.'),
    '#size' => 75,
    '#default_value' => variable_get('enrd_nrnp_invite_mail_confirm_cp_subject', ENRD_NRNP_INVITE_MAIL_CONFIRM_CP_SUBJECT),
    '#required' => TRUE,
  );

  $form['confirm_cp_template']['enrd_nrnp_invite_mail_confirm_cp_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#description' => t('Use the syntax [token] if you want to insert a replacement pattern.'),
    '#rows' => 15,
    '#default_value' => variable_get('enrd_nrnp_invite_mail_confirm_cp_body', ENRD_NRNP_INVITE_MAIL_CONFIRM_CP_BODY),
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
