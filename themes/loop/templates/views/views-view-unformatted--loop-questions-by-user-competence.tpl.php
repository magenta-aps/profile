<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div class="block-questions--header-wrapper">
  <h3 class="block-questions--header"><?php print t('You are the expert! Can you help?'); ?></h3>
  <?php if (!empty($view->result['0'])): ?>
    <h4 class="block-questions--sub-header"><?php print t('Questions about') . ': '; ?><em><?php print $view->field['field_area_of_expertise']->last_render;?></em></h4>
  <?php endif; ?>
</div>
<?php foreach ($rows as $id => $row): ?>
  <div class="block-questions--item">
    <?php print $row; ?>
  </div>
<?php endforeach; ?>
