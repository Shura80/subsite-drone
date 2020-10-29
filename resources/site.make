api = 2
core = 7.x

; ===================
; Contributed modules
; ===================

projects[addressfield][subdir] = "contrib"
projects[addressfield][version] = "1.3"

; https://webgate.ec.europa.eu/fpfis/wikis/x/YZ3YC
projects[admin_views][subdir] = "contrib"
; https://www.drupal.org/sa-contrib-2019-076
projects[admin_views][version] = "1.7"

projects[date][subdir] = "contrib"
projects[date][version] = "2.11-rc1"
; Issue #2305049: Wrong timezone handling in migrate process.
; https://www.drupal.org/node/2305049
; https://webgate.ec.europa.eu/CITnet/jira/browse/NEXTEUROPA-3324
; https://webgate.ec.europa.eu/CITnet/jira/browse/NEXTEUROPA-4710

; https://webgate.ec.europa.eu/fpfis/wikis/x/b5d7Eg
projects[double_field][subdir] = "contrib"
projects[double_field][version] = "2.5"

projects[ds_bootstrap_layouts][subdir] = "contrib"
projects[ds_bootstrap_layouts][download][type] = git
projects[ds_bootstrap_layouts][download][revision] = 0bef9d49a2b302c29ebed001b66f415c1d05b6c7
projects[ds_bootstrap_layouts][download][branch] = 7.x-3.x

projects[entityqueue][subdir] = "contrib"
projects[entityqueue][version] = "1.5"

projects[entityreference_view_widget][subdir] = "contrib"
projects[entityreference_view_widget][version] = "2.0-rc6"

projects[expanding_formatter][subdir] = "contrib"
projects[expanding_formatter][version] = "1.0"
;projects[expanding_formatter][patch][] = patches/expanding_formatter-fix_repeated_text.patch

projects[feeds_tamper_string2id][subdir] = "contrib"
projects[feeds_tamper_string2id][version] = "1.1"

projects[facetapi_bonus][subdir] = "contrib"
projects[facetapi_bonus][version] = "1.2"
projects[facetapi_bonus][patch][] = https://www.drupal.org/files/issues/2018-09-04/non-countable-2938545-5.patch

projects[field_collection][subdir] = "contrib"
projects[field_collection][version] = "1.0-beta12"
projects[field_collection][patch][] = patches/field_collection-entity_field_query_exception_unknown_field_issue_1866032.patch
projects[field_collection][patch][] = https://www.drupal.org/files/issues/2018-11-23/field_collection-php72-beta11-2936874-20.patch
projects[field_collection][patch][] = https://www.drupal.org/files/issues/2018-11-30/field_collection_migrate_notice_php_71-3009729-6.patch
projects[field_collection][patch][] = https://www.drupal.org/files/issues/2018-12-13/field_collection-beta12-php72-countable-2992575-25.txt

; Temporary local downgrade of File Entity for the Solr issues (NEMA-2381).
projects[file_entity][subdir] = "contrib"
projects[file_entity][version] = "2.10"

projects[geocoder][subdir] = "contrib"
projects[geocoder][version] = "1.3"
projects[geocoder][patch][] = https://www.drupal.org/files/issues/geocoder-osm-nominatim-address-2682507-2.patch

projects[invisimail][subdir] = "contrib"
projects[invisimail][version] = "1.2"

projects[invite][subdir] = "contrib"
projects[invite][version] = "4.1-rc1"

projects[message_digest][subdir] = "contrib"
projects[message_digest][version] = "1.0"
;Patch for translatable digests.
projects[message_digest][patch][] = https://www.drupal.org/files/issues/message_digest-i18n-2257445-1.patch
;Patch to add table index.
projects[message_digest][patch][] = patches/message-digest-add-table-indexes-2554627-D7.patch
;Patch to fix queue logic when aggregating digests.
projects[message_digest][patch][] = https://www.drupal.org/files/issues/message-queue-logic-2238833-8.patch

projects[message_notify][subdir] = "contrib"
projects[message_notify][version] = "2.5"

projects[message_subscribe][subdir] = "contrib"
projects[message_subscribe][version] = "1.0-rc2"

