<?php
/**
 * @file
 * loop_navigation.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function loop_navigation_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_block_ids';
  $strongarm->value = array(
    0 => 1,
    1 => 2,
  );
  $export['menu_block_ids'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_expanded';
  $strongarm->value = array(
    0 => 'management',
  );
  $export['menu_expanded'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'special_menu_items_nolink_tag';
  $strongarm->value = '<a href="#">';
  $export['special_menu_items_nolink_tag'] = $strongarm;

  return $export;
}
