<?php
/**
 * @file
 * loop_taxonomy.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function loop_taxonomy_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_panel_context';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
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
  $display->title = '%term:name';
  $display->uuid = 'eacecc12-ef9b-4b7d-9ec7-1b4ac69aebde';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-13ffa763-5a68-4273-9ea1-d88a2dbd6bc4';
    $pane->panel = 'alpha';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => '',
      'id' => '',
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
    $pane->uuid = '13ffa763-5a68-4273-9ea1-d88a2dbd6bc4';
    $display->content['new-13ffa763-5a68-4273-9ea1-d88a2dbd6bc4'] = $pane;
    $display->panels['alpha'][0] = 'new-13ffa763-5a68-4273-9ea1-d88a2dbd6bc4';
    $pane = new stdClass();
    $pane->pid = 'new-a6e23c12-9e77-4f73-983e-002d6d719342';
    $pane->panel = 'alpha';
    $pane->type = 'views_panes';
    $pane->subtype = 'loop_taxonomy_term-loop_taxonomy_content_pane';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a6e23c12-9e77-4f73-983e-002d6d719342';
    $display->content['new-a6e23c12-9e77-4f73-983e-002d6d719342'] = $pane;
    $display->panels['alpha'][1] = 'new-a6e23c12-9e77-4f73-983e-002d6d719342';
    $pane = new stdClass();
    $pane->pid = 'new-428b46af-5ec6-4eeb-b9e4-a21bec3bde26';
    $pane->panel = 'beta';
    $pane->type = 'flag_link';
    $pane->subtype = 'taxonomy_term';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'flag_name' => 'subscribe_taxonomy',
      'context' => 'argument_term_1',
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
    $pane->uuid = '428b46af-5ec6-4eeb-b9e4-a21bec3bde26';
    $display->content['new-428b46af-5ec6-4eeb-b9e4-a21bec3bde26'] = $pane;
    $display->panels['beta'][0] = 'new-428b46af-5ec6-4eeb-b9e4-a21bec3bde26';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view_panel_context'] = $handler;

  return $export;
}
