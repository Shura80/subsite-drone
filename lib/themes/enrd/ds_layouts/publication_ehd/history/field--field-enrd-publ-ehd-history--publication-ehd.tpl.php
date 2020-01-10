<?php

/**
 * @file
 * Custom template implementation for the field_enrd_publ_ehd_history field.
 *
 * Available variables:
 *
 * - $attributes: array of HTML attributes populated by modules, intended to
 *   be added to the main container tag of this template.
 * - $items: An array of field values. Use render() to output them.
 * - $label: The item label.
 * - $label_hidden: Whether the label display is set to 'hidden'.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - field: The current template type, i.e., "theming hook".
 *   - field-name-[field_name]: The current field name. For example, if the
 *     field name is "field_description" it would result in
 *     "field-name-field-description".
 *   - field-type-[field_type]: The current field type. For example, if the
 *     field type is "text" it would result in "field-type-text".
 *   - field-label-[label_display]: The current label position. For example, if
 *     the label position is "above" it would result in "field-label-above".
 * - $content_attributes: Same as attributes, except applied to the field
 *   item that appears in the template.
 * - $title_attributes: Same as attributes, except applied to the main field
 *   label that appears in the template.
 * Other variables:
 * - $element['#object']: The entity to which the field is attached.
 * - $element['#view_mode']: View mode, e.g. 'full', 'teaser'...
 * - $element['#field_name']: The field name.
 * - $element['#field_type']: The field type.
 * - $element['#field_language']: The field language.
 * - $element['#field_translatable']: Whether the field is translatable or not.
 * - $element['#label_display']: Position of label display, inline, above, or
 *   hidden.
 * - $field_name_css: The css-compatible field name.
 * - $field_type_css: The css-compatible field type.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 */
?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <fieldset class="collapse-text-fieldset collapsible collapsed">
    <?php if (!$label_hidden): ?>
      <legend>
        <span class="fieldset-legend">
          <a class="fieldset-title" data-toggle="collapse" href="#collapseHistory" aria-expanded="false" aria-controls="collapseHistory">
          <span class="fieldset-legend-prefix element-invisible">Show</span><?php print $label ?></a>
          <span class="summary"></span>
        </span>
      </legend>
    <?php endif; ?>
    <div class="fieldset-wrapper">
      <div class="collapse-text-text" id="collapseHistory">
        <div class="field-items"<?php print $content_attributes; ?>>
          <?php foreach ($items as $delta => $item): ?>
            <div class="field-item <?php print $delta % 2 ? 'odd' : 'even'; ?>"<?php print $item_attributes[$delta]; ?>>
               <?php print render($item); ?>
            </div>
          <?php endforeach; ?>
        </div>
      </div>
    </div>
  </fieldset>
</div>
