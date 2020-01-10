<?php

/**
 * @file
 * Display Suite Publication page template.
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

    <?php if ($side): ?>
    <div class="row">
      <<?php print $side_wrapper; ?> class="col-lg-8 col-md-8 col-sm-12 col-xs-12">
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
      <?php if ($side): ?>
        </<?php print $side_wrapper; ?>>
      <?php endif; ?>

    <?php if ($side): ?>
      <!-- Sidebar right -->
      <aside class="col-lg-4 col-md-4 col-sm-12 col-xs-12">
        <div class="side">
          <<?php print $side_wrapper; ?> class="ds-side<?php print $side_classes; ?>">
            <?php print $side; ?>
          </<?php print $side_wrapper; ?>>
        </div>
      </aside>
      <!-- /Sidebar right -->
    </div>
    <?php endif; ?>

</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
