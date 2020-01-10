@api @events @anonymous
Feature: ENRD Events
  In order to test some basic features functionality

  Background: I create a new Event content and associated taxonomy terms.
    # Terms for "Event type" taxonomy
    Given "event_types" terms:
      | name             |
      | BDD Event type 1 |
      | BDD Event type 2 |
      | BDD Event type 3 |
    And "enrd_origin" terms:
      | name             |
      | BDD Event origin |
    # Add some classification terms for pre-filtered events views.
    And "enrd_transversal_topics" terms:
      | name      |
      | BDD Topic |
    And "enrd_rural_development_policy" terms:
      | name          |
      | BDD Rural Dev |
    # Event in progress
    And I am viewing an "event" content in "published" status:
      | title            | BDD Event in progress                |
      | field_event_type | BDD Event type 1                     |
      | field_tax_origin | BDD Event origin                     |
      | field_event_date | 1 month ago - last day of next month |
    # Future event
    And I am viewing an "event" content in "published" status:
      | title                        | BDD Future event                                 |
      | field_event_type             | BDD Event type 2                                 |
      | field_tax_origin             | BDD Event origin                                 |
      | field_tax_transversal_topics | BDD Topic                                        |
      | field_event_date             | first day of next month - last day of next month |
    # Past event
    And I am viewing an "event" content in "published" status:
      | title                      | BDD Past event          |
      | field_event_type           | BDD Event type 2        |
      | field_tax_origin           | BDD Event origin        |
      | field_tax_rural_dev_policy | BDD Rural Dev           |
      | field_event_date           | 1 month ago - yesterday |

  @clean
  Scenario: View the "Upcoming events" block on the "News & Events" page.
    Given I am an anonymous user
    When I am on "news-events"
    Then I should see the text "Upcoming events" in the "right content" region
    And I should see the link "BDD Event in progress"

  @javascript
  Scenario: Check the visibility of the events in "Upcoming events" page.
    Given I am an anonymous user
    And I am on "news-events/events"
    And I see the heading "Upcoming events"

    When I select "BDD Event origin" from "Organiser"
    And I wait for AJAX to finish
    And I should see the link "BDD Event in progress"
    And I should see the link "BDD Future event"
    But I should not see the link "BDD Past event"

    When I select "BDD Event type 1" from "Event Type"
    And I wait for AJAX to finish
    And I should see the text "BDD Event in progress"

    When I select "BDD Event type 3" from "Event Type"
    And I wait for AJAX to finish
    And I should see the text "No events found."

  Scenario: Check the visibility of the term pre-filtered events in "Upcoming events" page.
    Given I am an anonymous user
    And I am on "news-events/events/upcoming/bdd-topic"
    Then I see the heading "Upcoming events: BDD Topic"
    And I see the heading "BDD Future event"

  @javascript
  Scenario: Check the visibility of the events in "Past events" page.
    Given I am an anonymous user
    And I am on "news-events/events/past"
    Then I should see the heading "Past events"

    When I select "BDD Event origin" from "Organiser"
    And I wait for AJAX to finish
    Then I should see the link "BDD Past event"
    But I should not see the link "BDD Event in progress"
    And I should not see the link "BDD Future event"

    When I select "BDD Event type 2" from "Event Type"
    And I wait for AJAX to finish
    And I should see the text "BDD Past event"

    When I select "BDD Event type 3" from "Event Type"
    And I wait for AJAX to finish
    And I should see the text "No events found."

  Scenario: Check the visibility of the term pre-filtered events in "Past events" page.
    Given I am an anonymous user
    And I am on "news-events/events/past/bdd-rural-dev"
    Then I see the heading "Past events: BDD Rural Dev"
    And I see the heading "BDD Past event"

  Scenario: Check the visibility of the fields of an event. and Stakeholder external link.
    Given I am an anonymous user
    And "enrd_countries" terms:
      | name              |
      | BDD Event country |

    And I am viewing an "event" content in "published" status:
      | title                        | BDD Custom past event                                               |
      | body                         | Event body                                                          |
      | field_event_date             | 01-01-2017 20:30 - 02-01-2017 02:00                                 |
      | field_event_location:country | IT                                                                  |
      | :administrative_area         | RM                                                                  |
      | :locality                    | Rome                                                                |
      | field_event_type             | BDD Event type 1                                                    |
      | field_tax_origin             | BDD Event origin                                                    |
      | field_tax_country            | BDD Event country                                                   |
      | field_stakeholders_events    | 0                                                                   |

    Then I should see the heading "BDD Custom past event"
    And I should see the text "Event body"
    And I should see the text "Dates: 01/01/2017 - 20:30 to 02/01/2017 - 02:00"
    And I should see the text "Location: Rome RM Italy"
    And I should see the text "Event type: BDD Event type 1"
    And I should see the text "Organiser: BDD Event origin"

    And I am viewing an "event" content in "published" status:
      | title                     | BDD Stakeholder past event                                          |
      | field_event_date          | 01-01-2017 20:30 Europe/Brussels - 02-01-2017 02:00 Europe/Brussels |
      | field_stakeholders_events | 1                                                                   |

    When I am on "news-events/events/past"
    And I select "BDD Event country" from "Countries"
    And I press the "Apply" button
    Then I should see the heading "Past events"
    And I should see the heading "January 2017"
    And I should see the link "BDD Custom past event"
    And I should see the text "Event body"
    And I should see the text "Dates: 01/01/2017 to 02/01/2017"
    And I should see the text "Location: Rome RM Italy"
    And I should see the text "Event type: BDD Event type 1"
    And I should see the text "Organiser: BDD Event origin"
    But I should not see the link "BDD Stakeholder past event"

  @online
  Scenario: Check the visibility of a stakeholder event.
    Given I am an anonymous user
    And I am viewing an "event" content in "published" status:
      | title                     | BDD Stakeholder today event          |
      | field_event_date          | tomorrow - tomorrow                  |
      | field_stakeholders_events | 1                                    |
      | field_location            | Example.com - http://www.example.com |

    When I am on "news-events/events"
    And I click "BDD Stakeholder today event"
    Then I should be on "http://www.example.com"

  @javascript @views @clean
  Scenario: Testing month and year date filters.
    Given I am an anonymous user
    # Event 01-01-2017 to 01-01-2017
    And I am viewing an "event" content in "published" status:
      | title            | BDD Jan event 2017      |
      | field_event_type | BDD Event type 1        |
      | field_event_date | 01-01-2017 - 01-01-2017 |
    # Event 01-02-2017 to 01-02-2017
    And I am viewing an "event" content in "published" status:
      | title            | BDD Feb event 2017      |
      | field_event_type | BDD Event type 1        |
      | field_event_date | 01-02-2017 - 01-02-2017 |
    # Event 01-01-2018 to 01-01-2018
    And I am viewing an "event" content in "published" status:
      | title            | BDD Jan event 2018      |
      | field_event_type | BDD Event type 1        |
      | field_event_date | 01-01-2018 - 01-01-2018 |
    # Event 31/12/YY
    And I am viewing an "event" content in "published" status:
      | title            | BDD Dec event                               |
      | field_event_type | BDD Event type 1                            |
      | field_event_date | 1/1 next year -1 day - 1/1 next year -1 day |

    When I am on "news-events/events"
    And I select "Dec" from "between_date_filter[value][month]"
    And I wait for AJAX to finish
    Then I should see the text "BDD Dec event"

    And I am on "news-events/events/past"
    When I select "2017" from "between_date_filter_1[value][year]"
    And I wait for AJAX to finish
    Then I should see the text "BDD Jan event 2017"
    And I should see the text "BDD Feb event 2017"
    But I should not see the text "BDD Jan event 2018"

    When I select "Jan" from "between_date_filter_1[value][month]"
    And I wait for AJAX to finish
    Then I should see the text "BDD Jan event 2017"
    But I should not see the text "BDD Feb event 2017"
    And I should not see the text "BDD Jan event 2018"
