<?php

/**
 * @file
 * Theme for enrd_mastermind Media plugin.
 */

/**
 * Implementation of template preprocess for the view.
 */
function template_preprocess_enrd_mastermind_media_plugin_style(&$vars) {
  template_preprocess_views_view_unformatted($vars);
}

/**
 * Implementation of template preprocess for the view fields.
 */
function template_preprocess_enrd_mastermind_media_plugin_rows(&$vars) {
  $vars['options']['default_field_elements'] = '';
  template_preprocess_views_view_fields($vars);

  $view = &$vars['view'];
  $options = $vars['options'];

  foreach ($options as $id => $field) {
    if ($id == 'metadata_field') {
      if (($key = array_search(0, $field)) !== FALSE) {
        unset($field[$key]);
      }

      foreach ($field as $key => $value) {
        if (!isset($view->field[$value])) {
          unset($options[$id][$key]);
        }
      }
      continue;
    }

    if (!isset($view->field[$field])) {
      unset($options[$id]);
    }
  }
}
