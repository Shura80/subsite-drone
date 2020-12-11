<?php

namespace Drupal\enrd\Context;

use Behat\Gherkin\Node\TableNode;
use EntityFieldQuery;
use Exception;

/**
 * Defines application features from the specific context.
 */
class GeneralContext extends RawGeneralContext {

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
      throw new Exception('The content type is not under moderation.');
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
    $query = new EntityFieldQuery();
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
      throw new Exception('The node was not found.');
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
   * I am on the content creation page.
   *
   * @Given I am creating a(n) :type( content)
   */
  public function iCreateContent($type) {
    $this->getSession()->visit($this->locatePath('/node/add/' . $type));
    $this->getSession()->wait(3000);
  }

  /**
   * Waiting for 1 second.
   *
   * @Then /^I wait for "([^"]*)" second(s)$/
   */
  public function iWaitFor($seconds) {
    $this->getSession()->wait(1000 * (int) $seconds);
  }

  /**
   * Visit a web form page searching by name.
   *
   * @Given I visit the :title web( )form
   */
  public function assertViewingWebform($title) {
    $query = new EntityFieldQuery();
    $entities = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'webform')
      ->propertyCondition('title', $title)
      ->range(0, 1)
      ->execute();

    if (!empty($entities['node'])) {
      $this->getSession()->visit($this->locatePath('/node/' . reset($entities['node'])->nid));
    }
    else {
      throw new Exception("The webform doesn't exist.");
    }
  }

}
