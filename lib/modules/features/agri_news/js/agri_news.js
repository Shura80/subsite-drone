/**
 * @file
 * Agri_news.js.
 */

/**
 * Other location conditional field.
 */
(function ($) {
    // Form states for conditional field_core_other_location multiselect field and
    // conditional field_news_other_location multiselect field.
    Drupal.behaviors.agri_news = {
        attach: function (context, settings) {

            // Get term id from module setting.
            var other_location_id = Drupal.settings.agri_news.other_location;

            // Geographical area in news content type.
            $("select[id*=field-core-geographical-area-und]", context).change(function () {
                var country_id = $("select[id$=field-core-geographical-area-und]").chosen().val();
                $("#edit-field-core-other-location").toggle($.inArray(other_location_id, country_id) !== -1);
            }).trigger("change");

            // Geographical area in funding opportunities content type.
            // The condition should go in AND with.
            $("select[id*=field-news-geographical-area-und]", context).change(function () {
                var country_id = $("select[id$=field-news-geographical-area-und]").chosen().val();
                var fund_type = $("select[id$=field-news-type-of-funding-und]").val();

                $("#edit-field-news-other-location").toggle($.inArray(other_location_id, country_id) !== -1 && fund_type != '_none');

            }).trigger("change");

            $("select[id*=field-news-type-of-funding-und]", context).change(function () {
                var country_id = $("select[id$=field-news-geographical-area-und]").chosen().val();
                var fund_type = $("select[id$=field-news-type-of-funding-und]").val();

                $("#edit-field-news-other-location").toggle($.inArray(other_location_id, country_id) !== -1 && fund_type != '_none');
            }).trigger("change");

        }
    };

})(jQuery);
