<?php

/**
 * @file
 * Definition of enrd_mastermind_handler_filter_alias.
 */

/**
 * Class to add content "Alias" as Exposed filter.
 */
class enrd_mastermind_handler_filter_alias extends views_handler_filter_string {

  /**
   * Query on the alias string.
   */
  public function query() {
    $this->ensure_my_table();
    $field = $this->table_alias . ".nid";

    $nids = $this->getNidsByAliasString($this->value);

    $this->query->add_where($this->options['group'], $field, $nids, 'IN');
  }

  /**
   * Apply the "LIKE" queries to fetch the aliases of nodes only.
   */
  public function getNidsByAliasString($aliasString) {
    $result = db_select('url_alias')
      ->condition('alias', '%' . $aliasString . '%', 'LIKE')
      ->condition('source', 'node/%', 'LIKE')
      ->fields('url_alias')
      ->execute();

    $nids = array();
    foreach ($result as $data) {
      $source_array = explode("/", $data->source);
      array_push($nids, end($source_array));
    }
    return $nids;
  }

  /**
   * Enables the "Contains" query operator when searching for a string.
   */
  public function operators() {
    $operators = array(
      'contains' => array(
        'title' => t('Contains'),
        'short' => t('contains'),
        'method' => 'op_contains',
        'values' => 1,
      ),
    );
    return $operators;
  }

}
