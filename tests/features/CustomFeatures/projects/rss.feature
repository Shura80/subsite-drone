@api @rss
Feature: ENRD Projects Feed.

  This feature is aimed at testing the Projects RSS Feed functionality.

  @anonymous
  Scenario: As anonymous I should be able to access the RSS Feed page of the latest published projects.
    Given I am an anonymous user
    And I am viewing a "project" content in "published" status:
      | title   | BDD RSS Test project |
      | created | 01-01-2020 8:00      |

    And I am at "rss/projects-practice"
    Then I should get a "200" HTTP response
