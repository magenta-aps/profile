<?php
/**
 * @file
 * Preprocess and Process Functions.
 */

/**
 * Override or insert variables into the page template.
 */
function loop_preprocess_page(&$variables) {
  global $user;
  $arg = arg();
  if ($user->uid > 0) {
    // Prepare system search block for page.tpl.
    if (module_exists('search_api_page')) {
      $variables['search'] = module_invoke('search_api_page', 'block_view', 'default');
    }
    else {
      $variables['search'] = module_invoke('search', 'block_view', 'form');
    }
  }

  // Drupal core got a minor bug with active trail on 'My account'.
  if ($arg[0] == 'user' && isset($arg[1]) && is_numeric($arg[1])) {
    if (!isset($arg[2])) {
      menu_set_active_item('user');
    }
    else {
      if ($arg[2] != 'messages') {
        menu_set_active_item('user');
      }
    }
  }

  if ($variables['is_front']) {
    $update_script_path = $GLOBALS['base_root'] . '/' . path_to_theme() . '/scripts/frontpage-column-width.js';
    drupal_add_js($update_script_path, 'file');
  }

  // Remove search form when no search results are found.
  if ((isset($variables['page']['content']['system_main']['results'])) &&  ($variables['page']['content']['system_main']['results']['#results']['result count'] == 0)) {
    unset($variables['page']['content']['system_main']['form']);
  }

  // Fetch a user block (my content) on user pages).
  if ($arg[0] == 'user') {
    $variables['loop_user_my_content'] = module_invoke('loop_user', 'block_view', 'loop_user_my_content');
    if (module_exists('pcp')) {
      $variables['user_completion_block'] = module_invoke('pcp', 'block_view', 'pcp_profile_percent_complete');
    }
    hide($variables['tabs']['#secondary']);
  }

  if ($arg[0] == 'front') {
    $variables['loop_frontpage_welcometext'] = module_invoke('loop_frontpage', 'block_view', 'loop_frontpage_welcometext');
  }

  // Load Loop primary menu.
  if (module_exists('loop_navigation') && ($user->uid > 0)) {
    $variables['main_menu_block'] = module_invoke('system', 'block_view', 'main-menu');
    $variables['management_menu_block'] = module_invoke('system', 'block_view', 'management');
    $variables['primary_menu_block'] = module_invoke('menu', 'block_view', 'menu-loop-primary-menu');
  }

  // Load Loop user menu.
  if (module_exists('loop_user') && $arg[0] == 'user') {
    $variables['user_menu_block'] = module_invoke('system', 'block_view', 'user-menu');
    $variables['user_public_block'] = module_invoke('loop_user', 'block_view', 'loop_user_my_content');
  }

  // Check if we are using a panel page to define layout.
  $panel = panels_get_current_page_display();
  if (empty($panel)) {
    $variables['no_panel'] = TRUE;
    if ($arg['0'] == 'search') {
      $variables['layout_class'] = 'layout-full-width';
    }
    else {
      $variables['layout_class'] = 'layout-default-inverted';
    }
  }

  // We add logout link here to be able to always print it last. (Hence not part
  // of any menu).
  if ($user->uid > 0 && !(array_key_exists('hide_logout', $variables) && $variables['hide_logout'])) {
    $variables['logout_link'] = l(t('Logout'), 'user/logout', array('attributes' => array('class' => array('nav--logout'))));
  }

  // Set title for page types. For some reason it does not work through page
  // title module.
  if (!empty($variables['node'])) {
    if ($variables['node']->type == 'page') {
      // Set page title.
      drupal_set_title($variables['node']->title);
    }
  }

  if (!theme_get_setting('show_breadcrumbs', 'loop')) {
    drupal_set_breadcrumb(array());
  }
}

/**
 * Implements hook_preprocess_node().
 *
 * Override or insert variables into the node template.
 */
function loop_preprocess_node(&$variables) {
  // Fetch node author.
  $author = user_load($variables['node']->uid);

  // Fetch user metadata.
  $variables['author_name'] = _loop_fetch_full_name($author);

  if (is_object($author)) {

    // Load entity wrapper.
    $wrapper = entity_metadata_wrapper('user', $author);

    // Fetch data.
    $variables['job_title'] = $wrapper->field_job_title->value();
    $variables['place'] = $wrapper->field_location_place->value();
  }

  $variables['author_image'] = _loop_fetch_author_image($author);

  // Add has comments class.
  if ($variables['comment_count'] > 0) {
    $variables['has_comments_class'] = 'has-comments';
  }
  else {
    $variables['has_comments_class'] = '';
  }

  // Fetch files related to post.
  if ($variables['type'] == 'post') {
    if (!empty($variables['field_file_upload'])) {
      $variables['files'] = _loop_fetch_files('node', $variables['node']);
    }
  }

  // Cleanup links.
  if (isset($variables['content']['links']['statistics'])) {
    $variables['content']['links']['statistics']['#access'] = FALSE;
  }

  if (isset($variables['content']['links']['comment'])) {
    $variables['content']['links']['comment']['#access'] = FALSE;
  }

  // Change default links display.
  $variables['content']['links']['abuse']['#attributes']['class'] = 'question--links';
  unset($variables['content']['links']['abuse']['#links']['abuse_node_history']);
}

