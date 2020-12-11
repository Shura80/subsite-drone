<?php

/**
 * @file
 * Contains \EnrdEVFSubContext.
 */

use Drupal\DrupalDriverManager;
use Drupal\DrupalExtension\Context\DrupalSubContextInterface;
use Drupal\DrupalExtension\Context\RawDrupalContext;
use Behat\Behat\Hook\Scope\BeforeScenarioScope;

/**
 * Behat test subcontext for the ENRD Email Validate Field.
 */
class EnrdEVFSubContext extends RawDrupalContext implements DrupalSubContextInterface {

  /**
   * {@inheritdoc}
   */
  protected $drupal;

  /**
   * Email notifications Context.
   *
   * @var \Drupal\enrd\Context\EmailNotificationsContext
   */
  private $emailNotificationsContext;

  /**
   * Constructs an EnrdEVFSubContext object.
   *
   * @param \Drupal\DrupalDriverManager $drupal
   *   The Drupal driver manager.
   */
  public function __construct(DrupalDriverManager $drupal) {
    $this->drupal = $drupal;
  }

  /**
   * Get EmailNotificationsContext.
   *
   * @BeforeScenario
   */
  public function gatherContexts(BeforeScenarioScope $scope) {
    $environment = $scope->getEnvironment();
    $this->emailNotificationsContext = $environment->getContext('Drupal\enrd\Context\EmailNotificationsContext');
  }

  /**
   * Confirm the email address through token link.
   *
   * @param string $email_address
   *   The email address to validate.
   *
   * @Then I confirm the :email_address through token link
   *
   * @throws \Exception
   */
  public function confirmEmailWithTokenLink($email_address) {

    $mail_collector = $this->emailNotificationsContext->getMailCollector();

    foreach ($mail_collector as $message) {
      if ($message['to'] == $email_address) {

        $pattern = "/\b(?:(?:https?):\/\/|www\.)[-a-z0-9+&@#\/%?=~_|!:,.;]*[-a-z0-9+&@#\/%=~_|]/i";
        preg_match_all($pattern, $message['body'], $matches, PREG_PATTERN_ORDER);
        foreach ($matches as $match) {
          $page_callback = reset($match);
          $this->getSession()->visit($page_callback);
        }
      }
      else {
        throw new \Exception(sprintf('Did not find expected message to %s', $email_address));
      }
    }
  }

}
