<?php

/**
 * @file
 * The enrd_facetapi_dropdown_links widget plugin alter configuration.
 */

/**
 * Custom widget that renders facets as a list of clickable checkboxes.
 *
 * This widget renders facets in the same way as FacetapiWidgetCheckboxLinks
 * but renders directly the content without wrapping the items with an <ul>.
 */
class EnrdNrnToolkitFacetapiWidgetLinks extends FacetapiWidgetLinks {

  /**
   * Implements FacetapiWidget::execute().
   *
   * Transforms the render array into something that can be wrapped
   * around a <div> element.
   *
   * @see FacetapiWidgetLinks::setThemeHooks()
   * @see FacetapiWidgetLinks::buildListItems()
   */
  public function execute() {
    $element =& $this->build[$this->facet['field alias']];

    // Sets each item's theme hook, builds recursive item list.
    $this->setThemeHooks($element);
    $items = $this->buildListItems($element);

    $element = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'facetapi-enrd-facetapi-dropdown-links',
          'facetapi-facet-' . str_replace('_', '-', $this->facet['field alias']),
        ),
        'id' => 'facetapi-facet-apachesolrsolr-block-' . str_replace('_', '-', $this->facet['field alias']),
      ),
    );

    if (!empty($items)) {
      foreach ($items as $key => $item) {
        $element[$key] = array(
          '#markup' => $item['data'],
        );
      }
    }

  }

  /**
   * Transforms the parent-child render array for use with a custom theme.
   *
   * The recursion allows this function to act on the various levels of a
   * hierarchical data set.
   *
   * @param mixed $build
   *   The items in the facet's render array being transformed.
   *
   * @return array
   *   The "items" parameter for theme_item_list().
   */
  public function buildListItems($build) {
    $settings = $this->settings->settings;

    // Initializes links attributes, adds rel="nofollow" if configured.
    $attributes = ($settings['nofollow']) ? array('rel' => 'nofollow') : array();
    $attributes += array('class' => $this->getItemClasses());

    // Builds rows.
    $items = array();
    foreach ($build as $item) {

      $row = array('class' => array(), 'data' => array());

      // Allow adding classes via altering.
      if (isset($item['#class'])) {
        $attributes['class'] = array_merge($attributes['class'], $item['#class']);
      }
      // Initializes variables passed to theme hook.
      $variables = array(
        'text' => $item['#markup'],
        'path' => $item['#path'],
        'count' => $item['#count'],
        'options' => array(
          'attributes' => $attributes,
          'html' => $item['#html'],
          'query' => $item['#query'],
        ),
      );

      // Adds the facetapi-zero-results class to items that have no results.
      if (!$item['#count']) {
        $variables['options']['attributes']['class'][] = 'facetapi-zero-results';
      }

      // Add an ID to identify this link.
      $variables['options']['attributes']['id'] = drupal_html_id('facetapi-link');

      // If the item has no children, it is a leaf and it should be built
      // to be passed to the parent item for theming purposes.
      if (empty($item['#item_children'])) {
        $row['child'] = array(
          'text' => $item['#markup'],
          'path' => $item['#path'],
          'count' => $item['#count'],
          'options' => array(
            'attributes' => $attributes,
            'html' => $item['#html'],
            'query' => $item['#query'],
          ),
        );
      }
      else {
        // If the item is active or the "show_expanded" setting is selected,
        // show this item as expanded so we see its children.
        if ($item['#active'] || !empty($settings['show_expanded'])) {
          $row['class'][] = 'expanded';
          $row['children'] = $this->buildListItems($item['#item_children']);
        }
        else {
          $row['class'][] = 'collapsed';
        }
        // Build the children to be themed with the parent item.
        $variables['children'] = $this->buildListItems($item['#item_children']);
      }

      // Gets theme hook, adds last minute classes.
      $class = array(
        (isset($item['#markup'])) ? drupal_html_class($item['#markup']) : 'generic-nrn-classification',
        ($item['#active']) ? 'facetapi-active' : 'facetapi-inactive',
      );
      $variables['options']['attributes']['class'] = $class;
      $variables['children'] = $this->buildListItems($item['#item_children']);

      // Themes the link, adds row to items.
      $row['data'] = theme($item['#theme'], $variables);
      $items[] = $row;
    }

    return $items;
  }

}