/**
 * Implements hook_preprocess_block().
 *
 * Override or insert variables into the block template.
 */
function loop_preprocess_block(&$variables) {
  // Skip login formular.
  if ((isset($variables['elements']['#form_id'])) && ($variables['elements']['#form_id'] == 'user_login')) {
    return;
  }

  // Are we dealing with the access denied or page not found block?
  if ($variables['user']->uid == 0 && !in_array(arg(0), array('user', 'loop_saml_redirect')) && $variables['is_front'] == FALSE) {
    if ($variables['block']->module == 'system' && $variables['block']->delta == 'main') {
      $variables['content'] = '<div class="messages error">' . $variables['content'] . '</div>';
    }
  }
}

/**
 * Implements hook_preprocess_panels_pane().
 *
 * Override or insert variables into the node template.
 *
 * Override or insert variables into the panel pane template.
 */
function loop_preprocess_panels_pane(&$variables) {
  if (arg(0) == 'editor') {
    $variables['theme_hook_suggestions'][] = 'panels_pane__editor';
  }

  // Add template for "notify friend" box.
  if ($variables['pane']->type == 'loop_friend_notification_pane') {
    $variables['theme_hook_suggestions'][] = 'panels_pane__loop_friend_notification';
  }

  // Add template for flag subscribe button on post node.
  if ($variables['pane']->type == 'flag_link') {
    $variables['theme_hook_suggestions'][] = 'panels_pane__flag_subscribe';
  }

  // Add message variable for panel pane.
  if ($variables['pane']->subtype == 'user_messages-panel_pane_1' || $variables['pane']->subtype == 'user_messages-panel_pane_5') {
    global $base_root;

    $variables['message_count'] = _loop_fetch_user_new_notifications();
    $update_script_path = $base_root . '/' . path_to_theme() . '/scripts/update-new-notifications.js';
    drupal_add_js($update_script_path, 'file');
    if (arg(0) == 'user') {
      $variables['theme_hook_suggestions'][] = 'panels_pane__user_page_unread_messages';
    }
  }

  $variables['title_attributes_array']['class'][] = 'block-module--title';
}

/**
 * Implements hook_search_api_page_results().
 */
function loop_preprocess_search_api_page_results(&$variables) {
  if ($variables['result_count'] == 0) {
    global $user;

    if (!in_array('read only', $user->roles)) {
      // No hits. Send formular to template.
      module_load_include('inc', 'node', 'node.pages');
      $node = new stdClass();
      $node->type = 'post';
      $node->langauge = LANGUAGE_NONE;
      $node->uid = $user->uid;
      $node->name = $user->name;

      // Add the post.
      $node->field_description['und'][0]['value'] = arg(1);
      $form = drupal_get_form('node_form', $node);
      $variables['node_form'] = $form;
    }
  }
}

/**
 * Implements theme_menu_local_task().
 */
function loop_menu_local_task($variables) {
  $secondary = '';
  $link = $variables['element']['#link'];
  $list_class = 'block-module--user-links-item';

  // Tabs on login pages.
  if ($GLOBALS['user']->uid == 0 || (arg(0) == 'notifications' && arg(1) == 'subscription')) {
    $list_class = 'tabs-anonymous';
  }

  // User account tabs (Left menu).
  if ($link['page_callback'] == 'page_manager_user_view_page') {
    $link['title'] = t('My account');
  }

  if ($link['page_callback'] == 'messaging_simple_user_page') {
    $link['title'] = t('Notifications');
  }

  if ($link['path'] == 'user/%/notifications') {
    $link['title'] = t('Subscriptions');
  }

  if ($link['path'] == 'user/%/messages') {
    // Add the secondary menu.
    $secondary = menu_secondary_local_tasks();
  }

  // Don't print shortcuts and statistics.
  if ($link['page_callback'] == 'statistics_user_tracker' || $link['path'] == 'user/%/shortcuts' || $link['path'] == 'user/%/message-subscribe') {
    return FALSE;
  }

  if (!empty($variables['element']['#active'])) {
    $list_class .= ' active';
  }

  $sub_menu = '';
  if ($secondary) {
    $sub_menu = '<ul class="block-module-user-links-list-sub">' . drupal_render($secondary) . '</ul>';
  }

  $link_text = $link['title'];

  if (!empty($variables['element']['#active'])) {
    // Add text to indicate active tab for non-visual users.
    $active = '<span class="element-invisible">' . t('(active tab)') . '</span>';

    // If the link does not contain HTML already, check_plain() it now.
    // After we set 'html'=TRUE the link will not be sanitized by l().
    if (empty($link['localized_options']['html'])) {
      $link['title'] = check_plain($link['title']);
    }
    $link['localized_options']['html'] = TRUE;
    $link_text = t('!local-task-title!active', array('!local-task-title' => $link['title'], '!active' => $active));
  }

  return '<li class="' . $list_class . '">' . l($link_text, $link['href'], $link['localized_options']) . "</li>\n" . $sub_menu;
}

