<?php

/**
 * @file
 * Default theme implementation for comments.
 *
 * Available variables:
 * - $author: Comment author. Can be link or plain text.
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $created: Formatted date and time for when the comment was created.
 *   Preprocess functions can reformat it by calling format_date() with the
 *   desired parameters on the $comment->created variable.
 * - $changed: Formatted date and time for when the comment was last changed.
 *   Preprocess functions can reformat it by calling format_date() with the
 *   desired parameters on the $comment->changed variable.
 * - $new: New comment marker.
 * - $permalink: Comment permalink.
 * - $submitted: Submission information created from $author and $created during
 *   template_preprocess_comment().
 * - $picture: Authors picture.
 * - $signature: Authors signature.
 * - $status: Comment status. Possible values are:
 *   comment-unpublished, comment-published or comment-preview.
 * - $title: Linked title.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - comment: The current template type, i.e., "theming hook".
 *   - comment-by-anonymous: Comment by an unregistered user.
 *   - comment-by-node-author: Comment by the author of the parent node.
 *   - comment-preview: When previewing a new or edited comment.
 *   The following applies only to viewers who are registered users:
 *   - comment-unpublished: An unpublished comment visible only to administrators.
 *   - comment-by-viewer: Comment by the user currently viewing the page.
 *   - comment-new: New comment since last the visit.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * These two variables are provided for context:
 * - $comment: Full comment object.
 * - $node: Node object the comments are attached to.
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_comment()
 * @see template_process()
 * @see theme_comment()
 *
 * @ingroup themeable
 */
?>
<div class="meta-data--author">
<?php if (isset($picture)): ?>
  <div class="meta-data--author-image">
    <a href="/user/<?php print $comment->uid;?>"><?php print $comment_author_image; ?></a>
  </div>
<?php endif ?>
  <div class="meta-data--author-wrapper">
    <?php if (isset($node->name) && isset($node->uid)): ?>
      <span class="meta-data--author-link"><?php print l($comment_author_name, 'user/' . $comment->account->uid); ?></span>
    <?php endif ?>
    <span class="meta-data--author-title"><?php print render($job_title); ?><?php if (isset($place)): ?>, <?php print render($place); ?><?php endif ?></span>
  </div>
</div>
<?php if (!empty($files)): ?>
  <div class="comments--files">
    <div class="comments--files-label"><?php print t('Files');?>:</div>
    <div class="comments--files-content">
      <?php foreach ($files as $file) : ?>
        <div class="question--file">
          <a href="<?php print file_create_url($file['uri']);?>" target="_blank">
            <span class="comments--icon comments--icon-<?php print str_replace('/', '-', $file['filemime']); ?>"></span>
            <span class="comments--file-name"><?php print truncate_utf8($file['filename'], 20, FALSE, TRUE); ?></span>
          </a>
        </div>
      <?php endforeach; ?>
    </div>
  </div>
<?php endif; ?>
<span class="comments--comment-meta-data">
  <span class="comments--comment-meta-data-date">
    <?php print t('Submitted') . ' ' . format_date($comment->created, $type = 'medium'); ?>
    <?php if ($comment->uid == $user->uid) : ?>
      - (<?php print l(t('edit comment'), 'comment/' . $comment->cid . '/edit'); ?>)
    <?php endif; ?>
  </span>
</span>
<div class="comments--comment-content">
  <?php print render($comment_body); ?>
</div>
<div class="comments--abuse">
  <?php print render($content['links']); ?>
</div>
<?php if (user_access('administer comments')) : ?>
  <div class="comments--editor-actions">
    <div class="comments--editor-actions-delete">
      <a href="/comment/<?php print $comment->cid; ?>/delete"><?php print t('Delete comment');?></a>
    </div>
    <div class="comments--editor-actions-edit">
      <a href="/comment/<?php print $comment->cid; ?>/edit"><?php print t('Edit comment');?></a>
    </div>
  </div>
<?php endif; ?>
