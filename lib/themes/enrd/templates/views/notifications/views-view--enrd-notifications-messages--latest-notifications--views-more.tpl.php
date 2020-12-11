<?php

/**
 * @file
 * Theme the more link.
 *
 * - $view: The view object.
 * - $more_url: the url for the more link.
 * - $link_text: the text for the more link.
 * - $new_window: The flag that indicates if link should be opened in a new
 *   window.
 *
 * @ingroup views_templates
 */
?>

<div class="more-link">
  <?php if ($count): ?>
  <a href="<?php print $more_url ?>"<?php if (!empty($new_window)): ?> target="_blank"<?php
 endif; ?>>
    <?php print $link_text; ?><br />
  </a>
  <?php endif ?>
    <div class="btn enrd-notifications settings-link">
      <?php print $settings_link; ?>
    </div>
</div>
