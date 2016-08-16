<?php
/**
 * @file
 * My content block for user account.
 *
 * Available variables:
 * - $link
 */
?>
<div class="user-profile--login-text">
  <?php if (!empty($link)) : ?>
    <p class="user-profile--login-link button--action"><?php print $link['content']; ?></p>
    <p><?php print t('If you are an external user without an AZ-ident, use the form below to login.');?></p>
  <?php endif;?>
</div>
