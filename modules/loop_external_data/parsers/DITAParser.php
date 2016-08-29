<?php
/**
 * @file
 * This file is a part of the Loop External Data module.
 */

/**
 * Class DITAParser
 *
 * For passing a DITA folder.
 */
class DITAParser implements ParserInterface {
  /**
   * Rename a DOMElement.
   *
   * @param DOMElement $old_tag
   *   Old DOMElement
   * @param string $new_tag_name
   *   The new name for the DOMElement
   *
   * @return DOMElement
   *   The new DOMElement
   */
  protected function renameTag($old_tag, $new_tag_name) {
    $document = $old_tag->ownerDocument;

    $new_tag = $document->createElement($new_tag_name);
    $old_tag->parentNode->replaceChild($new_tag, $old_tag);

    foreach ($old_tag->attributes as $attribute) {
      $new_tag->setAttribute($attribute->name, $attribute->value);
    }
    foreach (iterator_to_array($old_tag->childNodes) as $child) {
      $new_tag->appendChild($old_tag->removeChild($child));
    }
    return $new_tag;
  }

  /**
   * Removes all attributes from element.
   *
   * @param DOMElement $element
   *   The DOMElement to remove attributes from.
   */
  protected function removeAttributes($element) {
    $attributes = $element->attributes;
    while ($attributes->length) {
      $element->removeAttribute($attributes->item(0)->name);
    }
  }

  /**
   * Collapses ../ in paths.
   *
   * @param string $path
   *   Path to collapse.
   *
   * @return string
   *   The collapsed path.
   */
  protected function collapsePath($path) {
    $path_array = array();

    // Split $path at /.
    $split = preg_split('/\//', $path);

    // Iterate through parts and assemble new path array.
    // Pop the top element when ".." is encountered.
    foreach ($split as $part) {
      if ($part == '..') {
        array_pop($path_array);
      }
      else {
        array_push($path_array, $part);
      }
    }

    $result_path = '';
    $i = 0;
    $array_max_index = count($path_array);
    // Assemble the new path array to a string.
    foreach ($path_array as $part) {
      $i++;

      $result_path = $result_path . $part;

      if ($i < $array_max_index) {
        $result_path = $result_path . '/';
      }
    }

    return $result_path;
  }

