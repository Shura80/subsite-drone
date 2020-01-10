<?php

/**
 * @file
 * Lists used to generate taxonomy.
 */

/**
 * Project keywords terms.
 */
function _enrd_project_keywords() {
  return array(
    'Biodiversity',
    'Cooperation',
    'Forestry',
    'GHG / ammonia emissions',
    'Information & communication technologies (ICT)',
    'Innovation',
    'LEADER',
    'Producers groups',
    'Renewable energy',
    'Restructuring / modernisation',
    'Risk management',
    'Rural services',
    'Short supply circuits',
    'Soil',
    'Social inclusion',
    'Young farmers',
    'Water',
  );
}

/**
 * Project Measures terms.
 */
function _enrd_project_measures() {
  return array(
    'M01 Knowledge transfer & information actions',
    'M02 Advisory services',
    'M03 Quality schemes',
    'M04 Investments in physical assets',
    'M05 Damage/restoration /prevention actions',
    'M06 Farm & business development',
    'M07 Basic services & village renewal',
    'M08 Investments in forest areas',
    'M09 Producers groups & organisations',
    'M10 Agri - environment - climate',
    'M11 Organic farming',
    'M12 Natura 2000 & WFD',
    'M13 Areas with constraints',
    'M14 Animal welfare',
    'M15 Forest - environmental - climate',
    'M16 Cooperation',
    'M17 Risk management',
    'M18 Complementary payments to Croatia',
    'M19 LEADER / CLLD',
    'M20 Technical assistance',
  );
}

/**
 * Project Focus Areas terms.
 */
function _enrd_project_focus_areas() {
  return array(
    '1A Innovation & cooperation',
    '1B Links with research & innovation',
    '1C Lifelong learning & vocational training',
    '2A Farm’s performance, restructuring & modernization',
    '2B Entry of skilled/younger farmers',
    '3A Agri-food chain integration & quality',
    '3B Risk prevention & management',
    '4A Biodiversity’s restoration, preservation & enhancement',
    '4B Water management',
    '4C Soil erosion & soil management',
    '5A Water use efficiency',
    '5B Energy use efficiency',
    '5C Renewable sources & waste management',
    '5D Greenhouse Gas & ammonia emissions',
    '5E Carbon conservation & sequestration',
    '6A Diversification & job creation',
    '6B Local development',
    '6C ICT - Information & communication technologies',
  );
}

/**
 * EU Budget headings.
 */
function _enrd_projects_eu_budget_mff_headings() {
  return array(
    10 => 'Smart and Inclusive Growth: Competitiveness for growth and jobs',
    20 => 'Smart and Inclusive Growth: Economic, social and territorial cohesion',
    30 => 'Sustainable Growth: Natural Resources',
    40 => 'Security and citizenship',
    50 => 'Global Europe',
  );
}

/**
 * Lists Mff Programmes.
 */
