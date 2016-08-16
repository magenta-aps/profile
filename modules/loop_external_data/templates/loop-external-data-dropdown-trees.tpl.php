<li class="guide--nav-list-item has-sublist">
  <h4 class="guide--nav-list-title"><?php print $title; ?></h4>
  <ul class="guide--nav-list-sublist">
    <?php foreach ($childs as $child): ?>
      <?php print render($child); ?>
    <?php endforeach; ?>
  </ul>
</li>
