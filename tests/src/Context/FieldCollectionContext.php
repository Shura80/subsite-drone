<?php

namespace Drupal\enrd\Context;

use Behat\Gherkin\Node\TableNode;
use Drupal\DrupalExtension\Hook\Scope\AfterNodeCreateScope;

/**
 * Defines application features from the specific context.
 */
class FieldCollectionContext extends RawGeneralContext {

  private $entityCreated = [];

  /**
   * Retrieve last created node.
   *
   * @afterNodeCreate
   */
  public static function afterNodeCreate(AfterNodeCreateScope $scope) {
    if (!$node = $scope->getEntity()) {
      throw new \Exception('Failed to find a node in @afterNodeCreate hook.');
    }

    $context = $scope->getEnvironment()->getContext(__CLASS__);
    $context->setLastEntityCreated('node', $node);
  }

  /**
   * Setter function for the last entity created.
   *
   * @param string $entity_type
   *   Entity Type.
   * @param object $entity
   *   An entity already saved.
   *
   * @throws \EntityMalformedException
   */
  public function setLastEntityCreated($entity_type, $entity) {
    $this->entityCreated[$entity_type][] = $entity;
  }

  /**
   * Setter function for the last entity created.
   *
   * @param string $entity_type
   *   Entity Type.
   *
   * @return mixed
   *   FALSE or an Entity Object.
   *
   * @throws \Exception
   */
  public function getLastEntityCreated($entity_type) {
    if (isset($this->entityCreated[$entity_type])) {
      return end($this->entityCreated[$entity_type]);
    }
    else {
      throw new \Exception('There are no ' . $entity_type . ' entities to associate the field collection.');
    }
  }

  /**
   * Creates a field collection relative to the last node created.
   *
   * @Given /^I create the following "([^"]*)" field collection$/
   */
  public function iCreateTheFollowingFieldCollection($label, TableNode $fields) {

    $host_entity_type = 'node';
    $entity_type = 'field_collection_item';

    // Get the last created node during tests.
    $host_entity = $this->getLastEntityCreated($host_entity_type);

    $entity = (object) array();
    foreach ($fields->getRowsHash() as $field => $value) {
      $entity->{$field} = $value;
    }

    $this->parseEntityFields($entity_type, $entity);

    try {
      $field_collection = entity_create($entity_type,
        array('field_name' => $label)
      );
    }
    catch (Exception $e) {
      throw new \Exception('Invalid field name given: "' . $label . '" is not a Field Collection.');
    }

    try {
      $field_collection->setHostEntity($host_entity_type, $host_entity);
      $this->expandEntityFields($entity_type, $entity, $field_collection);
      $field_collection->save();
    }
    catch (Exception $e) {
      throw $e;
    }

    // Set internal browser on the node.
    $this->getSession()->visit($this->locatePath('/node/' . $host_entity->nid));

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

}
