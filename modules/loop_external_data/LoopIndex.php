<?php
/**
 * @file
 * A part of the loop_external_data module.
 */

class LoopIndex {
  protected $children;
  protected $references;

  /**
   * Constructor.
   *
   * @param array $children
   *   Array of children.
   * @param array $references
   *   Array of references.
   */
  public function __construct($children, $references) {
    $this->children = $children;
    $this->references = $references;
  }

  /**
   * Get the children of the index.
   *
   * @return array
   *   Array of children.
   */
  public function getChildren() {
    return $this->children;
  }

  /**
   * Get the references of the index.
   *
   * @return array
   *   Array of references.
   */
  public function getReferences() {
    return $this->references;
  }
}
