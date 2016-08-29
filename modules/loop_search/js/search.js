/**
 * @file
 * Auto complete attachment for search in Drupal.
 */

var LoopSearch = LoopSearch || [];
jQuery(document).ready(function($) {
  "use strict";

  var loopQuestions = new Bloodhound({
    datumTokenizer: function(d) {
      // Tokenize by splitting whitespace.
      return Bloodhound.tokenizers.whitespace(d.value);
    },
    queryTokenizer: Bloodhound.tokenizers.whitespace,
    remote: {
      url: '/loop_search/post/%QUERY',
      wildcard: '%QUERY'
    },
    prefetch:  {
      // URL to fetch.
      url: '/loop_search_nodes',
      // TTL 30 sec.
      ttl: 30000
    },
    // Detect duplicates in local and remote matches.
    dupDetector: function(remoteMatch, localMatch) {
      return remoteMatch.id === localMatch.id;
    }
  });
  loopQuestions.initialize();

  var questions = {
    // Pick source.
    source:  loopQuestions.ttAdapter(),
    // Display field.
    displayKey: 'title',
    // HTML template for output.
    templates: {
      header: '<h3 class=\"tt-suggestion-header\">' + Drupal.t('Questions') + '</h3>',
      suggestion: Handlebars.compile('{{title}}')
    }
  };
  LoopSearch.push(questions);
});
