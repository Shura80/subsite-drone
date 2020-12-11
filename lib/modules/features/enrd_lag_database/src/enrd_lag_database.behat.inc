<?php

/**
 * @file
 * Contains \EnrdLagDatabaseSubContext.
 */

use Drupal\DrupalDriverManager;
use Drupal\DrupalExtension\Context\DrupalSubContextInterface;
use Drupal\DrupalExtension\Context\RawDrupalContext;

/**
 * Behat test subcontext for the ENRD environment.
 */
class EnrdLagDatabaseSubContext extends RawDrupalContext implements DrupalSubContextInterface {

  /**
   * {@inheritdoc}
   */
  protected $drupal;

  /**
   * Constructs an EnrdLagDatabaseSubContext object.
   *
   * @param \Drupal\DrupalDriverManager $drupal
   *   The Drupal driver manager.
   */
  public function __construct(DrupalDriverManager $drupal) {
    $this->drupal = $drupal;
  }

  /**
   * Remove nodes created through feeds import.
   *
   * @AfterScenario @feeds
   */
  public function cleanupFeedNodes() {
    $query = new \EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'node')
      ->propertyCondition('title', 'BDD', 'STARTS_WITH')
      ->execute();
    if (isset($result['node'])) {
      $nids = array_keys($result['node']);
      foreach ($nids as $nid) {
        entity_delete('node', $nid);
      }
    }
  }

}
