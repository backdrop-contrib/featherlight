/**
 * @file
 * Enable captions in Featherlight lightboxes.
 */

(function($) {

Backdrop.behaviors.featherlightCaption = {
  attach: function(context, settings) {

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

