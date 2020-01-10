<?php

/**
 * @file
 * enrd_sfr_pub.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function enrd_sfr_pub_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'enrd_sfr-enrd_sfr_pub_contact_cp-field_enrd_sfr_pub_contcp_comm'.
  $field_instances['enrd_sfr-enrd_sfr_pub_contact_cp-field_enrd_sfr_pub_contcp_comm'] = array(
    'bundle' => 'enrd_sfr_pub_contact_cp',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Optionally provide some comments to your request.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_sfr_pub_contcp_comm',
    'label' => 'Comments',
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
        'maxlength_js' => 800,
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 1,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_sfr_pub_contact_cp-field_enrd_sfr_pub_contcp_email'.
  $field_instances['enrd_sfr-enrd_sfr_pub_contact_cp-field_enrd_sfr_pub_contcp_email'] = array(
    'bundle' => 'enrd_sfr_pub_contact_cp',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'enrd_evf',
        'settings' => array(),
        'type' => 'evf_default',
        'weight' => 9,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_sfr_pub_contcp_email',
    'label' => 'Email',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'template' => array(
        'body' => 'Dear [enrd_sfr:field_enrd_sfr_pub_contcp_name] [enrd_sfr:field_enrd_sfr_pub_contcp_surn],

Please confirm your email by clicking the link below.
[enrd_evf:token_url]

Your request to [enrd_sfr:field_enrd_sfr_pub_contcp_reas] will be completed following the confirmation of your email.

If you did not submit this request via the ENRD website then please ignore this email.

Regards,
the ENRD Contact Point team.
',
        'from' => 'publication@enrd.eu',
        'subject' => 'Request to [enrd_sfr:field_enrd_sfr_pub_contcp_reas]',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'enrd_evf',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'evf_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_sfr_pub_contact_cp-field_enrd_sfr_pub_contcp_modif'.
  $field_instances['enrd_sfr-enrd_sfr_pub_contact_cp-field_enrd_sfr_pub_contcp_modif'] = array(
    'bundle' => 'enrd_sfr_pub_contact_cp',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please specify which modifications you wish to apply to your subscription(s) information.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_sfr_pub_contcp_modif',
    'label' => 'Please specify how you would like to modify your subscription information',
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
        'maxlength_js' => 800,
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 1,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_sfr_pub_contact_cp-field_enrd_sfr_pub_contcp_name'.
  $field_instances['enrd_sfr-enrd_sfr_pub_contact_cp-field_enrd_sfr_pub_contcp_name'] = array(
    'bundle' => 'enrd_sfr_pub_contact_cp',
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
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_sfr_pub_contcp_name',
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
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_sfr_pub_contact_cp-field_enrd_sfr_pub_contcp_oldadd'.
  $field_instances['enrd_sfr-enrd_sfr_pub_contact_cp-field_enrd_sfr_pub_contcp_oldadd'] = array(
    'bundle' => 'enrd_sfr_pub_contact_cp',
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
        'weight' => 10,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_sfr_pub_contcp_oldadd',
    'label' => 'To what postal address do you currently receive the ENRD publications?',
    'required' => 1,
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
          'address-hide-postal-code' => 0,
          'address-hide-street' => 0,
          'address-hide-administrative-area' => 0,
          'address-hide-locality' => 0,
          'address-hide-country' => 0,
          'organisation' => 0,
          'name-full' => 0,
          'name-oneline' => 0,
          'address-optional' => 0,
        ),
      ),
      'type' => 'addressfield_standard',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_sfr_pub_contact_cp-field_enrd_sfr_pub_contcp_papel'.
  $field_instances['enrd_sfr-enrd_sfr_pub_contact_cp-field_enrd_sfr_pub_contcp_papel'] = array(
    'bundle' => 'enrd_sfr_pub_contact_cp',
    'default_value' => array(),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 6,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_sfr_pub_contcp_papel',
    'label' => 'Are you subscribed for electronic or paper copies?',
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
      ),
      'type' => 'options_buttons',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_sfr_pub_contact_cp-field_enrd_sfr_pub_contcp_reas'.
  $field_instances['enrd_sfr-enrd_sfr_pub_contact_cp-field_enrd_sfr_pub_contcp_reas'] = array(
    'bundle' => 'enrd_sfr_pub_contact_cp',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_sfr_pub_contcp_reas',
    'label' => 'Reason',
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
      ),
      'type' => 'options_select',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_sfr_pub_contact_cp-field_enrd_sfr_pub_contcp_surn'.
  $field_instances['enrd_sfr-enrd_sfr_pub_contact_cp-field_enrd_sfr_pub_contcp_surn'] = array(
    'bundle' => 'enrd_sfr_pub_contact_cp',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_sfr_pub_contcp_surn',
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
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_sfr_pub_contact_cp-field_enrd_sfr_pub_contcp_type'.
  $field_instances['enrd_sfr-enrd_sfr_pub_contact_cp-field_enrd_sfr_pub_contcp_type'] = array(
    'bundle' => 'enrd_sfr_pub_contact_cp',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 4,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_sfr_pub_contcp_type',
    'label' => 'Type of publication(s)',
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
      ),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_sfr_pub_contact_ehd-field_enrd_sfr_pub_contehd_email'.
  $field_instances['enrd_sfr-enrd_sfr_pub_contact_ehd-field_enrd_sfr_pub_contehd_email'] = array(
    'bundle' => 'enrd_sfr_pub_contact_ehd',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'enrd_evf',
        'settings' => array(),
        'type' => 'evf_default',
        'weight' => 6,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_sfr_pub_contehd_email',
    'label' => 'Email',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'template' => array(
        'body' => 'Dear [enrd_sfr:field_enrd_sfr_pub_contehd_name] [enrd_sfr:field_enrd_sfr_pub_contehd_surn],

Please confirm your email by clicking the link below.
[enrd_evf:token_url]

Your request to [enrd_sfr:field_enrd_sfr_pub_contehd_reas] will be completed following the confirmation of your email.

If you did not submit this request via the ENRD website then please ignore this email.

Sincerely,
the ENRD Evaluation Helpdesk\'s team.',
        'from' => 'publication@ruralevaluation.eu',
        'subject' => 'Request to [enrd_sfr:field_enrd_sfr_pub_contehd_reas]',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'enrd_evf',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'evf_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_sfr_pub_contact_ehd-field_enrd_sfr_pub_contehd_modif'.
  $field_instances['enrd_sfr-enrd_sfr_pub_contact_ehd-field_enrd_sfr_pub_contehd_modif'] = array(
    'bundle' => 'enrd_sfr_pub_contact_ehd',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please, specify what you want to modify in your subscription.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_sfr_pub_contehd_modif',
    'label' => 'Please specify how you would like to modify your subscription information',
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
        'maxlength_js' => 800,
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 1,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_sfr_pub_contact_ehd-field_enrd_sfr_pub_contehd_name'.
  $field_instances['enrd_sfr-enrd_sfr_pub_contact_ehd-field_enrd_sfr_pub_contehd_name'] = array(
    'bundle' => 'enrd_sfr_pub_contact_ehd',
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
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_sfr_pub_contehd_name',
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
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_sfr_pub_contact_ehd-field_enrd_sfr_pub_contehd_not'.
  $field_instances['enrd_sfr-enrd_sfr_pub_contact_ehd-field_enrd_sfr_pub_contehd_not'] = array(
    'bundle' => 'enrd_sfr_pub_contact_ehd',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Optionally provide some notes to your request.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_sfr_pub_contehd_not',
    'label' => 'Notes',
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
        'maxlength_js' => 800,
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 1,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_sfr_pub_contact_ehd-field_enrd_sfr_pub_contehd_reas'.
  $field_instances['enrd_sfr-enrd_sfr_pub_contact_ehd-field_enrd_sfr_pub_contehd_reas'] = array(
    'bundle' => 'enrd_sfr_pub_contact_ehd',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_sfr_pub_contehd_reas',
    'label' => 'Action',
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
      ),
      'type' => 'options_select',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_sfr_pub_contact_ehd-field_enrd_sfr_pub_contehd_surn'.
  $field_instances['enrd_sfr-enrd_sfr_pub_contact_ehd-field_enrd_sfr_pub_contehd_surn'] = array(
    'bundle' => 'enrd_sfr_pub_contact_ehd',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_sfr_pub_contehd_surn',
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
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_sfr_pub_contact_ehd-field_enrd_sfr_pub_contehd_type'.
  $field_instances['enrd_sfr-enrd_sfr_pub_contact_ehd-field_enrd_sfr_pub_contehd_type'] = array(
    'bundle' => 'enrd_sfr_pub_contact_ehd',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 4,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_sfr_pub_contehd_type',
    'label' => 'Type of publication(s)',
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
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_sfr_pub_subscribe_cp-field_enrd_sfr_pub_subcp_addr'.
  $field_instances['enrd_sfr-enrd_sfr_pub_subscribe_cp-field_enrd_sfr_pub_subcp_addr'] = array(
    'bundle' => 'enrd_sfr_pub_subscribe_cp',
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
        'weight' => 8,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_sfr_pub_subcp_addr',
    'label' => 'Address',
    'required' => 1,
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
          'address-hide-postal-code' => 0,
          'address-hide-street' => 0,
          'address-hide-administrative-area' => 0,
          'address-hide-locality' => 0,
          'address-hide-country' => 0,
          'organisation' => 0,
          'name-full' => 0,
          'name-oneline' => 0,
          'address-optional' => 0,
        ),
      ),
      'type' => 'addressfield_standard',
      'weight' => 10,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_sfr_pub_subscribe_cp-field_enrd_sfr_pub_subcp_email'.
  $field_instances['enrd_sfr-enrd_sfr_pub_subscribe_cp-field_enrd_sfr_pub_subcp_email'] = array(
    'bundle' => 'enrd_sfr_pub_subscribe_cp',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'enrd_evf',
        'settings' => array(),
        'type' => 'evf_default',
        'weight' => 11,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_sfr_pub_subcp_email',
    'label' => 'Email',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'template' => array(
        'body' => 'Dear [enrd_sfr:field_enrd_sfr_pub_subcp_name] [enrd_sfr:field_enrd_sfr_pub_subcp_surname],

Please confirm your email by clicking the link below.
[enrd_evf:token_url]

Your request to subscribe will be completed following the confirmation of your email.

If you did not submit this request via the ENRD website then please ignore this email.

Regards,
the ENRD Contact Point team.',
        'from' => 'publication@enrd.eu',
        'subject' => 'Request to subscribe',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'enrd_evf',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'evf_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_sfr_pub_subscribe_cp-field_enrd_sfr_pub_subcp_name'.
  $field_instances['enrd_sfr-enrd_sfr_pub_subscribe_cp-field_enrd_sfr_pub_subcp_name'] = array(
    'bundle' => 'enrd_sfr_pub_subscribe_cp',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Name + Surname should be maximum 35 characters.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_sfr_pub_subcp_name',
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
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_sfr_pub_subscribe_cp-field_enrd_sfr_pub_subcp_org'.
  $field_instances['enrd_sfr-enrd_sfr_pub_subscribe_cp-field_enrd_sfr_pub_subcp_org'] = array(
    'bundle' => 'enrd_sfr_pub_subscribe_cp',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Maximum 35 characters.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_sfr_pub_subcp_org',
    'label' => 'Organisation',
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
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_sfr_pub_subscribe_cp-field_enrd_sfr_pub_subcp_petitle'.
  $field_instances['enrd_sfr-enrd_sfr_pub_subscribe_cp-field_enrd_sfr_pub_subcp_petitle'] = array(
    'bundle' => 'enrd_sfr_pub_subscribe_cp',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 12,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_sfr_pub_subcp_petitle',
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
      ),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_sfr_pub_subscribe_cp-field_enrd_sfr_pub_subcp_surname'.
  $field_instances['enrd_sfr-enrd_sfr_pub_subscribe_cp-field_enrd_sfr_pub_subcp_surname'] = array(
    'bundle' => 'enrd_sfr_pub_subscribe_cp',
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
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_sfr_pub_subcp_surname',
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
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_sfr_pub_subscribe_cp-field_enrd_sfr_pub_subcp_type'.
  $field_instances['enrd_sfr-enrd_sfr_pub_subscribe_cp-field_enrd_sfr_pub_subcp_type'] = array(
    'bundle' => 'enrd_sfr_pub_subscribe_cp',
    'default_value' => array(),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 10,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_sfr_pub_subcp_type',
    'label' => 'Type of publication',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_sfr_pub_subscribe_ehd-field_enrd_sfr_pub_subehd_countr'.
  $field_instances['enrd_sfr-enrd_sfr_pub_subscribe_ehd-field_enrd_sfr_pub_subehd_countr'] = array(
    'bundle' => 'enrd_sfr_pub_subscribe_ehd',
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
        'weight' => 8,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_sfr_pub_subehd_countr',
    'label' => 'Country',
    'required' => 1,
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
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_sfr_pub_subscribe_ehd-field_enrd_sfr_pub_subehd_email'.
  $field_instances['enrd_sfr-enrd_sfr_pub_subscribe_ehd-field_enrd_sfr_pub_subehd_email'] = array(
    'bundle' => 'enrd_sfr_pub_subscribe_ehd',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'enrd_evf',
        'settings' => array(),
        'type' => 'evf_default',
        'weight' => 9,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_sfr_pub_subehd_email',
    'label' => 'Email',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'template' => array(
        'body' => 'Dear [enrd_sfr:field_enrd_sfr_pub_subehd_name] [enrd_sfr:field_enrd_sfr_pub_subehd_surnam],

Please confirm your email by clicking the link below.
[enrd_evf:token_url]

Your request to subscribe will be completed following the confirmation of your email.

If you did not submit this request via the ENRD website then please ignore this email.

Sincerely,
the ENRD Evaluation Helpdesk\'s team.',
        'from' => 'publication@ruralevaluation.eu',
        'subject' => 'Request to subscribe',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'enrd_evf',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'evf_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_sfr_pub_subscribe_ehd-field_enrd_sfr_pub_subehd_name'.
  $field_instances['enrd_sfr-enrd_sfr_pub_subscribe_ehd-field_enrd_sfr_pub_subehd_name'] = array(
    'bundle' => 'enrd_sfr_pub_subscribe_ehd',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_sfr_pub_subehd_name',
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
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_sfr_pub_subscribe_ehd-field_enrd_sfr_pub_subehd_organ'.
  $field_instances['enrd_sfr-enrd_sfr_pub_subscribe_ehd-field_enrd_sfr_pub_subehd_organ'] = array(
    'bundle' => 'enrd_sfr_pub_subscribe_ehd',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_sfr_pub_subehd_organ',
    'label' => 'Type of organisation',
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
      'module' => 'select_or_other',
      'settings' => array(
        'apply_chosen' => '',
        'available_options' => 'researcher|Researcher
evaluator|Evaluator
payingAgency|Paying Agency
lag|LAG
rdpManagingAuthority|RDP Managing Authority
networkOrganisation|Network Organisation (e.g. NRN)
euOrganisation|EU Organisation
lagNetwork|LAG Network
ministry|Ministry',
        'available_options_php' => '',
        'markup_available_options_php' => '&lt;none&gt;',
        'other' => 'Other',
        'other_size' => 60,
        'other_title' => '',
        'other_unknown_defaults' => 'other',
        'sort_options' => 0,
      ),
      'type' => 'select_or_other',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_sfr_pub_subscribe_ehd-field_enrd_sfr_pub_subehd_surnam'.
  $field_instances['enrd_sfr-enrd_sfr_pub_subscribe_ehd-field_enrd_sfr_pub_subehd_surnam'] = array(
    'bundle' => 'enrd_sfr_pub_subscribe_ehd',
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
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_sfr_pub_subehd_surnam',
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
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'enrd_sfr-enrd_sfr_pub_subscribe_ehd-field_enrd_sfr_pub_subehd_type'.
  $field_instances['enrd_sfr-enrd_sfr_pub_subscribe_ehd-field_enrd_sfr_pub_subehd_type'] = array(
    'bundle' => 'enrd_sfr_pub_subscribe_ehd',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 7,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'enrd_sfr',
    'field_name' => 'field_enrd_sfr_pub_subehd_type',
    'label' => 'Type(s) of Publication',
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
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_enrd_sfr_pub_subcp_type-field_enrd_sfr_pub_subcp_el_lang'.
  $field_instances['field_collection_item-field_enrd_sfr_pub_subcp_type-field_enrd_sfr_pub_subcp_el_lang'] = array(
    'bundle' => 'field_enrd_sfr_pub_subcp_type',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_field',
        'settings' => array(),
        'type' => 'i18n_list_default',
        'weight' => 4,
      ),
      'type_of_publication_name' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_enrd_sfr_pub_subcp_el_lang',
    'label' => 'Language(s)',
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
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_enrd_sfr_pub_subcp_type-field_enrd_sfr_pub_subcp_electr'.
  $field_instances['field_collection_item-field_enrd_sfr_pub_subcp_type-field_enrd_sfr_pub_subcp_electr'] = array(
    'bundle' => 'field_enrd_sfr_pub_subcp_type',
    'default_value' => array(),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_field',
        'settings' => array(),
        'type' => 'i18n_list_default',
        'weight' => 3,
      ),
      'type_of_publication_name' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_enrd_sfr_pub_subcp_electr',
    'label' => 'Electronic',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_enrd_sfr_pub_subcp_type-field_enrd_sfr_pub_subcp_lng_cop'.
  $field_instances['field_collection_item-field_enrd_sfr_pub_subcp_type-field_enrd_sfr_pub_subcp_lng_cop'] = array(
    'bundle' => 'field_enrd_sfr_pub_subcp_type',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'double_field',
        'settings' => array(
          'first' => array(
            'format' => '_none',
            'hidden' => 0,
            'prefix' => '',
            'suffix' => ':&nbsp;',
          ),
          'second' => array(
            'format' => '_none',
            'hidden' => 0,
            'prefix' => '',
            'suffix' => '',
          ),
          'style' => 'inline',
        ),
        'type' => 'double_field_unformatted_list',
        'weight' => 2,
      ),
      'type_of_publication_name' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_enrd_sfr_pub_subcp_lng_cop',
    'label' => 'Language(s) + N. of copies',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'double_field',
      'settings' => array(
        'first' => array(
          'general' => array(
            'prefix' => '',
            'required' => 1,
            'suffix' => '',
          ),
          'select' => array(
            'allowed_values' => array(
              'en' => 'EN',
              'fr' => 'FR',
              'de' => 'DE',
              'it' => 'IT',
              'es' => 'ES',
              'pl' => 'PL',
            ),
          ),
        ),
        'inline' => 1,
        'second' => array(
          'general' => array(
            'prefix' => '',
            'required' => 1,
            'suffix' => '',
          ),
          'select' => array(
            'allowed_values' => array(
              1 => 1,
              2 => 2,
              3 => 3,
              4 => 4,
              5 => 5,
            ),
          ),
        ),
      ),
      'type' => 'select_&_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_enrd_sfr_pub_subcp_type-field_enrd_sfr_pub_subcp_paper'.
  $field_instances['field_collection_item-field_enrd_sfr_pub_subcp_type-field_enrd_sfr_pub_subcp_paper'] = array(
    'bundle' => 'field_enrd_sfr_pub_subcp_type',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_field',
        'settings' => array(),
        'type' => 'i18n_list_default',
        'weight' => 1,
      ),
      'type_of_publication_name' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_enrd_sfr_pub_subcp_paper',
    'label' => 'Paper',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_enrd_sfr_pub_subcp_type-field_enrd_sfr_pub_subcp_typepub'.
  $field_instances['field_collection_item-field_enrd_sfr_pub_subcp_type-field_enrd_sfr_pub_subcp_typepub'] = array(
    'bundle' => 'field_enrd_sfr_pub_subcp_type',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 0,
      ),
      'type_of_publication_name' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 5,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_enrd_sfr_pub_subcp_typepub',
    'label' => 'Type of publication',
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
      ),
      'type' => 'options_select',
      'weight' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Action');
  t('Address');
  t('Are you subscribed for electronic or paper copies?');
  t('Comments');
  t('Country');
  t('Electronic');
  t('Email');
  t('Language(s)');
  t('Language(s) + N. of copies');
  t('Maximum 35 characters.');
  t('Name');
  t('Name + Surname should be maximum 35 characters.');
  t('Notes');
  t('Optionally provide some comments to your request.');
  t('Optionally provide some notes to your request.');
  t('Organisation');
  t('Paper');
  t('Please specify how you would like to modify your subscription information');
  t('Please specify which modifications you wish to apply to your subscription(s) information.');
  t('Please, specify what you want to modify in your subscription.');
  t('Reason');
  t('Surname');
  t('Title');
  t('To what postal address do you currently receive the ENRD publications?');
  t('Type of organisation');
  t('Type of publication');
  t('Type of publication(s)');
  t('Type(s) of Publication');

  return $field_instances;
}
