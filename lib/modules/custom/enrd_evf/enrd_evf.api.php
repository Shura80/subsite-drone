<?php

/**
 * @file
 * Hooks provided by the ENRD Email Verify Field.
 */

/**
 * Allow other modules to act when email confirmed.
 *
 * @param string $entity_type
 *   The entity name.
 * @param string $bundle
 *   Name of the bundle.
 * @param object $entity
 *   The entire entity object.
 * @param string $field_name
 *   The field name.
 * @param bool $by_email
 *   If TRUE, the email was confirmed using the link sent via email.
 */
function hook_enrd_evf_post_status_confirm($entity_type, $bundle, $entity, $field_name, $by_email = FALSE) {

  if ($by_email) {
    $message = t('Email confirmed by email!');
    drupal_set_message($message);
  }
  else {
    $message = t('Email confirmed without validation email!');
    drupal_set_message($message);
  }

}
