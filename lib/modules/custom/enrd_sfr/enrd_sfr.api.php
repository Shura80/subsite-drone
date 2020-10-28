<?php

/**
 * @file
 * Hooks provided by enrd_sfr module.
 */

/**
 * Allow other modules to act on ENRD Sfr's finalization.
 *
 * @param Drupal\enrd_sfr\Entity\EnrdSfr $enrd_sfr
 *   ENRD Sfr object.
 */
function hook_enrd_sfr_finalize($enrd_sfr) {
  // Apply customisations before saving ENRD Sfr.
}

/**
 * Allow other modules to alter the permissions on ENRD Sfr entity bundles.
 *
 * @param string $op
 *   The operation to be performed. Possible values:
 *   - "create"
 *   - "view"
 *   - "delete".
 * @param Drupal\enrd_sfr\Entity\EnrdSfr $enrd_sfr
 *   Either an enrd_sfr entity or in case $op is 'create' either an entity or
 *   an enrd_sfr type name.
 * @param object|null $account
 *   The user to check for. Leave it to NULL to check for the global user.
 * @param string|null $entity_type
 *   The type of the entity.
 *
 * @return bool|null
 *   ENRD_SFR_ENTITY_ACCESS_ALLOW if the operation is to be allowed (TRUE);
 *   ENRD_SFR_ENTITY_ACCESS_DENY if the operation is to be denied (FALSE);
 *   ENRD_SFR_ENTITY_ACCESS_IGNORE to not affect this operation at all (NULL).
 *
 * @see entity_access()
 */
function hook_enrd_sfr_access($op, $enrd_sfr = NULL, $account = NULL, $entity_type = NULL) {
  // Allow module to modify entity access.
  // Eg.: deny access to entity in view mode.
  if ($op == 'view') {
    // Do stuff to check access than, for example, deny access.
    return ENRD_SFR_ENTITY_ACCESS_DENY;
  }
}
