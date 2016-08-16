<?php

/**
 * @file
 * Theme implementation of user profile data.
 *
 * This template is used when viewing a registered member's profile page,
 * e.g., example.com/user/123. 123 being the users ID.
 *
 * Use render($user_profile) to print all profile items, or print a subset
 * such as render($user_profile['user_picture']). Always call
 * render($user_profile) at the end in order to print all remaining items. If
 * the item is a category, it will contain all its profile items. By default,
 * $user_profile['summary'] is provided, which contains data on the user's
 * history. Other data can be included by modules. $user_profile['user_picture']
 * is available for showing the account picture.
 *
 * Available variables:
 *   - $user_profile: An array of profile items. Use render() to print them.
 *   - Field variables: for each field instance attached to the user a
 *     corresponding variable is defined; e.g., $account->field_example has a
 *     variable $field_example defined. When needing to access a field's raw
 *     values, developers/themers are strongly encouraged to use these
 *     variables. Otherwise they will have to explicitly specify the desired
 *     field language, e.g. $account->field_example['en'], thus overriding any
 *     language negotiation rule that was previously applied.
 *
 * @see user-profile-category.tpl.php
 *   Where the html is handled for the group.
 * @see user-profile-item.tpl.php
 *   Where the html is handled for each item in the group.
 * @see template_preprocess_user_profile()
 *
 * @ingroup themeable
 */
?>
<h1>
  <?php if(!empty($full_name)) : ?>
    <?php print $full_name; ?>
  <?php else : ?>
    <?php print $elements['#account']->name; ?>
  <?php endif; ?>
  <?php if ($user->uid == $elements['#account']->uid || user_access('administer users')) : ?>
    <span class="user-profile-module--edit-link">(<a href="/user/<?php print $elements['#account']->uid;?>/edit"><?php print t('Edit'); ?></a>)</span>
  <?php endif; ?>
</h1>
<fieldset class="user-profile-module--field-group-fieldset-personal-info">
  <legend class="fieldset-legend"><?php print t('Personal information'); ?></legend>
  <div class="user-profile-module--personal-info-text">
    <div class="user-profile-module--field-personal-info">
      <span class="user-profile-module--field-label"><?php print t('First name') . ':'; ?></span><span class="user-profile-module--field-value"><?php print render($elements['field_first_name']);?></span>
    </div>
    <div class="user-profile-module--field-personal-info">
      <span class="user-profile-module--field-label"><?php print t('Surname') . ':'; ?></span><span class="user-profile-module--field-value"><?php print render($elements['field_last_name']);?></span>
    </div>
    <div class="user-profile-module--field-personal-info">
      <span class="user-profile-module--field-label"><?php print t('E-mail') . ':'; ?></span><span class="user-profile-module--field-value"><?php print ' ' . render($elements['#account']->mail);?></span>
    </div>
    <div class="user-profile-module--field-personal-info">
      <span class="user-profile-module--field-label"><?php print t('Phone') . ':'; ?></span><span class="user-profile-module--field-value"><?php print render($elements['field_phone_number']);?></span>
    </div>
  </div>
  <div class="user-profile-module--personal-info-image">
    <?php print render($elements['field_user_image']); ?>
    <?php print render($loop_user_best_answers['content']); ?>
  </div>
</fieldset>
<?php hide($user_profile['mimemail']); ?>
<?php hide($user_profile['group_personal_information']); ?>
<?php hide($user_profile['field_user_image']); ?>
<?php hide($user_profile['message_subscribe_email']); ?>
<?php hide($user_profile['field_phone_number']); ?>
<?php print render($user_profile); ?>
