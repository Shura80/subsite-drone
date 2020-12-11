<?php

namespace Drupal\enrd_sfr\Entity;

use Entity;

/**
 * Class EnrdSfr.
 */
class EnrdSfr extends Entity {

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

      // Allow modules to apply customisations.
      module_invoke_all('enrd_sfr_finalize', $this);

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
    return t('@label: subscription #@number', array('@label' => $this->bundleLabel(), '@number' => $this->identifier()));
  }

  /**
   * Override default URI.
   *
   * @inheritdoc
   */
  protected function defaultUri() {
    return array(
      'path' => str_replace(
        '_',
        '-',
        $this->entityType() . '/' . $this->bundle() . '/' . $this->identifier()),
    );
  }

  /**
   * Get entity bundle label.
   */
  protected function bundleLabel() {
    $t = get_t();
    return $t($this->entityInfo()['bundles'][$this->bundle()]['label']);
  }

}
