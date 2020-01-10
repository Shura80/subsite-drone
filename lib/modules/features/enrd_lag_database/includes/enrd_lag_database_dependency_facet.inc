<?php

/**
 * @file
 * Performs a dependency check against other specified facets/facet values.
 */

/**
 * Adds a dependency on another facet being active.
 */
class EnrdLagDatabaseDependencyFacet extends FacetapiDependencyFacet {

  /**
   * Executes the dependency check.
   */
  public function execute() {

    $facets = array_filter($this->settings['facets_multiple']);
    // Show this facet if no facet dependencies are configured.
    if (count($facets) > 0) {
      $active_facets = 0;

      foreach ($facets as $facet_name) {
        // Dependency is met.
        if ($this->activeItems[$facet_name]) {
          $active_facets++;
        }
      }

      return count($facets) == $active_facets;
    }
  }

  /**
   * Adds dependency settings to the form.
   */
  public function settingsForm(&$form, &$form_state) {

    // Get enabled facets (minus this dependency's one).
    $facets = $this->getEnabledFacets();

    $form[$this->id]['facets_multiple'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Show this facet only for specific other facets'),
      '#default_value' => $this->settings['facets_multiple'],
      '#options' => array_map('check_plain', $facets),
      '#description' => t('Show this facet only if all these selected facet(s) is actively in use. If you select no other facets, the facet will be visible not depend on other facets.'),
    );

  }

  /**
   * Returns defaults for settings.
   *
   * Has to be dynamic since we want a detail settings field for each dependency
   * but the enabled facets are not known yet (afaik, hence the add. property)
   */
  public function getDefaultSettings() {
    if (!count($this->defaultSettings)) {
      $this->defaultSettings = array(
        'facets_multiple' => array(),
      );
    }
    return $this->defaultSettings;
  }

}
