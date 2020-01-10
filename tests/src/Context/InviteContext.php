<?php

namespace Drupal\enrd\Context;

use Drupal\DrupalExtension\Context\RawDrupalContext;

/**
 * Defines application features from the specific context.
 */
class InviteContext extends RawDrupalContext {

  private $inviteCollector = [];

  /**
   * Get private array $inviteCollector.
   *
   * @return array
   *   An array with all invite entities.
   */
  public function getInviteCollector() {
    return $this->inviteCollector;
  }

  /**
   * Set private array $inviteCollector.
   */
  public function setInviteCollector($invite) {
    $this->inviteCollector[$invite->iid] = $invite;
  }

  /**
   * Accept the last invitation through token.
   *
   * @When /^I accept the invite$/
   */
  public function iAcceptInvite() {

    $last_invite = $this->getInviteCollector();
    $reg_code = reset($last_invite)->reg_code;
    // Build accept link.
    $accept_link = '/invite/accept/' . $reg_code;
    // Visit link to accept invite.
    $this->getSession()->visit($this->locatePath($accept_link));
  }

  /**
   * Clean invite table after an accepted invite scenario is finished.
   *
   * @AfterScenario @invite
   */
  public function cleanupInviteTable() {
    $ids = [];
    $invites = $this->getInviteCollector();
    foreach ($invites as $iid => $invite) {
      $ids[] = $iid;
    }

    // Get registration code based on email to which invite has been sent to.
    if (!empty($ids)) {
      // Clean invite table from test invite id row.
      entity_delete_multiple('invite', $ids);
    }
  }

}
