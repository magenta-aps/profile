<?php
/**
 * @file
 * loop_external_data.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function loop_external_data_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
  return NULL;
}

/**
 * Implements hook_node_info().
 */
function loop_external_data_node_info() {
  $items = array(
    'index' => array(
      'name' => t('Index'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'leaf' => array(
      'name' => t('Leaf'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'tree' => array(
      'name' => t('Tree'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
