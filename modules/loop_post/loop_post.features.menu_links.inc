<?php
/**
 * @file
 * loop_post.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function loop_post_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_create-post:node/add/post
  $menu_links['main-menu_create-post:node/add/post'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/post',
    'router_path' => 'node/add/post',
    'link_title' => 'Create post',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
      'identifier' => 'main-menu_create-post:node/add/post',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 40,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Create post');


  return $menu_links;
}
