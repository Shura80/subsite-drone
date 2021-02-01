<?php

/**
 * @file
 * enrd_news.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function enrd_news_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-event-field_core_attachments'.
  $field_instances['node-event-field_core_attachments'] = array(
    'bundle' => 'event',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 6,
      ),
      'enrd_nrn_toolkit_resource' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
      'eventlist' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'enrd_file_formatter',
        'settings' => array(
          'custom_file_title' => '',
          'display_type' => 'full',
          'force_file_title' => FALSE,
          'token_file_language' => '[file:field-enrd-taxonomies-file-lang:field-enrd-language-iso]',
        ),
        'type' => 'enrd_file_formatter',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_core_attachments',
    'label' => 'Further information',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'entity_translation_sync' => FALSE,
      'file_directory' => '',
      'file_extensions' => 'txt pdf png jpeg tiff gif jpg doc xls ods odt zip tar ppt pptx docx xlsx',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
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
          ),
        ),
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-event-field_docs'.
  $field_instances['node-event-field_docs'] = array(
    'bundle' => 'event',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'Please select one or more documents',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'enrd_nrn_toolkit_resource' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'eventlist' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_docs',
    'label' => 'Documents selection',
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
      'module' => 'entityreference_view_widget',
      'settings' => array(
        'allow_duplicates' => 0,
        'close_modal' => 1,
        'pass_argument' => 0,
        'pass_arguments' => '',
        'rendered_entity' => 0,
        'view' => 'enrd_event_document_ref|entityreference_view_widget_1',
        'view_mode' => 'full',
      ),
      'type' => 'entityreference_view_widget',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-event-field_enrd_event_online'.
  $field_instances['node-event-field_enrd_event_online'] = array(
    'bundle' => 'event',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Select this checkbox to flag it as "Online event".',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 34,
      ),
      'enrd_nrn_toolkit_resource' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'eventlist' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 8,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_enrd_event_online',
    'label' => 'Display as Online Event',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
        'enrd_fieldtips_enabled' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => -3,
    ),
  );

  // Exported field_instance: 'node-event-field_enrd_nrn_alter_description'.
  $field_instances['node-event-field_enrd_nrn_alter_description'] = array(
    'bundle' => 'event',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Optionally specify a description to be displayed on the NRN Toolkit search results list.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 33,
      ),
      'enrd_nrn_toolkit_resource' => array(
        'label' => 'hidden',
        'module' => 'smart_trim',
        'settings' => array(
          'more_link' => FALSE,
          'more_text' => 'Read more',
          'summary_handler' => 'full',
          'trim_length' => 300,
          'trim_link' => FALSE,
          'trim_options' => array(),
          'trim_preserve_tags' => '',
          'trim_suffix' => '...',
          'trim_type' => 'chars',
        ),
        'type' => 'smart_trim_format',
        'weight' => 0,
      ),
      'eventlist' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_enrd_nrn_alter_description',
    'label' => 'NRN Description',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'basic_html' => 'basic_html',
          'enrd_newsletter_archive' => 0,
          'enrd_safe_html' => 'enrd_safe_html',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 1,
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
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 3,
      ),
      'type' => 'text_textarea',
      'weight' => 21,
    ),
  );

  // Exported field_instance: 'node-event-field_enrd_nrn_date'.
  $field_instances['node-event-field_enrd_nrn_date'] = array(
    'bundle' => 'event',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 31,
      ),
      'enrd_nrn_toolkit_resource' => array(
        'label' => 'inline',
        'module' => 'date',
        'settings' => array(
          'custom_date_format' => '',
          'format_type' => 'enrd_nrn_toolkit_m_y',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => FALSE,
        ),
        'type' => 'date_default',
        'weight' => 31,
      ),
      'eventlist' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_enrd_nrn_date',
    'label' => 'Date',
    'required' => FALSE,
    'settings' => array(
      'default_value' => 'blank',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'd/m/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-10:+3',
      ),
      'type' => 'date_popup',
      'weight' => 19,
    ),
  );

  // Exported field_instance: 'node-event-field_enrd_nrn_include_toolkit'.
  $field_instances['node-event-field_enrd_nrn_include_toolkit'] = array(
    'bundle' => 'event',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Select this checkbox to include it in the NRN Toolkit',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
      'enrd_nrn_toolkit_resource' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 34,
      ),
      'eventlist' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_enrd_nrn_include_toolkit',
    'label' => 'Include in the NRN Toolkit',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 16,
    ),
  );

  // Exported field_instance: 'node-event-field_enrd_nrn_title'.
  $field_instances['node-event-field_enrd_nrn_title'] = array(
    'bundle' => 'event',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Optionally specify a title to be displayed on the NRN Toolkit search results list.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 32,
      ),
      'enrd_nrn_toolkit_resource' => array(
        'label' => 'hidden',
        'module' => 'title',
        'settings' => array(
          'title_class' => 'media-heading',
          'title_link' => 'content',
          'title_style' => 'h2',
        ),
        'type' => 'title_linked',
        'weight' => 0,
      ),
      'eventlist' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_enrd_nrn_title',
    'label' => 'NRN Title',
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
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 254,
      ),
      'type' => 'text_textfield',
      'weight' => 20,
    ),
  );

  // Exported field_instance: 'node-event-field_enrd_nrn_type'.
  $field_instances['node-event-field_enrd_nrn_type'] = array(
    'bundle' => 'event',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'enrd_nrn_toolkit_resource' => array(
        'label' => 'inline',
        'module' => 'ds',
        'settings' => array(
          'taxonomy_term_link' => 0,
          'taxonomy_term_separator' => ', ',
        ),
        'type' => 'ds_taxonomy_separator_localized',
        'weight' => 30,
      ),
      'eventlist' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_enrd_nrn_type',
    'label' => 'Resource type',
    'required' => FALSE,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 17,
    ),
  );

  // Exported field_instance: 'node-event-field_event_location'.
  $field_instances['node-event-field_event_location'] = array(
    'bundle' => 'event',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'addressfield',
        'settings' => array(
          'format_handlers' => array(
            0 => 'address',
          ),
          'use_widget_handlers' => 1,
        ),
        'type' => 'addressfield_default',
        'weight' => 28,
      ),
      'enrd_nrn_toolkit_resource' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
      'eventlist' => array(
        'label' => 'inline',
        'module' => 'addressfield',
        'settings' => array(
          'format_handlers' => array(
            0 => 'address',
          ),
          'use_widget_handlers' => 1,
        ),
        'type' => 'addressfield_default',
        'weight' => 3,
      ),
      'full' => array(
        'label' => 'inline',
        'module' => 'addressfield',
        'settings' => array(
          'format_handlers' => array(
            0 => 'address',
          ),
          'use_widget_handlers' => 1,
        ),
        'type' => 'addressfield_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_event_location',
    'label' => 'Location',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'addressfield',
      'settings' => array(
        'available_countries' => array(),
        'default_country' => 'site_default',
        'format_handlers' => array(
          'address' => 'address',
          'address-hide-postal-code' => 'address-hide-postal-code',
          'address-hide-street' => 'address-hide-street',
          'address-optional' => 'address-optional',
          'address-hide-country' => 0,
          'organisation' => 0,
          'name-full' => 0,
          'name-oneline' => 0,
        ),
      ),
      'type' => 'addressfield_standard',
      'weight' => -1,
    ),
  );

  // Exported field_instance: 'node-event-field_event_type'.
  $field_instances['node-event-field_event_type'] = array(
    'bundle' => 'event',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ds',
        'settings' => array(
          'taxonomy_term_link' => TRUE,
          'taxonomy_term_separator' => ', ',
        ),
        'type' => 'ds_taxonomy_separator_localized',
        'weight' => 17,
      ),
      'enrd_nrn_toolkit_resource' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'eventlist' => array(
        'label' => 'inline',
        'module' => 'ds',
        'settings' => array(
          'taxonomy_term_link' => 0,
          'taxonomy_term_separator' => ', ',
        ),
        'type' => 'ds_taxonomy_separator_localized',
        'weight' => 4,
      ),
      'full' => array(
        'label' => 'inline',
        'module' => 'ds',
        'settings' => array(
          'taxonomy_term_link' => 0,
          'taxonomy_term_separator' => ', ',
        ),
        'type' => 'ds_taxonomy_separator_localized',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_event_type',
    'label' => 'Event type',
    'required' => 1,
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
      'weight' => -2,
    ),
  );

  // Exported field_instance: 'node-event-field_picture_upload'.
  $field_instances['node-event-field_picture_upload'] = array(
    'bundle' => 'event',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 7,
      ),
      'enrd_nrn_toolkit_resource' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
      'eventlist' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'newsroom',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'newsroom',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_picture_upload',
    'label' => 'Images',
    'required' => FALSE,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'entity_translation_sync' => FALSE,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'image',
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(),
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
          ),
        ),
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-event-field_registration'.
  $field_instances['node-event-field_registration'] = array(
    'bundle' => 'event',
    'default_value' => array(
      0 => array(
        'registration_type' => '',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'registration',
        'settings' => array(
          'i18n_string_key' => NULL,
          'label' => 'Register',
        ),
        'type' => 'registration_link',
        'weight' => 15,
      ),
      'enrd_nrn_toolkit_resource' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
      'eventlist' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 34,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'registration',
        'settings' => array(
          'i18n_string_key' => NULL,
          'label' => NULL,
        ),
        'type' => 'registration_link',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_registration',
    'label' => 'Registration',
    'required' => 0,
    'settings' => array(
      'default_registration_settings' => array(
        'capacity' => 0,
        'reminder' => array(
          'reminder_settings' => array(
            'reminder_date' => NULL,
            'reminder_template' => '',
          ),
          'send_reminder' => 0,
        ),
        'scheduling' => array(
          'close' => NULL,
          'open' => NULL,
        ),
        'settings' => array(
          'confirmation' => 'Registration has been saved.',
          'from_address' => 'DIGIT-FPFIS-SUPPORT@ec.europa.eu',
          'maximum_spaces' => 1,
          'multiple_registrations' => 0,
          'registration_entity_access_roles' => array(
            2 => 0,
            3 => 0,
            4 => 0,
            5 => 0,
            6 => 0,
            7 => 0,
            8 => 0,
            9 => 0,
          ),
          'registration_waitlist_capacity' => 0,
          'registration_waitlist_enable' => 0,
        ),
        'status' => 0,
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'registration',
      'settings' => array(),
      'type' => 'registration_select',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-event-field_stakeholders_events'.
  $field_instances['node-event-field_stakeholders_events'] = array(
    'bundle' => 'event',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Select this checkbox to flag it as "Stakeholder event".',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 27,
      ),
      'enrd_nrn_toolkit_resource' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
      'eventlist' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 20,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_stakeholders_events',
    'label' => 'Display as Stakeholder Event',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => -4,
    ),
  );

  // Exported field_instance: 'node-event-field_tax_country'.
  $field_instances['node-event-field_tax_country'] = array(
    'bundle' => 'event',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
      'enrd_nrn_toolkit_resource' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
      'eventlist' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 31,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tax_country',
    'label' => 'Country',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'shs',
      'settings' => array(
        'shs' => array(
          'create_new_levels' => 0,
          'create_new_terms' => 0,
          'force_deepest' => 0,
          'node_count' => 0,
        ),
      ),
      'type' => 'taxonomy_shs',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-event-field_tax_evaluation'.
  $field_instances['node-event-field_tax_evaluation'] = array(
    'bundle' => 'event',
    'default_value' => array(),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
      'enrd_nrn_toolkit_resource' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'eventlist' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 28,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tax_evaluation',
    'label' => 'Evaluation',
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
        'shs' => array(
          'create_new_levels' => 0,
          'create_new_terms' => 0,
          'force_deepest' => 0,
          'node_count' => 0,
        ),
      ),
      'type' => 'options_select',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-event-field_tax_languages'.
  $field_instances['node-event-field_tax_languages'] = array(
    'bundle' => 'event',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
      'enrd_nrn_toolkit_resource' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
      'eventlist' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tax_languages',
    'label' => 'Language',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'shs',
      'settings' => array(
        'shs' => array(
          'create_new_levels' => 0,
          'create_new_terms' => 0,
          'force_deepest' => 0,
          'node_count' => 0,
        ),
      ),
      'type' => 'taxonomy_shs',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-event-field_tax_networking'.
  $field_instances['node-event-field_tax_networking'] = array(
    'bundle' => 'event',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
      'enrd_nrn_toolkit_resource' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
      'eventlist' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 28,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_tax_networking',
    'label' => 'NRN Classification',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'shs',
      'settings' => array(
        'shs' => array(
          'create_new_levels' => 0,
          'create_new_terms' => 0,
          'force_deepest' => 1,
          'use_chosen' => 0,
        ),
      ),
      'type' => 'taxonomy_shs',
      'weight' => 18,
    ),
  );

  // Exported field_instance: 'node-event-field_tax_origin'.
  $field_instances['node-event-field_tax_origin'] = array(
    'bundle' => 'event',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
      'enrd_nrn_toolkit_resource' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
      'eventlist' => array(
        'label' => 'inline',
        'module' => 'ds',
        'settings' => array(
          'taxonomy_term_link' => FALSE,
          'taxonomy_term_separator' => ', ',
        ),
        'type' => 'ds_taxonomy_separator_localized',
        'weight' => 5,
      ),
      'full' => array(
        'label' => 'inline',
        'module' => 'ds',
        'settings' => array(
          'taxonomy_term_link' => 0,
          'taxonomy_term_separator' => ', ',
        ),
        'type' => 'ds_taxonomy_separator_localized',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tax_origin',
    'label' => 'Organiser',
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
      ),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-event-field_tax_rural_dev_policy'.
  $field_instances['node-event-field_tax_rural_dev_policy'] = array(
    'bundle' => 'event',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
      'enrd_nrn_toolkit_resource' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 28,
      ),
      'eventlist' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tax_rural_dev_policy',
    'label' => 'Rural Development Policy',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'shs',
      'settings' => array(
        'shs' => array(
          'create_new_levels' => 0,
          'create_new_terms' => 0,
          'force_deepest' => 0,
          'node_count' => 0,
        ),
      ),
      'type' => 'taxonomy_shs',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-event-field_tax_translation_status'.
  $field_instances['node-event-field_tax_translation_status'] = array(
    'bundle' => 'event',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
      'enrd_nrn_toolkit_resource' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
      'eventlist' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tax_translation_status',
    'label' => 'Translation status',
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
      ),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-event-field_tax_transversal_topics'.
  $field_instances['node-event-field_tax_transversal_topics'] = array(
    'bundle' => 'event',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'enrd_nrn_toolkit_resource' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'eventlist' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tax_transversal_topics',
    'label' => 'Transversal topics',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'shs',
      'settings' => array(
        'shs' => array(
          'create_new_levels' => 0,
          'create_new_terms' => 0,
          'force_deepest' => 0,
          'node_count' => 0,
        ),
      ),
      'type' => 'taxonomy_shs',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-event-field_tax_update_status'.
  $field_instances['node-event-field_tax_update_status'] = array(
    'bundle' => 'event',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
      'enrd_nrn_toolkit_resource' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 31,
      ),
      'eventlist' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tax_update_status',
    'label' => 'Update status',
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
      ),
      'type' => 'options_select',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-news-field_news_image'.
  $field_instances['node-news-field_news_image'] = array(
    'bundle' => 'news',
    'deleted' => 0,
    'description' => 'Add an image that represents the news you are adding.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'newsroom',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'diff_standard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'newsroom',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'newsroom' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'newsroom',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_news_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'entity_translation_sync' => FALSE,
      'file_directory' => 'news',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '480x300',
      'title_field' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
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
          ),
        ),
        'preview_image_style' => 'medium',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 25,
    ),
  );

  // Exported field_instance: 'node-news-field_tax_country'.
  $field_instances['node-news-field_tax_country'] = array(
    'bundle' => 'news',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'newsroom' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tax_country',
    'label' => 'Country',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'shs',
      'settings' => array(
        'shs' => array(
          'create_new_levels' => 0,
          'create_new_terms' => 0,
          'force_deepest' => 0,
          'node_count' => 0,
        ),
      ),
      'type' => 'taxonomy_shs',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-news-field_tax_evaluation'.
  $field_instances['node-news-field_tax_evaluation'] = array(
    'bundle' => 'news',
    'default_value' => array(),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
      'newsroom' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tax_evaluation',
    'label' => 'Evaluation',
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
        'shs' => array(
          'create_new_levels' => 0,
          'create_new_terms' => 0,
          'force_deepest' => 0,
          'node_count' => 0,
        ),
      ),
      'type' => 'options_select',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-news-field_tax_languages'.
  $field_instances['node-news-field_tax_languages'] = array(
    'bundle' => 'news',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'newsroom' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 28,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tax_languages',
    'label' => 'Language',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'shs',
      'settings' => array(
        'shs' => array(
          'create_new_levels' => 0,
          'create_new_terms' => 0,
          'force_deepest' => 0,
          'node_count' => 0,
        ),
      ),
      'type' => 'taxonomy_shs',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-news-field_tax_origin'.
  $field_instances['node-news-field_tax_origin'] = array(
    'bundle' => 'news',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
      'full' => array(
        'label' => 'inline',
        'module' => 'ds',
        'settings' => array(
          'taxonomy_term_link' => FALSE,
          'taxonomy_term_separator' => ', ',
        ),
        'type' => 'ds_taxonomy_separator_localized',
        'weight' => 3,
      ),
      'newsroom' => array(
        'label' => 'inline',
        'module' => 'ds',
        'settings' => array(
          'taxonomy_term_link' => FALSE,
          'taxonomy_term_separator' => ', ',
        ),
        'type' => 'ds_taxonomy_separator_localized',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tax_origin',
    'label' => 'Source',
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
      ),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-news-field_tax_rural_dev_policy'.
  $field_instances['node-news-field_tax_rural_dev_policy'] = array(
    'bundle' => 'news',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 28,
      ),
      'newsroom' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tax_rural_dev_policy',
    'label' => 'Rural Development Policy',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'shs',
      'settings' => array(
        'shs' => array(
          'create_new_levels' => 0,
          'create_new_terms' => 0,
          'force_deepest' => 0,
          'node_count' => 0,
        ),
      ),
      'type' => 'taxonomy_shs',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-news-field_tax_translation_status'.
  $field_instances['node-news-field_tax_translation_status'] = array(
    'bundle' => 'news',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 31,
      ),
      'newsroom' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tax_translation_status',
    'label' => 'Translation status',
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
      ),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-news-field_tax_transversal_topics'.
  $field_instances['node-news-field_tax_transversal_topics'] = array(
    'bundle' => 'news',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
      'newsroom' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tax_transversal_topics',
    'label' => 'Transversal topics',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'shs',
      'settings' => array(
        'shs' => array(
          'create_new_levels' => 0,
          'create_new_terms' => 0,
          'force_deepest' => 0,
          'node_count' => 0,
        ),
      ),
      'type' => 'taxonomy_shs',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-news-field_tax_update_status'.
  $field_instances['node-news-field_tax_update_status'] = array(
    'bundle' => 'news',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'newsroom' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tax_update_status',
    'label' => 'Update status',
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
      ),
      'type' => 'options_select',
      'weight' => 36,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add an image that represents the news you are adding.');
  t('Country');
  t('Date');
  t('Display as Online Event');
  t('Display as Stakeholder Event');
  t('Documents selection');
  t('Evaluation');
  t('Event type');
  t('Further information');
  t('Image');
  t('Images');
  t('Include in the NRN Toolkit');
  t('Language');
  t('Location');
  t('NRN Classification');
  t('NRN Description');
  t('NRN Title');
  t('Optionally specify a description to be displayed on the NRN Toolkit search results list.');
  t('Optionally specify a title to be displayed on the NRN Toolkit search results list.');
  t('Organiser');
  t('Please select one or more documents');
  t('Registration');
  t('Resource type');
  t('Rural Development Policy');
  t('Select this checkbox to flag it as "Online event".');
  t('Select this checkbox to flag it as "Stakeholder event".');
  t('Select this checkbox to include it in the NRN Toolkit');
  t('Source');
  t('Translation status');
  t('Transversal topics');
  t('Update status');

  return $field_instances;
}
