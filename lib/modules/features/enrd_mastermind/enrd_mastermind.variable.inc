<?php

/**
 * @file
 * enrd_mastermind.variable.inc
 */

/**
 * Implements hook_variable_realm_default_variables().
 */
function enrd_mastermind_variable_realm_default_variables() {
  $realm_variables = array();
  $realm_variables['language']['de'] = array(
    'site_map_page_title' => 'Site Map',
    'site_name' => 'Europäische Netzwerk für die Entwicklung des ländlichen Raums (ENRD)',
    'site_slogan' => 'Das ländliche Europa verbinden ...',
  );
  $realm_variables['language']['en'] = array(
    'site_map_page_title' => 'Site Map',
    'site_name' => 'The European Network for Rural Development (ENRD)',
    'site_slogan' => 'Connecting Rural Europe ...',
  );
  $realm_variables['language']['es'] = array(
    'site_map_page_title' => 'Mapa Del Sitio',
    'site_name' => 'Red europea de desarrollo rural (REDR)',
    'site_slogan' => 'Ponemos en contacto a la Europa rural...',
  );
  $realm_variables['language']['fr'] = array(
    'site_map_page_title' => 'Plan Du Site',
    'site_name' => 'Le Réseau européen de développement rural (REDR)',
    'site_slogan' => 'Connecter l\'Europe rurale ...',
  );
  $realm_variables['language']['it'] = array(
    'site_map_page_title' => 'Mappa Del Sito',
    'site_name' => 'La Rete europea per lo sviluppo rurale (RESR)',
    'site_slogan' => 'Connettere l\'Europa rurale ...',
  );
  $realm_variables['language']['pl'] = array(
    'site_map_page_title' => 'Mapa Strony',
    'site_name' => 'Europejska Sieć na rzecz Rozwoju Obszarów Wiejskich (ENRD)',
    'site_slogan' => 'Łączenie europejskiej wsi ...',
  );

  return $realm_variables;
}
