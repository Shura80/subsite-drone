<?php

namespace Drupal\enrd_sfr\Controller;

/**
 * UI controller for ENRD Sfr Type.
 */
class EnrdSfrTypeUIController extends \EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = 'Manage ENRD Sfr types.';
    return $items;
  }

}
