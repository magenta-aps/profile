<?php
$path_to_theme = "/profiles/loop/themes/loop/";
?>
<?php include('inc/head.inc') ?>
<title>Loop - layouts</title>
</head>

<body>

<div class="page-wrapper js-page-wrapper">
  <div class="page-inner">
    <?php include 'inc/header.inc'; ?>
    <?php include('inc/search-block.inc') ?>
    <h1 style="border-bottom: 1px solid gray; margin-right: .5em; margin: 0 0 1em; margin-left: .5em; padding-bottom: .5em; text-align: center;">Frontpage</h1>
    <?php include('inc/page-frontpage.inc') ?>
    <h1 style="border-bottom: 1px solid gray; margin-right: .5em; margin: 1em 0 1em; margin-left: .5em; padding-bottom: .5em; text-align: center;">Dashboard</h1>
    <?php include('inc/page-dashboard.inc') ?>
    <h1 style="border-bottom: 1px solid gray; margin-right: .5em; margin: 1em 0 1em; margin-left: .5em; padding-bottom: .5em; text-align: center;">Ask question</h1>
    <div class="layout-alternative">
      <?php include('inc/page-ask-question.inc') ?>
    </div>
    <h1 style="border-bottom: 1px solid gray; margin-right: .5em; margin: 1em ; margin-left: .5em; padding-bottom: .5em; text-align: center;">Question</h1>
    <?php include('inc/page-question.inc') ?>
    <h1 style="border-bottom: 1px solid gray; margin-right: .5em; margin: 1em 0; margin-left: .5em; padding-bottom: .5em; text-align: center;">Search results</h1>
    <?php include('inc/page-search-result.inc') ?>
    <h1 style="border-bottom: 1px solid gray; margin-right: .5em; margin: 1em 0; margin-left: .5em; padding-bottom: .5em; text-align: center;">No search results</h1>
    <?php include('inc/page-no-search-results.inc') ?>
    <h1 style="border-bottom: 1px solid gray; margin-right: .5em; margin: 1em 0; margin-left: .5em; padding-bottom: .5em; text-align: center;">User profile</h1>
    <?php include('inc/user-profile-logged-in-page.inc') ?>
    <h1 style="border-bottom: 1px solid gray; margin-right: .5em; margin: 1em 0; margin-left: .5em; padding-bottom: .5em; text-align: center;">Edit user profile</h1>
    <?php include('inc/edit-user-profile-page.inc') ?>
  </div>
</div>
</body>
</html>
