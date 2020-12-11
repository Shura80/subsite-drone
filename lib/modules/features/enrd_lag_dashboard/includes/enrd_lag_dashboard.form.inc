<?php

/**
 * @file
 * File enrd_lag_dashboard.form.inc.
 */

/**
 * Implements hook_form().
 */
function enrd_lag_dashboard_lag_profile_form($form, &$form_state, $nid) {

  if ($nid && $node = node_load($nid)) {
    $revisions = node_revision_list($node);

    if (isset($node->workbench_moderation['current']) && $node->workbench_moderation['current']->state != workbench_moderation_state_published()) {
      $draft_revision = $node->workbench_moderation['current'];

      $node_current = workbench_moderation_node_current_load($node);
      $moderation = t('The current state is %state.', array('%state' => workbench_moderation_state_label($node->workbench_moderation['current']->state)));
      $moderate_form = drupal_get_form('workbench_moderation_moderate_form', $node_current);
      if (isset($moderate_form['state'])) {

        if ($moderate_form['state']['#type'] == 'value') {
          $moderation .= '<div class="moderation-actions">' . drupal_render($moderate_form) . '</div>';
        }
        else {
          $moderation .= '<div class="moderation-actions">' . t('Set moderation state: !moderation-actions-form', array('!moderation-actions-form' => drupal_render($moderate_form))) . '</div>';
        }
      }
      else {
        $moderation .= '<br />' . t('This update will be validated and put online by the webmaster.');
      }

      $items_operations[] = l(t('view update'), "node/$draft_revision->nid/draft");
      if (node_access('update', $node)) {
        $items_operations[] = l(t('edit'), "node/$draft_revision->nid/edit");
      }
      $items_operations[] = l(t('see history of updates'), "node/$draft_revision->nid/moderation");

      $form['draft_revision'] = [
        '#caption' => t('LAG profile update'),
        '#theme' => 'table',
        '#rows' => [
          [
            check_plain($draft_revision->title),
            format_date($draft_revision->timestamp, 'short'),
            check_plain($revisions[$draft_revision->vid]->name),
            theme('item_list', array('items' => $items_operations)),
            $moderation,
          ],
        ],
        '#header' => [
          t('LAG name'),
          t('Update date'),
          t('Update author'),
          t('Operations'),
          t('Status'),
        ],
        '#attributes' => array(
          'class' => array(
            'draft-revision',
          ),
        ),
        '#weight' => 1,
      ];
    }

    if (isset($node->workbench_moderation['published'])) {
      $pub_revision = $node->workbench_moderation['published'];

      $items_operations = array(
        l(t('view'), "node/$pub_revision->nid"),
      );
      if (!isset($form['draft_revision']) && node_access('update', $node)) {
        $items_operations[] = l(t('update lag profile'), "node/$pub_revision->nid/edit");
      }

      $form['published_revision'] = [
        '#caption' => t('LAG profile currently online'),
        '#theme' => 'table',
        '#rows' => [
          [
            check_plain($pub_revision->title),
            format_date($pub_revision->timestamp, 'short'),
            check_plain($revisions[$pub_revision->vid]->name),
            theme('item_list', array('items' => $items_operations)),
          ],
        ],
        '#header' => [
          t('LAG name'),
          t('Published on'),
          t('Published by'),
          t('Operations'),
        ],
        '#attributes' => array(
          'class' => array(
            'published-revision',
          ),
        ),
        '#weight' => 2,
      ];

    }
  }

  return $form;
}

/**
 * Contextual page for.
 *
 * @param int $lag
 *   The lag nid.
 *
 * @return array
 *   Renderable array.
 */
function enrd_lag_dashboard_contextual_dashboard($lag) {

  $output = array();

  $views_blocks = array(
    // enrd_lag_dashboard_published_cooperation_offers:coop_offers_published.
    'b19f501af737049d9be5365a2f2c2947',
    // enrd_lag_dashboard_contextual_cooperation_offers:coop_offers_draft.
    '2dc9cd7ca73cd051924217a5d7e6ddea',
    // enrd_lag_dashboard_contextual_cooperation_offers:coop_offers_pending.
    '1e5d0942cbb010350ba84366ec57c0aa',
    // enrd_lag_dashboard_contextual_cooperation_offers:coop_offers_archived.
    '0a6ac29e4f8dcbf2d06dec250c08ecf0',
  );

  foreach ($views_blocks as $delta) {
    $block = block_load('views', $delta);
    $output[] = _block_get_renderable_array(_block_render_blocks(array($block)));
  }

  return $output;
}
