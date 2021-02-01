<?php

namespace Drupal\enrd\Context;

use Behat\Mink\Exception\ExpectationException;
use Drupal\DrupalExtension\Context\RawDrupalContext;
use Drupal\nexteuropa\Context\MinkContext as DrupalExtensionMinkContext;
use Behat\Behat\Hook\Scope\BeforeScenarioScope;
use InvalidArgumentException;

/**
 * Defines application features from the specific context.
 */
class FormContext extends RawDrupalContext {

  /**
   * Mink Context.
   *
   * @var \Drupal\DrupalExtension\Context\MinkContext
   */
  private $minkContext;

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
   * Removes the honeypot limit of 5 seconds in the forms.
   *
   * @BeforeScenario
   */
  public function removeHoneypotTimeLimit() {
    variable_set('honeypot_time_limit', 0);
  }

  /**
   * Resets the default limit value in honeypot of 5 seconds.
   *
   * @AfterScenario
   */
  public function resetHoneypotTimeLimit() {
    variable_set('honeypot_time_limit', 5);
  }

  /**
   * Select value from autocomplete pop-up field.
   *
   * @When I fill in the autocomplete :autocomplete with :text and click :popup
   *
   * @throws \Behat\Mink\Exception\ExpectationException
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

    $popup_element = $autocomplete->find('xpath', "//div[contains(string(), '{$popup}')]");

    if (empty($popup_element)) {
      throw new ExpectationException(t('Could not find autocomplete popup text @popup', [
        '@popup' => $popup,
      ]), $this->getSession());
    }

    $popup_element->focus();
    $popup_element->click();
  }

  /**
   * Behat drupalextension test context for Chosen module.
   *
   * @When /^I set the chosen element "([^"]*)" to "([^"]*)"$/
   *
   * @throws \Behat\Mink\Exception\ExpectationException
   */
  public function iSetChosenElement($locator, $value) {
    $session = $this->getSession();
    $el = $session->getPage()->findField($locator);

    if (empty($el)) {
      throw new ExpectationException(t('No such select element @locator', [
        '@value' => $value,
        '@locator' => $locator,
      ]), $session);
    }

    $element_id = str_replace('-', '_', $el->getAttribute('id')) . '_chosen';

    $el = $session->getPage()->find('xpath', "//div[@id='{$element_id}']");

    if ($el->hasClass('chosen-container-single')) {
      // This is a single select element.
      $el = $session->getPage()
        ->find('xpath', "//div[@id='{$element_id}']/a[@class='chosen-single']");
    }
    elseif ($el->hasClass('chosen-container-multi')) {
      // This is a multi select element.
      $el = $session->getPage()
        ->find('xpath', "//div[@id='{$element_id}']/ul[@class='chosen-choices']/li[@class='search-field']/input");
    }
    $el->focus();
    $el->click();

    $selector = "//div[@id='{$element_id}']/div[@class='chosen-drop']/ul[@class='chosen-results']/li[text() = '{$value}']";
    $el = $session->getPage()->find('xpath', $selector);

    if (empty($el)) {
      throw new ExpectationException(t('No such option @value in @locator', [
        '@value' => $value,
        '@locator' => $locator,
      ]), $session);
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
