/**
 * @file
 * Code for specific behaviors of enrd_readmore.
 */

(function ($) {

  Drupal.behaviors.enrd_readmore = {
    attach: function (context, settings) {

      $.each(settings.enrdReadmore, function (selector, value) {
        Drupal.behaviors.enrd_readmore.swap(selector, settings);
      });
    },

    swap: function (selector, settings) {
      var containar = $(selector);
      var original = containar.html();

      containar.html(settings.enrdReadmore[selector]);
      settings.enrdReadmore[selector] = original;

      $(selector)
          .find('.enrd-readmore-trigger')
          .show()
          .click(function (e) {
            Drupal.behaviors.enrd_readmore.swap(selector, settings);
            e.preventDefault();
          });
    }
  };

})(jQuery);
