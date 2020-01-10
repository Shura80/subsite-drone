<?php

/**
 * @file
 * enrd_nrn_profiles.rules.inc
 */

/**
 * Implements hook_action_info().
 */
function enrd_nrn_profiles_rules_action_info() {
  $items = array();

  $items['enrd_nrn_profiles_nrn_editors_list'] = array(
    'label' => t('Get NRN Editor users'),
    'group' => t('ENRD NRN Profiles'),
    'parameter' => array(
      'node' => array(
        'type' => 'node',
        'label' => t('NRN Profile node'),
        'description' => t('The NRN Profile node.'),
      ),
    ),
    'provides' => array(
      'nrn_editor_users' => array(
        'type' => 'list<user>',
        'label' => t('List of NRN Editor users'),
      ),
    ),
    'base' => '_enrd_nrn_profiles_get_nrn_editors',
    'access callback' => 'og_rules_integration_access',
  );

  return $items;
}

/**
 * Helper function to get the list of NRN editors related to an NRN Profile.
 *
 * @param object $node
 *   The EntityDrupalWrapper object representig the node.
 *
 * @return array
 *   Returns an array with users retrieved.
 */
function _enrd_nrn_profiles_get_nrn_editors($node) {
  $users = array();
  // Get the list of "NRN Editor" users related to an NRN Profile.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'user')
    // Only include active users.
    ->propertyCondition('status', 1)
    // Filter by user who have reminder option checked on settings form.
    ->fieldCondition('field_enrd_nrnp_access_node', 'target_id', $node->nid, '=')
    // Filter by NRN Editor role.
    ->addTag('rolefilter')
    ->addMetaData('nrn_editor_role', 'NRN Editor');

  $result = $query->execute();

  if (!empty($result['user'])) {
    $user_ids = array_keys($result['user']);
    $users = array(
      'nrn_editor_users' => user_load_multiple($user_ids),
    );
  }

  return $users;
}
