/**
 * @file
 * Code for specific behaviors of enrd_fieldtips.
 */

(function ($) {

  Drupal.behaviors.enrd_fieldtips = {
    attach: function (context) {

      $('.enrd-fieldtips-item').children().once('enrd-fieldtips')
        .each(function () {

          var description = $(this).find('.description, .fieldset-description').last().hide().text();

          if (description.length) {
            $(this).find('label:first, .text-format-wrapper label, table.field-multiple-table label:first')
              .append(' ')
              .append($('<span class="glyphicon glyphicon-question-sign" data-toggle="tooltip" />').prop('title', description))
              .append(' ');
          }

        });
    }
  };

})(jQuery);
