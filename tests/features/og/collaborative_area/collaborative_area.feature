@api @og
Feature: AGRI Collaborative area
  In order to test the functionality "Invite by mail" into OG Collaborative Area

  Background: I create a new "Collaborative area" and users working on it
    Given I am viewing an "collaborative_area" content in "published" status:
      | title | BDD Collaborative area Community |

  Scenario: Check for renamed "View published" tab in "Collaborative area"
    Given I am logged in as a user with the "authenticated user" role
    And I have the "administrator member" role in the "BDD Collaborative area Community" group
    And I am on "/user"
    When I click "BDD Collaborative area Community"
    Then I should not see the text "View published"
    But I should see the link "Collaborative area"
    Then I should see "Collaborative Area" in the "sidebar_left"
    And I should see "Latest Content" in the "sidebar_left"
    And I should see "Latest Members" in the "sidebar_left"

  @og_permission
  Scenario: Check og permission for the member user
    Given I am logged in as a user with the "authenticated user" role
    And I have the "member" role in the "BDD Collaborative area Community" group
    And I am on "/user"
    When I click "BDD Collaborative area Community"
    Then I should not see "Group" in the ".tabs" element

  @og_permission
  Scenario: Check og permission for the administrator user
    Given I am logged in as a user with the "authenticated user" role
    And I have the "administrator member" role in the "BDD Collaborative area Community" group
    And I am on "/user"
    When I click "BDD Collaborative area Community"
    And I click "Group"
    Then I should see the link "Add people"
    And I should see the link "Invite people"
    And I should see the link "Invite list"
    And I should see the link "Menus"
    And I should see the link "People"
    And I should see the link "Permissions (read-only)"
    And I should see the link "Roles (read-only)"