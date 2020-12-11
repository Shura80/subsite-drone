<?php

namespace Drupal\enrd\Context;

use Behat\Behat\Hook\Scope\AfterStepScope;
use Behat\Behat\Hook\Scope\BeforeStepScope;
use Behat\Mink\Driver\Selenium2Driver;
use Behat\MinkExtension\Context\RawMinkContext;

/**
 * Provides step definitions for interacting with Drupal.
 */
class DebugContext extends RawMinkContext {

  private $stepId;

  /**
   * Set the Step ID.
   *
   * @BeforeStep
   */
  public function beforTheStep(BeforeStepScope $scope) {
    $this->stepId = date('Y-m-d-Hi') . '_' . basename($scope->getFeature()->getfile()) . '-' . $scope->getStep()->getLine() . '_' . uniqid();
  }

  /**
   * Hook into AfterStep.
   *
   * If the current step is failing, then print the html code of
   * the current page and, if the driver is an instance of
   * Selenium2Driver, print a screenshot of the current page.
   *
   * @AfterStep
   */
  public function afterTheStep(AfterStepScope $scope) {
    if (99 !== $scope->getTestResult()->getResultCode()) {
      return NULL;
    }

    $this->takeScreenshot();
    $this->takePageContent();
    $this->getErrorPosition($scope);
  }

  /**
   * Write a log file.
   *
   * @param string $content
   *   The content of the file.
   * @param string $extension
   *   The extension of the file.
   *
   * @return string
   *   The full file path just wrote.
   */
  private function logFile($content, $extension = 'log') {
    $filePath = __DIR__ . '/../../../.tmp/debug/behat/';
    $fileName = $this->stepId . '.' . $extension;

    $fullPath = $filePath . $fileName;

    if (!file_exists($filePath)) {
      mkdir($filePath, 0777, TRUE);
    }
    if (file_exists($fullPath)) {
      unlink($fullPath);
    }

    file_put_contents($fullPath, $content);
    return $fullPath;
  }

  /**
   * Save a screenshot.
   *
   * Save a screenshot of the current page if the driver is
   * an instance of Selenium2Driver.
   */
  private function takeScreenshot() {
    $driver = $this->getSession()->getDriver();

    if (!$driver instanceof Selenium2Driver) {
      return NULL;
    }

    $fullPath = $this->logFile($this->getSession()->getScreenshot(), 'png');
    echo(sprintf(
      "Result screenshot at: %s \n",
      $fullPath
    ));
  }

  /**
   * Save the html code of the current page.
   */
  private function takePageContent() {
    $fullPath = $this->logFile($this->getSession()->getPage()->GetContent(), 'html');
    echo(sprintf(
      "Result HTML page content at: %s \n",
      $fullPath
    ));
    return $this;
  }

  /**
   * Write the page content into a debug file.
   *
   * @Then Debug
   */
  public function debugPage() {
    $this->takePageContent();
    $this->takeScreenshot();
  }

  /**
   * Method getErrorPosition.
   *
   * Print the position of the error.
   *
   * @param \Behat\Behat\Hook\Scope\AfterStepScope $scope
   *   The AfterStep scope full object.
   */
  private function getErrorPosition(AfterStepScope $scope) {

    $fileContent = sprintf(
      "Feature: %s\n%s %s # %s:%s\n  %s (Exception)",
      $scope->getFeature()->getTitle(),
      $scope->getStep()->getKeywordType(),
      $scope->getStep()->getText(),
      $scope->getFeature()->getFile(),
      $scope->getStep()->getLine(),
      $scope->getTestResult()->getException()->getMessage()
    );

    $fullPath = $this->logFile($fileContent, 'log');
    echo(sprintf(
      "Position of error at: %s \n",
      $fullPath
    ));
  }

  /**
   * DPM for behat.
   *
   * @param mixed $var
   *   A variable.
   * @param string $prefix
   *   An identifier string for the variable.
   */
  public static function bpm($var, $prefix = '') {
    fwrite(STDOUT, "$prefix\n" . var_export($var, TRUE) . "\n");
  }

}
