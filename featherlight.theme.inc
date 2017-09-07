<?php
/**
 * @file
 * Theme functions for the Featherlight module.
 */

/**
 * Returns HTML for a Featherlight lightbox.
 *
 * @param array $variables
 *   An associative array containing:
 *   - item: An array of image data.
 *   - content_image_style: The image style to use for the content image.
 *   - lightbox_image_style: The image style to use for the lightbox image.
 *   - caption_attribute: The image attribute to use for the lightbox caption.
 *   - gallery: Whether or not multiple images should be displayed in a gallery.
 *
 * @ingroup themeable
 */
function theme_featherlight($variables = array()) {
  $item = $variables['item'];

  // Add Featherlight library files.
  backdrop_add_library('featherlight', 'featherlight', TRUE);
  if ($variables['gallery'] == TRUE) {
    backdrop_add_library('featherlight', 'featherlight-gallery', TRUE);
  }
  backdrop_add_js(backdrop_get_path('module', 'featherlight') . '/js/featherlight.js');

  // Add Featherlight settings.
  // Global.
  $config = config_get('featherlight.settings');
  backdrop_add_js(array('featherlight' => $config), 'setting');
  // File-specific.
  backdrop_add_js(array('featherlight' => array(
    'files' => array(
      'id-' . $item['fid'] => $variables['caption_attribute'],
    ),
  )), 'setting');

  // Generate content image.
  $image_variables = array(
    'uri' => $item['uri'],
    'width' => $item['width'],
    'height' => $item['height'],
    'alt' => $item['alt'],
    'title' => $item['title'],
    'attributes' => array(
      'data-file-id' => $item['fid'],
    ),
  );
  if (!empty($variables['content_image_style'])) {
    $image_variables['style_name'] = $variables['content_image_style'];
    $image = theme('image_style', $image_variables);
  }
  else {
    $image = theme('image', $image_variables);
  }

  // Generate lightbox image URL.
  if (!empty($variables['lightbox_image_style'])) {
    $url = image_style_url($variables['lightbox_image_style'], $item['uri']);
  }
  else {
    $url = file_create_url($item['uri']);
  }

  // Generate link options.
  $options = array(
    'attributes' => array(
      'class' => array('featherlight-lightbox'),
    ),
    'html' => TRUE,
  );

  return l($image, $url, $options);
}

