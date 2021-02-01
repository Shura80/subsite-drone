<?php

/**
 * @file
 * enrd_ruralstory.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function enrd_ruralstory_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'enrd_sfr-enrd_ruralstory-field_enrd_ruralstory_country'.
  $field_instances['enrd_sfr-enrd_ruralstory-field_enrd_ruralstory_country'] = array(
    'bundle' => 'enrd_ruralstory',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 14,
      ),
      'enrd_sfr_full_email' => array(
        'label' => 'inline',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 2,
      ),
      'full' => array(
        'label' => 'inline',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_ruralstory_country',
    'label' => 'Country',
    'required' => 1,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
        'enrd_fieldtips_enabled' => 0,
      ),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_ruralstory-field_enrd_ruralstory_email'.
  $field_instances['enrd_sfr-enrd_ruralstory-field_enrd_ruralstory_email'] = array(
    'bundle' => 'enrd_ruralstory',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 8,
      ),
      'enrd_sfr_full_email' => array(
        'label' => 'inline',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_plain',
        'weight' => 8,
      ),
      'full' => array(
        'label' => 'inline',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 6,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_ruralstory_email',
    'label' => 'Email',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'email',
      'settings' => array(
        'enrd_fieldtips_enabled' => 0,
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_ruralstory-field_enrd_ruralstory_files'.
  $field_instances['enrd_sfr-enrd_ruralstory-field_enrd_ruralstory_files'] = array(
    'bundle' => 'enrd_ruralstory',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 12,
      ),
      'enrd_sfr_full_email' => array(
        'label' => 'hidden',
        'module' => 'enrd_formatters',
        'settings' => array(
          'enrd_count_text' => 'You have submitted @count attached file(s)',
        ),
        'type' => 'enrd_count_summary',
        'weight' => 12,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'file_entity',
        'settings' => array(
          'text' => '[file:name]',
        ),
        'type' => 'file_download_link',
        'weight' => 5,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_ruralstory_files',
    'label' => 'Upload photos/files',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'entity_translation_sync' => FALSE,
      'file_directory' => 'enrd_ruralstory_form',
      'file_extensions' => 'jpeg jpg png doc docx pdf',
      'max_filesize' => '10 MB',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'enrd_fieldtips_enabled' => 0,
        'filefield_sources' => array(
          'filefield_sources' => array(
            'attach' => 0,
            'clipboard' => 0,
            'plupload' => 0,
            'reference' => 0,
            'remote' => 0,
            'upload' => 'upload',
          ),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'move',
            'path' => 'file_attach',
          ),
          'source_imce' => array(
            'imce_mode' => 0,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
            'search_all_fields' => 0,
          ),
        ),
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 11,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_ruralstory-field_enrd_ruralstory_links'.
  $field_instances['enrd_sfr-enrd_ruralstory-field_enrd_ruralstory_links'] = array(
    'bundle' => 'enrd_ruralstory',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'website, social media, video, etc.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(
          'custom_title' => '',
        ),
        'type' => 'link_default',
        'weight' => 11,
      ),
      'enrd_sfr_full_email' => array(
        'label' => 'hidden',
        'module' => 'enrd_formatters',
        'settings' => array(
          'enrd_count_text' => 'You have submitted @count relevant link(s)',
        ),
        'type' => 'enrd_count_summary',
        'weight' => 11,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_url',
        'weight' => 4,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_ruralstory_links',
    'label' => 'Relevant links',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 0,
      'entity_translation_sync' => FALSE,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(
        'enrd_fieldtips_enabled' => 0,
      ),
      'type' => 'link_field',
      'weight' => 10,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_ruralstory-field_enrd_ruralstory_name'.
  $field_instances['enrd_sfr-enrd_ruralstory-field_enrd_ruralstory_name'] = array(
    'bundle' => 'enrd_ruralstory',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'enrd_sfr_full_email' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'full' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_ruralstory_name',
    'label' => 'Name',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'enrd_newsletter_archive' => 'enrd_newsletter_archive',
          'enrd_safe_html' => 'enrd_safe_html',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'basic_html' => array(
              'weight' => 5,
            ),
            'enrd_newsletter_archive' => array(
              'weight' => 0,
            ),
            'enrd_safe_html' => array(
              'weight' => 0,
            ),
            'filtered_html' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => -10,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'enrd_fieldtips_enabled' => 0,
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_ruralstory-field_enrd_ruralstory_org'.
  $field_instances['enrd_sfr-enrd_ruralstory-field_enrd_ruralstory_org'] = array(
    'bundle' => 'enrd_ruralstory',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'enrd_sfr_full_email' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'full' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_ruralstory_org',
    'label' => 'Organisation',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'enrd_newsletter_archive' => 'enrd_newsletter_archive',
          'enrd_safe_html' => 'enrd_safe_html',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'basic_html' => array(
              'weight' => 5,
            ),
            'enrd_newsletter_archive' => array(
              'weight' => 0,
            ),
            'enrd_safe_html' => array(
              'weight' => 0,
            ),
            'filtered_html' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => -10,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'enrd_fieldtips_enabled' => 0,
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_ruralstory-field_enrd_ruralstory_region'.
  $field_instances['enrd_sfr-enrd_ruralstory-field_enrd_ruralstory_region'] = array(
    'bundle' => 'enrd_ruralstory',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'enrd_sfr_full_email' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'full' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_ruralstory_region',
    'label' => 'Region',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'enrd_newsletter_archive' => 'enrd_newsletter_archive',
          'enrd_safe_html' => 'enrd_safe_html',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'basic_html' => array(
              'weight' => 5,
            ),
            'enrd_newsletter_archive' => array(
              'weight' => 0,
            ),
            'enrd_safe_html' => array(
              'weight' => 0,
            ),
            'filtered_html' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => -10,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'enrd_fieldtips_enabled' => 0,
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_ruralstory-field_enrd_ruralstory_short_desc'.
  $field_instances['enrd_sfr-enrd_ruralstory-field_enrd_ruralstory_short_desc'] = array(
    'bundle' => 'enrd_ruralstory',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'enrd_sfr_full_email' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_ruralstory_short_desc',
    'label' => 'Short description of your story',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'enrd_newsletter_archive' => 'enrd_newsletter_archive',
          'enrd_safe_html' => 'enrd_safe_html',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'basic_html' => array(
              'weight' => 5,
            ),
            'enrd_newsletter_archive' => array(
              'weight' => 0,
            ),
            'enrd_safe_html' => array(
              'weight' => 0,
            ),
            'filtered_html' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => -10,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'enrd_fieldtips_enabled' => 0,
        'maxlength_js' => 2500,
        'maxlength_js_enforce' => 1,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 1,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_ruralstory-field_enrd_ruralstory_subject'.
  $field_instances['enrd_sfr-enrd_ruralstory-field_enrd_ruralstory_subject'] = array(
    'bundle' => 'enrd_ruralstory',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'enrd_sfr_full_email' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_ruralstory_subject',
    'label' => 'Subject',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'enrd_newsletter_archive' => 'enrd_newsletter_archive',
          'enrd_safe_html' => 'enrd_safe_html',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'basic_html' => array(
              'weight' => 5,
            ),
            'enrd_newsletter_archive' => array(
              'weight' => 0,
            ),
            'enrd_safe_html' => array(
              'weight' => 0,
            ),
            'filtered_html' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => -10,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'enrd_fieldtips_enabled' => 0,
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_ruralstory-field_enrd_ruralstory_surname'.
  $field_instances['enrd_sfr-enrd_ruralstory-field_enrd_ruralstory_surname'] = array(
    'bundle' => 'enrd_ruralstory',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'enrd_sfr_full_email' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'full' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_ruralstory_surname',
    'label' => 'Surname',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'enrd_newsletter_archive' => 'enrd_newsletter_archive',
          'enrd_safe_html' => 'enrd_safe_html',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'basic_html' => array(
              'weight' => 5,
            ),
            'enrd_newsletter_archive' => array(
              'weight' => 0,
            ),
            'enrd_safe_html' => array(
              'weight' => 0,
            ),
            'filtered_html' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => -10,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'enrd_fieldtips_enabled' => 0,
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_ruralstory-field_enrd_ruralstory_tel'.
  $field_instances['enrd_sfr-enrd_ruralstory-field_enrd_ruralstory_tel'] = array(
    'bundle' => 'enrd_ruralstory',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'enrd_sfr_full_email' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'full' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_ruralstory_tel',
    'label' => 'Tel.',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'enrd_newsletter_archive' => 'enrd_newsletter_archive',
          'enrd_safe_html' => 'enrd_safe_html',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'basic_html' => array(
              'weight' => 5,
            ),
            'enrd_newsletter_archive' => array(
              'weight' => 0,
            ),
            'enrd_safe_html' => array(
              'weight' => 0,
            ),
            'filtered_html' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => -10,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'enrd_fieldtips_enabled' => 0,
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_ruralstory-field_enrd_ruralstory_title'.
  $field_instances['enrd_sfr-enrd_ruralstory-field_enrd_ruralstory_title'] = array(
    'bundle' => 'enrd_ruralstory',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 5,
      ),
      'enrd_sfr_full_email' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 5,
      ),
      'full' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_ruralstory_title',
    'label' => 'Title',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'enrd_fieldtips_enabled' => 0,
      ),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_ruralstory-field_enrd_ruralstory_topic'.
  $field_instances['enrd_sfr-enrd_ruralstory-field_enrd_ruralstory_topic'] = array(
    'bundle' => 'enrd_ruralstory',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'links' => TRUE,
          'use_content_language' => TRUE,
          'view_mode' => 'default',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 2,
      ),
      'enrd_sfr_full_email' => array(
        'label' => 'inline',
        'module' => 'ds',
        'settings' => array(
          'taxonomy_term_link' => 0,
          'taxonomy_term_separator' => ', ',
        ),
        'type' => 'ds_taxonomy_separator_localized',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'inline',
        'module' => 'ds',
        'settings' => array(
          'taxonomy_term_link' => 0,
          'taxonomy_term_separator' => ', ',
        ),
        'type' => 'ds_taxonomy_separator_localized',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_ruralstory_topic',
    'label' => 'Theme / topic',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
        'enrd_fieldtips_enabled' => 0,
      ),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'flagging-enrd_ruralstory_status-field_enrd_ruralstory_flag_user'.
  $field_instances['flagging-enrd_ruralstory_status-field_enrd_ruralstory_flag_user'] = array(
    'bundle' => 'enrd_ruralstory_status',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => -9,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'flagging',
    'field_name' => 'field_enrd_ruralstory_flag_user',
    'label' => 'Flagging User',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'enrd_fieldtips_enabled' => 0,
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'flagging-enrd_ruralstory_status-field_enrd_ruralstory_status'.
  $field_instances['flagging-enrd_ruralstory_status-field_enrd_ruralstory_status'] = array(
    'bundle' => 'enrd_ruralstory_status',
    'default_value' => array(),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -10,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'flagging',
    'field_name' => 'field_enrd_ruralstory_status',
    'label' => 'Status',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
        'enrd_fieldtips_enabled' => 0,
      ),
      'type' => 'options_select',
      'weight' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Country');
  t('Email');
  t('Flagging User');
  t('Name');
  t('Organisation');
  t('Region');
  t('Relevant links');
  t('Short description of your story');
  t('Status');
  t('Subject');
  t('Surname');
  t('Tel.');
  t('Theme / topic');
  t('Title');
  t('Upload photos/files');
  t('website, social media, video, etc.');

  return $field_instances;
}
