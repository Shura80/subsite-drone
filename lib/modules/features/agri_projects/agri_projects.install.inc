<?php

/**
 * @file
 * agri_projects.install.inc
 */

/**
 * Define "Agricultural sectors" terms as simple strings.
 */
function agri_projects_get_default_agricultural_sectors() {
  return array(
    "Crops (generic)",
    "Cereals",
    "Protein crops",
    "Sugar crops",
    "Vegetables ",
    "Oil crops",
    "Other arable crops",
    "Olives and olive products",
    "Fruits",
    "Viticulture",
    "Other permanent crops",
    "Fodder and forage",
    "Flowers and ornamental plants",
    "Other non-food crops",
    "Forestry (wood & timber)",
    "Livestock (generic)",
    "Beef cattle",
    "Dairy cattle",
    "Sheep & Goats meat",
    "Sheep & Goats milk",
    "Pigs",
    "Poultry",
    "Bees & other insects",
    "Horses",
    "Other livestock and animal products",
    "Other sectors",
    "Not relevant",
  );
}

/**
 * Implements hook_post_features_enable_feature().
 */
function agri_projects_post_features_enable_feature($component) {
  features_revert(array('agri_projects' => array('variable')));
}
