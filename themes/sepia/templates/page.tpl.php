<?php

/**
 * @file
 */
?>
<header>
  <nav class="clearfix">
    <div class="border"></div>
    <ul class="topbar-menu">
      <li class="first topbar-link-search">
        <a class="menu-item js-topbar-link topbar-link-search" title="" href="/search">
          <i class="icon-search"></i>
        </a>
      </li>
      <li class="last topbar-link-menu">
        <a class="menu-item js-topbar-link topbar-link-menu active" title="" href="#">
          <i class="icon-align-justify"></i>
        </a>
      </li>
    </ul>

    <?php if (isset($main_menu)): ?>
      <?php print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('class' => array('main-menu')))); ?>
    <?php endif; ?>
  </nav>

  <?php if (isset($site_name) || isset($site_slogan)): ?>
    <section class="name-and-slogan clearfix">
      <?php if (isset($site_name)): ?>
        <h1 id="site-name"><?php print $site_name; ?></h1>
      <?php endif; ?>
      <?php if (isset($site_slogan)): ?>
        <h2 id="site-slogan"><?php print $site_slogan; ?></h2>
      <?php endif; ?>
    </section>
  <?php endif; ?>

  <?php print render($page['header']); ?>

</header> <!-- /.section, /#header -->

<section id="main-section" class="clearfix">
  <a id="main-content"></a>
  
  <?php if ($breadcrumb): ?>
    <div id="breadcrumb"><?php print $breadcrumb; ?></div>
  <?php endif; ?>

  <?php print $messages; ?>  <?php print render($title_prefix); ?>
  
  <?php if ($title): ?><h1 class="title" id="page-title"><?php print $title; ?></h1><?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if (isset($tabs)): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
  <?php print render($page['help']); ?>
  <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
  
  <?php print render($page['content']); ?>
  
  <?php print $feed_icons; ?>
</section>

<footer>
  <section>
    <?php print render($page['footer']); ?>
  </section> <!-- /.section, /#footer -->
</footer>
