<?php
/**
 * @file
 * Template to display a view as a table.
 *
 * Available variables:
 * - $title : The title of this group of rows. May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $class: A class or classes to apply to the table, based on settings.
 * - $rows: An array of row items. Each row is an array of content
 * - $totals: An array of calculated totals. Each row contains the total for one
 *   calculation.
 *   keyed by field ID.
 */
if (empty($rows) && empty($totals)) {
  return;
}
?>
<table class="<?php print $class; ?>">
  <?php if (!empty($title)) : ?>
    <caption><?php print $title; ?></caption>
  <?php endif; ?>
  <thead>
    <tr>
      <?php foreach ($header as $field => $label): ?>
        <th class="views-field views-field-<?php print $fields[$field]; ?> <?php print $options['info'][$field]['align'] ?>">
          <?php print $label; ?>
        </th>
      <?php endforeach; ?>
    </tr>
    <?php foreach ($totals as $type => $row): ?>
      <tr class="view-footer-number">
        <?php foreach ($row as $field => $content): ?>
          <td class="view-footer views-field views-field-<?php print $fields[$field]; ?>  <?php print $options['info'][$field]['align'] ?>">
            <?php print $content; ?>
            <?php if ($field == 'title') : ?>
              <?php print '(' . $view->total_rows . ')'; ?>
            <?php endif;?>
          </td>
        <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>
  </thead>
  <tbody>
    <?php foreach ($rows as $count => $row): ?>
      <tr class="<?php print ($count % 2 == 0) ? 'even' : 'odd';?>">
        <?php foreach ($row as $field => $content): ?>
          <td class="views-field views-field-<?php print $fields[$field]; ?>  <?php print $options['info'][$field]['align'] ?>">
            <?php print $content; ?>
          </td>
        <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>
  </tbody>
</table>
