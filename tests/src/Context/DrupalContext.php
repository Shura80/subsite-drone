<?php

namespace Drupal\agri\Context;

use Drupal\DrupalExtension\Context\DrupalContext as DrupalExtensionDrupalContext;

/**
 * Provides step definitions for interacting with Drupal.
 */
class DrupalContext extends DrupalExtensionDrupalContext {
  use \Drupal\nexteuropa\Context\ContextUtil;

  /**
   * Visit a node page given its type and title.
   *
   * @param string $type
   *   The node type.
   * @param string $title
   *   The node title.
   *
   * @Then I visit the :type content with title :title
   */
  public function visitContentPage($type, $title) {
    $nodes = node_load_multiple([], ['title' => $title, 'type' => $type], TRUE);
    if (!$nodes) {
      throw new \InvalidArgumentException("Node of type '{$type}' and title '{$title}' not found.");
    }
    // Get node path without any base path by setting 'base_url' and 'absolute'.
    $node = array_shift($nodes);
    $path = 'node/' . $node->nid;
    cache_clear_all($path, 'cache_path');
    drupal_static_reset('drupal_lookup_path');
    $path = url($path, ['base_url' => '', 'absolute' => TRUE]);
    // Visit newly created node page.
    $this->visitPath($path);
  }

}
