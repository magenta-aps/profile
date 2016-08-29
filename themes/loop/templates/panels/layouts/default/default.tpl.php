<?php
/**
 * @file
 * Template for a 3 column panel layout.
 *
 * This template provides a very simple "one column" panel display layout.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   $content['middle']: The only panel in the layout.
 */
?>
<?php if (!empty($content['alpha']) || !empty($content['beta']) || !empty($content['gamma'])): ?>
  <div class="layout-default">
    <div class="layout--inner">
      <?php if (!empty($content['alpha'])): ?>
        <div class="layout-element-alpha">
          <?php print $content['alpha']; ?>
        </div>
      <?php endif; ?>
      <?php if (!empty($content['beta'])): ?>
        <div class="layout-element-beta">
          <?php print $content['beta']; ?>
        </div>
      <?php endif; ?>
    </div>
    <?php if (!empty($content['gamma'])): ?>
      <div class="layout--inner">
        <div class="layout-element-gamma">
          <?php print $content['gamma']; ?>
        </div>
      </div>
    <?php endif; ?>
  </div>
<?php endif; ?>
