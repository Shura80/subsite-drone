<?php

/**
 * @file
 * agri_core.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function agri_core_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:administration:administer og menu'.
  $permissions['node:administration:administer og menu'] = array(
    'roles' => array(),
  );

  // Exported og permission:
  // 'node:collaborative_area:View all unpublished content'.
  $permissions['node:collaborative_area:View all unpublished content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission:
  // 'node:collaborative_area:access all webform results'.
  $permissions['node:collaborative_area:access all webform results'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission:
  // 'node:collaborative_area:access collab forum'.
  $permissions['node:collaborative_area:access collab forum'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission:
  // 'node:collaborative_area:access own webform submissions'.
  $permissions['node:collaborative_area:access own webform submissions'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:collaborative_area:add user'.
  $permissions['node:collaborative_area:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:collaborative_area:administer group'.
  $permissions['node:collaborative_area:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:collaborative_area:administer og menu'.
  $permissions['node:collaborative_area:administer og menu'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission:
  // 'node:collaborative_area:approve and deny subscription'.
  $permissions['node:collaborative_area:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:collaborative_area:create article content'.
  $permissions['node:collaborative_area:create article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:collaborative_area:create event content'.
  $permissions['node:collaborative_area:create event content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:collaborative_area:create forum content'.
  $permissions['node:collaborative_area:create forum content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission:
  // 'node:collaborative_area:create funding_opportunities content'.
  $permissions['node:collaborative_area:create funding_opportunities content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:collaborative_area:create gallery content'.
  $permissions['node:collaborative_area:create gallery content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:collaborative_area:create page content'.
  $permissions['node:collaborative_area:create page content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission:
  // 'node:collaborative_area:delete all webform submissions'.
  $permissions['node:collaborative_area:delete all webform submissions'] = array(
    'roles' => array(),
  );

  // Exported og permission:
  // 'node:collaborative_area:delete any article content'.
  $permissions['node:collaborative_area:delete any article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:collaborative_area:delete any event content'.
  $permissions['node:collaborative_area:delete any event content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:collaborative_area:delete any forum content'.
  $permissions['node:collaborative_area:delete any forum content'] = array(
    'roles' => array(),
  );

  // Exported og permission:
  // 'node:collaborative_area:delete any funding_opportunities content'.
  $permissions['node:collaborative_area:delete any funding_opportunities content'] = array(
    'roles' => array(),
  );

  // Exported og permission:
  // 'node:collaborative_area:delete any gallery content'.
  $permissions['node:collaborative_area:delete any gallery content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:collaborative_area:delete any page content'.
  $permissions['node:collaborative_area:delete any page content'] = array(
    'roles' => array(),
  );

  // Exported og permission:
  // 'node:collaborative_area:delete own article content'.
  $permissions['node:collaborative_area:delete own article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:collaborative_area:delete own event content'.
  $permissions['node:collaborative_area:delete own event content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:collaborative_area:delete own forum content'.
  $permissions['node:collaborative_area:delete own forum content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission:
  // 'node:collaborative_area:delete own funding_opportunities content'.
  $permissions['node:collaborative_area:delete own funding_opportunities content'] = array(
    'roles' => array(),
  );

  // Exported og permission:
  // 'node:collaborative_area:delete own gallery content'.
  $permissions['node:collaborative_area:delete own gallery content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:collaborative_area:delete own page content'.
  $permissions['node:collaborative_area:delete own page content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission:
  // 'node:collaborative_area:delete own webform submissions'.
  $permissions['node:collaborative_area:delete own webform submissions'] = array(
    'roles' => array(),
  );

  // Exported og permission:
  // 'node:collaborative_area:edit all webform submissions'.
  $permissions['node:collaborative_area:edit all webform submissions'] = array(
    'roles' => array(),
  );

  // Exported og permission:
  // 'node:collaborative_area:edit own webform submissions'.
  $permissions['node:collaborative_area:edit own webform submissions'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:collaborative_area:manage members'.
  $permissions['node:collaborative_area:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:collaborative_area:manage permissions'.
  $permissions['node:collaborative_area:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:collaborative_area:manage roles'.
  $permissions['node:collaborative_area:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission:
  // 'node:collaborative_area:moderate content from draft to needs_review'.
  $permissions['node:collaborative_area:moderate content from draft to needs_review'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission:
  // 'node:collaborative_area:moderate content from needs_review to draft'.
  $permissions['node:collaborative_area:moderate content from needs_review to draft'] = array(
    'roles' => array(),
  );

  // Exported og permission:
  // 'node:collaborative_area:moderate content from needs_review to published'.
  $permissions['node:collaborative_area:moderate content from needs_review to published'] = array(
    'roles' => array(),
  );

  // Exported og permission:
  // 'node:collaborative_area:moderate content from needs_review to validated'.
  $permissions['node:collaborative_area:moderate content from needs_review to validated'] = array(
    'roles' => array(),
  );

  // Exported og permission:
  // 'node:collaborative_area:moderate content from published to archived'.
  $permissions['node:collaborative_area:moderate content from published to archived'] = array(
    'roles' => array(),
  );

  // Exported og permission:
  // 'node:collaborative_area:moderate content from published to validated'.
  $permissions['node:collaborative_area:moderate content from published to validated'] = array(
    'roles' => array(),
  );

  // Exported og permission:
  // 'node:collaborative_area:moderate content from validated to needs_review'.
  $permissions['node:collaborative_area:moderate content from validated to needs_review'] = array(
    'roles' => array(),
  );

  // Exported og permission:
  // 'node:collaborative_area:moderate content from validated to published'.
  $permissions['node:collaborative_area:moderate content from validated to published'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:collaborative_area:subscribe'.
  $permissions['node:collaborative_area:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission:
  // 'node:collaborative_area:subscribe without approval'.
  $permissions['node:collaborative_area:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:collaborative_area:unsubscribe'.
  $permissions['node:collaborative_area:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission:
  // 'node:collaborative_area:update any article content'.
  $permissions['node:collaborative_area:update any article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:collaborative_area:update any event content'.
  $permissions['node:collaborative_area:update any event content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:collaborative_area:update any forum content'.
  $permissions['node:collaborative_area:update any forum content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission:
  // 'node:collaborative_area:update any funding_opportunities content'.
  $permissions['node:collaborative_area:update any funding_opportunities content'] = array(
    'roles' => array(),
  );

  // Exported og permission:
  // 'node:collaborative_area:update any gallery content'.
  $permissions['node:collaborative_area:update any gallery content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:collaborative_area:update any page content'.
  $permissions['node:collaborative_area:update any page content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:collaborative_area:update group'.
  $permissions['node:collaborative_area:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission:
  // 'node:collaborative_area:update own article content'.
  $permissions['node:collaborative_area:update own article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:collaborative_area:update own event content'.
  $permissions['node:collaborative_area:update own event content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:collaborative_area:update own forum content'.
  $permissions['node:collaborative_area:update own forum content'] = array(
    'roles' => array(),
  );

  // Exported og permission:
  // 'node:collaborative_area:update own funding_opportunities content'.
  $permissions['node:collaborative_area:update own funding_opportunities content'] = array(
    'roles' => array(),
  );

  // Exported og permission:
  // 'node:collaborative_area:update own gallery content'.
  $permissions['node:collaborative_area:update own gallery content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:collaborative_area:update own page content'.
  $permissions['node:collaborative_area:update own page content'] = array(
    'roles' => array(),
  );

  return $permissions;
}
