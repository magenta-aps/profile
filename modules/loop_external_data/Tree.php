<?php
/**
 * @file
 * A part of the loop_external_data module.
 */

/**
 * Class Tree
 *
 * Represents a tree in external data.
 */
class Tree extends LoopNode {
  protected $children;

  /**
   * Constructor.
   *
   * @param string $title
   *   The title of the Tree.
   * @param array $children
   *   Array of children.
   */
  public function __construct($title, $children) {
    parent::__construct($title);
    $this->children = $children;
  }

  /**
   * Get the children of the tree.
   *
   * @return array
   *   Array of children.
   */
  public function getChildren() {
    return $this->children;
  }
}
