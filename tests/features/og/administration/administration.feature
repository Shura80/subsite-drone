@api @administration
Feature: EIP-AGRI Administration group
  In order to test some basic features functionality

  Background: I create a new Administration and users working on it
    Given I am viewing an "administration" content:
      | title | BDD Administration Community |

  # Administration community members:
  # Member.
  Scenario: Viewing administration group page from simple group member
    Given I am logged in as a user with the "authenticated user" role
    And I have the "member" role in the "BDD Administration Community" group
    And I am on "/user"
    When I click "BDD Administration Community"
    Then I should not see "Group" in the ".tabs" element
    And I should see "Published content" in the "content_top_left" region
    And I should see "Unpublished content" in the "content_top_right" region
    And I should not see "Create content" in the "sidebar_left" region
    And I should see "Latest Content" in the "sidebar_left" region
    And I should see "Latest Members" in the "sidebar_left" region

  # Group contributor.
  Scenario: Viewing administration group page from group contributor
    Given I am logged in as a user with the "authenticated user" role
    And I have the "group contributor" role in the "BDD Administration Community" group
    And I am on "/user"
    When I click "BDD Administration Community"
    Then I should not see "Group" in the ".tabs" element
    And I should see "Published content" in the "content_top_left" region
    And I should see "Unpublished content" in the "content_top_right" region
    And I should see "Create content" in the "sidebar_left" region
    And I should see "Latest Content" in the "sidebar_left" region
    And I should see "Latest Members" in the "sidebar_left" region

  # Group editor.
  Scenario: Viewing administration group page from group editor
    Given I am logged in as a user with the "authenticated user" role
    And I have the "group editor" role in the "BDD Administration Community" group
    And I am on "/user"
    When I click "BDD Administration Community"
    Then I should not see "Group" in the ".tabs" element
    And I should see "Published content" in the "content_top_left" region
    And I should see "Unpublished content" in the "content_top_right" region
    And I should see "Create content" in the "sidebar_left" region
    And I should see "Latest Content" in the "sidebar_left" region
    And I should see "Latest Members" in the "sidebar_left" region

  # Group manager.
  Scenario: Viewing administration group page from group manager
    Given I am logged in as a user with the "authenticated user" role
    And I have the "group manager" role in the "BDD Administration Community" group
    And I am on "/user"
    When I click "BDD Administration Community"
    Then I should see the link "Group"
    And I should see "Published content" in the "content_top_left" region
    And I should see "Unpublished content" in the "content_top_right" region
    And I should not see "Create content" in the "sidebar_left" region
    And I should see "Latest Content" in the "sidebar_left" region
    And I should see "Latest Members" in the "sidebar_left" region
