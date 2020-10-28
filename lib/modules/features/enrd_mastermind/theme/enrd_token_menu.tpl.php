<?php
/**
 * @file
 * Default simple template to render provided menu tree.
 *
 * - $menu_name: The machine name of the menu.
 * - $menu_tree: The menu tree to be rendered.
 * - $menu_class: Additional menu class.
 * - $classes: The block classes array.
 * - $content: The rendered menu list items.
 */
?>

<div class="<?php print $classes; ?> <?php print $menu_class; ?>">
  <?php if (!empty($content)): ?>
    <?php print $content ?>
  <?php endif; ?>
</div>
