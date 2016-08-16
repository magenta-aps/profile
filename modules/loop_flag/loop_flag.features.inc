<?php
/**
 * @file
 * loop_flag.features.inc
 */

/**
 * Implements hook_flag_default_flags().
 */
function loop_flag_flag_default_flags() {
  $flags = array();
  // Exported flag: "Ranking".
  $flags['ranking'] = array(
    'entity_type' => 'comment',
    'title' => 'Ranking',
    'global' => 0,
    'types' => array(),
    'flag_short' => 'Thumbs up',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Remove thumbs up',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'diff_standard' => 'diff_standard',
      'token' => 'token',
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'module' => 'loop_flag',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;
}
