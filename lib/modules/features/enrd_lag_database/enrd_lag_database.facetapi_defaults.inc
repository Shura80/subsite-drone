<?php

/**
 * @file
 * enrd_lag_database.facetapi_defaults.inc
 */

/**
 * Implements hook_facetapi_default_facet_settings().
 */
function enrd_lag_database_facetapi_default_facet_settings() {
  $export = array();

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'apachesolr@solr::bm_field_enrd_lag_interested_in';
  $facet->searcher = 'apachesolr@solr';
  $facet->realm = '';
  $facet->facet = 'bm_field_enrd_lag_interested_in';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'facets' => array(),
      'reverse_dependency' => FALSE,
      'force_deactivation' => TRUE,
      'regex' => FALSE,
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => 1,
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
  );
  $export['apachesolr@solr::bm_field_enrd_lag_interested_in'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'apachesolr@solr::im_field_enrd_coop_topic_of_proj';
  $facet->searcher = 'apachesolr@solr';
  $facet->realm = '';
  $facet->facet = 'im_field_enrd_coop_topic_of_proj';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'facets' => array(),
      'reverse_dependency' => FALSE,
      'force_deactivation' => TRUE,
      'regex' => FALSE,
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => 0,
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
  );
  $export['apachesolr@solr::im_field_enrd_coop_topic_of_proj'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'apachesolr@solr::im_field_enrd_coop_type';
  $facet->searcher = 'apachesolr@solr';
  $facet->realm = '';
  $facet->facet = 'im_field_enrd_coop_type';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'facets' => array(),
      'reverse_dependency' => FALSE,
      'force_deactivation' => TRUE,
      'regex' => FALSE,
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => 0,
    'flatten' => '0',
    'individual_parent' => '1',
    'query_type' => 'term',
    'limit_active_items' => 0,
  );
  $export['apachesolr@solr::im_field_enrd_coop_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'apachesolr@solr::im_field_enrd_esif_programme';
  $facet->searcher = 'apachesolr@solr';
  $facet->realm = '';
  $facet->facet = 'im_field_enrd_esif_programme';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '50',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(
        'article' => 0,
        'page' => 0,
        'community' => 0,
        'cooperation_offer' => 0,
        'discussion' => 0,
        'document' => 0,
        'esi_funds_og' => 0,
        'publication_ehd' => 0,
        'event' => 0,
        'f_a_q' => 0,
        'focus_group' => 0,
        'focus_on' => 0,
        'lag' => 0,
        'news' => 0,
        'organization' => 0,
        'project' => 0,
        'publication' => 0,
        'rdp_information' => 0,
        'webform' => 0,
        'image' => 0,
        'video' => 0,
        'audio' => 0,
      ),
      'roles' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 0,
        5 => 0,
        12 => 0,
        8 => 0,
        9 => 0,
        11 => 0,
        15 => 0,
        14 => 0,
      ),
      'facets_multiple' => array(
        'ss_enrd_lag_full_main_fund' => 'ss_enrd_lag_full_main_fund',
        'im_field_enrd_lag_country' => 'im_field_enrd_lag_country',
        'bm_field_enrd_lag_interested_in' => 0,
        'im_field_enrd_lag_themes_interes' => 0,
        'im_field_enrd_coop_topic_of_proj' => 0,
        'im_field_enrd_coop_type' => 0,
        'im_field_enrd_publication_type' => 0,
        'ss_enrd_coop_lag_country' => 0,
        'sm_enrd_coop_lag_funds' => 0,
        'im_field_enrd_publication_keywor' => 0,
        'dm_field_enrd_publication_date' => 0,
        'im_field_enrd_publ_ehd_eval_them' => 0,
        'im_field_enrd_publ_ehd_eval_type' => 0,
        'im_field_enrd_publ_ehd_content_t' => 0,
        'im_field_enrd_publ_ehd_rdp' => 0,
        'im_field_tags' => 0,
        'author' => 0,
        'language' => 0,
        'im_field_tax_country' => 0,
        'bundle' => 0,
      ),
      'facets' => array(
        'bm_field_enrd_lag_interested_in' => 0,
        'im_field_enrd_lag_themes_interes' => 0,
        'im_field_enrd_coop_topic_of_proj' => 0,
        'im_field_enrd_coop_type' => 0,
        'im_field_enrd_publication_type' => 0,
        'ss_enrd_coop_lag_country' => 0,
        'sm_enrd_coop_lag_funds' => 0,
        'ss_enrd_lag_full_main_fund' => 0,
        'im_field_enrd_publication_keywor' => 0,
        'dm_field_enrd_publication_date' => 0,
        'im_field_enrd_publ_ehd_eval_them' => 0,
        'im_field_enrd_publ_ehd_eval_type' => 0,
        'im_field_enrd_publ_ehd_content_t' => 0,
        'im_field_enrd_publ_ehd_rdp' => 0,
        'im_field_enrd_lag_country' => 0,
        'im_field_tags' => 0,
        'author' => 0,
        'language' => 0,
        'im_field_tax_country' => 0,
        'bundle' => 0,
      ),
      'reverse_dependency' => 0,
      'force_deactivation' => 0,
      'regex' => 0,
      'facet_items_bm_field_enrd_lag_interested_in' => '',
      'facet_items_im_field_enrd_lag_themes_interes' => '',
      'facet_items_im_field_enrd_coop_topic_of_proj' => '',
      'facet_items_im_field_enrd_coop_type' => '',
      'facet_items_im_field_enrd_publication_type' => '',
      'facet_items_ss_enrd_coop_lag_country' => '',
      'facet_items_sm_enrd_coop_lag_funds' => '',
      'facet_items_ss_enrd_lag_full_main_fund' => '',
      'facet_items_im_field_enrd_publication_keywor' => '',
      'facet_items_dm_field_enrd_publication_date' => '',
      'facet_items_im_field_enrd_publ_ehd_eval_them' => '',
      'facet_items_im_field_enrd_publ_ehd_eval_type' => '',
      'facet_items_im_field_enrd_publ_ehd_content_t' => '',
      'facet_items_im_field_enrd_publ_ehd_rdp' => '',
      'facet_items_im_field_enrd_lag_country' => '',
      'facet_items_im_field_tags' => '',
      'facet_items_author' => '',
      'facet_items_language' => '',
      'facet_items_im_field_tax_country' => '',
      'facet_items_bundle' => '',
    ),
    'facet_mincount' => '1',
    'facet_missing' => 0,
    'flatten' => '0',
    'individual_parent' => '1',
    'query_type' => 'term',
    'limit_active_items' => 0,
  );
  $export['apachesolr@solr::im_field_enrd_esif_programme'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'apachesolr@solr::im_field_enrd_lag_country';
  $facet->searcher = 'apachesolr@solr';
  $facet->realm = '';
  $facet->facet = 'im_field_enrd_lag_country';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '50',
    'dependencies' => array(
      'facets' => array(),
      'reverse_dependency' => FALSE,
      'force_deactivation' => TRUE,
      'regex' => FALSE,
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => 0,
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
  );
  $export['apachesolr@solr::im_field_enrd_lag_country'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'apachesolr@solr::im_field_enrd_lag_themes_interes';
  $facet->searcher = 'apachesolr@solr';
  $facet->realm = '';
  $facet->facet = 'im_field_enrd_lag_themes_interes';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(
        'article' => 0,
        'page' => 0,
        'community' => 0,
        'cooperation_offer' => 0,
        'discussion' => 0,
        'document' => 0,
        'esi_funds_og' => 0,
        'publication_ehd' => 0,
        'event' => 0,
        'f_a_q' => 0,
        'focus_group' => 0,
        'focus_on' => 0,
        'lag' => 0,
        'news' => 0,
        'organization' => 0,
        'project' => 0,
        'rdp_information' => 0,
        'simplenews' => 0,
        'webform' => 0,
        'image' => 0,
        'video' => 0,
        'audio' => 0,
      ),
      'roles' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 0,
        5 => 0,
        12 => 0,
        8 => 0,
        9 => 0,
        11 => 0,
        15 => 0,
        14 => 0,
        17 => 0,
      ),
      'facets' => array(
        'bm_field_enrd_lag_interested_in' => 'bm_field_enrd_lag_interested_in',
        'im_field_enrd_coop_assets_area' => 0,
        'im_field_enrd_coop_type' => 0,
        'im_field_enrd_coop_topic_of_proj' => 0,
        'im_field_enrd_coop_partner_count' => 0,
        'im_field_enrd_coop_type_of_area' => 0,
        'im_field_enrd_lag_country' => 0,
        'ss_enrd_coop_lag_country' => 0,
        'sm_enrd_coop_lag_assets' => 0,
        'sm_vid_ENRD_ESI_Funds' => 0,
        'sm_enrd_coop_lag_phys_chars' => 0,
        'sm_enrd_coop_lag_key_themes' => 0,
        'sm_enrd_coop_lag_funds' => 0,
        'im_field_enrd_esif_programme' => 0,
        'im_field_enrd_additional_esi_fun' => 0,
        'im_field_enrd_publ_ehd_content_t' => 0,
        'im_field_enrd_publ_ehd_rdp' => 0,
        'im_field_enrd_publ_ehd_eval_type' => 0,
        'im_field_enrd_publ_ehd_eval_them' => 0,
        'im_field_tags' => 0,
        'language' => 0,
        'author' => 0,
        'im_field_tax_country' => 0,
        'bundle' => 0,
      ),
      'reverse_dependency' => 0,
      'force_deactivation' => 1,
      'regex' => 0,
      'facet_items_bm_field_enrd_lag_interested_in' => '',
      'facet_items_im_field_enrd_coop_assets_area' => '',
      'facet_items_im_field_enrd_coop_type' => '',
      'facet_items_im_field_enrd_coop_topic_of_proj' => '',
      'facet_items_im_field_enrd_coop_partner_count' => '',
      'facet_items_im_field_enrd_coop_type_of_area' => '',
      'facet_items_im_field_enrd_lag_country' => '',
      'facet_items_ss_enrd_coop_lag_country' => '',
      'facet_items_sm_enrd_coop_lag_assets' => '',
      'facet_items_sm_vid_ENRD_ESI_Funds' => '',
      'facet_items_sm_enrd_coop_lag_phys_chars' => '',
      'facet_items_sm_enrd_coop_lag_key_themes' => '',
      'facet_items_sm_enrd_coop_lag_funds' => '',
      'facet_items_im_field_enrd_esif_programme' => '',
      'facet_items_im_field_enrd_additional_esi_fun' => '',
      'facet_items_im_field_enrd_publ_ehd_content_t' => '',
      'facet_items_im_field_enrd_publ_ehd_rdp' => '',
      'facet_items_im_field_enrd_publ_ehd_eval_type' => '',
      'facet_items_im_field_enrd_publ_ehd_eval_them' => '',
      'facet_items_im_field_tags' => '',
      'facet_items_language' => '',
      'facet_items_author' => '',
      'facet_items_im_field_tax_country' => '',
      'facet_items_bundle' => '',
    ),
    'facet_mincount' => '1',
    'facet_missing' => 0,
    'flatten' => '0',
    'individual_parent' => '1',
    'query_type' => 'term',
    'limit_active_items' => 0,
  );
  $export['apachesolr@solr::im_field_enrd_lag_themes_interes'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'apachesolr@solr::sm_enrd_coop_lag_funds';
  $facet->searcher = 'apachesolr@solr';
  $facet->realm = '';
  $facet->facet = 'sm_enrd_coop_lag_funds';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'facets' => array(),
      'reverse_dependency' => FALSE,
      'force_deactivation' => TRUE,
      'regex' => FALSE,
    ),
    'facet_mincount' => 1,
    'facet_missing' => 0,
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
  );
  $export['apachesolr@solr::sm_enrd_coop_lag_funds'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'apachesolr@solr::ss_enrd_coop_lag_country';
  $facet->searcher = 'apachesolr@solr';
  $facet->realm = '';
  $facet->facet = 'ss_enrd_coop_lag_country';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '50',
    'dependencies' => array(
      'facets' => array(),
      'reverse_dependency' => FALSE,
      'force_deactivation' => TRUE,
      'regex' => FALSE,
    ),
    'facet_mincount' => 1,
    'facet_missing' => 0,
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
  );
  $export['apachesolr@solr::ss_enrd_coop_lag_country'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'apachesolr@solr::ss_enrd_lag_full_main_fund';
  $facet->searcher = 'apachesolr@solr';
  $facet->realm = '';
  $facet->facet = 'ss_enrd_lag_full_main_fund';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'facets' => array(),
      'reverse_dependency' => FALSE,
      'force_deactivation' => TRUE,
      'regex' => FALSE,
    ),
    'facet_mincount' => 1,
    'facet_missing' => 0,
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
  );
  $export['apachesolr@solr::ss_enrd_lag_full_main_fund'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'apachesolr@solr:block:bm_field_enrd_lag_interested_in';
  $facet->searcher = 'apachesolr@solr';
  $facet->realm = 'block';
  $facet->facet = 'bm_field_enrd_lag_interested_in';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'enrd_facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'exclude_items' => array(
        'status' => 1,
        'weight' => '-49',
      ),
      'rewrite_items' => array(
        'status' => 1,
        'weight' => '-48',
      ),
      'narrow_results' => array(
        'status' => 0,
        'weight' => '-47',
      ),
      'show_if_minimum_items' => array(
        'status' => 1,
        'weight' => '-46',
      ),
      'deepest_level_items' => array(
        'status' => 1,
        'weight' => '-45',
      ),
    ),
    'active_sorts' => array(
      'active' => 'active',
      'display' => 'display',
      'count' => 0,
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '3',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '0',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'exclude' => 'No',
    'regex' => 0,
    'show_minimum_items' => '1',
    'rewrite_items' => 1,
  );
  $export['apachesolr@solr:block:bm_field_enrd_lag_interested_in'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'apachesolr@solr:block:im_field_enrd_coop_topic_of_proj';
  $facet->searcher = 'apachesolr@solr';
  $facet->realm = 'block';
  $facet->facet = 'im_field_enrd_coop_topic_of_proj';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-49',
      ),
      'exclude_items' => array(
        'status' => 0,
        'weight' => '-48',
      ),
      'rewrite_items' => array(
        'status' => 0,
        'weight' => '-47',
      ),
      'narrow_results' => array(
        'status' => 0,
        'weight' => '-46',
      ),
      'show_if_minimum_items' => array(
        'status' => 1,
        'weight' => '-45',
      ),
      'deepest_level_items' => array(
        'status' => 0,
        'weight' => '-44',
      ),
    ),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '10',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'exclude' => '',
    'regex' => 0,
    'show_minimum_items' => '1',
  );
  $export['apachesolr@solr:block:im_field_enrd_coop_topic_of_proj'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'apachesolr@solr:block:im_field_enrd_coop_type';
  $facet->searcher = 'apachesolr@solr';
  $facet->realm = 'block';
  $facet->facet = 'im_field_enrd_coop_type';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-49',
      ),
      'exclude_items' => array(
        'status' => 0,
        'weight' => '-48',
      ),
      'rewrite_items' => array(
        'status' => 0,
        'weight' => '-47',
      ),
      'narrow_results' => array(
        'status' => 0,
        'weight' => '-46',
      ),
      'show_if_minimum_items' => array(
        'status' => 1,
        'weight' => '-45',
      ),
      'deepest_level_items' => array(
        'status' => 0,
        'weight' => '-44',
      ),
    ),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '10',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'exclude' => '',
    'regex' => 0,
    'show_minimum_items' => '1',
  );
  $export['apachesolr@solr:block:im_field_enrd_coop_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'apachesolr@solr:block:im_field_enrd_esif_programme';
  $facet->searcher = 'apachesolr@solr';
  $facet->realm = 'block';
  $facet->facet = 'im_field_enrd_esif_programme';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '10',
    'nofollow' => 1,
    'show_expanded' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
  );
  $export['apachesolr@solr:block:im_field_enrd_esif_programme'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'apachesolr@solr:block:im_field_enrd_lag_country';
  $facet->searcher = 'apachesolr@solr';
  $facet->realm = 'block';
  $facet->facet = 'im_field_enrd_lag_country';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-49',
      ),
      'exclude_items' => array(
        'status' => 0,
        'weight' => '-48',
      ),
      'rewrite_items' => array(
        'status' => 0,
        'weight' => '-47',
      ),
      'narrow_results' => array(
        'status' => 0,
        'weight' => '-46',
      ),
      'show_if_minimum_items' => array(
        'status' => 1,
        'weight' => '-45',
      ),
      'deepest_level_items' => array(
        'status' => 1,
        'weight' => '-44',
      ),
    ),
    'active_sorts' => array(
      'active' => 'active',
      'display' => 'display',
      'count' => 0,
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '5',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'exclude' => '',
    'regex' => 0,
    'show_minimum_items' => '1',
  );
  $export['apachesolr@solr:block:im_field_enrd_lag_country'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'apachesolr@solr:block:im_field_enrd_lag_themes_interes';
  $facet->searcher = 'apachesolr@solr';
  $facet->realm = 'block';
  $facet->facet = 'im_field_enrd_lag_themes_interes';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-49',
      ),
      'exclude_items' => array(
        'status' => 0,
        'weight' => '-48',
      ),
      'rewrite_items' => array(
        'status' => 0,
        'weight' => '-47',
      ),
      'narrow_results' => array(
        'status' => 0,
        'weight' => '-46',
      ),
      'show_if_minimum_items' => array(
        'status' => 1,
        'weight' => '-45',
      ),
      'deepest_level_items' => array(
        'status' => 1,
        'weight' => '-44',
      ),
    ),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '10',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'exclude' => '',
    'regex' => 0,
    'show_minimum_items' => '1',
  );
  $export['apachesolr@solr:block:im_field_enrd_lag_themes_interes'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'apachesolr@solr:block:sm_enrd_coop_lag_funds';
  $facet->searcher = 'apachesolr@solr';
  $facet->realm = 'block';
  $facet->facet = 'sm_enrd_coop_lag_funds';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '0',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'exclude' => '',
    'regex' => 0,
    'show_minimum_items' => '1',
  );
  $export['apachesolr@solr:block:sm_enrd_coop_lag_funds'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'apachesolr@solr:block:ss_enrd_coop_lag_country';
  $facet->searcher = 'apachesolr@solr';
  $facet->realm = 'block';
  $facet->facet = 'ss_enrd_coop_lag_country';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'exclude_items' => array(
        'status' => 0,
        'weight' => '-49',
      ),
      'rewrite_items' => array(
        'status' => 0,
        'weight' => '-48',
      ),
      'narrow_results' => array(
        'status' => 0,
        'weight' => '-47',
      ),
      'show_if_minimum_items' => array(
        'status' => 1,
        'weight' => '-46',
      ),
      'deepest_level_items' => array(
        'status' => 1,
        'weight' => '-45',
      ),
    ),
    'active_sorts' => array(
      'active' => 'active',
      'display' => 'display',
      'count' => 0,
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '5',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'exclude' => '',
    'regex' => 0,
    'show_minimum_items' => '1',
  );
  $export['apachesolr@solr:block:ss_enrd_coop_lag_country'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'apachesolr@solr:block:ss_enrd_lag_full_main_fund';
  $facet->searcher = 'apachesolr@solr';
  $facet->realm = 'block';
  $facet->facet = 'ss_enrd_lag_full_main_fund';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'exclude_items' => array(
        'status' => 0,
        'weight' => '-49',
      ),
      'rewrite_items' => array(
        'status' => 0,
        'weight' => '-48',
      ),
      'narrow_results' => array(
        'status' => 0,
        'weight' => '-47',
      ),
      'show_if_minimum_items' => array(
        'status' => 1,
        'weight' => '-46',
      ),
      'deepest_level_items' => array(
        'status' => 0,
        'weight' => '-45',
      ),
    ),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '0',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'exclude' => '',
    'regex' => 0,
    'show_minimum_items' => '1',
  );
  $export['apachesolr@solr:block:ss_enrd_lag_full_main_fund'] = $facet;

  return $export;
}
