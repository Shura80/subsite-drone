/**
 * @file
 * Custom javascript ENRD NRN Profiles.
 */

(function ($) {

  Drupal.behaviors.enrd_nrn_profiles = {
    attach: function (context, settings) {
      // Adds and removes 'active' class to collapsible fields.
      $('.panel-collapse').on('show.bs.collapse', function () {
        $(this).siblings('.enrd-collapse-field').addClass('active');
      });

      $('.panel-collapse').on('hide.bs.collapse', function () {
        $(this).siblings('.enrd-collapse-field').removeClass('active');
      });
    }
  };

})(jQuery);
