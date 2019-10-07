<?php

/**
 * @file
 * Template file for the organization_node_block view.
 */
?>
<table class="table table-condensed table-bordered small">
  <tbody>
  <?php foreach ($fields as $id => $field): ?>
    <tr>
      <td class="bold background-grey">
        <div class="align-right"><?php print $field->label_html; ?></div>
      </td>
      <td class="grey"><?php print $field->content; ?></td>
    </tr>
  <?php endforeach; ?>
  </tbody>
</table>