  /**
   * Traverses a DITA node.
   *
   * If leaf: Processes the referred reference.
   *          Inserts conrefs
   *          Replaces tables
   *          Replaces xrefs
   *          Inserts images in Drupal and changes image paths
   * If tree: Adds children to tree (after traversing each)
   *
   * @param SimpleXMLElement $node
   *   The node to traverse.
   * @param string $path_to_directory
   *   Path to the document directory.
   * @param int $index_node_id
   *   The NID (Drupal) of the index node.
   * @param array $object_references
   *   Array of object references.
   * @param array $xref_references
   *   Array of xref references.
   *
   * @return Leaf|null|Tree
   *   The result of traversing the node.
   */
  protected function traverseNode($node, $path_to_directory, $index_node_id, &$object_references, &$xref_references) {
    // Get the type of the given node.
    $node_type = $node->getName();

    if ($node_type == 'topicref') {
      // Get the reference to the topicref file.
      $href = $node['href'];

      // Load body of topic into DOM.
      $body = simplexml_load_file($path_to_directory . '/' . $href)->body;
      $domnode = dom_import_simplexml($body[0]);
      $dom = new DOMDocument();
      $domnode = $dom->importNode($domnode, TRUE);
      $dom->appendChild($domnode);

      // Setup XPath for DOM.
      $xpath = new DOMXPath($dom);

      // Replace conrefs
      // From these cases:
      // http://docs.oasis-open.org/dita/v1.1/OS/langspec/common/theconrefattribute.html
      // Only implemented "Using conref to refer to an element within a topic"
      foreach ($xpath->query('//*[@conref]') as $conref_element) {
        $conref = $conref_element->getAttribute('conref');
        $conref_split = explode('#', $conref);

        $file_path = $conref_split[0];
        $var_xml = simplexml_load_file($path_to_directory . '/' . dirname($href) . '/' . $file_path);
        if (!$var_xml) {
          $msg = array(
            "message" => "import error: file not found",
            "ref" => $path_to_directory . '/' . dirname($href) . '/' . $file_path,
          );
          continue;
        }

        if (count($conref_split) == 2) {
          $id_array = explode('/', $conref_split[1]);
          $id = $id_array[1];
          $contain_id = $id_array[0];

          // TODO:
          // This is not complete correct, but matches the Flare Dita output.
          // Correct syntax - $sxml = $varXML->xpath(
          // '(//*[@id="' . $containId . '"]//*[@id="' . $id . '"])[last()]');
          $sxml = $var_xml->xpath('(//topic//*[@id="' . $id . '"])[last()]');
          if (!$sxml) {
            $msg = array(
              "message" => "import error: entry not found",
              "conref" => '"' . $conref . '"',
              "ref" => '"' . $path_to_directory . '/' . dirname($href) . '/' . $file_path . '"',
              "containerid" => '"' . $contain_id . '"',
              "id" => '"' . $id . '"',
            );
            continue;
          }

          $xml = dom_import_simplexml($sxml[0]);

          $dom_xml = $dom->importNode($xml, TRUE);

          // Replace with neutral html element.
          $new_element = $dom->createElement('span');
          foreach ($dom_xml->childNodes as $child) {
            $new_element->appendChild($child);
          }

          $conref_element->parentNode->replaceChild($new_element, $conref_element);
        }
      }

      // Replace image paths.
      foreach ($xpath->query('//image') as $image) {
        // Contruct path to image file.
        $ref = $path_to_directory . '/' . dirname($href) . '/' . $image->getAttribute('href');

        // Read file from  disk.
        $file_name = basename($image->getAttribute('href'));
        $file_content = file_get_contents($ref);

        // Save file into Drupal.
        $dir = 'public://external_data/' . $index_node_id;
        file_prepare_directory($dir, FILE_CREATE_DIRECTORY);
        $file = file_save_data($file_content, $dir . '/' . $file_name, FILE_EXISTS_RENAME);
        $file_path = file_create_url($file->uri);

        // Set up new image html element.
        $image->removeAttribute('href');
        $image->setAttribute('src', $file_path);
        $image_clone = $image->cloneNode(TRUE);

        // Wrap image in link tag.
        $wrapping_link = $dom->createElement('a');
        $wrapping_link->setAttribute('href', $file_path);
        $wrapping_link->setAttribute('target', '_blank');
        $wrapping_link->appendChild($image_clone);
        $image->parentNode->replaceChild($wrapping_link, $image);

        $this->renameTag($image_clone, 'img');
      }

      // Replace references.
      foreach ($xpath->query('//xref') as $xref) {
        // External links have the scope attribute set to external.
        $scope = $xref->getAttribute('scope');

        if ($scope != 'external') {
          $xhref = dirname($href) . '/' . $xref->getAttribute('href');
          $next_index = count($xref_references);

          $xhref = explode('#', $xhref);
          $xref_references[$this->collapsePath($xhref[0])] = $next_index;

          // Check for empty content, insert title from references topic as text.
          if ($xref->nodeValue === '') {
            $ref_xml = simplexml_load_file($path_to_directory . '/' . $xhref[0]);

            foreach ($ref_xml->xpath("//topic/title") as $title) {
              $xref->nodeValue = (string) $title;
              break;
            }
          }
          $xref->setAttribute('href', $next_index);
        }
        else {
          $xref->setAttribute('target', '_blank');
        }

        // Change name of node to a.
        $this->renameTag($xref, 'a');
      }

      // Handle tables.
      // Remove colspec nodes.
      foreach ($xpath->query('//table//colspec') as $table_colspec) {
        $table_colspec->parentNode->removeChild($table_colspec);
      }
      // Move content out of tgroup to table.
      foreach ($xpath->query('//table//tgroup') as $table_tgroup) {
        foreach ($table_tgroup->childNodes as $child) {
          $table_tgroup->parentNode->appendChild($child->cloneNode(TRUE));
        }
        $table_tgroup->parentNode->removeChild($table_tgroup);
      }
      // Rename title to caption.
      foreach ($xpath->query('//table//title') as $table_title) {
        $this->renameTag($table_title, 'caption');
      }
      // Rename row to tr.
      foreach ($xpath->query('//table//row') as $table_row) {
        $this->renameTag($table_row, 'tr');
      }
      // Rename tbody//entry to td.
      foreach ($xpath->query('//table//tbody//entry') as $table_entry) {
        $this->renameTag($table_entry, 'td');
      }
      // Rename thead//entry to th.
      foreach ($xpath->query('//table//thead//entry') as $table_entry) {
        $this->renameTag($table_entry, 'th');
      }
      // Remove all attributes from table elements.
      foreach ($xpath->query('//*[self::table or self::thead or self::tbody or self::tr or self::td or self::th]') as $child) {
        $this->removeAttributes($child);
      }

      // Wrap all table elements in a div with the class table-wrapper.
      foreach ($xpath->query('//table') as $table) {
        $div = $dom->createElement('div');
        $div->setAttribute('class', 'table-wrapper');
        $div->appendChild($table->cloneNode(TRUE));
        $table->parentNode->replaceChild($div, $table);
      }

      // Rename body to div.
      foreach ($xpath->query('//body') as $b) {
        $b->setAttribute('class', 'external-content');
        $this->renameTag($b, 'div');
      }

      // Convert dom to html.
      $body = $dom->saveHTML();

      // Get next leaf id.
      $next_leaf_id = count($object_references);

      // Make leaf from title of the node and the body.
      $leaf = new Leaf((string) $node['navtitle'], $body, $next_leaf_id);

      // Save href to leaf reference.
      $object_references[(string) $href] = $next_leaf_id;

      return $leaf;
    }
    elseif ($node_type == 'topichead') {
      $children = array();

      // Iterate through children, and add the result of traversing each.
      foreach ($node->children() as $child) {
        $children[] = $this->traverseNode($child, $path_to_directory, $index_node_id, $object_references, $xref_references);
      }

      $tree = new Tree((string) $node['navtitle'], $children);
      return $tree;
    }

    return NULL;
  }

