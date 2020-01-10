<?php

namespace Drupal\enrd\Context;

use Behat\Gherkin\Node\TableNode;

/**
 * Defines application features from the specific context.
 */
class CommunityContext extends RawGeneralContext {

  /**
   * Creates content of the given type, provided in the form.
   *
   * | title     | My node        |
   * | Field One | My field value |
   * | author    | Joe Editor     |
   * | status    | 1              |
   * | ...       | ...            |
   *
   * @Given I am viewing a(n) :type( content) in the :community group:
   */
  public function assertViewingNodeOg($type, TableNode $fields, $community) {

    // Get the currently logged in user.
    if (!($user = $this->getUserManager()->getCurrentUser())) {
      throw new \Exception('Cannot assign anonymous user to a group.');
    }

    $node = (object) array(
      'type' => $type,
      'status' => 1,
      'uid' => 0,
      'og_group_ref' => $community,
    );
    foreach ($fields->getRowsHash() as $field => $value) {
      $node->{$field} = $value;
    }

    if (isset($user)) {
      $node->uid = $user->uid;
    }

    $saved = $this->nodeCreate($node);

    // Set internal browser on the node.
    $this->getSession()->visit($this->locatePath('/node/' . $saved->nid));
  }

  /**
   * Subscribes user to group with given status and grants the given OG role.
   *
   * @param string $role
   *   The OG role to grant to the user.
   * @param string $group
   *   The group to subscribe the user to.
   * @param string $state
   *   The user status in the group assigned: can be active, pending, blocked.
   *
   * @throws \InvalidArgumentException
   *   Thrown when the group doesn't exist, when multiple groups have the given
   *   group name, or when the given role doesn't exist in the given group.
   * @throws \Exception
   *   Thrown when an anonymous user is attempted to be subscribed to a group.
   *
   * @Given I have the :role role in :state status in the :group group
   */
  public function assignUserToGroupRoleWithStatus($role, $group, $state) {

    // Discover the groups with the given name.
    $groups = $this->getGroupsByName($group);

    // Use different membership status if needed.
    switch ($state) {
      case 'pending':
        $group_status = OG_STATE_PENDING;
        break;

      case 'blocked':
        $group_status = OG_STATE_BLOCKED;
        break;
    }

    // Check that we only have one group to rule them all.
    $count = array_sum(array_map('count', $groups));
    if ($count == 0) {
      throw new \InvalidArgumentException("No such group '$group'.");
    }
    if ($count > 1) {
      throw new \InvalidArgumentException("Multiple groups with the name '$group' exist.");
    }

    // We only have one group. Retrieve it from the $groups array.
    $entity_type = key($groups);
    $group = reset($groups[$entity_type]);

    // Get the available roles for this group.
    list($entity_id, , $bundle) = entity_extract_ids($entity_type, $group);
    $roles = og_roles($entity_type, $bundle, $entity_id);

    // Check that the given role exists in the group.
    $rid = array_search($role, $roles);
    if ($rid === FALSE) {
      throw new \InvalidArgumentException("The '$group' group does not have a '$role' role.");
    }

    // Get the currently logged in user.
    if (!($user = $this->getUserManager()->getCurrentUser())) {
      throw new \Exception('Cannot assign anonymous user to a group.');
    }

    // Subscribe the user to the group.
    og_group($entity_type, $entity_id, array('entity' => $user, 'state' => $group_status));

    // Grant the OG role to the user.
    og_role_grant($entity_type, $entity_id, $user->uid, $rid);
  }

  /**
   * Returns a list of OG groups with the given name across all entities.
   *
   * @param string $name
   *   The name of the groups to return.
   *
   * @return array
   *   An associative array, keyed by entity type, each value an indexed array
   *   of groups with the given name.
   */
  public function getGroupsByName($name) {
    $groups = array();

    foreach (og_get_all_group_bundle() as $entity_type => $bundles) {
      $entity_info = entity_get_info($entity_type);
      $query = new \EntityFieldQuery();
      $result = $query
        ->entityCondition('entity_type', $entity_type)
        ->entityCondition('bundle', array_keys($bundles), 'IN')
        ->fieldCondition(OG_GROUP_FIELD, 'value', 1, '=')
        ->propertyCondition($entity_info['entity keys']['label'], $name)
        // Make sure we can retrieve the data even if we are an anonymous user.
        ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT')
        ->execute();

      if (!empty($result[$entity_type])) {
        $groups[$entity_type] = entity_load($entity_type, array_keys($result[$entity_type]));
      }
    }

    return $groups;
  }

}
