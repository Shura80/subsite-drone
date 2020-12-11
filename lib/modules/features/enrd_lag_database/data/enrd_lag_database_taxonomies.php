<?php

/**
 * @file
 * List of taxonomy terms to import into LAG Database vocabularies.
 */

/**
 * Terms of ENRD Key themes of startegy vocabulary.
 */
function _enrd_lag_database_enrd_key_themes_of_strategy() {
  return array(
    'Innovation',
    'Research & Development',
    'New technologies',
    'Knowledge transfer / education / training activities',
    'Broadband / Internet / ICT',
    'Culture & Cultural heritage',
    'Agriculture & Farming',
    array(
      'Small farms',
      'Semi-subsistence farming',
      'Organic farming',
      'Livestock',
      'Animal welfare',
      'Young farmers',
      'Urban farming',
    ),
    'Fisheries and aquaculture',
    array(
      'Fisheries',
      'Aquaculture',
    ),
    'Forestry',
    'Food & Drink',
    'Marketing',
    'Supply chains / Producer organisations & Cooperatives',
    'Non-food products / Crafts',
    'Business development',
    'Economic diversification',
    'Tourism / Territorial branding',
    'Natural environment & Resources / Landscape',
    'Climate change mitigation / adaptation',
    'Local energy production / renewable energies',
    'Circular economy / bio, green economy',
    'Built environment',
    array(
      'Village / harbour renewal',
      'Public / community spaces and green areas',
      'Energy efficiency retrofitting of buildings',
      'Reconversion of brownfield areas',
      'Rural Infrastructures',
    ),
    'Social Inclusion/ Public services',
    array(
      'Integrated services delivery approaches',
      'Social services',
      'Transport & Mobility',
      'Education',
      'Health',
      'Housing',
      'Anti-discrimination',
      'Social enterprises',
    ),
    'Employment / job creation',
    array(
      'Access to labour market',
      'Work-private life reconciliation',
      'Self-employment',
      'Upskilling',
    ),
    'Target groups',
    array(
      'Youth',
      'Women',
      'Long-term unemployed',
      'Homeless',
      'Elderly',
      'Migrants',
      'Fishermen',
      'Marginalised communities e.g. Roma',
      'People with disabilities',
      'Ex-offenders',
      'Others',
    ),
    'Governance',
    'Community development',
    'Rural-Urban linkages',
  );

}

/**
 * Terms of ENRD Physical & demographic characteristics of LAG area vocabulary.
 */
function _enrd_lag_database_enrd_physical_demographic_characteristics_of_lag_area() {
  return array(
    'National / Regional borders',
    'Inland',
    'Island',
    'Lakes & rivers',
    'Coastal',
    'Mountainous',
    'Peri-Urban',
    'Urban',
    array(
      'Small town',
      'Historic centre',
      'Densely populated residential area',
      'Segregated/deprived neighbourhood',
    ),
    'Rural',
    'Isolated / Remote',
    'Sea basin',
    array(
      'Mediterranean',
      'Baltic',
      'North Sea',
      'Atlantic',
    ),
  );
}

/**
 * Terms of ENRD Project Types vocabulary.
 */
function _enrd_lag_database_enrd_project_types() {
  return array(
    'Cooperation within the country',
    array(
      'Across regions',
      'Within the same region',
    ),
    'Transnational cooperation',
    array(
      'Cross - border cooperation',
      'With other MSs (no shared border)',
      'Non EU countries',
    ),
    'Sea basin cooperation',
    array(
      'Mediterranean',
      'Baltic',
      'North Sea',
      'Atlantic',
    ),
  );
}

/**
 * Terms of ENRD Assets vocabulary.
 */
function _enrd_lag_database_enrd_assets() {
  return array(
    'High Nature Value',
    'Cropland',
    'Pasture',
    'Forest',
    'Non-productive',
    'Industry',
    'Presence of relevant cultural sites',
    'Mineral extraction',
    'Protected areas',
  );
}

/**
 * Terms of ENRD ESI Funds.
 */
function _enrd_lag_database_enrd_esi_funds() {
  return array(
    'EAFRD',
    'ERDF',
    'ESF',
    'EMFF',
  );
}

/**
 * Array of ENRD ESI Funds long name.
 */
function _enrd_lag_database_get_enrd_esi_funds_long_name() {
  return array(
    'EAFRD' => 'European Agricultural Fund for Rural Development (EAFRD)',
    'ERDF' => 'European Regional Development Fund (ERDF)',
    'ESF' => 'European Social Fund (ESF)',
    'EMFF' => 'European Maritime and Fisheries Fund (EMFF)',
  );
}

