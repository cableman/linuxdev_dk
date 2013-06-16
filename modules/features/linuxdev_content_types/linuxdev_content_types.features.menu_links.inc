<?php
/**
 * @file
 * linuxdev_content_types.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function linuxdev_content_types_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:menu-position/1
  $menu_links['main-menu:menu-position/1'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'menu-position/1',
    'router_path' => 'menu-position/%',
    'link_title' => 'Blog posts (menu position rule)',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'menu-position-link',
        ),
      ),
    ),
    'module' => 'menu_position',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'blog',
  );
  // Exported menu link: main-menu:menu-position/2
  $menu_links['main-menu:menu-position/2'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'menu-position/2',
    'router_path' => 'menu-position/%',
    'link_title' => 'Articels (menu position rule)',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'menu-position-link',
        ),
      ),
    ),
    'module' => 'menu_position',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'node/207',
  );
  // Exported menu link: main-menu:menu-position/3
  $menu_links['main-menu:menu-position/3'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'menu-position/3',
    'router_path' => 'menu-position/%',
    'link_title' => 'Movie (menu position rule)',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'menu-position-link',
        ),
      ),
    ),
    'module' => 'menu_position',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'movies',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Articels (menu position rule)');
  t('Blog posts (menu position rule)');
  t('Movie (menu position rule)');


  return $menu_links;
}
