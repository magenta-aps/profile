<?php
/**
 * @file
 * loop_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function loop_content_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function loop_content_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Side'),
      'base' => 'node_content',
      'description' => t('This content type is for static content, like about page.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  return $items;
}
