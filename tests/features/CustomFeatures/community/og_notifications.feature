@api @community
Feature: ENRD Notifications
  This feature is aimed to test "ENRD" Community notifications.

  Background: I create a new Community and users working on it
    Given users:
      | name        | mail                    | pass | roles                         |
      | group-admin | group-admin@example.com | test | authenticated user, webmaster |
    And I am viewing an "community" content in "published" status:
      | title  | BDD Community Notify |
      | author | group-admin          |

  # Community Member
  # Rule: ENRD OG member subscribe (Active)
  @og @emails @notify_users @active
  Scenario: Notify new Community Member that he has been actively subscribed and Group admin about new membership.
    Given the test email system is enabled
    And I am logged in as a user with the "authenticated user" role and I have the following fields:
      | field_firstname | User                    |
      | field_lastname  | Active                  |
      | mail            | user-active@example.com |
    And I have the "member" role in the "BDD Community Notify" group
    Then the email to "user-active@example.com" should contain "Your membership request was approved for 'BDD Community Notify'"
    And the email to "group-admin@example.com" should contain "User Active joined BDD Community Notify"

  # Rule: ENRD OG member subscribe (Pending)
  @og @emails @notify_users @pending
  Scenario: Notify new Community Member that his subscription is pending for approval.
    Given the test email system is enabled
    And I am logged in as a user with the "authenticated user" role and I have the following fields:
      | field_firstname | User                     |
      | field_lastname  | Pending                  |
      | mail            | user-pending@example.com |
    And I have the "member" role in "pending" status in the "BDD Community Notify" group
    Then the email to "user-pending@example.com" should contain "Your membership request for 'BDD Community Notify'"
    And the email to "group-admin@example.com" should contain "User Pending membership request BDD Community Notify"

  # Rule: ENRD OG member subscribe request (Approved)
  @og @emails @notify_users @approved
  Scenario: Notify new Community Member that his subscription has been approved and Group admin about new membership.
    Given I am logged in as a user with the "authenticated user" role and I have the following fields:
      | field_firstname | User                      |
      | field_lastname  | Approved                  |
      | mail            | user-approved@example.com |
    And I have the "member" role in "pending" status in the "BDD Community Notify" group
    And the test email system is enabled
    And I am logged in as "group-admin"
    When I am at "community/bdd-community-notify"
    And I click "Group"
    And I click "People"
    Then I should see the text "Pending" in the "User Approved" row
    When I click "edit" in the "User Approved" row
    And I select "Active" from "Status"
    And I press the "Update membership" button
    Then the email to "user-approved@example.com" should contain "Your membership request was approved for 'BDD Community Notify'"
    And the email to "group-admin@example.com" should contain "User Approved joined BDD Community Notify"

  # Rule: ENRD OG member subscribe (Blocked)
  @og @emails @notify_users @blocked
  Scenario: Notify new Community Member that his subscription has been rejected and Group admin about refusal.
    Given I am logged in as a user with the "authenticated user" role and I have the following fields:
      | field_firstname | User                     |
      | field_lastname  | Blocked                  |
      | mail            | user-blocked@example.com |
    And I have the "member" role in "pending" status in the "BDD Community Notify" group
    And the test email system is enabled
    And I am logged in as "group-admin"
    When I am at "community/bdd-community-notify"
    And I click "Group"
    And I click "People"
    Then I should see the text "Pending" in the "User Blocked" row
    When I click "edit" in the "User Blocked" row
    And I select "Blocked" from "Status"
    And I press the "Update membership" button
    # Both Blocked and Rejected rules fire.
    Then the email to "user-blocked@example.com" should contain "Your membership has been blocked for 'BDD Community Notify'"
    And the email to "group-admin@example.com" should contain "User Blocked blocked for BDD Community Notify"

  # Rule: ENRD OG member subscribe (Remove)
  @og @emails @notify_users @remove
  Scenario: Notify new Community Member that it has been removed from Group and Group admin about removal.
    Given I am logged in as a user with the "authenticated user" role and I have the following fields:
      | field_firstname | User                    |
      | field_lastname  | Remove                  |
      | mail            | user-remove@example.com |
    And I have the "member" role in "pending" status in the "BDD Community Notify" group
    And the test email system is enabled
    And I am logged in as "group-admin"
    When I am at "community/bdd-community-notify"
    And I click "Group"
    And I click "People"
    Then I should see the text "Pending" in the "User Remove" row
    When I click "remove" in the "User Remove" row
    And I press the "Remove" button
    Then the email to "user-remove@example.com" should contain "Group 'BDD Community Notify' removal"
    And the email to "group-admin@example.com" should contain "User Remove removed from BDD Community Notify"
