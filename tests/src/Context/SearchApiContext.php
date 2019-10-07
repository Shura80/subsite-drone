<?php

namespace Drupal\agri\Context;

/**
 * Defines application features from the specific context.
 */
class SearchApiContext extends RawGeneralContext {

  /**
   * Prepare environment for Search API node indexing.
   *
   * @BeforeScenario @search_api_node
   */
  public function prepareSearchApiNodeIndex() {
    // Clear node index.
    $command = "search-api-clear core_node_index";
    $this->getDriver('drush')->$command();

    // Reindex all data before reindex test nodes.
    $this->indexCoreNodeIndex();
  }

  /**
   * Prepare environment for Search API people indexing.
   *
   * @BeforeScenario @search_api_user
   */
  public function prepareSearchApiPeopleIndex() {

    // Clear people index.
    $command = "search-api-clear core_people_index";
    $this->getDriver('drush')->$command();

    // Reindex all data before reindex test users.
    $this->indexCorePeopleIndex();
  }

  /**
   * Send published content to the Search API node index.
   *
   * @Given I send site contents to the Search API node index
   */
  public function indexCoreNodeIndex() {
    $command = "search-api-index core_node_index";
    $this->getDriver('drush')->$command();
  }

  /**
   * Send user content to the Search API people index.
   *
   * @Given I send user contents to the Search API people index
   */
  public function indexCorePeopleIndex() {
    $command = "search-api-index core_people_index";
    $this->getDriver('drush')->$command();
  }

}
