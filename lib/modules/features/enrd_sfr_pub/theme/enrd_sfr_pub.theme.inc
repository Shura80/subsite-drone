<?php

/**
 * @file
 * Theme related functions for processing our output style plugins.
 */

/**
 * Theme callback for the export of the header.
 *
 * @param array $vars
 *   An associative array with the views information.
 *
 * @see \template_preprocess_views_data_export_csv_header()
 */
function template_preprocess_enrd_sfr_pub_cp_csv_header(array &$vars) {
  _views_data_export_header_shared_preprocess($vars);
  _enrd_sfr_pub_export_cp_add_custom_header($vars);

  // Special handling when quoted values are involved.
  if ($vars['options']['quote']) {
    $wrap = '"';
    $replace_value = '""';
  }
  else {
    $wrap = '';
    $replace_value = '';
  }

  foreach ($vars['header'] as $key => $value) {
    $output = decode_entities($value);
    $output = (empty($vars['options']['keep_html'])) ? strip_tags($output) : $output;
    if (!empty($vars['options']['trim'])) {
      $output = trim($output);
    }
    if (!empty($vars['options']['encoding']) && function_exists('iconv')) {
      switch ($vars['options']['encoding']) {

        case 'utf8_decode':
          $converted = utf8_decode($output);
          break;

        default:
          $converted = iconv("UTF-8", $vars['options']['encoding'], $output);
          break;
      }
      if ($converted !== FALSE) {
        $output = $converted;
      }
    }
    $vars['header'][$key] = $wrap . str_replace('"', $replace_value, $output) . $wrap;
  }
}

/**
 * Theme callback for the export of the body.
 *
 * @param array $vars
 *   An associative array with the views information.
 *
 * @see \template_preprocess_views_data_export_csv_body()
 */
function template_preprocess_enrd_sfr_pub_cp_csv_body(array &$vars) {
  _views_data_export_body_shared_preprocess($vars);

  // Special handling when quoted values are involved.
  if ($vars['options']['quote']) {
    $wrap = '"';
    $replace_value = '""';
  }
  else {
    $wrap = '';
    $replace_value = '';
  }

  // Format row values.
  foreach ($vars['themed_rows'] as $row_index => $row_value) {

    $views_row = $vars['rows'][$row_index];
    $entity_enrd_sfr = $views_row->_field_data['sfrid']['entity'];

    _enrd_sfr_pub_export_cp_add_custom_row_value($row_value, $row_index, $entity_enrd_sfr);

    foreach ($row_value as $j => $value) {
      $output = decode_entities($value);
      $output = (empty($vars['options']['keep_html'])) ? strip_tags($output) : $output;
      if (!empty($vars['options']['trim'])) {
        $output = trim($output);
      }

      if (!empty($vars['options']['encoding']) && function_exists('iconv')) {
        switch ($vars['options']['encoding']) {
          case 'utf8_decode':
            $converted = utf8_decode($output);
            break;

          default:
            $converted = iconv("UTF-8", $vars['options']['encoding'], $output);
            break;
        }
        if ($converted !== FALSE) {
          $output = $converted;
        }
      }
      if (!empty($vars['options']['replace_newlines'])) {
        if (!empty($vars['options']['newline_token'])) {
          $output = str_replace(array("\r\n", "\r", "\n"), $vars['options']['newline_replacement'], $output);
        }
        else {
          $output = str_replace("\n", $vars['options']['newline_replacement'], $output);
        }
      }
      $vars['themed_rows'][$row_index][$j] = $wrap . str_replace('"', $replace_value, $output) . $wrap;
    }
  }
}

/**
 * Add the header column for the csv file.
 *
 * @param array $vars
 *   An associative array with the views information.
 */
function _enrd_sfr_pub_export_cp_add_custom_header(array &$vars) {
  $vars['header'] += array_keys(_enrd_sfr_pub_export_cp_get_custom_column());
}

