<?php
/**
 * @file
 * loop_post_wysiwyg.features.inc
 */

/**
 * Implements hook_field_default_field_instances_alter().
 */
function loop_post_wysiwyg_field_default_field_instances_alter(&$data) {
  if (isset($data['comment-comment_node_post-comment_body'])) {
    $data['comment-comment_node_post-comment_body']['settings']['better_formats']['allowed_formats']['editor'] = 'editor'; /* WAS: 0 */
    $data['comment-comment_node_post-comment_body']['settings']['better_formats']['allowed_formats']['html'] = 0; /* WAS: '' */
    $data['comment-comment_node_post-comment_body']['settings']['better_formats']['allowed_formats']['simple'] = 0; /* WAS: 'simple' */
    $data['comment-comment_node_post-comment_body']['settings']['better_formats']['default_order_wrapper']['formats']['html'] = array(
      'weight' => -10,
    ); /* WAS: '' */
  }

  if (isset($data['comment-comment_node_post-field_file_upload_comment'])) {
    $data['comment-comment_node_post-field_file_upload_comment']['widget']['settings']['insert'] = 0; /* WAS: '' */
    $data['comment-comment_node_post-field_file_upload_comment']['widget']['settings']['insert_absolute'] = FALSE; /* WAS: '' */
    $data['comment-comment_node_post-field_file_upload_comment']['widget']['settings']['insert_class'] = ''; /* WAS: '' */
    $data['comment-comment_node_post-field_file_upload_comment']['widget']['settings']['insert_default'] = array(
      0 => 'auto',
    ); /* WAS: '' */
    $data['comment-comment_node_post-field_file_upload_comment']['widget']['settings']['insert_styles'] = array(
      0 => 'auto',
    ); /* WAS: '' */
    $data['comment-comment_node_post-field_file_upload_comment']['widget']['settings']['insert_width'] = ''; /* WAS: '' */
  }

  if (isset($data['node-post-field_description'])) {
    $data['node-post-field_description']['settings']['better_formats']['allowed_formats']['editor'] = 'editor'; /* WAS: 0 */
    $data['node-post-field_description']['settings']['better_formats']['allowed_formats']['html'] = 0; /* WAS: '' */
    $data['node-post-field_description']['settings']['better_formats']['allowed_formats']['simple'] = 0; /* WAS: '' */
    $data['node-post-field_description']['settings']['better_formats']['default_order_wrapper']['formats']['html'] = array(
      'weight' => -10,
    ); /* WAS: '' */
  }

  if (isset($data['node-post-field_file_upload'])) {
    $data['node-post-field_file_upload']['widget']['settings']['insert'] = 0; /* WAS: '' */
    $data['node-post-field_file_upload']['widget']['settings']['insert_absolute'] = FALSE; /* WAS: '' */
    $data['node-post-field_file_upload']['widget']['settings']['insert_class'] = ''; /* WAS: '' */
    $data['node-post-field_file_upload']['widget']['settings']['insert_default'] = array(
      0 => 'auto',
    ); /* WAS: '' */
    $data['node-post-field_file_upload']['widget']['settings']['insert_styles'] = array(
      0 => 'auto',
    ); /* WAS: '' */
    $data['node-post-field_file_upload']['widget']['settings']['insert_width'] = ''; /* WAS: '' */
  }
}

/**
 * Implements hook_views_default_views_alter().
 */
function loop_post_wysiwyg_views_default_views_alter(&$data) {
  if (isset($data['loop_node_comments'])) {
    $data['loop_node_comments']->display['default']->display_options['arguments']['nid']['exception'] = array(
      'title' => 'Alle',
    ); /* WAS: '' */
    $data['loop_node_comments']->display['default']->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter'; /* WAS: '' */
    $data['loop_node_comments']->display['default']->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende'; /* WAS: 'Ascending' */
    $data['loop_node_comments']->display['default']->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende'; /* WAS: 'Descending' */
    $data['loop_node_comments']->display['default']->display_options['pager']['options']['expose'] = array(
      'items_per_page_label' => 'Antal elementer',
      'items_per_page_options_all_label' => '- Alle -',
      'offset_label' => 'Forskydning',
    ); /* WAS: '' */
    $data['loop_node_comments']->display['default']->display_options['pager']['options']['tags'] = array(
      'first' => '« første',
      'previous' => '‹ forrige',
      'next' => 'næste ›',
      'last' => 'sidste »',
    ); /* WAS: '' */
    $data['loop_node_comments']->display['default']->display_options['title'] = 'Kommentar til indhold'; /* WAS: 'Comment for content' */
  }
}
