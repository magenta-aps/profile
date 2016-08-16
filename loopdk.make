api = 2
core = 7.x

; Contrib modules
projects[abuse][type] = "module"
projects[abuse][subdir] = "contrib"
projects[abuse][download][type] = "git"
projects[abuse][download][url] = "http://git.drupal.org/project/abuse.git"
projects[abuse][download][branch] = "7.x-1.x-dev"

projects[admin_views][subdir] = "contrib"
projects[admin_views][version] = "1.5"

projects[auto_entitylabel][subdir] = "contrib"
projects[auto_entitylabel][version] = "1.3"

projects[autocomplete_deluxe][subdir] = "contrib"
projects[autocomplete_deluxe][version] = "2.1"

projects[better_formats][subdir] = "contrib"
projects[better_formats][version] = "1.0-beta1"

projects[comment_counter][subdir] = "contrib"
projects[comment_counter][version] = "1.0-alpha1"

projects[ctools][subdir] = "contrib"
projects[ctools][version] = "1.9"

projects[date][subdir] = "contrib"
projects[date][version] = "2.9"

projects[diff][subdir] = "contrib"
projects[diff][version] = "3.2"

projects[elements][subdir] = "contrib"
projects[elements][version] = "1.4"

projects[entity][subdir] = "contrib"
projects[entity][version] = "1.6"

projects[entitycache][subdir] = "contrib"
projects[entitycache][version] = "1.5"

projects[entityreference][subdir] = "contrib"
projects[entityreference][version] = "1.1"

projects[facetapi][subdir] = "contrib"
projects[facetapi][version] = "1.5"

projects[features][subdir] = "contrib"
projects[features][version] = "2.7"

projects[features_extra][subdir] = "contrib"
projects[features_extra][version] = "1.0"

projects[features_override][subdir] = "contrib"
projects[features_override][version] = "2.0-rc2"

projects[field_group][subdir] = "contrib"
projects[field_group][version] = "1.5"

projects[flag][subdir] = "contrib"
projects[flag][version] = "3.7"

projects[globalredirect][subdir] = "contrib"
projects[globalredirect][version] = "1.5"

projects[google_analytics][subdir] = "contrib"
projects[google_analytics][version] = "2.x-dev"

projects[google_analytics_counter][subdir] = "contrib"
projects[google_analytics_counter][version] = "3.2"

projects[html5_tools][subdir] = "contrib"
projects[html5_tools][version] = "1.3"

projects[i18n][subdir] = "contrib"
projects[i18n][version] = "1.13"

projects[i18nviews][subdir] = "contrib"
projects[i18nviews][version] = "3.x-dev"

projects[jquery_update][subdir] = "contrib"
projects[jquery_update][version] = "3.0-alpha3"

projects[l10n_update][subdir] = "contrib"
projects[l10n_update][version] = "1.1"

projects[libraries][subdir] = "contrib"
projects[libraries][version] = "2.2"

projects[link][subdir] = "contrib"
projects[link][version] = "1.3"

projects[logintoboggan][subdir] = "contrib"
projects[logintoboggan][version] = "1.5"

projects[memcache][subdir] = "contrib"
projects[memcache][version] = "1.5"

projects[mailsystem][subdir] = "contrib"
projects[mailsystem][version] = "2.34"

projects[menu_admin_per_menu][subdir] = "contrib"
projects[menu_admin_per_menu][version] = "1.1"

projects[menu_attributes][subdir] = "contrib"
projects[menu_attributes][version] = "1.0-rc3"

projects[menu_block][subdir] = "contrib"
projects[menu_block][version] = "2.7"

projects[menu_token][subdir] = "contrib"
projects[menu_token][version] = "1.0-beta5"

projects[menu_position][subdir] = "contrib"
projects[menu_position][version] = "1.2"

projects[metatag][subdir] = "contrib"
projects[metatag][version] = "1.7"

projects[message][subdir] = "contrib"
projects[message][version] = "1.10"

projects[message_notify][subdir] = "contrib"
projects[message_notify][version] = "2.5"

projects[message_subscribe][subdir] = "contrib"
projects[message_subscribe][version] = "1.0-rc2"

projects[mimemail][subdir] = "contrib"
projects[mimemail][version] = "1.0-beta4"

projects[module_filter][subdir] = "contrib"
projects[module_filter][version] = "2.0"

projects[node_export][subdir] = "contrib"
projects[node_export][version] = "3.0"

projects[node_limit][subdir] = "contrib"
projects[node_limit][version] = "1.0-alpha5"

projects[oauth][subdir] = "contrib"
projects[oauth][version] = "3.2"

projects[page_title][subdir] = "contrib"
projects[page_title][version] = "2.7"

projects[panels][subdir] = "contrib"
projects[panels][version] = "3.5"

projects[pathauto][subdir] = "contrib"
projects[pathauto][version] = "1.3"

