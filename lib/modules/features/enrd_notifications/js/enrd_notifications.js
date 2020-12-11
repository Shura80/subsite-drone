/**
 * @file
 * Code for behavior of email flags in notifications settings form.
 *
 * Ajax views call and js setting parameters for notification panel.
 */

(function ($) {
  Drupal.behaviors.enrd_notifications = {
    attach: function (context, settings) {
      var set_follow_checkboxes = function () {
        // Replace every email flag link element that
        // has class ot the type  flag-email-[NAME] with a checkbox.
        $('#quicktabs-enrd_notifications_settings span[class*="flag-email"] a').
          each(function () {
            var a_target = $(this).addClass('formatted-as-checkbox')

            if (a_target.children('span').length === 0) {
              a_target.wrapInner('<span class="hidden"></span>')
            }

            if (a_target.hasClass('flag-action') &&
              a_target.children('input').length === 0) {
              a_target.prepend('<input type="checkbox">')
            }
            else if (a_target.children('input').length === 0) {
              a_target.prepend('<input type="checkbox" checked>')
            }
          })
      }

      // Call the function to replace link with checkboxes on settings panel.
      if ($('#quicktabs-enrd_notifications_settings a.flag').length > 0) {
        set_follow_checkboxes()
      }

      // Notifications List: remove table header for read messages.
      if ($('.view-enrd-notifications-messages table.unread').length
        && $('.view-enrd-notifications-messages table.read').length) {
        $('.view-enrd-notifications-messages table.read thead').hide()
      }

      // Notifications Panel.
      // Badge Counter.
      if ($('.enrd-notifications-counter').length) {
        // Define view to call, method and parameters.
        $.ajax({
          type: 'get',
          url: Drupal.settings.basePath + 'views/ajax',
          dataType: 'json',
          data: {
            view_name: 'enrd_notifications_messages',
            view_display_id: 'notifications_badge_count',
          },
          // On success, print a message counter inside the element.
          success: function (response) {
            if (response[1] !== undefined) {
              var output = response[1].data
              $('.enrd-notifications-counter').html(output)
            }
          },
        })
      }

      // Notifications Panel.
      // Load latest unread messages.
      $('.enrd-notifications-panel-button', context).one('click', function () {
        // Get the limit value set in Message Subscribe form.
        var panel_limit = Drupal.settings.enrd_notifications.enrd_notifications_panel_limit
        // Define view to call, method and parameters.
        $.ajax({
          type: 'get',
          url: Drupal.settings.basePath + 'views/ajax',
          dataType: 'json',
          data: {
            view_name: 'enrd_notifications_messages',
            view_display_id: 'latest_notifications',
            items_per_page: panel_limit,
          },
          // On success, print latest messages in the panel element.
          success: function (response) {
            if (response[1] !== undefined) {
              var output = response[1].data
              $('.enrd-notifications-panel.latest-messages-list').html(output)
            }
          },
        })
      })
    },
  }

})(jQuery)
