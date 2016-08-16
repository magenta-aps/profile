/**
 * @file
 * Used to redirect after logout.
 */
jQuery(function() {
  "use strict";

  setTimeout(function () {
    window.location = '/user';
  }, 5000);
});
