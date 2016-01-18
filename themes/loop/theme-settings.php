<?php

/**
 * @file
 * Theme setting callbacks for the loop theme.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * @param $form
 *   The form.
 * @param $form_state
 *   The form state.
 */
function loop_form_system_theme_settings_alter(&$form, &$form_state) {
  $form['theme_settings']['show_breadcrumbs'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show breadcrumbs'),
    '#default_value' => theme_get_setting('show_breadcrumbs', 'loop'),
    '#description' => t("Show breadcrumbs at the top each page."),
  );
}
