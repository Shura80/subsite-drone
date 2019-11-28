@api @events
Feature: EIP-AGRI Events section
  In order to test some basic features functionality.

  @anonymous @layout
  Scenario: Splash page: show event list with filters and mini calendar
    Given I am an anonymous user
    When I am on "events"
    # Mini calendar in sidebar left.
    Then I should see an ".view-agri-calendar" element
    And I should see the link "View full calendar" in the "sidebar_left"
    # Event list with the filters and the quicktabs.
    Then I should see the text "Free text search" in the "content_bottom" region
    And I should see the text "Filter by location" in the "content_bottom" region
    And I should see the text "Filter by event type" in the "content_bottom" region
    And I should see the text "Items per page" in the "content_bottom" region
    And I should see the button "Search"
    And I should see the button "Reset"
    And I should see an "#quicktabs-agri_event_event_list" element
    And I should see the text "Upcoming" in the "content_bottom" region
    And I should see the text "Past" in the "content_bottom" region

  @anonymous @layout
  Scenario: Calendar page: show calendar month/year
    Given I am an anonymous user
    When I am on "events/calendar"
    Then I should see the heading "Events calendar"
    # Check if the tabs for the navigation exists.
    And I should see the link "Day"
    And I should see the link "Month"
    And I should see the link "Year"
    # Check if show the month calendar.
    And I should see an ".month-view" element
    And I should see the link "Current month"
    # View the year calendar
    When I am on "events/calendar/year"
    # Check if show the year calendar.
    Then I should see an ".year-view" element
    And I should see the link "Current year"
    # View the day calendar
    When I am on "events/calendar/day"
    # Check if show the day calendar.
    Then I should see an ".day-view" element
    And I should see the link "Current day"

  @javascript
  Scenario: Check the conditional fields functionality in Event content type.
    Given I am logged in as a user with the "administrator" role
    And I am viewing a "event" content in "draft" status:
      | title                        | BDD Event                                                                 |
      | field_event_address          | Street of the BDD Event                                                   |
      | field_event_type             | Other European events                                                     |
      | field_core_geographical_area | Belgium                                                                   |
      | field_event_date             | 01-01-2019 00:00:00 Europe/Brussels - 31-01-2019 23:59:00 Europe/Brussels |
    When I click "Edit draft"
    And I select "-Other" from "Type of event"
    And I fill in "Other" with "BDD event type"
    And I set the chosen element "Location" to "Other"
    And I fill in "Specify other location" with "BDD other location"
    And I click "Publishing options"
    And I select "published" from "Moderation state"
    And I press the "Save" button
    Then I should see "Tuesday, 1 January, 2019 to Thursday, 31 January, 2019" in the "Dates" row
    And I should see "BDD event type" in the "Type of event" row
    And I should see "BDD other location" in the "Location" row

  Scenario: Check that date field is visible on event nodes and event list.
    Given "core_geographical_area" terms:
      | name              |
      | BDD Test location |
    And "event_type" terms:
      | name      |
      | BDD Event |
    And I am viewing an "event" content in "published" status:
      | title                        | BDD Event Dates visibility                                                |
      | language                     | und                                                                       |
      | field_event_type             | BDD Event                                                                 |
      | field_event_address          | Via Roma 100, 00100 ROMA ITALY                                            |
      | field_event_date             | 01-01-2018 09:00:00 Europe/Brussels - 31-01-2018 09:00:00 Europe/Brussels |
      | field_core_geographical_area | BDD Test location                                                         |
    Then I should see the heading "BDD Event Dates visibility"
    And I should see "Monday, 1 January, 2018 - 09:00 to Wednesday, 31 January, 2018 - 09:00"
    When I am at "events"
    And I select "BDD Event" from "Filter by event type"
    And I fill in "Free text search" with "BDD"
    And I press the "edit-submit-events-list" button
    And I click "Past"
    Then I should see the link "BDD Event Dates visibility"
    And I should see "Monday, 1 January, 2018 - 09:00 to Wednesday, 31 January, 2018 - 09:00"

  @homepage
  Scenario: Check that newest events are visbile in the block of new homepage's layout.
    Given I am an anonymous user
    And "core_geographical_area" terms:
      | name              |
      | BDD Test location |
    And "event_type" terms:
      | name           |
      | BDD Event Home |
    And I am viewing an "event" content in "published" status:
      | title                        | BDD Event in homepage           |
      | language                     | und                             |
      | field_event_type             | BDD Event Home                  |
      | field_event_address          | Via Italia 55, 00100 ROMA ITALY |
      | field_event_date             | now - now +1week                |
      | field_core_geographical_area | BDD Test location               |
    When I am on the homepage
    Then I should see the link "BDD Event in homepage" in the "content_top_right"