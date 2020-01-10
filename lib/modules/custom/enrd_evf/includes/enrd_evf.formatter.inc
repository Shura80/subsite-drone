<?php

/**
 * @file
 * Define the hook_formatter for the field enrd_evf.
 */

/**
 * Implements hook_field_formatter_info().
 */
function enrd_evf_field_formatter_info() {
  $formats = array(
    'evf_default' => array(
      'label' => t('Default email link'),
      'description' => t('Display the email address as a mailto link.'),
      'field types' => array('email_verify_field'),
    ),
    'evf_plain' => array(
      'label' => t('Email plain text'),
      'description' => t('Display the email address as plain text.'),
      'field types' => array('email_verify_field'),
    ),
  );

  return $formats;
}

/**
 * Implements hook_field_formatter_view().
 */
function enrd_evf_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, &$items, $display) {

  $element = array();
  switch ($display['type']) {
    // Display the email address as a mailto link.
    case 'evf_default':
      foreach ($items as $delta => $item) {
        $output = l($item['email'], 'mailto:' . $item['email']);
        $element[$delta] = array('#markup' => $output);
      }
      break;

    // Display the email address as plain text.
    case 'evf_plain':
      foreach ($items as $delta => $item) {
        $element[$delta] = array('#markup' => check_plain($item['email']));
      }
      break;

  }

  return $element;
}
