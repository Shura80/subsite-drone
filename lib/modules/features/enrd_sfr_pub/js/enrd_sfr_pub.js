/**
 * @file
 * Code for specific behaviors of subscriptions forms.
 */

(function ($) {
  Drupal.behaviors.enrd_sfr_pub = {
    attach: function (context, settings) {

      // CP Subscription request form.
      // Identify all Receive paper copy checkboxes.
      $('.field-name-field-enrd-sfr-pub-subcp-paper input').on('change', function () {
        // Identify all checked Receive paper copy checkboxes.
        var paper_version = $('.field-name-field-enrd-sfr-pub-subcp-paper input:checked').length > 0;
        // Show or hide address field elements not required.
        $('.field-name-field-enrd-sfr-pub-subcp-addr').find('.street-block, .addressfield-container-inline, .locality-block').toggle(paper_version);
        // Show "Delivery Address" group label only if Paper version is checked.
        $('.group-delivery-address h2').toggle(paper_version);
      }).trigger('change');

    },
  }

})(jQuery);
