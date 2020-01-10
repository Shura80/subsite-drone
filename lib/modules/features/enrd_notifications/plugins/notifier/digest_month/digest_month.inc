<?php

/**
 * @file
 * digest_month.inc
 */

$plugin = array(
  'title' => t('Monthly Message Digest'),
  'description' => t('Send Message via monthly digest.'),
  'class' => 'EnrdNotificationsMessageDigestMonth',
  'view_modes' => array(
    'message_notify_monthly_digest' => array('label' => t('Notify - Monthly digest')),
  ),
);
