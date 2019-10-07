<?php

/**
 * @file
 * Template file for the example display.
 *
 * Variables available:
 *
 * $plugin: The pager plugin object. This contains the view.
 *
 * $plugin->view
 *   The view object for this navigation.
 *
 * $nav_title
 *   The formatted title for this view. In the case of block
 *   views, it will be a link to the full view, otherwise it will
 *   be the formatted name of the year, month, day, or week.
 *
 * $prev_url
 * $next_url
 *   Urls for the previous and next calendar pages. The links are
 *   composed in the template to make it easier to change the text,
 *   add images, etc.
 *
 * $prev_options
 * $next_options
 *   Query strings and other options for the links that need to
 *   be used in the l() function, including rel=nofollow.
 */
?>
<?php if (!empty($pager_prefix)): ?>
  <?php print $pager_prefix; ?>
<?php endif; ?>
<div class="date-nav-wrapper clearfix">
    <div class="<?php print $container_item_list_class; ?>">
        <?php if (!$mini): ?>
            <div class="date-heading">
                <h3><?php print $nav_title; ?></h3>
            </div>
        <?php endif; ?>
        <ul class="agri-calendar pager">
          <?php if (!empty($prev_url)): ?>
              <li class="date-prev">
                <?php print $prev_url; ?>
              </li>
          <?php endif; ?>

          <?php if ($mini): ?>
              <li class="date-heading">
                  <h3><?php print $nav_title; ?></h3>
              </li>
          <?php else: ?>
            <?php if (!empty($current_date)): ?>
              <li class="current-date">
                <?php print $current_date; ?>
              </li>
            <?php endif; ?>
          <?php endif; ?>

          <?php if (!empty($next_url)): ?>
              <li class="date-next">
                <?php print $next_url; ?>
              </li>
          <?php endif; ?>
        </ul>
    </div>
</div>
