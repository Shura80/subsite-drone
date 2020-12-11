<?php

/**
 * @file
 * enrd_sfr_pub.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function enrd_sfr_pub_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_enrd_sfr_pub_contcp_comm'.
  $field_bases['field_enrd_sfr_pub_contcp_comm'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_contcp_comm',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 1,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_enrd_sfr_pub_contcp_email'.
  $field_bases['field_enrd_sfr_pub_contcp_email'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_contcp_email',
    'indexes' => array(
      'email' => array(
        0 => 'email',
      ),
    ),
    'locked' => 1,
    'module' => 'enrd_evf',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'expiration_time' => 1,
    ),
    'translatable' => 0,
    'type' => 'email_verify_field',
  );

  // Exported field_base: 'field_enrd_sfr_pub_contcp_modif'.
  $field_bases['field_enrd_sfr_pub_contcp_modif'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_contcp_modif',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 1,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_enrd_sfr_pub_contcp_name'.
  $field_bases['field_enrd_sfr_pub_contcp_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_contcp_name',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 1,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_enrd_sfr_pub_contcp_oldadd'.
  $field_bases['field_enrd_sfr_pub_contcp_oldadd'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_contcp_oldadd',
    'indexes' => array(),
    'locked' => 1,
    'module' => 'addressfield',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'addressfield',
  );

  // Exported field_base: 'field_enrd_sfr_pub_contcp_papel'.
  $field_bases['field_enrd_sfr_pub_contcp_papel'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_contcp_papel',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 1,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'electronic' => 'Electronic',
        'paper' => 'Paper',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_enrd_sfr_pub_contcp_reas'.
  $field_bases['field_enrd_sfr_pub_contcp_reas'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_contcp_reas',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 1,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'unsubscribe' => 'Unsubscribe',
        'modify subscription data' => 'Modify your subscriptions',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_enrd_sfr_pub_contcp_surn'.
  $field_bases['field_enrd_sfr_pub_contcp_surn'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_contcp_surn',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 1,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_enrd_sfr_pub_contcp_type'.
  $field_bases['field_enrd_sfr_pub_contcp_type'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_contcp_type',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 1,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'EURuralReview' => 'EU Rural Review',
        'EAFRDProjectsBrochure' => 'EAFRD Projects Brochure',
        'RuralConnectionsMagazine' => 'Rural Connections Magazine',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_enrd_sfr_pub_contehd_email'.
  $field_bases['field_enrd_sfr_pub_contehd_email'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_contehd_email',
    'indexes' => array(
      'email' => array(
        0 => 'email',
      ),
    ),
    'locked' => 1,
    'module' => 'enrd_evf',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'expiration_time' => 1,
    ),
    'translatable' => 0,
    'type' => 'email_verify_field',
  );

  // Exported field_base: 'field_enrd_sfr_pub_contehd_modif'.
  $field_bases['field_enrd_sfr_pub_contehd_modif'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_contehd_modif',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 1,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_enrd_sfr_pub_contehd_name'.
  $field_bases['field_enrd_sfr_pub_contehd_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_contehd_name',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 1,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_enrd_sfr_pub_contehd_not'.
  $field_bases['field_enrd_sfr_pub_contehd_not'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_contehd_not',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 1,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_enrd_sfr_pub_contehd_reas'.
  $field_bases['field_enrd_sfr_pub_contehd_reas'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_contehd_reas',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 1,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'unsubscribe' => 'Unsubscribe',
        'modify subscription data' => 'Modify your subscription',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_enrd_sfr_pub_contehd_surn'.
  $field_bases['field_enrd_sfr_pub_contehd_surn'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_contehd_surn',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 1,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_enrd_sfr_pub_contehd_type'.
  $field_bases['field_enrd_sfr_pub_contehd_type'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_contehd_type',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 1,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'Factsheets' => 'Fact sheets',
        'Newsletters' => 'Newsletters',
        'Guidelines' => 'Guidelines',
        'Reports' => 'Reports',
        'Workingdocuments' => 'Working documents',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_enrd_sfr_pub_subcp_addr'.
  $field_bases['field_enrd_sfr_pub_subcp_addr'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_subcp_addr',
    'indexes' => array(),
    'locked' => 1,
    'module' => 'addressfield',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'addressfield',
  );

  // Exported field_base: 'field_enrd_sfr_pub_subcp_el_lang'.
  $field_bases['field_enrd_sfr_pub_subcp_el_lang'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_subcp_el_lang',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 1,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'EN' => 'EN',
        'FR' => 'FR',
        'DE' => 'DE',
        'ES' => 'ES',
        'IT' => 'IT',
        'PL' => 'PL',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_enrd_sfr_pub_subcp_electr'.
  $field_bases['field_enrd_sfr_pub_subcp_electr'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_subcp_electr',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 1,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'No',
        1 => 'Electronic version',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_enrd_sfr_pub_subcp_email'.
  $field_bases['field_enrd_sfr_pub_subcp_email'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_subcp_email',
    'indexes' => array(
      'email' => array(
        0 => 'email',
      ),
    ),
    'locked' => 1,
    'module' => 'enrd_evf',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'expiration_time' => 1,
    ),
    'translatable' => 0,
    'type' => 'email_verify_field',
  );

  // Exported field_base: 'field_enrd_sfr_pub_subcp_lng_cop'.
  $field_bases['field_enrd_sfr_pub_subcp_lng_cop'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_subcp_lng_cop',
    'indexes' => array(),
    'locked' => 1,
    'module' => 'double_field',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'first' => array(
        'maxlength' => 2,
        'precision' => 10,
        'scale' => 2,
        'size' => 'normal',
        'type' => 'varchar',
      ),
      'second' => array(
        'maxlength' => 255,
        'precision' => 10,
        'scale' => 2,
        'size' => 'small',
        'type' => 'int',
      ),
    ),
    'translatable' => 0,
    'type' => 'double_field',
  );

  // Exported field_base: 'field_enrd_sfr_pub_subcp_name'.
  $field_bases['field_enrd_sfr_pub_subcp_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_subcp_name',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 1,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_enrd_sfr_pub_subcp_org'.
  $field_bases['field_enrd_sfr_pub_subcp_org'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_subcp_org',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 1,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_enrd_sfr_pub_subcp_paper'.
  $field_bases['field_enrd_sfr_pub_subcp_paper'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_subcp_paper',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 1,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'No',
        1 => 'Paper version',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_enrd_sfr_pub_subcp_petitle'.
  $field_bases['field_enrd_sfr_pub_subcp_petitle'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_subcp_petitle',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 1,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'Mr' => 'Mr',
        'Ms' => 'Ms',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_enrd_sfr_pub_subcp_surname'.
  $field_bases['field_enrd_sfr_pub_subcp_surname'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_subcp_surname',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 1,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_enrd_sfr_pub_subcp_type'.
  $field_bases['field_enrd_sfr_pub_subcp_type'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_subcp_type',
    'indexes' => array(
      'revision_id' => array(
        0 => 'revision_id',
      ),
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 1,
    'module' => 'field_collection',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'hide_blank_items' => 1,
      'hide_initial_item' => 0,
      'path' => '',
    ),
    'translatable' => 0,
    'type' => 'field_collection',
  );

  // Exported field_base: 'field_enrd_sfr_pub_subcp_typepub'.
  $field_bases['field_enrd_sfr_pub_subcp_typepub'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_subcp_typepub',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 1,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'EURuralReview' => 'EU Rural Review',
        'EAFRDProjectsBrochure' => 'EAFRD Projects Brochure',
        'RuralConnections' => 'Rural Connections Magazine',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_enrd_sfr_pub_subehd_countr'.
  $field_bases['field_enrd_sfr_pub_subehd_countr'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_subehd_countr',
    'indexes' => array(),
    'locked' => 1,
    'module' => 'addressfield',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'addressfield',
  );

  // Exported field_base: 'field_enrd_sfr_pub_subehd_email'.
  $field_bases['field_enrd_sfr_pub_subehd_email'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_subehd_email',
    'indexes' => array(
      'email' => array(
        0 => 'email',
      ),
    ),
    'locked' => 1,
    'module' => 'enrd_evf',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'expiration_time' => 1,
    ),
    'translatable' => 0,
    'type' => 'email_verify_field',
  );

  // Exported field_base: 'field_enrd_sfr_pub_subehd_name'.
  $field_bases['field_enrd_sfr_pub_subehd_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_subehd_name',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 1,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_enrd_sfr_pub_subehd_organ'.
  $field_bases['field_enrd_sfr_pub_subehd_organ'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_subehd_organ',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 1,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_enrd_sfr_pub_subehd_surnam'.
  $field_bases['field_enrd_sfr_pub_subehd_surnam'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_subehd_surnam',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 1,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_enrd_sfr_pub_subehd_type'.
  $field_bases['field_enrd_sfr_pub_subehd_type'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enrd_sfr_pub_subehd_type',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 1,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'factSheets' => 'Fact sheets',
        'newsletters' => 'Newsletters',
        'guidelines' => 'Guidelines',
        'reports' => 'Reports',
        'workingDocuments' => 'Working documents',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
