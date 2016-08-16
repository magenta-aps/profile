<?php
/**
 * @file
 * loop_dashboard.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function loop_dashboard_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'editor_dashboard';
  $page->task = 'page';
  $page->admin_title = 'Editor dashboard';
  $page->admin_description = '';
  $page->path = 'editor/dashboard';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 3,
            1 => 4,
            2 => 5,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => t('Dashboard'),
    'name' => 'menu-loop-primary-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_editor_dashboard_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'editor_dashboard';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Editor dashboard',
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
  $display->layout = 'dashboard';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'alpha' => NULL,
      'beta' => NULL,
      'gamma' => NULL,
      'delta' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Dashboard';
  $display->uuid = '5c4610bd-d98d-4392-833f-1c60080f8cba';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-150e7490-581d-4d5a-80e7-e7acdbb8bdb7';
    $pane->panel = 'alpha';
    $pane->type = 'block';
    $pane->subtype = 'loop_dashboard-loop_dashboard_questions';
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
    $pane->uuid = '150e7490-581d-4d5a-80e7-e7acdbb8bdb7';
    $display->content['new-150e7490-581d-4d5a-80e7-e7acdbb8bdb7'] = $pane;
    $display->panels['alpha'][0] = 'new-150e7490-581d-4d5a-80e7-e7acdbb8bdb7';
    $pane = new stdClass();
    $pane->pid = 'new-fabae8f8-da05-4cd3-90ff-b24e0ae98979';
    $pane->panel = 'beta';
    $pane->type = 'block';
    $pane->subtype = 'loop_dashboard-loop_dashboard_comments';
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
    $pane->uuid = 'fabae8f8-da05-4cd3-90ff-b24e0ae98979';
    $display->content['new-fabae8f8-da05-4cd3-90ff-b24e0ae98979'] = $pane;
    $display->panels['beta'][0] = 'new-fabae8f8-da05-4cd3-90ff-b24e0ae98979';
    $pane = new stdClass();
    $pane->pid = 'new-aaff6e5e-6bc6-41f2-89e4-d988a495466a';
    $pane->panel = 'gamma';
    $pane->type = 'block';
    $pane->subtype = 'loop_dashboard-loop_dashboard_other_content';
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
    $pane->uuid = 'aaff6e5e-6bc6-41f2-89e4-d988a495466a';
    $display->content['new-aaff6e5e-6bc6-41f2-89e4-d988a495466a'] = $pane;
    $display->panels['gamma'][0] = 'new-aaff6e5e-6bc6-41f2-89e4-d988a495466a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['editor_dashboard'] = $page;

  return $pages;

}
