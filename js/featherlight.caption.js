/**
 * @file
 * Enable captions in Featherlight lightboxes.
 */

(function($) {

Backdrop.behaviors.featherlightCaption = {
  attach: function(context, settings) {

    $.featherlight.prototype.afterContent = function() {
      var caption = this.$currentTarget.find('img').attr(settings.featherlight.caption);
      this.$instance.find('.featherlight-caption').remove();
      $('<div class="featherlight-caption">').text(caption).appendTo(this.$instance.find('.featherlight-content'));
    };

  }
};

})(jQuery);

