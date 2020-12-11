<?php

/**
 * @file
 * Rural Story Submission E-mail based on "Display Suite reset" template.
 *
 * Available variables:
 * - $ds_content: renders DS Content region.
 * - $drupal_render_children: renders and concatenates children of an element.
 */
?>
<div><?php print $ds_content; ?></div>
<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
