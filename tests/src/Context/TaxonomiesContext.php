<?php

namespace Drupal\enrd\Context;

use Drupal\DrupalExtension\Context\RawDrupalContext;

/**
 * Defines application features from the specific context.
 */
class TaxonomiesContext extends RawDrupalContext {

  /**
   * Initializes context.
   */
  public function __construct() {
  }

  /**
   * {@inheritdoc}
   */
  public function getSession($name = NULL) {
    $session = $this->getMink()->getSession($name);
    $selector = $session->getSelectorsHandler()->getSelector('named_exact');

    // Create custom Xpath to identify hierarchical selects.
    $xpath = ".//label[contains(normalize-space(string(.)), %locator%)]//ancestor-or-self::*[contains(@class,'field-widget-taxonomy-shs')]//select[contains(@class,'shs-select')]";
    $selector->registerNamedXpath('hselect', $xpath);

    $xpath = ".//label[contains(normalize-space(string(.)), %locator%)]//ancestor-or-self::*[contains(@class,'field-widget-taxonomy-shs')]//select[contains(@class,'shs-enable')]";
    $selector->registerNamedXpath('active_hselect', $xpath);

    return $session;
  }

  /**
   * Visits the content add page for the content type.
   *
   * @Given I am on content add :content_type
   *
   * @When I go to content add :content_type
   */
  public function pageNodeAdd($content_type) {
    $this->visitPath("/node/add/$content_type");

    $this->getSession()->getDriver()->evaluateScript(
      "jQuery('#admin-menu').hide();"
    );
  }

  /**
   * Selects option in select field with specified id|name|label|value.
   *
   * @When /^(?:|I )select "(?P<option>(?:[^"]|\\")*)" from hierarchical select "(?P<select>(?:[^"]|\\")*)"$/
   */
  public function selectHsOption($select, $option) {

    $page = $this->getSession()->getPage();
    $field = $page->find('named_exact', array('hselect', $select));

    if (NULL === $field) {
      throw new \Exception(sprintf('The select "%s" was not found in the page %s', $select, $this->getSession()->getCurrentUrl()));
    }

    $field->selectOption($option, FALSE);
  }

  /**
   * Check the selected option into a select field.
   *
   * @Then /^the option "([^"]*)" from (hierarchical select|select) "([^"]*)" is selected$/
   */
  public function theOptionFromSelectIsSelected($option, $select_type, $select) {

    // Different selectors for select and hierarchical select.
    $selector = ($select_type == 'hierarchical select') ? 'active_hselect' : 'select';

    $select_field = $this->getSession()->getPage()->find('named_exact', array($selector, $select));

    if (NULL === $select_field) {
      throw new \Exception(sprintf('The select "%s" was not found in the page %s', $select, $this->getSession()->getCurrentUrl()));
    }

    $option_field = $select_field->find('xpath', ".//option[@selected='selected']");
    if (NULL === $option_field) {
      throw new \Exception(sprintf('No option is selected in the %s select in the page %s', $select, $this->getSession()->getCurrentUrl()));
    }

    // Strange difference with or without javascript.
    $selected_value = trim(strip_tags($option_field->getHtml()));

    if ($selected_value !== $option) {
      throw new \Exception(sprintf('The option "%s" was not selected in the page %s, %s was selected', $option, $this->getSession()->getCurrentUrl(), $selected_value));
    }
  }

}
