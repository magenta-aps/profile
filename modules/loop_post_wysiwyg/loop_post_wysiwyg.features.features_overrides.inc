<?php
/**
 * @file
 * loop_post_wysiwyg.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function loop_post_wysiwyg_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field_instance
  $overrides["field_instance.comment-comment_node_post-comment_body.settings|better_formats|allowed_formats|editor"] = 'editor';
  $overrides["field_instance.comment-comment_node_post-comment_body.settings|better_formats|allowed_formats|html"] = 0;
  $overrides["field_instance.comment-comment_node_post-comment_body.settings|better_formats|allowed_formats|simple"] = 0;
  $overrides["field_instance.comment-comment_node_post-comment_body.settings|better_formats|default_order_wrapper|formats|html"] = array(
    'weight' => -10,
  );
  $overrides["field_instance.comment-comment_node_post-field_file_upload_comment.widget|settings|insert"] = 0;
  $overrides["field_instance.comment-comment_node_post-field_file_upload_comment.widget|settings|insert_absolute"] = FALSE;
  $overrides["field_instance.comment-comment_node_post-field_file_upload_comment.widget|settings|insert_class"] = '';
  $overrides["field_instance.comment-comment_node_post-field_file_upload_comment.widget|settings|insert_default"] = array(
    0 => 'auto',
  );
  $overrides["field_instance.comment-comment_node_post-field_file_upload_comment.widget|settings|insert_styles"] = array(
    0 => 'auto',
  );
  $overrides["field_instance.comment-comment_node_post-field_file_upload_comment.widget|settings|insert_width"] = '';
  $overrides["field_instance.node-post-field_description.settings|better_formats|allowed_formats|editor"] = 'editor';
  $overrides["field_instance.node-post-field_description.settings|better_formats|allowed_formats|html"] = 0;
  $overrides["field_instance.node-post-field_description.settings|better_formats|default_order_wrapper|formats|html"] = array(
    'weight' => -10,
  );
  $overrides["field_instance.node-post-field_file_upload.widget|settings|insert"] = 0;
  $overrides["field_instance.node-post-field_file_upload.widget|settings|insert_absolute"] = FALSE;
  $overrides["field_instance.node-post-field_file_upload.widget|settings|insert_class"] = '';
  $overrides["field_instance.node-post-field_file_upload.widget|settings|insert_default"] = array(
    0 => 'auto',
  );
  $overrides["field_instance.node-post-field_file_upload.widget|settings|insert_styles"] = array(
    0 => 'auto',
  );
  $overrides["field_instance.node-post-field_file_upload.widget|settings|insert_width"] = '';

  // Exported overrides for: views_view
  $overrides["views_view.loop_node_comments.display|default|display_options|arguments|nid|exception"] = array(
    'title' => 'Alle',
  );
  $overrides["views_view.loop_node_comments.display|default|display_options|exposed_form|options|exposed_sorts_label"] = 'Sortér efter';
  $overrides["views_view.loop_node_comments.display|default|display_options|exposed_form|options|sort_asc_label"] = 'Stigende';
  $overrides["views_view.loop_node_comments.display|default|display_options|exposed_form|options|sort_desc_label"] = 'Faldende';
  $overrides["views_view.loop_node_comments.display|default|display_options|pager|options|expose"] = array(
    'items_per_page_label' => 'Antal elementer',
    'items_per_page_options_all_label' => '- Alle -',
    'offset_label' => 'Forskydning',
  );
  $overrides["views_view.loop_node_comments.display|default|display_options|pager|options|tags"] = array(
    'first' => '« første',
    'previous' => '‹ forrige',
    'next' => 'næste ›',
    'last' => 'sidste »',
  );
  $overrides["views_view.loop_node_comments.display|default|display_options|title"] = 'Kommentar til indhold';

 return $overrides;
}
