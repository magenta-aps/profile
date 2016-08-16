<?php
/**
 * @file
 * loop_search.features.inc
 */

/**
 * Implements hook_default_search_api_index().
 */
function loop_search_default_search_api_index() {
  $items = array();
  $items['post'] = entity_import('search_api_index', '{
    "name" : "Post",
    "machine_name" : "post",
    "description" : null,
    "server" : "default",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "title" : { "type" : "text", "boost" : "2.0" },
        "type" : { "type" : "string" },
        "status" : { "type" : "integer" },
        "comments" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "comment" },
        "search_api_language" : { "type" : "string" },
        "field_description:value" : { "type" : "text" },
        "field_keyword:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_profession:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_subject:name" : { "type" : "text" },
        "comments:comment_body:value" : { "type" : "list\\u003Ctext\\u003E" },
        "body:value" : { "type" : "text" },
        "body:summary" : { "type" : "text" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : {
              "external_sources" : "external_sources",
              "leaf" : "leaf",
              "post" : "post",
              "instruction" : "instruction"
            }
          }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "field_keyword:name" : true,
              "field_profession:name" : true,
              "field_subject:name" : true,
              "comments:comment_body:value" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "field_keyword:name" : true,
              "field_profession:name" : true,
              "field_subject:name" : true,
              "comments:comment_body:value" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : { "status" : 0, "weight" : "15", "settings" : { "fields" : [] } },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "field_keyword:name" : true,
              "field_profession:name" : true,
              "field_subject:name" : true,
              "comments:comment_body:value" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : [],
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 1,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_page().
 */
function loop_search_default_search_api_page() {
  $items = array();
  $items['default'] = entity_import('search_api_page', '{
    "index_id" : "post",
    "path" : "search",
    "name" : "Default",
    "machine_name" : "default",
    "description" : "",
    "options" : {
      "mode" : "terms",
      "fields" : [],
      "per_page" : "10",
      "result_page_search_form" : 1,
      "get_per_page" : 0,
      "view_mode" : "search_api_page_result",
      "search_api_spellcheck" : 1
    },
    "enabled" : "1"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function loop_search_default_search_api_server() {
  $items = array();
  $items['default'] = entity_import('search_api_server', '{
    "name" : "Default",
    "machine_name" : "default",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids" : true,
      "scheme" : "http",
      "host" : "localhost",
      "port" : "8983",
      "path" : "\\/solr\\/loop",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "http_method" : "AUTO",
      "autocorrect_spell" : 0,
      "autocorrect_suggest_words" : 0
    },
    "enabled" : "1"
  }');
  return $items;
}
