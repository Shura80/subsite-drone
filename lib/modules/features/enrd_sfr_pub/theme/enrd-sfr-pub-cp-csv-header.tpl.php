<?php

/**
 * @file
 * Template to display the CSV header for "enrd_sfr_pub_cp_csv" plugin.
 */
?>
<?php if ($options['header']): ?>
  <?php print implode($options['separator'], $header) . "\r\n"; ?>
<?php endif; ?>
