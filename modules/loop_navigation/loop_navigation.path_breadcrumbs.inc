<?php
/**
 * @file
 * loop_navigation.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function loop_navigation_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'add_node';
  $path_breadcrumb->name = 'Add node';
  $path_breadcrumb->path = 'node/add/%type';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '!page_title',
    ),
    'paths' => array(
      0 => '%site:current-page:path',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'type' => array(
        'position' => 2,
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['add_node'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'node_breadcrumbs';
  $path_breadcrumb->name = 'Node breadcrumbs';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%node:field-subject',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => '%node:field-subject:url',
      1 => '%node:url',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Indholdselement: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['node_breadcrumbs'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'subject_breadcrumb';
  $path_breadcrumb->name = 'Subject breadcrumb';
  $path_breadcrumb->path = 'taxonomy/term/%term';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%term',
    ),
    'paths' => array(
      0 => '%term',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'term' => array(
        'position' => 2,
        'argument' => 'term',
        'settings' => array(
          'identifier' => 'Taksonomiterm: ID',
          'input_form' => 'tid',
          'vids' => array(
            1 => 0,
            2 => 0,
            3 => 0,
          ),
          'breadcrumb' => 1,
          'transform' => 0,
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['subject_breadcrumb'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_breadcrumb';
  $path_breadcrumb->name = 'User breadcrumb';
  $path_breadcrumb->path = 'user/%uid';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '!page_title',
    ),
    'paths' => array(
      0 => 'user/!uid',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'uid' => array(
        'position' => 1,
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['user_breadcrumb'] = $path_breadcrumb;

  return $export;
}
