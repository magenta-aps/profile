<?php
/**
 * @file
 * loop_frontpage.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function loop_frontpage_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-welcome'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'welcome',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'loop' => array(
        'region' => 'pagetop',
        'status' => 1,
        'theme' => 'loop',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
