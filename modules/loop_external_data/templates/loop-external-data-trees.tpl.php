<ul>
  <li>
    <?php print $title; ?>
    <ul>
      <?php foreach ($childs as $child): ?>
        <li>
          <?php print render($child); ?>
        </li>
      <?php endforeach; ?>
    </ul>
  </li>
</ul>
