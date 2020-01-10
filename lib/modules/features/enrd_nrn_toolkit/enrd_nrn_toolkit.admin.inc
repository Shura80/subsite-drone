<?php

/**
 * @file
 * Admin interface for enrd nrn toolkit system.
 */

/**
 * Form callback for module settings.
 *
 * @return array
 *   A form array.
 */
function enrd_nrn_toolkit_field_instances_form() {
  $instances = field_info_instances('node');
  $field_base = _enrd_nrn_toolkit_field_base_list();

  // Build header.
  $header = [
    'content_type' => ['data' => t('Content type')],
  ];

  foreach (_enrd_nrn_toolkit_field_group_list() as $group_name => $group) {
    $header[$group_name]['data'] = $group['label'];
  }

  $form = ['content_type' => []];
  $options = [];

  // Build values for content types, check every field.
  foreach (node_type_get_names() as $node_type => $node_name) {
    $form['content_type'][$node_type] = [
      '#type' => 'radio',
      '#disabled' => _enrd_nrn_toolkit_check_content_type('node', $node_type),
      '#default_value' => '',
    ];

    $options[$node_type] = [
      'content_type' => check_plain($node_name),
    ];

    $field_group = field_group_info_groups('node', $node_type, 'form');

    foreach ($field_base as $group_name => $group) {
      foreach ($group as $field_name => $info) {

        $present = isset($instances[$node_type][$field_name]);
        $grouped = (isset($field_group[$group_name]) && in_array($field_name, $field_group[$group_name]->children));

        $options[$node_type][$group_name]['data'][$field_name] = [
          '#type' => 'container',
          'icon' => [
            '#type' => 'container',
            '#attributes' => [
              'class' => ['ui-icon ' . ($present ? ($grouped ? 'ui-icon-locked' : 'ui-icon-check') : 'ui-icon-minus')],
              'style' => 'display: inline-block;',
            ],
          ],
          'field-info' => [
            '#markup' => ($present) ?
            l($instances[$node_type][$field_name]['label'],
                "admin/structure/types/manage/$node_type/fields/$field_name",
                ['attributes' => ['title' => check_plain($info['label'])]])
            : check_plain($info['label']),
          ],
        ];
      }
    }
  }

  $form['notice'] = [
    '#type' => 'item',
    '#title' => t('Warning'),
    '#markup' => t("This configuration form is only for platform administrators and developers use. Beware if you don't know the effects.<br />All operations can not be reverted."),
    '#weight' => -1,
  ];

  $form['content_type'] = $form['content_type'] + [
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t('No content type available.'),
    '#js_select' => FALSE,
    '#multiple' => FALSE,
  ];

  $form['submit'] = [
    '#type' => 'submit',
    '#value' => t('Add set'),
  ];

  return $form;
}

/**
 * Form submit function for enrd_taxonomies_field_instances_form.
 */
function enrd_nrn_toolkit_field_instances_form_submit($form, &$form_state) {
  $content_type = key(array_filter($form_state['values']['content_type']));
  if (isset($content_type)) {
    if (_enrd_nrn_toolkit_set_instance('node', $content_type)) {
      drupal_set_message(t('NRN Toolkit fields added to @bundle bundle.',
        ['@bundle' => $content_type]));
    }
  }
}

/**
 * ENRD NRN Toolkit field group structure.
 *
 * @return array
 *   An array with ENRD NRN Toolkit field group structure.
 */
function _enrd_nrn_toolkit_field_group_list() {
  return [
    'group_nrn_toolkit' => [
      'label' => t('NRN Toolkit'),
    ],
  ];
}

/**
 * ENRD NRN Toolkit field structure.
 *
 * @return array
 *   An array with ENRD NRN Toolkit field structure.
 */
