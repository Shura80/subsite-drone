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
    <div class="field-item"<?php print $content_attributes; ?>>
        <div class="item-list">
            <ul>
              <?php foreach ($items as $delta => $item): ?>
                  <li><?php print render($item); ?><span class="glyphicon glyphicon-share"></span></li>
              <?php endforeach; ?>
            </ul>
        </div>
    </div>
</div>