/**
 * Terms of ENRD ESIF Programme.
 */
function _enrd_lag_database_enrd_esif_programme() {
  return array(
    'EAFRD',
    array(
      'Austria',
      array(
        'Rural Development Programme - National',
      ),
      'Belgium',
      array(
        'Rural Development Programme - Flanders',
        'Rural Development Programme - Wallonia',
      ),
      'Bulgaria',
      array('Rural Development Programme - National'),
      'Croatia',
      array('Rural Development Programme - National'),
      'Cyprus',
      array('Rural Development Programme - National'),
      'Czech Republic',
      array('Rural Development Programme - National'),
      'Denmark',
      array('Rural Development Programme - National'),
      'Estonia',
      array('Rural Development Programme - National'),
      'Finland',
      array(
        'Rural Development Programme - Mainland',
        'Rural Development Programme - Âland Islands',
      ),
      'France',
      array(
        'Rural Development Programme - Alsace',
        'Rural Development Programme - Aquitaine',
        'Rural Development Programme - Auvergne',
        'Rural Development Programme - Basse-Normandie',
        'Rural Development Programme - Bourgogne',
        'Rural Development Programme - Bretagne',
        'Rural Development Programme - Centre - Val de Loire',
        'Rural Development Programme - Champagne-Ardenne',
        'Rural Development Programme - Corse',
        'Rural Development Programme - Franche-Comté',
        'Rural Development Programme - Guadeloupe',
        'Rural Development Programme - Guyane',
        'Rural Development Programme - Haute-Normandie',
        'Rural Development Programme - Ile-De-France',
        'Rural Development Programme - Languedoc-Roussillon',
        'Rural Development Programme - Limousin',
        'Rural Development Programme - Lorraine',
        'Rural Development Programme - Martinique',
        'Rural Development Programme - Mayotte',
        'Rural Development Programme - Midi-Pyrénées',
        'Rural Development Programme - National',
        'Rural Development Programme - Nord-Pas de Calais',
        "Rural Development Programme - Provence-Alpes-Côte d'Azur",
        'Rural Development Programme - Pays de la Loire',
        'Rural Development Programme - Picardie',
        'Rural Development Programme - Poitou-Charentes',
        'Rural Development Programme - Réunion',
        'Rural Development Programme - Rhône-Alpes',

      ),
      'Germany',
      array(
        'Rural Development Programme - Baden-Württemberg',
        'Rural Development Programme - Bayern',
        'Rural Development Programme - Brandenburg/Berlin',
        'Rural Development Programme - Hessen',
        'Rural Development Programme - Mecklenburg-Vorpommern',
        'Rural Development Programme - Niedersach/Bremen',
        'Rural Development Programme - Nordrhein-Westfalen',
        'Rural Development Programme - Rheinland-Pfalz',
        'Rural Development Programme - Saarland',
        'Rural Development Programme - Sachsen',
        'Rural Development Programme - Sachsen-Anhalt',
        'Rural Development Programme - Schleswig-Holstein',
        'Rural Development Programme - Thuringen',
      ),
      'Greece',
      array('Rural Development Programme - National'),
      'Hungary',
      array('Rural Development Programme - National'),
      'Ireland',
      array('Rural Development Programme - National'),
      'Italy',
      array(
        'Rural Development Programme - Abruzzo',
        'Rural Development Programme - Basilicata',
        'Rural Development Programme - Calabria',
        'Rural Development Programme - Campania',
        'Rural Development Programme - Emilia Romagna',
        'Rural Development Programme - Friuli Venezia Giulia',
        'Rural Development Programme - Lazio',
        'Rural Development Programme - Liguria',
        'Rural Development Programme - Lombardia',
        'Rural Development Programme - Marche',
        'Rural Development Programme - Molise',
        'Rural Development Programme - National',
        'Rural Development Programme - Piemonte',
        'Rural Development Programme - Bolzano',
        'Rural Development Programme - Trento',
        'Rural Development Programme - Puglia',
        'Rural Development Programme - Sardegna',
        'Rural Development Programme - Sicilia',
        'Rural Development Programme - Toscana',
        'Rural Development Programme - Umbria',
        "Rural Development Programme - Valle D'Aosta",
        'Rural Development Programme - Veneto',
      ),
      'Latvia',
      array('Rural Development Programme - National'),
      'Lithuania',
      array('Rural Development Programme - National'),
      'Luxembourg',
      array('Rural Development Programme - National'),
      'Malta',
      array('Rural Development Programme - National'),
      'Poland',
      array('Rural Development Programme - National'),
      'Portugal',
      array(
        'Rural Development Programme - Azores',
        'Rural Development Programme - Mainland',
        'Rural Development Programme - Madeira',
      ),
      'Romania',
      array('Rural Development Programme - National'),
      'Slovakia',
      array('Rural Development Programme - National'),
      'Slovenia',
      array('Rural Development Programme - National'),
      'Spain',
      array(
        'Rural Development Programme - National',
        'Rural Development Programme - Andalucia',
        'Rural Development Programme - Aragon',
        'Rural Development Programme - Asturias',
        'Rural Development Programme - Islas Baleares',
        'Rural Development Programme - Islas Canarias',
        'Rural Development Programme - Cantabria',
        'Rural Development Programme - Castilla la Mancha',
        'Rural Development Programme - Castilla y Leon',
        'Rural Development Programme - Cataluña',
        'Rural Development Programme - Extremadura',
        'Rural Development Programme - Galicia',
        'Rural Development Programme - Madrid',
        'Rural Development Programme - Murcia',
        'Rural Development Programme - Navarra',
        'Rural Development Programme - Pais Vasco',
        'Rural Development Programme - La Rioja',
        'Rural Development Programme - Valencia',
      ),
      'Sweden',
      array('Rural Development Programme - National'),
      'The Netherlands',
      array('Rural Development Programme - National'),
      'United Kingdom',
      array(
        'Rural Development Programme - England',
        'Rural Development Programme - Northern Ireland',
        'Rural Development Programme - Scotland',
        'Rural Development Programme - Wales',
      ),
    ),
    'ERDF',
    array(
      'Bulgaria',
      'Croatia',
      'Cyprus',
      'Denmark',
      'Estonia',
      'Finland',
      'France',
      'Germany',
      'Greece',
      'Ireland',
      'Italy',
      'Latvia',
      'Lithuania',
      'Poland',
      'Portugal',
      'Romania',
      'Slovenia',
      array("Operational Programme for the Implementation of the European Cohesion Policy - National"),
      'Spain',
      'Sweden',
      'United Kingdom',
    ),
    'ESF',
    array(
      'Bulgaria',
      'Croatia',
      'Cyprus',
      'Denmark',
      'Estonia',
      'Finland',
      'France',
      'Germany',
      'Greece',
      'Ireland',
      'Italy',
      'Latvia',
      'Lithuania',
      'Poland',
      array(
        "Operational Programme 'Knowledge Education Development' - National",
        "Operational Programme - Podlaskie Voivodeship",
        "Operational Programme - Kujawsko-Pomorskie",
      ),
      'Portugal',
      'Romania',
      'Slovenia',
      'Spain',
      'Sweden',
      'United Kingdom',
    ),
    'EMFF',
    array(
      'Bulgaria',
      array(
        'Operational Programme - National',
      ),
      'Croatia',
      array(
        'Operational Programme - National',
      ),
      'Cyprus',
      array(
        'Operational Programme - National',
      ),
      'Denmark',
      array(
        'Operational Programme - National',
      ),
      'Estonia',
      array(
        'Operational Programme - National',
      ),
      'Finland',
      array(
        'Operational Programme - National',
      ),
      'France',
      array(
        'Operational Programme - National',
      ),
      'Germany',
      array(
        'Operational Programme - National',
      ),
      'Greece',
      array(
        'Operational Programme - National',
      ),
      'Ireland',
      array(
        'Operational Programme - National',
      ),
      'Italy',
      array(
        'Operational Programme - National',
      ),
      'Latvia',
      array(
        'Operational Programme - National',
      ),
      'Lithuania',
      array(
        'Operational Programme - National',
      ),
      'Poland',
      array(
        'Operational Programme - National',
      ),
      'Portugal',
      array(
        'Operational Programme - National',
      ),
      'Romania',
      array(
        'Operational Programme - National',
      ),
      'Slovenia',
      array(
        'Operational Programme - National',
      ),
      'Spain',
      array(
        'Operational Programme - National',
      ),
      'Sweden',
      array(
        'Operational Programme - National',
      ),
      'United Kingdom',
      array(
        'Operational Programme - National',
      ),
    ),
  );
}

/**
 * Helper function to create ENRD Lag vocabularies and import terms on install.
 *
 * @param string $machine_name
 *   The machine name of the vocabulary to create.
 *
 * @return mixed
 *   Return terms structure for the vocabulary.
 */
function _enrd_lag_database_taxonomies($machine_name) {
  $list_function = "_enrd_lag_database_$machine_name";
  if (function_exists($list_function)) {
    return $list_function();
  }
  else {
    return array();
  }
}
