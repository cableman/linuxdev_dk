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

  // Exported menu link: main-menu:menu-position/4
  $menu_links['main-menu:menu-position/4'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'menu-position/4',
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
  // Exported menu link: main-menu:menu-position/5
  $menu_links['main-menu:menu-position/5'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'menu-position/5',
    'router_path' => 'menu-position/%',
    'link_title' => 'Movies (menu position rule)',
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
  // Exported menu link: main-menu:menu-position/6
  $menu_links['main-menu:menu-position/6'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'menu-position/6',
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
  // Exported menu link: management:admin/structure/menu-position
  $menu_links['management:admin/structure/menu-position'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu-position',
    'router_path' => 'admin/structure/menu-position',
    'link_title' => 'Menu position rules',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure rules for menu positions.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/structure',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Articels (menu position rule)');
  t('Blog posts (menu position rule)');
  t('Menu position rules');
  t('Movies (menu position rule)');


  return $menu_links;
}
