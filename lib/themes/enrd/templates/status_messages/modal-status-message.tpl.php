<?php

/**
 * @file
 * Theme implementation to display a status message as Bootstrap Modal window.
 *
 * Available variables:
 *
 * - $modal_title: the title of the modal window.
 * - $modal_dismiss_label: the hidden label of the closing element.
 * - $modal_dismiss_button: the message displayed on the dismiss button.
 * - $message: the message body.
 *
 * @see template_preprocess_modal_status_message().
 *
 * @ingroup themeable
 */
?>
<?php if ($message): ?>
<div class="messages modal modal-message fade" tabindex="-1" role="dialog">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-header">
        <?php if ($modal_dismiss_label): ?>
          <form>
            <button type="submit" class="close" data-dismiss="modal" aria-label="<?php print $modal_dismiss_label; ?>"><span aria-hidden="true">&times;</span></button>
          </form>
        <?php endif; ?>
        <?php if ($modal_title): ?>
          <h4 class="modal-title"><?php print $modal_title; ?></h4>
        <?php endif; ?>
      </div>
      <div class="modal-body">
        <?php print $message; ?>
      </div>
      <?php if ($modal_dismiss_button): ?>
      <div class="modal-footer">
        <form>
          <button type="submit" class="btn btn-default" data-dismiss="modal"><?php print $modal_dismiss_button; ?></button>
        </form>
      </div>
      <?php endif; ?>
    </div>
  </div>
</div>
<?php endif; ?>
