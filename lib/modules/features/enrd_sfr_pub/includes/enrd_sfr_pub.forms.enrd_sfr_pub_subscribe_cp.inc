<?php

/**
 * @file
 * Code for enrd_sfr_pub_subscribe_cp form customizations.
 */

/**
 * Customizations on the ENRD Sfr Subscription CP Form.
 *
 * @param mixed $form
 *   Drupal form array.
 * @param mixed $form_state
 *   Drupal form state array.
 */
function _enrd_sfr_pub_subscribe_cp_customizations(&$form, &$form_state) {
  // After build alterations.
  $form['#after_build'][] = '_enrd_sfr_pub_subscribe_cp_form_after_build';

  // Actually make fields required according to the respective fields.
  $form['#validate'][] = '_enrd_sfr_pub_subscribe_cp_form_validate';

  // Prefill form fields for Authenticated.
  _enrd_sfr_pub_prefill_form_fields(array(
    'field_enrd_sfr_pub_subcp_name' => 'name',
    'field_enrd_sfr_pub_subcp_surname' => 'surname',
    'field_enrd_sfr_pub_subcp_email' => 'email',
  ), $form);

  // Specific js behaviors for subscriptions form.
  $form['#attached']['js'][] = [
    'type' => 'file',
    'data' => drupal_get_path('module', 'enrd_sfr_pub') . '/js/enrd_sfr_pub.js',
  ];

  // Customizations on "Type of publication" collection:
  if (isset($form['field_enrd_sfr_pub_subcp_type'][LANGUAGE_NONE])) {

    // "Type of publication" field collection.
    $type_group = &$form['field_enrd_sfr_pub_subcp_type'][LANGUAGE_NONE];

    // Custom theme function.
    $type_group['#theme'] = 'enrd_sfr_pub_subcp_type';

    // Override "Add another item" field collection item button label.
    $type_group['add_more']['#value'] = t('+ Add another publication');

    // Apply conditions to each field collection.
    foreach ($type_group as $type_key => &$type_of_publication) {

      if (is_array($type_of_publication) && is_numeric($type_key)) {

        // Remove (all languages) next to field labels.
        // Note: (all languages) is added because field coll. is translatable.
        if (field_collection_item_is_translatable() && variable_get('entity_translation_shared_labels', TRUE)) {
          foreach (element_children($type_of_publication) as $key) {
            if (isset($type_of_publication[$key]['#process'])) {
              $process_callback = $type_of_publication[$key]['#process'];
              if (($process_key = array_search('entity_translation_element_translatability_clue', $process_callback)) !== FALSE) {
                unset($type_of_publication[$key]['#process'][$process_key]);
              }
            }
          }
        }

        // Override default "- Select a value -" option label.
        $type_of_publication['field_enrd_sfr_pub_subcp_typepub'][LANGUAGE_NONE]['#options']['_none'] = '- Select a type of publication -';

        // Override "Remove" button label for every field collection item.
        $type_of_publication['remove_button']['#value'] = t('- Remove publication');
        // Place the "Remove" button next to "Type of publication".
        $type_of_publication['remove_button']['#weight'] = $type_of_publication['field_enrd_sfr_pub_subcp_typepub']['#weight'] + 1;

        if (isset($type_of_publication['field_enrd_sfr_pub_subcp_lng_cop'][LANGUAGE_NONE]) || isset($type_of_publication['field_enrd_sfr_pub_subcp_el_lang'][LANGUAGE_NONE])) {

          $paper_lang_num_copies_fields = &$type_of_publication['field_enrd_sfr_pub_subcp_lng_cop'][LANGUAGE_NONE];
          $electronic_languages_fields = &$type_of_publication['field_enrd_sfr_pub_subcp_el_lang'][LANGUAGE_NONE];

          // Do not apply theme to Double select.
          $paper_lang_num_copies_fields['#theme'] = '';

          // Override "Language(s)+N.copies" field "Add another item" btn label.
          $paper_lang_num_copies_fields['add_more']['#value'] = t('+ Add other language copies');
          // Force "Add other language copies" btn to be shown at the bottom.
          $paper_lang_num_copies_fields['add_more']['#weight'] = 99;

          // Conditions applied according to "Paper version".
          $paper = array(':input[name="field_enrd_sfr_pub_subcp_type[und][' . $type_key . '][field_enrd_sfr_pub_subcp_paper][und]"]' => array('checked' => TRUE));
          // Conditions applied according to "Electronic version".
          $electronic = array(':input[name="field_enrd_sfr_pub_subcp_type[und][' . $type_key . '][field_enrd_sfr_pub_subcp_electr][und]"]' => array('checked' => TRUE));

          // Field "Language(s) + N. of copies" states.
          $type_of_publication['field_enrd_sfr_pub_subcp_lng_cop']['#states']['visible'] = $paper;
          $type_of_publication['field_enrd_sfr_pub_subcp_lng_cop']['#states']['required'] = $paper;
          // Field "Language(s)" states.
          $type_of_publication['field_enrd_sfr_pub_subcp_el_lang']['#states']['visible'] = $electronic;
          $type_of_publication['field_enrd_sfr_pub_subcp_el_lang']['#states']['required'] = $electronic;

          // Customizations on "Language(s) + N. of copies" field:
          foreach ($paper_lang_num_copies_fields as $key => &$lang_copies_field) {
            // Prepend <span> element to show "x" above "Remove" btn.
            if (is_numeric($key)) {
              $lang_copies_field['remove_button']['#prefix'] = '<span class="glyphicon glyphicon-remove" aria-hidden="true"></span>';
            }
            if (isset($lang_copies_field['_weight'])) {
              // Hide "_weight", ordering select.
              $lang_copies_field['_weight']['#attributes'] = array('class' => array('hidden'));
            }

            if (isset($lang_copies_field['first']) || isset($lang_copies_field['second'])) {
              // Override default "Language(s)" select val. (Double fld).
              $lang_copies_field['first']['#options'][''] = t('Language');
              // Override default "N. of copies" select val. (Double fld).
              $lang_copies_field['second']['#options'][''] = t('Copies');
              // Override "Remove" button label for each paper copy.
              $lang_copies_field['remove_button']['#value'] = t('Remove copy');
            }
          }

          // Override "Choose some options" default with "-Select Language(s)-".
          $electronic_languages_fields['#attributes']['data-placeholder'] = t('- Select Language(s) -');

          // Customizations on "Language(s)" field:
          if (isset($electronic_languages_fields['#options'])) {
            // Remove "- None -" option from Chosen multi field.
            unset($electronic_languages_fields['#options']['_none']);
          }
          // Hide "Language(s)" label.
          $electronic_languages_fields['#title_display'] = 'invisible';
        }
      }
    }

  }

  // Replace "Title" default value.
  if (isset($form['field_enrd_sfr_pub_subcp_petitle'])) {
    $form['field_enrd_sfr_pub_subcp_petitle'][LANGUAGE_NONE]['#options']['_none'] = t('- Select a title -');
  }

  // Customizations on the "Address" field.
  // Apply req. marker if one of the Papers is selected.
  $paper_selected = array(
    array(':input[name="field_enrd_sfr_pub_subcp_type[und][0][field_enrd_sfr_pub_subcp_paper][und]"]' => array('checked' => TRUE)),
    array(':input[name="field_enrd_sfr_pub_subcp_type[und][1][field_enrd_sfr_pub_subcp_paper][und]"]' => array('checked' => TRUE)),
    array(':input[name="field_enrd_sfr_pub_subcp_type[und][2][field_enrd_sfr_pub_subcp_paper][und]"]' => array('checked' => TRUE)),
  );

  if (isset($form['field_enrd_sfr_pub_subcp_addr'][LANGUAGE_NONE][0])) {

    // Addressfield field.
    $address = &$form['field_enrd_sfr_pub_subcp_addr'][LANGUAGE_NONE][0];

    // Make Address fields required if Paper is selected.
    $address['street_block']['thoroughfare']['#states']['required'] = $paper_selected;
    $address['locality_block']['locality']['#states']['required'] = $paper_selected;

    // Override Address 1 & 2 titles.
    $address['street_block']['thoroughfare']['#title'] = t('Address Line 1');
    $address['street_block']['premise']['#title'] = t('Address Line 2');
    // Force maxlength & size to Address 1 & 2.
    $address['street_block']['thoroughfare']['#maxlength'] = ENRD_SFR_PUB_EU_MAXLENGTH;
    $address['street_block']['premise']['#maxlength'] = ENRD_SFR_PUB_EU_MAXLENGTH;
    // Apply description to Address 1 & 2.
    $address['street_block']['thoroughfare']['#description'] = t('Maximum 35 characters.');
    $address['street_block']['premise']['#description'] = t('Maximum 35 characters.');
  }

  // Apply maxlength to "Name", "Surname" & "Organisation" fields.
  $personal_info_fields = array(
    'field_enrd_sfr_pub_subcp_name',
    'field_enrd_sfr_pub_subcp_surname',
    'field_enrd_sfr_pub_subcp_org',
  );

  foreach ($personal_info_fields as $field) {
    if (isset($form[$field][LANGUAGE_NONE][0]['value'])) {
      $form[$field][LANGUAGE_NONE][0]['value']['#maxlength'] = ENRD_SFR_PUB_EU_MAXLENGTH;
    }
  }

  $publications_page = apachesolr_search_page_load('publications_elibrary');

  if ($publications_page) {
    // Add a page description.
    $element = array(
      '#type' => 'markup',
      '#markup' => t('Fill in the form below to request subscription to !url.', array(
        '!url' => l(
          t('ENRD publications'),
          $publications_page['search_path'],
          array(
            'attributes' =>
              array(
                'title' => t('ENRD Publications search page.'),
                'target' => '_blank',
              ),
          )
        ),
      )),
    );

    $form['enrd_sfr_subscribe_cp_description'] = $element;

    if (isset($form['#fieldgroups']['group_contact_cp_contact_details'])) {
      // Set description weight.
      $form['enrd_sfr_subscribe_cp_description']['#weight'] = $form['#fieldgroups']['group_contact_cp_contact_details']->weight - 1;
    }
  }

  form_load_include($form_state, 'inc', 'enrd_mastermind', 'includes/enrd_mastermind.form.legal_notice_element');
  // EU Legal notice & Privacy Policy statements.
  $form['field_enrd_sfr_pub_eu_legal_notice'] = _enrd_mastermind_eu_legal_notice_checkbox();
  // Show disclaimer "Legal notice" msg below "Address" field.
  if (isset($form['field_enrd_sfr_pub_subcp_addr'])) {
    $form['field_enrd_sfr_pub_eu_legal_notice']['#weight'] = $form['field_enrd_sfr_pub_subcp_addr']['#weight'] + 1;
  }

  // Disclaimer message to "Newsletter" link.
  $form['enrd_sfr_pub_newsletter_link'] = _enrd_sfr_pub_redirect_enrd_newsletter_link();
  // Place the "Newsletter" link below "Submit" button.
  $form['enrd_sfr_pub_newsletter_link']['#weight'] = $form['actions']['#weight'] + 1;

  // Add link message to Contact CP Form.
  $form['enrd_sfr_pub_contact_cp'] = _enrd_sfr_pub_redirect_contact_cp_message();
  if (isset($form['enrd_sfr_pub_newsletter_link'])) {
    // Place the Contact CP disclaimer below Newsletter link.
    $form['enrd_sfr_pub_contact_cp']['#weight'] = $form['enrd_sfr_pub_newsletter_link']['#weight'] + 1;
  }

}

