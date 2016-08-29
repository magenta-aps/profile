<?php

/**
 * Implements hook_views_query_alter().
 *
 * Removes leaf and tree content from admin/content.
 */
function loop_admin_views_query_alter(&$view, &$query) {
  if ($view->name == "admin_views_node") {
    $query->where[1]['conditions'][] = array(
      'field' => "node.type",
      'value' => array(
        'leaf',
        'tree'
      ),
      'operator' => 'not in'
    );
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Removes leaf and tree in exposed form.
 */
function loop_admin_form_views_exposed_form_alter(&$form, &$form_state) {
  if (isset($form['type']['#options']['leaf'])) {
    unset($form['type']['#options']['leaf']);
    unset($form['type']['#options']['tree']);
  }
}
