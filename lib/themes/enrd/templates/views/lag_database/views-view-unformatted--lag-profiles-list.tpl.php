<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
    <hgroup class="mb20">
        <h1><?php print $title; ?></h1>
    </hgroup>
<?php endif; ?>

<section class="col-lg-12 col-md-12">
  <?php foreach ($rows as $id => $row): ?>
      <div<?php if (isset($classes_array[$id])): ?> class="<?php print $classes_array[$id]; ?>"<?php
     endif; ?>>
        <?php print $row; ?>
      </div>
  <?php endforeach; ?>
</section>