/**
 * Add the custom column for each row of the csv file.
 *
 * @param array $row_values
 *   The values of the row exposed from views results.
 * @param int $row_index
 *   The row index.
 * @param object $entity_enrd_sfr
 *   The entire entity "enrd_sfr".
 */
function _enrd_sfr_pub_export_cp_add_custom_row_value(array &$row_values, $row_index, $entity_enrd_sfr) {

  $column = _enrd_sfr_pub_export_cp_get_custom_column();
  $field_collection_name = 'field_enrd_sfr_pub_subcp_type';

  $fc_field_values = _enrd_sfr_pub_export_cp_get_field_collection_value($field_collection_name, $entity_enrd_sfr);

  foreach ($fc_field_values as $fc_field_value) {
    _enrd_sfr_pub_export_cp_set_fields($column, $fc_field_value);
  }

  $row_values += $column;
}

/**
 * Get all field value from a field collection field.
 *
 * @param string $field_name
 *   The machine name of the field_collection field.
 * @param object $entity
 *   The entity object.
 *
 * @return array
 *   An array field_name|value for each element of the field collection item.
 */
function _enrd_sfr_pub_export_cp_get_field_collection_value($field_name, $entity) {

  $fc_field_values = array();

  $e_wrapper = entity_metadata_wrapper(ENRD_SFR_ENTITY_NAME, $entity);
  $field_collection_value = $e_wrapper->{$field_name}->value();
  $fc_fields = array_keys(field_info_instances('field_collection_item', $field_name));

  foreach ($field_collection_value as $key => $field_collection_obj) {
    $fc_wrapper = entity_metadata_wrapper('field_collection_item', $field_collection_obj);

    foreach ($fc_fields as $fc_field_name) {
      $fc_field_values[$key][$fc_field_name] = $fc_wrapper->{$fc_field_name}->value();
    }
  }

  return $fc_field_values;
}

/**
 * Handler that set the value for custom columns for each row.
 *
 * @param array $column
 *   The reference to the column of the row.
 * @param array $fc_field_value
 *   An array field_name|value of the field collection item.
 */
function _enrd_sfr_pub_export_cp_set_fields(array &$column, array $fc_field_value) {

  // Set column "Subscriptions[type_publication]_[type_publication]".
  $type_of_publication = $fc_field_value['field_enrd_sfr_pub_subcp_typepub'];
  $type_publication_column_index = 'Subscriptions' . $type_of_publication . '_' . $type_of_publication;
  $column[$type_publication_column_index] = 'Yes';

  // Paper version.
  if ($fc_field_value['field_enrd_sfr_pub_subcp_paper']) {
    // If "paper" for 1 or more Type of Publications.
    $column['Communicationtype_Papersubscription'] = 'Yes';

    // For each "type publication" set the language and number of copies column.
    foreach ($fc_field_value['field_enrd_sfr_pub_subcp_lng_cop'] as $copies_version) {
      $lang = drupal_strtoupper($copies_version['first']);
      $n_copies = $copies_version['second'];

      $paper_lang_column_index = 'Subscriptions' . $type_of_publication . '_Paper' . $lang;
      $paper_quantity_column_index = 'Subscriptions' . $type_of_publication . '_Quantity' . $lang;
      $column[$paper_lang_column_index] = 'Yes';
      $column[$paper_quantity_column_index] = $n_copies;
    }
  }

  // Electronic version.
  if ($fc_field_value['field_enrd_sfr_pub_subcp_electr']) {
    // If "electronic" for 1 or more Type of Publications.
    $column['Communicationtype_Electronicsubscriptions'] = 'Yes';

    // Set language (EN and/or Other).
    foreach ($fc_field_value['field_enrd_sfr_pub_subcp_el_lang'] as $elettronic_lang) {
      if ($elettronic_lang == 'EN') {
        $elettronic_lang_en_column_index = 'Subscriptions' . $type_of_publication . '_ElecEN';
        $column[$elettronic_lang_en_column_index] = 'Yes';
      }
      else {
        $elettronic_lang_other_column_index = 'Subscriptions' . $type_of_publication . '_ElecOTHER';
        $column[$elettronic_lang_other_column_index] = 'Yes';
      }
    }
  }
}

