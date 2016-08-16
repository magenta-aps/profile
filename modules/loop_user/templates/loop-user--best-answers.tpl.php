<?php
/**
 * @file loop-user-best-answers.tpl.php
 * Best answers block for user account
 *
 * Available variables:
 * - $answers_count
 * - $best_answers_count
 *
 */
?>
<div class="user-profile--user-answers">
  <div class="user-profile--answers">
    <div class="user-profile--answers-inner">
      <label class="user-profile--answers-label"><?php print t('Answers'); ?></label>
      <div class="user-profile--answers-count" href=""><?php print $answers_count; ?></div>
    </div>

  </div>
  <div class="user-profile--best-answers">
    <div class="user-profile--answers-inner">
      <label class="user-profile--answers-label"><?php print t('Top answers'); ?></label>
      <div class="user-profile--answers-best-count" href=""><?php print $top_answers_count; ?></div>
    </div>
  </div>
</div>