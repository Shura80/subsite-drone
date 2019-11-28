<?php

/**
 * @file
 * Definition of agri_core_views_handler_area_link_page.
 */

/**
 * Views area handler to display custom link to page.
 */
class agri_core_views_handler_area_link_page extends views_handler_area {

  /**
   * Definition.
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['text'] = array('default' => '', 'translatable' => TRUE);
    $options['path'] = array('default' => '');
    $options['class'] = array('default' => '');
    $options['title'] = array('default' => '');
    $options['target'] = array('default' => '');

    return $options;
  }

  /**
   * Form.
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    unset($form['label']);
    unset($form['empty']);

    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => 'Text',
      '#default_value' => $this->options['text'],
      '#size' => 60,
      '#maxlength' => 128,
    );

    $form['path'] = array(
      '#type' => 'textfield',
      '#title' => 'Path',
      '#default_value' => $this->options['path'],
      '#size' => 60,
      '#maxlength' => 128,
    );

    $form['attributes'] = array(
      '#type' => 'fieldset',
      '#title' => t('Attributes'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $form['class'] = array(
      '#type' => 'textfield',
      '#title' => t('Link CSS class'),
      '#default_value' => $this->options['class'],
      '#description' => t('A custom CSS class to add to the link'),
      '#fieldset' => 'attributes',
    );

    $form['title'] = array(
      '#type' => 'textfield',
      '#title' => t('Link title'),
      '#description' => t('Set the title attribute of the link'),
      '#default_value' => $this->options['title'],
      '#fieldset' => 'attributes',
    );

    $target_options = array(
      ''        => t('None'),
      '_blank'  => t('New window (_blank)'),
      '_parent' => '_parent',
      '_self'   => '_self',
      '_top'    => '_top',
    );

    $form['target'] = array(
      '#type' => 'select',
      '#title' => t('Link target'),
      '#description' => t('Set the target attribute of the link.'),
      '#options' => $target_options,
      '#default_value' => $this->options['target'],
      '#fieldset' => 'attributes',
    );

  }

  /**
   * Return create a new community button.
   */
  public function render($empty = FALSE) {
    if ($empty && empty($this->options['empty'])) {
      return '';
    }

    $text = $this->options['text'];
    $path = $this->options['path'];

    $link_properties = array();

    $attribute_keys = array('title', 'target', 'class');
    foreach ($attribute_keys as $property) {
      if (empty($this->options[$property])) {
        continue;
      }

      if ($property === 'class') {
        $link_properties['attributes'][$property] = explode(' ', $this->options[$property]);
        continue;
      }

      $link_properties['attributes'][$property] = $this->options[$property];
    }

    return l($text, $path, $link_properties);
  }

}
