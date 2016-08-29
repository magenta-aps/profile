<?php
/**
 * @file
 * loop_external_sources_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function loop_external_sources_content_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function loop_external_sources_content_node_info() {
  $items = array(
    'external_sources' => array(
      'name' => t('External sources'),
      'base' => 'node_content',
      'description' => t('Content containing links to external data'),
      'has_title' => '1',
      'title_label' => t('Description'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
