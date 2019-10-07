/**
 * @file
 * agri_colorbox.js
 */

/**
 * AGRI custom colorbox settings.
 */
(function ($) {
    Drupal.behaviors.initColorboxDefaultStyle = {
        attach: function (context, settings) {
            $(document).bind('cbox_complete', function () {
              // Only run if there is a title.
              if ($('#cboxTitle:empty', context).length == false) {
                  setTimeout(function () {
                      $('#cboxTitle', context).slideUp()
                  }, 1500);
                    $('#cboxLoadedContent img', context).bind('mouseover', function () {
                        $('#cboxTitle', context).slideDown();
                    });
                    $('#cboxOverlay', context).bind('mouseover', function () {
                        $('#cboxTitle', context).slideUp();
                    });
              }
              else {
                  $('#cboxTitle', context).hide();
              }
            });
            if ($('#cboxLoadedContent > img').attr('src')) {
                var fullHref = $('#cboxLoadedContent > img').attr('src').replace(/styles\/agri_gallery_preview\/public\//, '');
                var fullLink = $('<a/>');
                fullLink.attr('href', fullHref);
                fullLink.attr('target', 'new');
                fullLink.attr('title', Drupal.t('Right click to download'));
                fullLink.text(Drupal.t('Download image'));
                $('#cboxDownload').remove();
                var download = $('<div id="cboxDownload"></div>').append(fullLink).append('<span>|</span>');
                $('#cboxClose').before(download);
            }
        }
  };

})(jQuery);
