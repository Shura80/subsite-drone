<?php

namespace Drupal\enrd\Context;

use Drupal\DrupalExtension\Context\RawDrupalContext;

/**
 * Defines application features from the specific context.
 */
class MediaContext extends RawDrupalContext {

  private $files = [];

  /**
   * Set private array $files.
   */
  public function setFiles($file) {
    $this->files[$file->fid] = $file;
  }

  /**
   * Creates file entity of type image with a caption field.
   *
   * @Given /^an image "([^"]*)" with the caption "([^"]*)"$/
   */
  public function iUploadAnImage($filename, $caption) {
    global $language;

    $path = $this->getMinkParameter('files_path');

    if (strpos($filename, '.jpg')) {
      $images = file_scan_directory($path, '/\.jpg/');
      if ($images) {
        $image = reset($images);
        $test_image_path = $this->getMinkParameter('files_path') . '/' . $image->filename;
        $fileContents = file_get_contents($test_image_path);
        // Saves a file to the specified destination and creates a db entry.
        $file = file_save_data(
          $fileContents,
          "public://{$filename}",
          FILE_EXISTS_REPLACE
        );

        // Applies Caption to the image.
        if (!empty($file)) {
          if ($file->type == 'image') {
            if (empty($file->field_caption)) {
              // Set Image "Caption".
              $file->field_caption[$language->language][0]['value'] = $caption;

              file_save($file);
              $this->setFiles($file);
            }
          }
          else {
            throw new Exception(sprintf('File with filename "%s" is not an image.', $filename));
          }
        }
      }
      else {
        throw new Exception(sprintf('There are no .jpg images in the resources dir: "%s".', $path));
      }
    }
    else {
      throw new Exception(sprintf('Can only create .jpg test images.'));
    }
  }

  /**
   * Creates file entity of type video with a description field.
   *
   * @Given /^a video "([^"]*)" with the description "([^"]*)"$/
   */
  public function iUploadVideoWithDescription($filename, $description) {
    global $language;

    $path = $this->getMinkParameter('files_path');

    if (strpos($filename, '.mp4')) {
      $videos = file_scan_directory($path, '/\.mp4/');
      if ($videos) {
        $video = reset($videos);
        $test_video_path = $this->getMinkParameter('files_path') . '/' . $video->filename;
        $fileContents = file_get_contents($test_video_path);
        // Saves a file to the specified destination and creates a db entry.
        $file = file_save_data(
          $fileContents,
          "public://{$filename}",
          FILE_EXISTS_REPLACE
        );

        // Applies Description to the video.
        if (!empty($file)) {
          if ($file->type == 'video') {
            // Set Video "Description".
            $file->field_video_description[$language->language][0]['value'] = $description;

            file_save($file);
            $this->setFiles($file);
          }
          else {
            throw new Exception(sprintf('File with filename "%s" is not a video.', $filename));
          }
        }
      }
      else {
        throw new Exception(sprintf('There are no .mp4 videos in the resources dir: "%s".', $path));
      }
    }
    else {
      throw new Exception(sprintf('Can only create .mp4 test videos.'));
    }
  }

  /**
   * Creates file entity of type document.
   *
   * @Given /^a document "([^"]*)"$/
   */
  public function iUploadaDocument($filename) {

    $path = $this->getMinkParameter('files_path');

    if (strpos($filename, '.pdf')) {
      $docs = file_scan_directory($path, '/\.pdf/');
      if ($docs) {
        $docs = reset($docs);
        $test_doc_path = $this->getMinkParameter('files_path') . '/' . $docs->filename;
        $fileContents = file_get_contents($test_doc_path);
        // Saves a file to the specified destination and creates a db entry.
        $file = file_save_data(
          $fileContents,
          "public://{$filename}",
          FILE_EXISTS_REPLACE
        );

        // Applies Description to the video.
        if (!empty($file)) {
          file_save($file);
          $this->setFiles($file);
        }
      }
      else {
        throw new Exception(sprintf('There are no .pdf documents in the resources dir: "%s".', $path));
      }
    }
  }

  /**
   * Clean files created during tests once the scenario is finished.
   *
   * @AfterScenario
   */
  public function cleanupFilesTable() {
    if (!empty($this->files)) {
      foreach ($this->files as $file) {
        // Ensure that stored fid is still a valid reference to a file object.
        if ($file = file_load($file->fid)) {
          // Clean files table from file created during test.
          entity_delete('file', $file->fid);
        }
      }
    }
  }

}
