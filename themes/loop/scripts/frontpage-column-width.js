/**
 * To change this template use File | Settings | File Templates.
 */

(function($) {
  // Set class based on number of elements.
  $(document).ready(function () {
    if($('.layout-element-beta').length > 0 && $('.layout-element-gamma').length > 0){
      $('.layout-element-beta').addClass('js-half-width');
      $('.layout-element-gamma').addClass('js-half-width');
    } else {
      $('.layout-element-beta').addClass('js-full-width');
      $('.layout-element-gamma').addClass('js-full-width');
    }
  });

})(jQuery);
