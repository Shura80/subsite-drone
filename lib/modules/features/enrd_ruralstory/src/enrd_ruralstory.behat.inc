<?php

/**
 * @file
 * Contains \EnrdRuralStorySubContext.
 */

use Drupal\DrupalDriverManager;
use Drupal\DrupalExtension\Context\DrupalSubContextInterface;
use Drupal\DrupalExtension\Context\RawDrupalContext;

/**
 * Behat test subcontext for the ENRD environment.
 */
class EnrdRuralStorySubContext extends RawDrupalContext implements DrupalSubContextInterface {

  /**
   * {@inheritdoc}
   */
  protected $drupal;

  /**
   * Constructs an EnrdRuralStorySubContext object.
   *
   * @param \Drupal\DrupalDriverManager $drupal
   *   The Drupal driver manager.
   */
  public function __construct(DrupalDriverManager $drupal) {
    $this->drupal = $drupal;
  }

  /**
   * Remove enrd_sfr entities created on ruralstory form submissions.
   *
   * @AfterScenario @enrd-ruralstory-form
   */
  public function cleanupEnrdRuralStorySubmissions() {
    $query = new \EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'enrd_sfr')
      ->propertyCondition('type', 'enrd_ruralstory')
      ->fieldCondition('field_enrd_ruralstory_subject', 'value', 'BDD', 'STARTS_WITH')
      ->execute();
    if (isset($result['enrd_sfr'])) {
      entity_delete_multiple('enrd_sfr', array_keys($result['enrd_sfr']));
    }
  }

}
