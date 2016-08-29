<?php

/**
 * @file loop-dashboard--questions.tpl.php
 * Displays questions list for dashboard.
 */
?>
<?php if (!empty($profile)) : ?>
  <?php if ($user->uid == $profile->uid) : ?>
    <?php $title = t('My content'); ?>
    <?php $question_title = t('My questions'); ?>
    <?php $comments_title = t('My comments'); ?>
  <?php else : ?>
    <?php $title = t('Users content'); ?>
    <?php $question_title = t('Questions'); ?>
    <?php $comments_title = t('Comments'); ?>
  <?php endif; ?>
  <aside class="block-my-content">
    <div class="block-module--inner">
      <h2 class="block-module--my-content-header"><?php print $title;?> </h2>
      <ul class="block-module--my-content-list">
        <li class="block-module--my-content-item"><?php echo l($question_title, 'user/' . $profile->uid . '/nodes', array('attributes' => array('class' => array('block-module--link'))));?></li>
        <li class="block-module--my-content-item"><?php echo l($comments_title, 'user/' . $profile->uid . '/user-comments', array('attributes' => array('class' => array('block-module--link'))));?></li>
      </ul>
    </div>
  </aside>
<?php endif; ?>
<div class="dashboard-list">
  <h2><?php print t('Questions') ?></h2>
  <div class="dashboard-list--filter">
    <form class="dashboard-list--form" accept-charset="UTF-8">
      <div class="views-exposed-widgets">
        <input placeholder="<?php print t('Type parts of title or content to filter the list');?>" class="dashboard-list--filter-field form-text js-questions-text-filter" type="text" id="edit-combine" name="combine" value="" size="30" maxlength="128">
      </div>
      <div>
        <input class="dashboard-list--submit form-submit" type="submit" id="edit-submit-loop-editor-content" name="" value="Udfør">
      </div>
    </form>
    <div class="dashboard--comment-filters">
      <label class="dashboard--filter-label"><?php print t('Show only');?></label>
      <div class="dashboard--filter-links">
        <a href="#" class="dashboard--filter-link js-questions-answer-filter js-questions-unanswered is-active">
          <span class="dashboard--show-only-link-short"><?php print t('Unanswered');?></span>
          <span class="dashboard--show-only-link-long"><?php print t('Unanswered questions');?></span>
        </a>
        <a href="#" class="dashboard--filter-link js-questions-answer-filter js-questions-answered">
          <span class="dashboard--show-only-link-short"><?php print t('Answered');?></span>
          <span class="dashboard--show-only-link-long"><?php print t('Answered questions');?></span>
        </a>
      </div>
    </div>
    <div class="dashboard--sorting">
      <label class="dashboard--filter-label"><?php print t('Sort by');?></label>
      <div class="dashboard--sort-links">
        <a href="#" class="js-has-answers-removed dashboard--sort-link js-questions-sort-filter js-questions-sort-newest is-active"><?php print t('Newest');?></a>
        <a href="#" class="js-has-answers-removed dashboard--sort-link js-questions-sort-filter js-questions-sort-oldest"><?php print t('Oldest');?></a>
        <a href="#" class="js-has-answers-removed dashboard--sort-link js-questions-sort-filter js-questions-sort-alphabetic is-last">
          <span class="dashboard--alphabetical-link-short"><?php print t('A-Z');?></span>
          <span class="dashboard--alphabetical-link-long"><?php print t('Alphabetical');?></span>
        </a>
        <a href="#" class="js-has-answers-removed dashboard--sort-link js-questions-sort-filter js-questions-sort-comments is-hidden">
          <span class="dashboard--replies-link-short"><?php print t('Comments');?></span>
          <span class="dashboard--replies-link-long"><?php print t('# answers');?></span>
        </a>
      </div>
    </div>
  </div>

  <div class="dashboard-list js-dashboard-questions">
    <div class="dashboard--spinner">
    </div>
  </div>

  <div class="dashboard-list--more-link">
    <a href="/editor/dashboard/questions"><?php print t('show all questions');?></a>
  </div>
</div>


<?php
// This is used to enrich the above results.
?>
<script id="js-list-item-template-questions" type="text/x-handlebars-template">
  <div class="dashboard-list--item">
    <a href="/node/{{nid}}/edit" class="dashboard-list--icon"> </a>
    <p class="dashboard-list--text">
      <a href="/node/{{nid}}">{{title}}</a> ({{coms}} <?php print ('answers');?>)
    </p>
    <span class="dashboard-list--meta-data">
    <?php print t('Content, created');?> {{date}} - {{full_name}}
    </span>
  </div>
</script>
