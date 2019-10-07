<?php

/**
 * @file
 * agri_administrations.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function agri_administrations_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:administration:View all unpublished content'.
  $permissions['node:administration:View all unpublished content'] = array(
    'roles' => array(
      'group contributor' => 'group contributor',
      'group editor' => 'group editor',
    ),
  );

  // Exported og permission: 'node:administration:access all webform results'.
  $permissions['node:administration:access all webform results'] = array(
    'roles' => array(),
  );

  // Exported og permission:
  // 'node:administration:access own webform submissions'.
  $permissions['node:administration:access own webform submissions'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:administration:add user'.
  $permissions['node:administration:add user'] = array(
    'roles' => array(
      'group manager' => 'group manager',
    ),
  );

  // Exported og permission: 'node:administration:administer group'.
  $permissions['node:administration:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission:
  // 'node:administration:approve and deny subscription'.
  $permissions['node:administration:approve and deny subscription'] = array(
    'roles' => array(
      'group manager' => 'group manager',
    ),
  );

  // Exported og permission: 'node:administration:create article content'.
  $permissions['node:administration:create article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:administration:create event content'.
  $permissions['node:administration:create event content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:administration:create forum content'.
  $permissions['node:administration:create forum content'] = array(
    'roles' => array(),
  );

  // Exported og permission:
  // 'node:administration:create funding_opportunities content'.
  $permissions['node:administration:create funding_opportunities content'] = array(
    'roles' => array(
      'group contributor' => 'group contributor',
      'group editor' => 'group editor',
    ),
  );

  // Exported og permission: 'node:administration:create gallery content'.
  $permissions['node:administration:create gallery content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:administration:create page content'.
  $permissions['node:administration:create page content'] = array(
    'roles' => array(),
  );

  // Exported og permission:
  // 'node:administration:delete all webform submissions'.
  $permissions['node:administration:delete all webform submissions'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:administration:delete any article content'.
  $permissions['node:administration:delete any article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:administration:delete any event content'.
  $permissions['node:administration:delete any event content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:administration:delete any forum content'.
  $permissions['node:administration:delete any forum content'] = array(
    'roles' => array(),
  );

  // Exported og permission:
  // 'node:administration:delete any funding_opportunities content'.
  $permissions['node:administration:delete any funding_opportunities content'] = array(
    'roles' => array(
      'group editor' => 'group editor',
    ),
  );

  // Exported og permission: 'node:administration:delete any gallery content'.
  $permissions['node:administration:delete any gallery content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:administration:delete any page content'.
  $permissions['node:administration:delete any page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:administration:delete own article content'.
  $permissions['node:administration:delete own article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:administration:delete own event content'.
  $permissions['node:administration:delete own event content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:administration:delete own forum content'.
  $permissions['node:administration:delete own forum content'] = array(
    'roles' => array(),
  );

  // Exported og permission:
  // 'node:administration:delete own funding_opportunities content'.
  $permissions['node:administration:delete own funding_opportunities content'] = array(
    'roles' => array(
      'group contributor' => 'group contributor',
    ),
  );

  // Exported og permission: 'node:administration:delete own gallery content'.
  $permissions['node:administration:delete own gallery content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:administration:delete own page content'.
  $permissions['node:administration:delete own page content'] = array(
    'roles' => array(),
  );

  // Exported og permission:
  // 'node:administration:delete own webform submissions'.
  $permissions['node:administration:delete own webform submissions'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:administration:edit all webform submissions'.
  $permissions['node:administration:edit all webform submissions'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:administration:edit own webform submissions'.
  $permissions['node:administration:edit own webform submissions'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:administration:manage members'.
  $permissions['node:administration:manage members'] = array(
    'roles' => array(
      'group manager' => 'group manager',
    ),
  );

  // Exported og permission: 'node:administration:manage permissions'.
  $permissions['node:administration:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:administration:manage roles'.
  $permissions['node:administration:manage roles'] = array(
    'roles' => array(
      'group manager' => 'group manager',
    ),
  );

  // Exported og permission:
  // 'node:administration:moderate content from draft to needs_review'.
  $permissions['node:administration:moderate content from draft to needs_review'] = array(
    'roles' => array(
      'group contributor' => 'group contributor',
      'group editor' => 'group editor',
    ),
  );

  // Exported og permission:
  // 'node:administration:moderate content from needs_review to draft'.
  $permissions['node:administration:moderate content from needs_review to draft'] = array(
    'roles' => array(
      'group editor' => 'group editor',
    ),
  );

  // Exported og permission:
  // 'node:administration:moderate content from needs_review to published'.
  $permissions['node:administration:moderate content from needs_review to published'] = array(
    'roles' => array(
      'group editor' => 'group editor',
    ),
  );

  // Exported og permission:
  // 'node:administration:moderate content from needs_review to validated'.
  $permissions['node:administration:moderate content from needs_review to validated'] = array(
    'roles' => array(
      'group editor' => 'group editor',
    ),
  );

  // Exported og permission:
  // 'node:administration:moderate content from published to archived'.
  $permissions['node:administration:moderate content from published to archived'] = array(
    'roles' => array(
      'group editor' => 'group editor',
    ),
  );

  // Exported og permission:
  // 'node:administration:moderate content from published to validated'.
  $permissions['node:administration:moderate content from published to validated'] = array(
    'roles' => array(
      'group editor' => 'group editor',
    ),
  );

  // Exported og permission:
  // 'node:administration:moderate content from validated to needs_review'.
  $permissions['node:administration:moderate content from validated to needs_review'] = array(
    'roles' => array(
      'group editor' => 'group editor',
    ),
  );

  // Exported og permission:
  // 'node:administration:moderate content from validated to published'.
  $permissions['node:administration:moderate content from validated to published'] = array(
    'roles' => array(
      'group editor' => 'group editor',
    ),
  );

  // Exported og permission: 'node:administration:subscribe'.
  $permissions['node:administration:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:administration:subscribe without approval'.
  $permissions['node:administration:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:administration:unsubscribe'.
  $permissions['node:administration:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:administration:update any article content'.
  $permissions['node:administration:update any article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:administration:update any event content'.
  $permissions['node:administration:update any event content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:administration:update any forum content'.
  $permissions['node:administration:update any forum content'] = array(
    'roles' => array(),
  );

  // Exported og permission:
  // 'node:administration:update any funding_opportunities content'.
  $permissions['node:administration:update any funding_opportunities content'] = array(
    'roles' => array(
      'group editor' => 'group editor',
    ),
  );

  // Exported og permission: 'node:administration:update any gallery content'.
  $permissions['node:administration:update any gallery content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:administration:update any page content'.
  $permissions['node:administration:update any page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:administration:update group'.
  $permissions['node:administration:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:administration:update own article content'.
  $permissions['node:administration:update own article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:administration:update own event content'.
  $permissions['node:administration:update own event content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:administration:update own forum content'.
  $permissions['node:administration:update own forum content'] = array(
    'roles' => array(),
  );

  // Exported og permission:
  // 'node:administration:update own funding_opportunities content'.
  $permissions['node:administration:update own funding_opportunities content'] = array(
    'roles' => array(
      'group contributor' => 'group contributor',
    ),
  );

  // Exported og permission: 'node:administration:update own gallery content'.
  $permissions['node:administration:update own gallery content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:administration:update own page content'.
  $permissions['node:administration:update own page content'] = array(
    'roles' => array(),
  );

  return $permissions;
}
