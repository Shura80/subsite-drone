<?php

/**
 * @file
 * Code for managing private functions used on og.
 */

/**
 * Helper function to add ESI Funds OG nodes.
 *
 * @param string $ctype
 *   The name of the content type of which nodes are being created.
 * @param string $vocab
 *   The name of the vocabulary type of which nodes are being created.
 *
 * @return object
 *   Returns the entity object just created.
 */
function _enrd_lag_database_add_esi_funds_og_nodes($ctype, $vocab) {
  // Node titles list.
  $titles = array(
    'EAFRD' => 'European Agricultural Fund for Rural Development (EAFRD)',
    'ERDF' => 'European Regional Development Fund (ERDF)',
    'ESF' => 'European Social Fund (ESF)',
    'EMFF' => 'European Maritime and Fisheries Fund (EMFF)',
  );

  $values = array(
    'type' => $ctype,
    'comment' => 0,
    'status' => 1,
  );

  foreach ($titles as $key => $title) {
    // Get the term reference with the same name as node title.
    $term = taxonomy_get_term_by_name($key, $vocab);

    $entity = entity_create('node', $values);

    // Set the values.
    $ewrapper = entity_metadata_wrapper('node', $entity);
    $ewrapper->title->set($title);
    $ewrapper->field_enrd_main_esi_fund->set(key($term));

    // Save the entity object.
    try {
      $ewrapper->save();
    }
    catch (Exception $e) {
    }
  }

  return $entity;
}

/**
 * Global workaround to set all OG permissions.
 */
function _enrd_lag_database_overrides_og_permission() {

  $content_types = array('news', 'discussion', 'event', 'document');
  $roles = array(OG_AUTHENTICATED_ROLE);
  $bundles = array(ENRD_LAG_DATABASE_LAG_GROUP_NODE, ENRD_LAG_DATABASE_ESI_FUND_GROUP_NODE);

  // Remove default community permissions.
  _enrd_mastermind_set_og_permission($content_types, $roles, $bundles);

  drupal_set_message(t("Revoked community permissions on non LAG node types."));
}

/**
 * Override default permissions for a group member.
 *
 * @param array $types
 *   Content types array to modify.
 * @param array $roles
 *   Array of roles.
 * @param array $bundles
 *   Array of og group type.
 *
 * @see og_role_revoke_permissions()
 */
function _enrd_lag_database_set_og_permission(array $types, array $roles, array $bundles) {

  $query = db_select('og_role', 'og')
    ->fields('og', array('rid'))
    ->condition('og.name', $roles, 'IN')
    ->condition('og.group_bundle', $bundles, 'IN')
    ->execute();

  $permissions = array();

  foreach ($types as $nodetype) {
    $permissions[] = 'create ' . $nodetype . ' content';
    $permissions[] = 'update own ' . $nodetype . ' content';
    $permissions[] = 'update any ' . $nodetype . ' content';
    $permissions[] = 'delete own ' . $nodetype . ' content';
    $permissions[] = 'delete any ' . $nodetype . ' content';
  }

  while ($rid = $query->fetchAssoc()) {
    og_role_revoke_permissions($rid, $permissions);
  }
}

/**
 * Helper function to set administrator role rid in LAG and RDPs.
 */
function _enrd_lag_database_set_admin_rids($bundle) {
  if ($bundle == ENRD_LAG_DATABASE_LAG_GROUP_NODE) {
    // LAGs.
    $data = db_select('og_role', 'ogr')
      ->fields('ogr', array('rid', 'name'))
      ->condition('group_bundle', $bundle)
      ->condition('name', 'administrator member')
      ->execute()->fetchAssoc();

    $rid = $data['rid'];

    variable_set('og_group_manager_default_rids_node_lag',
      array($rid => $rid)
    );

    drupal_set_message(t("Set default role on LAG Groups: %name", array('%name' => $data['name'])));
  }

  if ($bundle == ENRD_LAG_DATABASE_ESI_FUND_GROUP_NODE) {
    // ESI Funds.
    $data = db_select('og_role', 'ogr')
      ->fields('ogr', array('rid', 'name'))
      ->condition('group_bundle', $bundle)
      ->condition('name', 'administrator member')
      ->execute()->fetchAssoc();

    $rid = $data['rid'];

    variable_set('og_group_manager_default_rids_node_esi_funds_og',
      array($rid => $rid)
    );

    drupal_set_message(t("Set default role on ESI Funds Groups: %name", array('%name' => $data['name'])));
  }
}

/**
 * Helper function to check user LAG/ESI Fund OG group membership.
 *
 * @param mixed $account
 *   The account object or id.
 *
 * @return bool
 *   Return either a user is member or not of LAG group.
 */
function _enrd_lag_database_is_lag_member($account) {

  $uid = is_object($account) ? $account->uid : $account;
  if ($uid) {
    // Check for active user OG membership.
    $query = db_select('og_membership', 'ogm')
      ->fields('ogm')
      ->condition('ogm.group_type', 'node')
      ->condition('ogm.state', OG_STATE_ACTIVE)
      ->condition('entity_type', 'user')
      ->condition('etid', $uid);
    $query->join('node', 'group_node', 'ogm.gid = group_node.nid');
    // Check if membership is for LAG or ESI Fund OG node type.
    $query->condition(
      db_or()
        ->condition('group_node.type', 'lag')
        ->condition('group_node.type', 'esi_funds_og')
    );

    return (bool) $query->execute()->rowCount();
  }
  return FALSE;
}

/**
 * Helper function to assign global role to group user when giving membership.
 *
 * @param string $role_name
 *   Name of the role to assign to user.
 * @param mixed $account
 *   The user account object or user id.
 *
 * @throws \Exception
 *
 * @return bool
 *   Return either success or not of the operation performed.
 */
function _enrd_lag_database_assign_role($role_name, $account) {
  $uid = is_object($account) ? $account->uid : $account;
  $role = user_role_load_by_name($role_name);
  if ($uid && $role) {
    db_merge('users_roles')
      ->key(array('uid' => $uid, 'rid' => $role->rid))
      ->execute();

    // Clear the static loading cache.
    entity_get_controller('user')->resetCache(array($uid));
    return TRUE;
  }
  return FALSE;
}

/**
 * Helper function to revoke global role to group user when removing as member.
 *
 * @param string $role_name
 *   Name of the role to revoke from user.
 * @param mixed $account
 *   The user account object or user id.
 *
 * @throws \Exception
 *
 * @return bool
 *   Return either success or not of the operation performed.
 */
function _enrd_lag_database_revoke_role($role_name, $account) {
  $uid = is_object($account) ? $account->uid : $account;
  $role = user_role_load_by_name($role_name);
  if ($uid && $role) {
    db_delete('users_roles')
      ->condition('rid', $role->rid)
      ->condition('uid', $uid)
      ->execute();

    // Clear the static loading cache.
    entity_get_controller('user')->resetCache(array($uid));
    return TRUE;
  }
  return FALSE;
}

/**
 * Helper function to get list of group's users.
 *
 * @param int $gid
 *   The node id of the group we are deleting.
 *
 * @return array
 *   A list of users inside a specific group.
 */
function _enrd_lag_database_get_users_in_group($gid) {
  $query = new EntityFieldQuery();
  $query
    ->entityCondition('entity_type', 'user')
    ->fieldCondition('og_user_node', 'target_id', $gid, '=');

  $results = $query->execute();

  if (empty($results)) {
    return FALSE;
  }

  $uids = array_keys($results['user']);

  return $uids;
}
