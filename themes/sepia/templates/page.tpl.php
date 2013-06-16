<?php

/**
 * @file
 */
?>
<header>
  <nav>
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

  <?php print render($page['header']); ?>

</header> <!-- /.section, /#header -->

<div class="content-wrapper">
  <?php if (isset($page['secondary_content']) && !empty($page['secondary_content'])) { ?>
    <div class="primary-content">
  <?php } else { ?>
    <div class="primary-content-full">
  <?php } ?>
    <a id="main-content"></a>

    <?php if (isset($breadcrumb)): ?>
      <?php print $breadcrumb; ?>
    <?php endif; ?>

    <?php print $messages; ?>

    <?php if (isset($tabs)): ?>
      <div class="tabs"><?php print render($tabs); ?></div>
    <?php endif; ?>

    <?php print render($page['help']); ?>

    <?php if (isset($action_links)): ?>
      <ul class="action-links">
        <?php print render($action_links); ?>
      </ul>
    <?php endif; ?>

    <?php print render($page['content']); ?>

    <?php print $feed_icons; ?>
  </div>

  <?php if (isset($page['secondary_content']) && !empty($page['secondary_content'])): ?>
    <div class="secondary-content">
      <?php print render($page['secondary_content']); ?>
    </div>
  <?php endif; ?>
</div>

<?php if (isset($page['footer'])): ?>
  <footer>
    <?php if (isset($site_name)): ?>
      <p class="site-name"><?php print $site_name; ?></p>
    <?php endif; ?>
    <?php print render($page['footer']); ?>
  </footer>
<?php endif; ?>