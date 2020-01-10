<?php

/**
 * @file
 * Display Suite NRN Profile page template.
 *
 * Available variables:
 *
 * Layout:
 * - $classes: String of classes that can be used to style this layout.
 * - $contextual_links: Renderable array of contextual links.
 * - $layout_wrapper: wrapper surrounding the layout.
 */
?>

<<?php print $layout_wrapper; print $layout_attributes; ?> class="<?php print $classes; ?> clearfix">

<?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
<?php endif; ?>

<div class="row">
    <div class="col-lg-9 col-sm-12">
      <?php if ($main): ?>
        <<?php print $main_wrapper; ?> class="nrnp-ds-region-main">
            <?php print $main; ?>
        </<?php print $main_wrapper; ?>>
      <?php endif; ?>
      <?php if ($links): ?>
        <<?php print $links_wrapper; ?> class="nrnp-ds-region-links">
            <?php print $links; ?>
        </<?php print $links_wrapper; ?>>
      <?php endif; ?>
      <?php if ($nsu_operation): ?>
        <<?php print $nsu_operation_wrapper; ?> class="nrnp-ds-region-nsu-operation">
            <?php print $nsu_operation; ?>
        </<?php print $nsu_operation_wrapper; ?>>
      <?php endif; ?>
    </div>

    <div class="col-lg-3 col-sm-12">
      <?php if ($side_right): ?>
        <<?php print $side_right_wrapper; ?> class="nrnp-ds-region-side-left">
            <?php print $side_right; ?>
        </<?php print $side_right_wrapper; ?>>
      <?php endif; ?>
    </div>
</div>

</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
