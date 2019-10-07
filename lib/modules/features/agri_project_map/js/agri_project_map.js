/**
 * @file
 * Custom javascript for agri_project_map module.
 */

(function ($) {

    L.custom = {

        init: function (obj, params) {

            var regions = Drupal.settings.agri_project_map.regions;
            var countries = Drupal.settings.agri_project_map.countries;

            var map = L.map(obj, {
                "center": [57, 10],
                "zoom": Drupal.settings.agri_project_map.custom_options.map_zoom,
                "background": Drupal.settings.agri_project_map.custom_options.map_background
            });

            var view_display = Drupal.settings.agri_project_map.current_display;

            window.map = map;

            // Custom options to defined style and events.
            var countries_options = {
                insets: false,
                year: 2013,
                style: function () {
                    return {
                        fillOpacity: 0,
                        weight: 0
                    };
                },

                // Bind events here.
                onEachFeature: function (feature, layer) {

                    var selected_region = regions.indexOf(feature.id);

                    if (selected_region > -1) {

                        layer.setStyle({
                            fillColor: "#c0d731",
                            fillOpacity: 0.7,
                            color: "#000",
                            weight: 1,
                            dashArray: 0
                        });

                        layer.bindLabel(feature.properties.NUTS_NAME);

                        layer.on({
                            click: function () {
                                $.ajax(Drupal.settings.basePath + 'ajax/project-eu-map/' + feature.id + '?view-display=' + view_display, {
                                    success: function (response) {
                                        map.info.show(response);
                                    }
                                });
                            },

                            mouseover: function () {
                                layer.setStyle({
                                    fillOpacity: 1,
                                    weight: 2
                                });
                            },

                            mouseout: function () {
                                layer.setStyle({
                                    fillOpacity: 0.7,
                                    weight: 1
                                });
                            }
                        });
                    }
                }
            };

            // Disable full screen function.
            L.wt.sidebar({
                "fullscreen": false
            }).addTo(map);

            L.wt.countries([{
                "level": 3,
                "countries": countries
            }], countries_options).addTo(map);

            // Process next components.
            $wt._queue("next");

        }
    };

})(jQuery);
