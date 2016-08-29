<?php
/**
 * @file
 * loop_frontpage.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function loop_frontpage_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'loop_frontpage';
  $page->task = 'page';
  $page->admin_title = 'Loop frontpage';
  $page->admin_description = 'Frontpage for Loop website';
  $page->path = 'front';
  $page->access = array(
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_loop_frontpage_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'loop_frontpage';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Loop frontpage panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'loop--front',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'User',
        'keyword' => 'user',
        'name' => 'user',
        'type' => 'current',
        'uid' => '',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'front-page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'middle' => NULL,
      'alpha' => NULL,
      'beta' => NULL,
      'gamma' => NULL,
      'delta' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'ac956a2f-d36c-42be-bf88-33d3ee789124';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9946cfb1-6914-4e31-ad6f-caa5d2dd7ce6';
    $pane->panel = 'alpha';
    $pane->type = 'views_panes';
    $pane->subtype = 'user_messages-panel_pane_5';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'uid' => '%user:uid',
      ),
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
    $pane->uuid = '9946cfb1-6914-4e31-ad6f-caa5d2dd7ce6';
    $display->content['new-9946cfb1-6914-4e31-ad6f-caa5d2dd7ce6'] = $pane;
    $display->panels['alpha'][0] = 'new-9946cfb1-6914-4e31-ad6f-caa5d2dd7ce6';
    $pane = new stdClass();
    $pane->pid = 'new-60f29869-b2c4-427b-9e50-d3537c4f8d7f';
    $pane->panel = 'beta';
    $pane->type = 'views_panes';
    $pane->subtype = 'loop_questions_by_user_profession-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 6,
            ),
          ),
          'context' => 'context_user_1',
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '60f29869-b2c4-427b-9e50-d3537c4f8d7f';
    $display->content['new-60f29869-b2c4-427b-9e50-d3537c4f8d7f'] = $pane;
    $display->panels['beta'][0] = 'new-60f29869-b2c4-427b-9e50-d3537c4f8d7f';
    $pane = new stdClass();
    $pane->pid = 'new-04d21e8b-d7fe-4319-a74c-27503eb8ce1e';
    $pane->panel = 'delta';
    $pane->type = 'views_panes';
    $pane->subtype = 'loop_taxonomy_terms_list-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Topics',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '04d21e8b-d7fe-4319-a74c-27503eb8ce1e';
    $display->content['new-04d21e8b-d7fe-4319-a74c-27503eb8ce1e'] = $pane;
    $display->panels['delta'][0] = 'new-04d21e8b-d7fe-4319-a74c-27503eb8ce1e';
    $pane = new stdClass();
    $pane->pid = 'new-32f36dc4-4cfe-44f6-9512-2697d6290ea2';
    $pane->panel = 'gamma';
    $pane->type = 'views_panes';
    $pane->subtype = 'loop_questions_by_user_competence-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '32f36dc4-4cfe-44f6-9512-2697d6290ea2';
    $display->content['new-32f36dc4-4cfe-44f6-9512-2697d6290ea2'] = $pane;
    $display->panels['gamma'][0] = 'new-32f36dc4-4cfe-44f6-9512-2697d6290ea2';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['loop_frontpage'] = $page;

  return $pages;

}
