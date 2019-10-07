<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * @ingroup views_templates
 */
?>
<div class="row margin-bottom">
  <div class="col-xs-2">
    <?php print $picture; ?>
  </div>
  <div class="col-xs-10">
    <?php foreach ($fields as $id => $field): ?>
      <?php if (!empty($field->separator)): ?>
        <?php print $field->separator; ?>
      <?php endif; ?>

      <?php print $field->wrapper_prefix; ?>
      <?php print $field->label_html; ?>
      <?php print $field->content; ?>
      <?php print $field->wrapper_suffix; ?>
    <?php endforeach; ?>
  </div>
</div>
