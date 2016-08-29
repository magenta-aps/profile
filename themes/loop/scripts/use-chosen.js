/**
 * Created with JetBrains PhpStorm.
 * User: martinydegranath
 * Date: 07/04/14
 * Time: 10.22
 * To change this template use File | Settings | File Templates.
 */

(function($) {
  // Start the show.
  $(document).ready(function () {
    $('.js-chosen-select-area-of-expertise').chosen({
      no_results_text: "Angiv værdi.",
      placeholder_text : "Angiv værdi."
    });

    $('.js-chosen-select-profession').chosen({
      no_results_text: "Angiv værdi.",
      placeholder_text : "Angiv værdi."
    });
  });

})(jQuery);
