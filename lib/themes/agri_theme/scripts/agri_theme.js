/**
 * @file
 * Custom javascript for agri_theme.
 */

(function ($) {

  // Custom behaviors for agri_theme.
  Drupal.behaviors.agri_theme = {
    attach: function (context, settings) {

      // Custom behaviors for the bean static block.
      var content = ".bean-agri-static-block";
      var link_field = ".field-name-field-agri-core-bean-link";

      $(content + ' a').on('click', function (e) {
        e.stopPropagation();
      });
      $(content).on("click", function () {
        var parent_id = '#' + $(this).parent().attr('id');
        $(parent_id).find(link_field + ' a')[0].click();
      }).css("cursor", "pointer");

      $(link_field).hide();

      // Check is mobile.
      if (this.isMobile()) {

        $('.navbar .dropdown > a').click(function () {
          if ($(this).data('clicked') == 'true') {
            location.href = $(this).attr('href');
          }
          else {
            $(this).data('clicked', 'true');
          }
        });
      }
      else {
        $('[data-hover="dropdown"]').dropdownHover().click(function () {
          document.location.href = this.href;
        });
      }
    },

    isMobile: function () {
      return /Android|webOS|iPhone|iPad|iPod|BlackBerry|IEMobile|Opera Mini/i.test(navigator.userAgent);
    }
  };

  // Define custom callback for the twitterfeed.
  window.agriThemeTwitterFeedsBlock = function (e) {
    $("#block-agri-core-agri-core-twitter-feeds").slideDown("slow");
  };

})(jQuery);