  /**
   * Merges the arrays $objectReferences and $xrefReferences into a new array.
   *
   * From referenceIndex => Leaf object.
   *
   * @param array $object_references
   *   Array of object references.
   * @param array $xref_references
   *   Array of xref references.
   *
   * @return array
   *   The merged array.
   */
  protected function replaceReferences($object_references, $xref_references) {
    $index_references = array();

    foreach ($xref_references as $ref => $index) {
      $leaf_id = $object_references[$ref];
      $arr = array(
        'leafID' => $leaf_id,
        'nid' => -1,
      );
      $index_references[$index] = $arr;
    }

    return $index_references;
  }

  /**
   * Processes a DITA folder.
   *
   * @param string $path_to_directory
   *   Path to the document directory.
   * @param int $index_node_id
   *   Node id (drupal) of the Index.
   *
   * @return LoopIndex
   *   The index root node.
   */
  public function process($path_to_directory, $index_node_id) {
    // Load the table of references.
    $xml = simplexml_load_file($path_to_directory . '/' . 'Ditamap.ditamap');

    $children = array();
    $object_references = array();
    $xref_references = array();

    // Process each child and add to Index as children.
    foreach ($xml->children() as $child) {
      $node_type = $child->getName();
      if ($node_type == 'topichead') {
        $children[] = $this->traverseNode($child, $path_to_directory, $index_node_id, $object_references, $xref_references);
      }
    }

    // Merge references into reference overview.
    $index_references = $this->replaceReferences($object_references, $xref_references);

    $index = new LoopIndex($children, $index_references);
    return $index;
  }


  /**
   * Identify if this is a DITA folder.
   *
   * Look through the folder for a Ditamap.ditamap file.
   *
   * @param string $path_to_directory
   *   Path to the document directory.
   *
   * @return bool
   *   True if project is identified as a DITA project.
   */
  public function identifyFormat($path_to_directory) {
    $entries = scandir($path_to_directory);
    foreach ($entries as $entry) {
      if ($entry == 'Ditamap.ditamap') {
        return TRUE;
      }
    }
    return FALSE;
  }
}
