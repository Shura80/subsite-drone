<?php

/**
 * @file
 * Theme implementation for terms of the "Forums" vocabulary in full view mode.
 */
?>
<div id="taxonomy-term-<?php print $term->tid; ?>" class="<?php print $classes; ?>">

  <?php if (!$page): ?>
    <h4><a href="<?php print $term_url; ?>"><?php print $term_name; ?></a></h4>
  <?php endif; ?>

  <div class="content">
    <?php print render($content); ?>
  </div>

</div>
