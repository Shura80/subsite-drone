; ===================
; This file is intended as an EXAMPLE.
; Copy it to resources/site.make to include it in your builds.
; ===================

api = 2
core = 7.x

; ===================
; Contributed modules
; ===================

projects[calendar][subdir] = "contrib"
projects[calendar][version] = "3.5"
projects[calendar][patch][] = https://www.drupal.org/files/issues/calendar-multi-day-past-future-2698061-2.patch

projects[conditional_fields][subdir] = "contrib"
projects[conditional_fields][version] = "3.0-alpha2"
projects[conditional_fields][patch][] = https://www.drupal.org/files/issues/filled_with_a_value-2142691-16.patch
projects[conditional_fields][patch][] = https://www.drupal.org/files/issues/conditional_fields-IE9_fix-1373656-13.patch

projects[content_lock][subdir] = "contrib"
projects[content_lock][version] = "2.2"

projects[context_menu_block][subdir] = "contrib"
projects[context_menu_block][version] = "3.1"
projects[context_menu_block][patch][] = https://www.drupal.org/files/issues/context_menu_block-2415167-7.patch

projects[context_og][subdir] = "contrib"
projects[context_og][version] = "2.1"

projects[field_collection][subdir] = "contrib"
projects[field_collection][version] = "1.0-beta12"
projects[field_collection][patch][] = https://www.drupal.org/files/issues/field_collection-logic_issue_with_fetchHostDetails-2382089-47.patch

projects[field_collection_fieldset][subdir] = "contrib"
projects[field_collection_fieldset][version] = "2.6"

projects[field_collection_table][subdir] = "contrib"
projects[field_collection_table][version] = "1.0-beta5"

projects[invite][subdir] = "contrib"
projects[invite][version] = "4.1-rc1"

projects[node_clone][subdir] = "contrib"
projects[node_clone][version] = "1.0"

projects[oauth][subdir] = "contrib"
projects[oauth][version] = "3.4"

projects[og_bulkadd][subdir] = "contrib"
projects[og_bulkadd][version] = "1.3"

projects[og_menu][subdir] = "contrib"
projects[og_menu][version] = "3.1"

projects[og_webform][subdir] = "contrib"
projects[og_webform][version] = "1.x-dev"

projects[persistent_menu_items][subdir] = "contrib"
projects[persistent_menu_items][version] = "1.0"

projects[phpexcel][subdir] = "contrib"
projects[phpexcel][version] = "3.11"

projects[redirect][subdir] = "contrib"
projects[redirect][version] = "1.0-rc3"

projects[search_api][subdir] = "contrib"
projects[search_api][version] = "1.22"

projects[search_api_db][subdir] = "contrib"
projects[search_api_db][version] = "1.6"

projects[search_api_exclude][subdir] = "contrib"
projects[search_api_exclude][version] = "1.3"

projects[search_api_saved_searches][subdir] = "contrib"
projects[search_api_saved_searches][version] = "1.7"
projects[search_api_saved_searches][patch][] = https://www.drupal.org/files/issues/2019-03-07/fix-result-count-3038333-2-7.patch

projects[term_merge][subdir] = "contrib"
projects[term_merge][version] = "1.4"

projects[twitter][subdir] = "contrib"
projects[twitter][version] = "5.11"

projects[usermerge][subdir] = "contrib"
projects[usermerge][version] = "2.11"

projects[views_block_filter_block][subdir] = "contrib"
projects[views_block_filter_block][version] = "1.0-beta2"
projects[views_block_filter_block][patch][] = https://www.drupal.org/files/issues/vbfb-no_ajax_dependency-2162479-5.patch

projects[webform_scheduler][subdir] = "contrib"
projects[webform_scheduler][version] = "1.0-beta9"
projects[webform_scheduler][patch][] = https://www.drupal.org/files/issues/webform_scheduler-xss-2924894.patch

projects[webform_validation][subdir] = "contrib"
projects[webform_validation][version] = "1.14"

; =========
; Libraries
; =========

; PHPExcel 1.8.1
libraries[PHPExcel][download][url] = https://github.com/PHPOffice/PHPExcel/archive/1.8.1.zip
libraries[PHPExcel][download][type]= "file"
libraries[PHPExcel][download][request_type]= "get"
libraries[PHPExcel][download][file_type] = "zip"

; bootstrap-hover-dropdown 2.2.1
libraries[bootstrap-hover-dropdown][download][url] = https://github.com/CWSpear/bootstrap-hover-dropdown/archive/v2.2.1.zip
libraries[bootstrap-hover-dropdown][download][type]= "file"
libraries[bootstrap-hover-dropdown][download][request_type]= "get"
libraries[bootstrap-hover-dropdown][download][file_type] = "zip"

; ======
; Themes
; ======
