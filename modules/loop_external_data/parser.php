<?php
/**
 * @file
 * A part of the loop_external_data module.
 */

/**
 * Class NoParserFoundException
 */
class NoParserFoundException extends Exception {}

/**
 * Class Parser
 *
 * Standard parser class. Selects relevant parser when calling parse().
 */
class Parser {
  /**
   * Parses a zip file.
   *
   * @param string $filename
   *   The name of the zip file.
   * @param string $path_to_directory
   *   The path to the directory to unzip into.
   * @param int $index_node_id
   *   The id of the Index node added to Drupal.
   *
   * @throws NoParserFoundException
   *
   * @returns $data
   *  The data formatted as XML.
   */
  public function parse($filename, $path_to_directory, $index_node_id) {
    if ($this->extractZip($filename, $path_to_directory)) {
      // Zip file extracted. Find folder.
      if ((is_dir($path_to_directory)) && ($dh = opendir($path_to_directory))) {
        while (($directory = readdir($dh)) !== FALSE) {
          if (is_readable($path_to_directory . '/' . $directory) &&
              is_dir($path_to_directory . '/' . $directory) &&
              !in_array($directory, array('.', '..'))) {
            $parser = $this->search($path_to_directory . '/' . $directory);

            if (is_null($parser)) {
              throw new NoParserFoundException();
            }

            // Get output data.
            $data = $parser->process($path_to_directory . '/' . $directory, $index_node_id);

            return $data;
          }
        }
      }
    }
  }

  /**
   * Convert from CP865 to UTF8 characters in $text to UTF-8.
   *
   * @param string $text
   *   Text to convert to utf-8.
   *
   * @return string
   *   Result string.
   */
  protected function convertCP865ToUTF8($text) {
    $text = iconv("CP865", "UTF-8", rawurldecode($text));

    return $text;
  }

  /**
   * Extracts a zip file to a directory.
   *
   * @param string $filename
   *   Name of the zip file.
   * @param string $path_to_directory
   *   Path to document directory.
   *
   * @return bool
   *   Did the extraction succeed?
   */
  protected function extractZip($filename, $path_to_directory) {
    file_prepare_directory($path_to_directory, FILE_CREATE_DIRECTORY);

    $za = new ZipArchive();

    $za->open($filename);

    for ($i = 0; $i < $za->numFiles; $i++) {
      $stat = $za->statIndex($i);
      $entryname = $this->convertCP865ToUTF8($stat['name']);
      // If getFromIndex returns false it is a directory.
      if ($content = $za->getFromIndex($i)) {
        file_put_contents($path_to_directory . '/' . $entryname, $content);
      }
      else {
        $path = $path_to_directory . '/' . $entryname;
        file_prepare_directory($path, FILE_CREATE_DIRECTORY);
      }
    }
    $za->close();

    return TRUE;
  }

  /**
   * Search $pathToDirectory for a match with known parsers.
   *
   * @param string $path_to_directory
   *   Path to extracted files.
   *
   * @return parser|NULL
   *   The matching parser or NULL if no parser found.
   */
  protected function search($path_to_directory) {
    $parser = NULL;

    $path = drupal_get_path('module', 'loop_external_data');
    $path .= '/parsers/';

    if ((is_dir($path)) && ($dh = opendir($path))) {
      while (($file = readdir($dh)) !== FALSE) {
        if (fnmatch("*.php", $file) && is_readable($path . $file)) {
          include_once $path . $file;

          $class_name = basename($file, '.php');

          $test_parser = new $class_name();

          if ($test_parser->identifyFormat($path_to_directory)) {
            $parser = $test_parser;
            break;
          }
        }
      }
    }
    return $parser;
  }
}
