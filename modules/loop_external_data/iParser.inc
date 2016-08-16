<?php
/**
 * @file
 * A part of the loop_external_data module.
 */

/**
 * Interface iParser
 *
 * Specifies the functions a Parser must contain.
 */
interface ParserInterface {
  /**
   * Identifies whether a directory matches the format of the parser.
   *
   * @param string $path_to_directory
   *   Path to the directory.
   *
   * @return bool
   *   True if directory identified, false otherwise.
   */
  public function identifyFormat($path_to_directory);

  /**
   * Processes the directory.
   *
   * @param string $path_to_directory
   *   Path to the directory to import.
   * @param int $index_node_id
   *   The nid of the Index node in Drupal.
   */
  public function process($path_to_directory, $index_node_id);
}