/**
 * After build callback for the ENRD Sfr Subscription CP Form.
 *
 * @param mixed $form
 *   Drupal form array.
 * @param mixed $form_state
 *   Drupal form state array.
 */
function _enrd_sfr_pub_subscribe_cp_form_after_build($form, &$form_state) {
  // Override default ENRD Sfr add page title.
  drupal_set_title(t('Subscribe to publications'));

  // Add empty value to use in the addressfield_default_values_alter hook.
  if (isset($form['field_enrd_sfr_pub_subcp_addr'][LANGUAGE_NONE][0])) {
    // "Address" field.
    $address_element = &$form['field_enrd_sfr_pub_subcp_addr'][LANGUAGE_NONE][0];

    $address_element['country']['#options'] = array('' => t('- Select a country -')) + $address_element['country']['#options'];
  }

  // Initialize Paper controller.
  $paper_is_checked = FALSE;

  // Check if there is a paper copy request.
  if (isset($form_state['values']['field_enrd_sfr_pub_subcp_type'][LANGUAGE_NONE])) {

    foreach ($form_state['values']['field_enrd_sfr_pub_subcp_type'][LANGUAGE_NONE] as $type) {
      if (isset($type['field_enrd_sfr_pub_subcp_paper']) && $type['field_enrd_sfr_pub_subcp_paper'][LANGUAGE_NONE] == 1) {
        $paper_is_checked = TRUE;
        break;
      }
    }

  }

  // If Paper is not checked, make fields not required.
  if (!$paper_is_checked) {
    // Custom validation.
    $address_element['street_block']['thoroughfare']['#required'] = FALSE;
    $address_element['locality_block']['postal_code']['#required'] = FALSE;
    $address_element['locality_block']['dependent_locality']['#required'] = FALSE;
    $address_element['locality_block']['locality']['#required'] = FALSE;
    $address_element['locality_block']['administrative_area']['#required'] = FALSE;
  }

  return $form;

}

