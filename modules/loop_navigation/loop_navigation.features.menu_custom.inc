<?php
/**
 * @file
 * loop_navigation.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function loop_navigation_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: management.
  $menus['management'] = array(
    'menu_name' => 'management',
    'title' => 'Management',
    'description' => 'The <em>Management</em> menu contains links for administrative tasks.',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Exported menu: menu-loop-primary-menu.
  $menus['menu-loop-primary-menu'] = array(
    'menu_name' => 'menu-loop-primary-menu',
    'title' => 'Loop Primary Menu',
    'description' => 'Primary menu with support for smaller screen and touch devices. Works as a submenu to Main Menu',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Translatables.
  // Included for use with string extractors like potx.
  t('Loop Primary Menu');
  t('Management');
  t('Primary menu with support for smaller screen and touch devices. Works as a submenu to Main Menu');
  t('The <em>Management</em> menu contains links for administrative tasks.');


  return $menus;
}
