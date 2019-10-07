<?php

/**
 * @file
 * agri_sfc_project_import.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function agri_sfc_project_import_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'phpexcel_apc_cachetime';
  $strongarm->value = '600';
  $export['phpexcel_apc_cachetime'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'phpexcel_cache_mechanism';
  $strongarm->value = 'cache_in_memory_gzip';
  $export['phpexcel_cache_mechanism'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'phpexcel_memcache_cachetime';
  $strongarm->value = '600';
  $export['phpexcel_memcache_cachetime'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'phpexcel_memcache_host';
  $strongarm->value = 'localhost';
  $export['phpexcel_memcache_host'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'phpexcel_memcache_port';
  $strongarm->value = '11211';
  $export['phpexcel_memcache_port'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'phpexcel_phptemp_limit';
  $strongarm->value = '8';
  $export['phpexcel_phptemp_limit'] = $strongarm;

  return $export;
}
