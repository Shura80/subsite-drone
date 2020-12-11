<?php
/**
 * @file
 * Custom easy_breadcrumb theme implementation to display breadcrumb block.
 *
 * Available variables:
 * - $menu_breadcrumb: fixed breadcrumb menu elements.
 * - $breadcrumb: breadrcumb elements.
 * - $segments_quantity: number of breadcrumb segments.
 * - $separator: segment separator element.
 * - $separator_ending: prints the page's title as a link or as a text.
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $block_zebra: Outputs 'odd' and 'even' dependent on each block region.
 * - $zebra: Same output as $block_zebra but independent of any block region.
 * - $block_id: Counter dependent on each block region.
 * - $id: Same output as $block_id but independent of any block region.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 * - $block_html_id: A valid HTML ID and guaranteed unique.
 *
 * @ingroup themeable
 */
?>

<?php print drupal_render($menu_breadcrumb); ?>
<?php if ($segments_quantity): ?>
    <?php foreach ($breadcrumb as $i => $item): ?>
        <li><?php print $item; ?></li>
    <?php endforeach; ?>
<?php endif; ?>
