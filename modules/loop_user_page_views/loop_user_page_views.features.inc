<?php
/**
 * @file
 * loop_user_page_views.features.inc
 */

/**
 * Implements hook_views_api().
 */
function loop_user_page_views_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
