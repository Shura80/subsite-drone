<?php

/**
 * @file
 * This template handles the layout of the views exposed filter form.
 *
 * Variables available:
 * - $widgets: An array of exposed form widgets. Each widget contains:
 * - $widget->label: The visible label to print. May be optional.
 * - $widget->operator: The operator for the widget. May be optional.
 * - $widget->widget: The widget itself.
 * - $sort_by: The select box to sort the view using an exposed form.
 * - $sort_order: The select box with the ASC, DESC options to define order.
 *   May be optional.
 * - $items_per_page: The select box with the available items per page. May be
 *   optional.
 * - $offset: A textfield to define the offset of the view. May be optional.
 * - $reset_button: A button to reset the exposed filter applied. May be
 *   optional.
 * - $button: The submit button for the form.
 * - $q: used to add exposed parameter at the beginning if clean URLs are off.
 * - $brexit_disclaimer: The Brexit Disclaimer.
 *
 * @ingroup views_templates
 */
?>

<?php if (!empty($q)): ?>
  <?php
  // This ensures that, if clean URLs are off, the 'q' is added first so that
  // it shows up first in the URL.
  print $q;
  ?>
<?php endif; ?>

<div class="block block-digitization clearfix panel-default">
  <?php foreach ($widgets as $id => $widget): ?>
      <div id="<?php print $widget->id; ?>-wrapper"
           class="block-title panel-heading views-exposed-widget views-widget-<?php print $id; ?>">
        <?php print $widget->label; ?>
        <?php if (!empty($widget->label)): ?>
        <?php endif; ?>
      </div>
      <div class="content">
        <?php print $widget->widget; ?>
      </div>
  <?php endforeach; ?>
    <div class="views-exposed-widget views-submit-button">
      <?php print $button; ?>
    </div>
  <?php if (!empty($reset_button)): ?>
      <div class="views-exposed-widget views-reset-button">
        <?php print $reset_button; ?>
      </div>
  <?php endif; ?>
  <?php if (!empty($brexit_disclaimer)): ?>
    <?php print $brexit_disclaimer; ?>
  <?php endif; ?>
</div>
