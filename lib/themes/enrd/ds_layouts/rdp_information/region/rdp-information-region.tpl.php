<?php

/**
 * @file
 * Display Suite Region field collection template.
 *
 * Available variables:
 *
 * Layout:
 * - $classes: String of classes that can be used to style this layout.
 * - $contextual_links: Renderable array of contextual links.
 * - $layout_wrapper: wrapper surrounding the layout.
 *
 * Display Suite Regions:
 *
 * - $headline: Rendered content for the "Headline" region.
 * - $headline_classes: String of classes that can be used to style the
 *   "Headline" region.
 *
 * - $introductory_text: Rendered content for the "Introductory text" region.
 * - $introductory_text_classes: String of classes that can be used to style the
 *   "Introductory text" region.
 *
 * - $rdp_documents: Rendered content for the "RDP documents" region.
 * - $rdp_documents_classes: String of classes that can be used to style the
 *   "RDP documents" region.
 *
 * - $partnership_agreement_docs: Rendered content for the
 *   "Partnership Agreement documents" region.
 * - $partnership_agreement_docs_classes: String of classes that can be used
 *   to style the "Partnership Agreement documents" region.
 *
 * - $nrn_image: Rendered content for the "NRN Image" region.
 * - $nrn_image_classes: String of classes that can be used to style the
 *   "NRN Image" region.
 *
 * - $nrn_information: Rendered content for the "NRN Information" region.
 * - $nrn_information_classes: String of classes that can be used to style
 *   the "NRN Information" region.
 *
 * - $managing_authority: Rendered content for the
 *   "Managing Authority" region.
 * - $managing_authority_classes: String of classes that can be used to style
 *   the "Managing Authority" region.
 *
 * - $paying_agency: Rendered content for the "Paying Agency" region.
 * - $paying_agency_classes: String of classes that can be used to style the
 *   "Paying Agency" region.
 *
 * - $country_region: Rendered content for the "Country Region" region.
 * - $country_region_classes: String of classes that can be used to style the
 *   "Country Region" region.
 *
 * Section labels:
 *
 * - $rdp_information_label: "RDP information" section label.
 * - $national_rural_network_label: "National Rural Network" section label.
 * - $region_id: the Region field collection id used to display the <div> id.
 */
?>

<<?php print $layout_wrapper; print $layout_attributes; ?> class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

    <div class="panel panel-default">
    <?php if ($headline): ?>
          <div class="panel-heading">
              <a class="panel-title" data-toggle="collapse" data-parent="#rdp-info-accordion" href="#panel-element-<?php print $region_id; ?>">
                <?php print $headline; ?>
              </a>
          </div>
    <?php endif; ?>
    <div id="panel-element-<?php print $region_id; ?>" class="panel-collapse collapse">
        <div class="panel-body">
              <?php if ($introductory_text): ?>
                <div class="row intro-text">
                  <<?php print $introductory_text_wrapper; ?> class="col-md-12">
                    <?php print $introductory_text; ?>
                  </<?php print $introductory_text_wrapper; ?>>
                </div>
              <?php endif; ?>
              <?php if ($rdp_documents): ?>
                <div class="row rdp-information">
                  <div class="col-md-12">
                  <div class="block-title"><h3><?php print $rdp_information_label; ?></h3><span class="filler"></span></div>
                    <<?php print $rdp_documents_wrapper; ?> class="col-md-12">
                      <?php print $rdp_documents; ?>
                    </<?php print $rdp_documents_wrapper; ?>>
                  </div>
                </div>
              <?php endif; ?>
              <?php if ($nrn_image || $nrn_information): ?>
                <div class="row national-rural-network">
                  <div class="col-md-12">
                    <div class="field field-label-above">
                      <div class="field-label"><?php print $national_rural_network_label; ?></div>
                    </div>
                    <?php if ($nrn_image): ?>
                      <div class="col-md-<?php print (!$nrn_information ? $cols = 12 : $cols = 2); ?>">
                        <?php print $nrn_image; ?>
                      </div>
                    <?php endif; ?>
                    <?php if ($nrn_information): ?>
                      <div class="col-md-<?php print (!$nrn_image ? $cols = 12 : $cols = 10); ?>">
                        <?php print $nrn_information; ?>
                      </div>
                    <?php endif; ?>
                  </div>
                </div>
              <?php endif; ?>
              <?php if ($managing_authority || $paying_agency): ?>
              <div class="row additional-information">
                <div class="col-md-12">
                <?php if ($managing_authority): ?>
                  <div class="col-md-12">
                    <?php print $managing_authority; ?>
                  </div>
                <?php endif; ?>
                <?php if ($paying_agency): ?>
                  <div class="col-md-12">
                    <?php print $paying_agency; ?>
                  </div>
                <?php endif; ?>
                </div>
              </div>
              <?php endif; ?>
            </div>
        </div>
    </div>

</<?php print $layout_wrapper; ?>>
<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children; ?>
<?php endif; ?>
