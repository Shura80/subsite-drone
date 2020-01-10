<?php

/**
 * @file
 * Display Suite Project page template.
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

  <!-- Needed to activate contextual links -->
  <?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <div class="row">
    <div class="col-md-12 col-xs-12 project-main">
      <div class="row project-top">

        <div class="col-sm-7 col-xs-12">
          <<?php print $headline_wrapper; ?> class="ds-headline<?php print $headline_classes; ?>">
          <?php print $headline; ?>
        </<?php print $headline_wrapper; ?>>
        </div>
      <div class="col-sm-5 col-xs-12">
        <div class="<?php print empty($thumb) ? 'project-image-placeholder' : 'project-image'; ?>">
          <<?php print $thumb_wrapper; ?> class="ds-thumb<?php print $thumb_classes; ?>">
          <?php print $thumb; ?>
        </<?php print $thumb_wrapper; ?>>
      </div>
    </div>
      </div>
      <div class="row">
        <div class="col-md-12">
          <<?php print $main_wrapper; ?> class="ds-main<?php print $main_classes; ?>">
          <?php print $main; ?>
        </<?php print $main_wrapper; ?>>
        </div>
      </div>
    </div>
  </div>

</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
