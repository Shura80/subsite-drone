<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT
 *     output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field.
 *     Do not use:
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html
 *     to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
<article class="search-result row">
    <div class="col-xs-12 col-sm-12 col-md-12">
        <h3><a href="#"
               title=""><?php print $fields['title_field']->content; ?></a></h3>
        <div class="project-details">
            <ul class="list-inline">
                <li><i class="glyphicon glyphicon-flag"></i><b><?php print $fields['field_enrd_lag_code']->label_html; ?></b></li>
                <li><?php print $fields['field_enrd_lag_code']->content; ?></li>
            </ul>
            <ul class="list-inline">
                <li><i class="glyphicon glyphicon-globe"></i><b><?php print $fields['field_tax_country']->label_html; ?></b></li>
                <li><?php print $fields['field_tax_country']->content; ?></li>
            </ul>
            <ul class="list-inline">
                <li><i class="glyphicon glyphicon-map-marker"></i><b><?php print $fields['og_enrd_rdps_group_ref']->label_html; ?></b></li>
                <li><?php print $fields['og_enrd_rdps_group_ref']->content; ?></li>
            </ul>
        </div>
    </div>
    <span class="clearfix borda"></span>
</article>
