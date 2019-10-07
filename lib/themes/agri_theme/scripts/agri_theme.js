/**
 * @file
 * Custom javascript for agri_theme.
 */

(function ($) {
    $(document).ready(function () {

      function isMobile() {
          return /Android|webOS|iPhone|iPad|iPod|BlackBerry|IEMobile|Opera Mini/i.test(navigator.userAgent);
      }

      if (isMobile()) {

          $('.navbar .dropdown > a').click(function () {
              console.log('this: ' + this);
            if ($(this).data('clicked') == 'true') {
                location.href = $(this).attr('href');
            }
            else {
                $(this).data('clicked', 'true');
            }
          });
      }
      else {
          $('[data-hover="dropdown"]').dropdownHover()
              .click(function () {
                  document.location.href = this.href;
              });
      }
    });
})(jQuery);
