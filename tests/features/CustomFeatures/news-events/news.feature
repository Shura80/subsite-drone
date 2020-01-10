@api @news @anonymous
Feature: ENRD News
  In order to test some basic features functionality

  Background: I have some News content and News origin
    Given 'enrd_origin' terms:
      | name            |
      | BDD News origin |

    # News published
    And I am viewing a "news" content in "published" status:
      | title                       | BDD News published |
      | field_news_publication_date | today 8:00         |
      | field_top_news              | top                |
      | field_tax_origin            | BDD News origin    |
    # News unpublished
    And I am viewing a "news" content in "draft" status:
      | title                       | BDD News unpublished |
      | field_top_news              | top                  |
      | field_news_publication_date | today 8:00           |

  Scenario: Check the visibility of a published news.
    Given I am an anonymous user
    When I am viewing a "news" content in "published" status:
      | title                       | BDD News custom |
      | body                        | BDD News body   |
      | field_news_publication_date | 01-01-2015 8:00 |
      | field_tax_origin            | BDD News origin |
    Then I should see the heading "BDD News custom" in the "title"
    And I should see the text "BDD News body"
    And I should see the text "Publication date: 01/01/2015"
    And I should see the text "Source: BDD News origin"

  Scenario: View the "News" feed block on the home page.
    Given I am an anonymous user
    When I am on the homepage
    Then I should see the text "News"
    And I should see the link "BDD News published"
    And I should not see the link "BDD News unpublished"

  Scenario: View the "News" block on the "News & Events" page.
    Given I am an anonymous user
    When I am on "news-events"
    Then I should see the heading "News" in the "bottom content" region
    And I should see the link "BDD News published"

  Scenario: Check the visibility of a news in the news list page.
    Given I am an anonymous user
    When I am on "news-events/news"
    Then I should see the text "News"
    And I should see the link "BDD News published"
    And I should see the text "Source: BDD News origin"

  @javascript @clean
  Scenario: Testing Date and Source filters in the news list page.
    Given I am an anonymous user
    # News published 01/01/2017
    And I am viewing a "news" content in "published" status:
      | title                       | BDD News 2017-01 |
      | field_news_publication_date | 01-01-2017 8:00  |
      | field_top_news              | top              |
      | field_tax_origin            | BDD News origin  |
    # News published 01/02/2017
    And I am viewing a "news" content in "published" status:
      | title                       | BDD News 2017-02 |
      | field_news_publication_date | 01-02-2017 8:00  |
    # News published 01/01/2018
    And I am viewing a "news" content in "published" status:
      | title                       | BDD News 2018-01 |
      | field_news_publication_date | 01-01-2018 8:30  |
    And I am on "news-events/news"
    When I select "2017" from "field_news_publication_date_value[value][year]"
    And I wait for AJAX to finish
    Then I should see the text "BDD News 2017-01"
    And I should see the text "BDD News 2017-02"
    But I should not see the text "BDD News 2018-01"

    When I select "Jan" from "field_news_publication_date_value[value][month]"
    And I wait for AJAX to finish
    Then I should see the text "BDD News 2017-01"
    And I should not see the text "BDD News 2017-02"
    But I should not see the text "BDD News 2018-01"

    When I select "BDD News origin" from "filter_news_source"
    And I wait for AJAX to finish
    Then I should see the text "BDD News 2017-01"
