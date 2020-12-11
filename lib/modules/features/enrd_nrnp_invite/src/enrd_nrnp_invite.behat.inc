<?php

/**
 * @file
 * Contains \EnrdNrnpInviteSubContext.
 */

use Behat\Behat\Hook\Scope\BeforeScenarioScope;
use Drupal\DrupalDriverManager;
use Drupal\DrupalExtension\Context\DrupalSubContextInterface;
use Drupal\DrupalExtension\Context\RawDrupalContext;

/**
 * Class EnrdNrnpInviteSubContext.
 */
class EnrdNrnpInviteSubContext extends RawDrupalContext implements DrupalSubContextInterface {

  /**
   * {@inheritdoc}
   */
  protected $drupal;

  /**
   * Mink Context.
   *
   * @var \Drupal\enrd\Context\inviteContext
   */
  private $inviteContext;

  /**
   * Constructs an EnrdNrnpInviteSubContext object.
   *
   * @param \Drupal\DrupalDriverManager $drupal
   *   The Drupal driver manager.
   */
  public function __construct(DrupalDriverManager $drupal) {
    $this->drupal = $drupal;
  }

  /**
   * Get MinkContext.
   *
   * @BeforeScenario
   */
  public function gatherContexts(BeforeScenarioScope $scope) {
    $environment = $scope->getEnvironment();
    $this->inviteContext = $environment->getContext('Drupal\enrd\Context\InviteContext');
  }

  /**
   * Behat drupal extension test context for invitation functionality.
   *
   * @param string $email
   *   The email address.
   *
   * @When /^I retrieve the NRN invite send to "([^"]*)"$/
   *
   * @throws InvalidArgumentException
   *    Throw an exception if arguments are not defined.
   */
  public function iRetrieveNrnInvite($email) {

    $field_name = 'field_enrd_nrnp_invite_email';
    $type = 'enrd_nrnp_invite';

    // Get the id of invite sent to email parameter.
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'invite')
      ->entityCondition('bundle', $type)
      ->fieldCondition($field_name, 'email', $email, '=');

    $result = $query->execute();

    // Get registration code based on email to which invite has been sent to.
    if ($result && $result['invite']) {
      $id = reset($result['invite'])->iid;
      $invite = entity_load('invite', [$id]);
      $this->inviteContext->setInviteCollector(reset($invite));
    }
    else {
      throw new InvalidArgumentException('Email provided has not been used to invite a user.');
    }

  }

}
