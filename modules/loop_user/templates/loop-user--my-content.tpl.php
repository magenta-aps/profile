<?php

/**
 * @file loop-user-my-content.tpl.php
 * My content block for user account
 *
 * Available variables:
 * - $user
 * - $profile
 *
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
