<?php

/**
 * @file
 * Default implementation of the last update info.
 *
 * Available variables:
 * - $label: the label.
 * - $date: the date.
 *
 * @see template_preprocess()
 * @see template_preprocess_block()
 * @see template_process()
 */
?>
<?php if (!empty($label) && !empty($date)): ?>
  <?php print $label; ?>: <?php print $date; ?>
<?php endif; ?>
