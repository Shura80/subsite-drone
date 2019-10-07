/**
 * @file
 * Agri_publications.js.
 */

/**
 * Other location conditional field.
 */
(function ($) {
    // Form states for conditional field_core_other_location multiselect field.
    Drupal.behaviors.agri_publications = {
        attach: function (context, settings) {

            // Get term id from module setting.
            var other_location_id = Drupal.settings.agri_publications.other_location;

            $("select[id*=field-core-geographical-area-und]", context).change(function () {
                var country_id = $("select[id$=field-core-geographical-area-und]").chosen().val();
                $("#edit-field-core-other-location").toggle($.inArray(other_location_id, country_id) !== -1);
            }).trigger("change");
        }
    };

})(jQuery);
