@api @og @invite-accepted
Feature: AGRI invite
  In order to test the functionality "Invite by mail" into OG Collaborative Area

  Background:
    Given users:
      | name             | mail                         |
      | bdd-user-invitee | bdd-user-invitee@example.com |

  Scenario:
    Given I am logged in as a user with the "authenticated user" role
    And I am viewing an "collaborative_area" content in "published" status:
      | title | BDD Collaborative area |
    And I have the "administrator member" role in the "BDD Collaborative area" group
    And the test email system is enabled
    And I am on "/user"
    When I click "BDD Collaborative area"
    And I click "Group"
    And I click "Invite people"
    Then I fill in "edit-email" with "bdd-user-invitee@example.com"
    And I fill in "edit-event-title" with "BDD event name"
    When I press the "Invite user(s)" button
    Then I should see the following success messages:
      | success messages             |
      | bdd-user-invitee@example.com |
    And the email to "bdd-user-invitee@example.com" should contain "We would like to invite you to join the"
    When I visit the "collaborative_area" content with title "BDD Collaborative area"
    And I click "Group"
    And I click "Invite list"
    Then I should see the link "bdd-user-invitee@example.com"
    And I should see the text "Valid"
    Given I am logged in as "bdd-user-invitee"
    And I accept the invitation sent to "bdd-user-invitee@example.com" email address
    Then I should be on "/en/collaborative-area/bdd-collaborative-area"