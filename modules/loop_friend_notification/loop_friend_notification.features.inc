<?php
/**
 * @file
 * loop_friend_notification.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function loop_friend_notification_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_message_type().
 */
function loop_friend_notification_default_message_type() {
  $items = array();
  $items['user_sharing_node_reference'] = entity_import('message_type', '{
    "name" : "user_sharing_node_reference",
    "description" : "User sharing node reference",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "da",
    "arguments" : null,
    "message_text" : { "da" : [
        {
          "value" : "Brugeren [message:field-sender] vil gerne g\\u00f8re dig opm\\u00e6rksom p\\u00e5 tr\\u00e5den \\u003Ca href=\\u0022\\/node\\/[message:field-node:nid]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E.",
          "format" : "html",
          "safe_value" : "Brugeren [message:field-sender] vil gerne g\\u00f8re dig opm\\u00e6rksom p\\u00e5 tr\\u00e5den \\u003Ca href=\\u0022\\/node\\/[message:field-node:nid]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E."
        }
      ]
    }
  }');
  return $items;
}
