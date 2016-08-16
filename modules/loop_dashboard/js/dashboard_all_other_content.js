/**
 * @file
 * Containing class for the functionality of the filter.
 */
(function ($) {
  "use strict";

  var doc = {
    list: [],
    display: [],
    template: '',
    filter: {
      title: '',
      sorting: 'newest',
      items: 5
    },

    /**
     * Defines the different filters.
     */
    sortByFilter: function(a, b) {
      if (doc.filter.sorting === 'newest') {
        return ((a.ts < b.ts) ? 1 : ((a.ts > b.ts) ? -1 : 0));
      }
      else if (doc.filter.sorting === 'oldest') {
        return ((a.ts < b.ts) ? -1 : ((a.ts > b.ts) ? 1 : 0));
      }
      else if (doc.filter.sorting === 'alphabetic') {
        a = a.title.toLowerCase();
        b = b.title.toLowerCase();
        return ((a < b) ? -1 : ((a > b) ? 1 : 0));
      }
    },

    /**
     * Function to call every time the display list should be updated.
     */
    updateList: function() {
      doc.display = [];

      // Sort according to filter.
      doc.list.sort(doc.sortByFilter);

      // Get 5 elements according to
      $.each(doc.list, function(index, obj) {
        if (obj.title.toLowerCase().indexOf(doc.filter.title.toLowerCase()) >= 0) {
          doc.display.push(obj);
        }
      });

      $(".js-dashboard-other").html("");
      $.each(doc.display, function(index, obj) {
        $(".js-dashboard-other").append(doc.template(obj));
      });
    }
  };


  $(document).ready(function($) {
    // Load the template for each entry.
    doc.template = Handlebars.compile(
      $("#js-list-item-template-other").html()
    );

    // Load the data from the backend.
    $.get("/loop_dashboard_search_other_content", function(data) {
      doc.list = data;
      doc.updateList();
    });

    // Register event listeners for filters.
    $('.js-other-sort-newest').on('click', function(event) {
      event.preventDefault();
      if (!doc.filter.sorting !== 'newest') {
        $('.js-other-sort-filter').removeClass('is-active');
        $('.js-other-sort-newest').addClass('is-active');

        doc.filter.sorting = 'newest';
        doc.updateList();
      }
    });
    $('.js-other-sort-oldest').on('click', function(event) {
      event.preventDefault();
      if (doc.filter.sorting !== 'oldest') {
        $('.js-other-sort-filter').removeClass('is-active');
        $('.js-other-sort-oldest').addClass('is-active');

        doc.filter.sorting = 'oldest';
        doc.updateList();
      }
    });
    $('.js-other-sort-alphabetic').on('click', function(event) {
      event.preventDefault();
      if (!doc.filter.sorting !== 'alphabetic') {
        $('.js-other-sort-filter').removeClass('is-active');
        $('.js-other-sort-alphabetic').addClass('is-active');

        doc.filter.sorting = 'alphabetic';
        doc.updateList();
      }
    });
    $('.js-other-text-filter').on('keyup', function(event) {
      event.preventDefault();
      doc.filter.title = $(this).val();
      doc.updateList();
    });
  });

})(jQuery);
