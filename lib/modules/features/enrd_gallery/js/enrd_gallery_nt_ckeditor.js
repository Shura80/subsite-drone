/**
 * @file
 * CKEDITOR plugin file.
 */

(function ($) {

  /**
   * NextEuropa Token CKEditor plugin extension.
   */
  CKEDITOR.on('dialogDefinition', function (evt) {
    // Check that it's NextEuropa Token CKEditor dialog.
    var dialogName = evt.data.name;

    if (dialogName === 'nexteuropa_token_ckeditor_dialog') {
      // The definition of the dialog window.
      var definition = evt.data.definition;

      definition.contents.push({
        // Add "ENRD Gallery" tab and wrapper to the dialog window.
        id: 'info-enrd-galleries',
        label: Drupal.t('Insert Media Galleries'),
        title: Drupal.t('Insert Media Galleries'),
        elements: [
          {
            id: 'enrd_gallery_embed_gallery_ckeditor',
            type: 'html',
            html: '<div class="enrd-gallery-dialog-container"></div>'
          }
        ]
      });

      // Attach to the function executed when dialog is displayed for the first time.
      definition.dialog.on('load', function () {

        // Get CKEditor object.
        var editor = this.getParentEditor();

        // Store current editor id. It will be refreshed every time a new dialog is open.
        Drupal.nexteuropa_token_ckeditor = Drupal.nexteuropa_token_ckeditor || {};
        Drupal.nexteuropa_token_ckeditor.current_editor_id = editor.id;

        if (!(editor.id in Drupal.nexteuropa_token_ckeditor)) {
          // Get "ENRD Gallery" dialog container id.
          var id = 'enrd-gallery-' + editor.id + '-dialog-container';
          // Get dialog DOM object.
          var content = $(this.getElement('info-enrd-galleries', 'enrd_gallery_embed_gallery_ckeditor').$);
          $('.enrd-gallery-dialog-container', content).attr('id', id);

          var ajax_settings = {
            url: Drupal.settings.basePath + 'nexteuropa/enrd-gallery-ckeditor/' + id,
            event: 'dialog.enrd-gallery-embed-gallery-ckeditor',
            method: 'html'
          };
          // Set Ajax config. to the dialog DOM object.
          Drupal.ajax[id] = new Drupal.ajax(id, content[0], ajax_settings);
          content.trigger(ajax_settings.event);
        }
      });

    }

  });

})(jQuery);
