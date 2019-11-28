/**
 * @file
 * agri_core.js
 */

/**
 * Autofill phone field with country phone code set in field_core_country.
 */
(function ($) {

  Drupal.behaviors.agriCoreSetPhoneCode = {
    attach: function (context, settings) {

      var country_phone_codes = Drupal.settings.agri_core.country_phone_codes;

      $("select[id*=field-core-geographical-area-und]").change(function () {
        var count = $(":selected", this).length;

        var country_id = $("select[id$=field-core-geographical-area-und]").chosen().val();
        var phone_field = $("input[id$=field-user-phone-und-0-value]");

        // Check if selected country matches a phone code.
        $.each(country_phone_codes, function (key, element) {
          if (count > 0 && count <= 1) {
            if (country_id === key) {
              phone_field.val(element + " ");
            }
          }
          else {
            phone_field.val("");
          }
        });

      });
    }
  };
})(jQuery);
