<?php

/**
 * @file
 * Display Suite Cooperation offer search page template.
 *
 * Available variables:
 *
 * Layout:
 * - $classes: String of classes that can be used to style this layout.
 * - $contextual_links: Renderable array of contextual links.
 * - $layout_wrapper: wrapper surrounding the layout.
 *
 * Regions:
 *
 * - $thumb: Rendered content for the "Thumb" region.
 * - $thumb_classes: String of classes that can be used to style the
 *   "Thumb" region.
 *
 * - $headline: Rendered content for the "Headline" region.
 * - $headline_classes: String of classes that can be used to style the
 *   "Headline" region.
 *
 * - $main: Rendered content for the "Main" region.
 * - $main_classes: String of classes that can be used to style the
 *   "Main" region.
 *
 * - $side: Rendered content for the "Side" region.
 * - $side_classes: String of classes that can be used to style the
 *   "Side" region.
 */
?>

<<?php print $layout_wrapper; print $layout_attributes; ?> class="<?php print $classes; ?> clearfix">

    <?php if (isset($title_suffix['contextual_links'])): ?>
      <?php print render($title_suffix['contextual_links']); ?>
    <?php endif; ?>

  <tr class="<?php print $classes . " " . $zebra; ?>">
    <td>
      <?php print $coop_lag_country; ?>
    </td>
    <td>
      <?php print $coop_offer_name; ?>
    </td>
    <td>
      <?php print $coop_offering_lag; ?>
    </td>
    <td>
      <?php print $coop_project_type; ?>
    </td>
    <td>
      <?php print $coop_expiry_date; ?>
    </td>
  </tr>

</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
