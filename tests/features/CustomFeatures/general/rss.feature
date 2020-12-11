@api @rss
Feature: ENRD Custom Feed

  This feature is aimed at testing the customized RSS Feed functionality.

  @anonymous @javascript
  Scenario: As Anonymous I want to get a dynamic RSS Feed based on the Topics and Countries that I choose.
    Given I am an anonymous user
    And 'enrd_transversal_topics' terms:
      | name               |
      | BDD Bioeconomy     |
      | BDD Smart Villages |
    And 'enrd_countries' terms:
      | name      |
      | BDD Italy |
    And I am viewing a "page" content in "published" status:
      | title                        | BDD content for RSS Feed |
      | field_tax_transversal_topics | BDD Bioeconomy           |

    # When the Feed returns some results.
    When I am at "rss/content"
    And I set the chosen element "topics[]" to "BDD Bioeconomy"
    And I wait for AJAX to finish
    Then I should see "Subscribe to the RSS Feed to stay up to date:"
    But I should not see "At the moment, there isn't any content matching the selected criteria."
    And I should see the link "Get RSS Link"
    # Check compulsoriness of "Topics" filter.
    When I am at "rss/content"
    And I set the chosen element "countries[]" to "BDD Italy"
    And I wait for AJAX to finish
    Then I should see the following error message:
      | error messages            |
      | Topics field is required. |
    # When the Feed doesn't return any results.
    When I press the "Reset" button
    And I set the chosen element "topics[]" to "BDD Smart Villages"
    And I wait for AJAX to finish
    Then I should see "At the moment, there isn't any content matching the selected criteria."
    And I should see "Subscribe to the RSS Feed to stay up to date:"
    And I should see the link "Get RSS Link"

  @anonymous
  Scenario: As Anonymous I want to reach the "Content Feed" RSS page.
    Given I am an anonymous user
    When I am on "rss/content/feed"
    Then I should get a "200" HTTP response
