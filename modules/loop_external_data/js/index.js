(function ($) {
  $(document).ready(function() {
    $('.guide--nav-wrapper li li').toggle();

    $('.guide--nav-list-title').on("click", function() {
      $(this).parent().find('li').toggle();
    })

    $('li > .active').parents('li').each(function() {
      $(this).show();
      $(this).siblings().show();
    });
  });
})(jQuery);