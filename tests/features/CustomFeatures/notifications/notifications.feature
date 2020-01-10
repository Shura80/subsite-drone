@api @notifications
Feature: ENRD Notifications.
  This Feature aims to manage site and email notifications for users that are
  subscribed to certain content types.

  @admin @message-subscribe-settings
  Scenario: As an administrator user I want check for the message subscribe form settings.
    Given I am logged in as a user with the "administer message subscribe" permission
    When I am at "admin/config/system/message-subscribe"
    Then the "message_subscribe_flag_prefix" field should contain "enrd_follow"
    And I should see "Notifications panel item limit"
    And I should see "Choose a day of month to schedule unread notifications reminder."
    And I should see "Mail sender address"

  @javascript @authenticated @notifications @notifications-settings-panel
  Scenario: As an authenticated user I want to check that flag to subscribe to different content types are in place.
    Given I am logged in as a user with the "authenticated user" role
    When I click "Latest Notifications" in the "tools buttons" region
    And I wait for AJAX to finish
    And I click "Settings" in the "tools buttons" region
    # Flag links.
    Then I should see the link "Contents you follow"
    And I should see the link "LAGs you follow"
    And I should see the link "Click to follow site's news"
    When I click "Check this option to be notified by email"
    And I wait for AJAX to finish
    # Show a warning when click email flag without relative follow flag already flagged.
    Then I should see "You can't receive emails if you don't follow any news"
    When I click "Click to follow site's news"
    And I wait for AJAX to finish
    Then I should see the link "Click to unfollow site's news"
    # Hide the email flag warning once relative follow flag has benn flagged.
    And I should not see "You can't receive emails if you don't follow any news"
    And I should see the link "Click to follow site's events"
    When I click "Click to follow site's events"
    And I wait for AJAX to finish
    Then I should see the link "Click to unfollow site's events"
    Then I should see the link "Click to follow LAGs' Cooperation Offers"
    When I click "Click to follow LAGs' Cooperation Offers"
    And I wait for AJAX to finish
    Then I should see the link "Click to unfollow LAGs' Cooperation Offers"
    # Notifications Settings panel.
    And I should see the link "LAGs you follow"
    When I click "LAGs you follow"
    Then I should see the heading "Search LAGs"
    And I should see 'Start to type in the "Search in the LAG Database" field or use the "Advanced search" filters to find LAGs you may be interested in.' in the "content" region
    And I should see "Search in the LAG Database" in the "content" region
    And I should see the button "Advanced search" in the "content" region
    When I press the "Advanced search" button
    And I should see "Country"
    And I should see "ESI Fund"
    And I should see "ESIF Programme"
    And I should see the link "Email settings"
    When I click "Email settings"
    Then I should see "How often would you like to receive email notifications?"
    And I should have the following options for "edit-message-subscribe-email-freq":
      | option                          |
      | Once a day in an email digest   |
      | Once a week in an email digest  |
      | Once a month in an email digest |
    And I should see "Remind me of unread notifications"
    And I should see an "#edit-field-enrd-notifications-remind" element

  @javascript @authenticated @notifications @notifications-subscription
  Scenario: As a user I want to get website notifications when I follow a content type that has a new published item.
    Given I am logged in as a user with the "administrator" role and I have the following fields:
      | mail            | user_admin@example.com |
      | field_firstname | User                   |
      | field_lastname  | Admin                  |
    When I click "Latest Notifications" in the "tools buttons" region
    And I wait for AJAX to finish
    And I click "Settings" in the "tools buttons" region
    And I click "Click to follow site's news"
    And I wait for AJAX to finish
    # Workaround for a message created after a node publication.
    And I am at "node/add/news"
    And I fill in "edit-title-field-en-0-value" with "BDD News to follow"
    And I click "Publishing options"
    And I select "Published" from "Moderation state"
    And I wait for AJAX to finish
    And I press the "Save" button
    And I wait
    # Check if message has been created.
    Then the ".enrd-notifications-counter" element should contain "1"
    And I should find a message subscribe item in the queue list
    When I click "Latest Notifications" in the "tools buttons" region
    And I wait for AJAX to finish
    Then I should see "The new News BDD News to follow has been published"
    # Check if the notifications is set as read once clicked.
    Then I open my notifications page
    And I follow "BDD News to follow"
    Then the ".enrd-notifications-counter" element should not contain "1"
    # Check that new Drafty logic doesn't create notifications on new non-published revisions.
    When I am at "news-events/news/bdd-news-follow"
    And I follow "New draft"
    And I press the "Save" button
    And I wait
    Then the ".enrd-notifications-counter" element should not contain "1"

  @javascript @authenticated @notifications @notifications-subscription @emails @clean
  Scenario: As a user I want to be notified by email when I follow a content type that has a new published item.
    Given I am logged in as a user with the "administrator" role and I have the following fields:
      | mail            | user_admin@example.com |
      | field_firstname | User                   |
      | field_lastname  | Admin                  |
    Given the test email system is enabled
    When I click "Latest Notifications" in the "tools buttons" region
    And I wait for AJAX to finish
    And I click "Settings" in the "tools buttons" region
    And I click "Click to follow site's news"
    And I wait for AJAX to finish
    And I should see "Send email"
    # Check only email flag to see if default option "monthly" is used by default.
    And I click "Check this option to be notified by email"
    And I wait for AJAX to finish
    # Workaround for a message created after a node publication.
    And I am at "node/add/news"
    And I fill in "edit-title-field-en-0-value" with "BDD News to follow"
    And I click "Publishing options"
    And I select "Published" from "Moderation state"
    And I wait for AJAX to finish
    And I press the "Save" button
    # Run queue and message digest cron to schedule digest and send it
    And I run drush "queue-run message_subscribe"
    Then the "monthly" message digest item has been "created"
    And I run cron
    Then the "monthly" message digest item has been "sent"
    Then the email to "user_admin@example.com" should contain "The European Network for Rural Development (ENRD) Message Digest"
    And the email to "user_admin@example.com" should contain "Greetings User Admin, you have received the following notifications on the site: The European Network for Rural Development (ENRD)."
    And the email to "user_admin@example.com" should contain "The new News BDD News to follow [1] has been published."

  @notifications @flag-access
  Scenario: As a LAG user I should see the flag link to follow a LAG if not mine.
    Given 'enrd_countries' terms:
      | name      | parent         |
      | BDD Italy | European Union |
    And I am viewing a "lag" content in "published" status:
      | field_enrd_lag_code    | BDD-IT-000                                               |
      | title                  | BDD LAG 000                                              |
      | og_group_ref           | European Agricultural Fund for Rural Development (EAFRD) |
      | field_enrd_lag_country | BDD Italy                                                |
      | language               | und                                                      |
    And I am viewing a "lag" content in "published" status:
      | field_enrd_lag_code    | BDD-IT-001                                               |
      | title                  | BDD LAG 001                                              |
      | og_group_ref           | European Agricultural Fund for Rural Development (EAFRD) |
      | field_enrd_lag_country | BDD Italy                                                |
      | language               | und                                                      |
    And I am logged in as a user with the "LAG User" role and I have the following fields:
      | og_user_node | BDD LAG 000 |
    And I have the "LAG Contact" role in the "BDD LAG 000" group
    When I am at "lag/bdd-it-000"
    Then I should not see the link "Click to follow this LAG's updates"
    When I am at "lag/bdd-it-001"
    Then I should see the link "Click to follow this LAG's updates"