/**
 * Validate function for ENRD Sfr Subscription CP Form fields.
 *
 * @param mixed $form
 *   Drupal form array.
 * @param mixed $form_state
 *   Drupal form state array.
 */
function _enrd_sfr_pub_subscribe_cp_form_validate($form, &$form_state) {

  if (isset($form_state['values']['field_enrd_sfr_pub_subcp_name'][LANGUAGE_NONE][0]['value']) ||
    isset($form_state['values']['field_enrd_sfr_pub_subcp_surname'][LANGUAGE_NONE][0]['value'])) {

    $name = $form_state['values']['field_enrd_sfr_pub_subcp_name'][LANGUAGE_NONE][0]['value'];
    $surname = $form_state['values']['field_enrd_sfr_pub_subcp_surname'][LANGUAGE_NONE][0]['value'];

    // "Name" and "Surname" count control: max 35 chars in tot.
    if (!empty($name) || !empty($surname)) {
      $tot_count = drupal_strlen($name) + drupal_strlen($surname);
      if ($tot_count > ENRD_SFR_PUB_EU_MAXLENGTH) {
        form_set_error('field_enrd_sfr_pub_subcp_name', t('Name + Surname should be maximum 35 characters in total.'));
        form_set_error('field_enrd_sfr_pub_subcp_surname');
      }
    }
  }

  // "Type of publication" select fields.
  if (isset($form_state['values']['field_enrd_sfr_pub_subcp_type'][LANGUAGE_NONE])
    && isset($form['field_enrd_sfr_pub_subcp_type'][LANGUAGE_NONE])) {

    $types_of_publication_values = $form_state['values']['field_enrd_sfr_pub_subcp_type'][LANGUAGE_NONE];
    $types_of_publication_element = $form['field_enrd_sfr_pub_subcp_type'][LANGUAGE_NONE];

    foreach ($types_of_publication_values as $type_key => $type_of_publication) {

      if (is_array($type_of_publication) && is_numeric($type_key)) {

        // "Language(s) + N. of copies" required if
        // "Paper version" is checked.
        if (isset($type_of_publication['field_enrd_sfr_pub_subcp_paper'][LANGUAGE_NONE][0]['value']) && ($type_of_publication['field_enrd_sfr_pub_subcp_paper'][LANGUAGE_NONE][0]['value'] == 1)) {

          $languages_copies = $type_of_publication['field_enrd_sfr_pub_subcp_lng_cop'][LANGUAGE_NONE];

          foreach ($languages_copies as $key => $language_copy) {
            if (is_array($language_copy) && is_numeric($key)) {
              if (empty($language_copy['first']) && empty($language_copy['second'])) {
                form_set_error('field_enrd_sfr_pub_subcp_type][' . LANGUAGE_NONE . '][' . $type_key . '][field_enrd_sfr_pub_subcp_lng_cop][' . LANGUAGE_NONE . '][' . $key . '][first', t('!name field is required.', array('!name' => $types_of_publication_element[$type_key]['field_enrd_sfr_pub_subcp_lng_cop'][LANGUAGE_NONE]['#title'])));
                form_set_error('field_enrd_sfr_pub_subcp_type][' . LANGUAGE_NONE . '][' . $type_key . '][field_enrd_sfr_pub_subcp_lng_cop][' . LANGUAGE_NONE . '][' . $key . '][second');
              }
            }
          }
        }

        // "Language(s)" required if "Electronic version" checked.
        if ($type_of_publication['field_enrd_sfr_pub_subcp_electr'][LANGUAGE_NONE][0]['value'] == 1 && empty($type_of_publication['field_enrd_sfr_pub_subcp_el_lang'][LANGUAGE_NONE][0]['value'])) {
          form_set_error('field_enrd_sfr_pub_subcp_type][' . LANGUAGE_NONE . '][0][field_enrd_sfr_pub_subcp_el_lang', t('!name field is required.', array('!name' => $types_of_publication_element[0]['field_enrd_sfr_pub_subcp_el_lang'][LANGUAGE_NONE]['#title'])));
        }

        // At least "Paper copy" or "Electronic" selected if Type is specified.
        if (!empty($type_of_publication['field_enrd_sfr_pub_subcp_typepub'][LANGUAGE_NONE][0]['value'])) {
          if ($type_of_publication['field_enrd_sfr_pub_subcp_paper'][LANGUAGE_NONE][0]['value'] == 0 && $type_of_publication['field_enrd_sfr_pub_subcp_electr'][LANGUAGE_NONE][0]['value'] == 0) {
            form_set_error('field_enrd_sfr_pub_subcp_type][und][0][field_enrd_sfr_pub_subcp_paper][und]', t('You must specify if you wish to subscribe to paper or electronic (or both) for a Type of publication.', array('!name' => $form['field_enrd_sfr_pub_subcp_type'][LANGUAGE_NONE][$type_key]['field_enrd_sfr_pub_subcp_paper'][LANGUAGE_NONE]['#title'])));
          }
        }

      }

    }

  }

  // Uniqueness value restriction on "Type of publication".
  $types_of_publication = array_column($types_of_publication_values, 'field_enrd_sfr_pub_subcp_typepub');

  if (!empty($types_of_publication)) {
    $type_of_publication_target_values = [];

    foreach ($types_of_publication as $type) {
      // Get the actual value from the multidimensional array.
      $types_of_publication_value = $type[LANGUAGE_NONE][0]['value'];
      // Push the value into the actual array.
      array_push($type_of_publication_target_values, $types_of_publication_value);
    }

    // Show error if same "Type of publication" entered more than once.
    if (count($type_of_publication_target_values) !== count(array_unique($type_of_publication_target_values))) {
      form_set_error('field_enrd_sfr_pub_subcp_type][' . LANGUAGE_NONE . '][0][field_enrd_sfr_pub_subcp_typepub', t('Cannot enter the same !name more than once.', array('!name' => $types_of_publication_element[0]['field_enrd_sfr_pub_subcp_typepub'][LANGUAGE_NONE]['#title'])));
    }
  }

  // Uniqueness value restriction on "Language(s)" Double field.
  $pub_type_languages_copies = array_column($types_of_publication_values, 'field_enrd_sfr_pub_subcp_lng_cop');

  if (!empty($pub_type_languages_copies)) {

    foreach ($pub_type_languages_copies as $lang_key => $language_copy) {

      if (is_array($language_copy) && is_numeric($lang_key)) {
        $languages = array_column($language_copy[LANGUAGE_NONE], 'first');

        // Show error if same "Language" for a specific Type of publication
        // has been entered more than once.
        if (count($languages) !== count(array_unique($languages))) {
          form_set_error('field_enrd_sfr_pub_subcp_type][' . LANGUAGE_NONE . '][' . $lang_key . '][field_enrd_sfr_pub_subcp_lng_cop][' . LANGUAGE_NONE . '][0][first', t('Cannot enter same Language for a !name more than once.', array('!name' => $types_of_publication_element[0]['field_enrd_sfr_pub_subcp_typepub'][LANGUAGE_NONE]['#title'])));
        }
      }
    }

  }

  // Validate "Address" Postal/Zip code of the available countries.
  if (isset($form_state['values']['field_enrd_sfr_pub_subcp_addr'][LANGUAGE_NONE][0]['postal_code'])) {
    $field_subcp_addr = $form_state['values']['field_enrd_sfr_pub_subcp_addr'][LANGUAGE_NONE][0];
    $postal_code = $field_subcp_addr['postal_code'];
    $country = isset($field_subcp_addr['country']) ? $field_subcp_addr['country'] : FALSE;

    $validation_result = postal_code_validation_validate($postal_code, $country);

    if (!empty($postal_code) && !empty($validation_result['error'])) {
      form_set_error(implode('][', $form['field_enrd_sfr_pub_subcp_addr'][LANGUAGE_NONE][0]['locality_block']['postal_code']['#parents']), $validation_result['error']);
    }
  }

}

