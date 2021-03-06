<?php
/**
 * @file
 * Administration page callbacks for the Featherlight module.
 */

/**
 * Form constructor for the Featherlight settings form.
 */
function featherlight_admin_form($form, &$form_state) {
  $config = config('featherlight.settings');

  $form['openspeed'] = array(
    '#type' => 'number',
    '#title' => t('Open speed'),
    '#description' => t("The duration of the opening animation. Default is 250."),
    '#default_value' => $config->get('openspeed'),
    '#min' => 1,
    '#field_suffix' => t('ms'),
  );
  $form['closespeed'] = array(
    '#type' => 'number',
    '#title' => t('Close speed'),
    '#description' => t("The duration of the closing animation. Default is 250."),
    '#default_value' => $config->get('closespeed'),
    '#min' => 1,
    '#field_suffix' => t('ms'),
  );
  $form['closeonclick'] = array(
    '#type' => 'select',
    '#title' => t('Close on click'),
    '#description' => t("Close the lightbox when clicking this. Default is Background."),
    '#options' => array(
      FALSE => t('Disabled'),
      'background' => t('Background'),
      'anywhere' => t('Anything'),
    ),
    '#default_value' => $config->get('closeonclick'),
  );
  $form['closeonesc'] = array(
    '#type' => 'checkbox',
    '#title' => t('Close on ESC'),
    '#description' => t("Close the lightbox when pressing the ESC key. Default is TRUE."),
    '#default_value' => $config->get('closeonesc'),
  );
  $form['closeicon'] = array(
    '#type' => 'textfield',
    '#title' => t('Close icon'),
    '#description' => t("HTML to use as the close icon. Can be an HTML character entity, or any other HTML (such as a Font Awesome span). Default is '&#10005;'."),
    '#default_value' => $config->get('closeicon'),
  );
  $form['otherclose'] = array(
    '#type' => 'textfield',
    '#title' => t('Other close'),
    '#description' => t("Selector for alternative close button(s) (e.g. 'a.close'). Default is empty."),
    '#default_value' => $config->get('otherclose'),
  );
  $form['loader'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display spinner'),
    '#description' => t("Show an animated spinner while the lightbox is loading."),
    '#default_value' => $config->get('loader'),
  );
  $form['loading'] = array(
    '#type' => 'textfield',
    '#title' => t('Loading'),
    '#description' => t("Content to show while the lightbox is loading (like a spinner). Default is empty."),
    '#default_value' => $config->get('loading'),
    '#states' => array(
      'visible' => array(
        ':input[name="loader"]' => array('checked' => FALSE),
      ),
    ),
  );
  $form['swipe'] = array(
    '#type' => 'checkbox',
    '#title' => t('Swipe'),
    '#description' => t("Allows swiping on touch-enabled devices to navigate between images in a gallery."),
    '#default_value' => $config->get('swipe'),
  );

  $form['manual'] = array(
    '#type' => 'fieldset',
    '#title' => t('Manual use'),
    '#description' => t("Settings for when you want to load the lightbox manually."),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['manual']['every_page'] = array(
    '#type' => 'checkbox',
    '#title' => t('Load on every page'),
    '#description' => t("Load the Featherlight library files on every page."),
    '#default_value' => $config->get('every_page'),
  );
  $form['manual']['caption_attribute'] = array(
    '#type' => 'select',
    '#title' => t('Caption'),
    '#description' => t('The image attribute to use for the lightbox caption.'),
    '#options' => array(
      'alt' => t('Alt'),
      'title' => t('Title'),
    ),
    '#empty_option' => t('None'),
    '#default_value' => $config->get('caption_attribute'),
    '#states' => array(
      'visible' => array(
        ':input[name="every_page"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form['manual']['gallery'] = array(
    '#type' => 'checkbox',
    '#title' => t('Gallery'),
    '#description' => t("Display images in a gallery."),
    '#default_value' => $config->get('gallery'),
    '#states' => array(
      'visible' => array(
        ':input[name="every_page"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['#config'] = 'featherlight.settings';
  return system_settings_form($form);
}

