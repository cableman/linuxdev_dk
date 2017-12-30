<?php

/**
 * @file
 * Administration interface for the module, basically the selection of contexts
 * and the changing of names.
 */

/**
 * The administration form, which lists modules that implements hook_block.
 *
 * @param array $form_state
 * @return array $form
 */
function context_filter_admin_form() {
  $form = array();

  // Find all modules that implements hook_block
  $options = array();
  foreach (module_implements('block_info') as $module) {
    $options[$module] = $module;
  }

  // Build admin form
  $form['context_filter_block_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Context drop down types'),
    '#options' => $options,
    '#default_value' => variable_get('context_filter_block_types', $options),
  );

  return system_settings_form($form);
}

/**
 * Administration form for chaning the group drop-down names in context.
 *
 * @return array $form
 */
function context_filter_names_admin_form() {
  $form = array(
    '#tree' => TRUE,
  );

  // Load the selected modules that provides blocks or show all modules that
  // provides blocks.
  $options = array_filter(variable_get('context_filter_block_types', NULL));
  if (!$options) {
    foreach (module_implements('block') as $module) {
      $options[$module] = $module;
    }
  }

  // Load default values.
  $default = variable_get('context_filter_names', array());

  // Build form elements.
  foreach ($options as $value) {
    $form['context_filter_names'][$value] = array(
      '#type' => 'textfield',
      '#title' => $value,
      '#default_value' => isset($default[$value]) ? $default[$value] : $value,
      '#description' => t('Change the name displayed in the context drop-down box.'),
    );
  }

  return system_settings_form($form);
}