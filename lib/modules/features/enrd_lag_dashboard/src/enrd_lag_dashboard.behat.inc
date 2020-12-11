<?php

/**
 * @file
 * Contains \EnrdLagDashboardSubContext.
 */

use Drupal\DrupalDriverManager;
use Drupal\DrupalExtension\Context\DrupalSubContextInterface;
use Drupal\DrupalExtension\Context\RawDrupalContext;

/**
 * Behat test subcontext for the ENRD environment.
 */
class EnrdLagDashboardSubContext extends RawDrupalContext implements DrupalSubContextInterface {

  /**
   * {@inheritdoc}
   */
  protected $drupal;

  /**
   * Constructs an EnrdLagDashboardSubContext object.
   *
   * @param \Drupal\DrupalDriverManager $drupal
   *   The Drupal driver manager.
   */
  public function __construct(DrupalDriverManager $drupal) {
    $this->drupal = $drupal;
  }

  /**
   * Remove webform test submissions.
   *
   * @AfterScenario @contact-form
   */
  public function cleanupWebformSubmissions() {
    // Get the submissions containing the BDD placeholder used for tests.
    $query = db_select('webform_submitted_data', 'wsd');
    $query->fields('wsd', array('nid', 'sid'));
    $query->condition('data', 'BDD%', 'LIKE');
    $query->groupBy('nid');
    $query->groupBy('sid');
    $result = $query->execute()->fetchAllAssoc('sid');

    // Loop through resultset tp load every submission object.
    foreach ($result as $data) {
      $nid = $data->nid;
      $sid = $data->sid;

      // Then clean submissions and submitted_data webform tables.
      db_delete('webform_submitted_data')
        ->condition('nid', $nid)
        ->condition('sid', $sid)
        ->execute();
      db_delete('webform_submissions')
        ->condition('nid', $nid)
        ->condition('sid', $sid)
        ->execute();
    }
  }

}
