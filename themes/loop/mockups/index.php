<?php
$path_to_theme = "/profiles/loop/themes/loop/";
?>
<?php include 'inc/head.inc'; ?>
<title>Loop frontpage</title>
</head>

<body>
<div class="page-wrapper js-page-wrapper">
  <div class="page-inner">
    <?php include 'inc/header.inc'; ?>
    <?php $is_front = TRUE; ?>
    <?php include 'inc/search-block.inc'; ?>
    <?php include('inc/page-frontpage.inc') ?>
  </div>
</div>
</body>
</html>