function _enrd_nrn_toolkit_field_base_list() {
  return [
    'group_nrn_toolkit' => [
      'field_enrd_nrn_include_toolkit' => [
        'label' => t('Include in the NRN Toolkit'),
        'description' => t('Select this checkbox to include it in the NRN Toolkit section.'),
        'widget' => 'options_onoff',
      ],
      'field_enrd_nrn_type' => [
        'label' => t('Resource type'),
        'widget' => 'options_select',
      ],
      'field_tax_networking' => [
        'label' => t('NRN Classification'),
        'widget' => 'taxonomy_shs',
      ],
      'field_enrd_nrn_date' => [
        'label' => t('Date'),
        'description' => t('This date is used for sorting purposes in the NRN Toolkit search results list.'),
        'widget' => 'date_select',
      ],
      'field_enrd_nrn_title' => [
        'label' => t('NRN Title'),
        'description' => t('Optionally specify a title to be displayed on the NRN Toolkit search results list.'),
        'widget' => 'text_textfield',
      ],
      'field_enrd_nrn_alter_description' => [
        'label' => t('NRN Description'),
        'description' => t('Optionally specify a description to be displayed on the NRN Toolkit search results list.'),
        'widget' => 'text_textarea',
      ],
    ],
  ];
}

/**
 * Check if content type had at least one nrn toolkit field.
 *
 * @param string $entity_type
 *   Entity type.
 * @param string $bundle_name
 *   Bundle machine name.
 *
 * @return bool
 *   Return true if bundle contains at least on field.
 */
function _enrd_nrn_toolkit_check_content_type($entity_type, $bundle_name) {
  $instances = field_info_instances($entity_type, $bundle_name);

  foreach (_enrd_nrn_toolkit_field_base_list() as $fields) {
    if (!empty(array_intersect_key($fields, $instances))) {
      return TRUE;
    }
  }
  return FALSE;
}

/**
 * Instance the set into the entity bundle.
 *
 * @param string $entity_type
 *   Entity type.
 * @param string $bundle
 *   Bundle machine name.
 * @param bool $force
 *   Force the operation even if bundle already contains a field instance.
 *
 * @return bool
 *   TRUE if operation was executed.
 *
 * @throws \FieldException
 */
function _enrd_nrn_toolkit_set_instance($entity_type, $bundle, $force = FALSE) {
  if (!_enrd_nrn_toolkit_check_content_type($entity_type, $bundle) || $force) {

    $service_field = multisite_config_service('field');
    $service_group = multisite_config_service('field_group');

    module_load_include('inc', 'enrd_nrn_toolkit', 'enrd_nrn_toolkit.features.field_instance');

    $feature_field_instances = enrd_nrn_toolkit_field_default_field_instances();
    $field_groups = _enrd_nrn_toolkit_field_group_list();
    foreach (_enrd_nrn_toolkit_field_base_list() as $group_name => $group) {

      $added_field = [];

      foreach ($group as $field_name => $field_info) {
        if (!field_info_instance($entity_type, $field_name, $bundle)) {
          // Create a new instance.
          $service_field->createInstanceField($field_name, $entity_type, $bundle)
            ->label($field_info['label'])
            ->widget($field_info['widget'])
            ->save();

          $instance_to_copy = "node-page-$field_name";

          // Set custom options for widget, settings and description.
          if (isset($feature_field_instances[$instance_to_copy])) {
            $instance_info = field_info_instance($entity_type, $field_name, $bundle);

            // Get field description from our structure or from the mold bundle.
            $instance_info['description'] = isset($field_info['description']) ? $field_info['description'] : $feature_field_instances[$instance_to_copy]['description'];
            $instance_info['widget'] = $feature_field_instances[$instance_to_copy]['widget'];
            $instance_info['settings'] = $feature_field_instances[$instance_to_copy]['settings'];

            field_update_instance($instance_info);
          }

          $added_field[] = $field_name;
        }
      }

      $service_group->createFieldGroup($field_groups[$group_name]['label'], $group_name, $entity_type, $bundle)
        ->setChildren($added_field)
        ->setType('tab')->setFormatter('closed')->setWeight(20)
        ->setInstanceSetting('classes', "$group_name field-group-tab")
        ->setInstanceSetting('required_fields', FALSE)
        ->save();
    }
    return TRUE;
  }
  return FALSE;
}
