<?php
/**
 * @file
 * Implementation of hook_panels_layouts().
 */

$plugin = array(
  'title' => t('Default inverted'),
  'category' => t('Loop custom'),
  'icon' => 'default-inverted.png',
  'theme' => 'default-inverted',
  'regions' => array(
    'alpha' => t('Alpha'),
    'beta' => t('Beta'),
  ),
);
