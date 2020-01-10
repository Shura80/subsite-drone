<?php

/**
 * @file
 * Admin interface for enrd taxonomies classification system.
 */

/**
 * Form callback for module settings.
 *
 * @return array
 *   A form array.
 */
function enrd_taxonomies_field_instances_form() {

  $instances = field_info_instances('node');
  $field_base = _enrd_taxonomies_field_base_list();

  // Build header.
  $header = array(
    'content_type' => array('data' => t('Content type')),
  );

  foreach (_enrd_taxonomies_field_group_list() as $group_name => $group) {
    $header[$group_name]['data'] = $group['label'];
  }

  $form = array('content_type' => array());
  $options = array();

  // Build values for content types, check every field.
  foreach (node_type_get_names() as $node_type => $node_name) {
    $form['content_type'][$node_type] = array(
      '#type' => 'radio',
      '#disabled' => _enrd_taxonomies_check_content_type('node', $node_type),
      '#default_value' => '',
    );

    $options[$node_type] = array(
      'content_type' => check_plain($node_name),
    );

    $field_group = field_group_info_groups('node', $node_type, 'form');

    foreach ($field_base as $group_name => $group) {
      foreach ($group as $field_name => $field_label) {

        $present = isset($instances[$node_type][$field_name]);
        $grouped = (isset($field_group[$group_name]) && in_array($field_name, $field_group[$group_name]->children));

        $options[$node_type][$group_name]['data'][$field_name] = array(
          '#type' => 'container',
          'icon' => array(
            '#type' => 'container',
            '#attributes' => array(
              'class' => array('ui-icon ' . ($present ? ($grouped ? 'ui-icon-locked' : 'ui-icon-check') : 'ui-icon-minus')),
              'style' => 'display: inline-block;',
            ),
          ),
          'field-info' => array(
            '#markup' => ($present) ?
            l($instances[$node_type][$field_name]['label'],
              "admin/structure/types/manage/$node_type/fields/$field_name",
              array('attributes' => array('title' => check_plain($field_label))))
            : check_plain($field_label),
          ),
        );
      }
    }
  }

  $form['notice'] = array(
    '#type' => 'item',
    '#title' => t('Warning'),
    '#markup' => t("This configuration form is only for platform administrators and developers use. Beware if you don't know the effects.<br />All operations can not be reverted."),
    '#weight' => -1,
  );

  $form['content_type'] = $form['content_type'] + array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t('No content type available.'),
    '#js_select' => FALSE,
    '#multiple' => FALSE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add set'),
  );

  return $form;
}

/**
 * Form submit function for enrd_taxonomies_field_instances_form.
 */
function enrd_taxonomies_field_instances_form_submit($form, &$form_state) {
  $content_type = key(array_filter($form_state['values']['content_type']));
  if (isset($content_type)) {
    if (_enrd_taxonomies_set_instance('node', $content_type)) {
      drupal_set_message(t('Classification fields added to @bundle bundle.', array('@bundle' => $content_type)));
    }
  }
}
