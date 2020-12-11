<?php

/**
 * @file
 * Template for custom display "ENRD Media Object" style.
 */
?>

<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<div class="media-list
<?php if (!empty($options['wrapper_class'])): ?>
 <?php print $options['wrapper_class']; ?>
<?php endif; ?>">
  <?php foreach ($rows as $id => $row): ?>
    <article class="media<?php if ($classes_array[$id]): ?>
        <?php print $classes_array[$id]; ?>"
   <?php endif; ?>>
      <?php print $row; ?>
    </article>
  <?php endforeach; ?>
</div>
