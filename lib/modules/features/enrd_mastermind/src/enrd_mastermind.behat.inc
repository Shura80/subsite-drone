<?php

/**
 * @file
 * Contains \EnrdMastermindSubContext.
 */

use Drupal\DrupalDriverManager;
use Drupal\DrupalExtension\Context\DrupalSubContextInterface;
use Drupal\nexteuropa\Context\MinkContext as DrupalExtensionMinkContext;
use Drupal\DrupalExtension\Context\RawDrupalContext;
use Behat\Behat\Hook\Scope\BeforeScenarioScope;

/**
 * Behat test subcontext for the ENRD environment.
 */
class EnrdMastermindSubContext extends RawDrupalContext implements DrupalSubContextInterface {

  public $lastUpdateInfoSkipPaths;

  /**
   * {@inheritdoc}
   */
  protected $drupal;

  /**
   * Mink Context.
   *
   * @var \Drupal\DrupalExtension\Context\MinkContext
   */
  private $minkContext;

  /**
   * Constructs an EnrdMastermindSubContext object.
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
    $this->minkContext = $environment->getContext(DrupalExtensionMinkContext::class);
  }

  /**
   * Prepare environment to test last update info, getting skip paths variable.
   *
   * @BeforeScenario @last-update-info
   */
  public function getLastUpdateInfoSkipPaths() {
    // Store the original variable to restore after the scenario.
    $this->lastUpdateInfoSkipPaths = variable_get('enrd_lastupdate_custom_skipped_paths');
  }

  /**
   * Clean last update info skip paths variable after scenario is finished.
   *
   * @AfterScenario @last-update-info
   */
  public function cleanLastUpdateInfoSkipPaths() {
    if (!empty($this->lastUpdateInfoSkipPaths)) {
      variable_set('enrd_lastupdate_custom_skipped_paths', $this->lastUpdateInfoSkipPaths);
    }
    else {
      variable_del('enrd_lastupdate_custom_skipped_paths');
    }
  }

}
