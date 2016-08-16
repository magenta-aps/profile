<?php
/**
 * @file
 * loop_profession_optional.features.inc
 */

/**
 * Implements hook_field_default_field_instances_alter().
 */
function loop_profession_optional_field_default_field_instances_alter(&$data) {
  if (isset($data['user-user-field_profession'])) {
    $data['user-user-field_profession']['required'] = 0; /* WAS: 1 */
  }
}
