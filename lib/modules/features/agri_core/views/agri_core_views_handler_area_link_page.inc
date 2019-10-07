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
    $options['custom_text'] = array('default' => '', 'translatable' => TRUE);
    $options['custom_path'] = array('default' => '');
    $options['tokenize'] = array('default' => FALSE, 'bool' => TRUE);
    return $options;
  }

  /**
   * Form.
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    unset($form['label']);
    unset($form['empty']);

    $form['custom_text'] = array(
      '#type' => 'textfield',
      '#title' => 'Text',
      '#default_value' => $this->options['custom_text'],
      '#size' => 60,
      '#maxlength' => 128,
    );

    $form['custom_path'] = array(
      '#type' => 'textfield',
      '#title' => 'Path',
      '#default_value' => $this->options['custom_path'],
      '#size' => 60,
      '#maxlength' => 128,
    );

    $form['tokenize'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use replacement tokens from the first row'),
      '#default_value' => $this->options['tokenize'],
    );

    // Get a list of the available fields and arguments for token replacement.
    $options = array();
    foreach ($this->view->display_handler->get_handlers('field') as $field => $handler) {
      $options[t('Fields')]["[$field]"] = $handler->ui_name();
    }

    $count = 0;
    foreach ($this->view->display_handler->get_handlers('argument') as $handler) {
      $options[t('Arguments')]['%' . ++$count] = t('@argument title', array('@argument' => $handler->ui_name()));
      $options[t('Arguments')]['!' . $count] = t('@argument input', array('@argument' => $handler->ui_name()));
    }

    if (!empty($options)) {
      foreach (array_keys($options) as $type) {
        if (!empty($options[$type])) {
          $items = array();
          foreach ($options[$type] as $key => $value) {
            $items[] = $key . ' == ' . check_plain($value);
          }
          $output = theme('item_list',
            array(
              'items' => $items,
              'type' => $type,
            ));
        }
      }

      $form['token_help'] = array(
        '#type' => 'fieldset',
        '#title' => t('Replacement patterns'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
        '#value' => $output,
        '#id' => 'edit-options-token-help',
        '#dependency' => array(
          'edit-options-tokenize' => array(1),
        ),
        '#prefix' => '<div>',
        '#suffix' => '</div>',
      );
    }

  }

  /**
   * Return create a new community button.
   */
  public function render($empty = FALSE) {
    $link = drupal_get_path_alias() . '/' . $this->options['custom_path'];
    return l($this->options['custom_text'], $link);
  }

}
