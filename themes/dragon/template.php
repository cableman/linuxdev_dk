<?php

function dragon_preprocess_node(&$variables) {
  $node = $variables['node'];
  $variables['date'] = format_date($node->created, 'custom', 'D, d/m/Y');

  if (variable_get('node_submitted_' . $node->type, TRUE)) {
    $variables['display_submitted'] = TRUE;
    $variables['submitted'] = t('Submitted by !username on !datetime', array('!username' => $variables['name'], '!datetime' => $variables['date']));
  }
}

function dragon_preprocess_page(&$vars) {
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
}

function dragon_form_user_login_alter(&$form, &$form_state, $form_id) {
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