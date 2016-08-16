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
<?php if (!empty($content['alpha'])): ?>
  <div class="layout-full-width">
    <div class="layout--inner">
      <?php if (!empty($content['alpha'])): ?>
        <div class="layout-element-alpha">
          <?php print $content['alpha']; ?>
        </div>
      <?php endif; ?>
    </div>
  </div>
<?php endif; ?>
