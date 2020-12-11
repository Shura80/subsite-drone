<?php

/**
 * Monthly email notifier.
 */
class EnrdNotificationsMessageDigestMonth extends MessageDigest {

  /**
   * Return a custom 1 month interval for Message Digest email digest settings.
   */
  public function getInterval() {
    return '1 month';
  }

}
