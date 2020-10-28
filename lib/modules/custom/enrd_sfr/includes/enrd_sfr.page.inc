<?php

/**
 * @file
 * File enrd_sfr.page.inc.
 */

/**
 * Menu callback: render the ENRD Sfr entity page.
 *
 * @param \Drupal\enrd_sfr\Entity\EnrdSfr $enrd_sfr
 *   The ENRD Sfr object.
 * @param string $view_mode
 *   (optional) The ENRD Sfr bundle view mode.
 *
 * @return array|bool
 *   Either the ENRD Sfr renderable array or FALSE.
 */
function enrd_sfr_page_view($enrd_sfr, $view_mode = 'full') {
  return entity_view(ENRD_SFR_ENTITY_NAME, array(entity_id(ENRD_SFR_ENTITY_NAME, $enrd_sfr) => $enrd_sfr), $view_mode);
}
