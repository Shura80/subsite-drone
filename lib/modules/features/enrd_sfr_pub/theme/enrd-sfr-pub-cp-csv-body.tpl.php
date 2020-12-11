<?php

/**
 * @file
 * Template to display the CSV body for "enrd_sfr_pub_cp_csv" plugin.
 */
?>
<?php foreach ($themed_rows as $count => $item_row): ?>
  <?php print implode($options['separator'], $item_row) . "\r\n"; ?>
<?php endforeach; ?>
