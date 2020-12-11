<?php

/**
 * @file
 * Contains \EnrdSfrPubSubContext.
 */

use Drupal\DrupalDriverManager;
use Drupal\DrupalExtension\Context\DrupalSubContextInterface;
use Drupal\DrupalExtension\Context\RawDrupalContext;

/**
 * Behat test subcontext for the ENRD environment.
 */
class EnrdSfrPubSubContext extends RawDrupalContext implements DrupalSubContextInterface {

  /**
   * {@inheritdoc}
   */
  protected $drupal;

  /**
   * Constructs an EnrdSfrPubSubContext object.
   *
   * @param \Drupal\DrupalDriverManager $drupal
   *   The Drupal driver manager.
   */
  public function __construct(DrupalDriverManager $drupal) {
    $this->drupal = $drupal;
  }

  /**
   * Helper function to call to remove enrd_sfr entities created on submissions.
   *
   * @param string $field_email
   *   The email to search for.
   * @param string $value
   *   The searched string value that should be searched in the $field_email.
   */
  private function cleanupEnrdSfrPub($field_email, $value) {
    $query = new \EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'enrd_sfr')
      ->fieldCondition($field_email, 'email', $value, 'CONTAINS')
      ->execute();

    if (isset($result['enrd_sfr'])) {
      entity_delete_multiple('enrd_sfr', array_keys($result['enrd_sfr']));
    }
  }

  /**
   * Delete enrd_sfr entities after executing their scenarios.
   *
   * @AfterScenario @sfr-pub
   */
  public function cleanupEnrdSfrPubContactCpSubmissions() {
    // Clean entities searching by value in email fields.
    $this->cleanupEnrdSfrPub('field_enrd_sfr_pub_subcp_email', 'example.com');
    $this->cleanupEnrdSfrPub('field_enrd_sfr_pub_subehd_email', 'example.com');
    $this->cleanupEnrdSfrPub('field_enrd_sfr_pub_contcp_email', 'example.com');
    $this->cleanupEnrdSfrPub('field_enrd_sfr_pub_contehd_email', 'example.com');
  }

}
