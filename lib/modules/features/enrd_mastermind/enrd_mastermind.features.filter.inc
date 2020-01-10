<?php

/**
 * @file
 * enrd_mastermind.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function enrd_mastermind_filter_default_formats() {
  $formats = array();

  // Exported format: Basic HTML.
  $formats['basic_html'] = (object) array(
    'format' => 'basic_html',
    'name' => 'Basic HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => 5,
    'filters' => array(
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'toolbox_sanitize' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_html' => array(
        'weight' => 1,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a> <em> <strong> <abbr> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_autop' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: ENRD Newsletter Archive.
  $formats['enrd_newsletter_archive'] = (object) array(
    'format' => 'enrd_newsletter_archive',
    'name' => 'ENRD Newsletter Archive',
    'cache' => 0,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'toolbox_sanitize' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => 1,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_basepath' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
      'media_filter' => array(
        'weight' => 3,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 4,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_tokens' => array(
        'weight' => 5,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Safe HTML.
  $formats['enrd_safe_html'] = (object) array(
    'format' => 'enrd_safe_html',
    'name' => 'Safe HTML',
    'cache' => 0,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'filter_tokens' => array(
        'weight' => -47,
        'status' => 1,
        'settings' => array(),
      ),
      'toolbox_sanitize' => array(
        'weight' => -46,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_basepath' => array(
        'weight' => -41,
        'status' => 1,
        'settings' => array(),
      ),
      'media_filter' => array(
        'weight' => -39,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => -38,
        'status' => 1,
        'settings' => array(),
      ),
      'invisimail_encode_html_entities' => array(
        'weight' => -37,
        'status' => 1,
        'settings' => array(
          'encoder' => 'html_entities',
          'chunk' => 1,
          'link' => 1,
        ),
      ),
    ),
  );

  // Exported format: Filtered HTML.
  $formats['filtered_html'] = (object) array(
    'format' => 'filtered_html',
    'name' => 'Filtered HTML',
    'cache' => 0,
    'status' => 1,
    'weight' => -9,
    'filters' => array(
      'toolbox_sanitize' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => 1,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_basepath' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
      'media_filter' => array(
        'weight' => 4,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 5,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_html' => array(
        'weight' => 6,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a> <em> <strong> <abbr> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd> <table> <th> <tr> <td> <caption> <colgroup> <col> <br> <p> <colgroup> <thead> <tbody> <tfoot> <map> <area><img> <span>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'invisimail_encode_html_entities' => array(
        'weight' => 7,
        'status' => 1,
        'settings' => array(
          'encoder' => 'html_entities',
          'chunk' => 1,
          'link' => 1,
        ),
      ),
      'filter_tokens' => array(
        'weight' => 8,
        'status' => 1,
        'settings' => array(),
      ),
      'collapse_text_filter' => array(
        'weight' => 9,
        'status' => 1,
        'settings' => array(
          'form' => 1,
          'default_title' => 'Click here to expand or collapse this section',
        ),
      ),
    ),
  );

  // Exported format: Full HTML.
  $formats['full_html'] = (object) array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'cache' => 0,
    'status' => 1,
    'weight' => -10,
    'filters' => array(
      'toolbox_sanitize' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_basepath' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
      'media_filter' => array(
        'weight' => 4,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 5,
        'status' => 1,
        'settings' => array(),
      ),
      'invisimail_encode_html_entities' => array(
        'weight' => 7,
        'status' => 1,
        'settings' => array(
          'encoder' => 'html_entities',
          'chunk' => 1,
          'link' => 1,
        ),
      ),
      'filter_tokens' => array(
        'weight' => 8,
        'status' => 1,
        'settings' => array(),
      ),
      'collapse_text_filter' => array(
        'weight' => 9,
        'status' => 1,
        'settings' => array(
          'form' => 1,
          'default_title' => 'Click here to expand or collapse this section',
        ),
      ),
    ),
  );

  // Exported format: Plain text.
  $formats['plain_text'] = (object) array(
    'format' => 'plain_text',
    'name' => 'Plain text',
    'cache' => 1,
    'status' => 1,
    'weight' => -8,
    'filters' => array(
      'invisimail_encode_html_entities' => array(
        'weight' => -49,
        'status' => 1,
        'settings' => array(
          'encoder' => 'html_entities',
          'chunk' => 1,
          'link' => 1,
        ),
      ),
      'filter_html_escape' => array(
        'weight' => -48,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_basepath' => array(
        'weight' => -46,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => -39,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_autop' => array(
        'weight' => -38,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