;Patches on message_subscribe.
projects[message_subscribe][patch][] = https://www.drupal.org/files/issues/2184567-message-subscribe-blocked-users-23.patch
projects[message_subscribe][patch][] = https://www.drupal.org/files/issues/group-context-1828184-67.patch
projects[message_subscribe][patch][] = https://www.drupal.org/files/issues/prevent_loop_of_message-2303795-12.patch

projects[message_subscribe_email_frequency][subdir] = "contrib"
projects[message_subscribe_email_frequency][version] = "1.1"

; https://webgate.ec.europa.eu/fpfis/wikis/x/q98RC
projects[multiple_fields_remove_button][subdir] = "contrib"
projects[multiple_fields_remove_button][version] = "1.5"

; https://webgate.ec.europa.eu/fpfis/wikis/x/ApAFGg
projects[postal_code_validation][subdir] = "contrib"
projects[postal_code_validation][version] = "1.7"

projects[queue_mail][subdir] = "contrib"
projects[queue_mail][version] = "1.6"

projects[redirect][subdir] = "contrib"
projects[redirect][version] = "1.0-rc3"
projects[redirect][patch][] = https://www.drupal.org/files/issues/2018-11-28/redirect-func_get_args-3016519-2.patch

projects[shs][subdir] = "contrib"
projects[shs][version] = "1.8"

projects[special_menu_items][subdir] = "contrib"
projects[special_menu_items][version] = "2.0"

projects[socialfield][subdir] = "contrib"
projects[socialfield][version] = "1.5"
projects[socialfield][patch][] = https://www.drupal.org/files/issues/2823399-default-values-fix.patch
projects[socialfield][patch][] = https://www.drupal.org/files/issues/2018-05-01/socialfield-new-services-unavailable-existing-fields-2464803-12.patch

projects[term_merge][subdir] = "contrib"
projects[term_merge][version] = "1.3"

projects[uuid_features][subdir] = "contrib"
projects[uuid_features][version] = "1.0-rc1"

projects[views_between_dates_filter][subdir] = "contrib"
projects[views_between_dates_filter][version] = "1.0"

; https://webgate.ec.europa.eu/fpfis/wikis/x/cR_CE
projects[views_data_export_phpexcel][subdir] = "contrib"
projects[views_data_export_phpexcel][version] = "1.0"
projects[views_data_export_phpexcel][patch][] = https://www.drupal.org/files/issues/support_batch-2644866-11.patch

projects[views_data_export_phpspreadsheet][download][type] = "git"
projects[views_data_export_phpspreadsheet][download][url] = "https://git.drupalcode.org/project/views_data_export_phpspreadsheet.git"
projects[views_data_export_phpspreadsheet][download][revision] = "2c285de339ba30fa9f0f8303f2d41fd3971bed97"
projects[views_data_export_phpspreadsheet][subdir] = "contrib"

; https://webgate.ec.europa.eu/fpfis/wikis/x/1YDBEg
projects[views_flag_refresh][subdir] = "contrib"
projects[views_flag_refresh][version] = "1.3"
projects[views_flag_refresh][patch][] = https://www.drupal.org/files/issues/views_flag_refresh-1967718-3.patch

projects[views_tree][subdir] = "contrib"
projects[views_tree][version] = "2.0"

projects[webform_references][subdir] = "contrib"
projects[webform_references][version] = "1.9"

projects[webform_validation][subdir] = "contrib"
projects[webform_validation][version] = "1.18"

; =========
; Libraries
; =========

libraries[jquery.rwdimagemaps][download][type] = "git"
libraries[jquery.rwdimagemaps][download][url] = "https://github.com/stowball/jQuery-rwdImageMaps.git"
libraries[jquery.rwdimagemaps][destination] = "libraries"
libraries[jquery.rwdimagemaps][download][tag] = "1.6"

libraries[jquery.mask][download][type] = "git"
libraries[jquery.mask][download][url] = "https://github.com/igorescobar/jQuery-Mask-Plugin.git"
libraries[jquery.mask][download][revision] = "be8c1bb3b9f6040ff923ee81f7b57fe12a0f15e4"
libraries[jquery.mask][destination] = "libraries"

; ======
; Themes
; ======
