<?php

namespace Drupal\enrd_mastermind;

use Drupal\multisite_config\ConfigBase;

/**
 * Class Config.
 *
 * @package Drupal\enrd_mastermind.
 */
class Config extends ConfigBase {

  /**
   * Disable major version management for a node type.
   *
   * @param string $node_type
   *   Content type machine name.
   */
  public function disableVersionManagement($node_type = NULL) {

    $version_management_node_types = variable_get('version_management_node_types', []);

    if ($version_management_node_types[$node_type] == $node_type) {
      $version_management_node_types[$node_type] = 0;
      variable_set('version_management_node_types', $version_management_node_types);
      watchdog('enrd_mastermind',
        'The node type %node_type has been removed from Version Management',
        ['%node_type' => $node_type]);
    }
  }

}
