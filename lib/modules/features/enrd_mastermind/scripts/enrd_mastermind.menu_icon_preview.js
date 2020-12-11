/**
 * @file
 * Custom javascript menu icons.
 */

(function ($) {
  // Menu icons preview behavior.
  Drupal.behaviors.menu_icon_preview = {
    attach: function (context, settings) {

      $('#edit-options-attributes-data-image, #edit-menu-options-attributes-data-image').on('change', function (e) {
        var type = $(this.options[this.selectedIndex]).closest('optgroup').prop('label');
        var icon = Drupal.checkPlain($(this).val());

        switch (type) {
          case 'ENRD Icons':
            icon_class = 'icon ' + icon;
            break;

          case 'Glyphicons':
          default:
            icon_class = 'glyphicon glyphicon-' + icon;
        }

        $("#options-attributes-data-image-preview").remove();
        $(this).before(Drupal.theme('menuItemIcons', 'options-attributes-data-image-preview', icon_class));
      }).trigger('change');

    },
  }

  Drupal.theme.prototype.menuItemIcons = function (id, icon_class) {
    return '<span id="' + id + '" class="' + icon_class + '"></span> ';
  }

})(jQuery);
