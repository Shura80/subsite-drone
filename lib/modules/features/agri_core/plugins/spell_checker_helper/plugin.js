/**
 * @file
 * Javascript file for text collapse.
 */

CKEDITOR.plugins.add('spell_checker_helper',
    {
        init: function (editor) {
            /* COMMAND */
            editor.addCommand('cmdSpellCheckerHelper', new CKEDITOR.dialogCommand('spellCheckerHelper'));

            /* BUTTON */
            editor.ui.addButton('spell_checker_helper',
                {
                    label: Drupal.settings.agri_core.button_label,
                    command: 'cmdSpellCheckerHelper',
                    icon: this.path + 'spell_checker_helper.png'
                });

            /* DIALOG */
            CKEDITOR.dialog.add('spellCheckerHelper', function (editor) {
                return {
                    title: Drupal.settings.agri_core.dialog_title,
                    minWidth: 300,
                    minHeight: 200,
                    contents: [{
                        id: 'tab1',
                        label: 'Settings',
                        elements: [{
                            type: 'html',
                            html: Drupal.settings.agri_core.dialog_text
                        }]
                    }],
                    buttons: [CKEDITOR.dialog.okButton]
                };
                // dialog.add.
            });
            // init:
        }
        // plugin.add.
    });
