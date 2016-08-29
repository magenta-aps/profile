<?php
$plugin = array(
  'single' => TRUE,  // Just do this one, it is needed.
  'category' => t('Miscellaneous'), // A category to put this under.
  'title' => t('Notify friend'),  // Title to show up on the pane screen.
  'description' => t('Notify a friend of a node, sending that friend a message'), // Description to show up on the pane screen.
  'edit form' => 'loop_friend_notification_pane_custom_pane_edit_form', // A function that will return the settings form for the pane.
  'render callback' => 'loop_friend_notification_pane_custom_pane_render', // A function that will return the renderable content.
  'admin info' => 'loop_friend_notification_pane_custom_pane_admin_info', // A function that will return the information displayed on the admin screen (optional).
  'defaults' => array( // Array of defaults for the settings form.
    'text' => '',
  ),
  'all contexts' => TRUE, // This is NEEDED to be able to use substitution strings in your pane.
);
