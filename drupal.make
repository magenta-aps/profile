api = 2
core = 7.x

; Core
; As d.o is having issues with the update XML file, we are using this form for downloading core.
; See this: https://drupal.org/node/2126123
projects[drupal][type] = core
projects[drupal][version] = 7.34
projects[drupal][download][type] = get
projects[drupal][download][url] = http://ftp.drupal.org/files/projects/drupal-7.34.tar.gz
projects[drupal][patch][] = "https://drupal.org/files/drupal-menu_navigation_links-1018614-83.patch"
projects[drupal][patch][] = "https://drupal.org/files/issues/translate_role_names-2205581-1.patch"

; Install profile.
projects[loopdk][type] = "profile"
projects[loopdk][download][type] = "git"
projects[loopdk][download][url] = "git@github.com:loopdk/profile.git"
projects[loopdk][download][branch] = "master"
