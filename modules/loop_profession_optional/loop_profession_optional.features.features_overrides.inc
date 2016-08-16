<?php
/**
 * @file
 * loop_profession_optional.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function loop_profession_optional_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field_instance
  $overrides["field_instance.user-user-field_profession.required"] = 0;

 return $overrides;
}
