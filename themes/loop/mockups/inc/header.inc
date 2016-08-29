<nav class="nav-mobile js-mobile-nav">
  <a href="#" title="" class="first leaf nav-mobile--link active">
    <span class="nav-mobile--text">Example menu item</span>
  </a>
  <a href="#" title="" class="last leaf nav-mobile--link active">
    <span class="nav-mobile--text">Another example menu item</span>
  </a>
</nav>
<header class="header" role="banner">
  <div class="header--inner">
    <a href="/" class="logo--link"><img src="<?php echo $path_to_theme; ?>/logo.png" alt="" class="logo--image"></a>
    <div class="nav--wrapper">
      <nav class="nav">
        <a href="#" title="" class="first leaf nav--link">
          <img class="nav--icon" src="<?php echo $path_to_theme; ?>images/nav-user-icon.png">
          <span class="nav--text">My account</span>
        </a>
        <a href="#" title="" class="leaf nav--link">
          <img class="nav--icon" src="<?php echo $path_to_theme; ?>images/nav-mail-icon.png">
          <span class="nav--text">Messages</span>
        </a>
        <a href="#" title="" class="leaf nav--link">
          <img class="nav--icon" src="<?php echo $path_to_theme; ?>images/nav-add-icon.png">
          <span class="nav--text">Create post</span>
        </a>
        <a href="#" title="" class="last leaf nav--toggle-mobile-nav js-toggle-mobile-nav nolink">
          <img class="nav--icon" src="<?php echo $path_to_theme; ?>images/nav-menu-icon.png">
          <span class="nav--text">Menu</span>
        </a>
      </nav>
      <nav class="nav-dropdown">
        <div class="nav-dropdown--wrapper">
          <a href="#" title="" class="nav-dropdown--header">
            Menu
            <img class="nav-dropdown--icon" src="<?php echo $path_to_theme; ?>images/nav-arrow-down-icon.png">
          </a>
          <div class="nav-dropdown--item">
            <a href="#" title="" class="nav-dropdown--link">Min konto</a>
            <a href="#" title="" class="nav-dropdown--link">Notifikationer</a>
            <a href="#" title="" class="nav-dropdown--link">Opret spørgsmål</a>
            <a href="#" title="" class="nav-dropdown--link">Log af</a>
          </div>
        </div>
        <div class="nav-dropdown--wrapper">
          <a href="#" title="" class="nav-dropdown--header">
            Something else
            <img class="nav-dropdown--icon" src="<?php echo $path_to_theme; ?>images/nav-arrow-down-icon.png">
          </a>
          <div class="nav-dropdown--item">
            <a href="#" title="" class="nav-dropdown--link">First link</a>
            <a href="#" title="" class="nav-dropdown--link">Another link</a>
            <a href="#" title="" class="nav-dropdown--link">Last link</a>
          </div>
        </div>
      </nav>
    </div>
  </div>
</header>
