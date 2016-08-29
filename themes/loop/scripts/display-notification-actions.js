/**
 *
 * Display notification action
 *
 */

(function($) {
  function display_notification_actions() {
    // Attach click function.
    $(".js-user-profile-notification-select").click(function(){
      var form = $(this).parents("form").first();
      var actions = form.find('.js-user-profile-notification-actions');
      // Show actions.
      //$('.js-user-profile-notification-actions').show();
      actions.addClass('anim-open-notification-tab');
      actions.removeClass('anim-close-notification-tab');

      // Count the number of boxes checked.
      var boxes_checked = 0;
      form.find('.js-user-profile-notification-select:checked').each(function () {
        boxes_checked++;
      });

      // If no boxes are checked, hide the actions.
      if (boxes_checked === 0) {
        actions.addClass('anim-close-notification-tab');
        actions.removeClass('anim-open-notification-tab');
        //actions.hide();
      }
    });
  }

  function clear_selections() {
    // Attach click function.
    $(".js-user-profile--notification-clear-all").click(function(){
      var form = $(this).parents("form").first();
      var actions = form.find('.js-user-profile-notification-actions');
      // Deselect all checkboxes.
      form.find('.js-user-profile-notification-select').attr('checked', false);

      // Hide actions.
      actions.addClass('anim-close-notification-tab');
      actions.removeClass('anim-open-notification-tab');
      //actions.hide();
    });
  }

  // Start the show.
  $(document).ready(function () {
    display_notification_actions();
    clear_selections();
  });
})(jQuery);
