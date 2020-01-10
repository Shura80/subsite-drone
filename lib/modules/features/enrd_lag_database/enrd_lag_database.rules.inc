<?php

/**
 * @file
 * enrd_lag_database.rules.inc
 */

/**
 * Implements hook_action_info().
 */
function enrd_lag_database_rules_action_info() {
  $items = array();

  $items['enrd_lag_database_get_members_with_role_in_group'] = array(
    'label' => t('Get group members with role(s) in group'),
    'group' => t('ENRD LAG Database'),
    'parameter' => array(
      'group' => array(
        'type' => 'entity',
        'label' => t('Group'),
        'description' => t('The group.'),
      ),

      'og_role' => array(
        'type' => 'list<text>',
        'label' => t('Group roles'),
        'options list' => 'og_rules_group_roles_options_list',
        'description' => t('Select group role(s) to limit members list.'),
      ),
    ),
    'provides' => array(
      'group_members_with_role_in_group' => array(
        'type' => 'list<user>',
        'label' => t('List of group members with selected role(s) in group'),
      ),
    ),
    'base' => '_enrd_lag_database_get_og_members_with_role_in_group',
    'access callback' => 'og_rules_integration_access',
  );

  $items['enrd_lag_database_get_og_members_with_role_and_country'] = array(
    'label' => t('Get group members with Country and role(s) in group'),
    'group' => t('ENRD LAG Database'),
    'parameter' => array(
      'group' => array(
        'type' => 'entity',
        'label' => t('Group'),
        'description' => t('The group.'),
      ),

      'og_role' => array(
        'type' => 'list<text>',
        'label' => t('Group roles'),
        'options list' => 'og_rules_group_roles_options_list',
        'description' => t('Select group role(s) to limit members list.'),
      ),

      'country' => array(
        'type' => 'taxonomy_term',
        'label' => t('User Country'),
        'description' => t('Select User\'s associated Country'),
      ),
    ),
    'provides' => array(
      'group_members_in_group_with_country' => array(
        'type' => 'list<user>',
        'label' => t('List of group users with selected role(s) and Country'),
      ),
    ),
    'base' => '_enrd_lag_database_get_og_members_with_role_and_country',
    'access callback' => 'og_rules_integration_access',
  );

  $items['enrd_lag_database_get_lag_managers_in_group'] = array(
    'label' => t('Get LAG Manager members in Group'),
    'group' => t('ENRD LAG Database'),
    'parameter' => array(
      'group' => array(
        'type' => 'entity',
        'label' => t('Group'),
        'description' => t('The group.'),
      ),
    ),
    'provides' => array(
      'group_members_with_role_man_in_group' => array(
        'type' => 'list<user>',
        'label' => t('List of group members with "LAG Manager" role in group'),
      ),
    ),
    'base' => '_enrd_lag_database_get_lag_managers_in_group',
    'access callback' => 'og_rules_integration_access',
  );

  $items['enrd_lag_database_get_nsu_in_group'] = array(
    'label' => t('Get NSU members in Group'),
    'group' => t('ENRD LAG Database'),
    'parameter' => array(
      'group' => array(
        'type' => 'entity',
        'label' => t('Group'),
        'description' => t('The group.'),
      ),
    ),
    'provides' => array(
      'group_members_with_role_nsu_in_group' => array(
        'type' => 'list<user>',
        'label' => t('List of group members with "National manager" role in group'),
      ),
    ),
    'base' => '_enrd_lag_database_get_nsu_managers_in_group',
    'access callback' => 'og_rules_integration_access',
  );

  $items['enrd_lag_database_get_lag_admin_users'] = array(
    'label' => t('Get LAG admin users'),
    'group' => t('ENRD LAG Database'),
    'provides' => array(
      'lag_admin_users' => array(
        'type' => 'list<user>',
        'label' => t('List of LAG Admin users'),
      ),
    ),
    'base' => '_enrd_lag_database_get_lag_admin_users',
    'access callback' => 'og_rules_integration_access',
  );

  return $items;
}

/**
 * Action: Get group members with selected group role from a Group content.
 *
 * @param EntityDrupalWrapper $group
 *   The EntityDrupalWrapper object representig the OG group.
 * @param array $og_roles
 *   An array of OG roles labels.
 *
 * @return array
 *   Returns a list of users with searched roles.
 */
function _enrd_lag_database_get_og_members_with_role_in_group(EntityDrupalWrapper $group, array $og_roles) {
  // Get active members with specified role(s) in this group.
  $query = db_select('og_users_roles', 'ogur');
  $query->join('og_role', 'ogr', 'ogr.rid = ogur.rid');
  $query->join('og_membership', 'ogm', 'ogm.gid = ogur.gid');
  $query->fields('ogur', array('uid'))
    ->condition('ogur.group_type', $group->type())
    ->condition('ogur.gid', $group->getIdentifier())
    ->condition('ogm.state', OG_STATE_ACTIVE)
    ->condition('ogr.name', $og_roles, 'IN')
    ->distinct();

  $result = array(
    'group_members_with_role_in_group' => $query->execute()->fetchCol(),
  );

  return $result;
}

