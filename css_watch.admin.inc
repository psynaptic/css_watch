<?php
/**
 * @file
 * Admin settings form for the CSS Watch module.
 */

/**
 * Admin settings form.
 */
function css_watch_settings() {
  $form = array();

  $enabled_themes = variable_get('css_watch_enabled_themes', array());

  $form['css_watch_poll_interval'] = array(
    '#type' => 'textfield',
    '#title' => t('Polling Interval'),
    '#description' => t('Enter polling interval in milliseconds'),
    '#default_value' => variable_get('css_watch_poll_interval', CSS_WATCH_DEFAULT_INTERVAL),
  );
  $form['css_watch_enabled_themes'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Enabled themes'),
    '#description' => t('Select the themes that should have their stylesheets listed to allow them to be selected monitored.'),
    '#options' => css_watch_get_themes(),
    '#default_value' => $enabled_themes,
  );

  if (!empty($enabled_themes)) {
    $form['css_watch_stylesheets'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Selected stylesheets'),
      '#description' => t('Pick the stylesheets you would like to be monitored for changes.'),
      '#options' => css_watch_get_stylesheets(),
      '#default_value' => variable_get('css_watch_stylesheets', array()),
    );
  }

  return system_settings_form($form);
}

function css_watch_get_themes() {
  foreach (list_themes() as $theme => $data) {
    $themes[$theme] = $theme;
  }
  return $themes;
}

function css_watch_get_stylesheets() {
  $themes = variable_get('css_watch_enabled_themes', array());

  $system_themes = list_themes();
  $stylesheets = array();
  foreach ($themes as $theme) {
    foreach ($system_themes[$theme]->stylesheets as $styles) {
      foreach ($styles as $media => $stylesheet) {
        $stylesheets[$stylesheet] = $stylesheet;
      }
    }
  }
  return $stylesheets;
}
