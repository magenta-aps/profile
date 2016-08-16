<?php
/**
 * @file
 * loop_post.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function loop_post_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_2';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Post',
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
              'post' => 'post',
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
      'center' => NULL,
      'alpha' => NULL,
      'beta' => NULL,
      'gamma' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '97a03160-fb40-434c-ad78-7c76b10aa8f9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d994a098-6eb6-4f2a-a682-f61de0f30b2f';
    $pane->panel = 'alpha';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 1,
      'no_extras' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 1,
      'leave_node_title' => 0,
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
    $pane->uuid = 'd994a098-6eb6-4f2a-a682-f61de0f30b2f';
    $display->content['new-d994a098-6eb6-4f2a-a682-f61de0f30b2f'] = $pane;
    $display->panels['alpha'][0] = 'new-d994a098-6eb6-4f2a-a682-f61de0f30b2f';
    $pane = new stdClass();
    $pane->pid = 'new-15c9ebc5-cf53-48a0-b423-7d41c6dc11ec';
    $pane->panel = 'alpha';
    $pane->type = 'views_panes';
    $pane->subtype = 'loop_node_comments-loop_post_comments_most_valid_comment';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '15c9ebc5-cf53-48a0-b423-7d41c6dc11ec';
    $display->content['new-15c9ebc5-cf53-48a0-b423-7d41c6dc11ec'] = $pane;
    $display->panels['alpha'][1] = 'new-15c9ebc5-cf53-48a0-b423-7d41c6dc11ec';
    $pane = new stdClass();
    $pane->pid = 'new-37733e41-2124-4905-aa07-2e8f00185b87';
    $pane->panel = 'alpha';
    $pane->type = 'views_panes';
    $pane->subtype = 'loop_node_comments-loop_post_comments_other_comments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '37733e41-2124-4905-aa07-2e8f00185b87';
    $display->content['new-37733e41-2124-4905-aa07-2e8f00185b87'] = $pane;
    $display->panels['alpha'][2] = 'new-37733e41-2124-4905-aa07-2e8f00185b87';
    $pane = new stdClass();
    $pane->pid = 'new-3b00d83d-17c2-4baa-ac2d-0d2b36b6a7fc';
    $pane->panel = 'beta';
    $pane->type = 'flag_link';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'flag_name' => 'subscribe_node',
      'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = '3b00d83d-17c2-4baa-ac2d-0d2b36b6a7fc';
    $display->content['new-3b00d83d-17c2-4baa-ac2d-0d2b36b6a7fc'] = $pane;
    $display->panels['beta'][0] = 'new-3b00d83d-17c2-4baa-ac2d-0d2b36b6a7fc';
    $pane = new stdClass();
    $pane->pid = 'new-8d69457f-e73e-4036-a817-04b562ff17c1';
    $pane->panel = 'beta';
    $pane->type = 'loop_friend_notification_pane';
    $pane->subtype = 'loop_friend_notification_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => '',
      'override_title' => 1,
      'override_title_text' => 'Del med en ven',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '8d69457f-e73e-4036-a817-04b562ff17c1';
    $display->content['new-8d69457f-e73e-4036-a817-04b562ff17c1'] = $pane;
    $display->panels['beta'][1] = 'new-8d69457f-e73e-4036-a817-04b562ff17c1';
    $pane = new stdClass();
    $pane->pid = 'new-0bb2f825-4693-4ff9-b1f7-bb0546b4ee70';
    $pane->panel = 'gamma';
    $pane->type = 'node_comment_form';
    $pane->subtype = 'node_comment_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'anon_links' => 0,
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0bb2f825-4693-4ff9-b1f7-bb0546b4ee70';
    $display->content['new-0bb2f825-4693-4ff9-b1f7-bb0546b4ee70'] = $pane;
    $display->panels['gamma'][0] = 'new-0bb2f825-4693-4ff9-b1f7-bb0546b4ee70';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-d994a098-6eb6-4f2a-a682-f61de0f30b2f';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_2'] = $handler;

  return $export;
}
