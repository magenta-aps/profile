<?php
/**
 * @file
 * Default dashboard template.
 */
?>
<div class="dashboard--content-overview">
  <div class="dashboard--content-overview-inner">
    <p class="dashboard--content-overview-text"><span><?php print $post_count; ?></span> <?php print t('new questions in the periode'); ?></p>
    <p class="dashboard--content-overview-text"><span><?php print $comment_count; ?></span> <?php print t('new answers in the periode'); ?></p>
  </div>
</div>