/**
 * The mapping for custom columns added after the "views" fields.
 *
 * @return array
 *   Return an associative array [column_name] => [default_value].
 */
function _enrd_sfr_pub_export_cp_get_custom_column() {
  // Set all values to empty for future implementations of the default value.
  return array(
    'Communicationtype_Papersubscription' => '',
    'Communicationtype_Electronicsubscriptions' => '',
    'SubscriptionsEURuralReview_EURuralReview' => '',
    'SubscriptionsEURuralReview_PaperEN' => '',
    'SubscriptionsEURuralReview_QuantityEN' => '',
    'SubscriptionsEURuralReview_PaperFR' => '',
    'SubscriptionsEURuralReview_QuantityFR' => '',
    'SubscriptionsEURuralReview_PaperDE' => '',
    'SubscriptionsEURuralReview_QuantityDE' => '',
    'SubscriptionsEURuralReview_PaperIT' => '',
    'SubscriptionsEURuralReview_QuantityIT' => '',
    'SubscriptionsEURuralReview_PaperES' => '',
    'SubscriptionsEURuralReview_QuantityES' => '',
    'SubscriptionsEURuralReview_PaperPL' => '',
    'SubscriptionsEURuralReview_QuantityPL' => '',
    'SubscriptionsEURuralReview_ElecEN' => '',
    'SubscriptionsEURuralReview_ElecOTHER' => '',
    'SubscriptionsEAFRDProjectsBrochure_EAFRDProjectsBrochure' => '',
    'SubscriptionsEAFRDProjectsBrochure_PaperEN' => '',
    'SubscriptionsEAFRDProjectsBrochure_QuantityEN' => '',
    'SubscriptionsEAFRDProjectsBrochure_PaperFR' => '',
    'SubscriptionsEAFRDProjectsBrochure_QuantityFR' => '',
    'SubscriptionsEAFRDProjectsBrochure_PaperDE' => '',
    'SubscriptionsEAFRDProjectsBrochure_QuantityDE' => '',
    'SubscriptionsEAFRDProjectsBrochure_PaperIT' => '',
    'SubscriptionsEAFRDProjectsBrochure_QuantityIT' => '',
    'SubscriptionsEAFRDProjectsBrochure_PaperES' => '',
    'SubscriptionsEAFRDProjectsBrochure_QuantityES' => '',
    'SubscriptionsEAFRDProjectsBrochure_PaperPL' => '',
    'SubscriptionsEAFRDProjectsBrochure_QuantityPL' => '',
    'SubscriptionsEAFRDProjectsBrochure_ElecEN' => '',
    'SubscriptionsEAFRDProjectsBrochure_ElecOTHER' => '',
    'SubscriptionsRuralConnections_RuralConnections' => '',
    'SubscriptionsRuralConnections_PaperEN' => '',
    'SubscriptionsRuralConnections_QuantityEN' => '',
    'SubscriptionsRuralConnections_PaperFR' => '',
    'SubscriptionsRuralConnections_QuantityFR' => '',
    'SubscriptionsRuralConnections_PaperDE' => '',
    'SubscriptionsRuralConnections_QuantityDE' => '',
    'SubscriptionsRuralConnections_PaperIT' => '',
    'SubscriptionsRuralConnections_QuantityIT' => '',
    'SubscriptionsRuralConnections_PaperES' => '',
    'SubscriptionsRuralConnections_QuantityES' => '',
    'SubscriptionsRuralConnections_PaperPL' => '',
    'SubscriptionsRuralConnections_QuantityPL' => '',
    'SubscriptionsRuralConnections_ElecEN' => '',
    'SubscriptionsRuralConnections_ElecOTHER' => '',
  );
}
