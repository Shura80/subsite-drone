<?php

/**
 * @file
 * Display Suite Project search result template.
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
 * - $abstract: Rendered content for the "Abstract" region.
 * - $abstract_classes: String of classes that can be used to style the
 *   "Abstract" region.
 *
 * - $meta: Rendered content for the "Meta" region.
 * - $meta_classes: String of classes that can be used to style the
 *   "Meta" region.
 *
 * Variables:
 *
 * - $meta_fields: List of fields contained in the "Meta" region.
 */
?>
<<?php print $layout_wrapper; print $layout_attributes; ?> class="<?php print $classes; ?> clearfix">

<article class="media img-150 metadata-before">

  <?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <?php if ($thumb): ?>
  <div class="thumbnail">
    <<?php print $thumb_wrapper; ?>>
      <?php print $thumb; ?>
    </<?php print $thumb_wrapper; ?>>
  </div>
  <?php endif; ?>

  <div class="media-body">
    <div>
      <?php print $headline; ?>

      <?php if ($meta): ?>
        <div class="metadata">
            <dl>
              <?php print $meta; ?>
            </dl>
        </div>
      <?php endif; ?>

      <div class="abstract">
        <<?php print $abstract_wrapper; ?>>
          <?php print $abstract; ?>
        </<?php print $abstract_wrapper; ?>>
      </div>

    </div>
  </div>
</article>


</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
