<?php

/**
 * @file
 * Define the hook_widget for the field enrd_evf.
 */

/**
 * Implements hook_field_widget_info().
 */
function enrd_evf_field_widget_info() {
  return array(
    'evf_textfield' => array(
      'label' => t('Text field'),
      'field types' => array('email_verify_field'),
      'settings' => array(
        'size' => 60,
      ),
    ),
  );
}

/**
 * Implements hook_field_widget_form().
 */
function enrd_evf_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $base) {

  $element = $base;
  $element['email'] = $base + array(
    '#type' => 'textfield',
    '#default_value' => isset($items[$delta]['email']) ? $items[$delta]['email'] : '',
    '#size' => $instance['widget']['settings']['size'],
  );

  return $element;
}

/**
 * Implements hook_field_widget_error().
 */
function enrd_evf_field_widget_error($element, $error, $form, &$form_state) {
  if ($error['error']) {
    form_error($element, $error['message']);
  }
}

/**
 * Implements hook_field_widget_settings_form().
 */
function enrd_evf_field_widget_settings_form($field, $instance) {
  $widget = $instance['widget'];

  $form['size'] = array(
    '#type' => 'textfield',
    '#title' => t('Size of textfield'),
    '#default_value' => $widget['settings']['size'],
    '#required' => TRUE,
    '#element_validate' => array('_element_validate_integer_positive'),
  );
  return $form;
}
