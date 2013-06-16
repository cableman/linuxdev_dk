<?php
/**
 * @file
 * linuxdev_movies.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function linuxdev_movies_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'movie_index';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_movie_index';
  $view->human_name = 'Movie index';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Movies';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    2 => '2',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_movie_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Sort criterion: Indexed Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'search_api_index_movie_index';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Indexed Content: Genres */
  $handler->display->display_options['filters']['field_genre']['id'] = 'field_genre';
  $handler->display->display_options['filters']['field_genre']['table'] = 'search_api_index_movie_index';
  $handler->display->display_options['filters']['field_genre']['field'] = 'field_genre';
  $handler->display->display_options['filters']['field_genre']['group'] = '0';
  /* Filter criterion: Indexed Content: Media */
  $handler->display->display_options['filters']['field_media']['id'] = 'field_media';
  $handler->display->display_options['filters']['field_media']['table'] = 'search_api_index_movie_index';
  $handler->display->display_options['filters']['field_media']['field'] = 'field_media';
  $handler->display->display_options['filters']['field_media']['value'] = array(
    14 => '14',
    15 => '15',
  );
  $handler->display->display_options['filters']['field_media']['group'] = '0';
  /* Filter criterion: Indexed Content: Type */
  $handler->display->display_options['filters']['field_type']['id'] = 'field_type';
  $handler->display->display_options['filters']['field_type']['table'] = 'search_api_index_movie_index';
  $handler->display->display_options['filters']['field_type']['field'] = 'field_type';
  $handler->display->display_options['filters']['field_type']['value'] = array(
    21 => '21',
    20 => '20',
  );
  $handler->display->display_options['filters']['field_type']['group'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'movies';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Movies';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $export['movie_index'] = $view;

  return $export;
}