/**
 * Implements theme_menu_local_tasks().
 */
function loop_menu_local_tasks($variables) {
  $output = '';
  // Tabs for login pages.
  if ($GLOBALS['user']->uid > 0 && arg(0) == 'user') {
    if (!empty($variables['primary'])) {
      $variables['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
      $variables['primary']['#prefix'] .= '<ul class="block-module--user-links-list">';
      $output .= drupal_render($variables['primary']);
    }
  }
  return $output;
}

/**
 * Implements theme_menu_tree__main_menu().
 *
 * System generated menu links from different modules. Menu not to be changed
 * by users. Forms the header menu together with primary menu.
 */
function loop_menu_tree__main_menu($variables) {
  $theme_path = drupal_get_path('theme', 'loop');

  // Add notification link.
  if (_loop_print_notification_tab()) {
    $variables['tree'] = _loop_print_notification_tab() . $variables['tree'];
  }

  // Add front page link from code
  // due to the notification tab being added to start of menu.
  global $base_root;
  $variables['tree'] = l(t('Frontpage'), $base_root, array(
      'attributes' => array(
        'class' => array(
          'nav--frontpage-link',
        ),
      ),
      'html' => 'TRUE',
    )) . $variables['tree'];

  // If loop navigation exists add a mobile drop down navigation.
  if (module_exists('loop_navigation')) {
    $element['#localized_options']['attributes']['class'][] = 'last leaf nav--toggle-mobile-nav js-toggle-mobile-nav nolink';

    // Allow images in the links.
    $element['#localized_options']['html'][] = TRUE;

    // Allow no path (path = #)
    $element['#localized_options']['external'][] = TRUE;

    $img = array(
      'path' => '/' . $theme_path . '/images/nav-menu-icon.png',
      'attributes' => array('class' => 'nav--icon'),
    );
    // Create the title with image icon.
    $element['#title'] = theme_image($img) . '<span class="nav--text">Menu</span>';

    $variables['tree'] = $variables['tree'] . l($element['#title'], '#', $element['#localized_options']);
  }

  // If the menu contains <li> tag add a ul tag.
  return $variables['tree'];
}

/**
 * Implements theme_menu_tree__menu_loop_primary_menu().
 *
 * User generated link.
 * Forms the header menu together with main menu.
 */
function loop_menu_tree__menu_loop_primary_menu($variables) {
  return $variables['tree'];
}

/**
 * Implements theme_menu_tree__menu_loop_primary_menu().
 *
 * User generated link.
 * Forms the header menu together with main menu.
 */
function loop_menu_tree__management($variables) {
  return $variables['tree'];
}

/**
 * Implements theme_menu_link().
 */
function loop_menu_link__main_menu($variables) {
  $theme_path = drupal_get_path('theme', 'loop');
  $element = $variables['element'];

  // Add images to links depending on the path of the link.
  switch ($element['#href']) {
    case 'user':
      $img = array(
        'path' => '/' . $theme_path . '/images/nav-user-icon.png',
        'attributes' => array('class' => 'nav--icon'),
      );
      // Create the title with image icon.
      $element['#title'] = theme_image($img) . '<span class="nav--text">' . $element['#title'] . '</span>';
      break;

    case 'node/add/post':
      $img = array(
        'path' => '/' . $theme_path . '/images/nav-add-icon.png',
        'attributes' => array('class' => 'nav--icon'),
      );
      // Create the title with image icon.
      $element['#title'] = theme_image($img) . '<span class="nav--text">' . $element['#title'] . '</span>';
      break;
  }

  $element['#localized_options']['attributes']['class'][] = 'nav--link';

  // Allow images in the links.
  $element['#localized_options']['html'][] = TRUE;

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);

  return $output . "\n";
}

/**
 * Implements theme_menu_link().
 */