projects[path_breadcrumbs][subdir] = "contrib"
projects[path_breadcrumbs][version] = "3.3"

projects[pcp][subdir] = "contrib"
projects[pcp][version] = "1.7"

projects[redirect][subdir] = "contrib"
projects[redirect][version] = "1.0-rc3"

projects[role_delegation][subdir] = "contrib"
projects[role_delegation][version] = "1.1"

projects[rules][subdir] = "contrib"
projects[rules][version] = "2.9"

projects[saml_sp][type] = "module"
projects[saml_sp][subdir] = "contrib"
projects[saml_sp][download][type] = "git"
projects[saml_sp][download][url] = "http://git.drupal.org/project/saml_sp.git"
projects[saml_sp][download][branch] = "7.x-2.x"
; SAML SP bugfixes:
projects[saml_sp][patch][] = "https://www.drupal.org/files/issues/nameid-correction.patch"
projects[saml_sp][patch][] = "https://www.drupal.org/files/issues/2649478-saml_sp-validation_of_signed_elements_fails-2.patch"
; Custom SAML SP hooks
projects[saml_sp][patch][] = "https://raw.githubusercontent.com/os2loop/profile/master/patches/saml_sp_drupal_login-alter_user_hooks.patch"

projects[search_api][subdir] = "contrib"
projects[search_api][version] = "1.16"

projects[search_api_page][subdir] = "contrib"
projects[search_api_page][version] = "1.2"

projects[search_api_solr][subdir] = "contrib"
projects[search_api_solr][version] = "1.9"

projects[search_api_spellcheck][subdir] = "contrib"
projects[search_api_spellcheck][version] = "1.0"

projects[secure_permissions][subdir] = "contrib"
projects[secure_permissions][version] = "1.6"

projects[shorten][subdir] = "contrib"
projects[shorten][version] = "1.4"

projects[shurly][subdir] = "contrib"
projects[shurly][version] = "1.2"

projects[simplesamlphp_auth][subdir] = "contrib"
projects[simplesamlphp_auth][version] = "2.0-alpha2"

projects[special_menu_items][subdir] = "contrib"
projects[special_menu_items][version] = "2.0"

projects[statistics_counter][subdir] = "contrib"
projects[statistics_counter][version] = "1.4"

projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = "2.0"

projects[style_settings][type] = "module"
projects[style_settings][subdir] = "contrib"
projects[style_settings][download][type] = "git"
projects[style_settings][download][url] = "http://git.drupal.org/project/style_settings.git"
projects[style_settings][download][branch] = "7.x-2.x"

projects[taxonomy_manager][subdir] = "contrib"
projects[taxonomy_manager][version] = "1.0"

projects[token][subdir] = "contrib"
projects[token][version] = "1.6"
projects[token][patch] = "https://www.drupal.org/files/issues/token-field_description_overwritten-2474403-12-D7.patch"

projects[transliteration][subdir] = "contrib"
projects[transliteration][version] = "3.2"

projects[uuid][subdir] = "contrib"
projects[uuid][version] = "1.0-beta1"

projects[uuid_features][subdir] = "contrib"
projects[uuid_features][version] = "1.0-alpha4"

projects[variable][subdir] = "contrib"
projects[variable][version] = "2.5"

projects[views][subdir] = "contrib"
projects[views][version] = "3.13"
projects[views][patch][] = "https://drupal.org/files/views-make_destination_parameter_configurable-1239566-26.patch"
projects[views][patch][] = "https://drupal.org/files/views-1685144-localization-bug_1.patch"

projects[views_calc][subdir] = "contrib"
projects[views_calc][version] = "1.1"

projects[views_bulk_operations][subdir] = "contrib"
projects[views_bulk_operations][version] = "3.3"

projects[views_flag_refresh][subdir] = "contrib"
projects[views_flag_refresh][version] = "1.3"

projects[wysiwyg][subdir] = "contrib"
projects[wysiwyg][version] = "2.x-dev"

; Libraries
libraries[ckeditor][download][type] = "get"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%204.5.3/ckeditor_4.5.3_full.zip"
libraries[ckeditor][directory_name] = "ckeditor"
libraries[ckeditor][destination] = "libraries"

libraries[respondjs][download][type] = "get"
libraries[respondjs][download][url] = "https://raw.github.com/scottjehl/Respond/master/dest/respond.min.js"
libraries[respondjs][directory_name] = "respondjs"
libraries[respondjs][destination] = "libraries"

libraries[php-saml][download][type] = "git"
libraries[php-saml][download][url] = "https://github.com/onelogin/php-saml.git"
libraries[php-saml][directory_name] = "php-saml"
libraries[php-saml][destination] = "libraries"

libraries[xmlseclibs][download][type] = "git"
libraries[xmlseclibs][download][url] = "https://github.com/Maks3w/xmlseclibs.git"
libraries[xmlseclibs][directory_name] = "xmlseclibs"
libraries[xmlseclibs][destination] = "libraries"