function _enrd_projects_mff_programmes() {
  return array(
    10 => 'MFF 2007-2013 Programmes',
    array(
      20 => 'Competitiveness for growth and employment',
      array(
        30 => 'Seventh Research framework programme (incl. compl. of sixth Research FP)',
        40 => 'Decommissioning (Direct research)',
        50 => 'Ten',
        60 => 'Galileo',
        70 => 'Marco Polo',
        80 => 'Lifelong Learning',
        90 => 'Competitiveness and innovation framework programme (CIP)',
        100 => 'Social policy agenda',
        110 => 'Customs 2013 and Fiscalis 2013',
        120 => 'Nuclear decommissioning',
        130 => 'European Global Adjustment Funds',
        140 => 'Energy projects to aid economic recovery',
        150 => 'Other competitiveness for growth and employment actions & programmes',
      ),
      160 => 'Cohesion for growth and employment',
      array(
        170 => 'European Structural and Investment Funds',
        180 => 'Cohesion Fund',
        190 => 'Other cohesion for growth and employment actions & programmes',
      ),
      200 => 'Preservation & management of natural resources',
      array(
        210 => 'Market related expenditure and direct aids',
        220 => 'Agriculture markets',
        230 => 'Fisheries market',
        240 => 'Animal and plant health',
        250 => 'Rural development',
        260 => 'European fisheries fund',
        270 => 'Fisheries governance and international agreements',
        280 => 'LIFE+',
        290 => 'Decentralised agencies',
        300 => 'Other preservation & management of natural resources actions & programmes',
      ),
      310 => 'Citizenship, freedom, security & justice',
      array(
        320 => 'Freedom, security and justice',
        array(
          330 => 'Solidarity and management of migration flows',
          340 => 'Security and safeguarding liberties',
          350 => 'Fundamental rights and justice',
          360 => 'Decentralised agencies',
          370 => 'Other actions and programmes',
        ),
        380 => 'Citizenship',
        array(
          390 => 'Public health and consumer protection programme',
          400 => 'Culture 2007-2013',
          410 => 'Youth in action',
          420 => 'Media 2007',
          430 => 'Europe for Citizens',
          440 => 'Civil protection Financial instrument',
          450 => 'Communication actions',
          460 => 'European Solidarity Fund',
          470 => 'Decentralised agencies',
          480 => 'Other citizenship actions & programmes',
        ),
      ),
      490 => 'The EU as a global player',
      array(
        500 => 'Instrument for Pre-accession assistance (IPA)',
        505 => 'European Neighbourhood and Partnership Instrument (ENPI)',
        510 => 'Other EU as a global player actions & programmes',
      ),
      515 => '10th European Development Fund (EDF, 2008-2013)*',
    ),
    520 => 'MFF 2014-2020 Programmes',
    array(
      530 => 'Competitiveness for growth and jobs',
      array(
        540 => 'European satellite navigation systems (EGNOS and Galileo)',
        550 => 'European Earth Observation Programme (Copernicus)',
        560 => 'Nuclear Safety and Decommissioning',
        570 => 'International Thermonuclear Experimental Reactor (ITER)',
        580 => 'Horizon 2020',
        590 => 'Competitiveness of enterprises and SMEs (COSME)',
        600 => 'Education, Training, Youth and Sport (Erasmus +)',
        610 => 'Social Change and Innovation',
        620 => 'Customs, Fiscalis and Anti-Fraud',
        630 => 'Connecting Europe Facility',
      ),
      640 => 'Economic, social and territorial cohesion',
      array(
        650 => 'Youth Employment Initiative (specific top-up allocation)',
        660 => 'Regional convergence (Less developed regions)',
        670 => 'Transition regions',
        680 => 'Competitiveness (More developed regions)',
        690 => 'Territorial cooperation',
        700 => 'Cohesion fund',
        710 => 'Outermost and sparsely populated regions',
      ),
      720 => 'Sustainable Growth: Natural Resources',
      array(
        730 => 'European Agricultural Guarantee Fund (EAGF) — Market related expenditure and direct payments',
        740 => 'European Agricultural Fund for Rural Development (EAFRD)',
        750 => 'European Maritime Affairs and Fisheries',
        760 => 'European Maritime and Fisheries Fund',
        770 => 'International fisheries agreements and obligatory contributions to Regional Fisheries Management Organisations (RFMOs)',
        780 => 'Environment and climate action (LIFE)',
      ),
      790 => 'Security and citizenship',
      array(
        800 => 'Asylum and Migration Fund',
        810 => 'Internal Security Fund',
        820 => 'IT systems',
        830 => 'Justice',
        840 => 'Rights and Citizenship',
        850 => 'Civil Protection Mechanism',
        860 => 'Europe for Citizens',
        870 => 'Food and feed',
        880 => 'Health for Growth',
        890 => 'Consumer protection',
        900 => 'Creative Europe',
      ),
      910 => 'Global Europe',
      array(
        920 => 'Instrument for Pre-accession assistance (IPA II)',
        930 => 'European Neighbourhood Instrument (ENI)',
        940 => 'European Instrument for Democracy and Human Rights (EIDHR)',
        950 => 'Instrument for Stability (IfS)',
        960 => 'Common Foreign and Security Policy (CFSP)',
        970 => 'Partnership Instrument (PI)',
        980 => 'Development Cooperation Instrument (DCI)',
        990 => 'Humanitarian aid',
        1000 => 'Civil Protection and European Emergency Response Centre (ERC)',
        1010 => 'European Voluntary Humanitarian Aid Corps EU Aid Volunteers (EUAV)',
        1020 => 'Instrument for Nuclear Safety Cooperation (INSC)',
        1030 => 'Macro-financial Assistance',
        1040 => 'Guarantee fund for External actions',
      ),
      1050 => '11th European Development Fund (EDF, 2014-2020)*',
    ),
  );
}

/**
 * Lists Ec priorities.
 */
function _enrd_projects_ec_priorities() {
  return array(
    10 => 'Jobs, Growth and Investment',
    20 => 'Digital Single Market',
    30 => 'Energy Union and Climate',
    40 => 'Internal Market',
    50 => 'Economic and Monetary Union',
    60 => 'EU-US Free Trade',
    70 => 'Justice and Fundamental Rights',
    80 => 'Migration',
    90 => 'EU as a Global Actor',
    100 => 'Democratic Change',
  );
}

/**
 * Budget broad areas.
 */
function _enrd_projects_broad_areas() {
  return array(
    10 => 'Employment',
    20 => 'Competitiveness',
    30 => 'Education & training',
    40 => 'Research & innovation',
    50 => 'Investment for growth',
    60 => 'Information and communications technology - ICT',
    70 => 'Environment & climate',
    80 => 'Energy',
    90 => 'Transport',
    100 => 'Business',
    110 => 'Economic governance',
    120 => 'Economic relations with U.S.',
    130 => 'Fundamental rights',
    140 => 'Migration',
    150 => 'Stability & security',
    160 => 'Humanitarian aid',
    170 => 'Development',
    180 => 'Citizens and social dialogue',
    190 => 'European Neighbourhood Policy and Enlargement Negotiations',
    200 => 'Agriculture and Rural Development',
    210 => 'Fisheries and Maritime Affairs',
  );
}
