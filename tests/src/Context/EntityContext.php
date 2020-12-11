<?php

namespace Drupal\enrd\Context;

use Behat\Gherkin\Node\TableNode;

/**
 * Defines application features from the specific context.
 */
class EntityContext extends RawGeneralContext {

  private $entityCollector = [];

  /**
   * Build private array $entityCollector.
   */
  public function setEntity($entity) {
    $this->entityCollector[] = [$entity->identifier() => $entity->entityType()];
  }

  /**
   * Creates content of the given type, as in the table below.
   *
   * | title     | My entity      |
   * | field_one | My field value |
   * | ...       | ...            |
   *
   * @Given I create the following :entity_type entity of type :bundle:
   */
  public function iCreateTheFollowingEntityOfType($entity_type, TableNode $fields, $bundle = NULL) {

    $entity_fields = (object) [];
    foreach ($fields->getRowsHash() as $field => $value) {
      $entity_fields->{$field} = $value;
    }

    $this->parseEntityFields($entity_type, $entity_fields);

    try {
      $entity = entity_create($entity_type,
        ['type' => $bundle]
      );
    }
    catch (Exception $e) {
      throw new \Exception('Invalid type given: "' . $entity_type . '" is not a valid entity type.');
    }

    try {
      $this->expandEntityFields($entity_type, $entity_fields, $entity);
      $entity->save();
      $this->setEntity($entity);
    }
    catch (Exception $e) {
      throw $e;
    }
  }

  /**
   * Creates and visits content of the given type, as in the table below.
   *
   * | title     | My entity      |
   * | field_one | My field value |
   * | ...       | ...            |
   *
   * @Given I am viewing the :entity_type entity of type :bundle:
   */
  public function assertViewingEntityOfType($entity_type, TableNode $fields, $bundle = NULL) {
    $entity_fields = (object) [];
    foreach ($fields->getRowsHash() as $field => $value) {
      $entity_fields->{$field} = $value;
    }

    $this->parseEntityFields($entity_type, $entity_fields);

    try {
      $entity = entity_create($entity_type,
        ['type' => $bundle]
      );
    }
    catch (Exception $e) {
      throw new \Exception('Invalid type given: "' . $entity_type . '" is not a valid entity type.');
    }

    try {
      $this->expandEntityFields($entity_type, $entity_fields, $entity);
      $entity->save();
      $this->setEntity($entity);
    }
    catch (Exception $e) {
      throw $e;
    }

    // Set internal browser on the new entity.
    $path = $entity->uri()['path'];
    $this->getSession()
      ->visit($this->locatePath($path));
  }

  /**
   * Expands properties on the given entity object to the expected structure.
   *
   * @param string $entity_type
   *   The entity type ID.
   * @param \stdClass $entity
   *   Entity object.
   * @param object $filled_entity
   *   Filled entity object.
   */
  protected function expandEntityFields($entity_type, \stdClass $entity, $filled_entity) {
    $core = $this->getDriver()->getCore();
    $field_types = $core->getEntityFieldTypes($entity_type);
    foreach ($field_types as $field_name => $type) {
      if (isset($entity->$field_name)) {
        $filled_entity->$field_name = $core->getFieldHandler($entity, $entity_type, $field_name)
          ->expand($entity->$field_name);
      }
    }
  }

  /**
   * Clean entities created during tests once the scenario is finished.
   *
   * @AfterScenario
   */
  public function cleanupEntities() {
    if (!empty($this->entityCollector)) {
      foreach ($this->entityCollector as $type) {
        // Clean entities created during testing scenarios.
        entity_delete(reset($type), key($type));
      }
    }
  }

}
