/**
 * @file
 * Enable captions in Featherlight lightboxes.
 */

(function($) {

Backdrop.behaviors.featherlightCaption = {
  attach: function(context, settings) {

    $.featherlight.prototype.afterContent = function() {
      var imgData = this.$currentTarget.find('img');
      var fileID = imgData.attr('data-file-id');
      var captionAttr = settings.featherlight['id-' + fileID]['captionAttr'];
      var caption = imgData.attr(captionAttr);
      this.$instance.find('.featherlight-caption').remove();
      $('<div class="featherlight-caption">').text(caption).appendTo(this.$instance.find('.featherlight-content'));
    };

  }
};

})(jQuery);

