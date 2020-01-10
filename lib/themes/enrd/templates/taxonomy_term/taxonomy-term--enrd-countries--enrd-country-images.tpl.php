<?php

/**
 * @file
 * Default theme implementation to display a term.
 *
 * Available variables:
 * - $name: (deprecated) The unsanitized name of the term. Use $term_name
 *   instead.
 * - $content: An array of items for the content of the term (fields and
 *   description). Use render($content) to print them all, or print a subset
 *   such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $term_url: Direct URL of the current term.
 * - $term_name: Name of the current term.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - taxonomy-term: The current template type, i.e., "theming hook".
 *   - vocabulary-[vocabulary-name]: The vocabulary to which the term
 *   belongs to.
 *   For example, if the term is a "Tag" it would result in "vocabulary-tag".
 *
 * Other variables:
 * - $term: Full term object. Contains data that may not be safe.
 * - $view_mode: View mode, e.g. 'full', 'teaser'...
 * - $page: Flag for the full page state.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the term. Increments each time it's output.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * @see template_preprocess()
 * @see template_preprocess_taxonomy_term()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<?php if (isset($term)): ?>
 <?php if (empty($content['field_enrd_countries_flag'][0]['file'])): ?>
   <div class="col-md-12">
 <?php endif; ?>
   <div id="taxonomy-term-<?php print $term->tid; ?>" class="<?php print $classes; ?>">
     <h1>
       <?php if (!empty($content['field_enrd_countries_flag'][0]['file']['#item']['uri'])): ?>
       <span style="background-image: url('<?php print file_create_url($content['field_enrd_countries_flag'][0]['file']['#item']['uri']); ?>');"></span>
       <?php endif; ?>
       <?php if (isset($term_name)): ?>
       <?php print $term_name; ?>
       <?php endif; ?>
       <?php if (!empty($content['field_enrd_countries_shape'][0]['file']['#item']['uri'])): ?>
       <span style="background-image: url('<?php print file_create_url($content['field_enrd_countries_shape'][0]['file']['#item']['uri']); ?>');"></span>
       <?php endif; ?>
     </h1>
   </div>
 <?php if (empty($content['field_enrd_countries_flag'][0]['file'])): ?>
   </div>
 <?php endif; ?>
<?php endif; ?>
