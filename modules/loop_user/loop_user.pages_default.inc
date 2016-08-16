<?php
/**
 * @file
 * loop_user.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function loop_user_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view_panel_context';
  $handler->task = 'user_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -26;
  $handler->conf = array(
    'title' => 'User default',
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
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 2,
            ),
          ),
          'context' => 'argument_entity_id:user_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'default-inverted';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'alpha' => NULL,
      'beta' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = t('My account');
  $display->uuid = 'c7d4a77e-2a44-4a1a-82a4-b7f43bc9eb64';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-7294dcc5-8036-41d5-9877-9f58311aca79';
    $pane->panel = 'alpha';
    $pane->type = 'page_tabs';
    $pane->subtype = 'page_tabs';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'compare_users',
          'settings' => array(
            'equality' => '1',
          ),
          'context' => array(
            0 => 'logged-in-user',
            1 => 'argument_entity_id:user_1',
          ),
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 2,
            ),
          ),
          'context' => 'argument_entity_id:user_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'type' => 'primary',
      'id' => 'tabs',
      'override_title' => 1,
      'override_title_text' => t('My account'),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7294dcc5-8036-41d5-9877-9f58311aca79';
    $display->content['new-7294dcc5-8036-41d5-9877-9f58311aca79'] = $pane;
    $display->panels['alpha'][0] = 'new-7294dcc5-8036-41d5-9877-9f58311aca79';
    $pane = new stdClass();
    $pane->pid = 'new-5e25e15f-93b5-4fbd-9641-bd465af4ebde';
    $pane->panel = 'alpha';
    $pane->type = 'block';
    $pane->subtype = 'loop_user-loop_user_my_content';
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
          'context' => 'argument_entity_id:user_1',
          'not' => TRUE,
        ),
      ),
    );
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5e25e15f-93b5-4fbd-9641-bd465af4ebde';
    $display->content['new-5e25e15f-93b5-4fbd-9641-bd465af4ebde'] = $pane;
    $display->panels['alpha'][1] = 'new-5e25e15f-93b5-4fbd-9641-bd465af4ebde';
    $pane = new stdClass();
    $pane->pid = 'new-6a0864bc-1d3c-47b2-ba5c-0c07ba36a9cb';
    $pane->panel = 'alpha';
    $pane->type = 'block';
    $pane->subtype = 'pcp-pcp_profile_percent_complete';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'compare_users',
          'settings' => array(
            'equality' => '1',
          ),
          'context' => array(
            0 => 'argument_entity_id:user_1',
            1 => 'logged-in-user',
          ),
          'not' => FALSE,
        ),
      ),
    );
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '6a0864bc-1d3c-47b2-ba5c-0c07ba36a9cb';
    $display->content['new-6a0864bc-1d3c-47b2-ba5c-0c07ba36a9cb'] = $pane;
    $display->panels['alpha'][2] = 'new-6a0864bc-1d3c-47b2-ba5c-0c07ba36a9cb';
    $pane = new stdClass();
    $pane->pid = 'new-e76e52ca-1d49-493d-9c54-9ef9eb411c58';
    $pane->panel = 'beta';
    $pane->type = 'user_profile';
    $pane->subtype = 'user_profile';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:user_1',
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
    $pane->uuid = 'e76e52ca-1d49-493d-9c54-9ef9eb411c58';
    $display->content['new-e76e52ca-1d49-493d-9c54-9ef9eb411c58'] = $pane;
    $display->panels['beta'][0] = 'new-e76e52ca-1d49-493d-9c54-9ef9eb411c58';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['user_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view_panel_context_2';
  $handler->task = 'user_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'User comments',
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
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'user/*/user-comments',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'default-inverted';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'alpha' => NULL,
      'beta' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'e9af1ed2-a64c-42f8-9012-18cbca45c96c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0ff8be8d-2667-4466-97cc-03c6480b3f2d';
    $pane->panel = 'alpha';
    $pane->type = 'page_tabs';
    $pane->subtype = 'page_tabs';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'compare_users',
          'settings' => array(
            'equality' => '1',
          ),
          'context' => array(
            0 => 'logged-in-user',
            1 => 'argument_entity_id:user_1',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'type' => 'primary',
      'id' => 'tabs',
      'override_title' => 1,
      'override_title_text' => t('My account'),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0ff8be8d-2667-4466-97cc-03c6480b3f2d';
    $display->content['new-0ff8be8d-2667-4466-97cc-03c6480b3f2d'] = $pane;
    $display->panels['alpha'][0] = 'new-0ff8be8d-2667-4466-97cc-03c6480b3f2d';
    $pane = new stdClass();
    $pane->pid = 'new-d54b6d08-ff65-4b68-ba91-d34c5df86ffb';
    $pane->panel = 'alpha';
    $pane->type = 'block';
    $pane->subtype = 'loop_user-loop_user_my_content';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'd54b6d08-ff65-4b68-ba91-d34c5df86ffb';
    $display->content['new-d54b6d08-ff65-4b68-ba91-d34c5df86ffb'] = $pane;
    $display->panels['alpha'][1] = 'new-d54b6d08-ff65-4b68-ba91-d34c5df86ffb';
    $pane = new stdClass();
    $pane->pid = 'new-a1745ca6-b03f-4e34-9d1d-7601d4a472a2';
    $pane->panel = 'beta';
    $pane->type = 'views_panes';
    $pane->subtype = 'loop_user_comments-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Comments by %user:field_first_name %user:field_last_name',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a1745ca6-b03f-4e34-9d1d-7601d4a472a2';
    $display->content['new-a1745ca6-b03f-4e34-9d1d-7601d4a472a2'] = $pane;
    $display->panels['beta'][0] = 'new-a1745ca6-b03f-4e34-9d1d-7601d4a472a2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['user_view_panel_context_2'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view_panel_context_3';
  $handler->task = 'user_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'User content',
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
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'user/*/nodes',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'default-inverted';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'alpha' => NULL,
      'beta' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '6dbb6314-3658-4cfa-ac35-edfe448e432a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c3c35b81-0280-40f1-880b-a4209f49978d';
    $pane->panel = 'alpha';
    $pane->type = 'page_tabs';
    $pane->subtype = 'page_tabs';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'compare_users',
          'settings' => array(
            'equality' => '1',
          ),
          'context' => array(
            0 => 'logged-in-user',
            1 => 'argument_entity_id:user_1',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'type' => 'primary',
      'id' => 'tabs',
      'override_title' => 1,
      'override_title_text' => t('My account'),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c3c35b81-0280-40f1-880b-a4209f49978d';
    $display->content['new-c3c35b81-0280-40f1-880b-a4209f49978d'] = $pane;
    $display->panels['alpha'][0] = 'new-c3c35b81-0280-40f1-880b-a4209f49978d';
    $pane = new stdClass();
    $pane->pid = 'new-85ee600e-4da4-4ce8-8515-35744a4b7d99';
    $pane->panel = 'alpha';
    $pane->type = 'block';
    $pane->subtype = 'loop_user-loop_user_my_content';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '85ee600e-4da4-4ce8-8515-35744a4b7d99';
    $display->content['new-85ee600e-4da4-4ce8-8515-35744a4b7d99'] = $pane;
    $display->panels['alpha'][1] = 'new-85ee600e-4da4-4ce8-8515-35744a4b7d99';
    $pane = new stdClass();
    $pane->pid = 'new-39196a6c-b47a-44a1-94fc-3423a5f0bdc9';
    $pane->panel = 'beta';
    $pane->type = 'views_panes';
    $pane->subtype = 'loop_user_nodes-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Content by %user:field_first_name %user:field_last_name',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '39196a6c-b47a-44a1-94fc-3423a5f0bdc9';
    $display->content['new-39196a6c-b47a-44a1-94fc-3423a5f0bdc9'] = $pane;
    $display->panels['beta'][0] = 'new-39196a6c-b47a-44a1-94fc-3423a5f0bdc9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['user_view_panel_context_3'] = $handler;

  return $export;
}
