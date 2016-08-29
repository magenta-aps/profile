<?php
/**
 * @file
 * loop_frontend.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function loop_frontend_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['system-main-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main-menu',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'loop' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'loop',
        'weight' => -13,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
