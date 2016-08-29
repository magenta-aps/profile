/**
 * @file
 * Listen to ajax completed events and clear out date fields if the reset button
 * was pressed on the admin stats page.
 */
jQuery(document).ajaxComplete(function(event, xhr, settings) {
  "use strict";

  if (settings.extraData._triggering_element_name === 'filter-reset') {
    jQuery.datepicker._clearDate(jQuery('#edit-filter-start-date-datepicker-popup-0'));
    jQuery.datepicker._clearDate(jQuery('#edit-filter-end-date-datepicker-popup-0'));
  }
});