/**
 * Custom function to append Contact CP form message.
 *
 * @return array
 *   HTML to render the form submit suffix.
 */
function _enrd_sfr_pub_redirect_contact_cp_message() {
  // Disclaimer msg shown in the CP Subscriptions Form.
  return array(
    '#type' => 'item',
    '#markup' => t('If you want to unsubscribe or modify your subscriptions, please !url.', array(
      '!url' => l(
        t('send your request to the ENRD Contact Point'),
        ENRD_SFR_PUB_ADD_REQUEST . _enrd_sfr_type_path_replace(ENRD_SFR_PUB_CONT_CP_FORM),
        array('attributes' => array('target' => '_blank'))
      ),
    )),
  );
}

/**
 * Custom theme for "Type of publication" ENRD Sfr field collection element.
 *
 * Combine multiple values into a table.
 *
 * @param mixed $variables
 *   An associative array containing:
 *   - element: A render element representing the form element.
 */
function theme_enrd_sfr_pub_subcp_type($variables) {
  $element = $variables['element'];
  $output = '';

  if ($element['#cardinality'] > 1 || $element['#cardinality'] == FIELD_CARDINALITY_UNLIMITED) {
    $table_id = drupal_html_id($element['#field_name'] . '_values');
    $type_of_publ_class = drupal_html_class($element['#field_name']);
    $required = !empty($element['#required']) ? theme('form_required_marker', $variables) : '';

    $header = array(
      array(
        'data' => '<label>' . t('!title !required', array('!title' => $element['#title'], '!required' => $required)) . "</label>",
        'colspan' => 2,
        'class' => array('field-label hidden'),
      ),
    );
    $rows = array();

    // Render "Add more" btn + items.
    $items = array();
    foreach (element_children($element) as $key) {
      if ($key === 'add_more') {
        $add_more_button = &$element[$key];
      }
      else {
        $items[] = &$element[$key];
      }
    }

    // Add the items as table rows.
    foreach ($items as $key => $item) {
      // Wrap Type of publ. & Remove fields around (flex) container.
      $item['grouping_type_publication'] = array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => array(
            drupal_html_class($item['#host_entity_type'] . '-grouping-type-publications'),
          ),
        ),
      );
      $item['grouping_type_publication']['field_enrd_sfr_pub_subcp_typepub'] = $item['field_enrd_sfr_pub_subcp_typepub'];
      $item['grouping_type_publication']['remove_button'] = $item['remove_button'];
      $item['grouping_type_publication']['#weight'] = $item['field_enrd_sfr_pub_subcp_typepub']['#weight'];
      unset($item['field_enrd_sfr_pub_subcp_typepub']);
      unset($item['remove_button']);

      // Wrap the Paper & Electronic fields around (flex) container.
      $item['grouping_publ_versions'] = array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => array(
            drupal_html_class($item['#host_entity_type'] . '-grouping-publ-versions'),
          ),
        ),
      );
      $item['grouping_publ_versions']['#weight'] = $item['grouping_type_publication']['#weight'] + 1;

      // Wrap fieldset around the "Paper" checkbox & the Double select.
      if (isset($item['field_enrd_sfr_pub_subcp_paper']) || isset($item['field_enrd_sfr_pub_subcp_lng_cop'])) {
        $item['group_paper'] = array(
          '#type' => 'fieldset',
          '#attributes' => array(
            'class' => array(
              drupal_html_class($item['#host_entity_type'] . '-group-paper'),
            ),
          ),
          '#suffix' => '<div class="enrd-sfr-separator"></div>',
        );
        $item['group_paper']['field_enrd_sfr_pub_subcp_paper'] = $item['field_enrd_sfr_pub_subcp_paper'];
        $item['group_paper']['field_enrd_sfr_pub_subcp_lng_cop'] = $item['field_enrd_sfr_pub_subcp_lng_cop'];
        $item['grouping_publ_versions']['group_paper'] = $item['group_paper'];

        unset($item['field_enrd_sfr_pub_subcp_paper']);
        unset($item['field_enrd_sfr_pub_subcp_lng_cop']);
        unset($item['group_paper']);
      }

      // Wrap fieldset around the "Electronic" checkbox & the Chosen select.
      if (isset($item['field_enrd_sfr_pub_subcp_electr']) || isset($item['field_enrd_sfr_pub_subcp_el_lang'])) {
        $item['group_electronic'] = array(
          '#type' => 'fieldset',
          '#attributes' => array(
            'class' => array(
              drupal_html_class($item['#host_entity_type'] . '-group-electronic'),
            ),
          ),
        );
        $item['group_electronic']['field_enrd_sfr_pub_subcp_electr'] = $item['field_enrd_sfr_pub_subcp_electr'];
        $item['group_electronic']['field_enrd_sfr_pub_subcp_el_lang'] = $item['field_enrd_sfr_pub_subcp_el_lang'];
        $item['grouping_publ_versions']['group_electronic'] = $item['group_electronic'];

        unset($item['field_enrd_sfr_pub_subcp_electr']);
        unset($item['field_enrd_sfr_pub_subcp_el_lang']);
        unset($item['group_electronic']);
      }

      // Hide select related to the field collection item weight.
      $item['_weight']['#attributes'] = array('class' => array('hidden'));
      $cells = array(
        drupal_render($item),
      );
      $rows[] = array(
        'data' => $cells,
      );
    }

    $output = '<div class="form-item">';
    $output .= theme('table',
      array(
        'header' => $header,
        'rows' => $rows,
        'attributes' => array(
          'id' => $table_id,
          'class' => array('field-multiple-table', $type_of_publ_class),
        ),
      )
    );
    $output .= $element['#description'] ? '<div class="description">' . $element['#description'] . '</div>' : '';
    $output .= '<div class="clearfix">' . drupal_render($add_more_button) . '</div>';
    $output .= '</div>';
  }
  else {
    foreach (element_children($element) as $key) {
      $output .= drupal_render($element[$key]);
    }
  }

  return $output;

}
