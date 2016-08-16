<?php
/**
 * @file
 * A part of the loop_external_data module.
 */

/**
 * Class LoopNode
 *
 * Represents a node of external data.
 */
class LoopNode {
  protected $title;

  /**
   * Constructor.
   *
   * @param string $title
   *   The title of the node.
   */
  public function __construct($title) {
    $this->title = $title;
  }

  /**
   * Get the title of the node.
   *
   * @return string
   *   The title of the node.
   */
  public function getTitle() {
    return $this->title;
  }
}
