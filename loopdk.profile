<?php
/**
 * @file
 * The installation profile.
 */

/**
 * Implement hook_install_tasks_alter().
 *
 * Redirect language selection to our own function.
 */
function loopdk_install_tasks_alter(&$tasks, $install_state) {
  // Callback for language selection.
  $tasks['install_select_locale']['function'] = 'loopdk_locale_selection';
}

// Set default language to english.
function loopdk_locale_selection(&$install_state) {
  $install_state['parameters']['locale'] = 'en';
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Set site name, country and timezone.
 */
function loopdk_form_install_configure_form_alter(&$form, $form_state) {
  $form['site_information']['site_name']['#default_value'] = 'Loop';
  $form['server_settings']['site_default_country']['#default_value'] = 'DK';
  $form['server_settings']['date_default_timezone']['#default_value'] = 'Europe/Copenhagen';
}

/**
 * Pick settings.
 *
 * Dashboard, user pages and translations.
 */
function loopdk_module_selection_form($form, &$form_state) {
  $form['addons'] = array(
    '#type' => 'fieldset',
    '#title' => t('Add-ons'),
    '#weight' => 1,
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  $form['addons']['user_pages'] = array(
    '#type' => 'checkbox',
    '#title' => t('User pages'),
    '#description' => t('Include user display and user sub pages.'),
    '#default_value' => TRUE,
  );

  $all_modules = system_rebuild_module_data();
  // Additional Loop modules to suggest installing
  //   module name => install (default checkbox value)
  $loop_modules = array(
    'loop_configure_theme' => FALSE,
    'loop_post_wysiwyg' => FALSE,
  );
  foreach ($loop_modules as $module => $install) {
    if (isset($all_modules[$module])) {
      $module_info = $all_modules[$module]->info;
      $form['addons'][$module] = array(
        '#type' => 'checkbox',
        '#title' => $module_info['name'],
        '#description' => $module_info['description'],
        '#default_value' => $install,
      );
    }
  }

  $form['addons']['translation'] = array(
    '#type' => 'checkbox',
    '#title' => t('Danish translation'),
    '#description' => t('Install and enable Danish translation.'),
    '#default_value' => FALSE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => st('Continue installation'),
    '#weight' => 20,
  );

  return $form;
}

/**
 * Formula submit function for Loop settings.
 */
function loopdk_module_selection_form_submit($form, &$form_state) {
  $dependency_modules = array();

  if ($form_state['values']['translation']) {
    variable_set('loopdk_install_translations', TRUE);
  }

  $all_modules = system_rebuild_module_data();
  foreach ($form_state['values'] as $module => $install) {
    if (isset($all_modules[$module]) && $install) {
      $dependency_modules[] = $module;
    }
  }

  if ($form_state['values']['user_pages']) {
    $dependency_modules[] = 'loop_user_page_views';
    $dependency_modules[] = 'loop_user_related_content_profession';
    $dependency_modules[] = 'loop_user_related_content_competence';
  }
  module_enable($dependency_modules);
}

/**
 * Implements hook_install_tasks().
 *
 * Add extra steps.
 * Settings, Filter & WYSIWYG and Final round up.
 */
function loopdk_install_tasks(&$install_state) {

  $ret = array(
    // Module selection form.
    'loopdk_module_selection_form' => array(
      'display_name' => 'Module selection',
      'display' => TRUE,
      'type' => 'form',
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    ),
    // Update translations.
    'loopdk_import_translation' => array(
      'display_name' => 'Update translations',
      'display' => variable_get('loopdk_install_translations', FALSE),
      'type' => 'batch',
      'run' => variable_get('loopdk_install_translations', FALSE) ? INSTALL_TASK_RUN_IF_NOT_COMPLETED : INSTALL_TASK_SKIP,
    ),
    // Update translations.
    'loopdk_import_contrib_translation' => array(
      'display_name' => 'Update contribute translations',
      'display' => variable_get('loopdk_install_translations', FALSE),
      'type' => 'batch',
      'run' => variable_get('loopdk_install_translations', FALSE) ? INSTALL_TASK_RUN_IF_NOT_COMPLETED : INSTALL_TASK_SKIP,
    ),
    // Filter and WYSIWYG settings.
    'loopdk_setup_filter_and_wysiwyg' => array(
      'display_name' => st('Setup filter and WYSIWYG'),
      'display' => TRUE,
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
      'type' => 'batch'
    ),
    // Round up installation.
    'loopdk_final_settings' => array(
      'display_name' => st('Round up installation'),
      'display' => TRUE,
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
      'type' => 'normal',
    )
  );

  return $ret;
}

/**
 * Translation callback.
 *
 * Add danish language and import for every module.

 * @return array
 *   List of batches.
 */
function loopdk_import_translation() {
  // Enable danish language.
  include_once DRUPAL_ROOT . '/includes/locale.inc';
  locale_add_language('da', NULL, NULL, NULL, '', NULL, TRUE, TRUE);

  $operations = array();

  // Import our own translations.
  $operations[] = array(
    '_loopdk_insert_translation',
    array(
      'default',
      '/profiles/loopdk/translations/da.po',
    ),
  );

  // Import field translation group.
  $operations[] = array(
    '_loopdk_insert_translation',
    array(
      'field',
      '/profiles/loopdk/translations/da_fields.po',
    ),
  );

  // Import menu translation group.
  $operations[] = array(
    '_loopdk_insert_translation',
    array(
      'menu',
      '/profiles/loopdk/translations/da_menu.po',
    ),
  );

  // Import panels translation group.
  $operations[] = array(
    '_loopdk_insert_translation',
    array(
      'panels',
      '/profiles/loopdk/translations/da_panels.po',
    ),
  );

  // Import views translation group.
  $operations[] = array(
    '_loopdk_insert_translation',
    array(
      'views',
      '/profiles/loopdk/translations/da_views.po',
    ),
  );

  $batch = array(
    'title' => st('Installing translations'),
    'operations' => $operations,
    'file' => drupal_get_path('profile', 'loopdk') . '/loopdk.callbacks.inc',
  );

  return $batch;
}

/**
 * Install contribute modules translations.
 */
function loopdk_import_contrib_translation() {
  // Build batch with l10n_update module.
  $history = l10n_update_get_history();
  module_load_include('check.inc', 'l10n_update');
  $available = l10n_update_available_releases();
  $updates = l10n_update_build_updates($history, $available);

  // Fire of the batch.
  module_load_include('batch.inc', 'l10n_update');
  $updates = _l10n_update_prepare_updates($updates, NULL, array());
  $batch = l10n_update_batch_multiple($updates, LOCALE_IMPORT_KEEP);

  return $batch;
}

/**
 * Setup text filter and WYSIWYG.
 */
function loopdk_setup_filter_and_wysiwyg() {
  $format = new Stdclass();
  $format->format = 'editor';
  $format->name = 'Editor';
  $format->status = 1;
  $format->weight = 0;
  $format->filters = array(
    'filter_html' => array(
      'weight' => -48,
      'status' => 1,
      'settings' => array(
        'allowed_html' => '<h2> <h3> <h4> <a> <em> <strong> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd> <p> <img> <br> <table> <tbody> <tr> <th> <td>',
        'filter_html_help' => 1,
        'filter_html_nofollow' => 0,
      ),
    ),
    'filter_autop' => array(
      'weight' => -46,
      'status' => 1,
      'settings' => array(),
    ),
    'filter_htmlcorrector' => array(
      'weight' => -45,
      'status' => 1,
      'settings' => array(),
    ),
    'shortener' => array(
      'weight' => -44,
      'status' => 1,
      'settings' => array(
        'shortener_url_behavior' => 'strict',
        'shortener_url_length' => '72'
      )
    )
  );

  filter_format_save($format);

  $settings = array(
    'default' => 1,
    'user_choose' => 0,
    'show_toggle' => 1,
    'theme' => 'advanced',
    'language' => 'en',
    'buttons' => array(
      'default' => array(
        'Bold' => 1,
        'Italic' => 1,
        'Underline' => 1,
        'BulletedList' => 1,
        'NumberedList' => 1,
        'Link' => 1,
        'PasteText' => 1,
        'Styles' => 1,
      ),
    ),
    'toolbar_loc' => 'top',
    'toolbar_align' => 'left',
    'path_loc' => 'bottom',
    'resizing' => 1,
    'verify_html' => 1,
    'preformatted' => 0,
    'convert_fonts_to_spans' => 1,
    'remove_linebreaks' => 1,
    'apply_source_formatting' => 0,
    'paste_auto_cleanup_on_paste' => 0,
    'block_formats' => 'p,address,pre,h2,h3,h4,h5,h6,div',
    'css_setting' => 'theme',
    'css_path' => '',
    'css_classes' => 'Header (h2)=h2.header--big
    Header (h3)=h3.header--medium
    Header (h4)=h4.header--small',
  );

  db_merge('wysiwyg')
    ->key(array('format' => $format->format))
    ->fields(array(
      'editor' => 'ckeditor',
      'settings' => serialize($settings),
    ))
    ->execute();

  $format = new Stdclass();
  $format->format = 'simple';
  $format->name = 'Simple';
  $format->cache = 1;
  $format->status = 1;
  $format->weight = -10;
  $format->filters = array(
    'filter_url' => array(
      'weight' => -48,
      'status' => 1,
      'settings' => array(
        'filter_url_length' => 72,
      ),
    ),
    'filter_html' => array(
      'weight' => 0,
      'status' => 1,
      'settings' => array(
        'allowed_html' => '<br> <p> <a>',
        'filter_html_help' => 0,
        'filter_html_nofollow' => 0,
      ),
    ),
    'filter_autop' => array(
      'weight' => 0,
      'status' => 1,
      'settings' => array(),
    ),
    'shortener' => array(
      'weight' => -45,
      'status' => 1,
      'settings' => array(
        'shortener_url_behavior' => 'strict',
        'shortener_url_length" => "72'
      )
    )
  );

  filter_format_save($format);

  $format = new Stdclass();
  $format->format = 'html';
  $format->name = 'HTML';
  $format->cache = 1;
  $format->status = 1;
  $format->weight = -10;
  $format->filters = array(
    'filter_html' => array(
      'weight' => 0,
      'status' => 1,
      'settings' => array(
        'allowed_html' => '<br> <a>',
        'filter_html_help' => 0,
        'filter_html_nofollow' => 0,
      ),
    ),
  );

  filter_format_save($format);

  // Setup contribute module Shorten to use contribute module ShURLy.
  variable_set('shorten_service', 'ShURLy');
  variable_set('shorten_service_backup', 'none');
  variable_set('shorten_generate_token', 0);
  variable_set('shorten_show_service', 0);
  variable_set('shorten_use_alias', 0);
}

/**
 * Final Loop install profile settings.
 *
 * 1. Revert every feature.
 * 2. Enable Transliterate contribute module setting.
 * 3. Setup default user icon.
 * 4. Refresh strings.
 */
function loopdk_final_settings() {
  module_load_include('inc', 'features', 'features.export');

  $features = array();
  foreach (features_get_features(NULL, TRUE) as $module) {
    switch (features_get_storage($module->name)) {
      case FEATURES_OVERRIDDEN:
      case FEATURES_NEEDS_REVIEW:
      case FEATURES_REBUILDABLE:
        $features[$module->name] = $module->components;
        break;
    }
  }

  features_revert($features);

  // Setup url path to use Transliteration module.
  variable_set('pathauto_transliterate', 1);

  // Setup default user icon.
  if (!$da = file_get_contents(drupal_get_path('theme', 'loop') . '/images/default-user-icon.png')) {
    throw new Exception("Error opening file");
  }

  if (!$file = file_save_data($da, 'public://default-user-icon.png', FILE_EXISTS_RENAME)) {
    throw new Exception("Error saving file");
  }

  $instance = field_info_instance('user', 'field_user_image', 'user');
  $instance['settings']['default_image'] = $file->fid;
  field_update_instance($instance);

  // Refresh strings.
  module_load_include('inc', 'i18n_string', 'i18n_string.admin');
  i18n_string_refresh_group('default');
  i18n_string_refresh_group('field');
  i18n_string_refresh_group('menu');
  i18n_string_refresh_group('panels');
  i18n_string_refresh_group('views');
}
