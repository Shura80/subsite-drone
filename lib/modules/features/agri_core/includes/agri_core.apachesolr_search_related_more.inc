<?php

/**
 * @file
 * agri_core.apachesolr_search_related_more.inc
 */

/**
 * Callback to get related content of a given node and block configuration.
 *
 * @param object $node
 *   The node object to search related content for.
 *
 * @throws Exception
 *
 * @return array
 *   Return a renderizable array with results list.
 */
function agri_core_more_solr_related_content($node) {

  // Get the node nid to filter block results.
  $nid = $node->nid;
  $delta = 'agri-mlt-' . $node->type;
  // Load apachesolr internal block delta.
  $block = apachesolr_search_mlt_block_load($delta);

  // Is Solr mlt is defined build an array with other suggestions.
  if ($block) {
    // Set a custom number of results to show in "Show more" link page.
    $block['num_results'] = 50;
    // Get solr default environment object.
    $solr_default = apachesolr_default_environment();
    $solr_env = apachesolr_get_solr($solr_default);
    // Set the search type ("More like this").
    $context['search_type'] = 'apachesolr_search_mlt';
    $context['block_id'] = $delta;

    // Get the results from built query for related content.
    $docs = apachesolr_search_mlt_suggestions($block, apachesolr_document_id($nid), $solr_env, $context);

    // If the Solr query return results, theme with mlt_recommendation_block.
    if (!empty($docs)) {
      $link_path = drupal_get_path_alias('node/' . $node->nid);
      $suggestions['content'] = [
        '#theme' => 'apachesolr_search_mlt_recommendation_block',
        '#docs' => $docs,
        '#delta' => $delta,
      ];

      // Render a link to more suggestions page.
      $suggestions['show_more_link'] = [
        '#theme' => 'link',
        '#text' => t('Back'),
        '#path' => $link_path,
        '#options' => [
          'attributes' => [
            'class' => ['solr-related back'],
            'title' => t('Go back to the previous page'),
          ],
          'html' => TRUE,
        ],
      ];
      // Add a dynamic title of the source node.
      drupal_set_title(t('More related content for !arg', ['!arg' => $node->title]));

      return $suggestions;
    }
  }
  // Cannot load related content for node, so show a 404 page.
  drupal_not_found();
}
