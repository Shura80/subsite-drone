<?php

/**
 * @file
 * Template for custom display "ENRD Media Object" rows.
 */
?>

<?php if (!empty($options['image_field'])): ?>
  <div class="thumbnail">
    <?php if (!empty($fields[$options['image_field']]->separator)): ?>
      <?php print $fields[$options['image_field']]->separator; ?>
    <?php endif; ?>

    <?php print $fields[$options['image_field']]->wrapper_prefix; ?>
    <?php print $fields[$options['image_field']]->label_html; ?>
    <?php print $fields[$options['image_field']]->content; ?>
    <?php print $fields[$options['image_field']]->wrapper_suffix; ?>
  </div>
<?php endif; ?>

<div class="media-body">
  <div>
    <?php if (!empty($options['heading_field'])): ?>
      <h2 class="media-heading">
        <?php if (!empty($fields[$options['heading_field']]->separator)): ?>
          <?php print $fields[$options['heading_field']]->separator; ?>
        <?php endif; ?>

        <?php print $fields[$options['heading_field']]->wrapper_prefix; ?>
        <?php print $fields[$options['heading_field']]->label_html; ?>
        <?php print $fields[$options['heading_field']]->content; ?>
        <?php print $fields[$options['heading_field']]->wrapper_suffix; ?>
      </h2>
    <?php endif; ?>

    <?php if (!empty($options['abstract_field'])): ?>
      <div class="abstract">
        <?php if (!empty($fields[$options['abstract_field']]->separator)): ?>
          <?php print $fields[$options['abstract_field']]->separator; ?>
        <?php endif; ?>

        <?php print $fields[$options['abstract_field']]->wrapper_prefix; ?>
        <?php print $fields[$options['abstract_field']]->label_html; ?>
        <?php print $fields[$options['abstract_field']]->content; ?>
        <?php print $fields[$options['abstract_field']]->wrapper_suffix; ?>
      </div>
    <?php endif; ?>

    <?php if (!empty($options['metadata_field'])): ?>
      <div class="metadata">
        <dl>
          <?php foreach ($options['metadata_field'] as $field): ?>
            <?php if (!empty($fields[$field]->content)): ?>
              <dt><?php print $fields[$field]->label_html; ?></dt>
              <dd><?php print $fields[$field]->content; ?></dd>
            <?php endif ?>
          <?php endforeach ?>
        </dl>
      </div>
    <?php endif; ?>

  </div>
</div>
