<div class="layout-default">
  <div class="layout--inner">
    <div class="layout-element-alpha">
      <h1 class="page-title">Søgeresultater</h1>
      <div class="search-result">
        <div class="search-result--lead">
          Du søgte på: <strong>Dokumentation</strong>
        </div>
        <?php
        for ($i=1;$i<=10;$i++) {
          echo '
            <div class="search-result--item">
              <span class="meta-data--date">Oprettet den 28. marts 2013</span>
              <a href="question.php" class="search-result--link">Hvordan dokumenteres delvis aktindsigt? Og findes der en vejledning i dokumentation af aktindsigt?</a>
              <a href="#" class="search-result--comments">12 svar</a>
            </div>
                ';
        }
        ?>
      </div>
    </div>
    <div class="layout-element-beta">
      Beta
    </div>
  </div>
</div>
