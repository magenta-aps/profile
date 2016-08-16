<?php
/**
 * @file
 * loop_external_data.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function loop_external_data_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_3';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Index',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'index' => 'index',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'default';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'alpha' => NULL,
      'beta' => NULL,
      'gamma' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'fc2f1421-2340-415a-ab80-fe95608db5a3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-872c5807-d590-41ed-b339-906724e7da6d';
    $pane->panel = 'alpha';
    $pane->type = 'block';
    $pane->subtype = 'loop_external_data-index';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '872c5807-d590-41ed-b339-906724e7da6d';
    $display->content['new-872c5807-d590-41ed-b339-906724e7da6d'] = $pane;
    $display->panels['alpha'][0] = 'new-872c5807-d590-41ed-b339-906724e7da6d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-872c5807-d590-41ed-b339-906724e7da6d';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_3'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_4';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'Leaf',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'leaf' => 'leaf',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'default';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'alpha' => NULL,
      'beta' => NULL,
      'gamma' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '4c6d5cdd-f8f7-4155-b7f8-8c8804131c3b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3b521531-c722-415c-8687-ae664338bef1';
    $pane->panel = 'alpha';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 0,
      'no_extras' => 1,
      'override_title' => 1,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 0,
      'leave_node_title' => 1,
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3b521531-c722-415c-8687-ae664338bef1';
    $display->content['new-3b521531-c722-415c-8687-ae664338bef1'] = $pane;
    $display->panels['alpha'][0] = 'new-3b521531-c722-415c-8687-ae664338bef1';
    $pane = new stdClass();
    $pane->pid = 'new-2ef7ffa5-e978-4102-a994-4888b531cc35';
    $pane->panel = 'beta';
    $pane->type = 'block';
    $pane->subtype = 'loop_external_data-index';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2ef7ffa5-e978-4102-a994-4888b531cc35';
    $display->content['new-2ef7ffa5-e978-4102-a994-4888b531cc35'] = $pane;
    $display->panels['beta'][0] = 'new-2ef7ffa5-e978-4102-a994-4888b531cc35';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_4'] = $handler;

  return $export;
}