function loop_menu_link__menu_loop_primary_menu($variables) {
  $theme_path = drupal_get_path('theme', 'loop');
  $element = $variables['element'];

  // Sub item exist (Element is parent).
  if (!empty($variables['element']['#below'])) {
    $img_white = array(
      'path' => '/' . $theme_path . '/images/nav-arrow-down-icon-white.png',
      'attributes' => array('class' => 'nav-dropdown--icon-white'),
    );
    $img_green = array(
      'path' => '/' . $theme_path . '/images/nav-arrow-down-icon.png',
      'attributes' => array('class' => 'nav-dropdown--icon-green'),
    );
    // Create the title with image icon.
    $element['#title'] = theme_image($img_white) . theme_image($img_green) . '<span class="nav--text">' . $element['#title'] . '</span>';

    // Wrap the sub menu.
    $sub_menu = '<div class="nav-dropdown--item">' . drupal_render($element['#below']) . '</div>';

    $element['#localized_options']['attributes']['class'][] = 'nav-dropdown--header';

    // Allow images in the links.
    $element['#localized_options']['html'][] = TRUE;

    $output = '<div class="nav-dropdown--wrapper">' . l($element['#title'], $element['#href'], $element['#localized_options']) . $sub_menu . '</div>';
  }

  // Element has parent.
  elseif ($element['#original_link']['plid'] > 0) {
    $element['#localized_options']['attributes']['class'][] = 'nav-dropdown--link';
    $output = l($element['#title'], $element['#href'], $element['#localized_options']);
    return $output;
  }

  // Default main menu link, not parent and not child.
  else {
    $element['#localized_options']['attributes']['class'][] = 'nav--link';
    $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  }

  return $output . "\n";
}

/**
 * Implements theme_menu_link().
 */
function loop_menu_link__management($variables) {
  $theme_path = drupal_get_path('theme', 'loop');
  $element = $variables['element'];

  if ($element['#href'] == 'admin') {
    $img_white = array(
      'path' => '/' . $theme_path . '/images/nav-arrow-down-icon-white.png',
      'attributes' => array('class' => 'nav-dropdown--icon-white'),
    );
    $img_green = array(
      'path' => '/' . $theme_path . '/images/nav-arrow-down-icon.png',
      'attributes' => array('class' => 'nav-dropdown--icon-green'),
    );
    // Create the title with image icon.
    $element['#title'] = theme_image($img_white) . theme_image($img_green) . '<span class="nav--text">' . $element['#title'] . '</span>';

    // Wrap the sub menu.
    $sub_menu = '<div class="nav-dropdown--item">' . drupal_render($element['#below']) . '</div>';

    $element['#localized_options']['attributes']['class'][] = 'nav-dropdown--header';

    // Allow images in the links.
    $element['#localized_options']['html'][] = TRUE;

    $output = '<div class="nav-dropdown--wrapper">' . l($element['#title'], $element['#href'], $element['#localized_options']) . $sub_menu . '</div>';
  }
  else {
    $element['#localized_options']['attributes']['class'][] = 'nav-dropdown--link';
    $output = l(t($element['#title']), $element['#href'], $element['#localized_options']);
  }

  return $output . "\n";
}

/**
 * Returns HTML for a field set form element and its children.
 *
 * Changes the class added to field sets, so it differs from the wrapper added
 * inside.
 */
function loop_fieldset($variables) {
  $element = $variables['element'];
  element_set_attributes($element, array('id'));
  _form_set_class($element, array('field-group-fieldset'));

  $output = '<fieldset' . drupal_attributes($element['#attributes']) . '>';
  if (!empty($element['#title'])) {
    // Always wrap field set legends in a SPAN for CSS positioning.
    $output .= '<legend><span class="fieldset-legend">' . $element['#title'] . '</span></legend>';
  }

  $output .= '<div class="fieldset-wrapper">';
  if (!empty($element['#description'])) {
    $output .= '<div class="fieldset-description">' . $element['#description'] . '</div>';
  }

  $output .= $element['#children'];
  if (isset($element['#value'])) {
    $output .= $element['#value'];
  }

  $output .= '</div>';
  $output .= "</fieldset>\n";

  return $output;
}

/**
 * Implements template_preprocess_user_profile().
 */
function loop_preprocess_user_profile(&$variables) {
  $account = $variables['elements']['#account'];

  $variables['full_name'] = _loop_fetch_full_name($account);
  $variables['loop_user_best_answers'] = module_invoke('loop_user', 'block_view', 'loop_user_best_answers');

  // Helpful $user_profile variable for templates.
  foreach (element_children($variables['elements']) as $key) {
    $variables['user_profile'][$key] = $variables['elements'][$key];
  }

  // Preprocess fields.
  field_attach_preprocess('user', $account, $variables['elements'], $variables);
}

/**
 * Implements theme_panels_default_style_render_region().
 *
 * Remove the panel separator from the default rendering method.
 */
