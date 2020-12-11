<?php

namespace Drupal\enrd\Context;

use Drupal\DrupalExtension\Context\DrupalContext as DrupalExtensionDrupalContext;
use Drupal\DrupalExtension\Hook\Scope\BeforeNodeCreateScope;

/**
 * Provides step definitions for interacting with Drupal.
 */
class DrupalContext extends DrupalExtensionDrupalContext {
  use \Drupal\nexteuropa\Context\ContextUtil;

  /**
   * Hook into node creation.
   *
   * @beforeNodeCreate
   */
  public static function alterNodeParameters(BeforeNodeCreateScope $scope) {
    call_user_func('parent::alterNodeParameters', $scope);
    // @see `features/api.feature`
    // Change 'published on' to the expected 'created'.
    $node = $scope->getEntity();
    if (isset($node->{"published on"})) {
      $node->created = $node->{"published on"};
      unset($node->{"published on"});
    }

    $context = $scope->getContext('DrupalContext');

    // Assign authorship to myself.
    if (!isset($node->uid) && !empty($node->author)) {
      if ($node->author == 'myself') {
        if ($context->getUserManager()->currentUserIsAnonymous()) {
          throw new \Exception(sprintf('There is no current logged in user to create a node for.'));
        }

        $node->uid = $context->getUserManager()->getCurrentUser()->uid;
      }
    }

    if (!isset($node->language)) {
      $node->language = language_default('language');
    }
  }

  /**
   * {@inheritdoc}
   *
   * @AfterScenario @api
   */
  public function cleanTerms() {
    $batch =& batch_get();
    if (!isset($batch['id'])) {
      $batch['current_set'] = 0;
      $batch['sets'] = array();
      $batch['id'] = 'batch';
      $batch['progressive'] = FALSE;
    }
    parent::cleanTerms();
    $this->getDriver()->clearStaticCaches();

    if (isset($batch['id']) && $batch['id'] == 'batch') {
      unset($batch['id']);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function termCreate($term) {
    $saved = parent::termCreate($term);
    $this->getDriver()->clearStaticCaches();

    return $saved;
  }

}
