<?php
/**
 * @file
 * Default theme implementation for displaying a single search result.
 *
 * This template renders a single search result and is collected into
 * search-api-page-results.tpl.php. This and the parent template are dependent
 * on one another, sharing the markup for definition lists.
 *
 * View mode is set in the Search page settings. If you select
 * "Themed as search results", then this template will be used for theming the
 * individual results. Any other view mode will bypass this template.
 *
 * Available variables:
 * - $index: The search index this search is based on.
 * - $url: URL of the result.
 * - $title: Title of the result.
 * - $snippet: A small preview of the result.
 * - $info: String of all the meta information ready for print. Applies
 *   only if the result is a node.
 * - $info_split: Contains same data as $info, split into a keyed array.
 * - $classes: CSS classes for this list element.
 *
 * Default keys within $info_split:
 * - $info_split['user']: Author of the entity, where an author exists.
 *   Depends on permission.
 * - $info_split['date']: Last update of the entity, if the 'updated'
 *   field exists. Short formatted.
 *
 * Since $info_split is keyed, a direct print of the item is possible.
 * This array applies where the search result is a node, so it is
 * recommended to check for its existence before printing.
 * Where the result is a node, the default keys of 'user' and 'date'
 * will always exist.
 *
 * To check for all available data within $info_split, use the code below.
 * @code
 *   <?php print '<pre>'. check_plain(print_r($info_split, 1)) .'</pre>'; ?>
 * @endcode
 *
 * @see template_preprocess_search_api_page_result()
 */
?>
<?php $url['options']['attributes']['class'] = 'search-result--link';?>
<div class="search-result--item">
  <?php if ($info) : ?>
    <div class="search-result--meta-data">
      <div class="search-result--meta-data-date"><?php print 'Created ' . format_date($item->created, $type = 'medium'); ?></div>
      <div class="search-result--meta-data-type">
        <?php print t('Type'); ?>:
        <?php if($item->type == 'leaf') : ?>
          <?php print t('Guide'); ?>
        <?php elseif ($item->type == 'post') : ?>
          <?php print t('Question'); ?>
        <?php else : ?>
          <?php print t($item->type); ?>
        <?php endif;?>
      </div>
    </div>
  <?php endif; ?>
  <?php print $url ? l($title, $url['path'], $url['options']) : check_plain($title); ?>
  <?php print $url ? l($item->comment_count . ' ' . t('Answers'), $url['path'], array('attributes' => array('class' => array('search-result--comments')))) : check_plain($item->comment_count); ?>
</div>
