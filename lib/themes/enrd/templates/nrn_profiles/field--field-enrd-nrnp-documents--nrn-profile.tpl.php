<?php

/**
 * @file
 * Contains template file.
 */
?>

<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if (!$label_hidden): ?>
      <div class="label-above"<?php print $title_attributes; ?>><?php print $label ?></div>
  <?php endif; ?>
    <div class="field-items"<?php print $content_attributes; ?>>
        <ul>
          <?php foreach ($items as $delta => $item): ?>
              <li class="field-item"<?php print $item_attributes[$delta]; ?>><?php print render($item); ?></li>
          <?php endforeach; ?>
        </ul>
    </div>
</div>
