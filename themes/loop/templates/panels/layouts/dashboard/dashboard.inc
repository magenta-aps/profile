<?php
/**
 * @file
 * Implementation of hook_panels_layouts().
 */

$plugin = array(
  'title' => t('Dashboard'),
  'category' => t('Loop custom'),
  'icon' => 'dashboard.png',
  'theme' => 'dashboard',
  'regions' => array(
    'alpha' => t('Alpha'),
    'beta' => t('Beta'),
    'gamma' => t('Gamma'),
    'delta' => t('Delta'),
  ),
);
