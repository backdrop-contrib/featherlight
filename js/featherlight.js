/**
 * @file
 * Set Featherlight defaults and add captions.
 */

(function($) {

Backdrop.behaviors.featherlight = {
  attach: function(context, settings) {

    // Set Featherlight options.
    var options = {
      type: 'image',
      openSpeed: Number(settings.featherlight.openspeed),
      closeSpeed: Number(settings.featherlight.closespeed),
      closeOnClick: settings.featherlight.closeonclick,
      closeOnEsc: settings.featherlight.closeonesc,
      closeIcon: settings.featherlight.closeicon,
      otherClose: settings.featherlight.otherclose,
      loading: settings.featherlight.loading,
    };

    // Bind Featherlight to image(s).
    $('a.fl-image').featherlight(options);
    if (typeof $.featherlightGallery === 'function') {
      $('a.fl-gallery').featherlightGallery(options);
    }

    // Add caption.
    $.featherlight.prototype.afterContent = function() {
      var captionAttr = false;
      var caption = false;
      var img = this.$currentTarget.find('img');

      // Get caption attribute.
      if (settings.featherlight.hasOwnProperty('files')) {
        if (typeof img.attr('data-file-id') !== 'undefined') {
          var key = 'id-' + img.attr('data-file-id');
          captionAttr = settings.featherlight.files[key];
        }
      }
      else {
        if (settings.featherlight.caption_attribute) {
          captionAttr = settings.featherlight.caption_attribute;
        }
      }

      // Get and set caption.
      this.$instance.find('.featherlight-caption').remove();
      this.$instance.find('.featherlight-content').css('padding-bottom', '0');
      if (captionAttr) {
        caption = img.attr(captionAttr);

        if (caption) {
          $('<div class="featherlight-caption">').text(caption).appendTo(this.$instance.find('.featherlight-content'));
          var captionHeight = this.$instance.find('.featherlight-caption').height();
          this.$instance.find('.featherlight-content').css('padding-bottom', captionHeight + 'px');
        }
      }
    };

  }
};

})(jQuery);

