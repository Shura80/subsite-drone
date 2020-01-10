<?php

/**
 * @file
 * Definition of enrd_mastermind_media_plugin_rows.
 */

/**
 * Class to define a row plugin handler.
 */
class enrd_mastermind_media_plugin_rows extends views_plugin_row {

  /**
   * Definition.
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['image_field'] = array('default' => NULL);
    $options['heading_field'] = array('default' => NULL);
    $options['abstract_field'] = array('default' => NULL);
    $options['metadata_field'] = array('default' => array());
    return $options;
  }

  /**
   * Form.
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Pre-build all of our option lists for the dials and switches that follow.
    $fields = array();
    foreach ($this->display->handler->get_handlers('field') as $field => $handler) {
      if ($label = $handler->label()) {
        $fields[$field] = $label;
      }
      else {
        $fields[$field] = $handler->ui_name();
      }
    }

    $form['image_field'] = array(
      '#type' => 'select',
      '#title' => t('Image field'),
      '#options' => array('' => t('<None>')) + $fields,
      '#default_value' => $this->options['image_field'],
      '#description' => t('Select the field that will be used as the image.'),
    );

    $form['heading_field'] = array(
      '#type' => 'select',
      '#title' => t('Heading field'),
      '#options' => array('' => t('<None>')) + $fields,
      '#default_value' => $this->options['heading_field'],
      '#description' => t('Select the field that will be used as the heading.'),
    );

    $form['abstract_field'] = array(
      '#type' => 'select',
      '#title' => t('Abstract field'),
      '#options' => array('' => t('<None>')) + $fields,
      '#default_value' => $this->options['abstract_field'],
      '#description' => t('Select the field that will be used as the abstract.'),
    );

    $form['metadata_field'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Metadata field'),
      '#options' => $fields,
      '#default_value' => $this->options['metadata_field'],
      '#description' => t('Select the field that will be used as the metadata.'),
    );

  }

}
