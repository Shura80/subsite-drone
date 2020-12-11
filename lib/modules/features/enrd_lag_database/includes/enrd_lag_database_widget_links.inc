<?php

/**
 * @file
 * The enrd_facetapi_checkbox_links widget plugin alter configuration.
 */

/**
 * Custom widget that renders facets as a list of clickable checkboxes.
 *
 * This widget renders facets in the same way as FacetapiWidgetCheckboxLinks
 * but renders directly the content without wrapping the items with an <ul>.
 */
class EnrdLagDatabaseFacetapiWidgetCheckboxLinks extends FacetapiWidgetCheckboxLinks {

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
    $element = &$this->build[$this->facet['field alias']];

    // Sets each item's theme hook, builds item list.
    $this->setThemeHooks($element);
    $items = $this->buildListItems($element);

    $element = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'facetapi-facetapi-enrd-checkbox-links',
          'facetapi-facet-' . str_replace('_', '-', $this->facet['field alias']),
        ),
        'id' => 'facetapi-facet-apachesolrsolr-block-' . str_replace('_', '-', $this->facet['field alias']),
      ),
    );

    if (!empty($items)) {
      foreach ($items as $key => $item) {
        $element[$key] = array(
          '#markup' => $item['data'],
          '#prefix' => '<div>',
          '#suffix' => '</div>',
        );
      }
    }

  }

}
