<?php

namespace Drupal\agri\Context;

use Drupal\DrupalExtension\Context\RawDrupalContext;

/**
 * Defines application features from the specific context.
 */
class RawGeneralContext extends RawDrupalContext {
  use \Drupal\nexteuropa\Context\ContextUtil;

  /**
   * {@inheritdoc}
   */
  protected function getContext($class) {

    foreach ($this->getEnvironment()->getContexts() as $context) {
      if ($context instanceof $class) {
        return $context;
      }
    }

    return FALSE;
  }

  /**
   * Returns hook environment.
   *
   * @return InitializedContextEnvironment
   *   The Environment.
   */
  public function getEnvironment() {
    return $this->getDrupal()->getEnvironment();
  }

}