/**
 * Helper function to get the list of OG members related to a Group and Country.
 *
 * @param EntityDrupalWrapper $group
 *   The EntityDrupalWrapper object representig the OG group.
 * @param array $og_roles
 *   An array of OG roles labels.
 * @param object $country
 *   The term obj of the Node Country field.
 *
 * @return array
 *   Returns an array with users retrieved.
 */
function _enrd_lag_database_get_og_members_with_role_and_country(EntityDrupalWrapper $group, array $og_roles, $country) {
  // Get active NSU members from a specific Group and Country.
  $query = db_select('og_users_roles', 'ogur');
  $query->join('og_role', 'ogr', 'ogr.rid = ogur.rid');
  $query->join('og_membership', 'ogm', 'ogm.gid = ogur.gid');
  $query->join('field_data_field_enrd_lag_country', 'ctr', 'ogur.uid = ctr.entity_id');
  $query->fields('ogur', array('uid'))
    ->condition('ogur.group_type', $group->type())
    ->condition('ogur.gid', $group->getIdentifier())
    ->condition('ogm.state', OG_STATE_ACTIVE)
    ->condition('ogr.name', $og_roles, 'IN')
    ->condition('ctr.field_enrd_lag_country_tid', $country->tid)
    ->distinct();

  $result = array(
    'group_members_in_group_with_country' => $query->execute()->fetchCol(),
  );

  return $result;
}

/**
 * Action: Get LAG Manager members from a Group.
 *
 * @param EntityDrupalWrapper $group
 *   The EntityDrupalWrapper object representig the OG group.
 *
 * @return array
 *   Returns a list of users with searched roles.
 */
function _enrd_lag_database_get_lag_managers_in_group(EntityDrupalWrapper $group) {
  // Get active members with specified role(s) in this group.
  $query = db_select('og_users_roles', 'ogur');
  $query->join('og_role', 'ogr', 'ogr.rid = ogur.rid');
  $query->join('og_membership', 'ogm', 'ogm.gid = ogur.gid');
  $query->fields('ogur', array('uid'))
    ->condition('ogur.group_type', $group->type())
    ->condition('ogur.gid', $group->getIdentifier())
    ->condition('ogm.state', OG_STATE_ACTIVE)
    ->condition('ogr.name', array(ENRD_LAG_DATABASE_USER_MANAGER_ROLE, ENRD_LAG_DATABASE_USER_CONTACT_ROLE), 'IN')
    ->distinct();

  $result = array(
    'group_members_with_role_man_in_group' => $query->execute()->fetchCol(),
  );

  return $result;
}

/**
 * Action: Get NSU members from a Group.
 *
 * @param EntityDrupalWrapper $group
 *   The EntityDrupalWrapper object representig the OG group.
 *
 * @return array
 *   Returns a list of users with searched roles.
 */
function _enrd_lag_database_get_nsu_managers_in_group(EntityDrupalWrapper $group) {
  // Get active members with specified role(s) in this group.
  $query = db_select('og_users_roles', 'ogur');
  $query->join('og_role', 'ogr', 'ogr.rid = ogur.rid');
  $query->join('og_membership', 'ogm', 'ogm.gid = ogur.gid');
  $query->fields('ogur', array('uid'))
    ->condition('ogur.group_type', $group->type())
    ->condition('ogur.gid', $group->getIdentifier())
    ->condition('ogm.state', OG_STATE_ACTIVE)
    ->condition('ogr.name', 'National manager')
    ->distinct();

  $result = array(
    'group_members_with_role_nsu_in_group' => $query->execute()->fetchCol(),
  );

  return $result;
}

/**
 * Helper function to get the list of LAG admin users.
 *
 * @return array
 *   Returns an array with users retrieved.
 */
function _enrd_lag_database_get_lag_admin_users() {
  // Get the list of "LAG User" / "Admin" users.
  $query = db_select('users_roles', 'ur');
  $query->join('role', 'r', 'r.rid = ur.rid');
  $query->fields('ur', array('uid'))
    ->condition('r.name', 'administrator');
  $sub_query = db_select('users_roles', 'ur');
  $sub_query->join('role', 'r', 'r.rid = ur.rid');
  $sub_query->fields('ur', array('uid'));
  $sub_query->condition('r.name', 'LAG User');
  $query->condition('uid', $sub_query, 'IN')
    ->distinct();

  $result = array(
    'lag_admin_users' => $query->execute()->fetchCol(),
  );

  return $result;

}

/**
 * Options list callback for user roles.
 */
function _enrd_lag_database_user_roles_options_list($element) {
  $roles = user_roles(TRUE);
  $roles = array_combine($roles, $roles);

  return $roles;
}
