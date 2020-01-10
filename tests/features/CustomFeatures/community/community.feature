@api @community
Feature: ENRD Community functionalities

  Background: I create a new Community and users working on it
    Given I am viewing an "community" content in "published" status:
      | title | BDD Community |

  # Community Member
  Scenario: Access from the Community menu only the following sections: Start page, Meetings and Discussions
    Given I am logged in as a user with the "authenticated user" role
    And I have the "member" role in the "BDD Community" group

    When I am on "/myenrd"
    And I click "BDD Community"

    Then I should see the heading "BDD Community"
    And I should see the link "Start Page" in the "right sidebar" region
    And I should see the link "Meetings" in the "right sidebar" region
    And I should see the link "Discussions" in the "right sidebar" region

    # Create new Discussion content and edit or delete own content.
    And I should see the link "Discussion" in the "og contextual links" region
    And I should not see the link "Document" in the "og contextual links" region
    And I should not see the link "Event" in the "og contextual links" region
    And I should not see the link "LAG" in the "og contextual links" region
    And I should not see the link "News" in the "og contextual links" region

  # Community Manager
  Scenario: Community manager should create an Event
    Given I am logged in as a user with the "authenticated user" role
    And I have the "community_manager" role in the "BDD Community" group

    When I am on "/myenrd"
    And I click "BDD Community"

    Then I should see the heading "BDD Community"
    And I should see the link "Discussion" in the "og contextual links" region
    And I should see the link "Event" in the "og contextual links" region
    And I should see the link "Document" in the "og contextual links" region
    And I should not see the link "LAG" in the "og contextual links" region
    And I should not see the link "News" in the "og contextual links" region

  @groups_moderator
  Scenario: Access to workbench page for managing content
    Given I am logged in as a user with the "groups moderator" role
    When I go to "admin/workbench"
    Then I should not get a 403 HTTP response
    When I go to "admin/workbench/needs-review"
    Then I should not get a 403 HTTP response
    When I go to "admin/workbench/drafts"
    Then I should not get a 403 HTTP response
