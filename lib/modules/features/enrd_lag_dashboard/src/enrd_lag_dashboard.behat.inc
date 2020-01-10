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
    $result = $query->execute()->fetchAllAssoc('sid');

    module_load_include('inc', 'webform', 'includes/webform.report');

    // Loop through resultset tp load every submission object.
    foreach ($result as $data) {
      $nid = $data->nid;
      $sid = $data->sid;
      $node = entity_load_single('node', $nid);
      $submission = webform_get_submissions(array(
        'nid' => $nid,
        'sid' => $sid,
      ), NULL);
      // Then delete submission using webform API.
      webform_submission_delete($node, reset($submission));
    }
  }

}
