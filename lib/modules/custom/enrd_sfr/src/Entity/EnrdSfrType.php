<?php

namespace Drupal\enrd_sfr\Entity;

/**
 * ENRD Sfr Type class.
 */
class EnrdSfrType extends \Entity {
  public $name;
  public $label;
  public $description;
  public $weight = 0;

  /**
   * Creates a new ENRD Sfr Type entity.
   *
   * @inheritdoc
   *
   * @see entity_create()
   */
  public function __construct($values = array()) {
    parent::__construct($values, 'enrd_sfr_type');
  }

}
