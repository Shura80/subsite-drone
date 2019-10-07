/**
 * @file
 * Custom javascript for agri_project module.
 */

(function ($) {

    // Form states for conditional field_core_other_location multiselect field.
    Drupal.behaviors.agri_projects = {
        attach: function (context, settings) {

            // Hide the fieldset group_proj_partners if empty.
            $('[name="field_proj_funding_source_list[und]"]', context).change(function () {
                $('fieldset.group-proj-partners').toggle(true).toggle($('fieldset.group-proj-partners .fieldset-wrapper > *').filter(':visible').length > 0);
            }).change();

            // Check if term id is passed from module.
            if (typeof Drupal.settings.agri_projects !== 'undefined') {

                // Get term id from module setting.
                var other_location_id = Drupal.settings.agri_projects.other_location;
                // Projects multiple choices Geographical scope field.
                $("select[id*=field-proj-geographical-area-und]", context).change(function () {
                    var country_id = $("select[id$=field-proj-geographical-area-und]").chosen().val();
                    $("#edit-field-proj-other-location").toggle($.inArray(other_location_id, country_id) !== -1);
                }).trigger("change");

                // Project ideas multiple choices Geographical scope field.
                $("select[id*=field-core-geographical-area-und]", context).change(function () {
                    var country_id = $("select[id$=field-core-geographical-area-und]").chosen().val();
                    $("#edit-field-core-other-location").toggle($.inArray(other_location_id, country_id) !== -1);
                }).trigger("change");

            }

            // Show flag links as checkbox in Projects content type.
            $('span.flag-agri-privacy-policy a.flag').each(function () {
                var a_target = $(this).addClass('formatted-as-checkbox');

                if (a_target.contents().length) {
                    // Remove the standard link and show checkbox only.
                    a_target.wrapInner('<span style="display: none;"></span>')
                }
                if (a_target.hasClass('flag-action') && a_target.children('input').length === 0) {
                    a_target.prepend('<input type="checkbox">')
                }
                else if (a_target.children('input').length === 0) {
                    a_target.prepend('<input type="checkbox" checked>')
                }
            })
        }
    };

})(jQuery);
