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
    <div>
        <?php foreach ($items as $delta => $item): ?>
            <?php print render($item); ?>
        <?php endforeach; ?>

    </div>
</div>
