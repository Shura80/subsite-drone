<?php

namespace Drupal\enrd\Context;

use Drupal\DrupalExtension\Context\RawDrupalContext;

/**
 * Defines application features from the specific context.
 */
class EmailNotificationsContext extends RawDrupalContext {

  private $originalMailSystem;
  private $mailCollector = [];

  const DRUPAL_MAIL_COLLECTOR = 'drupal_test_email_collector';

  /**
   * Prepare environment for TestingMailSystem getting the original mail system.
   *
   * @BeforeScenario @emails
   */
  public function setupEmailCollector() {
    // Store the original system to restore after the scenario.
    $this->originalMailSystem = variable_get('mail_system', ['default-system' => 'MimeMailSystem']);

    // Set the test system.
    variable_set('mail_system', ['default-system' => 'TestingMailSystem']);
    // Flush the email buffer,
    // allowing us to reuse this step definition to clear existing mail.
    variable_set(self::DRUPAL_MAIL_COLLECTOR, []);

    $this->mailCollector = [];
  }

  /**
   * Clean testing email collector variable also after a scenario is finished.
   *
   * @AfterScenario @emails
   */
  public function cleanupEmailCollector() {
    variable_del(self::DRUPAL_MAIL_COLLECTOR);
    variable_set('mail_system', $this->originalMailSystem);

    $this->mailCollector = [];
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
   * Init property $mailCollector with system var drupal_test_email_collector.
   *
   * @Then /^I receive an email$/
   */
  public function iReceiveAnEmail() {
    if (empty($this->getMailCollector())) {
      throw new \Exception(sprintf('No emails collected'));
    }
  }

  /**
   * Check the email content during test.
   *
   * @Then /^the email to "([^"]*)" should contain "([^"]*)"$/
   */
  public function theEmailToShouldContain($to, $contents) {
    $active_email = FALSE;

    // Parse $message array to search matching strings.
    foreach ($this->getMailCollector() as $message) {
      if ($message['to'] == $to) {
        $active_email = $message;
        // Clean body from carriage return to search in clean strings.
        $message['body'] = str_replace(["\n", "\r"], ' ', $message['body']);
        $message['subject'] = str_replace(["\n", "\r"], ' ', $message['subject']);
        $found_in_body = strpos($message['body'], $contents);
        $found_in_subject = strpos($message['subject'], $contents);

        // If string is found in body or subject give a positive result.
        if ($found_in_body !== FALSE || $found_in_subject !== FALSE
        ) {
          return TRUE;
        }
      }
    }

    if ($active_email === FALSE) {
      // If string is not found in body or subject warn about negative result.
      throw new \Exception('Did not find expected content in message body or subject.');
    }
    else {
      // If recipient is not found in "to" string warn about negative result.
      throw new \Exception(sprintf('Did not find expected message to %s', $to));
    }
  }

  /**
   * Get a list of the emails collected.
   *
   * @return array
   *   An array with all sent mails.
   */
  public function getMailCollector() {
    // We can't use variable_get() because $conf is only fetched once per
    // scenario.
    $variables = array_map('unserialize',
      db_query('SELECT name, value FROM {variable} WHERE name = :value',
        [':value' => self::DRUPAL_MAIL_COLLECTOR]
      )->fetchAllKeyed());

    // Init property $mailCollector with system var drupal_test_email_collector.
    if (!empty($variables[self::DRUPAL_MAIL_COLLECTOR])) {
      foreach ($variables[self::DRUPAL_MAIL_COLLECTOR] as $message) {
        $this->mailCollector[] = $message;
      }
    }

    variable_del(self::DRUPAL_MAIL_COLLECTOR);

    return $this->mailCollector;
  }

}
