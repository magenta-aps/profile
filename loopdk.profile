<?php

/**
 * Implement hook_install_tasks_alter().
 *
 */
function loopdk_install_tasks_alter(&$tasks, $install_state) {
  // Callback for languageg selection.
  $tasks['install_select_locale']['function'] = 'loopdk_locale_selection';
}

// Set default language to english.
function loopdk_locale_selection(&$install_state) {
  $install_state['parameters']['locale'] = 'en';
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
if (!function_exists("system_form_install_configure_form_alter")) {
  function system_form_install_configure_form_alter(&$form, $form_state) {
    $form['site_information']['site_name']['#default_value'] = 'LOOP';
    $form['server_settings']['site_default_country']['#default_value'] = 'DK';
    $form['server_settings']['date_default_timezone']['#default_value'] = 'Europe/Copenhagen';
  }
}

/**
 * Implements hook_install_tasks().
 *
 * As this function is called early and often, we have to maintain a cache or
 * else the task specifying a form may not be available on form submit.
 */
function loopdk_install_tasks(&$install_state) {

  $ret = array(
    // Update translations.
/*    'loopdk_import_translation' => array(
      'display_name' => st('Set up translations'),
      'display' => TRUE,
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
      'type' => 'batch',
    ),*/
    'loopdk_setup_filter_and_wysiwyg' => array(
      'display_name' => st('Setup filter and WYSIWYG'),
      'display' => TRUE,
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
      'type' => 'batch'
    ),
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
 *
 * @param $install_state
 *   An array of information about the current installation state.
 *
 * @return array
 *   List of batches.
 */
function loopdk_import_translation() {
  // Enable danish language.
  include_once DRUPAL_ROOT . '/includes/locale.inc';
  locale_add_language('da', NULL, NULL, NULL, '', NULL, TRUE, TRUE);

  // Import our own translations.
  $file = new stdClass();
  $file->uri = DRUPAL_ROOT . '/profiles/loopdk/translations/da.po';
  $file->filename = basename($file->uri);
  _locale_import_po($file, 'da', LOCALE_IMPORT_OVERWRITE, 'default');

  // Import field translation group.
  $file = new stdClass();
  $file->uri = DRUPAL_ROOT . '/profiles/loopdk/translations/da_fields.po';
  $file->filename = basename($file->uri);
  _locale_import_po($file, 'da', LOCALE_IMPORT_OVERWRITE, 'field');

  // Import menu translation group.
  $file = new stdClass();
  $file->uri = DRUPAL_ROOT . '/profiles/loopdk/translations/da_menu.po';
  $file->filename = basename($file->uri);
  _locale_import_po($file, 'da', LOCALE_IMPORT_OVERWRITE, 'menu');

  // Import panels translation group.
  $file = new stdClass();
  $file->uri = DRUPAL_ROOT . '/profiles/loopdk/translations/da_panels.po';
  $file->filename = basename($file->uri);
  _locale_import_po($file, 'da', LOCALE_IMPORT_OVERWRITE, 'panels');

  // Import views translation group.
  $file = new stdClass();
  $file->uri = DRUPAL_ROOT . '/profiles/loopdk/translations/da_views.po';
  $file->filename = basename($file->uri);
  _locale_import_po($file, 'da', LOCALE_IMPORT_OVERWRITE, 'views');

  // Build batch with l10n_update module.
  $history = l10n_update_get_history();
  module_load_include('check.inc', 'l10n_update');
  $available = l10n_update_available_releases();
  $updates = l10n_update_build_updates($history, $available);

  // Fire of the batch!
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
        'shortener_url_length" => "72'
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

  // URL shorten.
  variable_set('shorten_service', 'ShURLy');
  variable_set('shorten_service_backup', 'none');
  variable_set('shorten_generate_token', 0);
  variable_set('shorten_show_service', 0);
  variable_set('shorten_use_alias', 0);
}

/*
 * Revert features.
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
}
