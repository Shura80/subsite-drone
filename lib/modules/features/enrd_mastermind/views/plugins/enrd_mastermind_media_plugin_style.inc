<?php

/**
 * @file
 * Definition of enrd_mastermind_media_plugin_style.
 */

/**
 * Class to define a style plugin handler.
 */
class enrd_mastermind_media_plugin_style extends views_plugin_style {

  /**
   * Definition.
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['wrapper_class'] = array('default' => NULL);
    return $options;
  }

  /**
   * Form.
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['wrapper_class'] = array(
      '#type' => 'textfield',
      '#title' => t('Wrapper class'),
      '#description' => t('Classes that will be added to the media-list class.'),
      '#default_value' => $this->options['wrapper_class'],
    );

  }

}
