<?php
/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>
<div class="<?php print $classes; ?>">
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <?php print $title; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($header): ?>
    <legend class="fieldset-legend">
      <?php print $header; ?>
    </legend>
  <?php endif; ?>

  <?php if ($exposed): ?>
    <div class="dashboard-list--filter">
      <?php print $exposed; ?>
      <div class="dashboard--comment-filters">
        <label class="dashboard--filter-label"><?php print t('Show only');?></label>
        <div class="dashboard--filter-links">
          <?php print l(t('Unanswered questions'), '#', array(
            'external' => TRUE,
            'attributes' => array(
              'class' => array(
                'dashboard--filter-link',
                'js-dashboard-answers-hide',
                'is-active',
              ),
            ),
          ));?>
          <?php print l(t('Answered questions'), '#', array(
            'external' => TRUE,
            'attributes' => array(
              'class' => array(
                'dashboard--filter-link',
                'js-dashboard-answers-show',
              ),
            ),
          ));?>
        </div>
      </div>
      <div class="dashboard--sorting">
        <label class="dashboard--filter-label"><?php print t('Sort by');?></label>
        <div class="dashboard--sort-links">
          <?php print l(t('Newest'), '#', array(
            'external' => TRUE,
            'attributes' => array(
              'class' => array(
                'dashboard--sort-link',
                'is-active',
                'js-sort-link',
              ),
            ),
          ));?>
          <?php print l(t('Oldest'), '#', array(
            'external' => TRUE,
            'attributes' => array(
              'class' => array(
                'dashboard--sort-link',
                'js-sort-link',
              ),
            ),
          ));?>
          <?php print l(t('Alphabetical'), '#', array(
            'external' => TRUE,
            'attributes' => array(
              'class' => array(
                'dashboard--sort-link',
                'js-sort-link',
                'js-dashboard-alphabetical',
              ),
            ),
          ));?>
          <?php print l(t('Number of answers'), '#', array(
            'external' => TRUE,
            'attributes' => array(
              'class' => array(
                'dashboard--sort-link',
                'js-dashboard-answers',
              ),
            ),
          ));?>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <?php if ($attachment_before): ?>
    <div class="attachment attachment-before">
      <?php print $attachment_before; ?>
    </div>
  <?php endif; ?>
  <div class="dashboard-list">
    <?php if ($rows): ?>
      <?php print $rows; ?>
    <?php elseif ($empty): ?>
      <div class="view-empty">
        <?php print $empty; ?>
      </div>
    <?php endif; ?>
  </div>

  <?php if ($pager): ?>
    <?php print $pager; ?>
  <?php endif; ?>

  <?php if ($attachment_after): ?>
    <div class="attachment attachment-after">
      <?php print $attachment_after; ?>
    </div>
  <?php endif; ?>

  <?php if ($more): ?>
    <div class="dashboard-list--more-link">
      <?php print $more; ?>
    </div>
  <?php endif; ?>

  <?php if ($footer): ?>
    <div class="view-footer">
      <?php print $footer; ?>
    </div>
  <?php endif; ?>

  <?php if ($feed_icon): ?>
    <div class="feed-icon">
      <?php print $feed_icon; ?>
    </div>
  <?php endif; ?>
</div>
