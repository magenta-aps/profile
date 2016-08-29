/**
 *
 * Update new notifications.
 *
 * Javascript used to update the new notifications number when a message changes status to read.
 *
 */

(function($) {

  // Toggle mobile navigation.
  function change_new_message_count() {
    // Attach click function.
    $('.js-notification-count').on("click", ".js-message--flag", function() {
      var message_count = $('.js-user-message-count').data("new-message-count") - 1;
      $('.js-notification-tab-count').text(message_count);
    });
  }

  // Start the show.
  $(document).ready(function () {
    change_new_message_count();
  });

})(jQuery);
