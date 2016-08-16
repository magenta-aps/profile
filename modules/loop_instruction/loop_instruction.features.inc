<?php
/**
 * @file
 * loop_instruction.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function loop_instruction_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function loop_instruction_node_info() {
  $items = array(
    'instruction' => array(
      'name' => t('Instruction'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
