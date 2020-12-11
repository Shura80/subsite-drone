<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
<div class="<?php print $title; ?>">
<?php endif; ?>
  <?php foreach ($rows as $id => $row): ?>
      <div<?php if ($classes_array[$id]): ?>
        <?php print ' class="' . $classes_array[$id] . '"'; ?>>
     <?php endif; ?>
        <?php print $row; ?>
      </div>
  <?php endforeach; ?>
</div>
