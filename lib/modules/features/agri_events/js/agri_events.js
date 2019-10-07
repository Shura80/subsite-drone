/**
 * @file
 * Agri_events.js.
 */

/**
 * Other location conditional field.
 */
(function ($) {
    // Form states for conditional field_core_other_location multiselect field.
    Drupal.behaviors.agri_events = {
        attach: function (context, settings) {

            // Get term id from module setting.
            var other_location_id = Drupal.settings.agri_events.other_location;

            $("select[id*=field-core-geographical-area-und]", context).change(function () {
                var country_id = $("select[id$=field-core-geographical-area-und]").chosen().val();
                $("#edit-field-core-other-location").toggle($.inArray(other_location_id, country_id) !== -1);
            }).trigger("change");

            // Set default end time for the end date.
            $("#edit-field-event-date-und-0-value2-datepicker-popup-0").datepicker({
                dateFormat: 'dd/mm/yy',
                onSelect: function () {
                    var popup = $("#edit-field-event-date-und-0-value2-timeEntry-popup-1");
                    if (popup.val() === '') {
                        popup.val("23:59");
                    }
                }
            });

        }
    };

})(jQuery);
