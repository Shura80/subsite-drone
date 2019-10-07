<?php

/**
 * @file
 * Template file field--field-core-bulk-image-upload--page.tpl.php.
 */
?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if (!$label_hidden): ?>
    <div class="field-label"<?php print $title_attributes; ?>><?php print $label; ?></div>
  <?php endif; ?>
  <div class="field-items"<?php print $content_attributes; ?>>
      <div class="field-item <?php print $delta % 2 ? 'odd' : 'even'; ?>"<?php print $item_attributes[$delta]; ?>>
      <?php print render($items); ?>
      </div>
  </div>
</div>
