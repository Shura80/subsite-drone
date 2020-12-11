/**
 * @file
 * Custom javascript ENRD LAG DB.
 */

(function ($) {
  // Custom behaviors for the theme.
  Drupal.behaviors.enrd_lag_database = {
      attach: function (context, settings) {

        // Administrator and NSU behavior.
        if ($('#lag-node-form #edit-og-group-ref-und-0-admin, #lag-node-form #edit-og-group-ref-und-0-default').length > 0) {

          $('#lag-node-form #edit-og-group-ref-und-0-admin, #lag-node-form #edit-og-group-ref-und-0-default').on('change', function (e) {

            var main_fund = $(this).find('option:selected').text();

            if (main_fund.length == 0) {
              $("label[for*='edit-field-enrd-additional-esi-funds-und']").parent().toggle(true);
            }
            else {
              // Hide Main ESI Fund from Additional ESI Funds multiple chechbox options.
              if (main_fund.length > 0) {
                var matching_div = $("label[for*='edit-field-enrd-additional-esi-funds-und']:contains(" + main_fund + ")").parent();

                matching_div.toggle(false);

                // Other than hiding the checkbox, uncheck it.
                if (matching_div.find('input:checked')) {
                  matching_div.find('input').prop('checked', false);
                }
              }

              // Restore previously hidden Additional ESI Fund.
              var not_matching_funds = $('label[for*="edit-field-enrd-additional-esi-funds-und-"]').text();
              main_fund = main_fund.replace(')','');
              var additional_funds = not_matching_funds.split(') ', 4);

              // Show Additional ESI Funds not matching the selected Main ESI Fund.
              additional_funds.forEach(function (element) {
                if (element != main_fund) {
                  $("label[for*='edit-field-enrd-additional-esi-funds-und']:contains(" + element + ")").parent().toggle(true);
                }
              });
            }

          }).change();

        }

        // NSU and LAG manager/contact behaviors.
        if ($('#lag-node-form #edit-og-group-ref-und-0-admin').length == 0) {

          // Keep open the dropdown into advance views filters.
          $('#lag-node-form #edit-og-group-ref-und-0-default').on('change', function (e) {

            // Match the ESIF Main fund acronym from Main ESI Fund labels.
            var fund_acronym_regex = /\(([A-Z]+)\)$/i
            var fund_acronym = $('#edit-og-group-ref-und-0-default option:selected').text().match(fund_acronym_regex);

            $('#edit-field-enrd-esif-programme-und optgroup').prop('disabled', true);
            $('#edit-field-enrd-esif-programme-und optgroup[label=' + fund_acronym[1] + ']').prop('disabled', false);

            // Reset the value if the optgroup is disabled or without valid values.
            if (!$('#edit-field-enrd-esif-programme-und').val() || $('#edit-field-enrd-esif-programme-und').val() == '_none') {
              $('#edit-field-enrd-esif-programme-und').val('_none');
              $('#edit-field-enrd-esif-programme-und optgroup[label=' + fund_acronym[1] + ']:enabled option[value=_none]').prop('selected', true);
            }

            // Chosen compatibility.
            $('#edit-field-enrd-esif-programme-und').trigger('chosen:updated');

          }).change();

          $('input[name="field_enrd_main_esi_fund_disabled"]').on('change', function (e) {

            var main_fund = $('input[name="field_enrd_main_esi_fund_disabled"]').val();

            // Hide Main ESI Fund from Additional ESI Funds multiple chechbox options.
            if (main_fund.length > 0) {
              $("label[for*='edit-field-enrd-additional-esi-funds-und']:contains(" + main_fund + ")").parent().toggle(false);
            }

          }).change();

        }

          // Jquery Mask Plugin LAG phone number formatting.
          var phone_number = Drupal.settings.enrd_lag_database.phone;
          var phone_number_warning_message = Drupal.t('Please review and update your phone number in line with the following format: +12 345 6789.');
          var valid = Drupal.settings.enrd_lag_database.valid;

          // Get the phone number input field in edit/create.
          var phone_edit_field = $('#edit-field-enrd-lag-phone-und-0-value');

          // If field exists and number is not defined (new node).
          if (phone_edit_field.length && phone_number == null) {
              // Apply mask and placeholder patterns.
              phone_edit_field.mask('+00 000 0000 0000 0000', {placeholder: "+__ ___ ____"});
          }

          // If field exists and has a valid number.
          if (phone_edit_field.length && phone_number != null && valid == true) {
              phone_edit_field.val(phone_number);
              // Apply mask and placeholder patterns.
              phone_edit_field.mask('+00 000 0000 0000 0000', {placeholder: "+__ ___ ____"});
          }

          if (phone_edit_field.length && phone_number != null && valid == false) {

              // Set a warning message to invite user to update phone number.
              $('div.field-name-field-enrd-lag-phone input').addClass('lag-phone-number-warning');
              $("<span class='lag-phone-number-warning-message'> " + phone_number_warning_message + "</span>").insertAfter(phone_edit_field);

              phone_edit_field.keyup(function () {
                  if (phone_edit_field.val().length) {
                      // When wrong value is removed mask is displayed.
                      phone_edit_field.mask('+00 000 0000 0000 0000', {placeholder: "+__ ___ ____"});
                      // And warning classes and message are removed.
                      $('div.field-name-field-enrd-lag-phone input').removeClass('lag-phone-number-warning');
                      $('span.lag-phone-number-warning-message:before').remove();
                      $('span.lag-phone-number-warning-message').remove();
                  }
              });
          }

          // Field in node view.
          var phone_view_field = $('.main-content .field-name-field-enrd-lag-phone > div.field-items > div.field-item');

          // If field exists and has a valid number.
          if (phone_view_field.length && phone_number != null && valid == true) {
              phone_view_field.text(phone_number);
              // If phone number in view is valid, apply mask.
              phone_view_field.mask('+00 000 0000 0000 0000');
          }

      }
  };

  Drupal.behaviors.collapsibleLagSections = {
    attach: function (context, settings) {
      // Adds and removes 'active' class to "Additional information"
      // and "LAG Funding" headings of the currently shown collapsible item.
      $('.panel-collapse').on('show.bs.collapse', function () {
        $(this).siblings('.additional-info-heading').addClass('active');
      });

      $('.panel-collapse').on('hide.bs.collapse', function () {
        $(this).siblings('.additional-info-heading').removeClass('active');
      });

      $('.panel-collapse').on('show.bs.collapse', function () {
        $(this).siblings('.lag-funding-heading').addClass('active');
      });

      $('.panel-collapse').on('hide.bs.collapse', function () {
        $(this).siblings('.lag-funding-heading').removeClass('active');
      });
    }
  };

  Drupal.behaviors.lagLogo = {
    attach: function (context, settings) {
      // Adds 'lag-logo-active' CSS class if the "LAG logo" is visible.
      if ($('.node-type-lag .ds-lag-headline div').hasClass('field-name-field-enrd-lag-logo')) {

        $('.node-type-lag #page-title').addClass('lag-logo-active');
        $('.node-type-lag .view-mode-full div.project-top').addClass('lag-logo-active');

      }

    }
  };

})(jQuery);
