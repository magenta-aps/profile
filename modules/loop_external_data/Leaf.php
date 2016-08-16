<?php
/**
 * @file
 * A part of the loop_external_data module.
 */

/**
 * Class Leaf
 */
class Leaf extends LoopNode {
  protected $body;
  protected $leafID;
  protected $drupalNID;

  /**
   * Constructor.
   *
   * @param string $title
   *   Name of the leaf.
   * @param string $body
   *   Body of the leaf.
   * @param int $leaf_id
   *   ID of the leaf.
   */
  public function __construct($title, $body, $leaf_id) {
    parent::__construct($title);
    $this->body = $body;
    $this->leafID = $leaf_id;
    $this->drupalNID = -1;
  }

  /**
   * Get the body of the leaf.
   *
   * @return string
   *   The body of the leaf.
   */
  public function getBody() {
    return $this->body;
  }

  /**
   * Set the body of the leaf.
   *
   * @param string $body
   *   The new body.
   */
  public function setBody($body) {
    $this->body = $body;
  }

  /**
   * Get the leaf ID.
   *
   * @return int
   *   The id of the leaf.
   */
  public function getLeafID() {
    return $this->leafID;
  }

  /**
   * Get the NID (drupal) for the leaf.
   *
   * @return int
   *   The nid of the leaf.
   */
  public function getDrupalNID() {
    return $this->drupalNID;
  }

  /**
   * Set the NID (drupal) of the leaf.
   *
   * @param int $drupal_nid
   *   The nid of the leaf.
   */
  public function setDrupalNID($drupal_nid) {
    $this->drupalNID = $drupal_nid;
  }
} 
