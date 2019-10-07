<?php

/**
 * @file
 * Contains \AgriCoreSubContext.
 */

use Drupal\DrupalDriverManager;
use Drupal\DrupalExtension\Context\DrupalSubContextInterface;
use Drupal\DrupalExtension\Context\RawDrupalContext;

/**
 * Behat test subcontext for the EIP-AGRI environment.
 */
class AgriInviteSubContext extends RawDrupalContext implements DrupalSubContextInterface {

  /**
   * {@inheritdoc}
   */
  protected $drupal;

  /**
   * Constructs an AgriCoreSubContext object.
   *
   * @param \Drupal\DrupalDriverManager $drupal
   *   The Drupal driver manager.
   */
  public function __construct(DrupalDriverManager $drupal) {
    $this->drupal = $drupal;
  }

  /**
   * Behat drupalextension test context for agri_invite module.
   *
   * @param string $email
   *   The email of the user that receive the invite.
   *
   * @When /^I accept the invitation sent to "([^"]*)" email address$/
   *
   * @throws InvalidArgumentException
   *    Thros an exception if argument is not defined.
   */
  public function iAcceptEmailInvitation($email) {
    // Get the id of invite sent to email parameter.
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'invite')
      ->entityCondition('bundle', 'agri_invite')
      ->fieldCondition('field_invitation_email', 'email', $email, '=');
    $result = $query->execute();

    // Get registration code based on email to which invite has been sent to.
    if ($result && $result['invite']) {
      $id = reset($result['invite'])->iid;
      $invite = entity_load('invite', [$id]);
      $reg_code = reset($invite)->reg_code;
      // Build agri_invite accept link.
      $accept_link = '/invite/accept/' . $reg_code;
      // Visit link to accept invite.
      $this->getSession()->visit($this->locatePath($accept_link));
    }
    else {
      throw new InvalidArgumentException('Email provided has not been used to invite a user.');
    }

  }

  /**
   * Clean invite table after an accepted invite scenario is finished.
   *
   * @AfterScenario @invite-accepted
   */
  public function cleanupInviteTable() {

    $email = 'bdd-user-invitee@example.com';

    // Get the iid of invite sent to email parameter.
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'invite')
      ->entityCondition('bundle', 'agri_invite')
      ->fieldCondition('field_invitation_email', 'email', $email, '=');

    $result = $query->execute();

    // Get registration code based on email to which invite has been sent to.
    if ($result['invite']) {
      // Clean invite table from test invite id row.
      entity_delete_multiple('invite', array_keys($result['invite']));
    }
  }

}
