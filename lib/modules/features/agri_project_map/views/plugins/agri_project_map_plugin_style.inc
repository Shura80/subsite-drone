<?php

/**
 * @file
 * Definition of agri_project_map_plugin_style.
 */

/**
 * Class to define a style plugin handler.
 */
class agri_project_map_plugin_style extends views_plugin_style {

  /**
   * Set default options.
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['map_background'] = array('default' => 'graybg');
    $options['map_zoom'] = array('default' => '3');
    return $options;
  }

  /**
   * Options form.
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['map_background'] = array(
      '#title' => t('Map background'),
      '#type' => 'select',
      '#options' => array(
        'graybg' => t('graybg'),
        'graybg_eu28' => t('graybg_eu28'),
      ),
      '#default_value' => $this->options['map_background'],
    );

    $form['map_zoom'] = array(
      '#title' => t('Map zoom'),
      '#type' => 'textfield',
      '#default_value' => $this->options['map_zoom'],
    );

  }

  /**
   * Allow the style to do stuff before each row is rendered.
   *
   * @param mixed $result
   *   The full array of results from the query.
   */
  public function pre_render($result) {

    $countries = array();
    $regions = array();
    $fields = array_keys($this->view->field);

    foreach ($result as $index => $row) {
      foreach ($fields as $field_id) {
        $field_value = $this->get_field($index, $field_id);
        if (!empty($field_value)) {
          if (drupal_strlen($field_value) == 2 && !in_array($field_value, $countries)) {
            $countries[] = $field_value;
          }

          if (drupal_strlen($field_value) > 2 && !in_array($field_value, $regions)) {
            $regions[] = $field_value;
          }
        }
      }
    }

    drupal_add_js(array(
      'agri_project_map' => array(
        'countries' => $countries,
        'regions' => $regions,
        'custom_options' => $this->options,
        'current_display' => $this->view->current_display,
      ),
    ), 'setting');

  }

  /**
   * Render the display in this style.
   */
  public function render() {

    $smartloader_prurl = variable_get('agri_core_webtools_smartloader_prurl', AGRI_CORE_WEBTOOLS_SMARTLOADER_PRURL);
    if (!empty($smartloader_prurl)) {

      if (isset($this->view->live_preview) && $this->view->live_preview) {
        return t('Selected style are not compatible with live preview.');
      }

      drupal_add_js($smartloader_prurl, array(
        'type' => 'external',
        'defer' => 'defer',
      ));

      $json_array = array(
        'service' => 'map',
        'custom' => array(
          base_path() . drupal_get_path('module', 'agri_project_map') . '/js/agri_project_map.js',
        ),
        'version' => '2.0',
      );

      // The drupal_json_encode() wrapper does not accept options parameters.
      // @codingStandardsIgnoreLine - see MULTISITE-19190
      $element['#markup'] = json_encode($json_array, JSON_UNESCAPED_SLASHES);
      $element['#prefix'] = '<div class="project-map"><script type="application/json">';
      $element['#suffix'] = '</script></div>';

      return drupal_render($element);

    }
  }

}
