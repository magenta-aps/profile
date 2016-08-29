<div class="layout--inner">
  <div class="layout-element-alpha">
    <h1 class="page-title">Opret spørgsmål</h1>
    <p>
      Udfyld formularen for at oprette dit spørgsmål. Husk at brug søgefunktionen først, så du ikke opretter et spørgsmål der allerede er blevet oprettet (og evt. besvaret).
    </p>
    <div class="form-module">
      <form action="ask-question.php">
        <div class="form-item form-type-select">
          <label for="question-categori">Kategori <span class="form-required">*</span></label>
          <select class="form-select" required>
            <option value="">Vælg kategori</option>
            <option value="1">Option 1</option>
            <option value="2">Option 2</option>
            <option value="3">Option 3</option>
          </select>
        </div>
        <div class="form-item form-type-autocomplete-deluxe">
          <label for="question-terms">Nøgleord <span class="form-required">*</span></label>
          <input type="text" size="60" value="" name="field_keyword[und][textfield]" style="" id="autocomplete-deluxe-input" class="autocomplete-deluxe-form form-text jquery-once-1-processed ui-autocomplete-input autocomplete-deluxe-multiple ui-autocomplete-loading" autocomplete="off">
          <div class="description">Indtast nøgleord, systemet kommer automatisk med forslag. Tryk på enter eller knappen for at tilføje.</div>
        </div>
        <div class="form-item form-type-textarea">
          <label for="question-textarea">Spørgsmål <span class="form-required">*</span></label>
          <textarea rows="1" class="form-textarea" id="question-textarea" required></textarea>
          <div class="description">Enter your question or observation.</div>
        </div>
        <div class="form-actions">
          <input type="submit" value="Opret spørgsmål" class="form-submit">
        </div>
      </form>
    </div>
  </div>
</div>
