<?php

function sepia_preprocess_page(&$vars) {
  //  Removes the tabs from user  login, register & password
  switch (current_path()) {
    case 'user':
      $vars['title'] = t('Login');
      unset($vars['tabs']);
      break;
    case 'user/register':
      $vars['title'] = t('New account');
      unset($vars['tabs']);
      break;
    case 'user/password':
      $vars['title'] = t('DOH! I forgot my password');
      unset($vars['tabs']);
      break;
  }

  if (isset($vars['node'])) {
    // If the node type is "blog" the template suggestion will be "page--blog.tpl.php".
    $vars['theme_hook_suggestions'][] = 'page__' . $vars['node']->type;
  }
}

function sepia_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];
  if (!empty($breadcrumb)) {
    // Adding the title of the current page to the breadcrumb.
    $breadcrumb[] = drupal_get_title();

    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';

    $output .= '<div class="breadcrumb">' . implode(' » ', $breadcrumb) . '</div>';
    return $output;
  }
}

function sepia_form_user_login_alter(&$form, &$form_state, $form_id) {
  $form['name']['#attributes']['placeholder'] = $form['name']['#title'];
  unset($form['name']['#title']);
  unset($form['name']['#description']);

  $form['pass']['#attributes']['placeholder'] = $form['pass']['#title'];
  unset($form['pass']['#title']);
  unset($form['pass']['#description']);

  $form['openid_identifier']['#attributes']['placeholder'] = $form['openid_identifier']['#title'];
  unset($form['openid_identifier']['#title']);
  unset($form['openid_identifier']['#description']);
}