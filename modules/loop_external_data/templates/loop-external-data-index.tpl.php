<ul>
  <?php foreach ($forest['#childs'] as $tree): ?>
    <li>
      <?php print render($tree); ?>
    </li>
  <?php endforeach; ?>
</ul>
