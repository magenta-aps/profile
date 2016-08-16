<?php

/**
 * @file loop-dashboard--other-content.tpl.php
 * Displays other content list for dashboard.
 */
?>
<div class="dashboard-list">
  <h2><?php print t('Content') ?></h2>
  <div class="dashboard-list--filter">
    <form class="dashboard-list--form jquery-once-1-processed" action="/editor/dashboard/content" method="get" id="views-exposed-form-loop-editor-content-panel-pane-1" accept-charset="UTF-8">
      <div class="views-exposed-widgets">
        <input placeholder="<?php print t('Type parts of title or content to filter the list');?>" class="dashboard-list--filter-field form-text js-other-text-filter" type="text" id="edit-combine" name="combine" value="" size="30" maxlength="128">
      </div>
      <div>
        <input class="dashboard-list--submit form-submit" type="submit" id="edit-submit-loop-editor-content" name="" value="Udfør">
      </div>
    </form>
    <div class="dashboard--sorting">
      <label class="dashboard--filter-label"><?php print t('Sort by');?></label>
      <div class="dashboard--sort-links">
        <a href="#" class="js-has-answers-removed dashboard--sort-link js-other-sort-filter js-other-sort-newest is-active"><?php print t('Newest');?></a>
        <a href="#" class="js-has-answers-removed dashboard--sort-link js-other-sort-filter js-other-sort-oldest "><?php print t('Oldest');?></a>
        <a href="#" class="js-has-answers-removed dashboard--sort-link js-other-sort-filter js-other-sort-alphabetic is-last">
          <span class="dashboard--alphabetical-link-short"><?php print t('A-Z');?></span>
          <span class="dashboard--alphabetical-link-long"><?php print t('Alphabetical');?></span>
        </a>
      </div>
    </div>
  </div>

  <div class="dashboard-list js-dashboard-other">
    <div class="dashboard--spinner">
    </div>
  </div>

  <div class="dashboard-list--more-link">
    <a href="/editor/dashboard/other_content"><?php print t('show all content');?></a>
  </div>
</div>


<?php
// This is used to enrich the above results.
?>
<script id="js-list-item-template-other" type="text/x-handlebars-template">
  <div class="dashboard-list--item">
    <a href="/node/{{nid}}/edit" class="dashboard-list--icon"> </a>
    <p class="dashboard-list--text">
      <a href="/node/{{nid}}">{{title}}</a>
    </p>
    <span class="dashboard-list--meta-data">
    <?php print t('Content, created');?> {{date}} - {{full_name}}
    </span>
  </div>
</script>
