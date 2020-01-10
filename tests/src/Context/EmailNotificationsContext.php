<?php

namespace Drupal\enrd\Context;

use Drupal\DrupalExtension\Context\RawDrupalContext;

/**
 * Defines application features from the specific context.
 */
class EmailNotificationsContext extends RawDrupalContext {

  public $originalMailSystem;
  public $activeEmail;
  private $mailCollector = array();

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
   * Cleanup the rules_scheduler table before testing it.
   *
   * @BeforeScenario @scheduling
   */
  public function cleanRulesSchedulerTable() {
    db_truncate('rules_scheduler')->execute();
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
   * Init property $mailCollector with system var drupal_test_email_collector.
   *
   * @Then /^I receive an email$/
   */
  public function iReceiveAnEmail() {

    $variable_name = 'drupal_test_email_collector';

    // We can't use variable_get() because $conf is only fetched once per
    // scenario.
    $variables = array_map('unserialize',
      db_query("SELECT name, value FROM {variable} WHERE name = '$variable_name'")->fetchAllKeyed());

    if (empty($variables['drupal_test_email_collector'])) {
      throw new \Exception(sprintf('no emails in %s', $variable_name));
    }

    foreach ($variables['drupal_test_email_collector'] as $message) {
      $this->mailCollector[] = $message;
    }

    variable_del('drupal_test_email_collector');
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

    // Parse $message array to search matching strings.
    foreach ($variables['drupal_test_email_collector'] as $message) {
      if ($message['to'] == $to) {
        $this->activeEmail = $message;
        // Clean body from carriage return to search in clean strings.
        $message['body'] = str_replace(array("\n", "\r"), ' ', $message['body']);
        $message['subject'] = str_replace(array("\n", "\r"), ' ', $message['subject']);
        $found_in_body = strpos($message['body'], $contents);
        $found_in_subject = strpos($message['subject'], $contents);

        // If string is found in body or subject give a positive result.
        if ($found_in_body !== FALSE || $found_in_subject !== FALSE
        ) {
          return TRUE;
        }
        // If string is not found in body or subject warn about negative result.
        else {
          throw new \Exception('Did not find expected content in message body or subject.');
        }
      }
    }
    // If recipient is not found in "to" string warn about negative result.
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

  /**
   * Get private variable $mailCollector.
   *
   * @return array
   *   An array with all sent mails.
   */
  public function getMailCollector() {
    return $this->mailCollector;
  }

}
