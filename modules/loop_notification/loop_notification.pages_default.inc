<?php
/**
 * @file
 * loop_notification.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function loop_notification_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'messages';
  $page->task = 'page';
  $page->admin_title = 'Messages';
  $page->admin_description = '';
  $page->path = 'user/%uid/messages';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Messages',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => 'Messages',
      'name' => 'user-menu',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'uid' => array(
      'id' => 1,
      'identifier' => 'User: ID',
      'name' => 'entity_id:user',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_messages_panel_context_3';
  $handler->task = 'page';
  $handler->subtask = 'messages';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Messages all',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(),
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
  $display->title = t('Messages');
  $display->uuid = '24c2a122-e628-4285-8035-99f5feb65405';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d238d16d-9bb1-4f72-90cf-3cc562c02413';
    $pane->panel = 'alpha';
    $pane->type = 'page_tabs';
    $pane->subtype = 'page_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'type' => 'both',
      'id' => 'tabs',
      'override_title' => 1,
      'override_title_text' => 'My account',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd238d16d-9bb1-4f72-90cf-3cc562c02413';
    $display->content['new-d238d16d-9bb1-4f72-90cf-3cc562c02413'] = $pane;
    $display->panels['alpha'][0] = 'new-d238d16d-9bb1-4f72-90cf-3cc562c02413';
    $pane = new stdClass();
    $pane->pid = 'new-15ea4d5b-703a-48fc-b7c4-912cb88bba91';
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
    $pane->uuid = '15ea4d5b-703a-48fc-b7c4-912cb88bba91';
    $display->content['new-15ea4d5b-703a-48fc-b7c4-912cb88bba91'] = $pane;
    $display->panels['alpha'][1] = 'new-15ea4d5b-703a-48fc-b7c4-912cb88bba91';
    $pane = new stdClass();
    $pane->pid = 'new-1401f447-c816-4338-b5e3-ea028d9b9871';
    $pane->panel = 'beta';
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
    $pane->uuid = '1401f447-c816-4338-b5e3-ea028d9b9871';
    $display->content['new-1401f447-c816-4338-b5e3-ea028d9b9871'] = $pane;
    $display->panels['beta'][0] = 'new-1401f447-c816-4338-b5e3-ea028d9b9871';
    $pane = new stdClass();
    $pane->pid = 'new-2c921fba-066a-4b6a-8633-f6e4afe105e0';
    $pane->panel = 'beta';
    $pane->type = 'views_panes';
    $pane->subtype = 'user_messages-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'more_link' => 1,
      'use_pager' => 0,
      'pager_id' => '0',
      'items_per_page' => '3',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '2c921fba-066a-4b6a-8633-f6e4afe105e0';
    $display->content['new-2c921fba-066a-4b6a-8633-f6e4afe105e0'] = $pane;
    $display->panels['beta'][1] = 'new-2c921fba-066a-4b6a-8633-f6e4afe105e0';
    $pane = new stdClass();
    $pane->pid = 'new-b335a174-be8c-49c2-ba2a-4b398ff491c3';
    $pane->panel = 'beta';
    $pane->type = 'views_panes';
    $pane->subtype = 'user_messages-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'more_link' => 1,
      'use_pager' => 0,
      'pager_id' => '0',
      'items_per_page' => '3',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'b335a174-be8c-49c2-ba2a-4b398ff491c3';
    $display->content['new-b335a174-be8c-49c2-ba2a-4b398ff491c3'] = $pane;
    $display->panels['beta'][2] = 'new-b335a174-be8c-49c2-ba2a-4b398ff491c3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['messages'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'user_notifications';
  $page->task = 'page';
  $page->admin_title = 'User notifications';
  $page->admin_description = '';
  $page->path = 'user/%uid/notifications';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Notifications',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => 'Messages',
      'name' => 'user-menu',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'uid' => array(
      'id' => 1,
      'identifier' => 'User: ID',
      'name' => 'entity_id:user',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_user_notifications_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'user_notifications';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Notifications',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(),
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
  $display->title = t('Subscriptions');
  $display->uuid = 'd2434553-0d76-4954-bbd4-c8888cfb265f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b383e803-eb8c-4e36-a89e-a2e0cd777bbb';
    $pane->panel = 'alpha';
    $pane->type = 'page_tabs';
    $pane->subtype = 'page_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'type' => 'both',
      'id' => 'tabs',
      'override_title' => 1,
      'override_title_text' => 'My account',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b383e803-eb8c-4e36-a89e-a2e0cd777bbb';
    $display->content['new-b383e803-eb8c-4e36-a89e-a2e0cd777bbb'] = $pane;
    $display->panels['alpha'][0] = 'new-b383e803-eb8c-4e36-a89e-a2e0cd777bbb';
    $pane = new stdClass();
    $pane->pid = 'new-b9cb4a96-dea4-4c61-aa6f-6976f8736b54';
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
    $pane->uuid = 'b9cb4a96-dea4-4c61-aa6f-6976f8736b54';
    $display->content['new-b9cb4a96-dea4-4c61-aa6f-6976f8736b54'] = $pane;
    $display->panels['alpha'][1] = 'new-b9cb4a96-dea4-4c61-aa6f-6976f8736b54';
    $pane = new stdClass();
    $pane->pid = 'new-cfacbf95-ee75-4774-b13b-cb810741c397';
    $pane->panel = 'beta';
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
    $pane->uuid = 'cfacbf95-ee75-4774-b13b-cb810741c397';
    $display->content['new-cfacbf95-ee75-4774-b13b-cb810741c397'] = $pane;
    $display->panels['beta'][0] = 'new-cfacbf95-ee75-4774-b13b-cb810741c397';
    $pane = new stdClass();
    $pane->pid = 'new-4e3a42bd-0a95-4e34-b24c-5022026f8c81';
    $pane->panel = 'beta';
    $pane->type = 'views_panes';
    $pane->subtype = 'loop_user_subscriptions-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '4e3a42bd-0a95-4e34-b24c-5022026f8c81';
    $display->content['new-4e3a42bd-0a95-4e34-b24c-5022026f8c81'] = $pane;
    $display->panels['beta'][1] = 'new-4e3a42bd-0a95-4e34-b24c-5022026f8c81';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['user_notifications'] = $page;

  return $pages;

}
