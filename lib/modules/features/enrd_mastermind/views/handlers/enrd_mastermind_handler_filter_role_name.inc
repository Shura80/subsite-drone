<?php

/**
 * @file
 * Definition of enrd_mastermind_handler_filter_role_name.
 */

/**
 * Class to add "Role name" as filter.
 */
class enrd_mastermind_handler_filter_role_name extends views_handler_filter_many_to_one {

  /**
   * {@inheritdoc}
   */
  public function get_value_options() {

    $roles = user_roles(TRUE);
    unset($roles[DRUPAL_AUTHENTICATED_RID]);
    foreach ($roles as $role) {
      $this->value_options[$role] = $role;
    }
  }

  /**
   * Override empty and not empty operator labels to be clearer for user roles.
   */
  public function operators() {
    $operators = parent::operators();
    $operators['empty']['title'] = t("Only has the 'authenticated user' role");
    $operators['not empty']['title'] = t("Has roles in addition to 'authenticated user'");
    return $operators;
  }

}
