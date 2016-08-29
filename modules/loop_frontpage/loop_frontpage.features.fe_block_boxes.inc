<?php
/**
 * @file
 * loop_frontpage.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function loop_frontpage_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Velkomst til sitet';
  $fe_block_boxes->format = 'html';
  $fe_block_boxes->machine_name = 'welcome';
  $fe_block_boxes->body = 'Velkommen til It-afdelingens vidensdatabase.
Her kan du søge hjælp og vejledning i brugen af en lang række IT-værktøjer. 
Du kan stille spørgsmål og du kan hjælpe andre ved at være med til at besvare de spørgsmål, som bliver stillet på sitet. Gå ind på ”Min konto” og tilføj de emner, som du kan hjælpe andre med under punktet ”kompetencer”.
Vidensdatabasen er hjælp til selvhjælp. Den erstatter ikke IT-support. Så hvis du oplever deciderede IT- fejl skal du henvende dig til hotlinesystemet på <a href="http://medarbejderportal/itvaerktoejer">http://medarbejderportal/itvaerktoejer</a>.';

  $export['welcome'] = $fe_block_boxes;

  return $export;
}
