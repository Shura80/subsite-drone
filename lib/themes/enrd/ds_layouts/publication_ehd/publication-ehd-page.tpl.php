<?php

/**
 * @file
 * Display Suite Evaluation Publication page template.
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

<article class="media img-150">

  <?php if ($thumb): ?>
    <div class="thumbnail">
        <div class="<?php print empty($thumb) ? 'project-image-placeholder' : 'project-image'; ?>">
            <<?php print $thumb_wrapper; ?> class="ds-thumb<?php print $thumb_classes; ?>">
          <?php print $thumb; ?>
        </<?php print $thumb_wrapper; ?>>
        </div>
    </div>
  <?php endif; ?>

  <div class="media-body">
      <div>
        <?php if ($headline): ?>
        <div class="media-heading">
          <<?php print $headline_wrapper; ?> class="ds-headline<?php print $headline_classes; ?>">
            <?php print $headline; ?>
          </<?php print $headline_wrapper; ?>>
        </div>
        <?php endif; ?>

        <div class="abstract">
          <<?php print $abstract_wrapper; ?> class="ds-abstract<?php print $abstract_classes; ?>">
            <?php print $abstract; ?>
          </<?php print $abstract_wrapper; ?>>
        </div>

        <div class="metadata">
          <<?php print $meta_wrapper; ?> class="ds-metadata<?php print $meta_classes; ?>">
            <?php print $meta; ?>
          </<?php print $meta_wrapper; ?>>
        </div>
      </div>
    </div>
</article>

</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
