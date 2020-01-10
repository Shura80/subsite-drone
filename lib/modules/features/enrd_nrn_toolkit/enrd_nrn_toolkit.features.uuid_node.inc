<?php

/**
 * @file
 * enrd_nrn_toolkit.features.uuid_node.inc
 */

/**
 * Implements hook_uuid_features_default_content().
 */
function enrd_nrn_toolkit_uuid_features_default_content() {
  $nodes = array();

  $nodes[] = array(
    'title' => 'Contact us',
    'log' => '',
    'status' => 1,
    'comment' => 1,
    'promote' => 0,
    'sticky' => 0,
    'ds_switch' => '',
    'type' => 'webform',
    'language' => 'und',
    'tnid' => 0,
    'translate' => 0,
    'uuid' => 'b1cd0e38-44ba-4455-aaec-34494bb77a85',
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
      'source' => 'b1cd0e38-44ba-4455-aaec-34494bb77a85',
      'alias' => '',
      'language' => 'und',
    ),
    'webform' => array(
      'nid' => 'b1cd0e38-44ba-4455-aaec-34494bb77a85',
      'confirmation' => '<p>Thank you for your submission. Your email has been sent successfully. You will be contacted shortly by the Networking team of the ENRD Contact Point.</p>',
      'confirmation_format' => 'full_html',
      'redirect_url' => '<none>',
      'status' => 1,
      'block' => 1,
      'allow_draft' => 0,
      'auto_save' => 0,
      'submit_notice' => 1,
      'confidential' => 0,
      'submit_text' => '',
      'submit_limit' => -1,
      'submit_interval' => -1,
      'total_submit_limit' => -1,
      'total_submit_interval' => -1,
      'progressbar_bar' => 1,
      'progressbar_page_number' => 0,
      'progressbar_percent' => 0,
      'progressbar_pagebreak_labels' => 1,
      'progressbar_include_confirmation' => 1,
      'progressbar_label_first' => 'Start',
      'progressbar_label_confirmation' => 'Complete',
      'preview' => 0,
      'preview_next_button_label' => '',
      'preview_prev_button_label' => '',
      'preview_title' => '',
      'preview_message' => '',
      'preview_message_format' => 'full_html',
      'preview_excluded_components' => array(),
      'record_exists' => TRUE,
      'roles' => array(
        0 => 1,
        1 => 2,
      ),
      'emails' => array(
        1 => array(
          'nid' => 'b1cd0e38-44ba-4455-aaec-34494bb77a85',
          'eid' => 1,
          'email' => 5,
          'subject' => 3,
          'from_name' => 1,
          'from_address' => 2,
          'template' => 'Organisation: [submission:values:enrd_nrn_toolkit_contact_us_your_organisation]

Email: [submission:values:enrd_nrn_toolkit_contact_us_email]

Message: [submission:values:enrd_nrn_toolkit_contact_us_message]',
          'excluded_components' => array(),
          'html' => 1,
          'attachments' => 0,
          'exclude_empty' => 0,
          'extra' => FALSE,
          'status' => 1,
        ),
        2 => array(
          'nid' => 'b1cd0e38-44ba-4455-aaec-34494bb77a85',
          'eid' => 2,
          'email' => 2,
          'subject' => 'Copy - ENRD NRN Toolkit contact form',
          'from_name' => 'default',
          'from_address' => 'default',
          'template' => 'This is a copy of the message you sent via the NRN Toolkit contact form.

Organisation: [submission:values:enrd_nrn_toolkit_contact_us_your_organisation]
      
Email: [submission:values:enrd_nrn_toolkit_contact_us_email]
      
Message: [submission:values:enrd_nrn_toolkit_contact_us_message]
        
The information you provide will be directly forwarded to the Networking team of the ENRD Contact Point.',
          'excluded_components' => array(),
          'html' => 1,
          'attachments' => 0,
          'exclude_empty' => 0,
          'extra' => FALSE,
          'status' => 1,
        ),
      ),
      'components' => array(
        6 => array(
          'nid' => 'b1cd0e38-44ba-4455-aaec-34494bb77a85',
          'cid' => 6,
          'pid' => 0,
          'form_key' => 'enrd_nrn_toolkit_contact_us_help_text',
          'name' => 'Help text',
          'type' => 'markup',
          'value' => 'Send us your ideas, suggestions, good practices and experiences related to rural development networking.',
          'extra' => array(
            'format' => 'plain_text',
            'private' => 0,
            'display_on' => 'form',
          ),
          'required' => 0,
          'weight' => 5,
          'page_num' => 1,
        ),
        1 => array(
          'nid' => 'b1cd0e38-44ba-4455-aaec-34494bb77a85',
          'cid' => 1,
          'pid' => 0,
          'form_key' => 'enrd_nrn_toolkit_contact_us_your_organisation',
          'name' => 'Your organisation',
          'type' => 'textfield',
          'value' => '',
          'extra' => array(
            'description' => 'Enter the name of the organisation you belong to.',
            'title_display' => 'before',
            'description_above' => 0,
            'private' => 0,
            'wrapper_classes' => '',
            'css_classes' => '',
            'maxlength' => 50,
            'width' => '',
            'field_prefix' => '',
            'field_suffix' => '',
            'disabled' => 0,
            'unique' => 0,
            'placeholder' => '',
            'attributes' => array(),
            'analysis' => FALSE,
            'minlength' => '',
          ),
          'required' => 1,
          'weight' => 6,
          'page_num' => 1,
        ),
        2 => array(
          'nid' => 'b1cd0e38-44ba-4455-aaec-34494bb77a85',
          'cid' => 2,
          'pid' => 0,
          'form_key' => 'enrd_nrn_toolkit_contact_us_email',
          'name' => 'Email',
          'type' => 'email',
          'value' => '[current-user:mail]',
          'extra' => array(
            'description' => 'Enter your email address.',
            'title_display' => 'before',
            'description_above' => 0,
            'private' => 0,
            'wrapper_classes' => '',
            'css_classes' => 'form-control',
            'multiple' => 0,
            'format' => 'short',
            'width' => '',
            'unique' => 0,
            'disabled' => 0,
            'placeholder' => '',
            'attributes' => array(),
            'analysis' => FALSE,
          ),
          'required' => 1,
          'weight' => 7,
          'page_num' => 1,
        ),
        3 => array(
          'nid' => 'b1cd0e38-44ba-4455-aaec-34494bb77a85',
          'cid' => 3,
          'pid' => 0,
          'form_key' => 'enrd_nrn_toolkit_contact_us_subject',
          'name' => 'Subject',
          'type' => 'hidden',
          'value' => 'ENRD NRN Toolkit contact form',
          'extra' => array(
            'private' => 0,
            'hidden_type' => 'value',
            'analysis' => FALSE,
          ),
          'required' => 0,
          'weight' => 8,
          'page_num' => 1,
        ),
        4 => array(
          'nid' => 'b1cd0e38-44ba-4455-aaec-34494bb77a85',
          'cid' => 4,
          'pid' => 0,
          'form_key' => 'enrd_nrn_toolkit_contact_us_message',
          'name' => 'Message',
          'type' => 'textarea',
          'value' => '',
          'extra' => array(
            'title_display' => 'before',
            'description_above' => 0,
            'private' => 0,
            'wrapper_classes' => '',
            'css_classes' => '',
            'cols' => '',
            'rows' => '',
            'resizable' => 1,
            'disabled' => 0,
            'description' => '',
            'placeholder' => '',
            'attributes' => array(),
            'analysis' => FALSE,
          ),
          'required' => 1,
          'weight' => 9,
          'page_num' => 1,
        ),
        5 => array(
          'nid' => 'b1cd0e38-44ba-4455-aaec-34494bb77a85',
          'cid' => 5,
          'pid' => 0,
          'form_key' => 'enrd_nrn_toolkit_contact_us_recipient',
          'name' => 'Recipient',
          'type' => 'hidden',
          'value' => 'nrn-meeting@enrd.eu',
          'extra' => array(
            'private' => 0,
            'hidden_type' => 'value',
            'analysis' => FALSE,
          ),
          'required' => 0,
          'weight' => 10,
          'page_num' => 1,
        ),
      ),
      'conditionals' => array(),
      'path' => array(
        'source' => 'b1cd0e38-44ba-4455-aaec-34494bb77a85',
      ),
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
    'print_pdf_size' => NULL,
    'print_pdf_orientation' => NULL,
    'pathauto_perform_alias' => FALSE,
  );
  return $nodes;
}
