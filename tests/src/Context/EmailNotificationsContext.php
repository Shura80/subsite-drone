<?php

namespace Drupal\agri\Context;

use Drupal\DrupalExtension\Context\RawDrupalContext;

/**
 * Defines application features from the specific context.
 */
class EmailNotificationsContext extends RawDrupalContext {
  public $originalMailSystem;
  public $activeEmail;

  /**
   * Initializes context.
   */
  public function __construct() {
  }

  /**
   * Prepare environment for TestingMailSystem getting the original mail system.
   *
   * @BeforeScenario @emails
   */
  public function setupEmailCollector() {
    // Store the original system to restore after the scenario.
    $this->originalMailSystem = variable_get('mail_system', array('default-system' => 'MimeMailSystem'));
  }

  /**
   * Enable the test mail system before testing email send.
   *
   * @Given /^the test email system is enabled$/
   */
  public function theTestEmailSystemIsEnabled() {
    // Set the test system.
    variable_set('mail_system', array('default-system' => 'TestingMailSystem'));
    // Flush the email buffer,
    // allowing us to reuse this step definition to clear existing mail.
    variable_set('drupal_test_email_collector', array());
  }

  /**
   * Check the email content during test.
   *
   * @Then /^the email to "([^"]*)" should contain "([^"]*)"$/
   */
  public function theEmailToShouldContain($to, $contents) {
    // We can't use variable_get() because $conf is only fetched once per
    // scenario.
    $variables = array_map('unserialize',
      db_query("SELECT name, value FROM {variable} WHERE name = 'drupal_test_email_collector'")->fetchAllKeyed());
    $this->activeEmail = FALSE;
    foreach ($variables['drupal_test_email_collector'] as $message) {
      if ($message['to'] == $to) {
        $this->activeEmail = $message;
        if (strpos($message['body'], $contents) !== FALSE ||
          strpos($message['subject'], $contents) !== FALSE
        ) {
          return TRUE;
        }
        throw new \Exception('Did not find expected content in message body or subject.');
      }
    }
    throw new \Exception(sprintf('Did not find expected message to %s', $to));
  }

  /**
   * Clean testing email collector variable also after a scenario is finished.
   *
   * @AfterScenario @emails
   */
  public function cleanupEmailCollector() {
    variable_del('drupal_test_email_collector');
    variable_set('mail_system', $this->originalMailSystem);
  }

}
