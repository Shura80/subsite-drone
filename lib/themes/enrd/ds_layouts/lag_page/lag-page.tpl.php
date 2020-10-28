<?php

/**
 * @file
 * Display Suite LAG profile page template.
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

      <div class="col-md-12">
         <<?php print $headline_wrapper; ?> class="ds-lag-headline<?php print $headline_classes; ?>">
         <?php print $headline; ?>
      </<?php print $headline_wrapper; ?>>
      </div>
    </div>
    <div class="row">
       <div class="col-md-12">
           <<?php print $main_wrapper; ?> class="ds-main<?php print $main_classes; ?>">
           <?php print $main; ?>
       </<?php print $main_wrapper; ?>>
       </div>
    </div>
    <?php if ($contact): ?>
    <div class="row">
        <div class="col-md-12">
            <legend><?php print $contact_label ?></legend>
            <<?php print $contact_wrapper; ?> class="ds-contact<?php print $contact_classes; ?>">
          <?php print $contact; ?>
        </<?php print $contact_wrapper; ?>>
        </div>
    </div>
    <?php endif; ?>
    <?php if ($additional): ?>
    <div class="row">
        <div class="col-md-12">
          <div class="additional-info-heading">
              <legend><a data-toggle="collapse" href="#additionalInfo"><?php print $additional_label ?></a></legend>
          </div>
          <<?php print $additional_wrapper; ?> id="additionalInfo" class="ds-additional<?php print $additional_classes; ?> panel-collapse collapse">
              <?php print $additional; ?>
          </<?php print $additional_wrapper; ?>>
        </div>
    </div>
    <?php endif; ?>
    <?php if ($funding): ?>
    <div class="row">
        <div class="col-md-12">
          <div class="lag-funding-heading">
              <legend><a data-toggle="collapse" href="#lagFunding"><?php print $funding_label ?></a></legend>
          </div>
          <<?php print $funding_wrapper; ?> id="lagFunding" class="ds-funding<?php print $funding_classes; ?> panel-collapse collapse">
             <?php print $funding; ?>
          </<?php print $funding_wrapper; ?>>
        </div>
    </div>
    <?php endif; ?>
  </div>
</div>

</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
