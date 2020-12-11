<?php

/**
 * @file
 * Definition of enrd_mastermind_handler_field_operations.
 *
 * Views field handler. Extends VBO handler and fix a Views issue.
 * Implements the Views Form API.
 *
 * @see https://www.drupal.org/node/2856944
 * @see https://www.drupal.org/project/views/issues/1928952
 */

/**
 * Class enrd_mastermind_handler_field_operations.
 *
 * @ingroup views_field_handlers
 */
class enrd_mastermind_handler_field_operations extends views_bulk_operations_handler_field_operations {

  /**
   * Overridden to add the field for the entity id.
   */
  public function query() {
    $this->table_alias = $this->view->base_table;
    $entity_info = entity_get_info($this->entity_type);
    $this->base_field = $entity_info['entity keys']['id'];

    if (!empty($this->relationship)) {
      foreach ($this->view->relationship as $relationship) {
        if ($relationship->alias == $this->relationship) {
          $this->table_alias = $relationship->alias;
        }
      }
    }

    // Add the field if the query back-end implements an add_field() method,
    // just like the default back-end.
    if (method_exists($this->query, 'add_field')) {
      $this->field_alias = $this->query->add_field($this->table_alias, $this->base_field, '');
    }

    $this->add_additional_fields();
  }

}
