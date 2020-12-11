/**
 * @file
 * Custom ENRD Mastermind behavior.
 */

(function ($) {

  Drupal.behaviors.enrd_mastermind = {
    attach: function (context, settings) {
      if (!Drupal.views || !Drupal.views.instances) {
        return;
      }

      for (var i in Drupal.views.instances) {
        var instance = Drupal.views.instances[i],
          url = instance.element_settings.url;

        // Check for any valid views filter identifiers and remove them.
        var validViewsIdentifiers = Drupal.settings.validViewsIdentifiers || '';
        if (validViewsIdentifiers) {
          url = decodeURIComponent(url);

          for (var j = 0; j < validViewsIdentifiers.length; j++) {
            var regExpr = '\\&?' + validViewsIdentifiers[j] + '(\\[\\])?=[^&]*';
            var regExprObj = new RegExp(regExpr, 'g');

            url = url.replace(regExprObj, "");
          }
        }

        // Only the .options.url part is needed for the desired functionality.
        // The rest is modified for consistency.
        instance.element_settings.url = url;

        if (instance.exposedFormAjax) {
          instance.exposedFormAjax.options.url = url;
          instance.exposedFormAjax.element_settings = instance.element_settings;
          instance.exposedFormAjax.url = url;
        }

        if (instance.pagerAjax) {
          instance.pagerAjax.options.url = url;
          instance.pagerAjax.element_settings = instance.element_settings;
          instance.pagerAjax.url = url;
        }

        if (instance.refreshViewAjax) {
          instance.refreshViewAjax.options.url = url;
          instance.refreshViewAjax.element_settings = instance.element_settings;
          instance.refreshViewAjax.url = url;
        }
      }
    }
  };

})(jQuery);
