<?php

namespace Drupal\enrd_sfr\Entity;

/**
 * Class EnrdSfr.
 */
class EnrdSfr extends \Entity {

  protected $isAlmostFinalized = FALSE;

  /**
   * Creates a new ENRD Sfr entity.
   *
   * @inheritdoc
   *
   * @see entity_create()
   */
  public function __construct($values = array()) {
    parent::__construct($values, 'enrd_sfr');
  }

  /**
   * Finalize the Submission request.
   *
   * @param bool $save_entity
   *   If TRUE save the entity during finalizing.
   */
  public function finalize($save_entity = FALSE) {
    // Check that the request is not finalized.
    if (!$this->isFinalized()) {
      $this->isAlmostFinalized = TRUE;
      // Set "finalized" property to current timestamp.
      $this->finalized = REQUEST_TIME;
      // Change "status" property to 1.
      $this->status = ENRD_SFR_STATUS_FINALIZED;
      // Show general confirmation message.
      drupal_set_message(t('Your submission request has been forwarded correctly.'), 'modal');

      // If requested save ENRD Sfr Entity.
      if ($save_entity) {
        $this->save();
      }
    }
  }

  /**
   * Check if the Submission request is finalized.
   *
   * @return bool
   *   Return true if the submission is finalized.
   */
  public function isFinalized() {
    return $this->status === ENRD_SFR_STATUS_FINALIZED;
  }

  /**
   * Check if the Submission request is almost finalized.
   *
   * @return bool
   *   Return true if the submission finalizing is ongoing.
   */
  public function isAlmostFinalized() {
    return $this->isAlmostFinalized;
  }

  /**
   * Override default entity label.
   *
   * @inheritdoc
   */
  protected function defaultLabel() {
    return t('Subscription #@number', array('@number' => $this->identifier()));
  }

}
