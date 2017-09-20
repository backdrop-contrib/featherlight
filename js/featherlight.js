/**
 * @file
 * Set Featherlight defaults and add captions.
 */

(function($) {

Backdrop.behaviors.featherlight = {
  attach: function(context, settings) {

    // Set Featherlight options.
    $.featherlight.defaults.openSpeed = Number(settings.featherlight.openspeed);
    $.featherlight.defaults.closeSpeed = Number(settings.featherlight.closespeed);
    $.featherlight.defaults.closeOnClick = settings.featherlight.closeonclick;
    $.featherlight.defaults.closeOnEsc = settings.featherlight.closeonesc;
    $.featherlight.defaults.closeIcon = settings.featherlight.closeicon;
    $.featherlight.defaults.otherClose = settings.featherlight.otherclose;
    $.featherlight.defaults.loading = settings.featherlight.loading;

    // Add caption.
    $.featherlight.prototype.afterContent = function() {
      var caption = false;
      var img = this.$currentTarget.find('img');
      if (img[0].hasAttribute('data-file-id')) {
        var key = 'id-' + img.attr('data-file-id');
        var captionAttr = settings.featherlight.files[key];

        if (typeof captionAttr !== 'undefined') {
          // Caption attribute taken from field formatter settings.
          if (captionAttr) {
            var caption = img.attr(captionAttr);
          }
        }
        else {
          // Caption attribute taken from global settings.
          if (settings.featherlight.caption_attribute) {
            var caption = img.attr(settings.featherlight.caption_attribute);
          }
        }

        if (caption) {
          this.$instance.find('.featherlight-caption').remove();
          $('<div class="featherlight-caption">').text(caption).appendTo(this.$instance.find('.featherlight-content'));
        }
      }
    };

  }
};

})(jQuery);

