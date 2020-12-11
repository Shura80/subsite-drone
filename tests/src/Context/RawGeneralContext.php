<?php

namespace Drupal\enrd\Context;

use Drupal\DrupalExtension\Context\RawDrupalContext;

/**
 * Defines application features from the specific context.
 */
class RawGeneralContext extends RawDrupalContext {
  use \Drupal\nexteuropa\Context\ContextUtil;

  /**
   * Unix-time of scenario started.
   *
   * @var int
   */
  private $startTimeScenario;

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

  /**
   * Set the unix-time scenario start.
   *
   * @BeforeScenario @api
   */
  public function setStartTimeScenario() {
    $this->startTimeScenario = time();
  }

  /**
   * Find and remove all messages created during the scenario.
   *
   * @AfterScenario @api
   */
  public function cleanupScenarioMessages() {

    if (module_exists('message')) {
      $purge_messages_type = array();

      foreach (message_type_load() as $message_type) {
        $purge_messages_type[] = $message_type->name;
      }

      if (!empty($purge_messages_type)) {
        $base_query = new \EntityFieldQuery();
        $base_query->entityCondition('entity_type', 'message', '=')
          ->propertyCondition('type', $purge_messages_type, 'IN')
          ->propertyCondition('timestamp', $this->startTimeScenario, '>')
          ->propertyOrderBy('timestamp', 'DESC')
          ->propertyOrderBy('mid', 'DESC');

        $result = $base_query->execute();

        if (isset($result['message']) && !empty($result['message'])) {
          message_delete_multiple(array_keys($result['message']));
        }
      }
    }
  }

}
