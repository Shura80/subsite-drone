<?php

/**
 * @file
 * Contains template file.
 */
?>

<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if (!$label_hidden): ?>
      <div class="field-label enrd-collapse-field"<?php print $title_attributes; ?>>
          <a data-toggle="collapse" href="#nrnProfileRegRepres"><?php print $label ?></a>
      </div>
  <?php endif; ?>
    <div id="nrnProfileRegRepres" class="field-items ds-additional panel-collapse collapse"<?php print $content_attributes; ?>>
      <?php foreach ($items as $delta => $item): ?>
          <div class="field-item <?php print $delta % 2 ? 'odd' : 'even'; ?>"<?php print $item_attributes[$delta]; ?>><?php print render($item); ?></div>
      <?php endforeach; ?>
    </div>
</div>
