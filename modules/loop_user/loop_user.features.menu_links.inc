<?php
/**
 * @file
 * loop_user.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function loop_user_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_my-account:user
  $menu_links['main-menu_my-account:user'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'My account',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_my-account:user',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('My account');


  return $menu_links;
}
