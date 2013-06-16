<?php
/**
 * @file
 * linuxdev_movies.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function linuxdev_movies_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function linuxdev_movies_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function linuxdev_movies_default_search_api_index() {
  $items = array();
  $items['movie_index'] = entity_import('search_api_index', '{
    "name" : "Movie index",
    "machine_name" : "movie_index",
    "description" : null,
    "server" : "mysql",
    "item_type" : "node",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "title" : { "type" : "string" },
        "field_genre" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_media" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "search_api_language" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "0", "bundles" : { "movie" : "movie" } }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : [],
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : [],
            "spaces" : "[^\\\\p{L}\\\\p{N}^\\u0027]",
            "ignorable" : "[-]"
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
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function linuxdev_movies_default_search_api_server() {
  $items = array();
  $items['mysql'] = entity_import('search_api_server', '{
    "name" : "MySQL",
    "machine_name" : "mysql",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "1",
      "indexes" : { "movie_index" : {
          "title" : {
            "table" : "search_api_db_movie_index_title",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_genre" : {
            "table" : "search_api_db_movie_index_field_genre",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_media" : {
            "table" : "search_api_db_movie_index_field_media",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_type" : {
            "table" : "search_api_db_movie_index_field_type",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_movie_index_search_api_language",
            "type" : "string",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
