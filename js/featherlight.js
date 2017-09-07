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
      var img = this.$currentTarget.find('img');
      var key = 'id-' + img.attr('data-file-id');
      var imgSettings = settings.featherlight[key];
      if (imgSettings.captionEnabled) {
        var caption = img.attr(imgSettings.captionAttr);
        this.$instance.find('.featherlight-caption').remove();
        $('<div class="featherlight-caption">').text(caption).appendTo(this.$instance.find('.featherlight-content'));
      }
    };

  }
};

})(jQuery);

