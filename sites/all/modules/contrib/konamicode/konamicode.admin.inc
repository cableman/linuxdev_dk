<?php
/**
 * @file
 * Provides the administration settings for the Konami Code module.
 */

/**
 * Menu callback; The administration settings for the Konami Code.
 */
function konamicode_admin_settings($form, &$form_state) {
  // Retrieve all available Konami Actions.
  $actions = module_invoke_all('konamicode');

  // Allow the user to choose which actions are active.
  $enabled = array_filter(variable_get('konamicode_actions', array()));
  // The default requires at least Image Attack.
  if (empty($enabled)) {
    $enabled = array('imageattack' => 'imageattack');
  }

  // Construct the settings form.
  $form['konamicode_actions'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Actions'),
    '#description' => t('Which actions should be enabled.'),
    '#options' => $actions,
    '#default_value' => $enabled,
    '#attached' => array(
      'css' => array(
        drupal_get_path('module', 'konamicode') . '/konamicode.admin.css' => array(),
      ),
      'js' => array(
        drupal_get_path('module', 'konamicode') . '/konamicode.admin.js' => array(),
      ),
    ),
  );
  $form['konamicode_settings'] = array(
    '#type' => 'vertical_tabs',
  );

  // Settings for each individual action.
  foreach ($actions as $action => $name) {
    // Assemble the settings for the action.
    $settings = module_invoke_all('konamicode_' . $action . '_settings');
    $settings['konamicode_code_' . $action] = array(
      '#type' => 'textfield',
      '#title' => t('Key code sequence'),
      '#default_value' => variable_get('konamicode_code_' . $action, '38,38,40,40,37,39,37,39,66,65'),
      '#description' => t('The <a href="@keycodes">key code sequence</a> used to activate the %name action, seperated by commas. Provide either the key code integer, or the character of the key. Defaults to the <a href="@konamicode">Konami Code</a>. Some examples are: "<em>38,38,40,40,37,39,37,39,66,65</em>", "<em>g,o,d</em>", "<em>n,o,c,l,i,p</em>", etc.', array(
        '%name' => $name,
        '@konamicode' => 'https://www.drupal.org/docs/8/modules/konami-code/general-information-and-history',
        '@keycodes' => 'https://www.drupal.org/docs/8/modules/konami-code/configuring-key-code-sequence',
      )),
      '#weight' => -9,
    );

    // Add the demonstration capabilities.
    module_invoke_all('konamicode_' . $action);

    // Stick all the settings in a fieldset.
    $form['konamicode_action_' . $action] = array_merge($settings, array(
      '#type' => 'fieldset',
      '#title' => $name,
      '#description' => t('Settings associated with the %name action. This will only be used if you have it enabled above.', array('%name' => $name)),
      '#collapsible' => TRUE,
      '#group' => 'konamicode_settings',
      '#attributes' => array('data-konamicodeaction' => $action),
    ));
  }
  return system_settings_form($form);
}

/**
 * Implements hook_konamicode_IMAGEATTACK_settings().
 */
function konamicode_konamicode_imageattack_settings() {
  $form['konamicode_imageattack'] = array(
    '#title' => t('Images'),
    '#type' => 'textarea',
    '#description' => t('The absolute URL of the images to attack the user with. Each different image should be seperated by a line break.'),
    '#default_value' => variable_get('konamicode_imageattack', 'https://drupal.org/files/druplicon-small.png'),
    '#rows' => 2,
  );
  $form['konamicode_imageattackmax'] = array(
    '#title' => t('Amount of images'),
    '#type' => 'textfield',
    '#description' => t('Number of images to appear on the screen during an attack.'),
    '#default_value' => variable_get('konamicode_imageattackmax', 500),
    '#size' => 5,
  );
  return $form;
}

/**
 * Implements hook_konamicode_REDIRECT_settings().
 */
function konamicode_konamicode_redirect_settings() {
  $form['konamicode_destination'] = array(
    '#type' => 'textfield',
    '#title' => t('Destination'),
    '#description' => t('When people enter the <a href="@konamicode">Konami Code</a>, redirect them to the given URL. This can either be an internal or external path.', array('@konamicode' => 'https://www.drupal.org/docs/8/modules/konami-code/general-information-and-history')),
    '#default_value' => variable_get('konamicode_destination', 'https://youtu.be/dQw4w9WgXcQ'),
  );
  return $form;
}

