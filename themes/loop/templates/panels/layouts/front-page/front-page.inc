<?php
/**
 * @file
 * Implementation of hook_panels_layouts().
 */

$plugin = array(
  'title' => t('Front page'),
  'category' => t('Loop custom'),
  'icon' => 'front-page.png',
  'theme' => 'front-page',
  'regions' => array(
    'alpha' => t('Alpha'),
    'beta' => t('Beta'),
    'gamma' => t('Gamma'),
    'delta' => t('Delta'),
  ),
);
