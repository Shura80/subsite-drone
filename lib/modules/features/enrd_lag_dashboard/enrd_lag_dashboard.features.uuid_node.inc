<?php

/**
 * @file
 * enrd_lag_dashboard.features.uuid_node.inc
 */

/**
 * Implements hook_uuid_features_default_content().
 */
function enrd_lag_dashboard_uuid_features_default_content() {
  $nodes = array();

  $nodes[] = array(
    'title' => 'Contact the Webmaster',
    'log' => '',
    'status' => 1,
    'comment' => 2,
    'promote' => 0,
    'sticky' => 0,
    'ds_switch' => '',
    'type' => 'webform',
    'language' => 'und',
    'tnid' => 0,
    'translate' => 0,
    'uuid' => '420e5009-ae60-48de-b46c-166ef46627d7',
    'body' => array(),
    'translations' => (object) array(
      'original' => NULL,
      'data' => array(),
    ),
    'metatags' => array(
      'und' => array(
        'revisit-after' => array(
          'value' => 15,
          'period' => 'day',
        ),
      ),
    ),
    'entity_type' => 'node',
    'rdf_mapping' => array(
      'rdftype' => array(
        0 => 'sioc:Item',
        1 => 'foaf:Document',
      ),
      'title' => array(
        'predicates' => array(
          0 => 'dc:title',
        ),
      ),
      'created' => array(
        'predicates' => array(
          0 => 'dc:date',
          1 => 'dc:created',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
      'changed' => array(
        'predicates' => array(
          0 => 'dc:modified',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
      'body' => array(
        'predicates' => array(
          0 => 'content:encoded',
        ),
      ),
      'uid' => array(
        'predicates' => array(
          0 => 'sioc:has_creator',
        ),
        'type' => 'rel',
      ),
      'name' => array(
        'predicates' => array(
          0 => 'foaf:name',
        ),
      ),
      'comment_count' => array(
        'predicates' => array(
          0 => 'sioc:num_replies',
        ),
        'datatype' => 'xsd:integer',
      ),
      'last_activity' => array(
        'predicates' => array(
          0 => 'sioc:last_activity_date',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
    ),
    'path' => array(
      'pathauto' => 0,
      'pid' => NULL,
      'source' => '420e5009-ae60-48de-b46c-166ef46627d7',
      'alias' => '',
      'language' => 'und',
    ),
    'webform' => array(
      'nid' => '420e5009-ae60-48de-b46c-166ef46627d7',
      'confirmation' => '<p>Thank you for your submission. You will be contacted shortly by the Webmaster of the ENRD LAG Database.</p>
',
      'confirmation_format' => 'full_html',
      'redirect_url' => '<none>',
      'status' => 1,
      'block' => 0,
      'allow_draft' => 0,
      'auto_save' => 0,
      'submit_notice' => 1,
      'submit_text' => '',
      'submit_limit' => -1,
      'submit_interval' => -1,
      'total_submit_limit' => -1,
      'total_submit_interval' => -1,
      'progressbar_bar' => 1,
      'progressbar_page_number' => 0,
      'progressbar_percent' => 0,
      'progressbar_pagebreak_labels' => 1,
      'progressbar_include_confirmation' => 0,
      'progressbar_label_first' => 'Start',
      'progressbar_label_confirmation' => 'Complete',
      'preview' => 0,
      'preview_next_button_label' => '',
      'preview_prev_button_label' => '',
      'preview_title' => '',
      'preview_message' => '',
      'preview_message_format' => 'full_html',
      'preview_excluded_components' => array(),
      'confidential' => 0,
      'record_exists' => TRUE,
      'roles' => array(
        0 => 2,
      ),
      'emails' => array(
        1 => array(
          'nid' => '420e5009-ae60-48de-b46c-166ef46627d7',
          'eid' => 1,
          'email' => 5,
          'subject' => 2,
          'from_name' => 7,
          'from_address' => 8,
          'template' => '[submission:values:enrd_lag_dashboard_contact_webmaster_contact_form]

Message: [submission:values:enrd_lag_dashboard_contact_webmaster_message]',
          'excluded_components' => array(),
          'html' => 1,
          'attachments' => 0,
          'extra' => FALSE,
          'exclude_empty' => 0,
          'status' => 1,
        ),
        2 => array(
          'nid' => '420e5009-ae60-48de-b46c-166ef46627d7',
          'eid' => 2,
          'email' => 8,
          'subject' => 'Copy - [submission:values:enrd_lag_dashboard_contact_webmaster_subject]',
          'from_name' => 'default',
          'from_address' => 'default',
          'template' => 'This is a copy of the message you sent via the ENRD LAG Dashboard: \'Contact the Webmaster\' contact form.

Email: [submission:values:enrd_lag_dashboard_contact_webmaster_from_email]

Message: [submission:values:enrd_lag_dashboard_contact_webmaster_message]

The information you provided has been directly forwarded to the Webmaster of the ENRD LAG Database.',
          'excluded_components' => array(),
          'html' => 1,
          'attachments' => 0,
          'extra' => FALSE,
          'exclude_empty' => 0,
          'status' => 1,
        ),
      ),
      'components' => array(
        7 => array(
          'nid' => '420e5009-ae60-48de-b46c-166ef46627d7',
          'cid' => 7,
          'pid' => 0,
          'form_key' => 'enrd_lag_dashboard_contact_webmaster_from_name',
          'name' => 'From name',
          'type' => 'hidden',
          'value' => '[current-user:name]',
          'extra' => array(
            'private' => 0,
            'hidden_type' => 'value',
            'analysis' => FALSE,
          ),
          'required' => 0,
          'weight' => 6,
          'page_num' => 1,
        ),
        8 => array(
          'nid' => '420e5009-ae60-48de-b46c-166ef46627d7',
          'cid' => 8,
          'pid' => 0,
          'form_key' => 'enrd_lag_dashboard_contact_webmaster_from_email',
          'name' => 'From email',
          'type' => 'hidden',
          'value' => '[current-user:mail]',
          'extra' => array(
            'private' => 0,
            'hidden_type' => 'value',
            'analysis' => FALSE,
          ),
          'required' => 0,
          'weight' => 7,
          'page_num' => 1,
        ),
        2 => array(
          'nid' => '420e5009-ae60-48de-b46c-166ef46627d7',
          'cid' => 2,
          'pid' => 0,
          'form_key' => 'enrd_lag_dashboard_contact_webmaster_subject',
          'name' => 'Subject',
          'type' => 'textfield',
          'value' => '',
          'extra' => array(
            'title_display' => 'before',
            'description_above' => 0,
            'private' => 0,
            'wrapper_classes' => '',
            'css_classes' => 'form-control',
            'maxlength' => 255,
            'width' => '',
            'field_prefix' => '',
            'field_suffix' => '',
            'disabled' => 0,
            'unique' => 0,
            'description' => 'Enter the subject of your message.',
            'placeholder' => '',
            'attributes' => array(),
            'analysis' => FALSE,
            'minlength' => '',
          ),
          'required' => 1,
          'weight' => 8,
          'page_num' => 1,
        ),
        4 => array(
          'nid' => '420e5009-ae60-48de-b46c-166ef46627d7',
          'cid' => 4,
          'pid' => 0,
          'form_key' => 'enrd_lag_dashboard_contact_webmaster_message',
          'name' => 'Message',
          'type' => 'textarea',
          'value' => '',
          'extra' => array(
            'description' => '',
            'title_display' => 'before',
            'description_above' => 0,
            'private' => 0,
            'wrapper_classes' => '',
            'css_classes' => '',
            'cols' => '',
            'rows' => '',
            'resizable' => 1,
            'disabled' => 0,
            'placeholder' => '',
            'attributes' => array(),
            'analysis' => FALSE,
          ),
          'required' => 1,
          'weight' => 9,
          'page_num' => 1,
        ),
        5 => array(
          'nid' => '420e5009-ae60-48de-b46c-166ef46627d7',
          'cid' => 5,
          'pid' => 0,
          'form_key' => 'enrd_lag_dashboard_contact_webmaster_recipient',
          'name' => 'Recipient',
          'type' => 'hidden',
          'value' => 'LAG-database-webmaster@enrd.eu',
          'extra' => array(
            'private' => 0,
            'hidden_type' => 'value',
            'analysis' => FALSE,
          ),
          'required' => 0,
          'weight' => 10,
          'page_num' => 1,
        ),
        6 => array(
          'nid' => '420e5009-ae60-48de-b46c-166ef46627d7',
          'cid' => 6,
          'pid' => 0,
          'form_key' => 'enrd_lag_dashboard_contact_webmaster_contact_form',
          'name' => 'Contact form',
          'type' => 'hidden',
          'value' => 'Message received for the ENRD LAG Dashboard: \'[current-page:title]\' contact form.',
          'extra' => array(
            'private' => 0,
            'hidden_type' => 'value',
            'analysis' => FALSE,
          ),
          'required' => 0,
          'weight' => 11,
          'page_num' => 1,
        ),
      ),
      'conditionals' => array(),
      'path' => array(
        'source' => '420e5009-ae60-48de-b46c-166ef46627d7',
      ),
      'validation' => array(),
    ),
    'comment_count' => 0,
    'print_html_display' => 1,
    'print_html_display_comment' => 0,
    'print_html_display_urllist' => 1,
    'print_mail_display' => 1,
    'print_mail_display_comment' => 0,
    'print_mail_display_urllist' => 1,
    'print_pdf_display' => 1,
    'print_pdf_display_comment' => 0,
    'print_pdf_display_urllist' => 1,
    'subscriptions_notify' => TRUE,
    'print_pdf_size' => '',
    'print_pdf_orientation' => '',
    'pathauto_perform_alias' => FALSE,
  );
  return $nodes;
}
