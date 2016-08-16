<?php
/**
 * @file
 * loop_admin.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function loop_admin_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_add-content:node/add
  $menu_links['management_add-content:node/add'] = array(
    'menu_name' => 'management',
    'link_path' => 'node/add',
    'router_path' => 'node/add',
    'link_title' => 'Add content',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'management_add-content:node/add',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'management_administration:admin',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add content');


  return $menu_links;
}
