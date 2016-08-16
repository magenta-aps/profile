<?php
/**
 * @file
 * Implementation of hook_panels_layouts().
 */

$plugin = array(
  'title' => t('Full width'),
  'category' => t('Loop custom'),
  'icon' => 'full-width.png',
  'theme' => 'full-width',
  'regions' => array(
    'alpha' => t('Alpha'),
  ),
);