function loop_panels_default_style_render_region($vars) {
  $output = '';
  $output .= implode('', $vars['panes']);
  return $output;
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Change html of user login.
 */
function loop_form_user_login_alter(&$form) {
  $form['#prefix'] = '<h2>' . t('User login') . '</h2>';
  $form['pass']['#suffix'] = '<ul class="user-form--password-link"><li><a href="/user/password">' . t('Request new password') . '</a></li></ul>';
  $form['name']['#description'] = FALSE;
  $form['name']['#title'] = t('Username or e-mail');
  $form['pass']['#description'] = FALSE;
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function loop_form_views_form_loop_user_subscriptions_panel_pane_1_alter(&$form, &$form_state, $form_id) {
  // Add form class.
  $form['#attributes']['class'][] = 'vbo-views-form';

  // Copy button from field group.
  if (!empty($form['select'])) {
    $form['rules_component::rules_remove_subscription'] = $form['select']['rules_component::rules_remove_subscription'];
  }

  // Add wrappers.
  $form['rules_component::rules_remove_subscription']['#prefix'] = '<div class="js-user-profile-notification-actions user-profile--notification-actions"><div class="user-profile--notification-actions-inner">';
  $form['rules_component::rules_remove_subscription']['#suffix'] = '</div></div>';

  // Add warning class to button.
  $form['rules_component::rules_remove_subscription']['#attributes']['class'][] = 'user-profile--notification-actions--button-remove button--warning';

  // Add js class to checkboxes.
  if (!empty($form['views_bulk_operations'])) {
    foreach ($form['views_bulk_operations'] as $key => $value) {
      if (is_array($value)) {
        $form['views_bulk_operations'][$key]['#attributes']['class'][] = 'js-user-profile-notification-select';
      }
    }
  }

  // Remove stuff from form.
  unset($form['#prefix']);
  unset($form['#suffix']);
  unset($form['select_all_markup']);

  // Remove field group containing actions.
  unset($form['select']);

  // Add custom js.
  $display_notification_script_path = $GLOBALS['base_root'] . '/' . path_to_theme() . '/scripts/display-notification-actions.js';
  drupal_add_js($display_notification_script_path, 'file');

  // If on confirmation step.
  if ($form_state['step'] == 'views_bulk_operations_confirm_form') {
    $form['actions']['submit']['#attributes']['class'][] = 'user-profile--notification-actions--button--confirm button--warning';
    $form['actions']['cancel']['#attributes']['class'][] = 'user-profile--notification-actions--button button--action';
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function loop_form_views_form_loop_user_taxonomy_subscriptions_panel_pane_1_alter(&$form, &$form_state, $form_id) {
  // Add form class.
  $form['#attributes']['class'][] = 'vbo-views-form';

  // Copy button from field group.
  if (!empty($form['select'])) {
    $buttonKey = 'rules_component::loop_notification_remove_taxonomy_subscription';
    if (array_key_exists($buttonKey, $form['select'])) {
      $form['rules_component::rules_remove_subscription'] = $form['select'][$buttonKey];
    } else {
      // Fall back to hardcoded definition because Drupal
      $form['rules_component::rules_remove_subscription'] = array(
          '#type' => 'submit',
          '#value' => t('Remove subscription'),
          '#validate' => array('views_bulk_operations_form_validate'),
          '#submit' => array('views_bulk_operations_form_submit'),
          '#operation_id' => 'rules_component::loop_notification_remove_taxonomy_subscription'
      );
    }
  }

  // Add wrappers.
  $form['rules_component::rules_remove_subscription']['#prefix'] = '<div class="js-user-profile-notification-actions user-profile--notification-actions"><div class="user-profile--notification-actions-inner">';
  $form['rules_component::rules_remove_subscription']['#suffix'] = '</div></div>';

  // Add warning class to button.
  $form['rules_component::rules_remove_subscription']['#attributes']['class'][] = 'user-profile--notification-actions--button-remove button--warning';

  // Add js class to checkboxes.
  if (!empty($form['views_bulk_operations'])) {
    foreach ($form['views_bulk_operations'] as $key => $value) {
      if (is_array($value)) {
        $form['views_bulk_operations'][$key]['#attributes']['class'][] = 'js-user-profile-notification-select';
      }
    }
  }

  // Remove stuff from form.
  unset($form['#prefix']);
  unset($form['#suffix']);
  unset($form['select_all_markup']);

  // Remove field group containing actions.
  unset($form['select']);

  // Add custom js.
  $display_notification_script_path = $GLOBALS['base_root'] . '/' . path_to_theme() . '/scripts/display-notification-actions.js';
  drupal_add_js($display_notification_script_path, 'file');

  // If on confirmation step.
  if ($form_state['step'] == 'views_bulk_operations_confirm_form') {
    $form['actions']['submit']['#attributes']['class'][] = 'user-profile--notification-actions--button--confirm button--warning';
    $form['actions']['cancel']['#attributes']['class'][] = 'user-profile--notification-actions--button button--action';
  }
}

/**
 * Implements hook_FROM_ID_form_alter().
 */
function loop_form_user_register_form_alter(&$form) {
  // Add js chosen class to profession field.
  $field_profession_lang = $form['field_profession']['#language'];
  $form['field_profession'][$field_profession_lang]['#attributes']['class'][] = 'js-chosen-select-profession';
}

/**
 * Implements hook_form_FORM_alter().
 */
function loop_form_views_exposed_form_alter(&$form) {
  if (arg(1) == 'dashboard') {
    if ($form['#id'] == 'views-exposed-form-loop-editor-users-panel-pane-1') {
      $form['combine']['#attributes']['placeholder'] = t('Type name, username, email or profession to filter the list');
    }
    else {
      $form['combine']['#attributes']['placeholder'] = t('Type text that is part of title or content to filter the list');
    }

    $form['#attributes']['class'][] = 'dashboard-list--form';
    $form['combine']['#attributes']['class'][] = 'dashboard-list--filter-field';
    $form['submit']['#attributes']['class'][] = 'dashboard-list--submit';
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Adds custom class names and placeholder attribute and icon prefix to search
 * field.
 */
function loop_form_search_api_page_search_form_default_alter(&$form) {
  // Change title text and make sure the label is displayed.
  $form['keys_1']['#title_display'] = 'before';
  $form['keys_1']['#title'] = t('Search for an answer');
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function loop_form_comment_form_alter(&$form) {
  $variables['user_obj'] = user_load($GLOBALS['user']->uid);
  if (!empty($variables['user_obj'])) {
    $variables['user_name'] = _loop_fetch_full_name($variables['user_obj']);

    // Load entity wrapper.
    $wrapper = entity_metadata_wrapper('user', $variables['user_obj']);

    // Get job title.
    $variables['jobtitle'] = $wrapper->field_job_title->value();
    $variables['place'] = $wrapper->field_location_place->value();
    $variables['author_image'] = _loop_fetch_author_image($variables['user_obj']);
  }

  $form['#prefix'] = theme('comment_form_prefix', $variables);
  $form['#prefix'] .= '<div class="form-module">';
  // Let modules set a global variable to influence the use of wysiwyg comments, but default to FALSE.
  $form['comment_body'][LANGUAGE_NONE][0]['#wysiwyg'] = array_key_exists('use_wysiwyg_comments', $GLOBALS) ? $GLOBALS['use_wysiwyg_comments'] : FALSE;
  $form['#suffix'] = '</div>';

  hide($form['author']);
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * The user profile form.
 */
function loop_form_user_profile_form_alter(&$form) {
  $form['account']['status']['#access'] = FALSE;
  $form['account']['#prefix'] = '<fieldset class="field-group-fieldset">';
  $form['account']['#suffix'] = '</fieldset>';
  $form['redirect']['#access'] = FALSE;
  $form['metatags']['#access'] = FALSE;
  $form['timezone']['#access'] = FALSE;
  $form['#attributes']['class'] = 'user-profile-form';

  $field_expertise_lang = $form['field_area_of_expertise']['#language'];
  $form['field_area_of_expertise'][$field_expertise_lang]['#attributes']['class'][] = 'js-chosen-select-area-of-expertise';

  // Image field.
  $user_image_field_lang = $form['field_user_image']['#language'];
  unset($form['field_user_image'][$user_image_field_lang]['0']['#description']);
  unset($form['field_user_image'][$user_image_field_lang]['0']['#title']);

  $form['locale']['#access'] = FALSE;

  // Add js chosen class to profession field.
  $field_profession_lang = $form['field_profession']['#language'];
  $form['field_profession'][$field_profession_lang]['#attributes']['class'][] = 'js-chosen-select-profession';

  // Set page title.
  drupal_set_title(t("Edit user"));
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * For display on user/[uid]/notifications/subscription.
 */
function loop_form_notifications_account_manage_subscriptions_form_alter(&$form) {
  // Hide filtering.
  $form['filters']['#access'] = FALSE;

  // Remove unneeded info about the users subscriptions and clean up the table.
  unset($form['admin']['options']['#prefix']);
  unset($form['admin']['options']['#suffix']);
  unset($form['admin']['subscriptions']['#header']['sid']);
  unset($form['admin']['subscriptions']['#header']['type']);
  unset($form['admin']['subscriptions']['#header']['status']);
  unset($form['admin']['subscriptions']['#header']['created']);
  unset($form['admin']['subscriptions']['#header']['send_method']);
  unset($form['admin']['subscriptions']['#header']['send_interval']);

  // Add a class to the form.
  $form['admin']['subscriptions']['#attributes']['class'][] = 'notification--user-subscriptions';
}

/**
 * Implements hook_theme().
 */
function loop_theme($existing, $type, $theme, $path) {
  return array(
    'comment_form_prefix' => array(
      'variables' => array(),
      'path' => drupal_get_path('theme', 'loop') . '/templates/forms',
      'template' => 'comment-form-prefix',
    ),
  );
}

/**
 * Implements hook_preprocess_comment().
 *
 * Load user for every comment.
 */
function loop_preprocess_comment(&$variables) {
  // Make the content author object available.
  $variables['comment']->account = user_load($variables['comment']->uid);

  $variables['comment_author_name'] = _loop_fetch_full_name($variables['comment']->account);
  $variables['comment_author_image'] = _loop_fetch_author_image($variables['comment']->account);

  $variables['comment_body'] = _loop_fetch_comment_body($variables['comment']);

  $comment_author = $variables['comment']->account;
  if (is_object($comment_author)) {

    // Load entity wrapper for author.
    $wrapper = entity_metadata_wrapper('user', $comment_author);

    // Fetch the fields needed.
    $variables['place'] = $wrapper->field_location_place->value();
    $fetched_job_title = field_get_items('user', $variables['comment']->account, 'field_job_title');
    $variables['job_title'] = field_view_value('user', $variables['comment']->account, 'field_job_title', $fetched_job_title[0], array());
  }

  // Fetch files related to the comment.
  if ($variables['node']->type == 'post') {
    if (!empty($variables['field_file_upload_comment'])) {
      $variables['files'] = _loop_fetch_files('comment', $variables['comment']);
    }
  }

  $variables['content']['links']['abuse']['#attributes']['class'] = 'comment--links';

  // Remove flag, delete, edit and reply links.
  unset($variables['content']['links']['comment']['#links']['comment-delete']);
  unset($variables['content']['links']['comment']['#links']['comment-edit']);
  unset($variables['content']['links']['flag']);
  unset($variables['content']['links']['comment']['#links']['comment-reply']);
}

/**
 * Implements hook_preprocess_loop_post_subscription_list().
 *
 * Preprocesss function for displaying subscribe/un-subscribe on nodes.
 */
function loop_preprocess_loop_post_subscription_list(&$vars) {
  $vars['custom_link'] = l($vars['link']['#text'], $vars['link']['#path'], array('attributes' => array('class' => array('block-module--link')), 'html' => 'TRUE', 'query' => array($vars['link']['#query'])));

  if ($vars['link']['#text'] == 'Subscribe') {
    $vars['current_type_css'] = 'block-follow-question';
  }
  else {
    $vars['current_type_css'] = 'block-unfollow-question';
  }
}

/**
 * Implements hook_textarea().
 *
 * Remove grippie from textarea.
 */
function loop_textarea($variables) {
  $element = $variables['element'];
  $element['#attributes']['name'] = $element['#name'];
  $element['#attributes']['id'] = $element['#id'];
  $element['#attributes']['cols'] = $element['#cols'];
  $element['#attributes']['rows'] = $element['#rows'];

  _form_set_class($element, array('form-textarea'));

  $wrapper_attributes = array(
    'class' => array('form-textarea-wrapper'),
  );

  $output = '<div' . drupal_attributes($wrapper_attributes) . '>';
  $output .= '<textarea' . drupal_attributes($element['#attributes']) . '>' . check_plain($element['#value']) . '</textarea>';
  $output .= '</div>';
  return $output;
}

/**
 * Implements hook_preprocess_views_view().
 *
 * Add variables to the base view template files (views.view.tpl.php and
 * overrides).
 */
function loop_preprocess_views_view(&$vars) {
  // We run the new message count in this function since the view updates with
  // ajax.
  if ($vars['view']->name == 'user_messages') {
    $new_message_count = _loop_fetch_user_new_notifications();
    $vars['user_messages'] = $new_message_count;

    // Add update notification script.
    $update_script_path = $GLOBALS['base_root'] . '/' . path_to_theme() . '/scripts/update-new-notifications.js';
    drupal_add_js($update_script_path, 'file');
  }

  // If the view is one of the two front page views, add a few user variables.
  if ($vars['view']->name == 'loop_questions_by_user_profession' || $vars['view']->name == 'loop_questions_by_user_competence') {
    if ($vars['user']->uid > 0) {
      // Fetch full user obj.
      $user_obj = user_load($vars['user']->uid);

      // Load entity wrapper.
      $wrapper = entity_metadata_wrapper('user', $user_obj);

      if ($vars['view']->name == 'loop_questions_by_user_profession') {
        $items = $wrapper->field_profession->value();
        $user_professions = array();
        foreach ($items as $item) {
          if (is_object($item)) {
            $user_professions[] = $item->name;

          }
        }
        $vars['user_profession'] = $user_professions;
      }

      if ($vars['view']->name == 'loop_questions_by_user_competence') {
        $items = $wrapper->field_area_of_expertise->value();
        $user_area_of_expertises = array();
        foreach ($items as $item) {
          if (is_object($item)) {
            $user_area_of_expertises[] = $item->name;
          }
        }
        $vars['user_area_of_expertise'] = $user_area_of_expertises;
      }
    }
  }
}

/**
 * Function for printing the notification tab.
 *
 * Since the page already exists we don't use hook menu.
 *
 * @return string
 *   HTML for the notification tab or false if module does not exist or user is
 *   not logged in.
 */
function _loop_print_notification_tab() {
  // We run the new message count in this function called from
  // loop_links__system_primary_menu().
  // since it should display on all pages.
  if (module_exists('loop_notification') && $GLOBALS['user']->uid > 0) {
    $new_message_count = _loop_fetch_user_new_notifications();

    // If new messages exist.
    if ($new_message_count > 0) {
      $new_messages = '<span class="notification js-notification-tab-count">' . $new_message_count . '</span>';
    }
    else {
      $new_messages = '';
    }

    // Add the link image for mobile.
    $img = array(
      'path' => '/' . path_to_theme() . '/images/nav-mail-icon.png',
      'attributes' => array('class' => 'nav--icon'),
    );

    $title = theme_image($img) . '<span class="nav--text">' . t('Notifications') . '</span>' . $new_messages;

    $menutab = l($title, 'user/' . $GLOBALS['user']->uid . '/messages', array('attributes' => array('class' => array('nav--link')), 'html' => 'TRUE'));
  }
  else {
    $menutab = FALSE;
  }
  return $menutab;
}

/**
 * Fetch the full name from a user object.
 *
 * If both first name and last name is set.
 *
 * @param StdClass $user
 *   Drupal user object.
 *
 * @return string
 *   Name based on user fields.
 */
function _loop_fetch_full_name ($user) {
  $name = '';

  // Make sure we are dealing with an object.
  if (is_object($user)) {

    // Load entity wrapper.
    $wrapper = entity_metadata_wrapper('user', $user);

    // Get first name and last name.
    $first_name = $wrapper->field_first_name->value();
    $last_name = $wrapper->field_last_name->value();

    // Set name.
    if ($first_name && $last_name) {
      $name = $first_name . ' ' . $last_name;
    }
    else {
      $name = $user->name;
    }
  }
  return $name;
}

/**
 * Fetches notifications related to current user.
 *
 * @return int
 *   Number of new notifications related to current user.
 */
function _loop_fetch_user_new_notifications() {
  // Fetch all current users messages from the message table.
  $all_message_count = db_query('SELECT uid FROM message WHERE uid = :uid', array(':uid' => $GLOBALS['user']->uid))->rowCount();

  // Fetch flag id (fid) for the message_read flag.
  $flag_id = db_query('SELECT fid FROM flag WHERE name = :machine_name', array(':machine_name' => "message_read"))->fetchField();

  // Fetch all flags of type message_read (fid) that the current user made.
  $flagged_read_message_count = db_query('SELECT entity_id FROM flagging WHERE uid = :uid AND fid = :fid', array(':uid' => $GLOBALS['user']->uid, ':fid' => $flag_id))->rowCount();

  // Subtract the two.
  $new_notifications = $all_message_count - $flagged_read_message_count;

  return $new_notifications;
}

/**
 * Fetches an image based on author.
 *
 * @param StdClass $author
 *   Drupal user object.
 *
 * @return string
 *   Themed image based on author.
 */
function _loop_fetch_author_image($author) {
  $author_image = '';

  if (is_object($author)) {
    // Load entity wrapper.
    $wrapper = entity_metadata_wrapper('user', $author);

    // Get first name and last name.
    $author_image_field = $wrapper->field_user_image->value();
    $author_image = theme('image_style', array('style_name' => 'preview', 'path' => $author_image_field['uri']));
    if (empty($author_image_field)) {
      $image_path = 'default-user-icon.png';
      $author_image = theme('image_style', array('style_name' => 'preview', 'path' => $image_path));
    }
  }

  return $author_image;
}

/**
 * Fetches body of comment.
 *
 * @param StdClass $comment
 *   Comment object.
 *
 * @return string
 *   Comment safe value.
 */
function _loop_fetch_comment_body($comment) {
  // Load entity wrapper.
  $wrapper = entity_metadata_wrapper('comment', $comment);
  $comment = $wrapper->comment_body->value();

  return $comment['safe_value'];
}

/**
 * Fetches files related to node or comment.
 *
 * @param string $type
 *   The entity type.
 * @param StdClass $entity
 *   Entity object.
 *
 * @return mixed
 *   files - The files related to the entity.
 */
function _loop_fetch_files($type, $entity) {
  $files = FALSE;

  $wrapper = entity_metadata_wrapper($type, $entity);
  if ($type == 'comment') {
    // Fetch files.
    $files = $wrapper->field_file_upload_comment->value();
  }
  elseif ($type == 'node') {
    // Fetch files.
    $files = $wrapper->field_file_upload->value();
  }

  return $files;
}
