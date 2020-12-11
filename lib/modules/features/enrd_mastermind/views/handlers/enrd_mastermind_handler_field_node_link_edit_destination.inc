<?php

/**
 * @file
 * Definition of views_handler_field_node_link_edit.
 */

/**
 * Handler that allows to optionally set destination in node edit link.
 *
 * @ingroup views_field_handlers
 */
class enrd_mastermind_handler_field_node_link_edit_destination extends views_handler_field_node_link {

  /**
   * {@inheritdoc}
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['destination'] = ['default' => TRUE, 'bool' => TRUE];

    return $options;
  }

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {

    parent::options_form($form, $form_state);

    $form['destination'] = [
      '#title' => t('Destination'),
      '#type' => 'checkbox',
      '#default_value' => $this->options['destination'],
      '#description' => t('If checked the link will have destination parameter set to current page.'),
    ];
  }

  /**
   * Renders the link.
   */
  public function render_link($node, $values) {

    // Ensure user has access to edit this node.
    if (!node_access('update', $node)) {
      return;
    }

    // Print the edit link without the destination querystring.
    $this->options['alter']['make_link'] = TRUE;
    $this->options['alter']['path'] = "node/$node->nid/edit";
    if (!empty($this->options['destination']) || !isset($this->options['destination'])) {
      $this->options['alter']['query'] = drupal_get_destination();
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    return $text;
  }

}
