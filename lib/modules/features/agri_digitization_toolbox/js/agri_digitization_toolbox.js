/**
 * @file
 * Code to display checkboxes instead of flag links in Digitization toolbox view.
 */

(function ($) {
  Drupal.behaviors.agri_digitization_toolbox = {
    attach: function (context, settings) {

      $('span.flag-agri-digitization-toolbox a.flag').each(function () {
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
  }

})(jQuery);
