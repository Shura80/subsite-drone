<?php

/**
 * @file
 * Contains \AgriCoreSubContext.
 */

use Drupal\DrupalDriverManager;
use Drupal\DrupalExtension\Context\DrupalSubContextInterface;
use Drupal\DrupalExtension\Context\RawDrupalContext;
use Behat\Behat\Hook\Scope\BeforeScenarioScope;
use Behat\Gherkin\Node\TableNode;

/**
 * Behat test subcontext for the EIP-AGRI environment.
 */
class AgriCoreSubContext extends RawDrupalContext implements DrupalSubContextInterface {

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
   * Constructs an AgriCoreSubContext object.
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
    $this->minkContext = $environment->getContext('Drupal\DrupalExtension\Context\MinkContext');
  }

  /**
   * Set wider resolution before scenarios.
   *
   * @BeforeScenario @javascript
   */
  public function beforeScenario() {
    $this->getSession()->getDriver()->maximizeWindow();
  }

  /**
   * Creates content of the given type, provided in the form.
   *
   * | title     | My node        |
   * | Field One | My field value |
   * | author    | Joe Editor     |
   * | status    | 1              |
   * | ...       | ...            |
   *
   * @Given I am viewing a(n) :type( content) in :state status:
   */
  public function assertViewingNodeModerate($type, TableNode $fields, $state) {
    $node = (object) array(
      'type' => $type,
    );
    foreach ($fields->getRowsHash() as $field => $value) {
      $node->{$field} = $value;
    }
    if (!workbench_moderation_node_type_moderated($type)) {
      throw new \Exception('The content type is not under moderation.');
    }
    $node->workbench_moderation_state_new = $state;
    $saved = $this->nodeCreate($node);
    // Set internal browser on the node.
    $this->getSession()->visit($this->locatePath('/node/' . $saved->nid));
  }

  /**
   * Delete node form title.
   *
   * @Given I delete a node with title :title :
   */
  public function assertDeletingNode($title) {
    $query = new \EntityFieldQuery();
    $entities = $query->entityCondition('entity_type', 'node')
      ->propertyCondition('title', $title)
      ->range(0, 1)
      ->execute();
    if (!empty($entities['node'])) {
      foreach ($entities['node'] as $node) {
        node_delete($node->nid);
      }
    }
    else {
      throw new \Exception('The node was not found.');
    }
  }

  /**
   * Asserts that a given content type cannot be edited.
   *
   * @Then I should not be able to edit a/an :type( content)
   */
  public function assertCannotEditNodeOfType($type) {
    $node = (object) array('type' => $type);
    $saved = $this->nodeCreate($node);
    // Set internal browser on the node edit page.
    $this->getSession()->visit($this->locatePath('/node/' . $saved->nid . '/edit'));
    // Test status.
    $this->assertSession()->statusCodeEquals('403');
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
      $el->click();
    }
    elseif ($el->hasClass('chosen-container-multi')) {
      // This is a multi select element.
      $el = $session->getPage()->find('xpath', "//div[@id='{$element_id}']/ul[@class='chosen-choices']/li[@class='search-field']/input");
      $el->click();
    }

    $selector = "//div[@id='{$element_id}']/div[@class='chosen-drop']/ul[@class='chosen-results']/li[text() = '{$value}']";
    $el = $session->getPage()->find('xpath', $selector);

    if (empty($el)) {
      throw new ExpectationException(t('No such option @value in @locator', array(
        '@value' => $value,
        '@locator' => $locator,
      )), $session);
    }

    $el->click();
  }

  /**
   * Clean database after scenarios tagged with @SFC.
   *
   * Remove files created by the SFC import process.
   *
   * @AfterScenario @SFC
   */
  public function cleanDatabase() {
    // Delete files.
    $file_query = new EntityFieldQuery();
    $result = $file_query->entityCondition('entity_type', 'file')
      ->propertyCondition('filename', 'sfc_test', 'STARTS_WITH')
      ->execute();
    if (isset($result['file'])) {
      $fids = array_keys($result['file']);
      foreach ($fids as $fid) {
        entity_delete('file', $fid);
      }
    }
  }

}
