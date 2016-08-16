<?php
/**
 * @file
 * loop_notification.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function loop_notification_default_rules_configuration() {
  $items = array();
  $items['loop_notification_send_mail'] = entity_import('rules_config', '{ "loop_notification_send_mail" : {
      "LABEL" : "Send mail to subscribers",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "mimemail" ],
      "USES VARIABLES" : {
        "node" : { "label" : "node", "type" : "node" },
        "user" : { "label" : "user", "type" : "user" },
        "comment" : { "label" : "comment", "type" : "comment" }
      },
      "IF" : [
        { "NOT data_is" : { "data" : [ "user:uid" ], "value" : [ "comment:author:uid" ] } }
      ],
      "DO" : [
        { "mimemail" : {
            "key" : "Mail on message creation",
            "to" : "[user:mail]",
            "from_mail" : "[site:mail]",
            "subject" : "Nyt svar til sp\\u00f8rgsm\\u00e5let [node:title]",
            "body" : "\\u003Ch2\\u003ENyt svar til sp\\u00f8rgsm\\u00e5let [node:title]\\u003C\\/h2\\u003E\\r\\n\\u003Cp\\u003EK\\u00e6re [user:field-first-name] [user:field-last-name]\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003EDer er kommet nyt svar til sp\\u00f8rgsm\\u00e5let \\u003Ca href=\\u0022\\/node\\/[node:nid]\\u0022\\u003E[node:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003EMed venlig hilsen\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003E[site:name]\\u003C\\/p\\u003E\\r\\n\\u003C\\/br\\u003E\\r\\n\\u003C\\/br\\u003E\\r\\n\\u003Cp\\u003EDette er en automatisk meddelelse fra [site:name]\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003EDu kan styre dine abonnementer fra din \\u003Ca href=\\u0022\\/user\\/[user:uid]\\/notifications\\u0022\\u003Ebrugerprofil\\u003C\\/a\\u003E\\u003C\\/p\\u003E",
            "attachments" : [ "" ],
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_autosubscribe_node_post_author'] = entity_import('rules_config', '{ "rules_autosubscribe_node_post_author" : {
      "LABEL" : "Autosubscribe node post author",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "flag", "rules" ],
      "ON" : { "node_insert--post" : { "bundle" : "post" } },
      "DO" : [
        { "flag_flagnode" : {
            "flag" : "subscribe_node",
            "node" : [ "node" ],
            "flagging_user" : [ "node:author" ],
            "permission_check" : 0
          }
        }
      ]
    }
  }');
  $items['rules_create_message'] = entity_import('rules_config', '{ "rules_create_message" : {
      "LABEL" : "Create message",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "flag", "rules", "comment" ],
      "ON" : { "comment_insert" : [] },
      "DO" : [
        { "flag_fetch_users_node" : {
            "USING" : { "flag" : "subscribe_node", "node" : [ "comment:node" ] },
            "PROVIDE" : { "users" : { "users" : "Users who flagged" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "users" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "component_rules_create_notification" : {
                  "active_user_object" : [ "list-item" ],
                  "comment_author" : [ "comment:author" ],
                  "comment" : [ "comment" ]
                }
              },
              { "component_loop_notification_send_mail" : {
                  "node" : [ "comment:node" ],
                  "user" : [ "list-item" ],
                  "comment" : [ "comment" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_create_notification'] = entity_import('rules_config', '{ "rules_create_notification" : {
      "LABEL" : "Create notification",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "active_user_object" : { "label" : "Active user objject", "type" : "user" },
        "comment_author" : { "label" : "comment_author", "type" : "user" },
        "comment" : { "label" : "comment", "type" : "comment" }
      },
      "RULES" : [
        { "RULE" : {
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } },
            "IF" : [
              { "NOT data_is" : { "data" : [ "active-user-object" ], "value" : [ "comment-author" ] } }
            ],
            "DO" : [
              { "entity_create" : {
                  "USING" : {
                    "type" : "message",
                    "param_type" : "comment_added_to_post",
                    "param_user" : [ "active-user-object" ]
                  },
                  "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
                }
              },
              { "data_set" : {
                  "data" : [ "entity-created:field-message-node-reference" ],
                  "value" : [ "comment:node" ]
                }
              },
              { "entity_save" : { "data" : [ "entity-created" ], "immediate" : 1 } }
            ],
            "LABEL" : "Create notification"
          }
        }
      ]
    }
  }');
  $items['rules_remove_subscription'] = entity_import('rules_config', '{ "rules_remove_subscription" : {
      "LABEL" : "Remove subscription",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "Subscriptions" ],
      "REQUIRES" : [ "flag" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "DO" : [
        { "flag_unflagnode" : {
            "flag" : "subscribe_node",
            "node" : [ "node" ],
            "flagging_user" : [ "site:current-user" ],
            "permission_check" : 0
          }
        }
      ]
    }
  }');
  $items['rules_set_message_read'] = entity_import('rules_config', '{ "rules_set_message_read" : {
      "LABEL" : "Set message read",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "notification" ],
      "REQUIRES" : [ "flag" ],
      "USES VARIABLES" : { "message_read" : { "label" : "Set message read", "type" : "message" } },
      "DO" : [
        { "flag_flagmessage" : {
            "flag" : "message_read",
            "message" : [ "message-read" ],
            "flagging_user" : [ "site:current-user" ],
            "permission_check" : 0
          }
        }
      ]
    }
  }');
  return $items;
}