/**
 * Implements hook_konamicode_ALERT_settings().
 */
function konamicode_konamicode_alert_settings() {
  $form['konamicode_alert'] = array(
    '#type' => 'textfield',
    '#title' => t('Text'),
    '#description' => t('The text to display to the user.'),
    '#default_value' => variable_get('konamicode_alert', t('Konami Code Is Geek!')),
  );
  return $form;
}

/**
 * Implements hook_konamicode_GEOCITIESIZER_settings().
 */
function konamicode_konamicode_geocitiesizer_settings() {
  $form['konamicode_geocitiesizer_info'] = array(
    '#markup' => t('NOTE: This is a very old action relying on an external HTTP site. This will not work on sites using https.'),
    '#weight' => -10,
  );

  $form['konamicode_geocitiesizer_theme'] = array(
    '#type' => 'select',
    '#title' => t('Theme'),
    '#description' => t('The theme to use when Geocities-izing.'),
    '#default_value' => variable_get('konamicode_geocitiesizer_theme', 0),
    '#options' => array(
      0 => t('Random'),
      1 => t('Yellow'),
      2 => t('Tech'),
      3 => t('Space'),
    ),
  );
  return $form;
}

/**
 * Implements hook_konamicode_SNOWFALL_settings().
 */
function konamicode_konamicode_snowfall_settings() {
  $form['konamicode_snowfall_flakecount'] = array(
    '#type' => 'textfield',
    '#title' => t('Flake Count'),
    '#description' => t('The amount of flakes to display.'),
    '#default_value' => variable_get('konamicode_snowfall_flakecount', '200'),
  );
  $form['konamicode_snowfall_flakecolor'] = array(
    '#type' => 'textfield',
    '#title' => t('Flake Color'),
    '#description' => t('The HTML color code of which to display the snowflakes.'),
    '#default_value' => variable_get('konamicode_snowfall_flakecolor', '#FFFFFF'),
  );
  $form['konamicode_snowfall_minsize'] = array(
    '#type' => 'textfield',
    '#title' => t('Minimum Size'),
    '#default_value' => variable_get('konamicode_snowfall_minsize', '2'),
  );
  $form['konamicode_snowfall_maxsize'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum Size'),
    '#default_value' => variable_get('konamicode_snowfall_maxsize', '5'),
  );
  $form['konamicode_snowfall_minspeed'] = array(
    '#type' => 'textfield',
    '#title' => t('Minimum Speed'),
    '#default_value' => variable_get('konamicode_snowfall_minspeed', '1'),
  );
  $form['konamicode_snowfall_maxspeed'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum Speed'),
    '#default_value' => variable_get('konamicode_snowfall_maxspeed', '5'),
  );
  $form['konamicode_snowfall_round'] = array(
    '#type' => 'checkbox',
    '#title' => t('Round'),
    '#description' => t('Makes the snowflakes rounded if the browser supports it.'),
    '#default_value' => variable_get('konamicode_snowfall_round', TRUE),
  );
  $form['konamicode_snowfall_shadow'] = array(
    '#type' => 'checkbox',
    '#title' => t('Shadow'),
    '#description' => t('Gives the snowflakes a shadow if the browser supports it.'),
    '#default_value' => variable_get('konamicode_snowfall_shadow', TRUE),
  );
  return $form;
}

/**
 * Implements hook_konamicode_BROWSERPONIES_settings().
 */
