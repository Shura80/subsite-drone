<?php

/**
 * @file
 * Display Suite NRN Toolkit page template.
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

<article class="row media">

  <?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>


    <div class="col-md-2">
        <<?php print $thumb_wrapper; ?> class="ds-thumb <?php print $thumb_classes; ?>">
        <?php print $thumb; ?>
        </<?php print $thumb_wrapper; ?>>
    </div>

    <div class="col-md-10">
        <?php if ($nrn_title): ?>
          <<?php print $nrn_title_wrapper; ?> class="ds-headline<?php print $headline_classes; ?>">
            <?php print $nrn_title; ?>
          </<?php print $nrn_title_wrapper; ?>>
        <?php else: ?>
          <<?php print $headline_wrapper; ?> class="ds-headline<?php print $headline_classes; ?>">
            <?php print $headline; ?>
          </<?php print $headline_wrapper; ?>>
        <?php endif; ?>

        <<?php print $meta_wrapper; ?> class="ds-metadata<?php print $meta_classes; ?>">
            <?php print $meta; ?>
        </<?php print $meta_wrapper; ?>>

        <?php if ($nrn_description): ?>
          <<?php print $nrn_description_wrapper; ?> class="ds-headline<?php print $abstract_classes; ?>">
            <?php print $nrn_description; ?>
          </<?php print $nrn_description_wrapper; ?>>
        <?php else: ?>
          <<?php print $abstract_wrapper; ?> class="ds-headline<?php print $abstract_classes; ?>">
            <?php print $abstract; ?>
          </<?php print $abstract_wrapper; ?>>
        <?php endif; ?>
    </div>

</article>



</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
