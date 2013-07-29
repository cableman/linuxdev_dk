<?php
/**
 * @file
 * linuxdev_content_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function linuxdev_content_types_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function linuxdev_content_types_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_fontyourface_features_default_font().
 */
function linuxdev_content_types_fontyourface_features_default_font() {
  return array(
    'Lekton italic (latin)' => array(
      'name' => 'Lekton italic (latin)',
      'enabled' => 1,
      'url' => 'http://www.google.com/webfonts/family?family=Lekton&subset=latin#italic',
      'provider' => 'google_fonts_api',
      'css_selector' => '.site-name',
      'css_family' => 'Lekton',
      'css_style' => 'italic',
      'css_weight' => 'normal',
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:2:{s:4:"path";s:13:"Lekton:italic";s:6:"subset";s:5:"latin";}',
    ),
    'PT Sans regular (latin)' => array(
      'name' => 'PT Sans regular (latin)',
      'enabled' => 1,
      'url' => 'http://www.google.com/webfonts/family?family=PT Sans&subset=latin#regular',
      'provider' => 'google_fonts_api',
      'css_selector' => 'h1, h2, h3, h4, h5, h6',
      'css_family' => 'PT Sans',
      'css_style' => 'normal',
      'css_weight' => 'normal',
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:2:{s:4:"path";s:15:"PT Sans:regular";s:6:"subset";s:5:"latin";}',
    ),
    'Source Sans Pro regular (latin)' => array(
      'name' => 'Source Sans Pro regular (latin)',
      'enabled' => 1,
      'url' => 'http://www.google.com/webfonts/family?family=Source Sans Pro&subset=latin#regular',
      'provider' => 'google_fonts_api',
      'css_selector' => 'header, .content-wrapper',
      'css_family' => 'Source Sans Pro',
      'css_style' => 'normal',
      'css_weight' => 'normal',
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:2:{s:4:"path";s:23:"Source Sans Pro:regular";s:6:"subset";s:5:"latin";}',
    ),
  );
}

/**
 * Implements hook_node_info().
 */
function linuxdev_content_types_node_info() {
  $items = array(
    'blog_post' => array(
      'name' => t('Blog post'),
      'base' => 'node_content',
      'description' => t('Used to create new blog posts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'book' => array(
      'name' => t('Articles'),
      'base' => 'node_content',
      'description' => t('<em>Books</em> have a built-in hierarchical navigation. Use for handbooks or tutorials.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'movie' => array(
      'name' => t('Movie'),
      'base' => 'node_content',
      'description' => t('Movie description only visible to login users'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Static page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
