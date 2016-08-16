<?php
/**
 * @file
 * Ensures that form comments are prefixes correctly.
 *
 * Available variables:
 *   - $author_image: The rendered author image.
 *   - $user_name: The user first name and second name or drupal username if
 *     none is set.
 *   - $jobtitle: The user job title.
 *   - $place: The user job title.
 */
?>
<h3><?php print t('Your reply'); ?></h3>
<div class="meta-data--author">
  <div class="meta-data--author-image">
    <a href="/user/<?php print $user->uid;?>">
      <?php if ($author_image) :?>
        <?php print $author_image; ?>
      <?php endif;?>
    </a>
  </div>
  <div class="meta-data--author-wrapper">
    <a href="/user/<?php print $user->uid;?>">
      <?php if ($user_name) :?>
        <?php print $user_name; ?>
      <?php endif;?>
    </a>
    <span class="meta-data--author-title">
      <?php if ($jobtitle) :?>
        <?php print $jobtitle; ?>
      <?php endif; ?>
      <?php if ($place) : ?>
        <?php print ', ' . $place; ?>
      <?php endif; ?>
    </span>
  </div>
</div>
