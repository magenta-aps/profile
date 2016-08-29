<?php
/**
 * @file
 * loop_taxonomy.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function loop_taxonomy_taxonomy_default_vocabularies() {
  return array(
    'keyword' => array(
      'name' => 'Keyword',
      'machine_name' => 'keyword',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'profession' => array(
      'name' => 'Profession',
      'machine_name' => 'profession',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'subject' => array(
      'name' => 'Subject',
      'machine_name' => 'subject',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
