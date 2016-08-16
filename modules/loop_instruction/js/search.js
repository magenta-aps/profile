var LoopSearch = LoopSearch || [];
jQuery(document).ready(function($) {

  var loopInstruction = new Bloodhound({
    datumTokenizer: function(d) {
      // Tokenize by splitting whitespace.
      return Bloodhound.tokenizers.whitespace(d.value);
    },
    queryTokenizer: Bloodhound.tokenizers.whitespace,
    remote: {
      url: '/loop_search/instruction/%QUERY',
      wildcard: '%QUERY'
    },
    prefetch:  {
      // URL to fetch.
      url: '/loop_instruction',
      // TTL 30 sec.
      ttl: 30000
    },
    dupDetector: function(remoteMatch, localMatch) {
        return remoteMatch.id === localMatch.id;
    }
  });
  loopInstruction.initialize();

  var documents = {
    // Pick source.
    source:  loopInstruction.ttAdapter(),
    // Display field.
    displayKey: 'title',
    // HTML template for output.
    templates: {
      header: '<h3 class=\"tt-suggestion-header\">' + Drupal.t('Instruction') + '</h3>',
      suggestion: Handlebars.compile('{{title}}')
    }
  };
  LoopSearch.push(documents);
});
