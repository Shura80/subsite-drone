<?php

namespace Drupal\enrd\Context;

/**
 * Defines application features from the specific context.
 */
class SolrContext extends RawGeneralContext {

  private $environment;

  /**
   * Check Solr environment before the indexation tests run.
   *
   * @BeforeScenario @solr
   */
  public function checkSolrEnvironment() {

    if (!module_exists('apachesolr')) {
      throw new \Exception('Apache Solr framework seems to be disabled.');
    }

    $env_id = apachesolr_default_environment();
    $environment = apachesolr_environment_load($env_id);

    // Check for availability.
    if (!apachesolr_server_status($environment['url'], $environment['service_class'])) {
      throw new \Exception('Solr server seems to be unavailable or misconfigurated.');
    }

    $this->environment = $environment;
  }

  /**
   * Send content of certain type to the Solr search index.
   *
   * @Given I send the :content_type(s) to the Solr search index
   */
  public function indexContentTypes($content_types) {

    $content_types = explode(',', $content_types);
    $content_types = array_map('trim', $content_types);

    foreach ($content_types as $content_type) {
      // Deletes the content of certain type from the index.
      $command = "solr-delete-index node:$content_type";
      $this->getDriver('drush')->$command();
      // Marks the content of certain type for reindexing.
      $command = "solr-mark-all node:$content_type";
      $this->getDriver('drush')->$command();
    }
    // Reindexes contents just marked.
    $command = "solr-index";
    $this->getDriver('drush')->$command();

    // Waits for Apache Solr server to finish indexing.
    $this->waitForSolrIndex();
  }

  /**
   * Send published content to the Solr search index.
   *
   * @Given I send site contents to the Solr search index
   */
  public function indexSiteContents() {
    // Deletes the content of certain type from the index.
    $command = "solr-delete-index";
    $this->getDriver('drush')->$command();

    // Marks the content of certain type for reindexing.
    $command = "solr-mark-all";
    $this->getDriver('drush')->$command();

    // Reindexes contents just marked.
    $command = "solr-index";
    $this->getDriver('drush')->$command();

    // Waits for Apache Solr server to finish indexing.
    $this->waitForSolrIndex();
  }

  /**
   * Check if Solr Server is still receiving or indexing documents.
   *
   * @return bool
   *   TRUE if server is still indexing.
   *
   * @throws \Exception
   */
  private function solrIsStillIndexing() {
    $environment = $this->environment;

    try {
      $solr = apachesolr_get_solr($environment['env_id']);
      $solr->clearCache();
      $data = $solr->getLuke();

      module_load_include('inc', 'apachesolr', 'apachesolr.index');
      $status = apachesolr_index_status($environment['env_id']);

      return ($status['total'] != 0 && $status['remaining'] == 0 && $data->index->numDocs < $status['total']);
    }
    catch (Exception $e) {
      throw new \Exception('Error retriving pending docs.');
    }

  }

  /**
   * Wait Solr server ends indexing.
   *
   * @throws \Exception
   */
  private function waitForSolrIndex() {
    do {
      sleep(5);
    } while ($this->solrIsStillIndexing());
    sleep(5);
  }

}
