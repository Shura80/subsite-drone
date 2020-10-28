<?php

namespace Drupal\enrd_sfr\Controller;

use EntityAPIController;
use DatabaseTransaction;

/**
 * Class EnrdSfrController.
 */
class EnrdSfrController extends EntityAPIController {

  /**
   * Implements EntityAPIControllerInterface.
   *
   * @inheritdoc
   */
  public function create(array $values = array()) {
    global $user;

    $values += array(
      'created' => REQUEST_TIME,
      'uid' => $user->uid ? $user->uid : 0,
      'status' => ENRD_SFR_STATUS_NOT_FINALIZED,
    );
    return parent::create($values);
  }

  /**
   * Implements EntityAPIControllerInterface.
   *
   * @inheritdoc
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    $return = parent::save($entity, $transaction);

    if ($entity->isAlmostFinalized()) {
      // Trigger Rules 'enrd_sfr_finalize' event.
      if (module_exists('rules')) {
        rules_invoke_event('enrd_sfr_finalize', $entity);
      }
    }

    return $return;
  }

}
