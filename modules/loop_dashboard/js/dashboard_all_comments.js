/**
 * @file
 * Containing class for the functionality of the filter.
 */
(function ($) {
  "use strict";

  var dc = {
    comments: [],
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
      if (dc.filter.sorting === 'newest') {
        return ((a.ts < b.ts) ? 1 : ((a.ts > b.ts) ? -1 : 0));
      }
      else if (dc.filter.sorting === 'oldest') {
        return ((a.ts < b.ts) ? -1 : ((a.ts > b.ts) ? 1 : 0));
      }
      else if (dc.filter.sorting === 'alphabetic') {
        a = a.subject.toLowerCase();
        b = b.subject.toLowerCase();
        return ((a < b) ? -1 : ((a > b) ? 1 : 0));
      }
    },

    /**
     * Function to call every time the display list should be updated.
     */
    updateList: function() {
      dc.display = [];

      // Sort according to filter.
      dc.comments.sort(dc.sortByFilter);

      // Get 5 elements according to
      $.each(dc.comments, function(index, obj) {
        if (obj.subject.toLowerCase().indexOf(dc.filter.title.toLowerCase()) >= 0) {
          dc.display.push(obj);
        }
      });

      $(".js-dashboard-comments").html("");
      $.each(dc.display, function(index, obj) {
        $(".js-dashboard-comments").append(dc.template(obj));
      });
    }
  };


  $(document).ready(function($) {
    // Load the template for each entry.
    dc.template = Handlebars.compile(
      $("#js-list-item-template-comments").html()
    );

    // Load the data from the backend.
    $.get("/loop_dashboard_search_comments", function(data) {
      dc.comments = data;
      dc.updateList();
    });

    // Register event listeners for filters.
    $('.js-comments-sort-newest').on('click', function(event) {
      event.preventDefault();
      if (!dc.filter.sorting !== 'newest') {
        $('.js-comments-sort-filter').removeClass('is-active');
        $('.js-comments-sort-newest').addClass('is-active');

        dc.filter.sorting = 'newest';
        dc.updateList();
      }
    });
    $('.js-comments-sort-oldest').on('click', function(event) {
      event.preventDefault();
      if (dc.filter.sorting !== 'oldest') {
        $('.js-comments-sort-filter').removeClass('is-active');
        $('.js-comments-sort-oldest').addClass('is-active');

        dc.filter.sorting = 'oldest';
        dc.updateList();
      }
    });
    $('.js-comments-sort-alphabetic').on('click', function(event) {
      event.preventDefault();
      if (!dc.filter.sorting !== 'alphabetic') {
        $('.js-comments-sort-filter').removeClass('is-active');
        $('.js-comments-sort-alphabetic').addClass('is-active');

        dc.filter.sorting = 'alphabetic';
        dc.updateList();
      }
    });
    $('.js-comments-text-filter').on('keyup', function(event) {
      event.preventDefault();
      dc.filter.title = $(this).val();
      dc.updateList();
    });
  });
})(jQuery);
