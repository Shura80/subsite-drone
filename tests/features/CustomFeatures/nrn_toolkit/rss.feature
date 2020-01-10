@api @rss
Feature: ENRD NRN Toolkit Feed

  This feature is aimed at testing the NRN Toolkit RSS Feed functionality.

  @anonymous
  Scenario: As anonymous I want to access the RSS Feed page of the latest NRN Toolkit content.
    Given I am an anonymous user
    And 'enrd_networking' terms:
      | name                     | parent           |
      | BDD NRN Operation        | Running the NRNs |
    Given 'enrd_resource_type' terms:
      | name              |
      | BDD Web page      |
    And I am viewing a "page" content in "published" status:
      | title                          | BDD RSS Feed NRN Toolkit page |
      | field_enrd_nrn_include_toolkit | 1                             |
      | field_enrd_nrn_type            | BDD Web page                  |
      | field_tax_networking           | BDD NRN Operation             |
      | field_enrd_nrn_date            | 12-09-2019                    |

    When I am at "rss/nrn-toolkit"
    Then I should get a "200" HTTP response
