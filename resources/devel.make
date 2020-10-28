api = 2
core = 7.x

; ===================
; Contributed modules
; ===================

projects[devel][subdir] = "development"
projects[devel][version] = "1.7"

projects[maillog][subdir] = "development"
projects[maillog][version] = "1.0-alpha1"

projects[memcache][subdir] = "development"
projects[memcache][version] = "1.6"

projects[module_filter][subdir] = "development"
projects[module_filter][version] = "2.2"

projects[stage_file_proxy][subdir] = "development"
projects[stage_file_proxy][version] = "1.9"

; Used for development purposes.
projects[taxonomy_csv][subdir] = "contrib"
projects[taxonomy_csv][version] = "5.10"
projects[taxonomy_csv][patch][] = https://www.drupal.org/files/taxonomy_csv-rm_unknown_options_check-1475952-10.patch
