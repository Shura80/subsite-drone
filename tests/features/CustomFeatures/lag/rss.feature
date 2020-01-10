@api @rss
Feature: ENRD Cooperation offers Feed.

  This feature is aimed at testing the Cooperation offers RSS Feed functionality.

  @anonymous @coop
  Scenario: As anonymous I should be able to access the RSS Feed page of the latest cooperation offers.
    Given I am an anonymous user
    And 'enrd_countries' terms:
      | name        |
      | BDD Belgium |
    And I am viewing a "lag" content in "published" status:
      | title                     | BDD LAG Published                                        |
      | field_enrd_lag_country    | BDD Belgium                                              |
      | field_enrd_lag_code       | BDD-BE-LAG-PUB                                           |
      | og_group_ref              | European Agricultural Fund for Rural Development (EAFRD) |
      | language                  | und                                                      |
    And I am viewing a "cooperation_offer" content in "published" status:
      | title                           | BDD RSS Feed Cooperation offer |
      | field_enrd_coop_partner_country | BDD Belgium                    |
      | field_enrd_coop_expiry_date     | 13-12-2020 09:00               |
      | og_lag_group_ref                | BDD LAG Published              |
      | language                        | und                            |

    When I am at "rss/leader-clld/cooperation-offers"
    Then I should get a "200" HTTP response
