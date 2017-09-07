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
    '#description' => t("The duration (in 'ms') of the opening animation. Default is 250."),
    '#default_value' => $config->get('openspeed'),
    '#min' => 1,
  );
  $form['closespeed'] = array(
    '#type' => 'number',
    '#title' => t('Close speed'),
    '#description' => t("The duration (in 'ms') of the closing animation. Default is 250."),
    '#default_value' => $config->get('closespeed'),
    '#min' => 1,
  );
  // Disabled, as 'anywhere' doesn't work with galleries.
  // @see: https://github.com/noelboss/featherlight/issues/324
  // $form['closeonclick'] = array(
  //   '#type' => 'select',
  //   '#title' => t('Close on click'),
  //   '#description' => t("Close the lightbox when clicking this. Default is Background."),
  //   '#options' => array(
  //     FALSE => t('Disabled'),
  //     'background' => t('Background'),
  //     'anywhere' => t('Anything'),
  //   ),
  //   '#default_value' => $config->get('closeonclick'),
  // );
  $form['closeonclick'] = array(
    '#type' => 'checkbox',
    '#title' => t('Close on background'),
    '#description' => t("Close the lightbox when clicking on the background. Default is true."),
    '#default_value' => $config->get('closeonclick'),
    '#return_value' => 'background',
  );
  $form['closeonesc'] = array(
    '#type' => 'checkbox',
    '#title' => t('Close on ESC'),
    '#description' => t("Close the lightbox when pressing the ESC key. Default is true."),
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
  $form['loading'] = array(
    '#type' => 'textfield',
    '#title' => t('Loading'),
    '#description' => t("Content to show while the lightbox is loading (like a spinner). Default is empty."),
    '#default_value' => $config->get('loading'),
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