function konamicode_konamicode_browserponies_settings() {
  $form['konamicode_browserponies_baseurl'] = array(
    '#type' => 'textfield',
    '#title' => t('Base URL'),
    '#description' => t('Base URL of the Browser Ponies files'),
    '#default_value' => variable_get('konamicode_browserponies_baseurl', 'https://panzi.github.io/Browser-Ponies'),
    '#required' => TRUE,
  );

  $form['konamicode_browserponies_showLoadProgress'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Download Progress Bar'),
    '#default_value' => variable_get('konamicode_browserponies_showLoadProgress', true),
  );

  $form['konamicode_browserponies_fadeDuration'] = array(
    '#type' => 'textfield',
    '#title' => t('Fade Duration'),
    '#description' => t('Amount of time in milliseconds for the ponies to appear on the screen'),
    '#default_value' => variable_get('konamicode_browserponies_fadeDuration', 500),
    '#required' => TRUE,
  );

  $form['konamicode_browserponies_audioEnabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable audio if browser supports HTML 5 Audio'),
    '#default_value' => variable_get('konamicode_browserponies_audioEnabled', false),
  );

  $form['konamicode_browserponies_volume'] = array(
    '#type' => 'textfield',
    '#title' => t('Audio Volume'),
    '#description' => t('Enter a value between 0 and 1 (eg. 0.1, 0.2, etc)'),
    '#default_value' => variable_get('konamicode_browserponies_volume', 1),
  );

  $form['konamicode_browserponies_fps'] = array(
    '#type' => 'textfield',
    '#title' => t('Frames Per Second'),
    '#description' => t('The lower the number, the better the performance'),
    '#default_value' => variable_get('konamicode_browserponies_fps', 25),
    '#required' => TRUE,
  );

  $form['konamicode_browserponies_showFps'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Frames per Second'),
    '#default_value' => variable_get('konamicode_browserponies_showFps', false),
  );

  $form['konamicode_browserponies_speed'] = array(
    '#type' => 'textfield',
    '#title' => t('Speed Multiplier'),
    '#description' => t('How fast are these ponies going?'),
    '#default_value' => variable_get('konamicode_browserponies_speed', 3),
    '#required' => TRUE,
  );

  $form['konamicode_browserponies_speakProbability'] = array(
    '#type' => 'textfield',
    '#title' => t('Random Speak Probability'),
    '#description' => t('Enter a value between 0 and 1 (eg. 0.1, 0.2, etc)'),
    '#default_value' => variable_get('konamicode_browserponies_speakProbability', 0.1),
    '#required' => TRUE,
  );

  $form['konamicode_browserponies_applejack'] = array(
    '#type' => 'textfield',
    '#title' => t('Applejack'),
    '#description' => t('Enter the number of Applejack ponies on the screen'),
    '#default_value' => variable_get('konamicode_browserponies_applejack', 1),
    '#required' => TRUE,
  );

  $form['konamicode_browserponies_fluttershy'] = array(
    '#type' => 'textfield',
    '#title' => t('Fluttershy'),
    '#description' => t('Enter the number of Fluttershy ponies on the screen'),
    '#default_value' => variable_get('konamicode_browserponies_fluttershy', 1),
    '#required' => TRUE,
  );

  $form['konamicode_browserponies_pinkiepie'] = array(
    '#type' => 'textfield',
    '#title' => t('Pinkiepie'),
    '#description' => t('Enter the number of Pinkiepie ponies on the screen'),
    '#default_value' => variable_get('konamicode_browserponies_pinkiepie', 1),
    '#required' => TRUE,
  );

  $form['konamicode_browserponies_rainbowdash'] = array(
    '#type' => 'textfield',
    '#title' => t('Rainbowdash'),
    '#description' => t('Enter the number of Rainbowdash ponies on the screen'),
    '#default_value' => variable_get('konamicode_browserponies_rainbowdash', 1),
    '#required' => TRUE,
  );

  $form['konamicode_browserponies_rarity'] = array(
    '#type' => 'textfield',
    '#title' => t('Rarity'),
    '#description' => t('Enter the number of Rarity ponies on the screen'),
    '#default_value' => variable_get('konamicode_browserponies_rarity', 1),
    '#required' => TRUE,
  );

  $form['konamicode_browserponies_twilightsparkle'] = array(
    '#type' => 'textfield',
    '#title' => t('Twilight Sparkle'),
    '#description' => t('Enter the number of Twilight Sparkle ponies on the screen'),
    '#default_value' => variable_get('konamicode_browserponies_twilightsparkle', 1),
    '#required' => TRUE,
  );
  return $form;
}
