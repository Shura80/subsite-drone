@api @mastermind @search
Feature: ENRD Global Search Functionality
  This feature is aimed at allowing users to search for site contents of several types in the website
  by applying search filters or by running a free-text search.

  Background: Create a bunch of geographical taxonomy terms.
    Given 'enrd_countries' terms:
      | name        | parent         |
      | BDD Belgium | European Union |
    And 'enrd_esif_programme' terms:
      | name             | parent      |
      | BDD Belgium      | EAFRD       |
      | BDD Programme BE | BDD Belgium |

  @anonymous
  Scenario: As Anonymous, I can see the search box on the home page.
    Given I am an anonymous user
    When I am at "home-page"
    And I press the "edit-submit" button
    Then I should see the heading "Search results"

  @anonymous @filters @solr @clean
  Scenario: Create a bunch of content to be retrieved as search results.
    Given I am an anonymous user
    And I am viewing a "page" content in "published" status:
      | title    | BDD Global Search Basic |
      | language | en                      |
      | body     | BDD Global page body    |
    And I am viewing a "lag" content in "published" status:
      | title                     | BDD Global Search Local Action Group                     |
      | language                  | und                                                      |
      | field_enrd_lag_country    | BDD Belgium                                              |
      | field_enrd_esif_programme | BDD Programme BE                                         |
      | field_enrd_lag_code       | BDD-BE-001                                               |
      | og_group_ref              | European Agricultural Fund for Rural Development (EAFRD) |
    And I am viewing a "cooperation_offer" content in "published" status:
      | title                           | BDD Global Search Offer              |
      | language                        | und                                  |
      | field_enrd_coop_partner_country | BDD Belgium                          |
      | og_lag_group_ref                | BDD Global Search Local Action Group |
    And I am viewing a "rdp_information" content in "published" status:
      | title                          | BDD Global Search Country data |
      | language                       | en                             |
      | field_enrd_rdp_info_intro_text | BDD National Introductory text |
    And I am viewing a "publication_ehd" content in "published" status:
      | title                           | BDD Global Search EHD Publication |
      | language                        | en                                |
      | field_enrd_publ_ehd_description | BDD Global Evaluation Description |
    And I am viewing an "event" content in "published" status:
      | title    | BDD Custom Search event |
      | language | en                      |
      | body     | BDD Custom Event body   |
    When I am viewing a "news" content in "published" status:
      | title    | BDD Custom Search bdd-news |
      | language | en                         |
      | body     | BDD Custom News body       |
    And I am viewing a "project" content in "published" status:
      | title                   | BDD Custom Search project   |
      | language                | en                          |
      | field_enrd_prj_headline | BDD Custom Project Headline |
    And I am viewing a "publication" content in "published" status:
      | title                       | BDD Custom Search publ                       |
      | language                    | en                                           |
      | field_enrd_publication_desc | BDD Published Custom Publication Description |
    And I am viewing a "nrn_profile" content in "published" status:
      | title                       | BDD Global Search NRN profile                |
      | language                    | en                                           |
      | field_enrd_nrnp_brief_intro | BDD Published Global NRN Profile Description |

    When I send site contents to the Solr search index
    And I go to "search"
    And I fill in "keys" with "bdd"
    And I press "Search"

  # Facet: Type.
    When I follow "Page"
    Then I should see the heading "BDD Global Search Basic"
    And I should see "BDD Global page body" in the "content" region
    But I should not see the heading "BDD Global Search Local Action Group"
    And I follow "Clear filters"

    When I follow "LAG"
    Then I should see the heading "BDD Global Search Local Action Group"
    And I should see "BDD Belgium" in the "content" region
    And I should see "BDD Programme BE" in the "content" region
    And I should see "BDD-BE-001" in the "content" region
    And I should see "European Agricultural Fund for Rural Development (EAFRD)" in the "content" region
    But I should not see the heading "BDD Global Search Offer"
    And I follow "Clear filters"

    When I follow "Cooperation Offer"
    Then I should see the heading "BDD Global Search Offer"
    And I should see "BDD Belgium" in the "content" region
    And I should see "BDD Global Search Local Action Group" in the "content" region
    But I should not see the heading "BDD Global Search Local Action Group"
    And I follow "Clear filters"

    When I follow "Country Information"
    Then I should see the heading "BDD Global Search Country data"
    And I should see "BDD National Introductory text" in the "content" region
    But I should not see the heading "BDD Global Search Offer"
    And I follow "Clear filters"

    When I follow "Evaluation Publication"
    Then I should see the heading "BDD Global Search EHD Publication"
    And I should see "BDD Global Evaluation Description" in the "content" region
    But I should not see the heading "BDD Global Search Country data"
    And I follow "Clear filters"

    When I follow "Event" in the "right sidebar" region
    Then I should see the heading "BDD Custom Search event"
    And I should see "BDD Custom Event body" in the "content" region
    But I should not see the heading "BDD Global Search EHD Publication"
    And I follow "Clear filters"

    When I follow "News" in the "right sidebar" region
    Then I should see the heading "BDD Custom Search bdd-news"
    And I should see "BDD Custom News body" in the "content" region
    But I should not see the heading "BDD Global Search EHD Publication"
    And I follow "Clear filters"

    When I follow "Project" in the "right sidebar" region
    Then I should see the heading "BDD Custom Search project"
    And I should see "BDD Custom Project Headline" in the "content" region
    But I should not see the heading "BDD Custom Search bdd-news"
    And I follow "Clear filters"

    When I follow "NRN Profile" in the "right sidebar" region
    Then I should see the heading "BDD Global Search NRN profile"
    And I should see "BDD Published Global NRN Profile Description" in the "content" region
    But I should not see the heading "BDD Custom Search event"
    And I follow "Clear filters"

    When I fill in "keys" with "Global"
    And I press the "Search" button
    Then I should see the heading "BDD Global Search Basic"
    And I should see the heading "BDD Global Search Local Action Group"
    And I should see the heading "BDD Global Search Offer"
    And I should see the heading "BDD Global Search Country data"
    And I should see the heading "BDD Global Search NRN profile"
    But I should not see the heading "BDD Custom Search event"
    But I should not see the heading "BDD Custom Search bdd-news"
    But I should not see the heading "BDD Custom Search project"
    But I should not see the heading "BDD Custom Search publ"
