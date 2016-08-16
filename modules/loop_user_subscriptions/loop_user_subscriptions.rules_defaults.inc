<?php
/**
 * @file
 * loop_user_subscriptions.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function loop_user_subscriptions_default_rules_configuration() {
  $items = array();
  $items['loop_notification_remove_taxonomy_subscription'] = entity_import('rules_config', '{ "loop_notification_remove_taxonomy_subscription" : {
      "LABEL" : "Remove taxonomy subscription",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "Subscriptions" ],
      "REQUIRES" : [ "flag" ],
      "USES VARIABLES" : { "term" : { "label" : "term", "type" : "taxonomy_term" } },
      "DO" : [
        { "flag_unflagtaxonomy_term" : {
            "flag" : "subscribe_taxonomy",
            "taxonomy_term" : [ "term" ],
            "flagging_user" : [ "site:current-user" ],
            "permission_check" : 0
          }
        }
      ]
    }
  }');
  return $items;
}
