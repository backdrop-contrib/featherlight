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
      if (captionAttr) {
        caption = img.attr(captionAttr);

        if (caption) {
          this.$instance.find('.featherlight-caption').remove();
          $('<div class="featherlight-caption">').text(caption).appendTo(this.$instance.find('.featherlight-content'));
        }
      }
    };

  }
};

})(jQuery);

