@api @rss
Feature: ENRD Evaluation Feed

  This feature is aimed at testing the Evaluation RSS Feed functionality.

  @anonymous
  Scenario: As anonymous I want to access the Feed page of the latest Evaluation content.
    Given I am an anonymous user
    And I am viewing a "publication_ehd" content in "published" status:
      | title                     | BDD RSS Feed Evaluation content |

    When I am at "rss/evaluation"
    Then I should get a "200" HTTP response
