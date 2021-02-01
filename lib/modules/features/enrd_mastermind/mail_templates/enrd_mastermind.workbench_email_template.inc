<?php

/**
 * @file
 * File workbench_mail.template.inc.
 */

/**
 * Definition default template for module workbench_email.
 *
 * @return array
 *   Return custom settings of workbench_email.
 */
function _enrd_mastermind_workbench_email_get_settings() {
  $items = array(
    'draft:needs_review:editor' => array(
      'from_name' => 'draft',
      'to_name' => 'needs_review',
      'role' => 'editor',
      'automatic' => 1,
      'subject' => '[site:name] Workflow - "[node:title_field]" needs to be reviewed',
      'message' => 'Dear Editor,
Content "[node:title_field]" needs to be reviewed.
Please follow this link: [node:url]
Login page: [site:login-url]

For more information on EU Login, please refer to the following documentation:
[site:eu-login-tutorial].

Please do not reply to this automated message.',
    ),

    'needs_review:draft:original-author' => array(
      'from_name' => 'needs_review',
      'to_name' => 'draft',
      'role' => 'workbench-email:original-author-of-node',
      'automatic' => 1,
      'subject' => '[site:name] Workflow - "[node:title_field]" needs to be reviewed',
      'message' => 'Dear Author,
Content "[node:title_field]" has not been approved and needs to be reviewed.
Please follow this link: [node:url]
Login page: [site:login-url]

For more information on EU Login, please refer to the following documentation:
[site:eu-login-tutorial].

Please do not reply to this automated message.',
    ),

    'needs_review:validated:publisher' => array(
      'from_name' => 'needs_review',
      'to_name' => 'validated',
      'role' => 'publisher',
      'automatic' => 1,
      'subject' => '[site:name] Workflow - "[node:title_field]" ready for publication',
      'message' => 'Dear Publisher,
Content "[node:title_field]" has been moved in "Validated" status and is ready for publication.
Please follow this link: [node:url]
Login page: [site:login-url]

For more information on EU Login, please refer to the following documentation:
[site:eu-login-tutorial].

Please do not reply to this automated message.',
    ),

    'needs_review:published:original-author' => array(
      'from_name' => 'needs_review',
      'to_name' => 'published',
      'role' => 'workbench-email:original-author-of-node',
      'automatic' => 1,
      'subject' => '[site:name] Workflow - "[node:title_field]" has been published',
      'message' => 'Dear Author,
Content "[node:title_field]" has been published.
Please follow this link: [node:url]
Login page: [site:login-url]

For more information on EU Login, please refer to the following documentation:
[site:eu-login-tutorial].

Please do not reply to this automated message.',
    ),

    'validated:published:original-author' => array(
      'from_name' => 'validated',
      'to_name' => 'published',
      'role' => 'workbench-email:original-author-of-node',
      'automatic' => 1,
      'subject' => '[site:name] Workflow - "[node:title_field]" has been published',
      'message' => 'Dear Author,
Content "[node:title_field]" has been published.
Please follow this link: [node:url]
Login page: [site:login-url]

For more information on EU Login, please refer to the following documentation:
[site:eu-login-tutorial].

Please do not reply to this automated message.',
    ),

    'published:archived:original-author' => array(
      'from_name' => 'published',
      'to_name' => 'archived',
      'role' => 'workbench-email:original-author-of-node',
      'automatic' => 0,
      'subject' => '[site:name] Workflow - "[node:title_field]" has been archived',
      'message' => 'Dear Author,
Content "[node:title_field]" has been archived.
Please follow this link: [node:url]
Login page: [site:login-url]

For more information on EU Login, please refer to the following documentation:
[site:eu-login-tutorial].

Please do not reply to this automated message.',
    ),

    'published:archived:publisher' => array(
      'from_name' => 'published',
      'to_name' => 'archived',
      'role' => 'publisher',
      'automatic' => 1,
      'subject' => '[site:name] Workflow - "[node:title_field]" has been archived',
      'message' => 'Dear Publisher,
Content "[node:title_field]" has been archived.
Please follow this link: [node:url]
Login page: [site:login-url]

For more information on EU Login, please refer to the following documentation:
[site:eu-login-tutorial].

Please do not reply to this automated message.',
    ),

  );
  return $items;
}
