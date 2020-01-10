/**
 * @file
 * Custom javascript for ENRD sub theme.
 */

// Every script put in that block will use jQuery 1.7.1
// add your code in the ready function if you want to be sure the page is fully
// loaded before execution.
(function ($) {
  // Custom behaviors for the theme.
  Drupal.behaviors.enrd = {
    attach: function (context, settings) {

      // Enable responsive maps.
      $('img[usemap]').rwdImageMaps && $('img[usemap]').rwdImageMaps();

      // Keep open the dropdown into advance views filters.
      $('.dropdown-menu').on('click', function (e) {
        if ($(this).hasClass('keep-open')) {
          e.stopPropagation();
        }
      });

      // Fix carousel items heights.
      $('.normalize .carousel').each(function () {
        $(this).carouselHeights();
      });

      // Activates collapsible behavior on Accordion elements.
      $('.accordion').on('show.bs.collapse', function () {
        $(this).find('.in').collapse('hide');
      });

      // Adds 'active' class to the panel heading of the currently shown accordion item.
      $('.panel-collapse').on('show.bs.collapse', function () {
        $(this).siblings('.panel-heading').addClass('active');
      });

      // Remove 'active' class to the panel heading of the previous shown accordion item.
      $('.panel-collapse').on('hide.bs.collapse', function () {
        $(this).siblings('.panel-heading').removeClass('active');
      });

      // Tooltips.
      $('[data-toggle="tooltip"]').tooltip();

      // Menu dropdown.
      $('.dropdown-toggle').dropdown();

      // Run Drupal status message of type 'modal' as Bootstrap Modal.
      $('.modal-message').modal();

      $('.button-checkbox').each(function () {

        // Add glyphicon settings to icons.
        var $widget = $(this),
          $button = $widget.find('button'),
          $checkbox = $widget.find('input:checkbox'),
          color = $button.data('color'),
          settings = {
            on: {
              icon: 'glyphicon glyphicon-check'
            },
            off: {
              icon: 'glyphicon glyphicon-unchecked'
            }
          };

        // Event Handlers applied on checkbox elements.
        $button.on('click', function () {
          $checkbox.prop('checked', !$checkbox.is(':checked'));
          $checkbox.triggerHandler('click');
          updateDisplay();
        });
        $checkbox.on('click', function () {
          updateDisplay();
        });

        // Actions applied on checkbox elements.
        function updateDisplay() {
          var isChecked = $checkbox.is(':checked');

          // Set the button's state.
          $button.data('state', (isChecked) ? "on" : "off");

          // Set the button's icon.
          $button.find('.state-icon')
            .removeClass()
            .addClass('state-icon ' + settings[$button.data('state')].icon);

          // Update the button's color.
          if (isChecked) {
            $button
              .removeClass('btn-default')
              .addClass('btn-' + color + ' active');
          }
          else {
            $button
              .removeClass('btn-' + color + ' active')
              .addClass('btn-default');
          }
        }

        // Initialization.
        function init() {

          updateDisplay();

          // Inject the icon if applicable.
          if ($button.find('.state-icon').length == 0) {
            $button.prepend('<i class="state-icon ' + settings[$button.data('state')].icon + '"></i> ');
          }
        }
        init();
      });
    }
  };

  Drupal.behaviors.enrd_main_menu = {
    attach: function (context) {

      if (window.matchMedia) {
        // Media query screen-md.
        var mq_md = window.matchMedia('(min-width: 992px)');
        mq_md.addListener(WidthChange);
        WidthChange(mq_md);
      }

      // Media query change.
      function WidthChange(mq) {
        if (mq.matches) {
          // Recalculate menu dropdown height for 2nd levels.
          $('.region-sidebar-left ul.nav li ul').each(function (index) {
            var parentHeight = Math.max.apply(null, $(this).find('ul').map(function () {
                return $(this).height();
            }).get()) + 40;
            if ($(this).height() < parentHeight) {
              $(this).css('height', parentHeight);
            }
          });
        }
      }
    }
  };

  // Custom behaviors for the twitterfeed.
  Drupal.behaviors.twitterfeed = {
    attach: function (context, settings) {

      var showNumber = 3;
      var startPos = 0;
      var endPos = showNumber;
      var $List = $('#block-bean-twitterfeeds .smk-tweets');
      $List.hide().slice(startPos ,endPos).fadeIn();

      $('#tweet-next').on('click', function () {
        var $List = $('#block-bean-twitterfeeds .smk-tweets');
        if (endPos < $List.length) {
          startPos = startPos + showNumber;
          endPos = endPos + showNumber;
          $List.hide().slice(startPos ,endPos).fadeIn();
        }
        return false;
      });

      $('#tweet-prev').on('click', function () {
        var $List = $('#block-bean-twitterfeeds .smk-tweets');
        if (startPos > 0) {
          startPos = startPos - showNumber;
          endPos = endPos - showNumber;
          $List.hide().slice(startPos ,endPos).fadeIn();
        }
        return false;
      });
    }
  };

  // Mobile header adjustments.
  Drupal.behaviors.mobile_header = {
    attach: function (context) {

      $('#block-system-user-menu', context).once('createDomMobileElements', function () {

        // Clone Global search box to mobile header.
        if ($('#block-search-form').length) {
          $('#search-block-form').clone().appendTo($('#search-box-holder'));
        }

        // Add 'open' class when clicking on the search button.
        $('#search-box-holder >a').on('click tap', function (e) {
          $(this).toggleClass('open');
          e.preventDefault();
        });

        // Hide search block when clicking outside of the search bar.
        $('body').on('click tap', function (e) {
          var $trigger = $('#search-box-holder');
          if ($trigger.has(e.target).length == 0 && !$trigger.is(e.target)) {
            $('#search-box-holder >a').removeClass('open');
          }
        });

        // Clone user menu to mobile header.
        if ($('#block-system-user-menu > .username').length) {
          $('#block-system-user-menu > .username').clone().appendTo($('#user-menu-holder')).find('.dropdown-toggle>.glyphicon').removeClass('btn');
          $('#user-menu-holder .username .dropdown-toggle>*:not(.glyphicon)').prependTo($('#user-menu-holder .username .dropdown-menu')).wrapAll('<li class="userMenuTitle"></li>');
        }

        // Clone Main menu to mobile header and adds mobile behaviours  and mobile specific elements.
        if ($('#block-system-main-menu > .menu').length) {
          $('#block-system-main-menu > .menu').clone().appendTo($('#main-menu-holder')).wrapAll('<div class="menu-mobile"></div>');
          $('#main-menu-holder .menu > li > ul').each(function (index) {
            $(this).prepend(Drupal.theme('responsiveMenuBackButton', Drupal.t('Back'), Drupal.t('Go back to previous level')))
              .find('.menuback > a').on('click tap',function (e) {
                $(this).parent().parent().toggleClass('open');
                e.preventDefault();
              });

            $(Drupal.theme('responsiveMenuSelectButton')).on('click tap',function (e) {
              var myContainer = $('.menu-mobile > .menu');
              var scrollTo = $(this).next('ul');
              scrollTo.toggleClass('open');
              myContainer.animate({
                scrollTop: scrollTo.offset().top - myContainer.offset().top + myContainer.scrollTop()
              });
              e.preventDefault();
            }).insertBefore($(this));
          });
        }

        // Clone tool buttons to mobile menu block.
        if ($('.region-tools-buttons>section').length) {
          $('.region-tools-buttons').clone().appendTo($('#main-menu-holder .menu-mobile'));
        }

      });

      $('#main-menu-holder >a').on('click',function (e) {
        $(this).toggleClass('open');
        e.preventDefault();
      })
    }
  };

  Drupal.behaviors.header_scroller = {
    attach: function (context, settings) {

      // Initialize headroom.js.
      var myScroll = document.querySelector('#mobile-header');
      // Construct an instance of Headroom, passing the element.
      var headroom = new Headroom(myScroll, {
        'offset': document.getElementById('mobile-header-wrapper').offsetTop,
        'tolerance': {
          down : 50,
          up : 30
        },
      });

      // Initialise.
      headroom.init();
    }
  };

  // Opens the URL by selecting a Country from the homepage Country Map select options (Mobile).
  Drupal.behaviors.eucountrymap = {
    attach: function (context, settings) {
      $('select[name=eu-country-map]').on('change', function () {
        var url = $(this).val();
        if (url) {
          window.location = url;
        }
        return false;
      });
    }
  };

  // Opens all CP Publication documents in a new tab.
  Drupal.behaviors.enrd_publications = {
    attach: function (context, settings) {
      $('.field-name-field-enrd-publication-file a').attr('target', '_blank');
      $('.field-name-field-enrd-publications-rel-docs a').attr('target', '_blank');
    }
  };

  Drupal.theme.prototype.responsiveMenuBackButton = function (text, title) {
    return '<li class="menuback"><a title="' + title + '" href="#"><span class="glyphicon glyphicon-chevron-left"></span><span>' + text + '</span></a></li>';
  };

  Drupal.theme.prototype.responsiveMenuSelectButton = function () {
    return '<a class="haschildren" href="#"><span class="glyphicon glyphicon-chevron-right"></span></a>';
  }

})(jQuery);

/**
 * Normalize Bootstrap Carousel Items Heights.
 */
(function ($) {
  $.fn.carouselHeights = function () {

    // Initialize vars to work with carousel items height.
    var items = $(this).find('.item'),
      carousel_inner = $(this).find('.carousel-inner'),
      heights = [],
      tallest,
      // Initialize the timer handler.
      resizeId;

    // Define the function to set the minimum height to carousel items.
    var normalizeHeights = function () {
      tallest = 0;
      heights.length = 0;

      items.each(function () {
        heights.push($(this).height());
      });
      tallest = Math.max.apply(null, heights);
      carousel_inner.css('min-height', tallest + 'px');
    };

    // Call normalize even if there are no resize or orientationchange events.
    normalizeHeights();

    // Reset carousel items minimum height when resizing the window or
    // when device screen orientation is changed.
    $(window).on('resize orientationchange', function () {
      normalizeHeights();
      // Initially clear timeout.
      clearTimeout(resizeId);
      // Set timeout to match CSS ".container" selector transition duration.
      resizeId = setTimeout(normalizeHeights, 100);
    });
  };
})(jQuery);
