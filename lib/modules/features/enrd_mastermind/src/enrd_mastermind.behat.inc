<?php

/**
 * @file
 * Contains \EnrdMastermindSubContext.
 */

use Drupal\DrupalDriverManager;
use Drupal\DrupalExtension\Context\DrupalSubContextInterface;
use Drupal\nexteuropa\Context\MinkContext as DrupalExtensionMinkContext;
use Drupal\DrupalExtension\Context\RawDrupalContext;
use Behat\Mink\Exception\ExpectationException;
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

  /**
   * Select value from autocomplete pop-up field.
   *
   * @When I fill in the autocomplete :autocomplete with :text and click :popup
   */
  public function fillInDrupalAutocomplete($autocomplete, $text, $popup) {
    $element = $this->getSession()->getPage()->findField($autocomplete);
    $element->focus();

    // Set the autocomplete text then put a space at the end which triggers
    // the JS to go do the autocomplete values.
    $element->setValue($text);
    $element->keyUp(' ');

    sleep(2);
    $this->minkContext->iWaitForAjaxToFinish();

    // Get Drupal autocomplete element by id.
    $autocomplete = $this->getSession()->getPage()->findById('autocomplete');

    if (empty($autocomplete)) {
      throw new ExpectationException(t('Could not find the autocomplete popup box'), $this->getSession());
    }

    $popup_element = $autocomplete->find('xpath', "//div[text() = '{$popup}']");

    if (empty($popup_element)) {
      throw new ExpectationException(t('Could not find autocomplete popup text @popup', array(
        '@popup' => $popup,
      )), $this->getSession());
    }

    $popup_element->focus();
    $popup_element->click();
  }

  /**
   * Behat drupalextension test context for Chosen module.
   *
   * @When /^I set the chosen element "([^"]*)" to "([^"]*)"$/
   */
  public function iSetChosenElement($locator, $value) {
    $session = $this->getSession();
    $el = $session->getPage()->findField($locator);

    if (empty($el)) {
      throw new ExpectationException(t('No such select element @locator', array(
        '@value' => $value,
        '@locator' => $locator,
      )), $session);
    }

    $element_id = str_replace('-', '_', $el->getAttribute('id')) . '_chosen';

    $el = $session->getPage()->find('xpath', "//div[@id='{$element_id}']");

    if ($el->hasClass('chosen-container-single')) {
      // This is a single select element.
      $el = $session->getPage()->find('xpath', "//div[@id='{$element_id}']/a[@class='chosen-single']");
    }
    elseif ($el->hasClass('chosen-container-multi')) {
      // This is a multi select element.
      $el = $session->getPage()->find('xpath', "//div[@id='{$element_id}']/ul[@class='chosen-choices']/li[@class='search-field']/input");
    }
    $el->focus();
    $el->click();

    $selector = "//div[@id='{$element_id}']/div[@class='chosen-drop']/ul[@class='chosen-results']/li[text() = '{$value}']";
    $el = $session->getPage()->find('xpath', $selector);

    if (empty($el)) {
      throw new ExpectationException(t('No such option @value in @locator', array(
        '@value' => $value,
        '@locator' => $locator,
      )), $session);
    }

    $el->focus();
    $el->click();
  }

  /**
   * Behat drupalextension to hover over a CSS selector.
   *
   * @When /^I hover over the element "([^"]*)"$/
   */
  public function iHoverOverTheElement($locator) {
    $session = $this->getSession();
    // Run the actual query and return the element.
    $element = $session->getPage()->find('css', $locator);

    if (NULL === $element) {
      throw new InvalidArgumentException(sprintf('Could not evaluate CSS selector: "%s"', $locator));
    }

    // Hover over the element.
    $element->mouseOver();
  }

}
